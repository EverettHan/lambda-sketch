#ifndef CATPolyFeatureLinesDetector_h__
#define CATPolyFeatureLinesDetector_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFeatureLinesDetector.h : compute of mesh gradient at vertices

//
//===================================================================
// January 2020  Creation DCU3
//===================================================================

#include "CATMath3x3Matrix.h"
#include "CATMath2x2Matrix.h"
#include "CATMathVector2D.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"



// export
#include "ExportedByCATPolyFeatureLineOperator.h"

// mesh
#include "CATPolyVertexCurvatureAttributeOpe.h"
#include "CATPolyVertexNormalAttributeOpe.h"
#include "CATPolyVoronoiWeighting.h"
//
// math
#include "CATPolyMeshScalarDerivativeOpe.h"



// stl
#include <vector>
#include <map>
#include <array>
#include <unordered_set>

class CATIPolyMesh;


struct FeatureLineFilter {
    double coeffBetweenKminAndKmax;
    double SegmentWidth;
    CATBoolean singularFilter;
    double RadiusOfCurvatureMax;
    double RadiusOfCurvatureMin;
    FeatureLineFilter(int coeff,double width,CATBoolean singular,double radiusMax,double radiusMin) :
        coeffBetweenKminAndKmax(coeff), SegmentWidth(width), singularFilter(singular), RadiusOfCurvatureMax(radiusMax), RadiusOfCurvatureMin{radiusMin} {};

};

class ExportedByCATPolyFeatureLineOperator CATPolyFeatureLinesDetector
{
   
public:

    CATPolyFeatureLinesDetector(const CATIPolyMesh & iMesh,FeatureLineFilter* =nullptr);
    virtual ~CATPolyFeatureLinesDetector();
//
    HRESULT Run();
    std::vector<CATMathPoint> GetRidge() { return m_edges_ridge; }
    std::vector<CATMathPoint> GetValley() { return m_edges_valley; }
	CATPolyVertexCurvatureAttributeOpe* Getcurvature_op() { return m_curvature_op; }

	void SetFilter(FeatureLineFilter* ifilter) {m_Filter=ifilter;}

private:
    

    HRESULT ComputeFeatureLines();
    HRESULT compute_extremality(const std::vector<double>& k_max, const std::vector<double>& k_min, const std::vector<CATMathVector>& k_vec_max, const std::vector<CATMathVector>& k_vec_min, std::vector<double> &e_max, std::vector<double> &e_min, std::unordered_set<int> &regular_max, std::unordered_set<int> &regular_min);
    HRESULT FeatureLines(const std::unordered_set<int> &regular_max,const std::unordered_set<int> &regular_min, const std::vector<double> &e_max, const std::vector<double> &e_min, const std::vector<double> &k_max, const std::vector<double> &k_min, const std::vector<CATMathVector> &k_vec_max, const std::vector<CATMathVector> &k_vec_min);    
    HRESULT compute_zero(int f, const std::vector<double> &e, const std::vector<CATMathVector>& k_vec, std::vector<bool>& faces_marked, std::vector<CATMathPoint> &edges);
    HRESULT searchSalientEdges(std::vector<CATMathPoint>& edges, const std::unordered_set<int> &regular, const std::vector<double> &k_max, const std::vector<double> &k_min, const std::vector<double> &e, const std::vector<CATMathVector>& k_vec,  std::vector<bool> &faces_marked, int mode);
    HRESULT searchFeatureLinesOnSingularTriangle(std::vector<CATMathPoint> & edges_max, const std::unordered_set<int> &regular_max,const  std::vector<double> &e_max, const std::vector<bool> &faces_marked_max, int mode);
    HRESULT compute_Curvature(std::vector<double>& k_max, std::vector<double>& k_min, std::vector<CATMathVector>& k_vec_max, std::vector<CATMathVector>& k_vec_min);
    HRESULT compute_CurvatureDerivative(std::vector<CATMathVector>& G_k_max, std::vector<CATMathVector>& G_k_min);

    
    static HRESULT vertex_triangle_adjacency(const std::vector<CATMathPoint >  &V, const std::vector<std::array<int, 3>> & F, std::vector<std::vector<int>> &VF, std::vector<std::vector<int>> &VFi);
    static HRESULT triangle_triangle_adjacency(std::vector<CATMathPoint >  V, std::vector<std::array<int, 3>>& F, std::vector<std::array<int, 3>>& TT);
    static void compute_triangle_regularity(std::vector<std::array<int, 3>>   F,const  std::vector<CATMathVector>& k_vec, std::unordered_set<int>& regular, std::unordered_set<int>& singular);
    static double ComputeAreaVolume(const CATMathPoint & pt1, const CATMathPoint & pt2, const CATMathPoint & pt3);
    static HRESULT doublearea(const std::vector<CATMathPoint >  &V,const std::vector<std::array<int, 3>> & F, std::vector<double> &A);
    static double vertex_extremality(int p, const std::vector<double> &k,const  std::vector<CATMathVector>& k_vec, const std::vector<CATMathVector>& G_k,const  std::unordered_set<int>& regular, const std::vector<std::vector<int>> &m_VF, const std::vector<double> &m_A);
    static HRESULT Barycenter(const std::vector<CATMathPoint >  &V, const std::vector<std::array<int, 3>>& F, std::vector<CATMathPoint > &B);

//
//
  const CATIPolyMesh & m_Mesh; 
  
  CATPolyVertexCurvatureAttributeOpe * m_curvature_op;
  CATPolyMeshScalarDerivativeOpe * m_derivative_min;
  CATPolyMeshScalarDerivativeOpe * m_derivative_max;



  std::vector<CATMathPoint >  m_V;
  std::vector<std::array<int, 3>>  m_F;
  std::vector<std::vector<int>> m_VF;
  std::vector<std::vector<int>> m_VFi;
  std::vector<double> m_A;
  std::vector<CATMathPoint> m_B;
  std::vector<std::array<int, 3>> m_TT;
  
  std::vector<CATMathPoint> m_edges_ridge;
  std::vector<CATMathPoint> m_edges_valley;

  FeatureLineFilter *m_Filter;

};


#endif // CATPolyFeatureLinesDetector_h__
