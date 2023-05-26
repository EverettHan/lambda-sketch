#ifndef  PLMExchangeReportService_h
#define  PLMExchangeReportService_h
// COPYRIGHT DASSAULT SYSTEMES 2013-2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Service Class enabling to ease PLM Exchange model management
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Offer high level services to manage bais operation on PLM Exchange model.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  January 2013     (JLM) Initial Revision
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************
// Abstract class    : No
// Template code     : No
// Ilined   Function : No
// ****************************************************************

// --- Header that need to be referenced

// --- * System framework

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

// --- * Mother class

#include "PLMExchangeModel.h"
#include "PLMExchangeNode.h"
#include "PLMExchangeSet.h"

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

// --- * Forward declaration

class PLMExchangeSet            ;
class PLMExchangeEngine         ;
class PLMExchangeExecution      ;
class PLMExchangeOptionSet      ;
class PLMExchangeNotification   ;
class PLMExchangeObject         ;
class PLMExchangeOption         ;
class PLMExchangeMetric         ;
class PLMExchangeAttribute      ;
class PLMExchangeDataSource     ;
class PLMExchangeClassObject    ;
class PLMExchangeClassAttribute ;

// --- Class definition

/**
  * Class to define services on PLM exchange report model.
  *
  * <b>Role</b>:
  *    Define services on PLM exchange report model..
  */
class ExportedByPLMExchangeModel PLMExchangeReportService
{
   public:

      // ---------------------------------------------------
      // --- Manage Factory for PLM Exchange model.
      // ---------------------------------------------------

    /**
      * Init PLM Exchange Report model.
      *
      * <br><b>Role</b>: Prepares access to PLM Exchange report model.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>PLM Exchange model successfuly initialized.</dd>
      *    <dt>S_FALSE</dt>    <dd>PLM Exchange model already initialized.</dd>
      *    <dt>E_FAIL</dt>     <dd>PLM Exchange model initialization failed.</dd>
      *    </dl>
      */
      static HRESULT InitPLMExchangeModel() ;

    /**
      * Close PLM Exchange Report model.
      *
      * <br><b>Role</b>: Close PLM Exchange report model and free all allocated information.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>PLM Exchange model successfuly closed.</dd>
      *    <dt>S_FALSE</dt>    <dd>PLM Exchange model is already closed.</dd>
      *    <dt>E_FAIL</dt>     <dd>PLM Exchange model closure failed.</dd>
      *    </dl>
      */
      static HRESULT ClosePLMExchangeModel() ;

    /**
      * Quick print of PLM Exchange Model.
      *
      * <br><b>Role</b>: Quick print of PLM Exchange Model.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>PLM Exchange model dump successfuly executed.</dd>
      *    <dt>S_FALSE</dt>    <dd>No PLM Exchange model opened.</dd>
      *    <dt>E_FAIL</dt>     <dd>PLM Exchange model dump failed.</dd>
      *    </dl>
      */
      static HRESULT DumpPLMExchangeModel() ;

    /**
      * Stream PLM exchange report model as an XML or JSON file.
      *
      * <br><b>Role</b>: Stream PLM exchange report model as an XML file on disk.
      *   <p><u>NB:</u>The default XSL will be used in the generated XML.</p>
      *
      * @param iusReportFilePath [in]
      *   File path of the XML report file.
      *
      * @param iXMLFilter
      *   Filter to apply when streaming PLM Exchange Model.
      *
      * @param inFileFormat
      *   Define file format to be used.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>XML_STREAMING</dt>   <dd>XML streaming.</dd>
      * <dt>JSON_STREAMING</dt>  <dd>JSON streaming.</dd>
      * </dl>
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>PLM Exchange model XML report successfuly exported.</dd>
      *    <dt>S_FALSE</dt>    <dd>No PLM Exchange model opened.</dd>
      *    <dt>E_FAIL</dt>     <dd>PLM Exchange model XML report generation failed.</dd>
      *    </dl>
      */
      static HRESULT SaveReport( const CATUnicodeString & iusReportFilePath
                               , int                      iXMLFilter   = PLMExchangeNode::XMLReport
                               , int                      inFileFormat = PLMExchangeNode::XML_STREAMING ) ;

