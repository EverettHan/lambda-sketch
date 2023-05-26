#ifndef CATIPGMPolyTopOperator_h_
#define CATIPGMPolyTopOperator_h_

// COPYRIGHT DASSAULT SYSTEMES 2017

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"
#include "CATErrorDef.h"

class CATBody;
class CATCGMOutput;
class CATCGMStream;
class CATExtCGMReplay;
class CATGMPolyOperTopExt;
class CATGeoFactory;
class CATString;
class CATTopData;
class CATError;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMPolyTopOperator;

/** @nodoc */
class ExportedByCATGMOperatorsInterfaces CATIPGMPolyTopOperator: public CATIPGMTopOperator
{
public:
  /**
  * Constructor
  */
  CATIPGMPolyTopOperator();

  /**
  * Computation method returning the result Body (may be null), including CATTry/CATCatch mechanism
  * This method guarantees that the potential error is caught
  */
  virtual HRESULT RunAndGetResult(CATBody * &oResultBody, CATError * &oResultError) = 0;


protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMPolyTopOperator(); // -> delete can't be called
};

#endif /* CATIPGMPolyTopOperator_h_ */
