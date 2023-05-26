// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuFrustumProjection.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Dec 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuFrustum_H
#define CATPolyVisuFrustum_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"

#include "CATMathPointf.h"
#include "CATMathVectorf.h"

class CATMathVector;

class ExportedByPolyVisuProjectionOper CATPolyVisuFrustum
{
public:
  //constructor and destructor
  CATPolyVisuFrustum();  
  virtual ~CATPolyVisuFrustum();

  HRESULT SetParam(const CATMathPointf& iCenter,
                   const CATMathVectorf& iU, 
                   const CATMathVectorf& iV, 
                   const CATMathVectorf& iW, 
                   float iRight, float iLeft,
                   float iTop, float iBottom,
                   float iNear, float iFar);

  HRESULT GetBase (CATMathVector& oU, 
                   CATMathVector& oV,
                   CATMathVector& oW);

  HRESULT GetNDCCoords(const CATMathPointf& iOldCoords, CATMathPointf& oNewCoords)const;

  float Rad() const;
  const CATMathPointf& Center()const;

public:
  CATMathVectorf _U, _V, _W;
  CATMathPointf _Center;
  float _Near, _Far, _Right, _Left, _Top, _Bottom;
};

#endif
