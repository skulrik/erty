#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

/**
 * Interface to all logger class.
 */
class Logger
{
public:
    virtual ~Logger(void) {}

    /**
     * Log a message.
     * All loggerclass must implement this method.
     * @param message the message to log.
     */
    virtual void write(const std::string& message) = 0;
};

#endif
