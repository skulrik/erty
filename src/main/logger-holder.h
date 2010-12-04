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
#include <list>
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
 * @param level only log with level greather or equal to this will be logged in this logger.
 * @param logger the logger to register.
 */
#define REGISTER_LOG(level,logger) LoggerHolder::Register(level(), new logger)

#define UNREGISTER_ALL_LOGS() LoggerHolder::UnregisterAll()
/**
 * Macros that pass the source file name and line number to the Logger class.
 * @param level the level of the log message
 * @param identifier the log identifier
 * @param message the message to log
 */
#define LOG(level,identifier,message) LoggerHolder::Log<level,identifier>(__FUNCTION__, __FILE__, __LINE__, message)
#define LOG_DEBUG(identifier,message) LoggerHolder::Log<Debug,identifier>(__FUNCTION__, __FILE__, __LINE__, message)
#define LOG_INFO(identifier,message) LoggerHolder::Log<Info,identifier>(__FUNCTION__, __FILE__, __LINE__, message)
#define LOG_ERROR(identifier,message) LoggerHolder::Log<Error,identifier>(__FUNCTION__, __FILE__, __LINE__, message)


/** Each logger are stored as a boost shared ptr in the LoggerItem struct. */
typedef boost::shared_ptr<Logger> LoggerPtr;

/** Represent one available logger. */
struct LoggerItem
{
    /** Only log with level greather or equal to this will be logged in this logger. */
    unsigned int priority;

    /** The logger in which will be write log messages. */
    LoggerPtr logger;

    /**
     * Instanciate a new LoggerItem.
     * @param priority only log with level greather or equal to this will be logged in this logger.
     * @param logger the logger in which will be write log messages.
     */
    LoggerItem(int priority, Logger* logger) :
        priority(priority), logger(LoggerPtr(logger))
    {
    }
};

/**
 * Compare two LoggerItem for equality.
 * @param a the first LoggerItem.
 * @param b the second LoggerItem.
 * @return true if both LoggerItem contains the same logger.
 */
inline bool operator==(const LoggerItem& a, const LoggerItem& b)
{
    return (*(a.logger) == *(b.logger));
}

/** Type for the list of all loggers. */
typedef std::list<LoggerItem> LoggerList;


/**
 * Class that log string of text to the console.
 */
class LoggerHolder
{
public:

    /**
     * Register a new logger.
     * If the logger is already registered, its priority will be adjuted to match the requested one.
     * @param level only log with level greather or equal to this will be logged in this logger.
     * @param logger the logger to register.
     */
    template <class LogLevel>
    static void Register(LogLevel level, Logger* logger)
    {
        LoggerList* loggers = GetLoggers();
        LoggerItem loggerItem(level.priority(), logger);

        LoggerList::iterator logItemIter = std::find(loggers->begin(), loggers->end(), loggerItem);
        if (logItemIter == loggers->end())
        {
            loggers->push_back(loggerItem);
        }
        else
        {
            logItemIter->priority = level.priority();
        }
    }

    /**
     * Unregister all registered loggers.
     */
    static void UnregisterAll()
    {
        LoggerList* loggers = GetLoggers();
        loggers->clear();
    }

    /**
     * Log a message.
     * @param function function name in which the log call was triggered.
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @tparam LogLevel the level of the log message
     * @tparam Identifier the identifier of the log message
     */
    template <class LogLevel, class Identifier>
    static void Log(const char* function, const char* file, const int line, const char* message)
    {
        std::string identifier;
        demangle(typeid(Identifier).name(), identifier);

        Log(identifier.c_str(), function, file, line, message, LogLevel());
    }

private:
    /**
     * Log method dispatcher by Loglevel.
     * @param identifier the identifier of the log message
     * @param function function name in which the log call was triggered.
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param level the level of the log message.
     */
    template <class LogLevel>
    static void Log(const char* identifier, const char* function, const char* file, const int line, const char* message, LogLevel level)
    {
        std::stringstream ss;
        ss << "[" << level.level() << "] [" << DateTime::Now() << "] [" << identifier << "] from " << function << " in " << file << ":" << line << " - " << message << std::endl;

        LoggerList* loggers = GetLoggers();
        BOOST_FOREACH(LoggerItem& loggerItem, *loggers)
        {
            if (level.priority() >= loggerItem.priority)
            {
                loggerItem.logger->write(ss.str());
            }
        }

    }

    /**
     * Retrieve the loggers from the IoC container.
     * Create it if its not there.
     * @return the list of all registered loggers.
     */
    static LoggerList* GetLoggers()
    {
        LoggerList* loggers = 0;

        if (IoC::IsRegistered<LoggerList>())
        {
            loggers = IoC::Resolve<LoggerList>();
        }
        else
        {
            loggers = new LoggerList();
            IoC::Register<LoggerList>(loggers);
        }

        return loggers;
    }

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(LoggerHolder);
};

#endif
