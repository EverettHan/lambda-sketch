// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPDeclareBitFieldFactory.h
// Header definition of CATSYPDeclareBitFieldFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2012  Creation: qf1
//===================================================================
#ifndef CATSYPDeclareBitFieldFactory_H
#define CATSYPDeclareBitFieldFactory_H


#include <CATSYPFactoryResult.h>
#include <CATISYPValues.h>
#include <CATUnicodeString.h>
#include "CATDataType.h"


#define CATSYP_DECLARE_UINT32_BITFIELDFACTORY(I_EXPORTED_BY, I_CLASS, I_BITFIELD_NAME) \
  CATSYP_DECLARE_BITFIELDFACTORY(I_EXPORTED_BY, I_CLASS, I_BITFIELD_NAME, CATUINT32)

#define CATSYP_DECLARE_ULONG64_BITFIELDFACTORY(I_EXPORTED_BY, I_CLASS, I_BITFIELD_NAME) \
  CATSYP_DECLARE_BITFIELDFACTORY(I_EXPORTED_BY, I_CLASS, I_BITFIELD_NAME, CATULONG64)

#define CATSYP_DECLARE_BITFIELDFACTORY(I_EXPORTED_BY, I_CLASS, I_BITFIELD_NAME, TYPE) \
  extern "C" I_EXPORTED_BY \
  CATSYPFactoryResult CATSYP##I_CLASS##__##I_BITFIELD_NAME##Factory(const CATUnicodeString& i_string);\
  \
  extern "C" I_EXPORTED_BY \
  HRESULT CATSYP##I_CLASS##__##I_BITFIELD_NAME##Serializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);\
  \
  extern "C" I_EXPORTED_BY \
  const CATSYPDynArray<CATUnicodeString>& CATSYP##I_CLASS##__##I_BITFIELD_NAME##StringsList();

  
  
#endif
