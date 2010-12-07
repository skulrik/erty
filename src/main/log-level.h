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
#ifndef _LOG_LEVEL_H_
#define _LOG_LEVEL_H_

#include <syslog.h>

struct LogLevel
{
    /** Return the logging level as a character string. */
    virtual const char* level() const = 0;

    /** return the logging prioriry value. */
    virtual unsigned int priority() const = 0;

    /** return the logging prioriry value for syslog. */
    virtual unsigned int syslogPriority() const = 0;
};

/** Trigger a debug log message */
struct Debug : public LogLevel
{
    /** Return the debug logging level as a character string. */
    const char* level() const
    {
        return "DEBUG";
    }

    /** return the debug logging prioriry value. */
    unsigned int priority() const
    {
        return 0;
    }

    /** return the debug logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_DEBUG;
    }
};

/** trigger an information log message */
struct Info : public LogLevel
{
    /** return the info logging level as a character string. */
    const char* level() const
    {
        return "INFO";
    }

    /** return the info logging prioriry value. */
    unsigned int priority() const
    {
        return 10;
    }

    /** return the info logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_INFO;
    }
};

/** Trigger a notice log message */
struct Notice : public LogLevel
{
    /** Return the notice logging level as a character string. */
    const char* level() const
    {
        return "NOTICE";
    }

    /** Return the notice logging prioriry value. */
    unsigned int priority() const
    {
        return 20;
    }

    /** return the notice logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_NOTICE;
    }
};

/** Trigger a warning log message */
struct Warning : public LogLevel
{
    /** Return the warning logging level as a character string. */
    const char* level() const
    {
        return "WARNING";
    }

    /** Return the warning logging prioriry value. */
    unsigned int priority() const
    {
        return 30;
    }

    /** return the warning logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_WARNING;
    }
};

/** Trigger an error log message */
struct Error : public LogLevel
{
    /** Return the error logging level as a character string. */
    const char* level() const
    {
        return "ERROR";
    }

    /** Return the error logging prioriry value. */
    unsigned int priority() const
    {
        return 40;
    }

    /** return the error logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_ERR;
    }
};

/** Trigger a critical log message */
struct Critical : public LogLevel
{
    /** Return the critical logging level as a character string. */
    const char* level() const
    {
        return "CRITICAL";
    }

    /** Return the critical logging prioriry value. */
    unsigned int priority() const
    {
        return 50;
    }

    /** return the critical logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_CRIT;
    }
};

/** Trigger an alert log message */
struct Alert : public LogLevel
{
    /** Return the alert logging level as a character string. */
    const char* level() const
    {
        return "ALERT";
    }

    /** Return the alert logging prioriry value. */
    unsigned int priority() const
    {
        return 60;
    }

    /** return the alert logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_ALERT;
    }
};

/** Trigger an emergency log message */
struct Emergency : public LogLevel
{
    /** Return the emergency logging level as a character string. */
    const char* level() const
    {
        return "EMERGENCY";
    }

    /** Return the emergency logging prioriry value. */
    unsigned int priority() const
    {
        return 70;
    }

    /** return the emergency logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return LOG_EMERG;
    }
};

#endif
