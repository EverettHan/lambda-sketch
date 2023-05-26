#ifndef OPTIONAL_H
#define OPTIONAL_H

#include "CATOmxCxxPortability.h"
#include "CATOmxKernel.h"

namespace CATOmx
{
  namespace Internals
  {
    OMX_Cxx11_NORETURN ExportedByCATOmxKernel  void BadOptionalAccessAssertion();
  }


  // NAME
  //		optional - cheap alternative to std::optional in C++17
  //
  // SYNOPSIS
  //		optional<double> x;
  //		x = 3.14;
  //		if (x) y = x.value();
  //
  // DESCRIPTION
  //		This class provide a simple implementation of the "real" std::optional, with
  //		somewhat limited fuctionality. It should however be upward compatible.
  template <typename T>
  struct optional
  {
    optional() : has_val(false) { }

    template <typename U>
    optional(const U& x) : val(x), has_val(true) { }

    optional(const optional& x) {
      if (has_val = x.has_value())
        new (&val) T(x.value());
    }

    ~optional() { reset(); }

    void reset() {
      if (has_value())
      {
        val.T::~T();
        has_val = false;
      }
    }

    bool has_value() const { return has_val; }
    explicit operator bool() const { return has_value(); }

    const T& value() const & { return const_cast<optional&>(*this).value(); }
    T& value() & {
      if (!has_value())
        Internals::BadOptionalAccessAssertion();
      return val;
    }

    T&& value() && = delete;
    const T&& value() const && = delete;

    T value_or(const T& def) const { return has_value() ? value() : def; }

    optional& operator=(const optional<T>& x) {
      if (!x.has_value())
        reset();
      else
        *this = x.value();
      return *this;
    }

    template <typename U>
    optional& operator=(const U& x) {
      if (this->has_value())
        val = x;
      else {
        new (&val) T(x);
        has_val = true;
      }
      return *this;
    }

    template <typename U>
    void operator=(const optional<U>& x) {
      if (!x.has_value())
        reset();
      else
        *this = x.value();
    }

    const T* operator->() const & { return &value(); }
    T* operator->() & { return &value(); }
    const T& operator*() const & { return value(); }
    T& operator*() & { return value(); }

    const T* operator->() const && = delete;
    T* operator->() && = delete;
    const T& operator*() const && = delete;
    T& operator*() && = delete;
  private:
    bool has_val;
    union { T val; bool dummy; };
  };
}

#endif
