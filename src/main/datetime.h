#pragma once
#ifndef _DATETIME_H_
#define _DATETIME_H_

#include <boost/date_time/posix_time/posix_time.hpp>
#include "utils.h"

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

#endif
