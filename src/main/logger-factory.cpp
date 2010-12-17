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
#include "logger-factory.h"
#include "logger.h"
#include "console-logger.h"
#include "file-logger.h"
#include "syslog-logger.h"
#include "utils.h"

namespace erty
{

// ----------------------------------------------------------------------------
// LOGGER FACTORY
// ----------------------------------------------------------------------------

LoggerFactory::~LoggerFactory()
{
}
// ----------------------------------------------------------------------------

Logger* LoggerFactory::create(const std::string& type, const std::string& param)
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
    return new NullLogger();;
}
// ----------------------------------------------------------------------------

}

