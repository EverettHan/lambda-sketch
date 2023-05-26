// COPYRIGHT Dassault Systemes 2008-2011
//===================================================================
//
// CATPLMREBriefcaseImportOptions.h
// Optional parameters of the Import briefcase APIs
//
//===================================================================
//
//
//===================================================================
//
//  Jul 2008  Creation: JDC
//===================================================================

#ifndef _CATPLMREBriefcaseImportOptions_H
#define _CATPLMREBriefcaseImportOptions_H

/**
  * @level Protected
  * @usage U1
  */

#include "CATPLMIntegrationInterfaces.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATCollec.h"
#include "CATString.h"
#include "CATLISTPCATPLMREDataImportResultRecord.h"

class PLMExchangeExecution;
class CATLISTV(CATPLMID);
class CATIPLMREBriefcaseDataImportReporting;

/**
  * Object holding optional parameters of the Import briefcase APIs.
  * <br><b>Role</b>: This object allows to define optional parameters for @href CATIPLMReplicationEngine#ImportBriefcase and CATIPLMReplicationEngine#ImportBriefcaseAsNew services.
  *
  * @see CATIPLMReplicationEngine
  */
class ExportedByCATPLMIntegrationInterfaces CATPLMREBriefcaseImportOptions
{
   public:
      CATPLMREBriefcaseImportOptions()          ;
      virtual ~CATPLMREBriefcaseImportOptions() ;

    /**
      * Allows to get the list of imported entities.
      * <br><b>Role:</b>If provided, the PLMIds of the imported entities will be appended.
      */ 
      HRESULT SetImportedEntitiesReportList( CATLISTV(CATPLMID) * ipImportedEntities ) ;

    /**
      * Specify if downward import is authorized
      * <br><b>Role:</b>.if set to TRUE, allows downward import. default is FALSE.
      */ 
      HRESULT AllowWeakenedEntities( CATBoolean iAllow ) ;

    /**
      * Specify if a pre release state is authorized
      * <br><b>Role:</b>.if set to TRUE, import will be done without checking a potential pre release state. default is TRUE.
      */ 
      HRESULT AllowPreReleaseState( CATBoolean iAllow ) ;  

    /**
      * Description of conflict rule applicable when importing PLM entities.
      * <dl>
      * <dt>GenerateErrorOnConflict</dt>      <dd>Error in case of a conflict.</dd>
      * <dt>KeepLocalObjectOnConflict</dt>    <dd>In case of a conflict, keep local PLM entity ignoring the one in the briefcase.</dd>
      * <dt>TakeIncomingObjectOnConflict</dt> <dd>In case of a conflict, take the PLM entity issued from the briefcase.</dd>
      * </dl>
      */
      enum CATPLMREGlobalConflictRule 
      {
        GenerateErrorOnConflict      = 0
      , KeepLocalObjectOnConflict    = 1
      , TakeIncomingObjectOnConflict = 2
      } ;

    /**
      * Description of conflict rule applicable when importing PLM entities in delegation context.
      * <dl>
      * <dt>DetectConflict</dt>            <dd>Error in case of a conflict.</dd>
      * <dt>IgnoreAndKeepLocalData</dt>    <dd>In case of a conflict, keep local PLM entity ignoring the one in the briefcase.</dd>
      * <dt>UpdateWithIncomingData</dt>    <dd>In case of a conflict, take the PLM entity issued from the briefcase.</dd>
      * </dl>
      */
      enum CATPLMREWaiveConflictRule 
      {
        DetectConflict          = 0 
      , IgnoreAndKeepLocalData  = 1
      , UpdateWithIncomingData  = 2
      } ;

    /**
      * Specifies the conflict rule applicable at Synchronize when importing PLM entities.
      * <br><b>Role:</b>This service allows to specify the conflict rule applicable at Synchronize when importing PLM entities.Default value is GenerateErrorOnConflict.
      */ 
      HRESULT SetGlobalConflictRule( CATPLMREGlobalConflictRule iConflictRule ) ;

    /**
      * Specifies the waive conflict rule applicable at Synchronize when importing PLM entities.
      * <br><b>Role:</b>This service allows to specify the conflict rule applicable at Synchronize when importing PLM entities ibn Delegation context(waive/revoke).Default value is DetectConflict.
      */ 
      HRESULT SetWaiveConflictRule( CATPLMREWaiveConflictRule iWaiveConflictRule ) ;

    /**
      * Activates the replication engine data import reporting.
      * <br><b>Role:</b>This service allows to activate the replication engine data import reporting.
      */ 
      HRESULT ActivateDataImportReporting( CATIPLMREBriefcaseDataImportReporting    * ipCATIPLMREBriefcaseDataImportReporting
                                         , CATListPtrCATPLMREDataImportResultRecord * ipListOfDataImportResultRecords ) ;

