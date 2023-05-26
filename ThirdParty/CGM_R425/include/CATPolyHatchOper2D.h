/* -*-C++-*-*/
#ifndef CATPolyHatchOper2D_H
#define CATPolyHatchOper2D_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2011
//
// CATPolyHatchOper2D
//
// DESCRIPTION :
//
//               Apply the Hatching on a CATFace with a set of dashed lines patterns
//               to compute a result as a set of parametric points and segments 
//
//=============================================================================
// Abstract Class     : Yes
//
// History
//
// November. 2011   Dominique PREVOST (DPS)    Creation    
//
//=============================================================================

#include "PolygonalHatching.h"         // ExportedBy

#include "CATErrorDef.h"               // HRESULT define
#include "CATListOfDouble.h"
#include "CATTolerance.h"

class CATPolyHatchResult2D;
class CATPolyHatchPattern2D;

class CATPolyPolygon2D;
class CATTolerance;
class CATSoftwareConfiguration;
class CATMathBox2D;


/**
* Class defining the operator that applies the Hatching on a polygonal face from a set of dashed line patterns
* The returned result is a set of parametric (2D) dots and dashes.
*<ul>
* <li>CATPolyHatchOper2D is created with the <tt>CATCreatePolyHatchOper2D</tt> global function.
* It can be reused for different Hatching parameters.
* It must be directly removed with the <tt>delete</tt> method after use.
* It is not streamable. 
* <li>The Hatching can be limited or not to a given area from the face boundaries with the methods
* <tt>SetHatchWidthFromBoundary</tt> and <tt>UnsetHatchWidthFromBoundary</tt>
*<li>The CATPolyHatchResult2D data instance is accessed through the <tt>Run</tt> method. 
* It can be kept by the user even if the operator is removed, but it must be directly removed with the <tt>delete</tt> method after use.
*</ul>
*/

class ExportedByPolygonalHatching CATPolyHatchOper2D
{

public:

  /**
  * Life Cycle Management
  * No constructor for this virtual class.  
  * Please, use the CATCreatePolyHatchOper2D method (at the end of this header) 
  * Destructor
  */
  virtual ~CATPolyHatchOper2D() {};


public:

 /** @name Settings
  @{ */

  /**
  * Defines a strip from the boundary to limit the hatching area
  * The default behavior applies the offset of the boundary keeping sharp vertices
  * @param iStripWidth
  *   A positive value defining the strip inside the face.
  *   A negative value defining the strip outside the face.
  * @param iRoundedOffsetSAG (optional)
  *   enables the Minkowsky offset behavior and drives the precision to approximate circular arcs by polylines
  */
  virtual void DefineALimitingBorderStrip (double iStripWidth, double * iRoundedOffsetSAG=NULL) = 0;

 /**
 * Unsets the strip limiting the hatching which will occur on the full face.
 * This is the default setting.
 */
  virtual void UnsetLimitingBorderStrip () = 0;

 /** @} */


public:

 /** @name Main Method
  @{ */

 /**
  * Runs the operator for a given hatch pattern.
  * @param iPattern
  *   The hatch pattern to apply to the polygonal face.
  * @param iAngle
  *   The angle of the pattern with the first axis in degrees.
  * @param iScale
  *   The scaling of the pattern. A larger scale means a bigger pattern is applied.
  * @param oResult
  *   An output argument with the result of the operation.
  *   The returned object must be deleted by the caller.
  * @return
  * <ul>
  *   <li> <tt>S_OK</tt> if the operator runs successfully.
  *   <li> <tt>E_FAIL</tt> if an error occurs.
  * </ul>
  */
  virtual HRESULT Run (CATPolyHatchPattern2D& iPattern, double iAngle, double iScale, CATPolyHatchResult2D *& oResult) = 0;

 /** @} */


public :

 /**
  * Debug only
  * Enable/Disable the option to parallelize the computation with several tasks
  * @param iEnabledMultiTasks
  * The performances depend on this option : to speed up the hatching for complexe patterns, activate the MultiTasksMode
  */
  virtual void EnableMultiTasks(CATBoolean iEnabledMultiTasks=TRUE) = 0;

 /**
  * Debug only
  * Please, note that the Offset Polygon2D remains under the responsability of the PolyHatchOper2D current instance.
  * This use has to be limited to a simple reading while the operator is still alive.
  * MAY RETURN NULL
  */
  virtual const CATPolyPolygon2D * GetOffsetPolygon2D() = 0;

};


// =======================================================================================================================================================

/**
* Creates an operator to apply the hatching on a given polyhedral face
* <br>The constructor generates a CATPolyHatchEngine2D instance
* @param iPolygonFace
*    The topological polyhedral Data
*    The polygonal face defines the area to hatch.
* @param iTol
*    CATTolerance object defining the scale & the set of tolerances for both relative and length tests
* @param iConfig
*    Versionning management :
*    a null Config leads to the 'best so far' behavior, but the stability of the result is not garanteed in the future
* @param iFaceBox2D
*    (not Mandatory) avoids to compute the box if known by the caller
* @return
*   The pointer to the created operator
*   To be removed with the <tt>delete</tt> method.
* @see CATPolyHatchOper2D
*/

ExportedByPolygonalHatching CATPolyHatchOper2D * CATCreatePolyHatchOper2D(const CATPolyPolygon2D &iPolygonFace, const CATTolerance &iTol,
                                                                          CATSoftwareConfiguration * iConfig, CATMathBox2D * iFaceBox2D=NULL);

#endif
