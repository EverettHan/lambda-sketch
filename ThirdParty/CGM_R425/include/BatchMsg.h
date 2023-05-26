/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* ================================================================================== */
#ifndef BatchMsg_H_
#define BatchMsg_H_
// COPYRIGHT DASSAULT SYSTEMES 1997

/** 
 *  @level Protected 
 *  @usage U1
 */

#include "CATIAV5Level.h"

//===========================================================================
// November 2002   Creation                  YWE 
// ==========================================================================
//
/*x
Section Batch Messages
Abstract This section contains methods to display messages
* <BR> As a PLMBatch convention:
* <UL>
* <LI> an eror has a returnCode > 0
* <LI> a warning has a returnCode < 0
* </UL>
* Documents have error from 70 to  89 and some negative values
x*/


/**
 * param IerDocNotV5.
 * Error Document not V5 type.
 */
#define   IerDocNotV5                  70
/**  
 * param IerDocNotExist.
 * Error Document not  Exists.
 */
#define   IerDocNotExist               71
/** 
 * param IerDocNotConverted.
 * Error Document not Converted.
 */
#define   IerDocNotConverted           72
/** 
 * param IerDocNoReadAccess.
 * Error Document no Read Access.
 */
#define   IerDocNoReadAccess           73
/** 
 * param IerDocNoWriteAccess.
 * Error Document no Write Access.
 */
#define   IerDocNoWriteAccess          74
/** 
 * param IerDocBadExtension.
 * Error Document with Bad Extension.
 */
#define   IerDocBadExtension           75
/** 
 * param WngDocGoodExtension.
 * Warning Document with Good Extension.
 */
#define   WngDocGoodExtension         -75
/** 
 * param IerDocInUse.
 * Error Document in Use.
 */
#define   IerDocInUse		       76
/** 
 * param IerDocNoDoc.
 * Error No such Document.
 */
#define   IerDocNoDoc		       77
/** 
 * param IerDocReadError.
 * Error Document Read error.
 */
#define   IerDocReadError	       78
/** 
 * param IerDocWriteError.
 * Error Document Write error.
 */
#define   IerDocWriteError	       79
/**  
 * param IerDocNoDocFound.
 * Error Document not found.
 */
#define   IerDocNoDocFound             80
/** 
 * param IerDocAlreadyExist.
 * Error Document already exists.
 */
#define   IerDocAlreadyExist           81
/** 
 * param IerDocAlreadyExist.
 * Error Document already exists.
 * There is no Replace option.
 */
#define   IerDocAlreadyExistNoReplace      83
/** 
 * param WngDocAlreadyExist.
 * Warning Document already exists.
 */
#define   WngDocAlreadyExist          -81
/** 
 * param WngDocWillBeOverWritten.
 * Warning Document will overwritten if already exists.
 */
#define   WngDocWillBeOverWritten          -82
/** 
 * param WngDocBackUpCreated.
 * Warning Document backup created.
 */
#define   WngDocBackUpCreated          -88
/** 
 * param IerDocCreationError.
 * Error Document Creation error.
 */
#define   IerDocCreationError	       82
/** 
 * param WngDocNotProcessed.
 * Warning Document not processed.
 */
#define   WngDocNotProcessed         -100  /* negative absolument !!! */
/** 
 * param WngDocAlreadyProcessed.
 * Warning Document already processed.
 */
#define   WngDocAlreadyProcessed     -101  /* negative absolument !!! */
/** 
 * param InfDocProcessed.
 * Info Document processed.
 */
#define   InfDocProcessed            -102  /* negative absolument !!! */
/** 
 * param InfDocNotModified.
 * Info Document not modified.
 */
#define   InfDocNotModified          -103  /* negative absolument !!! */
/** 
 * param InfDocWrite.
 * Info Document is written.
 */
#define   InfDocWrite                -104  /* negative absolument !!! */

/** 
 * param IerDocRefNotV5.
 * Error Document Reference not V5.
 */
#define   IerDocRefNotV5                87
/** 
 * param IerDocRefNotExist.
 * Error Document Reference no existance.
 */
#define   IerDocRefNotExist             88
/** 
 * param IerDocRefNoReadAccess.
 * Error Document Reference no read access.
 */
#define   IerDocRefNoReadAccess         89
/** 
 * param IerNewDocNoRefOverwrite.
 * Error Document Reference Overwrite.
 */
#define   IerNewDocNoRefOverwrite       90
/** 
 * param IerNewDocNoWriteAccess.
 * Error New Document no write access.
 */
#define   IerNewDocNoWriteAccess        91
/** 
 * param IerNewDocAlreadyExist.
 * Error New Document already exists.
 */
#define   IerNewDocAlreadyExist         92
/** 
 * param IerNewDocWriteError.
 * Error New Document write error.
 */
#define   IerNewDocWriteError	        96
/** 
 * param WngNewDocAlreadyExist.
 * Warning New Document already exists.
 */
#define   WngNewDocAlreadyExist        -92
/** 
 * param WngNewDocBackuped.
 * Warning New Document backed up.
 */
#define   WngNewDocBackuped            -93
/** 
 * param WngNewDocBackupAbort.
 * Warning New Document back up abort.
 */
