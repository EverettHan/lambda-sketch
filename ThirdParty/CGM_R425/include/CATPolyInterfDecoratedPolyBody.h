// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfDecoratedPolyBody.h
//
//===================================================================
//
// Usage notes:
// Class adding additional informations on a polybody.
//
//===================================================================
//
// Sep 2009 Creation: JS9
// Apr 2013 Modification JXO: IsEmpty
// Jul 2013 Modification JXO: CATTolerance
// Aug 2015 Modification JXO: Permanently switch to doubles for XSCale compliance
//===================================================================

#ifndef CATPolyInterfDecoratedPolyBody_h
#define CATPolyInterfDecoratedPolyBody_h

#include "CATPolyBoundingVolumeOperators.h"

// Poly
#include "CATPolyBodyIsGeometricallyClosed.h"
#include "CATPolySetOfMutex.h"

// System
#include "CATBoolean.h"
#include "CATListPV.h"
class CATMathBox;
class CATMapOfPtrToPtr;

// Math
#include "CATTolerance.h"
class CATMathVector;
#include "CATMathTransformation.h"

// Polyhedral
class CATIPolySurface;
class CATIPolyMesh;
class CATBVHNodeConst;
class CATPolyVertex;
class CATPolyEdge;
class CATPolyVertexFacetNeighborhoodIterator;
class CATPolyEdgeVertexFacetNeighborhoodIterator;
class CATPolyFace;
class CATIPolySurfaceVertexPositionConstLayer;
class CATMapOf3DoublesToInt;
class CATListOfDecoVertexList;
class CATPolyInterfDecoListPV;

// Interference
#include "CATPolyInterfDecoratedTree.h"
class CATPolyInterferenceDecoratedSurface;
class CATPolyInterfDecoratedObjectsVisitor;

/**
 * Iterator on all the meshes registered in the polybody.
 * This function will not iterate on all the faces of
 * the polybody, but only on the already registered meshes.
 */
class CATIDecoPBDecoratedSurfaceIterator
{
public:
  CATIDecoPBDecoratedSurfaceIterator() {}
  virtual ~CATIDecoPBDecoratedSurfaceIterator() {}

  virtual void Begin() = 0;
  virtual void operator++() = 0;
  virtual CATBoolean End() = 0;

  virtual CATPolyInterferenceDecoratedSurface * operator*() = 0;
};

/**
 * Iterator on the faces of the polybody (given as meshes).
 * This iterator may iterator may iterate on all or only part of the meshes.
 * Each request for a mesh might require the creation of the mesh.
 * So whenever possible, use the DecoratedSurfaceIterator.
 */
class CATIDecoPBSurfaceIterator
{
public:
  CATIDecoPBSurfaceIterator() {}
  virtual ~CATIDecoPBSurfaceIterator() {}

  virtual void Begin() = 0;
  virtual void operator++() = 0;
  virtual CATBoolean End() = 0;

  virtual CATIPolySurface * operator*() = 0;
};


/**
 * Class adding additional informations on a polybody.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfDecoratedPolyBody
{
public:

  CATPolyInterfDecoratedPolyBody(const CATBVHNodeConst & node,
                                 CATPolyInterfDecoratedTree & parentTree,
                                 CATPolyInterfClashContactOper::AccuracyChooser * accuracyChooser,
                                 const CATTolerance & iTol);
  virtual ~CATPolyInterfDecoratedPolyBody();

  /**
   * Get the sag of the polybody
   */
  inline double GetAccuracy() const;

  /**
   * Get whether the polybody is surfacic or not.
   */
  inline CATBoolean IsSurfacic() const;

  /**
   * Get wether the polybody is a closed volume or not.
   */
  CATBoolean IsClosed();

  /**
   * Get wether the polybody is empty.
   */
  CATBoolean IsEmpty();

  /**
   * @return Additional positionning applied to the polybody.
   */
  inline const CATMathTransformation & GetPosition() const;

  /**
   * Get the mesh corresponding to a leaf node in the BVH tree.
   * Returns NULL is the node does not correspond to a face
   * of the polybody. The mesh might need to be constructed and
   * must be realeased after its used.
   */
  CATIPolySurface * GetCorrespondingFace(const CATBVHNodeConst & leafNode) const;

  /**
   * Get the mesh corresponding to a node (it might need to be constructed).
   * The decorated mesh if constructed in not already done.
   * @param leafNode must be a leaf node of the BVH tree.
   */
  CATPolyInterferenceDecoratedSurface * GetCorrespondingSurface(const CATBVHNodeConst & leafNode,
                                                                CATBoolean computeNormals,
                                                                const CATPolyFace * pFace);

  /**
   * Translate the PolyBody, faster than Move.
   */
  void Translate(const CATMathVector & iTranslation);

  /**
   * Move the polybody by a transformation
   */
  void Move(const CATMathTransformation & transfo);

  /**
   * Get the corresponding CATPolyBody.
   * If you need all the the possible information (i.e. Cell layers), you can have it.
   * On the other hand, if you need only surfaces and if macro topology is not mandatory,
   * pass iWithFaceEdges as FALSE. This is much better for performances. 
   */
  const CATPolyBody * GetPolyBody(CATBoolean iWithFaceEdges = FALSE) const;

  /**
   * Get the BVH node corresponding to the polybody.
   */
  inline const CATBVHNodeConst & GetCorrespondingNode() const;

  /**
   * Get the absolute transformation of the tree the node belongs to.
   */
  inline const CATMathTransformation & GetTreeTransformation() const;

  /**
   * Get an instance of the decorated mesh iterator.
   * Must be deleted afterwards.
   */
  CATIDecoPBDecoratedSurfaceIterator * GetDecoratedSurfaceIterator() const;

  /**
   * Get an instance of the face iterator which iterate only on
   * the face which are not registered.
   * Must be delete afterwards.
   */
  CATIDecoPBSurfaceIterator * GetUnregisteredFaceIterator() const;

  /**
   * Get an iterator on all the faces of the polybody.
   * Default implementation use the registered and unregistered
   * iterators.
   * Must be deleted afterwards.
   */
  CATIDecoPBSurfaceIterator * GetFaceIterator() const;

  /**
   * Return NULL if the node does not correspond to a registered node
   */
  CATPolyInterferenceDecoratedSurface * GetCorrespondingSurfaceIfRegistered(const CATBVHNodeConst & leafNode) const;

  /**
   * Accept a visitor and call its visit method on the children meshes.
   */
  void Accept(CATPolyInterfDecoratedObjectsVisitor & visitor);

  /**
   * Flush all the meshes registered in thr polybody but keep
   * the normals.
   */
  void FlushSurfaces();

  // Return whether a transformation is a translation
  // If so the parameter oTranslation is updated with the translation
  static CATBoolean IsTranslation(const CATMathTransformation & transfo);

  // JXO on 2010/08/12: we can release the faces once inclusion has been detected
  void ReleaseIsClosed();

  // Returns the CATTolerance associated with this CATPolyInterfDecoratedPolyBody
  const CATTolerance & GetTolerance() const {return m_PolyBodyTolerance;}

  HRESULT ComputePermanentAccurateNormals();
  void ComputeVerticesPermanentNormals(
                                       CATMapOf3DoublesToInt & edgeVerticesMap,
                                       CATListOfDecoVertexList & vertexBuffer);
  
