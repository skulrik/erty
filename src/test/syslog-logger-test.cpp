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
#include "gtest/gtest.h"
#include "logging.h"
#include "utils.h"

#include <boost/regex.hpp>
#include <boost/format.hpp>

#define LOG_COMPONENT "SyslogLoggerTest"

class SyslogLoggerTest : public ::testing::Test
{
protected:

    static void TearDownTestCase()
    {
        UNREGISTER_ALL_LOGGERS();
    }

    SyslogLoggerTest()
    {
    }

    virtual ~SyslogLoggerTest()
    {
    }

    virtual void SetUp()
    {
        REGISTER_LOGGER(SyslogLogger);
        REGISTER_LOG_COMPONENT(LOG_COMPONENT, Debug);
    }

    virtual void TearDown()
    {
    }

    const std::string buildRegex(const char* level, const char* message)
    {
        return (_F("\\[%1%\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] \\[SyslogLoggerTest\\] from .* in .*:\\d* - %2%\n") % level % message).str();
    }
};

TEST_F(SyslogLoggerTest, TestCannedLog)
{
    std::string log("[INFO] [2010-Dec-02 10:45:40] [SyslogLoggerTest] from TestBody in src/test/logger-test.cpp:58 - TestCannedLog\n");
    const boost::regex e(buildRegex("INFO", "TestCannedLog"));
    ASSERT_TRUE(regex_match(log, e));
}

TEST_F(SyslogLoggerTest, TestLogDebug)
{
    const boost::regex e(buildRegex("DEBUG", __FUNCTION__));
    DEBUG_LOG(LOG_COMPONENT, __FUNCTION__);
#ifdef DEBUG
#endif
}

TEST_F(SyslogLoggerTest, TestLogInfo)
{
    const boost::regex e(buildRegex("INFO", __FUNCTION__));
    INFO_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogNotice)
{
    const boost::regex e(buildRegex("NOTICE", __FUNCTION__));
    NOTICE_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogWarning)
{
    const boost::regex e(buildRegex("WARNING", __FUNCTION__));
    WARNING_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogError)
{
    const boost::regex e(buildRegex("ERROR", __FUNCTION__));
    ERROR_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogCritical)
{
    const boost::regex e(buildRegex("CRITICAL", __FUNCTION__));
    CRITICAL_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogAlert)
{
    const boost::regex e(buildRegex("ALERT", __FUNCTION__));
    ALERT_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogEmergency)
{
    const boost::regex e(buildRegex("EMERGENCY", __FUNCTION__));
    EMERGENCY_LOG(LOG_COMPONENT, __FUNCTION__);
}

