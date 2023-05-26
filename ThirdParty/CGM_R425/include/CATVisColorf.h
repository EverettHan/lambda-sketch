// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisColorf_H
#define CATVisColorf_H

#include "SGInfra.h"
#include "CATVisColor.h"

//-----------------------------------------------------------------------

class ExportedBySGInfra CATVisColorf
{
public:
  CATVisColorf(float iRed=1.f, float iGreen=1.f ,float iBlue=1.f, float iAlpha=1.f);
  CATVisColorf (const CATVisColorf &);
  CATVisColorf (const CATVisColor &);
  ~CATVisColorf();

  // operateurs
  inline CATVisColorf& operator=(const CATVisColorf& iCol);
  inline CATVisColorf& operator=(const CATVisColor& iCol);
  inline CATVisColorf& operator*=(const CATVisColorf& iCol);
  inline CATVisColorf& operator*=(const CATVisColor& iCol);
  inline CATVisColorf& operator*=(float iScale);
  inline CATVisColorf& operator+=(const CATVisColorf& iCol);
  inline CATVisColorf& operator+=(const CATVisColor& iCol);
  inline CATVisColorf& operator+=(float iDelta);
  CATVisColorf operator-(const CATVisColorf&  iColor) const;
  CATVisColorf operator+(const CATVisColorf&  iColor) const;
  CATVisColorf operator*(const CATVisColorf&  iColor) const;
  CATVisColorf operator*(float  iScale) const;
  inline void AlphaBlend(const CATVisColorf& iCol);
  inline int operator ==(const CATVisColorf & iColor) const;
  inline int operator !=(const CATVisColorf & iColor) const;

  inline float Red() const;
  inline float Green() const;
  inline float Blue() const;
  inline float Alpha() const;
  inline float* RGBA() const;

  float Luminance() const;

  inline void SetRed(float iRed);
  inline void SetGreen(float iGreen);
  inline void SetBlue(float iBlue);
  inline void SetAlpha(float iAlpha);
  inline void SetRGB(float iRed, float iGreen,float iBlue);
  inline void MultiplyRGB(float iScale);
  inline void SetRGBA(float iRed, float iGreen,float iBlue,float iAlpha);
  
  void SetHSL(float  iHue, float  iSaturation, float  iLuminance);
  void GetHSL(float& oHue, float& oSaturation, float& oLuminance) const;

private:    
  float _rgba [4];
};

//-----------------------------------------------------------------------

inline float CATVisColorf::Red() const
{
  return _rgba[0];
}

inline float CATVisColorf::Green() const
{
  return _rgba[1];
}

inline float CATVisColorf::Blue() const
{
  return _rgba[2];
}

inline float CATVisColorf::Alpha() const
{
  return _rgba[3];
}

inline  CATVisColorf& CATVisColorf::operator=(const CATVisColorf& iColor)
{
  _rgba[0] = iColor._rgba[0];
  _rgba[1] = iColor._rgba[1];
  _rgba[2] = iColor._rgba[2];
  _rgba[3] = iColor._rgba[3];
  return *this;
}

inline  CATVisColorf& CATVisColorf::operator=(const CATVisColor& iColor)
{
  _rgba[0] = (float)iColor.Red()*CATVisColor::GetRatioToFloat();
  _rgba[1] = (float)iColor.Green()*CATVisColor::GetRatioToFloat();
  _rgba[2] = (float)iColor.Blue()*CATVisColor::GetRatioToFloat();
  _rgba[3] = (float)iColor.Alpha()*CATVisColor::GetRatioToFloat();
  return *this;
}

inline CATVisColorf& CATVisColorf::operator*=(const CATVisColorf& iColor)
{
  _rgba[0] *= iColor._rgba[0];
  _rgba[1] *= iColor._rgba[1];
  _rgba[2] *= iColor._rgba[2];
  _rgba[3] *= iColor._rgba[3];
  return *this;
}

