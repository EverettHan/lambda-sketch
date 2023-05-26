#ifndef CATVBAApplication_h
#define CATVBAApplication_h

#include "VbaAfx.h"
#include "VBAIntegration.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATVBACodeMacro.h"

#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS

#ifndef _DS_VBAIntegrationIsOutProcess // -JBX 3.2012 VBA7 Migration 
#include "CATVBAApplicationBase.h"
#endif // _DS_PLATEFORME_64

class CWnd;
struct IDispatch;

#ifdef _DS_VBAIntegrationIsOutProcess // -JBX 3.2012 VBA7 Migration 
class CATIAVBAContainer;
class CATIAVBAHostingApplication;
class CATMessageFilterImpl;
extern "C" ExportedByVBAIntegration CATIAVBAHostingApplication * pCATIAVBAHostingApplication;
#endif // _DS_PLATEFORME_64

/**
 * Class which defines an MFC Application with VBA support.
 * The CApcApplication template class adds an ApcHost to the CWinApp MFC application.
 * This class is derived in Dialog to implement CATInteractiveApplication on NT.
 */

#ifndef _DS_VBAIntegrationIsOutProcess // -JBX 3.2012 VBA7 Migration 
class ExportedByVBAIntegration CATVBAApplication : public CATVBAApplicationBase {
#else // _DS_PLATEFORME_64
class ExportedByVBAIntegration CATVBAApplication {
#endif // _DS_PLATEFORME_64
	public:
		/**
		 * Constructor.
		 */
		CATVBAApplication();

		/**
		 * Destructor.
		 */
		~CATVBAApplication();

		/**
		 * Returns the VBA application singleton.
		 */
		static HRESULT SharedInstance(
			CATVBAApplication*& oVBAApplication);

		// Overwritten MFC methods.

		/**
		 * Checks and stores the parameters required for VBA initialization.
		 * The VBA application object must support all of VBA constraints (have a
		 * coclass, be dual, have the appobject IDL tag, support
		 * IProvideClassInfo2...). 
		 */
		BOOL InitInstance(
			IDispatch* iAppObject,
			CATUnicodeString& iAppName,
			CATUnicodeString& iTypelibName);

#ifdef _DS_VBAIntegrationIsOutProcess // -JBX 3.2012 VBA7 Migration 
		/**
		 * Shuts down VBA before quitting the application.
		 */
		int ExitInstance();

		// VBA - V5 event loop integration.
		/**
		 * Subclasses must call this method before executing their
		 * OnEnable event handler.
		 */
		HRESULT BeforeOnEnable(BOOL bEnable);

		/**
		 * Subclasses must call this method after executing their
		 * OnEnable event handler.
		 */
		HRESULT AfterOnEnable(BOOL bEnable);

		/**
		 * Subclasses must call this method before executing their
		 * OnClose event handler.
		 */
		HRESULT BeforeOnClose();

		/**
		 * Subclasses must call this method after executing their
		 * OnClose event handler.
		 */
		HRESULT AfterOnClose();

		/**
		 * Subclasses must call this method before executing their
		 * OnActivate event handler.
		 */
		HRESULT BeforeOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);

