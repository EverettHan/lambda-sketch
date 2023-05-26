#ifndef __CATOmxLogError_h__
#define __CATOmxLogError_h__


/**
 * @href http://osmwebdsy/wiki/index.php/CATOmxLogError#CATOmxLogImpact
 */
#define CATOmxLogImpact(errorId,...) CATOmxLogErrorMacro(Impact, errorId, __VA_ARGS__)

#ifndef CATOmxLogError
 /**
  * @href http://osmwebdsy/wiki/index.php/CATOmxLogError#CATOmxLogError
  */
#define CATOmxLogError(errorId,...) CATOmxLogErrorMacro(Error, errorId, __VA_ARGS__)
#endif
  /** same as CATOmxLogError, use it if you also use CATOmxLogAbend.h */
#define CATOmxLogError2(errorId,...) CATOmxLogErrorMacro(Error, errorId, __VA_ARGS__)

/**
 * @href http://osmwebdsy/wiki/index.php/CATOmxLogError#CATOmxLogUnexpectedError
 */
#define CATOmxLogUnexpectedError(errorId,...) CATOmxLogErrorMacro(UnexpectedError, errorId, __VA_ARGS__)

 /**
 * @href http://osmwebdsy/wiki/index.php/CATOmxLogError#CATOmxLogExternalError
 */
#define CATOmxLogExternalError(errorId,...) CATOmx::LogError(CATOmx::ExternalError, __FILE__, __LINE__, errorId, CATOmxMakePrinter(__VA_ARGS__))


 // System
#include "CATUnicodeString.h"
class CATError;
// ObjectModelerCollection
#include "CATOmxKernel.h"
#include "CATOmxPrint.h"
#include "CATOmxTextStream.h"
#include "CATOmxCxxPortability.h"

/**
 * prints a CATError into a CATOmxTextStream for debugging purpose
 * outputs something like:
 *   $(error->GetMsgId())@$(error->GetMsgCatalog()).CATNls, {"Type":"$(error->IsA())", "ErrorMessage":"$(error->GetNLSMessage()",...}
 */
ExportedByCATOmxKernel CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATError* error);
inline CATOmxTextStream& operator<<(CATOmxTextStream& out, const CATError& error) { return operator<<(out, &error); }


#if OMX_CXX11_SUPPORT_LAMBDA == 1
#include <functional>
#endif

namespace CATOmx
{
  /** internal */
  enum Severity { Impact, Error, UnexpectedError, ExternalError, LegacyLogError, LegacyLogAbend };

  /** internal */
#if OMX_CXX11_SUPPORT_LAMBDA == 1
  typedef std::function<void(CATOmxTextStream&)> MessageBuilder;
#else
  typedef CATUnicodeString MessageBuilder;
#endif

  /** internal implementation functions, do not call directly*/
  ExportedByCATOmxKernel void LogError(Severity severity, const char* source, int line, const char* iErrorId, const MessageBuilder& buildMessage);
  ExportedByCATOmxKernel const char* GetErrorId(const CATError* error);
  inline const char* GetErrorId(const CATError& error) { return GetErrorId(&error); }
}

#if OMX_CXX11_SUPPORT_LAMBDA == 1
/** internal helper */
#define CATOmxMakePrinter(...) [&](CATOmxTextStream& out) {CATOmxPrint(out, __VA_ARGS__); }
#else
/** internal helper */
#define CATOmxMakePrinter(...) CATUnicodeString()
#endif

/** internal helper */
#define CATOmxLogErrorMacro(severity, errorId, ...) \
  do \
  { \
    struct errorId { static void severity(const CATOmx::MessageBuilder& buildMessage) { CATOmx::LogError(CATOmx::severity, __FILE__, __LINE__, #errorId, buildMessage ); } }; \
    errorId::severity(CATOmxMakePrinter(__VA_ARGS__)); \
  } while (false)


#endif // __CATOmxLogError_h__
