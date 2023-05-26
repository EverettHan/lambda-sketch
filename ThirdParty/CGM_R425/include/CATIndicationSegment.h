#ifndef CATIndicationSegment_H
#define CATIndicationSegment_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATMathPoint.h"
#include "CATMathPointf.h"
#include "CATBaseUnknown.h"

#include "CATVisFoundation.h"

/**
 * Class to define the line segment under the mouse cursor in a 3D viewpoint.
 * <b>Role</b>: This class stores in its public data members <tt>pt1</tt> and <tt>pt2</tt>
 * the extremities of the line segment located under the mouse cursor.
 * This class is used by dialog objects when making a query to a manipulator.
 */
class ExportedByCATVisFoundation CATIndicationSegment : public CATBaseUnknown
{
  public :
  /** Constructor of an empty 2D indication segment. */
  CATIndicationSegment();

  /** Constructor of a 2D indication segment.
   * @param iNearPoint
   * Nearest extremity of the segment.
   * @param iFarPoint
   * Farthest extremity of the segment.
   */
  CATIndicationSegment (CATMathPoint iNearPoint, CATMathPoint iFarPoint);

  /** Constructor of a 2D indication segment.
   * @param iNearPoint
   * Nearest extremity of the segment.
   * @param iFarPoint
   * Farthest extremity of the segment.
   */
  CATIndicationSegment (CATMathPointf iNearPoint, CATMathPointf iFarPoint);

  /** Copy constructor. */
  CATIndicationSegment(const CATIndicationSegment & iIndicationSegment);

  /** Assignement operator. */
  CATIndicationSegment & operator=(const CATIndicationSegment & iIndicationSegment);

 /** @nodoc */
  CATMathPoint  pt1; // nearest extremity
 /** @nodoc */
  CATMathPoint  pt2; // farthest extremity

  /** @nodoc */
  static const char * ClassName();

  protected :
  static const char * _className;
};

#endif // CATIndicationSegment_H
