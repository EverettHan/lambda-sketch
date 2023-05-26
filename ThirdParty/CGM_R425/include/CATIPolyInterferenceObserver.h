// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyInterferenceObserver.h
//
//===================================================================
//
// Usage notes:
// Observer interface for CATIPolyInterference.
//
//===================================================================
//
// Aug 2009 Creation: JS9
// Dec 2018 Modification JXO: TrianglesAreClashing
//===================================================================

#ifndef CATIPolyInterferenceObserver_h
#define CATIPolyInterferenceObserver_h

#include "CATPolyBoundingVolumeOperators.h"

// Interference
class CATIPolyInterference;
class CATPolyInterfDecoratedTriangle;


// Math
class CATMathPoint;

/**
 * Observer interface for CATIPolyInterference.
 */
class ExportedByCATPolyBoundingVolumeOperators CATIPolyInterferenceObserver
{
public:

  virtual ~CATIPolyInterferenceObserver() {}

  /**
   * When the observer is attached and each time a new interference is build,
   * this function is called.
   */
  virtual void ProcessInterference(CATIPolyInterference * interf) = 0;

  /**
   * When the observer is attached and each time a new couple of triangles is found intersecting,
   * this function is called.
   * The two intersections points may identical if the triangles intersect in a single point or a polygon.
   */
  virtual void TrianglesAreClashing(CATPolyInterfDecoratedTriangle & tri1,
                                    CATPolyInterfDecoratedTriangle & tri2,
                                    const CATMathPoint oPoints[2]) = 0;

protected:

  /**
   * Constructor
   */
  CATIPolyInterferenceObserver() {}
  
};

#endif // CATIPolyInterferenceObserver_h