protected:
  
  /**
   * Modify the accuracy.
   */
  void SetAccuracy(double accuracy);

  inline CATBoolean IsTransfoIdentity() const {return _bIsIdentity;}
  inline CATBoolean IsTransfoTranslation() const {return _bIsTranslation;}
  inline void GetTranslation(CATMathVector & translation) const {_oPosition.GetVector(translation);}

  // To be able to access above methods
  friend class CATPolyInterferenceDecoratedSurface;
  friend class CATPolyInterferenceDecoratedMesh;
  friend class CATPolyInterferenceDecoratedCanonic;

private:

  //---------------------------------------------------------------------
  // Compute the absolute position of the node
  CATMathTransformation ComputeAbsolutePosition() const;

  // Compute wether the position is a general transformation, a translation or the identity
  void GetPositionTransfoType();

  void InsertDecoSurface(const CATBVHNodeConst * node, CATPolyInterferenceDecoratedSurface * surface);
  CATPolyInterferenceDecoratedSurface * LocateDecoSurface(const CATBVHNodeConst * node) const;
  //---------------------------------------------------------------------
  CATMathTransformation _oPosition; // Additional position of the PolyBody
  CATPolyInterfDecoratedTree & _rParentTree;

  const CATTolerance & m_PolyBodyTolerance;

  double _dAccuracy;
  CATBoolean _bIsSurfacic;
  // Keep the status also on the decorated polybody to avoid accessing the node each time
  // since it requires to use a mutex.
  CATBoolean _bIsClosed;
  CATBoolean _bIsClosedStatusUpToDate;
  CATBoolean _bHasInterfNormals;
  // Additional informations on the positioning
  CATBoolean _bIsIdentity;
  CATBoolean _bIsTranslation;

  const CATBVHNodeConst & _rPbNode;

  CATMapOfPtrToPtr _oMapNodeToSurface;

  static CATPolySetOfMutex _oCloseFlagMutex;
  //---------------------------------------------------------------------
  CATPolyBodyIsGeometricallyClosed _ClosedChecker;

  CATListPV _oPermanentInterfNormalBuffer;
};

//-----------------------------------------------------------------------------
inline double CATPolyInterfDecoratedPolyBody::GetAccuracy() const
{
  return _dAccuracy;
}
//-----------------------------------------------------------------------------
inline CATBoolean CATPolyInterfDecoratedPolyBody::IsSurfacic() const
{
  return _bIsSurfacic;
}
//-----------------------------------------------------------------------------
inline const CATMathTransformation & CATPolyInterfDecoratedPolyBody::GetPosition() const
{
  return _oPosition;
}
//-----------------------------------------------------------------------------
inline const CATBVHNodeConst & CATPolyInterfDecoratedPolyBody::GetCorrespondingNode() const
{
  return _rPbNode;
}
//-------------------------------------------------------------------------------
const CATMathTransformation & CATPolyInterfDecoratedPolyBody::GetTreeTransformation() const
{
  return _rParentTree.GetCurrentPosition();
}
//-------------------------------------------------------------------------------

#endif // CATPolyInterfDecoratedPolyBody_H
