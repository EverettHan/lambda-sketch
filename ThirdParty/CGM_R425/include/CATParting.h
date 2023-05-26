/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//----------------------------------------------------------------------------
//
// CATParting
// Definition CATParting
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Usage notes:
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// June 99    Creation                                 I. Levy
// Juil 99    Ajout debug + GetDataForExtr             P. Rossignol
// Sept 99    Ajout GetAllCutEdgesOfInitialBody        I. Levy
// Mar  00    Ajout GetPartingTypesOfNuplets           P. Rossignol
// Mar  00    Ajout GetEdgesPositionVsParting          P. Rossignol
// Dec  01    Gestion de plusieurs partings shells     fbz
//----------------------------------------------------------------------------
#ifndef CATParting_H 
#define CATParting_H

//Windows compatibility
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"


// TopologicalOperators libraries
#include "CATTopRibDef.h"
#include "CATTopRibObject.h"
#include "CATLimitingInfoForEdge.h"

// LISTP libraries
#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATShell.h"
#include "CATListOfInt.h"
#include "CATListOfCATPlanes.h"
#include "CATMapVoidToVoid.h"
#include "ListPOfCATTopRibNuplets.h"
#include "CATListPV.h"
#include "ListPOfCATVertex.h"

// Mathematics libraries
#include "CATMathDef.h"
#include "CATMathDirection.h"
#include "CATMathBox.h"

#include "CATCGMNewArray.h"
#include "CATCGMVirtual.h"

class CATBody;
class CATShell;
class CATFace;
class CATEdge;
class CATVertex;
class CATCell;
class CATCGMJournalList;
class CATMapVoidToVoid;
class CATTopologicalOperator;
class CATTopRib;
class CATSoftwareConfiguration;
class CATPlane;
class CATRibTopOp;
class CATFilletCrossPartingLinker;
class CATTopPropagationEdge;
class CATCGMActivateDebug;
class CATTopRibNuplet;

class CATDistanceMinPtSur;
class CATEdgeRibbon;
class CATDynEdgeFilletRibbon;
class CATTopPropagationEdge;
//class CATBlendVertexSpec;

//#define DebugVisuParting
//#define BreakPoints
//#define DeleteVisu

#ifdef DebugVisuParting
#include "CATTopRibDbg.h"
#endif

#include "CATSafe.h"
CATSafeDefine(CATParting);

//-----------------------------------------------------------------------------
/* Replaced by a new class
struct CATLimitingForEdge
{
  CATBody *_Body;
  //CATDynEdgeFilletRibbon *_SpecToLinkToLimiting;
  //CATEdgeRibbon  *_EdgeRibForLimiting;
  ListPOfCATEdge _SpecEdges;
  ListPOfCATEdge _RibbonEdges;
  CATShell * _PartingShell;
  int _NoPartingShell;
  void * _SpecForBV;
  ListPOfCATVertex _VertexToSimlify;
};
*/

class ExportedByRIBLight CATParting  : public CATTopRibObject
{
public:
  //-----------------------------------------------------------------------------
  // Constructor
  //
  // Please note: The provided orientation may be CATOrientationUnknown. In
  //              that case, CATParting will attempt to compute the orientation
  //              if the Parting element is (partly) confused with the initial
  //              body's shell.
  //              However, if the Parting body actually intersects the
  //              initial body (i.e. an IN Parting shell will be created)
  //              the Parting orientation will remain unknown and an error
  //              will be generated. 
  //-----------------------------------------------------------------------------
CATParting(CATBody                     *iCreationBody,
           CATBody                     *iPartingBody,
           ListPOfCATFace              &iPartingFaces,
           CATOrientation               iPartingOri,
           CATCGMJournalList           *iJournal,
           CATLONG32                    iPartingContext,
           CATBoolean                   iIsPartingUntil,
           const int                    iSmartCrossparting=0,
           CATFilletCrossPartingLinker *iLinker=NULL,
           CATBoolean IsForSpec=FALSE,
           int iLimitingCreatedFromConstructionDetails = 0,
           int iUniqueInfo = 0);

  CATCGMNewClassArrayDeclare; // Pool allocation

  //-----------------------------------------------------------------------------
  // Destructor
  //-----------------------------------------------------------------------------
  ~CATParting();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  void CleanUp();

