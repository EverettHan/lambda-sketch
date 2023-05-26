/* -*-C++-*- */

#ifndef CATTopRibNuplet_H
#define CATTopRibNuplet_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibNuplet
// Classe definissant les elements d'appui au niveau topologique pour  
// le calcul de ruban 
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
#include "ExportedByRIBLight.h"

#include "CATTopRibObject.h"
#include "CATTopRibDef.h"
#include "CATGeoFactory.h"
#include "CATMathDef.h"
#include "CATTopRibDbg.h"  // Pour PermanentDisplay
#include "CATTopRibTool.h" 
#include "CATTopRibMacroTool.h" 
#include "CATBody.h"       
#include "CATEdge.h"
#include "CATVertex.h"
#include "TopologicalOperatorsErrors.h" 
#include "TopologicalOperatorsInternalError.h"  

class CATCrvParam;
class CATXParam;
class CATCurve;
class CATEdgeCurve;
class CATPCurve;
class CATPointOnEdgeCurve;

class CATVertex;
class CATEdge;
class CATFace;
class CATLoop;
#include "CATCell.h"

class CATConnect;
class CATLoopExtension;
class CATComplFace;
class CATTopRibSupport;
class CATTopRibGeoNuplet;
class CATTopRibSupCand;
class CATTopRibNupletCand;
class CATSupContact;
class CATArrayOfPointOnSupport;
class CATPointOnSurface;
class CATPointOnEdgeCurve;
class CATSoftwareConfiguration;
class CATArrayOfNupletsLists;
class CATSewingCompl;

class CATCGMActivateDebug;
struct CATTopDbgAttribut;
class CATMathSetOfVectors;

class CATBothSidesDraftNuplet;
class CATNtrlDrftRibNuplet;
class CATReflectDrftRibNuplet;
class CATBlendNuplet;
class CATRlmNuplet;
class CATRlmRib;

#include "ListPOfCATCell.h"
#include "ListPOfCATTopRibNuplets.h"
#include "ListPOfCATPointOnNuplet.h"
#include "ListPOfCATTopRibGeoNuplet.h"
#include "CATListOfCATGeometries.h"
#include "CATListPV.h"
#include "CATMathInline.h"

#include "CATSafe.h"
CATSafeDefine(CATTopRibNuplet);

#include "GeometricUtilities.h"

#define CATTopRibNupletSizeBySupport 10      // nombre de void* que la classe fille doit allouer par support

class ExportedByRIBLight CATTopRibNuplet : public CATTopRibObject
{
  //------------------------------------------------------------------------------
  // Constructor
  // iMemory doit etre alloue par la classe derivee et doit etre de taille 8*iSuppNumber*sizeof(void*) 
  //------------------------------------------------------------------------------
  protected:
  CATTopRibNuplet(const int iSuppCount, void** iAllocatedMemory); 

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public :
  virtual ~CATTopRibNuplet();

  //------------------------------------------------------------------------------
  // Clean Method after dummy creation operation
  //------------------------------------------------------------------------------
  virtual void CleanAfterCreateFaces(int iSupp1, int iSupp2);

  //------------------------------------------------------------------------------
  // default constructor. Not implemented
  //------------------------------------------------------------------------------
  private :
  CATTopRibNuplet();

  //------------------------------------------------------------------------------
  // Copy constructor. Not implemented
  //------------------------------------------------------------------------------
  private :
  CATTopRibNuplet(CATTopRibNuplet &iOperator);

  //------------------------------------------------------------------------------
  // Affectation operator. Not implemented
  //------------------------------------------------------------------------------
  private :
  CATTopRibNuplet& operator=(const CATTopRibNuplet &iOperator);

  //------------------------------------------------------------------------------
  // Writing-Reading methods
  //------------------------------------------------------------------------------
  public :
  INLINE  int                 GetDimension    () const;
  virtual void                SetSupport      (const int iNumSupp, const CATTopRibSupport & iNewSupp); // Modified By : SUH : 2004:6:14
          void                SetTool         (CATTopRibTool      * const iTool);
  virtual void                SetGeoNuplet    (CATTopRibGeoNuplet * const iGeoNuplet);
  virtual void                UnsetGeoNuplet  ();

  INLINE  CATTopRibSupport   *GetSupp         (const int iNumSupp) const;
          CATDomain          *GetSupportDomain(const int iSupport) const;          
          CATBody            *GetSupportBody  (const int iSupport) const;          
  INLINE  CATTopRibTool      *GetTool         () const;
  INLINE  CATTopRibMacroTool *GetMacroTool    () const;
  INLINE  CATGeoFactory      *GetFactory      () const;
  INLINE  CATBody            *GetCreationBody () const;
  INLINE  CATTopRibGeoNuplet *GetGeoNuplet    () const; // Safe method
  INLINE  CATTopRibGeoNuplet *ReadGeoNuplet   () const; // May return NULL

  private:
  int                         GetSuppIndex    (const CATTopRibSupport *iSupp) const;
  //------------------------------------------------------------------------------
  // Tracks
  //------------------------------------------------------------------------------
  public:
  CATCell*                    GetTrack       (CATTopRibSupport *iSupport, CATTopRibSign *oOrientation = NULL);
  CATCell*                    GetTrack       (const int         iNumSupp, CATTopRibSign *oOrientation = NULL) const;

  // Remplace la trace courante par la trace specifiee. Nettoie les vertex coupants et les candidats.
  CATCell*                    SwapTrack      (const int         iNumSupp,
                                              CATCell         * iNewTrack,
                                              CATCell         * iOldTrack=NULL,
                                              const CATBoolean  iUpdateGeoTrack=FALSE); // Set also GeoTrack on Geo Nuplet
  void                        TrimTracks     (const CATTopRibSign   iDirection, 
                                              ListPOfCATTopRibNuplets *iPreviousNupletsWhoCanShareSameGeometry = NULL);
  void                        DestroyTracks  (const CATBoolean iKeepInitVertices=FALSE);
  // Indique si les traces doivent etre maintenues communes sur l ensemble des supports
  virtual CATBoolean          IsSingleTrack  () const ;
  CATBoolean                  AreAllTracksVertices () const ;

  public:
  // Remplace la trace courante par la trace specifiee.
  void                        AddTrack       (CATCell          *iTrackCell,
                                              const int         iNumSupp,
                                              const CATBoolean  iUpdateGeoTrack=FALSE); // Set also GeoTrack on GeoNuplet

  void SetVertexIsOnExactInterpol(const CATBoolean iValue=TRUE, const CATTopRibSign iDirection=BothDirections);
  CATBoolean GetVertexIsOnExactInterpol(const CATTopRibSign iDirection);
  
  protected: //Modified by REN 2005:04:05    This function is used by overloaded function CATParallelNuplet::CreateRawTracks.
  // Create the raw tracks and store them in the Nuplet
  virtual CATBoolean CreateRawTracks (CATTopRibSign iDirection, CATBoolean iCheckWithTgt = FALSE);

  protected:
  // Create the raw track for a given support and store it in the Nuplet
  virtual CATCell * CreateRawTrack(CATLONG32 iNumSupp);

  //------------------------------------------------------------------------------
  // Link Cell
  //------------------------------------------------------------------------------
  public:
  void                        SetLinkCell    (CATTopRibSign  iDirection, CATCell *iLinkCell, int  ipos);
  INLINE CATCell*             GetLinkCell    (CATTopRibSign  iDirection, int ipos);

  CATCell* GetContactLinkCell(CATTopRibSign iDirection, int ipos, CATTopRibPropagation iPropagMode);

  //------------------------------------------------------------------------------
  // End Vertices 
  //------------------------------------------------------------------------------
  public:
  CATVertex*                  GetEndVertex   (const CATTopRibSign iDirection, const int iNumSupp, CATBoolean* oIsPartOfTrack=NULL);

  virtual void                SwapEndVertex  (CATVertex* iNewEndVertex, const int  iNumSupp, const CATTopRibSign iDirection);

  void                        UpdateEndVertex(CATVertex * iOldVertex, CATVertex * iNewVertex);

  void                        NotifyCellChange(CATCell* iNewCell, CATCell *iOldCell);

  // returns Poec defined by actual EndVertex (for TrackDmension=1 Nuplet only)
  CATPointOnEdgeCurve*        GetEndPointOnEdgeCurve(const CATTopRibSign iDirection, const int  iNumSupp);

  // Adds Poec into MacroPoint under actual EndVertex if necesssary and if #NULL (for TrackDmension=1 Nuplet only)
  void                        AddEndPointOnEdgeCurve(const CATTopRibSign  iDirection, const int iNumSupp, CATPointOnEdgeCurve* iPoec);

  private:
  void                        AddEndVertex   (const CATTopRibSign  iDirection, CATVertex *iVertex, const int iNumSupp);

  //------------------------------------------------------------------------------
  // Check if the type of an N-uplet solution is as expected
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsSolOk (CATTopRibNuplet    & iNupletRef,
                      CATBoolean           iCheckSupports=FALSE,
                      CATTopRibPropagation iMode=PropagStandard,
                      CATListOfInt *iSupportsForcedToPropagCoarse = NULL);


  //------------------------------------------------------------------------------
  // Debug methods
  //------------------------------------------------------------------------------
  public:
  virtual void Dump( CATCGMOutput& ioOS );

  void DumpLine( CATCGMOutput& ioOS, int iLine);
  int GetNbDumpLine();

  virtual void Check();

  //------------------------------------------------------------------------------
  // Update the GeoNuplet's track for a given support if it is a point
  // (to be called after MergeVertices or if an init/exit vertex has replaced
  // the MacroPoint that was initially computed by the geometric operator)
  //------------------------------------------------------------------------------
  public:
  void UpdateGeoNupletOnEndVertex(CATLONG32 iSupportIndex);

  //------------------------------------------------------------------------------
  // Transition management
  // SetTransition: sets the status of this Nuplet.
  // A transition Nuplet should not be exported but should rather deform it adjacent nuplets
  //------------------------------------------------------------------------------
  public:
  void                        SetTransition(const CATBoolean iIsTransition = TRUE) ;
  INLINE CATBoolean           IsTransition() const ;

  //------------------------------------------------------------------------------
  // Orientation management
  //------------------------------------------------------------------------------
  public:
  INLINE CATTopRibSign        GetOrientation ();
  INLINE void                 SetOrientation (CATTopRibSign iOrientation);

  protected:
  virtual CATOrientation      ComputeConventionalOrientation(); // Default implementation for Intersection and Fillet

  //------------------------------------------------------------------------------
  // Misc.
  //------------------------------------------------------------------------------

  public:
  virtual void                ClearOutputs   ();
  void                        ClearContact(const CATTopRibSign iDirection, const int iNumSupp);

