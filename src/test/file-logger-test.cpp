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
        REGISTER_LOGGER(FileLogger(TEST_OUTPUT_FILE_NAME));
        REGISTER_LOG_COMPONENT(LOG_COMPONENT, Debug);
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
    std::string log("[INFO ] [2010-Dec-02 10:45:40] [FileLoggerTest] from TestBody in src/test/logger-test.cpp:58 - TestCannedLog");
    const boost::regex e(buildRegex("INFO ", "TestCannedLog"));
    ASSERT_TRUE(regex_match(log, e));
}

TEST_F(FileLoggerTest, TestLogDebug)
{
    const boost::regex e(buildRegex("DEBUG", __FUNCTION__));
    LOG_DEBUG(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogInfo)
{
    const boost::regex e(buildRegex("INFO ", __FUNCTION__));
    LOG_INFO(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

TEST_F(FileLoggerTest, TestLogError)
{
    const boost::regex e(buildRegex("ERROR", __FUNCTION__));
    LOG_ERROR(LOG_COMPONENT, __FUNCTION__);
    ASSERT_TRUE(regex_match(readResultFile(), e));
}

