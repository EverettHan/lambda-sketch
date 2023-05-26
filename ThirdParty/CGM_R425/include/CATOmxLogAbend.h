#ifndef __CATOmxLogAbend_h__
#define __CATOmxLogAbend_h__

/**
 * @level Protected
 * @usage U1
 */

 // ObjectModelerCollection
#include "CATOmxKernel.h" // ExportedByCATOmxKernel
#include "CATOmxKeyValueBlock.h"

/**obsolete*/
#define CATOmxDefineFileNameAgain(iFileName) static const char * const CATOmxLogAbendFileName = iFileName
/**obsolete*/
#define CATOmxDefineFileName CATOmxDefineFileNameAgain(__FILE__)

/**nodoc, internal usage*/
ExportedByCATOmxKernel void CATOmxLogAbendFunction(const char * const iMessage, const char * const iFileName, const int iLine);

// The message is inserted in the string "Invariant failed: ... in ... at line ...",
// so if you expect "something" to be true, write
//   if ( !something ) CATOmxLogAbend("something");
#define CATOmxLogAbend(iMessage) CATOmxLogAbendFunction(iMessage, __FILE__, __LINE__)

/**nodoc, internal usage*/
ExportedByCATOmxKernel void CATOmxLogAbendPrintfFunction(const char* iFileName, int iLine, const char* format, ...);

/** same as CATOmxLogAbend but using a printf formated message*/
#define CATOmxLogAbendPrintf(format,...) CATOmxLogAbendPrintfFunction(__FILE__,__LINE__,format,__VA_ARGS__)

/** internal functions, do not use directly, use instead CATOmxLogAbendError/CATOmxLogError macros*/
ExportedByCATOmxKernel void CATOmxLogErrorFunction(const char* iFileName, int iLine, bool iAbend, const CATUnicodeString& iMessage, const CATOmxKeyValueBlock& iProperties);
inline void CATOmxLogErrorFunction(const char* iFileName, int iLine, bool iAbend, const CATUnicodeString& iMessage) { return CATOmxLogErrorFunction(iFileName, iLine, iAbend, iMessage, CATOmxKeyValueBlock()); }
ExportedByCATOmxKernel void CATOmxLogErrorFunction(const char* iFileName, int iLine, bool iAbend, const class CATError& iError, const CATOmxKeyValueBlock& iAdditionalProperties);
inline void CATOmxLogErrorFunction(const char* iFileName, int iLine, bool iAbend, const class CATError& iError) { return CATOmxLogErrorFunction(iFileName, iLine, iAbend, iError, CATOmxKeyValueBlock()); }

/**
 * log a CATError in "error log"
 * CATOmxLogAbendError will trigger a CATSysLogAbend (and so terminate process in CATDevelopmentStage), CATOmxLogError will not.
 *
 * examples:
 *
 * CATOmxLogAbendError("this should not occur"); //same as CATOmxLogAbend
 * CATOmxLogError("this should not occur"); //log the message, no abend
 *
 * CATError* error = ...;
 * CATOmxLogError(*error); //log all informations concerning error
 *
 * CATOmxKeyValueBlock additionalInfos;
 * additionalInfos.SetValue("ObjectId","Wheel.3")
 * CATOmxLogError(*error,additionalInfos); //log all informations concerning error, enrich log with additionalInfos
 */
#define CATOmxLogAbendError(...) CATOmxLogErrorFunction(__FILE__,__LINE__,true,__VA_ARGS__)

#ifndef CATOmxLogError
#ifdef _WINDOWS_SOURCE
#pragma deprecated(CATOmxLogError)
#endif
 /**
  * same as CATOmxLogAbendError but does not call CATSysLogAbend (and never crashes even in ODT mode)
  * deprected: migrate to CATOmxLogError from CATOmxLogError.h or use CATOmxLogCATError
  */
#define CATOmxLogError(...)     CATOmxLogErrorFunction(__FILE__,__LINE__,false,__VA_ARGS__)
#endif

  /** same as CATOmxLogError, use it when you also use CATOmxLogError.h */
#define CATOmxLogCATError(...)     CATOmxLogErrorFunction(__FILE__,__LINE__,false,__VA_ARGS__)

#endif // __CATOmxLogAbend_h__
