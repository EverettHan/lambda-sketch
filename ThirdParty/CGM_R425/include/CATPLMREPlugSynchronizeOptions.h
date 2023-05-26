// COPYRIGHT Dassault Systemes 2008-2015
//==================================================================
//
// CATPLMREPlugSynchronizeOptions.h
// Optional parameters of the plug synchronize APIs
//
//===================================================================
//
// History:
// --------
//  January 2008  Author: LED  Objective: Creation: 
//  March   2012  Author: JLM  Objective: Quick code review
//===================================================================

#ifndef _CATPLMREPlugSynchronizeOptions_H
#define _CATPLMREPlugSynchronizeOptions_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATSysErrorDef.h"
#include "CATSysBoolean.h"
#include "CATString.h"
#include "CATLISTPCATPLMREDataImportResultRecord.h"

class CATIPLMEngineListener                 ;
class CATIPLMREBriefcaseDataImportReporting ;
class CATPLMREBriefcaseReport               ;
class CATLISTV(CATPLMID)                    ;

/**
  * Object holding optional parameters of the plug synchronize API.
  * <br><b>Role</b>: This object allows to define optional parameters for @href CATIPLMReplicationEnginePlugServices#SynchronizePlug service.
  *
  * @see CATIPLMReplicationEnginePlugServices
  */
class ExportedByCATPLMIntegrationInterfaces CATPLMREPlugSynchronizeOptions
{
   public:

    /**
      * Description of conflict rule applicable at Synchronize when importing PLM entities.
      * <dt> <code>GenerateErrorOnConflict</code>      <dd> Error in case of a conflict
      * <dt> <code>KeepLocalObjectOnConflict</code>    <dd> In case of a conflict, keep local PLM entity ignoring the one in the briefcase
      * <dt> <code>TakeIncomingObjectOnConflict</code> <dd> In case of a conflict, take the PLM entity issued from the briefcase
      */
      enum CATPLMREGlobalConflictRule 
      {
        GenerateErrorOnConflict      = 0
      , KeepLocalObjectOnConflict    = 1
      , TakeIncomingObjectOnConflict = 2
      } ;

      CATPLMREPlugSynchronizeOptions() ;
      ~CATPLMREPlugSynchronizeOptions() ;

    /**
      * Allows to provide a PLM listener.
      * <br><b>Role:</b>If provided, the PLM listener will be notified of the publish progress and errors.
      */ 
      HRESULT SetListener( CATIPLMEngineListener *ipListener ) ;

    /**
      * Allows to provide a PLM environment to be used during import.
      * <br><b>Role:</b>This method allows to define the PLM environment to be used during import. The PLM environment be used to determine custom type for created entities.
      * <br>By default, no import environment is defined.
      */ 
      HRESULT SetImportEnvironment( const CATString & iEnvironmentId ) ;

    /**
      * Specifies if edition token processing should be ignored.
      * <br><b>Role:</b>By default, edition tokens contained in the revision are processed during synchronization. This service allows to skip this step.
      */ 
      HRESULT IgnoreEditionTokens( CATBoolean iYesOrNo ) ;     

    /**
      * Specifies if data synchronization should be ignored.
      * <br><b>Role:</b>This service allows to skip the data synchronization.
      */ 
      HRESULT IgnoreData( CATBoolean iYesOrNo ) ;

    /**
      * Specifies the conflict rule applicable at Synchronize when importing PLM entities.
      * <br><b>Role:</b>This service allows to specify the conflict rule applicable at Synchronize when importing PLM entities.Default value is GenerateErrorOnConflict.
      */ 
      HRESULT SetGlobalConflictRule( CATPLMREGlobalConflictRule iConflictRule ) ;

    /**
      * Specifies if weakened entities can be imported.
      * <br><b>Role:</b> if set to TRUE, allows downward import. default is FALSE.
      */
      HRESULT AllowWeakenedEntities( CATBoolean iAllow ) ;

    /**
      * @deprecated R207
      * Activates the replication engine data import reporting.
      * <br><b>Role:</b>This service allows to activate the replication engine data import reporting.
      */ 
      HRESULT ActivateDataImportReporting( CATString                                * ipDataImportReportingLateType
                                         , CATListPtrCATPLMREDataImportResultRecord * ipListOfDataImportResultRecords ) ;