    /**
      * Stream PLM exchange report model as an XML or JSON file.
      *
      * <br><b>Role</b>: Stream PLM exchange report model as an XML file on disk.
      *
      * @param iusReportFilePath [in]
      *   File path of the XML report file.
      *
      * @param iusReportXslPath [in]
      *   File path of the XSL file to referenced in the generated XML.
      *   <p><u>NB:</u>In case of null string, the default XSL will be used in the generated XML.</p>
      *
      * @param iXMLFilter
      *   Filter to apply when streaming PLM Exchange Model.
      *
      * @param inFileFormat
      *   Define file format to be used.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>XML_STREAMING</dt>   <dd>XML streaming.</dd>
      * <dt>JSON_STREAMING</dt>  <dd>JSON streaming.</dd>
      * </dl>
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>PLM Exchange model XML report successfuly exported.</dd>
      *    <dt>S_FALSE</dt>    <dd>No PLM Exchange model opened.</dd>
      *    <dt>E_FAIL</dt>     <dd>PLM Exchange model XML report generation failed.</dd>
      *    </dl>
      */
      static HRESULT SaveReport( const CATUnicodeString & iusReportFilePath
                               , const CATUnicodeString & iusReportXslPath
                               , int                      iXMLFilter   = PLMExchangeNode::XMLReport
                               , int                      inFileFormat = PLMExchangeNode::XML_STREAMING ) ;

      // ---------------------------------------------------
      // --- Manage Factory for PLM Exchange Execution.
      // ---------------------------------------------------

    /**
      * Start recording a one execution.
      *
      * <br><b>Role</b>: Start recording a one execution.
      *
      * @param icExecName [in]
      *   Execution name.
      *
      * @param oxExecNode [out]
      *   Execution report node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateExecution( const CATUnicodeString   & icExecName
                                    , PLMExchangeExecution   * & oxExecNode ) ;

    /**
      * Set an Execution node as current.
      *
      * <br><b>Role</b>: Set an Execution node as current.
      *
      * @param ixExecNode [in]
      *   Execution  node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Set input Execution node as current succeeded.</dd>
      *    <dt>E_FAIL</dt>     <dd>Set input Execution node as current failed.</dd>
      *    </dl>
      */
      static HRESULT SetExecutionAsCurrent( PLMExchangeExecution * ixExecNode ) ;

      // ---------------------------------------------------
      // --- Manage factory for Notification.
      // ---------------------------------------------------

