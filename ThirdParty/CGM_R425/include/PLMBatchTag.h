/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002
//===========================================================================
// Usage Notes:   
//===========================================================================
// September 2002   Creation                  YWE 
// Les Tags de PLMBATCH: la plateforme Batch d'acces aux donnees
//===========================================================================

//#ifndef PLMBatchTag_h
//#define PLMBatchTag_h

/** @level Protected 
* @usage U1
*/
#ifndef PATHSeparator    
#ifdef _WINDOWS_SOURCE
#define PATHSeparator      "\\"
#else
#define PATHSeparator      "/"
#endif
#endif
#ifndef PATH_CHAR_Separator    
#ifdef _WINDOWS_SOURCE
#define PATH_CHAR_Separator      '\\'
#else
#define PATH_CHAR_Separator      '/'
#endif
#endif

#include "CATUnicodeString.h"
/**
 * Defines the PLMBatch report directory.
 */
#ifndef PLMBATCH_REPORT_DIR
#define PLMBATCH_REPORT_DIR "\\ PLMBATCH \\" 
#endif

/**
 * DEFAULT_DIR: Defines the default directory for output.
 * <BR> By default, DEFAULTDIR and TMPDIR are initialized with the class
 * <DD>DEFAULTDIR : execution directory (PWD variable)
 * <DD>     TMPDIR : temporary directory (ADL_TMP variable)
 * Directory "" == DEFAULTDIR
 */

#ifndef DEFAULTDIR
#define DEFAULTDIR "\\ DEFAULT \\"
#endif


#ifndef CNEXT_SYNCHRO
#define CNEXT_SYNCHRO 0
#endif

#ifndef CATUTIL
#define CATUTIL 1
#endif


#ifndef CNEXT_ASYNCHRO
#define CNEXT_ASYNCHRO 2
#endif

/**
 * HELP_VPLMOBJ_SEARCH: Defines URL of the Search Object in PLMBatch official documentation
 */

#ifndef HELP_VPLMOBJ_SEARCH
//#ifdef _WINDOWS_SOURCE
//#define HELP_VPLMOBJ_SEARCH "online\\basug_C2\\basugbt2305.htm"   // the name of the file of the help document
//#else
//#define HELP_VPLMOBJ_SEARCH "online/basug_C2/basugbt2305.htm"   // the name of the file of the help document
#define HELP_VPLMOBJ_SEARCH "English/ComUserMap/com-t-Batch-ObjectSearch.htm"   // the name of the file of the help document
//#endif
#endif

#ifndef HELP_FILEDOC_SEARCH
//#ifdef _WINDOWS_SOURCE
//#define HELP_FILEDOC_SEARCH "online\\basug_C2\\basugbt2304.htm"   // the name of the file of the help document
//#else
//#define HELP_FILEDOC_SEARCH "online/basug_C2/basugbt2304.htm"   // the name of the file of the help document
#define HELP_FILEDOC_SEARCH "English/ComUserMap/com-t-Batch-FileSearch.htm"   // the name of the file of the help document
//#endif
#endif

//#endif
