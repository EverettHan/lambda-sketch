// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarsSpatialPartitionOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  mar 2004 Creation: dhp
// juin 2009 zfi
//===================================================================

#ifndef CATPolyBarsSpatialPartitionOper_H
#define CATPolyBarsSpatialPartitionOper_H

#include "CATPolyBaseSpatialPartitionOper.h"

#include "CATListOfInt.h"

#include "CATListPV.h"

#include "CATMathPoint.h"
#include "CATMathBox.h"

#include "PolyBodyBuilders.h"


class CATIPolyMesh;
class CATPolyBars;
class PartitionCell;
class CATCGMOutput;

class ExportedByPolyBodyBuilders CATPolyBarsSpatialPartitionOper : public CATPolyBaseSpatialPartitionOper
{
  
public :
  CATPolyBarsSpatialPartitionOper (const int sizeX,
                                   const int sizeY,
                                   const int sizeZ);

  ~CATPolyBarsSpatialPartitionOper ();

  //build
  HRESULT Set (const CATIPolyMesh * iPolyMesh,
               const CATPolyBars* iPolyBars);

  HRESULT AddVerticesAndBars (const CATIPolyMesh * iPolyMesh,
                              const CATPolyBars* iPolyBars);

  HRESULT AddVertices(const CATIPolyMesh* iPolyMesh, 
                      const CATListOfInt& iVertices);
  
  HRESULT AddBar(const int iIdxBar);
  HRESULT RemoveBar(const int iIdxBar);
  
  HRESULT AddVertex(const int iIdxVertex);
  HRESULT RemoveVertex(const int iIdxVertex);

  //get results
  HRESULT GetBarCells (const int iBar,
                       CATListOfInt & cellsX,
                       CATListOfInt & cellsY,
                       CATListOfInt & cellsZ) const;

  HRESULT GetVertices (const int iVertex,
                       const double iDistance,
                       CATListOfInt & oVerticesList) const;

  HRESULT GetBars (const int iVertex,
                   const double iDistance,
                   CATListOfInt & oBarsList) const;

  HRESULT GetClosestVertexToPosition(const CATMathPoint& iP,
                                     const double iMaxDistance,
                                     int& oVertexIndex)const;
  //inherited
private:
  CATBoolean CleanupCell (void* cell);

private:
  //build
  HRESULT BuildVertices();
  HRESULT BuildVertices(const CATListOfInt& iVertices);
  HRESULT BuildBars();

private:
  const CATIPolyMesh* _PolyMesh;
  const CATPolyBars* _PolyBars;
};
#endif
