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
#include "application.h"
#include "logging.h"
#include <iostream>
#include "internationalization.h"

/** Define the mail application logging component. */
#define LOG_MAIN_COMPONENT "main"

int applicationMain()
{
    INFO_LOG(LOG_MAIN_COMPONENT,"Startup");
    std::cout << _("Hello, World!") << std::endl;
    INFO_LOG(LOG_MAIN_COMPONENT,"Shutdown");
    return EXIT_SUCCESS;
}
