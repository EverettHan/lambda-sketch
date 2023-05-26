
#ifndef CATHDRPixelIterator_H_
#define CATHDRPixelIterator_H_


#include <CATHDRPixel.h>
#include <vector>

class CATHDRPixelIterator
{

public:
  
  CATHDRPixelIterator() : _width(0), _height(0), _components(0), _data(0) 
  {
  }

  CATHDRPixelIterator(int width, int height, int comp, float* data) :
    _width(width), _height(height), _components(comp), _data(data) 
  {
  }

  template <const int component_count>
  void At(const CATHDRPixel& p, int x, int y) 
  {
    x = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(x, 0), _width-1);
    y = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(y, 0), _height-1);

    if (x < _width && y < _height) 
    {
      const int i = component_count * (x + y*_width);
      
      _data[i] = (float)p.r;
      if (component_count > 1)
        _data[i+1] = (float)p.g;
      if (component_count > 2)
        _data[i+2] = (float)p.b;
    }
  }

  template <const int component_count>
  CATHDRPixel At(int x, int y) const
  {
    x = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(x, 0), _width-1);
    y = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(y, 0), _height-1);
        
    const int i = component_count * (x + y*_width);
    return CATHDRPixel(_data[i], 
      component_count > 1 ? _data[i+1] : 0.0, 
      component_count > 2 ? _data[i+2] : 0.0);   
  }


  void At(const CATHDRPixel& p, int x, int y) 
  {
    x = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(x, 0), _width-1);
    y = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(y, 0), _height-1);
    if (x < _width && y < _height) 
    {
      const int i = _components * (x + y*_width);
      _data[i] = (float)p.r;
      _data[i+1] = (float)p.g;
      _data[i+2] = (float)p.b;
    }
  }

  CATHDRPixel At(int x, int y) const
  {
    x = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(x, 0), _width-1);
    y = CAT_MIN_OVERRIDE(CAT_MAX_OVERRIDE(y, 0), _height-1);

    const int i = _components * (x + y*_width);
    return CATHDRPixel(_data[i], _data[i+1], _data[i+2]);
  }

  int Index(int x, int y) {
    if (x < _width && y < _height) {
      return (x + y*_width);
    }
    return -1;
  }

  RealValue HSVLum(int x, int y) const
  {
    CATHDRPixel p = At(x, y);
    return p.HSVLum();
  }

  RealValue YLum(int x, int y) const
  {
    CATHDRPixel p = At(x, y);
    return p.YLum();
  }

  float* _data;
  int _width, _height;
  int _components;
};


class CATPixelIterator
{
public:
  
  CATPixelIterator() : _width(0), _height(0), _components(0), _data(0) 
  {
  }

  CATPixelIterator(int width, int height, int comp, unsigned char* data) :
    _width(width), _height(height), _components(comp), _data(data) 
  {
  }

  static RealValue Clamp(RealValue v, RealValue minv, RealValue maxv) 
  {
    return v < minv ? minv : (v > maxv ? maxv : v);
  }

  void At(const CATHDRPixel& p, int x, int y) 
  {
    if (x < _width && y < _height) 
    {
      const int i = _components * (x + y*_width);
      _data[i] = (unsigned char)(Clamp(p.r, 0, 1) * 255);
      _data[i+1] = (unsigned char)(Clamp(p.g, 0, 1) * 255);
      _data[i+2] = (unsigned char)(Clamp(p.b, 0, 1) * 255);
    }
  }

  CATHDRPixel At(int x, int y) const
  {
    if (x < _width && y < _height) {
      const int i = _components * (x + y*_width);
      return CATHDRPixel((RealValue)_data[i] / (RealValue)255.0, (RealValue)_data[i+1] / (RealValue)255.0, (RealValue)_data[i+2] / (RealValue)255.0);
    }
    return CATHDRPixel();
  }

  int Index(int x, int y) {
    if (x < _width && y < _height) {
      return (x + y*_width);
    }
    return -1;
  }

  RealValue YLum(int x, int y) const
  {
    CATHDRPixel p = At(x, y);
    return p.YLum();
  }

  RealValue HSVLum(int x, int y) const
  {
    CATHDRPixel p = At(x, y);
    return p.HSVLum();
  }

  unsigned char* _data;
  int _width, _height;
  int _components;
};


struct CATLumIterator
{
  const std::vector<RealValue>& _ref;
  int _width, _height;

  CATLumIterator(const std::vector<RealValue>& ref, int width, int height) :
    _ref(ref), _width(width), _height(height) {
  }

  RealValue At(RealValue u, RealValue v) const {
    int x = (int)(u * _width);
    int y = (int)(v * _height);
    return _ref[x + y*_width];
  }
};

#endif //CATHDRPixelIterator_H_

