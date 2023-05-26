#ifndef OOCPCHROPERATOR_H
#define OOCPCHROPERATOR_H

#include "OOCPCHRESULT.h"

enum class OOCPCOperatorCode : std::uint32_t
{
    eERROR_NO_REPOSITORY = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_NO_OPERATOR,
    eERROR_NO_NODE_CACHE,
    eERROR_NO_OCTREE_CACHE,
    eERROR_NO_LOD_NODE_CACHE,
    eERROR_NO_REQUESTED_METADATA,
    eERROR_UNREGISTERED_METADATA,
    eERROR_BAD_METADATA_SIZE,
    eERROR_INCOMPATIBLE_CACHE,
    eERROR_NO_LOADABLE_NODE,
    eERROR_METADATA_ACCESSDENIED,
    eERROR_INCOMPATIBLE_POINTCLOUD_IMPL,
    eERROR_INVALID_TASK_PARAMETERS,
    eERROR_TASK_DEFAULT_RETURN,
    eERROR_INVALID_TRAVERSAL_ALGORITHM,
    eERROR_UNLOADABLE_LEAF_NODE,
    eERROR_NOT_A_SLICE,
    eERROR_SLICE_WITHOUT_CHILDREN,
    eERROR_INVALID_NODE,
    eERROR_NO_NODE_BBOX,
    eERROR_NO_NODE_SPACE_BBOX,
    eERROR_UNSUPPORTED_FLOAT,
    eERROR_INVALID_DISPATCH_OPTION,
    eERROR_INVALID_DOUBLE_DISPATCH_OPTION,
    eERROR_TBB, //!< errors related to VENIntelTBB
    eERROR_NO_POINTCLOUD
};

static constexpr HRESULT OOCPCOPERATOR_E_NO_REPOSITORY = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_REPOSITORY);
static constexpr HRESULT OOCPCOPERATOR_E_NO_OPERATOR = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_OPERATOR);
static constexpr HRESULT OOCPCOPERATOR_E_NO_NODE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_NODE_CACHE);
static constexpr HRESULT OOCPCOPERATOR_E_NO_OCTREE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_OCTREE_CACHE);
static constexpr HRESULT OOCPCOPERATOR_E_NO_LOD_NODE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_LOD_NODE_CACHE);
static constexpr HRESULT OOCPCOPERATOR_E_NO_REQUESTED_METADATA = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_REQUESTED_METADATA);
static constexpr HRESULT OOCPCOPERATOR_E_UNREGISTERED_METADATA = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_UNREGISTERED_METADATA);
static constexpr HRESULT OOCPCOPERATOR_E_BAD_METADATA_SIZE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_BAD_METADATA_SIZE);
static constexpr HRESULT OOCPCOPERATOR_E_INCOMPATIBLE_CACHE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INCOMPATIBLE_CACHE);
static constexpr HRESULT OOCPCOPERATOR_E_NO_LOADABLE_NODE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_LOADABLE_NODE);
static constexpr HRESULT OOCPCOPERATOR_E_METADATA_ACCESSDENIED = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_METADATA_ACCESSDENIED);
static constexpr HRESULT OOCPCOPERATOR_E_INCOMPATIBLE_POINTCLOUD_IMPL = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INCOMPATIBLE_POINTCLOUD_IMPL);
static constexpr HRESULT OOCPCOPERATOR_E_INVALID_TASK_PARAMETERS = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INVALID_TASK_PARAMETERS);
static constexpr HRESULT OOCPCOPERATOR_E_TASK_DEFAULT_RETURN = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_TASK_DEFAULT_RETURN);
static constexpr HRESULT OOCPCOPERATOR_E_INVALID_TRAVERSAL_ALGORITHM = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INVALID_TRAVERSAL_ALGORITHM);
static constexpr HRESULT OOCPCOPERATOR_E_UNLOADABLE_LEAF_NODE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_UNLOADABLE_LEAF_NODE);
static constexpr HRESULT OOCPCOPERATOR_E_NOT_A_SLICE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NOT_A_SLICE);
static constexpr HRESULT OOCPCOPERATOR_E_SLICE_WITHOUT_CHILDREN = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_SLICE_WITHOUT_CHILDREN);
static constexpr HRESULT OOCPCOPERATOR_E_INVALID_NODE = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INVALID_NODE);
static constexpr HRESULT OOCPCOPERATOR_E_NO_NODE_BBOX = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_NODE_BBOX);
static constexpr HRESULT OOCPCOPERATOR_E_NO_NODE_SPACE_BBOX = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_NODE_SPACE_BBOX);
static constexpr HRESULT OOCPCOPERATOR_E_UNSUPPORTED_FLOAT = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_UNSUPPORTED_FLOAT);
static constexpr HRESULT OOCPCOPERATOR_E_INVALID_DISPATCH_OPTION = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INVALID_DISPATCH_OPTION);
static constexpr HRESULT OOCPCOPERATOR_E_INVALID_DOUBLE_DISPATCH_OPTION = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_INVALID_DOUBLE_DISPATCH_OPTION);
static constexpr HRESULT OOCPCOPERATOR_E_NO_POINTCLOUD = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_NO_POINTCLOUD );
static constexpr HRESULT OOCPCOPERATOR_E_TBB = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCOperatorCode::eERROR_TBB );
static constexpr HRESULT OOCPCOPERATOR_E_ABORT = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCCode::eABORT);
static constexpr HRESULT OOCPCOPERATOR_E_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCCode::eFAIL );
static constexpr HRESULT OOCPCOPERATOR_E_NOTIMPL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCCode::eNOTIMPL );
static constexpr HRESULT OOCPCOPERATOR_E_INVALID_PARAMETER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCCode::eINVALID_PARAMETER );
static constexpr HRESULT OOCPCOPERATOR_E_UNEXPECTED = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCCode::eUNEXPECTED);
static constexpr HRESULT OOCPCOPERATOR_E_OUTOFMEMORY = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eOPERATOR, OOCPCCode::eOUTOFMEMORY);

