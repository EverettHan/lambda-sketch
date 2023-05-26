//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef VisMultipipeConfiguration_H
#define VisMultipipeConfiguration_H

#include "CATVisFoundation.h"

#include "CATVizBaseIUnknown.h"

#include <vector>
#include "CATBaseUnknown.h"

//=============================================================================
/**
 * VisDisplayProperties
 */
class ExportedByCATVisFoundation VisDisplayProperties
{
public:

  //
  VisDisplayProperties();

  //
  void SetScreenResolution(int iWidth, int iHeight);
  void SetScreenPosition(int iXPosition, int iYPosition);
  void SetMMInSupportUnit(float iMMInSupportUnit);
  void SetRatioWH(float iRatioWH);
  void SetAsRefWall(int iIsRefWall);
  void SetUseOffscreenFrameBufferMode();

  void SetInnerScreenResolution(int iWidth, int iHeight);
  void SetInnerScreenPosition(int iXPosition, int iYPosition);
  void SetInnerMMInSupportUnit(float iMMInSupportUnit);
  void SetInnerRatioWH(float iRatioWH);
  //
  void GetScreenResolution(int& oWidth, int& oHeight) const;
  void GetScreenPosition(int& oXPosition, int& oYPosition) const;
  void GetMMInSupportUnit(float& oMMInSupportUnit)const;
  void GetRatioWH(float& oRatioWH) const;
  int IsRefWall() const;
  int IsOffscreenFrameBufferUsed() const;

  void GetInnerScreenResolution(int& oWidth, int& oHeight) const;
  void GetInnerScreenPosition(int& oXPosition, int& oYPosition) const;
  void GetInnerMMInSupportUnit(float& oMMInSupportUnit)const;
  void GetInnerRatioWH(float& oRatioWH) const;
  
private:

  int _xPixelPosition;
  int _yPixelPosition;
  int _pixelWidth;
  int _pixelHeight;
  float _mmInSupportUnit;
  float _ratioWH;
  int _isRefWall;
  int _useOffscreenFrameBuffer;

  int _xInnerPixelPosition;
  int _yInnerPixelPosition;
  int _innerPixelWidth;
  int _innerPixelHeight;
  float _innerMMInSupportUnit;
  float _innerRatioWH;
};

//=============================================================================
/**
 * VisMultipipeConfiguration
 */
class ExportedByCATVisFoundation VisMultipipeConfiguration : public CATVizBaseIUnknown
{
public:
  
  //
  VisMultipipeConfiguration();
  VisMultipipeConfiguration(const VisMultipipeConfiguration &);
  VisMultipipeConfiguration& operator=(const VisMultipipeConfiguration&);

  //
  void AddDisplay(VisDisplayProperties const& iDisplay);
  int GetDisplayCount() const;
  void GetDisplayCount(int& oDisplayCount) const; //:FIXME: migrate callers
  
  //
  void GetScreenResolution(int iDisplayIndex, int& oWidth, int& oHeight) const;
  void GetScreenPosition(int iDisplayIndex, int& oXPosition, int& oYPosition) const;
  void GetScreenMMInSupportUnit(int iDisplayIndex, float& oMMInSupportUnit) const;
  void GetScreenRatioWH(int iDisplayIndex, float& oRatioWH) const;
  int IsRefWall(int iDisplayIndex) const;
  int IsOffscreenFrameBufferUsed(int iDisplayIndex) const;

  void GetInnerScreenResolution(int iDisplayIndex, int& oInnerWidth, int& oInnerHeight) const;
  void GetInnerScreenPosition(int iDisplayIndex, int& oInnerXPosition, int& oInnerYPosition) const;
  void GetInnerScreenMMInSupportUnit(int iDisplayIndex, float& oInnerMMInSupportUnit) const;
  void GetInnerScreenRatioWH(int iDisplayIndex, float& oInnerRatioWH) const;

private:

  std::vector<VisDisplayProperties> _displayList;
};

#endif
   