  //-----------------------------------------------------------------------------
  // Add Parting in case of Multi Parting
  //-----------------------------------------------------------------------------
  void Add(CATBody                     *iPartingBody,
           ListPOfCATFace              &iPartingFaces,
           CATOrientation               iOrientation,
           CATLONG32                    iPartingContext,
           CATBoolean                   iIsPartingUntil,
           const int                    iSmartCrossparting=0,
           CATFilletCrossPartingLinker *iLinker=NULL,
           CATBoolean IsForSpec=FALSE,
           int iLimitingCreatedFromConstructionDetails = 0,
           int iUniqueInfo = 0);

  //-----------------------------------------------------------------------------
  // Assign configuration before running methods
  //-----------------------------------------------------------------------------
  void SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig);

  //-----------------------------------------------------------------------------
  // Returns TRUE if Parting is until 
  //-----------------------------------------------------------------------------
  CATBoolean IsPartingUntil(); // iNumeroParting=1
  CATBoolean IsPartingUntil(int iNumeroParting); /* for multi parting */

  //-----------------------------------------------------------------------------
  // Set data for initial Body
  //-----------------------------------------------------------------------------
  void SetInitialData(CATBody  * iInitialBody, CATShell * iInitialShell, CATBoolean InitialShellIsInternal=FALSE);
  void SetInitialData(int iNumeroParting,       /* for multi parting */
                      CATBody  * iInitialBody,
                      CATShell * iInitialShell);

  //-----------------------------------------------------------------------------
  // Set,unset and get update option for vertex blend
  //-----------------------------------------------------------------------------
  void ChangeUpdateForBV(int pos);
  CATBoolean GetUpdateForBV(int pos);



  //-----------------------------------------------------------------------------
  // Intersect parting Shell with initial Shell
  // Call after SetInitailData method
  // returns 1 if an intersection was found
  //-----------------------------------------------------------------------------
  int IntersectWithInitialShell(CATBoolean iRemoveDegenerate = CATBoolean(0));
  int IntersectWithInitialShell(int iNumeroParting, CATBoolean iRemoveDegenerate = CATBoolean(0));   /* for multi parting */

  //-----------------------------------------------------------------------------
  // Disconnect parting Shell
  // Call after IntersectWithInitialShell
  //-----------------------------------------------------------------------------
  void DisconnectParting();
  void DisconnectParting(int iNumeroParting); /* for multi parting */

  //-----------------------------------------------------------------------------
  // Disconnect Edges and Vertices of initial Shell only
  // Call after IntersectWithInitialShell
  //-----------------------------------------------------------------------------
  void DisconnectInitialEdges();

  //-----------------------------------------------------------------------------
  // Smart duplicates Parting Faces 
  //-----------------------------------------------------------------------------
  void SmartDuplicatePartingFaces(CATTopRibSol   * iType = NULL,
                                  ListPOfCATFace * iFacesNotToDuplicate = NULL,
                                  CATCGMJournalList  * iJournal=NULL);
  
  //-----------------------------------------------------------------------------
  // Returns 1 if :
  // _ Shell is parting, with its type (optionnal)
  // _ Face  is parting, with its type (optionnal)
  // _ Edge  is a cutting an initial Cell
  //-----------------------------------------------------------------------------
  CATBoolean IsPartingShell(CATShell * iShell, CATTopRibSol * oType         = NULL);
  CATBoolean IsPartingFace(CATFace   * iFace , CATTopRibSol * oType         = NULL);
  CATBoolean IsCuttingEdge(CATEdge   *  iEdge, 
                           CATCell   ** oCellSupport = NULL,
                           CATSide   *  oSide        = NULL);

  //---------------------------------------------------------------------------
  // Returns 1 if Cell is on border of a Parting Face
  //---------------------------------------------------------------------------
  CATLONG32 IsBorderOfPartingFace(CATCell * iCell);

  //-----------------------------------------------------------------------------
  // Returns all the parting Shells of a given type
  //-----------------------------------------------------------------------------
  void GetAllPartingShells(ListPOfCATShell & oListOfShells,
                           CATTopRibSol    * iType = NULL);

  //-----------------------------------------------------------------------------
  // Returns the parting Shell containing the given Face and the numero of Parting Shell
  //-----------------------------------------------------------------------------
  // CATShell * GetPartingShell(CATFace * iPartingFace);
  CATShell * GetPartingShell(CATFace * iPartingFace, int & oNumeroParting); 
  CATShell * GetPartingShell(CATEdge * iEdge, int & oNumeroParting); 
  

  //-----------------------------------------------------------------------------
  // Returns the initial Shell
  //-----------------------------------------------------------------------------
  CATShell * GetInitialShell();

  //-----------------------------------------------------------------------------
  // Returns the Body containing the initial Shell
  //-----------------------------------------------------------------------------
  CATBody  * GetBodyOfInitialShell();

  //-----------------------------------------------------------------------------
  // Returns the Body containing the parting Shells
  //-----------------------------------------------------------------------------
  CATBody  * GetBodyOfPartingShell(CATFace * iFace); /* ajout d'une face pour multi-parting */

  //-----------------------------------------------------------------------------
  // Pour multi-parting
  //-----------------------------------------------------------------------------
  int GetNumParting(CATShell *iShell);

  //-----------------------------------------------------------------------------
  // Returns the parting orientation 
  //-----------------------------------------------------------------------------
  CATOrientation  GetOrientation(int iNumeroParting); /* pour multi parting */

  //-----------------------------------------------------------------------------
  // Modifies the parting orientation
  //-----------------------------------------------------------------------------
  void SetOrientation(int iNumeroParting, CATOrientation iPartingOri); /* pour multi parting */

  //-----------------------------------------------------------------------------
  // Returns initial parting Faces 
  //-----------------------------------------------------------------------------
  void GetInitialPartingFaces(const int iNumeroParting, 
                              CATLISTP(CATFace) &oInitialPartingFaces,
                              CATListOfInt      &oFacesOrientation    ) const;

  //-----------------------------------------------------------------------------
  // Returns the relative orientation between the initial Shell and 
  // parting Shells of a given type
  //-----------------------------------------------------------------------------
  CATOrientation  GetRelativeOrientation(CATTopRibSol iType, CATFace * iFace); /* ajout d'une face pour multi-parting */

  //-----------------------------------------------------------------------------
  // Returns the type of a parting Face :
  //  _ SolTypeIn                   if the Face is inside  the initial Shell
  //  _ SolTypeOut                  if the Face is outside the initial Shell
  //  _ SolTypeIn +SolTypeConfused  if the Face is confused In  with the initial Shell
  //  _ SolTypeOut+SolTypeConfused  if the Face is confused Out with the initial Shell
  //-----------------------------------------------------------------------------
  CATTopRibSol    GetPartingFaceType(CATFace * iPartingFace);

  //-----------------------------------------------------------------------------
  // Returns the type of a parting Shell :
  //       _ SolTypeIn    if the Shell is inside  the initial Shell
  //       _ SolTypeOut   if the Shell is outside the initial Shell
  //-----------------------------------------------------------------------------
  CATTopRibSol    GetPartingShellType(CATShell * iPartingShell);
  
  //-----------------------------------------------------------------------------
  // Returns whether a Parting is SmartCrossparting or not.
  // if iNumeroParting==0, returns whether at least one Parting is SmartCrossParting
  //-----------------------------------------------------------------------------
  CATBoolean IsSmartCrossParting(const int iNumeroParting=0) const;

  //-----------------------------------------------------------------------------
  // Computes & bufferizes whether a Parting is fully included in the BRep of the input body.
  //-----------------------------------------------------------------------------
  CATBoolean IsCrossPartingOnBoundary(const int iPartingIndex, CATFilletCrossPartingLinker** oLinker=NULL);

  //-----------------------------------------------------------------------------
  // Returns all the parting Faces of agivem type
  //-----------------------------------------------------------------------------
  void GetPartingFaces(CATTopRibSol    iType, ListPOfCATFace &oListOfFaces);

  //-----------------------------------------------------------------------------
  // Returns all the parting Faces of EXACTLY a given type and on a given parting Number
  //-----------------------------------------------------------------------------
  void GetPartingFaces(const CATTopRibSol iType, const int iNumeroParting, ListPOfCATFace &oListOfFaces);

  //-----------------------------------------------------------------------------
  // Returns all the cutting Edges lying on iFace in an ordered list
  // oOrientation     : orientation of Edges (synchronized list)
  // oNbrEdgesPerWire : number of continuous edges (not synchronized)
  //-----------------------------------------------------------------------------
  void GetCuttingEdges(CATFace        * iFace, 
		                   ListPOfCATEdge  &oCuttingEdges,
		                   CATListOfInt   * oOrientation = NULL,
		                   CATListOfInt   * oNbrEdgesPerWire = NULL);

  //-----------------------------------------------------------------------------
  // Returns all the Edges lying on initial Face that have been cut
  // oListOfTypes :
  //       _ SolTypeIn        if the Edge is above the parting
  //       _ SolTypeOut       if the Edge is below the parting
  //       _ SolTypeConfused  if the Edge is confused with the parting
  // Si iCheckType = FALSE, on ne fait pas le check sur les types Unknown  
  //-----------------------------------------------------------------------------
  void GetCutEdgesOfInitialFace(CATFace       * iInitialFace,
                                ListPOfCATEdge &oListOfCutEdges,
                                CATListOfInt   &oListOfTypes,
                                CATBoolean      iCheckType = TRUE,
                                void           *iFilletSpec = NULL );

  //-----------------------------------------------------------------------------
  // Returns all the Edges of initial Body that have been cut
  //-----------------------------------------------------------------------------
  void GetAllCutEdgesOfInitialBody(ListPOfCATEdge  &oListOfCutEdges,
                                   CATListOfInt   * oListOfTypes = NULL,
						                       void *iFilletSpec = NULL );

  //-----------------------------------------------------------------------------
  // Returns TRUE if a CutEdge sharing iVertex with iCuttingEdge and having the
  // good type have been found
  // oCutEdge  : Edge of initial Shell which has a common vertex (iVertex) with
  //             a given CuttingEdge
  // oPrevFace : Face of initial Shell that is the support cell of iCuttingEdge and
  //             that is bordered by oCutEdge
  // oNextFace : Other Face bounded by oCutEdge
  // Signification de iOption :
  //  0 - Valeur par defaut et comportement de base
  //  1 - Activation du traitement special confusion [n'est active que lorsqu'on
  //      est en mode completion recursive]
  //-----------------------------------------------------------------------------
  CATBoolean GetSurroundingCandidatesOfInitialShell(CATEdge    *  iCuttingEdge,
                                                    CATVertex  *  iVertex,
                                                    CATTopRibSol  iType,
                                                    CATEdge    * &oCutEdge,
                                                    CATFace    * &oPrevFace,
                                                    CATFace    * &oNextFace,
                                                    int           iOption = 0,
											        void       *  iFilletSpec = NULL);

  //-----------------------------------------------------------------------------
  // Gets the support candidates of initial Shell
  //-----------------------------------------------------------------------------
  void GetSupportCandidatesOfInitialShell(CATCell        * iCuttingCell,
                                          ListPOfCATEdge & oAdjEdges,
                                          ListPOfCATFace & oAdjFaces);    
   
  //-----------------------------------------------------------------------------
  // Rend les donnees necessaires a la construction du support d'extrapolation
  // Service pour les methodes d'odonnancement des faces candidates.
  //----------------------------------------------------------------------------
  void GetDataForExtrSupport( CATVertex         *iVertex, 
                              CATEdge            *iBodyEdge,
                              //CATTopRibSol  iType,                            
                              CATFace            *iFaceBeforVertex,
                              CATFace            *iFaceAfterVertex,
                              ListPOfCATEdge     &oPartingEdgeBeforVertex,
                              ListPOfCATEdge     &oPartingEdgeAfterVertex,
                              ListPOfCATFace     *oPartingFaceBeforVertex = NULL,
                              ListPOfCATFace     *oPartingFaceAfterVertex = NULL);

  //------------------------------------------------------------------------------
  // Rend 1) la face parting OUT/IN bordee par iBorderEdge et adjacente a iFace
  //      2) le shell parting de cette face out
  //
  // NB: 1) Si iface est une face du shell initial qui est en confusion avec une
  //        face Parting et s'il y a une autre face parting adjacente a iBorderEdge
  //        alors la methode rend cette autre face
  //     2) Si iCheckInputFaceLocation vaut FALSE, la method suppose que iFace est
  //        IN ou CONFUSED, ce qui a pour consequence que le resultat vaudra NULL
  //        si en fait elle est OUT
  //------------------------------------------------------------------------------
  CATFace* GetOutPartingFace(CATFace     *iFace,
                             CATEdge     *iBorderEdge,
                             CATShell   **oOwningShell            = NULL,
                             CATBoolean   iCheckInputFaceLocation = FALSE);

  //------------------------------------------------------------------------------
  // Service qui rend la liste des positions des differents nuplets de iRib
  // (de iFirstIndex a iLastIndex) par rapport au parting
  // Les elements de cette liste peuvent prendre les 3 valeurs suivantes:
  // - SolTypeIn        : le nuplet est situe au-dessus  du parting
  // - SolTypeOut       : le nuplet est situe au-dessous du parting
  // - SolTypeConfused  : le nuplet est en confusion avec le parting
  // NB : s'il n'y a pas de parting, tous les elts de la liste valent SolTypeIn
  //      (i.e. tous les nuplets sont consideres "au-dessus du parting").
  //------------------------------------------------------------------------------
  void GetPartingTypesOfNuplets(CATLONG32       iFirstIndex, 
                                CATLONG32       iLastIndex,
                                int        iNumSupp,   
                                CATTopRib *iRib,
								CATListOfInt & oPartingTypesList);

  //------------------------------------------------------------------------------
  // Marquage des nuplets du ruban avec leur position par rapport au parting
  //------------------------------------------------------------------------------
  void UpdatePartingTypesOfNuplets(CATTopRib *iRib, int iNumSupp, CATBoolean *ioRattrap = NULL, 
                                   CATTopPropagationEdge *iSA=NULL, CATBoolean iSaveVerticesForSimplification=FALSE, void * iSpec=NULL);
  void UpdatePartingTypesOfNuplets(CATLISTP(CATTopRibNuplet) &iLNuplets, const int iNumSupp, CATTopPropagationEdge *iSA=NULL,CATBoolean iSaveVerticesForSimplification=FALSE,
	                               void * iSpec = NULL); 
  void UpdatePartingTypesOfNuplets(CATTopRibNuplet  *iNup,int         iNumSupp,
                                             CATTopRibSol &ReferenceType, 
                                             ListPOfCATTopRibNuplets &iLNuplets,
                                             int &iFirst, int &iPresent,
                                             CATBoolean *ioRattrap = NULL,
                                             //CATTopPropagationEdge *iSA = NULL,
                                             CATListPV *iInfoForAssocWithRibbon=NULL,
                                             CATBoolean iSaveVerticesForSimplification=FALSE,
                                             CATCGMActivateDebug* BrkPntMngr = NULL, 
                                             CATLISTP(CATGeometry) *CreatedObjects = NULL );

  //------------------------------------------------------------------------------
  // Modifier la super arete afin de garder la partie d'edges contenue du cote
  // fonctionnelle du parting
  //------------------------------------------------------------------------------
  void UpdateSA (CATTopPropagationEdge *iSA, ListPOfCATEdge *iRemovedEdges=NULL, void * iFilletSpec=NULL);

  void GetPartingTypesForWire (ListPOfCATEdge* iEdges, CATListOfInt* iOrientations,
                               CATListOfInt & oTypeVsParting, CATTopPropagationEdge *iSA=NULL,
                              // CATBoolean *iAllInfoForAssoc=NULL,
                               CATBoolean *IgnoreBVLimitings=NULL, void *FilletSpecs=NULL);
  //------------------------------------------------------------------------------
  //Requettes sur la situation (le positionnement) des cellules vs parting
  //------------------------------------------------------------------------------
  int  IsLyingOnParting (CATVertex *iVertex, // returns Parting number
                         ListPOfCATFace  &oFace,
                         CATEdge        *&oEdge,
                         CATVertex      *&oVertex,
                         CATListOfInt   *iSearchedPartingNo = NULL,
                         CATBoolean     *iIgnoreSearchedPartings=NULL,
                         ListPOfCATVertex *iVertexToSimlify = NULL);
  int  IsLyingOnParting (CATEdge *iEdge, // return 0, 1, 2 or 3
                         CATVertex *iStartVertex, 
                         CATVertex *iEndVertex,
                         CATTopRibSol& oType,
                         CATListPV *iInfoForAssocWithRibbon=NULL,
                         CATBoolean     *iIgnoreSearchedPartings=NULL,
                         ListPOfCATVertex *iVertexToSimlify=NULL
                         );
  //------------------------------------------------------------------------------
  // Answers if the edge is on the side defined by the orientation of the parting skin
  //------------------------------------------------------------------------------
  CATBoolean EdgeIsInOrUnknown(CATEdge *iCurEdge, CATBoolean *iIgnoreBVLimitings=NULL, void * iFilletSpec =NULL);

  //------------------------------------------------------------------------------
  // Service qui type les aretes de la face iFace lorsqu'elle est intersectee
  // par le parting (si la face est non intersectee, on rend la PseudoLoop
  // constituee de la concatenation de toutes les aretes de la face, mais
  // la liste parallele oPseudoLoopTypes est mise a SolTypeUnknown).
  // Les types possibles sont les suivants:
  // - SolTypeIn        : l'edge est situee au-dessus  du parting
  // - SolTypeOut       : l'edge est situee au-dessous du parting
  // - SolTypeConfused  : l'edge est en confusion avec le parting
  // Si iFace n'est pas intersectee par le parting, mais qu'une (ou plusieurs)
  // des edges de iFace sont en confusion avec des edges du parting,
  // on met oFaceIsJustConfused a VRAI, oFaceIsNotIntersected a VRAI et
  // les autres listes sont remplies de la meme facon que dans le cas ou 
  // iFace n'est pas intersectee par le parting.
  //------------------------------------------------------------------------------
  void GetEdgesPositionVsParting(CATFace        *iFace, 
                                 CATBoolean     &oFaceIsNotIntersected,
                                 CATBoolean     &oFaceIsJustConfused,
                                 ListPOfCATEdge &oPseudoLoop,
                                 CATListOfInt   &oPseudoLoopTypes,
                                 CATListOfInt   *oNumLoop = NULL,
                                 int            *oNbLoops = NULL);

  //------------------------------------------------------------------------------
  // Rend les edges de iFace qui sont en confusion avec des edges du parting
  //------------------------------------------------------------------------------
  ListPOfCATEdge GetConfusedEdges(CATFace *iFace);

  //-----------------------------------------------------------------------------
  // Get the support face of a confused Parting face
  //-----------------------------------------------------------------------------
  CATFace * GetSupportFaceOnInitialShell(CATFace      * iPartingFace,
                                         CATTopRibSol * oType = NULL);
  CATBoolean SetSupportFaceOnInitialShell(CATFace*           iPartingFace, 
                                          const CATTopRibSol iType,
                                          CATFace*           iInitialFace);

  //-----------------------------------------------------------------------------
  // Get the confused Parting face lying on a given face of the initial shell
  //-----------------------------------------------------------------------------
  CATFace * GetConfusedPartingFace(CATFace      * iInitialFace,
                                   CATTopRibSol * oType = NULL);

  //------------------------------------------------------------------------------
  // Set the optional information for the Edges reporting
  //------------------------------------------------------------------------------
  void SetEdgeReporting   (CATCGMJournalList * iEdgesJournal); 
  void UnsetEdgeReporting ();
  //------------------------------------------------------------------------------
  // Get/set _Journal
  //------------------------------------------------------------------------------
  CATCGMJournalList* GetPartingJournal();
  void SetPrivateJournal (CATCGMJournalList* iJournal, CATBoolean IsPrivate=TRUE);

  //------------------------------------------------------------------------------
  // Compute the best box for the Parting
  //------------------------------------------------------------------------------
  void ComputePartingBox(CATMathBox        &iInitialBox,
                         CATMathBox        &oPartingBox,
                         CATMathDirection * iDirection = NULL);
  
  //------------------------------------------------------------------------------
  // Update List of the shells or _partingshell for the sake of the cleaning
  //------------------------------------------------------------------------------
  void UpdateWithRemovedShell (CATShell *CurShell);
    
  //------------------------------------------------------------------------------
  // Save List of edges for the sake of the cleaning
  //------------------------------------------------------------------------------
  void SaveIntersectionScar (int iNbWires,CATEdge **iEdgesWire, int *iNbEdgesInWire);

  //------------------------------------------------------------------------------
  // Set RibTopOp
  //------------------------------------------------------------------------------
  void SetRibTopOp(CATRibTopOp *iRibTopOp);

  //------------------------------------------------------------------------------
  // Rend TRUE en cas de collision entre la skin a coudre d'une part [iSkin]
  // et les shells parting out inutilises d'autre part
  //------------------------------------------------------------------------------
  CATBoolean CheckPartingsCollision(CATShell        *iSkin,                     
                                    ListPOfCATShell &iAllPartingShells,
                                    ListPOfCATShell &iPartingShellsToDisc);

  //------------------------------------------------------------------------------
  // Prepro qui regarde les intersections inter parting/limiting 
  // Si il y a intersection, alors on lancera le check final
  //------------------------------------------------------------------------------
  void CheckPartingsCollision();

  //------------------------------------------------------------------------------
  // Rend le diagnostic de collision
  //------------------------------------------------------------------------------
  CATBoolean CollisionHasBeenDetected();

  //------------------------------------------------------------------------------
  // Set special priority mode (in cases of convex trimming, if there are only
  // OUT Parting faces and faces on the initial body, the latter have a higher
  // priority, but only if the special priority mode has been activated)
  //------------------------------------------------------------------------------
  void SetSpecialProrityMode(CATBoolean iSpecialPriorityMode);

  //------------------------------------------------------------------------------
  // Get special priority mode
  //------------------------------------------------------------------------------
  CATBoolean GetSpecialProrityMode();
  //------------------------------------------------------------------------------
  // IsInitialised
  //------------------------------------------------------------------------------
  CATBoolean IsInitialised();
  //-----------------------------------------------------------------------------
  //
  //-----------------------------------------------------------------------------
  void UpdateWithNewBody (CATBody *iOldBody,CATBody *iNewBody);
   //-----------------------------------------------------------------------------
  // Pour travailler dans le mode PartingUntil meme si le parting intersect le body initial 
  //-----------------------------------------------------------------------------
  void ForcePartingUntil ();
  void UnforcePartingUntil ();
  CATBoolean IsPartingUntilForced();
  CATBoolean DoesPartingCutOneRib();


  //-----------------------------------------------------------------------------
  // Association du limiting avec la super arete SW Blend VErtex
  //-----------------------------------------------------------------------------
