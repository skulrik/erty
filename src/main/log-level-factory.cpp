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

#include "log-level-factory.h"
#include "log-level.h"
#include "utils.h"

namespace erty
{

// ----------------------------------------------------------------------------
// LOG LEVEL FACTORY
// ----------------------------------------------------------------------------

LogLevelFactory::~LogLevelFactory()
{
}
// ----------------------------------------------------------------------------

LogLevel* LogLevelFactory::create(const std::string& levelName)
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
// ----------------------------------------------------------------------------

}

