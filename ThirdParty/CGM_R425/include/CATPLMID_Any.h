#ifndef CATPLMID_Any_H
#define CATPLMID_Any_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
* @level Private
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "IUnknown.h"
#include "CATUuid.h"
#include "CATDbBinary.h"
#include "CATUnicodeString.h"
#include "CATPLMIdentificationAccessMacros.h"
#include "CATOmxDeprecated.h"

/** obsolete */
enum CATPLMID_AnyFormat
{
  CatPLMID_Any_CATUuid = 1, //the unique possible value
  CatPLMID_Any_Binary = 3, //obsolete
  CatPLMID_Any_Unicode = 4, //obsolete
  CatPLMID_Any_Undefined = 5
};


/** NoDoc */
class CATPLMID_Any;

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi tcx 2005-08-02.20:09:19 [Replace forward declaration of standard streams with osfwd.h] **/
#include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS


/** prefer CATPLMID_Any() */
extern const ExportedByCATPLMIdentificationAccess CATPLMID_Any CATPLMID_Any_Null;


/**
 * this class is an uuid
 */
class ExportedByCATPLMIdentificationAccess CATPLMID_Any
{
public:

  /**
  * Empty Constructor
  * */
  inline CATPLMID_Any() { m_u64[0] = m_u64[1] = 0; }

  /**
  * Destructor
  */
  inline ~CATPLMID_Any() {}

  /**
  * Returns FALSE if not valuated
  */
  inline explicit operator bool() const { return !IsNull(); }
  inline int IsNull() const { return m_u64[0] == 0 && m_u64[1] == 0; }

  /**
  * Constructor by Copy of Identifier
  */
  inline CATPLMID_Any(const CATPLMID_Any& iFrom)
  {
    m_u64[0] = iFrom.m_u64[0];
    m_u64[1] = iFrom.m_u64[1];
  }

  /**
  * Assigning  by copy of Identifier
  */
  inline CATPLMID_Any& operator=(const CATPLMID_Any& iFrom)
  {
    m_u64[0] = iFrom.m_u64[0];
    m_u64[1] = iFrom.m_u64[1];
    return *this;
  }

  /** Build from CATUuid */
  inline CATPLMID_Any(const CATUuid & iUuid) { iUuid.get(m_u8); }
  CATPLMID_Any& operator=(const CATUuid& iUuid) { iUuid.get(m_u8); return *this; }

  /** Convert to CATUuid*/
  HRESULT GetCATUuid(CATUuid & oUuid) const;
  operator CATUuid() const;

  /**
  * Check equality between two a Object Integration Types
  */
  inline int operator == (const CATPLMID_Any & iCopy) const { return m_u64[0] == iCopy.m_u64[0] && m_u64[1] == iCopy.m_u64[1]; }
  inline int operator != (const CATPLMID_Any & iCopy) const { return !this->operator==(iCopy); }

  /** obsolete (use ==) */
  inline HRESULT IsEqual(const CATPLMID_Any & iIdentifier, CATBoolean & oEqual) const
  {
    oEqual = (this->operator==(iIdentifier)) != 0;
    return S_OK;
  }

  /**
  * Comparison of identifier, total order.
  *
  * @return
  *      -1 if physical id is is inferior to iOther's one<br>
  *       1 if physical id is is superior to iOther's one<br>
  *       0 if physical id is equal to iOther's one<br>
  */
  int Compare(const CATPLMID_Any & iOther) const;

  /** obsolete */
  OMX_DEPRECATED("Useless") HRESULT GetFormat(CATPLMID_AnyFormat & oType) const;

  /** Assigns CATPLMID_Any()  */
  HRESULT Reset() { *this = CATPLMID_Any(); return S_OK; }


  /** Generates a new uuid */
  inline HRESULT SetCATUuid() { return SetCATUuid(CATUuid()); }

  /** Assign a uuid */
  inline HRESULT SetCATUuid(const CATUuid & iUuid) { *this = iUuid; return S_OK; }

  /** Computes hash key */
  unsigned int ComputeHashKey() const;
  inline CATUINTPTR Differentiate() const { return ComputeHashKey(); }

  /**
   * return hexadecimal representation of the uuid( so 32 characters)
   */
  CATUnicodeString ToString() const;

  /**
    * Build uuid from input string which must have the format returned by ToString()
    */
  HRESULT FromString(const CATUnicodeString& iHex);

  /** Prefer CATUuid versions*/
  CATPLMID_Any(const unsigned char iIdentifier[16]);
  HRESULT GetCATUuid(unsigned char oIdentifier[16]) const;
  HRESULT SetCATUuid(const unsigned char iIdentifier[16]);

  /** do not use CATDbBinary*/
  OMX_DEPRECATED("Use CATUuid") HRESULT SetCATUuid(const CATDbBinary & iUuid);
  OMX_DEPRECATED("Use CATUuid") HRESULT GetCATUuid(CATDbBinary & oUuid) const;

  /** obsolete */
  OMX_DEPRECATED("not implemented") inline HRESULT SetUnicode(const CATUnicodeString & iUnicode) { return E_NOTIMPL; }
  OMX_DEPRECATED("not implemented") inline HRESULT GetUnicode(CATUnicodeString       & oUnicode) const { return E_NOTIMPL; }
  OMX_DEPRECATED("not implemented") inline HRESULT BinaryLength(size_t & oLength) const { return E_NOTIMPL; }
  OMX_DEPRECATED("not implemented") inline const BYTE& operator [] (const size_t iLength) const { return *(BYTE*)NULL; }

  /** piece of crap */
  OMX_DEPRECATED("obsolete") HRESULT DevelopmentStage(CATUnicodeString & oUnicode) const;
  OMX_DEPRECATED("obsolete") HRESULT DevelopmentStage(ostream &ToDump, const int iDecalage) const;
  OMX_DEPRECATED("obsolete") const char * hrefTag(const short ihref) const;

private:
  union
  {
    unsigned char   m_u8[16];
    CATUINT32       m_u32[4];
    CATULONG64      m_u64[2];
  };
};


#endif
