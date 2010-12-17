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

#include "syslog-logger.h"
#include <syslog.h>
#include "logger.h"
#include "log-level.h"
#include "utils.h"
#include <string>

namespace erty
{

// ----------------------------------------------------------------------------
// SYSLOG LOGGER
// ----------------------------------------------------------------------------

SyslogLogger::SyslogLogger()
{
    uuid(__CLASS__);
    openlog(NULL, LOG_PID, 0);
}
// ----------------------------------------------------------------------------

SyslogLogger::~SyslogLogger()
{
    closelog();
}
// ----------------------------------------------------------------------------

void SyslogLogger::write(const LogLevel& level, const std::string& message)
{
    syslog(level.syslogPriority(), message.c_str(), 0);
}
// ----------------------------------------------------------------------------

}

