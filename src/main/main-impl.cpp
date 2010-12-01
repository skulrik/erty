#include "main-impl.h"
#include "ioc.h"
#include "internationalization.h"
#include "program-options.h"
#include "logger.h"

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
