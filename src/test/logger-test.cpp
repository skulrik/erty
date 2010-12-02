#include "gtest/gtest.h"
#include "logger.h"
#include "utils.h"

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

    const std::string buildRegex(const char* level, const char* message)
    {
        return (_F("\\[%1%\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] \\[LoggerTest\\] from .* in .* at line \\d*: %2%\n") % level % message).str();
    }

    std::streambuf *original;
    std::stringstream *stream;
};

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
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogInfoWithMacro)
{
    const boost::regex e(buildRegex("INFO ", "info"));
    LOG_INFO(LoggerTest, "info");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogError)
{
    const boost::regex e(buildRegex("ERROR", "error"));
    LOG(Error, LoggerTest, "error");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogErrorWithMacro)
{
    const boost::regex e(buildRegex("ERROR", "error"));
    LOG_ERROR(LoggerTest, "error");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogWithDefine)
{
#define LOG_LEVEL Info
    const boost::regex e(buildRegex("INFO ", "error"));
    LOG(LOG_LEVEL, LoggerTest, "error");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

