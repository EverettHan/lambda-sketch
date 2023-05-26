/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef CATAdpVersioningInfo_H
#define CATAdpVersioningInfo_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationAccess.h"

#include "CATOmxSharable.h"

#include "CATErrorDef.h"
#include "CATCollec.h"

#include "CATPLMID.h"

class CATIAdpPLMIdentificator;
class CATAdpMajorInformation;
class CATAdpMinorInformation;

class CATAdpVersioningInfo;
class CATLISTV (CATAdpVersioningInfo);

/**
 * Class giving access to a set of informations resulting from CATAdpVersioningServices::GetVersioningInfo method.
 */
class ExportedByCATPLMIntegrationAccess CATAdpVersioningInfo
{
public:

  CATAdpVersioningInfo ();
  ~CATAdpVersioningInfo ();
  CATAdpVersioningInfo (const CATAdpVersioningInfo &iVInfo);

/** 
 * Gets the source identificator.
 *
 * @param oSource [out, CATBaseUnknown#Release]
 *   The retrieved component identificator.
 *
 * @return
 *   <code>S_OK</code> The element is good and no report is associated.
 *   <code>E_FAIL</code> No specific element is associated to this CATAdpVersioningInfo object. 
 *
 */ 
  HRESULT GetElement(CATIAdpPLMIdentificator *& oSource);

/** 
 * Gets the major versioniong informations of the element.
 *
 * @param oMajorInfo
 *   The major information found on the source. 
 *
 * @return
 *   <code>S_OK</code> if there is a major information.
 *   <code>E_FAIL</code> if there is not a major information.
 *
 */ 
  HRESULT GetMajorVersioningInformation ( CATAdpMajorInformation &oMajorInfo );
      
/** 
 * Gets the minor versioniong informations of the element.
 *
 * @param oMinorInfo
 *   The minor information found on the source. 
 *
 * @return
 *   <code>S_OK</code> if there is a minor information.
 *   <code>E_FAIL</code> if there is not a minor information.
 *
 */ 
  HRESULT GetMinorVersioningInformation ( CATAdpMinorInformation &oMinorInfo );

/** 
 * Gets a list of versioning info on each major version of the element.
 *
 * @param oMajorVersionList [out,#Release]
 *   The list of retrieved major objects if requested.
 *   These element are based only on major information so :
 *     - There is no associated element GetElement will return E_FAIL on these objects.
 *     - You can get Major information and asociated minor elements on these object (if available)
 *     - You can't get minor information or associated major element : GetMinorVersioningInformation and GetAssociatedMajor on these object will return E_FAIL
 *   The list is ordered from oldest to newest inside major family based on majororder attribute.
 *
 */ 
  HRESULT GetAssociatedMajor ( CATLISTV (CATAdpVersioningInfo)& oMajorVersionList );

/** 
 * Gets an handle on minor elements family.
 *
 * @param oMinorVersionList [out]
 *   The list of retrieved minor objects if requested.
 *   These element are based on physical elements so :
 *     - There is one associated element
 *     - You can get Minor information on them
 *     - You can't get associated major/minor element : GetAssociatedMajor and GetAssociatedMinor on these objects will return E_FAIL
 *     - GetMajorVersioningInformation will return E_FAIL because it is useless : they share the same major information than the current element.
 *   The list is ordered from oldest to newest inside the minor family based on minororder attribute.
 *
 */ 
  HRESULT GetAssociatedMinor ( CATLISTV (CATAdpVersioningInfo)& oMinorVersionList );

  /** @nodoc */
  int operator !=(const CATAdpVersioningInfo& iVerInfo ) const;
  /** @nodoc */
	CATAdpVersioningInfo& operator=(const CATAdpVersioningInfo &iToken);
  /** @nodoc */
  void SetElement (const CATPLMID &iElement);
  HRESULT GetElement (CATPLMID &oElement);
  /** @nodoc */
  void SetMajorInfo (const CATAdpMajorInformation &iMajorInfo);
  /** @nodoc */
  void SetMinorInfo (const CATAdpMinorInformation &iMinorInfo);
  /** @nodoc */
  void AppendMajorElement (const CATAdpVersioningInfo &iMajorElem);
  /** @nodoc */
  void AppendMinorElement (const CATAdpVersioningInfo &iMinorElem);

private:
  friend class CATAdpProtectedVersioningServices;
  friend class CATPLMVersioningConvertion;

  void Clean();
  CATPLMID _Element;
  CATAdpMajorInformation *_MajorInfo;
  CATAdpMinorInformation *_MinorInfo;
  CATLISTV(CATAdpVersioningInfo) *_MajorList;
  CATLISTV(CATAdpVersioningInfo) *_MinorList;
};
#endif