  virtual CATBoolean          IsSolLocked    ();
  virtual CATBoolean          IsSolLocked(CATLONG32 iNumSupp);
  virtual void                LockSol        ();

  CATTopRib*                  GetRlmRibOwner ();
  private:
  virtual CATRlmRib*          GetOwnerRib    ();
  public:

  //------------------------------------------------------------------------------
  // Duplicate an N-uplet's contents
  //------------------------------------------------------------------------------
  virtual void DuplicateContents (CATTopRibNuplet *iNuplet);

  //------------------------------------------------------------------------------
  // Duplicate data generated by a N-uplet
  //------------------------------------------------------------------------------
  virtual void DuplicateOutputs(CATTopRibNuplet *iNuplet);
  //------------------------------------------------------------------------------
  // Duplicate data generated by a N-uplet on a given support 
  // iSrcSupp specifies the support index in source nuplet
  // iDstSupp specifies the support index in 'this'
  //------------------------------------------------------------------------------
  virtual void DuplicateOutputsOnSupport(CATTopRibNuplet *iSrcNuplet, int iSrcSupp, int iDstSupp);

  //------------------------------------------------------------------------------
  // Find out whether a rolling support is to be maintained for the
  // next Nuplet: the default answer is NO
  // Rem : TRUE signifie qu'on veut toujours rester sur le support de meme
  //       dimension
  //       FASLE signifie qu'on peut eventuellement changer de dimension de
  //       support
  //------------------------------------------------------------------------------
  virtual CATBoolean IsStillRolling (CATTopRibSign      iDirection,
                                     CATTopRibSupport * iSupport);

  //------------------------------------------------------------------------------
  // Read/Analyze contact on the track of a given support in a given direction
  //------------------------------------------------------------------------------
  CATVertex* GetSupportContact(CATTopRibSign iDirection, const int iNumSupp, CATCell* &TrackOnSupport);

  virtual CATCell   *SupportBrdrContact (CATTopRibSign       iDirection,
					                               CATTopRibSupport   *iSupport,
					                               CATVertex          *iContactVertex,
                                         CATCell           **oSUpportOfBrdr=NULL,
                                         int iNumSup = 0);

  CATTopRibNupletCand * GetNupletCand(CATTopRibSign iDirection);
  CATTopRibSupCand    * GetSupCand   (CATTopRibSign iDirection,
                                      CATLONG32          iNumSup);
  CATTopRibSupCand    * HasSupCand   (CATTopRibSign iDirection,
                                      CATLONG32          iNumSup);

  void               GetSupContact       (CATTopRibSign        iDirection,
					                                CATTopRibPropagation iMode,  
					                                CATLONG32                 iNumsup,
					                                CATSupContact       *iNextSup);

  virtual CATBoolean         HasNewCandidates     (CATTopRibSign        iDirection,
                                          CATLONG32                 iNumsup=0); 
  //------------------------------------------------------------------------------
  // Read/Write the contact type for a given support at a given end of
  // the N-uplet's track. To be used carefully. 
  //------------------------------------------------------------------------------

  CATTopRibContact ReadContactType (CATTopRibSign    iDirection,                       
                                    int              iPos);

  void SetContactType (CATTopRibSign    iDirection,
                       CATTopRibContact iContactType,
                       int              iPos);


  //------------------------------------------------------------------------------
  // Get the init/exit data.
  // Return FALSE if no solution exists
  //------------------------------------------------------------------------------
  virtual CATBoolean ComputeInitAndExitData (CATTopRibSign   iDirection);                                  
 
  //------------------------------------------------------------------------------
  // Set the start or end vertices if necessary
  //------------------------------------------------------------------------------
  void SetInitOrExitVertices (CATTopRibSign   iDirection   ,
                              CATSupContact  *iContact     );

  //------------------------------------------------------------------------------
  // Compute the lists of N-uplets obtained for the current supports
  // The lists are stored in an array object (if the array is not empty
  // the lists are appended)
  //------------------------------------------------------------------------------
  public:
  virtual void ComputeNuplets   (CATTopRibSign           iDirection,
                                 CATArrayOfNupletsLists &ioNupletsListsArray,
                                 CATBoolean *SplitWithMoreThanOneFace=NULL); //D1A
  //private:
  //CATBoolean _SplitWithMoreThanOneFace;

  public :
  void SetSplitWithMoreThanOneFace (CATBoolean *iSplit);
  CATBoolean GetSplitWithMoreThanOneFace (int iSupp);
  //------------------------------------------------------------------------------
  // Merge les vertex et les listes de nuplets decoupes pour discontinuites C1
  // - Chapeau qui simplifie le probleme en degageant les listes inutiles
  //------------------------------------------------------------------------------
  void MergeC1CutNuplets(int                     iNbOldList,
                         CATArrayOfNupletsLists &ioNupletsListsArray,
                         CATTopRibSign           iDirection);
  
  //------------------------------------------------------------------------------
  // CheckMissingInitExits
  //------------------------------------------------------------------------------

  void CheckMissingInitExits(CATTopRibSign  iDirection,
                             CATBoolean    &oInitIsMissing, 
                             CATBoolean    &oExitIsMissing);

  //------------------------------------------------------------------------------
  // If the inits or exits weren't used or could not be provided, try to set
  // them on the computed geometry
  //------------------------------------------------------------------------------

  void SetInitAndExitOnGeometry (CATTopRibSign             iDirection);

  //------------------------------------------------------------------------------
  // Get the start or end vertex (depending on iDirection) in the current
  // Nuplet on a given support. If said vertex is "untouchable" then
  // replace it with a new cutting vertex (the old one is returned in
  // oOldVertex)
  //------------------------------------------------------------------------------
  CATVertex *GetVertexInNuplet(CATTopRibSign   iDirection,
                               CATLONG32            iSupportIndex,
                               CATVertex     **oOldVertex = NULL);

  //------------------------------------------------------------------------------
  // Create the list of Nuplets based on the synchronized split
  // of the raw tracks
  //
  // Please note: this method needs the geometry and topology to be set;
  //              however, it does unset them before exiting, since the
  //              new N-uplets will use the old _GeoNuplet and since the
  //              old tracks are no longer valid (in most cases, it's
  //              tracks will have been destroyed)
  //------------------------------------------------------------------------------
  protected:
  virtual void CutAndSynchronize (CATTopRibSign            iDirection,
                                  ListPOfCATTopRibNuplets &oNewNuplet,
                                  CATBoolean      *SplitWithMoreThanOneFace=NULL);

  //------------------------------------------------------------------------------
  // This method cuts the synchronised tracks again with all supports in order
  // to detect possible confusions
  //
  // Please note: This has not yet been implemented for general N-uplets since
  //              they do not really split the tracks when synchronising.
  //              Therefore only intersection N-uplets benefit from this since
  //              their tracks are split on all supports at all synchronised
  //              points.
  //------------------------------------------------------------------------------
  void CutAgainWithSupports(ListPOfCATCell  *ioTrackCell,
                            CATTopRibSol   **ioInOutInfo,
                            ListPOfCATCell  *SuppCellsForInOutInfo,
                            int              iCutAgainSupportIndex = 0);

  //------------------------------------------------------------------------------
  // Cut (and synchronize) the tracks again with the N-uplet's supports in order
  // to detect confusions that have not been detected earlier on (because they
  // are due to the creation of new vertices along the tracks)
  //
  // Please note: The method must not disconnect any track, but keep the same
  //              track and possibly detect it as being confused with a border
  //              of the support cell
  //------------------------------------------------------------------------------
  public:
  void CutAgain(CATFace       *iCutFace,
                CATEdge       *iCutEdge,
                CATEdge      **ioNewEdge,
                int           &ioNbEdges,
                CATLocation  **ioLocations     = NULL,
                CATBoolean     iCheckFace      = FALSE,
                CATBoolean     iCheckLocation  = FALSE,
                CATBoolean     iCheckEdge      = TRUE,
                CATBoolean     iOnlyEdgeInFace = TRUE);

  //------------------------------------------------------------------------------
  // This method indicates whether it's possible to cut the synchronised tracks
  // again with all supports in order to detect possible confusions
  //------------------------------------------------------------------------------
  private:
  virtual CATBoolean DoCutAgain();

  //------------------------------------------------------------------------------
  // Create a list of clone N-uplets which are inverted comperard to the
  // originial ones
  //------------------------------------------------------------------------------
  protected:
  void CreateInvertedCloneNuplets(ListPOfCATTopRibNuplets &iNuplets, 
                                  ListPOfCATTopRibNuplets &oNewNuplets);

  // -----------------------------------------------------------------------------     
  // Cut the resulting edges with cutting edges and update inside/outside 
  // information. 
  // -----------------------------------------------------------------------------
  public:
  void CutWithCuttingEdges                (CATTopRibSign      iDirextion,
                                           CATFace         *  iSupportFace,
                                           ListPOfCATCell  &  ioTrackEdge,
                                           CATTopRibSol   *&  ioInOutInfo,
                                           ListPOfCATCell   * oSuppCellsForInOutInfo);

  private :
  //------------------------------------------------------------------------------
  // Update the In/Out information of a track
  //------------------------------------------------------------------------------
  void UpdateInOutInfoOfTrack (CATTopRibSol   iOldInOutInfo,
                               CATLocation    iLocation,
                               CATSide        iSideToKeep,
                               CATBoolean     iFullSideAccepted,
                               CATTopRibSign  iDirection,
                               CATFace       *iSupportFace,
                               CATEdge       *iTrackEdge,
                               CATEdge       *iCuttingEdge,
                               CATTopRibSol  &oInOutInfo);

  public :

  // test si le nuplet s'auto intersecte
  CATBoolean IsAutoIntersecting(int iSupp);

  //------------------------------------------------------------------------------
  // Create a list of CATPointOnNuplet objects defined by a list of track cells
  // on a given support
  //------------------------------------------------------------------------------
  virtual void CreatePointsOnNuplet       (CATTopRibSupport         *iSupport,
					   ListPOfCATCell           &iTrackCell,
					   ListPOfCATPointOnNuplet  &ioPointOnNuplet,
                                           CATArrayOfPointOnSupport &ioPointOnSupportArray,
					   CATLONG32                     &ioFirstPN,
					   CATLONG32                     &ioLastPN);

  //------------------------------------------------------------------------------
  // Cut a track edge with a support face's boundary and create edges with
  // inside/outside information
  //------------------------------------------------------------------------------
  virtual void CutEdgeWithFace           (CATEdge                  *iRawTrackEdge,
                                          CATCurve                 *iTrackCurve,
                                          CATFace                  *iSupportFace,
                                          ListPOfCATCell           &oTrackEdge,
                                          CATTopRibSol            *&oInOutInfo,
                                          CATLoop                  *iBadLoop=NULL,
                                          ListPOfCATCell * oSuppCellsForInOutInfo=NULL,
                                          CATBoolean      *SplitWithMoreThanOneFace=NULL);

