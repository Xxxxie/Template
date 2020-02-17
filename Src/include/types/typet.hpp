#ifndef TYPET_HPP
#define TYPET_HPP

#include "type2.hpp"

template<typename T>
class TypeT
{
public:
    enum{ IsFundaT = IsFundaT<T>::Yes,
        IsPtrT = CompoundT<T>::IsPtrT,
        IsRefT = CompoundT<T>::IsRefT,
        IsArrayT = CompoundT<T>::IsArrayT,
        IsFuncT = CompoundT<T>::IsFuncT,
        IsPtrMemT = CompoundT<T>::IsPtrMemT,
        IsEnumT = IsEnumT<T>::Yes,
        IsClassT = IsClassT<T>::Yes};
};

#endif