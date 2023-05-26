#ifndef CATPLMID_Simple_H
#define CATPLMID_Simple_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
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

#include "CATPLMIdentificationAccessMacros.h"
#include "CATPLMID.h"
#include "CATPLMRepositoryName.h"
#include "CATPLMID_RepositoryLocation.h"
#include "CATOmxDeprecated.h"

#ifdef _CAT_ANSI_STREAMS
#include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS

class CATPLMID_Any;
class CATPLMID_RepositoryLocation;
class PlmIDSimple;
class CATPLMID_Compatibility;
class CATPLMTypeH;

/**
 * A CATPLMID_Simple is an identifier for a PLM component
 * It contains:
 *   3 uuids:
 *     - physicalid
 *     - majorid
 *     - logicalid
 *   a PLM type (see CATPLMType, CATPLMTypeH)
 *   but also
 *     a CATPLMRepositoryName
 *     a CATPLMID_RepositoryLocation
 */
class ExportedByCATPLMIdentificationAccess CATPLMID_Simple
{
public:
  /**
  * Constructor (Empty)
  */
  inline CATPLMID_Simple() :_ImplNative(nullptr) {}

  /**
  * Constructor By copy of value
  */
  inline CATPLMID_Simple(const CATPLMID_Simple& iCopy) : CATPLMID_Simple(iCopy._ImplNative) {}


  /**
  * definition by copy of value
  */
  CATPLMID_Simple& operator=(const CATPLMID_Simple &iCopy);

#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
  inline CATPLMID_Simple(CATPLMID_Simple&& iOther) :_ImplNative(iOther._ImplNative) { iOther._ImplNative = nullptr; }
  inline CATPLMID_Simple& operator=(CATPLMID_Simple&& iOther) { auto* tmp = _ImplNative; _ImplNative = iOther._ImplNative; iOther._ImplNative = tmp; return *this; }
#endif

  /**
  */
  inline explicit operator bool() const { return nullptr != _ImplNative; }
  inline bool IsNull() const { return nullptr == _ImplNative; }

  /**
  * Destructor
  */
  ~CATPLMID_Simple();

  /**
  * GetPhysicalId
  *
  * @param oIdentifier
  *    Logical identifier
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetPhysicalId(CATPLMID_Any & oIdentifier) const;
  CATPLMID_Any GetPhysicalId() const;

  /**
  * GetMajorId
  *
  * @param oIdentifier
  *    Major identifier
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetMajorId(CATPLMID_Any & oIdentifier) const;

  /**
  * GetLogicalId
  *
  * @param oIdentifier
  *    Logical identifier
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetLogicalId(CATPLMID_Any& oIdentifier) const;

  /**
  * Retrieve physicalid/majorid/logicalid as a string
  * see CATPLMID_Any::ToString for format
  */
  HRESULT GetPhysicalIdAsString(CATUnicodeString & oPhysicalId) const;
  HRESULT GetLogicalIdAsString(CATUnicodeString &oLogicalId) const;
  HRESULT GetMajorIdAsString(CATUnicodeString &oMajorId) const;


  /**
   * retrieve type
   */
  HRESULT GetType(CATPLMTypeId & oTypeReference) const;
  CATPLMTypeH GetType() const;

  /**
  * GetRepositoryName
  *
  * @param oRepositoryName
  *    Repository Name
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetRepositoryName(CATPLMRepositoryName & oRepositoryName) const;

  /**
  * GetRepositoryLocation
  *
  * @param oLocation
  *    Repository Location
  *
  * @return
  *      S_OK    if request succeeded <br>
  *      S_FALSE if request succeeded but without result<br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetRepositoryLocation(CATPLMID_RepositoryLocation & oLocation) const;

  /**
   * Comparison (return strcmp like value)
   */
  int Compare(const CATPLMID_Simple& i2) const;

  int operator==(const CATPLMID_Simple& i2) const;
  inline int operator!=(const CATPLMID_Simple& i2) const { return !this->operator==(i2); }

  /**
   * Hashing
   */
  unsigned int ComputeHashKey() const;

  /** see CATPLMID::ToString */
  CATUnicodeString ToString(unsigned int iFormat = 0) const;

  /**
  * S_OK:    this id comes from database
  * S_FALSE: this id has been generated in session
  * E_XXX:   this is is null
  */
  HRESULT IsValidForRemoteUsage() const;
  HRESULT IsValidForRemoteUsage(CATBoolean & oValidForRemoteUsage) const
  {
    HRESULT hr = IsValidForRemoteUsage();
    oValidForRemoteUsage = S_OK == hr;
    return hr;
  }

  /**
  * IsValidForSpaceRegistration
  *
  * @param oValidForSpaceRegistration
  *
  *      TRUE  : Proxy can be created and indexed with this PLMID.
  *      FALSE : Proxy cannot be created because PLMID is partially defined.
  *              Mandatory informations are : PhysId, LogId, MajId, RepName, TypeId
  *              Optional informations are : Location
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  HRESULT IsValidForSpaceRegistration(CATBoolean & oValidForSpaceRegistration) const;


  /** obsolete */
  OMX_DEPRECATED2("meaningless") HRESULT GetSiteOfProvider(CATPLMID_RepositoryLocation & oSiteOfRepository) const;
  /** obsolete */
  OMX_DEPRECATED2("meaningless") HRESULT IsFree(CATBoolean & oFree, CATPLMID & oHandle) const;

  inline PlmIDSimple* GetLetter() const { return _ImplNative; }
  explicit CATPLMID_Simple(const PlmIDSimple*);

  void SetLetter(const PlmIDSimple * iPlmIDSimple);

private:
  PlmIDSimple *_ImplNative;
};




#endif
