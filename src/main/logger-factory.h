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
#ifndef _LOGGER_FACTORY_H_
#define _LOGGER_FACTORY_H_

#include "logger.h"
#include "console-logger.h"
#include "file-logger.h"
#include "syslog-logger.h"
#include "utils.h"

/**
 * Factory class to that produce Logger.
 */
class LoggerFactory
{
public:
    virtual ~LoggerFactory()
    {
    }

    /**
     * Create a Logger, base on its type.
     * @param type the logger type.
     * @param param parameter used in Logger constructor.
     * @return a new Logger, or null if the type does not match any logger.
     */
    virtual Logger* create(const std::string& type, const std::string& param)
    {
        std::string loweredType = toLower(type);

        if (loweredType == "console")
        {
            return new ConsoleLogger();
        }
        else if (loweredType == "file")
        {
            return new FileLogger(param.c_str());
        }
        else if (loweredType == "syslog")
        {
            return new SyslogLogger();
        }
        return 0;
    }
};

#endif
