/* -*-C++-*-*/
#ifndef CATPolyWireOffsetOper2D_H
#define CATPolyWireOffsetOper2D_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2018
//
// CATPolyWireOffsetOper2D
//
// DESCRIPTION :
//
//               Apply the offset on all wires from a CATPolyPolygon2D
//               The offset is defined by a constant value.
//               If the RoundedOffset option is enabled, it gives a circular arc result (according to the Minkowsky offset specification),
//               If the RoundedOffset option is disabled, it gives a sharp vertex computed by extrapolation (in this case, the offset distance is not respected).
//
//=============================================================================
// Abstract Class     : No
//
// History
//
// January 2018   Julien GOURDON (JXO)    Creation    
//
//=============================================================================

#include "PolygonalOperators.h"        // ExportedBy

#include "CATErrorDef.h"               // HRESULT define

class CATSoftwareConfiguration;
class CATTolerance;
class CATPolyPolygon2D;
class CATPolyOffsetRule2D;
class CATPolyWire2D;

/**
* Class implementing the offset of polygonal wires
* The returned result is a new PolyPolygon2D (a wire)
*<ul>
* <li>CATPolyWireOffsetOper2D is created with the <tt>CATPolyWireOffsetOper2D</tt> constructor method.
* It can be reused with different offset values (but without any effect on the perfomances)
* It must be directly removed with the <tt>delete</tt> method after use.
* It is not streamable. 
*<li>The CATPolyPolygon2D data result is filled through the <tt>Run</tt> method. 
* It can be kept by the user even if the operator is removed, but it must be directly removed with the <tt>delete</tt> method after use.
*</ul>
* @see CATPolyPolygon2D
*/

class ExportedByPolygonalOperators CATPolyWireOffsetOper2D
{

public:

  enum Side
  {
    eRHS, // Right hand side
    eLHS  // Left hand side
  };

 /**
  * Constructor
  * @param iWirePolygon
  * The polygonal wire to offset
  * @param iSetOfTol
  * Set of tolerances depending on a contextual scale, mandatory to be compliant with the CGM rules (CATCGMContainer, CATGeoFactory)
  * In other contexts, this set can be set to null and the polygonal operation will be computed with an Exact Arithmetic in a gridded mode
  * @param iSoftwareConfig
  * Versionning Management to allow the caller not to be impacted by a change of behavior after correction
  * a Null configuration leads to take advantage of the last version of code (best so far)
  */
  CATPolyWireOffsetOper2D(const CATPolyPolygon2D &iWirePolygon, const CATTolerance * iSetOfTol=NULL, CATSoftwareConfiguration * iSoftwareConfig=NULL);

 /**
  * Destructor
  */
  ~CATPolyWireOffsetOper2D();

 /** @name Main Method
  @{ */

 /**
  * This call leads to enable the default behavior of Rounded 'Minkowsky' Offset :
  * This default mode impacts the offset behavior only on the convexe (resp. concave) border vertices in case of positive (resp. negative) offset value
  * the offset will create polyhedral arcs from sharp vertices and the final precision depends on the accuracy given by the Run() method.
  *
  * Runs the operator for a given offset value.
  * @param iOffsetValue
  *   The Offset value to apply on the wire.
  * @param iSAG
  *   Accuracy value to drive the precision (polylines discretization in Minkowsky circle offset ...)
  * @param oOffsetPolygon2D
  *   An output argument with the result of the operation.
  *   The returned object must be deleted by the caller.
  * @return
  * <ul>
  *   <li> <tt>S_OK</tt> if the operator runs successfully.
  *   <li> <tt>E_FAIL</tt> if an error occurs.
  * </ul>
  */
  HRESULT Run (Side iSide, const double iOffsetValue, const double iSAG, CATPolyPolygon2D *& oOffsetPolygon2D);

 /**
  * RUN METHOD with wire selection.
  * This call leads to enable the default behavior of Rounded 'Minkowsky' Offset :
  * This default mode impacts the offset behavior only on the convexe (resp. concave) border vertices in case of positive (resp. negative) offset value
  * the offset will create polyhedral arcs from sharp vertices and the final precision depends on the accuracy given by the Run() method.
  *
  * Runs the operator for a given offset value.
  * @param iOffsetValue
  *   The Offset value to apply on the wire.
  * @param iSAG
  *   Accuracy value to drive the precision (polylines discretization in Minkowsky circle offset ...)
  * @param iWireToOffset
  *   Wire to offset. It should be inside the input polygon. All other wires will be skipped.
  * @param oOffsetPolygon2D
  *   An output argument with the result of the operation.
  *   The returned object must be deleted by the caller.
  * @return
  * <ul>
  *   <li> <tt>S_OK</tt> if the operator runs successfully.
  *   <li> <tt>E_FAIL</tt> if an error occurs.
  * </ul>
  */
  HRESULT Run (Side iSide, const double iOffsetValue, const double iSAG, CATPolyWire2D * iWireToOffset, CATPolyPolygon2D *& oOffsetPolygon2D);

  /** @} */

private:

  // Input Data
  // ----------
  const CATPolyPolygon2D    & m_WirePolygon;
  const CATTolerance        * m_SetOfTol;
  CATSoftwareConfiguration  * m_Config;
};

#endif
