#include "mainImpl.h"
#include "internationalization.h"

#include <iostream>

int mainImpl(int /*argc*/, char** /*argv*/)
{
    internationalize("CPP_APP_TEMPLATE", "/usr/share/locale");
    std::cout << _("Hello, World!") << std::endl;
    return EXIT_SUCCESS;
}
