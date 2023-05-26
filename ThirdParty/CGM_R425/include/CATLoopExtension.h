/* -*-C++-*- */

#ifndef CATLoopExtension_H
#define CATLoopExtension_H

// COPYRIGHT DASSAULT SYSTEMES 2000

//=============================================================================
//=============================================================================
//
// CATLoopExtension 

// classe centralisant la gestion du processus de completion :
// - gestion des rubans d'extrapolations
// - gestion de la completion des nuplets
// - partage des rubans d'extrapolation
// - creation de nouvelles faces sur la surfaces initiale (permettra
//   notamment de franchir la fermeture d'une surface fermee)
//
// NB : a priori, on aura une bijection CATLoopExtension/Face initiale
//      il faudra voir si on ne doit pas remplacer cette bijection par
//      CATLoopExtension/Surface
//      (permettrait une premiere gestion des collisions)
//
//=============================================================================

//=============================================================================
// Jan  2000  Creation                               P. Rossignol
//
//            Contributions majeures                 ASE CWM FBZ PRL
//
//            Responsable                            P. Rossignol
//=============================================================================
//=============================================================================



// Ribbon
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "ListPOfCATComplFace.h"
#include "CATTopDef.h"
#include "ListPOfCATTopRibNuplets.h"
#include "ListPOfCATTopRibSupports.h"

// Topologie
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATTopology.h"
#include "CATMemVertMerger.h"

// Geometrie
#include "CATSurLimits.h"

// Math
#include "CATMathDef.h"
#include "CATMathInline.h"

// System
#include "CATListPV.h"

// Autres
class CATBody;
class CATShell;
class CATFace;
class CATLoop;
class CATEdge;
class CATVertex;
class CATCell;
class CATSurface;
class CATSoftwareConfiguration;
class CATRelimInit;
class CATRibTopOp;
class CATTwistAnalysis;

#include "CATTopRibObject.h"

// Pour le nommage des bords
#define CATBordType int

#include "CATSafe.h"
CATSafeDefine(CATLoopExtension);

class ExportedByRIBLight CATLoopExtension  : public CATTopRibObject
{

public: 
  
  //------------------------------------------------------------------------------
  // Constructeurs
  //------------------------------------------------------------------------------
  CATLoopExtension(); 
  //CATLoopExtension(CATBody                  *iCreationBody,
  //                 CATFace                  *iInitialFace,
  //                 CATLoop                  *iInitialLoop,
  //                 CATSoftwareConfiguration *iConfig);

  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATLoopExtension();

private:
  //------------------------------------------------------------------------------
  // Copy constructor. Not implemented
  //------------------------------------------------------------------------------
  CATLoopExtension(CATLoopExtension &iLoopExtension);

  //------------------------------------------------------------------------------
  // Affectation operator. Not implemented
  //------------------------------------------------------------------------------
  CATLoopExtension& operator=(const CATLoopExtension &iLoopExtension);

public:

  //------------------------------------------------------------------------------
  //  Generate the CATComplFace(s) of the LoopExtension
  //
  // (Raise exception whenever this not empty and this is still referenced to)
  //------------------------------------------------------------------------------
  void SetLoopExtData(CATBody*                  iCreationBody,
                      CATFace*                  iInitialFace,
                      CATLoop*                  iInitialLoop,
                      CATSoftwareConfiguration* iConfig, 
                      CATBoolean                iCreateSingleComplLoopExtension,
                      CATSurLimits*             iExtrapolResLimits,
                      CATFace*                  iPrevInitialFace = 0, // original face and loop used in a
                      CATLoop*                  iPrevInitialLoop = 0, // previous complementary computation. 
                      CATListPV*                iOldLoops = NULL,     // Tableaux de correspondances entre les loops de iPrevInitialFace
                      CATListPV*                iNewLoops = NULL);    // et les loops de la nouvelle face complementaire

  void SetRibTopOp(CATRibTopOp* iRibTopOp);
  void SetClosureOnFrontierIsDetected(CATEdge* iEdge);  // Appel de la methode de mm nom sur le RibTopOp - Throw si _RibTopOp non defini
  CATBoolean ClosureOnFrontierHasBeenDetected();        // Appel de la methode de mm nom sur le RibTopOp - Throw si _RibTopOp non defini
  CATBoolean ComplementairesFix_2();                    // Rend TRUE si code "Complementaires Drop2" actif

