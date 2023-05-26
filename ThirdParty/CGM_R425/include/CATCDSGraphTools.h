// COPYRIGHT DASSAULT SYSTEMES 2012
//=============================================================================
//
// CATCDSGraphTools:
//   General Functions for working with graph
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Mars 2010  Creation                               KUB
//=============================================================================

#ifndef CATCDSGraphTools_h
#define CATCDSGraphTools_h

#include "SolverUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSListP.h"


class CATCDSEdge {
public:
  int _v1;
  int _v2;
  int _isScanned;
  int _idxConstr;
  int _idxClass;
  int _direction; // =1 corresponds to v1->v2, =-1 to v2->v1
  CATCDSEdge() :_v1(-1), _v2(-1), _isScanned(0), _idxConstr(-1), _idxClass(-1), _direction(0) {}
};


enum CATCDSArtPointStatus {
  asValid,
  asRadiusNotFixed,
  asCSDepends,
  asHasSketchBond,
  asMovedRigidSet,
  asFullDOFRigidSet,
  asVariable,
  asCurvature,
  asNotValid
};

void MergeCycles(
  int inVertices,
  int inEdges, CATCDSEdge *iaEdges,
  int *iaIdxSucc, CATCDSEdge **iaSucc,
  CATCDSArtPointStatus *iaNotValidArtPoint,
  int &onArtPointToMerge, int *oaArtPointToMerge,
  int &onComps,
  int *ioaConstrClasses,
  int &oArtPointsNb,
  int &onSimpleComps
);



void CreateAdjList(
  int inVertices,
  int inEdges, CATCDSEdge *iaEdges,
  int *&oaIdxSucc, CATCDSEdge **&oaSucc
);

// Finds cycles on graph
// @return TRUE if cycle is found, FALSE otherwise
ExportedBySolverUtilities CATCDSBoolean FindCycles(int inVertices,
                         int inEdges, CATCDSEdge *iaEdges,
                         int *ioaEdgeCycle,
                         int *ioaVertexClass = 0) ;

// Find biconnected components on graphs
// @return Number of found biconnected components
ExportedBySolverUtilities int FindBiconnectedComponents(
  int inVertices,
  int inEdges,
  CATCDSEdge *iaEdges,
  int *oaVerticesClass
);

#endif // CATCDSGraphTools_h
