/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef	xxPLMBatchProviderBasics_h
#define	xxPLMBatchProviderBasics_h

/** @level Private 
* @usage U1
*/

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByPLMBatchInfraServices.h"

class ExportedByPLMBatchInfraServices PLMBatchProviderBasics {
  public:

/*x
Section PLMBatchProviderBasics  
Abstract This class contains basic methods dealing with PLMBatch provider accessing with string without any prereq on standard PLMBatch objects such as PLMBatchEngine , CATBatchContext , CATIPLMBatchProvider ....
* <BR>This static object has to be updated for each new CATIPLMBatchProvider integration
x*/

/**
 * Get the external (NLS) name of a CATIPLMBatchProvider.
 * <br>This CATIPLMBatchProvider name is exposed in Xml and User interface (PLMBatchProvider combo, PLMBatch reports, ...).
 * @param iProvName  the name of the Provider for which we search the corresponding NLS name
 * <BD> for instance:  File, PLM1, TST, VPM1, DXP, IPD ...
 * @return
 * The external name of the PLMBatchProvider
 * <BR>When no NLS name is found, return the iProvName name
*/
static CATUnicodeString GetPLMBatchProviderNLSName ( CATUnicodeString iProvName ) ;
/**
* Return the list of UI attributes
* <BR>Return the list of UI attributes for connection
* <BR>Control secondary Logon Panel for activation of existing attributes
* <br> Using this service, CATIPLMBatchProvider can block/disable un-necessary field display in secondary logon Panel used for COEXISTENCE usage.
 * @param iProvName  the name of the Provider for which we search the corresponding list of attributes
 * <BD> for instance:  File, PLM1, TST, VPM1, DXP, IPD ...
* @return the list of attributes
* <BR>	List in which Provider should add FieldNames to block.
*   Supported FieldNames are: "User","xPwd","Serv","Role","Port","iURL".
*	<BR>example - below	code would dis-activate User,Password fields in Logon Panel.
*		<BR> FieldName.Append("User");
*		<BR> FieldName.Append("xPwd");
*/
static CATListOfCATUnicodeString LockUILogonAttributes(CATUnicodeString iProvName);
/**
* Return NLS Name of an UI attributes
 * <br>This attribut NLS name is exposed in UILogonPanel User interface ...
 * @param iProvName  the name of the CATIPLMBatchProvider for which we search a corresponding NLS name
 * @param iAttributName  the name of the Attribute for which we search a corresponding NLS name
 * @param oAttributNLSName  the NLS name of the Attribute 
 * @reurn <UL>
 * <LI>E_FAIL when iAttributName is not a valid attribute for the iProviderName CATIPLMNBatchProvider
 * <LI>S_OK else
 * </UL>
*/
static HRESULT GetAttributeNLSName(CATUnicodeString iProvName , CATUnicodeString iAttributName , CATUnicodeString & oAttributNLSName);


} ;

#endif
