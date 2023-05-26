//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/04/08
//===================================================================
// CATIAfrSpecialTransition.cpp
// Header definition of class CATIAfrSpecialTransition
//===================================================================
//
// Usage notes:
//
// This interface is part of the workshop transition mechanism. Please also look at CATIWorkbenchTransition interface.
// This interface will be called only during a transition (user Apps choice or CATWorkbench/CATWorkbenchServices::Dotransition call).
// This interface will be called only on the target workshop of the transition.
//
// As CATIWorkbenchTransition, CATIAfrSpecialTransition must be implemented on a late type 
// and this late type's name is the name of the workshop followed by "_trans".
//
// Implement this interface only in an extension of the late type deriving from CATEAfrSpecialTransition adapter.
//
//===================================================================
//  2013/04/08 Creation: ers
//===================================================================
#ifndef CATIAfrSpecialTransition_H
#define CATIAfrSpecialTransition_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"


extern ExportedByCATAfrItf  IID IID_CATIAfrSpecialTransition ;


enum CATAfrSpecialTransitionMode {
  AfrTransitionNotSupported=0,
  AfrTransitionForCompatibility=1,
  AfrTransitionOpenMode=2, 
  AfrTransitionExploreMode=3};

class ExportedByCATAfrItf CATIAfrSpecialTransition: public CATBaseUnknown
{
CATDeclareInterface;

public:

  // Tell if you want ExecuteSpecialTransition method to be called
  // Return OpenMode or ExploreMode if you want ExecuteSpecialTransition to be called
  virtual CATAfrSpecialTransitionMode IsSpecialTransitionSupported () = 0;

  // Execute your transition code.
  // This will be called just before CATIWorkbenchTransition::DoTransition method on the same late type.
  // As CATIWorkbenchTransition::DoTransition method, ExecuteSpecialTransition method should return:
  //   - 0 if the transition process should continue after, 
  //   - or 1 if the transition process ends with this call.
  virtual int ExecuteSpecialTransition (CATAfrSpecialTransitionMode iMode) = 0;



  // Tell if you want Execute method to be executed. Obsolete method, use previous methods.
  virtual CATBoolean IsSupported() = 0;
  // Execute your transition code. Obsolete method, called only if IsSupported returns 1...
  virtual int Execute () = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIAfrSpecialTransition, CATBaseUnknown);

#endif
