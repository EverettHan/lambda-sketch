// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuProjectionUtils.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Oct 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuProjectionUtils_H
#define CATPolyVisuProjectionUtils_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"

class CATMathVector;
class CATPolyBody;
class CATIPolyMesh;
class CAT3DRep;
class CAT3DBagRep;
class CATGraphicAttributeSet;
class CATPixelImage;
class CATPolyBody;
class CATMathBox;
class CATPolyFace;
class CAT3DBoundingSphere;
class CATMathBox2D;

class  ExportedByPolyVisuProjectionOper CATPolyVisuProjectionUtils
{
public:
  
  static HRESULT FillDirections(CATMathVector* ioSightDirection, 
                                CATMathVector* ioUpDirection, 
                                int iNbDirections);

  static HRESULT FillDirectionsFromFacesNormals(CATPolyBody& iPolyBody, 
                                                CATMathVector*& oSightDirection, 
                                                CATMathVector*& oUpDirection, 
                                                int nbDirections);

  static HRESULT FillDirectionFromFaceNormal(CATPolyBody& iPolyBody,
                                             int iIdxFace,
                                             CATMathVector& oSightDirection,
                                             CATMathVector& oUpDirection);

  static HRESULT FindPolyMeshAverageNormal(const CATIPolyMesh& iMesh, 
					                                 CATMathVector& n);

  static HRESULT FindPolyMeshParam(const CATIPolyMesh& iMesh, 
                                   CATMathVector& u, 
                                   CATMathVector& v,
                                   CATMathVector& w);

  static HRESULT CreateUniformColoredRep(const CAT3DRep& iOriginalRep, CAT3DRep*& oColoredRep);
  static HRESULT ComputeBoundingBox(const CAT3DRep&  iRep, 
                                    const CATMathVector& iSightDirection,
                                    const CATMathVector& iUpDirection, CATMathBox& ioBoundingBox);

  static CATPixelImage* CreateAtlasImage(CATPolyBody& iPolyBody, int iWidth, int iHeight);
  static CATPixelImage* CreateAtlasImageRGBA(CATPolyBody& iPolyBody, int iWidth, int iHeight);

  static HRESULT ComputeBoundingElement(CATPolyBody& iPolyBody, 
                                        CAT3DBoundingSphere& oBs);
  
  static HRESULT ComputeBoundingElement(CATPolyFace& iPolyFace, 
                                        CAT3DBoundingSphere& oBs);
  
  static HRESULT ComputeBoundingBox2D(CATPolyFace& iPolyFace, 
                                      CATMathBox2D& oBBox2D);


private:
  static HRESULT UpdateRep(const CAT3DRep& iRep, 
                           CAT3DBagRep& ioNewRep, 
                           const CATGraphicAttributeSet& iGraphicAttr);
};

#endif //CATPolyVisuProjectionUtils_H

