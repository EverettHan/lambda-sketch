// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPImplementBitFieldFactory.h
// Header definition of CATSYPImplementBitFieldFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: qf1
//===================================================================
#ifndef CATSYPImplementBitFieldFactory_H
#define CATSYPImplementBitFieldFactory_H


#include <CATBasicBoxing.h>
#include <CATListOfCATUnicodeString.h>
#include <CATSysTSVectorOfUnicodeString.h>
#include <CATSysTSUnicodeString.h>

#define CATSYP_IMPLEMENT_UINT32_BITFIELDFACTORY(I_CLASS, I_BITFIELD_NAME) \
  CATSYP_IMPLEMENT_BITFIELDFACTORY(I_CLASS, I_BITFIELD_NAME, CATUINT32)

#define CATSYP_IMPLEMENT_ULONG64_BITFIELDFACTORY(I_CLASS, I_BITFIELD_NAME) \
  CATSYP_IMPLEMENT_BITFIELDFACTORY(I_CLASS, I_BITFIELD_NAME, CATULONG64)

#define CATSYP_IMPLEMENT_BITFIELDFACTORY(I_CLASS, I_BITFIELD_NAME, TYPE) \
  CATSYPFactoryResult CATSYP##I_CLASS##__##I_BITFIELD_NAME##Factory(const CATUnicodeString& i_string)\
  {\
    TYPE resValue;\
    HRESULT hr = I_CLASS::I_BITFIELD_NAME::GetValueFromString(i_string, resValue);\
    if(FAILED(hr))\
    {\
      return CATSYPFactoryResult(0, CATSYPFactoryResult::InvalidBitFieldValue);\
    }\
    return CATSYPFactoryResult(CATBoxingOf##I_CLASS##__##I_BITFIELD_NAME::Box(I_CLASS::I_BITFIELD_NAME(resValue)));\
  }\
  \
  HRESULT CATSYP##I_CLASS##__##I_BITFIELD_NAME##Serializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string)\
  {\
    I_CLASS::I_BITFIELD_NAME bitfield;\
    o_string = "";\
    HRESULT hr = CATBoxingOf##I_CLASS##__##I_BITFIELD_NAME::Unbox(i_spCBU, bitfield);\
    if(hr == E_FAIL)\
      return E_FAIL;\
    o_string = bitfield.GetString();\
    return S_OK;\
  }\
  \
  const CATSYPDynArray<CATUnicodeString>& CATSYP##I_CLASS##__##I_BITFIELD_NAME##StringsList()\
  {\
    return I_CLASS::I_BITFIELD_NAME::GetStringsList();\
  }


#endif
