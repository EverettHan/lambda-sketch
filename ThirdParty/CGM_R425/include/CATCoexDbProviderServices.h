/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/**
* @level Private
* @usage U1
*/
#ifndef CATCoexDbProviderServices_h
#define CATCoexDbProviderServices_h
//COPYRIGHT DASSAULT SYSTEMES 2011
#include "ExportedByCATDbProvider.h"
#include "IUnknown.h"

class CATUnicodeString;
class CATICoexDbProvider;
class CATICoexDbProviderUser;
class CATICoexDbProvider_var;
class CATICoexDbProviderUser_var;
//class CATIPLMBatchProvider_var;

class ExportedByCATDbProvider CATCoexDbProviderServices
{

public:
   /**
    * Create coexistence database provider
	* @param oCoexDbProvider [out]
    * The coexistence database provider.
    * @return S_OK
    *   successful.
    * @return E_FAIL
    *   failed.
    */  
	static HRESULT CreateCoexDbProvider(CATICoexDbProvider *&oCoexDbProvider);

   /**
    * Create coexistence database provider from another coexistence database provider.
	* @param iCoexDbProvider [in]
    * The coexistence database provider to be copied.
	* @param oCoexDbProvider [out]
    * The created coexistence database provider.
    * @return S_OK
    *   successful.
    * @return E_FAIL
    *   failed.
    */  
	static HRESULT CreateCoexDbProviderFromDbProvider(const CATICoexDbProvider_var &iCoexDbProvider,CATICoexDbProvider_var &oCoexDbProvider);

   /**
    * Create coexistence provider user
	* @param oCoexDbProvider [out]
    * The coexistence provider user.
    * @return S_OK
    *   successful.
    * @return E_FAIL
    *   failed.
    */  
	static HRESULT CreateCoexDbProviderUser(CATICoexDbProviderUser *&oCoexDbProviderUser);

   /**
    * Create coexistence provider user  from another coexistence provider user.
	* @param iCoexDbProvider [in]
    * The coexistence provider user to be copied.
	* @param oCoexDbProvider [out]
    * The created coexistence provider user.
    * @return S_OK
    *   successful.
    * @return E_FAIL
    *   failed.
    */  
	static HRESULT CreateCoexDbProviderUserFromDbProviderUser(const CATICoexDbProviderUser_var &iCoexDbProviderUser,CATICoexDbProviderUser_var &oCoexDbProviderUser);

    //static HRESULT GetListOfAllConnectors(CATListOfCATUnicodeString &oListOfAllConnectors);

	static HRESULT GetCoexDbProviderNumId(CATUnicodeString &iConnectorName, int &oProviderNumId);
	static HRESULT GetCoexDbProviderMaxNumId(int &oProviderMaxNumId);

	//static HRESULT LockUILogonAttributes(const CATUnicodeString &iProviderName,CATListOfCATUnicodeString &oFieldNames);

	//static HRESULT SetPLMBatchProviderData(const CATICoexDbProviderUser_var &iCoexDbProviderUser,const CATICoexDbProvider_var &iCoexDbProvider,CATIPLMBatchProvider_var &oPLMBatchProvider);

	//static HRESULT GetCoexDbProviderFromPLMBatchProvider(const CATIPLMBatchProvider_var &iPLMBatchProvider, CATICoexDbProvider_var &ioCoexDbProvider);

	//static HRESULT GetCoexDbProviderUserFromPLMBatchProvider(const CATIPLMBatchProvider_var &iPLMBatchProvider, CATICoexDbProviderUser_var &ioCoexDbProviderUser);
} ;
#endif
