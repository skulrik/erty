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
#include "main-impl.h"
#include "ioc.h"
#include "internationalization.h"
#include "program-options.h"
#include "logging.h"

#include <iostream>
#include <exception>

int mainImpl(int argc, char** argv)
{
    try
    {
        // Set up locale using current LANG environment variable
        internationalize("CPP_APP_TEMPLATE", "/usr/share/locale");

        // Parse the command line program options, and register it into the IoC container
        ProgramOptions* programOptions = new ProgramOptions(argc, argv);
        IoC::Register<ProgramOptions>(programOptions);

        // Verify if help mode was requested
        if (programOptions->isHelpMode())
        {
            std::cout << programOptions->getUsage();
            return EXIT_FAILURE;
        }


        // Execute the main application code
        std::cout << _("Hello, World!") << std::endl;
        return EXIT_SUCCESS;
    }
    catch (std::exception& e)
    {
        LOG_ERROR(void,e.what());
        return EXIT_FAILURE;
    }
}