  //------------------------------------------------------------------------------
  // Cut track edge with border edges of support face
  //------------------------------------------------------------------------------
  private:
  void CutEdgeWithFaceBorder(CATFace                *iSupportFace,
                             CATEdge                *iRawTrackEdge,
                             int                     &NbNewEdges,
                             CATLocation            **EdgeLocation,
                             CATEdge               **&NewEdge);

  //------------------------------------------------------------------------------
  // Cut a track Vertex with a support face's boundary 
  //------------------------------------------------------------------------------
  public:
  virtual void GetVertexLocationInFace   (CATVertex       *iRawVertex,
					                                CATFace         *iSupportFace,
					                                ListPOfCATCell  &oNewVertex,
					                                CATTopRibSol   *&InOutInfo);

  //------------------------------------------------------------------------------
  // Cut a track Vertex with a support edge
  //------------------------------------------------------------------------------
  virtual void GetVertexLocationInEdge     (CATVertex       *iRawVertex,
					                                  CATEdge         *iSupportEdge,
					                                  ListPOfCATCell  &oNewVertex,
					                                  CATTopRibSol   *&InOutInfo);

  //------------------------------------------------------------------------------
  // Cut a track edge with a support edge and create edges with
  // inside/outside information
  //------------------------------------------------------------------------------
  virtual void CutEdgeWithEdge           (CATEdge                  *iRawTrackEdge,
                                          CATEdge                  *iSupportEdge,
                                          CATTopRibSign             iDirection,
                                          CATTopRibSupport         *iSupport,
                                          ListPOfCATCell           &oTrackCell,
                                          CATTopRibSol            *&oInOutInfo);
  
   //------------------------------------------------------------------------------
   // Check if a track must be cut 
   //------------------------------------------------------------------------------
   CATVertex * IsTrackToSplit(CATTopRibSign iDirection,
                              CATLONG32          iNumSupp);

  //------------------------------------------------------------------------------
  // Cut the topological track of one given support
  // Returns a non null vertex if the track has been modified.
  // ioWorkWireToDel est un wire vide qui va servir a "proteger" les edges resultantes
  // de la disconnection le cas echeant. 
  // Il doit etre NULL en entree, et devra etre detruit dans l'appelant 
  // APRES UTILISATION DES EDGES RESULTANTES s'il est non nul en sortie
  //------------------------------------------------------------------------------
  virtual CATVertex * SplitTrackOnSupport(CATTopRibSign    iDirection,
                                          CATLONG32        iNumSupp,
                                          CATCell       *& oCellToKeep,
                                          CATCell       *& oCellToDelete,
                                          CATWire       *& ioWorkWireToDel,
                                          CATVertex     *  iCuttingVertex=NULL,
                                          CATLocation   *  oKeepLoc=NULL,
                                          CATLocation   *  oDeleteLoc=NULL);

  //------------------------------------------------------------------------------
  // Instancie le vertex fin d'une trace comme coupant dans une cellule si non deja 
  // fait. Ne gere que les supports faces pour l'instant.
  //------------------------------------------------------------------------------
  virtual void SetCutting(CATTopRibSign   iDirection,
			  CATLONG32            iNumSupp,
			  CATCell       * iCutCell);

  //------------------------------------------------------------------------------
  // Renvoie 1 si un vertex extremite d'une trace est un zero franc, 0 si c'est 
  // une extremite d'une zone de confusion.
  //------------------------------------------------------------------------------
  CATBoolean GetCuttingStatus(CATTopRibSign   iDirection,
                              CATLONG32            iNumSupp);

  //------------------------------------------------------------------------------
  // Synchronize all cuts on all topological tracks by creating a vertex on
  // each track for each cut point
  //------------------------------------------------------------------------------
  virtual void SynchronizeCutsOnAllTracks  (ListPOfCATCell           *iTrackCell,
                                            CATTopRibSol            **iInOutInfo,
                                            ListPOfCATCell           *SuppCellsForInOutInfo,
                                            ListPOfCATPointOnNuplet  &ioPointOnNuplet);

  //------------------------------------------------------------------------------
  // Merge all identical points on N-uplet
  //
  // Please note: The first and last points are obviously the same on all
  //              supports and thus are merged automatically, all others are
  //              merged if their parameters are very close, or if their
  //              respective vertices are lying on the same vertex
  //------------------------------------------------------------------------------
  virtual void MergeAllIdenticalPointsOnNuplet(ListPOfCATPointOnNuplet &ioPointOnNuplet);

  //------------------------------------------------------------------------------
  // Create a list of resulting N-uplets
  //------------------------------------------------------------------------------
  virtual void CreateResultingNuplets (CATTopRibSign             iDirection,
                                       ListPOfCATCell           *iTrackCell,
                                       CATTopRibSol            **iInOutInfo,
                                       ListPOfCATCell           *SuppCellsForInOutInfo,
                                       ListPOfCATPointOnNuplet  &iPointOnNuplet,
                                       ListPOfCATTopRibNuplets  &oNewNuplet);

  //------------------------------------------------------------------------------
  // 1) Check that there are either exactly the same number of tracks
  //    on each support, or just one vertex track on some supports
  // 2) Return the number of tracks
  //------------------------------------------------------------------------------
  virtual CATLONG32 CheckSynchronization (ListPOfCATCell *iTrackCell);

  //------------------------------------------------------------------------------
  // Split the track edge and update the list of CATPointOnNuplet elements
  //
  // Please note: 1) iSupportIndex varies between 1 and _NbSupp and indicates
  //                 the support of iEdgeToCut
  //              2) iPointIndex indicates the current point in the list of
  //                 CATPointOnNuplet elements
  //------------------------------------------------------------------------------
  void SplitTrackAndUpdatePointsOnNuplet (CATEdge                  *iEdgeToCut,
                                          CATCrvParam              &iCutParamOnTrack,
                                          ListPOfCATPointOnNuplet  &ioPointOnNuplet,
                                          CATLONG32                      iPointIndex,
                                          CATLONG32                      iSupportIndex,
                                          CATEdge                 *&oLeftEdge,
                                          CATEdge                 *&oRightEdge);

  //------------------------------------------------------------------------------
  // Pseudo-split the track edge in two at a given parameter on the EdgeCurve
  //
  // Please note: For CATTopRibNuplet, the track edge is not really split,
  //              but instead a vertex is simply created on the edge at the
  //              position defined by iCutParamOnEdgeCurveToCut.
  //              However, a derived class may implement an actual split
  //              of the edge in two new edges (oLeftEdge and oRightEdge).
  //------------------------------------------------------------------------------
  virtual void SplitTrackEdge (CATEdge              *iEdgeToCut,
                               CATCrvParam          &iCutParamOnEdgeCurveToCut,
                               CATVertex           *&oNewVertex,
                               CATEdge             *&oLeftEdge,
                               CATEdge             *&oRightEdge,
                               CATPointOnEdgeCurve  *iPointOnEdgeCurveToCut);

  //------------------------------------------------------------------------------
  // Get the global type of an N-uplet solution (inside or outside)
  //------------------------------------------------------------------------------
  virtual CATTopRibSol GetSolType (int iNbSupp=0, int * iNumSupp=NULL) const ;
  virtual CATTopRibSol GetGlobalSolType ();
  // optionnal argument oAndInOnAllRolling only significant for BlendNuplets - see CATBlendNuplet
  virtual int GetSupportInOrConfused(CATBoolean * oAndInOnAllRolling = NULL);
  
  //------------------------------------------------------------------------------
  // Get the type of an N-uplet solution (inside or outside) with respect to a
  // given support (iNumSupp >=1 && iNumSupp <= Number of Supports)
  //------------------------------------------------------------------------------
  CATTopRibSol GetSolTypeOnSupport (const CATLONG32 iNumSupp) const ;
  //------------------------------------------------------------------------------
  // Get the type of an N-uplet solution (upwards or downwards) with respect to a
  // given support (iNumSupp >=1 && iNumSupp <= Number of Supports) 
  // and a parting element (cf. UpdatePartingTypesOfNuplets on CATparting)
  //------------------------------------------------------------------------------

  CATTopRibSol GetTypeVsParting (const CATLONG32 iNumSupp) const;
  //------------------------------------------------------------------------------
  // SetTypeVersusParting
  //------------------------------------------------------------------------------
  void SetTypeVsParting (const CATTopRibSol iSolType, const CATLONG32 iNumSupp);

  //------------------------------------------------------------------------------
  // Set the type for each support of an N-uplet solution (inside or outside). 
  // Useful for confused track.  
  //------------------------------------------------------------------------------
  void SetSolType (CATTopRibNuplet * iNupletRef);

  //------------------------------------------------------------------------------
  // Set the type for each support of an N-uplet solution
  //------------------------------------------------------------------------------
  void SetSolType(const CATTopRibSol iSolType);

  //------------------------------------------------------------------------------
  // Set the type of an N-uplet solution with regards to a support
  //------------------------------------------------------------------------------
  void SetSolType(const CATTopRibSol iSolType, const CATLONG32 iNumSupp);

  CATBoolean AreAllRollingSupportsOut();
  CATBoolean IsNupletInOnAllOtherRollingSupports(int iSupp);
  int GetNbOutRollingSupports();

  //------------------------------------------------------------------------------
  // Check if the type of an N-uplet solution is as expected (In or Out), related to 
  // a given support.
  //------------------------------------------------------------------------------
  virtual CATBoolean IsSolOkOnSupport(const int iNumSupp, 
                                      const CATTopRibSol iTypRef, 
                                      const CATTopRibSol iTypToCheck) const ;

  //------------------------------------------------------------------------------
  // Get the precision of the tracks at the end (according to the direction) of 
  // a Nuplet
  //------------------------------------------------------------------------------
  virtual double GetErrorOnTracks(CATTopRibSign iDirection);

  //------------------------------------------------------------------------------
  // Get the precision of the tracks at one point 
  //------------------------------------------------------------------------------
  virtual double GetErrorOnTracks(CATLONG32          iNumSupp,
			          CATCrvParam & iParam);


  //------------------------------------------------------------------------------
  // Get the orientation of the N-uplet's track with respect to their underlying
  // geometry
  //------------------------------------------------------------------------------
  virtual CATOrientation GetCommonTrackOrientation ();

  //------------------------------------------------------------------------------
  // Get the End Param of a N-Uplet in a given direction 
  //------------------------------------------------------------------------------
  virtual void GetEndParam (CATTopRibSign  iDirection,
			                      CATCrvParam   &oEndParam ,
			                      int           *oNumRef=NULL);

