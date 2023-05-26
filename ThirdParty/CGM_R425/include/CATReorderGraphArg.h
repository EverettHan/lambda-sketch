#ifndef CATReorderGraphArg_h
#define CATReorderGraphArg_h

// COPYRIGHT DASSAULT SYSTEMES 1998
// ===================================================================
//
// CATReorderGraphArg:
// argument de la fonction reorder graph
//
// ===================================================================
// Usage notes:
//
// 
// ===================================================================
// Mar. 2000. Creation
// ===================================================================

#include "IUnknown.h"
#include "CATInteractiveInterfaces.h"

class ExportedByCATInteractiveInterfaces CATReorderGraphArg
{
public:

  CATReorderGraphArg (const IID* iNavIID=0,const IID* iNavMoveIID=0);
  ~CATReorderGraphArg();

  IID* _nav_iid;
  IID* _nav_move_iid;

private:
  // Not implemented methods
  CATReorderGraphArg(const CATReorderGraphArg &iObjectToCopy);
  CATReorderGraphArg& operator=(const CATReorderGraphArg&);

};

#endif
