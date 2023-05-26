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
// Nov 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuFrustumProjection_H
#define CATPolyVisuFrustumProjection_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"
#include "CATMathVectorf.h"
#include "CATBoolean.h"
#include "CATMathPointf.h"


class CATMathVector;
class CAT3DRep;
class CATPixelImage;

class CATMapOfIntIntToFloat;
class CATMapOfIntIntToInt;
class CATMapOfIntIntToPtr;
class CATMapOfIntToPtr;
class CATMapOfIntToInt;

class CATPolyBody;
class CATPolyVisuProjectionData;
class CATPolyVisuProjectionSupport;

class CATMathVectorf;
class CATMathPointf;
class CAT3DBoundingSphere;
class CATPolyVisuFrustum;
class CAT3DBoundingSphere;

class ExportedByPolyVisuProjectionOper CATPolyVisuFrustumProjection
{
public:  
  //constructor and destructor  
  CATPolyVisuFrustumProjection();
  virtual ~CATPolyVisuFrustumProjection();

public:
  //main methods

  HRESULT RunView(const CAT3DRep& iOriginalRep,
                  const CATPolyVisuFrustum& iFrustum,
                  CATPixelImage* ioTextureImage,
                  CATPixelImage* ioNormalMapImage,
                  CATPixelImage* ioDisplMapImage) const;

  HRESULT ProjectPolyBody(CATPolyBody& iPolyBody, const CATPolyVisuFrustum& iFrustum) const;

 private:
  HRESULT PrintTexture(int iWidth, int iHeight,
                       const CATPixelImage& colorShot,
                       float* positionShot,
                       const CATPolyVisuFrustum& iFrsutum,
                       CATPixelImage& ioTexture)const ;

  HRESULT PrintDisplacement(int iWidth, int iHeight,
                            float* positionShot,
                            const CATPolyVisuFrustum& iFrsutum,
                            CATPixelImage& ioDispMap)const ;

  HRESULT FindPositionFromPoint(const CATMathPointf& iPos,
                                const CATPolyVisuFrustum& iFrsutum,
                                float& oTexX, float& oTexY,
                                CATBoolean& ioFound) const;

  HRESULT FillDirectionsFromFrustum(const CATPolyVisuFrustum& iFrustum, 
                                    CATMathVectorf* oSightDir,
                                    CATMathVectorf* oUpDir,
                                    int iNbDirs) const;

};

#endif
