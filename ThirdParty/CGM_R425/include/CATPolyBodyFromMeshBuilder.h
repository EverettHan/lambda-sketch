//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBodyFromMeshBuilder.h
//
//=============================================================================
// 2009-02-12 ZFI
//=============================================================================

#ifndef CATPolyBodyFromMeshBuilder_H
#define CATPolyBodyFromMeshBuilder_H

#include "PolyBodyBuilders.h"
#include "CATErrorDef.h" 

class CATIPolyMesh;
class CATPolyBody;
class CATPolySegmentLayer;
class CATPolyBodyGeometryLayer;
class CATMapOfPtrToInt;

class ExportedByPolyBodyBuilders CATPolyBodyFromMeshBuilder
{
public:
  enum SegmentationType
  {
    NormalsAndTextureCoordsDiscontinuity,
    FrontSegmentation    
  };

public:

	CATPolyBodyFromMeshBuilder (int iSegmentationType);
	~CATPolyBodyFromMeshBuilder ();

public:
  HRESULT Run (CATIPolyMesh& iMesh, CATPolyBody*& oPolyBody, CATPolyBodyGeometryLayer* ioGeometryLayer=0) const;

private:
  HRESULT FillGeometryLayer(const CATMapOfPtrToInt& iMapCellToSupportId, 
                            const CATPolySegmentLayer& iSegmentLayer, 
                            CATPolyBodyGeometryLayer& ioGeometryLayer) const;
 
private:
  int _SegmentationType;


};

#endif 
