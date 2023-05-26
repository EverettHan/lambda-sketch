/* -*-C++-*- */

#ifndef CATTopRib_H
#define CATTopRib_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRib
// Classe definissant un ruban topologique
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//===================================================================
//#include "ExportedByCATFDGImpl.h"
//#include "ExportedByRIBLight.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"
#include "CATMathDef.h"
#include "CATMathInline.h"
#include "CATTopRibDef.h" 

#include "CATArrayOfNupletsLists.h"

#include "CATListOfInt.h"
#include "CATListPV.h"
#include "ListPOfCATTopRibNupletConnexion.h"
#include "CATListOfCATCrvParams.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATTopRibNuplets.h"
#include "ListPOfCATTopRibs.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATTopRibSupports.h"


#include "CATCGMJournalList.h"
#include "CATCGMJournalInfo.h"

#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"

class CATCGMFormol;

#include "CATTopRibMacroTool.h"
class CATTopRibTool;
class CATTopRibNuplet;
class CATTopRibNupletConnexion;
class CATTopRibGeoNuplet;
class CATTopRibSupport;
class CATBody;
class CATShell;
class CATCell;
class CATFace;
class CATEdge;
class CATVertex;
class CATSupContact;
class CATTopRibSupCand;
class CATTopRibNupletCand;
class CATLoopExtension;
class CATCrvParam;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCGMActivateDebug;
class CATRibContact;
class CATSewingCompl;
class WireUtilities;
class CATBlendRib;
class CATNtrlDrftRib;
class CATXParam;
class CATRlmNuplet;
class CATRlmRib;


struct CATTopDbgAttribut;

class CATCGMJournalList;

#define DeleteListOfNuplets 1
#define DeleteNuplets       2

#include "CATSafe.h"
CATSafeDefine(CATTopRib);

//#define D1A_SmoothReflectCurveDOSB

class ExportedByRIBLight CATTopRib : public CATTopRibObject
{
 private:
  int                      _StartOfRib;       // Numero du premier Nuplet appartenant au ruban 
  int                      _EndOfRib;         // Numero du dernier Nuplet appartenant au ruban 
  CATTopRibType            _Type;             // Type of ribbon (open, close)
  int                      _DirToPropag;      // Directions dqns lesquelles on peut propager le ruban
  int                      _CompulsoryPropag;

  // Gestion des N-uplets solutions qui
  // n'ont pas encore ete incorpores et
  // qui proviennent d'un calcul fait au
  // prealable (une case pour chaque
  // direction de propagation)
  CATArrayOfNupletsLists *_InitNupletsListsArray[2]; // pointeurs sur les tableaux venant de l'initialisation
                                                     // du ruban et qui sont geres par un objet de type
                                                     // CATRibMultiInitManager
  CATArrayOfNupletsLists  _NupletsListsArray[2];// Listes de Nuplet solutions trouvees lors du dernier ComputeNuplets
                                                // (celles qui ont deja ete incorporee dans le ruban ont ete vide de
                                                // leur Nuplets afin d'eviter qu'elles soient consideres pour la suite)
  CATLONG32               _DeleteLastSol[2];    // Indique s'il faut detruire les listes de solutions (par defaut oui)
  CATBoolean              _UseLastSolBackwardAlsoForForward;
  CATBoolean              _ArrayWasBorrowed[2];
  CATBoolean              _HasInfiniteLoop;
  int                     _NbSameNup;
  CATTopRibNuplet*        _LastNupForCheck[2];

 protected:
  ListPOfCATTopRibNuplets         _ListPOfNuplet   ; // List of Nuplet pointers
  ListPOfCATTopRibNupletConnexion _ListPOfConnexion; // List of NupletConnexion pointers
  CATTopRibMacroTool             *_MacroTool;        // Macrotool for complete ribbon definition
  CATTopRibNuplet                *_FirstNupletExported;
  CATTopRibNuplet                *_LastNupletExported;

  CATCGMJournalList              *_JournalForInnerEdges; // Journal pour les edges internes d'une skin
  CATBoolean                      _GeometricalMultiSolManagementActivity; // Error multisol Actif
  CATBoolean                      _NeedToRearrange;
  CATBoolean                      _IsFreeRib;


 public:

  //------------------------------------------------------------------------------
  // Define argument type
  //------------------------------------------------------------------------------
  enum RibArgType
  {
    CellArg,
    SupportArg
  };

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATTopRib(); 

  private :
  /* Copy constructor. Forbidden */
  CATTopRib(CATTopRib &iRib);
  /* Affectation operator. Forbidden */
  CATTopRib& operator=(const CATTopRib &iRib);

  public:
  //------------------------------------------------------------------------------
  // Clone a Ribbon
  //------------------------------------------------------------------------------
  virtual CATTopRib * CloneRib();
  virtual CATTopRib * CloneRib(int iStartNuplet, int iEndNuplet);
  virtual void DuplicateContents(CATTopRib * iOriginalRib);
  virtual void DuplicateContents(CATTopRib * iOriginalRib, 
                                 int         iStartNuplet,
                                 int         iEndNuplet);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------

  virtual ~CATTopRib();

  //------------------------------------------------------------------------------
  // Writing-Reading methods
  //------------------------------------------------------------------------------

  virtual void SetMacroTool   (CATTopRibMacroTool *const iMacroTool);

  INLINE CATTopRibMacroTool* GetMacroTool() const   { if ( NULL==_MacroTool ) CATThrowForNullPointerReturnValue(NULL); return _MacroTool; }

  
  virtual void SetList (ListPOfCATTopRibNuplets & CurrentRibbon, 
			                  int                       FisrtNupletIn,
			                  int                       LastNupletIn,
                        CATTopRibSign             iDirection = Forward);

  virtual int  InsertAt(int                      & ioPosToAdd,
			                  CATTopRibSign              iDirection,
			                  CATTopRibNupletConnexion * &iConnexion, 
			                  ListPOfCATTopRibNuplets  & iPartToAdd,
			                  int                      & ioFirstToAdd,
			                  int                      & ioLastToAdd,
			                  CATBoolean                 iUpToDate      =0,
                        CATTopRibNupletConnexion * iOtherConnexion=NULL);

  virtual void TransferComplementData(CATTopRibSign     iDirection,
                                      CATTopRibNuplet  *iLastNuplet,
                                      CATTopRibNuplet  *iNewNuplet);

  virtual void RemoveFrom(int                 & ioPosToRemove,
			                    const CATTopRibSign   iDirection,
                          const CATBoolean      iSaveAsExtraNuplet = TRUE );

  virtual CATBoolean   RemoveNuplet(const int iNupletToRemove, const CATBoolean iResetType=TRUE);

  virtual void ExtractFrom(int                     & ioPosToRemove,
                           const CATTopRibSign       iDirection ,
                           int                     & oStart,
                           int                     & oEnd,
                           ListPOfCATTopRibNuplets & oExtractedNups );

  //void         ShiftClosureAfter(const int iNewEndOfRib, const CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Pour la completion, recupere la liste des vertex dont on sait qu'il ne faudra pas les extrapoler
  //------------------------------------------------------------------------------
  virtual void GetNonExtrapolableVertices(ListPOfCATVertex &oNonExtrapolableVertices);

  //------------------------------------------------------------------------------
  // Transfer all N-uplets to a given Ribbon
  //
  // The method returns TRUE if succesful and FALSE otherwise
  //------------------------------------------------------------------------------
  CATBoolean TransferNupletsTo (CATTopRibSign  iDirection, CATTopRib* iRib);



  void         RemoveAllNuplets(); // Remove all N-uplets in the list

  void         RemoveUnusedNuplets(CATTopRibSign iDirection=UnknownDirection,
                                   CATBoolean    iDelExtrRib = TRUE,
                                   CATBoolean    iRemoveExtraNupets = TRUE);          // Remove ExtraNuplets only
                                                                                // if iDirection==UnknownDirection
  void         CleanExtraNuplets (); //jma 25/07/2005
  int          ExtrapolWithExtraNuplets(const CATTopRibSign iDirection, const CATBoolean iOnlyOneNuplet=FALSE);
  // void         AddDegeneratedNuplets(const CATTopRibSign iDirection, const int iNupletCount);

  CATBoolean   RemoveSelfIntersecting(int           iNbDir      ,
                                      CATTopRibSign iDirs[]     ,
                                      int           AddedPart[] ,CATBoolean    iCheckContinuity = TRUE);
  
  void                      SetStartOfRib(const int iNewStart);
  void                      SetEndOfRib  (const int iNewEnd, const CATTopRibSign iDirection=Forward);
  CATTopRibNuplet         * GetEndNuplet(const CATTopRibSign iDirection, int * oEndNupletIndex=NULL);
  CATVertex               * GetEndVertex(CATTopRibSign iDirection, int iSupp);
  int                       GetEndNupletIndex(const CATTopRibSign iDirection) ;
  void                      GetEndParam(const CATTopRibSign  iDirection, const int iNupletIndex, CATCrvParam   &oEndParam, int *oNumRef=NULL   );
  CATTopRibNuplet         * GetLastNupletInList(CATTopRibSign  iDirection, int* oPosLastNuplet = NULL); 
  int                       GetAdjacentNupletIndex(const CATTopRibSign  iDirection, const int iNupletIndex, const CATBoolean iOnlyBetweenStartAndEnd=TRUE) const ;   // return 0 if limit nuplet of Open Rib
                                                   