    /**
      * Sets one notification information.
      *
      * <br><b>Role</b>: Sets notification information.
      *
      * @param ixNode [in]
      *   Node on which notification will be associated.
      *
      * @param inType [in]
      *  Notification type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeTraceNotification</dt>       <dd>Simple trace notification. </dd>
      * <dt>PLMExchangeDebugNotification</dt>       <dd>Debug trace notification.</dd>
      * <dt>PLMExchangeInformationNotification</dt> <dd>Information notification.</dd>
      * <dt>PLMExchangeWarningNotification</dt>     <dd>Warning notification.</dd>
      * <dt>PLMExchangeErrorNotification</dt>       <dd>Error notification.</dd>
      * <dt>PLMExchangeFatalNotification</dt>       <dd>Datal error notification.</dd>
      * </dl>
      *
      * @param icErrorId [in]
      *  Error name.
      *
      * @param icMessage [in]
      *  NLS notification message.
      *
      * @param oxNotifNode [out]
      *   Notification node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateNotification( PLMExchangeNode           * ixNode
                                       , int                         inType
                                       , const CATUnicodeString    & icErrorId
                                       , const CATUnicodeString    & icMessage
                                       , PLMExchangeNotification * & oxNotifNode ) ;

      // ---------------------------------------------------
      // --- Manage factory for Object & Attribute Class.
      // ---------------------------------------------------

    /**
      * Creates one new Object Class.
      *
      * <br><b>Role</b>: Creates one new Object Class.
      *
      * @param inMoType [in]
      *   Object core Type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeObjectType_Reference</dt>      <dd>Reference.</dd>
      * <dt>PLMExchangeObjectType_Port</dt>           <dd>Port.</dd>
      * <dt>PLMExchangeObjectType_Connection</dt>     <dd>Connection.</dd>
      * <dt>PLMExchangeObjectType_Instance</dt>       <dd>Instance.</dd>
      * <dt>PLMExchangeObjectType_Representation</dt> <dd>Representation.</dd>
      * <dt>PLMExchangeObjectType_RepInstance</dt>    <dd>Representation Instance.</dd>
      * <dt>PLMExchangeObjectType_Entity</dt>         <dd>Entity.</dd>
      * <dt>PLMExchangeObjectType_Relation</dt>       <dd>Relation.</dd>
      * </dl>
      *
      * @param icName [in]
      *   Object class name.
      *
      * @param oxObjectClassNode [out]
      *   Object Class node.
      *
      * @param ixDataSource  [in]
      *   Data source node on which object class is defined; if NULL associate to default data source of current Execution.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateObjectClass( PLMExchangeNode::PLMExchangeObjectType   inMoType
                                      , const CATUnicodeString                 & icName
                                      , PLMExchangeClassObject               * & oxObjectClassNode
                                      , PLMExchangeDataSource                  * ixDataSource = NULL ) ;

     /**
      * Creates one new Attribute class.
      *
      * <br><b>Role</b>: Creates one new Attribute class.
      *
      * @param ixObjectClassNode [in]
      *   Mother object class.
      *
      * @param icName [in]
      *   Attribute class name.
      *
      * @param inType [in]
      *   Value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param oxAttrClassNode [out]
      *   Attribute class node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateAttributeClass( PLMExchangeClassObject      * ixObjectClassNode
                                         , const CATUnicodeString      & icName
                                         , int                           inType
                                         , PLMExchangeClassAttribute * & oxAttrClassNode ) ;

      // ---------------------------------------------------
      // --- Manage factory for Object.
      // ---------------------------------------------------

    /**
      * Creates one new object.
      *
      * <br><b>Role</b>: Creates one object.
      *
      * @param inMoType [in]
      *   Object core Type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeObjectType_Reference</dt>      <dd>Reference.</dd>
      * <dt>PLMExchangeObjectType_Port</dt>           <dd>Port.</dd>
      * <dt>PLMExchangeObjectType_Connection</dt>     <dd>Connection.</dd>
      * <dt>PLMExchangeObjectType_Instance</dt>       <dd>Instance.</dd>
      * <dt>PLMExchangeObjectType_Representation</dt> <dd>Representation.</dd>
      * <dt>PLMExchangeObjectType_RepInstance</dt>    <dd>Representation Instance.</dd>
      * <dt>PLMExchangeObjectType_Entity</dt>         <dd>Entity.</dd>
      * <dt>PLMExchangeObjectType_Relation</dt>       <dd>Relation.</dd>
      * </dl>
      *
      * @param icId  [in]
      *   Oid (could be an empty string if no Oid).
      *
      * @param oxObjectNode [out]
      *   Object node.
      *
      * @param ixClassObjectNode  [in]
      *   Class object to be used as template (optional if NULL).
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateObject( PLMExchangeNode::PLMExchangeObjectType   inMoType
                                 , const CATString                        & icIdd
                                 , PLMExchangeObject                    * & oxObjectNode
                                 , PLMExchangeClassObject                 * ixClassObjectNode = NULL ) ;

      // ---------------------------------------------------
      // --- Manage factory for Options.
      // ---------------------------------------------------

    /**
      * Creates one new Option.
      *
      * <br><b>Role</b>: Creates one new Option in default option set.
      *
      * @param ixExecNode [in]
      *   Execution node.
      *
      * @param icOptionKey  [in]
      *   Access key to NLS option name.
      *   <p>This string enables to look for NLS option name. It is a structured string made of 3 fields CATNls file name, '.' character
      *   and key inside this message catalog: name_CATNls_File.key </p>
      *
      * @param inType [in]
      *   Value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param icDefaultValue [in]
      *   Default option value.
      *
      * @param icValue [in]
      *   Value.
      *
      * @param iisSet [in]
      *   Information to identify if value has been set.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>0</dt>  <dd>Value not set.</dd>
      *  <dt>1</dt>  <dd>Value has been set.</dd>
      *  </dl>
      *
      * @param inLockStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Value is not locked.</dd>
      *  <dt>1</dt>   <dd>Value is locked.</dd>
      *  </dl>
      *
      * @param oxOptionNode [out]
      *   Option node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateOption( PLMExchangeExecution   * ixExecNode
                                 , const CATUnicodeString & icOptionKey
                                 , int                      inType
                                 , const CATUnicodeString & icDefaultValue
                                 , const CATUnicodeString & icValue
                                 , int                      iisSet
                                 , int                      inLockStatus
                                 , PLMExchangeOption    * & oxOptionNode ) ;

    /**
      * Creates one new Option.
      *
      * <br><b>Role</b>: Creates one new Option.
      *
      * @param ixExecNode [in]
      *   Execution node.
      *
      * @param icOptionGroupKey  [in]
      *   Access key to NLS option Set name.
      *   <p>This string enables to look for NLS option name. It is a structured string made of 3 fields CATNls file name, '.' character
      *   and key inside this message catalog: name_CATNls_File.key </p>
      *
      * @param icOptionKey  [in]
      *   Access key to NLS option name.
      *   <p>This string enables to look for NLS option name. It is a structured string made of 3 fields CATNls file name, '.' character
      *   and key inside this message catalog: name_CATNls_File.key </p>
      *
      * @param inType [in]
      *   Value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param icDefaultValue [in]
      *   Default option value.
      *
      * @param icValue [in]
      *   Value.
      *
      * @param iisSet [in]
      *   Information to identify if value has been set.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>0</dt>  <dd>Value not set.</dd>
      *  <dt>1</dt>  <dd>Value has been set.</dd>
      *  </dl>
      *
      * @param inLockStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Value is not locked.</dd>
      *  <dt>1</dt>   <dd>Value is locked.</dd>
      *  </dl>
      *
      * @param oxOptionNode [out]
      *   Option node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateOption( PLMExchangeExecution   * ixExecNode
                                 , const CATUnicodeString & icOptionGroupKey
                                 , const CATUnicodeString & icOptionKey
                                 , int                      inType
                                 , const CATUnicodeString & icDefaultValue
                                 , const CATUnicodeString & icValue
                                 , int                      iisSet
                                 , int                      inLockStatus
                                 , PLMExchangeOption    * & oxOptionNode ) ;

      // ---------------------------------------------------
      // --- Manage factory for Metrics.
      // ---------------------------------------------------

    /**
      * Creates one new metric.
      *
      * <br><b>Role</b>: Creates one new metric.
      *
      * @param ixNode [in]
      *   Node on which metric will be associated.
      *
      * @param icName [in]
      *   Metric name.
      *
      * @param inType [in]
      *   Value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param icValue [in]
      *   Value.
      *
      * @param iisSet [in]
      *   Information to identify if value has been set.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>0</dt>  <dd>Value not set.</dd>
      *  <dt>1</dt>  <dd>Value has been set.</dd>
      *  </dl>
      *
      * @param oxMetricNode [out]
      *   Metric node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateMetric( PLMExchangeNode        * ixNode
                                 , const CATUnicodeString & icName
                                 , int                      inType
                                 , const CATUnicodeString & icValue
                                 , int                      iisSet
                                 , PLMExchangeMetric    * & oxMetricNode ) ;

    /**
      * Creates one new metric.
      *
      * <br><b>Role</b>: Creates one new metric.
      *
      * @param ixNode [in]
      *   Node on which metric will be associated.
      *
      * @param icName [in]
      *   Metric name.
      *
      * @param inType [in]
      *   Value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param oxMetricNode [out]
      *   Metric node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateMetric( PLMExchangeNode        * ixNode
                                 , const CATUnicodeString & icName
                                 , int                      inType
                                 , PLMExchangeMetric    * & oxMetricNode ) ;

      // ---------------------------------------------------
      // --- Manage factory for Attributes.
      // ---------------------------------------------------

    /**
      * Creates one new Attribute.
      *
      * <br><b>Role</b>: Creates one new Attribute.
      *
      * @param ixNode [in]
      *   Node on which attribute will be associated.
      *
      * @param icName [in]
      *   Attribute name.
      *
      * @param inType [in]
      *   Value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param icValue [in]
      *   Value.
      *
      * @param iisSet [in]
      *   Information to identify if value has been set.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>0</dt>  <dd>Value not set.</dd>
      *  <dt>1</dt>  <dd>Value has been set.</dd>
      *  </dl>
      *
      * @param oxAttrNode [out]
      *   Attribute node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateAttribute( PLMExchangeNode        * ixNode
                                    , const CATUnicodeString & icName
                                    , int                      inType
                                    , const CATUnicodeString & icValue
                                    , int                      iisSet
                                    , PLMExchangeAttribute * & oxAttrNode ) ;

    /**
      * Creates one new array Attribute.
      *
      * <br><b>Role</b>: Creates one new Attribute with an array of values.
      *
      * @param ixNode [in]
      *   Node on which attribute will be associated.
      *
      * @param icName [in]
      *   Attribute name.
      *
      * @param ilstValue [in]
      *   list of Values.
      *
      * @param iisSet [in]
      *   Information to identify if value has been set.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>0</dt>  <dd>Value not set.</dd>
      *  <dt>1</dt>  <dd>Value has been set.</dd>
      *  </dl>
      *
      * @param oxAttrNode [out]
      *   Attribute node.
      *
      * @return
      *   Returns error code.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>S_OK</dt>       <dd>Creation successfuly done.</dd>
      *    <dt>E_FAIL</dt>     <dd>Creation failed.</dd>
      *    </dl>
      */
      static HRESULT CreateAttribute( PLMExchangeNode                 * ixNode
                                    , const CATUnicodeString          & icName
                                    , const CATListOfCATUnicodeString & ilstValue
                                    , int                               iisSet
                                    , PLMExchangeAttribute          * & oxAttrNode ) ;

