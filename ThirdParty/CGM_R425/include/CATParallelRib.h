/* -*-C++-*- */
#ifndef CATParallelRib_H
#define CATParallelRib_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//===================================================================
//===================================================================
//
// CATParallelRib
// Class for generation of parallel Ribbon as wire parallel 
//
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// feb. 99    Creation                          N.Barrier
//===================================================================
//===================================================================

#include "CATTopRib.h"
#include "ListPOfCATEdge.h"
#include "CATCGMNewArray.h"
#include "CATTopRibConfig.h"

class CATTopRibMacroTool;
class CATTopRibNuplet;
class CATCGMJournalList;
class CATTopRibNupletCand;
class CATWire;
class CATVertexInVolume;
class CATSurParam;
class CATBody;

class CATParallelRib : public CATTopRib
{
 public:

  //-------------------------------------------------------------------------
  // Constructor
  //--------------------------------------------------------------------------
  CATParallelRib(CATTopRibMacroTool * iTool);
  CATParallelRib();

  #ifdef CATTopRibNewArray
  CATCGMNewClassArrayDeclare;        // Pool allocation
  #endif

  //--------------------------------------------------------------------------
  // Destructor
  //--------------------------------------------------------------------------
  virtual ~CATParallelRib();

  //--------------------------------------------------------------------------
  // Ribbon computation propagation
  //--------------------------------------------------------------------------
  void Run();

  //--------------------------------------------------------------------------
  // Getting Ribbon result
  //--------------------------------------------------------------------------
  int NextWire( int iDeform = 1 );
  int GetWire( CATCGMJournalList *iJournal, CATWire *ioWire,
                          CATVertexInVolume *ioVertexInVolume );
  CATListOfInt * GetTwistedEdgesOfWire();
  int HasSolutions();
  CATTopRibNupletCand * const GetSupportCandidates( CATTopRibSign iDirection, 
                              			   CATTopRibPropagation iMode,
						   CATTopRibNuplet *iNuplet,
						   CATBoolean ConfusedIsValidAsNext=FALSE );
  CATBoolean CheckIfEnded( CATTopRibSign        iDirection,
                           CATTopRibPropagation iMode, 
                           int                 &ioCurNuplet,
                           CATBoolean           iSnappingTest=TRUE,
                           CATBoolean           iTestForCycleInsideRibbon=FALSE);

  CATBoolean CheckContinuity( CATTopRibNuplet           *iPrevNuplet,
			      CATTopRibSign              iPrevDir,
			      CATTopRibNuplet           *iNextNuplet,
			      CATTopRibSign              iNextDir,
                              CATTopRibNupletConnexion *&oConnexion,
                              CATListOfInt              *iSupportsToIgnore = NULL,
                              CATBoolean                 iOnlyRollingSupports = CATFalse,
                              CATListOfDouble           *oDistance = NULL);

  CATBoolean CheckIfNupletConfusedWithRibbon (CATTopRibPropagation       iMode,
                                                      ListPOfCATTopRibNuplets   &iListOfAddedNuplets,
                                                      int                        iPosAddNuplet,
                                                      int                        iPosNuplet,
                                                      CATTopRibSign              iDirection);

  CATBoolean FindOtherCandidates( CATTopRibSign iDirection, CATTopRibPropagation iMode,
						 int iNumNuplet);
  void  InitOutside(CATLONG32 iNumInit);
  void  InsertOutSide(CATBody * ioOutsideBody);
  void ConfusedCandidateIsValidAsNext (CATBoolean & ioConfusedIsValidAsNext);

  //Basically detecting that for same pair of supports, already a solution is found or not which is invalid.
  //So, creating a new ribbon is avoided.
  CATBoolean ContainsInvalidCopyOf (CATTopRibNuplet * iNuplet);
  CATListOfInt* GetOverlappedEdgesOfWire();
  void ReplaceNup(CATTopRibNuplet* iNuplet, CATTopRibNuplet*& oNuplet);

 private :
  CATLISTP(CATEdge) _EdgesForUnsetCutting ;
  CATListOfInt *_TwistedEdges;
  CATListPV _TwistedEdgesList;