public :
    void AddLimitingInfoForEdge (CATListPV & iLimitingInfo);
    void SetWithRibbonEdges (CATTopPropagationEdge *iSA);
    void GetLimitingInfoForEdge (CATListPV & iLimitingInfo);
    void UpdateLimitingInfoForEdge (CATCGMJournalList *iJournal);
    CATLimitingInfoForEdge *GetLimitingInfoForEdge (int NuPartingShell);

    CATBoolean IsAssocWithRibbon (int NuPartingShell);

    CATBoolean HasLimitingInfoForEdge_TypeDL();   

private:
  //---------------------------------------------------------------------------
  //- Data
  //---------------------------------------------------------------------------
  // Parting Data
  CATBody                      * _CreationBody;  
  ListPOfCATBody                 _ListOfPartingBody; 
  int                            _NbParting;

  ListPOfCATFace                 _PartingFaces;
  CATListOfInt                   _NumeroFirstFaceParting;  
  ListPOfCATBody                 _ListOfInitialPartingBody; 
  ListPOfCATFace                 _InitialPartingFaces;

  CATShell                     * _InitialShell;
  ListPOfCATShell                _ListOfPartingShell;  

  CATMapVoidToVoid               _ListOfCutPartingFaces; // Ptr1 = CATCell, Ptr2 = CATPartingFaceInfo
  CATMapVoidToVoid               _ListOfCuttingEdges;    // Ptr1 = CATCell, Ptr2 = CATPartingCuttingEdgeInfo
  ListPOfCATCell                 _ListOfFreeEndEdges;
  CATListOfInt                   _ListOfClosedWire;
  ListPOfCATShell                _ListOfPartingShells[2];  // [0] => Out   [1] => In
  CATEdge                      * _RefIteratorEdge;

  // JMA : BlendVertex for SW : association of parting with a particular ribbon
  CATListPV                     _LimitingAssocWithRibbon; // CATLimitingForEdge

  CATListOfInt                   _PartingOrientation;  
  CATListOfInt                   _SmartCrossParting;  // 0: Limiting, 1: CrossParting, 2: CrossPartingOnBoundary 
  CATFilletCrossPartingLinker   *_CrossPartingLinker;
  int                            _IntersectInitialShell;
  CATListOfInt                   _IsIntersectingInitialShell;  

  CATBoolean                     _PartingShellIsInternal;
  CATListOfInt                   _IsMPartingUntil;  
    
  CATLISTP(CATPlane)             _InfPlane;  

  CATRibTopOp                  * _RibTopOp;

  ListPOfCATEdge                 _IntersectionScar;      // edges to be cleaned if not used
  CATBoolean                     _XBetweenPartings;

  CATDistanceMinPtSur          * _DMinPtSur;

  // Journal Data
  CATCGMJournalList             * _Journal;
  CATCGMJournalList             * _EdgeJournal;
  CATSoftwareConfiguration*       _SoftwareConfiguration;
  CATListOfInt                    _MPartingContext;  
  CATBoolean                      _JournalIsPrivate;

  CATBoolean                      _SpecialPriorityMode;
  CATBoolean                      _PartingUntilForced;
  CATBoolean                      _PartingCutsOneRib;

  // Bufferisation + set des types Unknown pour GetCutEdgesOfInitialFaceSingle
  CATBoolean                      _UseBufCutEdges;
  ListPOfCATEdge                  _BufCutEdges;
  CATListOfInt                    _BufCutEdgesTypes;
  //ListPOfCATFace                  _BufCutEdgesFaces;

  //CATBoolean _LimitingCreatedFromConstructionDetails;
  CATListOfInt _LimitingFromPtDir, _ListOfUniqueInfo;

