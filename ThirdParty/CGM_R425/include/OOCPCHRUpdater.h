#ifndef OOCPCHRUPDATER_H
#define OOCPCHRUPDATER_H

#include "OOCPCHRESULT.h"

enum class OOCPCUpdaterCode : std::uint32_t
{
    eERROR_NO_TMP_DIR = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_DIR_CREATION_FAIL,
    eERROR_ITERATION_CREATION_FAIL,
    eERROR_BAD_RESOLUTION,
    eERROR_RESOLUTION_ESTIMATION_FAIL,
    eERROR_INCOMPATIBLE_STRING_REPOSITORY,
    eERROR_NO_POINTCLOUD_TO_UPDATE,
    eERROR_NO_NODE_CACHE,
    eERROR_NO_OCTREE_CACHE,
    eERROR_NO_LOD_NODE_CACHE,
    eERROR_INVALID_UPDATE_CONFIG,
    eERROR_INVALID_LOADABLE_NODE,
    eERROR_INCOMPATIBLE_COORD_SYSTEM,
    eERROR_NO_REPOSITORY,
    eERROR_INCOMPATIBLE_UPDATE_PARAMETERS,
    eERROR_INVALID_NODE_CLUSTER,
    eERROR_MORTON_CONVERSION_FAIL,
    eERROR_SLICING_FAIL,
    eERROR_MORTON_INCONSISTENCY,
    eERROR_INVALID_BOUNDING_BOX,
    eERROR_NO_THREAD_LOCAL_BUFFER,
    eERROR_POINT_DUMP_FAIL,
    eERROR_INVALID_OVERLAY,
    eERROR_OVERLAY_CREATION_FAIL,
    eERROR_INVALID_METADATA,
    eERROR_INVALID_ACCEL_CONT,
    eERROR_INVALID_METADATA_MAPPING,
    eERROR_UPDATE_RESULT_INCONSISTENCY,
    eERROR_HIERARCHY_REFIT_FAIL,
    eERROR_INVALID_NODE_ID,
    eERROR_NO_COLOR_PROFILE
};

static constexpr HRESULT OOCPCUPDATER_E_NO_TMP_DIR = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_TMP_DIR);
static constexpr HRESULT OOCPCUPDATER_E_DIR_CREATION_FAIL = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_DIR_CREATION_FAIL);
static constexpr HRESULT OOCPCUPDATER_E_ITER_CREATION_FAIL = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_ITERATION_CREATION_FAIL);
static constexpr HRESULT OOCPCUPDATER_E_BAD_RESOLUTION = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_BAD_RESOLUTION);
static constexpr HRESULT OOCPCUPDATER_E_RESOLUTION_ESTIMATION_FAIL = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_RESOLUTION_ESTIMATION_FAIL);
static constexpr HRESULT OOCPCUPDATER_E_INCOMPATIBLE_STRING_REPOSITORY = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INCOMPATIBLE_STRING_REPOSITORY);
static constexpr HRESULT OOCPCUPDATER_E_NO_POINTCLOUD_TO_UPDATE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_POINTCLOUD_TO_UPDATE);
static constexpr HRESULT OOCPCUPDATER_E_NO_NODE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_NODE_CACHE);
static constexpr HRESULT OOCPCUPDATER_E_NO_OCTREE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_OCTREE_CACHE);
static constexpr HRESULT OOCPCUPDATER_E_NO_LOD_NODE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_LOD_NODE_CACHE);
static constexpr HRESULT OOCPCUPDATER_E_INVALID_UPDATE_CONFIG = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_UPDATE_CONFIG );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_LOADABLE_NODE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_LOADABLE_NODE );
static constexpr HRESULT OOCPCUPDATER_E_INCOMPATIBLE_COORD_SYSTEM = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INCOMPATIBLE_COORD_SYSTEM );
static constexpr HRESULT OOCPCUPDATER_E_INCOMPATIBLE_UPDATE_PARAMETERS = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INCOMPATIBLE_UPDATE_PARAMETERS );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_NODE_CLUSTER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_NODE_CLUSTER );
static constexpr HRESULT OOCPCUPDATER_E_NO_REPOSITORY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_REPOSITORY );
static constexpr HRESULT OOCPCUPDATER_E_MORTON_CONVERSION_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_MORTON_CONVERSION_FAIL );
static constexpr HRESULT OOCPCUPDATER_E_SLICING_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_SLICING_FAIL );
static constexpr HRESULT OOCPCUPDATER_E_MORTON_INCONSISTENCY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_MORTON_INCONSISTENCY );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_BOUNDING_BOX = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_BOUNDING_BOX );
static constexpr HRESULT OOCPCUPDATER_E_NO_THREAD_LOCAL_BUFFER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_THREAD_LOCAL_BUFFER );
static constexpr HRESULT OOCPCUPDATER_E_POINT_DUMP_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_POINT_DUMP_FAIL );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_OVERLAY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_OVERLAY );
static constexpr HRESULT OOCPCUPDATER_E_OVERLAY_CREATION_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_OVERLAY_CREATION_FAIL );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_METADATA = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_METADATA );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_ACCEL_CONT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_ACCEL_CONT );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_METADATA_MAPPING = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_METADATA_MAPPING );
static constexpr HRESULT OOCPCUPDATER_E_UPDATE_RESULT_INCONSISTENCY = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_UPDATE_RESULT_INCONSISTENCY );
static constexpr HRESULT OOCPCUPDATER_E_HIERARCHY_REFIT_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_HIERARCHY_REFIT_FAIL );
static constexpr HRESULT OOCPCUPDATER_E_INVALID_NODE_ID = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_INVALID_NODE_ID );
static constexpr HRESULT OOCPCUPDATER_E_NO_COLOR_PROFILE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCUpdaterCode::eERROR_NO_COLOR_PROFILE );
static constexpr HRESULT OOCPCUPDATER_E_READ_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCCode::eREAD_FAULT );
static constexpr HRESULT OOCPCUPDATER_E_ABORT = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCCode::eABORT);
static constexpr HRESULT OOCPCUPDATER_E_NOTIMPL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCCode::eNOTIMPL );
static constexpr HRESULT OOCPCUPDATER_E_OUTOFMEMORY = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCCode::eOUTOFMEMORY);
static constexpr HRESULT OOCPCUPDATER_E_UNEXPECTED = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eUPDATER, OOCPCCode::eUNEXPECTED);

