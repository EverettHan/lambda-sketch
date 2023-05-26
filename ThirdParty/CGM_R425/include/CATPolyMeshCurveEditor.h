// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshCurveEditor.h
//
//===================================================================
// April 2020 - Creation
//===================================================================
#pragma once

#include "PolyBodyBoolean.h"
#include "CATErrorDef.h"   // For the definition of HRESULT.

#include <memory>

class CATIPolyMeshCurve;
class CATPolyMeshCurveEditorImpl;
class CATPolyBodyOverlayOptions;
class CATMathPoint;


/**
 * Editor of mesh curves.
 */
class ExportedByPolyBodyBoolean CATPolyMeshCurveEditor
{

public:

  /**
   * Constructor of an editor of mesh-curves.
   * @param iOptions
   *   @see CATPolyBodyOverlayOptions
   */
  CATPolyMeshCurveEditor (CATIPolyMeshCurve& mc,
                          std::shared_ptr<const CATPolyBodyOverlayOptions> iOptions = nullptr);

  ~CATPolyMeshCurveEditor ();

public:

  /**
   * Begins an edition pass of the mesh curve.
   */
  HRESULT BeginEdit ();

  /**
   * Edits the position of a mesh point from the curve.
   */
  HRESULT Edit (int cv, const CATMathPoint& P);

  /**
   * Ends of the edition pass of the mesh curve.
   * After edition of the positions, the mesh curve is updated 
   * to remain on the mesh.  If it cannot be edited, none of the
   * positions from the mesh curve are updated during this edit pass.
   */
  HRESULT EndEdit ();

private:

  CATPolyMeshCurveEditorImpl* _Operator;

};
