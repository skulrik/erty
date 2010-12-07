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

class LogLevelTest : public ::testing::Test
{
protected:
    LogLevelTest()
    {
        REGISTER_LOGGER(ConsoleLogger);
    }

    virtual ~LogLevelTest()
    {
        UNREGISTER_ALL_LOGGERS();
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
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestInfoLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() > 0);
}

