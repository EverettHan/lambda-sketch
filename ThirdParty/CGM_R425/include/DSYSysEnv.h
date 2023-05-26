#ifndef DSYSysEnv_H
#define DSYSysEnv_H

// COPYRIGHT DASSAULT SYSTEMES  2009

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYSysBase.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
/**
 * Get environment variable
 *
 * @param ipName      Environment variable name
 * @return            The environment variable value (NULL if does not exist)
 */
ExportedByDSYSysBase char* DSYSysGetEnv(const char* ipName);
ExportedByDSYSysBase wchar_t* DSYSysGetEnv(const wchar_t* ipName);

/**
 * Set environment variable
 *
 * @param ipName      Environment variable name
 * @param ipValue     Environment variable value
 * @param iOverWrite  Force replace flag. If the environment variable named
 *                    by envname already exists and the value of overwrite is
 *                    non-zero, the function shall return success and the
 *                    environment shall be updated. If the environment variable
 *                    named by envname already exists and the value of overwrite
 *                    is zero, the function shall return success and the
 *                    environmentshall remain unchanged.
 *
 * @return            0 if successful or -1 in the case of an error
 */
ExportedByDSYSysBase int DSYSysSetEnv(const char* ipName, const char* ipValue, int iOverWrite = 0);

/**
 * Unset environment variable
 *
 * @param ipName      Environment variable name
 */
ExportedByDSYSysBase void DSYSysUnsetEnv(const char* ipName);

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

#endif  // DSYSysEnv_H
