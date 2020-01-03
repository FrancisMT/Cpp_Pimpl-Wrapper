/**
 * This header provides the opaque impl type
 * and its pointer;
 **/

#pragma once

#include <memory>
#include <utility>

template<typename T>
class pimpl {

public:
    
    template<typename ...Args>
    pimpl(Args&& ...);

    pimpl();
    ~pimpl();
    
    T* operator->();
    T& operator*();

private:
    std::unique_ptr<T> impl;
};

//**************************************************************
/**
 * This constructor exists to provide a way to pass
 * initialization values through to the impl object.
 *
 * Since pimpl itself knows nothing about the impl type,
 * we use a constructor with a forwarding reference as
 * an argument and then it’s perfect forwarding to the rescue!
 **/ 
template<typename T>
template<typename ...Args>
pimpl<T>::pimpl(Args&& ...args)
    : impl{std::make_unique<T>(std::forward<Args>(args)...)} {}

template<typename T>
pimpl<T>::pimpl()
    : impl{std::make_unique<T>()} {}

template<typename T>
pimpl<T>::~pimpl() { }

template<typename T>
T* pimpl<T>::operator->() {
    return m.get();
}

template<typename T>
T& pimpl<T>::operator*() {
    return *m.get();
}