#include "gtest/gtest.h"
#include "datetime.h"
#include <sstream>

TEST(DateTimeTest, IsNowFunctionCanBeConvertedToAnNonEmptyString)
{
    std::stringstream ss;
    ss << DateTime::Now();

    ASSERT_FALSE(ss.str().empty());
}
