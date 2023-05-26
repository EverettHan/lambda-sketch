// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHTreeRepBuilderObserver
//
//===================================================================
// 2015-03-03   JXO
//      * New
//===================================================================
#ifndef CATBVHTreeRepBuilderObserver_H
#define CATBVHTreeRepBuilderObserver_H

#include "PolyVisuBVH.h"

// Poly
#include "CATPolyObserver.h"
class CATBVHNode;

class CATRep;
class CAT4x4Matrix;

class ExportedByPolyVisuBVH CATBVHTreeRepBuilderObserver : public CATPolyObserver<CATBVHTreeRepBuilderObserver>
{
public:
  /** Constructor */
  CATBVHTreeRepBuilderObserver();
  /** Destructor */
  virtual ~CATBVHTreeRepBuilderObserver();
  /** Notify that a terminal node has been created on this ternimal rep */
  virtual void AddTerminalRepNode(CATBVHNode * iNode, CATRep * iRep, const CAT4x4Matrix * iMat) = 0;
  /** Notify that this already added rep could have had its buffer changed */
  virtual void RefreshBuffer(CATRep & iRep) = 0;
};

#endif
