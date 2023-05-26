// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYP_Implement_Boxing.h
// Header definition of CATSYP_IMPLEMENT_BOXING
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: qf1
//===================================================================
#ifndef CATSYP_Implement_Boxing_H
#define CATSYP_Implement_Boxing_H

#include <CATSYPBoxingComparator.h>
#include <CATSYPHashMap.h>
#include <CATSysMacros.h>
#include <CATSYPCheck.h>
  
#define CATSYP_IMPLEMENT_BOXING_WITH_COMPARATOR( I_TYPE , comparatorClass)         \
  CATImplementClass( CATBoxingOf##I_TYPE, Implementation, CATISYPValues, CATNull ); \
  CATImplementBOA(CATISYPValues, CATBoxingOf##I_TYPE);                    \
                                                                        \
  CREATE_INSTANCE_COUNTER(CATBoxingOf##I_TYPE);                           \
                                                                        \
  CATBoxingOf##I_TYPE::CATBoxingOf##I_TYPE( const I_TYPE &iValue )            \
  : _value( iValue )                                                    \
  {                                                                     \
    INC_INSTANCE_COUNTER(CATBoxingOf##I_TYPE);                            \
  }                                                                     \
                                                                        \
  CATBoxingOf##I_TYPE::~CATBoxingOf##I_TYPE()                               \
  {                                                                     \
    DEC_INSTANCE_COUNTER(CATBoxingOf##I_TYPE);                            \
  }                                                                     \
                                                                        \
  int CATBoxingOf##I_TYPE::Equals(const CATBaseUnknown_var& i_spCBU)      \
  {                                                                     \
    const CATBoxingOf##I_TYPE *pOther = CAT_DYNAMIC_CAST(CATBoxingOf##I_TYPE, i_spCBU); \
    if (pOther == NULL)                                                 \
      return 0;                                                         \
    comparatorClass<I_TYPE> comparator;                           \
    return comparator.AreEqual(pOther->_value, this->_value);           \
  }                                                                     \
                                                                        \
  CATBaseUnknown_var CATBoxingOf##I_TYPE::Box(const I_TYPE &iValue)         \
  {                                                                     \
    CATBaseUnknown *obj= new CATBoxingOf##I_TYPE( iValue );               \
    CATBaseUnknown_var rc( obj );                                       \
    obj->Release();                                                     \
    return rc;                                                          \
  };                                                                    \
                                                                        \
  HRESULT CATBoxingOf##I_TYPE::Unbox(const CATBaseUnknown_var &i_spReference, \
                                   I_TYPE &oValue)                        \
  {                                                                     \
    const CATBoxingOf##I_TYPE *pBox = CAT_DYNAMIC_CAST(CATBoxingOf##I_TYPE, i_spReference); \
    if( pBox ) {                                                        \
      oValue= pBox->_value;                                             \
      return S_OK;                                                      \
    } else                                                              \
      return E_FAIL;                                                    \
  };                                                                    \
                                                                        \
  CATISYPValues * CATSYP##I_TYPE##BinaryUnstreamer(CATSYPCodedInputStream &i_inputStream) \
  {                                                                     \
    CATBoxingOf##I_TYPE *ret = CATBoxingOf##I_TYPE::BinaryUnstream(i_inputStream); \
    return ret;                                                         \
  }

#define CATSYP_IMPLEMENT_BOXING_WITH_ALIAS_WITH_COMPARATOR(I_TYPEALIAS, I_TYPE, comparatorClass)                    \
  CATImplementClass(CATBoxingOf##I_TYPEALIAS, Implementation, CATISYPValues, CATNull);           \
  CATImplementBOA(CATISYPValues, CATBoxingOf##I_TYPEALIAS);                                      \
                                                                                            \
  CREATE_INSTANCE_COUNTER(CATBoxingOf##I_TYPEALIAS);                                             \
                                                                                            \
  CATBoxingOf##I_TYPEALIAS::CATBoxingOf##I_TYPEALIAS(const I_TYPE &iValue)                            \
      : _value(iValue)                                                                      \
  {                                                                                         \
    INC_INSTANCE_COUNTER(CATBoxingOf##I_TYPEALIAS);                                              \
  }                                                                                         \
                                                                                            \
  CATBoxingOf##I_TYPEALIAS::~CATBoxingOf##I_TYPEALIAS()                                               \
  {                                                                                         \
    DEC_INSTANCE_COUNTER(CATBoxingOf##I_TYPEALIAS);                                              \
  }                                                                                         \
                                                                                            \
  int CATBoxingOf##I_TYPEALIAS::Equals(const CATBaseUnknown_var &i_spCBU)                        \
  {                                                                                         \
    const CATBoxingOf##I_TYPEALIAS *pOther = CAT_DYNAMIC_CAST(CATBoxingOf##I_TYPEALIAS, i_spCBU);     \
    if (pOther == NULL)                                                                     \
      return 0;                                                                             \
    comparatorClass<I_TYPE> comparator;                                                     \
    return comparator.AreEqual(pOther->_value, this->_value);                               \
  }                                                                                         \
                                                                                            \
  CATBaseUnknown_var CATBoxingOf##I_TYPEALIAS::Box(const I_TYPE &iValue)                         \
  {                                                                                         \
    CATBaseUnknown *obj = new CATBoxingOf##I_TYPEALIAS(iValue);                                  \
    CATBaseUnknown_var rc(obj);                                                             \
    obj->Release();                                                                         \
    return rc;                                                                              \
  };                                                                                        \
                                                                                            \
  HRESULT CATBoxingOf##I_TYPEALIAS::Unbox(const CATBaseUnknown_var &i_spReference,               \
                                     I_TYPE &oValue)                                        \
  {                                                                                         \
    const CATBoxingOf##I_TYPEALIAS *pBox = CAT_DYNAMIC_CAST(CATBoxingOf##I_TYPEALIAS, i_spReference); \
    if (pBox)                                                                               \
    {                                                                                       \
      oValue = pBox->_value;                                                                \
      return S_OK;                                                                          \
    }                                                                                       \
    else                                                                                    \
      return E_FAIL;                                                                        \
  };                                                                                        \
                                                                                            \
  CATISYPValues *CATSYP##I_TYPEALIAS##BinaryUnstreamer(CATSYPCodedInputStream &i_inputStream)    \
  {                                                                                         \
    CATBoxingOf##I_TYPEALIAS *ret = CATBoxingOf##I_TYPEALIAS::BinaryUnstream(i_inputStream);          \
    return ret;                                                                             \
  }

#define CATSYP_IMPLEMENT_BOXING( I_TYPE)\
  CATSYP_IMPLEMENT_BOXING_WITH_COMPARATOR( I_TYPE , CATSYPHashMapComparator)

#define CATSYP_IMPLEMENT_BOXING_WITH_ALIAS( I_TYPEALIAS, I_TYPE)\
  CATSYP_IMPLEMENT_BOXING_WITH_ALIAS_WITH_COMPARATOR( I_TYPEALIAS, I_TYPE , CATSYPHashMapComparator)
  
#endif
