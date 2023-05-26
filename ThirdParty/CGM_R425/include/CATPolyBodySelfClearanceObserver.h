// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySelfClearanceObserver.h
//
//===================================================================
//
// Usage notes:
// Observer to be notified when intersections and clearances are
// found inside a CATPolyBody
//
//===================================================================
//
// Apr 2014 Creation: JXO
//===================================================================
#ifndef CATPolyBodySelfClearanceObserver_h
#define CATPolyBodySelfClearanceObserver_h

#include "PolyBodyBVHOperators.h"

// Poly math
#include "CATPolyObserver.h"
class CATCellId;
#include "CATPolyDeprecated.h"

// Math
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"

// System
#include "CATSysBoolean.h"
#include "CATErrorDef.h"


/**
 * Observer to be notified when intersections and clearances are found inside a CATPolyBody
 */

class ExportedByPolyBodyBVHOperators CATPolyBodySelfClearanceObserver : public CATPolyObserver<CATPolyBodySelfClearanceObserver>
{
public:
  /**
   * To be implemented to be called back every time two close triangles are found in the mesh
   * @param pCellId1 Cell id of the cell the first triangle belongs to.
   * @param indext1 index of the first triangle in the CATIPolySurface
   * @param barycenter1 one of the geometric points on first triangle, closest to the second triangle,
   *                    in barycentric coordinates u, v, w inside first triangle
   * @param pCellId2 Cell id of the cell the second triangle belongs to.
   * @param indext2 index of the second triangle in the CATIPolySurface
   * @param barycenter2 one of the geometric points on second triangle, closest to the first triangle,
   *                    in barycentric coordinates u, v, w inside second triangle
   * @param distance Minimum distance between the two triangles
   */
  virtual void AddClearance(CATCellId * pCellId1, int indext1, const CATMathPoint & barycenter1,
                            CATCellId * pCellId2, int indext2, const CATMathPoint & barycenter2,
                            double distance) = 0;
  /**
   * To be implemented to be called back every time a new self intersection is found.
   * @param pCellId1 Cell id of the cell the first triangle belongs to.
   * @param indext1 index of the first triangle in the CATIPolySurface
   * @param pCellId2 Cell id of the cell the second triangle belongs to.
   * @param indext2 index of the second triangle in the CATIPolySurface
   */
  virtual void AddIntersection(CATCellId * pCellId1, int indext1,
                               CATCellId * pCellId2, int indext2,
                               const CATLISTV(CATMathPoint) & intersection) = 0;

  /**
   * @deprecated CATIAR418 CATProgressCallback
   * Temporary, to get feedback and to possibly stop the computation 
   * @param current current progress
   * @param total total range of progress
   * @return 1 if the computation has to stop, 0 otherwise
   */
  POLY_DEPRECATED("Use CATProgressCallback instead", virtual int Progress(int current, int total){return 0;});

protected:
  /** Default constructor, does nothing */
  CATPolyBodySelfClearanceObserver();
  /** Destructor */
  ~CATPolyBodySelfClearanceObserver();
};

#endif // CATPolyBodySelfClearanceObserver_H

