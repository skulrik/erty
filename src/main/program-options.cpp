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
#include "program-options.h"
#include "internationalization.h"

#include <sstream>
#include <exception>

ProgramOptions::ProgramOptions(int argc, char** argv) :
    _desc(_("Allowed options")), _vm()
{
    _desc.add_options()
    ("help,h", _("Display this message"))
    ("config-file,c", po::value<std::string>()->default_value("conf/logging.xml"), "Configuration file path");

    try
    {
        po::store(po::parse_command_line(argc, argv, _desc), _vm);
    }
    catch (std::exception& e)
    {
        throw InvalidOptionException(e.what());
    }
    po::notify(_vm);
}

bool ProgramOptions::isHelpMode()
{
    return (_vm.count("help"));
}

std::string ProgramOptions::getConfigFilePath()
{
    return _vm["config-file"].as<std::string>();
}

std::string ProgramOptions::getUsage()
{
    std::stringstream ss;
    ss << "CPP_APP_TEMPLATE version 1.0"         << std::endl
       << _("Usage: CPP_APP_TEMPLATE [options]") << std::endl
       << _desc;
    return ss.str();
}