#define   WngNewDocBackupAbort         -94
/** 
 * param InfNewDocPowerCopied.
 * Info New Document power copied.
 */
#define   InfNewDocPowerCopied         -95
/** 
 * param InfNewDocWrite.
 * Info New Document write successful.
 */
#define   InfNewDocWrite               -96  /* negative absolument !!! */
/** 
 * param IerFileIsADir.
 * Error File is Directory.
 */
#define   IerFileIsADir				   -97
/**
* param LateTypeNotSupported.
* Warning late type not supported .
*/
#define WngLateTypeNotSupported     	-84

#ifndef CATIAR417 // Migration on CATError PartOpenFailure after 216        
/**
* param RepNotFound.
* Warning Representation Not Found.
* <BR>CheckRep: Protection on Rep without available Authoring stream (cf HF 133305)
*/
#define WngDocNotFoundFromPLMComponent					-85 
#endif

// ==========================================================================
// Les Directory : 200 -> 249 & negatifs
// ==========================================================================
/** 
 * param IerDirisaFile.
 * Error Directory  is a file.
 */
#define   IerDirisaFile                 200
/** 
 * param IerDirNotExist.
 * Error Directory  not exists.
 */
#define   IerDirNotExist                201
/** 
 * param IerDirNoReadAccess.
 * Error Directory  no read access.
 */
#define   IerDirNoReadAccess            203
/** 
 * param IerDirNoWriteAccess.
 * Error Directory  no write access.
 */
#define   IerDirNoWriteAccess           204
/** 
 * param IerDirUndefined.
 * Error Directory  undefined.
 */
#define   IerDirUndefined               205
/** 
 * param IerDirConflict.
 * Error Directory  conflict.
 */
#define   IerDirConflict                206
/** 
 * param WngDirNotSelected.
 * Warning Directory not selected.
 */
#define   WngDirNotSelected          -201
/** 
 * param WngDocAlreadySelected.
 * Warning Document already selected.
 */
#define   WngDocAlreadySelected      -202

// Les XmlFiles : 270 -> 279 & negatifs
/**  
 * param IerXmlFileisaDir.
 * Error Xml File is a directory. 
*/
#define   IerXmlFileisaDir               270
/** 
 * param IerXmlFileNotExist.
 * Error Xml File not exists.
 */
#define   IerXmlFileNotExist             271
/** 
 * param IerXmlFileNoReadAccess.
 * Error Xml File no read access.
 */
#define   IerXmlFileNoReadAccess         273
/**  
 * param IerXmlFileNoWriteAccess.
 * Error Xml File no write access.
 */
#define   IerXmlFileNoWriteAccess        274
/** 
 * param IerXmlFileBadExtension.
 * Error Xml File bad extension.
*/
#define   IerXmlFileBadExtension         275
/** 
 * param IerXmlFileInUse.
 * Error Xml File in use.
 */
#define   IerXmlFileInUse		 276
/** 
 * param IerXmlFileReadError.
 * Error Xml File read error.
*/
#define   IerXmlFileReadError	         278
/** 
 * param IerXmlFileWriteError.
 * Error Xml File write error. 
*/
#define   IerXmlFileWriteError	         279
/** 
 * param WngXmlFileNotSelected.
 * Warning Xml File not selected.
*/
#define   WngXmlFileNotSelected         -271 /* negative absolument !!! */
/** 
 * param WngXmlFileAlreadySelected.
 * Warning Xml File  already selected.
 */
#define   WngXmlFileAlreadySelected     -272 /* negative absolument !!! */
/** 
 * param WngXmlFileOverwritten.
 * Warning Xml File  overwritten.
*/
#define   WngXmlFileOverwritten         -273 /* negative absolument !!! */

/** 
 * param IerInternal
 * Internal Error.
 */
#define   IerInternal                   1997

/**
 * param NotAlreadyProcessed.
 * Error Not Already Processed.
 */
#define   NotAlreadyProcessed          -1    /* negative absolument !!! */




class CATUnicodeString;
#include "ExportedByDataAdmin.h"
#include "CATString.h"

/** 
 * Service reads the Warning/Error Message from NLS Catalog.
 * @param iKey
 *			NLS string to read
 * @param iNom_catalog
 *			Catalog Name
 * @param iMsgParameters
 *			Action Params for message
 * @return 
 *		NLSed warning/error message
 */
ExportedByDataAdmin CATUnicodeString read_catalog (CATString iKey , CATString iNom_catalog, CATUnicodeString *iMsgParameters = NULL, int iMsgParamSize=1);


/**
 * Defines the "YES" WriteReport Flag.
 */
#define WRY 0
/**
 * Defines the "NO" WriteReport Flag.
 */
#define WRN 1

/** 
 * Service reads and posts warning/error messages
 * @param iError
 *			Error Number
 * @param iReport
 *			ecriture ou non dans le Report gere par ReportManagement
 * <UL>
 * <LI>         == 0 : Ecriture (Defaut)
 * <LI>         <> 0 : pas d'ecriture
 </UL>
 * @param iMsgParameters
 *			Action Params for message
 * @return 
 *			warning/error message
 */
ExportedByDataAdmin CATUnicodeString read_errmsg (int iError , int iReport = NULL,CATUnicodeString *iMsgParameters = NULL);

#endif

