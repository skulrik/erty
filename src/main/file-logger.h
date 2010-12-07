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
#pragma once
#ifndef _FILE_LOGGER_H_
#define _FILE_LOGGER_H_

#include <string>
#include <fstream>
#include <sstream>
#include "logger.h"
#include "utils.h"

/**
 * Logger that output messages in a file.
 */
class FileLogger : public Logger
{
public:
    /**
     * Instanciate a new FileLogger.
     * @param fileName the file name of the file to ouput message into it.
     */
    FileLogger(const char* fileName)
    {
        std::stringstream ss;
        ss << __CLASS__ << "::" << fileName;
        uuid(ss.str());

        _file.open(fileName, std::ios::app);
        _file.seekp(std::ios::beg);
    }

    virtual ~FileLogger()
    {
        _file.close();
    }

    /**
     * Write a message in the file..
     * @param message the message to log.
     */
    virtual void write(const std::string& message)
    {
        _file << message;
        _file.flush();
    }

private:

    /** The file in which message are log. */
    std::ofstream _file;
};

#endif
