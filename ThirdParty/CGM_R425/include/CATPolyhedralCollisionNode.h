// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyhedralCollisionNode.h
// Header definition of CATPolyhedralCollisionNode
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// January 2014 Creation JXO
//===================================================================
#ifndef CATPolyhedralCollisionNode_H
#define CATPolyhedralCollisionNode_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyEKBVHTreeSet.h"
#include "CATPolyBodySetCollisionDetection.h"

// Experience kernel
#include "EKNode.h"

// System
#include "CATErrorDef.h"
#include "CATUnicodeString.h"



class ExportedByPolyEKNodes CATPolyhedralCollisionNode : public CATPolyEKBVHTreeSet
{
public:
  /** Basic constructor */
  CATPolyhedralCollisionNode(const CATUnicodeString& nodename = CATUnicodeString(""));
  /** Destructor */
  ~CATPolyhedralCollisionNode();

  /** Implements EK::Node. Computes collisions using commands passed as JSON
   * @param input JSON
   *        Available "command": "HandShake", "RunCollisionDetection", "FullReset"
   *        Available variables: nbthreads
   */
  HRESULT OnText  (const CATUnicodeString& input, EK::Channel& origin);

protected:
  // Run state
  CATPolyBodySetCollisionDetection * m_CollisionOper;
  int m_nbthreads;
};

#endif

