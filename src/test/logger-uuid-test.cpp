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

TEST(LoggerUuidTest, TestThatTwoConsoleLoggerAreEquals)
{
    ASSERT_TRUE(ConsoleLogger() == ConsoleLogger());
}

TEST(LoggerUuidTest, TestThatAConsoleLoggerIsDifferentThanAFileLogger)
{
    ASSERT_FALSE(ConsoleLogger() == FileLogger("output.log"));
}

TEST(LoggerUuidTest, TestThatTwoFileLoggerAreEqualsIfTheBelongToTheSameFile)
{
    ASSERT_TRUE(FileLogger("output.log") ==FileLogger("output.log"));
}

TEST(LoggerUuidTest, TestThatTwoFileLoggerAreDifferentIfTheBelongToDifferentFile)
{
    ASSERT_FALSE(FileLogger("output-1.log") == FileLogger("output-2.log"));
}

