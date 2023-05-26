/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT Dassault Systemes 2004
//=============================================================================
//
// Services de nommage d'instances concretes
//
//=============================================================================
// Nov. 04   Creation                                                  F.BOUIS
//=============================================================================

#ifndef CATLinkableServicesForCInstance_H
#define CATLinkableServicesForCInstance_H

#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

class CATDocument;
class sequence_octet;
class CATComponentId;

/**
 * Concrete Objects naming services.
 * <b>Role</b>: Services for naming Concrete Objects .<br>
 */

class ExportedByCATObjectModelerBase CATLinkableServicesForCInstance
{
public:

  /**
   * Gets the naming context of the CI.
   * @param iCI
   *   The concrete  instance.
   * @param iInterfaceID
   *   Interface to query on the naming context.
   * @return
   *   the naming context of the CI.<br>
   */

	static CATBaseUnknown* GetNamingContext (const CATBaseUnknown* iCI, CATIdent iInterfaceID);

  /**
   * Gets the identifier of the CI.
   * @param iCI
   *   The concrete instance.
   * @param oIdentifier
   *   The identifier of the CI. It is the PLMID of the CO.
   * @param oIsAnUuid
   *   TRUE if the identifier is an UUID else FALSE.<br>
   */

	static void GetIdentifier(const CATBaseUnknown* iCI, SEQUENCE(octet) & oIdentifier,CATBoolean& oIsAnUuid);

  /**
   * Gets the document containing the CI.
   * @param iCI
   *   The concrete instance.
   * @return
   *   the document containing the CI. Should be NULL. <br>
   */

	static CATDocument* GetDocument (const CATBaseUnknown* iCI);

  /**
   * Gets the locator type of the CI.
   * @param iCI
   *   The concrete instance.
    * @return
   *   the locator type of the CI. Should be PLMLocator. <br>
   */

	static SEQUENCE(octet)  GetLocatorType(const CATBaseUnknown* iCI);

	/**
   * Gets the exposed status of the CI. 
   * @param iCI
   *   The concrete instance.
    * @return
   *   The exposed status. <br>
   */
	static boolean IsExposed(const CATBaseUnknown* iCI) ;

	/**
	* Gets the additional information of the CI
	* @param iCI
	*   The concrete instance.
	* @return
	*	A sequence containing the additional information
	*/
	static SEQUENCE(octet) GetAdditionalInfos( const CATBaseUnknown* iCI );

	/**
	* Gets the last modification id
	* @param iCI
	*   The concrete instance.
	* @return
	*	A sequence containing the last modification id
	*/
	static SEQUENCE(octet)  GetLastModificationId ( const CATBaseUnknown* iCI );


	/**
	 * Gets the complete name of a "component".
	 * @param iComponentId
	 *   The reference of the PLM object.
	 * @param oName
	 *   The complete name of the PLM object (binary encoded).
	 * @return
	 *   S_OK if he name has been successfully built, S_FALSE	else.
	 */
	static HRESULT GetLinkSequenceNameFromComponentId( const CATComponentId& iComponentId, SEQUENCE(octet)& oName );


private:

	// Not implemented

	CATLinkableServicesForCInstance();
	~CATLinkableServicesForCInstance();
	CATLinkableServicesForCInstance(const CATLinkableServicesForCInstance&);
	CATLinkableServicesForCInstance& operator = (const CATLinkableServicesForCInstance&);
};


#endif
