/*
===============================================================================
    COPYING PERMISSION STATEMENT
===============================================================================
    This file is part of erty.

    erty is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    erty is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with erty.  If not, see <http://www.gnu.org/licenses/>.
===============================================================================
*/

#include "file-logger.h"
#include "logger.h"
#include "log-level.h"
#include "utils.h"
#include <string>
#include <fstream>
#include <sstream>

namespace erty
{

// ----------------------------------------------------------------------------
// FILE LOGGER
// ----------------------------------------------------------------------------

FileLogger::FileLogger(const char* fileName)
{
    std::stringstream ss;
    ss << __CLASS__ << "::" << fileName;
    uuid(ss.str());

    _file.open(fileName, std::ios::app);
    _file.seekp(std::ios::beg);
}
// ----------------------------------------------------------------------------

FileLogger::~FileLogger()
{
    _file.close();
}
// ----------------------------------------------------------------------------

void FileLogger::write(const LogLevel& /*level*/, const std::string& message)
{
    _file << message;
    _file.flush();
}
// ----------------------------------------------------------------------------

}

