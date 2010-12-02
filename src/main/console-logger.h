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
    virtual void write(const std::string& message)
    {
        std::cout << message;
    }
};

#endif
