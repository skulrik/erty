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
#include "program-options.h"
#include "internationalization.h"
#include "configuration-parser.h"
#include "ioc.h"

#include <sstream>
#include <exception>

#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <iostream>

using boost::property_tree::ptree;

namespace erty
{

template <class T>
T getOptionValue(const po::variables_map& vm, const std::string& optionName)
{
    return vm[optionName].as<T>();
}

template <>
bool getOptionValue<bool>(const po::variables_map& vm, const std::string& optionName)
{
    return vm.count(optionName);
}

template <>
int getOptionValue<int>(const po::variables_map& vm, const std::string& optionName)
{
    return vm[optionName].as<int>();
}

ProgramOptions::ProgramOptions(int argc, char** argv) :
    _desc(_("Allowed options")), _vm()
{
    // First pass to load hard coded config option (that can specify a configuration file, with others option in it.
    loadPreDefinedOptions();
    applyCommandLineValues(argc, argv, _vm, true);
    po::notify(_vm);

    // Second pass to load config option defined in the configuration file.
    loadConfiguredOptions();
    applyCommandLineValues(argc, argv, _vm, false);
    po::notify(_vm);
}

void ProgramOptions::loadPreDefinedOptions()
{
    _desc.add_options()
    ("help,h", _("Display this message"))
    ("config-file,c", po::value<std::string>()->default_value("conf/config.xml"), _("Configuration file path"));
}

void ProgramOptions::loadConfiguredOptions()
{
    ptree pt;

    try
    {
        std::string configFileName = getConfigFilePath();
        ConfigurationParser* config = new ConfigurationParser(configFileName);
        IoC::Register<ConfigurationParser>(config);
        if (config->hasChilds("configuration.options"))
        {
            BOOST_FOREACH(ptree::value_type &v, config->getPT().get_child("configuration.options"))
            {
                std::string optionName = v.second.get<std::string>("name");
                std::string optionDesc = v.second.get<std::string>("description");
                std::string optionType = v.second.get<std::string>("type");
                std::string optionValue = v.second.get<std::string>("value");

                addOption(optionName, optionDesc, optionType, optionValue);
            }
        }
    }
    catch (std::exception& e)
    {
        throw ConfiguredOptionParsingException(e.what());
    }
}

void ProgramOptions::addOption(const std::string& name, const std::string& desc, const std::string& type, const std::string& value)
{
    std::string loweredType = toLower(type);
    if (loweredType == "string")
    {
        _desc.add_options()
        (name.c_str(), po::value<std::string>()->default_value(value.c_str()), _(desc.c_str()));
    }
    else if (loweredType == "boolean")
    {
        _desc.add_options()
        (name.c_str(), _(desc.c_str()));

        if (stringToBool(value))
        {
            _vm.insert(std::pair<std::string, boost::program_options::variable_value>(name, boost::program_options::variable_value::variable_value()));
        }
    }
    else if (loweredType == "integer")
    {
        _desc.add_options()
        (name.c_str(), po::value<int>()->default_value(boost::lexical_cast<int>(value)), _(desc.c_str()));
    }
    else
    {
        throw std::runtime_error((_F("Unknown program option type %1% for option %2%") % type % name).str());
    }
}

void ProgramOptions::applyCommandLineValues(int argc, char** argv, po::variables_map& vm, bool allowUnknown)
{
    try
    {
        if (allowUnknown)
        {
            po::store(po::command_line_parser(argc, argv).options(_desc).allow_unregistered().run(), vm);
        }
        else
        {
            po::store(po::parse_command_line(argc, argv, _desc), vm);
        }
    }
    catch (std::exception& e)
    {
        throw InvalidOptionException(e.what());
    }
}

std::string ProgramOptions::getConfigFilePath()
{
    return get<std::string>("config-file");
}

bool ProgramOptions::isHelpMode()
{
    return get<bool>("help");
}

std::string ProgramOptions::getUsage()
{
    std::stringstream ss;
    ss << "erty version 1.0"         << std::endl
       << _("Usage: erty [options]") << std::endl
       << _desc;
    return ss.str();
}

}

