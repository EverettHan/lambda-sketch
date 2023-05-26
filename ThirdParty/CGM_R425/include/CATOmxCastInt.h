#ifndef __CATOmxCastInt_H
#define __CATOmxCastInt_H

#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATOmxStaticAssert.h"
#include "CATDataType.h"

/** internal usage*/
ExportedByCATOmxKernel void CATOmxOnIntegerOverflow();
ExportedByCATOmxKernel void CATOmxOnIntegerOverflow(const void* data, size_t type);
#if OMX_ENABLE_STATIC_ASSERT == 1
#define OMX_ENCODE_INT_TYPE(type) ((sizeof(type) << 1) + std::is_signed<type>::value)
#endif

/**
 * internal usage.
 * purpose of this class is to hold an integer and be able to  "safely" cast it to another type of integer
 * never use directly, see CATOmxCastInt.
 */
template<typename Int>
class CATOmxCastableInt
{
  const Int m_value;

public:
  inline CATOmxCastableInt(Int value) :m_value(value) {}

  template<typename Int2>
  inline operator const Int2() const
  {
    OMX_STATIC_ASSERT(std::is_integral<Int2>::value, "CATOmxCastInt must be used only on integer types");
    const Int value = m_value;
    const Int2 value2 = static_cast<Int2>(value);
    if (static_cast<Int>(value2) != value || ((value >= 0) != (value2 >= 0)))
    {
#if OMX_ENABLE_STATIC_ASSERT == 1
      CATOmxOnIntegerOverflow(&m_value, OMX_ENCODE_INT_TYPE(Int));
#else
      CATOmxOnIntegerOverflow(NULL, 0);
#endif
    }
    return value2;
  }
#ifdef _WINDOWS_SOURCE
  //this overload works on windows but at least on linux it is always used instead of the generic one...damn this language and its compilers
  inline operator const Int() const { return m_value; }
#endif
};

/**
 * Clean(er) way to handle integer conversions
 * Use it when you need to cast an integer to another type of integer and ensure there is no overflow
 * For example it can allow to replace:
 *    size_t s;
 *    ULONG ul = (ULONG)s;
 *    CATAssert( ul == s );
 * by
 *    size_t s;
 *    ULONG ul = CATOmxCastInt(s);
 * Notice that sign a also checked, meaning that:
 * unsigned int u = 2147483648;
 * int i = CATOmxCastInt(u); //assertion raised here as i would be negative
 */
template<typename Int>
inline CATOmxCastableInt<Int> CATOmxCastInt(Int i)
{
  OMX_STATIC_ASSERT(std::is_integral<Int>::value, "CATOmxCastInt must be used only on integer types");
  return CATOmxCastableInt<Int>(i);
}

#endif

