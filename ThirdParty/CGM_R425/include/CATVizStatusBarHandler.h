#ifndef CATVizStatusBarHandler_H
#define CATVizStatusBarHandler_H

#include "CATVisFoundation.h"

#include  "CATUnicodeString.h"


// COPYRIGHT DASSAULT SYSTEMES 2001

class ExportedByCATVisFoundation CATVizStatusBarHandler
{
public:
  CATVizStatusBarHandler() {};
  virtual ~CATVizStatusBarHandler();
  virtual void SetStatusBarText(CATUnicodeString i_message) {};
};

#endif
