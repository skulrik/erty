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
#ifndef _LOG_LEVEL_FACTORY_H_
#define _LOG_LEVEL_FACTORY_H_

#include "log-level.h"

#include <string>

namespace erty
{

/**
 * Factory class to that produce LogLevel.
 */
class LogLevelFactory
{
public:
    virtual ~LogLevelFactory();

    /**
     * Create a LogLevel, base on its name.
     * @param levelName the level name.
     * @return a new LogLevel, or null if the name does not match any level.
     */
    virtual LogLevel* create(const std::string& levelName);
};

}

#endif
