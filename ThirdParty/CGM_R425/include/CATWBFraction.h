// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBFraction.h
// Header definition of CATWBFraction
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
// 24/05/19 Q48 Creation (upgrade from struct to class for streaming)
//===================================================================

#ifndef CATWBFraction_h
#define CATWBFraction_h

// Exported by
#include "WhiteBoxData.h"

// String
#include "CATCDSString.h"

// Debug
#include "CATWBDebug.h"

class ExportedByWhiteBoxData CATWBFraction // = n/m * Pi ^ k
{
public:

  CATWBFraction();
  ~CATWBFraction();

public:

#ifdef WDE1Proto_LongInteger
  double _n;
  double _m;
  int _k;
  double _pgcd;
#else
  int _n;
  int _m;
  int _k;
  //int _pgcd;
#endif

//  // Streaming
//protected:
//  friend class CATWBExpression; // not sure this is the best way to do this!!
//
//  void StreamProtected(CATCDSString & ioString) const;
//
//  static CATWBFraction UnstreamProtected(const CATCDSString & iString,
//                                         const int            iVersionOfStream);
};

#endif // CATWBFraction_h
