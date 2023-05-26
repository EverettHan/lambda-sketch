#ifndef DSYSysString_H
#define DSYSysString_H

//*****************************************************************************
//* DEPRECATED R425 - DO NOT USE!                                             *
//* Officially supported string-related helpers:
//*  - DSYStringHelper.h ('CUSFrom' to build a CATUnicodeString from various inputs)
//*  - DSYStringView.h   ('make_view' for efficient conversion between various string types)
//*  - DSYString*.h
//*****************************************************************************

#if (__cplusplus < 202002L)

#include "DSYString.h"  // CATUnicodeString
#include "DSYStringView.h" // make_view
#include "DSYSysCommon.h"  // DSYSysStrDup, _DSYSysUTF8_

//=======================================================================
/** @nodoc */
// [[deprecated("Use 'make_view' instead (DSYStringView.h) to avoid explicit memory allocation, or use CATUnicodeString::ConvertToUTF8 (cf. code sample in DSYString.h)")]]
inline _DSYSysUTF8_(char)* DSYSysStrToUTF8(const CATUnicodeString& irUnicodeString)
//=======================================================================
{
  using namespace DSY::UCS;
  auto s = make_view<char, ToUTF8>(irUnicodeString);
  const char* l_pUnicodeString = s.data();
  return ( nullptr != l_pUnicodeString ) ? DSYSysStrDup(l_pUnicodeString) : nullptr;
}

#endif

#endif  // DSYSysString_H
