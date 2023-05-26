// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanOperObserver.h
//
//===================================================================
// December 2013 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanOperObserver_H
#define CATPolyBooleanOperObserver_H

//#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"

#include "CATPolyBoolean.h"

class CATIPolyMesh;
class CATPolyExactArithmetic;
class CATPolyGriddedMeshAndBars;
class CATMathBox;


/**
 * Observer for the Boolean operator.
 * The capture observer derives from this class to record events and data from the Boolean operator (Phoenix).
*/
class CATPolyBooleanOperObserver
{

public:

  virtual ~CATPolyBooleanOperObserver () {}

public:

/** @name Observing events
    @{ */

  virtual void ReactToSetBoundingBox (const CATMathBox& iBBox) = 0;

  virtual void ReactToSetCheckOperand (const CATBoolean iCheck) = 0;

  virtual void ReactToSetOperand (const int iOperand, const CATIPolyMesh& iMesh, CATPolyGriddedMeshAndBars* iGriddedOperand) = 0;

  /**
   * Observer call made just before the operator runs.
   */
  virtual void BeforeRun (const CATPolyExactArithmetic& iExactArithmetic,
                          const CATPolyBoolean::BooleanOperation iOperation,
                          const CATBoolean iSetMembership,
                          const CATBoolean iAcceptSelfIntersectingOperands,
                          const CATBoolean iDoNotAddSecondOperand,
                          const CATBoolean iKeepPartition) = 0;

  /**
   * Observer call made just after the operator ran.
   */
  virtual void AfterRun (const CATIPolyMesh* iResult) = 0;

/** @} */

};

#endif
