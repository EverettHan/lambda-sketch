//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2004                                          *
//*===========================================================================*
//*                                                                           *
//*  Compression		                                              *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation decembre 2004                                  adt              *
//*===========================================================================*
#ifndef CATSysCompress_H
#define CATSysCompress_H
#include "JS0ZLIB.h"
#include "JS0COMP.h"

#include "DSYSysZipErrorDef.h"
#include "DSYSysCompress.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  class CATUnicodeString;


/**
 * Compresses a file.
 * <br><b>Role</b>: Compresses a file. The file is compressed in place in the
 * same directory and is named iName.iExt.
 * @param iName
 *   the name of the file to compress
 * @param iLevel
 *    The compression level.
 *    It  must be or between 0 and 9:
 *    1 gives best speed, 9 gives best compression, 0 gives no compression at
 *    all (the input data is simply copied).
 * @param iExt
 *   the extension to be used
 * @return 
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
 *   <br><tt> CATZ_E_INVALIDARG :</tt> if the level is not correct.
*/
  HRESULT ExportedByJS0COMP CATSysCompressFile( CATUnicodeString* iName, 
						int iLevel, 
						const char *iExt="gz");
						

					
/**
 * Compresses a file.
 * <br><b>Role</b>: Compresses a file. The file is compressed in the
 * same directory and is named iName.iExt.
 * @param iName
 *   the name of the file to compress
 * @param iLevel
 *    The compression level.
 *    It  must be or between 0 and 9:
 *    1 gives best speed, 9 gives best compression, 0 gives no compression at
 *    all (the input data is simply copied).
 * @param iMode
 *   <b>Legal values</b>:
 *   <br><tt> 0 :</tt> the file is compressed in place, thus the original
 *                     uncompressed file is deleted.
 *   <br><tt> 1:</tt>  the file is compressed but the original file remains
 * @param iExt
 *   the extension to be used
 * @return 
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
 *   <br><tt> CATZ_E_INVALIDARG :</tt> if the level is not correct.
*/
  HRESULT ExportedByJS0COMP CATSysCompressFileEx( CATUnicodeString* iName, 
						int iLevel, int iMode,
						const char *iExt=".gz");
						
/**
 * Decompresses a file.
 * <br><b>Role</b>: Decompresses a file. The file is decompressed in place in 
 * the same directory and is named iName less the extension.
 * @param iName
 *   the name of the file to compress
 * @param iExt
 *   the extension that has been used
 * @return 
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> CATZ_E_OUTOFMEMORY :</tt> if there was not enough memory
 *   <br><tt> CATZ_E_INVALIDARG :</tt> if the path is null or if the extension
 *                                     does not match.
 */
HRESULT ExportedByJS0COMP CATSysUncompressFile( CATUnicodeString* iName, 
						const char *iExt=".gz");


#ifdef __cplusplus
}
#endif




#endif /* ZLIB_H */

