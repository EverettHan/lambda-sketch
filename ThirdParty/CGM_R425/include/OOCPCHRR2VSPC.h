#ifndef OOCPCHRR2VSURVEY_H
#define OOCPCHRR2VSURVEY_H

/**
 * @file
 *
 * @brief Custom HRESULT codes for OOCPC's R2V Survey service component/facility.
 *
 * @details
 * This specific header is also used as an example for defining dedicated
 * component/facility HRESULTs, as such it contains extra comments on how
 * to define codes/HRESULTs.
 */


#include "OOCPCHRESULT.h"

 /**
  * @brief Codes dedicated to the builder facility/component for custom OOCPC HRESULT
  *
  * @details
  * As described for OOCPCCode and in various places of the OOCPCHRESULT.h header:
  *  - facility-dedicated codes should be defined via an enum class
  *  - the enum class should have std::uint32_t as underlying type
  *  - the dedicated code values should belong to the range 0x80 - 0x1FFF (both bound inclusive)
  *  - the helper value OOCPCCode::eCOMPONENT_SPECIFIC_START matches the start of the above range (0x80)
  *  - that helper value should be used as static_cast<std::uint32_t>(OOCPCCode::eCOMPONENT_SPECIFIC_START)
  *  - when adding new code values, avoid reordering the values (since that would change the underlying value and mess up prior codes logging)
  *  - avoid code that depends on the actual numeric value, and prefer using the names/enumerators (use OOCPCBuilderCode::eERROR_NO_POINT instead of static_cast<OOCPCBuilderCode>(0X80))
  */
enum class OOCPCR2VSPCCode : std::uint32_t
{
    eERROR_NO_REPOSITORY = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_NO_INPUT_STREAM,
    eERROR_NO_R2V_POINTCLOUD,
    eERROR_NO_UPDATE_CONTAINER,
    eERROR_NO_ACCEL_CONTAINER,
    eERROR_CANT_CREATE_LOD_CACHE,
    eERROR_BAD_LAYOUT,
    eERROR_EMPTY_LAYOUT,
    eERROR_ALLOC_TBB,
    eERROR_CANT_CREATE_IMPORTER,
    eERROR_NO_NEW_GEOMETRY,
    eERROR_READING_ITERATION
};


/**
 * @{ @name R2V Survey component custom HRESULT definitions
 *
 * @internal Each HRESULT should be defined as a constexpr HRESULT variable with internal linkage.
 * Note that constexpr implies const, and a const variable at namespace scope implies internal linkage.
 * (Implied: static in that context is optional as long as there aren't any extra qualifiers... since
 * it's easy to break, prefer explicitly specifying internal linkage, either with static or an anonymous
 * namespace.)
 */
static constexpr HRESULT OOCPCR2VSPC_S_OK = MAKE_OOCPC_HRESULT( SEVERITY_SUCCESS, OOCPCFacility::eR2VSPC, OOCPCCode::eOK );
static constexpr HRESULT OOCPCR2VSPC_S_NO_NEW_GEOMETRY = MAKE_OOCPC_HRESULT( SEVERITY_SUCCESS, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_NO_NEW_GEOMETRY );
static constexpr HRESULT OOCPCR2VSPC_E_NO_REPOSITORY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_NO_REPOSITORY );
static constexpr HRESULT OOCPCR2VSPC_E_NO_INPUT_STREAM = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_NO_INPUT_STREAM );
static constexpr HRESULT OOCPCR2VSPC_E_NO_R2V_POINTCLOUD = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_NO_R2V_POINTCLOUD );
static constexpr HRESULT OOCPCR2VSPC_E_NO_UPDATE_CONTAINER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_NO_UPDATE_CONTAINER );
static constexpr HRESULT OOCPCR2VSPC_E_NO_ACCEL_CONTAINER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_NO_ACCEL_CONTAINER );
static constexpr HRESULT OOCPCR2VSPC_E_CANT_CREATE_LOD_CACHE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_CANT_CREATE_LOD_CACHE );
static constexpr HRESULT OOCPCR2VSPC_E_BAD_LAYOUT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_BAD_LAYOUT );
static constexpr HRESULT OOCPCR2VSPC_E_EMPTY_LAYOUT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_EMPTY_LAYOUT );
static constexpr HRESULT OOCPCR2VSPC_E_ALLOC_TBB = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_ALLOC_TBB );
static constexpr HRESULT OOCPCR2VSPC_E_CANT_CREATE_IMPORTER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_CANT_CREATE_IMPORTER );
static constexpr HRESULT OOCPCR2VSPC_E_READING_ITERATION = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCR2VSPCCode::eERROR_READING_ITERATION );
static constexpr HRESULT OOCPCR2VSPC_E_UNEXPECTED = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSPC, OOCPCCode::eUNEXPECTED );
/** @} */   // Builder component custom HRESULT definitions


/**
 * @{ @name Builder component custom HRESULT listing for OOCPCHRTool
 *
 * @details Macro listing of the custom HRESULT values defined for
 * the Builder component. This definition format was choosen to
 * enable semi-automatic update of the listing known by OOCPCHRTool.
 *
 * Refer to OOCPCHRESULT.h, HRTOOL utilities.
 */
#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_HRR2VSPC \
    OOCPC_APPLY(OOCPCR2VSPC_S_OK),\
    OOCPC_APPLY(OOCPCR2VSPC_S_NO_NEW_GEOMETRY), \
    OOCPC_APPLY(OOCPCR2VSPC_E_NO_REPOSITORY), \
    OOCPC_APPLY(OOCPCR2VSPC_E_NO_INPUT_STREAM), \
    OOCPC_APPLY(OOCPCR2VSPC_E_NO_R2V_POINTCLOUD), \
    OOCPC_APPLY(OOCPCR2VSPC_E_NO_UPDATE_CONTAINER), \
    OOCPC_APPLY(OOCPCR2VSPC_E_NO_ACCEL_CONTAINER),\
    OOCPC_APPLY(OOCPCR2VSPC_E_CANT_CREATE_LOD_CACHE), \
    OOCPC_APPLY(OOCPCR2VSPC_E_BAD_LAYOUT),\
    OOCPC_APPLY(OOCPCR2VSPC_E_EMPTY_LAYOUT),\
    OOCPC_APPLY(OOCPCR2VSPC_E_ALLOC_TBB), \
    OOCPC_APPLY(OOCPCR2VSPC_E_CANT_CREATE_IMPORTER), \
    OOCPC_APPLY(OOCPCR2VSPC_E_READING_ITERATION), \
    OOCPC_APPLY(OOCPCR2VSPC_E_UNEXPECTED)
#endif  // OOCPC_USE_APPLY_LIST
 /** @} */   // Builder component custom HRESULT listing for OOCPCHRTool


#endif  //ifndef OOCPCHRBUILDER_H
