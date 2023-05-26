// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyContactInterfObserver.h
//
//===================================================================
//
// Usage notes:
// Observer interface for CATPolyContactInterf.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyContactInterfObserver_h
#define CATPolyContactInterfObserver_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATIPolyInterferenceObserver.h"

class CATIPolyInterference;
class CATPolyContactInterf;

/**
 * Observer interface for CATPolyContactInterf.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyContactInterfObserver : public CATIPolyInterferenceObserver
{
public:

  virtual ~CATPolyContactInterfObserver();

  /**
   * When the observer is attached and each time a new interference is build,
   * this function is called.
   */
  virtual void ProcessInterference(CATIPolyInterference * interf);

  /**
   * When the observer is attached and each time a new contact is found,
   * this function is called.
   */
  virtual void ProcessContact(CATPolyContactInterf * contact) = 0;

protected:

  /**
   * Constructor
   */
  CATPolyContactInterfObserver();
  
};

#endif // CATPolyContactInterfObserver_h
