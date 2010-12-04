#include "program-options.h"
#include "internationalization.h"

#include <sstream>
#include <exception>

ProgramOptions::ProgramOptions(int argc, char** argv) :
    _desc(_("Allowed options")), _vm()
{
    _desc.add_options()
    ("help,h", _("Display this message"));

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

std::string ProgramOptions::getUsage()
{
    std::stringstream ss;
    ss << "CPP_APP_TEMPLATE version 1.0"         << std::endl
       << _("Usage: CPP_APP_TEMPLATE [options]") << std::endl
       << _desc;
    return ss.str();
}
