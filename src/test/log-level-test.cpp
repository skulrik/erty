#include "gtest/gtest.h"
#include "logging.h"
#include "utils.h"

#include <boost/regex.hpp>
#include <boost/format.hpp>

class LogLevelTest : public ::testing::Test
{
protected:
    LogLevelTest()
    {
    }

    virtual ~LogLevelTest()
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

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG(Error, ConsoleLogger);
    LOG(Error, LogLevelTest, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG(Info, ConsoleLogger);
    LOG(Error, LogLevelTest, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG(Debug, ConsoleLogger);
    LOG(Error, LogLevelTest, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG(Error, ConsoleLogger);
    LOG(Info, LogLevelTest, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG(Info, ConsoleLogger);
    LOG(Info, LogLevelTest, "info");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestInfoLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG(Debug, ConsoleLogger);
    LOG(Info, LogLevelTest, "info");
    ASSERT_TRUE(stream->str().size() > 0);
}

