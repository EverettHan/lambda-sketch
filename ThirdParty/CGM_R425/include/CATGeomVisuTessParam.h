//===================================================================
// CATGeomVisuTessParam.h
//===================================================================

#ifndef CATGeomVisuTessParam_H
#define CATGeomVisuTessParam_H

#include "SGInfra.h"

#include "CATSysDataType.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"
#include "CATSysMacros.h"

/**
 * Base class that contains tessellation settings
 * Methods are categorized following CATGeomVisuTessParamAccessDefs::Category
 * Each method has an equivalent in CATManageVisuRepository (CATSettings API) so that migration is easy and transparent
 *
 * You might end up here if you want to :
 * 1. GET settings
 * - create an access : CATGeomVisuTessParamAccess::CreateParamAccess()
 * - create empty param CATGeomVisuTessParam()
 * - get settings : CATGeomVisuTessParamAccess::GetParam(oParam)
 * - use CATGeomVisuTessParam API to get target informations
 * - WARNING : only informations related to the given Category are available
 * 2. SET settings
 * - create an access : CATGeomVisuTessParamAccess::CreateParamAccess()
 * - create empty param CATGeomVisuTessParam()
 * - use CATGeomVisuTessParam API to set target informations
 * - set settings : CATGeomVisuTessParamAccess::SetParam(iParam)
 * - WARNING : only informations set to the param using SetXXX API AND related to the given Category will be propagated
 *
 * Methods are categorized following CATGeomVisuTessParamAccessDefs::Category
 */
class ExportedBySGInfra CATGeomVisuTessParam
{
public:

	/** Constructor : create an empty CATGeomVisuTessParam */
	CATGeomVisuTessParam();

	/** @nodoc : copy constructor, internal use only */
	CATGeomVisuTessParam(const CATGeomVisuTessParam& iParam);

	/** @nodoc : equal operator, internal use only */
	CATGeomVisuTessParam& operator=(const CATGeomVisuTessParam& iParam);

	/** Destructor */
	~CATGeomVisuTessParam();

	/** @nodoc : reset all defined settings, internal use only */
	HRESULT Reset();


	//==========//
	// ACCURACY //
	//==========//

	/** Accuracy ( = SAG ) mode
	* @param Proportional : An object will be tessellated based upon the given accuracy AND its bounding element size.
	* @param Fixed : An object will be tessellated based upon the given accuracy only.
	* @param AutoAdaptive : An object will be tessellated based upon an accuracy resulting from autonomous computation (parameters are : 0.2 base-value, bounding element size, model range, local curvature). Only available for 3D.
	* @param AutoAdaptiveCoarse : An object will be tessellated based upon twice the AutoAdaptive accuracy. Only available for 3D. Only available in override mode, dedicated to xApps.
	*/
	enum AccuracyMode { Proportional = 0, Fixed = 1, AutoAdaptive = 2, AutoAdaptiveCoarse = 3 };

	/** Target tesselation dimension
	* @param _2D : construction of 2D representations (CAT2DRep, CATI2DGeoVisu protocol)
	* @param _3D : construction of 3D representations (CAT3DRep, CATI3DGeoVisu protocol)
	* @param _3DCurve : construction of 3D lineic representations (CAT3DRep, CATI3DGeoVisu protocol)
	*/
	enum Dimension { _2D = 0, _3D = 1, _3DCurve = 2 };

