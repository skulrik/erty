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

#define LOG_COMPONENT "FileLoggerTest"
#define TEST_OUTPUT_FILE_NAME "test-output/file-logger-test.log"

class FileLoggerTest : public ::testing::Test
{
protected:

    FileLoggerTest()
    {
    }

    virtual ~FileLoggerTest()
    {
    }

    virtual void SetUp()
    {
        REGISTER_LOGGER(erty::FileLogger(TEST_OUTPUT_FILE_NAME));
        REGISTER_LOG_COMPONENT(LOG_COMPONENT, erty::Debug);
    }

    virtual void TearDown()
    {
        UNREGISTER_ALL_LOGGERS();
        std::remove(TEST_OUTPUT_FILE_NAME);
    }

    const std::string buildRegex(const char* level, const char* message)
    {
        return (_F("\\[%1%\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] \\[FileLoggerTest\\] from .* in .*:\\d* - %2%") % level % message).str();
    }

    const std::string readResultFile()
    {
        std::ifstream file;

        file.open(TEST_OUTPUT_FILE_NAME, std::ios::in);

        char buffer[1000];
        file.getline(buffer, 1000);
        file.close();

        std::string s(buffer);

        return s;
    }
};

TEST_F(FileLoggerTest, TestCannedLog)
{
    std::string log("[INFO] [2010-Dec-02 10:45:40] [FileLoggerTest] from TestBody in src/test/logger-test.cpp:58 - TestCannedLog");
    const boost::regex e(buildRegex("INFO", "TestCannedLog"));
    ASSERT_TRUE(regex_match(log, e));
}

TEST_F(FileLoggerTest, TestLogDebug)
{
    const boost::regex e(buildRegex("DEBUG", __FUNCTION__));
    DEBUG_LOG(LOG_COMPONENT, __FUNCTION__);
#ifdef DEBUG
    ASSERT_TRUE(regex_match(readResultFile(), e));
#endif
}

TEST_F(FileLoggerTest, TestLogInfo)
{
    const boost::regex e(buildRegex("INFO", __FUNCTION__));
    INFO_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogNotice)
{
    const boost::regex e(buildRegex("NOTICE", __FUNCTION__));
    NOTICE_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogWarning)
{
    const boost::regex e(buildRegex("WARNING", __FUNCTION__));
    WARNING_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogError)
{
    const boost::regex e(buildRegex("ERROR", __FUNCTION__));
    ERROR_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogCritical)
{
    const boost::regex e(buildRegex("CRITICAL", __FUNCTION__));
    CRITICAL_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogAlert)
{
    const boost::regex e(buildRegex("ALERT", __FUNCTION__));
    ALERT_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogEmergency)
{
    const boost::regex e(buildRegex("EMERGENCY", __FUNCTION__));
    EMERGENCY_LOG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

