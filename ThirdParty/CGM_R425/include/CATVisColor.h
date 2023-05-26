// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisColor_H
#define CATVisColor_H

#include "SGInfra.h"
#include "CATGraphicAttributeSet.h"

//-----------------------------------------------------------------------

class CATVisColorf;
class ExportedBySGInfra CATVisColor
{
public:
    CATVisColor(int iRed=255, int iGreen=255,int iBlue=255,int iAlpha=255);
    CATVisColor(unsigned int iColor);
    CATVisColor (const CATVisColor &);
    CATVisColor (const CATVisColorf &);
    ~CATVisColor();

    inline CATVisColor& operator=(const CATVisColor&);
    CATVisColor& operator=(const CATVisColorf&);
    inline int operator ==(const CATVisColor & iColor) const;
    inline int operator !=(const CATVisColor & iColor) const;

    inline unsigned char Red() const;
    inline unsigned char Green() const;
    inline unsigned char Blue() const;
    inline unsigned char Alpha() const;
    inline unsigned int Color() const;
    unsigned char Luminance() const;

    inline void SetRed(int iRed);
    inline void SetGreen(int iGreen);
    inline void SetBlue(int iBlue);
    inline void SetAlpha(int iAlpha);
    inline void SetRGB(int iRed, int iGreen,int iBlue);
    inline void SetRGBA(int iRed, int iGreen,int iBlue,int iAlpha);

    static float GetRatioToFloat();

    void Desaturate();
    void AlphaBlend(const CATVisColor& iColor, int iAlphaFlag=1);

private:
    RGBAStruct _color;
    static float _ratioToFloat;
};

//-----------------------------------------------------------------------

inline unsigned char CATVisColor::Red() const
{
    return _color.extend.red;
}

inline unsigned char CATVisColor::Green() const
{
    return _color.extend.green;
}

inline unsigned char CATVisColor::Blue() const
{
    return _color.extend.blue;
}

inline unsigned char CATVisColor::Alpha() const
{
    return _color.extend.alpha;
}

inline unsigned int CATVisColor::Color() const
{
    return _color.basic;
}

inline  CATVisColor& CATVisColor::operator=(const CATVisColor& iColor)
{
    _color.basic = iColor._color.basic;
    return *this;
}

inline void CATVisColor::SetRed(int iRed)
{
    _color.extend.red = (iRed>255 ? 255 : (iRed<0) ? 0 : iRed);
}

inline void CATVisColor::SetGreen(int iGreen)
{
    _color.extend.green = (iGreen>255 ? 255 : (iGreen<0) ? 0 : iGreen);
}

inline void CATVisColor::SetBlue(int iBlue)
{
    _color.extend.blue = (iBlue>255 ? 255 : (iBlue<0) ? 0 : iBlue);
}

inline void CATVisColor::SetAlpha(int iAlpha)
{
    _color.extend.alpha = (iAlpha>255 ? 255 : (iAlpha<0) ? 0 : iAlpha);
}

inline void CATVisColor::SetRGB(int iRed, int iGreen,int iBlue)
{
    SetRed(iRed);
    SetGreen(iGreen);
    SetBlue(iBlue);
}

inline void CATVisColor::SetRGBA(int iRed, int iGreen,int iBlue, int iAlpha)
{
    SetRGB(iRed, iGreen, iBlue);
    SetAlpha(iAlpha);
}

inline int CATVisColor::operator==(const CATVisColor & iColor) const
{
  return (_color.basic == iColor._color.basic);
}

inline int CATVisColor::operator!=(const CATVisColor & iColor) const
{
  return (_color.basic != iColor._color.basic);
}

#endif
