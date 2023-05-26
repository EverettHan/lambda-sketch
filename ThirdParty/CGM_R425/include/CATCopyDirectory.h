#ifndef CATCOPYDIR_H
#define CATCOPYDIR_H
/*
// COPYRIGHT DASSAULT SYSTEMES 2000
*/

#include "JS0LIB.h"
#include "CATLib.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Copies a directory.
 * <br><b>Role</b>:Copies a given directory into a new one.
 * @param iDir
 *      The path of the directory to copy.
 * @param iDirDest
 *      the path of the copy directory
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> CATLibSuccess :</tt>on Success.
 *   <br><tt> CATLibError :</tt> on failure
*/
ExportedByJS0LIB CATLibStatus CATCopyDirectory ( const char *iDir, 	
						 const char *iDirDest);
#ifdef __cplusplus
};
#endif

#endif