#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_HRUPDATER   \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_TMP_DIR), \
    OOCPC_APPLY(OOCPCUPDATER_E_DIR_CREATION_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_ITER_CREATION_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_BAD_RESOLUTION), \
    OOCPC_APPLY(OOCPCUPDATER_E_RESOLUTION_ESTIMATION_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_INCOMPATIBLE_STRING_REPOSITORY), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_POINTCLOUD_TO_UPDATE), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_NODE_CACHE), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_OCTREE_CACHE), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_LOD_NODE_CACHE), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_UPDATE_CONFIG), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_LOADABLE_NODE), \
    OOCPC_APPLY(OOCPCUPDATER_E_INCOMPATIBLE_COORD_SYSTEM), \
    OOCPC_APPLY(OOCPCUPDATER_E_INCOMPATIBLE_UPDATE_PARAMETERS), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_NODE_CLUSTER), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_REPOSITORY), \
    OOCPC_APPLY(OOCPCUPDATER_E_MORTON_CONVERSION_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_SLICING_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_MORTON_INCONSISTENCY), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_BOUNDING_BOX), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_THREAD_LOCAL_BUFFER), \
    OOCPC_APPLY(OOCPCUPDATER_E_POINT_DUMP_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_OVERLAY), \
    OOCPC_APPLY(OOCPCUPDATER_E_OVERLAY_CREATION_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_METADATA), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_ACCEL_CONT), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_METADATA_MAPPING), \
    OOCPC_APPLY(OOCPCUPDATER_E_UPDATE_RESULT_INCONSISTENCY), \
    OOCPC_APPLY(OOCPCUPDATER_E_HIERARCHY_REFIT_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_INVALID_NODE_ID), \
    OOCPC_APPLY(OOCPCUPDATER_E_NO_COLOR_PROFILE), \
    OOCPC_APPLY(OOCPCUPDATER_E_READ_FAIL), \
    OOCPC_APPLY(OOCPCUPDATER_E_ABORT), \
    OOCPC_APPLY(OOCPCUPDATER_E_NOTIMPL), \
    OOCPC_APPLY(OOCPCUPDATER_E_OUTOFMEMORY), \
    OOCPC_APPLY(OOCPCUPDATER_E_UNEXPECTED)
#endif  // OOCPC_USE_APPLY_LIST

#endif  //ifndef OOCPCHRUPDATER_H
