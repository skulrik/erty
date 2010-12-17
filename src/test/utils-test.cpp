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
#include "utils.h"

TEST(UtilsTest, TestThatToLowerReturnALowercaseVersionOfAnAlreadyLowercasedString)
{
    ASSERT_EQ(erty::toLower("hello"), "hello");
}

TEST(UtilsTest, TestThatToLowerReturnALowercaseVersionOfAnUppercaseString)
{
    ASSERT_EQ(erty::toLower("HELLO"), "hello");
}

TEST(UtilsTest, TestThatToUpperReturnAnUppercaseVersionOfAnAlreadyUppercasedString)
{
    ASSERT_EQ(erty::toUpper("HELLO"), "HELLO");
}

TEST(UtilsTest, TestThatToUpperReturnAnUppercaseVersionOfALowercaseString)
{
    ASSERT_EQ(erty::toUpper("hello"), "HELLO");
}

TEST(UtilsTest, TestStringToBoolTrueValues)
{
    ASSERT_TRUE(erty::stringToBool("true"));
    ASSERT_TRUE(erty::stringToBool("t"));
    ASSERT_TRUE(erty::stringToBool("y"));
    ASSERT_TRUE(erty::stringToBool("yes"));
    ASSERT_TRUE(erty::stringToBool("on"));

    ASSERT_TRUE(erty::stringToBool("TRUE"));
    ASSERT_TRUE(erty::stringToBool("T"));
    ASSERT_TRUE(erty::stringToBool("Y"));
    ASSERT_TRUE(erty::stringToBool("YES"));
    ASSERT_TRUE(erty::stringToBool("ON"));
}

TEST(UtilsTest, TestStringToBoolFalseValues)
{
    ASSERT_FALSE(erty::stringToBool("false"));
    ASSERT_FALSE(erty::stringToBool("f"));
    ASSERT_FALSE(erty::stringToBool("n"));
    ASSERT_FALSE(erty::stringToBool("no"));
    ASSERT_FALSE(erty::stringToBool("off"));

    ASSERT_FALSE(erty::stringToBool("FALSE"));
    ASSERT_FALSE(erty::stringToBool("F"));
    ASSERT_FALSE(erty::stringToBool("N"));
    ASSERT_FALSE(erty::stringToBool("NO"));
    ASSERT_FALSE(erty::stringToBool("OFF"));
}

TEST(UtilsTest, TestThatPassingAnInvalidToStringToBoolThrow)
{
    EXPECT_THROW(erty::stringToBool("invalid"), std::runtime_error);
}
