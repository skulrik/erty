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
#ifndef _IOC_H_
#define _IOC_H_

#include "utils.h"

#include <stdexcept>
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>

namespace erty
{

/**
 * IoC method can throws exception of this kind.
 */
class IoCException : public std::runtime_error
{
public:
    /**
     * Create a new IoCException with a specific message.
     * @param message the exception message.
     */
    IoCException(const char* message);
};

/** Type in which are registered the instance. */
typedef std::map<std::string, boost::shared_ptr<void> > IoCContainer;

/**
 * Inversion od control container class.
 * All the container does is mapping the name of an interface to an instance of this interface.
 */
class IoC
{
public:
    /**
     * Register an object pointer with it type name.
     * @param objectPtr The instance to register.
     * @tparam T The object type.
     */
    template<class T>
    static void Register(T* objectPtr);

    /**
     * Register an object pointer to a specific name.
     * @param name The name to which register the object.
     * @param objectPtr The instance to register.
     * @tparam T The object type.
     */
    template<class T>
    static void Register(const std::string& name, T* objectPtr);

    /**
     * Return an object pointer registred by its type name.
     * @tparam T The object type.
     * @return the registered object.
     */
    template<class T>
    static T* Resolve();

    /**
     * Return an object pointer registred by its registered name.
     * @param name The name to which register the object.
     * @tparam T The object type.
     * @return the registered object.
     */
    template<class T>
    static T* Resolve(const std::string& name);

    /**
     * Return true if an object is registered for a type.
     * @tparam T The object type.
     * @return true if an object is registered, else false.
     */
    template<class T>
    static bool IsRegistered();

    /**
     * Return true if an object is registered for a given name.
     * @param name The name to which register the object.
     * @tparam T The object type.
     * @return true if an object is registered, else false.
     */
    template<class T>
    static bool IsRegistered(const std::string& name);

    /**
     * Remove the registered object for a type.
     * @tparam T The object type.
     */
    template<class T>
    static void UnRegister();

    /**
     * Remove the registered object to a specific name.
     * @param name The name to which register the object.
     * @tparam T The object type.
     */
    template<class T>
    static void UnRegister(const std::string& name);

    /**
     * Unregister all objects present in the ioc container.
     */
    static void UnRegisterAll();

    /**
     * Retrieve an object from the ioc container, to inject it in the current context.
     * @param autocreate will create the object if its not in the ioc container.
     * @tparam T the type of the object to inject.
     * @return the requested object.
     * @throe IoCException
     */
    template <class T>
    static T& Inject(bool autocreate = true);

    /**
     * Retrieve an object from the ioc container, to inject it in the current context.
     * @param name The name to which register the object.
     * @param autocreate will create the object if its not in the ioc container.
     * @tparam T the type of the object to inject.
     * @return the requested object.
     * @throe IoCException
     */
    template <class T>
    static T& Inject(const std::string& name, bool autocreate = true);

private:

    /**
     * Return the string version of a type name.
     * @tparam T the type
     * @return the type name
     */
    template <class T>
    static std::string getTypeName();

    /** The map name->instance. */
    static IoCContainer _iocContainer;

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(IoC);
};

}

#include "ioc.hxx"

#endif
