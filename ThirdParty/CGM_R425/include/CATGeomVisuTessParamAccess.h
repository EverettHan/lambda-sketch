//===================================================================
// CATGeomVisuTessParamAccess.h
//===================================================================

#ifndef CATGeomVisuTessParamAccess_H
#define CATGeomVisuTessParamAccess_H

#include "SGInfra.h"

#include "CATSysDataType.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"

#include "CATGeomVisuTessParamAccessDefs.h"

class CATGeometry;
class CATGeomVisuTessParam;
class CATTolerance;
class CAT3DBoundingSphere;
class CATIGeomVisuTessParamAccess;

/**
 * Base class to access (get & set) tessellation settings.
 *
 * You might end up here if you want to :
 * 1. GET settings for knowlegde purpose (e.g. dump)
 * - create an access : CreateParamAccess(NULL)
 * - get settings : GetParam()
 * - use GetMode to specify where settings should be taken from and Category to target settings domains
 * 2. GET settings for computation purpose (e.g. tessellation)
 * - create an access, either on the target CATGeometry or not : CreateParamAccess(iGeometry)
 * - if no CATGeometry has been given, you can give info to the access : tolerance (mandatory for any geom accuracy computation) and bounding element (mandatory for proportional geom accuracy computation)
 * - get settings : GetParam() and eventually retrieve computed geom accuracies through CATGeomVisuTessParam::GetComputedXXX methods
 * - use GetMode to specify where settings should be taken from and Category to target settings domains
 * 3. SET settings
 * - create an access : CreateParamAccess(NULL)
 * - define settings in a CATGeomVisuTessParam
 * - set settings : SetParam()
 * - use SetMode to specify where settings should be set to and Category to target settings domains
 * - WARNING : only ToCATSettings SetMode is currently supported ; if you want to override settings locally, you can use CATGeomVisuTessSetting
 *
 */
class ExportedBySGInfra CATGeomVisuTessParamAccess
{
public:

	/** Destructor */
	~CATGeomVisuTessParamAccess();

	/**
		* Create an access to tessellation settings
		* @param iGeometry [in][default NULL]
		* CATGeometry for which you want to get information such as the accuracy to be used for tessellation
		* @return CATGeomVisuTessParamAccess* (NULL if an error occurred)
		*/
	static CATGeomVisuTessParamAccess* CreateParamAccess(CATGeometry* iGeometry = NULL);

	/**
		* Get tessellation settings
		* @param iMode [in]
		* CATGeomVisuTessParamAccessDefs::GetMode to specify where settings should be taken from
		* @param iCategory [in]
		* CATGeomVisuTessParamAccessDefs::Category to target settings domains
		* @param oParam [out]
		* CATGeomVisuTessParam containing tessellation settings
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetParam(CATGeomVisuTessParamAccessDefs::GetMode iMode, CATGeomVisuTessParamAccessDefs::Category iCategory, CATGeomVisuTessParam& oParam) const;

	/**
		* Set tessellation settings
		* @param iMode [in]
		* CATGeomVisuTessParamAccessDefs::SetMode to specify where settings should be set to
		* @param iCategory [in]
		* CATGeomVisuTessParamAccessDefs::Category to target settings domains
		* @param iParam [in]
		* CATGeomVisuTessParam containing tessellation settings (only settings that have been set to the param through dedicated SetXXX methods will be propagated)
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetParam(CATGeomVisuTessParamAccessDefs::SetMode iMode, CATGeomVisuTessParamAccessDefs::Category iCategory, const CATGeomVisuTessParam& iParam) const;

	/**
		* Get target geometry
		* @param oGeometry [out]
		* Target CATGeometry for which tessellation settings are computed
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetGeometry(CATGeometry*& oGeometry) const;

	/**
		* Set tolerance scale
		* @param iToleranceScale [in]
		* Tolerance scale to be used for CATGeomVisuTessParam::GetComputedXXX methods
		* If a CATGeometry has been provided, it will be directly retrieved from the CATTolerance and CATGeoFactory associated thus you cannot provide one.
		* Otherwise, provide one only if you are interested in these methods AND if you want a tolerance scale different from the default one.
		* Scale must be compliant with a scale category provided by CATTolerance::ConvertScaleToScaleCategory
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetToleranceScale(double iToleranceScale);

	/**
		* Get tolerance scale
		* @param oToleranceScale [out]
		* Tolerance scale to be used for CATGeomVisuTessParam::GetComputedXXX methods
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetToleranceScale(double& oToleranceScale) const;

	/**
		* Set bounding element
		* @param iBoundingElement [in]
		* CAT3DBoundingSphere to be used for CATGeomVisuTessParam::GetComputedXXX methods
		* If a CATGeometry has been provided, it will be directly retrieved from it thus you cannot provide one.
		* Otherwise, provide one only if you are interested in these methods AND if you want to get proportional geom accuracies
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT SetBoundingElement(const CAT3DBoundingSphere& iBoundingElement);

	/**
		* Get bounding element
		* @param oBoundingElement [out]
		* CAT3DBoundingSphere to be used for CATGeomVisuTessParam::GetComputedXXX methods
		* @return HRESULT S_OK if success or E_FAIL if error
		*/
	HRESULT GetBoundingElement(CAT3DBoundingSphere& oBoundingElement) const;

private:

	CATGeomVisuTessParamAccess(CATGeometry* iGeometry = NULL);

	CATIGeomVisuTessParamAccess* m_AccessItf;
};

#endif
