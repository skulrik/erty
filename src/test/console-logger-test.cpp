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
#include "gtest/gtest.h"
#include "logging.h"
#include "utils.h"

#include <boost/regex.hpp>
#include <boost/format.hpp>

#define LOG_COMPONENT "ConsoleLoggerTest"

class ConsoleLoggerTest : public ::testing::Test
{
protected:

    static void TearDownTestCase()
    {
        UNREGISTER_ALL_LOGGERS();
    }

    ConsoleLoggerTest()
    {
    }

    virtual ~ConsoleLoggerTest()
    {
    }

    virtual void SetUp()
    {
        REGISTER_LOGGER(erty::ConsoleLogger);
        REGISTER_LOG_COMPONENT(LOG_COMPONENT, erty::Debug);
        original = std::cout.rdbuf();
        stream = new std::stringstream;
        std::cout.rdbuf(stream->rdbuf());
    }

    virtual void TearDown()
    {
        std::cout.rdbuf(original);
        delete stream;
    }

    const std::string buildRegex(const char* level, const char* message)
    {
        return (_F("\\[%1%\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] \\[ConsoleLoggerTest\\] from .* in .*:\\d* - %2%\n") % level % message).str();
    }

    std::streambuf *original;
    std::stringstream *stream;
};

TEST_F(ConsoleLoggerTest, TestCannedLog)
{
    std::string log("[INFO] [2010-Dec-02 10:45:40] [ConsoleLoggerTest] from TestBody in src/test/logger-test.cpp:58 - TestCannedLog\n");
    const boost::regex e(buildRegex("INFO", "TestCannedLog"));
    ASSERT_TRUE(regex_match(log, e));
}

TEST_F(ConsoleLoggerTest, TestLogDebug)
{
    const boost::regex e(buildRegex("DEBUG", __FUNCTION__));
    DEBUG_LOG(LOG_COMPONENT, __FUNCTION__);
#ifdef DEBUG
    ASSERT_TRUE(regex_match(stream->str(), e));
#endif
}

TEST_F(ConsoleLoggerTest, TestLogInfo)
{
    const boost::regex e(buildRegex("INFO", __FUNCTION__));
    INFO_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(ConsoleLoggerTest, TestLogNotice)
{
    const boost::regex e(buildRegex("NOTICE", __FUNCTION__));
    NOTICE_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(ConsoleLoggerTest, TestLogWarning)
{
    const boost::regex e(buildRegex("WARNING", __FUNCTION__));
    WARNING_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(ConsoleLoggerTest, TestLogError)
{
    const boost::regex e(buildRegex("ERROR", __FUNCTION__));
    ERROR_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(ConsoleLoggerTest, TestLogCritical)
{
    const boost::regex e(buildRegex("CRITICAL", __FUNCTION__));
    CRITICAL_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(ConsoleLoggerTest, TestLogAlert)
{
    const boost::regex e(buildRegex("ALERT", __FUNCTION__));
    ALERT_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(ConsoleLoggerTest, TestLogEmergency)
{
    const boost::regex e(buildRegex("EMERGENCY", __FUNCTION__));
    EMERGENCY_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(stream->str(), e));
}
