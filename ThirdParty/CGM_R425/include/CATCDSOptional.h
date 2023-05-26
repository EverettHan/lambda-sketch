#ifndef CATCDSOptional_H
#define CATCDSOptional_H

#if (defined(_DARWIN_SOURCE) && __clang_major__ <= 10)  || (defined(_ANDROID_SOURCE) &&  __cplusplus < 201703L) || (defined(_IOS_SOURCE) && __clang_major__ <= 10)

#include <memory>

namespace std
{
  template<class T>
  class optional
  {
  public:
    optional() = default;
    ~optional() = default;
    optional(optional const &);
    optional& operator=(optional const&);
    optional(optional &&) = default;
    optional& operator=(optional &&) = default;
    optional(nullptr_t);
    optional& operator=(nullptr_t);
    optional(T const &);
    optional& operator=(T const &);

    T & value();
    T const & value() const;

    T & operator*();
    T const & operator*() const;

    operator bool() const;

  private:
    std::unique_ptr<T> _pValue;
  };

  template<class T>
  optional<T>::optional(optional const &iOpt)
    : _pValue(iOpt._pValue ? new T(*iOpt._pValue) : nullptr)
  {

  }

  template<class T>
  optional<T>& optional<T>::operator=(optional const& iOpt)
  {
    if (this != &iOpt)
      _pValue = std::unique_ptr<T>(iOpt._pValue ? new T(*iOpt._pValue) : nullptr);
    return *this;
  }

  template<class T>
  optional<T>::optional(nullptr_t)
  {
  }

  template<class T>
  optional<T>& optional<T>::operator=(nullptr_t)
  {
    _pValue = nullptr;
    return *this;
  }

  template<class T>
  optional<T>::optional(T const &iT)
    : _pValue(new T(iT))
  {
  }

  template<class T>
  optional<T>& optional<T>::operator=(T const &iT)
  {
    _pValue = std::unique_ptr<T>(new T(iT));
    return *this;
  }

  template<class T>
  T & optional<T>::value()
  {
    return *_pValue;
  }

  template<class T>
  T const & optional<T>::value() const
  {
    return *_pValue;
  }

  template<class T>
  T & optional<T>::operator*()
  {
    return *_pValue;
  }

  template<class T>
  T const & optional<T>::operator*() const
  {
    return *_pValue;
  }

  template<class T>
  optional<T>::operator bool() const
  {
    return !!_pValue;
  }

  constexpr nullptr_t nullopt = nullptr;
}

#else
#include <optional>
#endif

#endif
