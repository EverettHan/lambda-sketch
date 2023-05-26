// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyContourOper.h
//
//===================================================================
//
// Usage notes: Compute the contour and the neighbors of a subset
//              refrenced in CATIPolyIntegerSetPartition. Using 
//              topology contained in CATIPolySurface
//
//===================================================================
//
// June 2008  Creation: ZFI
//===================================================================


// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// PLEASE, SEE ALSO CATPolySurfaceBorderLoopsExtractor.h in PolyhedralObjects\ProtectedInterfaces
// TO USE INSTEAD OF THIS ONE.
// This alternative service manages efficiently tricky configurations with Non Manifold border vertices 
// and leads to a predictable and robust result
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*


#ifndef CATPolyContourOper_H
#define CATPolyContourOper_H

#include "CATPolySegmentCommon.h"
#include "CATErrorDef.h"

class CATIPolySurfaceFacetIterator;
class CATPolyIntegerSetPartition;
class CATPolySegmentLayer;
class CATIPolySurface;
class CATIPolySurfaceVertexFacetNeighborhood;

class CATIPolyIntegerSetParitition;
class CATIPolySurface;
class CATPolyContour;

class ExportedByCATPolySegmentCommon CATPolyContourOper
{
public:
  CATPolyContourOper(CATIPolySurface& iMesh, const CATPolyIntegerSetPartition* iPartition=0);
  virtual ~CATPolyContourOper();

public:
  HRESULT GetSubSetContour(int iIdxSubSet, CATPolyContour*& oContour) const;
  HRESULT GetContour(CATPolyContour*& oContour) const;

private:
  const CATPolyIntegerSetPartition* _Partition;
  
  CATIPolySurface& _Mesh;
  CATIPolySurfaceVertexFacetNeighborhood* _VertexFacetNeighborhood;

};

#endif
