#pragma once
#ifndef _FILE_LOGGER_H_
#define _FILE_LOGGER_H_

#include <string>
#include <fstream>
#include <sstream>
#include "logger.h"

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
        ss << typeid(*this).name() << "::" << fileName;
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