  //------------------------------------------------------------------------------
  // Set/Get/HasComplFace
  //------------------------------------------------------------------------------
/*
  virtual void SetComplFace(CATComplFace *iComplFace);
*/
  INLINE int GetNbComplFaces();
  INLINE CATComplFace* GetComplFace(int i);
  virtual int HasComplFace();

  //------------------------------------------------------------------------------
  // Renvoie la boite 2D de la loop
  //------------------------------------------------------------------------------
  void Get2DBoundingBox(CATSurLimits &oLimits);

  //------------------------------------------------------------------------------
  // Get the Index of a ComplFace that contains a given complementary Face
  // The method generates an error if the face is found more than once
  // If iThrowErrorIfNoIndex is TRUE, it also generates if the face isn't
  // found at all (if iThrowErrorIfNoIndex is FALSE, the method returns 0
  // in that case)
  //------------------------------------------------------------------------------
  int GetIndexOfComplFace(CATFace    *iComplementaryFace,
                          CATBoolean  iThrowErrorIfNoIndex = TRUE);

  //------------------------------------------------------------------------------
  // Find out if two faces are complementary faces in the same loop extension
  //------------------------------------------------------------------------------
  CATBoolean AreBothComplementaryFaces(CATFace *iPrevComplFace,
                                       CATFace *iNextComplFace);

  //------------------------------------------------------------------------------
  // GetInitialFace
  //------------------------------------------------------------------------------
  virtual CATFace* GetInitialFace();

  //------------------------------------------------------------------------------
  // GetInitialLoop
  //------------------------------------------------------------------------------
  INLINE CATLoop* GetInitialLoop();

  //------------------------------------------------------------------------------
  // GetCreatedLoop (Aujourd'hui : celle de la complface)
  //------------------------------------------------------------------------------
  virtual CATLoop* GetCreatedLoop();

  //------------------------------------------------------------------------------
  // Doit-on splitter les nuplets sur loopext avec toutes les loops
  //------------------------------------------------------------------------------
  CATBoolean GetSplitAllLoops();
  void       SetSplitAllLoops(CATBoolean iDoSplit);

  //------------------------------------------------------------------------------
  // special cas de confusion (HFV)
  //------------------------------------------------------------------------------
  void       SetSpcConfused();
  CATBoolean GetSpcConfused();


  //------------------------------------------------------------------------------
  // Get the ComplementaryFace of the i-th ComplFace object
  // NB: sort en erreur si pas de complementary face (i.e. on doit s'assurer
  //     de l'existence de la complface auparavant).
  //------------------------------------------------------------------------------
  virtual CATFace* GetComplementaryFace(int i);
  INLINE CATFace * GetComplFaceAdjInitialFace(int iCmplFace);
  INLINE int GetNbComplFaceAdjInitialFace();

  //-----------------------------------------------------------------------------
  // Partage des donnees : AddRef et Release 
  //-----------------------------------------------------------------------------
  void AddRefOnLoop();
  CATLONG32 ReleaseOnLoop();            

  //------------------------------------------------------------------------------
  // AppendNup : ajoute un nuplet a la liste de nuplets de la i-eme ComplFace
  //------------------------------------------------------------------------------
  void AppendNuplet(int              i               ,
                    CATTopRibNuplet *iNuplet         ,
                    int              iNumSupp        ,
		    int             *ioNumList  =NULL,
		    int             *ioPosInList=NULL,
		    CATOrientation  *ioOrient   =NULL);

  //------------------------------------------------------------------------------
  // RemoveNup : enleve un nuplet de la liste
  //------------------------------------------------------------------------------
  virtual void RemoveNup(CATTopRibNuplet *iNuplet);

  //------------------------------------------------------------------------------
  // RemoveUnnecessaryExtrRib : tmp xxx
  //------------------------------------------------------------------------------
  void RemoveUnnecessaryExtrRib(int i);

  //------------------------------------------------------------------------------
  // ExportComplementaryFace 
  //------------------------------------------------------------------------------
  void ExportComplementaryFace(int i);

  //------------------------------------------------------------------------------
  // UnExportComplementaryFace 
  //------------------------------------------------------------------------------
  void UnExportComplementaryFace(int i);
  
  //------------------------------------------------------------------------------
  // Check if a given complementary face has been exported
  //------------------------------------------------------------------------------
  CATBoolean HasComplFaceBeenExported(int i);

