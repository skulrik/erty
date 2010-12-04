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

