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

#include "logger.h"
#include "log-level.h"
#include "utils.h"
#include <string>

namespace erty
{

// ----------------------------------------------------------------------------
// LOGGER
// ----------------------------------------------------------------------------

Logger::~Logger(void)
{
}
// ----------------------------------------------------------------------------

const std::string& Logger::uuid() const
{
    return _uuid;
}
// ----------------------------------------------------------------------------

void Logger::uuid(const std::string& uuid)
{
    _uuid = uuid;
}
// ----------------------------------------------------------------------------

bool operator==(const Logger& a, const Logger& b)
{
    return (a.uuid() == b.uuid());
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// NULL LOGGER
// ----------------------------------------------------------------------------

NullLogger::NullLogger()
{
    uuid(__CLASS__);
}
// ----------------------------------------------------------------------------

void NullLogger::write(const LogLevel& /*level*/, const std::string& /*message*/)
{
}
// ----------------------------------------------------------------------------

}

