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
#ifndef _CONSOLE_LOGGER_H_
#define _CONSOLE_LOGGER_H_

#include <string>
#include <iostream>
#include "logger.h"
#include "log-level.h"
#include "utils.h"

namespace erty
{

/** Logger that output messages to the console. */
class ConsoleLogger : public Logger
{
public:
    /** Instanciate a new logger that will log to the console. */
    ConsoleLogger()
    {
        uuid(__CLASS__);
    }

    /**
     * Write a message to the console.
     * @param message the message to log.
     */
    virtual void write(const LogLevel& /*level*/, const std::string& message)
    {
        std::cout << message;
    }
};

}

#endif
