// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyInterfWarningObserver.h
//
//===================================================================
//
// Usage notes:
// Observer interface for CATPolyInterferenceWarnings.
//
//===================================================================
//
// Aug 2009 Creation: JS9
//===================================================================

#ifndef CATIPolyInterfWarningObserver_h
#define CATIPolyInterfWarningObserver_h

#include "CATPolyBoundingVolumeOperators.h"

// Interference
class CATPolyInterferenceWarning;

/**
 * Observer interface for CATPolyInterferenceWarnings.
 */
class ExportedByCATPolyBoundingVolumeOperators CATIPolyInterfWarningObserver
{
public:

  virtual ~CATIPolyInterfWarningObserver() {}

  /**
   * When the observer is attached and each time a new interference is build,
   * this function is called.
   */
  virtual void ProcessWarning(const CATPolyInterferenceWarning * warning) = 0;

protected:

  /**
   * Constructor
   */
  CATIPolyInterfWarningObserver() {}
  
};

#endif // CATIPolyInterfWarningObserver_h
