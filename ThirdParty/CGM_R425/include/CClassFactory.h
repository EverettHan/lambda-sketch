/**********************************************************************/
// File name: CClassFactory.h
//
//      Definition of CClassFactory
//
/**********************************************************************/

#ifndef CClassFactory_h
#define CClassFactory_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"
#include <afxwin.h>
#include <ole2.h>

#define CCLASSFACTORYEXTENSIONNUMBER 8  

class CNext;

class ExportedByCATAfrFoundation CClassFactory : IClassFactory
{
private:
    int _Count;               // reference count
    int _InDestruction;
    CNext* _pApp;
    unsigned int _DocumentType;
    static CClassFactory * _sClassFactory[CCLASSFACTORYEXTENSIONNUMBER];
    static DWORD _sRegisterClass[CCLASSFACTORYEXTENSIONNUMBER];
  
    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CClassFactory ();
    CClassFactory (const CClassFactory &);
    CClassFactory & operator= (const CClassFactory &);

public:

    static const char * sExtension[CCLASSFACTORYEXTENSIONNUMBER];
    static const GUID sClassId[CCLASSFACTORYEXTENSIONNUMBER];
    static int DeclareAllTheOLEClassFactories(CNext* );
    static void RevokeAllTheOLEClassFactories();

    CClassFactory(CNext* lpApp,unsigned int DocumentType);
    virtual ~CClassFactory();
    
    // IUnknown Methods
    STDMETHODIMP QueryInterface (REFIID riid, LPVOID FAR* ppvObj);
    STDMETHODIMP_(ULONG) AddRef ();
    STDMETHODIMP_(ULONG) Release ();
    
    STDMETHODIMP CreateInstance (LPUNKNOWN pUnkOuter,
      REFIID riid,
      LPVOID FAR* ppvObject);
    STDMETHODIMP LockServer ( BOOL fLock);

};

#endif
