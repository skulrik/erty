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
#ifndef _MAIN_IMPL_H_
#define _MAIN_IMPL_H_

#include <boost/function.hpp>

namespace erty
{

/**
 * Main application method caller.
 * Initialize the application based on the command line parameters it receive,
 * then call the applicationMain method.
 * @param argc the number of command line parameters.
 * @param argv the command line parameters.
 * @param applicationMain the main application code to run.
 * @return the return value of the applicationMain method.
 */
int mainImpl(int argc, char** argv, boost::function<int ()> applicationMain);

}

#endif