  CATListOfInt* _OverlappedEdges;
  CATListPV _OverlappedEdgesList;

  //ST5 Wk5-2013: IR 205828 NIHON; avoid redundancy check with REN Wk49-2010 (IR 76606)
  //Detected and ignored InvalidTrack is to do once; else start/end indices of whole rib gets corrupted
  CATTopRibNuplet * _LastInvalidNupletChecked;

             // Deform tracks of nuplet adjacent to iNupletTransition
             // inside the Rib, supress iNupletTransition and update
             // necessary information as poec moved.

  void SupressAndDeform( int iNupletTransition );

             // iParam1 and iParam2 are the points where tracks should
             // be moved on each surface.
             // this method computes an average tangent to have
             // G1 continuity in 3D space after deformation, represented
             // by two tangents in UV space of each surface support.

  int GetTangentForDeformation( int iNupletTransition,
                                CATSurParam *iParam1,
                                CATSurParam *iParam2,
                                CATMathVector2D *oTangent1,
			        CATMathVector2D *oTangent2 );
  CATLONG32 _InitOutSide;


  // Start : SUH : 2003:7:21
  void ComputeDataForHermetisationNew(int iType = 3);
  // End : SUH : 2003:7:21
  
  CATBoolean RearrangeNupletsInsideList(ListPOfCATTopRibNupletsNew &SolNupletList, CATTopRibSign iDirection, int PosToAdd);
  
  //Check if the track on wire support of iNuplet has already been used to compute a parallel in this ribbon
  //Only for geodesic parallel
  CATBoolean CheckNupletWireTrackIfAlreadyUsed(CATTopRibNuplet * iNuplet);
  
protected:
  void IncludeNextNupletInRibbon(CATTopRibSign      iDirection,
                                 CATTopRibNuplet  *&ioLastNuplet, 
                                 int               &ioNumNuplet, 
                                 int               &ioPosNewNuplet,
                                 CATBoolean         iGetConfused = FALSE);  

  CATBoolean FindCouplingECrvSurface(CATTopRibNuplet           *PrevNuplet,
                                     CATTopRibSign              iPrevDir,
                                     CATTopRibNuplet           *NextNuplet,
                                     CATTopRibSign              iNextDir,
                                     CATTopRibNupletConnexion *&oConnexion);
  CATBoolean CheckForJunctionEdge(CATPCurve *iBord1,
                                  CATPCurve *iBord2,
                                  CATVertex *V0,
                                  CATVertex *V1, 
                                  CATEdge *EdgeLink,
                                  double &gap);
  void ConnectNuplet (ListPOfCATTopRibNuplets& iPrevList,
                      CATTopRibSign            iPrevDir,
                      int                     &ioPrevPos,
                      ListPOfCATTopRibNuplets& iNextList,
                      CATTopRibSign            iNextDir,
                      int                     &ioNextPos,
                      CATTopRibNupletConnexion*iConnexion);
  void CreateConnexionNuplet(CATTopRibNuplet * iPrevNuplet,
                                      CATTopRibSign iPrevDir,
                                      CATTopRibNupletConnexion * iConnexion,
                                      CATTopRibNuplet *&oConnexionNuplet,
                                      CATTopRibNuplet * iNextNuplet);
  public:
    // used to identify whether current nuplet is junction nuplet, this info can be used to provide suitable support candidates
    CATBoolean GetCandid( CATTopRibNuplet *iNuplet);

    virtual int  InsertAt(int                      & ioPosToAdd,
                          CATTopRibSign              iDirection,
                          CATTopRibNupletConnexion * &iConnexion,
                          ListPOfCATTopRibNuplets  & iPartToAdd,
                          int                      & ioFirstToAdd,
                          int                      & ioLastToAdd,
                          CATBoolean                 iUpToDate = 0,
                          CATTopRibNupletConnexion * iOtherConnexion = NULL);

    protected:
      virtual CATBoolean FindMoreCandidates(CATTopRibSign        iDirection,
                                            CATTopRibPropagation iMode,
                                            int                  iNumNuplet,
                                            CATArrayOfNupletsLists * NupletsListsArrayPtr);
  };
#endif
//automate:10/09/01:suppression include de CATListOfInt.h
