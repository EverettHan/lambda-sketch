// COPYRIGHT Dassault Systemes 2005-2012
//===================================================================
//
// CATPLMREDataImportResultRecord.h
// Header definition of CATPLMREDataImportResultRecord
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef _CATPLMREDataImportResultRecord_h_
#define _CATPLMREDataImportResultRecord_h_

/**
  * @level Private
  * @usage U2
  */

#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATPLMID          ;
class CATDbBinary       ;
class CATString         ; 
class CATUnicodeString  ;
class CATPLMREOperation ;

// definition de la classe CATPLMREDataImportResultRecord classe abstraite.

class ExportedByCATPLMIntegrationInterfaces CATPLMREDataImportResultRecord : public CATBaseUnknown
{
   public: 

    /**
      * Data import treatment for the PLM entity.
      * <p>Possible values:</p>
      * <dl>
      * <dt>Tr_Ignore</dt>       <dd>The PLM component is ignored.</dd>
      * <dt>Tr_AsNew</dt>        <dd>The PLM component is created "AsNew" in the receiving repository.</dd>
      * <dt>Tr_Create</dt>       <dd>The PLM component is imported for the first time in the receiving repository (master/slave approach).</dd>
      * <dt>Tr_Update</dt>       <dd>The PLM component is updated in the receiving repository (master/slave approach).</dd>
      * <dt>Tr_Delete</dt>       <dd>The PLM component is deleted in the receiving repository (master/slave approach).</dd>
      * <dt>Tr_Detach</dt>       <dd>The PLM entity is detached from the receiving repository.</dd>
      * <dt>Tr_ForceUpdate</dt>  <dd>TThe PLM component is updated, but one inconsistency has been detected normal operation is imported in the receiving repository.</dd>
      * </dl>
      */
      enum CATPLMREDataImportTreatment
      {
        Tr_Ignore       = 0
      , Tr_AsNew        = 1
      , Tr_Create       = 2
      , Tr_Update       = 3
      , Tr_Delete       = 4
      , Tr_Detach       = 5
      , Tr_ForceUpdate  = 6
      }; 

    /**
      * Data import result for the PLM entity.
      * <p>Possible values:</p>
      * <dl>
      * <dt>Imp_TreatedOperationOK</dt>            <dd>The data import was successfull for the PLM entity.</dd>
      * <dt>Imp_FailedOperation</dt>               <dd>The data import failed for the PLM entity : import issue for this particular PLM entity.</dd>
      * <dt>Imp_FailedOperationByPropagation</dt>  <dd>The data import failed for the PLM entity, but only due to the failure of the data import of another PLM entity.</dd>
      * <dt>Imp_AbortedOperationOK</dt>            <dd>The data import of the PLM entity was aborted (the global data import stops before trying to import the PLM entity).</dd>
      * </dl>
      */
      enum CATPLMREDataImportResult
      {
        Imp_TreatedOperationOK            = 0         
      , Imp_FailedOperation               = 1
      , Imp_FailedOperationByPropagation  = 2
      , Imp_AbortedOperation              = 3
      } ; 

    /**
      * Data import weakened status for the PLM entity.
      * <p>Possible values:</p>
      * <dl>
      * <dt>NotApplicable</dt>                                 <dd>No data import weakened status defined in this case (case the PLM entity is ignored, deleted or detached for which the data import weakened status has no sense).</dd>
      * <dt>NotWeakened</dt>                                   <dd>The PLM entity is not weakened following its data import.</dd>
      * <dt>WeakenedByImportDegradation</dt>                   <dd>PLM entity weakened following its data import : the PLM entity was not initially weakened in the PLM briefcase, but the data import process has degradated it leading to a saved PLM entity weakened in the receiving repository.</dd>
      * <dt>WeakenedSinceBriefcase</dt>                        <dd>PLM entity weakened following its data import : the PLM entity was initially weakened in the PLM briefcase and the data import process has not created any additional degradation of this PLM entity.</dd>
      * <dt>WeakenedSinceBriefcasePlusImportDegradation</dt>   <dd>PLM entity weakened following its data import : the PLM entity was initially weakened in the PLM briefcase and the data import process has created additional degradation(s) of this PLM entity.</dd>
      * </dl>
      */

      enum CATPLMREDataImportWeakenedStatus
      { 
        NotApplicable                               = 0
      , NotWeakened                                 = 1
      , WeakenedByImportDegradation                 = 2
      , WeakenedSinceBriefcase                      = 3
      , WeakenedSinceBriefcasePlusImportDegradation = 4
      } ;

