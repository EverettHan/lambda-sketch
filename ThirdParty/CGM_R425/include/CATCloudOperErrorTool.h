/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1998  
//=============================================================================
// 
// Message Keys and message catalog for cloud operators errors
//
//=============================================================================
// 31-Jan-2022 - JLH - Portage Linux :
//                     Suppression des warnings et des erreurs de compilation en mode non-permissif.
// 29 May 2000 - STA - Update for mkman.
//    Sep 1999 - STA - Creation
//=============================================================================
//
#ifndef CATCloudOperErrorTool_H
#define CATCloudOperErrorTool_H
/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */ 

#include "ExportedByCATCloudBasicResources.h"

/**
 *  Message Catalog for Operator errors.
 *  @see ERR_InsufficientMemory,ERR_FileNotFound,ERR_TooManyOpenFiles,ERR_AccessDenied,ERR_FileExist,ERR_Failure.
 *  @see CATCloudOperError.
 */
#define CLOUDEDITORERRCATALOG		"CATCldResOperError"

/**
 *  Message Keys for insufficient memory.
 * @see CLOUDEDITORERRCATALOG,CATCloudOperError.
 */
#define ERR_InsufficientMemory		"CATCloudOperErrorTool.ERR_InsufficientMemory"

/**
 * Message Keys for file not found.
 * @see CLOUDEDITORERRCATALOG,CATCloudOperError.
 * @see CATCloudOperErrorTool#ErrnoToMessageKey.
 */
#define ERR_FileNotFound			"CATCloudOperErrorTool.ERR_FileNotFound"
/**
 * Message Keys for too many open files.
 * @see CLOUDEDITORERRCATALOG,CATCloudOperError.
 * @see CATCloudOperErrorTool#ErrnoToMessageKey.
 */
#define ERR_TooManyOpenFiles		"CATCloudOperErrorTool.ERR_TooManyOpenFiles"
/**
 * Message Keys for access denied.
 * @see CLOUDEDITORERRCATALOG,CATCloudOperError.
 * @see CATCloudOperErrorTool#ErrnoToMessageKey.
 */
#define ERR_AccessDenied			"CATCloudOperErrorTool.ERR_AccessDenied"
/**
 * Message Keys for file already exist.
 * @see CLOUDEDITORERRCATALOG,CATCloudOperError.
 * @see CATCloudOperErrorTool#ErrnoToMessageKey.
 */
#define ERR_FileExist				"CATCloudOperErrorTool.ERR_FileExist" 
/**
 * Message Keys for operation failure.
 * @see CLOUDEDITORERRCATALOG,CATCloudOperError.
 * @see CATCloudOperErrorTool#ErrnoToMessageKey.
 */
#define ERR_Failure					"CATCloudOperErrorTool.ERR_Failure"
 
/**
 * Class encapsulate static methods for error managment.
 *
 * @see CATCloudOperError.
 */
class ExportedByCATCloudBasicResources CATCloudOperErrorTool
{
  private:
	CATCloudOperErrorTool();
  public:
	/**
	 * Usefull static method to convert errno to message key.
	 *
	 * Note: only errno set by a file access error are take into accompt!
	 *<br><br>
	 *
	 *<b>Usage:</b>
	 *<dl>
	 *	<dt>if (a file error occur) {		<i>// errno was set</i>
	 *	<dl>
	 *		<dt>CATThrow (new CATCloudOperError(CATCloudOperErrorTool::ErrnoToMessageKey(),CLOUDEDITORERRCATALOG));
	 *	</dl>
	 *	<dt>}
	 *</dl>
	 * 
	 */
	static const char * ErrnoToMessageKey();
};

 

#endif 


