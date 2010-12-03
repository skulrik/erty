#pragma once
#ifndef _LOG_LEVEL_H_
#define _LOG_LEVEL_H_

/** Trigger a debug log message */
struct Debug
{
    /** Return the logging level as a character string. */
    const char* level()
    {
        return "DEBUG";
    }

    /** Return the logging prioriry value. */
    unsigned int priority()
    {
        return 0;
    }
};

/** Trigger an information log message */
struct Info
{
    /** Return the logging level as a character string. */
    const char* level()
    {
        return "INFO ";
    }

    /** Return the logging prioriry value. */
    unsigned int priority()
    {
        return 10;
    }
};

/** Trigger an error log message */
struct Error
{
    /** Return the logging level as a character string. */
    const char* level()
    {
        return "ERROR";
    }

    /** Return the logging prioriry value. */
    unsigned int priority()
    {
        return 20;
    }
};

/**
 * Compage two LogLevel priority.
 * @param a the first LogLevel.
 * @param b the second LogLevel.
 * @tparam A the first LogLevel type.
 * @tparam B the second LogLevel type.
 * @return true if a prioriry is greater than b priority.
 */
template <class A, class B>
bool operator>(A a, B b)
{
    return (a.priority() > b.priority());
}

/**
 * Compage two LogLevel priority.
 * @param a the first LogLevel.
 * @param b the second LogLevel.
 * @tparam A the first LogLevel type.
 * @tparam B the second LogLevel type.
 * @return true if a prioriry is lesser than b priority.
 */
template <class A, class B>
bool operator<(A a, B b)
{
    return (a.priority() < b.priority());
}

/**
 * Compage two LogLevel priority.
 * @param a the first LogLevel.
 * @param b the second LogLevel.
 * @tparam A the first LogLevel type.
 * @tparam B the second LogLevel type.
 * @return true if a prioriry is equal to b priority.
 */
template <class A, class B>
bool operator==(A a, B b)
{
    return (a.priority() == b.priority());
}

/**
 * Compage two LogLevel priority.
 * @param a the first LogLevel.
 * @param b the second LogLevel.
 * @tparam A the first LogLevel type.
 * @tparam B the second LogLevel type.
 * @return true if a prioriry is different than b priority.
 */
template <class A, class B>
bool operator!=(A a, B b)
{
    return (a.priority() != b.priority());
}

/**
 * Compage two LogLevel priority.
 * @param a the first LogLevel.
 * @param b the second LogLevel.
 * @tparam A the first LogLevel type.
 * @tparam B the second LogLevel type.
 * @return true if a prioriry is lower or equal than b priority.
 */
template <class A, class B>
bool operator<=(A a, B b)
{
    return (a.priority() <= b.priority());
}

/**
 * Compage two LogLevel priority.
 * @param a the first LogLevel.
 * @param b the second LogLevel.
 * @tparam A the first LogLevel type.
 * @tparam B the second LogLevel type.
 * @return true if a prioriry is greater or equal than b priority.
 */
template <class A, class B>
bool operator>=(A a, B b)
{
    return (a.priority() >= b.priority());
}

#endif
