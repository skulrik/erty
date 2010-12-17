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
#pragma once
#ifndef _INTERNATIONALIZATION_H_
#define _INTERNATIONALIZATION_H_

#include <libintl.h>
#include <locale.h>

namespace erty
{

/** Macro that allow usage of _("str') instead of gettext("str") to internationalize a string. */
#define _(STRING) gettext(STRING)

/**
 * Initialize the gettext libraries.
 * @param domainName The application domain registred in gettext.
 * @param dirName The directory where localization file are located.
 */
void internationalize(const char* domainName, const char* dirName);

}

#endif
