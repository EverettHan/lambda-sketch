// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyhedralClashNode.h
// Header definition of CATPolyhedralClashNode
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// November 2013 Creation JXO
//===================================================================
#ifndef CATPolyhedralClashNode_H
#define CATPolyhedralClashNode_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyEKBVHTreeSet.h"

// Experience kernel
#include "EKNode.h"

// System
#include "CATErrorDef.h"
#include "CATUnicodeString.h"



class ExportedByPolyEKNodes CATPolyhedralClashNode : public CATPolyEKBVHTreeSet
{
public:
  /** Basic constructor */
  CATPolyhedralClashNode(const CATUnicodeString& nodename = CATUnicodeString(""));
  /** Destructor */
  ~CATPolyhedralClashNode();

  /** Implements EK::Node. Computes clash using commands passed as JSON
   * @param input JSON
   *        Available "command": "HandShake", "RunClashContact", "FullReset"
   *        Available variables: nbthreads
   */
  HRESULT OnText  (const CATUnicodeString& input, EK::Channel& origin);

protected:
  // Run state
  CATPolyVisuClashContactOper * m_ClashOper;
  int m_nbthreads;
};

#endif

