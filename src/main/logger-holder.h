/*
===============================================================================
    COPYING PERMISSION STATEMENT
===============================================================================
    This file is part of erty.

    erty is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    erty is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with erty.  If not, see <http://www.gnu.org/licenses/>.
===============================================================================
*/
#pragma once
#ifndef _LOGGER_HOLDER_H_
#define _LOGGER_HOLDER_H_

#include <sstream>
#include <string>
#include <list>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include "logger.h"
#include "log-level.h"
#include "datetime.h"
#include "utils.h"
#include "ioc.h"

namespace erty
{

/**
 * Macro to register a new Logger.
 * @param logger the logger to register.
 */
#define REGISTER_LOGGER(logger) erty::LoggerHolder::RegisterLogger(new logger)

/** Macro that unregister all loggers. */
#define UNREGISTER_ALL_LOGGERS() erty::LoggerHolder::UnregisterAllLoggers()

/** Macro that register a new log component.
 * @param component the component identifier string
 * @param level the associate logging level.  Only log message with priority greater or equal that this level will be log.
 */
#define REGISTER_LOG_COMPONENT(component,level) erty::LoggerHolder::RegisterLogComponent(component, level())

/**
 * Macros to log a debug message
 * @param component the log component
 * @param message the message to log
 */
#ifdef DEBUG
#define DEBUG_LOG(component,message) erty::LoggerHolder::Log(erty::Debug(), component, __FUNCTION__, __FILE__, __LINE__, message)
#else
#define DEBUG_LOG(component,message)
#endif

/**
 * Macros to log an information message
 * @param component the log component
 * @param message the message to log
 */
#define INFO_LOG(component,message) erty::LoggerHolder::Log(erty::Info(), component, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * Macros to log a notice message
 * @param component the log component
 * @param message the message to log
 */
#define NOTICE_LOG(component,message) erty::LoggerHolder::Log(erty::Notice(), component, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * Macros to log a warning message
 * @param component the log component
 * @param message the message to log
 */
#define WARNING_LOG(component,message) erty::LoggerHolder::Log(erty::Warning(), component, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * Macros to log an error message
 * @param component the log component
 * @param message the message to log
 */
#define ERROR_LOG(component,message) erty::LoggerHolder::Log(erty::Error(), component, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * Macros to log a critical message
 * @param component the log component
 * @param message the message to log
 */
#define CRITICAL_LOG(component,message) erty::LoggerHolder::Log(erty::Critical(), component, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * Macros to log an alert message
 * @param component the log component
 * @param message the message to log
 */
#define ALERT_LOG(component,message) erty::LoggerHolder::Log(erty::Alert(), component, __FUNCTION__, __FILE__, __LINE__, message)

/**
 * Macros to log an emergency message
 * @param component the log component
 * @param message the message to log
 */
#define EMERGENCY_LOG(component,message) erty::LoggerHolder::Log(erty::Emergency(), component, __FUNCTION__, __FILE__, __LINE__, message)

/** Map of base priority by component. */
typedef std::map<std::string, unsigned int> LogComponents;

/** Each logger are stored as a boost shared ptr. */
typedef boost::shared_ptr<Logger> LoggerPtr;

/**
 * Comparison method that verify LoggerPtr equality.
 * @param a the first LoggerPtr.
 * @param b the second LoggerPtr.
 * @return true id both LoggerPtr are equals, else false.
 */
inline bool operator==(LoggerPtr a, LoggerPtr b)
{
    return (*(a.get()) == *(b.get()));
}

/** Type for the list of all loggers. */
typedef std::list<LoggerPtr> LoggerList;

/**
 * Class that log string of text to the console.
 */
class LoggerHolder
{
public:

    /** LoggerHolder defaulr constructor. */
    LoggerHolder() :
        _logComponents(), _loggerList()
    {
    }

    /**
     * Register a new logger.
     * If the logger is already registered, its priority will be adjuted to match the requested one.
     * @param logger the logger to register.
     * @return the registered logger.
     */
    static Logger* RegisterLogger(Logger* logger)
    {
        LoggerHolder& holder = IoC::Inject<LoggerHolder>();
        LoggerPtr loggerPtr = LoggerPtr(logger);

        LoggerList::iterator loggerIter = std::find(holder._loggerList.begin(), holder._loggerList.end(), loggerPtr);
        if (loggerIter == holder._loggerList.end())
        {
            holder._loggerList.push_back(loggerPtr);
        }
        return logger;
    }

    /**
     * Unregister all registered loggers.
     */
    static void UnregisterAllLoggers()
    {
        LoggerHolder& holder = IoC::Inject<LoggerHolder>();
        holder._loggerList.clear();
    }

    /**
     * Register a new log component.
     * If the component is already registered, only change its base priority.
     * @param component the component to register.
     * @param level only log message with priority greater or equal to this level will be logged.
     */
    static void RegisterLogComponent(const std::string& component, const LogLevel& level)
    {
        LoggerHolder& holder = IoC::Inject<LoggerHolder>();
        holder._logComponents[component] = level.priority();
    }

    /*
     * Log method dispatcher by Loglevel.
     * @param level the level of the log message.
     * @param component the component of the log message
     * @param function function name in which the log call was triggered.
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     */
    static void Log(const LogLevel& level, const char* component, const char* function, const char* file, const int line, const char* message)
    {
        std::stringstream ss;
        ss << "[" << level.level() << "] [" << DateTime::Now() << "] [" << component << "] from " << function << " in " << file << ":" << line << " - " << message << std::endl;

        LoggerHolder& holder = IoC::Inject<LoggerHolder>();
        unsigned int priority = holder.getComponentPriority(component);

        if (level.priority() >= priority)
        {
            BOOST_FOREACH(LoggerPtr& logger, holder._loggerList)
            {
                logger->write(level, ss.str());
            }
        }
    }

private:

    /**
     * Return the base priority of a component.
     * @param component the component from which we want the priority.
     * @return the registered priority for the component, or the Info priority if the component is not registered.
     */
    unsigned int getComponentPriority(const std::string& component) const
    {
#ifdef DEBUG
        unsigned int priority = Debug().priority();
#else
        unsigned int priority = Info().priority();
#endif
        LogComponents::const_iterator logComponent = _logComponents.find(component);
        if (logComponent != _logComponents.end())
        {
            priority = logComponent->second;
        }
        return priority;
    }

    /** Keep the list of registered base priority by log component. */
    LogComponents _logComponents;

    /** Keep the list of registered logger object. */
    LoggerList _loggerList;

    DISALLOW_COPY_AND_ASSIGN(LoggerHolder);
};

}

#endif
