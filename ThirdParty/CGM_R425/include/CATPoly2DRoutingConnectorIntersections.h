// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPoly2DRoutingConnectorIntersections.h
//
//===================================================================
//
// Usage notes: Graph tool to draw 2D routing of cables (connectors)
//              between boxes.
//              Intersections between connectors
//
//===================================================================
//
// May 2011 Creation: JXO
//===================================================================

#ifndef CATPoly2DRoutingConnectorIntersections_h
#define CATPoly2DRoutingConnectorIntersections_h

#include "Poly2DRouting.h"

// Poly
#include "CATPolyRefCounted.h"
#include "CATPoly2DRouting.h"

// System
#include "CATBoolean.h"
#include "CATDataType.h"

// Math
#include "CATMathPoint2D.h"


/**
 * Graph tool to draw 2D routing of cables (connectors) between boxes.
 * Intersections between connectors.
 * This class is an iterator along all the intersections a connector 
 * may have with other connectors.
 */

class ExportedByPoly2DRouting CATPoly2DRoutingConnectorIntersections : public CATPolyRefCounted
{
public:
  /**
   * Main connector id.
   */
  virtual unsigned int GetConnectorId() const = 0;
  /**
   * Return the number of intersection along this connector segment.
   */
  virtual unsigned int GetNbOfIntersections() const = 0;
  /**
   * Begin the iterator.
   */
  virtual void Begin() = 0;
  /**
   * Return true if we are at the end of the iterator (no more intersections)
   */
  virtual CATBoolean End() const = 0;
  /**
   * Iterate.
   */
  virtual void operator++() = 0;

  /**
   * Intersection:
   */
  virtual CATMathPoint2D GetPoint() = 0;
  /**
   * Return the id of the other connector
   */
  virtual unsigned int GetOtherConnectorId() = 0;
  /**
   * Return the orientation of this segment
   * (for example to draw a little bridge)
   * @return
   *        0: horizontal
   *        1: Vertical
   */
  virtual int GetOrientation() = 0;

protected:
  /**
   * Constructor
   */
  CATPoly2DRoutingConnectorIntersections(){}
  /**
   * Destructor
   */
  virtual ~CATPoly2DRoutingConnectorIntersections(){}

};

#endif /* CATPoly2DRoutingConnectorIntersections_h */
