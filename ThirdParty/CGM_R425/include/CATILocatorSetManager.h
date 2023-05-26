/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999
//-----------------------------------------------------------------------------
// class CATILocatorSetManager (Interface) :
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
// The first (and perhaps only) purpose of this interface
// is to suppress the dependency between ObjetSpecsModeler 
// and ObjectModelerSDM caused by V4-to-V5 CCP.
// The Create/ReleaseLocatorSet services can now be accesses
// from anywhere through this interface, whereas their
// implementation is still in ObjectModelerSDM.
//
//-----------------------------------------------------------------------------
// Creation nll Jan 99
//-----------------------------------------------------------------------------
#ifndef CATILocatorSetManager_H_
#define CATILocatorSetManager_H_

/**
 * @level Private
 * @usage U3
 */

#include "CP0CLIP.h"
#include "CATBaseUnknown.h"

class CATILocatorSet;
class CATIContainer;

extern ExportedByCP0CLIP IID IID_CATILocatorSetManager ;

class ExportedByCP0CLIP CATILocatorSetManager : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  virtual CATILocatorSet* CreateLocatorSet(const CATIContainer* on_container) = 0;

  virtual void RemoveLocatorSet(CATILocatorSet* loc) = 0;
};
 
CATDeclareHandler( CATILocatorSetManager, CATBaseUnknown ) ;

#endif




