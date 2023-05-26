/* -*-C++-*-*/
#ifndef CATPolyHatchPattern2D_H
#define CATPolyHatchPattern2D_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATPolyHatchPattern2D
//
// DESCRIPTION :
//
//    Implementation of a Generic Hatch Pattern,
//    composed by a set fo Hatch SubPatterns (full lines or Dashed Lines Patterns)
//
//=============================================================================
// Abstract Class     : yes
//=============================================================================
//
// History
//
// January. 2012   Dominique PREVOST (DPS)    Creation    
//
//=============================================================================

#include "CATBoolean.h" 


#include "PolygonalHatching.h"        // ExportedBy

#include "CATErrorDef.h"               // HRESULT define
#include "CATListOfDouble.h"
#include "CATLISTV_CATMathPoint2D.h" 

class CATMathPoint2D;

/**
* The hatch pattern class behaves like an iterator and cycles through all
* the elements (sub-hatch patterns) composing the pattern.
*
* A sub-hatch pattern is set of parallel lines where is applied a dash mask.
* @see CATPolyHatchGenericPattern2D
*/

class ExportedByPolygonalHatching CATPolyHatchPattern2D
{

public:

 /**
  * Life Cycle Management
  * PLEASE USE derivated class (default class is CATPolyHatchGenericPattern2D) to instanciate the Pattern
  * PLEASE USE delete function TO REMOVE THE OPERATOR INSTANCE
  */
  virtual ~CATPolyHatchPattern2D() {};


public:

 /** @name Iterator Interface
  @{ */

 /**
  * Sets the iterator to the beginning.
  * Resets the iterator for a new iteration.
  * This method may be called several times.
  */
  virtual void Begin () = 0;

 /**
  * Checks if the iterator reached the end.
  */
  virtual CATBoolean End () = 0;

 /**
  * Increments the iterator.
  */
  virtual void operator++ () = 0;

 /** @} */


public:

 /** @name Accessors to the current sub-element of the pattern.
  * This current element is a SubPattern defined as a set of full lines or dashed lines patterns
  @{ */

 /**
  * returns the angle (degrees) defining the rotation to apply on the planar reference axes
  */
  virtual double GetAngle () = 0;

 /**
  * returns the planar coordinates X,Y (before rotation) to define the line support reference
  */
  virtual void GetOrigin (CATMathPoint2D& oOrigin) = 0;

 /**
  * returns the Offset values X & Y to apply (after rotation) to compute the next instance of line support
  *   Offset value X is the offset along the line reference and doesn't matter in case of full lines
  *   Offset value Y is the distance between 2 successive line support instances
  */
  virtual void GetOffset (double oOffset[2]) = 0;

 /**
  * returns the successive values of Lengths and EmptySpaces defining the dashed lines pattern
  * no value means full lines !
  * a positive value defines the length of a segment to draw (dash)
  * a null value means a dot to draw on the line support
  * a negative value defines the length of the empty space between 2 successive elements (dot or dash)
  * sample : { 3., -2., 0., -2. } means ___  .  ___  .  ___  .  ___  .  ___  .
  */
  virtual CATBoolean GetDashedLinePattern (CATListOfDouble& oDashedLinePattern) = 0;

 /** @} */

};


#endif
