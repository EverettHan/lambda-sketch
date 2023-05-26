// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuBVHTreeSet.h
//
//===================================================================
//
// Usage notes:
// This class gather and arrange input representations in an efficient
// way to be used by the interference operators.
// Moreover, this class act as cache for these operators and can be
// slightly modified between calls to the operator.
//
//===================================================================
//
// Sep 2009 Creation: JXO
// Aug 2022 JXO : CloneVisuRep & SetMutexFree
//===================================================================

#ifndef CATPolyVisuBVHTreeSet_h
#define CATPolyVisuBVHTreeSet_h

#include "PolyVisuClash.h"

// Other
#include "CATMathTransformation.h"
#include "CATMapOfIntToPtr.h"
#include "CATListPV.h"
class CAT4x4Matrix;

// Visualization
class CAT3DRep;

// PolyMathematics
#include "CATPolyBodyBVHTreeSet.h"
#include "CATBVHNodeIterator.h"
#include "CATBVHAttribute.h"
#include "CATBVHTreeBuilder.h"
#include "CATPolyBoundingVolume.h"
class CATBVHTree;
class CATBVHNode;
class CATPolyBodyVisuContext;

// Polyhedral
#include "CATMapOfPtrToPtr.h"
#include "CATBVHTreeRepBuilder.h"
class CATPolyBVHTreeVisualizationFilter;
class CATPolyVisuBVHTreeSetMetaObserver;
class CATPolyVisuBVHTreeSetObserver;
class CATBVHTreeRepBuilderObserverForTreeSet;

#define CATPOLYVISUBVHTREESET_DEBUG


/**
 * This class gather and arrange input representations in an efficient
 * way to be used by the interference operators.
 * Moreover, this class act as cache for these operators and can be
 * slightly modified between calls to the operator.
 */
class ExportedByPolyVisuClash CATPolyVisuBVHTreeSet : public CATPolyBodyBVHTreeSet
{
public:


  /**
   * Constructor and destructor
   */
  CATPolyVisuBVHTreeSet();

  CATPolyVisuBVHTreeSet( const CATPolyVisuBVHTreeSet& iOther );

  virtual ~CATPolyVisuBVHTreeSet();

  /**
   * Set the spatial optimization mode to be used when the Bounding Volumes Hierachies are created.
   * Default is No Optimization.
   */
  void SetSpatialOptimizationMode(CATBVHTreeBuilder::SpatialOptimization iSpatialOptimization);

  /**
   * Set the Bounding Volumes type to be used in BVHs.
   * Default is Sphere type.
   */
  void SetBVType(CATPolyBoundingVolume::TypeID bvType);

  /**
   * Set a filter to be able to discard some of the reps or primitives.
   * NULL to unset.
   * Typical filter is CATPolyBVHTreeFilterHidden.
   */
  void SetFilter(CATPolyBVHTreeVisualizationFilter * filter);
  CATPolyBVHTreeVisualizationFilter * GetFilter() const;

  /**
   * DEPRECATED 
   * CAT4x4Matrix should never be used again, ever.
   * Use AddVisuRep instead.
   */
  HRESULT AddRep(int objectId, CAT3DRep * object, const CAT4x4Matrix * pos = NULL, CATBoolean iDoGenerateRepPath = FALSE, CATBVHTreeRepBuilder::EntityType iEntityTypes = CATBVHTreeRepBuilder::eFaceEntities, CATBoolean iExpandToFaces = FALSE);

  /**
   * Add a visu rep in the set at a certain position.
   * @return S_OK if the object could be correctly registers, E_FAIL otherwise.
   */
  HRESULT AddVisuRep(int objectId, CAT3DRep * object, const CATMathTransformation * pos = NULL, CATBoolean iDoGenerateRepPath = FALSE, CATBVHTreeRepBuilder::EntityType iEntityTypes = CATBVHTreeRepBuilder::eFaceEntities, CATBoolean iExpandToFaces = FALSE);

  HRESULT GetObjectCATRep(int iObjectId, const CATRep *& oRep ) const;

  /**
   * DEPRECATED 
   * CAT4x4Matrix should never be used again, ever.
   * Use ModifyTreePosition instead.       
   */
  HRESULT ModifyRepPosition(int objectId, const CAT4x4Matrix * pos);

  /**
   * Deactivate a rep already added by add rep.
   * The object won't be processed by operators.
   * @param objectId
   *     id of the object to desactivate.
   */
  HRESULT DeactivateRep(int objectId);
  /**
   * Activate a rep that had previously been deactivated.
   * Note that newly added reps are activated by default.
   * @param objectId
   *     id of the object to activate.
   */
  HRESULT ActivateRep(int objectId);

  /**
   * This removes the representation from the tree, and releases the memory from the pool.
   */
  HRESULT RemoveRep(int objectId);

  /**
   * Debug. You can release observer.
   */
  void RegisterVisuObserver(CATPolyVisuBVHTreeSetObserver*);
  /**
   * Debug
   */
  void UnregisterVisuObserver(CATPolyVisuBVHTreeSetObserver*);

  /**
   * When a BVHTreeSet is cloned, the clone and cloned one become "mutex free". They can be used in different threads without waiting for synchronisation barriers.
   * However, they cannot be used anymore in multiple threads. One BVHTreeSet used in different threads become NON thread safe.
   * See SetMutexFree method.
   */
  CATPolyVisuBVHTreeSet* Clone() const;

  /**
   * In case of an optimized VisuBVHTreeSet, this method duplicates one bvhtree associated to the rep, from iOther to this.
   */
  HRESULT CloneVisuRep(int objectId, const CATPolyVisuBVHTreeSet& iOther);

  /**
   * Advanced multithread management.
   * When a BVHTreeSet is cloned, the clone and cloned one become "mutex free". They can be used in different threads without waiting for synchronisation barriers.
   * However, they cannot be used anymore in multiple threads. One BVHTreeSet used in different threads become NON thread safe.
   * You may want to revert back to a mutex protected tree with this method.
   * @param iMutexFree
   *        FALSE revert back to a fully protected tree set.
   *        TRUE  BVHTreeSet can be used in ONE thread without waiting for synchronisation barriers.
   */
  HRESULT SetMutexFree(CATBoolean iMutexFree = TRUE);

protected:
  virtual HRESULT VirtualRemoveTree(int objectId);

private:
  HRESULT RemoveNode(int objectId, CATBVHNode & iNode);

  /**
   *	For cloning perspective
   *    If rep object are transformed between instantiation and cloning, transform rep back to their initial state with iRevert
   */
  HRESULT AddVisuRep2( int objectId, CAT3DRep * object, const CATMathTransformation* iRevert, const CATMathTransformation * pos = NULL, CATBoolean iDoGenerateRepPath = FALSE, CATBVHTreeRepBuilder::EntityType iEntityTypes = CATBVHTreeRepBuilder::eFaceEntities, CATBoolean iExpandToFaces = FALSE );

  //----------------------------------------------------------
  CATPolyBVHTreeVisualizationFilter * _pFilter;
  CATBVHTreeBuilder::SpatialOptimization _eVisuSpatialMode;
  CATPolyBoundingVolume::TypeID _eVisuBVType;

  CATMapOfPtrToPtr _MapOfRepToTrees;
  CATMapOfPtrToPtr _MapOfTreeToReps;
  CATPolyBodyVisuContext * _pContext;

  CATPolyVisuBVHTreeSetMetaObserver * m_MetaObserver;
  CATBVHTreeRepBuilderObserverForTreeSet * m_builderobs;
};

#endif /* CATPolyVisuInterfBVHTreeSet_h */
