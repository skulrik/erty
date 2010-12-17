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

#include "configuration-parser.h"
#include "utils.h"

#include <exception>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

namespace erty
{

// ----------------------------------------------------------------------------
// CONFIGURATION PARSER EXCEPTION
// ----------------------------------------------------------------------------

ConfigurationParserException::ConfigurationParserException(const char* message) :
    std::runtime_error((_F("ConfigurationParserException: %1%") % message).str())
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// CONFIGURATION PARSER
// ----------------------------------------------------------------------------

ConfigurationParser::ConfigurationParser() : _pt()
{
}
// ----------------------------------------------------------------------------

ConfigurationParser::ConfigurationParser(const std::string& fileName) :_pt()
{
    try
    {
        read_xml(fileName, _pt);
    }
    catch (std::exception& e)
    {
        throw ConfigurationParserException(e.what());
    }
}
// ----------------------------------------------------------------------------

bool ConfigurationParser::hasChild(const std::string& childName)
{
    try
    {
        _pt.get(childName, "");
        return true;
    }
    catch (std::exception& e)
    {
        return false;
    }
}
// ----------------------------------------------------------------------------

bool ConfigurationParser::hasChilds(const std::string& childsName)
{
    try
    {
        _pt.get_child(childsName);
        return true;
    }
    catch (std::exception& e)
    {
        return false;
    }
}
// ----------------------------------------------------------------------------

ptree& ConfigurationParser::getPT()
{
    return _pt;
}
// ----------------------------------------------------------------------------

}

