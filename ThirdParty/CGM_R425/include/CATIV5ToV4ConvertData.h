/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIV5ToV4ConvertData_h
#define CATIV5ToV4ConvertData_h

// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// Interface CATIV5ToV4ConvertData :
//     
//       
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Juin. 00   Creation                                
//=============================================================================

//#include "IUnknown.h"

#include "CATBaseUnknown.h"
#include "CATDataType.h"

#include "ExportedByAC0UAX.h"
extern IID ExportedByAC0UAX  IID_CATIV5ToV4ConvertData;

class ExportedByAC0UAX  CATIV5ToV4ConvertData: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
     virtual HRESULT  __stdcall Convert(double Unit)=0;
     virtual HRESULT  __stdcall Convert(CATLONG32 CodePage,
                                        CATLONG32 Real,
                                        CATLONG32 Integer)=0;
};
CATDeclareHandler(CATIV5ToV4ConvertData,CATBaseUnknown);

#endif
