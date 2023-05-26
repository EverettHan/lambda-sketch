// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVEdge.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVEdge_H
#define CATCGMUVEdge_H

#include "CATCGMUVCell.h"
#include "CATListPV.h"
#include "CATBoolean.h"
#include "CATListOfDouble.h"

class CATEdge;
class CATCGMUVTessEdge;
class CATCGMUVTessV5Edge;
class CATCGMUVCacheEdge;
class CATCGMUVEdgeMeshBasicItf;
class CATPolyGenericSubdivision;

class ExportedByTessellateCommon CATCGMUVEdge : public CATCGMUVCell
{
public :
  CATCGMUVEdge(CATEdge* iEdge);
  virtual ~CATCGMUVEdge();

public:
  CATCGMUVEdge* CastAsEdge();

  CATEdge* GetEdge()const {return _Edge;}
  
  virtual CATCGMUVTessEdge* CastAsTessEdge();
  virtual CATCGMUVTessV5Edge* CastAsTessV5Edge();
  virtual const CATCGMUVTessEdge* CastAsTessEdge()const;
  virtual const CATCGMUVTessV5Edge* CastAsTessV5Edge()const;

  virtual CATCGMUVCacheEdge* CastAsCacheEdge();
  virtual const CATCGMUVCacheEdge* CastAsCacheEdge()const;

public:
  virtual const CATCGMUVEdgeMeshBasicItf* GetEdgeMesh()const;

public:
  //old modelisation
  virtual HRESULT GetLocalParams(CATListOfDouble& oParams)const; //replace by subdivision
  virtual HRESULT GetLocalParamsAndTangents(CATListOfDouble& oParams, CATListPV& oTangents)const; 

  //better modelisation than global param
  virtual HRESULT SetBoundingLimits(const double iWMin, const double iWMax, int iSens);
  virtual HRESULT GetBoundingLimits(double& oWMin, double& oWMax, int& oSens)const;
  virtual HRESULT GetSubdivision(CATPolyGenericSubdivision& ioSubdivision)const;

protected:
  CATEdge* _Edge;
};

#endif
