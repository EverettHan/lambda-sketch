#ifndef CATFastRunBlackBoxOperatorExt_H_
#define CATFastRunBlackBoxOperatorExt_H_

// Prototype d'operateur Fast Update BlackBox Solution
#include "BODYNOPE.h"
#include "CATExtTopOperator.h"
#include "CATCGMNewArray.h"
#include "CATBasicFastRun.h"

class CATContextForFastRun;
class CATFastRunBlackBoxOperatorContextForFastRun;

class CATFastRunBlackBoxOperatorExt : public CATExtTopOperator
{
public : 
  CATFastRunBlackBoxOperatorExt();
  ~CATFastRunBlackBoxOperatorExt();

    CATCGMNewClassArrayDeclare;        // Pool allocation

  CATContextForFastRun *                        GetContextForFastRun();
  CATFastRunBlackBoxOperatorContextForFastRun * GetFastRunBlackBoxOperatorContextForFastRun();
  CATContextForFastRun *                        GetOrCreateContextForFastRun();
  CATFastRunBlackBoxOperatorContextForFastRun * GetOrCreateFastRunBlackBoxOperatorContextForFastRun();

  void SetCheckType(CATFastRunBlackBoxCheckType iType);
  CATFastRunBlackBoxCheckType GetCheckType();

  void RequireDefinitionOfInputAndOutputObjects();



  //int FastRun();

};

//ExportedByBODYNOPE CATFastRunBlackBoxOperator* CATCreateFastRunBlackBoxOperator (CATGeoFactory*     iContainer, CATTopData *iData );
#endif
