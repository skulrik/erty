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
#ifndef _UTILS_H_
#define _UTILS_H_

#include "demangle.h"
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

/**
 * Insert a copy constructor and a assignment operator that do nothing in a class.
 * Must be place under the private section of the class definition.
 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
       TypeName(const TypeName&) {};       \
       void operator=(const TypeName&) {}

/**
 * Insert a default constructor, copy constructor and a assignment operator that do nothing in a class.
 * Must be place under the private section of the class definition.
 */
#define DISALLOW_DEFAULT_COPY_AND_ASSIGN(TypeName) \
       TypeName() {};                              \
       TypeName(const TypeName&) {};               \
       void operator=(const TypeName&) {}

/**
 * Define a shortcut for boost::format function.
 */
#define _F boost::format

/**
 * Define a shortcut to get the type name of an object.
 * @param object the object to retrieve it type name.
 */
#define DEMANGLE(object) demangle(typeid(object).name()).c_str()

/**
 * Define a shorcut macro to get the current object class name.
 */
#define __CLASS__ demangle(typeid(*this).name()).c_str()

/**
 * Return a lowercase version of a string.
 * @param str the string to lowercase.
 * @return the lowercase version of the string.
 */
inline std::string toLower(const std::string& str)
{
    std::string lowerStr = str;
    boost::to_lower(lowerStr);
    return lowerStr;
}

/**
 * Return a uppercase version of a string.
 * @param str the string to uppercase.
 * @return the uppercase version of the string.
 * @throw std::runtime_error
 */
inline std::string toUpper(const std::string& str)
{
    std::string upperStr = str;
    boost::to_upper(upperStr);
    return upperStr;
}

inline bool stringToBool(const std::string& value)
{
    std::string loweredValue = toLower(value);

    if ((loweredValue == "true") || (loweredValue == "t") || (loweredValue == "y") || (loweredValue == "yes") || (loweredValue == "on"))
    {
        return true;
    }
    else if ((loweredValue == "false") || (loweredValue == "f") || (loweredValue == "n") || (loweredValue == "no") || (loweredValue == "off"))
    {
        return false;
    }

    throw std::runtime_error((_F("Cannot convert string %1% to bool value.") % value).str());
}

#endif
