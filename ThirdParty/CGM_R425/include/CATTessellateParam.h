// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessellateParam.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2012  Creation: TPG
//===================================================================

// copied from CATCGMUVCommonSettings->public view of settings under 
// convergence

#ifndef CATTessellateParam_H
#define CATTessellateParam_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATCGMUVParam.h"
#include "CATTessellateParamCache.h"

class CATSoftwareConfiguration;
class CATCGMTessellateParam;
class CATTessSettings;

class ExportedByTessellateCommon CATTessellateParam
{
public:
  enum Format_T
  {
    Static = 0,
    Dynamic,
    Dynamic_PNTWithTangents
  };

public:
  CATTessellateParam(CATSoftwareConfiguration* iSoftwareConfig, double iMaxDeviation, Format_T iFormat);
  virtual ~CATTessellateParam();
  CATTessellateParam(const CATTessellateParam &iTessParamToCopy);
  CATTessellateParam(CATSoftwareConfiguration* iSoftwareConfig, const CATCGMTessellateParam &iTessellateParam);
  CATTessellateParam(CATSoftwareConfiguration* iSoftwareConfig, const CATTessSettings &iTessSettings);
  CATBoolean IsEqualTo(const CATTessellateParam& iOther, double iLengthTol, double iAngleTol) const;

public:
  CATSoftwareConfiguration* GetSoftwareConfiguration()const{return _SoftwareConfiguration;}
  void SetMaxDeviation(double iMaxDeviation){_MaxDeviation = iMaxDeviation;}
  double GetMaxDeviation()const{return _MaxDeviation;}
  void SetFormat(Format_T iFormat){_Format = iFormat;}
  Format_T GetFormat()const{return _Format;}

  // MaxStep (only for Static format) - default MaxStep = CATMathInfinite
  void SetMaxStep(double iMaxStep){_MaxStep = iMaxStep;}
  double GetMaxStep()const{return _MaxStep;}

  // MaxAngle (only for Static format) - default MaxAngle = CATPI * 0.25
  void SetMaxAngle(double iMaxAngle){_MaxAngle = iMaxAngle;}
  double GetMaxAngle()const{return _MaxAngle;}

  // Isopars (only for Static format) - default 0,0
  void SetNbIsopars(unsigned short iNbIsoparU, unsigned short iNbIsoparV){_NbIsoparU = iNbIsoparU; _NbIsoparV = iNbIsoparV;}
  void GetNbIsopars(unsigned short & oNbIsoparU, unsigned short & oNbIsoparV)const{oNbIsoparU = _NbIsoparU; oNbIsoparV = _NbIsoparV;}

	// Regularize Option
	// 0 : standard, no regularization
	void SetTessRegularize(CATLONG32 iRegularizeOption){_RegularizeOption = iRegularizeOption;};
	CATLONG32 GetTessRegularize() const{return _RegularizeOption;};

  // Adaptive quality Option
  // 0 : standard, no adaptive quality
  void SetTessAdaptiveQuality(CATLONG32 iAdaptiveQualityOption) { _AdaptiveQualityOption = iAdaptiveQualityOption; };
  CATLONG32 GetTessAdaptiveQuality() const { return _AdaptiveQualityOption; };

  //Mise en Contexte  de conversion GMPolyBody
  void SetGMPolyTessBodyContext(int iGMPolyTessBodyContext) { _GMPolyTessBodyContext = iGMPolyTessBodyContext; };
	HRESULT GetTessellateParamCache(CATTessellateParamCache& oParam) const;
	HRESULT GetTessSettings(CATTessSettings& oTessSettings) const;

public:
  void DoGenerateVertexNormals(CATBoolean iActivate){_GenerateVertexNormals=iActivate;}
  CATBoolean GenerateVertexNormals()const{return _GenerateVertexNormals;}
  
  void DoGenerateVertexUVs(CATBoolean iActivate){_GenerateVertexUVs=iActivate;}
  CATBoolean GenerateVertexUVs()const{return _GenerateVertexUVs;}

  void DoGenerateVertexWs(CATBoolean iActivate){_GenerateVertexWs=iActivate;}
  CATBoolean GenerateVertexWs()const{return _GenerateVertexWs;}
 
  void DoGenerateVertexTangents(CATBoolean iActivate){_GenerateVertexTangents=iActivate;}
  CATBoolean GenerateVertexTangents()const{return _GenerateVertexTangents;}

  int GetGMPolyBodyContext() const { return _GMPolyTessBodyContext; };

private:
  CATSoftwareConfiguration * _SoftwareConfiguration;
	CATTessSettings * _TessSettings;

	Format_T _Format;
  double _MaxDeviation;

	double _MaxStep;
  double _MaxAngle;
	unsigned short _NbIsoparU;
  unsigned short _NbIsoparV;
  CATLONG32 _RegularizeOption;
  CATLONG32 _AdaptiveQualityOption;
  int _GMPolyTessBodyContext;
  
	CATBoolean _GenerateVertexNormals, _GenerateVertexUVs,_GenerateVertexWs,_GenerateVertexTangents;
};

#endif
