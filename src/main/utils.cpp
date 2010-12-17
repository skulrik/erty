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
#include "utils.h"
#include "demangle.h"
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

namespace erty
{

std::string toLower(const std::string& str)
{
    std::string lowerStr = str;
    boost::to_lower(lowerStr);
    return lowerStr;
}
// ----------------------------------------------------------------------------

std::string toUpper(const std::string& str)
{
    std::string upperStr = str;
    boost::to_upper(upperStr);
    return upperStr;
}
// ----------------------------------------------------------------------------

bool isTrue(const std::string& value)
{
    std::string loweredValue = toLower(value);
    return ((loweredValue == "true") || (loweredValue == "t") || (loweredValue == "y") || (loweredValue == "yes") || (loweredValue == "on"));
}
// ----------------------------------------------------------------------------

bool isFalse(const std::string& value)
{
    std::string loweredValue = toLower(value);
    return ((loweredValue == "false") || (loweredValue == "f") || (loweredValue == "n") || (loweredValue == "no") || (loweredValue == "off"));
}
// ----------------------------------------------------------------------------

bool stringToBool(const std::string& value)
{
    if (isTrue(value))
    {
        return true;
    }
    else if (isFalse(value))
    {
        return false;
    }

    throw std::runtime_error((_F("Cannot convert string %1% to bool value.") % value).str());
}
// ----------------------------------------------------------------------------

}