    /**
      * Get the existence of the PLM entity in the PLM briefcase.
      * @param oExistInPLMBriefcase
      *   Yes if the PLM entity exists in the PLM briefcase, else No
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      * <dt>S_OK</dt>    <dd>Getting the existence of the PLM entity in the PLM briefcase succeeded.</dd>
      * <dt>E_FAIL</dt>  <dd>Getting the existence of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetExistenceInPLMBriefcase( CATBoolean & oExistInPLMBriefcase ) = 0;

     /**
      * Get the physical id of the PLM entity in the PLM briefcase
      * @param oPhysicalId
      *   the physical id of the PLM entity in the PLM briefcase
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the physical id of the PLM entity in the PLM briefcase succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the physical id of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetPhysicalIdInPLMBriefcase( CATDbBinary & oPhysicalId ) = 0 ;

    /**
      * Get the major id of the PLM entity in the PLM briefcase.
      * @param oMajorId
      *   the major id of the PLM entity in the PLM briefcase.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the major id of the PLM entity in the PLM briefcase succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the major id of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetMajorIdInPLMBriefcase( CATDbBinary & oMajorId ) /*= 0*/;

    /**
      * Get the logical id of the PLM entity in the PLM briefcase.
      * @param oLogicalId
      *   the logical id of the PLM entity in the PLM briefcase.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the logical id of the PLM entity in the PLM briefcase succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the logical id of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetLogicalIdInPLMBriefcase( CATDbBinary & oLogicalId ) = 0;

    /**
      * Get the core name of the PLM entity in the PLM briefcase.
      * @param oCoreName
      *   the core name of the PLM entity in the PLM briefcase.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the core name of the PLM entity in the PLM briefcase succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the core name of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetCoreNameInPLMBriefcase( CATString & oCoreName ) = 0;

    /**
      * Get the modeler type of the PLM entity in the PLM briefcase.
      * @param oModelerType
      *   the modeler type of the PLM entity in the PLM briefcase.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the modeler type of the PLM entity in the PLM briefcase succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the modeler type of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetModelerTypeInPLMBriefcase( CATString & oModelerType ) = 0;

    /**
      * Get the customization type of the PLM entity in the PLM briefcase.
      * @param oCustomizationType
      *   the customization type of the PLM entity in the PLM briefcase.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the customization type of the PLM entity in the PLM briefcase succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the customization type of the PLM entity in the PLM briefcase failed.</dd>
      * </dl>
      */
      virtual HRESULT GetCustomizationTypeInPLMBriefcase( CATString & oCustomizationType ) = 0 ;

    /**
      * Get the application entity id of the PLM entity.
      * @param oApplicationEntityId
      *   The application entity id of the PLM entity.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the application entity id of the PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the application entity id of the PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetApplicationEntityId( CATString & oApplicationEntityId ) = 0 ;

    /**
      * Get the PLMId of the PLM entity (PLMId in the importing site).
      * @param oPLMId
      *   The PLMId of the PLM entity.
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the PLMId of the PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the PLMId of the PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetPLMId( CATPLMID & oPLMId ) = 0 ;

    /**
      * Get the data import treatment of a PLM entity.
      * @param oDataImportTreatment
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the data import treatment of a PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the data import treatment of a PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetDataImportTreatment( CATPLMREDataImportTreatment & oDataImportTreatment ) = 0 ;

    /**
      * Get the data import result of a PLM entity.
      * @param oDataImportResult
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the data import result of a PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the data import result of a PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetDataImportResult( CATPLMREDataImportResult & oDataImportResult ) = 0 ;

    /**
      * Get the data import weakened status of a PLM entity.
      * @param oDataImportWeakenedStatus
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Getting the data import weakened status of a PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Getting the data import weakened status of a PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetDataImportWeakenedStatus( CATPLMREDataImportWeakenedStatus & oDataImportWeakenedStatus ) = 0 ;

    /**
      * Get error information.
      * 
      * @param ocErrorKey [out]
      *   Error message Key.
      *
      * @param ocErrorMessage [out]
      *   NLS Error message.
      *   
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Error information successfully retrieved.</dd>
      *   <dt>S_FALSE</dt> <dd>No error information recorded.</dd>
      *   <dt>E_FAIL</dt>  <dd>Accessing to error information failed.</dd>
      * </dl>
      */
      virtual HRESULT GetErrorInformation( CATString & ocErrorKey , CATUnicodeString & ocErrorMessage ) = 0 ;

    /**
      * Get Replication associated replication operations.
      * 
      * @param opReplicationOperation [out,AddRef]
      *   Replication Operation.
      *
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>Error information successfully stored.</dd>
      *   <dt>E_FAIL</dt>  <dd>Accessing to error information failed.</dd>
      * </dl>
      */
      virtual HRESULT GetReplicationOperation( CATPLMREOperation *& opReplicationOperation ) const /*= 0*/ ;

   protected:

      // Constructor & Destructor
      CATPLMREDataImportResultRecord()          ;
      virtual ~CATPLMREDataImportResultRecord() ;  

} ;
#endif
