#ifndef CATOmbRelationContext_H
#define CATOmbRelationContext_H


// COPYRIGHT DASSAULT SYSTEMES 2005


/**
* @level Protected
* @usage U1
*/


#include "CATObjectModelerBase.h"
#include "IUnknown.h"
class CATComponentId;
#include "CATOmbRelationInformation.h"

class CATUnicodeString;


/**
* Class that represents the context of a relation.
*/
class  ExportedByCATObjectModelerBase CATOmbRelationContext
{
public:

  /**
   * Retrieves the path to the context component.
   * <br><b>Note:</b>It is made of the alias of the owner and the one of all instances of the path.
   * @param oName
   *  The path to the context component.
   * @return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>The name can't be computed.</dd>
   *   <dt>S_FALSE</dt>
   *    <dd>The pointed component is not loaded.</dd>
   *   <dt>S_OK</dt>
   *    <dd>The name was computed successfully.</dd>
   *  </dl>
   */
  virtual HRESULT GetName(CATUnicodeString& oName) const = 0;

  /**
   * Retrieves the context component.
   * @return
   *	The component, which can be complex.
   */
  virtual CATComponentId& GetInstance() const = 0;

  /**
  * Returns the binding status of the context component.
  * @param oStatus
  *   The status.
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The status was computed successfully.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The status can't be computed.</dd>
  *  </dl>
  */
  virtual HRESULT GetRelationContextStatus(CATOmbRelationStatus& oStatus, CATOmbAdditionalRelationStatus * oAdditionalRelationStatus = NULL) const = 0;

  /**
  * Returns the remote status of the relation
  *
  * The remote status is evaluated only at import time (Open, Refresh, ...).
  * This information is never updated by PLM Session.
  *
  * @param oRemoteStatus
  *   The remote status.
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The status were computed successfully</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The status can't be computed.</dd>
  *  </dl>
  */
  virtual HRESULT GetRelationContextRemoteStatus(CATOmbRelationRemoteStatus & oRemoteStatus) const = 0;
};

#endif

