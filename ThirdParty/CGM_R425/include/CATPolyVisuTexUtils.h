// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuTexUtils.h
//
//===================================================================
//
// Usage notes: Some Algos for Texture manipulation
//
//===================================================================
//
// Dec 2009 XXC: Add GenerateOrthoDistancesFromZBuffers and FlagMask
//               with bounding values
// Sep 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuTexUtils_H
#define CATPolyVisuTexUtils_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"
#include "CATPixelImage.h"


class CATMathPoint;
class CATMathVector;
class CATPolyVisuTexBox;
class CATMathVectorf;

class  ExportedByPolyVisuProjectionOper CATPolyVisuTexUtils
{
public:
  
  ////compute barycenter coords of a an input point in a triangle
  static HRESULT BarycenterCoords(const CATMathPoint& iVertex1, 
                                  const CATMathPoint&  iVertex2, 
                                  const CATMathPoint& iVertex3, 
                                  const CATMathPoint& iPoint , 
                                  CATMathPoint& oPoint);

  //compute triangle bounding box
  static HRESULT ComputeTriangleBB(const CATMathPoint& iVertex1, 
                                   const CATMathPoint&  iVertex2, 
                                   const CATMathPoint& iVertex3, 
                                   int& minX, int& maxX, 
                                   int& minY, int& maxY);
  //more optimized-> with arrays
  
  //compute triangle bounding box
  static HRESULT ComputeTriangleBB(const double iVertex1[2], 
                                   const double iVertex2[2], 
                                   const double iVertex3[2], 
                                   int& minX, int& maxX, 
                                   int& minY, int& maxY);
    
  //compute barycenter coords of a an input point in a triangle
  static HRESULT BarycenterCoords(const double iVertex1[2], 
                                  const double iVertex2[2], 
                                  const double iVertex3[2], 
                                  const double iPoint[2] , 
                                  double oPoint[3]);



  //update a bounding box of a triangle from an old bounding box.
  static HRESULT UpdateBoundingBox(const float texCoords[6] , 
                                   CATPolyVisuTexBox& ioLimits);

  //bounding box of a set of points
  static HRESULT BoundingBox(float* iVerticesCoords, 
                             int iNbVertices , 
                             float& xmin, float& xmax,
                             float& ymin, float& ymax);
  //compute triangle Area
  static float GetTriangleArea(const float coords[6]);

  //compute triangle Normal
  static HRESULT GetTriangleNormal(const CATMathPoint& iP1,
                                     const CATMathPoint& iP2,
                                     const CATMathPoint& iP3,
                                     CATMathVector& oVec);

  //compute the triangle coords in the trinagle bounding box
  static HRESULT ChangeRef(float ioArray[6] , 
                           const CATPolyVisuTexBox& iLimits);

  //get a texture triangle from an image, and past it in a second image. Do not get mask
  static HRESULT Past(const float iTexCoords1[6] ,
                      const CATPixelImage& iImage1,
                      unsigned  char iBackGroundR, 
                      unsigned  char iBackGroundG,
                      unsigned  char iBackGroundB, 
                      const float iTexCoords2[6],
                      CATPixelImage& ioImage2,
                      CATPixelImage& ioMaskImage);
  
  
  
  //past an image in another image, after scaling and translating it 
  static HRESULT PastReducedImageInOriginal(const CATPixelImage& iZoomedImage, 
                                         const CATPixelImage& iMaskImage, 
                                         int iZoomFactor , 
                                         int xOrigin, int yOrigin, 
                                         CATPixelImage& ioFinalImage);

  //get the bounded image with respect to the mask 
  static CATPixelImage* GetBoundedImage(CATPixelImage* iImage, CATPixelImage* iMask);

  //RGB merge
  static CATPixelImage* MergeImages(CATPixelImage* iShotImages[6],
                                    unsigned  char iBackGroundR, 
                                    unsigned  char iBackGroundG,
                                    unsigned  char iBackGroundB);

