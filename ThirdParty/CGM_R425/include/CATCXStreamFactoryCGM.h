/* -*-c++-*- */
#ifndef CATCXStreamFactoryCGM_h
#define CATCXStreamFactoryCGM_h

#include "ExportedByCATSubdOperator.h"
#include "CATExtCGMReplay.h"
#include "CATCGMNewArray.h"

/**
* Interface to manage persistency with CATMathStream/CACGMStream infrastructure CATCXStreamFactory
*/
class ExportedByCATSubdOperator CATCXStreamFactoryCGM : public CATExtCGMReplay
{
  CATDeclareClass;
  
public:
  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
  void GetSharedlibOfOperator(const char *operatorId, char* & sharedlib);

  HRESULT GetAvailableOperators(CATListOfCATString &OpIds);

};


#endif



