/*
===============================================================================
    COPYING PERMISSION STATEMENT
===============================================================================
    This file is part of CPP_APP_TEMPLATE.

    CPP_APP_TEMPLATE is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CPP_APP_TEMPLATE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CPP_APP_TEMPLATE.  If not, see <http://www.gnu.org/licenses/>.
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
#include "demangle.h"
#include "ioc.h"

/**
 * Macro to register a new Logger.
 * @param logger the logger to register.
 */
#define REGISTER_LOGGER(logger) LoggerHolder::RegisterLogger(new logger)

/** Macro that unregister all loggers. */
#define UNREGISTER_ALL_LOGGERS() LoggerHolder::UnregisterAllLoggers()

/** Macro that register a new log component.
 * @param component the component identifier string
 * @param level the associate logging level.  Only log message with priority greater or equal that this level will be log.
 */
#define REGISTER_LOG_COMPONENT(component,level) LoggerHolder::RegisterLogComponent<level>(component, level())

/**
 * Macros to log a debug message
 * @param component the log component
 * @param message the message to log
 */
#define LOG_DEBUG(component,message) LoggerHolder::Log<Debug>(component, __FUNCTION__, __FILE__, __LINE__, message, Debug())

/**
 * Macros to log an information message
 * @param component the log component
 * @param message the message to log
 */
#define LOG_INFO(component,message) LoggerHolder::Log<Info>(component, __FUNCTION__, __FILE__, __LINE__, message, Info())

/**
 * Macros to log an error message
 * @param component the log component
 * @param message the message to log
 */
#define LOG_ERROR(component,message) LoggerHolder::Log<Error>(component, __FUNCTION__, __FILE__, __LINE__, message, Error())

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

    /**
     * Register a new logger.
     * If the logger is already registered, its priority will be adjuted to match the requested one.
     * @param logger the logger to register.
     */
    static void RegisterLogger(Logger* logger)
    {
        LoggerHolder& holder = GetLoggerHolder();
        LoggerPtr loggerPtr = LoggerPtr(logger);

        LoggerList::iterator loggerIter = std::find(holder._loggerList.begin(), holder._loggerList.end(), loggerPtr);
        if (loggerIter == holder._loggerList.end())
        {
            holder._loggerList.push_back(loggerPtr);
        }
    }

    /**
     * Unregister all registered loggers.
     */
    static void UnregisterAllLoggers()
    {
        LoggerHolder& holder = GetLoggerHolder();
        holder._loggerList.clear();
    }

    template <class LogLevel>
    static void RegisterLogComponent(const std::string& component, LogLevel logLevel)
    {
        LoggerHolder& holder = GetLoggerHolder();
        holder._logComponents[component] = logLevel.priority();
    }

    /**
     * Log method dispatcher by Loglevel.
     * @param component the component of the log message
     * @param function function name in which the log call was triggered.
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param level the level of the log message.
     */
    template <class LogLevel>
    static void Log(const char* component, const char* function, const char* file, const int line, const char* message, LogLevel level)
    {
        std::stringstream ss;
        ss << "[" << level.level() << "] [" << DateTime::Now() << "] [" << component << "] from " << function << " in " << file << ":" << line << " - " << message << std::endl;

        LoggerHolder& holder = GetLoggerHolder();
        unsigned int priority = holder.getComponentPriority(component);

        if (level.priority() >= priority)
        {
            BOOST_FOREACH(LoggerPtr& logger, holder._loggerList)
            {
                logger->write(ss.str());
            }
        }

    }

private:

    /**
     * Retrieve the logger holder from the IoC container.
     * Create it if its not there.
     * @return the logger holder.
     */
    static LoggerHolder& GetLoggerHolder()
    {
        LoggerHolder* loggerHolder = 0;

        if (IoC::IsRegistered<LoggerHolder>())
        {
            loggerHolder = IoC::Resolve<LoggerHolder>();
        }
        else
        {
            loggerHolder = new LoggerHolder();
            IoC::Register<LoggerHolder>(loggerHolder);
        }

        return *loggerHolder;
    }

    /**
     * Return the base priority of a component.
     * @param component the component from which we want the priority.
     * @return the registered priority for the component, or the Info priority if the component is not registered.
     */
    unsigned int getComponentPriority(const std::string& component) const
    {
        unsigned int priority = Info().priority();
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

    /** LoggerHolder defaulr constructor. */
    LoggerHolder() :
        _logComponents(), _loggerList()
    {
    }

    DISALLOW_COPY_AND_ASSIGN(LoggerHolder);
};

#endif
