#pragma once
#ifndef _PROGRAM_OPTIONS_H_
#define _PROGRAM_OPTIONS_H_

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class ProgramOptions
{
public:
    ProgramOptions(int argc, char** argv);

    bool isHelpMode();
    void printUsage();

private:
    int argc;
    char** argv;

    po::options_description desc;
    po::variables_map vm;
};

#endif
