#ifndef IVISSG3DBODY_H
#define IVISSG3DBODY_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DPrimitiveIterator.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DBody;

class IVisSGPrimitive;

class ExportedByVisSceneGraph IVisSG3DBody : public IVisSG3DPrimitiveIterator
{
public:

  typedef enum _VisSG3DBodyCellType
  {
    VisSGBoundaryEdge,
    VisSGInternalSharpEdge,
    VisSGInternalSmoothEdge,
    VisSGBoundaryPoint,
    VisSGInternalSharpPoint,
    VisSGInternalSmoothPoint,
    VisSGSurfacicPoint,
    VisSGFreePoint,
    VisSGWireEdge,
    VisSGInfiniteFace,
    VisSGFace,
    VisSGV4Edge,
    VisSGUnknownType
  } VisSG3DBodyCellType;

  virtual HRESULT GetNumberOfCells(VisSG3DBodyCellType iType, VisSize& oNbPrimitives) = 0;
  virtual HRESULT GetCell(VisSG3DBodyCellType iType, VisSize iCellIndex, IVisSGPrimitive * & oPrimitive) = 0;
  virtual HRESULT AddCell(VisSG3DBodyCellType iType, IVisSGPrimitive *iPrimitive) = 0;
};

#endif
