#include "gtest/gtest.h"
#include "main-impl.h"
#include "internationalization.h"

#include <iostream>
#include <sstream>

class MainTest : public ::testing::Test
{
protected:
    MainTest()
    {
    }

    virtual ~MainTest()
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

TEST_F(MainTest, ExtractedFunctionReturnsZeroUponSuccess)
{
    int result = mainImpl(0, 0);
    ASSERT_EQ(0, result);
}

TEST_F(MainTest, CorrectOuputPutToCout)
{
    std::stringstream expected;
    expected << _("Hello, World!") << std::endl;
    mainImpl(0, 0);
    ASSERT_EQ(expected.str(), stream->str());
}

TEST_F(MainTest, ExtractedFunctionReturnsOneUponHelpModeAsked)
{
    const char* cmdLine[] = { "APP_NAME", "--help" };
    int result = mainImpl(2, (char**)cmdLine);
    ASSERT_EQ(1, result);
}

TEST_F(MainTest, ExtractedFunctionReturnsOneWhenAnInvalidParameterIsPassed)
{
    const char* cmdLine[] = { "APP_NAME", "--invalid" };
    int result = mainImpl(2, (char**)cmdLine);
    ASSERT_EQ(1, result);
}

