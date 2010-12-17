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
#ifndef _CONFIGURATION_PARSER_H_
#define _CONFIGURATION_PARSER_H_

#include "utils.h"

#include <exception>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

namespace erty
{

/**
 * ConfigurationParser  method can throws exception of this kind.
 */
class ConfigurationParserException : public std::runtime_error
{
public:
    /**
     * Create a new ConfigurationParserException with a specific message.
     * @param message the exception message.
     */
    ConfigurationParserException(const char* message) :
        std::runtime_error((_F("ConfigurationParserException: %1%") % message).str()) {}
};
/**
 * Class that can browse a confuguraton property tree.
 */
class ConfigurationParser
{
public:

    /**
     * Default constructor.
     */
    ConfigurationParser() : _pt()
    {
    }

    /**
     * Create a configuration parser by parsing a configuration file.
     * @param fileName the configuration file name.
     * @throw ConfigurationParserException
     */
    ConfigurationParser(const std::string& fileName) :_pt()
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

    /**
     * Check if a single property is present in the configuration.
     * @param childName the name of the property to check.
     * @return true if the property is present, else false.
     */
    bool hasChild(const std::string& childName)
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

    /**
     * Check if a mutiple property is present in the configuration.
     * @param childsName the name of the property to check.
     * @return true if the property is present, else false.
     */
    bool hasChilds(const std::string& childsName)
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

    /**
     * Return the property tree for of the configuration.
     * @return the configuration property tree.
     */
    ptree& getPT()
    {
        return _pt;
    }

private:
    /** The configuration property tree. */
    ptree _pt;

    DISALLOW_COPY_AND_ASSIGN(ConfigurationParser);
};

}

#endif
