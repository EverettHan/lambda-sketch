#ifndef CATPolyPathSmoothingObserver_h
#define CATPolyPathSmoothingObserver_h

// ExportedBy
#include "PolyBodyBVHOperators.h"

// PolyhedralMathematics
#include "CATRefCounted.h"

class CATPolyPPPath;

class ExportedByPolyBodyBVHOperators CATPolyPathSmoothingObserver : public CATRefCounted
{
public:

 /* Called before first run */
 virtual void SetPath(const CATPolyPPPath & iPath) = 0;

 /* -1 means only one big call */
 virtual void RanSmoothing(const CATPolyPPPath & oPath, int percent = -1) = 0;

};

#endif

