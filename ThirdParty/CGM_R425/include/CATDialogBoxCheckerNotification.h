#ifndef CATDialogBoxCheckerNotification_H
#define CATDialogBoxCheckerNotification_H

#include "DI0PANV2.h"

#include "CATNotification.h"

class ExportedByDI0PANV2 CATDialogBoxCheckerNotification : public CATNotification
{
	CATDeclareClass;
public:
	CATDialogBoxCheckerNotification();
    virtual ~CATDialogBoxCheckerNotification();
	
private:
    CATDialogBoxCheckerNotification(const CATDialogBoxCheckerNotification &iObjectToCopy);
	
};

#endif

