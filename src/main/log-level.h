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

/** Trigger a debug log message */
struct Debug
{
    /** Return the logging level as a character string. */
    const char* level()
    {
        return "DEBUG";
    }

    /** Return the logging prioriry value. */
    unsigned int priority()
    {
        return 0;
    }
};

/** Trigger an information log message */
struct Info
{
    /** Return the logging level as a character string. */
    const char* level()
    {
        return "INFO ";
    }

    /** Return the logging prioriry value. */
    unsigned int priority()
    {
        return 10;
    }
};

/** Trigger an error log message */
struct Error
{
    /** Return the logging level as a character string. */
    const char* level()
    {
        return "ERROR";
    }

    /** Return the logging prioriry value. */
    unsigned int priority()
    {
        return 20;
    }
};

#endif
