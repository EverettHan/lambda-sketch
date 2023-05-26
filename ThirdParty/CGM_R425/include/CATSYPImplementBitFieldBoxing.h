// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATSYPImplementBitFieldBoxing.h
// Header definition of CATSYP_IMPLEMENT_BITFIELDBOXING
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2012  Creation: qf1
//===================================================================
#ifndef CATSYP_Implement_BitFieldBoxing_H
#define CATSYP_Implement_BitFieldBoxing_H

#include <CATSYPBoxingComparator.h>
#include <CATSYPHashMap.h>
#include <CATSysMacros.h>


#define CATSYP_IMPLEMENT_UINT32_BITFIELDBOXING(I_CLASS, I_BITFIELD)\
  CATSYP_IMPLEMENT_BITFIELDBOXING(I_CLASS, I_BITFIELD, CATUINT32)

#define CATSYP_IMPLEMENT_ULONG64_BITFIELDBOXING(I_CLASS, I_BITFIELD)\
  CATSYP_IMPLEMENT_BITFIELDBOXING(I_CLASS, I_BITFIELD, CATULONG64)
  
#define CATSYP_IMPLEMENT_BITFIELDBOXING( I_CLASS, I_BITFIELD, TYPE)         \
  CATImplementClass( CATBoxingOf##I_CLASS##__##I_BITFIELD, Implementation, CATISYPValues, CATNull ); \
  CATImplementBOA(CATISYPValues, CATBoxingOf##I_CLASS##__##I_BITFIELD);                    \
                                                                        \
  CREATE_INSTANCE_COUNTER(CATBoxingOf##I_CLASS##__##I_BITFIELD);                           \
                                                                        \
  CATBoxingOf##I_CLASS##__##I_BITFIELD::CATBoxingOf##I_CLASS##__##I_BITFIELD( const I_CLASS::I_BITFIELD &iValue )            \
  : _value( iValue )                                                    \
  {                                                                     \
    INC_INSTANCE_COUNTER(CATBoxingOf##I_CLASS##__##I_BITFIELD);                            \
  }                                                                     \
                                                                        \
  CATBoxingOf##I_CLASS##__##I_BITFIELD::~CATBoxingOf##I_CLASS##__##I_BITFIELD()                               \
  {                                                                     \
    DEC_INSTANCE_COUNTER(CATBoxingOf##I_CLASS##__##I_BITFIELD);                            \
  }                                                                     \
                                                                        \
  int CATBoxingOf##I_CLASS##__##I_BITFIELD::Equals(const CATBaseUnknown_var& i_spCBU)      \
  {                                                                     \
    if (i_spCBU == NULL_var)                                            \
      return 0;                                                         \
    const CATBoxingOf##I_CLASS##__##I_BITFIELD *pOther = CAT_DYNAMIC_CAST(CATBoxingOf##I_CLASS##__##I_BITFIELD, i_spCBU->GetImpl()); \
    if (pOther == NULL)                                                 \
      return 0;                                                         \
    CATSYPHashMapComparator<I_CLASS::I_BITFIELD> comparator;                           \
    return comparator.AreEqual(pOther->_value, this->_value);           \
  }                                                                     \
                                                                        \
  CATBaseUnknown_var CATBoxingOf##I_CLASS##__##I_BITFIELD::Box(const I_CLASS::I_BITFIELD &iValue)         \
  {                                                                     \
    CATBaseUnknown *obj= new CATBoxingOf##I_CLASS##__##I_BITFIELD( iValue );               \
    CATBaseUnknown_var rc( obj );                                       \
    obj->Release();                                                     \
    return rc;                                                          \
  }                                                                   \
                                                                        \
  HRESULT CATBoxingOf##I_CLASS##__##I_BITFIELD::Unbox(const CATBaseUnknown_var &i_spReference, \
                                   I_CLASS::I_BITFIELD &oValue)                        \
  {                                                                     \
    if (i_spReference == NULL_var)                                      \
      return E_FAIL;                                                    \
    const CATBoxingOf##I_CLASS##__##I_BITFIELD *pBox = CAT_DYNAMIC_CAST(CATBoxingOf##I_CLASS##__##I_BITFIELD, i_spReference->GetImpl()); \
    if( pBox ) {                                                        \
      oValue= pBox->_value;                                             \
      return S_OK;                                                      \
    } else                                                              \
      return E_FAIL;                                                    \
  }                                                                     \
                                                                        \
  CATBoxingOf##I_CLASS##__##I_BITFIELD * CATBoxingOf##I_CLASS##__##I_BITFIELD::BinaryUnstream(CATSYPCodedInputStream &i_inputStream) \
  {                                                                     \
    return NULL;                                                        \
  }                                                                     \
                                                                        \
  int CATBoxingOf##I_CLASS##__##I_BITFIELD::BinaryStream(CATSYPCodedOutputStream &i_outputStream)            \
  {                                                                     \
    return 0;                                                           \
  }                                                                     \
                                                                        \
  CATISYPValues * CATSYP##I_CLASS##__##I_BITFIELD##BinaryUnstreamer(CATSYPCodedInputStream &i_inputStream) \
  {                                                                     \
    CATBoxingOf##I_CLASS##__##I_BITFIELD *ret = CATBoxingOf##I_CLASS##__##I_BITFIELD::BinaryUnstream(i_inputStream); \
    return ret;                                                         \
  }                                                                     \
                                                                        \
  CATBaseUnknown_var CreateBoxingOf##I_CLASS##__##I_BITFIELD(const TYPE& iValue)\
  {                                                                     \
    return CATBoxingOf##I_CLASS##__##I_BITFIELD::Box(I_CLASS::I_BITFIELD(iValue));   \
  }


#endif
