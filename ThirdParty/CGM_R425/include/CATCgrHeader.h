#ifndef CATCgrHeader_H
#define CATCgrHeader_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1997
//******************************************************************************
//  Abstract:
//  ---------
//    This class describes the save caractritics of cgr file : version number
//    setting .
//
//******************************************************************************
//  Usage:
//  ------
//    Object used by CATWriteCgr & CATReadCgr functions
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATBaseUnknown (SYSTEM Framework).
//
//******************************************************************************
//  Main Methods:
//  -------------
//    . Set Current version
//    . Set setting use 
//
//******************************************************************************

#include "SGInfra.h"
#include "CATVizBaseIUnknown.h"
#include "CATReadWriteCgr.h"
#include "CATMathPointf.h"
#include "CATListOfInt.h"

#include "CATSysDataType.h"
#include "CATSysErrorDef.h"
#include "CATSysBoolean.h"

class CAT3DLightSourceRep;
class CAT3DViewpoint;
class CATRep;
class CATSGData;

class ExportedBySGInfra CATCgrHeader : public CATVizBaseIUnknown
{
	friend class CATDmuStreamCgrHeader;
	friend class SGTestEditHeaderPrivate;
	CATDeclareClass_Deprec;

public:

	CATCgrHeader();

	virtual ~CATCgrHeader(void);

	enum CGRType
	{
		UNDEFINEDREP = 0,
		AV1 = 1,
		REVIEWREP = 2,
		PLAYREP = 3,
		BACKGROUNDREP = 4
	};

	void  SetSetting(CATSettingCgr newSetting);
	CATSettingCgr GetSetting(void);
	int   GetSetting(CATSettingCgr iSetting);

	int   GetVersionNumber(void);
	void  SetVersionNumber(int iVersionNumber);

	void  SetSagMode(int iMode);
	int   GetSagMode(void);
	void  Get3DSagInformations(int &_sagmode, double &_sagvalue, double &_curvevalue);
	void  Get2DSagInformations(int &_sagmode, double &_sagvalue);

	/////////////////////////////////////////////DEPRECATED METHODS ////////////////////////////////////
		/** @deprecated R420 : Use double instead.*/
	void  Get3DSagInformations(int &_sagmode, float &_sagvalue, float &_curvevalue);
	/** @deprecated R420 : Use double instead.*/
	void  Get2DSagInformations(int &_sagmode, float &_sagvalue);
	/////////////////////////////////////////END DEPRECATED METHODS ////////////////////////////////////

	void  Set3DSagInformations(int isagmode, double isagvalue, double icurvevalue);
	void  Set2DSagInformations(int isagmode, double isagvalue);

	void  GetTessellationInformations(CATULONG32 & oMaxTriangleThresholdForTessellation, CATULONG32 & oRegularizationSettingForTessellation);
	void  SetTessellationInformations(CATULONG32 iMaxTriangleThresholdForTessellation, CATULONG32 iRegularizationSettingForTessellation);

	void  GetAdaptiveQualityForTessellation(CATULONG32 & oAdaptiveQualityTessellation);
	void	SetAdaptiveQualityForTessellation(CATULONG32 iAdaptiveQualityTessellation);

	void GetEdgeHighCurvatureStepInformations(CATBoolean& oActivated, double& oThreshold);
	void SetEdgeHighCurvatureStepInformations(CATBoolean iActivated, double iThreshold);

	int   GetWireGaps();
	int   GetEdgeSmoothness();
	//GetSensitiveMode retourne 1 si l'option sensitive Mode n'st PAS active.
	int   GetSensitiveMode(void);
	int   GetV4TextMode(void);

	int   GetTimeStamp(void);

	void  GetBoundingBox(CATMathPointf& oMinPoint, CATMathPointf& oMaxPoint);

	void  SetComment(char * iComment);
	/*Le pointeur retournée doit être détruit avec l'opérateur DELETE*/
	char* GetComment(void);

	void  SetLightSources(CAT3DLightSourceRep** iLightSources, int nbLightSources);
	void  GetLightSources(CAT3DLightSourceRep**& oLightSources, int& nbLightSources);

	void  SetViewpoint(CAT3DViewpoint *iViewpoint);
	CAT3DViewpoint* GetViewpoint(void);

	inline void  SetToleranceScale(float iScale);

	/**
	 return code S_FALSE : invalid Tolerance (for example LargeScale node under normalScale node)
	 return code    S_OK : oScale == 0.f: undefined scale  factor.
												 oSCale > 0.f : highest scale factor of the scenegraph.
	*/
	inline HRESULT GetToleranceScale(float &oScale) const;

	void  SetRep(CATRep* iRep);

	void GetLodsSags(const float * & oSags, int & oNbContainers) const;

	CATBoolean GetUseCATSettingsWhenStreaming() const;
	void SetUseCATSettingsWhenStreaming(CATBoolean iValue);

	CATCgrHeader::CGRType GetCGRType();
	void                  SetCGRType(CATCgrHeader::CGRType iCGRType);

private:

	CATSettingCgr               _setting;
	int                         _versionNumber;
	int                         _3Dsagmode;
	double                      _3Dsag;
	double                      _3Dcurvesag;
	int                         _2Dsagmode;
	double                      _2Dsag;
	int                         _wireGaps;
	int                         _edgeSmoothness;
	CATLONG32                   _timestamp;
	int                         _V4Text3D;
	int                         _sensitiveMode;
	CATMathPointf               _minPoint;
	CATMathPointf               _maxPoint;
	char*                       _comment;
	int                         _nbLightSources;
	CAT3DLightSourceRep**       _lightSourceArray;
	CAT3DViewpoint*             _viewpoint;
	float												_ToleranceScale;
	CATRep*                     _rep;
	float   *                   _LODSags;
	int                         _nbLODContainers;
	CATULONG32									_MaxTriangleThresholdForTessellation;
	CATULONG32									_RegularizationSettingForTessellation;
	CATULONG32									_AdaptiveQualityTessellationVersion;
	CATBoolean									_UseCATSettingsWhenStreaming;
	CGRType                     _CGRType;
	CATBoolean									_EdgeHighCurvatureStepThresholdActivated;
	double											_EdgeHighCurvatureStepThreshold;

	// E8C : to be used for any new attribute, in order to change header content without new CGR version
	// See CATCgrHeader constructor implementation for more details on how to use
	CATSGData*									_DATA;

	int   ComputeBoundingBox(void);

	/**
	return -1.f : unvalid scenegraph in terms of scalefactor (i.e a node of a specific scale contains another node with higher scale factor).
	return  0.f : no scale factor defined in scenegraph.
	else        : highest scalefactor of the scenegraph.
	*/
	HRESULT ComputeScaleFactor(void);
	HRESULT RecursiveComputeScaleFactor(CATRep *iRep);

	CATListOfInt _tolScaleStack;
};

inline void  CATCgrHeader::SetToleranceScale(float iScale) { _ToleranceScale = iScale; };
inline HRESULT CATCgrHeader::GetToleranceScale(float &oScale) const
{
	if (_ToleranceScale == -1.f)
	{
		oScale = 0.f;
		return S_FALSE;
	}
	else
	{
		oScale = _ToleranceScale;
		return S_OK;
	}
};

#endif
