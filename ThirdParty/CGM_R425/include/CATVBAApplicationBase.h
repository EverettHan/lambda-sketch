#ifndef CATVBAApplicationBase_h
#define CATVBAApplicationBase_h

// VBA Framework
#include "VbaAfx.h"
#include "CATVBAInfra.h"
#include "VBAMenuItemHandler.h"

// System Framework
#include "CATBoolean.h"

class CWnd;
struct IDispatch;
class CATIVBAContainer;

/**
 * Class which defines an MFC Application with VBA support.
 * The CApcApplication template class adds an ApcHost to the CWinApp MFC application.
 * This class is derived in Dialog to implement CATInteractiveApplication on NT.
 */
#pragma warning( push )
#pragma warning( disable : 4275 )
class ExportedByCATVBAInfra CATVBAApplicationBase : public CApcApplication<CATVBAApplicationBase, CWinApp>
{
	public:
		/**
		 * Constructor.
		 */
		CATVBAApplicationBase();

		/**
		 * Destructor.
		 */
		~CATVBAApplicationBase();

		/**
		 * Returns the VBA application singleton.
		 */
		static HRESULT SharedInstance(
			CATVBAApplicationBase*& oVBAApplication);

		// Overwritten MFC methods.

		/**
		 * Checks and stores the parameters required for VBA initialization.
		 * The VBA application object must support all of VBA constraints (have a
		 * coclass, be dual, have the appobject IDL tag, support
		 * IProvideClassInfo2...). 
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
		BOOL InitInstance(
#else
		BOOL _InitInstance(
#endif
			IDispatch* iAppObject,
			const CString& iAppName,
			const CString& iTypelibPath,
			ITypeLib * iTypelib,
			HWND hWnd = NULL);

		/**
		 * Shuts down VBA before quitting the application.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
        int ExitInstance();
#else
        int _ExitInstance();
#endif         		

		// VBA - V5 event loop integration.
		/**
		 * Subclasses must call this method before executing their
		 * OnEnable event handler.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
        HRESULT BeforeOnEnable(BOOL bEnable);
#else
        HRESULT _BeforeOnEnable(BOOL bEnable);
#endif         		

		/**
		 * Subclasses must call this method after executing their
		 * OnEnable event handler.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
        HRESULT AfterOnEnable(BOOL bEnable);
#else
        HRESULT _AfterOnEnable(BOOL bEnable);
#endif         
		

		/**
		 * Subclasses must call this method before executing their
		 * OnClose event handler.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
        HRESULT BeforeOnClose();
#else
        HRESULT _BeforeOnClose();
#endif         		

		/**
		 * Subclasses must call this method after executing their
		 * OnClose event handler.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
		HRESULT AfterOnClose();
#else
		HRESULT _AfterOnClose();
#endif         

		/**
		 * Subclasses must call this method before executing their
		 * OnActivate event handler.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
		HRESULT BeforeOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
#else
		HRESULT _BeforeOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
#endif         

		/**
		 * Subclasses must call this method after executing their
		 * OnActivate event handler.
		 */
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
        HRESULT AfterOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
#else
        HRESULT _AfterOnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
#endif
		
		/**
		 * Subclasses must call this method after executing their
		 * Run event handler.
		 */
		HRESULT ApcHost_BeforeRun();
		
		/**
		 * Subclasses must call this method after executing their
		 * Run event handler.
		 */
		HRESULT ApcHost_AfterRun();

		static HRESULT CreateContainer(
			const CString& iProjectPath,
			const CString& iRealPath,
			const CString& iProjectName,
			CArray<CString, CString&>& iTypeLibsPaths,
			CArray<ITypeLib *, ITypeLib *>& iTypeLibs,
                        CString * iContainerRef,
			CATIVBAContainer*& oContainer);

		static HRESULT OpenContainer(
			const CString& iFilePath,
			const CString& iRealPath,
			const CString& iProjectName,
			CATBoolean iIsFileReadOnly,
			CString * iContainerRef,
			CATIVBAContainer*& oContainer);

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
		 * Returns the VBA IDE. All code to get access to the VBA
		 * IDE should always go through this function since it
		 * customizes the VBA IDE to add the "Macro libraries..."
		 * menu item.
		 */
		static HRESULT GetIDE(
			IApcIde *&oIde);

		/**
		 * Returns the VBE. All code to get access to VBE
		 * should always go through this function since it
		 * customizes the VBA IDE to add the "Macro libraries..."
		 * menu item.
		 */
		static HRESULT GetVBE(
			VBE *&oVBE);

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
                static HRESULT SetCallBackOnVBASave(CallBackOnVBASavePtr iCBOnVBASave32); 
		
#ifndef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
        HRESULT InformContainerOnVBASave(const CString& iContainerRef,const CString& iRealPath) ;
#else
		HRESULT _InformContainerOnVBASave(const CString& iContainerRef,const CString& iRealPath) ;
#endif         

                static HRESULT CloseVBAProjects();  

	protected:
	
		virtual HRESULT _CustomizeVBE(VBE * iVBE);
		
        /**
         * _RunHandler allows to define a custom action for the following events:
         *  + ApcHost_BeforeRun (iMode = 0)
         *  + ApcHost_AfterRun  (iMode = 1)
         * NOTE: virtuality is required for CATVBAHostingApplication
         */
        virtual HRESULT _RunHandler(short iMode);

#ifdef VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS
		// The following four methods are overloaded in CATVBAApplication to manage OutProcess
		virtual CATBoolean _IsRunning();
		virtual HRESULT    _ShowIDE();
		virtual HRESULT    _InsertCode(const CString& iText);
		virtual HRESULT    _DisableIDE(VARIANT_BOOL iDisabled);
        virtual HRESULT    _CloseVBAProjects();
#endif

		static CATVBAApplicationBase* _sharedInstance;
		static VBAMenuItemHandler *_handlerLibraries;
		static VBAMenuItemHandler *_handlerResolution;

		CATBoolean _vbaEnabled;	// True if the application supports VBA, false otherwise.
		CATBoolean _initialized;
		IDispatch* _appObject;
		CString _appName;
		HWND _hWnd;
        CallBackOnVBASavePtr _CallBackOnVBASave32;


		static HRESULT _CreateVBAMenuItem(
			VBE *iVbe,
			const CString& iMenuName,
			int iPositionalIndex,
			const CString& iCaption,
			const CString& iDescription,
			const CString& iToolTip,
			Office::CommandBarButton*& oItem);
		static HRESULT _WireVBAMenuItemEvents(
			VBE *iVbe,
			Office::CommandBarButton* iItem,
			VBAMenuItemHandler::VBAMenuItemHandlerCallback iCallback,
			VBAMenuItemHandler*& oHandler);
		static HRESULT _DestroyVBAMenuItem(
			VBE *iVbe,const CString& iMenuName);				

	private:
		static CATBoolean _vbeIsCustomized;

		/**
		 * Initializes VBA.
		 */
		HRESULT _Init();

};
#pragma warning( pop )

#endif
