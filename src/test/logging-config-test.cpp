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
#include "gmock/gmock.h"

#include "configuration-parser.h"
#include "logging.h"
#include "ioc.h"
#include "utils.h"

using ::testing::_;
using ::testing::Return;

class LogLevelFactoryMock : public erty::LogLevelFactory
{
public:
    MOCK_METHOD1(create, erty::LogLevel*(const std::string& level));
};

class LoggerFactoryMock : public erty::LoggerFactory
{
public:
    MOCK_METHOD2(create, erty::Logger*(const std::string& name, const std::string& param));
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
        erty::IoC::Register<erty::LogLevelFactory>(logLevelFactoryMock);

        loggerFactoryMock = new LoggerFactoryMock();
        erty::IoC::Register<erty::LoggerFactory>(loggerFactoryMock);

    }

    virtual void TearDown()
    {
        erty::IoC::UnRegister<erty::LogLevelFactory>();
        erty::IoC::UnRegister<erty::LoggerFactory>();
    }

    erty::LoggingConf loggingConf;
    LogLevelFactoryMock* logLevelFactoryMock;
    LoggerFactoryMock* loggerFactoryMock;
};

TEST_F(LoggingConfTest, TestLoadingOneComponentRegisterOneComponent)
{
    EXPECT_CALL(*logLevelFactoryMock, create(_)).Times(1).WillOnce(Return(new erty::Info()));
    erty::IoC::Register<erty::ConfigurationParser>(new erty::ConfigurationParser("resources/test-data/config-one-component.xml"));
    loggingConf.setup();
}

TEST_F(LoggingConfTest, TestLoadingTwoComponentRegisterTwoComponent)
{
    EXPECT_CALL(*logLevelFactoryMock, create(_))
    .Times(2)
    .WillOnce(Return(new erty::Info()))
    .WillOnce(Return(new erty::Info()));
    erty::IoC::Register<erty::ConfigurationParser>(new erty::ConfigurationParser("resources/test-data/config-two-component.xml"));
    loggingConf.setup();
}

TEST_F(LoggingConfTest, TestLoadingOneLoggerRegisterOneLogger)
{
    EXPECT_CALL(*loggerFactoryMock, create("console",_)).Times(1).WillOnce(Return(new erty::ConsoleLogger()));
    erty::IoC::Register<erty::ConfigurationParser>(new erty::ConfigurationParser("resources/test-data/config-one-logger.xml"));
    loggingConf.setup();
}

TEST_F(LoggingConfTest, TestLoadingTwoLoggerRegisterTwoLogger)
{
    EXPECT_CALL(*loggerFactoryMock, create("console",_)).Times(1).WillOnce(Return(new erty::ConsoleLogger()));
    EXPECT_CALL(*loggerFactoryMock, create("file","output.log")).Times(1).WillOnce(Return(new erty::FileLogger("output.log")));
    erty::IoC::Register<erty::ConfigurationParser>(new erty::ConfigurationParser("resources/test-data/config-two-logger.xml"));
    loggingConf.setup();
}

