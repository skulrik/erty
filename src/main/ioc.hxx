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
#ifndef _IOC_HXX_
#define _IOC_HXX_

#include "utils.h"

#include <stdexcept>
#include <string>
#include <map>
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>

namespace erty
{

// ----------------------------------------------------------------------------
// IOC
// ----------------------------------------------------------------------------

template<class T>
void IoC::Register(T* objectPtr)
{
    Register<T>(getTypeName<T>(), objectPtr);
}
// ----------------------------------------------------------------------------

template<class T>
void IoC::Register(const std::string& name, T* objectPtr)
{
    _iocContainer[name] = boost::shared_ptr<void>(objectPtr);
}
// ----------------------------------------------------------------------------

template<class T>
T* IoC::Resolve()
{
    return Resolve<T>(getTypeName<T>());
}
// ----------------------------------------------------------------------------

template<class T>
T* IoC::Resolve(const std::string& name)
{
    return (T*)(_iocContainer[name].get());
}
// ----------------------------------------------------------------------------

template<class T>
bool IoC::IsRegistered()
{
    return IsRegistered<T>(getTypeName<T>());
}
// ----------------------------------------------------------------------------

template<class T>
bool IoC::IsRegistered(const std::string& name)
{
    return (_iocContainer.find(name) != _iocContainer.end());
}
// ----------------------------------------------------------------------------

template<class T>
void IoC::UnRegister()
{
    UnRegister<T>(getTypeName<T>());
}
// ----------------------------------------------------------------------------

template<class T>
void IoC::UnRegister(const std::string& name)
{
    Register<T>(name, 0);
    _iocContainer.erase(name);
}
// ----------------------------------------------------------------------------

template <class T>
T& IoC::Inject(bool autocreate)
{
    return Inject<T>(getTypeName<T>(), autocreate);
}
// ----------------------------------------------------------------------------

template <class T>
T& IoC::Inject(const std::string& name, bool autocreate)
{
    T* object = 0;

    if (IoC::IsRegistered<T>(name))
    {
        object = IoC::Resolve<T>(name);
    }
    else if (autocreate)
    {
        object = new T();
        IoC::Register<T>(name, object);
    }

    if (object == 0)
    {
        throw IoCException((_F("No object registered for type %1% with name %2%.") % getTypeName<T>() % name).str().c_str());
    }

    return *object;
}
// ----------------------------------------------------------------------------

template <class T>
std::string IoC::getTypeName()
{
    return DEMANGLE(T);
}
// ----------------------------------------------------------------------------

}

#endif
