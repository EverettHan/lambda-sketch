#ifndef CATIHLRExact_h
#define CATIHLRExact_h
//COPYRIGHT DASSAULT SYSTEMES 2000

//Stephane Grabli

//------------------------------------------------------------------------
//
// Abstract : Interface to know whether a model supports exact HLR or not
// ---------- 
//            
//            
//              
//   
//------------------------------------------------------------------------
//
// Usage :    used to get the model dependant HLR algorithm
// -------    
//  
//------------------------------------------------------------------------
//
// Inheritance :  CATIHLRExact 
// -----------      CATBaseUnknown
//
//------------------------------------------------------------------------

#include "SGInfra.h"

#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATIHLRExact;
#else
extern "C" const IID IID_CATIHLRExact;
#endif

class ExportedBySGInfra CATIHLRExact : public CATBaseUnknown
{
  CATDeclareInterface;

public:
};

CATDeclareHandler(CATIHLRExact,CATBaseUnknown);


#endif