#ifdef DebugVisuParting
  //------------------------------------------------------------------------------
  // Debug data
  //------------------------------------------------------------------------------

  CATShowGeometry *_DbgVisuParting;
#endif

  //---------------------------------------------------------------------------
  //- Internal structures
  //---------------------------------------------------------------------------
  struct CATPartingFaceInfo
  {
    CATTopRibSol   _Type;
    CATFace      * _SupportFace;
    int            _NumeroPartingShellInitial; /* pour Multi parting */
   // CATEdgeRibbon *_EdgeFRib;
  };
  
  struct CATPartingCuttingEdgeInfo
  {
    CATCell        * _SupportCell;
    CATTopRibSol     _Type;
    CATOrientation   _Ori;
    int              _WireNbr;
  };

  //---------------------------------------------------------------------------
  //- Internal methods
  //---------------------------------------------------------------------------

  //---------------------------------------------------------------------------
  // Update _ListOfCutPartingFaces, _ListOfPartingShellsIn 
  // and _ListOfPartingShellsOut
  //---------------------------------------------------------------------------
  void InsertFaces(CATFace ** iListOfFaces, int iNbFaces, 
    CATTopRibSol iType, int iNumeroParting);



  //---------------------------------------------------------------------------
  // Prepare data before calling InsertFaces
  //---------------------------------------------------------------------------
  void UpdateCutPartingFaces();
  void UpdateCutPartingFaces(int iNumeroParting); /* pour multi parting */
  void UpdateCutPartingFacesOnBoundary(int iNumeroParting); 

  //---------------------------------------------------------------------------
  // Update _ListOfCuttingEdges and _ListOfClosedWire
  //---------------------------------------------------------------------------
  void UpdateCuttingEdges();  

  //-----------------------------------------------------------------------------
  // Returns all Edges lying on initial Face that have been cut by iCuttingEdge
  // and that have iVertex as an extremity 
  // oListOfTypes :
  //       _ SolTypeIn        if the Edge is above the parting
  //       _ SolTypeOut       if the Edge is below the parting
  //       _ SolTypeConfused  if the Edge is confused with the parting
  // iConsidersInShellsToo permet de considerer aussi les shells In pour
  // typer les CutEdges.
  //
  // Attention : cette methode peut maintenant rendre le type Unknown
  // =========   [ceci pour prendre en compte toutes les faces parting]
  //             C'est a l'appelant de gerer cette sortie.
  //             
  //-----------------------------------------------------------------------------
  void GetCutEdgesOfInitialFaceSingle(CATFace       * iInitialFace,
                                      CATEdge       * iCuttingEdge,
                                      CATVertex     * iVertex,
                                      ListPOfCATEdge &oListOfCutEdges,
                                      CATListOfInt  * oListOfTypes = NULL,
                                      int             iConsidersInShellsToo = 0,
                                      void          * iFilletSpec = NULL);


private :
 CATBoolean _InitialShellIsInternal;
 public :
 void UnsetInitialShellIsInternal();

 CATListOfInt _NeedsUpdateForVB;

};
#endif
