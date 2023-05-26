/* -*-C++-*-*/
#ifndef CATPolyOffsetOper2D_H
#define CATPolyOffsetOper2D_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATPolyOffsetOper2D
//
// DESCRIPTION :
//
//               Apply the offset on all boundaries of a set of polygonal faces 
//               The offset is defined by a constant value
//               The convention leads to erode the faces (trimming the matter) when the offset value is negative
//               and to dilate the faces (extrapolating the matter) when the offset is positive
//               A positive offset (resp. negative offset) applied on a convexe loop vertex (resp. concave vertex)
//               will lead to 2 different results according to the enabled/disabled RoundedBorderMode option
//               If the option is enabled, it gives a circular arc result (according to the Minkowski offset specification),
//               If the option is disabled, it gives a sharp vertex computed by extrapolation (in this case, the offset distance is not respected).
//
//=============================================================================
// Abstract Class     : No
//
// History
//
// January. 2012   Dominique PREVOST (DPS)    Creation    
//
//=============================================================================

#include "PolygonalOperators.h"        // ExportedBy

#include "CATPolyPolygon2D.h"          // aggregation
#include "CATMathBox2D.h"              // aggregation

#include "CATErrorDef.h"               // HRESULT define
#include "CATListOfDouble.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"

#include "CATMathInline.h"


class CATSoftwareConfiguration;
class CATTolerance;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyLoop2D;
class CATPolyOffsetRule2D;
class CATPolyOffsetObserver2D;

/**
* Class implementing the offset of polygonal closed boundaries (topological face loops)
* The returned result is a new PolyPolygon2D
*<ul>
* <li>CATPolyOffsetOper2D is created with the <tt>CATPolyOffsetOper2D</tt> constructor method.
* It can be reused with different offset values (but without any effect on the perfomances)
* It must be directly removed with the <tt>delete</tt> method after use.
* It is not streamable. 
*<li>The CATPolyPolygon2D data result is filled through the <tt>Run</tt> method. 
* It can be kept by the user even if the operator is removed, but it must be directly removed with the <tt>delete</tt> method after use.
*</ul>
* @see CATPolyPolygon2D
*/

class ExportedByPolygonalOperators CATPolyOffsetOper2D
{

public:

 /**
 * Life Cycle Management
 * Constructor
 * @param iPolygonFace
 * The polygonal Face to offset
 * @param iSetOfTol
 * Set of tolerances depending on a contextual scale, mandatory to be compliant with the CGM rules (CATCGMContainer, CATGeoFactory)
 * In other contexts, this set can be set to null and the polygonal operation will be computed with an Exact Arithmetic in a gridded mode
 * @param iSoftwareConfig
 * Versionning Management to allow the caller not to be impacted by a change of behavior after correction
 * a Null configuration leads to take advantage of the last version of code (best so far)
 */
  CATPolyOffsetOper2D(const CATPolyPolygon2D &iPolygonFace, const CATTolerance * iSetOfTol=NULL, CATSoftwareConfiguration * iSoftwareConfig=NULL);


 /**
  * Destructor
  */
  virtual ~CATPolyOffsetOper2D();


 /** @name Main Method
  @{ */

  /**
  * ADVANCED RUN METHOD
  *
  * Runs the operator for a given offset value.
  * @param iOffsetValue
  *   The Offset value to apply on all boundaries of the Polygonal face.
  * @param iOffsetRule
  *   Rule class defining the behavior (Rounded or Sharp) for each sharp vertex 2D
  * @param oOffsetPolygon2D
  *   An output argument with the result of the operation.
  *   The returned object must be deleted by the caller.
  * @return
  * <ul>
  *   <li> <tt>S_OK</tt> if the operator runs successfully.
  *   <li> <tt>E_FAIL</tt> if an error occurs.
  * </ul>
  */
  virtual HRESULT Run (const double iOffsetValue, const CATPolyOffsetRule2D & iOffsetRule,
                       CATPolyPolygon2D *& oOffsetPolygon2D);



 /**
 * BASIC RUN METHOD, please use the Run method with the RoundedRule argument to switch in ADVANCED MODE
 *
 * This call leads to enable the default behavior of Rounded 'Minkowski' Offset :
 * This default mode impacts the offset behavior only on the convexe (resp. concave) border vertices in case of positive (resp. negative) offset value
 * the offset will create polyhedral arcs from sharp vertices and the final precision depends on the accuracy given by the Run() method.
 *
 * Runs the operator for a given offset value.
 * @param iOffsetValue
 *   The Offset value to apply on all boundaries of the Polygonal face.
 * @param iSAG
 *   Accuracy value to drive the precision (polylines discretization in Minkowski circle offset ...)
 * @param oOffsetPolygon2D
 *   An output argument with the result of the operation.
 *   The returned object must be deleted by the caller.
 * @return
 * <ul>
 *   <li> <tt>S_OK</tt> if the operator runs successfully.
 *   <li> <tt>E_FAIL</tt> if an error occurs.
 * </ul>
 */
  virtual HRESULT Run (const double iOffsetValue, const double iSAG, CATPolyPolygon2D *& oOffsetPolygon2D);

  /** @} */

public:

  /** @name Observers
  @{ */

  /**
  * Registers an observer.
  */
  HRESULT RegisterObserver (CATPolyOffsetObserver2D& iObserver);

  /**
  * Unregisters an observer.
  */
  HRESULT UnregisterObserver (CATPolyOffsetObserver2D& iObserver);

  /** @} */

protected:

  /**
  * Offset the boundaries to limit the Hatching Area
  */
  HRESULT OffsetPolygonBoundaries(const CATPolyOffsetRule2D & iOffsetRule, CATPolyPolygon2D &oOffsetPolygon2D);

  /**
  * Set the offset boundary as operand for the boolean
  */
  HRESULT PrepareOffsetPolygonAsBooleanOperand(const CATPolyOffsetRule2D & iOffsetRule, CATPolyPolygon2D & ioOffsetPolygon2D, CATMathBox2D & oOffsetBox2D);

  /**
  * Check and repair the negative offset polygone in case of unexpected remaining areas outside the original polygone
  */
  HRESULT CheckAndRepairNegativeOffsetPolygon(CATPolyPolygon2D & ioOffsetPolygon2D);


private:

  // Input Data
  // ----------
  const CATPolyPolygon2D    & _PolygonFace;
  const CATTolerance        * _SetOfTol;
  CATSoftwareConfiguration  * _Config;
  CATPolyOffsetObserver2D   * _Observer;


  // Private Data
  // ------------
  double                      _MergeTol;
  double                      _OffsetVal;
};

#endif
