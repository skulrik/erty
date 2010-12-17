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
#ifndef _DATETIME_H_
#define _DATETIME_H_

#include <boost/date_time/posix_time/posix_time.hpp>
#include "utils.h"

namespace erty
{

/**
 * Utility class to work with date and time values.
 */
class DateTime
{
public:

    /**
     * Return the current date and time.
     * @return the current date and time.
     */
    static boost::posix_time::ptime Now()
    {
        return boost::posix_time::second_clock::local_time();
    }

private:
    DISALLOW_DEFAULT_COPY_AND_ASSIGN(DateTime);
};

}

#endif
