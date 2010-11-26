#include "gtest/gtest.h"
#include "mainImpl.h"

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
    expected << "Hello, World!" << std::endl;
    mainImpl(0, 0);
    ASSERT_EQ(expected.str(), stream->str());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


