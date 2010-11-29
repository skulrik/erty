#include "main-impl.h"
#include "logger.h"

int main(int argc, char** argv)
{
    LOG_INFO("Startup");
    int result = mainImpl(argc, argv);;
    if (result == 0)
    {
        LOG_INFO("Shutdown");
    }
    else
    {
        LOG_ERROR("Failure");
    }
    return result;
}
