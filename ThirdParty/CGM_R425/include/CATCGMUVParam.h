// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVParam.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2011  Creation: MPX
//===================================================================

#ifndef CATCGMUVParam_H
#define CATCGMUVParam_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATAssert.h"



class CATCGMStream;
class CATCGMUVStreamVersion;

#define CATCGMUVEnumType unsigned char

class ExportedByTessellateCommon CATCGMUVParam
{
public:

  inline CATCGMUVParam();
  
  // This is the constructor to be used for UV tessellation
  inline CATCGMUVParam(
          double iMaxDeviation, 
          CATCGMUVEnumType iMaxRefinementLevel, 
          CATCGMUVEnumType iRefinementMode, 
          CATCGMUVEnumType iFormat);

  // This is the constructor to be used for static tessellation
  inline CATCGMUVParam(
          double iMaxDeviation,
          double iMaxAngle,
          double iMaxStep,
          CATCGMUVEnumType iFormat,
          int Useless); /* It avoids a conflict between the constructors */
  
  inline ~CATCGMUVParam();

  
  inline double GetMaxDeviation();
  inline double GetMaxAngle();
  inline double GetMaxStep();
  inline CATCGMUVEnumType GetMaxRefinementLevel();
  inline CATCGMUVEnumType GetRefinementMode();
  inline CATCGMUVEnumType GetFormat() const;

public:

  CATBoolean IsMatching(const CATCGMUVParam& iParam, double iResolution) const;

  virtual void Stream   (CATCGMStream& iStream, double iResolution) const;
  virtual void UnStream (CATCGMStream& iStream, double iResolution, const CATCGMUVStreamVersion& iCGMUVStreamVersion);

private:
  inline void Reset();

private:
  double _MaxDeviation;
  double _MaxAngle;  // Only used in Static tessellation
  double _MaxStep;   // Only used in Static tessellation
  CATCGMUVEnumType _MaxRefinementLevel; // Only Used for UV Tessellation
  CATCGMUVEnumType _RefinementMode;  // Only Used for UV Tessellation
  CATCGMUVEnumType _Format;
};






inline 
CATCGMUVParam::CATCGMUVParam()
{
  Reset();
}
  
inline 
CATCGMUVParam::CATCGMUVParam(
     double iMaxDeviation, 
     CATCGMUVEnumType iMaxRefinementLevel, 
     CATCGMUVEnumType iRefinementMode, 
     CATCGMUVEnumType iFormat)
:
  _MaxDeviation(iMaxDeviation), 
  _MaxAngle(0.0),
  _MaxStep(0.0),
  _MaxRefinementLevel(iMaxRefinementLevel),
  _RefinementMode(iRefinementMode), 
  _Format(iFormat)
{
  CATSysCheckExpression(_Format != 0); // 0 stands for CATCGMUVCommonSettings::Static
}

inline 
CATCGMUVParam::CATCGMUVParam(
     double iMaxDeviation, 
     double iMaxAngle,
     double iMaxStep,
     CATCGMUVEnumType iFormat,
     int Useless)
:
  _MaxDeviation(iMaxDeviation), 
  _MaxAngle(iMaxAngle),
  _MaxStep(iMaxStep),
  _MaxRefinementLevel(0),
  _RefinementMode(0), 
  _Format(iFormat)
{
  CATSysCheckExpression(_Format == 0) ;// 0 stands for CATCGMUVCommonSettings::Static
}

inline
CATCGMUVParam::~CATCGMUVParam() 
{
  Reset();
}

inline void 
CATCGMUVParam::Reset()
{
  _MaxDeviation = 0.0;
  _MaxAngle     = 0.0;
  _MaxStep      = 0.0;
  _MaxRefinementLevel = 0; 
  _RefinementMode = 0; 
  _Format = 0;
}

  
inline double CATCGMUVParam::GetMaxDeviation()        {return _MaxDeviation;}
inline double CATCGMUVParam::GetMaxAngle()            {return _MaxAngle;}
inline double CATCGMUVParam::GetMaxStep()             {return _MaxStep;}
inline CATCGMUVEnumType    CATCGMUVParam::GetMaxRefinementLevel()  {return _MaxRefinementLevel;}
inline CATCGMUVEnumType    CATCGMUVParam::GetRefinementMode()      {return _RefinementMode;}
inline CATCGMUVEnumType    CATCGMUVParam::GetFormat() const        {return _Format;}


#endif
