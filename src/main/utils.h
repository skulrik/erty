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
#ifndef _UTILS_H_
#define _UTILS_H_

#include "demangle.h"
#include <string>
#include <boost/format.hpp>

namespace erty
{

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
#define DEMANGLE(object) erty::demangle(typeid(object).name()).c_str()

/**
 * Define a shorcut macro to get the current object class name.
 */
#define __CLASS__ erty::demangle(typeid(*this).name()).c_str()

/**
 * Return a lowercase version of a string.
 * @param str the string to lowercase.
 * @return the lowercase version of the string.
 */
std::string toLower(const std::string& str);

/**
 * Return a uppercase version of a string.
 * @param str the string to uppercase.
 * @return the uppercase version of the string.
 * @throw std::runtime_error
 */
std::string toUpper(const std::string& str);

/**
 * Verify if a string represent a true value.
 * @param value the string to verify.
 * @return true if the string represent a true value, else false.
 */
bool isTrue(const std::string& value);

/**
 * Verify if a string represent a false value.
 * @param value the string to verify.
 * @return true if the string represent a false value, else false.
 */
bool isFalse(const std::string& value);

/**
 * Return the boolean value of a string.
 * @param value the string to verify.
 * @return true if the string represent a true value, false if the string represent a false value.
 * @throw std::runtime_exception if the string represent neither a true or false value.
 */
bool stringToBool(const std::string& value);

}

#endif