inline CATVisColorf& CATVisColorf::operator*=(const CATVisColor& iColor)
{
  _rgba[0] *= (float)iColor.Red()*CATVisColor::GetRatioToFloat();
  _rgba[1] *= (float)iColor.Green()*CATVisColor::GetRatioToFloat();
  _rgba[2] *= (float)iColor.Blue()*CATVisColor::GetRatioToFloat();
  _rgba[3] *= (float)iColor.Alpha()*CATVisColor::GetRatioToFloat();
  return *this;
}

inline CATVisColorf& CATVisColorf::operator*=(float iScale)
{ 
  _rgba[0] *= iScale;
  _rgba[1] *= iScale;
  _rgba[2] *= iScale;
  _rgba[3] *= iScale;
  return *this;
}

inline CATVisColorf& CATVisColorf::operator+=(const CATVisColorf& iColor)
{
  _rgba[0] += iColor._rgba[0];
  _rgba[1] += iColor._rgba[1];
  _rgba[2] += iColor._rgba[2];
  _rgba[3] += iColor._rgba[3];
  return *this;
}

inline CATVisColorf& CATVisColorf::operator+=(const CATVisColor& iColor)
{   
  _rgba[0] += (float)iColor.Red()*CATVisColor::GetRatioToFloat();
  _rgba[1] += (float)iColor.Green()*CATVisColor::GetRatioToFloat();
  _rgba[2] += (float)iColor.Blue()*CATVisColor::GetRatioToFloat();
  _rgba[3] += (float)iColor.Alpha()*CATVisColor::GetRatioToFloat();
  return *this;
}

inline CATVisColorf& CATVisColorf::operator+=(float iDelta)
{
  _rgba[0] += iDelta;
  _rgba[1] += iDelta;
  _rgba[2] += iDelta;
  _rgba[3] += iDelta;
  return *this;
}

inline void CATVisColorf::AlphaBlend(const CATVisColorf& iCol)
{
  float alpha = iCol.Alpha();
  float minusalpha = 1-alpha;

  _rgba[0] = iCol.Red()  *alpha + _rgba[0]*minusalpha;
  _rgba[1] = iCol.Green()*alpha + _rgba[1]*minusalpha;
  _rgba[2] = iCol.Blue() *alpha + _rgba[2]*minusalpha;
  _rgba[3] = alpha       *alpha + _rgba[3]*minusalpha;
}

inline int CATVisColorf::operator==(const CATVisColorf & iColor) const
{
  return (_rgba[0]== iColor.Red() 
    && _rgba[1]==iColor.Green() 
    && _rgba[2]==iColor.Blue() 
    && _rgba[3]==iColor.Alpha());
}

inline int CATVisColorf::operator!=(const CATVisColorf & iColor) const
{
  return (_rgba[0]!= iColor.Red() 
    || _rgba[1]!=iColor.Green() 
    || _rgba[2]!=iColor.Blue() 
    || _rgba[3]!=iColor.Alpha());
}

inline void CATVisColorf::SetRed(float iRed)
{
  _rgba[0] = iRed;
}

inline void CATVisColorf::SetGreen(float iGreen)
{
  _rgba[1] = iGreen;
}

inline void CATVisColorf::SetBlue(float iBlue)
{
  _rgba[2] = iBlue;
}

inline void CATVisColorf::SetAlpha(float iAlpha)
{
  _rgba[3] = iAlpha;
}

inline void CATVisColorf::SetRGB(float iRed, float iGreen,float iBlue)
{
  SetRed    (iRed);
  SetGreen  (iGreen);
  SetBlue   (iBlue);
}

inline void CATVisColorf::MultiplyRGB(float iScale)
{
  SetRed    (Red()   * iScale);
  SetGreen  (Green() * iScale);
  SetBlue   (Blue()  * iScale);
}

inline void CATVisColorf::SetRGBA(float iRed, float iGreen,float iBlue, float iAlpha)
{
  SetRGB(iRed, iGreen, iBlue);
  SetAlpha(iAlpha);
}

inline float* CATVisColorf::RGBA() const
{
  return (float*) _rgba;
}

#endif
