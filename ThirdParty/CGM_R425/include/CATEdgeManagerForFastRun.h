/**
* @COPYRIGHT DASSAULT SYSTEMES 2009
*/
/* -*-c++-*- */
//===========================================================================
//
// Feb. 2010   Creation                            JJ3
//
//===========================================================================

#ifndef  CATEdgeManagerForFastRun_h
#define  CATEdgeManagerForFastRun_h

#include "CATCGMHashTableWithAssoc.h"
#include "CATBoolean.h"
#include "CATEdgeRelationsForFastRun.h"

class CATEdge;
class CATBody;
class CATContextForFastRunBoxSolutionExt;
class CATDrawerCollector;
class CATGeoFactory;
class CATCGMHashTable;
class CATCGMHashTableWithAssoc;
class CompleteNREdges;
class CATPartitionManager;
class CATCGMJournalList;
class CATCGMOutput;
class CATPAD;

class CATEdgeManagerForFastRun
{
public:

  CATEdgeManagerForFastRun(CATGeoFactory * ipFactory, int iEstimatedSize = 0);
  virtual ~CATEdgeManagerForFastRun();

  CATBoolean IsOREdge(CATEdge * iEdge);
  CATBoolean IsVirtual(CATEdge * iEdge);
  CATCGMHashTable * GetAssocNREdgesDrawer(CATEdge * iOREdge);
  CATCGMHashTable * GetVirtualEdges(CATEdge * iEdge);
  CATEdge * GetAssocRealEdge(CATEdge * iVirtualEdge);

  // Renvoie l'Edge Virtuelle liee a iVirtualEdge.
  CATEdge * GetLinkedVirtualEdge(CATEdge * iVirtualEdge);
  CATEdge * GetLinkedVirtualEdgeOI(CATEdge * iVirtualEdgeOR);
  CATDrawerCollector * computeGraphForConnexComponentsDecomposition(CATDrawerCollector * _CriticalVerticesHT,
                                                                    CATBody * iWorkingBody,
                                                                    CATPAD * _PADf,
                                                                    CATPAD * _PADg
                                                                    );

  CATEdge * CreateFGEdge( CATEdge * virtualOIEdge, 
                          CATEdge * virtualOREdge 
                          );

  void RemoveCreatedEdges();

private : 

  void SetOIEdge(CATEdge * iOIEdge);
  void SetAssocOREdge(CATEdge * iRefEdge, CATEdge * iAssocOREdge);
  void SetAssocNIEdge1(CATEdge * iRefEdge, CATEdge * iAssocNIEdge1);
  void SetAssocNIEdge2(CATEdge * iRefEdge, CATEdge * iAssocNIEdge2);
  void SetAssocVirtualEdge1(CATEdge * iRefEdge, CATEdge * iAssocVirtualEdge1);
  void SetAssocVirtualEdge2(CATEdge * iRefEdge, CATEdge * iAssocVirtualEdge2);
  void SetAssocPotentialNREdge1(CATEdge * iRefEdge, CATEdge * iAssocPotentialNREdge1);
  void SetAssocPotentialNREdge2(CATEdge * iRefEdge, CATEdge * iAssocPotentialNREdge2);


  void SetEdge(CATEdge * iEdge, CATEdgeRelationsForFastRun * iRelations);
  CATEdgeRelationsForFastRun * GetEdgeRelations(CATEdge * iEdge);
  CATCGMHashTableWithAssoc * _Relation_Edge_Relations;
  CATCGMHashTable * _Relations;


  int CreateVirtualEdges( CATEdge * iOldEdge, 
                          CATEdge * iNewEdge, 
                          CATEdge *& oVirtualOldEdge1, 
                          CATEdge *& oVirtualOldEdge2,
                          CATEdge *& oVirtualNewEdge1, 
                          CATEdge *& oVirtualNewEdge2
                          );

  CATCGMHashTableWithAssoc *    _Relation_virtualEdgeOI_virtualEdgeOR;
  CATCGMHashTableWithAssoc *    _Relation_virtualEdgeOR_virtualEdgeOI;
  CATCGMHashTable *             _VirtualEdges;
  CATCGMHashTable *             _VirtualVertices; 
  CATGeoFactory *               _Factory;
  CATBody *                     _WorkingBody;
  CATDrawerCollector *          _Relation_EdgesOR_EdgesNR;
  CATDrawerCollector *          _Relation_Edge_virtualEdges;
  CATCGMHashTableWithAssoc *    _Relation_virtualEdge_Edge;

};

#endif
