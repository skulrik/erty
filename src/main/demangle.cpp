#include "demangle.h"
#include <cxxabi.h>

#ifdef HAVE_CXA_DEMANGLE
void demangle(const char* name, std::string& demangledName)
{
    char buf[1024];
    size_t size=sizeof(buf);
    int status;
    abi::__cxa_demangle (name,
                         buf,
                         &size,
                         &status);
    demangledName = buf;
}
#else
void demangle(const char* name, std::string& demangledName)
{
    demangledName = name;
}
#endif
