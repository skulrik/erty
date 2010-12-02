#pragma once
#ifndef _CONSOLE_LOGGER_H_
#define _CONSOLE_LOGGER_H_

#include <string>
#include <iostream>
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
    LoggerFile(const char* fileName)
    {
        file.open(fileName, std::ios::app);
        file.seekp(std::ios::beg);
    }

    virtual ~LoggerFile()
    {
        file.close();
    }

    virtual void write(const std::string& message)
    {
        file << messsage;
        file.flush();
    }

private:
    std::ofstream file;
};

#endif
