/* -*-c++-*- */
#ifndef CATPLMID_RepositoryLocation_H
#define CATPLMID_RepositoryLocation_H

/**
* @level Private
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"

#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATDbBinary.h"
#include "CATDataType.h"

#include "CATPLMID.h"
#include "CATPLMRepositoryName.h"
#include "CATPLMIdentificationAccessMacros.h"

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi tcx 2005-08-02.20:09:19 [Replace forward declaration of standard streams with osfwd.h] **/
#include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS

class CATPLMID_Any;
class CATPLMID_RepositoryLocation;
class CATPLMTosPendingProviderImpl;
class SharedRepo;


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//    L O C A T I O N       M A N A G E M E N T
//
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
* Formats of Locations
*  More explicit is very welcome
*/
enum CATPLMID_RepositoryFormat
{
  CatPLMID_Repository_Binary,
  CatPLMID_Repository_Unicode,
  CatPLMID_Repository_Undefined
};



/**
 *  PLM Repository Location
 */
class ExportedByCATPLMIdentificationAccess CATPLMID_RepositoryLocation
{
public:
  /**
   * Returns dummy CATPLMID_RepositoryLocation ( CATPLMID_RepositoryLocation(1,"\1") )
   * which is duplicated everywhere.
   */
  static const CATPLMID_RepositoryLocation& Dummy();

  /**
  * Empty Constructor
  * */
  inline CATPLMID_RepositoryLocation() :_Shared(NULL) {}

  /**
  * Constructor by Copy of Location
  */
  inline CATPLMID_RepositoryLocation(const CATPLMID_RepositoryLocation& from) { _Shared = from._Shared; }

  /**
  * Assigning  by copy of Location
  */
  inline CATPLMID_RepositoryLocation& operator= (const CATPLMID_RepositoryLocation& from) { _Shared = from._Shared; return *this; }

  /**
  * DO NOT USE, USE ==/!=, RETURN CODE HAS NO MEANING (CAN BE AN HRESULT OR A BOOLEAN)
  */
  OMX_DEPRECATED2("use operator==") HRESULT IsEqual(const CATPLMID_RepositoryLocation & iOther, CATBoolean & oEqual) const;

  /**
  * Returns FALSE if not valuated
  */
  inline explicit operator bool() const { return !IsNull(); }
  inline int IsNull() const { return _Shared == nullptr; }

  /**
  * Equality operators
  */
  inline int operator == (const CATPLMID_RepositoryLocation & iToCompare) const { return _Shared == iToCompare._Shared; }
  inline int operator != (const CATPLMID_RepositoryLocation & iToCompare) const { return _Shared != iToCompare._Shared; }


  /**
  * Get Format of identifier
  *
  * @param oType
  *    Binary
  *    Unicode
  *    Undefined
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT GetFormat(CATPLMID_RepositoryFormat & oType) const;


  /**
  * Constructor by input binary length and value
  *
  * @param iLength
  *   length of binary Data
  *
  * @param iData
  *   Value of binary Data
  */
  CATPLMID_RepositoryLocation(const size_t iLength, const BYTE * iData);

  /**
  * Constructor Binary Location value in CATDbBinary format
  *
  * @param iLocation
  *   Format CATDbBinary of System generator
  */
  CATPLMID_RepositoryLocation(const CATDbBinary & iLocation);

  /**
  * Get Binary Location length
  *
  * @param oLength
  *   Location length
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT BinaryLength(size_t & oLength) const;

  /**
  * Get Binary Value by value
  *
  * @param iLength
  *   Location
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  const BYTE& operator [] (const size_t iLength) const;

  /**
  * Get Binary content
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT GetBinary(CATDbBinary & oLocation) const;
  HRESULT GetBinary(CATBinary & oLocation) const;

  /** @nodoc */
  HRESULT SetUnicode(const CATUnicodeString & iUnicode);


  /** @nodoc */
  HRESULT GetUnicode(CATUnicodeString& oUnicode) const;



  /**
  * Reset value of identifier
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT Reset();

  /** NoDoc */
  HRESULT DevelopmentStage(ostream &ToDump, const int iDecalage) const;


  /** @nodoc */
  CATULONGPTR GetIndex() const;


  /** @nodoc  */
  HRESULT  DevelopmentStage(CATUnicodeString & oUnicodeToDump) const;

  /** @nodoc */
  const char * hrefTag(const short ihref) const;

private:
  SharedRepo* _Shared;
};




#endif
