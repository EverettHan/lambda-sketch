// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuProjectionSupport.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Sep 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuProjectionSupport_H
#define CATPolyVisuProjectionSupport_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATPolyVisuProjectionOper.h"

class CATSupport;
class CAT3DViewpoint;
class CATPixelImage;
class CATMathVectorf;
class CAT3DBoundingSphere;

class ExportedByPolyVisuProjectionOper CATPolyVisuProjectionSupport
{
public:
  //Constructor and Destructor
  CATPolyVisuProjectionSupport();
  CATPolyVisuProjectionSupport(int iCaptureWidth, int iCaptureHeight);
  ~CATPolyVisuProjectionSupport();
  
public:
  HRESULT Initialize();

  HRESULT Reframe( const CATMathVectorf& iSightDirection, 
                   const CATMathVectorf& iUpDirection,
                   const CAT3DBoundingSphere& iBoundingSphere);
  
  //HRESULT Clip(float iNear, float iFar);
  HRESULT Clip(const CAT3DBoundingSphere& iBoundingSphere);

public:
  //Main methods
  int BR() const {return _BackgroundR;}
  int BG() const {return _BackgroundG;}
  int BB() const {return _BackgroundB;}
  
  CATSupport* RenderSupport() {return _RenderSupport;}
  CATPixelImage* Raster(){return _Raster;}
  CAT3DViewpoint* Viewpoint() const {return _Viewpoint;}
  int Width() {return _Width;}
  int Height(){return _Height;}
  float Depth(){return _Depth;}

  
private:
  int _BackgroundR , _BackgroundG, _BackgroundB;
  int _Width, _Height;
  float _Depth;

  CATSupport* _RenderSupport;
  CATPixelImage* _Raster;
  CAT3DViewpoint* _Viewpoint;
  
};

#endif
