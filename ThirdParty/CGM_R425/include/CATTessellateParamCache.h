// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessellateParamCache.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2016  Creation: TPG
//===================================================================

#ifndef CATTessellateParamCache_H
#define CATTessellateParamCache_H

#include "ExportedByTessellateCommon.h"
#include "CATMathRefCounted.h"
#include "CATTessSettings.h"
#include "CATBoolean.h"
#include "CATAssert.h"

class CATCGMStream;
class CATCGMUVStreamVersion;

class ExportedByTessellateCommon CATTessellateParamCache : public CATMathRefCounted
{
public:

  inline CATTessellateParamCache();
  
  // This is the constructor to be used for static tessellation
  inline CATTessellateParamCache(
          double iMaxDeviation,
					double iMaxDeviation1D,
          double iMaxAngle,
          double iMaxStep,
          unsigned char iRegularizeOption = 0,
					unsigned short iNbIsoparU=0,
					unsigned short iNbIsoparV=0,
          unsigned char iAdaptiveQualityOption = 0);

  inline CATTessellateParamCache(const CATTessellateParamCache& iTessellateParamCache);
  inline CATTessellateParamCache(const CATTessSettings& iTessSettings);
  
  inline ~CATTessellateParamCache();

  
  inline double GetMaxDeviation()const;
  inline double GetMaxDeviation1D()const;
  inline double GetMaxAngle()const;
  inline double GetMaxStep()const;
  inline unsigned char GetRegularizeOption()const;
  inline unsigned char GetAdaptiveQualityOption()const;
  inline unsigned short GetNbIsoparU()const;
  inline unsigned short GetNbIsoparV()const;

public:

  CATBoolean IsMatching(const CATTessellateParamCache& iParam, double iResolution) const;

  virtual void Stream   (CATCGMStream& iStream, double iResolution) const;
  virtual void UnStream (CATCGMStream& iStream, double iResolution, const CATCGMUVStreamVersion& iCGMUVStreamVersion);

private:
  inline void Reset();

private:
  double _MaxDeviation;
  double _MaxDeviation1D;
  double _MaxAngle;  
  double _MaxStep;  
	unsigned short _NbIsoparU;
	unsigned short _NbIsoparV;
  unsigned char  _RegularizeOption;
  unsigned char  _AdaptiveQualityOption;
};

inline 
CATTessellateParamCache::CATTessellateParamCache()
{
  Reset();
}
  
inline 
CATTessellateParamCache::CATTessellateParamCache(
     double iMaxDeviation,
		 double iMaxDeviation1D,
     double iMaxAngle,
     double iMaxStep,
     unsigned char iRegularizeOption,
		 unsigned short iNbIsoparU,
		 unsigned short iNbIsoparV,
     unsigned char iAdaptiveQualityOption)
:
  _MaxDeviation(iMaxDeviation), 
  _MaxDeviation1D(iMaxDeviation1D), 
  _MaxAngle(iMaxAngle),
  _MaxStep(iMaxStep),
  _RegularizeOption(iRegularizeOption),
	_NbIsoparU(iNbIsoparU),
	_NbIsoparV(iNbIsoparV),
  _AdaptiveQualityOption(iAdaptiveQualityOption)
{
}

inline 
CATTessellateParamCache::CATTessellateParamCache(const CATTessellateParamCache& iTessellateParamCache)
:
  _MaxDeviation(iTessellateParamCache.GetMaxDeviation()), 
  _MaxDeviation1D(iTessellateParamCache.GetMaxDeviation1D()), 
  _MaxAngle(iTessellateParamCache.GetMaxAngle()),
  _MaxStep(iTessellateParamCache.GetMaxStep()),
  _RegularizeOption(iTessellateParamCache.GetRegularizeOption()),
	_NbIsoparU(iTessellateParamCache.GetNbIsoparU()),
	_NbIsoparV(iTessellateParamCache.GetNbIsoparV()),
  _AdaptiveQualityOption(iTessellateParamCache.GetAdaptiveQualityOption())
{
}

inline 
CATTessellateParamCache::CATTessellateParamCache(const CATTessSettings& iTessSettings)
{
  _MaxDeviation=iTessSettings.GetSag();
  _MaxDeviation1D=iTessSettings.GetSag1D();
  _MaxAngle=iTessSettings.GetMaxAngle(); 
  _MaxStep=iTessSettings.GetStep(); 
  _RegularizeOption = iTessSettings.GetTessRegularize();
  _NbIsoparU=iTessSettings.GetCalIsopare() ? iTessSettings.GetNbIsoU():0; 
  _NbIsoparV=iTessSettings.GetCalIsopare() ? iTessSettings.GetNbIsoV():0;
  _AdaptiveQualityOption = iTessSettings.GetTessAdaptiveQuality();
}

inline
CATTessellateParamCache::~CATTessellateParamCache() 
{
  Reset();
}

inline void 
CATTessellateParamCache::Reset()
{
  _MaxDeviation     = 0.0;
  _MaxDeviation1D   = 0.0;
  _MaxAngle         = 0.0;
  _MaxStep          = 0.0;
  _RegularizeOption = 0;
	_NbIsoparU        = 0;
	_NbIsoparV        = 0;
  _AdaptiveQualityOption = 0;
}
  
inline double CATTessellateParamCache::GetMaxDeviation() const   {return _MaxDeviation;}
inline double CATTessellateParamCache::GetMaxDeviation1D() const {return _MaxDeviation1D;}
inline double CATTessellateParamCache::GetMaxAngle() const       {return _MaxAngle;}
inline double CATTessellateParamCache::GetMaxStep() const        {return _MaxStep;}
inline unsigned char CATTessellateParamCache::GetRegularizeOption() const { return _RegularizeOption; }
inline unsigned short CATTessellateParamCache::GetNbIsoparU() const       {return _NbIsoparU;}
inline unsigned short CATTessellateParamCache::GetNbIsoparV() const       {return _NbIsoparV;}
inline unsigned char CATTessellateParamCache::GetAdaptiveQualityOption() const { return _AdaptiveQualityOption; }

#endif

