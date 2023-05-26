// COPYRIGHT Dassault Systemes 2008-2015
//===================================================================
//
// CATPLMREPlugPublishOptions.h
// Optional parameters of the plug publish APIs
//
//==================================================================
//
//
//===================================================================
//
//  Jan 2008  Creation: LED
//  Jan 2016  Update:   Jean-Luc MEDIONI  Object: fix AWPD mkCheckSource warning
//===================================================================

#ifndef _CATPLMREPlugPublishOptions_H
#define _CATPLMREPlugPublishOptions_H

/**
  * @level Protected
  * @usage U1
  */

#include "CATPLMIntegrationInterfaces.h"

#include "IUnknown.h"
#include "CATSysBoolean.h"
#include "CATCollec.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATPLMREDataImportResultRecord.h"
#include "CATLISTPCATPLMREDataImportResultRecord.h"

class CATIPLMBriefcaseHeader         ;
class CATIPLMEngineListener          ;
class CATLISTV(CATPLMID)             ;
class CATIPLMREBriefcaseExportExtend ;
class CATPLMID                       ;
class CATPLMREBriefcaseReport        ;

/**
  * Object holding optional parameters of the plug publish API.
  * <br><b>Role</b>: This object allows to define optional parameters for @href CATIPLMReplicationEnginePlugServices#PublishPlug service.
  *
  * @see CATIPLMReplicationEnginePlugServices
  */
class ExportedByCATPLMIntegrationInterfaces CATPLMREPlugPublishOptions
{
   public:
      CATPLMREPlugPublishOptions()  ;
      ~CATPLMREPlugPublishOptions() ;

    /**
      * Allows to provide a PLM listener.
      * <br><b>Role:</b>If provided, the PLM listener will be notified of the publish progress and errors.
      */ 
      HRESULT SetListener( CATIPLMEngineListener * ipListener ) ;

    /**
      * Sets the briefcase header of the revision.
      * <br><b>Role:</b>This services allows to provide a customized briefcase header to be included in the revision.
      */ 
      HRESULT SetHeader( CATIPLMBriefcaseHeader * ipHeader ) ;

    /**
      * Allows to define the data scope of the publication.
      * <br><b>Role:</b>The data scope is the set of PLM components that will be published in this revision.
      * <br>It is empty be default.
      */ 
      HRESULT SetDataScope( const CATLISTV(CATPLMID) * ipComponents ) ;

    /**
      * Specifies if edition token publication is activated.
      * <br><b>Role:</b>By default, edition tokens are not published. This service allows to request the publication of edition tokens in the revision.
      */ 
      HRESULT PublishEditionTokens( CATBoolean iYesOrNo ) ;      

    /**
      * Specifies if delete propagation is activated.
      * <br><b>Role:</b>This service allows to request the replication-engine to retrieve deleted objects to be published.
      */ 
      HRESULT PropagateDelete( CATBoolean iYesOrNo ) ;

    /**
      * @deprecated R207
      * Activate the declaration of applicative ids for PLM components exported in the PLM briefcase
      * <br><b>Role:</b>Activate the declaration of applicative ids for PLM components exported in the PLM briefcase.
      */ 
      HRESULT ActivateExtendedExport( CATString * ipExtendedExportLateType ) ;

    /**
      * @deprecated R207
      * Get the extended export information
      * <br><b>Role:</b>Get the extended export information.
      */
      HRESULT GetExtendedExportInformation( CATString *& opExtendedExportLateType ) const ;

    /**
      * Activate the declaration of applicative ids for PLM components exported in the PLM briefcase
      * <br><b>Role:</b>Activate the declaration of applicative ids for PLM components exported in the PLM briefcase.
      */ 
      HRESULT ActivateExtendedExport( CATIPLMREBriefcaseExportExtend * ipCATIPLMREBriefcaseExportExtend ) ;

    /**
      * Get the extended export information (reading the implementation of CATIPLMREBriefcaseExportExtend to be used (if any))
      * <br><b>Role:</b>Get the extended export information if any.
      * @param opCATIPLMREBriefcaseExportExtend [out, IUnknown#Release]
      *   Handler to extended export information.
      */ 
      HRESULT GetExtendedExportInformation( CATIPLMREBriefcaseExportExtend *& opCATIPLMREBriefcaseExportExtend ) const ;

    /**
      * Get the file path (generally acknowledgement path) for Optimized Publish
      * <br><b>Role:</b>Get the input file path
      */ 
      HRESULT GetInputFilePathForOptimizedPublish( CATUnicodeString& oFilePath ) const ;

    /**
      * Set the file path (generally acknowledgement path) for Optimized Publish
      * <br><b>Role:</b>Set the input file path
      */ 
      HRESULT SetInputFilePathForOptimizedPublish( const CATUnicodeString& iFilePath ) ;

    /**
      * Set the briefcase report to store operation result and errors.
      * <br><b>Role:</b> used by the engine to contain the report.
      */
      HRESULT SetBriefcaseReport( CATPLMREBriefcaseReport * ipBriefcaseReport ) ;

    /**
      * Get Status to know if data have to be extracted or not
      * <br><b>Role:</b>Get Status to know if data have to be extracted or not
      */ 
      HRESULT GetDataToBeExtractedStatus( CATBoolean & oDataToBeExtractedStatus ) const ;

    /**
      * Set Status to know if data have to be extracted or not
      * <br><b>Role:</b>Set Status to know if data have to be extracted or not
      */ 
      HRESULT SetDataToBeExtractedStatus( const CATBoolean iDataToBeExtractedStatus ) ;

      /*
      * Get the briefcase report to store operation result and errors.
      * <br><b>Role:</b> Get the report container.
      */
      HRESULT GetBriefcaseReport( CATPLMREBriefcaseReport *& opBriefcaseReport ) const ;

   private:

      friend class CATPLMREPublishTask ;

      CATPLMREPlugPublishOptions& operator=(const CATPLMREPlugPublishOptions &); // not implemented
      CATPLMREPlugPublishOptions(const CATPLMREPlugPublishOptions &); // not implemented

      CATIPLMEngineListener          * _pListener                       ;
      CATIPLMBriefcaseHeader         * _pHeader                         ;
      const CATLISTV(CATPLMID)       * _pComponents                     ;
      CATString                      * _pExtendedExportLateType         ;
      CATIPLMREBriefcaseExportExtend * _pCATIPLMREBriefcaseExportExtend ;
      CATPLMREBriefcaseReport        * _pBriefcaseReport                ;
      CATUnicodeString                 _sInputFilePathOptimizedPublish  ;
      CATBoolean                       _bPublishEditionTokens           ;
      CATBoolean                       _bPropagateDelete                ;
      CATBoolean				            _bDataToBeExtractedStatus        ;
} ;
#endif
