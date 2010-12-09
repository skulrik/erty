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
#ifndef _LOGGING_CONF_H_
#define _LOGGING_CONF_H_

#include "log-level-factory.h"
#include "logger-factory.h"
#include "ioc.h"

#include <stdexcept>
#include <string>
#include <list>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

/**
 * LoggingConf  method can throws exception of this kind.
 */
class LoggingConfException : public std::runtime_error
{
public:
    /**
     * Create a new LoggingConfException with a specific message.
     * @param message the exception message.
     */
    LoggingConfException(const char* message) :
        std::runtime_error((_F("LoggingConfException: %1%") % message).str()) {}
};

/**
 * Class used to set up a logging environment, by loading a configuration file.
 */
class LoggingConf
{
public:

    /**
     * Create logging setup by parsing a logging configuration file.
     * @param fileName the logging configuration file name.
     */
    virtual void load(const std::string& fileName) const
    {
        ptree pt;

        try
        {
            read_xml(fileName, pt);
            registerLogComponents(pt);
            registerLoggers(pt);
        }
        catch (std::exception& e)
        {
            throw LoggingConfException(e.what());
        }
    }

private:

    /**
     * Parse the components node of the property tree, to register logging components.
     * @param pt the property tree
     */
    void registerLogComponents(ptree& pt) const
    {
        LogLevelFactory& logLevelFactory = getLogLevelFactory();
        BOOST_FOREACH(ptree::value_type &v, pt.get_child("logging.components"))
        {
            std::string componentName = v.second.get<std::string>("name");
            std::string componentLevel = v.second.get<std::string>("level");
            std::auto_ptr<LogLevel> level(logLevelFactory.create(componentLevel));

            LoggerHolder::RegisterLogComponent(componentName, *level);
        }
    }

    /**
     * Parse the loggers node of the property tree, to register loggers.
     * @param pt the property tree
     */
    void registerLoggers(ptree& pt) const
    {
        LoggerFactory& loggerFactory = getLoggerFactory();
        BOOST_FOREACH(ptree::value_type &v, pt.get_child("logging.loggers"))
        {
            std::string loggerType = v.second.get<std::string>("type");
            std::string loggerParam;
            if (loggerType == "file")
            {
                loggerParam = v.second.get<std::string>("file-name");
            }
            LoggerHolder::RegisterLogger(loggerFactory.create(loggerType, loggerParam));
        }
    }

    /**
     * Retrieve the log level factory from the IoC container.
     * Create it if its not there.
     * @return the log level factory.
     */
    LogLevelFactory& getLogLevelFactory() const
    {
        LogLevelFactory* logLevelFactory = 0;

        if (IoC::IsRegistered<LogLevelFactory>())
        {
            logLevelFactory = IoC::Resolve<LogLevelFactory>();
        }
        else
        {
            logLevelFactory = new LogLevelFactory();
            IoC::Register<LogLevelFactory>(logLevelFactory);
        }

        return *logLevelFactory;
    }

    /**
     * Retrieve the logger factory from the IoC container.
     * Create it if its not there.
     * @return the logger factory.
     */
    LoggerFactory& getLoggerFactory() const
    {
        LoggerFactory* loggerFactory = 0;

        if (IoC::IsRegistered<LoggerFactory>())
        {
            loggerFactory = IoC::Resolve<LoggerFactory>();
        }
        else
        {
            loggerFactory = new LoggerFactory();
            IoC::Register<LoggerFactory>(loggerFactory);
        }

        return *loggerFactory;
    }
};



#endif
