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

// EMERGENCY
TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_EMERGENCY(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

// ALERT
TEST_F(LogLevelTest, TestAlertLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_ALERT(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

// CRITICAL
TEST_F(LogLevelTest, TestCriticalLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestCriticalLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_CRITICAL(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

// ERROR
TEST_F(LogLevelTest, TestErrorLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestErrorLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestErrorLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_ERROR(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
    LOG_ERROR(__CLASS__, "critical");
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

// WARNING
TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_WARNING(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

// NOTICE
TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestNoticeLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Info);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestNoticeLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Debug);
    LOG_NOTICE(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() > 0);
}

// INFO
TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_INFO(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
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

// DEBUG
TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Emergency);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Alert);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Critical);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Error);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Warning);
    LOG_DEBUG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, Notice);
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
#ifdef DEBUG
    ASSERT_TRUE(stream->str().size() > 0);
#else
    ASSERT_TRUE(stream->str().size() == 0);
#endif
}