		/**
		 * Subclasses must call this method after executing their
		 * OnActivate event handler.
		 */
		HRESULT AfterOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);

		static HRESULT CreateContainer(
			const CString& iProjectPath,
			const CString& iRealPath,
			const CString& iProjectName,
			CArray<CString, CString&>& iTypeLibsPaths,
			CArray<ITypeLib *, ITypeLib *>& iTypeLibs,
                        CString * iContainerRef,
			CATIAVBAContainer*& oContainer);

		static HRESULT OpenContainer(
			const CString& iFilePath,
			const CString& iRealPath,
			const CString& iProjectName,
			CATBoolean iIsFileReadOnly,
                        CString * iContainerRef,
			CATIAVBAContainer*& oContainer);

		/**
		 * Returns TRUE if VBA is installed on the host and working,
		 * FALSE otherwise.
		 */
		static CATBoolean IsVBAEnabled();
		
		/**
		 * Returns TRUE if a VBA macro is running, FALSE otherwise.
		 */
		static CATBoolean IsRunning();
		
		/**
		 * Displays the VBA IDE.
		 */
		static HRESULT ShowIDE();

		/**
		 * Disables ot enables the VBA IDE.
		 * If iDisabled is VARIANT_TRUE, the VBA IDE will not appear. Normally, the VBA IDE will appear when: 
		 * 		- An untrapped run-time error is encountered.
		 * 		- A breakpoint or watch break is encountered.
		 * 		- The user presses CTRL+BREAK.		 
		 */
		static HRESULT DisableIDE(VARIANT_BOOL iDisabled);

		/**
		 * Insert the given text at the current selected position.
		 */
		static HRESULT InsertCode(const CString& iText);


                typedef HRESULT (*CallBackOnVBASavePtr)(const CString& iContainerRef,const CString& iRealPath);
                static HRESULT SetCallBackOnVBASave(CallBackOnVBASavePtr iCBOnVBASave64); 
                HRESULT InformContainerOnVBASave(const CString& iContainerRef,const CString& iRealPath) ;

                static HRESULT CloseVBAProjects();

#endif // _DS_PLATEFORME_64

	protected:

		/**
		 * Invoked by CATCallOnExit to clean-up static variables.
		 */
		static int _Cleanup (int iRc );

#ifndef _DS_VBAIntegrationIsOutProcess // -JBX 3.2012 VBA7 Migration 

		/**
		 * Activation of recording
		 */                
                static CATBoolean IsJournalingActivated() ;  

		/**
		 * Overriden _CustomizeVBE method 
		 */
		virtual HRESULT _CustomizeVBE(VBE * iVBE);

#endif // !_DS_PLATEFORME_64

#ifdef _DS_VBAIntegrationIsOutProcess // -JBX 3.2012 VBA7 Migration 
	private : 

		/**
		 * Retrieves the existing VBA hosting application or creates it if it does not exist.
		 */
		static HRESULT _GetOrCreateVBAHostingApplication(CATIAVBAHostingApplication *& oVBAHostingApplication);
	
		static CATIAVBAHostingApplication * _pCATIAVBAHostingApplication;
		static CATBoolean _creationAlreadyTried;
		static CATVBAApplication* _sharedInstance;
		static CATMessageFilterImpl * _messageFilter;

		CATUnicodeString _appName;
		CATUnicodeString _typelibName;
		CATBoolean _vbaEnabled;	// True if the application supports VBA, false otherwise.
                
                CallBackOnVBASavePtr _CallBackOnVBASave64;
#else
                static short         _IsJournalingActivated;
#endif // _DS_PLATEFORME_64

};

#else // VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS

#include "CATVBAApplicationBase.h"

class CWnd;
struct IDispatch;

#include "CATIAAppTypeLib.h"

/**
 * Class which defines an MFC Application with VBA support.
 * The CApcApplication template class adds an ApcHost to the CWinApp MFC application.
 * This class is derived in Dialog to implement CATInteractiveApplication on NT.
 */
class ExportedByVBAIntegration CATVBAApplication : public CATVBAApplicationBase {

	public:
		/**
		 * Constructor.
		 */
		CATVBAApplication();

		/**
		 * Destructor.
		 */
		virtual ~CATVBAApplication();

		/**
		 * Returns the VBA application singleton.
		 */
		static HRESULT SharedInstance(
			CATVBAApplication*& oVBAApplication);

		// Overwritten MFC methods.
        
