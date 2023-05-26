/**
* @fullReview AOO4 NSI 22:12:16
*/
//===================================================================
// COPYRIGHT  2022/09/30
//===================================================================
// IVIARCameraDevice.cpp
// Header definition of class IVIARCameraDevice
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/09/30 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef IVIARCameraDevice_H
#define IVIARCameraDevice_H

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"

//-----------------------------------------------------------------------------
class CATPixelImage;
class CATMathTransformation;


//-----------------------------------------------------------------------------

extern ExportedByIVInterfaces  IID IID_IVIARCameraDevice ;
class ExportedByIVInterfaces IVIARCameraDevice: public CATBaseUnknown
{
CATDeclareInterface;

public:
//
//
  /**
   * @brief Get the Viewpoint Angle
   * 
   * @return double 
   */
  virtual double GetViewpointAngle() = 0;

  /**
   * @brief Get a boolean that indicates if the camera has a fixed focal length or not 
   * 
   * @return boolean 
   */
  virtual bool IsFixedFocal() = 0;

  /**
   * @brief Get the Camera Image (current frame)
   * 
   * @return CATPixelImage* 
   */
  virtual CATPixelImage* GetCameraImage() = 0;

  /**
   * @brief Get the Image (Width, Height)
   * 
   * @param oXsize 
   * @param oYsize 
   */
  virtual void GetImageSize(int& oXsize, int& oYsize) = 0;

  /**
   * @brief Get the Camera Pose as an array[16] in ROW_MAJOR
   * 
   * @param oCameraPose 
   */
  virtual void GetCameraPose(double oCameraPose[16]) = 0;

  /**
   * @brief Get the Camera Pose in CATMathTransformation
   * 
   * @param oCameraPose Camera pose
   * @param iMatrixDispositionType  0 : COLUMN_MAJOR (by default), 1 : ROW_MAJOR
   */
  virtual void GetCameraPose(CATMathTransformation& oCameraPose, int iMatrixDispositionType = 0) = 0;

// 
//

};

//-----------------------------------------------------------------------
CATDeclareHandler( IVIARCameraDevice, CATBaseUnknown );

#endif
