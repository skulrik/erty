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

class LogLevel
{
public:
    /** Return the logging level as a character string. */
    const char* level() const
    {
        return _level;
    }

    /** return the logging prioriry value. */
    unsigned int priority() const
    {
        return _priority;
    }

    /** return the logging prioriry value for syslog. */
    unsigned int syslogPriority() const
    {
        return _syslogPriority;
    }

protected:
    LogLevel(const char* level, const unsigned int priority, const unsigned int syslogPriority)
        : _level(level), _priority(priority), _syslogPriority(syslogPriority)
    {
    }

private:
    const char* _level;
    const unsigned int _priority;
    const unsigned int _syslogPriority;
};

/** Trigger a debug log message */
class Debug : public LogLevel
{
public:
    Debug() : LogLevel("DEBUG", 0, LOG_DEBUG)
    {
    }
};

/** trigger an information log message */
class Info : public LogLevel
{
public:
    Info() : LogLevel("INFO", 10, LOG_INFO)
    {
    }
};

/** Trigger a notice log message */
class Notice : public LogLevel
{
public:
    Notice() : LogLevel("NOTICE", 20, LOG_NOTICE)
    {
    }
};

/** Trigger a warning log message */
class Warning : public LogLevel
{
public:
    Warning() : LogLevel("WARNING", 30, LOG_WARNING)
    {
    }
};

/** Trigger an error log message */
class Error : public LogLevel
{
public:
    Error() : LogLevel("ERROR", 40, LOG_ERR)
    {
    }
};

/** Trigger a critical log message */
class Critical : public LogLevel
{
public:
    Critical() : LogLevel("CRITICAL", 50, LOG_CRIT)
    {
    }
};

/** Trigger an alert log message */
class Alert : public LogLevel
{
public:
    Alert() : LogLevel("ALERT", 60, LOG_ALERT)
    {
    }
};

/** Trigger an emergency log message */
class Emergency : public LogLevel
{
public:
    Emergency() : LogLevel("EMERGENCY", 70, LOG_EMERG)
    {
    }
};

#endif
