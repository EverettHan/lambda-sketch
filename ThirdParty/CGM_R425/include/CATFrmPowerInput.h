#ifndef CATFrmPowerInput_H
#define CATFrmPowerInput_H
// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------

#include "CATAfrFoundation.h"
#include "CATCallbackManager.h"

class ExportedByCATAfrFoundation CATFrmPowerInput: public CATCallbackManager
{  
  CATDeclareClass;
  
public:
 
  CATFrmPowerInput ();
  virtual ~CATFrmPowerInput();
  static CATFrmPowerInput *GetFrmPowerInput();

  CATDeclareCBEvent(PowerInputEvent);
};

#endif
