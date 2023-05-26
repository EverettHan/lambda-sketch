// COPYRIGHT DASSAULT SYSTEMES 2014
#ifndef CATNlsTools_H
#define CATNlsTools_H

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__CATNlsTools)
# define ExportedByCATNlsTools      DSYExport
#else // __JS0RSCTools
# define ExportedByCATNlsTools      DSYImport
#endif  // __JS0RSCTools

#define ERROR_OK                    0x0     // The file has been converted
#define ERROR_COPIED                0x1     // The conversion is not-applicable. The file has been simply copied.
#define ERROR_UNKNOWN               0x2
#define ERROR_CONV_INIT             0x4     // the converter could not be loaded.
#define ERROR_CONV_INPUT_BAD_EXT    0x8     // Input file is not a CATNls.
#define ERROR_CONV_INPUT_BAD_ENC    0x10    // Input file is not properly encoded.
#define ERROR_IO                    0x20    // File access error.

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/
class DSYSysPath;

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

/**
 * ConvertCATNlsToUTF8.
 * Convert an English CATNls from MBCS (ANSI, ISO-8859-1 encodings) to 
 * UTF-8 Unicode.
 * The main operations performed by this routine are the following:
 *   1) Deep check the input CATNls encoding. If it is already UTF-8 
 *      encoded, go to step 3).
 *   2) Convert the file to UTF-8.
 *   3) Append a charset tag if necessary (if it not already there).
 *   4) Write the output file.
 *
 * @param [out] oCATNlsPath represents the output path for the generated 
 *              UTF-8 encoded CATNls file.
 *              Please note that if oCATNlsPath is missing the .CATNls 
 *              extension, it will be added.
 * @param [in]  iCATNlsPath is the path to the input CATNls file, which 
 *              should be MBCS-encoded.
 * @retval ERROR_OK upon success.
 * @retval ERROR_COPIED if the conversion is not-applicable and the file
 *              has been simply copied.
 * @retval a positive value in case of error. This value has one or more 
 *         of the following flags set:
 *          + ERROR_UNKNOWN (exclusive flag)
 *          + ERROR_CONV_INIT
 *          + ERROR_CONV_INPUT_BAD_EXT
 *          + ERROR_CONV_INPUT_BAD_ENC
 *          + ERROR_IO
 * NOTE: this routine should be thread-safe.
 */
//=======================================================================
ExportedByCATNlsTools int MkProcessCATNls(DSYSysPath &oCATNlsPath, DSYSysPath &iCATNlsPath);
//=======================================================================

#endif  // CATNlsTools_H
