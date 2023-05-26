// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuTexBox.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Sep 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyVisuTexBox_H
#define CATPolyVisuTexBox_H

class CATPolyVisuTexBox
{
public:
  CATPolyVisuTexBox(float iXmin, float iXmax, float iYmin, float iYmax):
      _Xmin(iXmin), _Xmax(iXmax), _Ymin(iYmin), _Ymax(iYmax){}
  CATPolyVisuTexBox():
      _Xmin(1.0f), _Xmax(0), _Ymin(1.0f), _Ymax(0){}

public:
  void Get(float& oXmin, float& oXmax, float& oYmin, float& oYmax)
  {
    oXmin = _Xmin;
    oXmax = _Xmax;
    oYmin = _Ymin;
    oYmax = _Ymax;
  }
  void Set(float iXmin, float iXmax, float iYmin, float iYmax)
  {
    _Xmin = iXmin;
    _Xmax = iXmax;
    _Ymin = iYmin;
    _Ymax = iYmax;
  }
  
  float Xmin() const { return _Xmin;}
  float Ymin() const { return _Ymin;}
  float Xmax() const { return _Xmax;}
  float Ymax() const { return _Ymax;}

  void SetXmin(float iValue) { _Xmin = iValue;}
  void SetYmin(float iValue) { _Ymin = iValue;}
  void SetXmax(float iValue) { _Xmax = iValue;}
  void SetYmax(float iValue) { _Ymax = iValue;}

private:
  float _Xmin, _Ymin, _Xmax, _Ymax;
};


#endif //CATPolyVisuTexBox_H

