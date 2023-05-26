/* -*-c++-*- */
#ifndef CATAdvancedLightTopOpFactory_h
#define CATAdvancedLightTopOpFactory_h

#include "FrFTopologicalOpeLight.h"
#include "CATExtCGMReplay.h"
//#include "CATCGMNewArray.h"

/**
* Interface to manage persistency with CATMathStream/CACGMStream infrastructure
*/
class ExportedByFrFTopologicalOpeLight CATAdvancedLightTopOpFactory : public CATExtCGMReplay
{
  CATDeclareClass;
  
public:
  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
  void GetSharedlibOfOperator(const char *operatorId, char* & sharedlib);

  HRESULT GetAvailableOperators(CATListOfCATString &OpIds);
};

#endif
