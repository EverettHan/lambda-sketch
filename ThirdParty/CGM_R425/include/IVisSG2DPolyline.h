#ifndef IVISSG2DPOLYLINE_H
#define IVISSG2DPOLYLINE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG2DCurve.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DPolyline;

/** 
 * Basic class of any Scene Graph 2D Polyline.
 * <b>Role</b>: This is the basic class that any Scene Graph 2D Polyline has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DPolyline : public IVisSG2DCurve
{  
public:
};

#endif // IVISSG2DPOLYLINE_H
