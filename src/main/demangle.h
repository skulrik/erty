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
#ifndef _DEMANGLE_H_
#define _DEMANGLE_H_

#include <string>

namespace erty
{

/**
 * Return the demangled version of an identifier.
 * Must be build with the HAVE_CXA_DEMANGLE option.
 * @param name the name to demangle.
 * @return the demangled version of the name is returnedis this parameter.
 */
std::string demangle(const char* name);

}

#endif
