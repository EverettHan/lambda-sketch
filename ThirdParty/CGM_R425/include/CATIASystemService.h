#ifndef CATIASystemService_h
#define CATIASystemService_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0INF.h"
#include "CATBSTR.h"
#include "CATBaseDispatch.h"
#include "CATIABase.h"
#include "CATVariant.h"
#include "CATSafeArray.h"
#include "CatScriptLibraryType.h"
#include "CATScriptLanguage.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0INF IID IID_CATIASystemService;
#else // LOCAL_DEFINITION_FOR_IID
extern "C" const IID IID_CATIASystemService;
#endif // LOCAL_DEFINITION_FOR_IID

class ExportedByJS0INF CATIASystemService: public CATIABase {
	CATDeclareInterface;
	
	public:
		/**
		 * Get the value of a environment variable
		 */
		virtual HRESULT  __stdcall Environ(
			const CATBSTR & iEnvString,
			CATBSTR & oValue)=0;

		/**
		 * @deprecated V6R2013
		 * Use  @href CATIASystemService#PrintToStdout instead.
	     * <br><b>Precondition</b>: Print is a reserved keyword of VBA then this method cannot be used in a VBA macro.
		 * Print the value of a variable on stdout.		 
		 */
		virtual HRESULT  __stdcall Print(
			const CATBSTR & iVariable)=0;

		/**
		 * Execute a process and wait for it to return
		 */
		virtual HRESULT  __stdcall ExecuteProcessus(
			const CATBSTR & iExecutablePath,
			CATLONG & oReturnCode)=0;

		/**
		 * Execute a process and doesn't wait for it to return
		 */
		virtual HRESULT  __stdcall ExecuteBackgroundProcessus(
			const CATBSTR & iExecutablePath,
			CATLONG & oReturnCode)=0;

		/**
		 * Execute a script
		 */
		virtual HRESULT __stdcall ExecuteScript(
			const CATBSTR & iLibraryName, 
			CatScriptLibraryType iType, 
			const CATBSTR & iProgramName, 
			const CATBSTR & iFunctionName, 
			const CATSafeArrayVariant & iParameters, 
			CATVariant & oResult)=0;

		/**
		 * Execute a script in memory
		 */
		virtual HRESULT __stdcall Evaluate(
			const CATBSTR & iScriptText, 
			CATScriptLanguage iLanguage, 
			const CATBSTR & iFunctionName, 
			const CATSafeArrayVariant & iParameters, 
			CATVariant & oResult)=0;
			
		/**
		 * Print the value of a variable on stdout
		 */
		virtual HRESULT __stdcall PrintToStdout(
			const CATBSTR & iVariable)=0;
			
		/**
		 * Computes a message string 
		 */
		virtual HRESULT __stdcall GetMessage(
			const CATBSTR & iCatalogName,
			const CATBSTR & iMessageKey,
			const CATSafeArrayVariant & iMsgParameters,
			const CATBSTR & iDefaultMsg,
			CATBSTR & oMessage)=0;
};
CATDeclareHandler(CATIASystemService,CATIABase);

#endif // CATIASystemService_h