#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_HROPERATOR \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_REPOSITORY), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_OPERATOR), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_NODE_CACHE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_OCTREE_CACHE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_LOD_NODE_CACHE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_REQUESTED_METADATA), \
    OOCPC_APPLY(OOCPCOPERATOR_E_UNREGISTERED_METADATA), \
    OOCPC_APPLY(OOCPCOPERATOR_E_BAD_METADATA_SIZE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INCOMPATIBLE_CACHE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_LOADABLE_NODE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_METADATA_ACCESSDENIED), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INCOMPATIBLE_POINTCLOUD_IMPL), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INVALID_TASK_PARAMETERS), \
    OOCPC_APPLY(OOCPCOPERATOR_E_TASK_DEFAULT_RETURN), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INVALID_TRAVERSAL_ALGORITHM), \
    OOCPC_APPLY(OOCPCOPERATOR_E_UNLOADABLE_LEAF_NODE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NOT_A_SLICE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_SLICE_WITHOUT_CHILDREN), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INVALID_NODE), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_NODE_BBOX), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_NODE_SPACE_BBOX), \
    OOCPC_APPLY(OOCPCOPERATOR_E_UNSUPPORTED_FLOAT), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INVALID_DISPATCH_OPTION), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INVALID_DOUBLE_DISPATCH_OPTION), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NO_POINTCLOUD), \
    OOCPC_APPLY(OOCPCOPERATOR_E_TBB), \
    OOCPC_APPLY(OOCPCOPERATOR_E_ABORT), \
    OOCPC_APPLY(OOCPCOPERATOR_E_FAIL), \
    OOCPC_APPLY(OOCPCOPERATOR_E_NOTIMPL), \
    OOCPC_APPLY(OOCPCOPERATOR_E_INVALID_PARAMETER), \
    OOCPC_APPLY(OOCPCOPERATOR_E_UNEXPECTED), \
    OOCPC_APPLY(OOCPCOPERATOR_E_OUTOFMEMORY)
#endif  // OOCPC_USE_APPLY_LIST

#endif  //ifndef OOCPCHROPERATOR_H