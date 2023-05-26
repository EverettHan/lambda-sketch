#ifndef CATIFileMenuMethods_h
#define CATIFileMenuMethods_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <CATAfrFoundation.h>
#include <CATBaseUnknown.h>
#include <CATDlgUtility.h>
#include <CATString.h>
#include <CATUnicodeString.h>

class CATDocument;
class CATFrmEditor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATIFileMenuMethods;
#else
extern "C" const IID IID_CATIFileMenuMethods;
#endif

class ExportedByCATAfrFoundation CATIFileMenuMethods : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  virtual CATDocument * New (CATUnicodeString Type,
                             CATBool ActivEditor = TRUE) = 0;

  virtual CATDocument * Open(CATUnicodeString storageName,
                             CATBool FlagRead,
                             int ActivEditor = 1) = 0;

  virtual HRESULT  NewFrom (CATUnicodeString storageName, 
                            CATDocument *& oNewFromDoc,
                            int ActivEditor = 1) = 0;

  virtual HRESULT  Save  (CATDocument * Doc) = 0;

  virtual HRESULT  SavAs (CATDocument * Doc,
                          CATUnicodeString FileName,
                          CATUnicodeString Format="") = 0;

  virtual HRESULT  Close (CATFrmEditor * edt = NULL,
                          CATString titleKey = "Close") = 0;

  virtual HRESULT  Exit  () = 0;

  virtual void     CreateEditorsWindow(CATFrmEditor * edt) = 0;

  //NLS
  virtual CATUnicodeString ReadFM_MsgCatalog(CATString key,
                                             CATString catalog="") = 0;
};

CATDeclareHandler(CATIFileMenuMethods, CATBaseUnknown);

#endif