  //compute difference between 2 z Buffers, and add To View Vector (distance = iZuffer1 - iZBuffer2)
  static HRESULT  GenerateDistancesFromZBuffers(const float* iZBuffer1, 
                                                const float* iZBuffer2, 
                                                int iWidth, int iHeight, 
                                                const CATMathVectorf& sightDirection, 
                                                CATPixelImage*& oDisX,
                                                CATPixelImage*& oDisY, 
                                                CATPixelImage*& oDisZ);

  /** Generate a two or more channels image from two Z-buffers
   *  iZBuffer1 and iZBuffer2, corresponding to two different viewed
   *  obects. The returned image encodes in the first (red) channel
   *  the distance between the two objects and in the second (green)
   *  channel the maximum encountered distance. This distance is
   *  computed, for each pixel, from the two Z-buffers and is
   *  normalized to fit in the interval [0;1].
   *@param iZBuffer1: the first Z-buffer.
   *@param iZBuffer2: the second Z-buffer.
   *@param iWidth: the requested width of the resulting image.
   *@param iHeight: the requested height of the resulting image.
   *@param iDepth: the depth of the clipping used to obtain the two
   *Z-buffers. This depth allows to get the real depth in the scene
   *between the two viewed objects.
   *@param iScale: the scale used in the atlas generated for one of
   *the two objects. It is used here to normalize the real distance
   *between the two viewed objects from 0 to 1.
   *@param iTresh: iTresh = iScale * M, where M is the maximum real
   *distance between the two viewed objects in the scene. It is used
   *to normalize the distance from 0 to 1, before encoding it in the
   *resulting picture. The final distance, for the pixel with line y
   *and column x, is given by
   *((iZBuffer2-iZBuffer2)*iDepth*iScale)/iTresh.
   *@param iDim: Requested image format: LA, RGB or GRBA (at least two
   *channels).
   *@param oDis: The resulting picture.
   *@return E_FAIL if something is wrong, S_OK otherwise.
   */
  static HRESULT GenerateOrthoDistancesFromZBuffers(const float* iZBuffer1, 
                                                    const float* iZBuffer2, 
                                                    int iWidth, int iHeight, 
                                                    float iDepth, float iScale,float iThresh,
                                                    CATPixelImageFormat iDim,
                                                    CATPixelImage*& oDis);
    
  static HRESULT GenerateOrthoDistancesFromZBuffer(const float* iZBuffer,  
                                                  int iWidth, int iHeight, 
                                                  float iZmin, float iZMax,
                                                  CATPixelImage*& oDis);

  //encore float in 3 RGB Canals
  static HRESULT Float2RGB(float iValue, 
                           unsigned char& oRed, unsigned char& oGreen, unsigned char& oBlue);
  static HRESULT Float2Char(float iValue, float iValueMax, unsigned char& oChar);

  //flag image with a triangle, and a color (gray)
  static HRESULT FlagMask(float iCoords[6], CATPixelImage& ioImage, unsigned int iColor);
  /** Flag a triangle in an existing image (with four channels)
   *  ioImage with a color given by the extremities of a 2D bounding
   *  box.
   *@param iCoords: contains the 2D coordinates of the three triangle
   *vertices in a [0;1]x[0;1] square which is mapped to the picture
   *ioImage.
   *@param ioImage: the image where the triangle is flagged.
   *@param iXmin, iXmax, iYmin, iYmax: the extremities of a 2D
   *bounding box which determines the color to give to each pixels in
   *the flagged triangle. Each value correspond to a unique channel in
   *the image: iXmin for red, iYmin for green, iXmax for blue and
   *iYmax for the alpha (transparency) channel.
   */
  static HRESULT FlagMask(float iCoords[6], CATPixelImage& ioImage, float iXmin, float iYmin, float iXmax, float iYmax);
};

#endif //CATPolyVisuTexUtils_H

