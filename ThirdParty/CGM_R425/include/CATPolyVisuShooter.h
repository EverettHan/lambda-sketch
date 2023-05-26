// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuShooter.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Nov 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuShooter_H
#define CATPolyVisuShooter_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"
#include "CATBoolean.h"


class CATPolyVisuProjectionSupport;
class CATMathPointf;
class CATMathVectorf;
class CAT3DRep;
class CATPixelImage;
class CATPolyVisuProjectionData;
class CAT3DBoundingSphere;
class CATPolyVisuFrustum;

class ExportedByPolyVisuProjectionOper CATPolyVisuShooter
{
public:  
  //constructor and destructor
  
  CATPolyVisuShooter();
  virtual ~CATPolyVisuShooter();

public:
  
  HRESULT GetMaskShot (CATPolyVisuProjectionSupport& iSupport,
                       const CAT3DRep& iRep,
                       CATPixelImage*& oShot) const;

  HRESULT GetColorsShot(CATPolyVisuProjectionSupport& iSupport,
                        const CAT3DRep& iRep,
                        CATPixelImage*& oColorShot) const; 

  HRESULT GetNormalsShot( CATPolyVisuProjectionSupport& iSupport,
                          const CAT3DRep& iRep,
                          CATPixelImage*& oShot) const;

  HRESULT GetDepthShot( CATPolyVisuProjectionSupport& iSupport,
                        const CAT3DRep& iRep,
                        float*& oDepthShot) const; 
  
  HRESULT GetDepthShot(CATPolyVisuProjectionSupport& iSupport,
                       const CAT3DRep& iRep,
                       CATPixelImage*& oDepthShot,
                       float iMinDepth, float iMaxDepth)  const; 

  HRESULT GetPositionShot(CATPolyVisuProjectionSupport& iSupport,
                          const CAT3DRep& iRep,
                          float*& oPositionShot)const;

  HRESULT GetDisplacementShot(CATPolyVisuProjectionSupport& iSupport,
                              float iDisplMax, float iScale,
                              const CAT3DRep& iSimpleRep,const CAT3DRep& iOriginalRep,             
                              CATPixelImage*& oShot)  const; 
};

#endif
