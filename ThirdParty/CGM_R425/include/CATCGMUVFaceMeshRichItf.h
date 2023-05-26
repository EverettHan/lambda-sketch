#ifndef CATCGMUVFaceMeshRichItf_H
#define CATCGMUVFaceMeshRichItf_H

#include "ExportedByTessellateCommon.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfULONG32.h"
#include "CATCGMUVFaceMeshBasicItf.h"


class CATFace;
class CATEdge;
class CATVertex;
class CATCGMUVParamSubdivision1D;


class ExportedByTessellateCommon CATCGMUVFaceMeshRichItf : public CATCGMUVFaceMeshBasicItf
{
public:
  virtual ~CATCGMUVFaceMeshRichItf();
public:

  /////////////////////////////////////////////
  // Vertex Geometry data
  /////////////////////////////////////////////

  // Face param grid in the form of compressed subdivision 
  virtual CATBoolean IsSurfParamSubdivisionAvailable() const {return FALSE;}
  virtual HRESULT GetSurfParamSubdivision(CATCGMUVParamSubdivision1D& oParamSubdivisionU, CATCGMUVParamSubdivision1D& oParamSubdivisionV) const {return E_FAIL;}

  //2d position on grid
  // iVIdx should be between 0 and (GetNbVertices() - 1)
  // oI should be between 0 and (NbUGrids - 1), where NbUGrids is the number of grid points in oParamSubdivisionU
  // oJ should be between 0 and (NbVGrids - 1), where NbVGrids is the number of grid points in oParamSubdivisionV
  // oLocation: 0= on grid node, 1=internal (mid-pt of rectagular grid, oI oJ gives left-down node), 2=unknown.
  virtual HRESULT GetPositionOnGrid(CATULONG32 iVIdx, CATULONG32& oI, CATULONG32& oJ, CATULONG32& oLocation) const {return E_FAIL;}

  /////////////////////////////////////////////
  // Triangle data
  /////////////////////////////////////////////

  // iTriangleIdx should be between 0 and (GetNbTriangles() - 1)
  // iCornerNumber should be either 0, 1 or 2
  // Should return S_FALSE if no opposite corner
  virtual HRESULT GetOppositeCorner(
                        CATULONG32 iTriangleIdx,             // index of given triangle
                        unsigned char iCornerNumber,         // index of given corner, either 0, 1 or 2
                        CATULONG32& oOppositeTriangleIdx,    // index of opposite triangle
                        unsigned char& iOppositeCornerNumber  // index of opposite corner, either 0, 1 or 2
                        ) const = 0;

  // iVIdx should be between 0 and (GetNbTriangles() - 1)
  // Indices in oListOfTriangles should be between 0 and (GetNbTriangles() - 1)
  virtual HRESULT GetTrianglesAroundVertex(CATULONG32 iVIdx, CATListOfULONG32& oListOfTriangles) const = 0;

public:

  /////////////////////////////////////////////
  // Not to be implemented by derived class
  /////////////////////////////////////////////

  // iTriangleIdx should be between 0 and (GetNbTriangles() - 1)
  // iCornerNumber should be either 0, 1 or 2
  // Should return S_FALSE if no opposite corner
  HRESULT GetOrientedOppositeCorner(
                        CATBoolean iAlignWithCATSurface,
                        CATULONG32 iTriangleIdx,             // index of given triangle
                        unsigned char iCornerNumber,         // index of given corner, either 0, 1 or 2
                        CATULONG32& oOppositeTriangleIdx,    // index of opposite triangle
                        unsigned char& iOppositeCornerNumber  // index of opposite corner, either 0, 1 or 2
                        ) const;

public:

  /////////////////////////////////////////////
  // Not to be implemented by derived class
  /////////////////////////////////////////////

  // For debugging. Checks for mesh correctness with regards to:
  // 1. Oppositecorners
  // 2. Compressed param subdivision of edge curves
  virtual HRESULT CheckMeshCorrectness() const;

protected:

  HRESULT CheckOppositeCorners() const;
  HRESULT CheckCurveParamSubdivision() const;
  HRESULT CheckSurfParamSubdivision() const;

};

#endif 

