#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>

#include "datetime.h"
#include "utils.h"
#include "demangle.h"

/** Trigger a debug log message */
struct Debug
{
    const char* level() { return "DEBUG"; }
};

/** Trigger an information log message */
struct Info
{
    const char* level() { return "INFO "; }
};

/** Trigger an error log message */
struct Error
{
    const char* level() { return "ERROR"; }
};

/**
 * Macros that pass the source file name and line number to the Logger class.
 * @param level the level of the log message
 * @param identifier the log identifier
 * @param message the message to log
 */
#define LOG(level,identifier,message) Logger::Log<level,identifier>(__FUNCTION__, __FILE__, __LINE__, message)
#define LOG_DEBUG(identifier,message) Logger::Log<Debug,identifier>(__FUNCTION__, __FILE__, __LINE__, message)
#define LOG_INFO(identifier,message) Logger::Log<Info,identifier>(__FUNCTION__, __FILE__, __LINE__, message)
#define LOG_ERROR(identifier,message) Logger::Log<Error,identifier>(__FUNCTION__, __FILE__, __LINE__, message)

/**
 * Class that log string of text to the console.
 */
class Logger
{
public:
    /**
     * Log a message.
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
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param level the level of the log message.
     */
    template <class LogLevel>
    static void Log(const char* identifier, const char* function, const char* file, const int line, const char* message, LogLevel level)
    {
        std::cout << "[" << level.level() << "] [" << DateTime::Now() << "] [" << identifier << "] from " << function << " in " << file << " at line " << line << ": " << message << std::endl;
    }

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(Logger);
};

#endif
