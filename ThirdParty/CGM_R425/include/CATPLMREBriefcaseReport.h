// COPYRIGHT Dassault Systemes 2006-2014
//===================================================================
//
// Dedicated to manage Channel Publish & Synchronize reporting.
// CATPLMREBriefcaseReport.h
//
//===================================================================
//
// Usage notes:
//
//
//===================================================================
//
//
//===================================================================
#ifndef CATPLMREBriefcaseReport_H
#define CATPLMREBriefcaseReport_H

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class CATIAdpPLMIdentificator ;

// --- Global error report

struct CATPLMREBriefcaseGlobalReport
{
   public:
      /**
      * Global PLMChannel operation status.
      * @param Failure
      *     The PLMChannel operation failed.
      * @param Success
      *     The PLMChannel operation Succeeded.
      * @param Warning
      *     The PLMChannel operation Succeeded, but with some warnings.
      */
      enum CATPLMBriefcaseOperationStatus
      {
        Failure = 0           
      , Success = 1        
      , Warning = 2        
      } ;

      CATPLMBriefcaseOperationStatus _BriefcaseOperationStatus ;
      CATString                      _sErrorKey                ;
      CATUnicodeString               _sOriginalErrorMessage    ;
} ;

struct CATPLMREBriefcaseDataReport
{
   public : 

    /**
      * The performed operation against the object.
      * @param None      
      * no operation performed on the object.
      * @param  Import_Create 
      * the object is created in database.
      * @param Import_Update
      * the object is updated in database.
      * @param  Import_Delete 
      * the object is deleted in database.
      * @param  Import_Ignore 
      * the object is ignored (if the object is up to date).
      * @param Import_ForceUpdate
      * Warning: the object is updated in database instead of created.
      * @param  Export 
      * the object is published.
      * @param  Export_Filtered   
      * the object is published but filtered because already up to date on the target site.
      * @param  Detach       
      * the object is detached.
      * @param  TransferSiteOwnership_Request     
      * the transfer site ownership of the object is requested.
      * @param TransferSiteOwnership_Emission              
      * the transfer site ownership of the object is emitted.
      * @param  TransferSiteOwnership_Reception             
      * the transfer site ownershpi of the object is received.
      * @param TransferSiteOwnership_Acknowledge           
      * the transfer site ownership of the object is acknowledged.
      * @param TransferSiteOwnership_Acknowledge_Reception           
      * the transfer site ownership acknowledgement of the object is received.
      * @param  Create 
      * the object is created in database.
      */
      enum CATPLMBriefcaseOperationType
      {
        Import_Create                               =  0
      , Import_Update                               =  1
      , Import_Delete                               =  2
      , Import_Ignore                               =  3
      , Import_ForceUpdate                          =  4
      , Export                                      = 10
      , Export_Filtered                             = 11
      , Detach                                      = 20
      , TransferSiteOwnership_Request               = 31
      , TransferSiteOwnership_Emission              = 32
      , TransferSiteOwnership_Reception             = 33
      , TransferSiteOwnership_Acknowledge           = 34
      , TransferSiteOwnership_Acknowledge_Reception = 35
      , Create                                      = 40
	 // , Downward									= 45
	//  , Downward_Filtered							= 46
      , Undefined                                   = 50
      } ;

    /**
      * Specific PLMChannel operation status for an ObjectId.
      * @param Failure
      *     The PLMChannel operation failed for this object.
      * @param Success
      *     The PLMChannel operation Succeeded for this object.
      * @param Warning
      *     The PLMChannel operation Succeeded for this object, but with warning.
      */
      enum CATPLMBriefcaseOperationStatus
      {
        Failure = 0           
      , Success = 1        
      , Warning = 2        
      , FailureMultiPro = 3
      } ;

    /**
      * Operation propagation status for this particular object.
      * @param Error
      *     The object is a faulty object.
      * @param ErrorByPropagation
      *     The object is not responsible of the failure of the operation.
      */
      enum CATPLMBriefcaseOperationSeverity
      {
        Error              = 0
      , ErrorByPropagation = 1
      } ;

      CATIAdpPLMIdentificator          * _Id                          ;
      CATPLMBriefcaseOperationType       _iBriefcaseOperationType     ;
      CATPLMBriefcaseOperationSeverity   _iBriefcaseOperationSeverity ;
      CATPLMBriefcaseOperationStatus     _iBriefcaseOperationStatus   ;
      CATString                          _sErrorKey                   ;
      CATUnicodeString                   _sOriginalErrorMessage       ;
      CATListOfCATUnicodeString          _iAdditionalInfo             ;

      CATPLMREBriefcaseDataReport() 
         : _Id(NULL)
         , _iBriefcaseOperationType(Import_Create)
         , _iBriefcaseOperationSeverity(ErrorByPropagation)
         , _iBriefcaseOperationStatus(Success)
         , _sErrorKey()
         , _sOriginalErrorMessage()
         , _iAdditionalInfo() {} ;

      ~CATPLMREBriefcaseDataReport()
      {
         if( _Id ) ((CATBaseUnknown*)_Id)->Release() ;  // No access to CATIPLMAdpIdentificator, then need to cast in CATBaseUnknown...
         _Id = NULL ;
      } ;

} ;

#include "CATLISTP_Clean.h"
#define CATLISTP_Append
#define CATLISTP_ApplyDelete
#define CATLISTP_RemoveAll
#define CATLISTP_QuickSort
#define CATLISTP_RemoveDuplicates
#include "CATLISTP_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByCATPLMIntegrationInterfaces

CATLISTP_DECLARE(CATPLMREBriefcaseDataReport)

class ExportedByCATPLMIntegrationInterfaces CATPLMREBriefcaseReport 
{
   public:
      CATPLMREBriefcaseReport()  ;
      ~CATPLMREBriefcaseReport() ;

      HRESULT GetGlobalReport( CATPLMREBriefcaseGlobalReport *& opGlobalReport ) const ;
   
      HRESULT SetGlobalReport( CATPLMREBriefcaseGlobalReport * ipGlobalReport ) ;
   
      HRESULT GetDataReports( CATLISTP(CATPLMREBriefcaseDataReport)& olDataReport ) const ;

      HRESULT AddDataReport( CATPLMREBriefcaseDataReport * ipDataReport ) ;

      HRESULT GetNumberOfDataReport( int & onbDataReport ) const ;

      HRESULT GetDataReport( int inDataReport , CATPLMREBriefcaseDataReport *& opDataReport ) const ;

   private:
      CATPLMREBriefcaseGlobalReport         * _pBriefcaseGlobalReport ;
      CATLISTP(CATPLMREBriefcaseDataReport)   _BriefcaseDataReport    ;
} ;
#endif
