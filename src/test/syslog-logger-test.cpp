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
#include "gmock/gmock.h"
#include "logging.h"
#include "utils.h"

#include <boost/regex.hpp>
#include <boost/format.hpp>

#define LOG_COMPONENT "SyslogLoggerTest"

using ::testing::_;
using ::testing::Return;

class SyslogLoggerMock : public SyslogLogger
{
public:
    MOCK_METHOD0(uuid, const std::string());
    MOCK_METHOD2(write, void(const LogLevel& level, const std::string& message));
};

class SyslogLoggerTest : public ::testing::Test
{
protected:

    SyslogLoggerTest()
    {
    }

    virtual ~SyslogLoggerTest()
    {
    }

    virtual void SetUp()
    {
        REGISTER_LOG_COMPONENT(LOG_COMPONENT, Debug);
        EXPECT_CALL(*loggerMock, uuid()).WillRepeatedly(Return(std::string(LOG_COMPONENT)));
        loggerMock = static_cast<SyslogLoggerMock*>(REGISTER_LOGGER(SyslogLoggerMock));
    }

    virtual void TearDown()
    {
        UNREGISTER_ALL_LOGGERS();
    }

    SyslogLoggerMock* loggerMock;
};

TEST_F(SyslogLoggerTest, TestLogDebug)
{
#ifdef DEBUG
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
#else
    EXPECT_CALL(*loggerMock, write(_, _)).Times(0);
#endif
    DEBUG_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogInfo)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    INFO_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogNotice)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    NOTICE_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogWarning)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    WARNING_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogError)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    ERROR_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogCritical)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    CRITICAL_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogAlert)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    ALERT_LOG(LOG_COMPONENT, __FUNCTION__);
}

TEST_F(SyslogLoggerTest, TestLogEmergency)
{
    EXPECT_CALL(*loggerMock, write(_, _)).Times(1);
    EMERGENCY_LOG(LOG_COMPONENT, __FUNCTION__);
}

