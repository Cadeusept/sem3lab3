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
      _ptr = nullptr;
      _count = nullptr;
    }

    SharedPtr(T* ptr) {
      _ptr = ptr;
      _count = new std::atomic<std::uint64_t>(1);
    }

    SharedPtr(const SharedPtr& r) {
      if (r._ptr != nullptr) {
        _ptr = r._ptr;
        _count = r._count;
        *_count++;
      } else {
        _ptr = nullptr;
        _count = nullptr;
      }

    }

    SharedPtr(SharedPtr&& r) {
      _ptr = r._ptr;
      _count = r._count;

      r.clear();
    }

    ~SharedPtr() {
      clear();
    }

    auto operator=(const SharedPtr& r) -> SharedPtr& {
      clear();
      _ptr = r._ptr;
      _count = r._count;

      if (r._ptr != nullptr) {
        *_count++;
      }

      return *this;
    }

    auto operator=(SharedPtr&& r) -> SharedPtr& {
      clear();
      _ptr = r._ptr;
      _count = r._count;

      if (r._ptr != nullptr) {
        *_count++;
      }

      r.clear();
      return *this;
    }

    // проверяет, указывает ли указатель на объект
    operator bool() const {
      return (_ptr != nullptr);
    }

    auto operator*() const -> T& {
      return *_ptr;
    }

    auto operator->() const -> T* {
      return _count;
    }

    auto get() -> T* {
      return _ptr;
    }

    void reset() {
      clear();
    }

    void reset(T* ptr) {
      clear();

      _ptr=ptr;
      _count = new std::atomic<std::uint64_t>(1);
    }

    void swap(SharedPtr& r) {
      std::swap(_ptr,r._ptr);
      std::swap(_count,r._count);
    }

    // возвращает количество объектов SharedPtr,
    // которые ссылаются на тот же управляемый объект
    auto use_count() const -> size_t {
      if (!this)
        return static_cast<size_t>(*_count);
      else
        return 0;
    }

private:
    T* _ptr;
    std::atomic<std::uint64_t>* _count;

    void clear() {
      if (_count != nullptr) {
        *_count--;
        if ((*_count == 0) && this) {
          delete _ptr;
          delete _count;
        }
      }
    }
};

#endif // INCLUDE_SHAREDPTR_HPP_
