#include "program-options.h"
#include "internationalization.h"

#include <sstream>

ProgramOptions::ProgramOptions(int argc, char** argv) :
    desc(_("Allowed options")), vm()
{
    desc.add_options()
    ("help,h", _("Display this message"));

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
}

bool ProgramOptions::isHelpMode()
{
    return (vm.count("help"));
}

std::string ProgramOptions::getUsage()
{
    std::stringstream ss;
    ss << "CPP_APP_TEMPLATE version 1.0"         << std::endl
       << _("Usage: CPP_APP_TEMPLATE [options]") << std::endl
       << desc;
    return ss.str();
}
