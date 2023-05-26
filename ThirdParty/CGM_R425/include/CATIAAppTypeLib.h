

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Feb 18 11:57:03 2011
 */
/* Compiler settings for CATIAAppTypeLib.midl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CATIAAppTypeLib_h__
#define __CATIAAppTypeLib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CATIAVBAHostingApplication_FWD_DEFINED__
#define __CATIAVBAHostingApplication_FWD_DEFINED__
typedef interface CATIAVBAHostingApplication CATIAVBAHostingApplication;
#endif 	/* __CATIAVBAHostingApplication_FWD_DEFINED__ */


#ifndef ___CATIAApp_FWD_DEFINED__
#define ___CATIAApp_FWD_DEFINED__
typedef interface _CATIAApp _CATIAApp;
#endif 	/* ___CATIAApp_FWD_DEFINED__ */


#ifndef __CATIAVBAProgram_FWD_DEFINED__
#define __CATIAVBAProgram_FWD_DEFINED__
typedef interface CATIAVBAProgram CATIAVBAProgram;
#endif 	/* __CATIAVBAProgram_FWD_DEFINED__ */


#ifndef __CATIAVBAForm_FWD_DEFINED__
#define __CATIAVBAForm_FWD_DEFINED__
typedef interface CATIAVBAForm CATIAVBAForm;
#endif 	/* __CATIAVBAForm_FWD_DEFINED__ */


#ifndef __CATIAVBAContainer_FWD_DEFINED__
#define __CATIAVBAContainer_FWD_DEFINED__
typedef interface CATIAVBAContainer CATIAVBAContainer;
#endif 	/* __CATIAVBAContainer_FWD_DEFINED__ */


#ifndef __CATIAHostCallback_FWD_DEFINED__
#define __CATIAHostCallback_FWD_DEFINED__
typedef interface CATIAHostCallback CATIAHostCallback;
#endif 	/* __CATIAHostCallback_FWD_DEFINED__ */


#ifndef __IVstaIntegration_FWD_DEFINED__
#define __IVstaIntegration_FWD_DEFINED__
typedef interface IVstaIntegration IVstaIntegration;
#endif 	/* __IVstaIntegration_FWD_DEFINED__ */


#ifndef __CATIAAppObj_FWD_DEFINED__
#define __CATIAAppObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class CATIAAppObj CATIAAppObj;
#else
typedef struct CATIAAppObj CATIAAppObj;
#endif /* __cplusplus */

#endif 	/* __CATIAAppObj_FWD_DEFINED__ */


#ifndef __CATIAVBAHostingApplicationImpl_FWD_DEFINED__
#define __CATIAVBAHostingApplicationImpl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CATIAVBAHostingApplicationImpl CATIAVBAHostingApplicationImpl;
#else
typedef struct CATIAVBAHostingApplicationImpl CATIAVBAHostingApplicationImpl;
#endif /* __cplusplus */

#endif 	/* __CATIAVBAHostingApplicationImpl_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __CATIA_APP_ITF_LIBRARY_DEFINED__
#define __CATIA_APP_ITF_LIBRARY_DEFINED__

/* library CATIA_APP_ITF */
/* [helpstring][hidden][version][uuid] */ 



typedef /* [public] */ CATIAVBAHostingApplication _CATIAVBAHostingApplication;

typedef /* [public] */ _CATIAApp CATIAApp;


EXTERN_C const IID LIBID_CATIA_APP_ITF;

#ifndef __CATIAVBAHostingApplication_INTERFACE_DEFINED__
#define __CATIAVBAHostingApplication_INTERFACE_DEFINED__

/* interface CATIAVBAHostingApplication */
/* [uuid][unique][dual][object] */ 


