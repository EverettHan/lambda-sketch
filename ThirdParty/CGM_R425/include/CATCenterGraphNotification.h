#ifndef CATCenterGraphNotification_h
#define CATCenterGraphNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATNotification.h"
#include "CATAfrFoundation.h"
#include "CATString.h"

class CATCmdWorkshop;
class CATCmdWorkbench;

class ExportedByCATAfrFoundation CATCenterGraphNotification : public CATNotification
{
  CATDeclareClass;
  
  public:

    CATCenterGraphNotification(const CATString & type);
    virtual ~CATCenterGraphNotification();

    const CATString & GetType();
    
  private:
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATCenterGraphNotification (const CATCenterGraphNotification &);
    CATCenterGraphNotification & operator= (const CATCenterGraphNotification &);

    CATString _type;
};

#endif
