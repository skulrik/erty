#include "gtest/gtest.h"
#include "logger.h"

#include <boost/regex.hpp>

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

    std::streambuf *original;
    std::stringstream *stream;
};

TEST_F(LoggerTest, StandardCannedLog)
{
    const boost::regex e("\\[DEBUG\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: debug\n");
    ASSERT_TRUE(regex_match("[DEBUG] [2010-Nov-30 16:02:41] src/test/logger-test.cpp, 36: debug\n", e));
}

TEST_F(LoggerTest, TestLogDebug)
{
    const boost::regex e("\\[DEBUG\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: debug\n");
    LOG(Debug,"debug");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogDebugWithMacro)
{
    const boost::regex e("\\[DEBUG\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: debug\n");
    LOG_DEBUG("debug");
    ASSERT_TRUE(regex_match(stream->str(), e));
}

TEST_F(LoggerTest, TestLogInfo)
{
    const boost::regex e("\\[INFO \\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: info\n");
    LOG(Info, "info");
}

TEST_F(LoggerTest, TestLogInfoWithMacro)
{
    const boost::regex e("\\[INFO \\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: info\n");
    LOG_INFO("info");
}

TEST_F(LoggerTest, TestLogError)
{
    const boost::regex e("\\[ERROR\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: error\n");
    LOG(Error, "error");
}

TEST_F(LoggerTest, TestLogErrorWithMacro)
{
    const boost::regex e("\\[ERROR\\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: error\n");
    LOG_ERROR("error");
}

TEST_F(LoggerTest, TestLogWithDefine)
{
#define LOG_LEVEL Info
    const boost::regex e("\\[INFO \\] \\[\\d{4}-[a-zA-Z]{3}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\] .*, \\d*: error\n");
    LOG(LOG_LEVEL,"error");
}

