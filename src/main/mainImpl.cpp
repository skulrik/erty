#include "mainImpl.h"
#include "internationalization.h"
#include "program-options.h"

#include <iostream>

int mainImpl(int argc, char** argv)
{
    // Set up locale using current LANG environment variable
    internationalize("CPP_APP_TEMPLATE", "/usr/share/locale");

    // Parse the command line program options
    ProgramOptions programOptions(argc, argv);
    if (programOptions.isHelpMode())
    {
        programOptions.printUsage();
        return EXIT_FAILURE;
    }

    // Execute the main application code
    std::cout << _("Hello, World!") << std::endl;
    return EXIT_SUCCESS;
}
