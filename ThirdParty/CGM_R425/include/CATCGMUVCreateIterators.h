// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCreateIterators.h
//
//===================================================================
//
//===================================================================
//
// Dec 2013 Creation: NHD
//===================================================================
#ifndef CATCGMUVCreateIterators_H
#define CATCGMUVCreateIterators_H

#include "ExportedByTessellateCommon.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMTessPointIter.h"
#include "CATCGMTessTrianIter.h"
#include "CATCGMTessFanIter.h"
#include "CATCGMTessStripeIter.h"
#include "CATMathVector.h"

class CATTessFaceDataCache;
class CATTessVertexPositionCache;
class CATTessVertexVectorCache;
class CATTessFaceDataCache;
class CATTessCacheFanIter;
class CATTessCacheStripeIter;
class CATTessCacheTrianIter;

ExportedByTessellateCommon CATCGMTessPointIter* CreateTessCachePointIter(const CATTessFaceDataCache* iFaceCache);

ExportedByTessellateCommon CATCGMTessTrianIter*  CreateTessCacheTrianIter(const CATTessFaceDataCache* iFaceCache);

ExportedByTessellateCommon CATCGMTessFanIter*  CreateTessCacheFanIter(const CATTessFaceDataCache* iFaceCache);

ExportedByTessellateCommon CATCGMTessStripeIter*  CreateTessCacheStripeIter(const CATTessFaceDataCache* iFaceCache);

#endif


