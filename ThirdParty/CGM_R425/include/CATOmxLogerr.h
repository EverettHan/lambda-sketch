#ifndef __CATOmxLogerr_h__
#define __CATOmxLogerr_h__
#include "CATOmxKernel.h"

#include "CATOmxTextStream.h"

#include <stdio.h>
class CATBaseUnknown;
class CATOmxKeyString;
class CATOmxExpandContext;

/**
 * Build an error context.
 */
struct CATOmxErrContext {
  const char*m_title;
  const char*m_file;
  const unsigned m_lineno;
  const char*m_near;
  CATOmxExpandContext *m_ctx;
  /**
   * Constructor.
   * @param iTitle the associated title
   * @param i
   */
  inline CATOmxErrContext(const char *iTitle, const char*iFile, unsigned iLineno, const char*iNear) : m_title(iTitle), m_file(iFile), m_lineno(iLineno), m_near(iNear), m_ctx(0) {}

};


/**
* allows to print a pointer
* CATOmxTextStream stream;
* void* ptr = ...
* stream << CATOmxPrintPointer(ptr);
*/
struct CATOmxPrintBUAsPointer
{
  const CATBaseUnknown* const m_ptr;
  inline CATOmxPrintBUAsPointer(const CATBaseUnknown* ptr) :m_ptr(ptr) {}
};
ExportedByCATOmxKernel CATOmxTextStream & operator<<(CATOmxTextStream& out, const CATOmxPrintBUAsPointer& ptr);
inline OMX_DEPRECATED("use CATOmxPrintBUAsPointer if you really want to print an address") CATOmxTextStream &  operator <<(CATOmxTextStream& out, const CATBaseUnknown* ptr) { return out << CATOmxPrintBUAsPointer(ptr); }

/**
 * Logging stream.
 * Important note : CATOmxLogerr will be integrated to CATOmxTextStream.
 *
 * The logging is altered by the severity of message.
 * Uppercase severity:
 * http://osmwebdsy/wiki/index.php/Omxlog_Severity
 *
 */
class ExportedByCATOmxKernel CATOmxLogerr {
public:


  /**
   * Associate Nls file to error-class.
   * The basic principle is to map the logerr(XX, iLabel, iTitle ) to a CATNls file.
   * if the CATOmxLogerr detect a mapped iLabel to iFile it try to find the iTitle string.
   * if found the iTitle is used as a key.
   *
   * @param iLabel the class to associate
   * @param iFile the basename of the NLS_FILE
   */
  static void NlsRegister(const char*iLabel, const char *iFile);
  /** Return the low level stream. */
};
/** */
#define OMX_PRINTLINE 0x0001
/**
 * Insert a stack in the log.
 * Caution PCS issue!
 */
#define OMX_LOGSTACK  0x0002

/**
 * Start a new error message with a source line context.
 * logerr('E',"OSM-ID",ctx)<< parm("ft") << this<< endl;
 * @param iSev   message severity
 * @param iLabel message label
 * @param iCtx   the source line context
 * @param iFlags OMX_LOGSTACK or OMX_PRINTLINE
 *
 */
ExportedByCATOmxKernel CATOmxTextStream &logerr(char iSev, const char*iLabel, CATOmxErrContext&iCtx, unsigned iFlags = 0);
/**
 * Start a new error message.
 * logerr('E',"OSM-ID","Label title")<< parm("ft") << this<< endl;
 *
 */
ExportedByCATOmxKernel CATOmxTextStream &logerr(char iSev, const char*iLabel, const char *iTitle, unsigned iFlags = 0);

/**
 * Start & close a message.
 * All parameter are provided thru an expand contex.
 * @param iSev message severity
 * @param iLabel message family identification
 * @param iExpandTitle the expand message
 * @param iContext the expansion context
 */
ExportedByCATOmxKernel void logerr(char iSev, const char*iLabel, const char *iExpandTitle, const CATOmxExpandContext &iContext);

/**
 * Report a source defect (usefull to soft assert).
 * Anomaly is logged in odt omxlog file and reported in MemoryCheck as an extended error.
 * If you want to track your anomaly in the omxlog web you have to ensure that your iLabel match the
 * following perl compatible regular expression "([><=])([A-Z]{3})-([A-Z]+)_(\d+)"
 *
 * @param iFile the file name use the  __FILE__ macro
 * @param iLine the line number use the __LINE__ macro
 * @param iLabel the encoded error id
 *    "{prefix}{fwcode}-{error}_{number}"
 *    where:
 *    {prefix} is > for precondition < for postcondition and = for invariant)
 *    {fwcode} is the 3 letter fw uppercase prefix (ex: OSM for ObjectSpecsModeler OMX for ObjectModelerCollection)
 *    {error}  an error identifier (uppercase)
 *    {number} the number of error
 *
 */
ExportedByCATOmxKernel
int CATOmxError(const char* iFile, int iLine, const char *iLabel, const char* iExpr);

#endif
