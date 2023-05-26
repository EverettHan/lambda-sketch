#ifndef CATContextForFastRunBoxSolutionExt_h
#define CATContextForFastRunBoxSolutionExt_h
/* -*-C++-*-*/
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//
// The generic Context for Box Solution.
//
//==========================================================================
// Jan. 09  Creation                                                    JJ3
//==========================================================================
#include "ExportedByPBELight.h"
#include "CATCGMNewArray.h"
#include "CATContextForFastRunExt.h"
//#include "CATDynFilletRibbon.h"
#include "CATCollec.h"
#include "CATCGMHashTableWithAssoc.h"
#include "CATSuperJournalForFastRun.h"
#include "CATConnexComponentManager.h"
#include "CATPartitionManager.h"
#include "CATFastRunBlackBox.h"
#include "CATDrawerCollector.h"
#include "CATPAD.h"
#include "CATEdgeManagerForFastRun.h"
#include "CATContextForFastRunBoxSolutionExtInterface.h"

class CATHashTableWithIntAssoc;
class CATTopologiesSetForFastRun;
class CATLump;

ExportedByPBELight int IsFastRunAllowedForVariableFilletWithSpine();

class ExportedByPBELight CATContextForFastRunBoxSolutionExt: public CATContextForFastRunBoxSolutionExtInterface
{

  public:
    CATContextForFastRunBoxSolutionExt();
    virtual ~CATContextForFastRunBoxSolutionExt();

    /**
     * Checks if Fast Update is possible and gives the current scenario.
     */
    CATFastRunStatus CheckContextForFastRun();

    int F_FastUpdate(CATBody *& oResult, CATCGMJournalList *&oJournal);
    CATBoolean TouchOldResult(CATTopology *iTopo, int iLevel);
    CATPartitionForFastRun FindPartition(CATTopology *iTopo, int iLevel);
    virtual CATBoolean PartialRunNeeded();
    void ConstructPartialResult(CATBody *& oBody, CATCGMJournalList *& oJournal);
    void DumpEdgeManager(CATCGMOutput& os);

    int          GetScenarioType();
    int          GetScenarioMaxFastRunnable();
    void         SetScenarioMaxFastRunnable(int  iScenarioMaxFastRunnable);

  protected:
    virtual int ComputeConnexComponentsToCheck();
    virtual int PrepareFastRunComplementaryRun();
    virtual CATFastRunStatus CheckOfOperatorForFastRun();

    CATBoolean ContextOK();
    virtual CATBoolean CheckVolumicCase(); // jma : à surcharger pour debloquer

    CATDomain *    CorrespondingLumpInOldInput(CATLump * iLump);
    int ComputeJ();
    int FindRelatedFaces(CATCGMHashTable * ipOldInputFacesWithNoRelatedFace = NULL);
    // IZE Method related to FindRelatedFaces
    // Aims toidentify the created faces in new input which still share geometry with their ancestor in OldInput
    int MatchFacesRetainingGeometry();
    int FindRelatedFacesInfra(CATCGMHashTable * iOldInputFaces = NULL,
                              CATCGMHashTable * ipOldInputFacesWithNoRelatedFace = NULL,
                              CATBoolean iSc2 = FALSE);
    int MainOfFindRelatedFacesInfra(CATCGMHashTable * & iOldInputFaces,
                                    CATFace         * & curFace1,
                                    CATCGMHashTable * & ipOldInputFacesWithNoRelatedFace,
                                    CATBoolean        & iSc2);
    int ComputeCriticalVerticesHT();
    // CATBoolean FindCorrespondingEdge(CATEdge* inputEdge);
    CATEdge *LocateOldResultEdge(CATLoop * iLoop, CATEdge * iEdge);
    int CheckIntersectionWithCreatedFaces();
    // IZE new check less constraining than the previous one
    int CheckIntersectionWithExtLoopOfCreatedFaces();
    CATBoolean CompareUVLimits(CATPCurve *iCurCurve, CATPCurve *iAssocCurve);
    int CheckNewEdgesPositionInModifiedFaces();
    CATFastRunStatus CheckScenario0();
    CATFastRunStatus CheckScenario1();
    CATFastRunStatus CheckScenario2();
    CATFastRunStatus CheckScenario3();
    // int CreateImpactedEdgesHTSc3();
    //int CreateImpactedEdgesHT();
    int ComputeConnexeComponents();

    CATCellHashTable * GetModifiedFacesWithNewGeometry();

    CATPartitionManager          *_Partitionment;
    CATSuperJournalForFastRun    *_J;
    int                           _lmin;
    int                           _lmax;
    CATCGMHashTable               _Sc2FacesInOldInput; // En fait les Faces de OldInput qui ne sont pas dans NewInput
    CATCGMHashTableWithAssoc      __RelationNewFaceSc2_OldFacesSc2;
    //CATCGMHashTableWithAssoc      __RelationOldFaceSc2_NewFacesSc2;
    CATDrawerCollector      __RelationOldFaceSc2_NewFacesSc2;
    // Scenario 2.5.
    CATCGMHashTableWithAssoc      __RelationNewFaceSc2_5_OldFacesSc2_5;
    CATDrawerCollector            __RelationOldFaceSc2_5_NewFacesSc2_5;
    CATCGMHashTableWithAssoc      _RelationOldResultFaceSc2_NewResultFacesSc2;
    CATDrawerCollector           *_CriticalVerticesHT; // Les Vertices critiques avec une HT des Edges associées.
    CATConnexComponentManager     _ConnexComponents;
    CATConnexComponentManager     _ConnexComponentsToCheck;
    CATConnexComponentManager     _ConnexComponentsToIgnore;
    CATCGMHashTable               _OldInputFacesModifiedBySc2;
    CATBody *                     _WorkingBody;
    CATPAD *                      _PADf;
    CATPAD *                      _PADg;

    CATFastRunBlackBox            _GenericFastRunOperator;
    CATGeoFactory *               _Factory;

    CATEdgeManagerForFastRun *   _EdgeManager;
    CATBoolean _ContextHasBeenChecked;

    CATBoolean IsSc2Face(CATFace * iFace);
    void SetRelation(CATFace * iOldInputFace, CATFace * iNewInputFace, CATBoolean iSc2 = TRUE);
    //CATFace * GetRelatedFace(CATFace * iFace);
    CATFace * GetRelatedOIFace(CATFace * iNIFace);
    //CATFaceHashTable * GetRelatedFaces(CATFace * iFace);
    CATCGMHashTable * GetRelatedNIFaces(CATFace * iOIFace);
    int GetNbFacesNotInNewInput();
    CATFace * GetFaceNotInNewInput(int iPos);

    virtual void InitScenarioMaxFastRunnable();
    virtual int  FindInputsError();
    virtual int  CheckMergableVertices();
    int          _ScenarioType;
    int          _ScenarioMaxFastRunnable; // A 1 par default.

    virtual CATBoolean NonSmartUpdate( CATFace * iFace, CATFace ** oFace = 0 );
    virtual CATBoolean NonSmartUpdate();
    virtual CATBoolean SlowConfiguration();
    friend class CATFastRunBlackBox;

    virtual void GetLimitingBodies(CATLISTP(CATBody) &iLimitingBodies);
};

#endif
