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
#include "program-options.h"

TEST(ProgramOptionsTest, IsHelpModeIsTrueWhenLongOption_help_IsSet)
{
    const char* cmdLine[] = { "APP_NAME", "--help" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_TRUE(programOptions.isHelpMode());
}

TEST(ProgramOptionsTest, IsHelpModeIsTrueWhenShortOption_h_IsSet)
{
    const char* cmdLine[] = { "APP_NAME", "-h" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_TRUE(programOptions.isHelpMode());
}

TEST(ProgramOptionsTest, IsHelpModeIsFalseWhenOption_help_IsNotSet)
{
    const char* cmdLine[] = { "APP_NAME" };
    erty::ProgramOptions programOptions(1, (char**)cmdLine);
    ASSERT_FALSE(programOptions.isHelpMode());
}

TEST(ProgramOptionsTest, InvalidOptionExceptionIsThrowWhenPassingAnInvalidCommandLineArgument)
{
    const char* cmdLine[] = { "APP_NAME", "--invalid" };
    ASSERT_THROW(erty::ProgramOptions(2, (char**)cmdLine), erty::InvalidOptionException);
}

TEST(ProgramOptionsTest, UsageIsNotEmpty)
{
    const char* cmdLine[] = { "APP_NAME" };
    erty::ProgramOptions programOptions(1, (char**)cmdLine);
    ASSERT_FALSE(programOptions.getUsage().empty());
}

TEST(ProgramOptionsTest, TestThatSpecifyNoConfigFileReturnTheDefaultValue)
{
    const char* cmdLine[] = { "APP_NAME" };
    erty::ProgramOptions programOptions(1, (char**)cmdLine);
    ASSERT_EQ(programOptions.getConfigFilePath(), "conf/config.xml");
}

TEST(ProgramOptionsTest, TestThatSpecifyLongConfigFileOptionReturnTheSpecifiedValue)
{
    const char* cmdLine[] = { "APP_NAME", "--config-file=resources/test-data/config.xml" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_EQ("resources/test-data/config.xml", programOptions.getConfigFilePath());
}

TEST(ProgramOptionsTest, TestThatSpecifyShortConfigFileOptionReturnTheSpecifiedValue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config.xml" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_EQ("resources/test-data/config.xml", programOptions.getConfigFilePath());
}

TEST(ProgramOptionsTest, TestThatSpecifyShortConfigFileOptionWithSpaceReturnTheSpecifiedValue)
{
    const char* cmdLine[] = { "APP_NAME", "-c", "resources/test-data/config.xml" };
    erty::ProgramOptions programOptions(3, (char**)cmdLine);
    ASSERT_EQ("resources/test-data/config.xml", programOptions.getConfigFilePath());
}

TEST(ProgramOptionsTest, TestThatSpecifyAnInvalidConfigurationFileThrowAnConfiguredOptionParsingException)
{
    const char* cmdLine[] = { "APP_NAME", "--config-file=inexisting-file.xml" };
    EXPECT_THROW(erty::ProgramOptions programOptions(2, (char**)cmdLine), erty::ConfiguredOptionParsingException);
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyFalseBooleanOptionFromConfigFileWithNoValueInCommandLineNoValueReturnFalse)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-false-boolean-option.xml" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_EQ(false, programOptions.get<bool>("boolean-option"));
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyFalseBooleanOptionFromConfigFileWithTrueValueInCommandLineNoValueReturnTrue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-false-boolean-option.xml", "--boolean-option" };
    erty::ProgramOptions programOptions(3, (char**)cmdLine);
    ASSERT_EQ(true, programOptions.get<bool>("boolean-option"));
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyFalseBooleanOptionFromConfigFileWithNoValueInCommandLineNoValueReturnTrue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-true-boolean-option.xml" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_EQ(true, programOptions.get<bool>("boolean-option"));
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyStringOptionFromConfigFileWithNoValueInCommandLineNoValueReturnConfigFileValue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-string-option.xml" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_EQ("abcdefg", programOptions.get<std::string>("string-option"));
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyStringOptionFromConfigFileWithStringValueInCommandLineNoValueReturnCommandLineValue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-string-option.xml", "--string-option=hijklmnop" };
    erty::ProgramOptions programOptions(3, (char**)cmdLine);
    ASSERT_EQ("hijklmnop", programOptions.get<std::string>("string-option"));
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyIntegerOptionFromConfigFileWithNoValueInCommandLineNoValueReturnConfigFileValue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-integer-option.xml" };
    erty::ProgramOptions programOptions(2, (char**)cmdLine);
    ASSERT_EQ(10, programOptions.get<int>("integer-option"));
}

TEST(ProgramOptionsTest, TestThatWhenSpecifyIntegerOptionFromConfigFileWithIntegerValueInCommandLineNoValueReturnCommandLineValue)
{
    const char* cmdLine[] = { "APP_NAME", "-cresources/test-data/config-integer-option.xml", "--integer-option=20" };
    erty::ProgramOptions programOptions(3, (char**)cmdLine);
    ASSERT_EQ(20, programOptions.get<int>("integer-option"));
}

