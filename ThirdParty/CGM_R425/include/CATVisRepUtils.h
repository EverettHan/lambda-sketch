#ifndef CAVisTRepUtils_H
#define CATVisRepUtils_H

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Provide services for 
//             - retrieving the GraphicPrimitive from a CAT3DCurvedPipeRep.
//             - retrieving the GraphicPrimitive from a CAT3DCylinderRep.
//
//------------------------------------------------------------------------------
// Inheritance: None
//------------------------------------------------------------------------------
// Main methods:    
//
//           CATVisGetCurvedPipeGPFromRep
//           CATVisGetCylinderGPFromRep
//=============================================================================
// Function:
//
//=============================================================================

#include "SceneGraphManager.h"      
#include "IUnknown.h"

class CAT3DRep;
class CAT3DCurvedPipeGP;
class CAT3DCylinderGP;

  /**
   * Get the GraphicPrimitive from a CAT3DCurvedPipeRep.
   * @param iRep
   *	The CAT3DCurvedPipeRep from which retrieving the GraphicPrimitive.
   * @param oCurvedPipeGP
   *	The returned GraphicPrimitive.
   * @return
   *	an HRESULT value.
   *		<br><b> Legal values</b>:
   *		<li><tt>S_OK</tt> if the operation succeeds </li>
   *		<li><tt>E_FAIL</tt> otherwise</li>.
   */
extern ExportedBySceneGraphManager HRESULT CATVisGetCurvedPipeGPFromRep	(const CAT3DRep *iRep, CAT3DCurvedPipeGP *& oCurvedPipeGP);

  /**
   * Get the GraphicPrimitive from a CAT3DCylinderRep.
   * @param iRep
   *	The CAT3DCylinderRep from which retrieving the GraphicPrimitive.
   * @param oCylinderGP
   *	The returned GraphicPrimitive.
   * @return
   *	an HRESULT value.
   *		<br><b> Legal values</b>:
   *		<li><tt>S_OK</tt> if the operation succeeds </li>
   *		<li><tt>E_FAIL</tt> otherwise</li>.
   */
extern ExportedBySceneGraphManager HRESULT CATVisGetCylinderGPFromRep	(const CAT3DRep *iRep, CAT3DCylinderGP *& oCylinderGP);

#endif
