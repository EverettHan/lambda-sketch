// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// List of darts
//
//=============================================================================
// 2022-04-01 NDO Custom list for template darts.
//=============================================================================
#pragma once

#include "CATListPV.h"
#include "Poly/TypeTraits.h"

template<size_t N> class CATPolyDart;
#ifndef _AIX_SOURCE
using CATPolyDart2 = CATPolyDart<2>;
using CATPolyDart3 = CATPolyDart<3>;
#else
typedef CATPolyDart<2> CATPolyDart2;
typedef CATPolyDart<3> CATPolyDart3;
#endif


class CATPolyDartList : public CATListPV
{
public:

  CATPolyDartList () {}

  template<class DART>
  inline int Append (DART* d);

  template<class DART>
  inline DART* Get (int iPos) const;

  template<class DART>
  inline int RemoveValue (DART* d);

};


template<class DART>
inline int CATPolyDartList::Append (DART* d)
{
#ifndef _AIX
  static_assert (Poly::is_same<DART, CATPolyDart2>::value || Poly::is_same<DART, CATPolyDart3>::value);
#endif
  return CATListPV::Append (d);
}


template<class DART>
inline DART* CATPolyDartList::Get (int iPos) const
{
#ifndef _AIX
  static_assert (Poly::is_same<DART, CATPolyDart2>::value || Poly::is_same<DART, CATPolyDart3>::value);
#endif
  return (DART*) operator[] (iPos);
}


template<class DART>
inline int CATPolyDartList::RemoveValue (DART* d)
{
#ifndef _AIX
  static_assert (Poly::is_same<DART, CATPolyDart2>::value || Poly::is_same<DART, CATPolyDart3>::value);
#endif
  return CATListPV::RemoveValue (d);
}