  //------------------------------------------------------------------------------
  // Get the End Param of a N-Uplet in a given direction and for a given support 
  //------------------------------------------------------------------------------
  CATBoolean GetEndParam (CATTopRibSign  iDirection,
                          CATLONG32           iNumSupp,
                          CATCrvParam   &oEndParam,
                          CATCurve     **oBaseGeo=NULL,
                          CATListOfInt  *ForbiddenSupports=NULL);

  //-----------------------------------------------------------------------------------
  // Calcul du gap max induit par un trou entre un support et ses supports
  // candidats. 
  //
  // Le booleen de la valeur de retour vaut true si un gap a ete trouve, false
  // sinon
  //
  //-----------------------------------------------------------------------------------
  virtual CATBoolean GetGapMax(CATTopRibSign        iDirection,
                               CATLONG32                 iNumSupp,
			                         double             & oDeltaXYZ);

  // Modified By : AJD : 2004:4:14
  // G0Gap => Directional g0 gap so that G0Gap.Norm() is (oDeltaXYZ - oDeltaNorm)
  // G1Gap => Directional g1 gap so that G1Gap.Norm() is oDeltaNorm
  virtual CATBoolean GetGapMax(CATTopRibSign        iDirection,
                               CATLONG32                 iNumSupp,
                               int                  iEvalGap,  // 1 pt - 3 pt + normale  
                               double             & oDeltaXYZ,
                               double             & oDeltaNorm,
                               CATMathVector       *oG0Gap = 0,
                               CATMathVector       *oG1Gap = 0);

  virtual CATBoolean GetGapMax(CATTopRibSign        iDirection,
		                           double             & oDeltaXYZ);

  //------------------------------------------------------------------------------
  // Modified By : AJD : 2004:4:13
  // This method uses more accurate computation done in geometry software
  // returns...
  //  1 = gap found
  //  0 = gap not found
  // -1 = geometry computation not implementated
    
  //------------------------------------------------------------------------------
  virtual short GetGapMaxExact(CATTopRibSign iDirection,
				                       CATLONG32     iNumSupp,				      
				                       double       &oGap);

  //------------------------------------------------------------------------------
  // Test si le nuplet est degenere a la tol iTol.
  //------------------------------------------------------------------------------
  // Modified By : AJD : 2004:6:14
  // iNumSupp = 0 => Nuplet is chekced on all the supports
  // 1 <= iNumSupp <= TotalNbSupp => Nuplet is checked on only specified support
  //------------------------------------------------------------------------------
  CATBoolean IsDegenerate(double iTol, const CATLONG32 iNumSupp = 0);

  // -----------------------------------------------------------------------------
  // Dis si on a le droit de degenerer une trace (pour rendre un vertex au lieu d'une edge)
  // Par defaut, on ne peux pas
  // -----------------------------------------------------------------------------
  virtual CATBoolean DegeneratedTrackAllowed(int iNumSupp);

  // -----------------------------------------------------------------------------
  // Dis si la degenerescence d'une track a une influence sur la degenerecence du Nuplet
  // -----------------------------------------------------------------------------
  virtual CATBoolean DontCareAboutDegeneratedTrackOnSupport(int iNumSupp);

  // -----------------------------------------------------------------------------
  // Cree une trace geo meme si elle est degeneree (creation dun vertex au lieu d'une edge)
  // Attention : Peut donc modifier la trace geometrique, ainsi que sa dimension.
  // -----------------------------------------------------------------------------
  virtual CATBoolean CreateDegeneratedGeoTrack(int                  iNumSupp, 
                                               CATVertex *          iEndVertex,
                                               CATTopRibDimension & ioTrackDimension,
                                               CATGeometry *&       ioGeoTrack);
  
  //------------------------------------------------------------------------------
  // Calcul sur le support iNumSupp le point 3D de l'extremite d'une trace. 
  // L'extremite est fonction de iDirection. Suivant EvalCommand, on calcule
  // egalement la normale au fond d'appui. 
  // Si ce fond n'est pas un bipar, le boolean de retour est mis a false,
  //              MAIS LE POINT 3D EST CALCULE QUAND MEME ! 
  // 
  // Valeurs possibles pour EvalCommand:
  // 
  //       1      : Calcul de EndPoint 
  //       2 ou 3 : Calcul de EndVector (norme)
  //
  //------------------------------------------------------------------------------
  virtual CATBoolean EvalOnNuplet // Renvoie true si toutes les evaluations sont ok
  (CATTopRibSign  iDirection,  // Extremite voulue (debut si backward, fin si forward)
   CATLONG32           iNumSupp,    // Numero de support 
   int            iEvalCommand,// Comande d'evaluation 
   CATMathPoint  &oEndPoint,   // Point 3D
   CATMathVector &oEndNormal, // Normale normee - Calculee en fonction de EvalCommand  
   CATMathVector *oUTangent = NULL,
   CATMathVector *oVTangent = NULL);
  

  //------------------------------------------------------------------------------
  // Calcul sur le support iNumSupp le point 3D en un point de la trace 
  // geometrique. Suivant EvalCommand, on calcule egalment la normale au fond 
  // d'appui. 
  // Si ce fond n'est pas un bipar, le boolean de retour est mis a false,
  //              MAIS LE POINT 3D EST CALCULE QUAND MEME ! 
  //
  // Le parametre passe doit etre sur la trace du support concerne 
  // 
  // Valeurs possibles pour EvalCommand:
  // 
  //       1      : Calcul de EndPoint 
  //       2 ou 3 : Calcul de EndVector (norme)
  //
  //------------------------------------------------------------------------------
  virtual CATBoolean EvalOnNuplet   // Renvoie false uniquement si eval de normale ko 
  (CATLONG32           iNumSupp,         // Numero de support 
   CATCrvParam   &iParam,           // Parametre ou l'on doit evaluer 
   CATMathPoint  *oEndPoint=NULL,   // Point 3D
   CATMathVector *oEndNormal=NULL, // Normale normee - Calculee en fonction de EvalCommand  
   CATMathVector *oUTangent = NULL,
   CATMathVector *oVTangent = NULL,
   CATSurParam   *oSurParam = NULL);

  //------------------------------------------------------------------------------
  // Calcul de la tangente 3D
  //------------------------------------------------------------------------------
  virtual CATBoolean EvalTangentOnNuplet
    (CATTopRibSign  iDirection,  // Extremite voulue (debut si backward, fin si forward)
     CATLONG32           iNumSupp,    // Numero de support 
     CATMathVector &oTangent);  // Tangente 3D

  //------------------------------------------------------------------------------
  // Check if a parameter point on a given support is included in the
  // corresponding geometric track
  //
  // Please note: For now, the method can return a parameter and PCurve only if
  //              the track is an EdgeCurve and if the support is a Face
  //
  // Return the number of solutions - Ambiguous if more that one
  //------------------------------------------------------------------------------
  int IsPointIncludedOnTrack (CATGeoFactory *iGeoFactory,
                              CATXParam     &iPointParam,
                              CATLONG32           iSupportIndex,
                              double         iInclusionTol,
                              CATCrvParam   **oParamOnCurve    = NULL,
                              CATCurve      **oCurve           = NULL,
                              CATBoolean      iUseNupletLimits = FALSE);

  //------------------------------------------------------------------------------
  // Cas du fillet edge face : si le plusieurs contacts sur le support face ont 
  // ete trouves par IsPointIncludedOnTrack
  //------------------------------------------------------------------------------
  void SelectIncludedPointUsingReport(int iRefSupportIndex, int *iPointIsIncluded,
    CATCrvParam **iParamOnCurveTab, CATCrvParam *ioParamOnCurve, int &ioNbSol);

  //------------------------------------------------------------------------------
  // Check if a given parameter on a given curve lying on a given support
  // is inside the parameter limits (if any) of the GeoNuplet
  //
  // Please note:
  // 1) This method is obviously only to be called when the track
  //    solution is a Curve
  // 2) The method snaps the parameter to the limit point if necessary
  //    (i.e. the parameter is OUTSIDE the limits but nearer than the
  //    provided tolerance to a limit point)
  //------------------------------------------------------------------------------
  CATBoolean IsParamInsideLimitsOfSolCurve(CATCrvParam &iParamOnCurve,
                                           CATCurve    *iCurve,
                                           CATLONG32         iSupportIndex,
                                           double       iInclusionTol,
                                           CATBoolean   iSnapToLimits = TRUE);

  //------------------------------------------------------------------------------
  // Useful to solve multiple solutions found by IsPointIncludedOnTrack
  //------------------------------------------------------------------------------
  CATBoolean SolveUnknownParam (CATCrvParam *  iTabParam     ,
                                CATCurve    ** iTabCurves    ,
			                          int         *  iTabNSol      ,
			                          int            iNumRef       ,
			                          CATBoolean     iOnlyOneVertex);

  //------------------------------------------------------------------------------
  // Manage problem due to error on tracks and gaps between cells
  //------------------------------------------------------------------------------
  void ManageErrorOnInclusion(CATSupContact *  iContact      ,
                              CATCrvParam   *  iTabParam     ,
                              CATCurve      ** iTabCurves    ,
			                        int           *  iTabNSol      ,
			                        int              iNumRef       , 
			                        CATBoolean       iOnlyOneVertex,
			                        CATTopRibSign    iDirection    );
			      

  //------------------------------------------------------------------------------
  // Check whether a given set of contacts is included in the N-uplet's geometric
  // tracks and update it accordingly (i.e. create POECs and add them to vertices
  // contained in the contacts)
  //------------------------------------------------------------------------------
  // FDL debut le 27/3/2000 : Methode virtuelle 
  //CATBoolean IncludeContact (CATTopRibSign  iDirection,
  //                           CATLONG32           iInitExitIndex,
  //                           CATSupContact *iContact,
  //                           double         iInclusionTol);
  virtual CATBoolean IncludeContact (CATTopRibSign  iDirection,
                                     CATLONG32           iInitExitIndex,
                                     CATSupContact *iContact,
                                     double         iInclusionTol);
  // FDL fin le 27/3/2000

  //------------------------------------------------------------------------------
  // Check whether the end of a given nuplet is included in the N-uplet's geometric
  // tracks 
  //
  // Please note: if iDirToUpdateThis != UnknownDirection, then the method
  // attempts to change the end Vertices of the N-uplet's tracks. But before
  // doing so, it checks whether the resulting would not be a degenrate N-uplet.
  // If that were the case the method does not update the vertices and returns
  // *oDegenerateResult = TRUE (oDegenerateResult is an optional output argument
  // and should be used whenever iDirToUpdateThis is used)
  //------------------------------------------------------------------------------
  CATBoolean IncludeEndNuplet(CATTopRibSign       iDirection           ,
                              CATTopRibNuplet *   iOriginalNuplet      ,
			                        CATTopRibSign       iDirToUpdateThis =UnknownDirection,			      
			                        CATCrvParam     **  oParamOnCurve    =NULL,
			                        CATCurve        *** oCurves          =NULL,
			                        CATVertex       *** oVertices        =NULL,
                                                CATBoolean      *   oDegenerateResult=NULL,
                              CATBoolean          iUseNupletLimits =FALSE,
                              int                 iNumSupp         =-1);