  INLINE int                GetSize() const              { return _ListPOfNuplet.Size();                                                    };
  INLINE int                GetStartOfRib()              { return _StartOfRib;                                                              };
  INLINE int                GetEndOfRib  ()              { return _EndOfRib;                                                                };
  INLINE CATTopRibNuplet*   GetNuplet(const int i) const { if (i<1 || i>_ListPOfNuplet.Size()) CATThrow (new TopologicalOperatorsInternalError(GBIntEFilletBadNuplet)); CATTopRibNuplet* Nuplet = _ListPOfNuplet[i]; ThrowIfNull(Nuplet); return Nuplet; };

  INLINE CATTopRibType      IsClosed() const {return _Type; }; // Le ruban est-il ferme? // Attention, methode mal nommee ! 
  INLINE int                GetNupletIndex(CATTopRibNuplet * iNuplet) { return _ListPOfNuplet.Locate(iNuplet); }; // Renvoie l'indice d'un nuplet donne du ruban 
  INLINE ListPOfCATTopRibNuplets & GetNupletList() { return _ListPOfNuplet; }; // Renvoie la liste de nuplet du ruban 
  CATGeoFactory*            GetFactory() const;
  CATBody*                  GetCreationBody() const;  

  void                      NotifyCellChange(CATCell* iNewCell, CATCell *iOldCell);
  static void               NotifyCellChange(CATLISTP(CATTopRibNuplet) &ioNupletList, CATCell* iNewCell, CATCell *iOldCell);

  INLINE CATBoolean         IsFreeRib();
  INLINE void               SetFreeRib();
  virtual CATBoolean        HasFreeNup();

  //------------------------------------------------------------------------------
  // Set last N-uplet solutions
  //------------------------------------------------------------------------------
  void SetLastSolNuplet(CATTopRibSign           iDirection,
                        CATArrayOfNupletsLists &iNupletsListsArray,
                        CATBoolean              iDeleteLastSol=TRUE);

  //------------------------------------------------------------------------------
  // Set pointer on initial last N-uplet solutions
  //
  // P.S. These pointers are not deleted by the ribbon (ownership doesn't change)
  //------------------------------------------------------------------------------
  void SetInitLastSolNuplet(CATTopRibSign           iDirection,
                            CATArrayOfNupletsLists *iNupletsListsArray);

  //------------------------------------------------------------------------------
  // Get the last N-uplet solution list array and the number of lists in the
  // array (the latter being optional)
  //------------------------------------------------------------------------------
  CATArrayOfNupletsLists &GetLastSolNuplet(CATTopRibSign  iDirection,
                                           CATBoolean    &oDeleteLastSol,
                                           CATBoolean    &oUseLastSolBackwardsAlsoForForward);

