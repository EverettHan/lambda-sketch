#ifndef CATPolyVertexNormalAttributeOpe_h__
#define CATPolyVertexNormalAttributeOpe_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATAPolyMeshVertexNormalAttributeOpe.h : enhanced computation of normal at mesh vertex
//
//===================================================================
// December 2017  Creation NUA
//===================================================================

// export
#include "ExportedByCATPolyFeatureLineOperator.h"

// Math
#include "CATMathVector.h"

#include "CATSysErrorDef.h"

// STL
#include <map>

class CATIPolyMesh;
class CATTolerance;

// Per Weights for Computing Vertex Normals from Facet Normals
// https://pdfs.semanticscholar.org/9146/5dff3c4beecc70bad31442925aa3abe35061.pdf 

class ExportedByCATPolyFeatureLineOperator CATPolyVertexNormalAttributeOpe
{
public:

  CATPolyVertexNormalAttributeOpe(const CATIPolyMesh & iMesh, const CATTolerance & iTol) : m_Mesh(iMesh), m_Tol(iTol) {}

  HRESULT Run() ;

  double ToDouble(int iNumV) const ;

  CATMathVector Get(int NumV) const
  {
    return m_Attr.at(NumV);
  }

private:

  std::map<int, CATMathVector> m_Attr;

  const CATIPolyMesh & m_Mesh;
  const CATTolerance & m_Tol;
};
#endif // CATPolyVertexNormalAttributeOpe_h__
