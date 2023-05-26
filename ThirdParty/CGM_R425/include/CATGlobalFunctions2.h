#ifndef CATGlobalFunctions2_h
#define CATGlobalFunctions2_h

// COPYRIGHT DASSAULT SYSTEMES 2000


#include "CATLifSpecs.h"
#include "CATICkeScalesServices.h"
#include "CATIKweNamingManager.h"
#include "CATIKweUIServices.h"
#include "CATIKweDicoServices.h"
#include "CATIPyInterpreter.h"
#include "CATIResourceManagementServices.h"

class ExportedByCATLifSpecs CATGlobalFunctions2 {
public:
  static CATIKweNamingManager_var GetNamingManager();

  static CATICkeScalesServices_var GetScalesServices();

  static CATIKweUIServices_var GetUIServices();

  static CATIKweDicoServices_var GetDicoServices();

  static CATIResourceManagementServices_var GetResourceManagementServices();

  static CATIPyInterpreter_var GetPyInterpreter();

private:
};

#endif 
