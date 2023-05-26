// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanObserver.h
// Header definition of CATPolyBooleanObserver
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2007 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanObserver_H
#define CATPolyBooleanObserver_H

#include "CATPolyBooleanOperators.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolyBars;


/*
Class watching the boolean events which edit the operands.
*/
class ExportedByCATPolyBooleanOperators CATPolyBooleanObserver
{

public:

  //
  // Listening to the refinement events.  A refinement event has a well-defined specification.
  // To refine the mesh, it performs the operations in this sequence:
  //    1) Add all the new vertices.
  //    2) Then, for each triangle to be refined:
  //       (a) Remove triangle.
  //       (b) Add new triangles splitting the triangle.
  //

  // Call made just before refinement of an operand.
  virtual HRESULT PrepareToRefineOperand (const CATIPolyMesh& iOperand);

  // Call made right after refinement of an operand.
  virtual HRESULT ReactToRefineOperand (const CATIPolyMesh& iOperand);

public:

  //
  // Listening to the refinement events.  A refinement event has a well-defined specification.
  // To refine the bars (free bars), it performs the operations in this sequence:
  //    1) Add all the new vertices.
  //    2) Then, for each bar to be refined:
  //       (a) Remove bar.
  //       (b) Add new bars splitting the bar.
  //

  // Call made just before refinement of an operand.
  virtual HRESULT PrepareToRefineOperand (const CATPolyBars& iOperand);

  // Call made right after refinement of an operand.
  virtual HRESULT ReactToRefineOperand (const CATPolyBars& iOperand);

public:

  virtual HRESULT ReactToCopyTriangle (const int iTriangleFrom, const CATIPolyMesh& iOperandFrom,
                                       const int iTriangleTo, const CATIPolyMesh& iOperandTo);

  virtual HRESULT ReactToCopyVertex (const int iVertexFrom, const CATIPolyMesh& iOperandFrom,
                                     const int iVertexTo, const CATIPolyMesh& iOperandTo);

public:

  // Call made after definition of an intersection bar.
  virtual HRESULT ReactToDefineIntersectionBar (CATPolyBars& iBars, const int iBar,
                                                const int triangleOtherMesh = 0);

};

#endif
