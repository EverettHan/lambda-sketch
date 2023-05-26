// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyConverter.h
// Header definition of CATPolyBodyConverter
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2008 Creation: MNA
//===================================================================
#ifndef CATPolyBodyConverter_H
#define CATPolyBodyConverter_H

#include "PolyImportExport.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATIPolyMesh;
class CATPolyMeshVertexNNormalsLayer;
class CATPolySurfaceFacetSupportLayer;
class CATPolyMeshTriangleVizLayer;
class CATIPolyMeshTriangleIterator;
class CATPolyBars;
class CATPolyBarsBarSupportLayer;
class CATPolyBarsBarVizLayer;
class CATPolyVizContainer;

class CATMapOfPtrToInt;


class ExportedByPolyImportExport CATPolyBodyConverter
{

public:

  CATPolyBodyConverter () {}
  ~CATPolyBodyConverter () {}

public:

  HRESULT BuildPolyBodyFromPolyMesh (const CATIPolyMesh& iMesh,
                                     const CATPolyMeshVertexNNormalsLayer* iNormalLayer,
                                     const CATPolyMeshTriangleVizLayer* iTriangleVizLayer,
                                     const CATPolyBars* iBars,
                                     const CATPolyBarsBarVizLayer* iBarVizLayer,                                                           
                                     CATPolyBody*& oPolyBody);
  
  HRESULT BuildPolyBodyFromPolyMesh (const CATIPolyMesh& iMesh,
                                     const CATPolyMeshVertexNNormalsLayer* iNormalLayer,
                                     const CATPolyMeshTriangleVizLayer* iTriangleVizLayer,
                                     const CATPolyBars* iBars,
                                     const CATPolyBarsBarVizLayer* iBarVizLayer, 
                                     const CATPolyBarsBarSupportLayer* iBarClipLayer,
                                     CATPolyBody*& oPolyBody,
                                     CATMapOfPtrToInt*& oMapFromPolyCellToVizKey,
                                     CATMapOfPtrToInt*& oMapFromPolyCellToClipKey);

public: 

  HRESULT Build (const CATIPolyMesh& iMesh,
                 const CATPolyMeshVertexNNormalsLayer* iNormalLayer,
                 const CATPolySurfaceFacetSupportLayer* iTriangleVizLayer,
                 const CATPolyBars* iBars,
                 const CATPolyBarsBarSupportLayer* iBarVizLayer, 
                 const CATPolyBarsBarSupportLayer* iBarClipLayer,
                 const CATPolyVizContainer* iVizContainer,
                 CATPolyBody*& oPolyBody,
                 CATMapOfPtrToInt*& oMapFromPolyCellToVizKey,
                 CATMapOfPtrToInt*& oMapFromPolyCellToClipKey);

private:

  HRESULT BuildPrivate (const CATIPolyMesh& iMesh,
                        const CATPolyMeshVertexNNormalsLayer* iNormalLayer,
                        const CATPolySurfaceFacetSupportLayer& iTriangleVizLayer,
                        const CATPolyBars& iBars,
                        const CATPolyBarsBarSupportLayer& iBarVizLayer, 
                        const CATPolyBarsBarSupportLayer* iBarClipLayer,
                        const CATPolyVizContainer* iVizContainer,
                        CATPolyBody*& oPolyBody,
                        CATMapOfPtrToInt*& oMapFromPolyCellToVizKey,
                        CATMapOfPtrToInt*& oMapFromPolyCellToClipKey);

};

#endif
