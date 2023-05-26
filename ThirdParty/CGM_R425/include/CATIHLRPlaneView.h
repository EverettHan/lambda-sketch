#ifndef CATIHLRPlaneView_h
#define CATIHLRPlaneView_h
#include "SGInfra.h"

#include "CATBaseUnknown.h"
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------
//
// Abstract : Interface to get the tool which does HLR job
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
// Inheritance :  CATIHLRPlaneView 
// -----------      CATBaseUnknown
//
//------------------------------------------------------------------------
//
// Main Methods :  GetPlaneView()
// --------------  
//               
//------------------------------------------------------------------------

class CATHLRPlaneView;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySGInfra IID IID_CATIHLRPlaneView;
#else
extern "C" const IID IID_CATIHLRPlaneView;
#endif

class ExportedBySGInfra CATIHLRPlaneView : public CATBaseUnknown
{
  CATDeclareInterface;

  public :
  ////////

  virtual CATHLRPlaneView * GetPlaneView () = 0;

} ; 

CATDeclareHandler(CATIHLRPlaneView,CATBaseUnknown);

#endif
