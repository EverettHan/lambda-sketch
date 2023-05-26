#ifndef OOCPCHRCACHE_H
#define OOCPCHRCACHE_H

#include "OOCPCHRESULT.h"

enum class OOCPCCacheCode : std::uint32_t
{
    eERROR_NO_REQUESTED_METADATA = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_METADATA_CONT_NOT_FOUND,
    eERROR_LEAF_WITH_CHILD,
    eERROR_SCHEDULER_REGISTER_FAIL,
    eERROR_SCHEDULER_INIT_FAIL,
    eERROR_SCHEDULER_BAD_CACHE_COUNT,
    eERROR_SCHEDULER_INVALID_CACHE,
    eERROR_SCHEDULER_BAD_PAGE_ID,
    eERROR_SCHEDULER_OUT_OF_PAGES
};

static constexpr HRESULT OOCPCCACHE_E_NO_REQUESTED_METADATA = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_NO_REQUESTED_METADATA );
static constexpr HRESULT OOCPCCACHE_E_METADATA_CONT_NOT_FOUND = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_METADATA_CONT_NOT_FOUND );
static constexpr HRESULT OOCPCCACHE_E_LEAF_WITH_CHILD = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_LEAF_WITH_CHILD );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_REGISTER_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_SCHEDULER_REGISTER_FAIL );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_INIT_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_SCHEDULER_INIT_FAIL );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_BAD_CACHE_COUNT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_SCHEDULER_BAD_CACHE_COUNT );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_INVALID_CACHE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_SCHEDULER_INVALID_CACHE );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_BAD_PAGE_ID = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_SCHEDULER_BAD_PAGE_ID );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_OUT_OF_PAGES = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCacheCode::eERROR_SCHEDULER_OUT_OF_PAGES );
static constexpr HRESULT OOCPCCACHE_E_SCHEDULER_INVALIDARG = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCode::eINVALID_PARAMETER );
static constexpr HRESULT OOCPCCACHE_E_OUTOFMEMORY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCode::eOUTOFMEMORY );
static constexpr HRESULT OOCPCCACHE_E_INVALIDARG = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCode::eINVALID_PARAMETER );
static constexpr HRESULT OOCPCCACHE_E_ABORT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCode::eABORT );
static constexpr HRESULT OOCPCCACHE_E_NOTIMPL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCACHE, OOCPCCode::eNOTIMPL );

#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_HRCACHE             \
    OOCPC_APPLY(OOCPCCACHE_E_NO_REQUESTED_METADATA), \
    OOCPC_APPLY(OOCPCCACHE_E_METADATA_CONT_NOT_FOUND), \
    OOCPC_APPLY(OOCPCCACHE_E_LEAF_WITH_CHILD), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_REGISTER_FAIL), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_INIT_FAIL), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_BAD_CACHE_COUNT), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_INVALID_CACHE), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_BAD_PAGE_ID), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_OUT_OF_PAGES), \
    OOCPC_APPLY(OOCPCCACHE_E_SCHEDULER_INVALIDARG), \
    OOCPC_APPLY(OOCPCCACHE_E_OUTOFMEMORY), \
    OOCPC_APPLY(OOCPCCACHE_E_INVALIDARG), \
    OOCPC_APPLY(OOCPCCACHE_E_ABORT), \
    OOCPC_APPLY(OOCPCCACHE_E_NOTIMPL)
#endif  // OOCPC_USE_APPLY_LIST


#endif  //ifndef OOCPCHRCACHE_H