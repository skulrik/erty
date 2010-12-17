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
#include "logger-holder.h"

#include <sstream>
#include <string>
#include <list>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include "logger.h"
#include "log-level.h"
#include "datetime.h"
#include "utils.h"
#include "ioc.h"

namespace erty
{

// ----------------------------------------------------------------------------
// LOGGER HOLDER
// ----------------------------------------------------------------------------

bool operator==(LoggerPtr a, LoggerPtr b)
{
    return (*(a.get()) == *(b.get()));
}
// ----------------------------------------------------------------------------

LoggerHolder::LoggerHolder() :
    _logComponents(), _loggerList()
{
}
// ----------------------------------------------------------------------------

Logger* LoggerHolder::RegisterLogger(Logger* logger)
{
    LoggerHolder& holder = IoC::Inject<LoggerHolder>();
    LoggerPtr loggerPtr = LoggerPtr(logger);

    LoggerList::iterator loggerIter = std::find(holder._loggerList.begin(), holder._loggerList.end(), loggerPtr);
    if (loggerIter == holder._loggerList.end())
    {
        holder._loggerList.push_back(loggerPtr);
    }
    return logger;
}
// ----------------------------------------------------------------------------

void LoggerHolder::UnregisterAllLoggers()
{
    LoggerHolder& holder = IoC::Inject<LoggerHolder>();
    holder._loggerList.clear();
}
// ----------------------------------------------------------------------------

void LoggerHolder::RegisterLogComponent(const std::string& component, const LogLevel& level)
{
    LoggerHolder& holder = IoC::Inject<LoggerHolder>();
    holder._logComponents[component] = level.priority();
}
// ----------------------------------------------------------------------------

void LoggerHolder::Log(const LogLevel& level, const char* component, const char* function, const char* file, const int line, const char* message)
{
    std::stringstream ss;
    ss << "[" << level.level() << "] [" << DateTime::Now() << "] [" << component << "] from " << function << " in " << file << ":" << line << " - " << message << std::endl;

    LoggerHolder& holder = IoC::Inject<LoggerHolder>();
    unsigned int priority = holder.getComponentPriority(component);

    if (level.priority() >= priority)
    {
        BOOST_FOREACH(LoggerPtr& logger, holder._loggerList)
        {
            logger->write(level, ss.str());
        }
    }
}
// ----------------------------------------------------------------------------

unsigned int LoggerHolder::getComponentPriority(const std::string& component) const
{
#ifdef DEBUG
    unsigned int priority = Debug().priority();
#else
    unsigned int priority = Info().priority();
#endif
    LogComponents::const_iterator logComponent = _logComponents.find(component);
    if (logComponent != _logComponents.end())
    {
        priority = logComponent->second;
    }
    return priority;
}
// ----------------------------------------------------------------------------


}

