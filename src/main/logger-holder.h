#pragma once
#ifndef _LOGGER_HOLDER_H_
#define _LOGGER_HOLDER_H_

#include <sstream>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include "logger.h"
#include "datetime.h"
#include "utils.h"
#include "demangle.h"
#include "ioc.h"

/** Trigger a debug log message */
struct Debug
{
    const char* level()
    {
        return "DEBUG";
    }
};

/** Trigger an information log message */
struct Info
{
    const char* level()
    {
        return "INFO ";
    }
};

/** Trigger an error log message */
struct Error
{
    const char* level()
    {
        return "ERROR";
    }
};

/**
 * Macro to register a new Logger.
 * @param logger the logger to register.
 */
#define REGISTER_LOG(logger) LoggerHolder::Register(new logger)

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

/**
 * Class that log string of text to the console.
 */
class LoggerHolder
{
private:
    /** Each logger are stored as a boost shared ptr in the list. */
    typedef boost::shared_ptr<Logger> LoggerPtr;

    /** Type for the list of all loggers. */
    typedef std::list<LoggerPtr> LoggerList;

public:

    /**
     * Register a new logger.
     * @param logger the logger to register.
     */
    static void Register(Logger* logger)
    {
        LoggerList* loggers = GetLoggers();
        loggers->push_back(LoggerPtr(logger));
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
        ss << "[" << level.level() << "] [" << DateTime::Now() << "] [" << identifier << "] from " << function << " in " << file << " at line " << line << ": " << message << std::endl;

        LoggerList* loggers = GetLoggers();
        BOOST_FOREACH(LoggerPtr& logger, *loggers)
        {
            logger->write(ss.str());
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
