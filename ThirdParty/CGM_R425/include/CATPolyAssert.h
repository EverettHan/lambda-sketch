#pragma once


#if (defined(__GNUC__) && defined(_LINUX_SOURCE))
  #if (!defined(__OPTIMIZE__) && !defined(NDEBUG))

#include <cstdio>
#include <cstdlib>
#include <string>
#include "PolyMathUtils.h"

ExportedByPolyMathUtils void poly_assert_fail(std::string const& expr, std::string const& file, std::string const& function, unsigned int const line, std::string const& msg = "");

#define poly_assert(expr) (static_cast<bool>(expr) ? (void)0 : poly_assert_fail(#expr, __FILE__, __func__, __LINE__))
#define poly_assert_msg(expr, msg) (static_cast<bool>(expr) ? (void)0 : poly_assert_fail(#expr, __FILE__, __func__, __LINE__, msg))

#define POLY_DEBUG_BUILD 1

  #else

#define poly_assert(expr) void(0)
#define poly_assert_msg(expr, msg) void(0)

  #endif

#else

#define poly_assert(expr) void(0)
#define poly_assert_msg(expr, msg) void(0)

#endif
