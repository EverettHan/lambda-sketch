// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuOrthoProjection.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
// Sept 2010 ZFI : Update new generic
// Dec 2008  XXC: Add of a second depth in the displacement map generation
// Oct 2008  XXC: RunFaceView with frame on one particular face
// Sep 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuOrthoProjection_H
#define CATPolyVisuOrthoProjection_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"
#include "CATBoolean.h"

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

class CATMathBox;


class ExportedByPolyVisuProjectionOper CATPolyVisuOrthoProjection
{
public:  
  //constructor and destructor  
  CATPolyVisuOrthoProjection();
  virtual ~CATPolyVisuOrthoProjection();

public:
  //new methods->official
  HRESULT RunGlobalViews(CATPolyBody& iPolyBody,
                         const CAT3DRep& iOriginalRep,
                         int iNbViews,
                         CATPixelImage* ioTextureImage,
                         CATPixelImage* ioNormalMapImage) const;
    
  HRESULT RunLocalViews(CATPolyBody& iPolyBody,
                        const CAT3DRep& iOriginalRep,
                        CATPixelImage* ioTextureImage,
                        CATPixelImage* ioNormalMapImage) const;

public:
  //deprecated
  //main methods
  HRESULT RunNViews( CATPolyBody& iPolyBody,
                     const CAT3DRep& iSimpleRep, 
                     const CAT3DRep& iOriginalRep,
                     int iNbViews,
                     CATPixelImage* ioTextureImage,
                     CATPixelImage* ioNormalMapImage,
                     CATPixelImage* ioDisplMapImage,float iDisplMax, float iScale) const;


  /** Generate textures of a complex model to map on a simplified
   *  version (in a CATPolyBody) of this complex model. Textures are
   *  obtained from different shootings of the complex original model
   *  (one view for each face of the simplified CATPolyBody). The
   *  CATPolyBody must already have a texture coordinates layer.
   *@param iPolyBody: the CATPolyBody representing the simplified
   *model.
   *@param iFrameBoundingRep: the CAT3DRep used to frame the
   *view.
   *@param iOriginalRep: the CAT3DRep representing the complex
   *original model.
   *@param iIdxFace: the index of the face to map to the texture in
   *the CATPolyBody.
   *@param ioTextureImage: a texture picture which renders the colors
   *of the original model.
   *@param ioNormalMapImage: the normal map, a texture that encodes
   *the normal to the surface of the original model.
   *@param ioDisplMapImage: the displacement map, a texture that
   *encodes the displacement between the original model and its
   *orthographic projection on the simplified model.
   *@param iDisplMax: the maximum displacement one can have between
   *the two models (original and simplified ones)
   *@param iScale: the scale of the CATPolyBody texture coordinates,
   *to map in a [0;1]x[0;1] square.
   *@return S_OK if everything is right, E_FAIL otherwise.
   */
  HRESULT RunFaceView(CATPolyBody& iPolyBody, 
                      const CAT3DRep& iFrameBoundingRep,
                      const CAT3DRep& iOriginalRep,
                      int iIdxFace,
                      CATPixelImage* ioTextureImage,
                      CATPixelImage* ioNormalMapImage,
                      CATPixelImage* ioDisplMapImage,float iDisplMax, float iScale) const;

  //only the capture, without transfer
  HRESULT CaptureView(const CAT3DRep& iOriginalRep,
                      const CATMathVector& iSightDirection, const CATMathVector& iUpDirection,
                      const int iWidth, const int iHeight,
                      CATPixelImage*& ioTextureImage, 
                      CATPixelImage*& ioNormalMapImage, 
                      CATPixelImage*& ioDisplMapImage, 
                      CATMathBox& oBoundingBox)const;

};

#endif
