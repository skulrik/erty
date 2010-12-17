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
#include "logging.h"

class LogLevelTest : public ::testing::Test
{
protected:
    LogLevelTest()
    {
        REGISTER_LOGGER(erty::ConsoleLogger);
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
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestEmergencyLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() > 0);
}

// ALERT
TEST_F(LogLevelTest, TestAlertLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestAlertLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    ALERT_LOG(__CLASS__, "alert");
    ASSERT_TRUE(stream->str().size() > 0);
}

// CRITICAL
TEST_F(LogLevelTest, TestCriticalLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestCriticalLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestCriticalLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    CRITICAL_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

// ERROR
TEST_F(LogLevelTest, TestErrorLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestErrorLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestErrorLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    ERROR_LOG(__CLASS__, "critical");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestErrorLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    ERROR_LOG(__CLASS__, "error");
    ASSERT_TRUE(stream->str().size() > 0);
}

// WARNING
TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestWarningLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    WARNING_LOG(__CLASS__, "warning");
    ASSERT_TRUE(stream->str().size() > 0);
}

// NOTICE
TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogDontAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestNoticeLogAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestNoticeLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestNoticeLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    NOTICE_LOG(__CLASS__, "notice");
    ASSERT_TRUE(stream->str().size() > 0);
}

// INFO
TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogDontAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestInfoLogAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() > 0);
}

TEST_F(LogLevelTest, TestInfoLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    INFO_LOG(__CLASS__, "info");
    ASSERT_TRUE(stream->str().size() > 0);
}

// DEBUG
TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsEmergency)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Emergency);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsAlert)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Alert);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsCritical)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Critical);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsError)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Error);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsWarning)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Warning);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsNotice)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Notice);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogDontAppearsWhenLoggerPrioriryIsInfo)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Info);
    DEBUG_LOG(__CLASS__, "debug");
    ASSERT_TRUE(stream->str().size() == 0);
}

TEST_F(LogLevelTest, TestDebugLogAppearsWhenLoggerPrioriryIsDebug)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::Debug);
    DEBUG_LOG(__CLASS__, "debug");
#ifdef DEBUG
    ASSERT_TRUE(stream->str().size() > 0);
#else
    ASSERT_TRUE(stream->str().size() == 0);
#endif
}

TEST_F(LogLevelTest, TestEmergencyLogDontAppearsWhenLoggerPrioriryIsNullLogLevel)
{
    REGISTER_LOG_COMPONENT(__CLASS__, erty::NullLogLevel);
    EMERGENCY_LOG(__CLASS__, "emergency");
    ASSERT_TRUE(stream->str().size() == 0);
}

