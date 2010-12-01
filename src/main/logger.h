#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>

#include "datetime.h"
#include "identity.h"
#include "utils.h"
#include "demangle.h"

/** Trigger a debug log message */
struct Debug {}; //< Trigger a debug log message

/** Trigger an information log message */
struct Info  {}; //< Trigger an information log message

/** Trigger an error log message */
struct Error {}; //< Trigger an error log message

/**
 * Macros that pass the source file name and line number to the Logger class.
 * @param level the level of the log message
 * @param identifier the log identifier
 * @param message the message to log
 */
#define LOG(level,identifier,message) Logger::Log<level,identifier>(__FILE__, __LINE__, message)
#define LOG_DEBUG(identifier,message) Logger::Log<Debug,identifier>(__FILE__, __LINE__, message)
#define LOG_INFO(identifier,message) Logger::Log<Info,identifier>(__FILE__, __LINE__, message)
#define LOG_ERROR(identifier,message) Logger::Log<Error,identifier>(__FILE__, __LINE__, message)

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
    static void Log(const char* file, const int line, const char* message)
    {
        std::string identifier;
        demangle(typeid(Identifier).name(), identifier);

        Log(identifier.c_str(), file, line, message, identity<LogLevel>());
    }

private:
    /**
     * Log method dispatcher by Loglevel.
     * @param identifier the identifier of the log message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @tparam LogLevel the level of the log message
     */
    template <class LogLevel>
    static void Log(const char* identifier, const char* file, const int line, const char* message, identity<LogLevel>)
    {
    }

    /**
     * Log a debug message
     * @param identifier the identifier of the log message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param identity<Debug> Debug dispatch value
     */
    static void Log(const char* identifier, const char* file, const int line, const char* message, identity<Debug>)
    {
        std::cout << "[DEBUG] [" << DateTime::Now() << "] [" << identifier << "] " << file << ", " << line << ": " << message << std::endl;
    }

    /**
     * Log an information message
     * @param identifier the identifier of the log message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param identity<Info> Info dispatch value
     */
    static void Log(const char* identifier, const char* file, const int line, const char* message, identity<Info>)
    {
        std::cout << "[INFO ] [" << DateTime::Now() << "] [" << identifier << "] " << file << ", " << line << ": " << message << std::endl;
    }

    /**
     * Log an error message
     * @param identifier the identifier of the log message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param identity<Error> Error dispatch value
     */
    static void Log(const char* identifier, const char* file, const int line, const char* message, identity<Error>)
    {
        std::cout << "[ERROR] [" << DateTime::Now() << "] [" << identifier << "] " << file << ", " << line << ": " << message << std::endl;
    }

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(Logger);
};

#endif
