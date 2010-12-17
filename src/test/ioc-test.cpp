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
#include "ioc.h"

struct Base {};
struct Impl : public Base {};

class IoCTest : public ::testing::Test
{
protected:

    virtual void SetUp()
    {
        erty::IoC::UnRegisterAll();
    }

    virtual void TearDown()
    {
        erty::IoC::UnRegisterAll();
    }
};

TEST_F(IoCTest, IsRegisteredReturnTrueForATypeWithARegisteredObject)
{
    Impl* impl = new Impl();
    erty::IoC::Register<Base>(impl);

    ASSERT_TRUE(erty::IoC::IsRegistered<Base>());
}

TEST_F(IoCTest, IsRegisteredReturnTrueForATypeWithNoRegisteredObject)
{
    Impl* impl = new Impl();
    erty::IoC::Register<Base>(impl);

    ASSERT_FALSE(erty::IoC::IsRegistered<Impl>());
}

TEST_F(IoCTest, ResolveReturnWhatRegisterHasSaved)
{
    Impl* impl = new Impl();
    erty::IoC::Register<Base>(impl);

    ASSERT_EQ(impl, erty::IoC::Resolve<Base>());
}

TEST_F(IoCTest, IsRegisteredReturnFalseForATypeForWhichTheObjectHasBeenUnRegistered)
{
    Impl* impl = new Impl();
    erty::IoC::Register<Base>(impl);

    erty::IoC::UnRegister<Base>();
    ASSERT_FALSE(erty::IoC::IsRegistered<Impl>());
}

TEST_F(IoCTest, RegisteringTwoObjectOfTheSameTypeToDifferentNameReturnGoodObjectForEachName)
{
    Impl* implA = new Impl();
    erty::IoC::Register<Base>("impl-a", implA);

    Impl* implB = new Impl();
    erty::IoC::Register<Base>("impl-b", implB);

    ASSERT_EQ(implA, erty::IoC::Resolve<Base>("impl-a"));
    ASSERT_EQ(implB, erty::IoC::Resolve<Base>("impl-b"));
}

TEST_F(IoCTest, TestThatInjectingAnObjectWithAutocreateSetToTrueReturnAValidObject)
{
    Impl& impl = erty::IoC::Inject<Impl>();
    ASSERT_TRUE(0 != &impl);
}

TEST_F(IoCTest, TestThatInjectingAnObjectWithAutocreateSetToFalseThrow)
{
    ASSERT_THROW(erty::IoC::Inject<Impl>(false), erty::IoCException);
}

