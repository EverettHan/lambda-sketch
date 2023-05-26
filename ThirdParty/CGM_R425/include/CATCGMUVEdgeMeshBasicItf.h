#ifndef CATCGMUVEdgeMeshBasicItf_H
#define CATCGMUVEdgeMeshBasicItf_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATEdge;
class CATCGMUVParamSubdivision1D;
class CATMathBox;

class ExportedByTessellateCommon CATCGMUVEdgeMeshBasicItf
{
public:
  virtual ~CATCGMUVEdgeMeshBasicItf();

public:

  virtual CATEdge& GetEdge() const = 0;


  virtual CATULONG32 GetNbVertices() const = 0; 

  virtual CATBoolean AreCoordsAvailable() const = 0;

  // iVIdx should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetCoords(CATULONG32 iVIdx, double& oX, double& oY, double& oZ) const = 0;
  
  //bounding box
  virtual HRESULT GetCoordsBoundingBox(CATMathBox& oBoundingBox)const{return E_FAIL;}

  virtual CATBoolean AreTangentsAvailable() const = 0;

  // iVIdx should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetTangent(CATULONG32 iVIdx, double& oX, double& oY, double& oZ) const = 0;

  virtual CATBoolean AreCurveParamsAvailable() const = 0;

  // iVIdx should be between 0 and (GetNbVertices() - 1)
  virtual HRESULT GetCrvParam(CATULONG32 iVIdx, double& oW) const = 0;

  virtual CATBoolean IsCrvParamSubdivisionAvailable() const = 0;

  // get curve params in the form of compressed subdivision 
  virtual HRESULT GetCrvParamSubdivision(CATCGMUVParamSubdivision1D& oParamSubdivision) const = 0;

  //zfi->perfo -> to be defined to officialized
  //virtual HRESULT GetCrvParamSubdivision(const unsigned char*& oSubdivBuffer, CATULONG32& oSubdivBufferSize, int& oSens) const{return E_FAIL;}
  //virtual HRESULT GetGeometry(CATBoolean iGetPositions, CATULONG32& oNbPositions, const double*& oPositions,
  //                            CATBoolean iGetTangents, CATULONG32& oNbTangents, const double*& oTangents,
  //                            CATBoolean iGetWs, CATULONG32& oNbWs, const double*& oWs,
  //                            CATBoolean& oReleaseAlloc)const{return E_FAIL;}

  virtual CATCGMUVEdgeMeshBasicItf* GetCopy() const;

public:

  // for internal use

  /////////////////////////////////////////////
  // Not necessary to be implemented by derived class
  /////////////////////////////////////////////

  // For debugging. Checks for mesh correctness with regards to:
  // 1. Compressed param subdivision
  virtual HRESULT CheckMeshCorrectness() const;

  virtual HRESULT GetCoordsUsingEval(CATULONG32 iVIdx, double& oX, double& oY, double& oZ) const;

protected:

  HRESULT CheckParamSubdivision() const;

};

#endif 

