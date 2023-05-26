#ifndef CATScriptSystemCalls_h
#define CATScriptSystemCalls_h

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
 * A layer to abstract the scripting infrastructure from the
 * underlying system calls (either NT or Mainwin)
 * @author: Jean-Francois Doue (JDU) David Morisot (DMO)
 */

#include "JS0CTYP.h"
#include "CATBSTR.h"
#include "CATNTTypes.h"
#include "IUnknown.h"
#ifndef _WINDOWS_SOURCE
// System Framework
#include "CATMainwin.h"
#else // _WINDOWS_SOURCE
#include <oaidl.h>
#endif // _WINDOWS_SOURCE

class ExportedByJS0CTYP CATScriptSystemCalls {
	public:
		// Typelibs
		static HRESULT LoadTypeLib(
			const wchar_t* szFile, 
			ITypeLib ** tplib);
		static HRESULT RegisterTypeLib(
			ITypeLib * ptlib, 
			wchar_t* szFullPath,
			wchar_t* szHelpDir);
		static HRESULT UnRegisterTypeLib(
			REFGUID libID,
			unsigned short wVerMajor,
			unsigned short wVerMinor,
			LCID lcid,
			SYSKIND syskind);
		static HRESULT QueryPathOfRegTypeLib(
			REFGUID libID,
			unsigned short wVerMajor,
			unsigned short wVerMinor,
			LCID lcid,
			CATBSTR * lpBstrPathName);

		// VARIANTs
		static void VariantInit(
			VARIANTARG * pvarg);
		
		static HRESULT VariantClear(
			VARIANTARG * pvarg);
		
		static HRESULT VariantCopy(
			VARIANTARG * pvargDest, 
			VARIANTARG * pvargSrc);
		
		static INT VariantTimeToSystemTime( 
			double iVtime,              
			LPSYSTEMTIME oLpSystemTime);
		
		static INT SystemTimeToVariantTime(
			LPSYSTEMTIME iLpSystemTime,  
			double *oPvtime);
		
		static HRESULT VariantChangeType( 
			VARIANTARG *oVargDest,  
			VARIANTARG *iVarSrc,  
			unsigned short iWFlags,  
			VARTYPE iVt);

		// COM
		static HRESULT CLSIDFromProgID(
			const wchar_t* lpszProgID,
			LPCLSID lpclsid);
		static HRESULT CoCreateInstance(
			const CLSID & rclsid, 
			LPUNKNOWN pUnkOuter,
			DWORD dwClsContext, 
			const IID & riid, 
			LPVOID * ppv);
		static HRESULT OleInitialize(LPVOID pv);
		
		static void OleUninitialize();
		
		// BSTRs
		static CATBSTR SysAllocStringLen(
			const wchar_t* iCharArray, 
			unsigned int iArraySize);
		static void SysFreeString(
			CATBSTR iBSTR);
		static unsigned int SysStringLen(CATBSTR iBSTR);


		// SafeArrays
		static SAFEARRAY * SafeArrayCreate(
			VARTYPE vt,
			unsigned int cDims, 
			SAFEARRAYBOUND * rgsabound);
		static HRESULT SafeArrayDestroy(
			SAFEARRAY * psa);
		static unsigned int SafeArrayGetDim(
			SAFEARRAY * psa);
		static HRESULT SafeArrayGetUBound(
			SAFEARRAY * psa, 
			unsigned int nDim, 
			CATLONG * plUbound);
		static HRESULT SafeArrayGetLBound(
			SAFEARRAY * psa, 
			unsigned int nDim, 
			CATLONG * plLbound);
		static HRESULT SafeArrayGetElement(
			SAFEARRAY * psa, 
			CATLONG * rgIndices, 
			void * pv);
		static HRESULT SafeArrayPutElement(
			SAFEARRAY * psa, 
			CATLONG * rgIndices, 
			void * pv);
		static HRESULT SafeArrayCopy( 
			SAFEARRAY *  psa,          
			SAFEARRAY **  ppsaOut);

		// Error
		static HRESULT CreateErrorInfo(
			ICreateErrorInfo **pperrinfo);
		static HRESULT SetErrorInfo(
			DWORD  dwReserved,     
			IErrorInfo  *perrinfo);
		static IID IID_CATIErrorInfo;


		static IID IID_NULL;
#if defined(_WINDOWS_SOURCE)
        // Signatures provided for compatibility only
        // On Windows, sizeof(wchar_t) == sizeof(unsigned short), so the cast it safe
        static HRESULT LoadTypeLib(const unsigned short * szFile, ITypeLib ** tplib)
        {
            return LoadTypeLib(reinterpret_cast<const wchar_t*>(szFile), tplib);
        }
        static HRESULT RegisterTypeLib(ITypeLib * ptlib, unsigned short* szFullPath, unsigned short* szHelpDir)
        {
            return RegisterTypeLib(ptlib, reinterpret_cast<wchar_t*>(szFullPath), reinterpret_cast<wchar_t*>(szHelpDir));
        }
        static HRESULT CLSIDFromProgID(const unsigned short* lpszProgID, LPCLSID lpclsid)
        {
            return CLSIDFromProgID(reinterpret_cast<const wchar_t*>(lpszProgID), lpclsid);
        }
        static CATBSTR SysAllocStringLen(const unsigned short* iCharArray, unsigned int iArraySize)
        {
            return SysAllocStringLen(reinterpret_cast<const wchar_t*>(iCharArray), iArraySize);
        }
#endif
};


#endif // CATScriptSystemCalls_h

