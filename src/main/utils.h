#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * Insert a copy constructor and a assignment operator that do nothing in a class.
 * Must be place under the private section of the class definition.
 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
       TypeName(const TypeName&) {};       \
       void operator=(const TypeName&) {}

/**
 * Insert a default constructor, copy constructor and a assignment operator that do nothing in a class.
 * Must be place under the private section of the class definition.
 */
#define DISALLOW_DEFAULT_COPY_AND_ASSIGN(TypeName) \
       TypeName() {};                              \
       TypeName(const TypeName&) {};               \
       void operator=(const TypeName&) {}

#endif
