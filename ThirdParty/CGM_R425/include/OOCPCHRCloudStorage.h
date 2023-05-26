#ifndef OOCPCHRCLOUDSTORAGE_H
#define OOCPCHRCLOUDSTORAGE_H

#include "OOCPCHRESULT.h"

enum class OOCPCCloudStorageCode : std::uint32_t
{
    eERROR_RENAME_FAIL = static_cast<std::uint32_t>( OOCPCCode::eCOMPONENT_SPECIFIC_START ),
    eERROR_NO_PASSPORT_URL,
    eERROR_NO_SERVICE_URL,
    eERROR_NO_LOGIN_TICKET,
    eERROR_NO_SERVICE_TICKET,
    eERROR_NO_LOGIN,
    eERROR_NO_PASSWORD,
    eERROR_OPEN_REQUEST_FAIL,
    eERROR_SEND_REQUEST_FAIL,
    eERROR_CLOSE_REQUEST_FAIL,
    eERROR_NO_RESPONSE_HEADER,
    eERROR_DOWNLOAD_FAIL,
    eERROR_REQUEST_FAIL,
    eERROR_INVALID_FILE_SIZE,
    eERROR_NO_CLOUD_SERVICE,
    eERROR_NO_CACHE_STORAGE,
    eERROR_MISSING_BLOCK,
    eERROR_UPLOAD_FAIL,
    eERROR_REMOVE_FAIL,
    eERROR_NO_AWS_CLIENT
};

static constexpr HRESULT OOCPCCLOUDSTORAGE_E_RENAME_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_RENAME_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_PASSPORT_URL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_PASSPORT_URL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_SERVICE_URL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_SERVICE_URL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_LOGIN_TICKET = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_LOGIN_TICKET );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_SERVICE_TICKET = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_SERVICE_TICKET );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_LOGIN = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_LOGIN );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_PASSWORD = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_PASSWORD );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_OPEN_REQUEST_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_OPEN_REQUEST_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_SEND_REQUEST_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_SEND_REQUEST_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_CLOSE_REQUEST_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_CLOSE_REQUEST_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_RESPONSE_HEADER = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_NO_RESPONSE_HEADER );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_DOWNLOAD_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_DOWNLOAD_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_REQUEST_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_REQUEST_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_INVALID_FILE_SIZE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCloudStorageCode::eERROR_INVALID_FILE_SIZE );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_CLOUD_SERVICE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eREPOSITORY, OOCPCCloudStorageCode::eERROR_NO_CLOUD_SERVICE );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_CACHE_STORAGE = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eREPOSITORY, OOCPCCloudStorageCode::eERROR_NO_CACHE_STORAGE );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_MISSING_BLOCK = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eREPOSITORY, OOCPCCloudStorageCode::eERROR_MISSING_BLOCK );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_UPLOAD_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eREPOSITORY, OOCPCCloudStorageCode::eERROR_UPLOAD_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_REMOVE_FAIL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eREPOSITORY, OOCPCCloudStorageCode::eERROR_REMOVE_FAIL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NO_AWS_CLIENT = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eREPOSITORY, OOCPCCloudStorageCode::eERROR_NO_AWS_CLIENT );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_NOTIMPL = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCode::eNOTIMPL );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_FILE_NOT_FOUND = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCode::eFILE_NOT_FOUND );
static constexpr HRESULT OOCPCCLOUDSTORAGE_E_UNEXPECTED = MAKE_OOCPC_HRESULT( SEVERITY_ERROR, OOCPCFacility::eCLOUDSTORAGE, OOCPCCode::eUNEXPECTED );

#ifdef OOCPC_USE_APPLY_LIST
#define OOCPC_APPLY_LIST_TO_HRCLOUDSTORAGE \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_RENAME_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_PASSPORT_URL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_SERVICE_URL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_LOGIN_TICKET), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_SERVICE_TICKET), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_LOGIN), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_PASSWORD), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_OPEN_REQUEST_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_SEND_REQUEST_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_CLOSE_REQUEST_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_RESPONSE_HEADER), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_DOWNLOAD_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_REQUEST_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_INVALID_FILE_SIZE), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_CLOUD_SERVICE), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_CACHE_STORAGE), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_MISSING_BLOCK), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_UPLOAD_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_REMOVE_FAIL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NO_AWS_CLIENT), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_NOTIMPL), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_FILE_NOT_FOUND), \
    OOCPC_APPLY(OOCPCCLOUDSTORAGE_E_UNEXPECTED)
#endif  // OOCPC_USE_APPLY_LIST


#endif  //ifndef OOCPCHRCLOUDSTORAGE_H