EXTERN_C const IID IID_CATIAVBAHostingApplication;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0663D094-471D-11D2-9AA3-00A024941EF0")
    CATIAVBAHostingApplication : public IDispatch
    {
    public:
        virtual HRESULT __stdcall InitInstance( 
            /* [in] */ IDispatch *iAppObject,
            /* [in] */ CATIAHostCallback *iHostCallack,
            /* [in] */ BSTR iAppName,
            /* [in] */ BSTR iTypelibPath,
            /* [in] */ ULONG64 iHostWindow) = 0;
        
        virtual /* [propget] */ HRESULT __stdcall get_Running( 
            /* [retval][out] */ VARIANT_BOOL *oIsRunning) = 0;
        
        virtual HRESULT __stdcall WmEnable( 
            /* [in] */ VARIANT_BOOL iEnabled) = 0;
        
        virtual HRESULT __stdcall WmActivate( 
            /* [in] */ WPARAM iWParam) = 0;
        
        virtual HRESULT __stdcall ShowIDE( void) = 0;
        
        virtual HRESULT __stdcall DisableIDE( 
            /* [in] */ VARIANT_BOOL iDisabled) = 0;
        
        virtual HRESULT __stdcall InsertCode( 
            /* [in] */ BSTR iText) = 0;
        
        virtual HRESULT __stdcall CreateContainer( 
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ BSTR iProjectName,
            /* [in] */ SAFEARRAY * iTypeLibsPaths,
            /* [retval][out] */ CATIAVBAContainer **oContainer) = 0;
        
        virtual HRESULT __stdcall OpenContainer( 
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ VARIANT_BOOL iIsFileReadOnly,
            /* [retval][out] */ CATIAVBAContainer **oContainer) = 0;
        
        virtual HRESULT __stdcall Quit( void) = 0;
        
        virtual HRESULT __stdcall IsAlive( void) = 0;
        
        virtual HRESULT __stdcall CreateContainerNew( 
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ BSTR iProjectName,
            /* [in] */ BSTR iContainerRef,
            /* [in] */ SAFEARRAY * iTypeLibsPaths,
            /* [retval][out] */ CATIAVBAContainer **oContainer) = 0;
        
        virtual HRESULT __stdcall OpenContainerNew( 
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ BSTR iProjectName,
            /* [in] */ BSTR iContainerRef,
            /* [in] */ VARIANT_BOOL iIsFileReadOnly,
            /* [retval][out] */ CATIAVBAContainer **oContainer) = 0;
        
        virtual HRESULT __stdcall CloseVBAProjects( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct CATIAVBAHostingApplicationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            CATIAVBAHostingApplication * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            CATIAVBAHostingApplication * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CATIAVBAHostingApplication * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( __stdcall *InitInstance )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ IDispatch *iAppObject,
            /* [in] */ CATIAHostCallback *iHostCallack,
            /* [in] */ BSTR iAppName,
            /* [in] */ BSTR iTypelibPath,
            /* [in] */ ULONG64 iHostWindow);
        
        /* [propget] */ HRESULT ( __stdcall *get_Running )( 
            CATIAVBAHostingApplication * This,
            /* [retval][out] */ VARIANT_BOOL *oIsRunning);
        
        HRESULT ( __stdcall *WmEnable )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ VARIANT_BOOL iEnabled);
        
        HRESULT ( __stdcall *WmActivate )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ WPARAM iWParam);
        
        HRESULT ( __stdcall *ShowIDE )( 
            CATIAVBAHostingApplication * This);
        
        HRESULT ( __stdcall *DisableIDE )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ VARIANT_BOOL iDisabled);
        
        HRESULT ( __stdcall *InsertCode )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ BSTR iText);
        
        HRESULT ( __stdcall *CreateContainer )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ BSTR iProjectName,
            /* [in] */ SAFEARRAY * iTypeLibsPaths,
            /* [retval][out] */ CATIAVBAContainer **oContainer);
        
        HRESULT ( __stdcall *OpenContainer )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ VARIANT_BOOL iIsFileReadOnly,
            /* [retval][out] */ CATIAVBAContainer **oContainer);
        
        HRESULT ( __stdcall *Quit )( 
            CATIAVBAHostingApplication * This);
        
        HRESULT ( __stdcall *IsAlive )( 
            CATIAVBAHostingApplication * This);
        
        HRESULT ( __stdcall *CreateContainerNew )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ BSTR iProjectName,
            /* [in] */ BSTR iContainerRef,
            /* [in] */ SAFEARRAY * iTypeLibsPaths,
            /* [retval][out] */ CATIAVBAContainer **oContainer);
        
        HRESULT ( __stdcall *OpenContainerNew )( 
            CATIAVBAHostingApplication * This,
            /* [in] */ BSTR iProjectPath,
            /* [in] */ BSTR iRealPath,
            /* [in] */ BSTR iProjectName,
            /* [in] */ BSTR iContainerRef,
            /* [in] */ VARIANT_BOOL iIsFileReadOnly,
            /* [retval][out] */ CATIAVBAContainer **oContainer);
        
        HRESULT ( __stdcall *CloseVBAProjects )( 
            CATIAVBAHostingApplication * This);
        
        END_INTERFACE
    } CATIAVBAHostingApplicationVtbl;

    interface CATIAVBAHostingApplication
    {
        CONST_VTBL struct CATIAVBAHostingApplicationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CATIAVBAHostingApplication_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define CATIAVBAHostingApplication_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define CATIAVBAHostingApplication_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define CATIAVBAHostingApplication_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define CATIAVBAHostingApplication_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define CATIAVBAHostingApplication_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define CATIAVBAHostingApplication_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define CATIAVBAHostingApplication_InitInstance(This,iAppObject,iHostCallack,iAppName,iTypelibPath,iHostWindow)	\
    ( (This)->lpVtbl -> InitInstance(This,iAppObject,iHostCallack,iAppName,iTypelibPath,iHostWindow) ) 

#define CATIAVBAHostingApplication_get_Running(This,oIsRunning)	\
    ( (This)->lpVtbl -> get_Running(This,oIsRunning) ) 

#define CATIAVBAHostingApplication_WmEnable(This,iEnabled)	\
    ( (This)->lpVtbl -> WmEnable(This,iEnabled) ) 

#define CATIAVBAHostingApplication_WmActivate(This,iWParam)	\
    ( (This)->lpVtbl -> WmActivate(This,iWParam) ) 

#define CATIAVBAHostingApplication_ShowIDE(This)	\
    ( (This)->lpVtbl -> ShowIDE(This) ) 

#define CATIAVBAHostingApplication_DisableIDE(This,iDisabled)	\
    ( (This)->lpVtbl -> DisableIDE(This,iDisabled) ) 

#define CATIAVBAHostingApplication_InsertCode(This,iText)	\
    ( (This)->lpVtbl -> InsertCode(This,iText) ) 

#define CATIAVBAHostingApplication_CreateContainer(This,iProjectPath,iRealPath,iProjectName,iTypeLibsPaths,oContainer)	\
    ( (This)->lpVtbl -> CreateContainer(This,iProjectPath,iRealPath,iProjectName,iTypeLibsPaths,oContainer) ) 

#define CATIAVBAHostingApplication_OpenContainer(This,iProjectPath,iRealPath,iIsFileReadOnly,oContainer)	\
    ( (This)->lpVtbl -> OpenContainer(This,iProjectPath,iRealPath,iIsFileReadOnly,oContainer) ) 

#define CATIAVBAHostingApplication_Quit(This)	\
    ( (This)->lpVtbl -> Quit(This) ) 

#define CATIAVBAHostingApplication_IsAlive(This)	\
    ( (This)->lpVtbl -> IsAlive(This) ) 

#define CATIAVBAHostingApplication_CreateContainerNew(This,iProjectPath,iRealPath,iProjectName,iContainerRef,iTypeLibsPaths,oContainer)	\
    ( (This)->lpVtbl -> CreateContainerNew(This,iProjectPath,iRealPath,iProjectName,iContainerRef,iTypeLibsPaths,oContainer) ) 

#define CATIAVBAHostingApplication_OpenContainerNew(This,iProjectPath,iRealPath,iProjectName,iContainerRef,iIsFileReadOnly,oContainer)	\
    ( (This)->lpVtbl -> OpenContainerNew(This,iProjectPath,iRealPath,iProjectName,iContainerRef,iIsFileReadOnly,oContainer) ) 

#define CATIAVBAHostingApplication_CloseVBAProjects(This)	\
    ( (This)->lpVtbl -> CloseVBAProjects(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __CATIAVBAHostingApplication_INTERFACE_DEFINED__ */


#ifndef ___CATIAApp_INTERFACE_DEFINED__
#define ___CATIAApp_INTERFACE_DEFINED__

/* interface _CATIAApp */
/* [uuid][unique][dual][object] */ 


EXTERN_C const IID IID__CATIAApp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("621052be-f2a9-11d4-a3aa-00d0b756ad5d")
    _CATIAApp : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT __stdcall get_CATIA( 
            /* [retval][out] */ /* external definition not present */ Application **oApplication) = 0;
        
        virtual /* [propget] */ HRESULT __stdcall get_DELMIA( 
            /* [retval][out] */ /* external definition not present */ Application **oApplication) = 0;
        
        virtual /* [propget] */ HRESULT __stdcall get_DMU( 
            /* [retval][out] */ /* external definition not present */ Application **oApplication) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _CATIAAppVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _CATIAApp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _CATIAApp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _CATIAApp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _CATIAApp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _CATIAApp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _CATIAApp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _CATIAApp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget] */ HRESULT ( __stdcall *get_CATIA )( 
            _CATIAApp * This,
            /* [retval][out] */ /* external definition not present */ Application **oApplication);
        
        /* [propget] */ HRESULT ( __stdcall *get_DELMIA )( 
            _CATIAApp * This,
            /* [retval][out] */ /* external definition not present */ Application **oApplication);
        
        /* [propget] */ HRESULT ( __stdcall *get_DMU )( 
            _CATIAApp * This,
            /* [retval][out] */ /* external definition not present */ Application **oApplication);
        
        END_INTERFACE
    } _CATIAAppVtbl;

    interface _CATIAApp
    {
        CONST_VTBL struct _CATIAAppVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _CATIAApp_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _CATIAApp_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _CATIAApp_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _CATIAApp_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _CATIAApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _CATIAApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _CATIAApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _CATIAApp_get_CATIA(This,oApplication)	\
    ( (This)->lpVtbl -> get_CATIA(This,oApplication) ) 

#define _CATIAApp_get_DELMIA(This,oApplication)	\
    ( (This)->lpVtbl -> get_DELMIA(This,oApplication) ) 

#define _CATIAApp_get_DMU(This,oApplication)	\
    ( (This)->lpVtbl -> get_DMU(This,oApplication) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___CATIAApp_INTERFACE_DEFINED__ */


#ifndef __CATIAVBAProgram_INTERFACE_DEFINED__
#define __CATIAVBAProgram_INTERFACE_DEFINED__

/* interface CATIAVBAProgram */
/* [uuid][unique][dual][object] */ 


EXTERN_C const IID IID_CATIAVBAProgram;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3a9e52fd-79e9-46f6-9c13-bec9f687257e")
    CATIAVBAProgram : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *oName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *oReadOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScriptText( 
            /* [retval][out] */ BSTR *oScriptText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetScriptText( 
            /* [in] */ BSTR iScriptText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsZombied( 
            /* [retval][out] */ VARIANT_BOOL *oZombied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDispatch( 
            /* [retval][out] */ IDispatch **oDispatch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Run( 
            /* [in] */ BSTR iFunctionName,
            /* [in] */ SAFEARRAY * iParams,
            /* [out] */ VARIANT *oReturnValue,
            /* [out] */ BSTR *oErrorSource,
            /* [out] */ BSTR *oErrorDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowCode( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct CATIAVBAProgramVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CATIAVBAProgram * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            CATIAVBAProgram * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            CATIAVBAProgram * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CATIAVBAProgram * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CATIAVBAProgram * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CATIAVBAProgram * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CATIAVBAProgram * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            CATIAVBAProgram * This,
            /* [retval][out] */ BSTR *oName);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            CATIAVBAProgram * This,
            /* [retval][out] */ VARIANT_BOOL *oReadOnly);
        
        HRESULT ( STDMETHODCALLTYPE *GetScriptText )( 
            CATIAVBAProgram * This,
            /* [retval][out] */ BSTR *oScriptText);
        
        HRESULT ( STDMETHODCALLTYPE *SetScriptText )( 
            CATIAVBAProgram * This,
            /* [in] */ BSTR iScriptText);
        
        HRESULT ( STDMETHODCALLTYPE *IsZombied )( 
            CATIAVBAProgram * This,
            /* [retval][out] */ VARIANT_BOOL *oZombied);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDispatch )( 
            CATIAVBAProgram * This,
            /* [retval][out] */ IDispatch **oDispatch);
        
        HRESULT ( STDMETHODCALLTYPE *Run )( 
            CATIAVBAProgram * This,
            /* [in] */ BSTR iFunctionName,
            /* [in] */ SAFEARRAY * iParams,
            /* [out] */ VARIANT *oReturnValue,
            /* [out] */ BSTR *oErrorSource,
            /* [out] */ BSTR *oErrorDescription);
        
        HRESULT ( STDMETHODCALLTYPE *ShowCode )( 
            CATIAVBAProgram * This);
        
        END_INTERFACE
    } CATIAVBAProgramVtbl;

    interface CATIAVBAProgram
    {
        CONST_VTBL struct CATIAVBAProgramVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CATIAVBAProgram_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define CATIAVBAProgram_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define CATIAVBAProgram_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define CATIAVBAProgram_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define CATIAVBAProgram_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define CATIAVBAProgram_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define CATIAVBAProgram_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define CATIAVBAProgram_GetName(This,oName)	\
    ( (This)->lpVtbl -> GetName(This,oName) ) 

#define CATIAVBAProgram_IsReadOnly(This,oReadOnly)	\
    ( (This)->lpVtbl -> IsReadOnly(This,oReadOnly) ) 

#define CATIAVBAProgram_GetScriptText(This,oScriptText)	\
    ( (This)->lpVtbl -> GetScriptText(This,oScriptText) ) 

#define CATIAVBAProgram_SetScriptText(This,iScriptText)	\
    ( (This)->lpVtbl -> SetScriptText(This,iScriptText) ) 

#define CATIAVBAProgram_IsZombied(This,oZombied)	\
    ( (This)->lpVtbl -> IsZombied(This,oZombied) ) 

#define CATIAVBAProgram_GetIDispatch(This,oDispatch)	\
    ( (This)->lpVtbl -> GetIDispatch(This,oDispatch) ) 

#define CATIAVBAProgram_Run(This,iFunctionName,iParams,oReturnValue,oErrorSource,oErrorDescription)	\
    ( (This)->lpVtbl -> Run(This,iFunctionName,iParams,oReturnValue,oErrorSource,oErrorDescription) ) 

#define CATIAVBAProgram_ShowCode(This)	\
    ( (This)->lpVtbl -> ShowCode(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __CATIAVBAProgram_INTERFACE_DEFINED__ */


#ifndef __CATIAVBAForm_INTERFACE_DEFINED__
#define __CATIAVBAForm_INTERFACE_DEFINED__

/* interface CATIAVBAForm */
/* [uuid][unique][dual][object] */ 


EXTERN_C const IID IID_CATIAVBAForm;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02f6dfc1-b69c-431c-9e27-85a6a112f851")
    CATIAVBAForm : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *oFormName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Display( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *oReadOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsZombied( 
            /* [retval][out] */ VARIANT_BOOL *oZombied) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct CATIAVBAFormVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CATIAVBAForm * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            CATIAVBAForm * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            CATIAVBAForm * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CATIAVBAForm * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CATIAVBAForm * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CATIAVBAForm * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CATIAVBAForm * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            CATIAVBAForm * This,
            /* [retval][out] */ BSTR *oFormName);
        
        HRESULT ( STDMETHODCALLTYPE *Display )( 
            CATIAVBAForm * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            CATIAVBAForm * This,
            /* [retval][out] */ VARIANT_BOOL *oReadOnly);
        
        HRESULT ( STDMETHODCALLTYPE *IsZombied )( 
            CATIAVBAForm * This,
            /* [retval][out] */ VARIANT_BOOL *oZombied);
        
        END_INTERFACE
    } CATIAVBAFormVtbl;

    interface CATIAVBAForm
    {
        CONST_VTBL struct CATIAVBAFormVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CATIAVBAForm_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define CATIAVBAForm_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define CATIAVBAForm_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define CATIAVBAForm_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define CATIAVBAForm_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define CATIAVBAForm_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define CATIAVBAForm_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define CATIAVBAForm_GetName(This,oFormName)	\
    ( (This)->lpVtbl -> GetName(This,oFormName) ) 

#define CATIAVBAForm_Display(This)	\
    ( (This)->lpVtbl -> Display(This) ) 

#define CATIAVBAForm_IsReadOnly(This,oReadOnly)	\
    ( (This)->lpVtbl -> IsReadOnly(This,oReadOnly) ) 

#define CATIAVBAForm_IsZombied(This,oZombied)	\
    ( (This)->lpVtbl -> IsZombied(This,oZombied) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __CATIAVBAForm_INTERFACE_DEFINED__ */


#ifndef __CATIAVBAContainer_INTERFACE_DEFINED__
#define __CATIAVBAContainer_INTERFACE_DEFINED__

/* interface CATIAVBAContainer */
/* [uuid][unique][dual][object] */ 


EXTERN_C const IID IID_CATIAVBAContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4e96295d-3d4a-4aa7-8f9f-164aef3cee30")
    CATIAVBAContainer : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *oName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *oReadOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProgramCount( 
            /* [retval][out] */ long *oCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScriptProgramName( 
            /* [in] */ long iIndex,
            /* [retval][out] */ BSTR *oScriptName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScriptProgramFromIndex( 
            /* [in] */ long iIndex,
            /* [retval][out] */ CATIAVBAProgram **oProgram) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScriptProgramFromName( 
            /* [in] */ BSTR iScriptName,
            /* [retval][out] */ CATIAVBAProgram **oProgram) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveScriptProgram( 
            /* [in] */ long iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenameScriptProgram( 
            /* [in] */ long iIndex,
            /* [in] */ BSTR iNewScriptName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateScriptProgram( 
            /* [in] */ BSTR iScriptName,
            /* [retval][out] */ CATIAVBAProgram **oProgram) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsZombied( 
            /* [retval][out] */ VARIANT_BOOL *oZombied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetZombied( 
            /* [in] */ VARIANT_BOOL iZombied) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FormCount( 
            /* [retval][out] */ long *oCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormName( 
            /* [in] */ long iIndex,
            /* [retval][out] */ BSTR *oFormName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormFromIndex( 
            /* [in] */ long iIndex,
            /* [retval][out] */ CATIAVBAForm **oForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFormFromName( 
            /* [in] */ BSTR iFormName,
            /* [retval][out] */ CATIAVBAForm **oForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveForm( 
            /* [in] */ long iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenameForm( 
            /* [in] */ long iIndex,
            /* [in] */ BSTR iNewFormName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDirty( 
            /* [retval][out] */ VARIANT_BOOL *oIsDirty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct CATIAVBAContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CATIAVBAContainer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            CATIAVBAContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            CATIAVBAContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CATIAVBAContainer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CATIAVBAContainer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CATIAVBAContainer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CATIAVBAContainer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            CATIAVBAContainer * This,
            /* [retval][out] */ BSTR *oName);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            CATIAVBAContainer * This,
            /* [retval][out] */ VARIANT_BOOL *oReadOnly);
        
        HRESULT ( STDMETHODCALLTYPE *ProgramCount )( 
            CATIAVBAContainer * This,
            /* [retval][out] */ long *oCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetScriptProgramName )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex,
            /* [retval][out] */ BSTR *oScriptName);
        
        HRESULT ( STDMETHODCALLTYPE *GetScriptProgramFromIndex )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex,
            /* [retval][out] */ CATIAVBAProgram **oProgram);
        
        HRESULT ( STDMETHODCALLTYPE *GetScriptProgramFromName )( 
            CATIAVBAContainer * This,
            /* [in] */ BSTR iScriptName,
            /* [retval][out] */ CATIAVBAProgram **oProgram);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveScriptProgram )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *RenameScriptProgram )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex,
            /* [in] */ BSTR iNewScriptName);
        
        HRESULT ( STDMETHODCALLTYPE *CreateScriptProgram )( 
            CATIAVBAContainer * This,
            /* [in] */ BSTR iScriptName,
            /* [retval][out] */ CATIAVBAProgram **oProgram);
        
        HRESULT ( STDMETHODCALLTYPE *Save )( 
            CATIAVBAContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsZombied )( 
            CATIAVBAContainer * This,
            /* [retval][out] */ VARIANT_BOOL *oZombied);
        
        HRESULT ( STDMETHODCALLTYPE *SetZombied )( 
            CATIAVBAContainer * This,
            /* [in] */ VARIANT_BOOL iZombied);
        
        HRESULT ( STDMETHODCALLTYPE *FormCount )( 
            CATIAVBAContainer * This,
            /* [retval][out] */ long *oCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormName )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex,
            /* [retval][out] */ BSTR *oFormName);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormFromIndex )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex,
            /* [retval][out] */ CATIAVBAForm **oForm);
        
        HRESULT ( STDMETHODCALLTYPE *GetFormFromName )( 
            CATIAVBAContainer * This,
            /* [in] */ BSTR iFormName,
            /* [retval][out] */ CATIAVBAForm **oForm);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveForm )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *RenameForm )( 
            CATIAVBAContainer * This,
            /* [in] */ long iIndex,
            /* [in] */ BSTR iNewFormName);
        
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            CATIAVBAContainer * This,
            /* [retval][out] */ VARIANT_BOOL *oIsDirty);
        
        END_INTERFACE
    } CATIAVBAContainerVtbl;

    interface CATIAVBAContainer
    {
        CONST_VTBL struct CATIAVBAContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CATIAVBAContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define CATIAVBAContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define CATIAVBAContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define CATIAVBAContainer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define CATIAVBAContainer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define CATIAVBAContainer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define CATIAVBAContainer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define CATIAVBAContainer_GetName(This,oName)	\
    ( (This)->lpVtbl -> GetName(This,oName) ) 

#define CATIAVBAContainer_IsReadOnly(This,oReadOnly)	\
    ( (This)->lpVtbl -> IsReadOnly(This,oReadOnly) ) 

#define CATIAVBAContainer_ProgramCount(This,oCount)	\
    ( (This)->lpVtbl -> ProgramCount(This,oCount) ) 

#define CATIAVBAContainer_GetScriptProgramName(This,iIndex,oScriptName)	\
    ( (This)->lpVtbl -> GetScriptProgramName(This,iIndex,oScriptName) ) 

#define CATIAVBAContainer_GetScriptProgramFromIndex(This,iIndex,oProgram)	\
    ( (This)->lpVtbl -> GetScriptProgramFromIndex(This,iIndex,oProgram) ) 

#define CATIAVBAContainer_GetScriptProgramFromName(This,iScriptName,oProgram)	\
    ( (This)->lpVtbl -> GetScriptProgramFromName(This,iScriptName,oProgram) ) 

#define CATIAVBAContainer_RemoveScriptProgram(This,iIndex)	\
    ( (This)->lpVtbl -> RemoveScriptProgram(This,iIndex) ) 

#define CATIAVBAContainer_RenameScriptProgram(This,iIndex,iNewScriptName)	\
    ( (This)->lpVtbl -> RenameScriptProgram(This,iIndex,iNewScriptName) ) 

#define CATIAVBAContainer_CreateScriptProgram(This,iScriptName,oProgram)	\
    ( (This)->lpVtbl -> CreateScriptProgram(This,iScriptName,oProgram) ) 

#define CATIAVBAContainer_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define CATIAVBAContainer_IsZombied(This,oZombied)	\
    ( (This)->lpVtbl -> IsZombied(This,oZombied) ) 

#define CATIAVBAContainer_SetZombied(This,iZombied)	\
    ( (This)->lpVtbl -> SetZombied(This,iZombied) ) 

#define CATIAVBAContainer_FormCount(This,oCount)	\
    ( (This)->lpVtbl -> FormCount(This,oCount) ) 

#define CATIAVBAContainer_GetFormName(This,iIndex,oFormName)	\
    ( (This)->lpVtbl -> GetFormName(This,iIndex,oFormName) ) 

#define CATIAVBAContainer_GetFormFromIndex(This,iIndex,oForm)	\
    ( (This)->lpVtbl -> GetFormFromIndex(This,iIndex,oForm) ) 

#define CATIAVBAContainer_GetFormFromName(This,iFormName,oForm)	\
    ( (This)->lpVtbl -> GetFormFromName(This,iFormName,oForm) ) 

#define CATIAVBAContainer_RemoveForm(This,iIndex)	\
    ( (This)->lpVtbl -> RemoveForm(This,iIndex) ) 

#define CATIAVBAContainer_RenameForm(This,iIndex,iNewFormName)	\
    ( (This)->lpVtbl -> RenameForm(This,iIndex,iNewFormName) ) 

#define CATIAVBAContainer_IsDirty(This,oIsDirty)	\
    ( (This)->lpVtbl -> IsDirty(This,oIsDirty) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __CATIAVBAContainer_INTERFACE_DEFINED__ */


#ifndef __CATIAHostCallback_INTERFACE_DEFINED__
#define __CATIAHostCallback_INTERFACE_DEFINED__

/* interface CATIAHostCallback */
/* [uuid][unique][dual][object] */ 


EXTERN_C const IID IID_CATIAHostCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47d94bae-4009-4162-87fd-efa8bc7d9a44")
    CATIAHostCallback : public IDispatch
    {
    public:
        virtual HRESULT __stdcall OnBeforeRun( void) = 0;
        
        virtual HRESULT __stdcall OnAfterRun( void) = 0;
        
        virtual HRESULT __stdcall OnBeforePause( void) = 0;
        
        virtual HRESULT __stdcall OnAfterPause( void) = 0;
        
        virtual HRESULT __stdcall ShowMacroLibraries( void) = 0;
        
        virtual HRESULT __stdcall InsertObjectResolution( void) = 0;
        
        virtual HRESULT __stdcall InformContainerOnVBASave( 
            /* [in] */ BSTR iContainerRef,
            /* [in] */ BSTR iRealPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct CATIAHostCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CATIAHostCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            CATIAHostCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            CATIAHostCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CATIAHostCallback * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CATIAHostCallback * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CATIAHostCallback * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CATIAHostCallback * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( __stdcall *OnBeforeRun )( 
            CATIAHostCallback * This);
        
        HRESULT ( __stdcall *OnAfterRun )( 
            CATIAHostCallback * This);
        
        HRESULT ( __stdcall *OnBeforePause )( 
            CATIAHostCallback * This);
        
        HRESULT ( __stdcall *OnAfterPause )( 
            CATIAHostCallback * This);
        
        HRESULT ( __stdcall *ShowMacroLibraries )( 
            CATIAHostCallback * This);
        
        HRESULT ( __stdcall *InsertObjectResolution )( 
            CATIAHostCallback * This);
        
        HRESULT ( __stdcall *InformContainerOnVBASave )( 
            CATIAHostCallback * This,
            /* [in] */ BSTR iContainerRef,
            /* [in] */ BSTR iRealPath);
        
        END_INTERFACE
    } CATIAHostCallbackVtbl;

    interface CATIAHostCallback
    {
        CONST_VTBL struct CATIAHostCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CATIAHostCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define CATIAHostCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define CATIAHostCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define CATIAHostCallback_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define CATIAHostCallback_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define CATIAHostCallback_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define CATIAHostCallback_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define CATIAHostCallback_OnBeforeRun(This)	\
    ( (This)->lpVtbl -> OnBeforeRun(This) ) 

#define CATIAHostCallback_OnAfterRun(This)	\
    ( (This)->lpVtbl -> OnAfterRun(This) ) 

#define CATIAHostCallback_OnBeforePause(This)	\
    ( (This)->lpVtbl -> OnBeforePause(This) ) 

#define CATIAHostCallback_OnAfterPause(This)	\
    ( (This)->lpVtbl -> OnAfterPause(This) ) 

#define CATIAHostCallback_ShowMacroLibraries(This)	\
    ( (This)->lpVtbl -> ShowMacroLibraries(This) ) 

#define CATIAHostCallback_InsertObjectResolution(This)	\
    ( (This)->lpVtbl -> InsertObjectResolution(This) ) 

#define CATIAHostCallback_InformContainerOnVBASave(This,iContainerRef,iRealPath)	\
    ( (This)->lpVtbl -> InformContainerOnVBASave(This,iContainerRef,iRealPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __CATIAHostCallback_INTERFACE_DEFINED__ */


#ifndef __IVstaIntegration_INTERFACE_DEFINED__
#define __IVstaIntegration_INTERFACE_DEFINED__

/* interface IVstaIntegration */
/* [uuid][unique][object][dual] */ 


EXTERN_C const IID IID_IVstaIntegration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d7fac347-e663-4cf6-83b3-014a99c246ea")
    IVstaIntegration : public IDispatch
    {
    public:
        virtual void STDMETHODCALLTYPE Load( 
            /* [in] */ _CATIAApp *pOMAgent) = 0;
        
        virtual void STDMETHODCALLTYPE Unload( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVstaIntegrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVstaIntegration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVstaIntegration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVstaIntegration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVstaIntegration * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVstaIntegration * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVstaIntegration * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVstaIntegration * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        void ( STDMETHODCALLTYPE *Load )( 
            IVstaIntegration * This,
            /* [in] */ _CATIAApp *pOMAgent);
        
        void ( STDMETHODCALLTYPE *Unload )( 
            IVstaIntegration * This);
        
        END_INTERFACE
    } IVstaIntegrationVtbl;

    interface IVstaIntegration
    {
        CONST_VTBL struct IVstaIntegrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVstaIntegration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVstaIntegration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVstaIntegration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVstaIntegration_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVstaIntegration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVstaIntegration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVstaIntegration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVstaIntegration_Load(This,pOMAgent)	\
    ( (This)->lpVtbl -> Load(This,pOMAgent) ) 

#define IVstaIntegration_Unload(This)	\
    ( (This)->lpVtbl -> Unload(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVstaIntegration_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CATIAAppObj;

#ifdef __cplusplus

class DECLSPEC_UUID("5a29422a-f2b0-11d4-a3aa-00d0b756ad5d")
CATIAAppObj;
#endif

EXTERN_C const CLSID CLSID_CATIAVBAHostingApplicationImpl;

#ifdef __cplusplus

class DECLSPEC_UUID("0663d095-471d-11d2-9aa3-00a024941ef0")
CATIAVBAHostingApplicationImpl;
#endif
#endif /* __CATIA_APP_ITF_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


