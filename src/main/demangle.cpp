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
#include "demangle.h"
#include <cxxabi.h>

namespace erty
{

#ifdef HAVE_CXA_DEMANGLE
std::string demangle(const char* name)
{
    char buf[1024];
    size_t size=sizeof(buf);
    int status;
    abi::__cxa_demangle (name,
                         buf,
                         &size,
                         &status);
    return std::string(buf);
}
#else
std::string demangle(const char* name)
{
    return std::string(name);
}
#endif

}