        /**
		 * Checks and stores the parameters required for VBA initialization.
		 * The VBA application object must support all of VBA constraints (have a
		 * coclass, be dual, have the appobject IDL tag, support
		 * IProvideClassInfo2...). 
		 */
		 BOOL InitInstance(
			IDispatch* iAppObject,
			CATUnicodeString& iAppName,		
			CATUnicodeString& iTypelibName);
		/**
		 * Shuts down VBA before quitting the application.
		 */
		 int ExitInstance()  ;

		// VBA - V5 event loop integration.
		/**
		 * Subclasses must call this method before executing their
		 * OnEnable event handler.
		 */
		 HRESULT BeforeOnEnable(BOOL bEnable); 

		/**
		 * Subclasses must call this method after executing their
		 * OnEnable event handler.
		 */
		 HRESULT AfterOnEnable(BOOL bEnable);

		/**
		 * Subclasses must call this method before executing their
		 * OnClose event handler.
		 */
		 HRESULT BeforeOnClose();

		/**
		 * Subclasses must call this method after executing their
		 * OnClose event handler.
		 */
		 HRESULT AfterOnClose();

		/**
		 * Subclasses must call this method before executing their
		 * OnActivate event handler.
		 */
		 HRESULT BeforeOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
		
		/**
		 * Subclasses must call this method after executing their
		 * OnActivate event handler.
		 */
		 HRESULT AfterOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
         
         static HRESULT CreateContainer(
			const CString& iProjectPath,
			const CString& iRealPath,
			const CString& iProjectName,
			CArray<CString, CString&>& iTypeLibsPaths,
			CArray<ITypeLib *, ITypeLib *>& iTypeLibs,
			CString * iContainerRef,
			CATIAVBAContainer*& oContainer);

		static HRESULT OpenContainer(
			const CString& iFilePath,
			const CString& iRealPath,
			const CString& iProjectName,
			CATBoolean iIsFileReadOnly,
			CString * iContainerRef,
			CATIAVBAContainer*& oContainer);
			
		// Following commented static methods are now implemented in CATVBAApplicationBase
		/*
		static CATBoolean IsVBAEnabled();
		static CATBoolean IsRunning();
		static HRESULT ShowIDE();
		static HRESULT DisableIDE(VARIANT_BOOL iDisabled);
		static HRESULT InsertCode(const CString& iText);
		typedef HRESULT (*CallBackOnVBASavePtr)(const CString& iContainerRef,const CString& iRealPath);
		static HRESULT SetCallBackOnVBASave(CallBackOnVBASavePtr iCBOnVBASave64); 
		static HRESULT CloseVBAProjects();
		*/
        
        HRESULT InformContainerOnVBASave(const CString& iContainerRef,const CString& iRealPath) ;		

	protected:

		/**
		 * Invoked by CATCallOnExit to clean-up static variables.
		 */
		static int _Cleanup (int iRc );

		/**
		 * Activation of recording
		 */                
        static CATBoolean IsJournalingActivated() ;  

		/**
		 * Overriden _CustomizeVBE method 
		 */
		 virtual HRESULT _CustomizeVBE(VBE * iVBE);

		// Following 4 methods are used to implement static methods of CATVBAApplicationBase
		 virtual CATBoolean _IsRunning();
		 virtual HRESULT    _ShowIDE();
		 virtual HRESULT    _DisableIDE(VARIANT_BOOL iDisabled);
		 virtual HRESULT    _InsertCode(const CString& iText);
         virtual HRESULT    _CloseVBAProjects();
         
	private:
		
		/**
		 * Retrieves the existing VBA hosting application or creates it if it does not exist.
		 */
		static HRESULT _GetOrCreateVBAHostingApplication(CATIAVBAHostingApplication *& oVBAHostingApplication);
		
		//Data
		static CATIAVBAHostingApplication * _pCATIAVBAHostingApplication;
		static CATBoolean _creationAlreadyTried;
		
		CATUnicodeString _appName_UCS;
		CATUnicodeString _typelibName_UCS;
};
#endif

#endif // CATVBAApplication_h

