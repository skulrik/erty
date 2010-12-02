#include "gtest/gtest.h"
#include "logging.h"

int main(int argc, char** argv)
{
    REGISTER_LOG(ConsoleLogger());
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