	/** Get accuracy mode for 'k'D tessellation [k = 2 or 3] ( ~ CATGet'k'DAccuracyMode() )
		* @param iDim [in] Dimension (allowed values : _2D and _3D)
		* @param oMode [out] AccuracyMode
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetAccuracyMode(Dimension iDim, AccuracyMode& oMode) const;

	/** Set accuracy mode for 'k'D tessellation [k = 2 or 3] ( ~ CATSet'k'DAccuracyMode() )
		* @param iDim [in] Dimension (allowed values : _2D and _3D)
		* @param iMode [in] AccuracyMode
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetAccuracyMode(Dimension iDim, AccuracyMode iMode);

	/** Get accuracy used for 'k'D tessellation [k = 2 or 3] ( ~ CATGet'k'DFixedAccuracy(), CATGet'k'DProportionnalAccuracy(), CATGet3DCurveAccuracy())
		* @param iDim [in] Dimension (allowed values : _2D, _3D, _3DCurve)
		* @param iMode [in] AccuracyMode (WARNING : useless for _3DCurve as the accuracy is independent from the mode)
		* @param oAccuracy [out] Accuracy value (WARNING : for _3DCurve it is actually a ratio to be applied to _3D sag)
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetAccuracy(Dimension iDim, AccuracyMode iMode, double& oAccuracy) const;

	/** Set accuracy used for 'k'D tessellation [k = 2 or 3] ( ~ CATSet'k'DFixedAccuracy(), CATSet'k'DProportionnalAccuracy(), CATSet3DCurveAccuracy())
		* @param iDim [in] Dimension (allowed values : _2D, _3D, _3DCurve) (WARNING : curve accuracy ratio is not editable in AA modes, it is hard coded to 1.0)
		* @param iMode [in] AccuracyMode
		*			WARNING.1 : useless for _3DCurve as the accuracy is independent from the mode
		* 		WARNING.2 : allowed values : Proportional and Fixed (AA accuracies are not editable)
		* @param iAccuracy [in] Accuracy value (WARNING : for _3DCurve it is actually a ratio to be applied to _3D sag)
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetAccuracy(Dimension iDim, AccuracyMode iMode, double iAccuracy);

	/** Get computed accuracy for 'k'D tessellation [k = 2 or 3]
		* It is computed from settings accuracy mode & value, tolerance scale & resolution, bounding element if proportional or AA mode
		* @param iDim [in] Dimension (allowed values : _2D, _3D, _3DCurve)
		* @param oAccuracy [out] accuracy to be used for 'k'D tessellation
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetComputedGeomAccuracy(Dimension iDim, double& oAccuracy) const;

	/** Set computed accuracy for 'k'D tessellation [k = 2 ou 3]
		* WARNING : useless if you are planning to call CATGeomVisuTessParamAccess::SetParam as this value only comes from computation and cannot be set by user
		* @param iDim [in] Dimension (allowed values : _2D, _3D, _3DCurve)
		* @param iAccuracy [in] accuracy to be used for 'k'D tessellation
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetComputedGeomAccuracy(Dimension iDim, double iAccuracy);

	/** @nodoc : internal use only */
	HRESULT HasComputedGeomAccuracyBeenAdjustedByResolution(Dimension iDim, bool& oHas) const;

	/** @nodoc : internal use only */
	HRESULT ComputedGeomAccuracyHasBeenAdjustedByResolution(Dimension iDim, bool iHas);

