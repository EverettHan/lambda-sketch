#ifndef __CATOmxAnyConvert_h__
#define __CATOmxAnyConvert_h__

#include "CATOmxKernel.h"
#include "IUnknown.h"

class CATOmxAny;
class _SEQUENCE_octet;
class CATRawCollint;
class CATRawColldouble;
class CATListValCATUnicodeString;
class CATListValCATBaseUnknown_var;
class CORBAAny;
class CATBinary;

/**
 * some conversion services between CATOmxAny and system collections
 * prefer CATOmxArray (@see CATOmxAnyArrayConvert.h) which allow shallow copies.
 */

/** _SEQUENCE_octet to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const _SEQUENCE_octet& );
/** _SEQUENCE_octet from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,_SEQUENCE_octet& );

/** CATRawCollint to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const CATRawCollint& );
/** CATRawCollint from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,CATRawCollint& );

/** CATRawColldouble to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const CATRawColldouble& );
/** CATRawColldouble from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,CATRawColldouble& );

/** CATListValCATUnicodeString to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const CATListValCATUnicodeString& );
/** CATListValCATUnicodeString from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,CATListValCATUnicodeString& );

/** CATListValCATBaseUnknown_var to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const CATListValCATBaseUnknown_var& );
/** CATListValCATBaseUnknown_var from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,CATListValCATBaseUnknown_var& );

/** CATBinary to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const CORBAAny& );
/** CATBinary from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,CORBAAny& );

/** CATBinary to CATOmxAny */
ExportedByCATOmxKernel HRESULT operator<<(CATOmxAny& any,const CATBinary& );
/** CATBinary from CATOmxAny */
ExportedByCATOmxKernel HRESULT operator>>(const CATOmxAny& any,CATBinary& );

#endif