  //------------------------------------------------------------------------------
  // IsCellOnLink
  //------------------------------------------------------------------------------
  CATLoop* IsCellOnLink(CATCell     *iLinkCell,
                        CATBoolean   iManageLyingOn = 0);
  
  
  //------------------------------------------------------------------------------
  // SetExtrapolationVertex() stocke le vertex d'extrapolation
  // pour que la common edge associee ne soit pas prise en compte 
  //
  // UseCommonEdgeForVertex() renvoie l'info stockee dans la methode ci-dessus
  //------------------------------------------------------------------------------
  void SetExtrapolationVertexAndEdge(CATVertex *iVertex, CATEdge * iEdge);
  CATBoolean UseCommonEdgeForVertex(CATVertex *iVertex, CATEdge * iEdge);

  //------------------------------------------------------------------------------
  // Get all the complementary faces that are bordered by a given cell
  //
  // Please note: if iBorderCell is NULL, all complementary faces are returned
  //------------------------------------------------------------------------------
  void GetAdjComplFaces(CATCell        *iBorderCell,
                        ListPOfCATFace &oComplFaces,
                        CATFace        *iFaceToAvoid = NULL);


  //------------------------------------------------------------------------------
  // Rend la complface la plus "probablement" utile
  //------------------------------------------------------------------------------
  CATFace* GetSortedAdjFace(CATCell        *iBorderCell,
                            ListPOfCATFace &iComplFaces);

  //------------------------------------------------------------------------------
  // Get the next edge and complementary face around a vertex
  //------------------------------------------------------------------------------
  void GetNextEdgeAndFaceAroundVertex(CATVertex  *iVertex,
                                      CATFace    *iFace,
                                      CATEdge    *iEdge,
                                      CATFace   *&oNextFace,
                                      CATEdge   *&oNextEdge);

  /*
  //------------------------------------------------------------------------------
  // Indique si iNuplet est complet
  //------------------------------------------------------------------------------  
  virtual CATBoolean IsComplete(CATRlmNuplet *iNuplet);
  
  //------------------------------------------------------------------------------
  // Ajoute un nuplet a la liste des nuplets poses
  // ? faire la disctinction nuplet et nuplet d'extrapol?
  //------------------------------------------------------------------------------  
  virtual void AddNuplet();

  //------------------------------------------------------------------------------
  // Ajoute un ruban a la liste des rubans contenant au moins un nuplet
  // pose sur la loop
  // ? meme question que pour AddNuplet
  //------------------------------------------------------------------------------  
  virtual void AddRib();

  //------------------------------------------------------------------------------
  // Indique si la surface sur laquelle on repose doit etre extrapolee
  //------------------------------------------------------------------------------  
  virtual CATBoolean HasToBeExtrapolated();

  //------------------------------------------------------------------------------
  // Indique si on doit ajouter une face supplementaire a la liste
  //------------------------------------------------------------------------------  
  virtual CATBoolean HasToBeExtended();
    
  //------------------------------------------------------------------------------
  // Cree une nouvelle face supplementaire
  //------------------------------------------------------------------------------  
  virtual void CreateSupplementaryFace();
  */  

protected:

  //------------------------------------------------------------------------------
  // Re-create the loops from a previous initial face and loop
  //------------------------------------------------------------------------------
  void CreatePrevLoops(CATComplFace *iComplFace,
                       CATFace      *iPrevInitialFace,
                       CATLoop      *iPrevInitialLoop,
                       CATBoolean    iLoopExtToDo,
                       CATListPV*    iOldLoops,
                       CATListPV*    iNewLoops);

  //------------------------------------------------------------------------------
  // ReadSurface from previously set data
  // Please note: the method will generate an error if a surface has
  // already been read
  //------------------------------------------------------------------------------
  void ReadSurface();

  //------------------------------------------------------------------------------
  // Recuperer des supports avec toutes les faces du
  // shell du body qui sont posees sur la meme surface
  //------------------------------------------------------------------------------
  void GetAllFaceSupportsOnSurface(ListPOfCATTopRibSupports &iSupports);

  //------------------------------------------------------------------------------
  // Creation - si besoin - de plusieurs faces complementaires
  // La methode rend TRUE si elle a cree tous les objets CATComplFace
  // necessaires (sinon elle rend FALSE ce qui indique qu'elle n'a
  // cree aucun objet)
  //------------------------------------------------------------------------------
  CATBoolean CreateMultiCompl(CATFace      *iPrevInitialFace = NULL,
                              CATLoop      *iPrevInitialLoop = NULL,
                              CATListPV    *iOldLoops        = NULL,
                              CATListPV    *iNewLoops        = NULL);

