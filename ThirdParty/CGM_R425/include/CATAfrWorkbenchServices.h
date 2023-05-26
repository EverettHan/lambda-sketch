#ifndef CATAfrWorkbenchServices_H
#define CATAfrWorkbenchServices_H
#include "CATAfrFoundation.h"

#include "IUnknown.h"

class CATUnicodeString;
class CATString;

// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//---------------------------------------------------------------------------
/**
 * Starts a workbench.
 * <br><b>Role</b>: This method starts a workbench as if the user had chosen it in the Start menu.
 * @param iWorkbenchId
 *   The identifier of the workbench to start.
 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>   <dd>if the workbench was found and started
 *   <dt><tt>E_FAIL</tt> <dd>if the workbench was not found
 *   </dl>
 */
ExportedByCATAfrFoundation
HRESULT CATAfrStartWorkbench (const CATString & iWorkbenchId);

//---------------------------------------------------------------------------
/**
 * Gets the identifier of a workbench.
 * <br><b>Role</b>: This method gets the identifier of a workbench from its user name.
 * <br>The workbench identifier is the internal name given to the workbench when it was created
 * (@href CATIWorkbench#CreateWorkbench).
 * <br>The workbench user name is the NLS string which appears in the Start menu.
 * @param iWorkbenchNLSName
 *   The NLS name of the workbench.
 * @param oWorkbenchId
 *   The identifier of the workbench.
 * @return
 *   <dl>
 *   <dt><tt>S_OK</tt>   <dd>if the workbench was found
 *   <dt><tt>E_FAIL</tt> <dd>if the workbench was not found
 *   </dl>
 */
ExportedByCATAfrFoundation
HRESULT CATAfrGetWorkbenchIdentifierFromNLSName (const CATUnicodeString & iWorkbenchNLSName, CATString & oWorkbenchId);

#endif
