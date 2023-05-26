
// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyBVHNodeBuilder
//
//===================================================================
// 2011-03-15   DPS
//      * New
//===================================================================

#ifndef CATTessBodyBVHNodeBuilder_H
#define CATTessBodyBVHNodeBuilder_H

#include "BVHTools.h"     // ExportedBy

#include "CATBVHNodeIterator.h"
#include "CATErrorDef.h"
#include "CATSysBoolean.h"

#include "CATPolyOBB.h"

#include "CATListOfCATCells.h"

class CATCGMTessBody;
class CATTessBodyBVHAttribute;
class CATPolyOBB;
class CATMathOBB;
class CATMathBox;

/**
 * This is a builder of CATBVHNode's from the geometric entities
 * of a CATCGMTessBody.  Specifically, it is a builder of CATBVHNode's for the CATIPolySurface's of 
 * the CATFace's and for the CATIPolyCurve's of the CATEdge of the CATBody referenced by the CATCGMTessBody. 
 * A CATBVHNode is constructed for each CATIPolySurface (CATFace) and CATIPolyCurve (CATEdge)
 * of the CATCGMTessBody.
 * AABB & OBB are the two types of bounding volumes used int the current algorithm.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATTessBodyBVHNodeBuilder 
{

public:

  enum EntityType
  {
    eAllEntities = 0,
    eFaceEntities,
    eEdgeEntities,
    eVertexEntities,
    eFaceAndWireEdgeEntities,
    eSpecEntities
    
  };

public:

  // Constructor with the type of cells on which a node generation is required
  CATTessBodyBVHNodeBuilder (CATCGMTessBody &iTessBody,
                             CATTessBodyBVHAttribute & iBodyNodeAttrib,
                             EntityType iEntityType = eAllEntities,
                             CATBoolean iUseSag = FALSE, 
                             unsigned int iMaxNbFacetsPerNode = -1);

  // Constructor with the list of cells on which a node generation is required
  CATTessBodyBVHNodeBuilder (CATCGMTessBody &iTessBody,
                             CATTessBodyBVHAttribute & iBodyNodeAttrib,
                             CATLISTP(CATCell)* iSpecFaces,
                             CATLISTP(CATCell)* iSpecEdges,
                             CATLISTP(CATCell)* iSpecVertices,
                             CATBoolean iUseSag = FALSE, 
                             unsigned int iMaxNbFacetsPerNode = -1);

  ~CATTessBodyBVHNodeBuilder ();


public:

  class Iterator : public CATBVHNodeIterator
  {
  public:

    Iterator (const CATTessBodyBVHNodeBuilder& iBuilder);
    ~Iterator();

  public:

    CATBVHNodeIterator& Begin ();
    CATBoolean End () const;
    CATBVHNodeIterator& operator++ ();

    CATBVHNode* operator* () const;

  protected :
    void CreatePolyOBBFromMathOBB(CATMathOBB &iAdBB, CATPolyOBB * &ioOBB) const;

  private:

    CATCGMTessBody   & _TessBody;

    CATTessBodyBVHAttribute & _pPBNodeAttrib;
    double _InflateSAG;
    EntityType _EntityType;
    unsigned int _MaxNbFacetsPerNode;

    CATLISTP(CATCell) _Faces;
    CATLISTP(CATCell) _Edges;
    CATLISTP(CATCell) _Vertices;
    int _CurrentFace;
    int _CurrentEdge;
    int _CurrentVertex;
    int _nbfaces;
    int _nbedges;
    int _nbv;
    CATBVHNode ** _NodeList;
  };



private:
   
  CATCGMTessBody              & _TessBody;
  CATLISTP(CATCell)           * _SpecFaces;
  CATLISTP(CATCell)           * _SpecEdges;
  CATLISTP(CATCell)           * _SpecVertices;


  CATTessBodyBVHAttribute     & _pPBNodeAttrib;
  EntityType                    _EntityType;
  double                        _InflateSAG;
  unsigned int                  _MaxNbFacetsPerNode;
};

#endif
