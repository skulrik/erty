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
#include "logging.h"

int main(int argc, char** argv)
{
    REGISTER_LOG(Debug,ConsoleLogger);

    LOG_INFO(void,"Startup");
    int result = mainImpl(argc, argv);;
    if (result == 0)
    {
        LOG_INFO(void,"Shutdown");
    }
    else
    {
        LOG_ERROR(void,"Failure");
    }
    return result;
}
