#ifndef CATVpReframeData_H
#define CATVpReframeData_H

#include "SGInfra.h"
#include "CATMathPoint.h"

enum BoundingElemType
{
  BoundingBox ,
  BoundingSphere
};

class ExportedBySGInfra  CATVpReframeData 
{

public:

  CATVpReframeData();
  virtual ~CATVpReframeData();

  const BoundingElemType& GetBoundingElemType();
  
  inline CATMathPoint GetCentre() const
  {
    return (_centre);
  }
  
  inline void SetCentre(CATMathPoint& iCentre) { _centre = iCentre; }

  inline float GetScreenHeight() const
  {
    return (_screenHeight);
  }
  inline void SetScreenHeight(float iScreenHeight) { _screenHeight = iScreenHeight; };

  inline float GetScreenWidth() const
  {
    return (_screenWidth);
  }
  inline void SetScreenWidth(float iScreenWidth) { _screenWidth = iScreenWidth; };

private:

  CATMathPoint _centre;
  float _screenHeight, _screenWidth;

protected:
  BoundingElemType _type;
};

//child class pertaining to the details of Bounding box
class ExportedBySGInfra CATVpBBoxReframeData : public CATVpReframeData
{
public:

  CATVpBBoxReframeData();
  virtual ~CATVpBBoxReframeData();
  
  inline float GetHeight() const
  {
    return (_height);
  }
  inline void SetHeight(float iHeight) { _height = iHeight; };

  inline float GetWidth() const
  {
    return (_width);
  }
  inline void SetWidth(float iWidth) { _width = iWidth; };

  inline float GetDepth() const
  {
    return (_depth);
  }
  inline void SetDepth(float iDepth) { _depth = iDepth; };

  void SetBoundingBoxData(CATMathPoint& iMinPt, CATMathPoint& iMaxPt);
  void GetBoundingBoxData(CATMathPoint& oMinPt, CATMathPoint& oMaxPt) const;


private:
  float _depth, _height, _width;
  CATMathPoint _minPoint, _maxPoint;

};

//child class pertaining to the details of Bounding shpere
class ExportedBySGInfra CATVpBSphereReframeData : public CATVpReframeData
{

public:
  CATVpBSphereReframeData();
  virtual ~CATVpBSphereReframeData();

  inline void SetRadius(float iradius) { _radius = iradius; }
  inline float GetRadius() const
  {
    return (_radius);
  }

  inline float GetRadiusMM() const
  {
    return (_radiusMM);
  }

private:
  float _radius, _radiusMM;

};

#endif

