#ifndef CATSysDRMHR_H
#define CATSysDRMHR_H
#include "CATErrorDef.h"

/* COPYRIGHT DASSAULT SYSTEMES 2006 */

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

/** 
 * DRM facility for HRESULT generation.
*/
#define FACILITY_DRM			0xFFD


/**
 * DRM failure.
*/
#define DRM_E_FAIL                     	_HRESULT_TYPEDEF_(0x8FFD0001L)

/**
 * The given DRM document has not been found.
*/
#define DRM_E_DOCUMENTNOTFOUND		_HRESULT_TYPEDEF_(0x8FFD0002L)

/**
 * A DRMILockbytes has no valid key to be able to be decrypted.
*/
#define DRM_E_NOKEY			_HRESULT_TYPEDEF_(0x8FFD0003L)

/** 
 * a right has not been granted in DRM context.
 */
#define DRM_E_ACCESSDENIED		_HRESULT_TYPEDEF_(0x8FFD0005L)

/**
 * No more memory in DRM context.
*/
#define DRM_E_INSUFFICIENTMEMORY	_HRESULT_TYPEDEF_(0x8FFD0008L)

/**
 * No DRM environment has been yet set. 
*/
#define DRM_E_NODRM			_HRESULT_TYPEDEF_(0x8FFD000AL)

/**
 * A call to DRM methods has been issued with invalid parameters.
*/
#define DRM_E_INVALIDPARAMETER          _HRESULT_TYPEDEF_(0x8FFD0057L)

/**
 * Invalid name for a DRM document.
*/
#define DRM_E_INVALIDNAME		_HRESULT_TYPEDEF_(0x8FFD00FCL)
/**
 * Unknown error in DRM context.
*/ 
#define DRM_E_UNKNOWN                   _HRESULT_TYPEDEF_(0x8FFD00FDL)

/**
 * Method is not currently implemented.
*/
#define DRM_E_UNIMPLEMENTED             _HRESULT_TYPEDEF_(0x8FFD00FEL)

/**
 * A unknown right has been queried.
*/
#define DRM_E_UNKNOWNRIGHT              _HRESULT_TYPEDEF_(0x8FFD00FFL)

/**
 * A DRM document has already been closed.
*/
#define DRM_E_REVERTED			_HRESULT_TYPEDEF_(0x8FFD0102L)


/**
 * A DRM document has been created with a to old code version no more supported.
*/
#define DRM_E_OLDFORMAT			_HRESULT_TYPEDEF_(0x8FFD0104L)


/**
 * A document has been encrypted with an other implementation of the DRM interfaces
 * and thus can not be read.
*/
#define DRM_E_OTHERDLL			_HRESULT_TYPEDEF_ (0x8FFD0482L)

/**
 * A DRM User Exit is required to read, but can not be found.
*/
#define DRM_E_NODLL			_HRESULT_TYPEDEF_ (0x8FFD0485L)

/**
 * A DRMILockbytes has detect a corruption and can not be decrypted.
*/
#define DRM_E_CRYPTCORRUPTION		_HRESULT_TYPEDEF_ (0x8FFD0570L)

/**
 * An illegal operation has been detected.
*/
#define DRM_E_ILLEGAL_OPERATION		_HRESULT_TYPEDEF_ (0x8FFD03E3L)

#endif



