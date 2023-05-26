#ifndef OOCPCHRINPUTBUFFER_H
#define OOCPCHRINPUTBUFFER_H

#include "OOCPCHRESULT.h"

enum class OOCPCInputBufferCode : std::uint32_t
{
    eERROR_MISSING_BUFFER = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_DUPLICATE_BUFFER,
    eERROR_EMPTY_BUFFER,
    eERROR_BAD_METADATA,
    eERROR_BUILD_CANCELLED,
    eERROR_NO_BUILDER,
    eERROR_NO_POS_CONT
};

static constexpr HRESULT OOCPCINPUTBUFFER_E_MISSING_BUFFER = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_MISSING_BUFFER);
static constexpr HRESULT OOCPCINPUTBUFFER_E_DUPLICATE_BUFFER = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_DUPLICATE_BUFFER);
static constexpr HRESULT OOCPCINPUTBUFFER_E_EMPTY_BUFFER = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_EMPTY_BUFFER);
static constexpr HRESULT OOCPCINPUTBUFFER_E_BAD_METADATA = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_BAD_METADATA);
static constexpr HRESULT OOCPCINPUTBUFFER_E_BUILD_CANCELLED = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_BUILD_CANCELLED);
static constexpr HRESULT OOCPCINPUTBUFFER_E_NO_BUILDER = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_NO_BUILDER);
static constexpr HRESULT OOCPCINPUTBUFFER_E_NO_POS_CONT = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCInputBufferCode::eERROR_NO_POS_CONT);
static constexpr HRESULT OOCPCINPUTBUFFER_E_ABORT = MAKE_OOCPC_HRESULT(SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCCode::eABORT);
static constexpr HRESULT OOCPCINPUTBUFFER_E_NOTIMPL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eINPUTBUFFER, OOCPCCode::eNOTIMPL );

#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_HRINPUTBUFFER   \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_MISSING_BUFFER), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_DUPLICATE_BUFFER), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_EMPTY_BUFFER), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_BAD_METADATA), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_BUILD_CANCELLED), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_NO_BUILDER), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_NO_POS_CONT), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_ABORT), \
    OOCPC_APPLY(OOCPCINPUTBUFFER_E_NOTIMPL)
#endif  // OOCPC_USE_APPLY_LIST

#endif  //ifndef OOCPCHRINPUTBUFFER_H