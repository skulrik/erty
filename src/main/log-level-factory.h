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
#ifndef _LOG_LEVEL_FACTORY_H_
#define _LOG_LEVEL_FACTORY_H_

#include "log-level.h"
#include "utils.h"

/**
 * Factory class to that produce LogLevel.
 */
class LogLevelFactory
{
public:
    virtual ~LogLevelFactory()
    {
    }

    /**
     * Create a LogLevel, base on its name.
     * @param levelName the level name.
     * @return a new LogLevel, or null if the name does not match any level.
     */
    virtual LogLevel* create(const std::string& levelName)
    {
        std::string loweredLevelName = toLower(levelName);

        if (loweredLevelName == "debug")
        {
            return new Debug();
        }
        else if (loweredLevelName == "info")
        {
            return new Info();
        }
        else if (loweredLevelName == "notice")
        {
            return new Notice();
        }
        else if (loweredLevelName == "warning")
        {
            return new Warning();
        }
        else if (loweredLevelName == "error")
        {
            return new Error();
        }
        else if (loweredLevelName == "critical")
        {
            return new Critical();
        }
        else if (loweredLevelName == "alert")
        {
            return new Alert();
        }
        else if (loweredLevelName == "emergency")
        {
            return new Emergency();
        }
        return new NullLogLevel();;
    }
};

#endif
