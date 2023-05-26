#ifndef CATDialogBoxCheckerAutoNotification_H
#define CATDialogBoxCheckerAutoNotification_H

#include "DI0PANV2.h"

#include "CATNotification.h"

class ExportedByDI0PANV2 CATDialogBoxCheckerAutoNotification : public CATNotification
{
  CATDeclareClass;

public:
  CATDialogBoxCheckerAutoNotification();
  virtual ~CATDialogBoxCheckerAutoNotification();

private:
  CATDialogBoxCheckerAutoNotification(const CATDialogBoxCheckerAutoNotification &iObjectToCopy);
};

#endif
