#ifndef CATExitSelectNotif_H_
#define CATExitSelectNotif_H_

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATNotification.h"

class ExportedByCATAfrSelection CATExitSelectNotif : public CATNotification
{
  CATDeclareClass;

  public:
   CATExitSelectNotif ();
   virtual ~CATExitSelectNotif();
};
#endif 
  

