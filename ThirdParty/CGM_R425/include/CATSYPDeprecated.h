#pragma once

//#if defined DISABLE_SYP_DEPRECATED_WARNINGS
#  define SYP_DEPRECATED(message)   /* disable deprecation warnings */
// #else
// #  if defined (__cplusplus) && (__cplusplus >= 201402) /* C++14 or greater */
// #    define SYP_DEPRECATED(message) [[deprecated(message)]]
// #  elif defined(_MSC_VER)
// #    define SYP_DEPRECATED(message) __declspec(deprecated(message))
// #  elif defined(__clang__) || (defined(__GNUC__) && (__GNUC__ * 10 + __GNUC_MINOR__ >= 45))
// #    define SYP_DEPRECATED(message) __attribute__((deprecated(message)))
// #  elif defined(__GNUC__) && (__GNUC__ * 10 + __GNUC_MINOR__ >= 31)
// #    define SYP_DEPRECATED(message) __attribute__((deprecated))
// #  else
// #    pragma message("WARNING: SYP_DEPRECATED needs custom implementation for this compiler")
// #    define SYP_DEPRECATED(message)   /* disabled */
// #  endif
// #endif /* DISABLE_SYP_DEPRECATED_WARNINGS */
