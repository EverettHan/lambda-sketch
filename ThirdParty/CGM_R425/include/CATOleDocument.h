//**********************************************************************
// D.Berree Mars 1997
//
// Objet OLE pour server Document composite     
//
//**********************************************************************
#ifndef CATOLEDOCUMENT_H 
#define CATOLEDOCUMENT_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#ifdef _WINDOWS_SOURCE
#include "CATAfrFoundation.h"

#include <afxwin.h>
#include <ole2.h>
//#include "CATDocument.h"
class CATDocument;
#include "CATFrmEditor.h"
#define MAXEXTENSIONSIZE 15

// DBI -->
#include <docobj.h>       // ActiveX

class    CATFrmOleToolBar;
class    CATDlgDocument;
class    CATDialog;


#define ReleaseInterface(p)  \
  if ((p) != NULL) {         \
    (p)->Release ();         \
    (p) = NULL;              \
  }

#define DeleteAndNull(p)     \
  if ((p) != NULL) {         \
    delete (p);              \
    (p) = NULL;              \
  }

/*
 * DBI: 13/09/99
 *
 * Under normal circumstances, when CATIA performs an
 * illegal operation (eg. illegal memory access), the
 * system throws an exception, than can be caught under
 * the debugger in order to generate a usefull backtrace.
 * When CATIA starts, it registers as an OLE server and
 * exposes its OLE start point interfaces (IClassFactory).
 * This registration alters the way the system reacts 
 * upon CATIA's illegal operation : it seems, that the
 * OLE interfaces are first released, and the exception 
 * is then thrown. Releasing the CATIA's OLE interfaces
 * prematurely leads to unpredictable behaviour and to
 * the unability to generate a relevant backtrace.
 * I introduced this flag for debug purpose. This flag
 * is controlled by the NO_CLASS_FACTORIES environment
 * variable. When set, this variable disables the class
 * factory registration (and so disables all the OLE 
 * stuff), and thus allows debugging under normal 
 * conditions.
 */

// DBE Nov 2002 passage ShouldRegister => IsOleActivated
// (plus restrictif)
//#  define OLE_CODE_BEGIN     \
//  if (CATOleDocument::ShouldRegister () == TRUE) {
#  define OLE_CODE_BEGIN     \
  if (CATOleDocument::IsOleActivated() == TRUE) {

#  define OLE_CODE_END       \
  }

// <-- DBI

class ExportedByCATAfrFoundation CATOleDocument : public IUnknown {

public:
  enum CATOleRegPolicy {
    orpUndefined,
    orpRegister,
    orpDontRegister
  };
  enum InsertionType {
    Undefined,
    Link,
    Embed
  };

  static BOOL ShouldRegister ();
  // DBE Nov 2002 +
  static inline BOOL IsOleActivated() { return sOleActivated; };
  static inline void SetOleActivated(BOOL OleActivated) { sOleActivated=OleActivated; };
  // DBE Nov 2002 -

private:
  static CATOleRegPolicy sRegPolicy;
  static BOOL sOleActivated;
  static int     sInitialWidth;
  static int     sInitialHeight;
  CATDocument  * _pDocument;  
  CATFrmEditor * _pFrmEditor;      
  char           _Extension[MAXEXTENSIONSIZE+1];
  int _Count;                     // reference count
  int _ClosingFrmEditor;          // booleen
  int _InDestruction;             // booleen
  int _LockedByWindow;            // booleen

  // flag telling whether the server is active
  BOOL _isActive;                 

  InsertionType _InsertionType; 

  DWORD _Register;                // Registered in ROT
  LPMONIKER _pMoniker;              
  int _Width;                     // largeur en pixels voulue par le container (setextent)  
  int _Height;                    // hauteur en pixels voulue par le container (setextent)  

  // interfaces used
  LPSTORAGE m_lpStorage;
  LPOLECLIENTSITE m_lpOleClientSite;          // IOleClientSite
  LPOLEADVISEHOLDER m_lpOleAdviseHolder;      // IOleAdviseHolder

//  methode utilitaire appelee par Load et LoadFromStorage    
    STDMETHODIMP InternalLoad (char* FileName, DWORD dwMode) ;

//  Pour protection en cas d'exit
    static void ExitCallBack();
    static int sExitStatus;

public:

  STDMETHODIMP QueryInterface (REFIID riid, LPVOID FAR* ppvObj);
  STDMETHODIMP_(ULONG) AddRef ();
  STDMETHODIMP_(ULONG) Release ();
// construction/destruction

  CATOleDocument(const char* Extension, CATFrmEditor * pFrmEditor=NULL);
  ~CATOleDocument();


// utility functions

    void LockByWindow(int Bool); // appele par CATFrmEditor
    STDMETHODIMP SetHostNames  ( LPCOLESTR szContainerApp, LPCOLESTR szContainerObj);
    HANDLE GetData(CLIPFORMAT Format);

// chargement a partir d'un fichier 
    STDMETHODIMP Load ( LPCOLESTR pszFileName, DWORD dwMode) ;
    STDMETHODIMP GetCurFile(LPOLESTR __RPC_FAR *ppszFileName); 

    STDMETHODIMP InitNew(LPSTORAGE lpStg);
    STDMETHODIMP LoadFromStorage (LPSTORAGE lpStg);
    STDMETHODIMP SaveToStorage (LPSTORAGE lpStg, BOOL fSameAsLoad);

    void GetClassId(LPCLSID lpClassID);

    STDMETHODIMP IsDirty();

    STDMETHODIMP Close ( DWORD dwSaveOption) ;
    STDMETHODIMP OpenEdit(LPOLECLIENTSITE pActiveSite);

    void SetExtent ( DWORD dwDrawAspect, LPSIZEL lpsizel);
    int SaveEmbed();
    void NotifySave();
    void NotifyDataChange();

    void ROTRegister(char * FileName);
    void ROTRevoke();

// member variable access
    inline int GetCount() { return _Count; };
    inline DWORD GetRotRegister() { return _Register; };
    inline int GetWidth() { return _Width; };
    inline int GetHeight() { return _Height; };
    inline void SetFrmEditor(CATFrmEditor* pFrmEditor) { _pFrmEditor = pFrmEditor; };
    
    inline InsertionType GetInsertionType() { return _InsertionType; };

// DBI -->
private:

  CATFrmWindow            * m_pFrmWindow;

  CATDlgDocument          * m_pDlgDocument;     // Frame CNext
// <-- DBI
};
#endif
#endif