  //------------------------------------------------------------------------------
  // Get the number of N-uplet lists in the last N-uplet solution
  //------------------------------------------------------------------------------
  int GetNbLastSolNupletLists(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Get the number of the last N-uplet solutions
  //------------------------------------------------------------------------------
  int GetNbLastSolNuplets(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Destroy and remove last N-uplet solutions
  //------------------------------------------------------------------------------
  void RemoveLastSolNuplet(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Check if the last N-uplet solutions stored for the two propagation directions
  // are identical
  //
  // Please note: The method generates an error message if it detects any
  //              inconsistency in the date structures
  //------------------------------------------------------------------------------
  CATBoolean AreLastSolsIdentical();

  //------------------------------------------------------------------------------
  // Check if last solution array was borrowed
  //------------------------------------------------------------------------------
  CATBoolean WasLastSolBorrowed(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Queries
  //------------------------------------------------------------------------------
  virtual CATTopRibGeoNuplet * SameGeometry (int             iCurNuplet, 
                                             int           & oEndNuplet,
                                             CATTopRibSign   iDirection=Forward);
  //-----------------------------------------------------------------
  // "Tronque" ioEndNuplet si le ruban est ferme et mon solution afin
  // de ne pas faire une seule face sur une surface fermee. 
  //-----------------------------------------------------------------
          void                 CutIfClosed      (int  iCurNuplet,
                                                 int &ioEndNuplet,
                                                 int iSplitNupletIfNecessary = FALSE);

  virtual void                 GetParameters    (int                     iCurNuplet,
					                                       int                     iEndNuplet,
					                                       CATCrvParam           & oStartParam,
					                                       CATCrvParam           & oEndParam,
					                                       CATTopRibSign         & oOrientation,
					                                       CATLISTP(CATCrvParam) * oInnerParams = NULL);

  virtual CATTopRibSupport   * SameSupport      (CATTopRibSign  iDirection,
                                                 int            iCurNuplet, 
					                                       int            iNumSupp,
					                                       int          & oEndNuplet,
                                                 CATBoolean     iLimitedStorage=CATBoolean(1));

  virtual void                 NupletsUsingCell (CATCell      * iSharingCell,
						                                     CATListOfInt & oNumNuplets ,
						                                     CATListOfInt & oNumSupp    );

  CATCell                    * GetSingleSupportCell (int iNumSupp,
                                                     int iCurNuplet = 0,
                                                     int iEndNuplet = 0);



  virtual CATBoolean           IsLastIn         (int           iCurPos      ,
					                                       CATTopRibSign iDirection   ,
						                                     int           iNbSupp =0   ,
						                                     int          *iNumSupp=NULL);

  
  int                          GetLastIn         (CATTopRibSign iDirection, int * iNumSupp=NULL, CATListOfInt *iForbiddenNuplets = NULL,
                                                  int *iStart=NULL, int *iEnd=NULL);

  CATBoolean 		       IsVertexIn       (int iCurPos, int iNumSupp, CATTopRibSign iDirection);

  virtual CATBoolean           HasCompatibleBlendSupport(CATTopRib * iRib1, int iDir1,
                                                         CATTopRib * iRib2, int iDir2);

  CATBoolean                   IsOnFreeBrdr      (CATTopRibSign iDirection, int numSupport,
                                                  CATBoolean ConfusionsIsFreeBrdr=TRUE);
  CATBoolean                   IsOnFreeBrdr (CATTopRibSign iDirection);
  CATBoolean                   IsOnSharpBrdr (CATTopRibSign iDirection, int numSupport);
  CATBoolean                   IsOnSharpBrdr (CATTopRibSign iDirection);
 
/*  void                         GetListOfCells (int INumSupport, ListPOfCATCell* oCells); */
  //------------------------------------------------------------------------------
  // Partie du ruban comprenant des Nuplets de type indefinis (correspond a des 
  // confusions dans la pratique)
  //------------------------------------------------------------------------------
  void GetConfusedPart(CATTopRibSign iDirection,
                       int           iCurPos,
                       int          &oFirstConfused,
                       int          &oLastConfused);

  //------------------------------------------------------------------------------
  // Partie du ruban a exporter dans une direction 
  //------------------------------------------------------------------------------
  CATBoolean PartToExport(CATTopRibSign  iDirection    ,
                          int           &oFirstToExport,
                          int           &oLastToExport ); 


  //------------------------------------------------------------------------------
  // Mise a jour des infos indiquant les parties du ruban qui ont deja ete
  // exportees 
  //------------------------------------------------------------------------------
  virtual void UpdateExportedPart(CATTopRibSign iDirection    ,
			                            int           iFirstToExport,
			                            int           iLastToExport ,
			                            CATBoolean    iClean=0      );

  //------------------------------------------------------------------------------
  // Remise a zero des infos indiquant les parties du ruban qui ont deja ete
  // exportees 
  //------------------------------------------------------------------------------    
  void RazExportedPart();

  //------------------------------------------------------------------------------
  // Position du dernier nuplet exportee dans une direction 
  //------------------------------------------------------------------------------
  int LastExported(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Direction de propagation d'un ruban (Forward/Backward).
  //------------------------------------------------------------------------------
  void       SetDirection  (CATTopRibSign  iDirToPropag,
                            CATBoolean     iCompulsoryPropag=TRUE);
  void       UnsetDirection(CATTopRibSign  iDirToPropag);
  CATBoolean HasToPropag   (CATTopRibSign  iDirToPropag,
                            CATBoolean    *oCompulsoryPropag=NULL);
											   
  //------------------------------------------------------------------------------
  // Ribbon propagation
  //------------------------------------------------------------------------------

/*  virtual CATBoolean       CanContinue          (CATTopRibSign        iDirection);*/

  virtual CATBoolean       ContinueRibbon       (CATTopRibSign        iDirection,
                                                 CATTopRibPropagation iMode     =PropagStandard);

  virtual CATBoolean       StepOver             (CATTopRibSign        iDirection,
						                                     CATLONG32                 iStep);

  virtual int              GetNewNuplets        (CATTopRibSign        iDirection,
						                                     CATTopRibPropagation iMode);

  virtual int              AddSolIfFound        (CATTopRibSign         iDirection,
	                                               int                  &ioNumNuplet,
	                                               CATTopRibNuplet      *iRefNuplet,
                                                 CATTopRibPropagation  iMode);

  virtual void             ConfusedCandidateIsValidAsNext (CATBoolean & ioConfusedIsValidAsNext);

  virtual CATTopRibNupletCand * const GetSupportCandidates (CATTopRibSign         iDirection, 
						                                                CATTopRibPropagation  iMode,
						                                                CATTopRibNuplet      *Nuplet,
						                                                CATBoolean            ConfusedIsValidAsNext=FALSE);
  
  virtual void             GetSupportCandidates (CATTopRibSign        iDirection,
						                                     CATTopRibPropagation iMode,
						                                     CATTopRibNuplet     *iNuplet,
						                                     CATSupContact       *iContact, 
						                                     int                  iSuppIndex,
						                                     CATTopRibSupCand    *NextSupp,
						                                     CATBoolean           ConfusedIsValidAsNext=FALSE);

          CATBoolean       HasCandidate         (CATTopRibSign        iDirection,
				                                         CATTopRibPropagation iMode     ,
				                                         CATTopRibNuplet     *iNuplet   );

  virtual CATBoolean       FindOtherCandidates  (CATTopRibSign        iDirection,
						                                     CATTopRibPropagation iMode,
						                                     int                  iNumNuplet); 						 

  virtual CATBoolean       IsNextRolling        (CATTopRibSign        iDirection,
						                                     CATTopRibNuplet     *iNuplet,
						                                     int                  iSuppIndex,
                                                 CATSupContact       *iContact,					         
						                                     CATCell             *iCandidateCell,
						                                     CATBoolean           iSameDomain,
						                                     CATTopRibSign       &oOrientation);

// Teste si la cellule que l'on pressent comme candidate est valide d'un point 
// de vue logique, i.e n'a t'elle pas deja ete consideree... 
// oConfusedCandidate = TRUE : Dans le cas ou on refuse les candidats en confusion,
//                             indique que le candidat est en confusion, il est donc accepte 
//                             mais ne doit etre pris seulement QUE SI il ne contient qu'un seul
//                             nouveau support candidat (voir CATTopRibNupletCand::IsNewIndexValid)
// iConfusedIsValidAsNext : TRUE si on veut que les candidats en confusion soient OK d'office
  virtual CATBoolean       IsValidAsNext        (int                iNumSupp,
                                                 CATTopRibSupport *iOldSupport,
				                                         CATSupContact    *iContact,
				                                         CATCell          *iNextCell,
                                                 CATTopRibSupCand *iNextSupp,
                                                 CATEdge          *iGoodEdge,
                                                 CATBoolean       &oConfusedCandidate,
                                                 CATBoolean ConfusedIsValidAsNext=FALSE);

  virtual CATBoolean       CheckContinuity      (CATTopRibNuplet          *PrevNuplet,
						                                     CATTopRibSign              iPrevDir,
                                                 CATTopRibNuplet          *NextNuplet,
                                                 CATTopRibSign             iNextDir,
                                                 CATTopRibNupletConnexion *&oConnexion,
                                                 CATListOfInt              *iSupportsToIgnore = NULL,
                                                 CATBoolean                 iOnlyRollingSupports = CATFalse,
                                                 CATListOfDouble           *oDistance = NULL);
  
  virtual void            CheckContinuityDbg    (CATTopRibNuplet           *PrevNuplet,
                                                 CATTopRibSign              iPrevDir,
                                                 CATTopRibNuplet           *NextNuplet,
                                                 CATTopRibSign              iNextDir,
                                                 CATBoolean                 iResCheck);

          int              AdvCheckContinuity   (int                       iPosNuplet,
						                                     CATTopRibSign             iDirection,
	                                                                             int                       iCmdCheck,
						                                     CATTopRibNuplet          *NewNuplet,
						                                     CATTopRibNupletConnexion *&oConnexion,
                                                 CATListOfInt *iSupportsToIgnore = NULL,
                                                 CATTopRibPropagation iMode = PropagUnknown,
                                                 CATBoolean                iOnlyRollingSupports = CATFalse,
                                                 CATBoolean                iNextToNewIsDegenerate = FALSE);

          void UpdateCandidatesForCheckContinuity(CATTopRibNuplet          *PrevNuplet,
						                                     CATTopRibSign              iPrevDir,
                                                 CATTopRibNuplet          *NextNuplet,
                                                 CATTopRibSign             iNextDir,
                                                 CATTopRibPropagation iMode);


          CATBoolean      CheckDegenNupletsSeries(int                        iPosNuplet,
                                                  CATTopRibSign              iDirection,
                                                  CATTopRibNuplet           *iNewNuplet,
                                                  CATTopRibNupletConnexion *&ioConnexion);

  virtual int              BeforeCheckContinuity(CATTopRibSign             iDirection,
				                                         CATListOfInt              &NumSuppOfModifContact,
				                                         ListPOfCATCell            &NewLinkCellBeforeModifContact,
				                                         CATListOfInt              &NewContactTypeBeforeModifContact,
				                                         CATTopRibNuplet          *CurNuplet,
				                                         CATTopRibNuplet          *PrevNuplet,
                                                 CATTopRibNuplet          *NewNuplet,
                                                 CATTopRibNupletConnexion *Connexion);


  virtual       CATBoolean       CheckIfClosed  (CATTopRibPropagation iMode=PropagStandard,
                                                 CATBoolean           iClose=CATBoolean(1),
                                                 CATBoolean            iExport=CATBoolean(0));

  CATBoolean       CheckIfSigma                 (CATTopRibSign        iDirection,
                                                 CATTopRibPropagation iMode=PropagStandard);

           virtual CATBoolean       CheckIfEnded(CATTopRibSign        iDirection, 
                                                 CATTopRibPropagation iMode     ,
                                                 int                 &ioCurNuplet,
                                                 CATBoolean           iSnappingTest=TRUE,
                                                 CATBoolean           iTestForCycleInsideRibbon=FALSE);
  virtual void             Check                () ;
  virtual void             Dump                 (CATCGMOutput& ioOS);

  INLINE void              SetType              (CATTopRibType iType) { _Type = iType; };
  INLINE CATTopRibType     GetType              () { return _Type; };

  virtual void             ConnectNuplet        (ListPOfCATTopRibNuplets& iPrevList,
					                                       CATTopRibSign            iPrevDir,
                                                 int                     &ioPrevPos,
                                                 ListPOfCATTopRibNuplets& iNextList,
                                                 CATTopRibSign            iNextDir,
                                                 int                     &ioNextPos,
                                                 CATTopRibNupletConnexion*iConnexion); 

  virtual CATBoolean       SplitTrackOnNuplet   (CATTopRibSign iDirection,
	                                               int           iNumNuplet,
                                                 CATBoolean    iKeepBoth=FALSE,
                                                 CATBoolean    iForceSplitOnExportedNuplet=FALSE,
                                                 CATListOfInt * iListOfProtectedSupports = NULL);
                                                 
  virtual CATBoolean       SplitTracksForExport (CATListOfInt * iListOfProtectedSupports);


          CATBoolean       TouchRib             (CATCell       * iCellToCut,
			                                           CATVertex     * iCuttingVertex,
			                                           int           & oTouchSupp,
			                                           int           & oTouchNuplet,
			                                           CATTopRibSign & oOriVsNuplet,
                                                 int             iThrowIfError = 1);
          
          CATBoolean       LocateNuplet         (CATCell * iCell,
						                                     CATCell * iSupportCell,
                                                 int     & oTouchSupp,
                                                 int     & oTouchNuplet,
                                                 int       iFirstNuplet = 0);

          void             UpdateLocation       (CATTopRibSign iDirection,
                                                 int           iLastToUpdate);
                                                 
/*	      void             UpdateLocation       (int           iReference,
						                                     int           iFirstToUpdate,
						                                     int           iLastToUpdate); */

          void             UpdateInternalCutting(const int StartNuplet   = 0,  // default = GetStartOfRib
                                                 const int EndNuplet     = 0,  // default = GetEndOfRib
                                                 const int iSupportIndex = 0); // default = All supports

          void             UpdateEndCutting     (const CATTopRibSign iDirection = BothDirections);

          void             UnsetCutting         (const int        iNumSupp,
                                                 const CATBoolean iUnsetVertices       = FALSE,
                                                 const CATBoolean iCleanDisconnectInfo = FALSE,
                                                 const CATBoolean iRecalculateTouched  = FALSE,
                                                 const CATBoolean iDesactivateCutting  = FALSE,
                                                 const CATBoolean iUnsetSplitCells     = TRUE);
              

//         virtual void      GetSplittingEdge     (const int        iNumSupp,
//                                                 ListPOfCATEdge & oSplitEdge,
//				                                         CATSide        & oSideKeep  );

  //------------------------------------------------------------------------------
  // Indique si iNuplet est deja present dans le ruban
  // - si iOptCheck = 0 (mode par defaut), le test "est deja present" n'est base
  //   que sur des CheckContinuity
  // - si iOptCheck = 1, on regarde si les tracks ne sont pas en confusion avec
  //   une arete bord de leur support. 
  //   Si seul l'un des nuplets est en confusion, la methode renvoie FALSE
  //   Si les 2 sont en confusion, il faut que ce soient sur des aretes
  //   identiques ou jumelles pour renvoyer TRUE
  //------------------------------------------------------------------------------
  
          CATBoolean       Contains             (CATTopRibNuplet         *iNuplet, 
                                                 ListPOfCATTopRibNuplets *iDegeneratedNuplets=NULL,                                                 
                                                 int                      iOptCheck = 0,
                                                 int                      iStart = 0,
                                                 int                      iEnd   = 0,
                                                 CATTopRibNuplet         ** oNupletInRibbon = NULL,
                                                 CATBoolean               iOnlyStantardConnection = FALSE);

          virtual CATBoolean ContainsInvalidCopyOf (CATTopRibNuplet * iNuplet);


  
  //------------------------------------------------------------------------------
  // Indique si vertex est pointe par un nuplet de ce ruban
  //------------------------------------------------------------------------------
  CATBoolean       Contains             (CATVertex * iVertex);        
  //------------------------------------------------------------------------------
  // Set the possible exit N-uplets in iMacroToolRef with the N-uplets
  // of the current ribbon (but only if it uses the same MacroTool)
  //
  // Please note: 1) if iMacroToolRef is not provided, then the current MacroTool
  //                 is used
  //              2) iNumRib is the index that identifies the current ribbon and
  //                 will be added to iMacroToolRef together with the exit
  //                 N-uplets
  //------------------------------------------------------------------------------
  void SetExit (CATTopRibSign       iDirection,
                CATTopRibMacroTool *iMacroToolRef = NULL,
                int                 iNumRib       = 1);



  //------------------------------------------------------------------------------
  // Ribbon initialisation 
  //------------------------------------------------------------------------------
  virtual CATBoolean MakeAndAddNupletWithInits( const CATTopRibSign      iDirection,
                                                const CATTopRibSupp      iTypeOfSupps[], // dimension = _MacroTool->GetNbSupports() ;
                                                const CATTopRibSol       iTypeOfSols[],
                                                const CATTopRibSign      iSupportOrns[],
                                                CATFace*                 iSupportCells[],
                                                CATLoopExtension*        iLoopExtensions[],
                                                const int                iTypeContacts[],
                                                CATVertex*               iInitCells[],
                                                CATCell*                 iLinkCells[],
                                                CATCell*                 iTracks[],
                                                CATCell*                 iExtrapolationContactCell = NULL,
                                                const CATBoolean         iRequireInitUsed = TRUE) ;

  //------------------------------------------------------------------------------
  // Remplir le ruban avec la liste de N-uplets initiaux
  //------------------------------------------------------------------------------
  CATBoolean MakeAndAddNuplets (CATTopRibSign        iDirection,
                                CATTopRibTool       *iTool,
                                CATTopRibSupport   **iSupports,
                                const int            iNbSupports,
				                        CATTopRibGeoNuplet  *iGeoNuplet   = NULL,
                                CATTopRibNuplet     *Nuplet       = NULL,
                                const CATBoolean     iSortInFirst = FALSE,
                                CATEdge             *iCommonEdge  = NULL,
                                const CATBoolean     iRequireInitUsed = TRUE);
  virtual void       SetCandidateOwnerRib(CATTopRibNuplet* iNup);                   // rien sur la classe mere, methode pr les classes derivees
  virtual CATBoolean AddNextNupletInConfusion(CATTopRibNuplet*            iNup,     // idem
                                              ListPOfCATTopRibNupletsNew& iLNups);

  //------------------------------------------------------------------------------
  // journal pour l'enregistrement des edges internes d'une skin 
  // s'il n existe pas, on n'enregistre pas d'edges internes.
  //------------------------------------------------------------------------------
  void SetRecordInnerEdges (CATCGMJournalList * iJournal);

  //------------------------------------------------------------------------------
  // Find initial N-uplets based on the MacroTool
  //------------------------------------------------------------------------------

  // iListeOri contient des orientations par rapport aux sides des faces support
  //           ATTENTION : - Remplir cette liste signifie que les orientations sont
  //                         coherentes entre elles, et donc qu'elles sont toutes
  //                         a garder telles quelles, ou toutes a inverser (voir iTuning).
  //                       - Ne pas la remplir signifie qu'on ignore les orientations, 
  //                         elles seront calculees en interne (4 combinaisons testees)
  // Entree optionnelle n'etant utilisee que si iListeOri est remplie :
  // iTuning    = 1 si il faut "tuner" les orientations (2 combinaisons testees)
  //            = 0 ---valeur par defaut
  //                inutile de "tuner", les orientations entrees sont les bonnes
  //                (une seule combinaison testee)

  // Si iArgType == CATTopRib::CellArg,
  //   iListeSupport contient des ListPOfCATCell *
  // tandis que si iArgType == CATTopRib::SupportArg,
  //   iListeSupport contient des ListPOfCATTopRibSupports *
  // iForce = 1: recherche les solutions geometriques sur les MaxLimits (ex: fillet en biais).

  void FindInitialNuplet             (CATListPV              &iListeSupport,
                                      CATListOfInt           &iListeOri,
                                      CATXParam*              iInit,                       // NULL if no Init to provide
                                      const int               iForce,
                                      CATArrayOfNupletsLists &ioNupletsListsArray,
                                      CATListOfInt           &oFirstNupletIn,
                                      CATListOfInt           &oLastNupletIn,
                                      int                     iTuning=0,
                                      CATTopRib::RibArgType     iArgType=CATTopRib::CellArg,
                                      int                      (*ipIdenticalSupMap)[CATTopRibMaxSupp] = 0);

  // Une deuxieme methode permet de fournir une orientation pour chaque cellule support
  void FindInitialNuplet             (CATListPV              &iListeSupport,
                                      CATListPV              &iListeSupportCompl,
                                      CATListOfInt           &iListeOri,
                                      CATListPV              &iListeOriCompl,
                                      CATArrayOfNupletsLists &ioNupletsListsArray,
                                      CATListOfInt           &ioFirstNupletIn,
                                      CATListOfInt           &ioLastNupletIn,
                                      int                     iTuning=0,
                                      CATTopRib::RibArgType   iArgType=CATTopRib::CellArg);

  //------------------------------------------------------------------------------
  // Methode pour trouver dans les cas ou les contacts des deux Nuplets
  // ont une meme EC pour LinkCell et sont trop eloignes,
  // s'il existe une solution pour passer de l'un a l'autre 
  // sur l'EC.
  //------------------------------------------------------------------------------
  virtual CATBoolean FindCouplingECrvSurface(CATTopRibNuplet           *PrevNuplet,
                                             CATTopRibSign              iPrevDir,
                                             CATTopRibNuplet           *NextNuplet,
                                             CATTopRibSign              iNextDir,
                                             CATTopRibNupletConnexion *&oConnexion);

  CATBoolean IsAutoIntersecting(int iSupp, int iStartNuplet = 0, int iEndNuplet = 0);

  //------------------------------------------------------------------------------
  // Renvoie vrai si la trace donnee du nuplet donne est en train de se propager en out
  // dans la direction donnee
  //------------------------------------------------------------------------------
  virtual CATBoolean TrackIsBeingOutPropagated(CATTopRibSign iDirection, int iNumNuplet, int iNumSupp);
  virtual CATBoolean GetInOutPropagation(int iDirection);
 
  int FindFirstNupletInOnSupport(CATTopRibSign iDirection, int iStartNuplet, int iSupp);
  int FindFirstNupletOutOnOneOtherRollingSupport(CATTopRibSign iDirection, int iStartNuplet, int iSupp);
  int FindFirstNupletOutOnSupport(CATTopRibSign iDirection, int iStartNuplet, int iSupp);

  //------------------------------------------------------------------------------
  // Check if a new relimitation nuplet returns back on the previous one 
  //------------------------------------------------------------------------------
  protected:
  virtual CATBoolean CheckReturnBack(CATTopRibNuplet *LastNuplet, 
                                     CATTopRibSign    iDirection,
                                     CATTopRibNuplet *NewNuplet);

  virtual CATBoolean CheckIfNupletReturnedBack(CATTopRibNuplet *LastNuplet, 
                                               CATTopRibSign    iDirection,
                                               CATTopRibNuplet *NewNuplet);
  
  virtual CATBoolean CheckIfNupletReturnedOnInitial(CATTopRibNuplet *Nuplet);

  private :
  // iListeOri contient des orientations par rapport aux sides des faces support
  void FindInitialNupletHi           (CATTopRib::RibArgType   iArgType,
                                      CATListPV              &iListeSupport,
                                      CATListOfInt           &iListeOri,
                                      CATXParam*              iInit,
                                      const int               iForce,
                                      CATArrayOfNupletsLists &ioNupletsListsArray,
                                      CATListOfInt           &oFirstNupletIn,
                                      CATListOfInt           &oLastNupletIn,
                                      int                       strategie=0,
                                      int                      (*ipIdenticalSupMap)[CATTopRibMaxSupp] = 0);

  CATBoolean ConfigSuiv (int & iPos, int iTailleTab, int ioTab[], int iLongTab[]);

  
  // iSupportOrientation : chaque element contient la future orientation du support
  virtual void  FindInitialNupletLow (CATTopRib::RibArgType   iArgType,
                                      const CATListPV        &iSupport,
                                      const CATListOfInt     &iSupportOrientation,
                                      CATXParam*              iInit,
                                      const int               iForce,
                                      CATArrayOfNupletsLists &iNupletsListsArray,
                                      CATListOfInt           &oFirstNupletIn,
                                      CATListOfInt           &oLastNupletIn);

    // Utilitaire interne qui lance exception si le ruban boucle a l infini, 
  // pourvu qu on l appelle a chaque nouveau Nuplet.
  /*public  :
  virtual void CheckInfiniteLoop(const int iDirection, int & Cycle, int & CycleOrder, int & NewCycle, int & CycleLength) const ;


  private :
  CATBoolean CompareNuplets( const int iNuplet1, const int iNuplet2 ) const ;*/

  // Utilitaire interne qui lance exception si le ruban boucle a l infini, 
  // pourvu qu on l appelle a chaque nouveau Nuplet.
  public  :
  virtual void CheckInfiniteLoop(const int          iDirection, 
                                  CATTopRibNuplet *&ioDebCycleRef, 
                                  CATTopRibNuplet *&ioDebCycleNew, 
                                  int              &ioCycleOrder, 
                                  int              &ioCycleLength);
  private :
  CATBoolean NupletsAreIdentical( const int iNuplet1, const int iNuplet2 ) const ;

   public  :
  //------------------------------------------------------------------------------
  // Degenere une edge en vertex au sein d un ruban
  //------------------------------------------------------------------------------
  virtual CATVertex* ReplaceEdgeByVertex(CATTopRibSign iDirection,
                                         int           iPosFirstNuplet, 
                                         int           iNumSupp,
                                         CATBoolean    iOnlyFirstNuplet = FALSE);

  INLINE CATSoftwareConfiguration* GetSoftwareConfiguration() const { return GetMacroTool()->GetSoftwareConfiguration(); };

  public :
//------------------------------------------------------------------------------
// Split a ribbon on a given N-uplet at a given parameter value
//
// Please note: 1) This works only with a CATCrvParam and Track Edges
//              2) The                whether the N-uplet was actually split in two or not
//              3) If DisconnectTracks == CATBoolean(1) then the method
//  method returns a CATBoolean value that indicates
//                 will actually disconnect the N-uplet's tracks
//              4) If the N-uplet can't be split, the parameter is either
//                 - at the start: oLeftNupletIndex  = 0
//                                 oRightNupletIndex = iNupletIndex
//                 or
//                 - at the end:  oLeftNupletIndex  = iNupletIndex
//                                oRightNupletIndex = 0
//                 Otherwise, if the N-uplet is split in two, the result is
//                 oLeftNupletIndex  = iNupletIndex
//                 oRightNupletIndex = iNupletIndex + 1
//------------------------------------------------------------------------------
  virtual CATBoolean Split (CATLONG32                iNupletIndex,
                            CATCrvParam             &iSplitParam,
                            CATLONG32                iSupportIndex,
                            CATLONG32               &oLeftNupletIndex,
                            CATLONG32               &oRightNupletIndex,
                            CATBoolean               iDisconnectTracks = FALSE,
                            CATCGMJournalList       *iJournal=NULL,
                            CATBoolean               iDuplicateGeometry = TRUE); 

  int IsToBeCompleted(int iDirection, int &oSupp);
  CATBoolean IsNupletToBeCompleted(int iNuplet, int &oSupp);
  CATBoolean SetIsCompleted(int iDirection);

  void CleanCompletionRibs();

//------------------------------------------------------------------------------
// Tries to locate a nuplet from a parameter on an edge
// -> return value : good nuplet index, or 0 if none has been found
//------------------------------------------------------------------------------
  int FindNupletFromParam(int iFirstNuplet, int iLastNuplet, 
                          int iSupportIndex, CATEdge *iTrackEdge, CATCrvParam &iCrvParam);

  void FindNupletsFromTrack(CATCell *iTrackCell, int iSupport, CATListOfInt &oFoundNupletIndexes);

  CATRibContact *CreateRibContactFromVertexAndTrack(CATVertex *iVertex, CATEdge *iTrack, int iSupport);

//------------------------------------------------------------------------------
// Merges iNupletIndex with next Nuplet if Tracks share geometry
// Returns whether merge was done.
//------------------------------------------------------------------------------
  CATBoolean Simplify(const CATLONG32 iNupletIndex, const CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Export d'une partie du ruban
  // Seules les parties "Rolling" le sont
  // Options : iSupportNumber : si on veut exporter les guides
  //                            (1 = exporter les guides)
  //           iFirstToExport et iLastToExport : definit les bornes de l'export
  //                                             (0 = tout exporter)
  //           iNupletsToBeIgnored : liste des Nuplets a ne pas exporter
  //------------------------------------------------------------------------------
  virtual void ExportRibbonTracks(CATCGMJournalList  *iJournal,
                                  ListPOfCATDomain   *&oExportedDomains,
                                  int                 iExportGuide = 0,
                                  int                 iFirstToExport = 0,
                                  int                 iLastToExport  = 0,
                                  ListPOfCATTopRibNuplets *iNupletsToBeIgnored = NULL,
                                  CATBoolean          iUnsetAllCuttings = TRUE,
                                  int                 iNumSupport = 0,
                                  CATBoolean          iAcceptAllConfusions = FALSE);

  //------------------------------------------------------------------------------
  // Nettoyage des edges des tracks
  //------------------------------------------------------------------------------  
  void CleanEdgesFromTracks ();

  //------------------------------------------------------------------------------
  // Compute the list of all nuplets which are out on at least one support
  //------------------------------------------------------------------------------
  virtual void GetAllOutNuplets (ListPOfCATTopRibNuplets &ioListOfOutNuplets);

  //------------------------------------------------------------------------------
  // Extract all the N-uplets of the ribbon
  //
  // Please note: 1) The ribbon doesn't contan any N-uplet after this
  //              2) _StartOfRib and _EndOfRib are set to 0
  //------------------------------------------------------------------------------
  virtual void ExtractNuplets (ListPOfCATTopRibNuplets &oNupletList);

  //------------------------------------------------------------------------------
  // If current Ribbon contains data of a given Ribbon, cleans associated data
  //------------------------------------------------------------------------------
  virtual void CleanBeforeDeletion(CATTopRib * iRibToDelete);

  //------------------------------------------------------------------------------
  // Find out if there are candidates between non-adjacent N-uplets in a ribbon
  //------------------------------------------------------------------------------
  CATBoolean HasCandidatesInGap(CATTopRibSign        iDirection,
                                CATTopRibPropagation iMode,
                                int                  iFirstIndex,
                                int                  iSecondIndex);

  //------------------------------------------------------------------------------
  // renvoie vrai si le ruban traverse une edge sharp sur le support donne
  // Attention: les link cells des nuplets du ruban doivent etre a jour !
  //------------------------------------------------------------------------------
  CATBoolean IsCrossingSharpEdge(int iNumSup, CATLISTP(CATGeometry) *iObjectsToIgnore = NULL);

  //------------------------------------------------------------------------------
  // renvoie vrai si le ruban traverse une edge sharp sur le support donne
  //------------------------------------------------------------------------------
  CATBoolean IsCrossingSharpEdgeOnSupport(int iNumSup, CATLISTP(CATGeometry) *iObjectsToIgnore = NULL);

  //------------------------------------------------------------------------------
  // renvoie vrai si le ruban traverse iEdge sur le support donne
  //------------------------------------------------------------------------------
  CATBoolean IsCrossingEdge(int iNumSup, CATEdge * iEdge);

  //------------------------------------------------------------------------------
  // renvoie toutes les aretes vives traversees par le ruban
  //------------------------------------------------------------------------------
  void GetCrossedSharpEdges(int iNumSup, ListPOfCATEdge &oCrossingSharpEdges);

  //------------------------------------------------------------------------------
  // verifie si le ruban se recouvre, optionnel : on teste this contre une
  // liste de rubans
  //------------------------------------------------------------------------------
  CATBoolean IsSigmaConfig(CATTopRibSign iDirection, ListPOfCATTopRibs     *iRibs = NULL);
  CATBoolean IsSigmaConfigVsNuplet(CATTopRibSign iDirection, CATTopRibNuplet *iNuplet);

#ifdef D1A_SmoothReflectCurveDOSB
  protected :
#else
  private:
#endif

  //------------------------------------------------------------------------------
  // trouver le wire auquel iEdge pourrait se connecter (avec lequel iEdge partage
  // un vertex.
  //------------------------------------------------------------------------------
  CATDomain * FindGoodWireForEdge (ListPOfCATDomain   &iExportedWires, 
                                   CATEdge            *iEdge);

 protected:
  //------------------------------------------------------------------------------
  // Get the bumpers of a support cell (edge only, at the moment)
  // This method can not compute orientations : CATSideUnknown is set
  // Return the number of bumpers computed
  // oPosOfCovererBumper = 0  unknown
  //                       -1 not covered
  //                       1  covered
  // ATTENTION : size of oBumpers and oOriBumpers should be 2
  //             size of oCoveredBumpers should be 2
  //------------------------------------------------------------------------------
  virtual int ComputeBumpers(int iNumSupport, CATCell * iCellSupp,
                             CATCell * oBumpers[], CATSide oOriBumpers[], 
                             int oCoveredBumpers[]);
  
  //------------------------------------------------------------------------------
  // enregistrement d edges generes par les nuplets (on enregistre les <<IN>> seuls)
  // Si INumSupport n'est pas renseigne (0), on prend tous les supports 
  //    A noter que dans ce cas qu'on ne fait rien si le support est "guide"
  // Si INumSupport est renseigne, tout type de support est accepte
  // iExtremities indique si on veut suivre les vertices extremites de ruban
  // (0=non qui est la valeur par defaut ; 1=oui)
  // (jma, le 8.12.99 : ajout de la liste d edges, oEdges, qui ont fait lobjet d'un ordre
  // de creation dans le journal : cette liste est calculee dans la methode si l'adresse
  // non nulle)
  // (jma le 03.12.01 ) Ajout de iAuxJournalForSupports, si les supports stockes dans
  // les nuplets ne sont pas de faces initiales, comme dans le cas de fillet avec parting,
  // et que le fillet doit se referer aux faces initiales, comme dans fillet en NoTrim,
  // ce journal nous permet de retrouver ces faces a travers les modifications enregistrees.
  //------------------------------------------------------------------------------
  /*
  virtual void RecordCreatedEdges (CATCGMJournalList *iJournal, int INumSupport,
                                   int iExtremities=0, ListPOfCATEdge* oEdges=NULL,
                                   ListPOfCATTopRibNuplets *iNupletsToBeIgnored=NULL,
                                   CATCGMJournalList *iAuxJournalForSupports = NULL);
  */

  //------------------------------------------------------------------------------
  // enregistrement d edges generes par les nuplets du ruban
  // iFirstToExport : Premier Nuplet generant une edge
  // iLastToExport  : Dernier Nuplet generant une edge
  // oEdge          : Liste des edges generees
  // INumSupport    : Numero du support origine (0 tous les supports) 
  // iExtremity     : Suivi des vertices extremites
  //------------------------------------------------------------------------------
  virtual void RecordAllCreatedEdges (CATCGMJournalList *iJournal,
                                      int                iFirstToExport,
                                      int                iLastToExport,
                                      ListPOfCATEdge    *oEdges             = NULL,
                                      int                INumSupport        = 0,
                                      int                iExtremity         = 0,
                                      CATBoolean         iJournalForINumSupport = FALSE,
                                      ListPOfCATTopRibNuplets      *iNupletsForJournal= NULL);

  //------------------------------------------------------------------------------
  // enregistrement de vertex generes par les nuplets (on enregistre les <<IN>> seuls)
  // Si INumSupport n'est pas renseigne (0), on prend tous les supports 
  //    A noter que dans ce cas qu'on ne fait rien si le support est "guide"
  // Si INumSupport est renseigne, tout type de support est accepte
  //------------------------------------------------------------------------------
  virtual void RecordCreatedVertices (CATCGMJournalList *iJournal, int INumSupport, ListPOfCATVertex* oVertices);

  //------------------------------------------------------------------------------
  //Methodes dediees a la deformation.
  //------------------------------------------------------------------------------
  virtual void ComputeDataForHermetisation();


  //return is 1 if there is a deformation, 0 else.
  virtual CATLONG32 ComputeDeformation(CATTopRibGeoNuplet* iGeoNuplet,int iFirstNuplet,int iLastNuplet);

  virtual CATBoolean ComputeHermetisation(CATTopRibGeoNuplet * iGeoNuplet,int iFirstNuplet,int iLastNuplet,
				    CATBoolean oExtremite[2],CATCrvParam ** &oCrvParamHermStart,CATCrvParam ** &oCrvParamHermEnd,
            CATBoolean oHealingNeededStart[CATTopRibMaxSupp], CATBoolean oHealingNeededEnd[CATTopRibMaxSupp]);

  virtual CATBoolean CanAcceptCandidate(CATEdge *iEdge, int iNumSupp);
  
  //------------------------------------------------------------------------------
  //Methodes dediees a la validation de nouveaux nuplet.
  //------------------------------------------------------------------------------
  virtual void CheckNupletForInsertion(CATTopRibPropagation       iMode,
                                       CATTopRibNuplet           &iReferenceNuplet,
                                       ListPOfCATTopRibNuplets   &iListOfAddedNuplets,
                                       int                        iPosNuplet,
                                       CATTopRibSign              iDirection,
                                       int                       &oPosNuplet,
                                       int                       &oPosNewNuplet,
                                       CATTopRibNupletConnexion *&oConnexion);

  virtual CATBoolean CheckIfNupletConfusedWithRibbon (CATTopRibPropagation       iMode,
                                                      ListPOfCATTopRibNuplets   &iListOfAddedNuplets,
                                                      int                        iPosAddNuplet,
                                                      int                        iPosNuplet,
                                                      CATTopRibSign              iDirection);
    
  int CheckIfNupletStartsFromInit (CATTopRibNuplet  *iAddNuplet,
                                   CATTopRibSign     iDirection);

  int CheckIfNupletReachedExit (CATTopRibNuplet  *iAddNuplet,
                                CATTopRibSign     iDirection);

  int CheckIfNupletBetweenInitExit (CATTopRibNuplet  *iAddNuplet);

  virtual CATBoolean CheckIfNupletWasIsotopologicallyInvalid(CATTopRibNuplet *LastNuplet,
                                                             CATTopRibSign    iDirection,
                                                             CATTopRibNuplet *NewNuplet);

  //-------------------------------------------------------------------
  // Get the effective number of N-uplets in the ribbon
  //-------------------------------------------------------------------
  private :
  virtual int GetEffectiveNumberOfNuplets();

//------------------------------------------------------------------------------
// Select the best geometrical solution
//------------------------------------------------------------------------------
  private :
  int SelectBestNupletList(CATTopRibSign           iDirection,
                           CATArrayOfNupletsLists &iNupletsListsArray,
                           CATLONG32               iNbConnectedListsOfSolutions,
                           CATListOfInt           &iIndexOfConnectedListsOfSolutions,
                           CATListOfInt           &iPositionOfConnectedNuplet,
                           CATListOfInt           &iPositionOfSupportNuplet);

  int SelectBestNuplet(CATTopRibNuplet * iLeftNuplet, CATTopRibNuplet * iRightNuplet, CATSupContact * iInit);

  protected :
  // Interne de GetNewNuplets
  virtual void GetNewNupletsInsideRibbon(CATTopRibSign      iDirection,
                                         CATTopRibNuplet * &ioLastNuplet,
                                         int               &ioNumNuplet,
                                         int               &ioPosNewNuplet,
                                         CATBoolean        &ioTryLastSolNuplet,
                                         CATBoolean        &ioLastSolNupletAlreadyTried,
                                         CATBoolean        &ioIter,
                                         CATBoolean         iGetConfused = FALSE);

  //-------------------------------------------------------------------------
  // Include next N-uple tin ribbon
  //-------------------------------------------------------------------------
  protected :
  virtual void IncludeNextNupletInRibbon(CATTopRibSign      iDirection,
                                 CATTopRibNuplet  *&ioLastNuplet, //dernier nuplet du ruban
                                 int               &ioNumNuplet, // fin du ruban pour recherche en cours
                                 int               &ioPosNewNuplet,
                                 CATBoolean         iGetConfused = FALSE);

  //-------------------------------------------------------------------
  // Add the confused N-uplet at the end of the ribbon,
  //
  // IF the current last N-uplet has no candidates, except on one
  // support where it has reached an edge (this means that the support
  // MUST be a face),
  //
  // AND IF the next N-uplet is confused with that same edge on the
  // same support
  //
  // The method returns TRUE if it has been able to add at least
  // one N-uplet to the ribbon
  //-------------------------------------------------------------------
  protected:
  CATBoolean AddConfusedNuplet(CATTopRibSign        iDirection,
                               CATTopRibPropagation iMode);

  //-------------------------------------------------------------------
  // This method inhibits the usage of CATTopRib::AddConfusedNuplet
  // It can be implemented in the child classes in order to change
  // the default behavior
  //-------------------------------------------------------------------
  protected:
  virtual CATBoolean TryAddConfusedNuplet();

  //-------------------------------------------------------------------
  // Check if the ribbon length is smaller than the gap between the
  // ribbon's two ends (this method is to be called when it can be
  // assumed that the ribbon is closed, except for the fact that
  // the ribbon itself may be smaller, i.e. shorter, than the gap)
  //-------------------------------------------------------------------
  protected:
  CATBoolean RibbonIsSmallerThanGap();

  //-------------------------------------------------------------------
  // Check if the length of each of the two N-uplets is smaller than
  // the gap between their extremities (as defined by the two provided
  // idrections)
  //-------------------------------------------------------------------
  protected:
  /*
  CATBoolean NupletsAreSmallerThanGap(CATTopRibNuplet *iPrevNuplet,
                                      CATTopRibNuplet *iNextNuplet,
                                      CATTopRibSign    iPrevDirection,
                                      CATTopRibSign    iNextDirection);
  */
  private :
  //------------------------------------------------------------------------------
  // Check wether all surfaces are canonic
  //------------------------------------------------------------------------------
  CATBoolean AllSupportsAreCanonic(const CATListPV &iSupport, CATTopRib::RibArgType iArgType);

  protected:
  //------------------------------------------------------------------------------
  // Determiner le nuplet solution valide et "connect-able"
  //
  // N.B.: 1) La methode retourne FALSE si on trouve PLUS d'une
  //          seule solution, et TRUE si on trouve aucune OU une
  //          seule solution.
  //       2) Si la methode rend FALSE, elle nettoie la memoire
  //          (en particulier elle detruit les nuplets de iNupletsListsArray)
  //------------------------------------------------------------------------------
  CATBoolean GetBestNupletListForInsertion(CATTopRibSign                    iDirection,
                                           CATTopRibPropagation             iMode,
                                           int                              NumNuplet,
                                           CATTopRibNuplet                 *NewNuplet,
                                           CATArrayOfNupletsLists          &iNupletsListsArray,
                                           CATListOfInt                    &ListOfPosToAdd,
                                           CATListOfInt                    &ListOfPosNewNuplet,
                                           CATListOfInt                    &ListOfListIndex,
                                           ListPOfCATTopRibNupletConnexion &ListOfConnexion);


  //--------------------------------------------------------------------
  // Vérifie dans la liste de nuplets que l'on vient d'inserer
  // si l'on peut créer une connexion
  // ex : Liste = (confused,out,in)
  //      peut-on créer une connexion entre (confused et in)
  // Implémenté dans CATRlmRib
  //--------------------------------------------------------------------
  virtual void CheckContinuityInListOfNuplet(CATTopRibSign iDirection,
                                     int          &ioPosNewNuplet);



  public :

  //------------------------------------------------------------------------------
  // Methodes necessaires au debug
  //------------------------------------------------------------------------------
  virtual void  ShowTrack (CATGeoFactory    *iGeoFactory, CATCGMActivateDebug *iBrkPntMngr=NULL,CATTopDbgAttribut * iAtt=NULL);
  virtual void ShowEndOfRib(CATTopRibSign iDirection, CATGeoFactory *iGeoFactory, CATCGMActivateDebug *iBrkPntMngr=NULL, CATTopDbgAttribut * iAtt=NULL);
  void CleanDebug(CATBoolean WithNuplets = FALSE);


  CATLISTP(CATGeometry) ObjectsForDebug;
  CATCGMFormol * _Formol;

  //--------------------------------------------------------------------
  // Create bodies with the track of the ribbon's N-uplets (on a
  // given support)
  //
  // Please note:
  // iOnlyNonExportedTracks is optional (generate bodies with the
  // tracks of not yet exported N-uplets)
  //--------------------------------------------------------------------
  public:
  void CreateBodiesWithTracksOnSupport(int                iSupportIndex, 
                                       CATLISTP(CATBody) &oBodies,
                                       CATBoolean         iOnlyNonExportedTracks = FALSE);

  
  void CreateWiresWithTracks(ListPOfCATDomain &CreatedWires, CATBoolean AllInRequired=FALSE, int iForceSupport = 0,
    CATBoolean iAddToCreationBody = CATTrue);


  // Start : AJD : 2003:4:7
  //--------------------------------------------------------------------
  // Set Connexion data
  // iMode = -1 => Only healing needed, iIsHealingNeeded must be TRUE
  // iMode = 0 => Clear Connexion (if ( iSupportInd==0 ) clears all supports
  // iMode = 1 => Set only start prm
  // iMode = 2 => Set only end prm
  // iMode = 3 => Set both start and end prm => default mode
  
  CATBoolean SetConnexionData( int iConnexionInd, int iSupportInd,
                         const CATCrvParam &iStartPrm,
                         const CATCrvParam &iEndPrm,
                         int iMode = 3,
                         CATBoolean iIsHealingNeeded = FALSE
                         );
  
  // New method to compute data for hermetisation
  // iType
  //    iType = 1, compute data on common support
  //    iType = 2, compute data on link 
  //    iType = 3 (1|2), Compute data on common support and on link
  // StartOfRib : Start of rib can be explicitly specified, if -1, GetStartOfRib will be used
  // EndOfRib : End of rib can be explicitly specified, if -1, GetEndOfRib will be used
  void ComputeDataForHermetisationNew( int iType = 3, int iStartOfRib = -1, int iEndOfRib = -1);

  //--------------------------------------------------------------------
  // End : AJD : 2003:4:7
  

  //------------------------------------------------------------------------------
  // Parcours le ruban et transforme les nuplets dont une trace est trop petite
  // en nuplet degenere 
  //
  // Les deux index debut et fin sonmt optionnels et permettent de donner un
  // intervalle plus court su rle ruban
  //------------------------------------------------------------------------------
  public:
  void FixDegeneratedTracks(int        iFirstIndex = 0,
                            int        iLastIndex  = 0,
                            CATBoolean iOneNupletAtATime = FALSE);

  CATBoolean RecongniseCellAsSupport (CATCGMJournalList * iJournal,
                                                 CATCell *iCell,int     & oTouchSupp,
                                                 int     & oTouchNuplet,
                                                 int       iFirstNuplet = 0);

  public:
  //------------------------------------------------------------------------------
  // Compare exported faces
  //------------------------------------------------------------------------------
  virtual CATBoolean CompareExportedFaces(const int iNuplet1, const int iNuplet2, const int iNumSupp);

  //------------------------------------------------------------------------------
  // Store an exported face
  //------------------------------------------------------------------------------
  /*
  void StoreCreatedFace(CATFace        *iFace,
                        CATOrientation  iFaceOrientation,
                        const int       iFirstNuplet,
                        const int       iLastNuplet);
  */
  //------------------------------------------------------------------------------
  // For two N-uplets that are ready to be connected (iDistance contains the
  // distance values computed by CheckContinuity/ComputeGap), check whether
  // one of them isn't actually just a very small inverted N-uplet (i.e. if it were
  // inverted once more, the connection would be much better)
  //------------------------------------------------------------------------------
  private:
  CATBoolean CheckIfOppositeConnectionIsBetter(CATTopRibSign    iDirection,
                                               CATTopRibNuplet *iCurNuplet,
                                               CATTopRibNuplet *iNewNuplet,
                                               CATListOfDouble &iDistance,
                                               CATListOfInt    *iSupportsToIgnore,
                                               CATBoolean       iOnlyRollingSupports);
  virtual void SetDataForRlmRib(CATTopRibNuplet *iNewNuplet);

  public:
  virtual void SetCompletedNuplet(CATTopRibNuplet* iNupletCompleted, CATTopRibSign iDirection);
  virtual CATRlmNuplet* GetCompletedNuplet(CATTopRibSign    iDirection);

  //------------------------------------------------------------------------------
  // Check whether a "loose," i.e. non-hermetic, connection between two N-uplets
  // is not actually over-riding one or several inverted N-uplets (which would
  // generate hermetic connections if only they were not inverted)
  //
  // If this is the case the method returns TRUE (otherwise it returns FALSE)
  //------------------------------------------------------------------------------
  private:
  CATBoolean CheckConnectionOverInvertedNuplets(CATTopRibSign           iDirection,
                                                CATTopRibPropagation    iMode,
                                                CATTopRibNuplet        *iReferenceNuplet,
                                                int                     iNumNuplet,
                                                CATArrayOfNupletsLists &iNupletsListsArray,
                                                int                     iList,
                                                int                     iPosNewNuplet);

  //------------------------------------------------------------------------------
  // Check whether a connection can be obtained between two N-uplets that is
  // better than a non-hermetic connection that yielded a larger gap (more than
  // the factory resolution - the data is contained in iReferenceDistance)
  //------------------------------------------------------------------------------
  private:
  CATBoolean CheckBetterContinuity(CATTopRibNuplet *iPrevNuplet,
                                   CATTopRibSign    iPrevDirection,
                                   CATTopRibNuplet *iNextNuplet,
                                   CATTopRibSign    iNextDirection,
                                   CATListOfDouble &iReferenceDistance,
                                   CATListOfInt    *iSupportsToIgnore = NULL,
                                   CATBoolean       iOnlyRollingSupports = FALSE);

  //------------------------------------------------------------------------------
  // CanConvertNupletOnLoopExtension
  //------------------------------------------------------------------------------
  private:
  virtual CATBoolean CanConvertNupletOnLoopExtension(CATTopRibSign iDirection,
    CATTopRibNuplet * iRefNuplet,
    CATTopRibNuplet *& ioNextNuplet,
    int &ioNumLastNuplet);

  public:
  virtual int ReUseLastGeoNupletForExtrapolation(CATTopRibSign iDirection, 
    int iNumNuplet, 
    CATTopRibNuplet *iNewNuplet, 
    CATTopRibPropagation iMode);


  //------------------------------------------------------------------------------
  // CleanPrevNuplet
  //------------------------------------------------------------------------------
  private:
    void CleanPrevNuplet(CATTopRibNuplet * iNuplet);

  //------------------------------------------------------------------------------
  //Isolate the ribbon
  //------------------------------------------------------------------------------
  public:
  virtual void Isolate(CATBoolean iOperationIsOK=FALSE);

  
  // Added By : AJD : 2004:6:23
  //------------------------------------------------------------------------------
  // Attempts to insert semi degenerate nuplet from 1st In-OUT nuplet from CuNupPos
  // Return position of new nuplet if successful
  // zero otherwise
  //------------------------------------------------------------------------------
  int AttemptSemiDegenNuplet( CATTopRibSign iDirection, int CurNupPos);

  //------------------------------------------------------------------------------
  // Gestion du flag InfiniteLoop
  //------------------------------------------------------------------------------
  private:
  void SetInfiniteLoopFlag(CATBoolean iInfiniteLoopFlag);
  public:
  CATBoolean HasInfiniteLoop();
 
  public :
  //-----------------------------------------------------------------
  // Mise a jour des infos dans les nuplets sur les appuis et les edges et dans le journal Officiel de l'operateur
  //-----------------------------------------------------------------
  virtual void UpdateWithJournal(CATCGMJournalList * iJournal, 
                                 ListPOfCATEdge    & iEdgesToReject, 
                                 CATShell          * iShellAfterDisconnect=NULL);

  virtual void UpdateRibbonWithJournal(CATCGMJournalList* iJournal, CATSewingCompl &iSewingCompl, const CATBoolean iRemoveNullSupportNuplets=FALSE);

  public:
  CATBoolean CreateWireUtilities(CATLONG32 iRefTrack);
  CATBoolean MoveAlongWire(int iRefNupletIndex, CATCrvParam &iRefParam, double iShift, CATTopRibSign &iDirWrtWire, 
    int &oNewNupletIndex, CATCrvParam & oNewParam);
  void RemoveWireUtilities();

  WireUtilities * GetWireUtilites();
  private:
  WireUtilities * _WireUtilities;
  CATListOfInt  * _FromGeoNToN;
  CATListOfInt  * _FromNToGeoN;

  private:
    // gestion des bumpers couverts en cas d'ambiguite
    CATBoolean ChoseBestCoveredBumperForSupport (int iSupp, CATTopRibSupport *iSupport, 
                                           const CATListPV  &iOtherSupports, 
                                           CATTopRib::RibArgType iArgType);

  public :
    CATCell* GetCoveredBumper(CATTopRibNuplet& iNuplet, const int iNumSupp);

    virtual CATBoolean HasInitiallyShiftedTracks ();
    
  public :
    int GetNextIn (int iNumNuplet, int iNumSupp, CATTopRibSign iDirection);

  public:
    virtual CATBoolean PropagateConfusedInit();

  protected:
    virtual CATBoolean CheckCandidateForVtxTrack (CATTopRibSign         iDirection,
                                                  CATTopRibNuplet*      iNuplet, 
                                                  CATSupContact*        iContact,
                                                  CATFace*              iCandFace,
                                                  int                   iSupp,
                                                  CATTopRibPropagation  iMode);

  //------------------------------------------------------------------------------
  // Verification logique pour determiner si deux N-uplets n'ont pas pas besoin
  // d'un N-uplet intermediaire, i.e. s'il ne faudra pas une etape de propagation
  // supplementaire avant de fermer le ruban
  //------------------------------------------------------------------------------
  protected:
  virtual CATBoolean CheckIfNupletsNeedPropagationForConnection(CATTopRibNuplet      *iLeftNuplet,
                                                                CATTopRibSign         iLeftDirection,
                                                                CATTopRibNuplet      *iRightNuplet,
                                                                CATTopRibSign         iRightDirection,
                                                                CATTopRibPropagation  iMode);
  public :
  virtual CATBoolean IsLongPropagationSet (CATTopRibSign  iDirection);
  virtual CATBoolean NeedLongPropagation (CATTopRibSign  iDirection);


  protected:
    virtual CATBoolean JunctionReached(CATTopRibNuplet         *iNuplet,
                                       int                      iStart,
                                       int                      iEnd);

    virtual CATBoolean CheckSupportForInclusion();
    virtual CATBoolean RearrangeNupletsInsideList (ListPOfCATTopRibNupletsNew &SolNupletList,
                                                   CATTopRibSign iDirection,
                                                   int PosToAdd);
  private :
  CATBoolean CheckIfAlreadyConnected (CATTopRibNuplet         *iPrevNuplet,
                                               CATTopRibSign            iPrevDir,
                                               CATTopRibNuplet         *iNextNuplet, 
                                               CATTopRibSign            iNextDir);
  // REN wk09 2006
   protected:
      void SetNeedToRearrange(CATBoolean NeedToReArrange);
      CATBoolean GetNeedToRearrange();
      // specific to parallel nuplet missing sol
      virtual CATBoolean GetCandid(CATTopRibNuplet *iNuplet);
  private:
    void GetSupportCandidates_VertexLinkCell(CATVertex * const iEndSommet, int const iDimCellSupp,
      CATTopRibNuplet *const iNuplet, CATSupContact *const iContact, CATSupContact &iVContact,
      CATTopRibSign const iDirection, int const iSupp, CATEdge * &oGoodEdge, CATCell *const iCellSup,
      CATTopRibSupCand *const iNextSupp, CATCell *const iLink, CATSupContact &iMContact, CATFace *&oLastFace,
      CATTopRibSign &oOriRef, CATTopRibSign &oOriSave, ListPOfCATFace &iAdjFaces, CATListOfInt &iNewRadialFaceOrder,
      int &oMaxRadialFaceSupport, CATListOfInt &iNewRadialEdgeOrder, int &oMaxRadialEdgeSupport,
      ListPOfCATTopRibSupports &iNewSupportToAdd, ListPOfCATEdge &iAdjEdges, CATEdge *&oRollingEdge,
      CATBoolean const iConfusedIsValidAsNext, int &oCurrentEdge);
    void GetSupportCandidates_EdgeLinkCell(CATCell * const iLink, int const iDimCellSupp, CATFace *&oLastFace,
                                                  CATTopRibNuplet *const iNuplet, CATCell *const iCellSup,
                                                  ListPOfCATEdge &iAdjEdges, ListPOfCATFace &iAdjFaces,
                                                  int const iSupp, CATEdge *&oRollingEdge);
    void GetSupportCandidates_ManageRollingEdges(CATEdge *&oRollingEdge, CATBoolean &oRollingEdgeCand,
                                                        CATTopRibSign const iDirection, CATTopRibNuplet *const iNuplet, int const iSupp,
                                                        CATSupContact *const iContact, CATBoolean const iSameDomain,
                                                        CATTopRibSign &oSens, 
                                                        const ListPOfCATFace &iAdjFaces, const ListPOfCATEdge &iAdjEdges,
                                                        int const iDimCellLink, CATFace *&oLastFace, CATTopRibSign &oOriRef,
                                                        int const iDimCellSupp, CATListOfInt &iNewRadialFaceOrder,
                                                        CATListOfInt &iNewRadialEdgeOrder, int &oMaxRadialEdgeSupport,
                                                        ListPOfCATTopRibSupports &iNewSupportToAdd,
                                                        CATTopRibSupCand *const iNextSupp,
                                                        int &oCurrentEdge);
    void GetSupportCandidates_ManageCandidateFaces(ListPOfCATFace &iAdjFaces, ListPOfCATEdge &iAdjEdges,CATTopRibSign &oSens,
                                                          CATSupContact &iVContact, CATSupContact &iMContact,
                                                          CATTopRibSign &oOriRef, CATTopRibSign const iOriSave, int const iSupp, CATCell *const iCellSup,
                                                          CATBoolean &oSameDomain, CATTopRibSupCand *const iNextSupp, CATVertex *const iEndSommet,
                                                          CATTopRibNuplet *const iNuplet, CATEdge *const iGoodEdge, CATBoolean const iConfusedIsValidAsNext,
                                                          CATTopRibSign const iDirection, CATSupContact *const iAVContact, int const iDimCellSupp,
                                                          CATSupContact *const iContact, CATListOfInt &iNewRadialFaceOrder,
                                                          CATListOfInt &iNewRadialEdgeOrder, int &oMaxRadialEdgeSupport,
                                                          ListPOfCATTopRibSupports &iNewSupportToAdd, CATTopRibPropagation const iMode,
                                                          int &oMaxRadialFaceSupport, CATFace *const iLastFace, int const iDimCellLink);
    void GetSupportCandidates_ManageCandidateEdges(CATTopRibSign &oOriRef, CATTopRibNuplet *const iNuplet, ListPOfCATEdge &iAdjEdges,
                                                          int const iSupp, CATSupContact *const iContact, CATTopRibSupCand *const iNextSupp,
                                                          CATEdge *const GoodEdge, CATBoolean &SameDomain, CATCell *const CellSup, int const DimCellSupp,
                                                          CATTopRibSign const iDirection, CATTopRibSign &oSens, CATListOfInt &iNewRadialFaceOrder,
                                                          CATListOfInt &NewRadialEdgeOrder, int &MaxRadialEdgeSupport,
                                                          ListPOfCATTopRibSupports &iNewSupportToAdd,
                                                          int &oMaxRadialFaceSupport);
    void GetSupportCandidates_NewKeepEdgePropagation(CATBoolean const iRollingEdgeCand,CATListOfInt &iNewRadialFaceOrder,
                                                          CATListOfInt &iNewRadialEdgeOrder, int &oMaxRadialEdgeSupport,
                                                          ListPOfCATTopRibSupports &iNewSupportToAdd,
                                                          int &oMaxRadialFaceSupport, CATTopRibSupCand *const iNextSupp);

    CATBoolean GetNextValidCandidate(CATTopRibNupletCand *iNupletCand, int iNumberOfSupports, CATTopRibSupport **&ioSupports);
     virtual CATBoolean IsCandidateValid(CATTopRibSupport **iCandidateSupports, int iNumberOfSupports);

  protected:
    virtual CATBoolean FreezePossible(int iSupp, CATTopRibSign iDirection);

    virtual void PropagateValidityStatus(const CATTopRibSign iDirection, 
                                         CATTopRibNuplet &iNupletRef, 
                                         const int iFromNupletIndex);

  virtual int GetLastToAddInRib(int iSolInList, ListPOfCATTopRibNupletsNew & iSolNupletList, 
                                CATTopRibSign iDirection, int PosToAdd, CATBoolean iusedPrecomputedNuplet=FALSE); //D1A: 2-Mar-2012

  //------------------------------------------------------------------------------
  // Methodes de cast : rendent NULL si cast impossible
  //------------------------------------------------------------------------------
public:
  virtual CATBlendRib*              GetAsBlendRib();
  virtual CATNtrlDrftRib*           GetAsNtrlDrftRib();
  virtual CATRlmRib*                GetAsRlmRib();
  virtual CATRlmRib*                GetAsExtrRib(); // Ruban d'extrapolation
  //Start: SOU 
  //for Multi-Core
public:
  //iListToTransfer is the index of list in iNupletListArray to be transferred from iNupletListArray to CATTopRib::_PrecomputedNupletLists
  void AppendPreComputedNupletsList(CATArrayOfNupletsLists& iNupletListArray, int iListToTransfer, int iFirstIn, int iLastIn);
  int TryUsePreComputedNupletsList(const CATTopRibNuplet *iPrevNuplet, CATTopRibSupport** iNewSupp, CATArrayOfNupletsLists& oNupletListArray);
  CATBoolean ReportUsedPrecomputedNuplet(CATTopRibNuplet* iNupletUsed);
  CATBoolean ReportUsedPrecomputedNupletList(int iListIndex);
  void CleanPrecomputedNupletLists(); 
  CATBoolean ContainsConfusedNuplet(CATTopRibNuplet* iPrevNuplet, CATTopRibNuplet* iNextNuplet);
protected:
   
  //End: SOU
  CATArrayOfNupletsLists _PrecomputedNupletLists;
  CATListOfInt _PrecomputedFirstIn;
  CATListOfInt _PrecomputedLastIn;

  protected:
    virtual CATBoolean FindMoreCandidates(CATTopRibSign        iDirection,
                                          CATTopRibPropagation iMode,
                                          int                  iNumNuplet,
                                          CATArrayOfNupletsLists * NupletsListsArrayPtr);

};

//-------------------------------------------------------------------------
// Propriete ruban cree lors de l'init Free
//-------------------------------------------------------------------------
INLINE void       CATTopRib::SetFreeRib()
{
  _IsFreeRib = TRUE;
}

INLINE CATBoolean CATTopRib::IsFreeRib()
{
  return _IsFreeRib;
}

#endif
