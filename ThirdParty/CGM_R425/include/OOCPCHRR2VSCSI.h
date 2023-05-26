#ifndef OOCPCHRR2VSCSI_H
#define OOCPCHRR2VSCSI_H

/**
 * @file
 *
 * @brief Custom HRESULT codes for OOCPC's R2V Survey CSI service component/facility.
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
enum class OOCPCR2VSCSICode : std::uint32_t
{
    eERROR_3D_NOTIFICATION = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_GRAPH_INVALID_FLOWS_CONTROL,
    eERROR_GRAPH_INVALID_DATA_PATH,
    eERROR_GRAPH_CONTROL_FLOW_DEAD_END,
    eERROR_GRAPH_INTERRUPTED,
    eERROR_GRAPH_SELECT_NODE_FAIL
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
static constexpr HRESULT OOCPCR2VSCSI_S_OK = MAKE_OOCPC_HRESULT( SEVERITY_SUCCESS, OOCPCFacility::eR2VSCSI, OOCPCCode::eOK );
static constexpr HRESULT OOCPCR2VSCSI_E_INVALID_PARAMETER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCCode::eINVALID_PARAMETER );
static constexpr HRESULT OOCPCR2VSCSI_E_3D_NOTIFICATION = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCR2VSCSICode::eERROR_3D_NOTIFICATION );
static constexpr HRESULT OOCPCR2VSCSI_E_GRAPH_INVALID_FLOWS_CONTROL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCR2VSCSICode::eERROR_GRAPH_INVALID_FLOWS_CONTROL );
static constexpr HRESULT OOCPCR2VSCSI_E_GRAPH_INVALID_DATA_PATH = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCR2VSCSICode::eERROR_GRAPH_INVALID_DATA_PATH );
static constexpr HRESULT OOCPCR2VSCSI_E_GRAPH_CONTROL_FLOW_DEAD_END = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCR2VSCSICode::eERROR_GRAPH_CONTROL_FLOW_DEAD_END );
static constexpr HRESULT OOCPCR2VSCSI_E_GRAPH_INTERRUPTED = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCR2VSCSICode::eERROR_GRAPH_INTERRUPTED );
static constexpr HRESULT OOCPCR2VSCSI_E_GRAPH_SELECT_NODE_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCR2VSCSICode::eERROR_GRAPH_SELECT_NODE_FAIL );
static constexpr HRESULT OOCPCR2VSCSI_E_UNEXPECTED = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCCode::eUNEXPECTED );
static constexpr HRESULT OOCPCR2VSCSI_E_ABORT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSCSI, OOCPCCode::eABORT );
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
#define OOCPC_APPLY_LIST_TO_HRR2VSCSI \
    OOCPC_APPLY(OOCPCR2VSCSI_S_OK),\
    OOCPC_APPLY(OOCPCR2VSCSI_E_INVALID_PARAMETER), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_3D_NOTIFICATION), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_GRAPH_INVALID_FLOWS_CONTROL), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_GRAPH_INVALID_DATA_PATH), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_GRAPH_CONTROL_FLOW_DEAD_END), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_GRAPH_INTERRUPTED), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_GRAPH_SELECT_NODE_FAIL), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_UNEXPECTED), \
    OOCPC_APPLY(OOCPCR2VSCSI_E_ABORT)
#endif  // OOCPC_USE_APPLY_LIST
 /** @} */   // Builder component custom HRESULT listing for OOCPCHRTool


#endif  //ifndef OOCPCHRBUILDER_H
