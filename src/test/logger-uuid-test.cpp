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

TEST(LoggerUuidTest, TestThatTwoConsoleLoggerAreEquals)
{
    ASSERT_TRUE(erty::ConsoleLogger() == erty::ConsoleLogger());
}

TEST(LoggerUuidTest, TestThatAConsoleLoggerIsDifferentThanAFileLogger)
{
    ASSERT_FALSE(erty::ConsoleLogger() == erty::FileLogger("output.log"));
    std::remove("output.log");
}

TEST(LoggerUuidTest, TestThatTwoFileLoggerAreEqualsIfTheBelongToTheSameFile)
{
    ASSERT_TRUE(erty::FileLogger("output.log") == erty::FileLogger("output.log"));
    std::remove("output.log");
}

TEST(LoggerUuidTest, TestThatTwoFileLoggerAreDifferentIfTheBelongToDifferentFile)
{
    ASSERT_FALSE(erty::FileLogger("output-1.log") == erty::FileLogger("output-2.log"));
    std::remove("output-1.log");
    std::remove("output-2.log");
}

