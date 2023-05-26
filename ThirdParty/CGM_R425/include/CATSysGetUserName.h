#ifndef CATSysGetUserName_H
#define CATSysGetUserName_H

#include "CATLib.h"

/**
 ** CATSysGetUserName 
 ** return the content of the USERNAME environment variable on Windows
 ** returns the same as CATGetLoginName on UNIX
 ** 
 **  ARGUMENTS
 **  iNameBuffer  : buffer where the name will be written
 **                  iNameBuffer must be of iNameSize length
 **  iNameSize    : length of the iNameBuffer buffer
 ** 
 **  RETURN VALUE
 **  CATLibSuccess : successfully retrieved the user name
 **  CATLibFailure : failed in retrieving the user name
 ** 
 **/
ExportedByJS0LIB CATLibStatus CATSysGetUserName (char *iNameBuffer,
					       unsigned int iNameSize);
#endif
