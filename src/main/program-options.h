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
        std::runtime_error((boost::format("InvalidOptionException: %1%") % message).str()) {}
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
     */
    ProgramOptions(int argc, char** argv);

    /**
     * Verify if the program was call with the help switch options.
     * @return true if the help switch is present, else false.
     */
    bool isHelpMode();

    /**
     * Return the program usage.
     * @return All the available program options.
     */
    std::string getUsage();

private:
    /** All the available options. */
    po::options_description desc;

    /** All the defined options and their values. */
    po::variables_map vm;

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(ProgramOptions);
};

#endif
