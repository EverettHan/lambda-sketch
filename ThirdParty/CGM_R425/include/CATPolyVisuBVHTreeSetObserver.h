// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuBVHTreeSetObserver.h
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

#ifndef CATPolyVisuBVHTreeSetObserver_h
#define CATPolyVisuBVHTreeSetObserver_h

#include "PolyVisuClash.h"

// Poly
class CATPolyBVHTreeVisualizationFilter;
#include "CATBVHTreeRepBuilder.h"
#include "CATPolyBodyBVHTreeSetObserver.h"

// PolyhedralMathematics
#include "CATBVHTreeBuilder.h"
#include "CATPolyBoundingVolume.h"
#include "CATPolyVisuBVHTreeSet.h"

// Math
#include "CATMathTransformation.h"

// Visualization
class CAT4x4Matrix;
class CAT3DRep;

/**
 * This class observes CATPolyVisuBVHTreeSet
 */
class ExportedByPolyVisuClash CATPolyVisuBVHTreeSetObserver : public CATPolyBodyBVHTreeSetObserver
{
public:
  /**
   * Constructor and destructor
   */
  CATPolyVisuBVHTreeSetObserver(){}
  virtual ~CATPolyVisuBVHTreeSetObserver(){}

  virtual void SetObserved(CATPolyVisuBVHTreeSet*) = 0;

  /**
   */
  virtual void SetRepSpatialOptimizationMode(CATBVHTreeBuilder::SpatialOptimization iSpatialOptimization) = 0;
  virtual void SetRepBVType(CATPolyBoundingVolume::TypeID bvType) = 0;
  virtual void SetFilter(CATPolyBVHTreeVisualizationFilter * filter) = 0;
  virtual HRESULT AddRep(int objectId, CAT3DRep * object, const CAT4x4Matrix * pos, CATBoolean iDoGenerateRepPath, CATBVHTreeRepBuilder::EntityType iEntityTypes, CATBoolean iExpandToFaces) = 0;
  virtual HRESULT AddVisuRep(int objectId, CAT3DRep * object, const CATMathTransformation * pos, CATBoolean iDoGenerateRepPath, CATBVHTreeRepBuilder::EntityType iEntityTypes, CATBoolean iExpandToFaces) = 0;
  virtual HRESULT ModifyRepPosition(int objectId, const CAT4x4Matrix * pos) = 0;
  virtual HRESULT DeactivateRep(int objectId) = 0;
  virtual HRESULT ActivateRep(int objectId) = 0;
  virtual HRESULT RemoveRep(int objectId) = 0;

};

#endif /* CATPolyVisuInterfBVHTreeSet_h */
