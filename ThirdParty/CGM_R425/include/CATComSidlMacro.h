// COPYRIGHT DASSAULT SYSTEMES 2007
#ifndef CATComSidlMacro_h
#define CATComSidlMacro_h

#include "BigLittle.h"
#include "CATComSidlError.h"

#define IF_NEGATIVE_SIZE_RETURN_ERROR(Trace, A, err) \
	if ((A) < 0)\
	{\
		_Invalidated = 1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NEGATIVE_SIZE_RETURN_ERROR)");\
		return CATReturnError(new CATComSidlError(#err, "CATComSidlError"));\
	}

#define IF_WRONG_SIZE_READ_RETURN_E_FAIL_AND_FREE(Trace, SIZE, SIZEREAD) \
	if ((SIZE) != (SIZEREAD))\
	{\
		free(buffer);\
		_Invalidated = 1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_WRONG_SIZE_READ_RETURN_E_FAIL_AND_FREE)");\
		return E_FAIL;\
	}

#define IF_WRONG_SIZE_READ_RETURN_E_FAIL(Trace, SIZE, SIZEREAD) \
	if ((SIZE) != (SIZEREAD))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_WRONG_SIZE_READ_RETURN_E_FAIL)");\
		return E_FAIL;\
	}

#define IF_NOT_A_OR_NOT_B_RETURN_E_FAIL(Trace, A, B) \
	if (!(A) || !(B))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NOT_A_OR_NOT_B_RETURN_E_FAIL)");\
		return E_FAIL;\
	}

#define IF_OPEN_OR_OPENONCE_RETURN_E_ALREADYOPEN(Trace, A, B) \
	if ((A) || (B))\
	{\
		A = 0;\
		B = 1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_OPEN_OR_OPENONCE_RETURN_E_ALREADYOPEN)");\
		return E_ALREADYOPEN;\
	}

#define IF_NOT_A_INVALIDAT_RETURN_ERROR(Trace, A, err) \
	if (!(A))\
	{\
		_Invalidated=1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NOT_A_INVALIDAT_RETURN_ERROR)");\
		return CATReturnError(new CATComSidlError(#err, "CATComSidlError"));\
	}

#define IF_NOT_A_RETURN_ERROR(Trace, A, err) \
	if (!(A))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NOT_A_RETURN_ERROR)");\
		return CATReturnError(new CATComSidlError(#err, "CATComSidlError"));\
	}

#define IF_INVALIDATED_RETURN_ERROR(Trace) \
	if (_Invalidated)\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_INVALIDATED_RETURN_ERROR)");\
		return E_INVALID_STREAM;\
	}

#define IF_FAILED_ALLOC_A_RETURN_ERROR(Trace, A) \
	if (!(A))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_FAILED_ALLOC_A_RETURN_ERROR)");\
		return E_OUTOFMEMORY;\
	}

#define IF_NOT_A_RETURN_E_FAIL(Trace, A) \
	if (!(A))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NOT_A_RETURN_E_FAIL)");\
		return E_FAIL;\
	}

#define IF_NOT_A_RETURN_E_INVALIDARG(Trace, A) \
	if (!(A))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NOT_A_RETURN_E_INVALIDARG)");\
		return E_INVALIDARG;\
	}

#define TEST_ERROR_AND_INVALIDATE(Trace, A, err) \
	if (FAILED(A)) \
	{\
		_Invalidated = 1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (TEST_ERROR_AND_INVALIDATE)");\
		return CATReturnError(new CATComSidlError(#err, "CATComSidlError"));\
	}

#define IF_FAILED_HR_RETURN_HR_AND_INVALIDATE(Trace, A) \
	if (FAILED(A))\
	{\
		_Invalidated = 1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_FAILED_HR_RETURN_HR_AND_INVALIDATE)");\
		return (A);\
	}

#define IF_FAILED_HR_RETURN_HR(Trace, A) \
	if (FAILED(A))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_FAILED_HR_RETURN_HR)");\
		return (A);\
	}

#define INVALIDATE_AND_RETURN_ERROR(Trace, err) \
	{\
		_Invalidated=1;\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (INVALIDATE_AND_RETURN_ERROR)");\
		return CATReturnError(new CATComSidlError(#err, "CATComSidlError"));\
	}

//SIP: Error in unstream of error
#define IF_NOT_A_OR_FAILED_B_CREATE_ERROR(Trace, A, B, err) \
	if (!(A) || FAILED(B))\
	{\
		DSYSysTraceError(Trace, "\tPLMSidlComHttpChunkedStreamClt::Error Macro (IF_NOT_A_OR_FAILED_B_CREATE_ERROR)");\
		A = new CATComSidlError(#err,"CATComSidlError");\
	}




//SIP: Warning this should be #ifdef but to keep compatibility we invert
#ifndef _ENDIAN_LITTLE
#define LEndianToBEndian16(A) (((A & 0xFF00) >> 8) | ((A & 0x00FF) << 8))
#define LEndianToBEndian32(A) ((((CATULONG32) A >> 24) & 0x000000FF) | (((CATULONG32) A >> 8) & 0x0000FF00) | (((CATULONG32) A << 8) & 0x00FF0000) | (((CATULONG32) A << 24) & 0xFF000000))
#define LEndianToBEndian64(A) ((((CATULONG64) A >> 56) & 0x00000000000000FF) | (((CATULONG64) A >> 40) & 0x000000000000FF00) | (((CATULONG64) A >> 24) & 0x0000000000FF0000) | (((CATULONG64) A >> 8) & 0x00000000FF000000) | (((CATULONG64) A << 8) & 0x000000FF00000000) | (((CATULONG64) A << 24) & 0x0000FF0000000000) | (((CATULONG64) A << 40) & 0x00FF000000000000) | (((CATULONG64) A << 56) & 0xFF00000000000000))
#define LEndianToBEndian16OK(A) (A)
#define LEndianToBEndian32OK(A) (A)
#define LEndianToBEndian64OK(A) (A)
#else
#define LEndianToBEndian16(A) (A)
#define LEndianToBEndian32(A) (A)
#define LEndianToBEndian64(A) (A)
#define LEndianToBEndian16OK(A) (((A & 0xFF00) >> 8) | ((A & 0x00FF) << 8))
#define LEndianToBEndian32OK(A) ((((CATULONG32) A >> 24) & 0x000000FF) | (((CATULONG32) A >> 8) & 0x0000FF00) | (((CATULONG32) A << 8) & 0x00FF0000) | (((CATULONG32) A << 24) & 0xFF000000))
#define LEndianToBEndian64OK(A) ((((CATULONG64) A >> 56) & 0x00000000000000FF) | (((CATULONG64) A >> 40) & 0x000000000000FF00) | (((CATULONG64) A >> 24) & 0x0000000000FF0000) | (((CATULONG64) A >> 8) & 0x00000000FF000000) | (((CATULONG64) A << 8) & 0x000000FF00000000) | (((CATULONG64) A << 24) & 0x0000FF0000000000) | (((CATULONG64) A << 40) & 0x00FF000000000000) | (((CATULONG64) A << 56) & 0xFF00000000000000))

#endif

#endif //_H
