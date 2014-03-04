#pragma once

#include <memory>
#include <type_traits>

namespace std {

template<class T, class... Ts>
typename enable_if<!is_array<T>::value, unique_ptr<T>>::type
make_unique(Ts&&... Args) {
    return (unique_ptr<T>(new T(forward<Ts>(Args)...)));
}

template<class T>
typename enable_if<is_array<T>::value && extent<T>::value == 0, unique_ptr<T>>::type
make_unique(size_t size) {
    typedef typename remove_extent<T>::type element;
    
    return (unique_ptr<T>(new element[size]()));
}

template<class T, class... Ts>
typename enable_if<extent<T>::value != 0, void>::type
make_unique(Ts&&...) = delete;

}