    /**
      * Search CATScmNode by Histo Id.
      *
      * <br><b>Role</b>: Search CATScmNode having a specific Histo Id.
      *
      * @return
      *  Returns error code
      *
      * @param inInTypeNode
      * Defines the type node you want to query on.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeNodeUnknown</dt>         <dd>Base type for all.</dd>
      * <dt>PLMExchangeNodeSet</dt>             <dd>Set of data to manage Report root or Options folders for instance.</dd>
      * <dt>PLMExchangeNodeMapping</dt>         <dd>Mapping instance.</dd>
      * <dt>PLMExchangeNodeObject</dt>          <dd>Object instance.</dd>
      * <dt>PLMExchangeNodeAttribute</dt>       <dd>Attribute value.</dd>
      * <dt>PLMExchangeNodeDataSource</dt>      <dd>Data repository.</dd>
      * <dt>PLMExchangeNodeClassObject</dt>     <dd>Object class.</dd>
      * <dt>PLMExchangeNodeClassAttribute</dt>  <dd>Attribute class.</dd>
      * <dt>PLMExchangeNodeNotification</dt>    <dd>Notification (Error, warning, information messages).</dd>
      * <dt>PLMExchangeNodeMetric</dt>          <dd>Metrics capture.</dd>
      * <dt>PLMExchangeNodeEngine</dt>          <dd>Software Engine.</dd>
      * <dt>PLMExchangeNodeOption</dt>          <dd>Option.</dd>
      * </dl>
      *
      * @param icOid
      *   Object Oid.
      *
      * @param oxResultList
      *  List of PLMExchangeNode with specified Oid.
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>At least one object found by Oid & Type.</dd>
      * <dt>S_FALSE</dt> <dd>No object found with type & oid criteria.</dd>
      * <dt>E_FAIL</dt>  <dd>One error raised during this operation.</dd>
      * </dl>
      */
      static HRESULT SearchByOid( int inInTypeNode , const CATString & icOid , CATListOfPLMExchangeNode & oxResultList ) ;

