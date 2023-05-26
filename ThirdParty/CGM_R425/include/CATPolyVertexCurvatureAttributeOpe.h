#ifndef CATPolyVertexCurvatureAttributeOpe_h__
#define CATPolyVertexCurvatureAttributeOpe_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexCurvatureAttributeOpe.h : compute of mesh curvature at vertices
// according "Per Estimating Curvatures and Their Derivatives on TriangleMeshes"
//
//===================================================================
// 04.03.2022 : RAQ : Report corrections
// December 2017  Creation NUA
//===================================================================

#include "CATMath3x3Matrix.h"
#include "CATMath2x2Matrix.h"
#include "CATMathVector2D.h"
#include "CATMathVector.h"

// export
#include "ExportedByCATPolyFeatureLineOperator.h"

// mesh
#include "CATPolyVertexNormalAttributeOpe.h"
#include "CATPolyVoronoiWeighting.h"

// math


// stl
#include <vector>
#include <map>
#include <array>

class CATTolerance;
class CATIPolyMesh;

// per Estimating Curvatures and Their Derivatives on TriangleMeshes
CATMath3x3Matrix RotateFrameToFrame(const CATMathVector & iVec1, const CATMathVector & iVec2);
CATMath3x3Matrix RotationFromAxisAndAngle(const CATMathVector & iVec, double iCos, double iSin);

struct LocalFrame_t
{
  double m_TotalWeight;

  CATMath3x3Matrix m_Frame;
  
  CATMath2x2Matrix m_SecondFF;

//#ifdef DEBUG_MODE
//  // debug
//  double Eval(double e, double f, double g) const
//  {
//    double Result = 0.;
//   /* for (const auto & I : m_Reg)
//    {
//      double Xt = m_SecondFF(0, 0) * I[0].GetX() + m_SecondFF(0, 1) * I[0].GetY();
//      double Yt = m_SecondFF(1, 0) * I[0].GetX() + m_SecondFF(1, 1) * I[0].GetY();
//
//      Result += (Xt - I[1].GetX()) * (Xt - I[1].GetX()) + (Yt - I[1].GetY()) * (Yt - I[1].GetY());
//    }*/
//    return Result;
//  }
//#endif

  LocalFrame_t() : m_TotalWeight(0.), m_SecondFF(0., 0., 0., 0.) {}
};

class ExportedByCATPolyFeatureLineOperator CATPolyVertexCurvatureAttributeOpe
{
public:

    CATPolyVertexCurvatureAttributeOpe(const CATIPolyMesh & iMesh, const CATTolerance & iTol, const CATBoolean iEnableTolerantMode = FALSE)
        : m_VertexNormalOpe(iMesh, iTol)
        , m_Tol(iTol)
        , m_Weighter(iMesh, iTol)
        , m_Mesh(iMesh)
        , m_EnableTolerantMode(iEnableTolerantMode)
    {}


  HRESULT Run() ;

  double ToDouble(int iNumV) const ;

  struct CurvData_t
  {
    std::array<double,2> m_Curv;
    
    std::array<CATMathVector,2> m_Dirs;
    std::array<CATMathVector2D, 2> m_Dirs2D;

    CurvData_t() 
      : m_Curv{0., 0.}
      , m_Dirs{CATMathVector(), CATMathVector()}
      , m_Dirs2D{ CATMathVector2D(), CATMathVector2D() }
    {}
  };

  //Get curvature value
  CATPolyVertexCurvatureAttributeOpe::CurvData_t Get(const int iNumV) const;

  //Get curvature value, return 0 if no error
  int Get(const int iNumV, CATPolyVertexCurvatureAttributeOpe::CurvData_t& oCurvData) const;

  CATBoolean EnableTolerantMode() const { return m_EnableTolerantMode; }

private:

  CATPolyVertexNormalAttributeOpe m_VertexNormalOpe;
  CATPolyVoronoiWeighting m_Weighter;

  HRESULT ComputeTriangleFrame(int NumT);
  int CompleteOrthogonalBasis2(const CATMathVector & iVec, CATMathVector& oV, CATMathVector& oW);

  std::map<int, LocalFrame_t> m_AllTriangleFrame;
  std::map<int, LocalFrame_t> m_AllVertexFrame;


  const CATTolerance &          m_Tol;
  std::map<int, CurvData_t>     m_Attr;
  const CATIPolyMesh &          m_Mesh;
  CATBoolean                    m_EnableTolerantMode;

};


#endif // CATPolyVertexCurvatureAttributeOpe_h__