  //------------------------------------------------------------------------------
  // Check whether the end of a given nuplet is included in the N-uplet's geometric
  // tracks and return the associated param on a given support 
  //------------------------------------------------------------------------------
  CATBoolean IncludeEndNuplet(CATTopRibSign     iDirection     ,
                              CATTopRibNuplet * iOriginalNuplet,
			      int               iNumSupp       ,
			      CATCrvParam     & oParmOnTrack   );

  //------------------------------------------------------------------------------
  // Update vertices to have the POEC on the geometry of this. Assume that the 
  // vertices are modifiable.
  //------------------------------------------------------------------------------
  CATBoolean UpdateVerticesOnNuplet(CATTopRibSign  iDirToUpdate,
                                    CATCrvParam *  iTabParam   ,
                                    CATCurve    ** iTabCurves  ,
                                    CATVertex   ** iVertices   );

  //------------------------------------------------------------------------------
  // Check if the N-uplet's tracks are either in total confusion with their
  // respective support (if the support is a face, the confusion has to be
  // with one of the support face's edges) or inside their support
  //
  // Please note: 1) if a list of cells is provided, it will be updated with the
  //                 "confused" support cells (if any),
  //                 i.e. if oConfusedSupportCell[i] is not NULL, it represents
  //                 the "confused" support cell on support number i.
  //                 if iSupportIndex >= 1 and <= NbSupports then the method is
  //                 only applied to the indicated support (however the output
  //                 list still contains as many elements as there are supports),
  //                 otherwise the method is applied to all supports
  //              2) If iTotalConfusion is TRUE then only "total" confusions
  //                 are detected, i.e. the track(s) must cover a border edge
  //                 completely
  //------------------------------------------------------------------------------
  CATBoolean IsInOrConfused (CATLONG32            iSupportIndex        = 0,
                             ListPOfCATCell *oConfusedSupportCell = NULL,
                             CATBoolean      iTotalConfusion      = FALSE);
  
  //------------------------------------------------------------------------------
  // Methode qui s'inspire de la precedente, en simplifiee : ici, on se contente
  // de dire si on est en confusion sur le support specifie et si c'est le cas
  // on rend la cell en confusion.
  //------------------------------------------------------------------------------
  CATBoolean IsConfused (CATLONG32      iSupportIndex,
                         CATCell **oConfusedSupportCell = NULL);

  //------------------------------------------------------------------------------
  // Verifie que les deux N-uplets fournis (qui sont censes etre connectes dans
  // le sens iFirstNuplet->iSecondNuplet, et etre orientes pareil que le N-uplet
  // courant) partagent des supports avec le N-uplet courant, de la maniere
  // suivante:
  //
  // Sur les N supports, N-2 sont identiques pour tous les N-uplets.
  //
  // Sur les 2 supports qui restent, un est identique entre le N-uplet courant
  // et iFirstNuplet uniquement, l'autre est identique entre le N-uplet courant
  // et iSecondNuplet uniquement
  //------------------------------------------------------------------------------
  CATBoolean CheckSupportCrossing(CATTopRibNuplet *iFirstNuplet,
                                  CATTopRibNuplet *iSecondNuplet);

  //------------------------------------------------------------------------------
  // Set all CONFUSION+? solution types to CONFUSION+iSolType
  //------------------------------------------------------------------------------
  void UpdateConfusionSolTypes (CATTopRibSol iSolType);

  //------------------------------------------------------------------------------
  // Report Cutting Cells on all adjacents Co-Cells
  //------------------------------------------------------------------------------
  virtual void ReportCutting(const int iSupportIndex = 0);

  //------------------------------------------------------------------------------
  // Switch the cutting status of an N-uplet's track on a given support:
  // - From the support cell to the complementary cell
  // - From the complementary cell to the old support cell
  //
  // Please note: 1) The method assumes that the supports have already been
  //                 switched, which is why in the case of a Backward switch
  //                 the ComplFace MUST be provided (et cette loop extension
  //                 doit avoir une ComplFace)
  //              2) The method works only with support FACES and track EDGES
  //                 (until further notice)
  //------------------------------------------------------------------------------
  void SwitchCuttingOnSupport (CATLONG32              iSupportIndex,
                               CATLoopExtension *iLoopExtension = NULL,
                               CATFace *iComplFace = NULL,
                               CATFace *iOldFace = NULL,
                               CATFace *iNewFace = NULL);

  //------------------------------------------------------------------------------
  // Unset the cutting status of the track on a specified support
  //
  // Please note: The method works only with support FACES and track EDGES
  //              (until further notice)
  //------------------------------------------------------------------------------
  void UnsetTrackCutting(int iSupportIndex);

  //------------------------------------------------------------------------------
  // Teste si le nuplet <<recouvre>> une edge donnee
  //
  // On verifie que
  // 1 - le nuplet couvre l'edge (sur la totalite de ses supports)
  // 2 - les traces Rolling du nuplet sont plus proches de l'edge que la
  //     distance donnee en entree (RollingDistMin modifiee)
  // NB: la distance entre les traces Guide et l'edge n'est pas modifiee,
  //     la methode ne tient pas compte des traces guide pour l'instant
  //     (par contre la methode derivee dans FilVarNuplet le fait)
  // La methode CheckEdgeMatching permet de filtrer les solutions geometriquement indesirables
  //------------------------------------------------------------------------------
  virtual CATBoolean EdgeMatching (CATEdge *iEdge,
                                   double  &ioRollingDistMin,
                                   double  &ioGuideDistMin);

  CATBoolean EdgeMatching (CATEdge *iEdge,
                                   double  &ioRollingDistMin,
                                   double  &ioGuideDistMin,
                                   CATBoolean iCheckForShiftedTracksActivated);

  virtual CATBoolean EdgeMatching (CATEdge     *iEdge,
                                   double      &ioRollingDistMin,
                                   double      &ioGuideDistMin,
                                   double      iTestRatio,
                                   CATMathBox &ioBufferizedEdgeBox,
                                   double     &oDistance ,
                                   CATBoolean  iCheckForShiftedTracksActivated = FALSE);

  virtual CATBoolean CheckEdgeMatching( CATEdge        * iEdge,
                                        CATMathPoint   & iPointOnEdge,
                                        const int        iNbRollingSupports, 
                                        CATMathPoint     iPointOnSupport[],
                                        CATSurParam      iSurParams[],
                                        CATMathDirection iNormalOnSupport[]);
  
  protected:
  virtual CATBoolean CheckEdgeMatchingForShiftedTracks( CATEdge        * iEdge,
                                                CATMathPoint   & iPointOnEdge,
                                                const int        iNbRollingSupports, 
                                                CATMathPoint     iPointOnSupport[],
                                                CATSurParam      iSurParams[],
                                                CATMathDirection iNormalOnSupport[]);

  //------------------------------------------------------------------------------
  // Teste si le nuplet <<recouvre>> topologiquement (sur un support identifie
  // par son index) une edge donnee
  //
  // On verifie que l'edge fait partie de la boucle de la face qui est couverte
  // par le nuplet
  // Methode non codee! (code a extraire de CATDrftRib::SearchDRLCoveredFaces)
  //------------------------------------------------------------------------------
  public:
 // virtual CATBoolean EdgeMatchingTopo (CATEdge *iEdge,
    virtual int EdgeMatchingTopo (CATEdge *iEdge,
                                       int      iSupportIndex,
                                       CATListPV *iLNuplets=NULL,int *iStart=NULL, int *iEnd=NULL,
                                       CATBoolean *iClosed=NULL,
                                       CATBoolean NonAdjacentInit=FALSE);

  //------------------------------------------------------------------------------
  // PositionVsSE
  // Positionnement dans le cas ou le vertex debut du nuplet est sur la Stopping edge
  //------------------------------------------------------------------------------

  CATBoolean PositionVsSE(CATTopRibSign iDirection,
                          CATFace     * iSupportFace, 
                          CATEdge     * iTrackEdge,
                          CATEdge     * iStoppingEdge,
                          CATSide       iSideToKeep,
                          CATTopRibSol &oSol);
  
  double MinimalDistanceBetweenEndVerticesAndPoint(const CATMathPoint &iPoint);
  
  protected :

  //CATLONG32                     _NbListsOfNuplet; // Attention, il existe aussi NbListsOfNuplet...
  //ListPOfCATTopRibNuplets *_ListsOfNuplet;

  //------------------------------------------------------------------------------
  // Add temporary data in N-uplet (to insure de-allocation even if error is
  // generated)
  //
  // Please note: if this method is called n times with the exact same input for
  //              the same N-uplet, it will take n calls to RemoveTemporaryData
  //              to actually remove the temporary data from the N-uplet
  //------------------------------------------------------------------------------
  //void AddTemporaryData (CATLONG32                     iNbListsOfNuplet, 
  //                       ListPOfCATTopRibNuplets *iListsOfNuplet);

  //------------------------------------------------------------------------------
  // Remove temporary data from N-uplet
  //------------------------------------------------------------------------------
  //void RemoveTemporaryData ();

  //------------------------------------------------------------------------------
  // Modified By : AJD : 2004:4:13
  // This method uses more accurate computation done in geometry software
  //------------------------------------------------------------------------------
  CATBoolean ComputeMaxGap( CATTopRibSign iDirection,
                            const CATMathSetOfLongs &iSupportIDs,
                            const CATMathSetOfVectors &iG0Gaps,
                            const CATMathSetOfVectors &iG1Gaps,
                            const CATMathSetOfVectors &iAnglesOfIncidence,
                            CATListOfDouble &oMaxGaps
				                    );

  

  //==============================================================================
  // Internal (private) utilities
  //==============================================================================
  private:
  //------------------------------------------------------------------------------
  // Compute solutions for a given Nuplet
  // NB: 1) ComputeSolOnNuplet fills in the _Orientation fields in the supports
  //     of the Nuplet. If the _Orientation fields are already initialized
  //     then ComputeSolOnNuplet computes its solutions accordingly
  //     2) The default ComputeSolOnNuplet doesn't do anything. The method has
  //     to be defined for each derived class
  //------------------------------------------------------------------------------
  virtual void ComputeSolOnNuplet (CATTopRibSign             iDirection,
                                   ListPOfCATTopRibNuplets *&oNuplet,
                                   CATLONG32                     &oInitUsedInFirstNuplet,
                                   CATLONG32                     &oExitUsedInFirstNuplet) = 0;

