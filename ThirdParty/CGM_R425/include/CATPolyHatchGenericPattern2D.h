/* -*-C++-*-*/
#ifndef CATPolyHatchGenericPattern2D_H
#define CATPolyHatchGenericPattern2D_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATPolyHatchGenericPattern2D
//
// DESCRIPTION :
//
//    Implementation of a Generic Hatch Pattern,
//    composed by a set fo Hatch SubPatterns (full lines or Dashed Lines Patterns)
//
//=============================================================================
// Abstract Class     : No
//=============================================================================
//
// History
//
// February. 2012   Dominique PREVOST (DPS)    Creation    
//
//=============================================================================

#include "CATPolyHatchPattern2D.h"     // derivation
#include "PolygonalHatching.h"         // ExportedBy

#include "CATBoolean.h"
#include "CATErrorDef.h"               // HRESULT define
#include "CATListOfDouble.h"

class CATPolyHatchSubPattern2D;
class CATMathPoint2D;

/**
* Class defining a generic polyhedral Hatch Pattern, as a set of SubPatterns.
* Each SubPattern is itself a layer of dashed line pattern to apply on a set of lines
* <li>CATPGMGenericHatchPattern is created with the <tt>CATPGMCreateGenericHatchPattern</tt> global function.
* It can be reused for different Hatching computations.
*/

class ExportedByPolygonalHatching CATPolyHatchGenericPattern2D : public CATPolyHatchPattern2D
{

public:

 /**
  * Life Cycle Management
  */
  CATPolyHatchGenericPattern2D();
  virtual ~CATPolyHatchGenericPattern2D();

  
public:

 /** @name Accessors to define the current sub-element of the pattern.
  * This current element is a SubPattern defined as a set of full lines or dashed lines patterns
  @{ */

 /**
  * Adds and defines a new SubPattern of a Hatch Pattern
  * This SubPattern is a pattern of full lines or dashed lines patterns
  * @param iAngle
  *   angle (degrees) defining the rotation to apply on the planar reference axes
  * @param iOrigin
  *   planar coordinates X, Y (before rotation) to define the line support reference
  * @param iOffset
  *   Offset values X & Y to apply (after rotation) to compute the next instance of line support
  *   Offset value X is the offset along the line reference and doesn't matter in case of full lines
  *   Offset value Y is the distance between 2 successive line support instances
  * @param iDashedLinePattern
  *   successive values of Lengths and EmptySpaces to define the dashed lines pattern
  *   no value means full lines !
  *   a positive value defines the length of a segment to draw (dash)
  *   a null value means a dot to draw on the line support
  *   a negative value defines the length of the empty space between 2 successive elements (dot or dash)
  *   sample : { 3., -2., 0., -2. } means ___  .  ___  .  ___  .  ___  .  ___  .
  */
  virtual void AddHatchSubPattern(double iAngle, CATMathPoint2D &iOrigin, double iOffset[2], CATListOfDouble &iDashedLinePattern);

 /** @} */


public:

 /** @name Iterator Interface
  @{ */

 /**
  * Sets the iterator to the beginning.
  * Resets the iterator for a new iteration.
  * This method may be called several times.
  */
  virtual void Begin ();

 /**
  * Checks if the iterator reached the end.
  */
  virtual CATBoolean End ();

 /**
  * Increments the iterator.
  */
  virtual void operator++ ();

 /** @} */


public:

 /** @name Accessors to the current sub-element of the pattern.
  * This current element is a SubPattern defined as a set of full lines or dashed lines patterns
  @{ */

 /**
  * returns the angle (degrees) defining the rotation to apply on the planar reference axes
  */
  virtual double GetAngle ();

 /**
  * returns the planar coordinates X,Y (before rotation) to define the line support reference
  */
  virtual void GetOrigin (CATMathPoint2D& oOrigin);

 /**
  * returns the Offset values X & Y to apply (after rotation) to compute the next instance of line support
  *   Offset value X is the offset along the line reference and doesn't matter in case of full lines
  *   Offset value Y is the distance between 2 successive line support instances
  */
  virtual void GetOffset (double oOffset[2]);

 /**
  * returns the successive values of Lengths and EmptySpaces defining the dashed lines pattern
  * no value means full lines !
  * a positive value defines the length of a segment to draw (dash)
  * a null value means a dot to draw on the line support
  * a negative value defines the length of the empty space between 2 successive elements (dot or dash)
  * sample : { 3., -2., 0., -2. } means ___  .  ___  .  ___  .  ___  .  ___  .
  */
  virtual CATBoolean GetDashedLinePattern (CATListOfDouble& oDashedLinePattern);

 /** @} */


private :

  // Internal Data
  // -------------
  unsigned int                   _IterCursor;
  unsigned int                   _NbSubPatterns;
  CATPolyHatchSubPattern2D    ** _SubPatternTab;
  CATPolyHatchSubPattern2D     * _CurSubPattern;

};

// inline methods
// ==============

#endif