	/** Get curve accuracy ratio used for V4 models ( ~ CATGetRealV43DCurveAccuracy() )
		* @param oRatio [out] Accuracy ratio
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetRealV43DCurveAccuracyRatio(double& oRatio) const;

	/** Set curve accuracy ratio used for V4 models
		* WARNING : useless if you are planning to call CATGeomVisuTessParamAccess::SetParam as this value only comes from computation and cannot be set by user
		* @param iRatio [in] Accuracy ratio
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetRealV43DCurveAccuracyRatio(double iRatio);

	/** Get transient accuracy mode activation ( ~ CATGetTransientAccMode() )
		* @param oMode [out] Activation boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetTransientAccuracyMode(bool& oMode) const;

	/** Set transient accuracy mode activation ( ~ CATSetTransientAccMode(), CATUnsetTransientAccMode() )
		* @param iMode [in] Activation boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetTransientAccuracyMode(bool iMode);

	/** Get transient accuracy ( ~ CATGetTransientAccMode() )
		* @param oAccuracy [out] Transient accuracy to be used if transient mode is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetTransientAccuracy(double& oAccuracy) const;

	/** Set transient accuracy ( ~ CATSetTransientAccMode() )
		* @param iAccuracy [in]  Transient accuracy to be used if transient mode is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetTransientAccuracy(double iAccuracy);


	//===========//
	// MAX ANGLE //
	//===========//

	/** Get max angle accuracy mode ( ~ CATGetMaxAngleAccuracyMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetMaxAngleAccuracyMode(int& oMode) const;

	/** Set max angle accuracy mode ( ~ CATSetMaxAngleAccuracyMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetMaxAngleAccuracyMode(int iMode);

	/** Get max angle ( ~ CATGetMaxAngle() )
		* @param oAngle [out] max angle to be used if max angle mode is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetMaxAngle(double& oAngle) const;

	/** Set max angle ( ~ CATSetMaxAngle() )
		* @param iAngle [in] max angle to be used if max angle mode is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetMaxAngle(double iAngle);


	//==============//
	// MESH QUALITY //
	//==============//

	/** Get adaptive quality tessellation activation ( ~ CATGetAdaptiveQualityTessellation() )
		* @param oActivated [out] activation boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetAdaptiveQualityActivated(bool& oActivated) const;

	/** Set adaptive quality tessellation activation ( ~ CATSetAdaptiveQualityTessellation() )
		* @param iActivated [in] activation boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetAdaptiveQualityActivated(bool iActivated);

	/** Get optimized mesh mode ( ~ CATGetOptimizedMeshMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetOptimizedMeshMode(unsigned int& oMode) const;

	/** Set optimized mesh mode ( ~ CATSetOptimizedMeshMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetOptimizedMeshMode(unsigned int iMode);

	/** Get max triangles threshold ( ~ CATGetMaxTrianglesThreshold() )
		* @param oThreshold [out] threshold value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetMaxTrianglesThreshold(unsigned int& oThreshold) const;

	/** Set max triangles threshold
		* WARNING : useless if you are planning to call CATGeomVisuTessParamAccess::SetParam as this value only comes from computation (and env variable) and cannot be set by user
		* @param iThreshold [in] threshold value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetMaxTrianglesThreshold(unsigned int iThreshold);


	//=========//
	// ISOPARS //
	//=========//

	/** Get isopar generation ( ~ CATGetIsoparGeneration() )
		* @param oGeneration [out] generation value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetIsoparGeneration(int& oGeneration) const;

	/** Set isopar generation ( ~ CATSetIsoparGeneration() )
		* @param iGeneration [in] generation value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetIsoparGeneration(int iGeneration);

	/** Get instant isopar generation ( ~ CATGetInstantIsoparGeneration() )
		* @param oGeneration [out] generation value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetInstantIsoparGeneration(int& oGeneration) const;

	/** Set instant isopar generation
		* WARNING : useless if you are planning to call CATGeomVisuTessParamAccess::SetParam as this value only comes from computation and cannot be set by user
		* @param iGeneration [in] generation value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetInstantIsoparGeneration(int iGeneration);

	/** Get number of isopars ( ~ CATGetNbIsopars() )
		* @param oNbIsopars [out] number of isopars to be generated if isopars generation is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetNbIsopars(int& oNbIsopars) const;

	/** Set number of isopars ( ~ CATSetNbIsopars() )
		* @param oNbIsopars [out] number of isopars to be generated if isopars generation is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetNbIsopars(int iNbIsopars);


	//==============//
	// SMOOTH EDGES //
	//==============//

	/** Get threshold activation ( ~ CATGetEdgeHighCurvatureStepThresholdActivated() )
		* @param oActivated [out] activation boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetEdgeHighCurvatureStepThresholdActivated(bool& oActivated) const;

	/** Set threshold activation ( ~ CATSetEdgeHighCurvatureStepThresholdActivated() )
		* @param iActivated [in] activation boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetEdgeHighCurvatureStepThresholdActivated(bool iActivated);

	/** Get threshold ( ~ CATGetEdgeHighCurvatureStepThreshold() )
		* @param oThreshold [out] threshold to be used if activation is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetEdgeHighCurvatureStepThreshold(double& oThreshold) const;

	/** Set threshold ( ~ CATSetEdgeHighCurvatureStepThreshold() )
		* @param iThreshold [in] threshold to be used if activation is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetEdgeHighCurvatureStepThreshold(double iThreshold);


	//====//
	// UV //
	//====//

	/** Get UV Mesh0 mode ( ~ CATGetUVMesh0Mode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetUVMesh0Mode(int& oMode) const;

	/** Set UV Mesh0 mode ( ~ CATSetUVMesh0Mode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetUVMesh0Mode(int iMode);

	/** Get UV Mesh0 accuracy ( ~ CATGetTargetSagForMesh0() )
		* @param oAccuracy [out] target accuracy for Mesh0 if mode is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetUVMesh0Accuracy(double& oAccuracy) const;

	/** Set UV Mesh0 accuracy ( ~ CATSetTargetSagForMesh0() )
		* @param iAccuracy [in] target accuracy for Mesh0 if mode is on
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetUVMesh0Accuracy(double iAccuracy);

	/** Get UV external discretization mode ( ~ CATGetExternalDiscretizationMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetUVExternalDiscretizationMode(int& oMode) const;

	/** Get UV external discretization mode ( ~ CATsetExternalDiscretizationMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetUVExternalDiscretizationMode(int iMode);


	//=====//
	// WTT //
	//=====//

	// WARNING : following methods are only meaningful under #define CATWTTModeDefinition

	/** Get WTT Visu mode ( ~ CATGetWTTVisuMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetWTTVisuMode(int& oMode) const;

	/** Set WTT Visu mode ( ~ CATSetWTTVisuMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetWTTVisuMode(int iMode);

	/** Get WTT Regularization mode ( ~ CATGetRegularizationMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetWTTRegularizationMode(int& oMode) const;

	/** Set WTT Regularization mode ( ~ CATSetRegularizationMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetWTTRegularizationMode(int iMode);


	//===========//
	// SHARPNESS //
	//===========//

	/** Get sharpness mode ( ~ CATGetSharpnessMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetSharpnessMode(int& oMode) const;

	/** Set sharpness mode ( ~ CATSetSharpnessMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetSharpnessMode(int iMode);

	//=========//
	// WYSIWYG //
	//=========//

	/** Get wysiwyg mode ( ~ CATGetWysiwygMode() )
		* @param oMode [out] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetWysiwygMode(int& oMode) const;

	/** Set wysiwyg mode ( ~ CATSetWysiwygMode() )
		* @param iMode [in] mode value
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetWysiwygMode(int iMode);


	//======//
	// LOCK //
	//======//

	// WARNING : Lock tag needs to be cumulated with the right tag in order to call these methods

	// Accuracy

	/** Get lock status for accuracy mode CATSetting ( ~ CATGetLock'k'DAccuracyMode() )
		* @param iDim [in] Dimension (allowed values : _2D and _3D)
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockAccuracyMode(Dimension iDim, bool& oLock) const;

	/** Set lock status for accuracy mode CATSetting ( ~ CATSetLock'k'DAccuracyMode() )
		* @param iDim [in] Dimension (allowed values : _2D and _3D)
		* @param iLock [in] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockAccuracyMode(Dimension iDim, bool iLock);

	/** Get lock status for accuracy CATSetting ( ~ CATGetLock'k'DFixedAccuracy(), CATGetLock'k'DProportionnalAccuracy(), CATGetLock3DCurveAccuracy() )
		* @param iDim [in] Dimension (allowed values : _2D, _3D, _3DCurve)
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockAccuracy(Dimension iDim, AccuracyMode iMode, bool& oLock) const;

	/** Set lock status for accuracy CATSetting ( ~ CATSetLock'k'DFixedAccuracy(), CATSetLock'k'DProportionnalAccuracy(), CATSetLock3DCurveAccuracy() )
		* @param iDim [in] Dimension (allowed values : _2D, _3D, _3DCurve)
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockAccuracy(Dimension iDim, AccuracyMode iMode, bool iLock);

	// Mesh Quality

	/** Get lock status for adaptive quality activation CATSetting ( ~ CATGetLockAdaptiveQualityTessellation() )
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockAdaptiveQualityActivated(bool& oLock) const;

	/** Set lock status for adaptive quality activation CATSetting ( ~ CATGetLockAdaptiveQualityTessellation() )
		* @param iLock [in] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockAdaptiveQualityActivated(bool iLock);

	/** Get lock status for optimized mesh mode CATSetting ( ~ CATGetLockOptimizedMeshMode() )
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockOptimizedMeshMode(bool& oLock) const;

	/** Set lock status for optimized mesh mode CATSetting ( ~ CATSetLockOptimizedMeshMode() )
		* @param iLock [in] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockOptimizedMeshMode(bool iLock);

	// Isopars

	/** Get lock status for isopar generation CATSetting ( ~ CATGetLockIsoparGeneration() )
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockIsoparGeneration(bool& oLock) const;

	/** Set lock status for isopar generation CATSetting ( ~ CATSetLockIsoparGeneration() )
		* @param iLock [in] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockIsoparGeneration(bool iLock);

	// Smooth Edges

	/** Get lock status for smooth edges threshold activation CATSetting ( ~ CATGetLockEdgeHighCurvatureStepThresholdActivated() )
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockEdgeHighCurvatureStepThresholdActivated(bool& oLock) const;

	/** Set lock status for smooth edges threshold activation CATSetting ( ~ CATSetLockEdgeHighCurvatureStepThresholdActivated() )
		* @param iLock [in] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockEdgeHighCurvatureStepThresholdActivated(bool iLock);

	/** Get lock status for smooth edges threshold CATSetting ( ~ CATGetLockEdgeHighCurvatureStepThreshold() )
		* @param oLock [out] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetLockEdgeHighCurvatureStepThreshold(bool& oLock) const;

	/** Set lock status for smooth edges threshold CATSetting ( ~ CATSetLockEdgeHighCurvatureStepThreshold() )
		* @param iLock [in] lock boolean
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetLockEdgeHighCurvatureStepThreshold(bool iLock);


private:

	template <typename T>
	struct VAR
	{
		T* _val;
		bool _lock;

		VAR() {
			_val = NULL;
			_lock = false;
		}

		VAR(const VAR& iV) {
			*this = iV;
		}

		VAR& operator=(const VAR& iV) {
			if (iV._val)
				SetVal(*(iV._val));
			else
				CATSysDeletePtr(_val);

			_lock = iV._lock;

			return *this;
		}

		~VAR() {
			CATSysDeletePtr(_val);
		}

		void SetVal(T iVal) {
			if (!_val)
				_val = new T(iVal);
			else
				*_val = iVal;
		}

		T GetVal() const {
			return _val ? *_val : (T)0;
		}
	};

	template <typename T>
	inline static T GetValue(const VAR<T>& iVar) {
		return iVar.GetVal();
	}

	template <typename T>
	inline static void SetValue(T val, VAR<T>& iVar) {
		iVar.SetVal(val);
	}

	template <typename T>
	inline static bool IsDefined(const VAR<T>& iVar) {
		return !!iVar._val;
	}

	template <typename T>
	inline void SetDefined(bool def, VAR<T>& iVar) {
		_Virgin = false;
	}

	template <typename T>
	inline static bool IsLocked(const VAR<T>& iVar) {
		return iVar._lock;
	}

	template <typename T>
	inline void SetLocked(bool lock, VAR<T>& iVar) {
		_Virgin = false;
		iVar._lock = lock;
	}

	inline static bool IsValid(AccuracyMode iMode) {
		return (iMode == Proportional || iMode == Fixed || iMode == AutoAdaptive || iMode == AutoAdaptiveCoarse);
	}

	inline static bool IsValid(Dimension iDim) {
		return (iDim == _2D || iDim == _3D || iDim == _3DCurve);
	}

	inline static bool IsAA(AccuracyMode iMode) {
		return (iMode == AutoAdaptive || iMode == AutoAdaptiveCoarse);
	}

	inline static bool IsValid(Dimension iDim, AccuracyMode iMode, bool noAA) {
		bool valid = false;
		switch (iDim)
		{
		case _2D :
			valid = (IsValid(iMode) && !IsAA(iMode));
			break;
		case _3D :
			valid = (IsValid(iMode) && !(noAA && IsAA(iMode)));
			break;
		}
		return valid;
	}

	// Accuracy
	VAR<AccuracyMode>	_AccuracyMode[4] = {};
	VAR<double>				_Accuracies[2][2] = {}; // [2D, 3D] x [Prop, Fixed]
	VAR<double>				_AccuracyRatios[2] = {}; // [3DCurveRatio, RealV4CurveRatio]
	VAR<double>				_GeomAccuracies[3] = {};
	bool							_GeomAccuracyHasBeenAdjustedByResolution[3] = {};
	VAR<bool>					_TransientAccuracyMode;
	VAR<double>				_TransientAccuracy;

	// Max Angle
	VAR<int>			_MaxAngleAccuracyMode;
	VAR<double>		_MaxAngle;

	// Mesh Quality
	VAR<unsigned int>	_OptmizedMeshMode;
	VAR<bool>					_AdaptiveQuality;
	VAR<unsigned int> _MaxTrianglesThreshold;

	// Isopars
	VAR<int>			_IsoparGeneration;
	VAR<int>			_InstantIsoparGeneration;
	VAR<int>			_NbIsopars;

	// Smooth Edges Curvature Step Threshold
	VAR<bool>			_EdgeHighCurvatureStepThresholdActivated;
	VAR<double>		_EdgeHighCurvatureStepThreshold;

	// UV
	VAR<int>			_UVMesh0Mode;
	VAR<double>		_UVMesh0Accuracy;
	VAR<int>			_UVExternalDiscretizationMode;

	// WTT
	VAR<int>			_WTTVisuMode;
	VAR<int>			_WTTRegularizationMode;

	// Sharpness
	VAR<int>			_SharpnessMode;

	// Wysiwyg
	VAR<int>			_WysiwygMode;

	// Reset criteria
	bool _Virgin = true;
};

#endif
