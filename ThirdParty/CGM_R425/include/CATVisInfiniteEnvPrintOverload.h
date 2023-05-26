// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisInfiniteEnvPrintOverload_H
#define CATVisInfiniteEnvPrintOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATVisColor.h"

class ExportedByCATVisFoundation CATVisInfiniteEnvPrintOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvPrintOverload* Create();

  // Default mode
  void SetBasicMode();

  // White Background mode
  // following ambiance parameters are modified:
  // * all backgrounds are replaced by a uniform white backgroung
  // * ground/grid are removed
  // * if iForceDefaultLighting is set to true, all lighting is replaced by default lighting (i.e. lighting in Basic Ambiance)
  // * all post effects are removed (DOF, bloom, styles)
  void SetWhiteBackgroundMode(bool iForceDefaultLighting = true);

  // Uniform Background mode
  // idem than SetWhiteBackgroundMode, but color of background can be define with (iR, iG, iB, iA)
  void SetUniformBackgroundMode(int iR=255, int iG=255, int iB=255, int iA=255, 
                                bool iForceDefaultLighting = true); 

  // to remove
  void SetPlaneInZBuffer(int iPlaneInZBufferMode);

  void SetTileMode(unsigned int iTileSize, unsigned int iWidth, unsigned int iHeight);

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;
  virtual void Overload(CATVisAmbiance& ioData) const;
  virtual void Overload(CATVisPostEffects& ioData) const;

  CATVisInfiniteEnvPrintOverload();
  virtual ~CATVisInfiniteEnvPrintOverload();

  unsigned int _whiteMode;
  CATVisColor  _bgCol;
  bool         _lightingOverload;

  unsigned int _tileMode;
  float        _tileRatio;
  int _planeInZBuffer;
};

//-----------------------------------------------------------------------

#endif
