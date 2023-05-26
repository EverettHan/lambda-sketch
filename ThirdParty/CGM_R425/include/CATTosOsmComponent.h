/* -*-c++-*- */
#ifndef CATTosOsmComponent_H
#define CATTosOsmComponent_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATPLMRepositoryName.h"
#include "CATComponentId.h"
#include "CATIPLMLogState.h"
#include "CATPLMID.h"
#include "CATCollec.h"

class CATPLMCEStamp;
class CATPLMRepositoryPrivilege;
class CATLISTP( CATLogicalAlternativesByOwner );
class CATFamilyByOwnerTable;
class CATPLMCopyEngine;
class CATPLMDuplicationEngine;
class CATPLMEngineOldErrMgtToolbox;
class CATPLMNewVersionEngine;
class CATAdpErrorCell;

class  ExportedByCATPLMTos CATTosOsmComponent 
{
public:
		                           
  /** 
  * DirtifySpecAttributePLMVisible
	*   For OSM infrastruture 
  *
  * @param iCATIOmbComponentObject
  *    master/slave representant in client session of a database object.
	*    Object should adhere to CATIComponent or CATIOmbComponentObject 
  *
  *  @param iAttributeNameModified
  *     CV5 Attribute Applicative Name  
  *
  * @return
  *      S_OK if request succeeded and Object is identified as a Valid <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT  DirtifySpecAttributePLMVisible(CATBaseUnknown           * iCATIOmbComponentObject,
		                                             const CATUnicodeString   & iAttributeNameModified);

  /** 
  * Gets a component in TOS given its PLMID
  * <br><b>Role:</b> Searches and gets a component in the Table of Objects in Session 
  * <br> given its PLMID.
  *
  * @param iPLMID
  *   Associated identification 
  *
  * @param oObject
  *   The memory address of implementation Component.
  *   Release() after usage the returned value of oPPV, if it has succeeded.
  *
  * @param iSessionDataSpace
  *   DataSpace (To be specified if not the default CATIA 3D)
  *
  * @return
  *      S_OK     if request succeeded with Result <br>
  *      S_FALSE  if request succeeded without Result <br>
  *      E_FAIL   if request failed <br>
  */
  static HRESULT IsUsed(const CATPLMID    & iPLMID,
                        CATBaseUnknown  * & oObject,
                        const CATProxySpace & iInfraSpace = CATProxySpace_Null ) ;

  /** 
  *  Checking if one Object is already engaged with DataBase System Association
  *
  * @param iObject
  *   The memory address of implementation Component.
  *
  * @return
  *      S_OK     if request succeeded with Result <br>
  *      S_FALSE  if request succeeded without Result <br>
  *      E_FAIL   if request failed <br>
  */
  static CATBoolean IsExposedForLink(CATBaseUnknown          * iObject) ;
 
  /** 
  * GetLogStatus
  *
  * @param iCID
  *    iCID
  *
  *  @param oStatus
  *      Associated Log status
  *
  * @return
  *      S_OK if request succeeded and Object is identified as a Valid <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT  GetLogStatus(const CATComponentId   & iCID ,
                               CATPLMLogStatus        & oStatus);

  /** 
  * SetCEStamp
  *
  * @param iCES
  *    Associated CE Stamp
  *
  * @param iCID
  *    iCID
  *
  * @param iKeepValueOnAlreadyInserted
  *    iCID
  *
  * @return
  *      S_OK    if request succeeded with CEStamp found <br>
  *      S_FALSE if request succeeded BUT Without CEStamp associativity<br>
  *      E_FAIL  if request failed <br>
  */
  static HRESULT  SetCEStamp(const CATPLMCEStamp    & iCES,
                             const CATComponentId   & iCID ,
                             const CATBoolean         iKeepValueOnAlreadyInserted = FALSE);

  /** 
  * GetCEStamp
  *
  * @param iCID
  *    iCID
  *
  * @return
  *     CATPLMCEStamp Value
  */
  static CATPLMCEStamp GetCEStamp(const CATComponentId   & iCID );


  /** 
  * SetRepositoryPrivilege
  *
  * @param iCES
  *    Associated CE Stamp
  *
  * @param iCID
  *    iCID
  *
  * @return
  *      S_OK    if request succeeded with RepositoryPrivilege found <br>
  *      S_FALSE if request succeeded BUT Without RepositoryPrivilege associativity<br>
  *      E_FAIL  if request failed <br>
  */
  static HRESULT  SetRepositoryPrivilege(const CATPLMRepositoryPrivilege    & iCES,
                             const CATComponentId   & iCID);

  /** 
  * GetRepositoryPrivilege
  *
  * @param iCID
  *    iCID
  *
  * @return
  *     CATPLMRepositoryPrivilege Value
  */
  static CATPLMRepositoryPrivilege GetRepositoryPrivilege(const CATComponentId   & iCID );


  
  /** 
  * FindLogicalEquivalenceByOwner
  *		Returns a set {owner, map{old component, new component list}}.
  *
  *		Given a set of input relations, this methods looks for logical equivalent of each target in the session.
  *		The solutions are ordered by PLM owner.
  *
  * @param inputRelations
  *    Logical Equivalence
  *
  * @param opFamilyTable
  *    Result of Logical Equivalence Search
  *
  * @param iFilter
  *    Criteria of in session memory
  *
  * @return
  *      S_OK    if request succeeded with CEStamp found <br>
  *      S_FALSE if request succeeded BUT Without CEStamp associativity<br>
  */
  static HRESULT FindLogicalEquivalenceByOwner(  const CATLISTV( CATComponentId )&					inputRelations,
	  CATFamilyByOwnerTable*&							opFamilyTable,
	  const CATTosQuery_Filter&							iFilter = CatTosQuery_OnlyWithValidPersistencyIntents,
	  const CATProxySpace & iInfraSpace = CATProxySpace_Null );


  private:

    friend class CATPLMCopyEngine;
    friend class CATPLMDuplicationEngine;
    friend class CATPLMEngineOldErrMgtToolbox;
    friend class CATPLMNewVersionEngine;
    friend class CATAdpErrorCell;
    friend class CATPCCTOSLOGServices;

    // Deprecated because unsafe
    static HRESULT Destroy(CATBaseUnknown  * iObject) ;

};




#endif
