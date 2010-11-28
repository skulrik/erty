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

