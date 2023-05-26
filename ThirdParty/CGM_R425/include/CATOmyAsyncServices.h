// COPYRIGHT Dassault Systemes 2005
//===================================================================
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyAsyncServices_H
#define CATOmyAsyncServices_H

#include "CATOmyAsyncInterfaces.h"

#include "CATListOfCATOmyCioUrlUsageCtx.h"
#include "CATAsyncBasicTypes.h"

#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATOmyAsyncProcessConstants.h"

class CATBinary;
class CATOmyPLMQLAsyncCallBackNotifier;
class CATIOmyAsyncResult;
class CATOmyVVSAsyncCallBackNotifier;
class CATIOmyAsyncTaskCompletionCallBack;
class CATOmxKeyValueBlock;
class CATIOmxBinaryStream;
class CATIOmyPowerIOMPGenericTransactionMsg;

//
// Services for MP asynchronism
//
class ExportedByCATOmyAsyncInterfaces CATOmyAsyncServices
{
  public:
 
    /**
  * Try to execute an async generic Transaction
  * @param iBinStream [in]
  *	The content query that will be executed async process side
  * @param iCallBack [in]
  *	The CallBack for the results. 
  * @param oAsyncResult[out]
  *	The async result for getting the processing status.
  */
   HRESULT ExecuteAsyncGenericTransaction(CATIOmyPowerIOMPGenericTransactionMsg * iGenericTransaction, CATOmyPLMQLAsyncCallBackNotifier* ipCallBack, CATIOmyAsyncResult  *& oppAsyncResult);

    /**
    * Try to execute an async PLMQL Transaction
	* @param iXMLMessage [in]
	*	The XML query filter.
	* @param iBinConn [in]
	*	The Connection binary 
	* @param iRepName [in]
	*	The repository name. 
	* @param iCallBack [in]
	*	The CallBack for the results. 
	* @param oAsyncResult[out]
	*	The async result for getting the processing status.
	*/
   HRESULT ExecuteAsyncPLMQLTransaction(CATUnicodeString &iXMLMessage,CATOmyPLMQLAsyncCallBackNotifier* iCallBack,CATIOmyAsyncResult  ** oAsyncResult);

    /**
    * Try to execute an async OpenConnection
	* @param iSelection [in]
	*	The list of urls to download.
	* @param iBinConn [in]
	*	The Connection binary 
	* @param iRepName [in]
	*	The repository name. 
	* @param iCallBack [in]
	*	The CallBack for the results. 
	* @param oAsyncResult[out]
	*	The async result for getting the processing status.
	*/
   HRESULT OpenConnections(const CATOmxList<CATOmyCioUrlUsageCtx>& iSelection,CATOmyVVSAsyncCallBackNotifier* iLoadAsyncCallback, CATIOmyAsyncResult  ** oAsyncResult );
   HRESULT OpenConnections(const CATListOfCATOmyCioUrlUsageCtx& iSelection,CATOmyVVSAsyncCallBackNotifier* iLoadAsyncCallback, CATIOmyAsyncResult  ** oAsyncResult );
   
   /**
   * Checks if we are working in the master master or a CATAsyncProcess
   * Should not be called directly. Use instead macro CATOMY_ASYNC_MASTER
   */
   static CATBoolean IsAsyncMaster();

  /** 
  * Current implementation : Kill all connected processes
  * @return S_OK : all processes have been killed
  *         S_FALSE : no process to be killed
  *         E*      : platform has not been able to confirm all processes are dead
  */
   HRESULT DisconnectAuxilliaryProcess(const char* iRepName) const;
   
   /** DO NOT USE platform internals **/
   HRESULT ConnectAuxilliaryProcess(CATBinary* iBinConn, const char* iRepName, const char* iCookieUrl, const char* iCookieContent);  

   //does nothing if cookies didn't change
   HRESULT ReconnectAuxilliaryProcess(CATBinary* iBinConn, const char* iRepName, const char* iCookieUrl, const char* iCookieContent);
   
   /** DO NOT USE platform internals **/
   HRESULT UpdateConnectionParameters(const CATBinary& iBufConn, const char* iRepositoryName, const char* iCookieUrl, const char* iCookieContent);
      
   CATOmyAsyncServices();
   ~CATOmyAsyncServices();

private :	
	
};

#endif


