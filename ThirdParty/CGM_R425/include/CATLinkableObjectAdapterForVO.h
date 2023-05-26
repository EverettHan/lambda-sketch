/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// Adapter pour l'implémentation de CATILinkableObject pour un objet virtuel
//
//=============================================================================
// Sep. 04   Creation                                                  O.PERIOU
//=============================================================================

#ifndef CATLinkableObjectAdapterForVO_H
#define CATLinkableObjectAdapterForVO_H

#include "CATOmbLnkVO.h"

#include "CATLinkableObjectAdapter.h"
#include "CATBaseUnknown.h"

class CATIVOFactory;

/**
 * Adapter for CATILinkableObject implementation for Virtual Object.
 * <b>Role</b>: Adapter for CATILinkableObject implementation for Virtual Object .<br>
 */

class ExportedByCATOmbLnkVO CATLinkableObjectAdapterForVO: public CATLinkableObjectAdapter 
{

public:

// CTOR, DTOR
	
  CATLinkableObjectAdapterForVO();
  virtual ~CATLinkableObjectAdapterForVO();

  /**
   * Gets the naming context of the VO.
   * @param iInterfaceID
   *   Interface to query on the naming context.
   * @return
   *   the naming context of the VO.<br>
   */
	
  CATBaseUnknown* GetNamingContext (CATIdent iInterfaceID) ;
  
 /**
   * Gets the identifier of the VO.
   * @param oIdentifier
   *   The identifier of the VO. It is the sequence of the identifiers of the simple objects componing the VO
   * @param oIsAnUuid
   *   TRUE if the identifier is an UUID else FALSE.<br>
   */
	
  void GetIdentifier( SEQUENCE(octet) & oIdentifier, boolean& oIsAnUuid);

  /**
   * Gets the document containing the VO.
   * @return
   *   the document containing the VO. Should be NULL. <br>
   */
	
  CATDocument    * GetDocument () ;
	
  /**
   * Gets the Last Modification Id of the VO.
    * @return
   *   the Last Modification Idof the VO. Should be void. <br>
   */

  SEQUENCE(octet)  GetLastModificationId () ;

  /**
   * Gets the locator type of the VO.
    * @return
   *   the locator type of the VO. Should be VOLocator. <br>
   */
	
  SEQUENCE(octet)  GetLocatorType();
	
  /**
   * Gets the Additional Infos of the VO.
    * @return
   *   the Additional Infos of the VO. Should be void. <br>
   */

  SEQUENCE(octet)  GetAdditionalInfos();
	
	
private:

// Not implemented

  CATLinkableObjectAdapterForVO(const CATLinkableObjectAdapterForVO&);
  CATLinkableObjectAdapterForVO& operator = (const CATLinkableObjectAdapterForVO&);

// Internal use

  CATIVOFactory* _Factory;
  CATIVOFactory* GetFactory();
};


#endif
