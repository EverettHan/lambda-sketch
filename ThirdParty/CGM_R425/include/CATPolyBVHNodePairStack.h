//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Stack of CATPolyBVHNodePair
// First in, first out
// Instantiate objects for you so you don't have to worry about memory
//
//=============================================================================
//  2009-03-12  JXO: New.
//  2015-04-23  JXO: Warning correction
//=============================================================================
#ifndef CATPolyBVHNodePairStack_H
#define CATPolyBVHNodePairStack_H

class CATPolyBVHNodePair;

#include "PolyBVH.h"

#include "CATErrorDef.h"
#include "CATMutex.h"
#include "CATWaitingPoint.h"

#include "CATPolyBVHNodePair.h"

#include "CATThreadSafeStack.h"

/**
 * Stack to manage couples that are potentially intersecting.
 * See @CATPolyBVHNodePair for details about couples.
 * You can add elements with the Push method. Instantiation is done for you.
 * Pops gives you the first added couple (first in, first out.)
 * This class is 100% thread safe.
 */

class ExportedByPolyBVH CATPolyBVHNodePairStack : public CATThreadSafeStack<CATPolyBVHNodePair>
{
public:
  CATPolyBVHNodePairStack(const CATPolyBVHNodePairStack & iCopy);
  CATPolyBVHNodePairStack(const CATBoolean iWaitForPop = TRUE);
  ~CATPolyBVHNodePairStack();

  /**
   * <b>Role</b>: Overwrites the content of the stack with this new stack.
   */
  CATPolyBVHNodePairStack & operator = (const CATPolyBVHNodePairStack & iCopy)
  {
    Copy(iCopy);
    return *this;
  }

};

#endif // !CATPolyBVHNodePairStack_H
