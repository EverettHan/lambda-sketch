// COPYRIGHT Dassault Systemes 2009
//===================================================================
// This is the adaptor that implementor of itf CATIOmyEditorNotification should C++ derived from

/**
 * @level Protected
 * @usage U2
 */

#ifndef CATOmyEditorNotificationAdapter_H
#define CATOmyEditorNotificationAdapter_H

#include "CATIOmyEditorNotification.h"
#include "CATOMYBaseSession.h"
#include "CATOmyIterator.h"

class ExportedByCATOMYBaseSession CATOmyEditorNotificationAdapter: public CATIOmyEditorNotification
{
public:
  void OnOpenForEditor (CATOmyIterator & iCmpIter);
  void OnLocalSaveForEditor ();
 
};

#endif // CATOmyEditorNotificationAdapter_H
