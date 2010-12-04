#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

/**
 * Base class of all logger classes.
 */
class Logger
{
public:
    virtual ~Logger(void) {}

    /**
     * Return the unique identifier of the logger.
     * @return the unique identifier of the logger.
     */
    virtual const std::string& uuid() const
    {
        return _uuid;
    }

    /**
     * Log a message.
     * All loggerclass must implement this method.
     * @param message the message to log.
     */
    virtual void write(const std::string& message) = 0;

protected:

    /**
     * Set the unique identifier of the logger.
     * Must be call in the constructor of each subclasses.
     * @param uuid the unique identifier of the logger.
     */
    void uuid(const std::string& uuid)
    {
        _uuid = uuid;
    }

private:
    /** The uniqueidentifier of the logger. */
    std::string _uuid;
};

/**
 * Compare two logger for equality.
 * @param a the first identifier.
 * @param b the second identifier.
 * @return true if the two logger have the same uuid, else false.
 */
inline bool operator==(const Logger& a, const Logger& b)
{
    return (a.uuid() == b.uuid());
}

#endif
