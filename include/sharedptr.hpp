// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_SHAREDPTR_HPP_
#define INCLUDE_SHAREDPTR_HPP_

#include <atomic>
#include <cstdint>
#include <cstdlib>

template <typename T>
class SharedPtr {
public:
    SharedPtr() {
      this->_ptr = nullptr;
      this->_count = new int(0);
    }

    SharedPtr(T* ptr) {
      this->_ptr = ptr;
      this->_count = new int(1);
    }

    SharedPtr(const SharedPtr& r) {
      this->_ptr = r.ptr;
      this->_count = r.use_count();
      *this->_count++;
    }

    SharedPtr(SharedPtr&& r) {
      this->_ptr = *r.get();
      this->_count = *r.use_count();
      *this->count++;
    }
    ~SharedPtr() {
      *this->_count--;
      if ((*_count == 0) && this) {
        delete this->_ptr;
        delete this->_count;
      }
    }

    auto operator=(const SharedPtr& r) -> SharedPtr& {
      _ptr=r.get();
      *_count=r.use_count();
    }

    auto operator=(SharedPtr&& r) -> SharedPtr& {
      _ptr=*r.get();
      *_count=*r.use_count();
    }

    // проверяет, указывает ли указатель на объект
    operator bool() const {
      if (this->_ptr == nullptr)
        return false;
      else
        return true;
    }

    auto operator*() const -> T& {
      return *this->_ptr;
    }

    auto operator->() const -> T* {
      return this->_ptr;
    }

    auto get() -> T* {
      return this->_ptr;
    }



    void reset() {
      *this->_count--;
      if (this->use_count() == 0) {
        delete this->_ptr;
        delete this->_count;
      }

      this->_ptr = nullptr;
      this->_count = nullptr;
    }

    void reset(T* ptr) {
      this->_ptr = ptr;
      *this->_count--;
      *this->_count = 1;
    }

    void swap(SharedPtr& r) {
      T* tmp_ptr = r.get();
      std::atomic<std::uint64_t> tmp_count = r.use_count();

      r = this;

      this->_ptr = tmp_ptr;
      *this->_count = tmp_count;
    }

    // возвращает количество объектов SharedPtr, которые ссылаются на тот же управляемый объект
    auto use_count() const -> size_t {
      return (size_t)(*_count);
    }

private:
    T* _ptr;
    std::atomic<std::uint64_t>* _count;
};

#endif // INCLUDE_SHAREDPTR_HPP_
