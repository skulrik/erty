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
 * Define a shorcut macro to get the current object class name.
 */
#define __CLASS__ demangle(typeid(*this).name()).c_str()
#endif
