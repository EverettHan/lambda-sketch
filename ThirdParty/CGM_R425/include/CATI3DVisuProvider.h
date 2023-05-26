
#ifndef CATI3DVisuProvider_H
#define CATI3DVisuProvider_H

// COPYRIGHT DASSAULT SYSTEMES 2000
//===================================================================
//

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATProviderItf.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

extern ExportedByCATProviderItf IID IID_CATI3DVisuProvider;

/**
 * Interface used to retrieve the children of a base feature's extension(s). 
 * <b>Role:</b> the provider algorithm handles the extension's children in order to
 * include them in the visualization process. 
 * @see CATI3DGeoVisu
 */
class ExportedByCATProviderItf CATI3DVisuProvider : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Returns a list of the children of a base feature's extension(s).
   * @param iObj
   *   The base feature object.
   * @param oListChildren
   *   The list of the children of the base feature's extension(s).
   * @return
   *   The code error. 
   *   <dl>
   *   <dt><tt>S_OK</tt></dt><dd>the method is successful</dd>
   *   <dt><tt>E_FAIL</tt></dt><dd>otherwise</dd>
   *   </dl>
   */
  virtual HRESULT GetChildren(CATBaseUnknown * iObj, CATLISTP(CATBaseUnknown) ** oListChildren) = 0;
};

//------------------------------------------------------------------

CATDeclareHandler(CATI3DVisuProvider, CATBaseUnknown);

#endif
