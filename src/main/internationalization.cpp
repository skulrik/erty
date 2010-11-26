#include "internationalization.h"

void internationalize(const char* domainName, const char* dirName)
{
    setlocale(LC_ALL, "");
    bindtextdomain(domainName, dirName);
    textdomain(domainName);
}
