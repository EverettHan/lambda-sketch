
#ifndef CATHDRPixel_h_
#define CATHDRPixel_h_

#include "CATVisColorf.h"
#include <CATMath.h>

#define CAT_MIN_OVERRIDE(x, y) (MinOverride((x), (y)))
#define CAT_MAX_OVERRIDE(x, y) (MaxOverride((x), (y)))

typedef float RealValue;

template <typename T>
T MinOverride(const T x, const T y) {
  return (( (x) < (y) ) ? (x) : (y));
}

template <typename T>
T MaxOverride(const T x, const T y) {
  return (( (x) > (y) ) ? (x) : (y));
}

struct HSVPixel
{
  RealValue h, s, v;
};


struct HSLPixel
{
  RealValue h, s, l;
};

struct YUVPixel 
{
  RealValue y, u, v;
};

struct Point2D
{
	short x,y;
};

class CATHDRPixel
{

public:

  RealValue r, g, b;

  CATHDRPixel(RealValue d) : r(d), g(d), b(d) {}
  CATHDRPixel() : r(0), g(0), b(0) {}
  CATHDRPixel(RealValue vr, RealValue vg, RealValue vb) : r(vr), g(vg), b(vb) {}
  CATHDRPixel(CATVisColorf& c) : r(c.Red()), g(c.Green()), b(c.Blue()) {}
  
  inline CATVisColorf GetVisColor() const {
    CATVisColorf c;
    c.SetRed((float)r);
    c.SetGreen((float)g);
    c.SetBlue((float)b);
    return c;
  }

  CATHDRPixel ClipIntensity(RealValue threhsold)
  {
    CATHDRPixel o = *this;
    RealValue v = YLum();
    RealValue m = threhsold / v;
    r *= m; g *= m; b *= m;
    return CATHDRPixel(o.r - r, o.g - g, o.b - b);
  }

  CATHDRPixel CutIntensity(RealValue value) 
  {
    CATHDRPixel o = *this;
    HSVPixel p = HSV();
    p.v -= value;
    From(p);
    return CATHDRPixel(o.r - r, o.g - g, o.b - b);
  }

  void From(const HSVPixel& p)
  {
    if ( p.s == 0 )                       //HSV from 0 to 1
    {
      r = p.v;
      g = p.v;
      b = p.v;
    }
    else
    {
      RealValue var_h = p.h * 6;
      if ( var_h == 6 ) 
        var_h = 0;
       int var_i = int( var_h );
       RealValue var_1 = p.v * ( 1 - p.s );
       RealValue var_2 = p.v * ( 1 - p.s * ( var_h - var_i ) );
       RealValue var_3 = p.v * ( 1 - p.s * ( 1 - ( var_h - var_i ) ) );

       if      ( var_i == 0 ) { r = p.v     ; g = var_3 ; b = var_1; }
       else if ( var_i == 1 ) { r = var_2 ; g = p.v     ; b = var_1; }
       else if ( var_i == 2 ) { r = var_1 ; g = p.v     ; b = var_3; }
       else if ( var_i == 3 ) { r = var_1 ; g = var_2 ; b = p.v;     }
       else if ( var_i == 4 ) { r = var_3 ; g = var_1 ; b = p.v;     }
       else                   { r = p.v     ; g = var_1 ; b = var_2; }
    }
  }

  HSVPixel HSV() const 
  {
    HSVPixel p = {0};
    RealValue var_Min = MinV();
    RealValue var_Max = MaxV();
    RealValue del_Max = var_Max - var_Min;

    p.v = var_Max;
    if ( del_Max == 0 )                     //This is a gray, no chroma...
    {
      p.h = 0;                                //HSV results from 0 to 1
      p.s = 0;
    }
    else                                    //Chromatic data...
    {
      p.s = del_Max / var_Max;

      RealValue del_R = ( ( ( var_Max - r ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
      RealValue del_G = ( ( ( var_Max - g ) / 6 ) + ( del_Max / 2 ) ) / del_Max;
      RealValue del_B = ( ( ( var_Max - b ) / 6 ) + ( del_Max / 2 ) ) / del_Max;

      if      ( r == var_Max ) p.h = del_B - del_G;
      else if ( g == var_Max ) p.h = ( 1 / 3 ) + del_R - del_B;
      else if ( b == var_Max ) p.h = ( 2 / 3 ) + del_G - del_R;

      if ( p.h < 0 ) p.h += 1;
      if ( p.h > 1 ) p.h -= 1;
    }
    return p;
  }

  friend CATHDRPixel operator + (const CATHDRPixel& a, const CATHDRPixel& b) 
  {
    return CATHDRPixel(a.r + b.r, a.g + b.g, a.b + b.b);
  }

  CATHDRPixel operator += (const CATHDRPixel& b) 
  {
    *this = *this + b;
    return *this;
  }

  friend CATHDRPixel operator - (const CATHDRPixel& a, const CATHDRPixel& b) 
  {
    return CATHDRPixel(a.r - b.r, a.g - b.g, a.b - b.b);
  }

  CATHDRPixel operator -= (const CATHDRPixel& b) 
  {
    *this = *this - b;
    return *this;
  }

  RealValue Normalize()
  {
    RealValue d = (RealValue)CATSqrt(r * r + g * g + b * b);
    if (d > 1)
    {
      r /= d;
      g /= d;
      b /= d;
    }
    else
      return 1;
    return d;
  }
  
  friend CATHDRPixel operator * (float v, const CATHDRPixel& h) 
  {
    return CATHDRPixel(h.r * v, h.g * v, h.b * v);
  }

  CATHDRPixel& operator *= (float v) 
  {
    *this = CATHDRPixel(r * v, g * v, b * v);
    return *this;
  }

  CATHDRPixel& operator /= (float v) 
  {
    *this = CATHDRPixel(r / v, g / v, b / v);
    return *this;
  }

  RealValue YLum() const {
    return (RealValue)0.299 * r + (RealValue)0.587 * g + (RealValue)0.114 * b;
  }

  RealValue HSVLum() const
  {    
    //return 0.299 * r + 0.587 * g + 0.114 * b;
    return MaxV();
  }

  RealValue MaxV() const {
    return MaxOverride(MaxOverride(r, g), b);
  }

  RealValue MinV() const {
    return MinOverride(MinOverride(r, g), b);
  }

  YUVPixel YUV() const 
  {
    YUVPixel p;
    p.y = YLum();
    p.u = (RealValue)0.492 * (b - p.y);
    p.v = (RealValue)0.877 * (r - p.y);
    return p;
  }

  void From(const YUVPixel& p)
  {
    r = p.y + (RealValue)1.14 * p.v;
    g = p.y - (RealValue)0.395 * p.u - (RealValue)0.581 * p.v;
    b = p.y + (RealValue)2.033 * p.u;
  }

  void Saturate(const double iSaturation)
  {
    const double pR = 0.299;
    const double pG = 0.587;
    const double pB = 0.114;
    const double p = CATSqrt(r*r*pR + g*g*pG + b*b*pB);
    
    r = (RealValue)(p + ((r-p) * iSaturation));
    g = (RealValue)(p + ((g-p) * iSaturation));
    b = (RealValue)(p + ((b-p) * iSaturation));
  }

};

#endif //CATHDRPixel_h_

