#include "main-impl.h"
#include "logger.h"

int main(int argc, char** argv)
{
    LOG_INFO(void,"Startup");
    int result = mainImpl(argc, argv);;
    if (result == 0)
    {
        LOG_INFO(void,"Shutdown");
    }
    else
    {
        LOG_ERROR(void,"Failure");
    }
    return result;
}
