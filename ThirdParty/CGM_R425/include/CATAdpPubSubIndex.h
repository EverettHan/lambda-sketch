// COPYRIGHT Dassault Systemes 2006
// Code removed in R419 / 2017x, keeping just not implemented API such callers can continue compiling

#ifndef CATAdpPubSubIndex_H
#define CATAdpPubSubIndex_H

#include "CATIAV5Level.h"
class CATUnicodeString;
class CATAdpPubSubIndex
{
public:
  inline HRESULT Marshall (CATUnicodeString &oOccurenceIndex) {return E_FAIL;}
  inline HRESULT UnMarshall(const CATUnicodeString &iOccurenceIndex) {return E_FAIL;}
};
#endif
