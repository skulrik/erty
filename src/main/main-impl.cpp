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
#include "main-impl.h"
#include "ioc.h"
#include "internationalization.h"
#include "program-options.h"
#include "logging.h"
#include "signal-handler.h"

#include <iostream>
#include <exception>
#include <boost/function.hpp>

namespace erty
{

int mainImpl(int argc, char** argv, boost::function<int ()> applicationMain)
{
    int result = EXIT_SUCCESS;
    try
    {
        // Set segmentation fault handler
        signal(SIGSEGV, printStacktrace);

        // Set up locale using current LANG environment variable
        internationalize("erty", "/usr/share/locale");

        // Parse the command line program options, and register it into the IoC container
        ProgramOptions* programOptions = new ProgramOptions(argc, argv);
        IoC::Register<ProgramOptions>(programOptions);

        // Verify if help mode was requested
        if (programOptions->isHelpMode())
        {
            std::cout << programOptions->getUsage();
            result = EXIT_FAILURE;
        }

        // Set up the logging environment
        LoggingConf().setup();

        // Execute the main application code
        if (result != EXIT_FAILURE)
        {
            result = applicationMain();
        }
    }
    catch (std::exception& e)
    {
        ERROR_LOG("",e.what());
        std::cerr << e.what() << std::endl;
        result = EXIT_FAILURE;
    }

    if (result == EXIT_FAILURE)
    {
        std::cerr << "Failure" << std::endl;
        ERROR_LOG("","Failure");
    }

    return result;
}
// ----------------------------------------------------------------------------

}

