// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.

#include "CATIAV5Level.h"
#ifdef CATIAR420

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)

#include "PolyBodyDecimate.h"
#include "CATSysErrorDef.h"

class CATPolyPolygon2D;

/* Decimate the outline of a 2D polygon. The output geometry may have self-intersections.
   Using a CATPolyBooleanOper2D with CATPolyBooleanOper2DBase::eBooleanNone is one way of
   resolving self-intersections. */
ExportedByPolyBodyDecimate HRESULT DecimateOutline(CATPolyPolygon2D &ioProjection, double iSag);

#endif //(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)

#endif //CATIAR420
