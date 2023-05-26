#ifndef CATGraphicElementIntersection_h
#define CATGraphicElementIntersection_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisItf.h"
#include "CATBaseUnknown.h"

#include "CATMathPoint.h"



/**
 * Class representing the intersection point coordinates when picking one object.
 * Used by @href CATGraphicPathElement to store information of the selection
 * <br>intersection point on a graphic element.
 * <br>Uses the @href #point variable to set/get intersection coordinates values.
 *
 * @see CATGraphicPathElement
 */
class ExportedByCATVisItf CATGraphicElementIntersection : public CATBaseUnknown
{
  CATDeclareClass;

  public :

  /**
  * Default constructor .
  *
  * @param iIntersectionPoint
  *        The intersection point on graphic element.
  */
  CATGraphicElementIntersection (CATMathPoint iIntersectionPoint);


  virtual ~CATGraphicElementIntersection ();

  /**
  * The intersection point on graphic element.
  */
  CATMathPoint  point;

  /**
   * the triangle number that has been selected
   * positive value means this number can be interpreted as a triangle number.
   * negative value means this value has no meaning.
   */
  int _TriangleNumber;
  
};

#endif