  //------------------------------------------------------------------------------
  // Creation  de plusieurs faces complementaires
  // dans le cas ou aucun element de la face initiale (edge ou vertex)
  // n'est pose sur la fermeture de la surface.
  //------------------------------------------------------------------------------
  CATBoolean CreateComplFacesWithoutElementsOnClosureFrontier(int           iNbBoxesOnSurface,
    CATSurLimits *iBoundingBoxes,
    CATListOfInt *iConnectedAreasPerBox,
    CATRelimInit *iRelimInit,
    CATFace      *iPrevInitialFace = NULL,
    CATLoop      *iPrevInitialLoop = NULL,
    CATListPV    *iOldLoops        = NULL,
    CATListPV    *iNewLoops        = NULL);

  //------------------------------------------------------------------------------
  // Creation  de plusieurs faces complementaires
  // dans le cas ou au moins  element de la face initiale (edge ou vertex)
  // est pose sur une (ou plusieurs) fermeture(s) de la surface.
  //------------------------------------------------------------------------------
  CATBoolean CreateComplFacesWithElementsOnClosureFrontier(int           iNbBoxesOnSurface,
    CATSurLimits *iBoundingBoxes,
    CATListOfInt *iConnectedAreasPerBox,
    CATRelimInit *iRelimInit,
    CATFace      *iPrevInitialFace ,
    CATLoop      *iPrevInitialLoop ,
    CATListPV    *iOldLoops        ,
    CATListPV    *iNewLoops        );

  //------------------------------------------------------------------------------
  // Creation d'un objet CATComplFace seul simple
  //
  // Les ioMinUEdge, ioMaxUEdge, ioMinVEdge et ioMaxUEdge constituent
  // des arguments d'entree/sortie optionnels qui definissent (s'il y
  // a lieu) la boucle externe (situee a _MaxLimits) de la face
  // complementaire generee
  // La convention est la suivante
  //
  //  + ----------------------------------------------> u croissant 
  //  |
  //  |               ioMinVEdge
  //  |             +------------->+
  //  |             |              |
  //  |             |              |
  //  |  ioMinUEdge |              | ioMaxUEdge
  //  |             |              |
  //  |             V              V
  //  |             +------------->+
  //  |               ioMaxVEdge
  //  |
  //  V v croissant
  //
  //------------------------------------------------------------------------------
  void CreateSingleCompl(CATFace      *iInitialFace     = NULL,
                         CATLoop      *iInitialLoop     = NULL,
                         CATFace      *iPrevInitialFace = NULL,
                         CATLoop      *iPrevInitialLoop = NULL,
                         CATListPV    *iOldLoops        = NULL,
                         CATListPV    *iNewLoops        = NULL,
                         CATEdge     **ioMinUEdge       = NULL,
                         CATEdge     **ioMaxUEdge       = NULL,
                         CATEdge     **ioMinVEdge       = NULL,
                         CATEdge     **ioMaxVEdge       = NULL);
  
  //------------------------------------------------------------------------------
  // Creation d'un object compl face simpl dans le cas où une (ou plus) des listes 
  // d'edges est sur la fermeture
  // Même convention que dans le cas basique.
  //------------------------------------------------------------------------------
  CATBoolean CreateSingleComplWithMultiEdgeOnFrontier(CATSurLimits   &iBoxLimits,
                                                CATRelimInit   *iRelimInit,
                                                CATFace        *iInitialFace,
                                                CATLoop        *iInitialLoop,
                                                CATFace        *iPrevInitialFace,
                                                CATLoop        *iPrevInitialLoop,
                                                CATListPV      *iOldLoops,
                                                CATListPV      *iNewLoops,
                                                ListPOfCATEdge & iMinUEdge,
                                                ListPOfCATEdge & iMaxUEdge,
                                                ListPOfCATEdge & iMinVEdge,
                                                ListPOfCATEdge & iMaxVEdge);

  //------------------------------------------------------------------------------
  // Calcul des boites d'encombrement des faces a generer:
  // Surface sans fermeture:           1 boite
  // Surface avec une seule fermeture: 2 boites
  // Surface avec deux fermeture:      4 boites
  //
  // La methode rend TRUE si tout s'est bien passe et FALSE sinon
  //
  // La convention de l'ordre des boites est la suivante:
  //
  //           Umin                        Umax
  //      Vmin +-------------+-------------+
  //           |             |             |
  //           |      1      |      2      |
  //           |             |             |
  //           +-------------+-------------+
  //           |             |             |
  //           |      3      |      4      |
  //           |             |             |
  //      Vmax +-------------+-------------+
  //
  //------------------------------------------------------------------------------
  CATBoolean ComputeBoundingBoxes(CATRelimInit &iRelimInit,
                                  double        iTol,
                                  int          &oNbBoxesOnSurface,
                                  CATSurLimits  oBoundingBoxes[4],
                                  CATListOfInt  oConnectedAreasPerBox[4]);

