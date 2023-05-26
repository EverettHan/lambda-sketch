// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHSmartRepNode
//
//===================================================================
// 2010-03-26   JXO
//      * New
//===================================================================
#ifndef CATBVHSmartRepNode_H
#define CATBVHSmartRepNode_H

// PolyhedralVisuOperators
#include "PolyVisuBVH.h"
#include "CATBVHNodeLeafRepIterator.h"

// PolyhedralBodyOperators
#include "CATBVHSmartNode.h"

// PolyhedralMathematics
#include "CATBVHTreeBuilder.h"
#include "CATPolySetOfMutex.h"
#include "CATPolyBoundingVolume.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CAT4x4Matrix;
class CATBVHVisuAttribute;
class CATPolyBodyVisuContext;
class CATPolyBVHTreeVisualizationFilter;


/**
 * This class represents a smart node for visualization representations.
 * This is a node in a BVH tree (built with visu attributes) that can span itself
 * on demand. As soon as children are accessed the node will expand and split itself.
 * So the call to GetNbChildren or to the children iterator can be CPU costly.
 */
class ExportedByPolyVisuBVH CATBVHSmartRepNode: public CATBVHSmartNode
{
  CATPolyDeclarePooledNew;

public:
  /**
   * Basic constructors and destructor
   */
  CATBVHSmartRepNode(CATRep                                & iRep, 
                     int                                     iRepPathId,
                     CATBVHTreeBuilder::SpatialOptimization  iSpatialOptimization,
                     CATPolyBoundingVolume::TypeID           iBVType,
                     CAT4x4Matrix                          * ipPosition = NULL, 
                     CATBVHNodeLeafRepIterator::EntityType   iEntityType = CATBVHNodeLeafRepIterator::eFaceEntities,
                     CATBoolean                              iSagInflate = FALSE,
                     CATPolyBVHTreeVisualizationFilter     * ipFilter = NULL,
                     int                                     iMaxNbFacetsPerNode = -1,
                     CATPolyBodyVisuContext                * ipContext = NULL,
                     CATBoolean                              iKeepInfinite = FALSE,
                     CATBoolean                              iGenerateRepPathes = FALSE,
                     CATBVHVisuAttribute                   * ipVisuAttribute = NULL,
                     CATBoolean                              iMutexFree = FALSE);


  /**
   * Constructor used for creating a complete Smart rep node (along with the associated tree) 
   * without peforming any computations for creating the node
   */
  CATBVHSmartRepNode(CATBVHVisuAttribute                   *   ipVisuAttribute,
                     CATBVHTreeBuilder::SpatialOptimization    iSpatialOptimization,
                     CATPolyBoundingVolume::TypeID             iBVType,
                     CATBVHNodeLeafRepIterator::EntityType     iEntityType,
                     CATBoolean                                iKeepInfinite,
                     int                                       iMaxNbFacetsPerNode,
                     CATBoolean                                iIsBuildAlready);

  virtual ~CATBVHSmartRepNode();

  /**
   * Smart Implementations:
   */
public:

  virtual int GetNbChildren() const;
  
  // collapses but does not flush polybodies
  virtual void ForceCollapse(int iCollapseMode = 0);
  
  // Flush any additional memory that can be computed again.
  virtual void FlushMemory();
  
  virtual BVHNodeType GetType(){return SmartRep;}
  virtual CATBVHAttribute* GetAttribute () const;

  /**
   * Momentary stops the expand of all smart rep nodes
   * @param iStop
   *    TRUE: stops expand
   *    FALSE: restart expand
   */
  static void StopRepExpand(CATBoolean iStop = TRUE);
  
  static CATBoolean IsRepStopped();

  CATBVHAttribute* GetFastAttribute () const;

  /**
   * Returns the optimization mode for the BVHRepNode
   */
  CATBVHTreeBuilder::SpatialOptimization GetOptimizationMode() const;

  /**
   * Returns the bounding volume type of the children computed for the BVHRepNode
   */
  CATPolyBoundingVolume::TypeID GetBVType() const;

  /**
   * Returns the entity type for the BVHRepNode
   */
  CATBVHNodeLeafRepIterator::EntityType GetEntityType() const;

  /**
   * Returns whether infinite geometry is considered for creating bounding volumes
   * Corresponds to the value of the m_KeepInfinite member
   */
  CATBoolean IsInfiniteGeomConsidered() const;

  /**
   * Returns whether the children of the node have been computed already or not
   */
  CATBoolean IsBuiltAlready() const;

protected:
void InitializeVisuAttribute(CATRep                 & iRep, 
                             CAT4x4Matrix           * ipPosition, 
                             CATPolyBodyVisuContext * ipContext, 
                             CATBVHVisuAttribute    * ipVisuAttribute);
  void UpdateAttribute() const;

  virtual CATBVHNodeConstList & GetChildren();
  

protected:
  CATBVHNode * _pRoot;
  CATPolyBVHTreeVisualizationFilter       * _pFilter;
  CATBVHTreeBuilder::SpatialOptimization    _SpatialOptimization;
  CATPolyBoundingVolume::TypeID             _BVType;
  CATBVHNodeLeafRepIterator::EntityType     _EntityType;
  char                                      _BuildStatus;
  CATBoolean                                _OnlyOneFace;
  CATBoolean                                m_KeepInfinite;


  static CATMutex           _mutRepStop;
  static CATPolySetOfMutex  _pmut;
  static CATBoolean         _stoprepexpand;

    

private:

  // Temporary method, to replace the old GetChildren in future
  CATBVHNodeConstList & GetChildrenNew();

  CATBoolean      _isNewStreamerEnabled;
};

#endif
