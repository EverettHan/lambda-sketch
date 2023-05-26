#ifndef OOCPCHRR2VIMAGE_H
#define OOCPCHRR2VIMAGE_H

#include "OOCPCHRESULT.h"

enum class OOCPCR2VImageCode : std::uint32_t
{
    eERROR_PNG_LOADING_FAIL = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_JPEG_LOADING_FAIL,
    eERROR_UNEXPECTED_EMPTY_IMAGE,
    eERROR_UNKNOWN_IMAGE_FORMAT,
    eERROR_UNKNOWN_COMPRESSION_FORMAT,
    eERROR_COMPRESSION_FAIL
};

static constexpr HRESULT OOCPCR2VIMAGE_E_PNG_LOADING_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VIMAGE, OOCPCR2VImageCode::eERROR_PNG_LOADING_FAIL );
static constexpr HRESULT OOCPCR2VIMAGE_E_JPEG_LOADING_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VIMAGE, OOCPCR2VImageCode::eERROR_JPEG_LOADING_FAIL );
static constexpr HRESULT OOCPCR2VIMAGE_E_UNEXPECTED_EMPTY_IMAGE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VIMAGE, OOCPCR2VImageCode::eERROR_UNEXPECTED_EMPTY_IMAGE );
static constexpr HRESULT OOCPCR2VIMAGE_E_UNKNOWN_IMAGE_FORMAT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VIMAGE, OOCPCR2VImageCode::eERROR_UNKNOWN_IMAGE_FORMAT );
static constexpr HRESULT OOCPCR2VIMAGE_E_UNKNOWN_COMPRESSION_FORMAT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VIMAGE, OOCPCR2VImageCode::eERROR_UNKNOWN_COMPRESSION_FORMAT );
static constexpr HRESULT OOCPCR2VIMAGE_E_COMPRESSION_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eR2VIMAGE, OOCPCR2VImageCode::eERROR_COMPRESSION_FAIL );

#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_OOCPCHRR2VIMAGE \
    OOCPC_APPLY( OOCPCR2VIMAGE_E_PNG_LOADING_FAIL ), \
    OOCPC_APPLY( OOCPCR2VIMAGE_E_JPEG_LOADING_FAIL ), \
    OOCPC_APPLY( OOCPCR2VIMAGE_E_UNEXPECTED_EMPTY_IMAGE ), \
    OOCPC_APPLY( OOCPCR2VIMAGE_E_UNKNOWN_IMAGE_FORMAT ), \
    OOCPC_APPLY( OOCPCR2VIMAGE_E_UNKNOWN_COMPRESSION_FORMAT ), \
    OOCPC_APPLY( OOCPCR2VIMAGE_E_COMPRESSION_FAIL )

#endif  // OOCPC_USE_APPLY_LIST


#endif  //ifndef OOCPCHRR2VIMAGE_H