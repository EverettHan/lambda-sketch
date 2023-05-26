// COPYRIGHT Dassault Systemes 2010
//===================================================================
//  Oct 2010  Creation:   IVD
//===================================================================
#ifndef CATIOmbVOSnapshotFactory_H 
#define CATIOmbVOSnapshotFactory_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "PLMIOmbVirtualObjectDescriptor.h"
#include "PLMIOmbVirtualObjectDescriptor.h"
#include "CATILinkableObject.h"
#include "CATOmbVOSnapshot.h"


extern ExportedByCATObjectModelerBase IID IID_CATIOmbVOSnapshotFactory;
/**
 * @level Private
 * @usage U5
 */ 
//------------------------------------------------------------------

class ExportedByCATObjectModelerBase CATIOmbVOSnapshotFactory : public CATBaseUnknown
{
  CATDeclareInterface;

public : 

  /**
  * Builds a snapshot of a given Virtual Object described in input.
  * This method build a snapshot of the VO corresponding to the VODescriptor object, if it is valid. Once created,
  * the VOSnapshot must be used before any datamodel modification.
  * This method must be implemented on a plm component.
  * The first plm component of the description <tt>iTargetOcc</tt> and <tt>this</tt> plm component MUST belong to the same macro-modeler !
  * Though, the first plm component of the description <tt>iTargetOcc</tt> and <tt>this</tt> plm component do not have to be identical.
  * The first plm component of the description <tt>iPointingOcc</tt> and <tt>this</tt> plm component MUST belong to the same macro-modeler !
  * Though, the first plm component of the description <tt>iPointingOcc</tt> and <tt>this</tt> plm component do not have to be identical.
  *   @param iTargetOcc [in]
  *      VODescriptor describing the pointed Virtual Object that will be snapshot.
  *   @param oLinkableVOSnapshot [out,CATBaseUnknown#Release]
  *      The created VO Snapshot.
  *      The caller must release the pointer (*oLinkableVOSnapshot) if not NULL.
  *   @return
  *     <ul>
  *       <li> S_OK if everything ran ok.</li>
  *       <li> E_INVALIDARG if provided arguments are unexpected.</li>
  *       <li> E_FAIL otherwise</li>
  *     </ul>
  */
  virtual HRESULT GetVOSnapshot2(PLMIOmbVirtualObjectDescriptor* iTargetOcc, CATILinkableObject **oLinkableVOSnapshot) = 0;

};

CATDeclareHandler(CATIOmbVOSnapshotFactory, CATBaseUnknown);

#endif
