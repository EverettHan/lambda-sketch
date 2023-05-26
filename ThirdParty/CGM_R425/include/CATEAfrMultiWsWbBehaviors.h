//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017
//===================================================================
// CATEAfrMultiWsWbBehaviors.cpp
// Header definition of class CATEAfrMultiWsWbBehaviors
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/01/27 Creation: ers
//===================================================================

#ifndef CATEAfrMultiWsWbBehaviors_H
#define CATEAfrMultiWsWbBehaviors_H

#include "CATIAfrMultiWsWbBehaviors.h"

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATString;

//-----------------------------------------------------------------------

class ExportedByCATAfrItf CATEAfrMultiWsWbBehaviors: public CATIAfrMultiWsWbBehaviors
{
public:

  CATDeclareClass;

  // Standard constructors and destructors
  // -------------------------------------
  CATEAfrMultiWsWbBehaviors ()=default;
  virtual ~CATEAfrMultiWsWbBehaviors ()=default;

// CATIAfrMultiWsWbBehaviors methods
  virtual CATBoolean ReplaceWithPreferredWorkbenchOfOtherWorkshop () override;

  virtual CATBoolean IsWorkbenchAllowed(const CATString & iToWorkshop) override;


private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATEAfrMultiWsWbBehaviors (CATEAfrMultiWsWbBehaviors &)=delete;
  CATEAfrMultiWsWbBehaviors& operator=(CATEAfrMultiWsWbBehaviors&)=delete;
};
#endif
