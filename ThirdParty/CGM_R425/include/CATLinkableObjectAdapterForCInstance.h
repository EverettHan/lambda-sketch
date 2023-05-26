/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
// Creation: PBV

#ifndef CATLinkableObjectAdapterForCInstance_h
#define CATLinkableObjectAdapterForCInstance_h

#include "CATObjectModelerBase.h"

#include "CATLinkableObjectAdapter.h"


/**
 * Adapter for CATILinkableObject implementation for Component Instance.
 * <b>Role</b>: Adapter for CATILinkableObject implementation for Component Instance .<br>
*/
class ExportedByCATObjectModelerBase CATLinkableObjectAdapterForCInstance : public CATLinkableObjectAdapter
{
public:

  CATLinkableObjectAdapterForCInstance();
  virtual ~CATLinkableObjectAdapterForCInstance();

  /**
   * Gets the naming context of the component instance.
   * @param iInterfaceID
   *   Interface to query on the naming context.
   * @return
   *   the naming context of the component instance.<br>
   */
  virtual CATBaseUnknown* GetNamingContext (CATIdent interfaceID);

  /**
   * Gets the identifier of the component instance.
   * @param oIdentifier
   *   The identifier of the component instance.
   * @param oIsAnUuid
   *   TRUE if the identifier is an UUID else FALSE.<br>
   */
  virtual void  GetIdentifier( SEQUENCE(octet) & identifier ,boolean & IsAnUuid);

  /**
   * Gets the document containing the component instance.
   * @return
   *   the document containing the component instance. Should be NULL. <br>
   */
  virtual CATDocument * GetDocument ();

  /**
  * Gets the Last Modification Id of the component instance.
  * @return
  *   the Last Modification Id of the component instance. Should be void. <br>
  */
  virtual SEQUENCE(octet)  GetLastModificationId ();

  /**
  * Gets the locator type of the component instance.
  * @return
  *   the locator type of the component instance. Should be PLMIDLocator. <br>
  */
  virtual SEQUENCE(octet)  GetLocatorType();

  /**
  * Gets the Additional Infos of the component instance.
  * @return
  *   the Additional Infos of the component instance. Should be void. <br>
  */
  virtual SEQUENCE(octet)  GetAdditionalInfos();
};

#endif

