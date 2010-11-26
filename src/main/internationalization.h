#pragma once
#ifndef _INTERNATIONALIZATION_H_
#define _INTERNATIONALIZATION_H_

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

void internationalize(const char* domainName, const char* dirName);

#endif
