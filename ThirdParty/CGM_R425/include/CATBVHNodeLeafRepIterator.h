// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHNodeLeafRepIterator
//
//===================================================================
// 2009-09-04   JXO
//      * New
//===================================================================
#ifndef CATBVHNodeLeafRepIterator_H
#define CATBVHNodeLeafRepIterator_H

#include "PolyVisuBVH.h"
#include "CATErrorDef.h"
#include "CATSysBoolean.h"

#include "CATBVHNodeIterator.h"

#include "CATPolyBoundingVolume.h"

#include "CATMathTransformation.h"

class CATPolyBVHTreeVisualizationFilter;
class CATBVHNode;
class CATRep;
class CATPolyBody;
class CAT4x4Matrix;
class CATMapOfPtrToPtr;
class CATPolyBodyVisuContext;


/**
 * Implementation of CATBVHNodeIterator for terminal visualization representation.
 * It will construct BVH nodes for faces and/or edges.
 */
class ExportedByPolyVisuBVH CATBVHNodeLeafRepIterator : public CATBVHNodeIterator
{
public:
  enum EntityType
  {
    eAllEntities = 0,
    eFaceEntities,
    eEdgeEntities,
    eVertexEntities,
    eFaceAndWireEdgeEntities
  };

public:

  /**
   * Constructor.
   * @param iRep
   *        Input terminal rep. BagReps are not expanded.
   * @param RepPathId
   *        Id for current rep path. See implementation of CATBVHTreeRepBuilder. Can be -1.
   * @param BVType
   *        Type of bounding volumes you want. See @CATPolyBoundingVolume.
   * @param iPosition
   *        Position of input representation.
   * @param iEntityType
   *        See @EntityType.
   * @param iSagInflate
   *        TRUE: Every bounding volume will be inflated of the value of the sag.
   *        FALSE: Bounding volumes are not inflated.
   * @param pFilter
   *        Sets filter for construction. See @CATPolyBVHTreeVisualizationFilter. Can be NULL.
   * @param MaxNbFacetsPerNode
   *        Activate smart nodes. Smart nodes can expand themselves on demand. They will split
   *        until they have less triangles than MaxNbFacetsPerNode. See @CATBVHSmartNode.
   * @param pContext
   *        Multi instanciation manager
   * @param iKeepInfinite
   *        If set to TRUE, infinite geometry (such as planes) will be taken into account,
   *        leading to not so smart bounding volumes...
   * @param iBody
   *        Don't use.
   */
  CATBVHNodeLeafRepIterator(CATRep & iRep, int RepPathId,
                            CATPolyBoundingVolume::TypeID BVType,
                            const CAT4x4Matrix * iPosition = NULL, EntityType iEntityType = eFaceEntities,
                            CATBoolean iSagInflate = FALSE,
                            CATPolyBVHTreeVisualizationFilter * pFilter = NULL,
                            int MaxNbFacetsPerNode = -1,
                            CATPolyBodyVisuContext * pContext = NULL,
                            CATBoolean iKeepInfinite = FALSE,
                            CATPolyBody * iBody = NULL,
                            CATBoolean dontuse = FALSE,
                            CATBoolean iMutexFree = FALSE);
  virtual ~CATBVHNodeLeafRepIterator();

public:

  // Set the iterator to the beginning.
  virtual CATBVHNodeLeafRepIterator& Begin();

  // Return TRUE if the iterator has reached the end and FALSE otherwise.
  virtual CATBoolean End() const;

  // Increment the iterator to the next valid element.
  virtual CATBVHNodeLeafRepIterator& operator++();

  // Return the total elements size.
  int GetSize();

public:

  // Return an instance of the CATBVHNode currently referenced by the iterator 
  // (or NULL if iterator has reached the end.)
  // Note: You will have to set the ParentRepAttribute on the nodes' attributes.
  virtual CATBVHNode * operator*() const;
  // Return a potential error code.
  // 0: No error
  // 1: Unexpected error
  // 2: Wire Rep but edges were not asked
  // 3: Point Rep but vertices were not asked
  // 4: Other non matching rep type / entity type
  int GetError();


  void SagInflate(CATPolyBoundingVolume & BV) const;

private:
  void PutAttribute(CATBVHNode & iNode) const;
  CATBoolean Filter() const;

private:

  CATPolyBVHTreeVisualizationFilter * _pFilter;
  CATRep & _Rep;
  CATMathTransformation _oBodyPosition;
  CATBoolean _bIsIdentity;
  double _sag;
  CATBoolean _saginflate;
  int _RepPathId;

  EntityType _entitytype;
  CATPolyBoundingVolume::TypeID _bvtype;
  CATBoolean _KeepInfinite;

  int _CurrentFace;
  int _CurrentEdge;
  int _CurrentVertex;
  int _nbfaces;
  int _nbedges;
  int _nbvertex;
  int _nbv;

  CATBVHNode ** _NodeList;
  CATPolyBody * _pBody;
  unsigned int _MaxNbFacetsPerNode;
  CATPolyBodyVisuContext * _Context;
  int _errorcode;
  CATBoolean _DeletePolyBody;
  CATBoolean m_MutexFree;
};

#endif
