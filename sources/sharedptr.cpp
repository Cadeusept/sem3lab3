// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <sharedptr.hpp>

template <typename T>
SharedPtr<T>::SharedPtr() {

}

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) {

}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &r) {

}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr &&r) {

}

template <typename T>
SharedPtr<T>::~SharedPtr() {

}

template <typename T>
SharedPtr<T>::operator bool() const {
  return false;
}

template <typename T>
auto SharedPtr<T>::operator*() const -> T & {
  return ;
}

template <typename T>
auto SharedPtr<T>::operator->() const -> T * {
  return nullptr;
}

template <typename T>
auto SharedPtr<T>::get() -> T * {
  return nullptr;
}

template <typename T>
void SharedPtr<T>::reset() {

}

template <typename T>
void SharedPtr<T>::reset(T *ptr) {

}

template <typename T>
void SharedPtr<T>::swap(SharedPtr &r) {

}

template <typename T>
auto SharedPtr<T>::use_count() const -> size_t {
  return 0;
}
