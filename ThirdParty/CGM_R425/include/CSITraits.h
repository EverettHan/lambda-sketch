#ifndef CSITraits_H
#define CSITraits_H

#include <type_traits>

namespace CSI
{
  // Define C++14/17 helper methods for clever people forcing C++11 in their makefiles
  template <class T>
  constexpr bool is_pointer_v = std::is_pointer<T>::value; //

  template <class T>
  constexpr bool is_class_v = std::is_class<T>::value; //
  // End C++14/17

  // Define C++20 helper methods for platforms not supporting C++20 yet
  template <class T>
  struct remove_cvref
  {
    using type = std::remove_cv_t<std::remove_reference_t<T>>;
  };

  template <class T>
  using remove_cvref_t = typename remove_cvref<T>::type;
  // End C++20
} // namespace CSI

#endif
