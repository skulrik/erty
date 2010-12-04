/*
===============================================================================
    COPYING PERMISSION STATEMENT
===============================================================================
    This file is part of CPP_APP_TEMPLATE.

    CPP_APP_TEMPLATE is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CPP_APP_TEMPLATE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CPP_APP_TEMPLATE.  If not, see <http://www.gnu.org/licenses/>.
===============================================================================
*/
#pragma once
#ifndef _IOC_H_
#define _IOC_H_

#include "utils.h"

#include <stdexcept>
#include <string>
#include <map>
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

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
    IoCException(const char* message) :
        std::runtime_error((_F("IoCException: %1%") % message).str()) {}
};

/**
 * Inversion od control container class.
 * All the container does is mapping the name of an interface to an instance of this interface.
 */
class IoC
{
public:
    /**
     * Register an object pointer with it type name.
     * @param objectPtr rTthe instance to register.
     * @tparam T The object type.
     */
    template<class T>
    static void Register(T* objectPtr)
    {
        _typeInstanceMap[typeid(T).name()] = boost::shared_ptr<void>(objectPtr);
    }

    /**
     * Return an object pointer registred by its type name.
     * @tparam T The object type.
     * @return the registered object.
     */
    template<class T>
    static T* Resolve()
    {
        return (T*)(_typeInstanceMap[typeid(T).name()].get());
    }

    /**
     * Return true if an object is registered for a type.
     * @tparam T The object type.
     * @return true if an object is registered, else false.
     */
    template<class T>
    static bool IsRegistered()
    {
        return (_typeInstanceMap.find(typeid(T).name()) != _typeInstanceMap.end());
    }

    /**
     * Remove the registered object for a type.
     * @tparam T The object type.
     */
    template<class T>
    static void UnRegister()
    {
        Register<T>(0);
    }

private:
    /** The map name->instance. */
    static std::map<std::string, boost::shared_ptr<void> > _typeInstanceMap;

    DISALLOW_DEFAULT_COPY_AND_ASSIGN(IoC);
};

#endif