  //------------------------------------------------------------------------------
  // Cut a geometric track with its support's boundary and generate
  // topological tracks that are either inside or outside the boundary
  //
  // Please note: All cells in the Nuplet that are lying on the current
  //              Support, are set to NULL, they are either deleted and
  //              replaced by new elements after the split operation or
  //              else remain as they were, but in both cases they are
  //              contained in the TrackCell list and will be pointed by
  //              the new Nuplets created in the CutAndSynchronize method
  //------------------------------------------------------------------------------
  void CutTrackWithSupport        (CATTopRibSign             iDirection,
                                   CATLONG32                      iNumSupp,
                                   ListPOfCATCell           &oTrackCell,
                                   CATTopRibSol            *&oInOutInfo,
                                   ListPOfCATCell          *oSuppCellsForInOutInfo=NULL,
                                   CATBoolean      *SplitWithMoreThanOneFace=NULL);

  //------------------------------------------------------------------------------
  // Gestion du meilleur choix pour les cellules coupantes
  //------------------------------------------------------------------------------
  virtual void GetGoodAndBadCutCells(ListPOfCATCell &iCutCells,
                                     CATCell       *&oSuppBrdCell, 
                                     CATCell       *&oBadLinkCell);
  //------------------------------------------------------------------------------
  // Gestion du meilleur choix pour les cellules coupantes
  //------------------------------------------------------------------------------
  virtual void GetGoodAndBadCutCellsWithParting (ListPOfCATCell &iCutCells,
                                     CATCell       *&oSuppBrdCell, 
                                     CATCell       *&oBadLinkCell);

  //==============================================================================


  public :
  //==============================================================================
  // Methodes necessaires au debug
  //==============================================================================
  void ShowTrack (CATGeoFactory       *iGeoFactory=NULL, 
                  CATCGMActivateDebug *iBrkPntMngr=NULL, 
                  CATTopDbgAttribut   *iAttributes=NULL,
                  CATTopRib           *iRib = NULL);
  void ShowTrackWithTag (CATGeoFactory       *iGeoFactory=NULL, 
                  CATCGMActivateDebug *iBrkPntMngr=NULL, 
                  CATTopDbgAttribut   *iAttributes=NULL,
                  CATTopRib           *iRib = NULL);
  virtual int GetStandardDisplay() ;
  void CleanDebug(CATLISTP(CATGeometry)* iObjectsForDebug=NULL); // Detruits les objets internes si pointeur NULL.


  CATLISTP(CATGeometry) ObjectsForDebug;

  // --------------------------------------------------------------
  // Reference management on Cells - Must be used very carefully !!
  // --------------------------------------------------------------
  friend class CATTopRib;
  private:
  static void AddReference    (CATCell* iTrackCell) ;
  static void ReleaseReference(CATCell* iTrackCell, CATTopRibMacroTool* iMacroTool, const CATBoolean iDoNotDestroyTrackCell=FALSE) ;

  // --------------------------------------------------------------
  // Operations sur les edges compatibles avec le partage
  // --------------------------------------------------------------
  public:
  CATEdge**  SplitEdge(CATEdge *iCutEdge, CATPointOnEdgeCurve* iPoec, 
                       int &oNbEdges);
  CATEdge**  SplitEdge(CATEdge* iCutEdge, CATFace* iSplittingFace, 
                       int &oNbEdges, CATLocation** oLocations, 
                       int iWithConfusion = 0, int iConditionalEdgeIntersections = 0,
                       int iPreserveModifiableVertices = 0, CATLoop* iLoopNotToIntersect = NULL,
                       int iStabilizeConfusion = 0);
  CATEdge** SplitCuttingEdge(CATFace* iCutFace, CATEdge* iCutEdge, 
                             int &oNbEdges, CATLocation** oLocations,
                             int iPreserveModifiableVertices = 0,
                             CATBoolean iCutAgain = FALSE);

  CATEdge** SplitCuttingEdgeWithWorkingWire(CATWire * iWire,  
                                            int &oNbEdges);

  CATEdge** SplitEdgeWithFacesOnSurface(CATEdge* iCutEdge, CATFace *face, CATDomain* iDomain, 
                                        int &oNbEdges, CATLocation** oLocations, ListPOfCATCell * oSuppCellsForLocations,
                                        int iWithConfusion, int iConditionalEdgeIntersections,
                                        int iPreserveModifiableVertices, CATLoop* iLoopNotToIntersect,
                                        CATBoolean *oSuccessful=NULL);

  virtual int GetConditionalEdgeIntersectionState();

  void GetFacesOnSurface(int iNumSupp, CATDomain* iDomain, CATFace* iFace, CATLISTP(CATFace)& oFaces);

  void MergeEdges(CATEdge* iEdge1, CATEdge* iEdge2, int inversion = 0);

  //------------------------------------------------------------------------------
  // Simple posage de iCutEdge s'il s'avere qu'il est inutile de lancer SplitEdge
  //------------------------------------------------------------------------------
  CATBoolean FastSplitEdge(CATTopologicalOperator   &iTopOp,
                           CATEdge                  *iCutEdge,
                           CATFace                  *iSplittingFace, 
                           int                      &oNbEdges,
                           CATEdge                **&oNewEdge,
                           CATLocation             **oLocations);

  //------------------------------------------------------------------------------
  // Gestion d'eventuelles solutions mixtes trouvees
  // (appele apres CATTopologicalOperators::SplitEdge par exemple)
  //------------------------------------------------------------------------------
  CATBoolean ManageMixedSolutions(int          &ioNbEdges,
                                  CATEdge     **iNewEdge,
                                  CATLocation **iLocations);

  //------------------------------------------------------------------------------
  // Manage "flat" vertices
  // (to be called after CATTopologicalOperators::SplitEdge)
  // (iLocations indicates the location of each edge in iNewEdge
  // with respect to iSplittingFace)
  //------------------------------------------------------------------------------
  private:
  void ManageFlatSolutions(CATFace      *iSplittingFace,
                           int           iNbEdges,
                           CATEdge     **iNewEdge,
                           CATLocation **iLocations);

  //------------------------------------------------------------------------------
  // Get all the cells bordering iFace on which iVertex has been set as
  // a cutting element
  //
  // Please note: The method starts by removing any elements from oSuppCellsOnFace
  //------------------------------------------------------------------------------
  public:
  void GetAllLinkCellsOnBorder(CATVertex      *iVertex,
                               CATFace        *iFace,
                               ListPOfCATCell &oSuppCellsOnFace);

  //------------------------------------------------------------------------------
  // Set a vertex "flat" in a face if necessary
  // The method returns TRUE if the vertex was actually "flattened"
  //------------------------------------------------------------------------------
  private:
  CATBoolean FlattenVertexInFace(CATVertex      *iVertex,
                                 CATFace        *iFace,
                                 ListPOfCATCell *oSuppCellsOnFace = NULL,
                                 CATBoolean      iDoFlatten       = TRUE);

  //------------------------------------------------------------------------------
  // Add degenerate N-uplets if necessary (i.e. if one or more support
  // faces need to be "flattened")
  //------------------------------------------------------------------------------
  private:
  void InsertDegeneratesForFlatSolutions(CATTopRibSign           iDirection,
                                         CATArrayOfNupletsLists &ioNupletsListsArray);
  //------------------------------------------------------------------------------
  // Update Contacts of Nuplets for propagation
  //------------------------------------------------------------------------------
  private:
  void UpdateCuttingForPropagation(CATTopRibSign           iDirection,
                                   CATArrayOfNupletsLists &ioNupletsListsArray);

  //------------------------------------------------------------------------------
  // Split an N-uplet at a given parameter
  //
  // Please note: 1) The provided parameter is defined on the geometry stored
  //                 in the GeoNuplet
  //              2) The method modifies the Nuplet and creates the next
  //                 N-uplet (in the forward direction) that is bordered
  //                 by the newly created vertex at the parameter location
  //              3) oParamSituation is an optional output:
  //                 - if the N-uplet can be split:
  //                   oParamSituation == UnknownDirection
  //                 - if it can't be split because the split parameter is
  //                   located at the N-uplet's start:
  //                   oParamSituation == Backward
  //                 - if it can't be split because the split parameter is
  //                   located at the N-uplet's end:
  //                   oParamSituation == Forward
  //------------------------------------------------------------------------------
  public :
  void SplitAtParam (CATCrvParam      &iSplitParam,
                     CATLONG32              iSupportIndex,
                     CATTopRibNuplet *&oNextNuplet,
                     CATTopRibSign    *oParamSituation = NULL);

  //------------------------------------------------------------------------------
  // check if it's possible to split an N-uplet on a given support at a given
  // parameter location (the parameter is defined for a given support as well)
  //
  // Please note: 1) The provided parameter is defined on the geometry stored
  //                 in the GeoNuplet
  //              2) oParamSituation is an optional output:
  //                 - if the N-uplet can be split:
  //                   oParamSituation == UnknownDirection
  //                 - if it can't be split because the split parameter is
  //                   located at the N-uplet's start:
  //                   oParamSituation == Backward
  //                 - if it can't be split because the split parameter is
  //                   located at the N-uplet's end:
  //                   oParamSituation == Forward
  //              3) iParamSupportIndex is the index of the support on which
  //                 iSplitParam is defined; iCurrentSupportIndex is the index
  //                 of the support on which the split test is to be performed
  //              4) if the nuplet can't  be split and oParamSituation == UnknownDirection,
  //                 then the provided parameter is outside the nuplet 
  //              5) if the nuplet can't  be split and oParamSituation == BothDirections,
  //                 then the provided parameter is on a degenerate track edge
  //------------------------------------------------------------------------------

  public :
  CATBoolean CheckSplitAtParamOnSupport (CATCrvParam    &iSplitParam,
                                         CATLONG32            iParamSupportIndex,
                                         CATLONG32            iCurrentSupportIndex,
                                         CATTopRibSign  *oParamSituation = NULL,
                                         ListPOfCATCell *ioTrack         = NULL,
                                         ListPOfCATCell *ioNextTrack     = NULL,
                                         CATCrvParam    *ioSplitParam    = NULL);

