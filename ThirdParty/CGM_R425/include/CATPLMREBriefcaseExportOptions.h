// COPYRIGHT Dassault Systemes 2008-2016
//===================================================================
//
// CATPLMREBriefcaseExportOptions.h
// Optional parameters of the Export briefcase APIs
//
//===================================================================
//
//
//===================================================================
//
//  Jul 2008  Creation: PA
//===================================================================

#ifndef _CATPLMREBriefcaseExportOptions_H
#define _CATPLMREBriefcaseExportOptions_H

/**
  * @level Protected
  * @usage U1
  */
#include "CATIAV5Level.h"
#include "CATPLMIntegrationInterfaces.h"
#include "IUnknown.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATCollec.h"

class PLMExchangeExecution           ;
class PLMExchangeOption              ;
class CATIPLMREBriefcaseExportExtend ;
class CATIPLMBriefcaseHeader         ;
class CATLISTV(CATPLMID)             ;
/**
  * Object holding optional parameters of the Export briefcase APIs.
  * <br><b>Role</b>: This object allows to define optional parameters for @href CATIPLMReplicationEngine#ExportToBriefcase service.
  *
  * @see CATIPLMReplicationEngine
  */
class ExportedByCATPLMIntegrationInterfaces CATPLMREBriefcaseExportOptions
{
   public:
      CATPLMREBriefcaseExportOptions()  ;
      ~CATPLMREBriefcaseExportOptions() ;

    /**
      * @deprecated R207
      * Activate the declaration of applicative ids for PLM components exported in the PLM briefcase.
      * <br><b>Role:</b>Activate the declaration of applicative ids for PLM components exported in the PLM briefcase.
      */ 
      HRESULT ActivateExtendedExport( CATString * ipExtendedExportLateType );

    /**
      * @deprecated R207
      * Get the extended export information (reading the implementation of CATIPLMREBriefcaseExportExtend to be used (if any)).
      * <br><b>Role:</b>Get the extended export information (reading the implementation of CATIPLMREBriefcaseExportExtend to be used (if any)).
      */ 
      HRESULT GetExtendedExportInformation( CATString *& opExtendedExportLateType ) ;

    /**
      * Activate the declaration of applicative ids for PLM components exported in the PLM briefcase
      * <br><b>Role:</b>Activate the declaration of applicative ids for PLM components exported in the PLM briefcase.
      */ 
      HRESULT ActivateExtendedExport( CATIPLMREBriefcaseExportExtend * ipCATIPLMREBriefcaseExportExtend );

    /**
      * Get the extended export information (reading the implementation of CATIPLMREBriefcaseExportExtend to be used (if any)).
      * <br><b>Role:</b>Get the extended export information if any.
      * 
      * @param opCATIPLMREBriefcaseExportExtend [out, IUnknown#Release]
      *   Handler to export information.
      */ 
      HRESULT GetExtendedExportInformation( CATIPLMREBriefcaseExportExtend *& opCATIPLMREBriefcaseExportExtend ) ;

    /**
      * Allows to define the data scope of the export.
      * <br><b>Role:</b>The data scope is the set of PLM components that will be exported.
      * <br>It is empty be default.
      */ 
      HRESULT SetDataScope( const CATLISTV(CATPLMID) * ipComponents ) ;  

    /**
      * Sets the briefcase header of the briefcase.
      * <br><b>Role:</b>This services allows to provide a customized briefcase header.
      */ 
      HRESULT SetHeader( CATIPLMBriefcaseHeader * ipHeader ) ;

    /**
      * Specify if a pre-release state is authorized.
      * <br><b>Role:</b>
      * if set to TRUE, export will be done without checking a potential pre release state. 
      * default is TRUE.
      */ 
      HRESULT AllowPreReleaseState( CATBoolean iAllow ) ;	

    /**
      * Get the PLMExchangeExecutionNode used for export reporting.
      * <br><b>Role:</b>Read the replication engine data export reporting information.
      * 
      * @param opExecution [out]
      *  Execution node.
      */ 
      HRESULT GetPLMExchangeExecutionNode( PLMExchangeExecution *& opExecution ) const ;

    /**
      * Set the PLMExchangeExecutionNode used for export reporting.
      * <br><b>Role:</b>Sets the execution node used for export reporting.
      * 
      * @param ipExecution [in]
      *  Execution node.
      */ 
      HRESULT SetPLMExchangeExecutionNode( PLMExchangeExecution *& ipExecution ) ;
	  
	 /**
      * Allows to define the data scope to waive at export.
      * <br><b>Role:</b>The data scope is the set of PLM components that will be waived at export.
      * <br>It is empty be default.
      */ 
      HRESULT SetDataScopeToWaive( const CATLISTV(CATPLMID) * ipComponents ) ;

    /**
      * Get current PLMBriefcase.
      * <br><b>Role:</b>Access to current PLMBriefcase.
      * 
      * @param opBriefcase [out]
      *   Briefcase metric.
      */ 
      HRESULT GetCurrentBriefcaseNode( PLMExchangeOption *& opBriefcase ) const ;

    /**
      * Set current PLMBriefcase used for export reporting.
      * <br><b>Role:</b>Defines current PLMBriefcase used for export reporting.
      * 
      * @param ipExecution [in]
      *   Briefcase metric.
      */ 
      HRESULT SetCurrentBriefcaseNode( PLMExchangeOption *& ipBriefcase ) ;

      /**
      * Get downward compatibility level.
      * <br><b>Role:</b>Access to downward compatibility level.
      * 
      * @param ousDownwardCompatibilityLevel [out]
      *   Downward compatibility level.
      */ 
      HRESULT GetDownwardCompatibilityLevel( CATUnicodeString & ousDownwardCompatibilityLevel ) const ;

