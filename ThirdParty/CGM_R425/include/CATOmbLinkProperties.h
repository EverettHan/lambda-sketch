#ifndef CATOmbLinkProperties_H
#define CATOmbLinkProperties_H


// COPYRIGHT DASSAULT SYSTEMES 2005


/**
* @level Protected
* @usage U1
*/


#include "CORBAAnyDef.h"
#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATListOfCATOmbLinkProperties.h"

class CATOmbOutputRelation;
class CATComponentId;

/**
* Class to retrieve the properties of an external link.
*/
class  ExportedByCATObjectModelerBase CATOmbLinkProperties
{
public:

  /**
  * Link property.
  *<br>
  * <b>Role:</b> This type enumerates the available properties of a link.
  * @param PointingElement
  *  The pointing element.
  * @param PointedElement
  *  The pointed element (if is exists).
  * @param PointedComponent
  *  The pointed component (if is exists).
  * @param LinkStatus
  *  The status of the link. (see @href CATOmbLinkStatus)
  * @param Owner
  *  The owner of the link (if it is defined).
  * @param PointingObject
  *  The pointing object (the pointing element as an object).
  * @param PointedObject
  *  The pointed object (if is exists, the pointed element as an object).
  */
  enum CATOmbLinkProperty
  {
    PointingElement, PointedElement, PointedComponent, LinkStatus,
    Owner, PublicationName = (Owner + 2), PointingObject = (PublicationName + 4), PointedObject, FinalTargetObject
  };

  /**
  * Link status.
  *<br>
  * <b>Role:</b> This type enumerates status of a link.
  * @param Unknown
  *  The status is unknown.
  * @param OK
  *  The link is solved.
  * @param Broken
  *  The link is broken.
  * @param NotSynchronized
  *  The link is not synchronized.
  * @param ComponentNotLoaded
  *  The pointed component is not completely loaded so the link can't be bound.
  * @param ComponentNotOpened
  *  The pointed component is not in session.
  * @param ComponentBrokenSession
  *  The pointed component has been deleted in session.
  * @param ComponentBrokenRemote
  *  The ponted component has been deleted in the remote persistency.
  * @param ComponentNotFound
  *  Not used.
    *  @param NotApplicable
    *  The SynchroStatus is not handled (the corresponding relation is not neutral).
  */
  enum CATOmbLinkStatus { Unknown, OK, Broken, NotSynchronized, ComponentNotFound, ComponentNotLoaded, ComponentNotOpened, ComponentBrokenSession, ComponentBrokenRemote, NotApplicable };

  /**
  * Retrieves the properties of the link.
  * @param iPropertyName
  *   The name of the property.
  * @param oPropertyValue
  *   The value of the property.
  *   <br>To retrieve a userfriendly value, use the >> operator on oPropertyValue (see @href CORBAAny)
  *   with the following rvalue C++ type.
  *   <table border="1">
  *     <tr>
  *       <td><b>Property Name </b></td>
  *       <td><b>C++ Type </b></td>
  *     </tr>
  *     <tr>
  *       <td>PointingElement</td>
  *       <td>CATUnicodeString</td>
  *     </tr>
  *     <tr>
  *       <td>PointedElement</td>
  *       <td>CATUnicodeString</td>
  *     </tr>
  *     <tr>
  *       <td>PointedComponent</td>
  *       <td>CATUnicodeString</td>
  *     </tr>
  *     <tr>
  *       <td>LinkStatus</td>
  *       <td>short</td>
  *     </tr>
  *     <tr>
  *       <td>Owner</td>
  *       <td>CATUnicodeString</td>
  *     </tr>
  *     <tr>
  *       <td>LinkName</td>
  *       <td>CATUnicodeString</td>
  *     </tr>
  *     <tr>
  *       <td>PublicationName</td>
  *       <td>CATUnicodeString</td>
  *     </tr>
  *     <tr>
  *       <td>IsSynchronizable</td>
  *       <td>unsigned short</td>
  *     </tr>
  *     <tr>
  *       <td>IsLogicallyReroutable</td>
  *       <td>unsigned short</td>
  *     </tr>
  *     <tr>
  *       <td>IsDeactivable </td>
  *       <td>unsigned short</td>
  *     </tr>
  *     <tr>
  *       <td>PointingObject</td>
  *       <td>CATBaseUnknown*</td>
  *     </tr>
  *     <tr>
  *       <td>PointedObject</td>
  *       <td>CATBaseUnknown*</td>
  *     </tr>
  *   </table>
  * @return
  *   S_OK.
  */
  virtual HRESULT GetLinkProperty(CATOmbLinkProperty iPropertyName, CORBAAny & oPropertyValue) = 0;

  /**
  * Returns the relational part of the link.
  * @return
  *   The output relation, NULL if the link is not valid anymore.
  */
  virtual CATOmbOutputRelation * GetOutputRelation() const = 0;

  /**
  * Loads the Pointed Component of the link.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The pointed component was loaded successfully.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The pointed component can't be loaded.</dd>
  *  </dl>
  */
  virtual HRESULT LoadPointedComponent() = 0;

  /**
  * Breaks the link.
  * <br><b>Note:</b>It may trigger a load event to load the pointing component.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The link was isolated successfully.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The link can't be isolated.</dd>
  *  </dl>
  */
  virtual HRESULT Break() = 0;

  /**
  * Isolates a list of links.
  * <br><b>Note:</b>It may trigger a load event to load the pointing components.
  * @param iLinks
  *  The list of links to isolate.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>E_FAIL</dt>
  *    <dd>At least one link failed to be isolated.</dd>
  *   <dt>S_OK</dt>
  *    <dd>All links were isolated successfully.</dd>
  *  </dl>
  */
  static HRESULT Break(const CATLISTP(CATOmbLinkProperties) & iLinks);

  /**
  * Synchronizes the current link.
  * <br><b>Note:</b>It may trigger a load event to load the pointing component.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The link was synchronized successfully.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The link can't be synchronized.</dd>
  *   <dt>E_INVALIDARG </dt>
  *    <dd>If synchronizing a synchro disabled relation.</dd>
  *  </dl>
  */
  virtual HRESULT Synchronize() = 0;

  /**
  * Synchronizes a list of links.
  * <br><b>Note:</b>It may trigger a load event to load the pointing component.
  * @param iLinks
  *  The list of links to synchronize.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>E_FAIL</dt>
  *    <dd>At least one link failed to be synchronizes.</dd>
  *   <dt>E_INVALIDARG </dt>
  *    <dd>If synchronizing a synchro disabled relation.</dd>
  *   <dt>S_OK</dt>
  *    <dd>All links were synchronized successfully.</dd>
  *  </dl>
  */
  static HRESULT Synchronize(const CATLISTP(CATOmbLinkProperties) & iLinks);

  /*
  * @deprecated
  * Use GetOutputRelation instead.
  * @see #GetOutputRelation
  */
  enum CATOmbRelationProperty { Role, Category };

  /**
  * @deprecated
  * Use GetOutputRelation instead.
  * @see #GetOutputRelation
  */
  virtual HRESULT GetRelationProperty(CATOmbRelationProperty iPropertyName, CORBAAny & oPropertyValue) = 0;

  /**
  * @deprecated
  * Use GetOutputRelation instead.
  * @see #GetOutputRelation
  */
  virtual HRESULT GetTargetPLMId(CATComponentId & oTargetId) = 0;
};

#endif