  //------------------------------------------------------------------------------
  // Replace the current GeoNuplet with a new one (with equivalent parameters!)
  // and update the N-uplet's tracks
  //------------------------------------------------------------------------------
  public :
  void SwitchToNewGeoNuplet ( CATTopRibGeoNuplet    *iNewGeoNuplet, 
                              CATLISTP(CATGeometry) *iOriginals             = NULL,   // Keep track of copying
                              CATLISTP(CATGeometry) *iCopies                = NULL,   // in order to manage geometry sharing
                              CATLISTP(CATGeometry) *iTopOriginals          = NULL,
                              CATLISTP(CATGeometry)* iSecondaryOriginals    = NULL,   
                              CATLISTP(CATGeometry)* iSecondaryCopies       = NULL,
                              CATLISTP(CATGeometry)* iSecondaryTopOriginals = NULL,
                              CATBoolean             iDontSwitchData = FALSE);        // DontSwitchData==TRUE means
                                                                                      // that the geometry is NOT
                                                                                      // and only the iOriginals and
                                                                                      // iCopies lists are generated
  // --------------------------------------------------------------
  // ExtraNuplet:
  // --------------------------------------------------------------
  // Methodes servant a archiver des solutions out, pouvant resservir 
  // si on a besoin d extrapoler ce Nuplet.
  // _ExtraNuplet[0]: Backward.
  // _ExtraNuplet[1]: Forward.
  // Chainage recursif jusqu a NULL.
  // --------------------------------------------------------------
  public :
  CATTopRibNuplet* NextExtraNuplet(const CATTopRibSign iDirection) const ;
  void SetExtraNuplet(const CATTopRibSign iDirection, CATTopRibNuplet* iExtraNuplet) ;
  CATTopRibNuplet* ExtractExtraNuplet(const CATTopRibSign iDirection) ;
  void RemoveExtraNuplets() ;
  private :
  void DisplayAsExtra();

  //------------------------------------------------------------------------------
  // Set/Get CloneNuplet
  //------------------------------------------------------------------------------
  public :
  void              SetCloneNuplet(CATTopRibNuplet * iNuplet);
  INLINE CATTopRibNuplet * GetCloneNuplet();

  //------------------------------------------------------------------------------
  // A usage des methodes qui doivent connaitre la version
  //------------------------------------------------------------------------------
  public :
  INLINE CATSoftwareConfiguration* GetSoftwareConfiguration() const;


  // -----------------------------------------------------------------------------
  // Accede / lit les donnees indiquant si le nuplet a ete complete (
  // -----------------------------------------------------------------------------
  void SetAlreadyCompleted(CATBoolean iAlreadyCompleted);
  CATBoolean HasAlreadyBeenCompleted();

  // -----------------------------------------------------------------------------
  // memorise le ruban de completion
  // -----------------------------------------------------------------------------

  void SetCompletionRibbon(int iDirection, CATTopRib *iCompletionRibbon);
  void DeleteCompletionRibbon(int iDirection);

  // -----------------------------------------------------------------------------
  // Le nuplet est-il potentiellement en overlap avec une autre partie 
  // du ruban ?
  // -----------------------------------------------------------------------------
  void SetSigmaNuplet(int iDirection);
  CATBoolean IsSigmaNuplet(int iDirection);

  // --------------------------------------------------------------
  // Donnees definissant un nuplet 
  // -----------------------------
  private :
  CATTopRibSupport       **  _Supp;         // Supports
  int                        _NbSupp;       // Nombre de supports a mettre en virtuelle pure 
  CATFace                *   _ComplFaceForConversion[2]; // Stockage de la compl face sur laquelle se trouve le nuplet initialement
  CATTopRibSol               _ComplType[2]; // stockage du type de la solution sur cette ComplFace
  CATTopRibTool           *  _Tool;         // Outil servant a calculer un morceau de ruban 
  CATBoolean _AlreadyCompleted;
  CATTopRib *_CompletionRibbon[2];


  // Donnees modelisant la Transition
  //---------------------------------
  private:
  CATBoolean                 _IsTransition;

  // Solution geometrique issue d'un nuplet
  // --------------------------------------
  protected :
  CATTopRibGeoNuplet      *  _GeoNuplet;   

  // Accrochage au MacroTool pour gestion memoire
  // --------------------------------------------
  private :
  int                        _MacroToolAppendIndex;

  // Solution topologique asociee a un nuplet. (Les tableaux sont a allouer par les classes derivees) 
  // -----------------------------------------
  private:
  CATEdge                 ** _Tracks;             // Traces ou bien Edge pointant vers vertex trace selon _TrackIsVertex
  CATBoolean               * _TrackIsVertex;
  CATEdge                 ** _EdgesForEV;                // Pour eviter la destruction des endvertex
  CATCell                 ** _LinkCell;          // Cellules liens 
  CATTopRibContact        *  _Contacts;          // Type des contacts
  CATBoolean              *  _LinkCellIsConfused;// Cellule liens confused oui/non
  CATTopRibSign              _Orientation;       // Orientation
  CATBoolean                 _IsNupletSigma[2];  // Stocke l'info que ce nuplet est potentiellemen en overlap avec une autre partie du ruban
  CATBoolean                 _VertexIsOnExactInterpol[2];// Geometric Interpolation is Exact at End Vertex

  // Donnees servant a determiner les nuplets suivant/precedents d'un nuplet
  // -----------------------------------------------------------------------
  protected :
  CATTopRibNupletCand     *  _CandBackward; // Candidat backward  
  CATTopRibNupletCand     *  _CandForward;  // Candidat forward

  CATBoolean                 _IsLocked;     // False si l'on peut perturber le resultat, true sinon

  // Pour recup ulterieure des traces hors ruban (utile notamment pour les encoches) 
  // -------------------------------------------------------------------------------
  private :
  CATTopRibNuplet         *  _ExtraNuplet[2];

  // Clone N-uplet (case of unsigned geometric solution) 
  // ---------------------------------------------------
  CATTopRibNuplet          * _CloneNuplet;

  // Pour la gestion des rubans isoles
  CATBoolean                 _HasBeenIsolated;

  private: //D1A: 28 may 2013
    CATBoolean _VertexAsCutting;

  // Donnees liees a la completion des nuplets
  // -----------------------------------------
  public :

  enum StateOfNuplet {
    NupletIsComplete,
    NupletIsIncomplete,
    Unknown
  };

  
  /* prl xxx : report ds LoopExtension : a faire */
  CATTopRib      ** _ExtrapolationEdgeRibbon;
  CATTopRibSign   * _ExtrapolationDirection;
  CATSide         * _ExtrapolationEdgeSide;
  CATCell        ** _ExtrapolationContactCell;
  CATCrvParam    ** _CrvParamOnExtrapolationContactCell;
  CATBoolean      * _ContactCellIsValid;
  StateOfNuplet   * _State;
  
  //CATLoopExtension        *_LoopExt; // non -> on demande au support

  public :
  
    void SetVertexAsCutting() {_VertexAsCutting = TRUE;} //D1A: 28 may 2013
  //------------------------------------------------------------------------------
  // Set du statut de completion
  //------------------------------------------------------------------------------
  void SetRelimState(CATTopRibSign                  iDirection,
                     int                            iSuppIndex,
                     CATTopRibNuplet::StateOfNuplet iState);

  //------------------------------------------------------------------------------
  // Get du statut de completion
  //------------------------------------------------------------------------------
  StateOfNuplet GetRelimState(CATTopRibSign iDirection,
                              int           iSuppIndex);

  //------------------------------------------------------------------------------
  // Set an extrapolation edge ribbon
  //------------------------------------------------------------------------------
  void SetExtrapolationEdgeRibbon(CATTopRibSign   iDirection,
                                  int             iSuppIndex,
                                  CATTopRib     * iExtrapolationEdgeRibbon,
                                  CATTopRibSign   iExtrapolationDirection,
                                  CATSide         iExtrapolationEdgeSide);

  //------------------------------------------------------------------------------
  // Get an extrapolation edge ribbon
  //------------------------------------------------------------------------------
  CATTopRib * GetExtrapolationEdgeRibbon(CATTopRibSign   iDirection,
                                         int             iSuppIndex,
                                         CATTopRibSign * oExtrapolationDirection = NULL,
                                         CATSide       * oExtrapolationEdgeSide  = NULL);
  //------------------------------------------------------------------------------
  // Steals an extrapolation edge ribbon : caller will have to destroy the ribbon
  //------------------------------------------------------------------------------
  CATTopRib * StealExtrapolationEdgeRibbon(CATTopRibSign   iDirection,
                                         int             iSuppIndex,
                                         CATTopRibSign * oExtrapolationDirection = NULL,
                                         CATSide       * oExtrapolationEdgeSide  = NULL);

  //------------------------------------------------------------------------------
  // Remove and destroy extrapolation edge ribbon in a given direction if it's
  // unused
  //
  // Please note: This method can only be called if the extrapolation edge ribbon
  //              is NOT shared with any other N-uplet!
  //------------------------------------------------------------------------------
  CATBoolean RemoveExtrapolationEdgeRibbon(CATTopRibSign iDirection,
                                           int           iSuppIndex,
                                           CATBoolean    iCheckIfUsed=1);
  
  //------------------------------------------------------------------------------
  // Find out if the edge extrapolation method has already been applied to
  // the N-uplet (for a given direction)
  //
  // iExtrapolationNuplet = NULL par defaut et est rempli si this nuplet ne le connait pas.
  // idem pour iExtrapolationDirection
  //
  // iCheckMore = 0 par defaut
  //              1 : EndVertex est-il pose coupant sur la track du nuplet d'extrapolation
  //                                              ou sur OtherVertex
  //                  ou  OtherVertex est-il pose coupant sur la track du nuplet (this)
  //                                              ou sur EndVertex 
  //------------------------------------------------------------------------------
  virtual CATBoolean QueryEdgeExtrapolationDone(CATTopRibSign iDirection,
                                                int           iSuppIndex,
                                                CATTopRibNuplet *iExtrapolationNuplet = NULL,
                                                CATTopRibSign    iExtrapolationDirection = 0,
                                                int           iCheckMore = 0);

  //------------------------------------------------------------------------------
  // Get the "last" N-uplet of th extrapolation edge ribbon
  //------------------------------------------------------------------------------
  CATTopRibNuplet *GetLastExtrapolationEdgeNuplet(CATTopRibSign  iDirection,
                                                  int            iSuppIndex,
                                                  CATLONG32          *oPosExtrapolationEdgeNuplet = NULL);

  //------------------------------------------------------------------------------
  // Set the extrapolation contact in a given direction
  //------------------------------------------------------------------------------
  void SetExtrapolationContactCell(CATTopRibSign   iDirection,
                                   int             iSuppIndex,
                                   CATCell        *iExtrapolationContactCell,
                                   CATBoolean      iContactCellIsValid = CATBoolean(0),
                                   CATCrvParam    *iCrvParamOnExtrapolationContactCell = NULL,
                                   CATBoolean      iCrvParamOnExtrapolationContactCellIsEvaluated = FALSE);

  //------------------------------------------------------------------------------
  // Get the extrapolation contact in a given direction
  //------------------------------------------------------------------------------
  CATCell * GetExtrapolationContactCell(CATTopRibSign  iDirection,
                                        int            iSuppIndex,
                                        CATBoolean   * oContactCellIsValid = NULL);

