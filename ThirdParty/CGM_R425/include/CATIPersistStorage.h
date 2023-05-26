/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIPersistStorage_H
#define CATIPersistStorage_H
//
//	Interface inspired from COM specification (cf IPersistStorage interface)
//
//	04/98		slg/lbf
//
/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"
#include "CATDataType.h"
//
class CATStorage;

extern ExportedByAD0XXBAS IID IID_CATIPersistStorage ;


class ExportedByAD0XXBAS CATIPersistStorage : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  // *** (IPersist) ***
  virtual HRESULT GetClassID (CLSID* pclsid) = 0;

    // *** (IPersistStorage) ***
  virtual HRESULT IsDirty () = 0;
  virtual HRESULT InitNew (CATStorage* pStg) = 0;
  virtual HRESULT SaveCompleted (CATStorage* pStgNew) = 0;
  virtual HRESULT HandsOffStorage () = 0;

  virtual HRESULT Load (CATStorage* pStg) = 0;
  virtual HRESULT Save (CATStorage* pStgSave, CATULONG32  fSameAsLoad, DWORD iRootStorageMode) = 0;

    // **** (New Method) ****
  virtual HRESULT IsLoaded () = 0; // retuns S_FALSE if not loaded
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIPersistStorage, CATBaseUnknown ) ;


#endif
