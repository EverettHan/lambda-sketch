// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceDecoratedCanonic.cpp
//
//===================================================================
//
// Usage notes:
// Class adding additional informations on a canonic (CATIPolySurface
// with one canonic support).
//
//===================================================================
//
// 2010-10-01 XXC: Creation
//===================================================================

#ifndef CATPolyInterferenceDecoratedCanonic_h
#define CATPolyInterferenceDecoratedCanonic_h

#include "CATPolyInterferenceDecoratedSurface.h"

// System
#include "CATMathBox.h"
#include "CATBoolean.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"

// Polyhedral
#include "CATIPolySurface.h"
#include "CATIPolySurfaceSupport.h"
#include "CATPolyBoxf.h"
#include "CATPolyMathObject.h"

// BVH
#include "CATBVHNodeConst.h"

// Interference
class CATPolyInterfDecoratedObjectsVisitor;
class CATPolyInterfDecoratedPolyBody;

/**
 * Class adding additional informations on a canonic (CATIPolySurface with one canonic support).
 */
class CATPolyInterferenceDecoratedCanonic : public CATPolyInterferenceDecoratedSurface
{
public:

  /**
   * Constructor of the mesh from a parent polybody and a
   * CATIPolySurface.
   * @param initialize only for derived classes.
   */
  CATPolyInterferenceDecoratedCanonic(CATPolyInterfDecoratedPolyBody & parentBody,
                                      const CATBVHNodeConst & node,
                                      CATIPolySurface & realCanonic,
                                      const CATPolyFace* pFace);
  virtual ~CATPolyInterferenceDecoratedCanonic();

public:

  CATPolyInterferenceDecoratedCanonic * CastAsDecoCanonic() { return this; }

public:

  /**
   * Accept a visitor and call its visit method on the children triangles.
   */
  void Accept(CATPolyInterfDecoratedObjectsVisitor & visitor);

protected:

  /** Set the vertices to their final position then update the AABB of
   *  the mesh
   */
  void PositionSurface();

private:

  //----------------------------------------------------------------------
  // Case when pos is a general transformation
  void ActualPositionSurface(const CATMathTransformation & pos);
  // Case when tranformation is a translation
  void ActualPositionSurface(const CATMathVector & pos);
  // Case of repositioning
  void RestorePosition();
  // Compute the bounding box of the positioned canonic
  HRESULT ComputeBox();
  //----------------------------------------------------------------------

 private:
  //----------------------------------------------------------------------
  CATPolyMathObject::Type _Type;
  CATPolyMathSurface * _CanonicSurface;
};

//-------------------------------------------------------------------------------
#endif // CATPolyInterferenceDecoratedPolyBody_H

