#ifndef CATOmyPowerIOAutoTransaction_H
#define CATOmyPowerIOAutoTransaction_H

#include "CATOMYCuteIO.h"
#include "CATAssert.h"
#include "CATBoolean.h"

class CATOmyPowerIOCachingBusinessLogic;

class ExportedByCATOMYCuteIO CATOmyPowerIOAutoTransaction
{
public:
  CATOmyPowerIOAutoTransaction(CATBoolean iStartTransaction=TRUE);
  ~CATOmyPowerIOAutoTransaction();
  
  void OnStartTransaction();
  
  inline CATOmyPowerIOCachingBusinessLogic* operator->() const     { CATAssert(_BlForTransaction) ; return _BlForTransaction; }
   
  inline CATBoolean operator!() const                              { return (!_BlForTransaction) ? (TRUE) : (FALSE); }
  inline operator CATOmyPowerIOCachingBusinessLogic*()             { return _BlForTransaction; }
  inline operator const CATOmyPowerIOCachingBusinessLogic*() const { return _BlForTransaction; }
  
private:
  CATOmyPowerIOCachingBusinessLogic* _BlForTransaction;
  CATOmyPowerIOCachingBusinessLogic* _BlForInform;
};

#endif
