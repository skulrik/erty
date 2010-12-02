#pragma once
#ifndef _INTERNATIONALIZATION_H_
#define _INTERNATIONALIZATION_H_

#include <libintl.h>
#include <locale.h>

/** Macro that allow usage of _("str') instead of gettext("str") to internationalize a string. */
#define _(STRING) gettext(STRING)

/**
 * Initialize the gettext libraries.
 * @param domainName The application domain registred in gettext.
 * @param dirName The directory where localization file are located.
 */
void internationalize(const char* domainName, const char* dirName);

#endif