  //------------------------------------------------------------------------------
  // Il vaut mieux selectionner le parametre
  // ideal le plus loin possible des zones connexes
  //------------------------------------------------------------------------------
  void ComputeFarIdealParam(CATBoolean  iOverlap,
                            double      iFirstParam,
                            double      iLastParam,
                            double      iminAbs,
                            double      imaxAbs,
                            double      iTol,
                           CATBoolean  iIsU,
                           double      iparV,
                            double     &ioIdeal);

  //------------------------------------------------------------------------------
  // Create the complementary face(s) that is/are adjacent to the given
  // box limits on the surface
  // The method returns TRUE if it has succeeded, FALSE otherwise
  //------------------------------------------------------------------------------
  CATBoolean CreateComplementaryFacesAtBoxLimits(CATSurLimits &iBoxLimits,
                                                 CATRelimInit &iRelimInit);

  //------------------------------------------------------------------------------
  // Add an element to the list of created elements
  // The method returns the position of the added element
  //------------------------------------------------------------------------------
  int AddCreatedElement(CATTopology *iElement);

  //------------------------------------------------------------------------------
  // Remove an element from the list of created elements
  //------------------------------------------------------------------------------
  void RemoveCreatedElement(CATTopology *iElement);

  //------------------------------------------------------------------------------
  // Remove all elements from the list of created elements starting at
  // a given position
  //------------------------------------------------------------------------------
  void RemoveCreatedElements(int iStartPosition);

  //------------------------------------------------------------------------------
  // Destroy all created elements
  //------------------------------------------------------------------------------
  void DestroyCreatedElements();

  //------------------------------------------------------------------------------
  // Inclusion des Edges de la InsideZone dans la Loop de la Face
  // La methode rend TRUE si tout s'est bien passe, FALSE sinon
  //------------------------------------------------------------------------------
  CATBoolean AddInsideZoneEdgesToLoopOfFace(CATFace        *iComplementaryFace,
                                            ListPOfCATFace &iInitialFaces,
                                            ListPOfCATEdge &iBorderEdges,
                                            int             iFirstEdgeIndex,
                                            int             iLastEdgeIndex);

  //------------------------------------------------------------------------------
  // Cette méthode vérifie que les faces complémentaires créees 
  // n'ont pas d'edges de longueur nulle.
  // Si une des faces compl en a, on détruit l'edge et on merge les vertex 
  //------------------------------------------------------------------------------
  void CheckDegenerateEdge();

  //------------------------------------------------------------------------------
  // Ajout d'une face complementaire simple a une LoopExtension
  // Cadre = extrapolation d'une surface non fermee          
  //------------------------------------------------------------------------------
public:
  CATBoolean AddSupplementaryFace(CATBoolean    *iExtBords,
                                  CATSurLimits  &iOrigMaxLims,
                                  CATSurLimits  &iExtrMaxLims,
                                  CATSurParam   &iRlmSurPar);
protected:
  void       CreateSupplementaryFace(CATFace      *iSupplFace);   

