//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/04/08
//===================================================================
// CATIAfrMultiWsWbBehaviors.cpp
// Header definition of class CATIAfrMultiWsWbBehaviors
//===================================================================
//
// Usage notes:
//
// This interface is part of the multi-workshop workbench mechanism.
// This interface will be called when the users enters a multi-workshop workbench in order to prevent from setting this workbench as the preferred workbench for all its workshops.
//
// CATIAfrMultiWsWbBehaviors must be implemented on a late type 
// and this late type's name is the name of the workbench followed by "_behaviors".
//
// Implement this interface only in an extension of the late type deriving from CATEAfrMultiWsWbBehaviors adapter.
//
//===================================================================
//  2013/04/08 Creation: ers
//===================================================================
#ifndef CATIAfrMultiWsWbBehaviors_H
#define CATIAfrMultiWsWbBehaviors_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATString;

extern ExportedByCATAfrItf  IID IID_CATIAfrMultiWsWbBehaviors ;

// This interface allows a multi-workshop workbench to override some default behaviors.
// This interface should be implemented on a late type named the same as the multi-workshop workbench followed by "_behaviors".
// Implement this interface only if the default behavior is not satisfying your workbench.
// This interface can be implemented only by deriving the adaptor: CATEAfrMultiWsWbBehaviors
class ExportedByCATAfrItf CATIAfrMultiWsWbBehaviors: public CATBaseUnknown
{
CATDeclareInterface;

public:

  // Ask if you want your multi-workshop workbench to be replaced by another workbench chosen by the user in another workshop (which is the default)
  virtual CATBoolean ReplaceWithPreferredWorkbenchOfOtherWorkshop () = 0;

  // Ask if you allow the workbench with this Workshop. The input workshop is necessary part of the supported workshop(s) declared in workbench CATRsc.
  // You will be called on this method each time the UI-Active Object is changed, so you can decide to forbid your workbench based on current UI-Active object.
  // Default implement return TRUE.
  virtual CATBoolean IsWorkbenchAllowed(const CATString & iToWorkshop) = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIAfrMultiWsWbBehaviors, CATBaseUnknown);

#endif
