/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//===================================================================
// COPYRIGHT Dassault Systemes 2013
//===================================================================
// Usage notes:
//===================================================================
// September 2013  Creation: YWE
//===================================================================

#ifndef CATErrorManager_H
#define CATErrorManager_H

#define	LONGHELP "LongHelp"

//#define iDEBUGXMLReport
//#include "ExportedByCATXMLReporter.h"
#include "ExportedByPLMBatchInfraServices.h"
#include "CATUnicodeString.h" 
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
#include "DLCDevLevel.h"
#ifdef DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
class PLMExchangeNode ;
#else
class CATBaseUnknown ;
#endif // XMLReport_LEVEL_AVAILABILITY

class ExportedByPLMBatchInfraServices CATErrorManager
{
public:
  friend class PLMBatchErrorServices ;
  friend class DWCErrorServices ;
  friend class CheckRepErrorServices ;
  friend class CoexAdminErrorServices ;
/*x
Section Object LifeCycle
Abstract This section contains methods to manage Lifecyle and usage of the CATErrorManager Object.
* <P> CATErrorManager is a basic object allowing to manage Errors for any kind of application. 
* <BR>Error can be of type:
* <UL>
* <LI>Fatal: process aborts as soon as fatal is raised
* <LI>Error: process continue but will end with non null RC because an Error has been detected
* <LI>Warning: process continue and will end with null RC
* </UL>
* CATErrorManager is linked to CATXMLReporter object for XML reporting
x*/


   /** 
 * Get the FatalRC
 * @return the last FatalRC written with <A HREF=#SetNotif>SetNotif</A>. 
  */

     int GetFatalRC() ;

  /** 
 * Get the first ErrorRC
 * Get the first ErrorRC, even if reset has been called
 * @return the first ErrorRC or FatalError written with <A HREF=#SetNotif>SetNotif</A>.
  */

     int GetFirstCATErrorRC() ;

  /** 
 * Get the ErrorRC
 * @return the last ErrorRC or FatalError written with <A HREF=#SetNotif>SetNotif</A>.
  */

     int GetErrorRC() ;

     /** 
 * Reset  the ErrorRC
 * <BR>Reset the last ErrorRC written with <A HREF=#SetNotif>SetNotif</A>.
 * <BR>In case of a process dealing with a set of independant objects, 
 * an Error raised for an Object_i should not be taken into account when procedsing Objet_j (only fatal error is common to all objects)
  */

     void ResetErrorRC() ;
 /** 
 * Check the Real Warning status of an error
 * <BR>Return the exact severity of an error taken into account a possible customization through iSeverity.iDomain.iErrorTag env var export.
 * @param iErrorTag The tag error for which Warning status has to be retrieved
 * @return the Warning status of the error:
 * <UL>
 * <LI>=1: error is a Warning, taken into account a possible customization through envvar export. 
 * <LI>=0: error is not a Warning but an Error or Fatal
 * </UL>
 */

     int IsaWarning (CATUnicodeString iErrortag ) ;

 
  /**
 * Set Information on an error
 * <BR>This method is used to manage a dictionary of error and corresponding return code/severity/Domain/Customization
 * and retrieve main information on error to display using CATErrorManager::<A HREF=../_PLMBatch/Code_CATErrorManager.php#SetNotif>SetNotif</A>
 * <BR>This method hardcode information for all CATErrorManager iErrorTag : 
 * @param iErrorTag The tag error for which information has to be retrieved
 * @param iDomain The domain of iErrorTag. This is also the  name of the catalog containing the oSeverity.oDomain.iErrorTag error definition.
 * <BR>iDomain information is also used for oSeverity.oDomain.iErrorTag Tag retrieval in CATErrorReporter_oDomain NLS catalog.
 * @param iSeverity The severity of iErrorTag [Fatal,Error,Warning]. 
 * <BR>iSeverity information is also used for oSeverity.oDomain.iErrorTag Tag retrieval in CATErrorReporter_oDomain NLS catalog.
 * @param iRCCode The return code attached to the error [Fatal,Error,Warning]. 
 * <DD>Positive in case of Error and Fatal
 * <DD>Negative in case of a Warning
 * @param iCusto The customizable status
 * <DD>=0 not customizable
 * <DD>=1 customizable (for Error, Warning only). No way to customize a Fatal error.
 * @return None
 */

  void RegisterPossibleError(CATListOfCATUnicodeString iErrortag,CATUnicodeString iDomain ,CATListOfCATUnicodeString iSeverity, CATListOfInt iRCCode, CATListOfInt iCusto) ;

 /** 
 * Get the last Message
 * @return the last message written with <A HREF=#SetNotif>SetNotif</A>. 
 * <BR>This message is useful for non XML reporting application
 * which need to write in its own reporting environment the message (for instance PLMBatch html reports)
 */



     CATUnicodeString GetLastHTMLMessage() ;

/** 
 * Public constructor
 */
    CATErrorManager ( );                    
 
/**
* Destructor.
*/   
     virtual ~CATErrorManager ();           
     CATErrorManager (CATErrorManager &);          // Copy constructor
     CATErrorManager& operator=(CATErrorManager&); // Equal operator

protected:

