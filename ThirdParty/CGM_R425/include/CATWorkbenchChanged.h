/**
 * @fullreview ERS-CVE 02:02:12
 * @error UDOO Y pas de constructeur par copie, pas d'operateur =
 */
#ifndef CATWorkbenchChanged_H
#define CATWorkbenchChanged_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrFoundation.h"
#include "CATNotification.h"

class ExportedByCATAfrFoundation CATWorkbenchChanged : public CATNotification
{
  CATDeclareClass;

  public:
    CATWorkbenchChanged();
    virtual ~CATWorkbenchChanged();

  private:
    // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
    CATWorkbenchChanged (const CATWorkbenchChanged &);
    CATWorkbenchChanged & operator= (const CATWorkbenchChanged &);

};

#endif
