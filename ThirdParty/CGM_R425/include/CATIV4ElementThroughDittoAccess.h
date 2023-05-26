/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIV4ElementThroughDittoAccess_h
#define CATIV4ElementThroughDittoAccess_h

#include "CATBaseUnknown.h"
#include "AC0CATPL.h"
#include "CATListOfInt.h"
 
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0CATPL IID IID_CATIV4ElementThroughDittoAccess ;
#else
extern "C" const IID IID_CATIV4ElementThroughDittoAccess ;
#endif


class ExportedByAC0CATPL CATIV4ElementThroughDittoAccess : public CATBaseUnknown
{
  CATDeclareInterface;
  
 public:
    virtual void GetPileDitto(CATListOfInt& PileDittos) = 0;
    virtual int GetJele() = 0;
    virtual int GetModel() = 0;
   
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler ( CATIV4ElementThroughDittoAccess, CATBaseUnknown);

#endif

