#ifndef CATBodyDataForPreProcess_H
#define CATBodyDataForPreProcess_H
//--------------------------------------------------------------------------------------------------
//
// CATBodyDataForPreProcess_H : Data storage class to allow reorganisation of input bodies to the 
//                              Compatible operator
//
// Internal use only for multi-body input boolean operators :
//
//--------------------------------------------------------------------------------------------------
#include "ExportedByCATTopologicalObjects.h"
#include "CATTopData.h"
#include "ListPOfCATBody.h"
#include "CATUnicodeString.h"
#include "CATMathInline.h"

#include "CATMathBox.h"
#include "CATLISTP_CATMathBox.h"

class CATTopOperator;

class ExportedByCATTopologicalObjects CATBodyDataForPreProcess
{
public:
  int _Vxs;
  int _Eds;
  int _Facs;
  int _Vols;
  CATMathBox _Box;
  CATBody* _Body;
  CATBodyDataForPreProcess(CATBody* iBody);
  ~CATBodyDataForPreProcess() {};
  void MergeData(CATBodyDataForPreProcess* iData);
  static void PreProcessBodyListForPerf(CATTopOperator* iOp, CATLISTP(CATBody)* iBodyList);
};

CATCGMLISTPP_DECLARE(CATBodyDataForPreProcess);

#endif

