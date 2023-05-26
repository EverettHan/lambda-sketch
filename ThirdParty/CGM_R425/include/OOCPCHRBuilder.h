#ifndef OOCPCHRBUILDER_H
#define OOCPCHRBUILDER_H

/**
 * @file
 * 
 * @brief Custom HRESULT codes for OOCPC's Builder component/facility.
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
enum class OOCPCBuilderCode : std::uint32_t
{
    eERROR_NO_POINT = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_REFIT_MORTON,
    eERROR_SORT_CHUNK,
    eERROR_SORT_MERGE,
    eERROR_REMOVE_DUPLICATE,
    eERROR_BUILD_OCTREE,
    eERROR_BUILD_CONTAINER,
    eERROR_ITERATION_CONTAINER,
    eERROR_REFIT_NODES,
    eERROR_POINTS_PER_FILE,
    eERROR_BUILD_SPLITTED_CONTAINER,
    eERROR_BUILD_LOD_CONTAINER,
    eERROR_INSTANTIATION_FAIL,
    eERROR_NO_REPOSITORY,
    eERROR_NO_POINTCLOUD,
    eERROR_NO_ITER_CONTAINER,
    eERROR_INVALID_ITERATION
};


/**
 * @{ @name Builder component custom HRESULT definitions
 *
 * @internal Each HRESULT should be defined as a constexpr HRESULT variable with internal linkage.
 * Note that constexpr implies const, and a const variable at namespace scope implies internal linkage.
 * (Implied: static in that context is optional as long as there aren't any extra qualifiers... since
 * it's easy to break, prefer explicitly specifying internal linkage, either with static or an anonymous
 * namespace.)
 */
static constexpr HRESULT OOCPCBUILDER_S_OK = MAKE_OOCPC_HRESULT( SEVERITY_SUCCESS, OOCPCFacility::eBUILDER, OOCPCCode::eOK );
static constexpr HRESULT OOCPCBUILDER_E_INVALIDARG = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCCode::eINVALID_PARAMETER );
static constexpr HRESULT OOCPCBUILDER_E_NOPOINT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_NO_POINT );
static constexpr HRESULT OOCPCBUILDER_E_REFITMORTON = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_REFIT_MORTON );
static constexpr HRESULT OOCPCBUILDER_E_CHUNKSORT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_SORT_CHUNK );
static constexpr HRESULT OOCPCBUILDER_E_MERGESORT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_SORT_MERGE );
static constexpr HRESULT OOCPCBUILDER_E_RMDUPLICATE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_REMOVE_DUPLICATE );
static constexpr HRESULT OOCPCBUILDER_E_BUILDOCTREE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_BUILD_OCTREE );
static constexpr HRESULT OOCPCBUILDER_E_BUILDCONTAINER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_BUILD_CONTAINER );
static constexpr HRESULT OOCPCBUILDER_E_ITRCONTAINER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_ITERATION_CONTAINER );
static constexpr HRESULT OOCPCBUILDER_E_REFITNODES = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_REFIT_NODES );
static constexpr HRESULT OOCPCBUILDER_E_POINTSPERFILE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_POINTS_PER_FILE );
static constexpr HRESULT OOCPCBUILDER_E_BUILDSPLITTEDCONT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_BUILD_SPLITTED_CONTAINER );
static constexpr HRESULT OOCPCBUILDER_E_BUILDLODCONT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_BUILD_LOD_CONTAINER );
static constexpr HRESULT OOCPCBUILDER_E_INSTANTIATION_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_INSTANTIATION_FAIL );
static constexpr HRESULT OOCPCBUILDER_E_NO_REPOSITORY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_NO_REPOSITORY );
static constexpr HRESULT OOCPCBUILDER_E_NO_POINTCLOUD = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_NO_POINTCLOUD );
static constexpr HRESULT OOCPCBUILDER_E_NO_ITER_CONTAINER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_NO_ITER_CONTAINER );
static constexpr HRESULT OOCPCBUILDER_E_INVALID_ITERATION = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCBuilderCode::eERROR_INVALID_ITERATION );
static constexpr HRESULT OOCPCBUILDER_E_ABORT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCCode::eABORT );
static constexpr HRESULT OOCPCBUILDER_E_OPEN_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCCode::eOPEN_FAILED );
static constexpr HRESULT OOCPCBUILDER_E_WRITE_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCCode::eWRITE_FAULT );
static constexpr HRESULT OOCPCBUILDER_E_READ_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCCode::eREAD_FAULT );
static constexpr HRESULT OOCPCBUILDER_E_OUTOFMEMORY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eBUILDER, OOCPCCode::eOUTOFMEMORY );
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
#define OOCPC_APPLY_LIST_TO_HRBUILDER               \
    OOCPC_APPLY(OOCPCBUILDER_S_OK),                 \
    OOCPC_APPLY(OOCPCBUILDER_E_INVALIDARG),         \
    OOCPC_APPLY(OOCPCBUILDER_E_NOPOINT),            \
    OOCPC_APPLY(OOCPCBUILDER_E_REFITMORTON),        \
    OOCPC_APPLY(OOCPCBUILDER_E_CHUNKSORT),          \
    OOCPC_APPLY(OOCPCBUILDER_E_MERGESORT),          \
    OOCPC_APPLY(OOCPCBUILDER_E_RMDUPLICATE),        \
    OOCPC_APPLY(OOCPCBUILDER_E_BUILDOCTREE),        \
    OOCPC_APPLY(OOCPCBUILDER_E_BUILDCONTAINER),     \
    OOCPC_APPLY(OOCPCBUILDER_E_ITRCONTAINER),       \
    OOCPC_APPLY(OOCPCBUILDER_E_REFITNODES),         \
    OOCPC_APPLY(OOCPCBUILDER_E_POINTSPERFILE),      \
    OOCPC_APPLY(OOCPCBUILDER_E_BUILDSPLITTEDCONT),  \
    OOCPC_APPLY(OOCPCBUILDER_E_BUILDLODCONT),       \
    OOCPC_APPLY(OOCPCBUILDER_E_INSTANTIATION_FAIL)
#endif  // OOCPC_USE_APPLY_LIST
/** @} */   // Builder component custom HRESULT listing for OOCPCHRTool


#endif  //ifndef OOCPCHRBUILDER_H
