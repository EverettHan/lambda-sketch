//===================================================================
// COPYRIGHT Dassault Systemes 2010/03/18
//===================================================================
// CATIPLMWorkspaceID.cpp
// Header definition of class CATIPLMWorkspaceID
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/03/18 Creation: LEC
//===================================================================

/**
* @level Protected
* @usage U4 CATPLMWorkspaceIDAdapter
*/

#ifndef CATIPLMWorkspaceID_H
#define CATIPLMWorkspaceID_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

class CATPLMID;

extern ExportedByCATPLMServicesItf  IID IID_CATIPLMWorkspaceID ;


class ExportedByCATPLMServicesItf CATIPLMWorkspaceID: public CATBaseUnknown
{
CATDeclareInterface;

public:

  /**
   * Returns the workspace identifier.
   * @param oWspID [out]
   *    The PLMID of the workspace.
   * 
   * E_FAIL : The PLMID cannot be retrieved.
   */
  virtual HRESULT GetWorkspaceID (CATPLMID &oWspID) = 0;

  /**
   * Set the workspace identifier.
   * @param iWspID [in]
   *    The PLMID of the workspace.
   * 
   * E_FAIL : The PLMID cannot be set.
   */
  virtual HRESULT SetWorkspaceID (const CATPLMID &iWspID) = 0;

};

//-----------------------------------------------------------------------

#endif
