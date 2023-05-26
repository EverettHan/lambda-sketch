#ifndef CATPolyHatchResultIter2D_H
#define CATPolyHatchResultIter2D_H


//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2011
//
// CATPolyHatchResultIter2D
//
// DESCRIPTION :
//
//               Hatching iterator to get all the dots and dashes
//               computed from a HatchPattern inside a polygonal face
//
//=============================================================================
// Abstract Class     : YES
//
// History
//
// December. 2011   Dominique PREVOST (DPS)    Creation    
//
//=============================================================================

#include "PolygonalHatching.h"        // ExportedBy
 
#include "CATBoolean.h"

class CATMathPoint2D;
class CATPolyHatchResult2D;
class CATPolyHatchSubResultIter2D;


/**
* Class defining the iterator that returns all the hatching dots and dashes
*<ul>
* <li>CATPolyHatchResultIter2D is created with the <tt>CATPolyHatchResultIter2D</tt> constructor method.
* It can be reused several times thanks to the <tt>Begin</tt> method
* It must be directly removed with the <tt>delete</tt> method after use.
* It is not streamable.
* @see CATPolyHatchResult2D
*/

class ExportedByPolygonalHatching CATPolyHatchResultIter2D
{

public:

 /**
  *  Life Cycle Management
  */
  CATPolyHatchResultIter2D(const CATPolyHatchResult2D & iHatchResult, CATBoolean iSkipDots=FALSE, CATBoolean iSkipDashes=FALSE);
  ~CATPolyHatchResultIter2D();


public:

 /** @name Iterator Interface
  @{ */

 /**
  * Resets the iterator for a new iteration through the dots and dashes.
  * This method may be called several times.
  */
  virtual void Begin ();

  virtual CATBoolean End ();

  virtual void operator++ ();

 /** @} */


public:

 /** @name Accessors to the elements composing the result.
  @{ */

 /**
  * Returns the dimension of the element:
  * <ul>
  *   0 Dot
  *   1 Dash.
  * </ul>
  */
  int GetDimension();

 /**
  * Returns a dot element.
  */
  void GetDot (CATMathPoint2D& oDot);

 /**
  * Returns a dash element defined by its two extremities.
  */
  void GetDash (CATMathPoint2D& oDashStart, CATMathPoint2D& oDashEnd);


private :
  
  const CATPolyHatchResult2D  & _HatchResult;

  CATPolyHatchSubResultIter2D * _SubResultIter;

  unsigned int                  _HatchCursor;

  CATBoolean                    _SkipDots;
  CATBoolean                    _SkipDashes;
};

#endif
