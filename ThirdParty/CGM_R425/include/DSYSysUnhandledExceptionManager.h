#ifndef DSYSysUnhandledExceptionManager_H
#define DSYSysUnhandledExceptionManager_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYSysUnhandledExceptionFilter_Win.h"
#include "DSYSysUnhandledExceptionFilter_Unix.h"
#include "DSYSysUnhandledExceptionFilter_Other.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
/**
 * We define here the right wrapper depending on the system we are on
 *
 *
 *                                                ----------------------------------
 *                                                | DSYSysUnhandledExceptionFilter |
 *                                                ----------------------------------
 *                                                               |
 *                                                               |
 *                   -----------------------------------------------------------------------------------------
 *                  |                                            |                                           |
 *                  |                                            |                                           |
 *  --------------------------------------     ---------------------------------------      ----------------------------------------
 *  | DSYSysUnhandledExceptionFilter_Win |     | DSYSysUnhandledExceptionFilter_Unix |      | DSYSysUnhandledExceptionFilter_Other |
 *  --------------------------------------     ---------------------------------------      ----------------------------------------
 *                  |                                            |                                           |
 *                  |                                            |                                           |
 *                   -----------------------------------------------------------------------------------------
 *                                                               |
 *                                                              \|/
 *                                              -----------------------------------
 *                                              | DSYSysUnhandledExceptionManager |
 *                                              -----------------------------------
 *
 */
/// Consider the wrapper as a unique object
#if defined(DSYSysUnhandledExceptionFilter_Win_H)
# define DSYSysInstallExceptionFilter     DSYSysInstallExceptionFilter_Win
# define DSYSysUninstallExceptionFilter   DSYSysUninstallExceptionFilter_Win
#else // DSYSysUnhandledExceptionFilter_Win_H
# if defined(DSYSysUnhandledExceptionFilter_Unix_H)
#   define DSYSysInstallExceptionFilter     DSYSysInstallExceptionFilter_Unix
#   define DSYSysUninstallExceptionFilter   DSYSysUninstallExceptionFilter_Unix
# else  // DSYSysUnhandledExceptionFilter_Unix_H
#   define DSYSysInstallExceptionFilter     DSYSysInstallExceptionFilter_Other
#   define DSYSysUninstallExceptionFilter   DSYSysUninstallExceptionFilter_Other
# endif // DSYSysUnhandledExceptionFilter_Unix_H
#endif  // DSYSysUnhandledExceptionFilter_Win_H

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

#endif  // DSYSysUnhandledExceptionManager_H
