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

class LoggerFactoryTest : public ::testing::Test
{
protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

    erty::LoggerFactory loggerFactory;
};

TEST_F(LoggerFactoryTest, TestLowercaseType)
{
    std::unique_ptr<erty::Logger> logger(loggerFactory.create("console", ""));
    ASSERT_TRUE(*(logger.get()) == erty::ConsoleLogger());
}

TEST_F(LoggerFactoryTest, TestUppercaseType)
{
    std::unique_ptr<erty::Logger> logger(loggerFactory.create("CONSOLE", ""));
    ASSERT_TRUE(*(logger.get()) == erty::ConsoleLogger());
}

TEST_F(LoggerFactoryTest, TestFileTypeCreateAFileLogger)
{
    std::unique_ptr<erty::Logger> logger(loggerFactory.create("file", "output.log"));
    ASSERT_TRUE(*(logger.get()) == erty::FileLogger("output.log"));
}

TEST_F(LoggerFactoryTest, TestSyslogTypeCreateASyslogLogger)
{
    std::unique_ptr<erty::Logger> logger(loggerFactory.create("syslog", ""));
    ASSERT_TRUE(*(logger.get()) == erty::SyslogLogger());
}

TEST_F(LoggerFactoryTest, TestInvalidTypeCreateANullLogger)
{
    std::unique_ptr<erty::Logger> logger(loggerFactory.create("invalid", ""));
    ASSERT_TRUE(*(logger.get()) == erty::NullLogger());
}

