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
#include "program-options.h"

TEST(ProgramOptionsTest, IsHelpModeIsTrueWhenLongOption_help_IsSet)
{
    const char* cmdLine[] = { "APP_NAME", "--help" };
    ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_TRUE(programOptions.isHelpMode());
}

TEST(ProgramOptionsTest, IsHelpModeIsTrueWhenShortOption_h_IsSet)
{
    const char* cmdLine[] = { "APP_NAME", "-h" };
    ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_TRUE(programOptions.isHelpMode());
}

TEST(ProgramOptionsTest, IsHelpModeIsFalseWhenOption_help_IsNotSet)
{
    const char* cmdLine[] = { "APP_NAME" };
    ProgramOptions programOptions(1, (char**)cmdLine);
    ASSERT_FALSE(programOptions.isHelpMode());
}

TEST(ProgramOptionsTest, InvalidOptionExceptionIsThrowWhenPassingAnInvalidCommandLineArgument)
{
    const char* cmdLine[] = { "APP_NAME", "--invalid" };
    ASSERT_THROW(ProgramOptions(2, (char**)cmdLine), InvalidOptionException);
}

TEST(ProgramOptionsTest, UsageIsNotEmpty)
{
    const char* cmdLine[] = { "APP_NAME" };
    ProgramOptions programOptions(1, (char**)cmdLine);
    ASSERT_FALSE(programOptions.getUsage().empty());
}

