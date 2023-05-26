#ifndef CATIASystemServiceImpl_h
#define CATIASystemServiceImpl_h

// COPYRIGHT DASSAULT SYSTEMES 1997

#include "CATBaseObject.h"
#include "JS0INF.h"
#include "CATBSTR.h"
#include "CATVariant.h"
#include "CATSafeArray.h"
#include "CatScriptLibraryType.h"
#include "CATScriptLanguage.h"

/**
 * Class to implement the CATIASystemService interface
 */
class ExportedByJS0INF CATIASystemServiceImpl : public CATBaseObject {
   CATDeclareClass;

   public:
	   // Implementation of the CATIASystemService interface
		virtual HRESULT  __stdcall Environ(
			const CATBSTR & iEnvString, 
			CATBSTR & oValue);
		virtual HRESULT  __stdcall Print(
			const CATBSTR & iVariable);
		virtual HRESULT __stdcall ExecuteProcessus( 
			const  CATBSTR & iExecPath,
			CATLONG & ValRet );
		virtual HRESULT __stdcall ExecuteBackgroundProcessus( 
			const  CATBSTR & iExecPath, 
			CATLONG & ValRet );
		virtual HRESULT __stdcall ExecuteScript(
			const CATBSTR & iLibraryName, 
			CatScriptLibraryType iType, 
			const CATBSTR & iProgramName, 
			const CATBSTR & iFunctionName, 
			const CATSafeArrayVariant & iParameters, 
			CATVariant & oResult);
		virtual HRESULT __stdcall Evaluate(
			const CATBSTR & iScriptText, 
			CATScriptLanguage iLanguage, 
			const CATBSTR & iFunctionName, 
			const CATSafeArrayVariant & iParameters, 
			CATVariant & oResult);		
		virtual HRESULT  __stdcall PrintToStdout(
			const CATBSTR & iVariable);
		virtual HRESULT __stdcall GetMessage(
			const CATBSTR & iCatalogName,
			const CATBSTR & iMessageKey,
			const CATSafeArrayVariant & iMsgParameters,
			const CATBSTR & iDefaultMsg,
			CATBSTR & oMessage);
			
		/**
		 * Constructor
		 */
		CATIASystemServiceImpl();
 		/**
		 * Destructor
		 */
		virtual ~CATIASystemServiceImpl();
   private:
	   /**
	    * Actual implementation of the ExecuteProcessus and ExecuteBackgroundProcessus
		* functions.
		*/
	   HRESULT _Execute(
		   const  CATBSTR & iExecPath, 
		   CATLONG & ValRet, 
		   int wait);
};

#endif //CATIASystemServiceImpl_h
