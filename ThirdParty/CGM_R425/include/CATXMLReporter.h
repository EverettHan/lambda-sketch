/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//===================================================================
// COPYRIGHT Dassault Systemes 2013
//===================================================================
// Usage notes:
//===================================================================
// September 2013  Creation: YWE
//===================================================================

#ifndef CATXMLReporter_H
#define CATXMLReporter_H

//#define XMLProtoHandler

//#define iDEBUGXMLReport
#define NAMING_NODE_CREDENTIAL "Credential"

//#include "ExportedByCATXMLReporter.h"
#include "ExportedByPLMBatchInfraServices.h"
#ifdef XMLProtoHandler
#include "CATBaseUnknown.h"
#endif
#include "CATUnicodeString.h"
#include "DLCDevLevel.h"

#include "CATListOfCATUnicodeString.h"

#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
class PLMExchangeNode ;
class PLMExchangeExecution ;
class PLMExchangeOption ;
class PLMExchangeDataSource ;
class PLMExchangeSet ;
class PLMExchangeNotification ;
class PLMExchangeObject ;
#endif
#ifndef PLMExchangeUnknownNotification
/** Local copie of PLMExchangeNotification notification **/
/** Constant value to define an unknown notification.     */
#define PLMExchangeUnknownNotification     0x00000000
/** Constant value to define a simple trace notification. */
#define PLMExchangeTraceNotification       0x00000001
/** Constant value to define a debug trace notification.  */
#define PLMExchangeDebugNotification       0x00000002
/** Constant value to define an information notification. */
#define PLMExchangeInformationNotification 0x00000004
/** Constant value to define a warning notification.      */
#define PLMExchangeWarningNotification     0x00000008
/** Constant value to define an error notification.       */
#define PLMExchangeErrorNotification       0x00000010
/** Constant value to define a fatal error notification.  */
#define PLMExchangeFatalNotification       0x00000020
#endif