      /**
      * Verify a file existence and accessibility
      * <BR>Verify the existence and accessibility of a file.
      * @param iFileName
      *   Full directory path
      * @param oExist
      *   Existance flag <ul>
      * <li>=0:   if the file does not exist
      * <li>=1: if the file exists
      * <li>=-1: if the file exists but does not observe the condition of access
      * </ul>
      * @param iAccess
      *   Access flag
      * <ul>
      * <li>=0: test the existence only
      * <li>=1: test the existence AND read access
      * <li>=2: test the existence AND write access
      * </ul>
      * @param iflag
      *   Access flag
      * <ul>
      * <li>=0: no flush of CATFileStat64 HashTable
      * <li>=1: INODE_UPDATE value for CATFileStat64 API
      * </ul>
      * @return
      *   <ul>
      *   E_FAIL: FileName corresponds a directory.
      *   </ul>
      */
      static HRESULT CheckIfFile(const CATUnicodeString &iFileName, int &oExist, int iAccess = 0, int iflag = 0 /*INODE_UPDATE*/);

      /**
      * Copy a Resource
      * <BR>Copy a resource (a file or the full content of a directory) under a directory.
      * @param iResourcePath the relative local path (regarding CATInstallPath) of the resource to copy
      * <UL>
      * <LI>In case of iResourceToCopy is a File, the file is copied under the iReceivingDir
      * <LI>In case of iResourceToCopy is a directory, the entire files under iResourceToCopy are copied under the iReceivingDir
      * </UL>
      * @param iResourceType the type of resource to copy
      * <UL>
      * <LI>1: iResourceToCopy is a directory
      * <LI>0: iResourceToCopy is a file (default)
      * </UL>
      * @param iReceivingDir the directory under which resources have to be copied
      * <BR><FONT COLOR=RED>Depending on the OS, iReceivingDir ends with '\' or '/' character</FONT>
      * <BR>If iReceivingDir doesn't exist, it is created.
      * @return <UL>
      *    <LI>OK: resource successfully copied
      *    <LI>
      *    <LI>E_FAIL: iReceivingDir is not a valid directory (not a directory, no write access)
      *    <LI>E_FAIL: iResourceToCopy can't be copied (does not exist, no read access)
      *    </UL>
      */
      static HRESULT CopyResource(CATUnicodeString & iRessourcePath, int iRessourceType, CATUnicodeString & iReceivingDir);