  /** 
 * Write a Message
 * <BR>Write a message in the (HTM/XML) reports
  * @param iCatalogName  The final name of the	CATNls Catalog (without .CATNls extension). 
  * <DD><IMG SRC=../_GIF/zHand.gif WIDTH=18> Complete name will be CATErrorReporter.iCatalogName.CATNls
 * @param ioSeverity  The	severity of the error.  Must be [Fatal,Error,Warning]
 * <DD>ioSeverity is an Input/Output argue and can be redefined in case of Customizable message (not nut iCusto argue)
 * @param iDomain  The	domain of the error. 
 * This domain must have been declared first using the <A HREF=#RegisterPossibleError>RegisterPossibleError</A> method.
* @param iKey 		The final key of the NLS message to read.
 * <DD><IMG SRC=../_GIF/zHand.gif WIDTH=18> Complete key will be iSeverity.iDomain.iKey
 * @param iCusto 			  If (Warning,Error) severity can be customized (then redefined in the corresponding CATRsc file).
 * <FONT COLOR=RED>Fatal can not be customizable.</FONT>
 * <BR>ErrorManager offers the capability to tune the customization's capability with several iCusto values:
 * <UL>
 * <LI>=0: Error is not customizable.
 * <LI>=1: Error can be promoted to higher severity of level One. Then
 * <UL>
 * <LI>Warning can be promoted to Error
 * <LI>Error can be promoted to Fatal
 * </UL>
 * <LI>=2: Error can be promoted to higher severity of level One and Two.Then
 * <UL>
 * <LI>Warning can be promoted to Error or Fatal
 * <LI>Error can be promoted to Fatal
 * </UL>
 * <LI>=-1: Error can be demoted to lower severity of level One. Then
 * <UL>
 * <LI>Error can be demoted to Warning
 * </UL>
 * <LI>=-2: Error can be demoted to lower severity of level One and Two: 
 * Not applicable as Fatal can't be customized.
 * <LI>=75: any customization is possible.
 * </UL>
 * List of customizable errors with possible values is to be clearly documented in the official documentation.

 * @param iRCCode 			The Return code
 * @param iArg 			Tab of arguments
 * @param iNbArg 		size of the iArg tab
 * @return <UL>
 *		<LI>S_OK: Message successfully written in the report
 *    <LI>S_FALSE: Message successfully written in the report with customized severity
 *     <LI>E_FAIL: Message not written. A default message has been written with similar severity.
 * Possible failure are: <UL>
 * <LI>CATNls file doesn't exist
 * <LI>CATNls file exists but has no read access
 * <LI>Domain is not in the authorized list of domains. Update the list with <A HREF=#RegisterPossibleError>RegisterPossibleError</A> method.
 * <LI>Message not found in the CATNls file
 * </UL>
 * </UL>
 */
#ifdef DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
 HRESULT SetNotif ( CATUnicodeString & ioSeverity, CATUnicodeString iDomain, CATUnicodeString iKey , int iCusto, int & ioRCCode, PLMExchangeNode * iTargetNode, CATUnicodeString *iArg , int iNbArg,CATListOfCATUnicodeString MoreInfoName , CATListOfCATUnicodeString MoreInfoKey , CATListOfCATUnicodeString MoreInfoValue );
#else
 HRESULT SetNotif ( CATUnicodeString & ioSeverity, CATUnicodeString iDomain, CATUnicodeString iKey , int iCusto, int & ioRCCode, CATBaseUnknown * iTargetNode, CATUnicodeString *iArg , int iNbArg,CATListOfCATUnicodeString MoreInfoName , CATListOfCATUnicodeString MoreInfoKey , CATListOfCATUnicodeString MoreInfoValue );
#endif // XMLReport_LEVEL_AVAILABILITY

private:
 /**
 * Get Information on an error
 * <BR>This method is used to manage a dictionary of error and corresponding return code/severity
 * and retrieve main information on error to display using DWCErrorServices::<A HREF=../_CATDWC/Code_DWCErrorServices.php#SetNotif>SetNotif</A>
 * <BR>This method hardcode information for all DWC iErrorTag : 
 * @param iErrorTag The tag error for which information has to be retrieved
 * @param oDomain The domain of iErrorTag. This is also the  name of the catalog containing the oSeverity.oDomain.iErrorTag error definition.
 * <BR>oDomain information is also used for oSeverity.oDomain.iErrorTag Tag retrieval in oCatalogName NLS catalog.
 * @param oSeverity The severity of iErrorTag [Fatal,Error,Warning]. 
 * <BR>oSeverity information is also used for oSeverity.oDomain.iErrorTag Tag retrieval in oCatalogName NLS catalog.
 * @param oRCCode The return code attached to the error [Fatal,Error,Warning]. 
 * <DD>Positive in case of Error and Fatal
 * <DD>Negative in case of a Warning
 * @param oCusto The customizable status
 * <DD>=0 not customizable
 * <DD>=1 customizable (for Error, Warning)
 * @return None
 */
 void GetErrorInfo(CATUnicodeString iErrortag, CATUnicodeString & oDomain ,CATUnicodeString & oSeverity, int & oRCCode, int & oCusto ) ;
 /** 
 * Get the Real severity of an error
 * <BR>Return the exact severity of an error taken into account a possible customization through envvar export. 
 * based on iSeverity.iDomain.iErrorTag Tag env var
 * @param iErrorTag The tag error for which information has to be retrieved
 * @param iDomain The domain of iErrorTag. 
 * @param iSeverity The severity of iErrorTag [Fatal,Error,Warning]. 
 * @return the real severity of iErrorTag [Fatal,Error,Warning]. 
 */
  CATUnicodeString GetCustomizedSeverity(CATUnicodeString iErrortag, CATUnicodeString iSeverity ,CATUnicodeString iDomain ) ;

  CATListOfCATUnicodeString _lErrortag;
  CATListOfCATUnicodeString _lDomain;
  CATListOfCATUnicodeString _lSeverity;
  CATListOfInt _lRCCode;
  CATListOfInt _lCusto;
 
  CATUnicodeString _LastHTMLMsg;
  int _lastFatalRC ;
  int _lastErrorRC ;
  int _firstErrorRC ;
};

#endif