  //------------------------------------------------------------------------------
  // Get the CrvParam on extrapolation contact in a given direction, 
  // if ExtrapolationContactCell is an edge
  //------------------------------------------------------------------------------
  void GetCrvParamOnExtrapolationContactCell(CATTopRibSign  iDirection,
                                             int            iSuppIndex,
                                             CATCrvParam   &oCrvParamOnExtrapolationContactCell,
                                             CATBoolean    &oCrvParamOnExtrapolationContactCellIsEvaluated);

  //--------------------------------------------------------------------------------------
  // Creation d'un body mono wire correspondant a une TrackEdge du Nuplet sur un support
  //--------------------------------------------------------------------------------------
  CATBody * CreateBodyWithTrackOnSupport(int iSuppIndex);

  //------------------------------------------------------------------------------
  // Creation d'une liste de bodies mono wire correspondant aux Tracks du Nuplet
  // (un body mono wire est genere pour une Track sur un support)
  //------------------------------------------------------------------------------
  void CreateBodiesWithTracks(CATLISTP(CATBody) &oBodiesWithTracksList);

  //------------------------------------------------------------------------------
  // Get an isoparametric curve of the nuplet at a given location, if possible
  // Return TRUE only if a curve has been created
  // WARNING : The support MUST BE a curve, and iParam MUST BE "on this curve" !!!
  //------------------------------------------------------------------------------
  virtual CATBoolean GetIsoparametricCurve(const int        iSupportNumber, 
                                           CATCrvParam    & iParam,
                                           const int        iSupp1,
                                           const int        iSupp2,
                                           CATCurve      *& oIsoCurve, 
                                           CATCrvLimits   & oIsoCurveLimits,
                                           CATOrientation & oOrientation    );

  public :
  //------------------------------------------------------------------------------
  // Update all MergedCurves beneath the track edge(s)
  // Please note: the method returns FALSE if the update could not be
  // performed correctly; TRUE otherwise
  //------------------------------------------------------------------------------
  CATBoolean UpdateMergedCurves();

  virtual void CheckEdgeWithTgts(CATTopRibSign iDirection, CATEdge * iEdge,CATBoolean &oIsEdgeInGoodDirection);


  private :
  void  CutClosedEdge (CATEdge * iEdge, 
                       ListPOfCATCell &oTrackCell, 
                       CATTopRibSol *&oInOutInfo,
                       ListPOfCATCell          &oSuppCellsForInOutInfo);
  CATBoolean ClosedTrackShouldBeCut(ListPOfCATCell *iTrackCell,  
                                    CATTopRibSol **iInOutInfo);
  void CutClosedTrack (CATTopRibSign             iDirection,
                       CATLONG32                      iNumSupp,
                       ListPOfCATCell           &TrackCell,
                       CATTopRibSol            *&InOutInfo,
                       ListPOfCATCell          & oSuppCellsForInOutInf);

  public:

  //-----------------------------------------------------------------------------------------
  // Check if track is a degenerate edge that needs to be "fixed," i.e. turned into a vertex
  //-----------------------------------------------------------------------------------------
    // Modified By : SUH : 2004:8:5
  virtual CATBoolean DegenerateTrackEdgeMustBeFixed(int        iSupportIndex,
                                            CATBoolean iUseNupletLimits = FALSE);


  // Start : SOU : 2003:9:13
  public:
    
  virtual CATBoolean IsKeepEdge(CATEdge * iEdge);

  private:
  CATBoolean FindConfusdLinkCell(const CATLONG32 &iNumSup, CATVertex * iEndVertex, CATCell * iCellSup
                                ,CATTopRibSupport * iSupport,CATCell * iTrack, CATCell * &oCellEnd);

  // End : SOU : 2003:9:13

  // Added By : AJD : 2004:7:14
  // Checks if vertex location is in edge gap/overlap
  // returns Border edge and location on edge curve
  CATBoolean IsVertexLocationInEdgeGap( CATFace *iSupportFace,
                              const CATSurParam &iSurParam, CATEdge *&oBorderEdge, CATCrvParam &oParamOnBorder);

  // Added By : AJD : 2004:7:29
  // Checks if edge location is in border edge gap
  // if true, also splits the raw track edge
  // returns new set of edges split by border edge
  CATBoolean IsEdgeLocationInEdgeGap( CATFace *iSupportFace, CATEdge *iRawTrackEdge,
                              int &oNbNewEdges, CATEdge **&oNewEdges, CATLocation *&oEdgeLocations);

  // Added By : AJD : 04 Jan 2006
  // Checks if edge location is in border edge overlap
  CATBoolean IsEdgeLocationInEdgeOverlap( CATFace *iSupportFace, CATEdge *iRawTrackEdge);

  // pfv 06-02-2004
  public:
  void DeleteNupletCand(CATTopRibSign iDirection);
  void SetIsolated();
  // end pfv

  // jma 27/02/2004
  public :
  //-----------------------------------------------------------------------------------------
  // Check if iNuplet is entirely included in this (supports must be tested identical)
  //-----------------------------------------------------------------------------------------
  virtual CATBoolean Contains (CATTopRibSign    iDirection,
                               CATTopRibNuplet *iNuplet);
  public :
    CATTopRibNuplet* Clone ();

  // jma 26/03/2004
  public :
 //------------------------------------------------------------------------------
  // update des donnees internes de la classe suite au disconnect 
  //------------------------------------------------------------------------------
  virtual void UpdateWithJournal(CATCGMJournalList * iJournal, 
                                 ListPOfCATEdge    & iEdgesToReject, 
                                 CATShell          * iShellAfterDisconnect=NULL);

  virtual void UpdateWithJournal(CATCGMJournalList *iJournal, CATSewingCompl    &iSewingCompl);

  CATBoolean IsVertexTrack (int iNumSupp);

  public : 

    void GetComplFaceForConversion(int iSuppIndex, CATFace *& oComplFace, CATTopRibSol &oComplType);
    void SetComplFaceForConversion(int iSuppIndex, CATFace *  iComplFace, CATTopRibSol  iComplType);

  public :
    virtual CATBoolean IsIsoTopoSpecMatchingSet(int iSupp);
  
  //------------------------------------------------------------------------------
  // Perfs : pour garder les equations ouvertes
  //------------------------------------------------------------------------------
private:
    void LockSupportsInFormol();

    
    CATCrvParam _TwistStartOutOfUsefulLimits, _TwistEndOutOfUsefulLimits;
    CATBoolean _TwistParamsOutOfUsefulLimits;

public:
  void SetOutsideOfUsefulLimitsTwistParams(CATCrvParam &iTwistStart, CATCrvParam &iTwistEnd);
  CATBoolean GetOutsideOfUsefulLimitsTwistParams(CATCrvParam &oTwistStart, CATCrvParam &oTwistEnd);

    void DeleteFormol();

  // Methodes de cast mere/filles
  public:
    virtual CATBothSidesDraftNuplet* CastInBothSidesDraftNuplet();
    virtual CATNtrlDrftRibNuplet*    GetAsNtrlDrftRibNuplet();
    virtual CATReflectDrftRibNuplet* GetAsReflectDrftRibNuplet();
    virtual CATBlendNuplet*          GetAsBlendNuplet();
    virtual CATRlmNuplet*            GetAsRlmNuplet();   
    virtual CATBoolean IsSortOfBlendNuplet();

  public:
    virtual void RemoveExtrapolationEdgeRibbonNew(CATComplFace* iCFace);

 private: 
   CATTopRibSign _SplitEnd;
   CATBoolean SetSplitEnd(CATTopRibSign iEnd); 
 public:
   CATTopRibSign GetSplitEnd() const {return _SplitEnd;}  

   virtual CATBoolean IsValidForInsertion(const CATTopSign iDirection);
};

// --------------------------------------------------------------
// INLINE methods
// --------------------------------------------------------------
INLINE CATTopRibTool*            CATTopRibNuplet::GetTool()                     const { ThrowIfNull(_Tool)      ; return _Tool ; } ;

INLINE CATTopRibMacroTool*       CATTopRibNuplet::GetMacroTool()                const { ThrowIfNull(_Tool)      ; return _Tool->GetMacroTool() ; } ;

INLINE CATSoftwareConfiguration* CATTopRibNuplet::GetSoftwareConfiguration()    const { ThrowIfNull(_Tool)      ; return _Tool->GetMacroTool()->GetSoftwareConfiguration() ; } ;

INLINE CATBody*                  CATTopRibNuplet::GetCreationBody()             const { ThrowIfNull(_Tool)      ; return _Tool->GetCreationBody() ; } ;

INLINE CATGeoFactory*            CATTopRibNuplet::GetFactory()                  const { ThrowIfNull(_Tool)      ; return _Tool ? _Tool->GetCreationBody()->GetFactory()->GetImplicitGeoFactory() : NULL ; } ;

INLINE CATTopRibGeoNuplet*       CATTopRibNuplet::GetGeoNuplet()                const { ThrowIfNull(_GeoNuplet) ; return _GeoNuplet ; } ;

INLINE CATTopRibGeoNuplet*       CATTopRibNuplet::ReadGeoNuplet()               const {                           return _GeoNuplet ; } ;

INLINE int                       CATTopRibNuplet::GetDimension()                const {                           return _NbSupp ; } ;

INLINE CATTopRibSign             CATTopRibNuplet::GetOrientation ()                   {                           return _Orientation; };

INLINE CATTopRibNuplet *         CATTopRibNuplet::GetCloneNuplet()                    {                           return (_CloneNuplet); };

INLINE CATBoolean                CATTopRibNuplet::IsTransition()               const  {                           return _IsTransition ; };

INLINE void                      CATTopRibNuplet::SetOrientation (CATTopRibSign iOrientation) { _Orientation = iOrientation; };

//------------------------------------------------------------------------------
INLINE CATTopRibSupport*         CATTopRibNuplet::GetSupp(const int iNumSupp)   const
//------------------------------------------------------------------------------
{
  int SuppIndex = iNumSupp-1;
  if (iNumSupp > _NbSupp || SuppIndex < 0)  
    CATThrow (new TopologicalOperatorsInternalError(GBIntEFilletBadSupportNumber));
  ThrowIfNull(_Supp[SuppIndex]) ; 
  return _Supp[SuppIndex];
}

//------------------------------------------------------------------------------
INLINE CATCell * CATTopRibNuplet::GetLinkCell (CATTopRibSign  iDirection, int iNumSupp)
//------------------------------------------------------------------------------
{
  int off = (iDirection == Forward) ? _NbSupp : 0;
  return _LinkCell[off+iNumSupp-1];
}
//------------------------------------------------------------------------------



#endif
