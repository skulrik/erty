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
#ifndef _CONFIGURATION_PARSER_H_
#define _CONFIGURATION_PARSER_H_

#include "utils.h"

#include <exception>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

/**
 * Class that can browse a confuguraton property tree.
 */
class ConfigurationParser
{
public:

    /**
     * Check if a single property is present in a property tree.
     * @param pt a property tree.
     * @param childName the name of the property to check.
     * @return true if the property is present, else false.
     */
    static bool hasChild(ptree& pt, const std::string& childName)
    {
        try
        {
            pt.get(childName, "");
            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }

    /**
     * Check if a mutiple property is present in a property tree.
     * @param pt a property tree.
     * @param childName the name of the property to check.
     * @return true if the property is present, else false.
     */
    static bool hasChilds(ptree& pt, const std::string& childsName)
    {
        try
        {
            pt.get_child(childsName);
            return true;
        }
        catch (std::exception& e)
        {
            return false;
        }
    }

private:
    DISALLOW_DEFAULT_COPY_AND_ASSIGN(ConfigurationParser);
};

#endif
