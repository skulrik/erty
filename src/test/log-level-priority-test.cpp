#include "gtest/gtest.h"
#include "log-level.h"

TEST(LogLevelPriorityTest, TestLesserThan)
{
    EXPECT_FALSE(Error() < Error());
    EXPECT_FALSE(Error() < Info());
    EXPECT_FALSE(Error() < Debug());
    EXPECT_TRUE(Info() < Error());
    EXPECT_FALSE(Info() < Info());
    EXPECT_FALSE(Info() < Debug());
    EXPECT_TRUE(Debug() < Error());
    EXPECT_TRUE(Debug() < Info());
    EXPECT_FALSE(Debug() < Debug());
}

TEST(LogLevelPriorityTest, TestGreatherThan)
{
    EXPECT_FALSE(Error() > Error());
    EXPECT_TRUE(Error() > Info());
    EXPECT_TRUE(Error() > Debug());
    EXPECT_FALSE(Info() > Error());
    EXPECT_FALSE(Info() > Info());
    EXPECT_TRUE(Info() > Debug());
    EXPECT_FALSE(Debug() > Error());
    EXPECT_FALSE(Debug() > Info());
    EXPECT_FALSE(Debug() > Debug());
}

TEST(LogLevelPriorityTest, TestEqualTo)
{
    EXPECT_TRUE(Error() == Error());
    EXPECT_FALSE(Error() == Info());
    EXPECT_FALSE(Error() == Debug());
    EXPECT_FALSE(Info() == Error());
    EXPECT_TRUE(Info() == Info());
    EXPECT_FALSE(Info() == Debug());
    EXPECT_FALSE(Debug() == Error());
    EXPECT_FALSE(Debug() == Info());
    EXPECT_TRUE(Debug() == Debug());
}

TEST(LogLevelPriorityTest, TestNotEqualTo)
{
    EXPECT_FALSE(Error() != Error());
    EXPECT_TRUE(Error() != Info());
    EXPECT_TRUE(Error() != Debug());
    EXPECT_TRUE(Info() != Error());
    EXPECT_FALSE(Info() != Info());
    EXPECT_TRUE(Info() != Debug());
    EXPECT_TRUE(Debug() != Error());
    EXPECT_TRUE(Debug() != Info());
    EXPECT_FALSE(Debug() != Debug());
}

TEST(LogLevelPriorityTest, TestLesserOrEqualThan)
{
    EXPECT_TRUE(Error() <= Error());
    EXPECT_FALSE(Error() <= Info());
    EXPECT_FALSE(Error() <= Debug());
    EXPECT_TRUE(Info() <= Error());
    EXPECT_TRUE(Info() <= Info());
    EXPECT_FALSE(Info() <= Debug());
    EXPECT_TRUE(Debug() <= Error());
    EXPECT_TRUE(Debug() <= Info());
    EXPECT_TRUE(Debug() <= Debug());
}

TEST(LogLevelPriorityTest, TestGreatherOrEqualThan)
{
    EXPECT_TRUE(Error() >= Error());
    EXPECT_TRUE(Error() >= Info());
    EXPECT_TRUE(Error() >= Debug());
    EXPECT_FALSE(Info() >= Error());
    EXPECT_TRUE(Info() >= Info());
    EXPECT_TRUE(Info() >= Debug());
    EXPECT_FALSE(Debug() >= Error());
    EXPECT_FALSE(Debug() >= Info());
    EXPECT_TRUE(Debug() >= Debug());
}

