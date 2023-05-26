// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuImageUtils.h
//
//===================================================================
//
// Usage notes: Some Algos for 2D Image Operations
//
//===================================================================
//
// Dec 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuImageUtils_H
#define CATPolyVisuImageUtils_H

#include "CATErrorDef.h"
#include "CATPolyVisuProjectionOper.h"


class CATPixelImage;
class CATMathPoint;
class CATMathVector;
class CATPolyVisuTexBox;
class CATMathVectorf;

class  ExportedByPolyVisuProjectionOper CATPolyVisuImageUtils
{
public:
  //get the mask of an image
  static CATPixelImage* GetMask(CATPixelImage* iImage,
                                int iRed, int iGreen, int iBlue);

  static CATPixelImage* GetMask(const CATPixelImage& iImage, int iGreyLevel);

  //dilate
  static HRESULT DilateSmooth(CATPixelImage& ioImage);
  static HRESULT BinarizeMask(CATPixelImage& ioMask , unsigned char iChar);
  static HRESULT DilateMask(CATPixelImage& ioMask, unsigned char iChar);

  static HRESULT DilateUniform(CATPixelImage& ioImage, int nbIters);
  static HRESULT DilateUniform(CATPixelImage& ioImage, const CATPixelImage& iMeskImage, int nbIters);

  static HRESULT DilateRGBAUniform(CATPixelImage& ioImage, int nbIters);
  static HRESULT DilateLUniform(CATPixelImage& ioImage, int nbIters);

  static HRESULT DilateMaskRGBA(CATPixelImage& ioImage, 
                                unsigned char iFront, 
                                unsigned char iMiddle, 
                                unsigned char iBack);
  
  static HRESULT DilateMaskRGBA(CATPixelImage& ioImage, 
                                const CATPixelImage& iMaskImage,
                                unsigned char iFront, 
                                unsigned char iMiddle, 
                                unsigned char iBack);

  static HRESULT BinarizeMaskRGBA(CATPixelImage& ioImage, unsigned char iFront);
  
  //close using fixed number of iterations
  static HRESULT CloseRGBA(CATPixelImage& ioImage, int nbIters);
  static HRESULT ErodeRGBA(CATPixelImage& ioImage, int nbIters);
  static HRESULT DilateRGBA(CATPixelImage& ioImage, int nbIters);

  //dilate using mask image
  static HRESULT DilateRGBA(CATPixelImage& ioImage, const CATPixelImage& iMaskImage);


  static HRESULT GetNeighbors8(int x, int y, int iWidth, int iHeight, int indexN[8]);
  static HRESULT GetNeighbors4(int x, int y, int iWidth, int iHeight, int indexN[4]);

  //extract from background and create RGBA image
  static CATPixelImage* ExtractFromBackGround(const CATPixelImage& iOriginal, 
                                              unsigned  char iBackGroundR, 
                                              unsigned  char iBackGroundG,
                                              unsigned  char iBackGroundB);
  
  static HRESULT FilterZBufferImage(CATPixelImage& iDisplMapImage);

};

#endif //CATPolyVisuImageUtils_H

