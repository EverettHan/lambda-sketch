// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClearanceInterfObserver.h
//
//===================================================================
//
// Usage notes:
// Observer interface for CATPolyClearanceInterf.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATPolyClearanceInterfObserver_h
#define CATPolyClearanceInterfObserver_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATIPolyInterferenceObserver.h"

class CATIPolyInterference;
class CATPolyClearanceInterf;

/**
 * Observer interface for CATPolyClearancetInterf.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyClearanceInterfObserver : public CATIPolyInterferenceObserver
{
public:

  virtual ~CATPolyClearanceInterfObserver();

  /**
   * When the observer is attached and each time a new interference is build,
   * this function is called.
   */
  virtual void ProcessInterference(CATIPolyInterference * interf);

  /**
   * When the observer is attached and each time a new clearance is found,
   * this function is called.
   */
  virtual void ProcessClearance(CATPolyClearanceInterf * clearance) = 0;

protected:

  /**
   * Constructor
   */
  CATPolyClearanceInterfObserver();
  
};

#endif // CATPolyClearanceInterfObserver_h