  //-----------------------------------------------------------------------------
// Creation d'une face carree basee sur une surface et des Umin/max, Vmin/max
// La face peut integrer des edges existantes
// La surface ne doit pas etre close (on travaille dans le cadre des 
// complementaires)
//-----------------------------------------------------------------------------

protected:
  CATFace* CreateSquareFace(CATBody                  *iBody,
                            CATSoftwareConfiguration *iConfig,
                            CATSurface               *iSurf,
                            CATSurLimits             &iSurLim,
                            CATOrientation            iOriFacSur, // ori fac vs surf
                            CATEdge                  *iEdge,
                            CATBordType               iType);
  void AddEdgeGeoTop       (CATFace                  *iFace,
                            CATEdge                  *iEdge, 
                            CATOrientation           &oEdgeOri);
  void CreateEdgeGeoTop    (CATBordType               iBordType,
                            CATFace                  *iFace,
                            CATSurLimits             &iSurLim,                                        
                            CATEdge                 *&oEdge,
                            CATOrientation          &oEdgeOri);

          
protected:
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  CATBody                      *_CreationBody;
  CATShell                     *_InitialShell;
  CATFace                      *_InitialFace;
  CATLoop                      *_InitialLoop;
  CATLocation                   _InitialLoopLocation;
  CATSoftwareConfiguration     *_SoftwareConfiguration;
  CATSurface                   *_Surface;
  CATBoolean                    _SurfaceIsUClosed;
  CATBoolean                    _SurfaceIsVClosed;
  CATSurLimits                  _MaxLimits;
  CATOrientation                _OrientationVsSurface;
  ListPOfCATComplFace           _ComplFaces;
  ListPOfCATTopology            _CreatedElements;
  //CATComplFace                 *_ComplFace;       // pour le moment...
  //ListPOfCATFace                _SupplFaces;      // liste des faces rajoutees 
  // cf. franchissement fermeture, ou extrapol en cours de relim, ...
  ListPOfCATTopRibNuplets       _Nups;
  CATLONG32                     _UseCount;                   // partage des donnees      
  CATVertex                    *_SpecialExtrapolationVertex; // Pour traitement specifique sur vertex d'extrapolation
  CATEdge                      *_SpecialEdge;
  ListPOfCATFace                _ComplFaceAdjInitialFace;

  CATBoolean                    _Conical;
  CATBoolean                    _VersLooExtForCone;
  CATRibTopOp                  *_RibTopOp;
  int                           _ComplFix2;
  int                           _ComplDbg; 
  CATTwistAnalysis             *_TwistAnalyst;

  CATBoolean                    _SplitAllLoops;
  CATBoolean                    _SpcConfused;

  CATMemVertMerger             *_MVMerger;

  /* Ds CATTopRib:
  CATTopRib                   **_ExtrapolationEdgeRibbon;
  CATTopRibSign                *_ExtrapolationDirection;
  CATSide                      *_ExtrapolationEdgeSide;
  CATCell                     **_ExtrapolationContactCell;
  CATBoolean                   *_ContactCellIsValid;
  StateOfNuplet                *_State;
  */
  // Et maintenant : on degage l'info "par support" [une * en moins]
  // + on vire la validite de la cellule [inutile]
  // On a donc les listes synchonnisees avec _Nups 
/* Perfo : FDS , je vire ces liste inutiles
  CATListPV                     _ExtrRibs[2];         // Un par direction pour chaque nuplet de _Nups
  CATListPV                     _ExtrDirs[2];         // idem
  CATListPV                     _ExtrSides[2];        // idem
  CATListPV                     _ExtrContactCells[2]; // idem
  CATListPV                     _NupStates[2];        // idem
  CATListPV                     _RlmRibs;             // liste des differents rubans des _Nups
*/
                                                      // NB: liste non synchrone avec _Nups
  // NB: On ne veut pas avoir d'indices a gerer : on recherchera le nuplet dans le ruban
  // adhoc, eventuellement avec une liste donnant pour un nuplet son ruban

  CATSurLimits                  _ResExtrLimits;
  CATBoolean                    _ResExtrAvailable;

  friend class CATAdvLoopExtension;
};

//------------------------------------------------------------------------------
//                               INLINE
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// GetNbComplFace
//------------------------------------------------------------------------------
INLINE int CATLoopExtension::GetNbComplFaces()
{
  return _ComplFaces.Size();
}

//------------------------------------------------------------------------------
// GetComplFace
//------------------------------------------------------------------------------
INLINE CATComplFace* CATLoopExtension::GetComplFace(int i)
{
  return _ComplFaces[i];
}

//------------------------------------------------------------------------------
// GetInitialLoop
//------------------------------------------------------------------------------
INLINE CATLoop* CATLoopExtension::GetInitialLoop()
{
  return _InitialLoop;                 
}


//------------------------------------------------------------------------------
// Get the ComplementaryFace adjacent to the initial loop
//------------------------------------------------------------------------------
INLINE CATFace * CATLoopExtension::GetComplFaceAdjInitialFace(int iCmplFace)
{
  return _ComplFaceAdjInitialFace[iCmplFace];
}

//------------------------------------------------------------------------------
// Get the number of complementary faces adjacent to the initial loop
//------------------------------------------------------------------------------
INLINE int CATLoopExtension::GetNbComplFaceAdjInitialFace()
{
  return _ComplFaceAdjInitialFace.Size();
}


#endif 
