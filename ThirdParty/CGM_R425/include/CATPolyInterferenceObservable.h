// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceObservable.h
//
//===================================================================
//
// Usage notes:
// Class adding the ability to attach interference observers.
//
//===================================================================
//
// Aug 2009 Creation: JS9
// Dec 2018 Modification JXO: NotifyObservers with CATPolyInterfDecoratedTriangle
//===================================================================

#ifndef CATPolyInterferenceObservable_h
#define CATPolyInterferenceObservable_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATListPV.h"

// Interference
class CATIPolyInterferenceObserver;
class CATIPolyInterference;
class CATPolyInterferenceWarning;
class CATIPolyInterfWarningObserver;
class CATPolyInterfDecoratedTriangle;

// Math
class CATMathPoint;

/**
 * Observer interface for CATPolyClearancetInterf.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceObservable
{
public:

  /**
   * Constructor ans destructor
   */
  CATPolyInterferenceObservable();
  virtual ~CATPolyInterferenceObservable();

  /**
   * Add a new observer.
   * @param observer observer to add.
   */
  virtual void AttachObserver(CATIPolyInterferenceObserver * observer);

  /**
   * Remove an already added observer.
   * @param observer observer to remove. If not present the function does nothing.
   */
  virtual void DetachObserver(CATIPolyInterferenceObserver * observer);

  /**
   * Notify the registered observers that the a new interference has just been created.
   * @param interf newly created interference.
   */
  virtual void NotifyObservers(CATIPolyInterference * interf);

  /**
   * Notify the registered observers that the a new couple of triangles clashing has been found.
   */
  virtual void NotifyObservers(CATPolyInterfDecoratedTriangle & tri1, CATPolyInterfDecoratedTriangle & tri2, const CATMathPoint oPoints[2]);

  /**
   * Add a new observer for warnings.
   * @param observer observer to add.
   */
  virtual void AttachObserver(CATIPolyInterfWarningObserver * observer);

  /**
   * Remove an already added observer.
   * @param observer observer to remove. If not present the function does nothing.
   */
  virtual void DetachObserver(CATIPolyInterfWarningObserver * observer);

  /**
   * Notify the registered observers that the a new warning has just been created.
   * @param interf newly created interference.
   */
  virtual void NotifyObservers(const CATPolyInterferenceWarning * warning);

private:
  
  CATListPV _oObservers;
  CATListPV _oWarningObservers;
};

#endif // CATPolyInterferenceObservable_h
