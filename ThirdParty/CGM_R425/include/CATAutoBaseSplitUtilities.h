#ifndef CATAutoBaseSplitUtilities_H
#define CATAutoBaseSplitUtilities_H
//===================================================================
// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATAutoBaseSplitUtilities.h
// 		
//===================================================================
//  Oct 2003  Creation: JHG
//===================================================================

#include "CATOracleObject.h"
#include "CATCGMNewArray.h"
#include "CATBoolean.h"
#include "ListPOfListPOfCATFace.h"
#include "CATListOfInt.h"
#include "ListPOfCATShell.h"
#include "ListPOfCATEdge.h"

#include "CFSEngine.h"
#include "CATIAV5Level.h"

#include "ListPOfCATAutoBaseSplitFaceSets.h"

class CATSmartBodyDuplicator;

class CATBody;
class CATTopBooleanOperator;
class CATAutoBaseThreadContext;

class ExportedByCFSEngine CATAutoBaseSplitUtilities : public CATOracleObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
  DEFINE_ADVOP_CLASS_NAME("CATAutoBaseSplitUtilities")

  CATAutoBaseSplitUtilities(CATTopOracle &iOracle, const CATAutoBaseThreadContext &iThreadContext);

  virtual ~CATAutoBaseSplitUtilities();

  CATBoolean AutoFilletPartingSplit(CATBody &iElementToCut, CATBody &iCuttingElement,
    CATBody *oCutElementPositiveSide[2], CATBody *oCutElementNegativeSide[2], CATBody *&oModifiedCuttingElement,
    CATCGMJournalList &oJournal, ListPOfCATEdge &oScarEdges,
    ListPOfCATFace *oConfusedFacesInInputBody);

  CATBody *MultiIntersectAndDisconnect(CATCGMJournalList &oJournal, 
    CATBody &iElementToCut, const ListPOfCATBody &iCuttingElements,
    ListPOfCATAutoBaseSplitFaceSets &oDisconnectedCutElementFaceSets,
    ListPOfCATEdge &oScarEdges, CATBoolean &iTrimCuttingElements);

#ifdef CATIAR201
  CATBody *InefficientBodiesRegularizator(const ListPOfCATBody &iBodiesToRegularize,
    CATCGMJournalList &oJournal, ListPOfCATFace &oConfusedFacesInResultBody);

  CATBody *HomeMadeTrim(CATCGMJournalList &oJournal, CATBody *iFirstBodyToCut, int iFirstSideToKeep,
    CATBody *iSecondBodyToCut, int iSecondSideToKeep);
#endif

  // intersects iElementToCut with iCuttingElement, puts the disconnected bodies
  // inside a single body and returns it
  // NB : iCuttingElement will be disconnected only if iDisconnectAlsoCuttingElement
  // is set to TRUE
  // oDisconnectedCutElementFaceSets and oDisconnectedCuttingElementFaceSets (if provided)
  // contain group of faces with same location
  CATBody *IntersectAndDisconnect(CATCGMJournalList &oJournal,
    CATBody &iElementToCut,
    CATBody &iCuttingElement,
    ListPOfCATAutoBaseSplitFaceSets &oDisconnectedCutElementFaceSets,
    CATBoolean iDisconnectAlsoCuttingElement = 0,
    ListPOfCATAutoBaseSplitFaceSets *oDisconnectedCuttingElementFaceSets = 0,
    ListPOfCATEdge *oScarEdges = 0,
    ListPOfCATFace *oConfusedFaces = 0,
    ListPOfCATFace *oConfusedFacesInInputBody = 0,
    CATBoolean iNoGroupCreation = 0,
    CATBoolean iCVMPrototype = 0);

private:
  CATBody *IntersectShells(CATTopBooleanOperator &iTopOp,
                          CATBody &iElementToCut,   CATShell &iShellToCut,
                          CATBody &iCuttingElement, CATShell &iCuttingShell,
                          ListPOfCATEdge *ioScarEdges);

#ifdef CATIAR201
  CATBody *IntersectBodies(CATTopBooleanOperator &iTopOp,
                          CATBody &iElementToCut, CATBody &iCuttingElement,
                          ListPOfCATEdge *ioScarEdges);
#endif

  CATBody *IntersectWireShell(CATTopBooleanOperator &iTopOp,
                          CATBody *iElementToCut,   CATShell *iShellToCut,
                          CATBody *iCuttingElement, CATWire *iCuttingWire);

  CATBoolean DisconnectDuplicatedImageOfBody(CATTopBooleanOperator &iTopOp,
    CATBody &iBodyWhichImageIsToBeDisconnected, CATSmartBodyDuplicator &iDuplicator);

  CATBoolean CreateCellGroupsFromBody(CATTopBooleanOperator &iTopOp,
                                                         CATBody &iBodyWhichImageHasBeenDisconnected,
                                                 CATSmartBodyDuplicator &iDuplicator,
                                                 ListPOfCATAutoBaseSplitFaceSets *oFaceSets,
                                                 CATBoolean iComputeSecondaryLocation);

  CATBoolean CreateCellGroupsFromShell(CATTopBooleanOperator &iTopOp, CATShell &iShell,
                                                 ListPOfCATAutoBaseSplitFaceSets *ioFaceSets,
                                                 CATBoolean iComputeSecondaryLocation);
  CATBoolean CleanDisconnectInfo(CATTopBooleanOperator &iTopOp,
                                                 CATBody &iBodyWhichImageHasBeenDisconnected,
                                                 CATSmartBodyDuplicator &iDuplicator);
  void UpdateTouchForVolumes(CATBody &iBodyToUpdate);

private:
  const CATAutoBaseThreadContext &_ThreadContext;
};

#endif
