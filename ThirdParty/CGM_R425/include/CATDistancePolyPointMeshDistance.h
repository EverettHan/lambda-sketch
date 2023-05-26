//==========================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2007
//==========================================================================================
//
//==========================================================================================
// Jan 09 Creation                                    MPX
//==========================================================================================

#ifndef CATDistancePolyPointMeshDistance_H
#define CATDistancePolyPointMeshDistance_H


#include "DistanceLight.h"
#include "CATPolyPointTriangleDistance.h"
#include "CATBoolean.h"


class CATMathPoint;
class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;

class ExportedByDistanceLight CATDistancePolyPointMeshDistance
{
public:
  static CATDistancePolyPointMeshDistance* New(CATIPolyMesh& iMesh, CATIPolyMeshTriangleIterator &iTriangleIt);
  virtual ~CATDistancePolyPointMeshDistance();

  virtual HRESULT Run(
            double iResolutionForLengthTest, 
            double iEpsilonForLengthTest,
            const CATMathPoint& iP,
            CATIPolyMesh& iMesh,
            CATIPolyMeshTriangleIterator &iTriangleIt
            ) = 0;
  virtual HRESULT Run(
            double iResolutionForLengthTest, 
            double iEpsilonForLengthTest,
            const CATMathPoint& iP
            ) = 0;

  virtual int GetTriangle() = 0;
  virtual const CATPolyPointTriangleDistance::Result& GetTriangleDistanceResult() = 0;

protected:
  virtual CATBoolean Initialize(CATIPolyMesh& iMesh, CATIPolyMeshTriangleIterator &iTriangleIt) = 0;

public:
  class ExportedByDistanceLight Creator
  {
  public:
    virtual CATDistancePolyPointMeshDistance* Create() const = 0;
    static void Register(const Creator* iCreator);
    static const Creator* Get();
  protected:
    static const Creator* _pCreator;
  };
};


#endif

