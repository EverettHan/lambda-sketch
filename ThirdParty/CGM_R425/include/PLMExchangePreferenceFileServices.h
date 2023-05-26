//===================================================================
// COPYRIGHT Dassault Systemes 2012-2015
//===================================================================

#ifndef PLMExchangePreferenceFileServices_H
#define PLMExchangePreferenceFileServices_H

#include "ExportedByPLMExchangeFileServices.h"
//CATPLMIdentificationAccess
#include "CATIPLMComponent.h"                  // CATPLMIdentificationAccess.m
// PLMExchangeServices
//#include "CATPLMSRMExchangeSpaceServices.h"  // PLMExchangeSpaceAPI.m
//System
#include "CATListOfCATUnicodeString.h"         // CO0LSTST.m

// -- Forward declaration
class CATUnicodeString                     ;

//enum ExchangeModeType;
#ifndef EXCHANGE_MODE_TYPE
#define EXCHANGE_MODE_TYPE
enum ExchangeModeType{ None = -1, FileExchange , ProjectSpace, TeamWorkspace }; 
#endif

/**
  * Class representing services to manage a Preference file exchanges.
  */
class ExportedByPLMExchangeFileServices PLMExchangePreferenceFileServices
{
   public:

    /**
      * Method to read the exchange space names from the preference file.
      * @param iCurrentExchangeMode[in]
      *   current exchange mode, File Exchanges, Project Space, Team Workspace.
      * @param oppExchangeSpaceNames[out]
      *   List of the names of the exchange spaces read from the preference file. 
      * @param oCntofExchangeSpaces[out]
      *   the count of exchange space names in the preference file.
      * @param ousExportFolderName[out]
      *   folder name in the prefernce file.
      * @return
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>in case of success.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      static HRESULT ReadPreferenceFile( ExchangeModeType      iCurrentExchangeMode
                                       , CATUnicodeString ** & oppExchangeSpaceNames
                                       , int                 & oCntofExchangeSpaces
                                       , CATUnicodeString    & ousExportFolderName ) ;
    /**
      * Method to save the exchange space names from the preference file.
      * @param iCurrentExchangeMode[in]
      * current exchange mode, File Exchanges, Project Space, Team Workspace.
      * @param iListOfSelectedExchangeSpaceNames[in]
      * List of the names of the exchange spaces to be saved to preference file. 
      * @param iusExportFolderName[out]
      * folder name to be saved to prefernce file.
      * @return
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>in case of success.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      static HRESULT SaveToPreferenceFile( ExchangeModeType            iCurrentExchangeMode
                                         , CATListOfCATUnicodeString & iListOfSelectedExchangeSpaceNames
                                         , CATUnicodeString          & iusExportFolderName ) ;
} ;
#endif
