#ifndef __CATOmxKeyValue_h__
#define __CATOmxKeyValue_h__

#include "CATOmxSharable.h"
#include "CATOmxKeyString.h"
#include "CATOmxAny.h"
#include "CATOmxPortability.h"
#ifdef CATIAR418
#define CATOMX_PROTECT_VALUE const
#else
#define CATOMX_PROTECT_VALUE
#endif
struct CATOmxKeyValue 
{
  CATOMX_PROTECT_VALUE CATOmxKeyString m_key;
  CATOMX_PROTECT_VALUE CATOmxAny m_value;
  CATOMX_PROTECT_VALUE unsigned int m_mask;

  inline CATOmxKeyValue() : m_mask(0) {}
  inline CATOmxKeyValue(const CATOmxKeyString &iKey) : m_key(iKey), m_mask(0) {}
  inline CATOmxKeyValue(const CATOmxKeyString &iKey,const CATOmxAny& iValue,unsigned int iMask = 0) : m_key(iKey), m_value(iValue), m_mask(iMask) {}
  inline CATOmxKeyValue(const CATOmxKeyValue &iValue) : m_key(iValue.m_key), m_mask(iValue.m_mask), m_value(iValue.m_value) {}
  inline CATOmxKeyValue& operator=(const CATOmxKeyValue &iValue) 
  { 
    const_cast<CATOmxKeyString&>(m_key) =iValue.m_key; 
    setMask(iValue.m_mask); 
    setValue(iValue.m_value);
    return *this;
  }

  inline void setMask(unsigned int iMask) { const_cast<unsigned int&>(m_mask) = iMask;}
  inline void setValue(const CATOmxAny &iValue) { const_cast<CATOmxAny&>(m_value) = iValue;}

  inline bool operator==(const CATOmxKeyValue& other) const {return m_key == other.m_key && m_value == other.m_value && m_mask == other.m_mask;}
  inline bool operator!=(const CATOmxKeyValue& other) const {return !this->operator==(other);}
};

#endif
