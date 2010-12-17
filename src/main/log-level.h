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
#ifndef _LOG_LEVEL_H_
#define _LOG_LEVEL_H_

namespace erty
{

/**
 * Base class of all log levels.
 */
class LogLevel
{
public:
    virtual ~LogLevel();

    /** Return the logging level as a character string. */
    const char* level() const;

    /** return the logging prioriry value. */
    unsigned int priority() const;

    /** return the logging prioriry value for syslog. */
    unsigned int syslogPriority() const;

protected:
    LogLevel(const char* level, const unsigned int priority, const unsigned int syslogPriority);

private:
    const char* _level;
    const unsigned int _priority;
    const unsigned int _syslogPriority;
};

/** Trigger a debug log message */
class Debug : public LogLevel
{
public:
    Debug();
};

/** trigger an information log message */
class Info : public LogLevel
{
public:
    Info();
};

/** Trigger a notice log message */
class Notice : public LogLevel
{
public:
    Notice();
};

/** Trigger a warning log message */
class Warning : public LogLevel
{
public:
    Warning();
};

/** Trigger an error log message */
class Error : public LogLevel
{
public:
    Error();
};

/** Trigger a critical log message */
class Critical : public LogLevel
{
public:
    Critical();
};

/** Trigger an alert log message */
class Alert : public LogLevel
{
public:
    Alert();
};

/** Trigger an emergency log message */
class Emergency : public LogLevel
{
public:
    Emergency();
};

/** Trigger a message that will not be logged. */
class NullLogLevel : public LogLevel
{
public:
    NullLogLevel();
};

}

#endif
