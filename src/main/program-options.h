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
#ifndef _PROGRAM_OPTIONS_H_
#define _PROGRAM_OPTIONS_H_

#include "utils.h"
#include <string>
#include <boost/program_options.hpp>
#include <boost/format.hpp>

namespace po = boost::program_options;

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
 * Class that manage all programs options.
 */
class ProgramOptions
{
public:
    /**
     * Create a new programs options manager class, by specifying command line arguments.
     * @param argc The number of command line arguments
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
     * @return the configuration file path (default to conf/logging.xml.
     */
    std::string getConfigFilePath();

    /**
     * Return the program usage.
     * @return All the available program options.
     */
    std::string getUsage();

private:
    /** All the available options. */
    po::options_description _desc;

    /** All the defined options and their values. */
    po::variables_map _vm;

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(ProgramOptions);
};

#endif
