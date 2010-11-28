#include "gtest/gtest.h"
#include "main-impl.h"
#include "internationalization.h"

#include <iostream>
#include <sstream>

class MainImplTest : public ::testing::Test
{
protected:
    MainImplTest()
    {
    }

    virtual ~MainImplTest()
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

TEST_F(MainImplTest, ExtractedFunctionReturnsZeroUponSuccess)
{
    int result = mainImpl(0, 0);
    ASSERT_EQ(0, result);
}

TEST_F(MainImplTest, CorrectOuputPutToCout)
{
    std::stringstream expected;
    expected << _("Hello, World!") << std::endl;
    mainImpl(0, 0);
    ASSERT_EQ(expected.str(), stream->str());
}

TEST_F(MainImplTest, ExtractedFunctionReturnsOneUponHelpModeAsked)
{
    const char* cmdLine[] = { "APP_NAME", "--help" };
    int result = mainImpl(2, (char**)cmdLine);
    ASSERT_EQ(1, result);
}

TEST_F(MainImplTest, ExtractedFunctionReturnsOneWhenAnInvalidParameterIsPassed)
{
    const char* cmdLine[] = { "APP_NAME", "--invalid" };
    int result = mainImpl(2, (char**)cmdLine);
    ASSERT_EQ(1, result);
}

