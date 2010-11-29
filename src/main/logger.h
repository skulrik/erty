#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include "datetime.h"
#include "identity.h"
#include "utils.h"

/** Trigger a debug log message */
struct Debug {}; //< Trigger a debug log message

/** Trigger an information log message */
struct Info  {}; //< Trigger an information log message

/** Trigger an error log message */
struct Error {}; //< Trigger an error log message

/**
 * Macro that pass the source file name and line number to the Logger class.
 * @param level the level of the log message
 * @param message the message to log
 */
#define LOG(level,message) Logger::Log<level>(__FILE__, __LINE__, message)

/**
 * Macro that pass the source file name and line number to the Logger class.
 * @param message the message to log
 */
#define LOG_DEBUG(message) Logger::Log<Debug>(__FILE__, __LINE__, message)

/**
 * Macro that pass the source file name and line number to the Logger class.
 * @param message the message to log
 */
#define LOG_INFO(message) Logger::Log<Info>(__FILE__, __LINE__, message)

/**
 * Macro that pass the source file name and line number to the Logger class.
 * @param message the message to log
 */
#define LOG_ERROR(message) Logger::Log<Error>(__FILE__, __LINE__, message)

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
     */
    template <class LogLevel>
    static void Log(const char* file, const int line, const char* message)
    {
        Log(file, line, message, identity<LogLevel>());
    }

private:
    /**
     * Log method dispatcher by Loglevel.
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @tparam LogLevel the level of the log message
     */
    template <class LogLevel>
    static void Log(const char* file, const int line, const char* message, identity<LogLevel>)
    {
    }

    /**
     * Log a debug message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param identity<Debug> Debug dispatch value
     */
    static void Log(const char* file, const int line, const char* message, identity<Debug>)
    {
        std::cout << "[DEBUG] [" << DateTime::Now() << "] " << file << ", " << line << ": " << message << std::endl;
    }

    /**
     * Log an information message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param identity<Info> Info dispatch value
     */
    static void Log(const char* file, const int line, const char* message, identity<Info>)
    {
        std::cout << "[INFO ] [" << DateTime::Now() << "] " << file << ", " << line << ": " << message << std::endl;
    }

    /**
     * Log an error message
     * @param file file name in which the log call was triggered.
     * @param line line in which the log call was triggered.
     * @param message the message to log.
     * @param identity<Error> Error dispatch value
     */
    static void Log(const char* file, const int line, const char* message, identity<Error>)
    {
        std::cout << "[ERROR] [" << DateTime::Now() << "] " << file << ", " << line << ": " << message << std::endl;
    }

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(Logger);
};

#endif
