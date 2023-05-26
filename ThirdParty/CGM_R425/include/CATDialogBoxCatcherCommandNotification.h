#ifndef CATDialogBoxCatcherCommandNotification_H
#define CATDialogBoxCatcherCommandNotification_H

#include "DI0PANV2.h"

#include "CATNotification.h"

class ExportedByDI0PANV2 CATDialogBoxCatcherCommandNotification : public CATNotification
{
        CATDeclareClass;
public:
        CATDialogBoxCatcherCommandNotification();
        virtual ~CATDialogBoxCatcherCommandNotification();

private:
        CATDialogBoxCatcherCommandNotification(const CATDialogBoxCatcherCommandNotification &iObjectToCopy);

};

#endif

