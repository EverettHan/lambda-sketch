// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVFace.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVFace_H
#define CATCGMUVFace_H

#include "CATCGMUVCell.h"
#include "CATListPV.h"
#include "ExportedByTessellateCommon.h"

class CATFace;
class CATEdge;
class CATIPolySurface;
class CATMapOfIntToInt;
class CATCGMUVTessFace;
class CATCGMUVTessV5Face;
class CATCGMUVFaceMeshRichItf;

class ExportedByTessellateCommon CATCGMUVFace : public CATCGMUVCell
{
public :
  CATCGMUVFace(CATFace* iFace);
  virtual ~CATCGMUVFace();

public:
  CATCGMUVFace* CastAsFace();

  CATFace* GetFace()const {return _Face;}
  
  virtual CATCGMUVTessFace* CastAsTessFace();
  virtual CATCGMUVTessV5Face* CastAsTessV5Face();

public:
  //Editable Tess Data
  virtual HRESULT GetTessellatedSurface(int iOrientation, 
                                        CATIPolySurface*& oPolySurface,
                                        CATMapOfIntToInt& ioVertexMap)const;

  virtual HRESULT GetTessellatedCurve(CATEdge* iEdge,
                                      CATListOfInt& oCurveIndices, 
                                      CATListOfDouble& oCurveParams,
                                      int& oSens)const;

public:
  //New Cache Infra
  virtual CATCGMUVFaceMeshRichItf* GetMesh()const;
                                      

protected:
  CATFace* _Face;

private:
  friend class CATCGMUVFaceEdgeIterator;
  friend class CATCGMUVFaceVertexIterator;
};

#endif
