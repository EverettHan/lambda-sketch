// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHTreeRepBuilder
//
//===================================================================
// 2009-09-07   JXO
//      * New
// 2013-03-14   JXO: RunWithMathTransformation
//===================================================================
#ifndef CATBVHTreeRepBuilder_H
#define CATBVHTreeRepBuilder_H

#include "PolyVisuBVH.h"

// System
#include "CATErrorDef.h"
#include "CATSysBoolean.h"

// BVH
#include "CATPolyBoundingVolume.h"
#include "CATBVHTreeBuilder.h"

// Poly
#include "CATMapOfPtrToInt.h"

// Visu
#include "CATRepPath.h"

class CATPolyBVHTreeVisualizationFilter;
class CATBVHTree;
class CATBVHNode;
class CATRep;
class CAT4x4Matrix;
class CATCGMProgressBar;
class CATPolyBodyVisuContext;
class CATMathTransformation;
class CATBVHTreeRepBuilderObserver;

/**
 * This is a builder of CATBVHNode's from the geometric entities
 * of a CATRep.
 */
class ExportedByPolyVisuBVH CATBVHTreeRepBuilder
{

public:

  /**
   * @param iSpatialOptimization
   *   Enumerator defining how the spatial hierarchy of the nodes is constructed and optimized.
   *   See @CATBVHTreeBuilder.
   * @param BVType
   *   Type of bounding volumes you want. See @CATPolyBoundingVolume.
   * @param iGenerateRepPathes
   *   Will generate CATRepPath for nodes that need them. It will take more memory but
   *   enables access to rep pathes in the visualisation attributes
   * @param iKeepInfinite
   *   If set to TRUE, infinite geometry (such as planes) will be taken into account,
   *   leading to not so smart bounding volumes...
   * @param iExpandToFaces
   *   Default is to not build subtrees inside terminal representations. It will be computed on demand.
   *   If set to TRUE, tree goes to the faces.
   */
  CATBVHTreeRepBuilder (CATBVHTreeBuilder::SpatialOptimization iSpatialOptimization,
                        CATPolyBoundingVolume::TypeID BVType = CATPolyBoundingVolume::AABBType,
                        CATBoolean iGenerateRepPathes = FALSE,
                        CATBoolean iKeepInfinite = FALSE,
                        CATBoolean iExpandToFaces = FALSE,
                        CATBoolean iMutexFree = FALSE
                        );

  ~CATBVHTreeRepBuilder ();

public:

  enum EntityType
  {
    eAllEntities = 0,
    eFaceEntities,
    eEdgeEntities,
    eVertexEntities,
    eFaceAndWireEdgeEntities
  };

  /**
   * Run method. Construcs the tree.
   * @param iRep
   *        Input rep. Known representation are @CAT3DBagRep and terminal representations.
   * @param iTransfo
   *        Position of input representation. If set, will be copied.
   * @param iEntityType
   *        See @CATBVHTreeRepBuilder::EntityType.
   * @param oBVHTree
   *        Output tree. Should be released by caller.
   * @param iSagInflate
   *        If set to TRUE, will inflate the bouding elements of the sag value.
   * @return
   *        S_OK: Everything went fine
   *        Any other error code: something went wrong.
   */
  HRESULT RunWithMathTransformation (CATRep& iRep, const CATMathTransformation* iTransfo, EntityType iEntityType,
                                     CATBVHTree*& oBVHTree, CATBoolean iSagInflate = FALSE, CATPolyBodyVisuContext * pContext = NULL);

  /**
   * Filter used to filter out any representation or primitive from the tree.
   * May be NULL to unset. See @CATPolyBVHTreeVisualizationFilter.
   */
  void SetFilter(CATPolyBVHTreeVisualizationFilter * pFilter);

  /**
   * Sets the progress bar.
   * <br />You may implement your own progress bar. See @CATCGMProgressBar.
   */
  void SetProgressBar(CATCGMProgressBar * iProgressBar);

  /**
   * Do we use nodes that can expand themselves at will?
   * Set to -1 (default) to deactivate smart nodes.
   */
  void SetMaxNbFacetsPerNode(int nb);
  /**
   * Put canonical information as second bounding volume in result if avaiable.
   */
  void UseCanonics(CATBoolean iUseCanonics = TRUE){_UseCanonics = iUseCanonics;}
  /**
   * Returns potential warnings during generation
   */
  CATMapOfPtrToInt & GetWarnings(){return _Warnings;}

  /** DEPRECATED! Use RunWithMathTransformation instead. */
  HRESULT Run (CATRep& iRep, CAT4x4Matrix* iMat, EntityType iEntityType,
               CATBVHTree*& oBVHTree, CATBoolean iSagInflate = FALSE, CATPolyBodyVisuContext * pContext = NULL);

  /** Observers */
  void RegisterObserver(CATBVHTreeRepBuilderObserver*);
  /** Observers */
  void UnregisterObserver(CATBVHTreeRepBuilderObserver*);

  /** @nodoc (for 2D Dynamic primitives) */
  void SetScale(double iScale){m_scale = iScale;}

  /** Default is false ! */
  void Process2DReps(CATBoolean iProcess2DReps = TRUE){m_2D = iProcess2DReps;}

private:
  CATBVHNode * VisitRep(CATRep * pRep, const CATMathTransformation * pTransfo = NULL);
  CATBVHNode * VisitPointCloudRep(CATRep * pRep, const CATMathTransformation * pTransfo = NULL);

private:

  CATPolyBVHTreeVisualizationFilter * _pFilter;

  CATCGMProgressBar * _pBar;

  CATBVHTreeBuilder::SpatialOptimization _spatialoptim;
  CATPolyBoundingVolume::TypeID _type;
  EntityType _EntityType;
  CATBoolean _SagInflate;
  unsigned int _MaxNbFacetsPerNode;
  int _currentpathid;
  CATBoolean _break;

  int _nbleaves;
  int _nbcurrentleaves;

  CATRepPath _CurrentPath;
  CATBoolean _generatepathes;
  CATBoolean _KeepInfinite;

  CATPolyBodyVisuContext * _Context;
  CATMapOfPtrToInt _Warnings;
  CATBoolean _LightMode;
  CATBoolean _UseCanonics;

  CATBVHTreeRepBuilderObserver * m_obs;

  double m_scale; // used for 2D Dynamic primitives
  CATBoolean m_2D;
  CATBoolean m_MutexFree;
};

#endif
