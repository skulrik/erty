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
#pragma once
#ifndef _LOGGING_CONF_H_
#define _LOGGING_CONF_H_

#include "log-level-factory.h"
#include "logger-factory.h"
#include "ioc.h"
#include "configuration-parser.h"

#include <stdexcept>
#include <string>
#include <list>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

namespace erty
{

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
     * Setup the logging environment from the current configuration.
     */
    void setup()
    {
        registerLogComponents();
        registerLoggers();
    }

private:

    /**
     * Parse the components node of the configuration, to register logging components.
     */
    void registerLogComponents() const
    {
        ConfigurationParser& config = IoC::Inject<ConfigurationParser>(false);
        if (config.hasChilds("configuration.logging.components"))
        {
            LogLevelFactory& logLevelFactory = IoC::Inject<LogLevelFactory>();
            BOOST_FOREACH(ptree::value_type &v, config.getPT().get_child("configuration.logging.components"))
            {
                std::string componentName = v.second.get<std::string>("name");
                std::string componentLevel = v.second.get<std::string>("level");
                std::auto_ptr<LogLevel> level(logLevelFactory.create(componentLevel));

                LoggerHolder::RegisterLogComponent(componentName, *level);
            }
        }
    }

    /**
     * Parse the loggers node of the configuration, to register loggers.
     */
    void registerLoggers() const
    {
        ConfigurationParser& config = IoC::Inject<ConfigurationParser>(false);
        if (config.hasChilds("configuration.logging.loggers"))
        {
            LoggerFactory& loggerFactory = IoC::Inject<LoggerFactory>();
            BOOST_FOREACH(ptree::value_type &v, config.getPT().get_child("configuration.logging.loggers"))
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
    }

};

}

#endif
