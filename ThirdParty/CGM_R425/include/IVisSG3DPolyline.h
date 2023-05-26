#ifndef IVISSG3DPOLYLINE_H
#define IVISSG3DPOLYLINE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DCurve.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DPolyline;

/** 
 * Basic class of any Scene Graph 3D Polyline.
 * <b>Role</b>: This is the basic class that any Scene Graph 3D Polyline has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DPolyline : public IVisSG3DCurve
{  
public:
};

#endif // IVISSG3DPOLYLINE_H
