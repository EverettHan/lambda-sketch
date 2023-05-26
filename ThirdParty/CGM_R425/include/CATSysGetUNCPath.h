//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004                                          
//===========================================================================
//                                                                           
//  Standard Files                                                     
//                                                                           
//  Usage Notes: As stdio
//===========================================================================
//  Creation avril 2004                                 adt              
//===========================================================================

#ifndef __CATSYSGETUNCPATH
#define __CATSYSGETUNCPATH
#include "JS0LIB.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include <time.h>

class CATUnicodeString;

/*
 * Retrieves the UNC path.
 * <br><b>Role</b>: takes a drive-based path for a network resource and 
 * returns an universal form of the name if applicable. On UNIX this function 
 * returns the original path, because the notion is not available.
 * @param iPath [in]
 *	Path of a drive-based path for a network resource.
 * @param oUNCPath [out]
 *      corresponding UNC path. It could be NULL if the functions fails.
 * @return 
 * <b>Legal values</b>:
 * <br><tt> S_OK:</tt> on success in this case an UNC path has been retrieved.
 * <br><tt> S_FALSE:</tt> if the transformation is not applicable because the 
 * current platform is unix, or on Windows because the resource is local.
 * <br><tt> <0:</tt>  on error.
 */ 

ExportedByJS0LIB HRESULT CATSysGetUNCPath( CATUnicodeString *iPath,
					   CATUnicodeString **oUNCPath);
 

#endif
