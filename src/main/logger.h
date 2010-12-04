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
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

/**
 * Base class of all logger classes.
 */
class Logger
{
public:
    virtual ~Logger(void) {}

    /**
     * Return the unique identifier of the logger.
     * @return the unique identifier of the logger.
     */
    virtual const std::string& uuid() const
    {
        return _uuid;
    }

    /**
     * Log a message.
     * All loggerclass must implement this method.
     * @param message the message to log.
     */
    virtual void write(const std::string& message) = 0;

protected:

    /**
     * Set the unique identifier of the logger.
     * Must be call in the constructor of each subclasses.
     * @param uuid the unique identifier of the logger.
     */
    void uuid(const std::string& uuid)
    {
        _uuid = uuid;
    }

private:
    /** The uniqueidentifier of the logger. */
    std::string _uuid;
};

/**
 * Compare two logger for equality.
 * @param a the first identifier.
 * @param b the second identifier.
 * @return true if the two logger have the same uuid, else false.
 */
inline bool operator==(const Logger& a, const Logger& b)
{
    return (a.uuid() == b.uuid());
}

#endif