      /**
      * Test a directory validity.
      * <BR>Test if a directory is a valid directory or not.
      * @param iDir
      * The path of the directory.
      * @param iAccess
      * The access permission of the directory.
      * @param oMsg
      * This parameter is used for getting the error messages in case of any error. Default Value is NULL.
      * <br>Default Value is NULL.
      * @return
      *  <UL>
      *	<LI>= 200 : directory is a file.</LI>
      *  <LI>= 201 : directory doesnot exist.</LI>
      *  <LI>= 204 : directory doesnot have write access.</LI>
      *  <LI>= 205 : directory is un defined.</LI>
      * </UL>
      */
      static int ValidDir(CATUnicodeString iDir, int iAccesPermission, CATUnicodeString * oMsg);


      /**
      * Directory Scan
      * <BR>Scan a Directory to get the list of files, taken into account a filter criteria
      * <BR>Warning: non recursive: Search is not applied to sub-directories.
      * @param iDirectory the directory to scan
      * @param iFilterKeys the list of  key to filter files according to File name
      * <BR>iFilterKeys is applied to the fileName, not on filePath ...
      * @param iFilterTyp the type of filtering to be applied when almost one iFilterKey is defined: <UL>
      * <LI>=0 AllBut: Return all files except the one containing the string 'iFilterKey'
      * <LI>=1 NonePlus: Return only files containing the string 'iFilterKey'
      * </UL>
      * @return The list of files found under iDirectoryName satisfying the iFilterKey/iFilterTyp criteria
      */
      static CATListOfCATUnicodeString * GetListOfFiles(CATUnicodeString & iDirectoryName, CATListOfCATUnicodeString iFilterKeys, int iFilterTyp);

      /**
      * Verify a directory existence and accessibility
      * <BR>Verify the existence and accessibility of a directory.
      * @param iDirName
      *   Full directory path
      * @return
      *   <dl>
      *   <dt><tt>0</tt>        the entered directory path is not valid (null).
      *   <dt><tt>1</tt>        the directory does not exist.
      *   <dt><tt>2</tt>        the directory exists but is not authorizes in writing.
      *   <dt><tt>3</tt>        if problem of access.
      *   </dl>
      */
      static int CheckIfDirectory(const CATUnicodeString &iDirName);

      // -------------------------------------------
      // --- Internal services
      // -------------------------------------------
   private:
      static PLMExchangeNode       * _xExchangeModelRoot ;
      static PLMExchangeSet        * _xObjectSet         ;
      static PLMExchangeDataSource * _xDefaultDataSource ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    private:
      /**  Service not to be implemented. */
      PLMExchangeReportService() ;

      ~PLMExchangeReportService() ;

      PLMExchangeReportService( const PLMExchangeReportService & ixNode ) ;
      PLMExchangeReportService & operator=( const PLMExchangeReportService & ixNode ) ;
} ;
#endif
