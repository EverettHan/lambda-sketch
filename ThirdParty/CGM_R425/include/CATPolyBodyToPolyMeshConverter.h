// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyToPolyMeshConverter.h
//
//===================================================================
// March 2010 Creation: ndo
//===================================================================
#ifndef CATPolyBodyToPolyMeshConverter_h
#define CATPolyBodyToPolyMeshConverter_h

#include "PolyBodyServices.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATMathTransformation.h"

class CATPolyBody;
class CATIPolyMesh;
class CATMapOf3DoublesToInt;


/**
 * Operators that converts a CATPolyBody into CATIPolyMesh.
 */
class ExportedByPolyBodyServices CATPolyBodyToPolyMeshConverter
{

public:

  CATPolyBodyToPolyMeshConverter () {_DoCopyUVs = _DoInvertTriangles = _DoTransfo = _DoInvertNormals = FALSE;}
  ~CATPolyBodyToPolyMeshConverter () {}

  inline void DoInvertTriangles (CATBoolean iDoInvert);
  inline void DoInvertNormales(CATBoolean iDoInvert);
  inline void SetTransformation(const CATMathTransformation& Transfo);

  // default is not to copy UVs
  // When copying, last one wins.
  inline void DoCopyUVs();

public:

  /**
   * Converts a CATPolyBody into a CATIPolyMesh.
   * The method adds all the data from the CATPolyBody to the CATIPolyMesh.
   */
  HRESULT Run (const CATPolyBody& iPolyBody, CATIPolyMesh& ioPolyMesh, CATMapOf3DoublesToInt * mapofpos = 0);

private:

  CATBoolean _DoInvertTriangles;
  CATBoolean _DoTransfo;
  CATBoolean _DoInvertNormals;
  CATMathTransformation _Transfo;
  CATBoolean _DoCopyUVs;
};


inline void CATPolyBodyToPolyMeshConverter::DoInvertTriangles (CATBoolean iDoInvert)
{
  _DoInvertTriangles = iDoInvert;
}

inline void CATPolyBodyToPolyMeshConverter::DoInvertNormales(CATBoolean iDoInvert)
{
  _DoInvertNormals = iDoInvert;
}

inline void CATPolyBodyToPolyMeshConverter::SetTransformation(const CATMathTransformation& Transfo)
{
  _DoTransfo = TRUE;
  _Transfo = Transfo;
}

inline void CATPolyBodyToPolyMeshConverter::DoCopyUVs()
{
  _DoCopyUVs = TRUE;
}

#endif
