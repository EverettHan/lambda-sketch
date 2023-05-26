// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPDefinitionObserver.h
//
//===================================================================
//
// Usage notes: Observer on CATPolyPPDefinition
//
//===================================================================
//
// 2015-08-31 JXO: Creation
//===================================================================

#ifndef CATPolyPPDefinitionObserver_HH
#define CATPolyPPDefinitionObserver_HH


// ExportedBy
#include "PolyPathPlanning.h"

// Poly
#include "CATPolyObserver.h"

class CATPolyPPPosition;

class ExportedByPolyPathPlanning CATPolyPPDefinitionObserver : public CATPolyObserver<CATPolyPPDefinitionObserver>
{
public:
  virtual void SetStart(CATPolyPPPosition * iStart) = 0;
  virtual void SetTarget(CATPolyPPPosition * iTarget) = 0;
  virtual void InsertNewBlackHole(CATPolyPPPosition * iBlackHole) = 0;
  virtual void AppendIntermediateTarget(CATPolyPPPosition * iIntermediatePoint) = 0;

protected:
  CATPolyPPDefinitionObserver();
  ~CATPolyPPDefinitionObserver();
};

#endif
