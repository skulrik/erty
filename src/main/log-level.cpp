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

#include "log-level.h"
#include <limits>
#include <syslog.h>

namespace erty
{

// ----------------------------------------------------------------------------
// LOG LEVEL
// ----------------------------------------------------------------------------

LogLevel::~LogLevel()
{
}
// ----------------------------------------------------------------------------

const char* LogLevel::level() const
{
    return _level;
}
// ----------------------------------------------------------------------------

unsigned int LogLevel::priority() const
{
    return _priority;
}
// ----------------------------------------------------------------------------

unsigned int LogLevel::syslogPriority() const
{
    return _syslogPriority;
}
// ----------------------------------------------------------------------------

LogLevel::LogLevel(const char* level, const unsigned int priority, const unsigned int syslogPriority) :
    _level(level), _priority(priority), _syslogPriority(syslogPriority)
{
}
// ----------------------------------------------------------------------------

Debug::Debug() :
    LogLevel("DEBUG", 0, LOG_DEBUG)
{
}
// ----------------------------------------------------------------------------

Info::Info() :
    LogLevel("INFO", 10, LOG_INFO)
{
}
// ----------------------------------------------------------------------------

Notice::Notice() :
    LogLevel("NOTICE", 20, LOG_NOTICE)
{
}
// ----------------------------------------------------------------------------

Warning::Warning() :
    LogLevel("WARNING", 30, LOG_WARNING)
{
}
// ----------------------------------------------------------------------------

Error::Error() :
    LogLevel("ERROR", 40, LOG_ERR)
{
}
// ----------------------------------------------------------------------------

Critical::Critical() :
    LogLevel("CRITICAL", 50, LOG_CRIT)
{
}
// ----------------------------------------------------------------------------

Alert::Alert() :
    LogLevel("ALERT", 60, LOG_ALERT)
{
}
// ----------------------------------------------------------------------------

Emergency::Emergency() :
    LogLevel("EMERGENCY", 70, LOG_EMERG)
{
}
// ----------------------------------------------------------------------------

NullLogLevel::NullLogLevel() :
    LogLevel("NULL", std::numeric_limits<unsigned int>::max(), -1)
{
}
// ----------------------------------------------------------------------------

}

