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
#include "utils.h"

TEST(UtilsTest, TestThatToLowerReturnALowercaseVersionOfAnAlreadyLowercasedString)
{
    ASSERT_EQ(toLower("hello"), "hello");
}

TEST(UtilsTest, TestThatToLowerReturnALowercaseVersionOfAnUppercaseString)
{
    ASSERT_EQ(toLower("HELLO"), "hello");
}

TEST(UtilsTest, TestThatToUpperReturnAnUppercaseVersionOfAnAlreadyUppercasedString)
{
    ASSERT_EQ(toUpper("HELLO"), "HELLO");
}

TEST(UtilsTest, TestThatToUpperReturnAnUppercaseVersionOfALowercaseString)
{
    ASSERT_EQ(toUpper("hello"), "HELLO");
}

