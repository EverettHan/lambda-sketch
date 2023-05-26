// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessParam.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2012  Creation: ZFI
//===================================================================

// copied from CATCGMUVCommonSettings->public view of settings under 
// convergence

#ifndef CATCGMUVTessParam_H
#define CATCGMUVTessParam_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATCGMUVParam.h"

class CATSoftwareConfiguration;

class ExportedByTessellateCommon CATCGMUVTessParam
{
public:
  enum Format_T
  {
    Static = 0,
    Dynamic
  };

public:
  CATCGMUVTessParam(CATSoftwareConfiguration* iSoftwareConfig, double iMaxDeviation, Format_T iFormat);
  virtual ~CATCGMUVTessParam();
  CATCGMUVTessParam(const CATCGMUVTessParam &iTessParamToCopy);

public:
  CATSoftwareConfiguration* GetSoftwareConfiguration(){return _SoftwareConfiguration;}
  double GetMaxDeviation(){return _MaxDeviation;}
  Format_T GetFormat(){return _Format;}

  // MaxStep (only for Static format) - default MaxStep = CATMathInfinite
  void SetMaxStep(double iMaxStep){_MaxStep = iMaxStep;}
  double GetMaxStep(){return _MaxStep;}

  // MaxAngle (only for Static format) - default MaxAngle = CATPI * 0.25
  void SetMaxAngle(double iMaxAngle){_MaxAngle = iMaxAngle;}
  double GetMaxAngle(){return _MaxAngle;}

public:
  void DoGenerateVertexNormals(CATBoolean iActivate){_GenerateVertexNormals=iActivate;}
  CATBoolean GenerateVertexNormals(){return _GenerateVertexNormals;}
  
  void DoGenerateVertexUVs(CATBoolean iActivate){_GenerateVertexUVs=iActivate;}
  CATBoolean GenerateVertexUVs(){return _GenerateVertexUVs;}

  void DoGenerateVertexWs(CATBoolean iActivate){_GenerateVertexWs=iActivate;}
  CATBoolean GenerateVertexWs(){return _GenerateVertexWs;}
 
  void DoGenerateVertexTangents(CATBoolean iActivate){_GenerateVertexTangents=iActivate;}
  CATBoolean GenerateVertexTangents(){return _GenerateVertexTangents;}

private:
  CATSoftwareConfiguration * _SoftwareConfiguration;
  double _MaxDeviation;
  double _MaxStep;
  double _MaxAngle;
  Format_T _Format;
  CATBoolean _GenerateVertexNormals, _GenerateVertexUVs,_GenerateVertexWs,_GenerateVertexTangents;
};

#endif
