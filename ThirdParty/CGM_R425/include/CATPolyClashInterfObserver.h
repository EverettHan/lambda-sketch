// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClashInterfObserver.h
//
//===================================================================
//
// Usage notes:
// Observer interface for CATPolyClashInterf.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyClashInterfObserver_h
#define CATPolyClashInterfObserver_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATIPolyInterferenceObserver.h"

class CATIPolyInterference;
class CATPolyClashInterf;

/**
 * Observer interface for CATPolyClashInterf.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyClashInterfObserver : public CATIPolyInterferenceObserver
{
public:

  virtual ~CATPolyClashInterfObserver();

  /**
   * When the observer is attached and each time a new interference is build,
   * this function is called.
   */
  virtual void ProcessInterference(CATIPolyInterference * interf);

  /**
   * When the observer is attached and each time a new clash is found,
   * this function is called.
   */
  virtual void ProcessClash(CATPolyClashInterf * clash) = 0;

protected:

  /**
   * Constructor
   */
  CATPolyClashInterfObserver();
  
};

#endif // CATPolyClashInterfObserver_h
