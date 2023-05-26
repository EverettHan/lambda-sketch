//===================================================================
// COPYRIGHT Dassault Systemes 2018/01/08
//===================================================================
// CATPLMPPrimeEnv.cpp
// Header definition of class CATPLMPPrimeEnv
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/01/08 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMPPrimeEnv_H
#define CATPLMPPrimeEnv_H

#include "CATPLMServicesPPrime.h"
#include "CATUnicodeString.h"

class ExportedByCATPLMServicesPPrime CATPLMPPrimeEnv
{

public:
  static CATPLMPPrimeEnv& s();
  ~CATPLMPPrimeEnv();

  /*
  * Change the activation status of PPrime mode
  * input :
  * iActivate [in] : if 'TRUE' PPrime is activated, otherwise, PPrime is not activated
  */
  void ChangePPrimeActivation(CATBoolean iActivate);
  CATBoolean IsPPrimeActivated();
  void  ChronoSnap();
  CATLONG64 GetChrono();

private:
  CATBoolean _PLM_PPRIME_ACTIVATION;
  // Constructor
  CATPLMPPrimeEnv();
  static CATPLMPPrimeEnv _Inst;
  CATLONG64 _chrono;
};

#endif
