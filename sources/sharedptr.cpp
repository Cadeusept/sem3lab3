// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <sharedptr.hpp>

template <typename T>
SharedPtr<T>::SharedPtr() {
  this->_ptr = nullptr;
  this->_count = 0;
}

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) {
  this->_ptr = ptr;
  this->_count = 1;
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr &r) {
  this->_ptr = r.ptr;
  this->_count = r.use_count();
  this->_count++;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr &&r) {
  this->_ptr = *r.get();
  this->_count = *r.use_count();
  this->count++;
}

template <typename T>
SharedPtr<T>::~SharedPtr() {
  this->_count--;
  if ( (this->_count == 0) && this) {
    delete this->_ptr;
  }
}

template <typename T>
SharedPtr<T>::operator bool() const {
  if (this->_ptr == nullptr)
    return false;
  else
    return true;
}

template <typename T>
auto SharedPtr<T>::operator*() const -> T & {
  return *this->_ptr;
}

template <typename T>
auto SharedPtr<T>::operator->() const -> T * {
  return this->_ptr;
}

template <typename T>
auto SharedPtr<T>::get() -> T * {
  return this->_ptr;
}

template <typename T>
void SharedPtr<T>::reset() {
  this->_count--;
  this->_ptr = nullptr;
}

template <typename T>
void SharedPtr<T>::reset(T *ptr) {
  this->_ptr = ptr;
  this->_count = 1;
}

template <typename T>
void SharedPtr<T>::swap(SharedPtr &r) {
  T* tmp_ptr = r.get();
  size_t tmp_count = r.use_count();

  r = this;

  this->_ptr = tmp_ptr;
  this->_count = tmp_count;
}

template <typename T>
auto SharedPtr<T>::use_count() const -> size_t {
  return _count;
}
