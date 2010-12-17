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
#ifndef _PROGRAM_OPTIONS_H_
#define _PROGRAM_OPTIONS_H_

#include "utils.h"
#include <string>
#include <boost/program_options.hpp>
#include <boost/format.hpp>

namespace po = boost::program_options;

namespace erty
{

/**
 * Exception thrown when an invalid option in pass to the application.
 */
class InvalidOptionException : public std::runtime_error
{
public:
    /**
     * Create a new InvalidOptionException with a specific message.
     * @param message the exception message.
     */
    InvalidOptionException(const char* message) :
        std::runtime_error((_F("InvalidOptionException: %1%") % message).str()) {}
};

/**
 * Exception thrown when an error while parsing the configured options.
 */
class ConfiguredOptionParsingException : public std::runtime_error
{
public:
    /**
     * Create a new ConfiguredOptionParsingException with a specific message.
     * @param message the exception message.
     */
    ConfiguredOptionParsingException(const char* message) :
        std::runtime_error((_F("ConfiguredOptionParsingException: %1%") % message).str()) {}
};

/**
 * Helper function that retrieve an option from a variable map.
 * @param vm the variable map.
 * @param optionName the name of the option.
 * @tparam the option type.
 * @return the option value.
 */
template <class T>
T getOptionValue(const po::variables_map& vm, const std::string& optionName);

/**
 * Class that manage all programs options.
 * Some options are hard coded, and users can defined other in the configuration file.
 */
class ProgramOptions
{
public:
    /**
     * Create a new programs options manager class, by specifying command line arguments.
     * @param argc The number of command line arguments.
     * @param argv The list of command line arguments.
     * @throw InvalidOptionException
     */
    ProgramOptions(int argc, char** argv);

    /**
     * Verify if the program was call with the help switch options.
     * @return true if the help switch is present, else false.
     */
    bool isHelpMode();

    /**
     * Return the path to the configuration file, specified with the --config-file option.
     * @return the configuration file path (default to conf/config.xml.
     */
    std::string getConfigFilePath();

    /**
     * Return the program usage.
     * @return All the available program options.
     */
    std::string getUsage();

    /**
     * Return the value of for an option.
     * @param optionName the name op the option.
     * @tparam T the type of the option.
     * @return the value of the option.
     */
    template<class T>
    T get(const std::string& optionName)
    {
        return getOptionValue<T>(_vm, optionName);
    }

private:

    /**
     * Load the hard coded options.
     */
    void loadPreDefinedOptions();

    /**
     * Load the user configured options from the configuration file.
     * @throw ConfiguredOptionParsingException
     */
    void loadConfiguredOptions();

    /**
     * Add an available option.
     * @param name the option name.
     * @param desc the option description.
     * @param type the option type.
     * @param value the option value,
     */
    void addOption(const std::string& name, const std::string& desc, const std::string& type, const std::string& value);

    /**
     * Apply the command line parameters the the variable map.
     * @param argc The number of command line arguments.
     * @param argv The list of command line arguments.
     * @param vm the variable map.
     * @param allowUnknoww indicate if command line parameter not defined are allowed.
     */
    void applyCommandLineValues(int argc, char** argv, po::variables_map& vm, bool allowUnknown);

    /** All the available options. */
    po::options_description _desc;

    /** All the defined options and their values. */
    po::variables_map _vm;

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(ProgramOptions);
};

}

#endif
