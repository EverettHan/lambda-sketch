#ifndef CATSHGETFOLDERPATH_H
#define CATSHGETFOLDERPATH_H


/* COPYRIGHT DASSAULT SYSTEMES 2001 */

#ifdef _WINDOWS_SOURCE
#include        "JS0LIB.h"  // exported by..
#include        <ShlObj.h>
#include        "DS_ShlObj.h"
#include        "CATUnicodeString.h"
#include        "CATLib.h"
   /************************************************************************************/
   /* Return a path even if SHGetFolderPath failed.                                    */
   /* Return code:                                                                     */
   /*  - CATLibSuccess : error =  0 :  SHGetFolderPath succeed                         */
   /*                    error =  1 :  pszPath was set to %USERPROFILE%                */
   /*                    error =  2 :  pszPath was set to CATGetTempDirectory          */
   /*                                                                                  */
   /*                                                                                  */
   /*  - CATLibError:    error = -1 :  pszPath was not allocated                       */
   /*                    error =  3 :  pszPath was too short                           */
   /*                    error =  4 :  No path found                                   */
   /************************************************************************************/

ExportedByJS0LIB CATLibStatus CATSHGetFolderPath (HWND hwndOwner, int nFolder,
                                                  HANDLE hToken, DWORD dwFlags, 
                                                  char * pszPath, int &error);

ExportedByJS0LIB CATLibStatus CATSHGetFolderPathW (HWND hwndOwner, int nFolder,
                                                  HANDLE hToken, DWORD dwFlags, 
                                                  CATUnicodeString * Path, int &error);

CATLibStatus CheckWriteAccess (CATUnicodeString path);
#endif
#endif