    /**
      * Read the replication engine data import reporting information.
      * <br><b>Role:</b>Read the replication engine data import reporting information.
      * 
      * @param opCATIPLMREBriefcaseDataImportReporting [out, CATBaseUnknown#Release]
      *  Access to Report information.
      * 
      * @param opListOfDataImportResultRecords [out]
      *  List of result records.
      */ 
      HRESULT GetDataImportReportingInformation( CATIPLMREBriefcaseDataImportReporting    *& opCATIPLMREBriefcaseDataImportReporting
                                               , CATListPtrCATPLMREDataImportResultRecord *& opListOfDataImportResultRecords         ) const ;

      /**
      * Get the PLMExchangeExecutionNode used for import reporting
      * <br><b>Role:</b>Read the replication engine data import reporting information.
      * 
      * @param opExecution [out]
      *  Execution node.
      */ 
      HRESULT GetPLMExchangeExecutionNode( PLMExchangeExecution *& opExecution ) const ;

      /**
      * Set the PLMExchangeExecutionNode used for import reporting
      * <br><b>Role:</b>Sets the execution node used for import reporting.
      * 
      * @param ipExecution [in]
      *  Execution node.
      */ 
      HRESULT SetPLMExchangeExecutionNode( PLMExchangeExecution *& ipExecution ) ;

      /**
      * Activate the Reidentification at import
      * <br><b>Role:</b>Activate the Reidentification at import
      * 
      */ 
      HRESULT ActivateReidentificationAtImport() ;

#ifdef CATIAR422
      /**
      * Set the PreviewImport mode for Import as Reference
      * <br><b>Role:</b>Sets the PreviewImport mode used to activate Preview Import.
      *
      * @param ibSimulMode [in]
      *  Preview Import Mode.
      */
      HRESULT SetSimulationMode(const CATBoolean ibSimulMode);

      /**
      * Get the PreviewImport mode ON/OFF value for Import as Reference
      * <br><b>Role:</b>Gets the Preview Import mode active/inactive value.
      *
      * @param obSimulMode [out]
      *  Preview Import Mode.
      */
      HRESULT GetSimulationMode(CATBoolean & obSimulMode) const;

      /**
      * Set the PreviewImportLog file path for Preview Import
      * <br><b>Role:</b>Sets the path for PreviewImportLog file to be created.
      *
      * @param iusPreviewImportLogPath [in]
      *  Preview Import file path in the format "E:\\PreviewImport\\LogFolder\\"
      */
      HRESULT SetPathOfLog(const CATUnicodeString & iusPreviewImportLogPath);

      /**
      * Get the PreviewImportLog file path for Preview Import
      * <br><b>Role:</b>Gets the path where PreviewImportLog file will be created.
      *
      * @param ousPreviewImportLogPath [out]
      *  Preview Import file path in the format "E:\\PreviewImport\\LogFolder\\"
      */
      HRESULT GetPathOfLog(CATUnicodeString & ousPreviewImportLogPath) const;

      // FUN127642
      /**
      * Set the json present or not
      *
      * @param bJsonPresent [in]
      */
      HRESULT SetExportControlJsonPresentOrNot(const CATBoolean& bJsonPresent);

      /**
      * Get the json present or not
      *
      * @param bJsonPresent [out]
      */
      HRESULT GetExportControlJsonPresentOrNot(CATBoolean& bJsonPresent) const;

#endif

   private:

      friend class CATPLMREImportAbstractTask ;

      CATPLMREBriefcaseImportOptions& operator=(const CATPLMREBriefcaseImportOptions &) ; // not implemented
      CATPLMREBriefcaseImportOptions(const CATPLMREBriefcaseImportOptions &) ;            // not implemented
  
      CATLISTV(CATPLMID)                       * _pImportedEntities                      ;

      CATPLMREGlobalConflictRule                 _conflictRule                           ;

      CATPLMREWaiveConflictRule                  _waiveConflictRule                      ;

      CATListPtrCATPLMREDataImportResultRecord * _pListOfDataImportResultRecords         ;
      CATIPLMREBriefcaseDataImportReporting    * _pCATIPLMREBriefcaseDataImportReporting ;

      CATBoolean                                 _bAllowWeakeanedEntities                ;
      CATBoolean                                 _bAllowPreReleaseState                  ;

      PLMExchangeExecution                     * _pExecution                             ;

      CATBoolean                                 _bReidentificationActivated             ;

#ifdef CATIAR422
      /** Specify if Preview/Simulation is ON/OFF in Import */
      CATBoolean                                 _bIsSimulationMode                      ;

      /** Specify the path where PreviewImportLog.xml is to be created*/
      CATUnicodeString                           _PreviewLogFilePath                     ;
#endif
      CATBoolean                                 _bECJsonPresent                          ;
} ;
#endif
