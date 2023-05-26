/* -*-c++-*- */
#ifndef CATAdvancedLightTopOpFactoryCreate_h
#define CATAdvancedLightTopOpFactoryCreate_h

#include "FrFTopologicalOpeLight.h"
#include "CATBaseUnknown.h"

/**
* Interface to manage persistency with CATMathStream/CACGMStream infrastructure
*/
class ExportedByFrFTopologicalOpeLight CATAdvancedLightTopOpFactoryCreate : public CATBaseUnknown
{
  CATDeclareClass;
  
public:
   CATAdvancedLightTopOpFactoryCreate();
  ~CATAdvancedLightTopOpFactoryCreate();

  HRESULT __stdcall CreateInstance(void **oPPV) ; 
};


#endif


