#ifndef CATMultiSelEvent_H
#define CATMultiSelEvent_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATNotification.h"
#include "CATVisFoundation.h"
#include "CATPickPathList.h"

/**
 * Event to indicate a multi-selection.
 * <b>Role</b>: This class stores the representations impacted by a multi-selection
 * as a <tt>CATPickPathList</tt>.
 */
class ExportedByCATVisFoundation CATMultiSelEvent : public CATNotification
{
  CATDeclareClass;

public:

  virtual ~CATMultiSelEvent();

  /** Constructs an empty multi-selection event.*/
  CATMultiSelEvent();

  /** Returns the list of selected pick-paths. */
  CATPickPathList & GetContainedObject();
  
protected:
  CATPickPathList _containedObject; // list of selected objects
};

#endif // CATMultiSelEvent_H
