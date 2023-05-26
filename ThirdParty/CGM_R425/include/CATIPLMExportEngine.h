/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2008-2011

#ifndef CATIPLMExportEngine_H
#define CATIPLMExportEngine_H
/**
  * @level Protected
  * @usage U3
  */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATIAV5Level.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMExportEngine;
#else
extern "C" const IID IID_CATIPLMExportEngine ;
#endif

class CATUnicodeString    ;
class CATPLMTypeId        ;
class CATLISTV(CATPLMID)  ;
class CATIAdpErrorMonitor ;

enum  CATPLMExportSubType 
{
   CATPLMExportSubType_ForDesign
 , CATPLMExportSubType_ForReview
 , CATPLMExportSubType_ForChannel
 , CATPLMExportSubType_ForTransferSiteOwnership
 , CATPLMExportSubType_ForReviewV6
 , CATPLMExportSubType_ForDelegation
 , CATPLMExportSubType_ForRemove
};

typedef struct
{
   CATPLMTypeId     * type         ;
   CATUnicodeString * V_Discipline ;
   CATUnicodeString * option       ;
   CATUnicodeString * extension; // KSL filled in case of 'Resource' or 'PLMDELResTyping' extension.
} OptionChosenForType ;

struct OptionChosenForTypeList
{
   OptionChosenForType     * _current ;
   OptionChosenForTypeList * _next    ;
} ;


/**
  * This interface representing the Export Engine.
  * Use @href CATPLMEngineToolbox#GetExportEngine to get a pointer on the Export Engine.
  * @see CATPLMEnginesToolbox
  * <p>Globally, the user can:</p>
  * <ul>
  *   <li>Check if the export operation is available for a given object type.</li>
  *   <li>Retrieve the possible export options for a given object type.</li>
  *   <li>Perform a PLMID completion for export given an input PLMID list.</li>
  * </ul>
  */
class ExportedByCATPLMIntegrationInterfaces CATIPLMExportEngine : public CATBaseUnknown
{
   CATDeclareInterface ;

   public:

    /**
      * Checks if the ExportSubType is available for the type identified by its CATPLMTypeId and the V_Disipline.
      * @param iRequired
      *   Type of Export the system wants to process
      * @param iType
      *   PLMType we want to check
      * @param iV_Discipline
      *   V_Discipline of the PLMType we want to check.
      * @return
      *  An HRESULT value
      * <dl>
      *  <dt>S_OK</dt>     <dd>This Export is available for the PLMType + V_Discipline.</dd>
      *  <dt>S_FALSE</dt>  <dd>The Export is not available for the PLMType + V_Discipline.</dd>
      *  <dt>E_FAIL</dt>   <dd>There is an error : For example, the PLMType does not exist.</dd>
      * </dl>  
      */
      virtual HRESULT IsExportAvailableForType( const CATPLMExportSubType & iRequired
                                              , const CATPLMTypeId        & iType
                                              , const CATUnicodeString    & iV_Discipline ) = 0 ;

    /**
      * Retrieves the possible options for a type identified by its CATPLMTypeId and the V_Discipline given an ExportSubType.
      * @param iRequired
      *   Type of Export the system wants to process
      * @param iType
      *   PLMType we want to check
      * @param iV_Discipline
      *   V_Discipline of the PLMType we want to check.
      * @param oAdditionalOptions
      *   Additional options
      * @return
      *  An HRESULT value
      * <dl>
      *  <dt>S_OK</dt><dd>oAdditionalOptions is valuated (even with an empty list)</dd>
      *  <dt>E_FAIL</dt><dd>There is an error.</dd>
      * </dl>  
      */
      virtual HRESULT WhichOptionAvailableForExport( const CATPLMExportSubType & iRequired
                                                   , const CATPLMTypeId        & iType
                                                   , const CATUnicodeString    & iV_Discipline
                                                   , CATListOfCATUnicodeString & oAdditionalOptions ) = 0 ;

    /** 
      * Calls Completion service for Export scenarios.
      * <br><b>Role:</b> This method allows you to complete a set of PLM Components for Export purpose,
      * according to the specified Completion Procedure.
      * @param iRequired
      *   The  subType of the Export.
      * @param iOptions
      *   The  option for type, if this list contains more than 0 or one elements for the same type, the first option is used as no option combination are allowed for export completion.
      * @param iInputIDs
      *   The identifiers of the PLM Components to complete.
      * @param oOutputIDs
      *   The identifiers of the PLM Components after Completion.
      * @param ioErrorMonitor
      *   The error monitor.
      * @return
      *   <dl>
      *   <dt>S_OK</dt>         <dd>Completion successfull.</dd> 
      *   <dt>E_FAIL</dt>       <dd>Error during completion.</dd>
      *   <dt>E_INVALIDARG</dt> <dd>Input parameter are not correct.</dd>
      *  </dl>
      */
      virtual HRESULT CompletionForExport( const CATPLMExportSubType & iRequired
                                         , OptionChosenForTypeList   * iOptions
                                         , const CATLISTV(CATPLMID)  & iInputIDs
                                         , CATLISTV(CATPLMID)        & oOutputIDs
                                         , CATIAdpErrorMonitor       * ioErrorMonitor = NULL ) = 0 ;
 } ;

CATDeclareHandler( CATIPLMExportEngine , CATBaseUnknown ) ;

#endif
