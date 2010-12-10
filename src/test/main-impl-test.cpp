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
#include "main-impl.h"
#include "internationalization.h"
#include "logging.h"
#include "sig-handler.h"

#include <iostream>
#include <sstream>

class MainImplTest : public ::testing::Test
{
protected:
    static void SetUpTestCase()
    {
        signal(SIGSEGV, printStacktrace);
    }

    MainImplTest()
    {
    }

    virtual ~MainImplTest()
    {
    }

    virtual void SetUp()
    {
        UNREGISTER_ALL_LOGGERS();
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

inline int successMain()
{
    return EXIT_SUCCESS;
}

inline int failedMain()
{
    return EXIT_FAILURE;
}

inline int helloMain()
{
    std::cout << _("Hello, World!") << std::endl;
    return EXIT_SUCCESS;
}

TEST_F(MainImplTest, ExtractedFunctionReturnsZeroUponSuccess)
{
    int result = mainImpl(0, 0, successMain);
    ASSERT_EQ(0, result);
}

TEST_F(MainImplTest, CorrectOuputPutToCout)
{
    std::stringstream expected;
    expected << _("Hello, World!") << std::endl;
    const char* cmdLine[] = { "APP_NAME", "--config-file=resources/test-data/logging-no-logger-no-component.xml" };
    mainImpl(2, (char**)cmdLine, helloMain);
    ASSERT_EQ(expected.str(), stream->str());
}

TEST_F(MainImplTest, ExtractedFunctionReturnsOneUponHelpModeAsked)
{
    const char* cmdLine[] = { "APP_NAME", "--help" };
    int result = mainImpl(2, (char**)cmdLine, successMain);
    ASSERT_EQ(1, result);
}

TEST_F(MainImplTest, ExtractedFunctionReturnsOneWhenAnInvalidParameterIsPassed)
{
    const char* cmdLine[] = { "APP_NAME", "--invalid" };
    int result = mainImpl(2, (char**)cmdLine, successMain);
    ASSERT_EQ(1, result);
}

