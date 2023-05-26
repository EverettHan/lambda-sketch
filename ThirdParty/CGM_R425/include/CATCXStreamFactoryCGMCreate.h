/* -*-c++-*- */
#ifndef CATCXStreamFactoryCGMCreate_h
#define CATCXStreamFactoryCGMCreate_h

#include "ExportedByCATSubdOperator.h"
#include "CATBaseUnknown.h"

/**
* Interface to manage persistency with CATMathStream/CACGMStream infrastructure
*/
class ExportedByCATSubdOperator CATCXStreamFactoryCGMCreate : public CATBaseUnknown
{
  CATDeclareClass;
  
public:
  CATCXStreamFactoryCGMCreate();
  ~CATCXStreamFactoryCGMCreate();

  HRESULT __stdcall CreateInstance(void **oPPV) ; 
};


#endif



