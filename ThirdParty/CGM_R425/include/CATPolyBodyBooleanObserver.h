// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyBooleanObserver.h
//
//===================================================================
// September 2013 Creation: ndo
//===================================================================
#ifndef CATPolyBodyBooleanObserver_H
#define CATPolyBodyBooleanObserver_H

//#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

#include "CATPolyBodyBinaryObserver.h"
#include "CATPolyBoolean.h"

class CATPolyBody;
class CATMathTransformation;
class CATPolyBodyBooleanOptions;
class CATString;
class CATechExt;


/**
 * Observer for the Boolean operator between solid operands.
 * The capture observer derives from this class to record events and data from the Boolean operator (Phoenix).
*/
class CATPolyBodyBooleanObserver : public CATPolyBodyNaryObserver
{

public:

  virtual ~CATPolyBodyBooleanObserver () {}

public:

/** @name Events specific to the CATPolyBodyBoolean operator.
    @{ */

  /**
   * Observer call made at the beginning of the CATPolyBodyBoolean::Run method with 
   * the operands, their optional positions and the operator options and parameters.
   */
  virtual void BeforeRun (const CATPolyBody& iOperand0, const CATMathTransformation* iPosition0, 
                          const CATPolyBody& iOperand1, const CATMathTransformation* iPosition1,
                          const CATPolyBodyBooleanOptions& iOptions) = 0;

  /**
   * Observer call made at the beginning of the CATPolyBodyBoolean::GetResult method with 
   * the boolean operation performed and an optional nary observer.
   * The implementation of this observer calls the optional nary observer for all observed events.
   */
  virtual void BeforeGetResult (const CATPolyBoolean::BooleanOperation iOperation, CATPolyBodyNaryObserver* iObserver) = 0;

  virtual const CATString* GetPhoenixName () const { return 0; }

  virtual CATechExt* GetPhoenixExtension () const { return 0; }

/** @} */

};

#endif
