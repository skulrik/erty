#pragma once
#ifndef _DEMANGLE_H_
#define _DEMANGLE_H_

#include <string>

/**
 * Return the demangled version of an identifier.
 * Must be build with the HAVE_CXA_DEMANGLE option.
 * @param name the name to demangle.
 * @ demangledName the demangled version of the name is returnedis this parameter.
 */
void demangle(const char* name, std::string& demangledName);

#endif
