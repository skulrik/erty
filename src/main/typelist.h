#pragma once
#ifndef _TYPELIST_H_
#define _TYPELIST_H_

/**
 * Mark the end of the list of type.
 */
class NullType {};

/**
 * Represent the list of types.
 */
class TypeList
{
    typedef H Head;
    typedef T Tail;
};

/**
 * Macros that define list of N types.
 */
#define TYPELIST_1(T1)\
TypeList<T1, NullType>

#define TYPELIST_2(T1, T2)\
TypeList<T1, TYPELIST_1(T2)>

#define TYPELIST_3(T1, T2, T3)\
TypeList<T1, TYPELIST_2(T2, T3)>

#define TYPELIST_4(T1, T2, T3, T4)\
TypeList<T1, TYPELIST_3(T2, T3, T4)>

#define TYPELIST_5(T1, T2, T3, T4, T5)\
TypeList<T1, TYPELIST_4(T2, T3, T4, T5)>

#define TYPELIST_6(T1, T2, T3, T4, T5, T6)\
TypeList<T1, TYPELIST_5(T2, T3, T4, T5, T6)>

#define TYPELIST_7(T1, T2, T3, T4, T5, T6, T7)\
TypeList<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7)>

#define TYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8)\
TypeList<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7, T8)>

#define TYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9)\
TypeList<T1, TYPELIST_8(T2, T3, T4, T5, T6, T7, T8, T9)>

#define TYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)\
TypeList<T1, TYPELIST_9(T2, T3, T4, T5, T6, T7, T8, T9, T10)>

#endif
