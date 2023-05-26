#ifndef CATPLMIdentifier_H
#define CATPLMIdentifier_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004

/**
* @level Private
* @usage U1       
*/
#include "CATPLMIdentificationAccess.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATString.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"

class CATPLMIdentifier;
class CATOxSingleton;
class CATComponentId;
class CATPLMID;
class PlmIDSimpleSnapshot;
class CATIAdpPLMIdentificator;
class PlmID;



/** Duplicate of CATPLMID */
class ExportedByCATPLMIdentificationAccess CATPLMIdentifier: public CATPLMID
{
public :

  /**
  * Check if Identifier  is unset or valuated.
  *
  * @return
  *      TRUE    if unset<br>
  *      FALSE   if valuated<br>
  */
  CATBoolean operator !  () const; 


  /**
  * Check equality (by physical identifier) between two Identifiers
  *
  * @param iToCompare
  *      Type of CATPLMIdentifier to Compare<br> 
  *
  * @return
  *      TRUE    if having same physical Id<br>
  *      FALSE   if not<br>
  */
  CATBoolean operator == (const CATPLMIdentifier & iToCompare) const;

  /**
  * Check inequality  (by physical identifier) between two Identifiers
  *
  * @param iToCompare
  *      Type of CATPLMIdentifier to Compare<br> 
  *
  * @return
  *      TRUE    if having same physical Id<br>
  *      FALSE   if not<br>
  */
  CATBoolean operator != (const CATPLMIdentifier & iToCompare) const;


  /*
  *	Construct unset Identifier 
  */
  CATPLMIdentifier();

  /*
  *	Destructor
  */
  ~CATPLMIdentifier();

  /**
  *	Constructor by Copy
  *
  * @param iCopyFrom
  *   Identifier
  *
  */
  CATPLMIdentifier(const CATPLMIdentifier& iCopyFrom);

  /**
  * Assign by Identifier
  *
  * @param iCopyFrom
  *   Identifier
  *
  */
  CATPLMIdentifier& operator = (const CATPLMIdentifier& iCopyFrom);


  /**
  * Import From PLMID, it succeeded only in following cases 
  *    1) it has been given from Query/Expand/Open
  *    2) it has been saved, comitted in repository and validated back in client side
  *
  * @param iCopyFrom
  *   Identifier
  *
  * @return
  *      S_OK    if success <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT ImportFromPLMID(const CATPLMID & iCopyFrom);

  /**
  * Export to PLMID, it succeeds only if the migration to PlmId is activated
  *
  * @param oPLMID
  *   Identifier
  *
  * @return
  *      S_OK    if success <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT ExportToPLMID(CATPLMID & oPLMID) const;

  /**
  * GetPhysicalClass
  *
  * @param oKey
  *   Result of dump
  *
  * @return
  *      S_OK    if success <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT GetPhysicalClass(unsigned int &oKey) const;

  /**
  * DumpForDebug  
  *
  * @param oDumpOutput
  *
  * @param iRFU
  *
  * @return
  *      S_OK    if success <br>
  *      E_FAIL  if request failed <br>
  */
  HRESULT DumpForDebug(CATString & oDumpOutput, const short iRFU=0) const;

  /** 
  * Gets a @href CATPLMIdentifier from a @href CATIAdpPLMIdentificator.
  *
  * <br><b>Role</b>: Restricted access service enabling to retrieve the complete identification set from a 
  * @href CATIAdpPLMIdentificator.
  *
  * @param iAdpId [in]
  *   The PLM identificator.
  * @param oPLMID [out]
  *   The retrieved PLMID.
  *
  * @return
  *   <code>S_OK</code> if the PLMID was successfully retrieved.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetPLMIdentifierFromAdpIdentificator( CATIAdpPLMIdentificator * iAdpId, CATPLMIdentifier & oIdentifier );

  /** 
  * Gets the CATIAdpPLMIdentificator from a CATPLMIdentifier.
  *
  * <br><b>Role</b>: From a@href CATPLMIdentifier, retrieves the related @href CATIAdpPLMIdentificator.
  *
  * @param iPLMID [in]
  *   The provided PLMID.
  * @param oPLMIdentificator [out, CATBaseUnknown#Release]
  *   The related PLMIdentificator.
  *
  * @return
  *   <code>S_OK</code> if the related plm type could be retrieved.
  *   <code>E_FAIL</code> otherwise.
  *
  */
  static HRESULT GetAdpIdentificatorFromPLMIdentifier( const CATPLMIdentifier & iIdentifier, CATIAdpPLMIdentificator *& oPLMIdentificator );
 };



#endif