    /**
      * Set downward compatibility level.
      * <br><b>Role:</b>Defines the downward compatibility level.
      * 
      * @param iusDownwardCompatibilityLevel [in]
      *   Downward compatibility level.
      */ 
      HRESULT SetDownwardCompatibilityLevel( const CATUnicodeString & iusDownwardCompatibilityLevel ) ;
#ifdef CATIAR422
	  HRESULT SetSimulationMode(const CATBoolean iSimulMode);

	  HRESULT GetSimulationMode(CATBoolean & oSimulMode) const;

	  HRESULT GetExchangeChannelName(CATUnicodeString & ousExchangeChannelName) const;

	  HRESULT SetExchangeChannelName(const CATUnicodeString & iusExchangeChannelName);
#endif

#ifdef CATIAR424 //FUN118229 & FUN124806 
	  /**
	  * Get the PLMExchangeDwExecutionNode used for export reporting.
	  * <br><b>Role:</b>Read the replication engine data export reporting information.
	  *
	  * @param opExecution [out]
	  *  Execution node.
	  */
	  HRESULT GetPLMExchangeDwExecutionNode(PLMExchangeExecution *& opDwExecution) const;

	  /**
		* Set the PLMExchangeExecutionNode used for export reporting.
		* <br><b>Role:</b>Sets the execution node used for export reporting.
		*
		* @param ipDwExecution [in]
		*  Execution node.
		*/
	  HRESULT SetPLMExchangeDwExecutionNode(PLMExchangeExecution *& ipDwExecution);

	  /**
	 * Get the report information needed for downward report generation.
	 * <br><b>Role:</b>Get the report information needed for downward report generation.
	 *
	 * @param ousReportLocation [out]
	 *  the 
	 * @param ousReportName [out]
	 *  the
	 */
	  HRESULT GetReportInformationForDw(CATUnicodeString& ousReportLocation, CATUnicodeString& ousReportName, CATBoolean& obFromBatch) const;

	  /**
		* Set the report information needed for downward report generation.
		* <br><b>Role:</b>Set the report information needed for downward report generation.
		*
		* @param ipDwExecution [in]
		*  Execution node.
		*/
	  HRESULT SetReportInformationForDw(const CATUnicodeString& iusReportLocation, const CATUnicodeString& iusReportName, CATBoolean bFromBatch=CATFalse);
	  
#endif
     // FUN127642
     HRESULT SetExportControlJsonPath(const CATUnicodeString&);
     HRESULT GetExportControlJsonPath(CATUnicodeString&);

     // Browsing Structure Data : NS1 :Start
     /**
      * Set the Browsing Structure Data.
      * <br><b>Role:</b>Set flag selected data is browsing structure data.
      *
      * @param iBrowsingStructureData [in]
      *  Boolean value is True is selected data is browsing structure data.
      */
     HRESULT SetBrowsingStructureData(const CATBoolean iBrowsingStructureData);

     /**
       * Get the Browsing Structure Data flag.
       * <br><b>Role:</b>Get flag selected data is browsing structure data.
       *
       * @param oBrowsingStructureData [out]
       *  Boolean value is True is selected data is browsing structure data.
       */
     HRESULT GetBrowsingStructureData(CATBoolean & oBrowsingStructureData) const;
     // Browsing Structure Data : NS1 :End
   private:

      friend class CATPLMREExportAbstractTask ;

      CATPLMREBriefcaseExportOptions& operator=(const CATPLMREBriefcaseExportOptions &) ; // not implemented
      CATPLMREBriefcaseExportOptions( const CATPLMREBriefcaseExportOptions & ) ;          // not implemented

    /** Applicative ids for PLM components exported in the PLM briefcase. */ 
      CATString                      * _pExtendedExportLateType         ;

    /** Extended export information (reading the implementation of CATIPLMREBriefcaseExportExtend to be used if any). */ 
      CATIPLMREBriefcaseExportExtend * _pCATIPLMREBriefcaseExportExtend ;

    /** Briefcase header if allocated. */ 
      CATIPLMBriefcaseHeader    *      _pHeader                         ;

    /** List of components to be exported. */ 
      const CATLISTV(CATPLMID)  *      _pComponents                     ;

    /** Specify if a pre-release state is authorized. */ 
      CATBoolean                       _bAllowPreReleaseState           ;

    /** Access to Exchange report model. */ 
      PLMExchangeExecution      *      _pExecution                      ;

	  
    /** List of components to be waived at export. */ 
      const CATLISTV(CATPLMID)  *      _pComponentsToWaive              ;

    /** Access to current Briefcase. */ 
      PLMExchangeOption         *      _pBriefcase                      ;

    /** Downward compatibility level. */ 
      CATUnicodeString                 _usDownwardCompatibilityLevel    ;
#ifdef CATIAR422
	/** Specify if simulation mode is ON/OFF in Export mode */
	  CATBoolean                       _bIsSimulationMode;

	  /** Specify the name of exchange channel selected by user in Batch mode */
	  CATUnicodeString                      _exchangeChannel;
#endif
#ifdef CATIAR424 //FUN118229
	  CATUnicodeString _usReportLocation;
	  CATUnicodeString _usReportName;
	  CATBoolean _bDwFromBatch;

	  /** Access to downward Exchange report model. */
	  PLMExchangeExecution      *      _pDwExecution;
#endif
     // FUN127642
     CATUnicodeString      _usExportControlJsonPath;

     CATBoolean                       _bIsBrowsingStructureData        ;   // Browsing Structure Data : NS1 


} ;
#endif

