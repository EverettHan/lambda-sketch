// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATNavigSONotification_h
#define CATNavigSONotification_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATNotification.h"
#include <CATOmnMain.h>

class ExportedByCATOmnMain CATNavigSONotification : public CATNotification
{
  public:
    CATDeclareClass;

    CATNavigSONotification(void* xso);
    virtual ~CATNavigSONotification();
    
    void PutXSO ( void* xso );
    void* GetXSO() const;

private:
    void* _xso;
};

#endif
