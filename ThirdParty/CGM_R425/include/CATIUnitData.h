/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIUnitData_h
#define CATIUnitData_h

// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// Interface CATIUnitData :
//     
//       
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Juin. 00   Creation                                
//=============================================================================

#include "IUnknown.h"

#include "CATIConvertData.h"

#include "ExportedByAC0UAX.h"
extern IID ExportedByAC0UAX  IID_CATIUnitData;

class ExportedByAC0UAX CATIUnitData: public CATIConvertData
{
  CATDeclareInterface;

public:
     virtual HRESULT  __stdcall Convert(double Unit)=0;
     virtual HRESULT  __stdcall Convert(long CodePage,
                                        long Real,
                                        long Integer)=0;
};

CATDeclareHandler(CATIUnitData,CATIConvertData);

#endif
