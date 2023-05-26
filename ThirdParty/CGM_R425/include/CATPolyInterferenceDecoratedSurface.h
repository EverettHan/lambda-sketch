// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceDecoratedSurface.h
//
//===================================================================
//
// Usage notes:
// Class adding additional informations on a surface
// (CATIPolySurface). A surface can then be specialized as a Mesh
// (triangulated surface) or a Canonic (sphere, cylinder, etc.)
//
//===================================================================
//
// 2010-10-01 XXC: Creation
//===================================================================

#ifndef CATPolyInterferenceDecoratedSurface_h
#define CATPolyInterferenceDecoratedSurface_h

#include "CATPolyBoundingVolumeOperators.h"

// System
#include "CATMathBox.h"
#include "CATBoolean.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"

// Polyhedral
#include "CATIPolySurface.h"
#include "CATPolyBoxf.h"
class CATPolyFace;

// Mathematics
#include "CATMathTransformation.h"

// BVH

// Interference
#include "CATPolyInterfDecoratedPolyBody.h"
class CATPolyInterfDecoratedObjectsVisitor;
class CATBVHNodeConst;
class CATPolyInterferenceDecoratedMesh;
class CATPolyInterferenceDecoratedCanonic;

/**
 * Class adding additional informations on a mesh (CATIPolySurface).
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceDecoratedSurface
{
public:

  /**
   * Static factory
   */
  static CATPolyInterferenceDecoratedSurface * CreateSurface(CATPolyInterfDecoratedPolyBody & parentBody,
                                                             const CATBVHNodeConst & node,
                                                             CATBoolean computeNormals,
                                                             const CATPolyFace * pFace);

  /**
   * Constructor of the mesh from a parent polybody and a
   * CATIPolymesh.
   * @param initialize only for derived classes.
   */
  CATPolyInterferenceDecoratedSurface(CATPolyInterfDecoratedPolyBody & parentBody,
                                      const CATBVHNodeConst & node,
                                      const CATPolyFace* pFace);
  virtual ~CATPolyInterferenceDecoratedSurface();

public:

  virtual CATPolyInterferenceDecoratedMesh * CastAsDecoMesh() { return 0; }
  virtual CATPolyInterferenceDecoratedCanonic * CastAsDecoCanonic() { return 0; }

public:

  /**
   * @return Enclosed mesh
   */
  CATIPolySurface * GetSurface() const;

  /**
   * @return CATPolyFace, if any
   */
  const CATPolyFace* GetFace() const;

  /**
   * Get the corresponding node in the BVH.
   */
  inline const CATBVHNodeConst & GetNode() const;

  /**
   * Get the bounding box of the mesh stored as floats.
   */
  inline const CATPolyBoxf & GetBoundingBoxf() const;

  // virtual inline void Destroy() = 0;

  /**
   * Get the accuracy of the mesh (sag).
   */
  double GetAccuracy() const;

  /**
   * To know wether the mesh is surfacic or volumic.
   */
  CATBoolean IsSurfacic() const;

  /**
   * Get the absolute transformation of the tree the node belongs to.
   */
  inline const CATMathTransformation & GetTreeTransformation() const;

  /**
   * @return Get the additional transformation of the mesh.
   */
  inline const CATMathTransformation & GetPosition() const;

  /**
   * Apply translation
   */
  void Translate(const CATMathVector & iTranslation);

  /**
   * Apply general transformation
   */
  void Move(const CATMathTransformation & transfo);

  /**
   * Construct a polymesh from a BVH leaf node.
   * An addref should be done afterwards.
   */
  static CATIPolySurface * ConstructFace(const CATBVHNodeConst & leafNode);

  /**
   * Accept a visitor and call its visit method on the children triangles.
   */
  virtual void Accept(CATPolyInterfDecoratedObjectsVisitor & visitor);

  /**
   * Returns parent body
   */
  const CATPolyInterfDecoratedPolyBody& GetBody() const
  {
    return _rParentBody;
  }

protected:

  /** Apply the displacements previously given through the Move and
   *  Translate methods to the surface.
   */
  void PositionSurface();

  virtual void RestorePosition() = 0;
  virtual void ActualPositionSurface(const CATMathVector & pos) = 0;
  virtual void ActualPositionSurface(const CATMathTransformation & pos) = 0;

protected:
  //----------------------------------------------------------------------
  CATPolyInterfDecoratedPolyBody & _rParentBody;

  const CATBVHNodeConst & _rNode;

  CATPolyBoxf _oBoundingBoxf; // For intersection with polyboxf
  //----------------------------------------------------------------------
  char _UpdatePosition; // 0 if no update, 1 if translation, 2 if other transformation

private:
    //useless
  //CATMathTransformation * _PositionToApply;
  CATMathTransformation _PositionToApply;
  unsigned char _iNbTransformation; // Number of successive transformations applied to the
                                    // decorated mesh. If too many transformation are applied,
                                    // coordinates are recomputed using layers.
  const CATPolyFace* m_face;
};

//-------------------------------------------------------------------------------
inline const CATBVHNodeConst & CATPolyInterferenceDecoratedSurface::GetNode() const
{
  return _rNode;
}
//-------------------------------------------------------------------------------
inline const CATPolyBoxf & CATPolyInterferenceDecoratedSurface::GetBoundingBoxf() const
{
  if (_UpdatePosition) ((CATPolyInterferenceDecoratedSurface *) this)->PositionSurface();
  return _oBoundingBoxf;
}
//-------------------------------------------------------------------------------
inline double CATPolyInterferenceDecoratedSurface::GetAccuracy() const
{
  return _rParentBody.GetAccuracy();
}
//-------------------------------------------------------------------------------
inline CATBoolean CATPolyInterferenceDecoratedSurface::IsSurfacic() const
{
  return _rParentBody.IsSurfacic();
}
//-------------------------------------------------------------------------------
inline const CATMathTransformation & CATPolyInterferenceDecoratedSurface::GetTreeTransformation() const
{
  return _rParentBody.GetTreeTransformation();
}
//-------------------------------------------------------------------------------
inline const CATMathTransformation & CATPolyInterferenceDecoratedSurface::GetPosition() const
{
  return _rParentBody.GetPosition();
}
//-------------------------------------------------------------------------------
#endif // CATPolyInterferenceDecoratedPolyBody_H

