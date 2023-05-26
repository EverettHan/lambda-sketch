// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuBVHTreeSetObserverImpl.h
//
//===================================================================
//
// Usage notes:
// This class observes CATPolyVisuBVHTreeSet
//
//===================================================================
//
// Oct 2011 Creation: JXO
//===================================================================

#ifndef CATPolyVisuBVHTreeSetObserverImpl_h
#define CATPolyVisuBVHTreeSetObserverImpl_h

#include "PolyVisuClash.h"

// Poly
class CATPolyBVHTreeVisualizationFilter;
#include "CATPolyVisuBVHTreeSetObserver.h"

// PolyhedralMathematics
#include "CATBVHTreeBuilder.h"
#include "CATPolyBoundingVolume.h"

// Math
#include "CATMathTransformation.h"

// Visualization
class CAT4x4Matrix;
class CAT3DRep;

/**
 * This class observes CATPolyVisuBVHTreeSet
 */
class ExportedByPolyVisuClash CATPolyVisuBVHTreeSetObserverImpl : public CATPolyVisuBVHTreeSetObserver
{
public:
  /**
   * Constructor and destructor
   */
  CATPolyVisuBVHTreeSetObserverImpl();
  virtual ~CATPolyVisuBVHTreeSetObserverImpl();

  /**
   * BVHTreeSet
   */
  virtual HRESULT AddTree(int objectId, CATBVHTree * object, const CATMathTransformation * pos);
  virtual HRESULT ModifyTreePosition(int objectId, const CATMathTransformation * pos);
  virtual HRESULT DesactivateTree(int objectId);
  virtual HRESULT ActivateTree(int objectId);
  virtual HRESULT DeactivateAll();
  virtual HRESULT ActivateAll();
  virtual HRESULT RemoveTree(int objectId);
  virtual HRESULT PrepareToRemoveTree(int objectId);
  virtual HRESULT PrepareToFlushTree(int objectId);
  virtual int CheckPoint();

  /**
   * PolyBody
   */
  virtual CATBoolean Enable();
  virtual CATBoolean Disable();
  virtual void SetSpatialOptimizationMode(CATBVHTreeBuilder::SpatialOptimization iSpatialOptimization);
  virtual void SetBVType(CATPolyBoundingVolume::TypeID bvType);
  virtual HRESULT AddPolyBody(int objectId, CATPolyBody * object, const CATMathTransformation * pos, CATPolyBodyBVHTreeSet::EntityType iType);
  virtual HRESULT AddSetOfPolyBodies(int objectId,
                                     CATListPV & iPolyBodies,
                                     CATListPV * iPositions,
                                     const CATMathTransformation * iOverallPositionMatrix,
                                     CATPolyBodyBVHTreeSet::EntityType iType);
  virtual HRESULT ModifyPolyBodyPosition(int objectId, const CATMathTransformation * pos);
  virtual HRESULT DeactivatePolyBody(int objectId);
  virtual HRESULT ActivatePolyBody(int objectId);
  virtual HRESULT DeactivateAllBodies();
  virtual HRESULT ActivateAllBodies();
  virtual HRESULT RemovePolyBody(int objectId);
  virtual void UseCanonics(CATBoolean iUseCanonics);

  /**
   * Visu
   */
  virtual void SetObserved(CATPolyVisuBVHTreeSet*);
  virtual void SetRepSpatialOptimizationMode(CATBVHTreeBuilder::SpatialOptimization iSpatialOptimization);
  virtual void SetRepBVType(CATPolyBoundingVolume::TypeID bvType);
  virtual void SetFilter(CATPolyBVHTreeVisualizationFilter * filter);
  virtual HRESULT AddRep(int objectId, CAT3DRep * object, const CAT4x4Matrix * pos, CATBoolean iDoGenerateRepPath, CATBVHTreeRepBuilder::EntityType iEntityTypes, CATBoolean iExpandToFaces);
  virtual HRESULT AddVisuRep(int objectId, CAT3DRep * object, const CATMathTransformation * pos, CATBoolean iDoGenerateRepPath, CATBVHTreeRepBuilder::EntityType iEntityTypes, CATBoolean iExpandToFaces);
  virtual HRESULT ModifyRepPosition(int objectId, const CAT4x4Matrix * pos);
  virtual HRESULT DeactivateRep(int objectId);
  virtual HRESULT ActivateRep(int objectId);
  virtual HRESULT RemoveRep(int objectId);

protected:
  CATBoolean m_isDisabled;

};

#endif /* CATPolyVisuBVHTreeSetObserverImpl_h */
