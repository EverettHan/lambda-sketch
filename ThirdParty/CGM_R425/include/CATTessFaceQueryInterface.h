#ifndef CATTessFaceQueryInterface_H
#define CATTessFaceQueryInterface_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "TessAPI.h"
#include "CATBoolean.h"
#include "CATDataType.h"
class CATMathVector;
class CATFace;
class CATEdge;
class CATVertex;

// This is as a pure virtual base class that acts as a query interface for seeking information 
// on known tessellation of a CATFace. The application should derive from this class and provide 
// the implementation. This can be used by the application to convey information about known 
// tessellation of a CATFace to CATTessellate (method AddFaceKnown), in the context of incremental 
// tessellation in CATTessIncrModePropagation mode.
// Note that the orientation of triangles should be with respect to CATSurface of the CATFace
// (i.e. in the same way as the convention in CATTessStore)

class ExportedByTessAPI CATTessFaceQueryInterface
{
public:

  CATTessFaceQueryInterface();
  virtual ~CATTessFaceQueryInterface();

  virtual CATFace* GetFaceInQuestion() const = 0;

  // Queries for tessellation points

  virtual int GetNumberOfPoints() const = 0;

  virtual void GetPtCoord(
                int iNumPoint,  // numbering starts with 0
                double oPtCoord[3]
                ) const = 0;

  virtual void GetSurfParam(
                int iNumPoint,  // numbering starts with 0
                double oSurfParam[2]
                ) const = 0;
  
  virtual void GetNormal(
                int iNumPoint,  // numbering starts with 0
                CATMathVector & oNormal
                ) const = 0;

  // Queries for isolated triangles
  
  virtual int GetNumberOfTriangles() const = 0;
  
  virtual CATLONG32 GetTrianglePointIndex(
                int iTriangleNumber, // numbering starts with 0
                int iTrianglePointNumber // iTrianglePointNumber can be 0, 1 or 2
                ) const = 0;

  // Queries for stripes
  
  virtual int GetNumberOfStripes() const = 0;
  
  virtual int GetNumberOfPointsInStripe(
                int iStripeNumber  // numbering starts with 0
                ) const = 0;
  
  virtual CATLONG32 GetStripePointIndex(
                int iStripeNumber, // numbering starts with 0
                int iStripePointNumber  // numbering starts with 0
                ) const = 0;

  // Queries for fans
  
  virtual int GetNumberOfFans() const = 0;
  
  virtual int GetNumberOfPointsInFan(
                int iFanNumber  // numbering starts with 0
                ) const = 0;
  
  virtual CATLONG32 GetFanPointIndex(
                int iFanNumber,  // numbering starts with 0
                int iFanPointNumber  // numbering starts with 0
                ) const = 0;

  // Queries for tessellation points lying on bounding edges of the face
  
  virtual void GetNumEdgePts(
                CATEdge& iEdge, 
                CATLONG32& oNumberOfPointsOnEdge, 
                CATBoolean& oSameSens // FALSE if the sequence of points on edge is reverse w.r.t. CATEdge sense
                ) const = 0;
  
  virtual void GetEdgePt(
                CATEdge& iEdge, 
                CATLONG32 iEdgePtNumber, // numbering starts with 0
                CATLONG32& oPointNumberInFace, 
                double& oEdgeParam
                ) const = 0;

  // Query for tessellation points corresponding to vertices

  // This method already has a default implementation that internally uses the ends points of 
  // edge tessellation queried using the above interfaces. For VertexInFace case, this default
  // implementation returns oPointNumberInFace as -1 (which means "not known").

  virtual void GetVertexPt(
                CATVertex& iVertex, 
                CATLONG32& oPointNumberInFace
                ) const;
};


#endif //CATTessFaceQueryInterface_H

