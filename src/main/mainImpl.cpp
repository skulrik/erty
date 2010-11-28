#include "mainImpl.h"
#include "ioc.h"
#include "internationalization.h"
#include "program-options.h"

#include <iostream>
#include <exception>

int mainImpl(int argc, char** argv)
{
    try
    {
        // Set up locale using current LANG environment variable
        internationalize("CPP_APP_TEMPLATE", "/usr/share/locale");

        // Parse the command line program options
        ProgramOptions* programOptions = new ProgramOptions(argc, argv);
        if (programOptions->isHelpMode())
        {
            std::cout << programOptions->getUsage();
            return EXIT_FAILURE;
        }

        IoC::Register<ProgramOptions>(programOptions);

        // Execute the main application code
        std::cout << _("Hello, World!") << std::endl;
        return EXIT_SUCCESS;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
