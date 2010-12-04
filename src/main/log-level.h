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

#endif
