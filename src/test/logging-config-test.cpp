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
#include "ioc.h"
#include "utils.h"

using ::testing::_;
using ::testing::Return;

class LogLevelFactoryMock : public LogLevelFactory
{
public:
    MOCK_METHOD1(create, LogLevel*(const std::string& level));
};

class LoggerFactoryMock : public LoggerFactory
{
public:
    MOCK_METHOD2(create, Logger*(const std::string& name, const std::string& param));
};

class LoggingConfTest : public ::testing::Test
{
protected:

    static void TearDownTestCase()
    {
        UNREGISTER_ALL_LOGGERS();
    }

    virtual void SetUp()
    {
        logLevelFactoryMock = new LogLevelFactoryMock();
        IoC::Register<LogLevelFactory>(logLevelFactoryMock);

        loggerFactoryMock = new LoggerFactoryMock();
        IoC::Register<LoggerFactory>(loggerFactoryMock);
    }

    virtual void TearDown()
    {
        IoC::UnRegister<LogLevelFactory>();
        IoC::UnRegister<LoggerFactory>();
    }

    LoggingConf loggingConf;
    LogLevelFactoryMock* logLevelFactoryMock;
    LoggerFactoryMock* loggerFactoryMock;
};

TEST_F(LoggingConfTest, TestNonExistingConfigFileThrowLoggingConfException)
{
    ASSERT_THROW(loggingConf.load("resources/test-data/logging-inexisting.xml"), LoggingConfException);
}

TEST_F(LoggingConfTest, TestMalformedConfigFileThrowLoggingConfException)
{
    ASSERT_THROW(loggingConf.load("resources/test-data/logging-malformed.xml"), LoggingConfException);
}

TEST_F(LoggingConfTest, TestLoadingOneComponentRegisterOneComponent)
{
    EXPECT_CALL(*logLevelFactoryMock, create(_)).Times(1).WillOnce(Return(new Info()));
    loggingConf.load("resources/test-data/logging-one-component.xml");
}

TEST_F(LoggingConfTest, TestLoadingTwoComponentRegisterTwoComponent)
{
    EXPECT_CALL(*logLevelFactoryMock, create(_))
    .Times(2)
    .WillOnce(Return(new Info()))
    .WillOnce(Return(new Info()));
    loggingConf.load("resources/test-data/logging-two-component.xml");
}

TEST_F(LoggingConfTest, TestLoadingOneLoggerRegisterOneLogger)
{
    EXPECT_CALL(*loggerFactoryMock, create("console",_)).Times(1).WillOnce(Return(new ConsoleLogger()));
    loggingConf.load("resources/test-data/logging-one-logger.xml");
}

TEST_F(LoggingConfTest, TestLoadingTwoLoggerRegisterTwoLogger)
{
    EXPECT_CALL(*loggerFactoryMock, create("console",_)).Times(1).WillOnce(Return(new ConsoleLogger()));
    EXPECT_CALL(*loggerFactoryMock, create("file","output.log")).Times(1).WillOnce(Return(new FileLogger("output.log")));
    loggingConf.load("resources/test-data/logging-two-logger.xml");
}