#ifdef XMLProtoHandler
class ExportedByPLMBatchInfraServices CATXMLReporter : public CATBaseUnknown
#else
class ExportedByPLMBatchInfraServices CATXMLReporter
#endif
{

public:
  friend class CATXMLObjectReporter ;
  friend class PLMImportExportBatchXMLReporter; // Add YWE-NS1-2017.10-Impossible prereq on PLMBatchDataAccessInterfaces
/*x
Section Object LifeCycle
Abstract This section contains methods to manage Lifecyle and usage of the CATXMLReporter Object.
* <P> CATXMLReporter is a basic object allowing to generate XML reporting for any kind of application.
* By default, Report is generated under the current_Directory/CATXMLReporter.xml file
x*/

/**
* Create Factory
* @param BatchName the name of the main process. By convention, it is the name of the Main process: it can be the name of the batch, or ...
* <BR>Default structure of the generated XML file is:
* <?php $WITHCOMMENT="CREATEFACTORY" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
* @return the pointer on the CATXMLReporter object
*/
     static CATXMLReporter * CreateFactory  (CATUnicodeString & iBatchName );

/**
* Destructor.
*/
     virtual ~CATXMLReporter ();
     CATXMLReporter (CATXMLReporter &);          // Copy constructor
     CATXMLReporter& operator=(CATXMLReporter&); // Equal operator



/**
* Get the last XMLReporter.
* <BR>This method is useful for application which wanna write information within the XMLReport without having access/manage to
* the complete xml infrastructure. Getting a pointer on the CATXMLReporter is enough to add any kind of information while prerequing
* the PLMExchangeServices framework.
* @return the last CATXMLReporter pointer if any
*/
     static CATXMLReporter * GetCurrentXMLReporter();

/*x
Section Resources management
Abstract This section contains specific methods used to define resources used by report
x*/

/**
* Set the ReportDirectory.
* @param  iReportDirectory the report directory under which report has to be created.
* <BR>If iReportDirectory does not exist, it is created.
* <BR><FONT COLOR=RED>Mandatory: iReportDirectory ends with "/"</FONT>
* <BR>In addition, a 'Data' sub-directory is automatically created under iReportDirectory to collect resources (icon, images, javascript, css ...)
* <DD>Hence, 'Data' sub-directory can be populated using PLMBatchInfraServices::<A HREF=../xGenerated/Code_PLMBatchInfraServices.php#CopyResource>CopyResource</A>
* @return <UL>
* <LI>OK: report directory successfully defined
* <LI>E_INVALIDARG: Null iReporterDirectory
* <LI>S_FALSE: report directory  was already defined and has been modified to new value
* <LI>E_FAIL: iReportDirectory already exists with no read/write access.
* </UL>
*/
     HRESULT SetReporterDirectory (CATUnicodeString & iReporterDirectory );
	 HRESULT GetReporterDirectory(CATUnicodeString & iReporterDirectory);
/**
* Set the ReportName.
* @param  iReportName the name of report which will be created under the report directory.
* <BR>By default, the name of the report is CATXMLReporter.
* Name of the Report must end with valid .xml extension
* @param iDeletePreviousReport (optional) Delete report corresponding to previous name (if any)
* <BR/>In case of reportName was valuated and an xml report was generated, this argue is to delete this file.
* @return <UL>
* <LI>OK: report directory successfully defined
* <LI>E_INVALIDARG: Null iReportName
* </UL>
*/
     HRESULT SetReporterName (CATUnicodeString & iReportName, int iDeletePreviousReport=0 );
	 HRESULT GetReporterName(CATUnicodeString & oReportName);
/**
* Set the Main Xsl.
* @param  iXslFileName the name of the Main XSL.
* <BR>No test is done on Xsl existency.
* Up to the caller to Copy expected file under the iReporterDirectory using local <A HREF=#CopyResource>CopyResource</A> or advanced
* PLMBatchInfraServices::<A HREF=../xGenerated/Code_PLMBatchInfraServices.php#CopyResource>CopyResource</A> API.
* <BR>iXslFileName is composed as Name.xsl
* @return <UL>
* <LI>OK: iXslFileName successfully defined
* <LI>E_INVALIDARG: iXslFileName is null or doesn't ends with .xsl extension.
* </UL>
*/
     HRESULT SetReporterXsl(CATUnicodeString & iXslFileName);

	 HRESULT GetReporterXsl(CATUnicodeString& xslName);
/**
* Customize the GlobalReturn code icon
* <BR>Customize the GlobalReturn code icon displayed in the header of the XML report (from the the Resource section).
* By default, return Code icons are:
* <UL>
* <TABLE BORDER=1 BORDERCOLOR=LIGHTGRAY CELLPADDING=5 CELLSPACING=0>
* <?php echo $LINE.$ROW."Process".$ROW."<IMG SRC=../_GIF/Report/Infra_Icon_Process.gif WIDTH=24>".$ROW." displayed when process not ended" ; ?>
* <?php echo $LINE.$ROW."Success".$ROW."<IMG SRC=../_GIF/Report/Infra_Icon_Success.gif WIDTH=24>".$ROW." displayed when process ends sucessfully" ; ?>
* <?php echo $LINE.$ROW."Warning".$ROW."<IMG SRC=../_GIF/Report/Infra_Icon_Warning.gif WIDTH=24>".$ROW." displayed when process aborts" ; ?>
* <?php echo $LINE.$ROW."Error".$ROW."<IMG SRC=../_GIF/Report/Infra_Icon_Error.gif WIDTH=24>".$ROW." displayed when process is partially done" ; ?>
* </TABLE>
* </UL>
* Application can decide to display its own Global return code icon just while redefining each, or a part of the icon.
 * @param icon the icon to be customized:
 * <UL>
 * <LI>=1: Sucess icon
 * <LI>=2: Error icon
 * <LI>=3: Warning icon
 * <LI>=4: Process icon
 * </UL>
 * @param iconName the name of the icon to attach to the corresponding <i>icon</i> information.
 * <BR>The name is Name.extension and does not contain the complete path.
 * It is up to the application to copy the new ressource under the Report/Data directory using <A HREF=#CopyResource>CopyResource</A> method.
 * <BR>Any graphical extension is supported: jpeg, gif ...
 * @return method retunrs E_FAILS when <i>icon</i> paraleters doesn't fit one of the expected value.
 */

 HRESULT SetGlobalReturnIcon (int icon, CATUnicodeString iConName) ;
/**
* Copy a Resource
* <BR>Copy a resource (a file or the full content of a directory) under the iReporterDirectory/Data
* @param iResourcePath the relative local path (regarding CATInstallPath) of the resource to copy
* <UL>
* <LI>In case of iResourceToCopy is a File, the file is copied under the iReporterDirectory/Data
* <LI>In case of iResourceToCopy is a directory, the entire files under iResourceToCopy are copied under the iReporterDirectory/Data
* </UL>
* @param iResourceType the type of resource to copy
* <UL>
* <LI>1: iResourceToCopy is a directory
* <LI>0: iResourceToCopy is a file (default)
* </UL>
* @return <UL>
* <LI>OK: resource successfully copied
* <LI>E_FAIL: iReceivingDir is not a valid directory (not a directory, no write access)
* <LI>E_FAIL: iResourceToCopy can't be copied (does not exist, no read access)
* </UL>
* CopyResource creates iReporterDirectory/Data if needed

*/
     HRESULT CopyResource (CATUnicodeString & iResourceToCopy , int iResourceType );

/**
* Save XML report
* <BR>Save the full PLMExchange XML report under the Report Directory.
* <BR>Final information is added in the report before Save, such as:
* <?php $WITHCOMMENT="SAVEXMLREPORT" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
* @return <UL>
* <LI>OK: save operation successful
* <LI>E_FAIL: save operation aborts <UL>
* <LI>The report already exists with no write access
* <LI>...
* </UL>
* </UL>
*/
  HRESULT StreamReporterAsFile();


/*x
Section Info creation
Abstract This section contains specific methods used to create information in the report
x*/


#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY

   /**
* Create a Node
* <BR>Add an Environment variable under dedicated 'EnvironmentVariable' node.
* <BR>By implementation Environment variable  information are monovaluated tags.
*
* @param NodeName the internal name of the Node
* @return
*/
 PLMExchangeSet * CreateApplicativeGlobalNode(CATUnicodeString  ApplicativeNodeName ) ;

 /**
* Retrieve a Node per its Name.
* <BR>This method is useful for application which wanna write information within the XMLReport without having access/manage to
* the complete xml infrastructure. Getting a pointer on the Node is enough to add any kind of information while prerequing
* the PLMExchangeServices framework.
* @return the last CATXMLReporter pointer if any
*/
 PLMExchangeSet * GetXMLReporterSpecificNode(CATUnicodeString &iNodeName);

   /**
 * Add Option info under any dedicated node
 * <BR>Add a Option/Value info under any dedicated node
 * @param iOptionName the internal name of the option (the name of the xml tag corresponding to the option)
 * @param iOptionNLSName the NLS name of the option (the name which will be displayed in the report)
 * @param iOptionValue the value of the option
* @param iTargetNode  The target node under which information has to be created.
* <DD>When iTargetNode is null, Option info is added under the default <?php echo $KBD ?>ExecutionOption<?php echo $EKBD ?> information node.
 * <?php $WITHCOMMENT="ADDOPTIONINFO" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
 * @return
 *  <UL>
 *    <LI>S_OK, if everything goes well.</LI>
 *    <LI>E_FAIL, if an error happened.</LI>
 *  </UL>
*/
 HRESULT AddOptionInfo(CATUnicodeString & iOptionName, CATUnicodeString & iOptionNLSName,CATUnicodeString & iOptionValue,PLMExchangeSet * iTargetNode=NULL) ;
#endif

 /**
* Add The return Code Metric information under the Main node
* @param iReturnCode the return code.
* @param iSeverity the severity [Error/Fatal/Dummy] attached to the return code.
* <BR>Monovlauated information ... several valuation of the information will overwrite the tag
* <?php $WITHCOMMENT="AddGlobalReturnCodeInfo" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
* @return None
*/
 HRESULT AddGlobalReturnCodeInfo(int iReturnCode, CATUnicodeString iSeverity) ;

/**
* Add an Metric information under any node
* @param iMetricName the internal name of the metric (the name of the xml tag corresponding to the metric)
* @param iMetricNLSName the NLS name of the metric (the name which will be displayed in the report)
* @param iMetricValue define if the information can be multivaluated or not.
* <UL>
* <LI>=0: not multivaluated: Several valuation of the information will overwrite the tag
* <LI>!=0: multivaluated:  Several valuation of the information will create several tags
* </UL>
* <?php $WITHCOMMENT="ADDMETRICINFO" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
* @return

*/
 HRESULT AddMetricInfo(CATUnicodeString & iMetricName, CATUnicodeString & iMetricNLSName,CATUnicodeString & iMetricValue , int iMultivalue = 0) ;

 /**
* Add an Environment variable
* <BR>Add an Environment variable under dedicated 'EnvironmentVariable' node.
* <BR>By implementation Environment variable  information are monovaluated tags.
*
* @param iEnvVarName the internal name of the environment variable (the name of the xml tag corresponding to the environment variable)
* <BR>By convention, it should be the name of the environment variable itself.
* @param iEnvVarNLSName the NLS name of the environment variable (the name which will be displayed in the report)
* @param iMetricValue the value of the environment variable (.i.e the result of CATGetEnv(iEnvVarName)).
* @param iPublicState define which customer exposition have the environment variable:
* <UL>
 * <LI>=0 (default): Public environment variable available for all customers
 * <LI>=1: Limited availability variable
 * <LI>=2: Restricted to dedicated customer variable
 * <LI>=3: InternalDs variable - Should not be communicated to customer
 * </UL>
 * <BR>As a convention, the reported value of the variable is defined as  : [value of the export] NLS abstract of the environment variable.
 * <?php $WITHCOMMENT="ADDENVVARINFO" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
 * @return
*/
 HRESULT AddEnvVarInfo(CATUnicodeString & iEnvVarName, CATUnicodeString & iEnvVarNLSName,CATUnicodeString & iEnvVarValue, int iPublicState ) ;

  /**
* Compute and Save a date
* <BR>Compute and Save a date (string format) under the Metric section
 * @param iMetricDateName the internal name of the date (the name of the xml tag corresponding to the metric)
 * @param iMetricDateNLSName the NLS name of the date (the name which will be displayed in the report)
 * <BR>By convention, the date value is computed when calling the API.
 * It is stored as a string (not a CATTime) in the XML report under the <KBD>ExecutionMetrics</KBD> node.
 * <BR>You can use predefined values:
 * <UL>
 * <LI><KBD>CATUnicodeString OptionName="StartReplayDate";</KBD> for the Start date (NLS message retrieved from CATXMLReporter.CATNls file)
 * <LI><KBD>CATUnicodeString OptionName="EndReplayDate";</KBD> for the End date (NLS message retrieved from CATXMLReporter.CATNls file)
 * <LI>For any other value, application has to define its own NLS message.
 * </UL>
 * <?php $WITHCOMMENT="ADDMETRICDATE" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
*/
 HRESULT AddMetricDate( CATUnicodeString & iMetricDateName , CATUnicodeString & iMetricDateNLSName ) ;

   /**
* Add a Resource
* <BR>Add a resource under the Resource section. These information are not supposed to be directly exposed in the final report,
* but are used to provide a better information.
 * <BR>This resource can be used in xsl for adding specific information.
 * <BR>It can be a link on official documentation for specific data , or for an engine
 * <BR>It can be an icon to use, depending on the current step of processing ...
 * @param iResourceName the internal name of the resource
 * @param iResourceValue the value of the resource
 * <?php $WITHCOMMENT="ADDRESOURCE" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
*/
 HRESULT AddResourceInfo( CATUnicodeString & iResourceName , CATUnicodeString & iResourceNLSName , CATUnicodeString & iResourceValue , int iMultivalue = 0) ;




#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY

 /**
* Add a notification
* <BR>Add a notification of  any type/severity in the xml report
* @param iNotifType    Notification type which value can be:
* <UL>
* <LI>PLMExchangeTraceNotification Simple trace notification.
* <LI>PLMExchangeDebugNotification Debug trace notification.
* <LI>PLMExchangeInformationNotification Information notification.
* <LI>PLMExchangeWarningNotification Warning notification.
* <LI>PLMExchangeErrorNotification Error notification.
* <LI>PLMExchangeFatalNotification Fatal error notification.
* </UL>
* @param icErrorId    Error internal name.
* @param icMessage    NLS notification message.
* @param iTargetNode  The target node under which notification has to be created.
* <BR>When the Input TargetNode is null, the notification is added under the main ExecutionNode, else it is added under the iTargetNode node
* <?php $WITHCOMMENT="ADDNOTIFICATION" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
* @return
*/
 PLMExchangeNotification * AddNotification(int iNotifType , const CATUnicodeString & icErrorId , const CATUnicodeString & icMessage , PLMExchangeNode * iTargetNode=NULL) ;

#endif // XMLReport_LEVEL_AVAILABILITY





/*x
Section Data Providers access
Abstract This section contains specific methods used to create information in the report
x*/


 /**
 * Add DataSource info
 * <BR>Add data source (input/ouput providers) definition and credentials
 * @param iProvTyp The provider Typ :<UL>
 * <LI>=1 (default): Input Provider
 * <LI>=2: Output Provider
 * </UL>
 * @param iProvInternalName The internalDS providername (VPMV4, PLM1, ...)
 * which external name can be retrieved with PLMBatchProviderBasics::<A HREF=../xGenerated/Code_PLMBatchProviderBasics.php#GetPLMBatchProviderNLSName>GetPLMBatchProviderNLSName</A>
 * @param iCredentialName the internal name of the Credential (the name of the xml tag corresponding to the Credential)
  * @param iCredentialValue
 * <?php $WITHCOMMENT="ADDDATAPROVIDER" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
 * @return
 *  <UL>
 *    <LI>S_OK, if everything goes well.</LI>
 *    <LI>E_FAIL, if an error happened.</LI>
 *  </UL>
 * CredentialNLSName (the name which will be displayed in the report) are retreived from NLS file
 * <P><IMG SRC=../_GIF/ZWork.gif WIDTH=24> Once defined, a DataSource can not be deleted/modified.
*/
 HRESULT AddDataProviderInfo( int iProvTyp, CATUnicodeString iProvInternalName, CATListOfCATUnicodeString & iCredentialName, CATListOfCATUnicodeString & iCredentialValue) ;

#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY

/**
 * Search on ObjectNode using its OID.
 * <BR>OID is computed for any VPLMObjects using the CATXMLObjectReporter::<A HREF=../xGenerated/Code_CATXMLObjectReporter.php#GetOIDfromObject>GetOIDfromObject</A>
 * @param iV6ObjCOID the OID of the object for which main PLMExchangeSet is requested
 * @param iFatherSet The XML ExchangeSet under which ObjectNode has to be searched
 * <BR/>When null, Object node is serached under the default root ObjectSet
 * @return the PLMExchangeObject of object which OID is iV6ObjCOID.
 * <BR>Null when no PLMExchangeSet can be found.
 */
 PLMExchangeObject * SearchByOIDfromObject (CATUnicodeString & iV6ObjCOID, PLMExchangeSet * iFatherSet = NULL)  ;
#endif // XMLReport_LEVEL_AVAILABILITY


private:
/*x
Section Private internal methods
Abstract This section contains specific private methods
x*/
 /**
* Add basic Metrics
* <BR>Build and write basic metrics under the <KBD>ExecutionMetrics</KBD> node.
* <BR>The metrics are: <UL><TABLE BORDER=1 BORDERCOLOR=GRAY CELLPADDING=5 CELLSPACING=0>
* <BR><?php echo $LINE.$HROW." Abstract ".$HROW." Internal Name ".$HROW." Type " ?>
* <BR><?php echo $LINE.$ROW." The Version ".$ROW."Version".$ROW." string " ?>
* <BR><?php echo $LINE.$ROW." The internal build identification with SP and HF ".$ROW."InternalBuild".$ROW." CATTime " ?>
* <BR><?php echo $LINE.$ROW." The build date ".$ROW."BuildDate".$ROW." string " ?>
* <BR><?php echo $LINE.$ROW." The host client ".$ROW."ClientMachine".$ROW." string " ?>
* </TABLE>
* </UL>
*/
 HRESULT AddDefaultMetrics( );

#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
/**
* Add a V6 object Node
* @param iV6OID the OID of the object to add (retrieved from PLMID with GetOIDfromObject)
* @param iV6ObjDisplName the displayName of the V6 object to add.
* <BR>Depending on the environment, it can be the TreeMask, the PLM_ExternalID
* @param ioV6DocExt the type of the object to add.
* It can be:<UL>
* <LI>PLMCoreReference
* <LI>PLMCoreRepReference
* </UL>
* This argue is a In/out argue. When null, the type is recomputed.
* @param ObjectNode The XML Object Node created
* @param iFatherSet The XML ExchangeSet under which ObjectNode has to be created
* <BR/>When null, Object node is created under the default root ObjectSet
* @return
*  <UL>
*    <LI>S_OK, if everything goes well. XML Object node has been created</LI>
*    <LI>S_FALSE, if everything goes well. XML Object node already exist and has not been created</LI>
*    <LI>E_FAIL, if an error happened. XML Object node not created (ObjectNode is null)</LI>
*  </UL>
* <?php $WITHCOMMENT="ADDOBJECT" ; include '../_PLMBatch/Include_Code_CATXMLReporter_CreateFactory.php' ?>
*/
 PLMExchangeObject * AddObject(CATUnicodeString & iV6OID, CATUnicodeString & iV6objDisplName, CATUnicodeString & iV6DocExt, CATListOfCATUnicodeString & iAttrName, CATListOfCATUnicodeString & iAttrValue, PLMExchangeSet * iFatherSet = NULL);
#endif
 /**
 * Private constructor
 */
    CATXMLReporter (CATUnicodeString & iBatchName );
#ifdef  DLC_XMLReportActive // XMLReport_LEVEL_AVAILABILITY
  PLMExchangeExecution        * _xRootNode ;
  PLMExchangeSet             * _xGlobalInfoNode     ;
  PLMExchangeSet             * _xOptionNode ;
  PLMExchangeSet             * _xEnvVarOptionNode ;
  PLMExchangeSet             * _xMetricNode ;
  PLMExchangeSet             * _xResourceNode ;
  PLMExchangeSet             * _xGlobalApplicativeNode ;
  PLMExchangeSet              * _xObjectSet ;
  PLMExchangeDataSource       * _xDataSourceIn ;
  PLMExchangeDataSource       * _xDataSourceOut ;
#endif
  CATUnicodeString _ReportDir ;
  CATUnicodeString _ReportName ;
  CATUnicodeString _XSLFile ;
  CATListOfCATUnicodeString _lstClassObject ;

  CATUnicodeString _IconGlobalSuccess ;
  CATUnicodeString _IconGlobalError ;
  CATUnicodeString _IconGlobalWarning ;
  CATUnicodeString _IconGlobalinProcess ;

};
#ifdef XMLProtoHandler
CATDeclareHandler(CATXMLReporter, CATBaseUnknown); //HandlerProto
#endif
#endif
