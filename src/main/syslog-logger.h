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
#ifndef _SYSLOG_LOGGER_H_
#define _SYSLOG_LOGGER_H_

#include <string>
#include <syslog.h>
#include "logger.h"
#include "log-level.h"
#include "utils.h"

/** Logger that output messages to the console. */
class SyslogLogger : public Logger
{
public:
    /** Instanciate a new logger that will log using the syslog facility. */
    SyslogLogger()
    {
        uuid(__CLASS__);
        openlog(NULL, LOG_PID, 0);
    }

    /** Closethe syslog log. */
    virtual ~SyslogLogger()
    {
        closelog();
    }

    /**
     * Send a message to syslog.
     * @param level the log level of the message.
     * @param message the message to log.
     */
    virtual void write(const LogLevel& level, const std::string& message)
    {
        syslog(level.syslogPriority(), message.c_str(), 0);
    }
};

#endif
