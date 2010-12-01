#include "gtest/gtest.h"
#include "logger.h"

#include <boost/regex.hpp>
#include <boost/format.hpp>

class LoggerTest : public ::testing::Test
{
protected:
    LoggerTest()
    {
    }

    virtual ~LoggerTest()
    {
    }

    virtual void SetUp()
    {
        original = std::cout.rdbuf();
        stream = new std::stringstream;
        std::cout.rdbuf(stream->rdbuf());
    }

    virtual void TearDown()
    {
        std::cout.rdbuf(original);
        delete stream;
    }

    const char* buildRegex(const char* level, const char* message)
    {
        return (boost::format("\\[%1%\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] \\[LoggerTest\\] .*, \\d*: %2%\n") % level % message).str().c_str();
    }

    std::streambuf *original;
    std::stringstream *stream;
};

TEST_F(LoggerTest, StandardCannedLog)
{
    const boost::regex e(buildRegex("DEBUG", "debug"));
    ASSERT_TRUE(regex_match("[DEBUG] [2010-Nov-30 16:02:41] [LoggerTest] src/test/logger-test.cpp, 36: debug\n", e));
}

TEST_F(LoggerTest, TestLogDebug)
{
    const boost::regex e(buildRegex("DEBUG", "debug"));
    LOG(Debug, LoggerTest, "debug");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogDebugWithMacro)
{
    const boost::regex e(buildRegex("DEBUG", "debug"));
    LOG_DEBUG(LoggerTest, "debug");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogInfo)
{
    const boost::regex e(buildRegex("INFO ", "info"));
    LOG(Info, LoggerTest, "info");
}

TEST_F(LoggerTest, TestLogInfoWithMacro)
{
    const boost::regex e(buildRegex("INFO ", "info"));
    LOG_INFO(LoggerTest, "info");
}

TEST_F(LoggerTest, TestLogError)
{
    const boost::regex e(buildRegex("ERROR", "error"));
    LOG(Error, LoggerTest, "error");
}

TEST_F(LoggerTest, TestLogErrorWithMacro)
{
    const boost::regex e(buildRegex("ERROR", "error"));
    LOG_ERROR(LoggerTest, "error");
}

TEST_F(LoggerTest, TestLogWithDefine)
{
#define LOG_LEVEL Info
    const boost::regex e(buildRegex("INFO ", "error"));
    LOG(LOG_LEVEL, LoggerTest, "error");
}

