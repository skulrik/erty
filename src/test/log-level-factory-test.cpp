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

#include <limits>

class LogLevelFactoryTest : public ::testing::Test
{
protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    LogLevelFactory logLevelFactory;
};

TEST_F(LogLevelFactoryTest, TestLowercaseName)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("debug"));
    ASSERT_EQ(logLevel->priority(), 0);
}

TEST_F(LogLevelFactoryTest, TestUppercaseName)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("DEBUG"));
    ASSERT_EQ(logLevel->priority(), 0);
}

TEST_F(LogLevelFactoryTest, TestInfoNameCreateAnInfoLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("info"));
    ASSERT_EQ(logLevel->priority(), 10);
}

TEST_F(LogLevelFactoryTest, TestNoticeNameCreateANoticeLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("notice"));
    ASSERT_EQ(logLevel->priority(), 20);
}

TEST_F(LogLevelFactoryTest, TestWarningNameCreateAWarningLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("warning"));
    ASSERT_EQ(logLevel->priority(), 30);
}

TEST_F(LogLevelFactoryTest, TestErrorNameCreateAnErrorLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("error"));
    ASSERT_EQ(logLevel->priority(), 40);
}

TEST_F(LogLevelFactoryTest, TestCriticalNameCreateACriticalLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("critical"));
    ASSERT_EQ(logLevel->priority(), 50);
}

TEST_F(LogLevelFactoryTest, TestAlertNameCreateAnAlertLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("alert"));
    ASSERT_EQ(logLevel->priority(), 60);
}

TEST_F(LogLevelFactoryTest, TestEmergencyNameCreateAnEmergencyLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("emergency"));
    ASSERT_EQ(logLevel->priority(), 70);
}

TEST_F(LogLevelFactoryTest, TestInvalidNameCreateANullLogLevel)
{
    std::unique_ptr<LogLevel> logLevel(logLevelFactory.create("invalid"));
    ASSERT_EQ(logLevel->priority(), std::numeric_limits<unsigned int>::max());
}

