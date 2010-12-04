#pragma once
#ifndef _CONSOLE_LOGGER_H_
#define _CONSOLE_LOGGER_H_

#include <string>
#include <iostream>
#include "logger.h"

/**
 * Logger that output messages to the console.
 */
class ConsoleLogger : public Logger
{
public:
    /**
     * Instanciate a new logger that will log to the console.
     */
    ConsoleLogger()
    {
        uuid(typeid(*this).name());
    }

    /**
     * Write a message to the console.
     * @param message the message to log.
     */
    virtual void write(const std::string& message)
    {
        std::cout << message;
    }
};

#endif
