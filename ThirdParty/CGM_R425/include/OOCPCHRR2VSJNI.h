#ifndef OOCPCHRR2VSJava_H
#define OOCPCHRR2VSJava_H

/**
 * @file
 *
 * @brief Custom HRESULT codes for OOCPC's R2V Survey Java service component/facility.
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
enum class OOCPCR2VSJNICode : std::uint32_t
{
    eERROR_ALLOC_JAVA = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_FIND_JAVA_CLASS
};


/**
 * @{ @name R2V Survey Java component custom HRESULT definitions
 *
 * @internal Each HRESULT should be defined as a constexpr HRESULT variable with internal linkage.
 * Note that constexpr implies const, and a const variable at namespace scope implies internal linkage.
 * (Implied: static in that context is optional as long as there aren't any extra qualifiers... since
 * it's easy to break, prefer explicitly specifying internal linkage, either with static or an anonymous
 * namespace.)
 */
static constexpr HRESULT OOCPCR2VSJNI_S_OK = MAKE_OOCPC_HRESULT( SEVERITY_SUCCESS, OOCPCFacility::eR2VSJAVA, OOCPCCode::eOK );
static constexpr HRESULT OOCPCR2VSJNI_E_ALLOC_JAVA = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSJAVA, OOCPCR2VSJNICode::eERROR_ALLOC_JAVA );
static constexpr HRESULT OOCPCR2VSJNI_E_FIND_JAVA_CLASS = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSJAVA, OOCPCR2VSJNICode::eERROR_FIND_JAVA_CLASS );
static constexpr HRESULT OOCPCR2VSJNI_E_UNEXPECTED = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VSJAVA, OOCPCCode::eUNEXPECTED );
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
#define OOCPC_APPLY_LIST_TO_HRR2VSJNI \
    OOCPC_APPLY(OOCPCR2VSJNI_S_OK),\
    OOCPC_APPLY(OOCPCR2VSJNI_E_ALLOC_JAVA), \
    OOCPC_APPLY(OOCPCR2VSJNI_E_FIND_JAVA_CLASS), \
    OOCPC_APPLY(OOCPCR2VSJNI_E_UNEXPECTED)
#endif  // OOCPC_USE_APPLY_LIST
 /** @} */   // Builder component custom HRESULT listing for OOCPCHRTool


#endif  //ifndef OOCPCHRBUILDER_H
