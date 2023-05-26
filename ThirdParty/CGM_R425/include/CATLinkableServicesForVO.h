/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT Dassault Systemes 2004
//=============================================================================
//
// Services de nommage d'objets virtuels
//
//=============================================================================
// Sep. 04   Creation                                                  O.PERIOU
//=============================================================================

#ifndef CATLinkableServicesForVO_H
#define CATLinkableServicesForVO_H

#include "CATOmbLnkVO.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

class CATDocument;
class CATIVOFactory;
class sequence_octet;

/**
 * Virual Objects naming services.
 * <b>Role</b>: Services for naming Virtual Objects .<br>
 */

class ExportedByCATOmbLnkVO CATLinkableServicesForVO
{
public:

  /**
   * Gets the naming context of the VO.
   * @param iVO
   *   The virual object.
   * @param iFactory
   *   The factory.
   * @param iInterfaceID
   *   Interface to query on the naming context.
   * @return
   *   the naming context of the VO.<br>
   */

	static CATBaseUnknown* GetNamingContext (const CATBaseUnknown* iVO, CATIVOFactory* iFactory, CATIdent iInterfaceID);

  /**
   * Gets the identifier of the VO.
   * @param iVO
   *   The virual object.
   * @param iFactory
   *   The factory.
   * @param oIdentifier
   *   The identifier of the VO. It is the sequence of the identifiers of the simple objects componing the VO
   * @param oIsAnUuid
   *   TRUE if the identifier is an UUID else FALSE.<br>
   */

	static void GetIdentifier(const CATBaseUnknown* iVO, CATIVOFactory* iFactory , SEQUENCE(octet) & oIdentifier,CATBoolean& oIsAnUuid);

  /**
   * Gets the document containing the VO.
   * @param iVO
   *   The virual object.
   * @param iFactory
   *   The factory.
   * @return
   *   the document containing the VO. Should be NULL. <br>
   */

	static CATDocument* GetDocument (const CATBaseUnknown* iVO, CATIVOFactory* iFactory);

  /**
   * Gets the locator type of the VO.
   * @param iVO
   *   The virual object.
   * @param iFactory
   *   The factory.
    * @return
   *   the locator type of the VO. Should be VOLocator. <br>
   */

	static SEQUENCE(octet)  GetLocatorType(const CATBaseUnknown* iVO, CATIVOFactory* iFactory);

  /**
   * Gets the Additional Infos of the VO.
   * @param iVO
   *   The virual object.
   * @param iFactory
   *   The factory.
    * @return
   *   the Additional Infos of the VO. Should be void. <br>
   */

	static SEQUENCE(octet)  GetAdditionalInfos(const CATBaseUnknown* iVO, CATIVOFactory* iFactory);

  /**
   * Gets the Last Modification Id of the VO.
   * @param iVO
   *   The virual object.
   * @param iFactory
   *   The factory.
    * @return
   *   the Last Modification Idof the VO. Should be void. <br>
   */

	static SEQUENCE(octet)  GetLastModificationId (const CATBaseUnknown* iVO, CATIVOFactory* iFactory);

  /**
  * Retrieves an equivalent VO inserted in the session link cache.
  * @param iVO
  *   The virual object.
  * @param iFactory
  *   The factory.
  * @return
  * <dl>
  * <dt> The equivalent VO if found in link cache. (Object should be released by caller)
  * </dl>
  */	
  static CATBaseUnknown * GetVOInLinkCache (const CATBaseUnknown* iVO, CATIVOFactory* iFactory);

private:

// Not implemented

	CATLinkableServicesForVO();
	~CATLinkableServicesForVO();
	CATLinkableServicesForVO(const CATLinkableServicesForVO&);
	CATLinkableServicesForVO& operator = (const CATLinkableServicesForVO&);
};


#endif
