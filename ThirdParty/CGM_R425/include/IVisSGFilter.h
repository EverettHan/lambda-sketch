#ifndef IVISSGFILTER_H
#define IVISSGFILTER_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGObject.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSGFilter;

/** 
 * Basic class of any filter to apply to Scene Graph Node Group.
 * <b>Role</b>: This is the basic class that any Scene Graph Filter has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSGFilter : public IVisSGObject
{  
public:

};

#endif // IVISSGFILTER_H
