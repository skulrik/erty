#include "gtest/gtest.h"
#include "ioc.h"

struct Base {};
struct Impl : public Base {};

TEST(IoCTest, IsRegisteredReturnTrueForATypeWithARegisteredObject)
{
    Impl* impl = new Impl();
    IoC::Register<Base>(impl);

    ASSERT_TRUE(IoC::IsRegistered<Base>());
}

TEST(IoCTest, IsRegisteredReturnTrueForATypeWithNoRegisteredObject)
{
    Impl* impl = new Impl();
    IoC::Register<Base>(impl);

    ASSERT_FALSE(IoC::IsRegistered<Impl>());
}

TEST(IoCTest, ResolveReturnWhatRegisterHasSaved)
{
    Impl* impl = new Impl();
    IoC::Register<Base>(impl);

    ASSERT_EQ(impl, IoC::Resolve<Base>());
}

TEST(IoCTest, IsRegisteredReturnFalseForATypeForWhichTheObjectHasBeenUnRegistered)
{
    Impl* impl = new Impl();
    IoC::Register<Base>(impl);

    IoC::UnRegister<Base>();
    ASSERT_FALSE(IoC::IsRegistered<Impl>());
}

