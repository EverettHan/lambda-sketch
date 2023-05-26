/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
#ifndef PLMBatchErrorServices_H
#define PLMBatchErrorServices_H

/** 
 *  @level Protected 
 *  @usage U1
 */
#include "ExportedByPLMBatchInfraServices.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

class CATErrorManager ;
#define	LONGHELP "LongHelp"

/**
 * Class to manipulate PLMBatch Error case
*/

class ExportedByPLMBatchInfraServices PLMBatchErrorServices
{
public:



/*x
Section Error Management
Abstract Following methods are used to manage  Error & Information with the CATErrorManager object.
x*/

  /** 
 * Register all possible errors
 * <BR>Register all possible errors
 * <BR>This method hardcode information for all iKey : Domain/Severity/Custo/RCCode
 * <UL>
 * @param oRCCode 			The Return code - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * @param ioSeverity  The	severity of the error.  Must be [Fatal,Error,Warning] - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * @param iDomain  The	domain of the error - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>.
 * Also used to compute the final name of the	CATNls Catalog (without .CATNls extension) - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * @param iCusto 			  If (Warning,Error) severity can be customized (then redefined in the corresponding CATRsc file).
 * </UL>
 * @param pErrorManager the CATErrorManager
 * @param iDomain the domain (PLMBATCH, ...) 
 * <BR>The domain is also used to retrieve the NLS message attached to the error
 * <BR>Current list of PLMBatch errors
 * <UL>
	* <LI>InternalError - Severity=Error - Custo=NO - ReturnCode=0
	* <LI>InvalidInputXML - Severity=Fatal - Custo=NO - ReturnCode=8
	* <LI>ConnectionAborted - Severity=Fatal - Custo=NO - ReturnCode=9
	* <LI>BatchServerTaskInvalid - Severity=Fatal - Custo=NO - ReturnCode=21
	* <LI>BatchServerTransactionStartFailure - Severity=Warning - Custo=YES - ReturnCode=-22
	* <LI>XMLQueryMultipleResult - Severity=Fatal - Custo=NO - ReturnCode=83
	* <LI>NonSupportedLateType - Severity=Warning - Custo=NO - ReturnCode=-84
	* <LI>LockedByAnotherUser - Severity=Error - Custo=YES - ReturnCode=85
	* <LI>NoObjectsRetrieved - Severity=Fatal - Custo=NO - ReturnCode=86
	* <LI>ObjectsNotRetrieved - Severity=Warning - Custo=YES - ReturnCode=-87
	* <LI>SharedLicense - Severity=Warning - Custo=YES - ReturnCode=-88
	* <LI>ObjectsNotOpened - Severity=Error - Custo=NO - ReturnCode=89
 * </UL>
 */
 static HRESULT RegisterAllErrors(CATErrorManager * pErrorManager, CATUnicodeString iDomain) ;

/** 
 * Write a Message
 * <BR>Write a Error/Warning/Fatal message in the (HTM/XML) reports and integrated to PLMBatch environment returnCode
 * @param iErrorTag 		The final key of the NLS message to read - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * @param ioRCCode 			The Return code - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * <BR>Warning, this argue is i/o for error with null internal RC (transparent PLMBATCH error)
 * @param MoreInfoName  
 * @param MoreInfoKey  
 * @param MoreInfoValue  

 * @param iArg 			(optional) Tab of arguments - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * @param iNbArg 		(optional) Size of the iArg tab - See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * @return (See CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>) 
 * <BR>Additional failure can be:<UL>
  *     <LI>E_FAIL: Message not written. A default message has been written with similar severity.
  * </UL>
 */
static  HRESULT SetErrorNotif ( CATErrorManager * TheErrorManager, CATUnicodeString iErrorTag , int & ioRCCode, CATListOfCATUnicodeString MoreInfoName, CATListOfCATUnicodeString MoreInfoKey, CATListOfCATUnicodeString MoreInfoValue, CATUnicodeString *iArg = NULL, int iNbArg=0);

};
#endif