    /**
      * Activates the replication engine data import reporting.
      * <br><b>Role:</b>This service allows to activate the replication engine data import reporting.
      */ 
      HRESULT ActivateDataImportReporting( CATIPLMREBriefcaseDataImportReporting    * ipCATIPLMREBriefcaseDataImportReporting
                                         , CATListPtrCATPLMREDataImportResultRecord * ipListOfDataImportResultRecords ) ;

    /**
      * Read the replication engine data import reporting information.
      * <br><b>Role:</b>Read the replication engine data import reporting information.
      */ 
      HRESULT GetDataImportReportingInformation( CATIPLMREBriefcaseDataImportReporting    *& opCATIPLMREBriefcaseDataImportReporting
                                               , CATListPtrCATPLMREDataImportResultRecord *& opListOfDataImportResultRecords ) ;

    /**
      * Set the briefcase report to store operation result and errors.
      * <br><b>Role:</b> used by the engine to contain the report.
      */
      HRESULT SetBriefcaseReport(CATPLMREBriefcaseReport * ipBriefcaseReport );

    /**
      * Set the List of Synchronized PLMIds.
      * <br><b>Role:</b>Set the List of Synchronized PLMIds.
      */ 
      HRESULT SetSynchronizedEntitiesList( CATLISTV(CATPLMID)* ipSynchronizedEntities ) ;

    /**
      * Get the briefcase report to store operation result and errors.
      * <br><b>Role:</b> Get the report container.
      */
      HRESULT GetBriefcaseReport( CATPLMREBriefcaseReport *& opBriefcaseReport ) const ;

    /**
      * Get the List of Synchronized PLMIds.
      * <br><b>Role:</b>Get the List of Synchronized PLMIds.
      */ 
      HRESULT GetSynchronizedEntitiesList( CATLISTV(CATPLMID) *& opSynchronizedEntities ) const ;

    /**
      * Set if PLMBriefcase without modification will be skipped.
      * <br><b>Role:</b>Set if PLMBriefcase without modification will be skipped.
      *
      * @param ibSkipEmptyBriefcase [in]
      *   Define if PLMBriefcase without modification will be skipped.
      *
      * @return
      *   Error code.
      */ 
      HRESULT SetSkipEmptyBriefcase( CATBoolean ibSkipEmptyBriefcase ) ;

    /**
      * Checks if PLMBriefcase without modification will be skipped.
      *
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      * <dt>TRUE</dt>   <dd>PLMBriefcase with no modification will be skipped.</dd>
      * <dt>FALSE</dt>  <dd>PLMBriefcase with no modification will be analyzed.</dd>
      * </dl>
      */ 
      CATBoolean SkipEmptyBriefcase() const ;

   private:

      friend class CATPLMRESynchronizeTask ;

      CATPLMREPlugSynchronizeOptions& operator=(const CATPLMREPlugSynchronizeOptions &); // not implemented
      CATPLMREPlugSynchronizeOptions(const CATPLMREPlugSynchronizeOptions &);            // not implemented

      CATIPLMEngineListener                    * _pListener                              ;
      CATString                                * _pDataImportReportingLateType           ;
      CATListPtrCATPLMREDataImportResultRecord * _pListOfDataImportResultRecords         ;
      CATIPLMREBriefcaseDataImportReporting    * _pCATIPLMREBriefcaseDataImportReporting ;
      CATPLMREBriefcaseReport                  * _pBriefcaseReport                       ;
      CATLISTV(CATPLMID)                       * _pSynchronizedEntities                  ;

      CATString                                  _sEnvironmentId                         ;
      CATPLMREGlobalConflictRule                 _ConflictRule                           ;

      CATBoolean                                 _bIgnoreData                            ;
      CATBoolean                                 _bIgnoreEditionTokens                   ;
      CATBoolean                                 _bAllowWeakeanedEntities                ;
      CATBoolean                                 _bSkipEmptyBriefcase                    ;
} ;
#endif
