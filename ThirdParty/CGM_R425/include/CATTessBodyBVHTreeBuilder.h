
// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyBVHTreeBuilder
//
//===================================================================
// 2011-03-15   DPS
//      * New, copied from CATPolyBodyBVHTreeBuilder
//===================================================================

#ifndef CATTessBodyBVHTreeBuilder_H
#define CATTessBodyBVHTreeBuilder_H

#include "BVHTools.h"     // ExportedBy

// BVH
#include "CATBVHNodeIterator.h"
#include "CATBVHTreeBuilder.h"
#include "CATListOfCATCells.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATBVHTree;
class CATBVHNode;
class CATCGMTessBody;
class CATIPolySurface;
class CATMathTransformation;


/**
 * This is a builder of CATBVHNode's from the geometric entities
 * of a CATPCGMTessBody.  Specifically, it is a builder of CATBVHNode's for the CATIPolySurface's of 
 * the CATFace's of the CATBody and for the CATIPolyCurve's of the CATEdge of the CATBody. 
 * A CATBVHNode is constructed for each CATIPolySurface (CATFace) and CATIPolyCurve (CATEdge)
 * of the CATBody.
 * AABB & OBB are the two types of bounding volumes used int the current algorithm.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATTessBodyBVHTreeBuilder 
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

  /*
   * @param iSpatialOptimization
   *   Enumerator defining how the spatial hierarchy of the nodes is constructed and optimized.
   *   See CATBVHTreeBuilder.
   * @param iMaxNbFacetsPerNode
   *   This is an input control parameters that controls the level of division of the CATIPolySurface's.
   *   The CATIPolySurface's are divided into as many sub-surfaces as needed to have a number of facets 
   *   below or equal to this parameter.  If this parameter is set to 0, then no division of the
   *   CATIPolySurface's occurs.
   */
  CATTessBodyBVHTreeBuilder (CATBVHTreeBuilder::SpatialOptimization iSpatialOptimization,
                             const unsigned int iMaxNbFacetsPerNode = 0);

 /*
  * Generation of the global (default) of local TessBodyBVHTree
  * @param iTessBody
  *   CGM Body datum + tessellation access
  * @param iEntityType
  *   to limit the node generation to some types of cells
  * @param oBVHTree
  *   output Tree
  * @param iSagInflate
  *   to take the approximation tolerance into account (contact case for example)
  * @param iSetOfSpecCells
  *   possibility to create a local tree from a set of specific cells 
  */
  HRESULT Run (CATCGMTessBody& iTessBody, EntityType iEntityType,
               CATBVHTree*& oBVHTree, CATBoolean iSagInflate, 
               CATLISTP(CATCell) * iSetOfSpecCells=NULL);

  ~CATTessBodyBVHTreeBuilder ();

private:

  void GetSpecCellsByType(CATLISTP(CATCell) & iSetOfSpecCells,
                          EntityType          iEntityType,
                          CATLISTP(CATCell) & oSpecFaces,
                          CATLISTP(CATCell) & oSpecEdges);

private:

  CATBVHTreeBuilder _TreeBuilder;

  unsigned int      _MaxNbFacetsPerNode;

};

#endif
