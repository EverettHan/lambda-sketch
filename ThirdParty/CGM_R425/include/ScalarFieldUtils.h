#ifndef __ScalarFieldUtils_h
#define __ScalarFieldUtils_h

#include "CATBaseUnknown.h"
#include "CATUuid.h"

#include "ScalarFields.h"

#include <iostream>
#include <chrono>

namespace sf {
  enum Token {END, X, Y, Z, DOUBLE, POLY,
  PLUS, SQUARE, MINUS, MULT, MIN, MAX, NOT, COS, SIN, ROOT,
  DIV, ABS, EXP, LN, POW, SYMDIFF, WITHOUT, ACOS, ASIN, TAN, ATAN,
  SIGN};
}

#ifdef _LINUX_SOURCE
#define SFINLINE __always_inline
#else
#define SFINLINE inline
#endif

#ifndef SF_TIMER
#define SF_TIMER

// Macro for timings. Call First SF_RESET on your timer
// then each time you will call SF_ELAPSED you will have timing
// info in the logs, with respect to the last time you called SF_RESET.
//
// timer need to be a std::chrono::high_resolution_clock::time_point
// for Example std::chrono::high_resolution_clock::time_point renderTime
#define SF_RESET(timer) \
  { \
    std::cout << "Elapsed Time reset for " << #timer << " in " << __func__ \
            << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
    timer = std::chrono::high_resolution_clock::now(); \
  }

#define SF_ELAPSED(timer) \
  { \
  std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer); \
  std::cout << "Elapsed Time for " << #timer << " in " << __func__ \
            << " at " << __FILE__ << ":" << __LINE__ << " " \
            << " : " << elapsed.count() << " ms" << std::endl; \
  }
#endif // SF_TIMER

#ifndef SF_CHECK_HELPERS
#define SF_CHECK_HELPERS

#define CHECK_HR(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return hr; \
  }

#define CHECK_HR_NO_RET(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
  }

#define CHECK_HR_RET_THAT(hr, that) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return that; \
  }

#define CHECK_HR_RET(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return; \
  }

#define CHECK_HR_RETI(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return 1; \
  }

#define CHECK_HR_RETB(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return FALSE; \
  }

#define CHECK_HR_RETPTR(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return nullptr; \
  }

#define LOG_INFO(msg) \
  { \
    std::cout << "Info from " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << msg << std::endl; \
  }

#define LOG_INFO_VAL(msg, msgval) \
  { \
    std::cout << "Info from " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << msg << " " << msgval << std::endl; \
  }

#define LOG_ERROR(msg) \
  { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << msg << std::endl; \
  }

#define LOG_NULL_PTR(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
  }

#define LOG_NULL_MPTR(ptr) \
  if(ptr.get()==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
  }
  
#define CHECK_PTR(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    return E_FAIL; \
  }

#define CHECK_PTR_RET(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    return; \
  }

#define CHECK_PTR_RETI(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    return 1; \
  }

#define CHECK_PTR_RETB(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    return FALSE; \
  }

#define CHECK_PTR_RETPTR(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    return nullptr; \
  }

#define CHECK_CONDITION(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return E_FAIL; \
  }

#define CHECK_CONDITION_RET(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return; \
  }

#define CHECK_CONDITION_AND_LOG(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
  }

#define CHECK_CONDITION_RETI(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return 1; \
  }

#define CHECK_CONDITION_RETB(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return FALSE; \
  }

#define CHECK_CONDITION_RETPTR(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return nullptr; \
  }

#define CHECK_CONDITION_RET_THAT(cond, that) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return that; \
  }

#define CHECK_CONDITION_NO_RET(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return; \
  }
#endif // SF_CHECK_HELPERS

#endif
