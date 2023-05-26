#ifndef CATVizMetaClassBase_H
#define CATVizMetaClassBase_H

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "SGInfra.h"
#define CATVIZMETAEXPORT ExportedBySGInfra
#include "CATVizMacForMetaClass.h"

// Base meta object
CATVizDeclareMeta(CATVizMetaUnknown);

// All primitives are of this type
CATVizDeclareMeta(CATVizMetaPrimitive);

// base for dynamic primitive
CATVizDeclareMeta(CATVizMetaDynamic);

// 3D primitives
CATVizDeclareMeta(CATVizMeta3DPrimitive);
CATVizDeclareMeta(CATVizMetaBounding);
CATVizDeclareMeta(CATVizMetaFace);
CATVizDeclareMeta(CATVizMetaEdge);
CATVizDeclareMeta(CATVizMetaCurve);
CATVizDeclareMeta(CATVizMetaPoint);

// Other 3D primitives
CATVizDeclareMeta(CATVizMetaLight);
CATVizDeclareMeta(CATVizMetaFixedPlan);

// 2D primitive
CATVizDeclareMeta(CATVizMeta2DPrimitive);
CATVizDeclareMeta(CATVizMeta2DCurve);
CATVizDeclareMeta(CATVizMeta2DPoint);

#undef CATVIZMETAEXPORT

#endif
