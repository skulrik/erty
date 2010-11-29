#pragma once
#ifndef _IDENTITY_H_
#define _IDENTITY_H_

/**
 * Build an identity value for a type, for use in metaprogramming.
 */
template<typename T>
struct identity
{
    typedef T type;
};

#endif
