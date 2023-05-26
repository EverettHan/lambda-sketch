/* -*-C++-*- */

#ifndef CATTopRibTool_H
#define CATTopRibTool_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibTool: Classe definissant un outil pour le ruban topologique
// -------------
//
//===================================================================

//===================================================================
// Usage notes:
// -----------
//
//   Un outil sert a determiner le manifold de reference pour chacun    
//   des appuis. Par derivation, il peut servir a contenir les   
//   caracteristiques de l'operation en cours: Fillet, Draft, ....
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
//===================================================================
//===================================================================

#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"
#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATListPV.h"
#include "ListPOfCATSupContact.h"
#include "CATListOfInt.h"
#include "CATMathInline.h"

class CATBody;
class CATVertex;
class CATEdge;
class CATFace;
class CATLoop;
class CATVertexIterator;
class CATXParam;
class CATSupContact;
class CATTopRibNuplet;
class CATTopRibGeoNuplet;
class CATTopRibNupletCand;
class CATTopRibSupport;
class CATTopRibTool;
class CATTopRibMacroTool;
class CATMathDirection;
class CATMathBox;
class CATSurface;
class CATSurLimits;
class CATLoopExtension;

class CATTopologicalOperator;

#include "CATSafe.h"
CATSafeDefine(CATTopRibTool);

class ExportedByRIBLight CATTopRibTool  : public CATTopRibObject
{
 public:

  //------------------------------------------------------------------------------
  // Constructor 
  //------------------------------------------------------------------------------
  CATTopRibTool(CATTopRibMacroTool       * iMacroTool,
                CATBody * const            iCreationBody,
		            const ListPOfCATBody     & iSupportBodies,
		            const ListPOfCATDomain   & iSupportDomains);

  //------------------------------------------------------------------------------
  // Destructor 
  //------------------------------------------------------------------------------
  virtual ~CATTopRibTool();

  //------------------------------------------------------------------------------
  // Data access
  //------------------------------------------------------------------------------
  INLINE CATTopRibMacroTool* GetMacroTool() const ;
  INLINE CATBody*            GetCreationBody() const ;
  INLINE CATDomain*          GetSupportDomain(const int iNumSupp) const; // Safe

  //------------------------------------------------------------------------------
  // Donne le nombre d'elements d'appui 
  //------------------------------------------------------------------------------ 
  virtual int GetNbRollingSupp();

  //------------------------------------------------------------------------------
  // Donne le nombre d'elements guide 
  //------------------------------------------------------------------------------ 
  virtual int GetNbGuideSupp();

  //------------------------------------------------------------------------------
  // Donne le nombre de supports (guide+rolling)
  //------------------------------------------------------------------------------ 
  virtual int GetNbSupports();

  //------------------------------------------------------------------------------
  // Donne la position du ieme element rolling (entre 1 et nombre de supports)
  // 0 si il n'y a pas de rolling
  //------------------------------------------------------------------------------ 
  virtual int GetPosRolling(int iRolling);

  //------------------------------------------------------------------------------
  // Donne la position du guide
  // erreur si il n'y a pas de guide
  //------------------------------------------------------------------------------ 
  virtual int GetPosGuide(int iGuide);

  //------------------------------------------------------------------------------
  // Get the index of the support that is supposed to have a large enough uv-box
  //------------------------------------------------------------------------------
  virtual CATLONG32 GetIndexOfSupportWithBigBox();

  //------------------------------------------------------------------------------
  // Nuplet precedent
  //------------------------------------------------------------------------------
  virtual void      SetPrevNuplet(CATTopRibNuplet * iPrevNuplet);
  CATTopRibNuplet * GetPrevNuplet();

  //------------------------------------------------------------------------------
  // Answers whether ExtraNuplet must be created after PrevNuplet
  //------------------------------------------------------------------------------
  virtual CATBoolean MustCreateExtraNuplet();

  //------------------------------------------------------------------------------
  // Regarde si on peut utiliser la solution du Nuplet precedent
  //------------------------------------------------------------------------------
  virtual CATTopRibGeoNuplet * ReUsePrevSol(CATTopRibNuplet * iNupletToCompute);

  //------------------------------------------------------------------------------
  // Blanchit l'outil pour preparer sa reutilisation 
  //------------------------------------------------------------------------------
  virtual void Clear();

  //------------------------------------------------------------------------------
  // Clears the vertex iteraotr and related data
  //------------------------------------------------------------------------------
  void ClearVertexIterator();

  //------------------------------------------------------------------------------
  // Create a new Nuplet
  // NB: This method needs to be defined for each derived class!
  //------------------------------------------------------------------------------
  virtual CATTopRibNuplet *CreateNuplet () = 0;

  //------------------------------------------------------------------------------
  // Clone a Nuplet  
  //------------------------------------------------------------------------------
  CATTopRibNuplet *CloneNuplet(CATTopRibNuplet * iNuplet);

  //------------------------------------------------------------------------------
  // Clone a GeoNuplet (the clone will have the SAME geometry)  
  //------------------------------------------------------------------------------
  virtual CATTopRibGeoNuplet *CloneGeoNuplet(CATTopRibGeoNuplet * iGeoNuplet) = 0;

  //------------------------------------------------------------------------------
  // Create a new Nuplet and set the supports 
  //------------------------------------------------------------------------------
  CATTopRibNuplet *CreateNuplet(CATTopRibSupport** iTabSupport, const int iNbSupp);

  //------------------------------------------------------------------------------
  // Create a new N-uplet Candidate
  //------------------------------------------------------------------------------
  virtual CATTopRibNupletCand * CreateNupletCand(CATTopRibSign iDirection, CATTopRibNuplet * iNuplet);
  //------------------------------------------------------------------------------
  // Get access to existing Candidates list
  //------------------------------------------------------------------------------
  CATTopRibNupletCand* GetCandidates(const CATTopRibSign iDirection) const;

  //------------------------------------------------------------------------------
  // Optimisation performances: renvoie FALSE si, compte tenu des specs de l outil
  // et des boxes des supports, il n y a aucune solution geometrique.
  // Se base sur l'encombrement des supports
  // En cas de doute, rend TRUE
  //------------------------------------------------------------------------------ 
  virtual CATBoolean DoBoxesIntersect(int                iNbSupports,
                                      CATTopRibSupport * iSupportArray[]); 


  //------------------------------------------------------------------------------
  // Optimisation performances: calcule une boite d'encombrement correspondant a 
  // une zone utile suffisamment grande pour contenir le ruban a calculer.
  //------------------------------------------------------------------------------ 
  virtual CATMathBox * ComputeWorkingBox();

  //------------------------------------------------------------------------------
  // Renvoie la liste d'egdes communes a deux cellules. L'interet de cette methode 
  // au niveau du tool est d'eviter de calculer a plusieurs reprises cette liste
  // pour les supports du nuplet courant. 
  //
  // Attention: La liste renvoyee est propriete du tool
  // ---------
  //
  // Arguments optionnels : iDomainLeft et/ou Right : Si aucune cellule commune n'est trouvee, on regarde
  //                                                  si on n'en trouve pas une commune avec une face voisine 
  //                                                  sur le meme fond et dans le meme domaine.
  //                                                  La cellule commune rendu aura forcement au moins une des deux
  //                                                  cellules donnees comme federatrice.
  //------------------------------------------------------------------------------
  virtual ListPOfCATCell * GetCommonCells(CATCell * iLeftCell, CATCell * iRightCell,
                                          CATBody * iLeftBody=0, CATDomain * iLeftDomain=0,
                                          CATBody * iRightBody=0, CATDomain * iRightDomain=0); 

  //------------------------------------------------------------------------------
  // Methode indiquant si l'on doit decouper les edges fermees en deux. Cette 
  // method est une bidouille pour by-passer des regressions draft a traiter 
  // asap 9jgd: le 21/5/99
  //------------------------------------------------------------------------------
  virtual CATBoolean CutClosedEdge();

    //------------------------------------------------------------------------------
  // Get the number of cutting edges lying on a face.
  //------------------------------------------------------------------------------
  int GetNbCuttingEdges(CATFace * iSupportFace);

  //------------------------------------------------------------------------------
  // Get a given cutting edges lying on a face.
  //------------------------------------------------------------------------------
  CATEdge * GetCuttingEdge(CATFace   * iSupportFace,
                           int         iNumCutting,                             
	                   CATSide   * oSideToKeep=NULL,
                           CATBoolean* oFullSideAccepted=NULL);  
  
  //------------------------------------------------------------------------------
  // Indique si une edge est coupante sur une face 
  //------------------------------------------------------------------------------
  CATBoolean IsACuttingEdge(CATFace * iFace,
                            CATEdge * iEdge,
                            CATSide & oSide);
  
  //-----------------------------------------------------------------------------
  // Cherche les cellules bordees par un vertex (edges et faces) et les rend de 
  // maniere ordonnee.
  // L'ordre peut etre impose en passant une edge et une face. Dans ce cas on rend
  // dans la liste d'edge les edges qui servent a la transition vers de nouvelles 
  // faces, et dans la liste des faces ces nouvelles faces. En premier on trouvera 
  // l'edge donne et la face qui lui est directement adjacente. En second dans la 
  // liste d'edge on aura l'edge adjacente au vertex sur la nouvelle face ...
  // Les faces sont donnees shell par shell. Lorsque l'on passe sur un nouveau 
  // shell, on retrouve juste avant la face initiale. 
  // Lorsque l'on tombe sur un bord libre, et si la variable StopOnFreeEdge est a 
  // false, on revient sur la face initiale et l'on itere dans l'autre sens de
  // maniere a etre sur de ne rater aucune face.   
  //-----------------------------------------------------------------------------
  // Le resultat de la methode est bufferise et est nettoye par Clear 
  // (y compris le VertexIterator).
  // Le VertexIterator correspondant est accessible en valeur de retour
  // ( mais il reste la propriete de ce Tool ).
  //-----------------------------------------------------------------------------
  CATVertexIterator* GetAdjacentCells(CATBody* iBody,
                                      CATVertex* iVertex,
                                      CATBoolean iCheckSameEdgeAndFace,
                                      CATEdge* iFirstEdge,
                                      CATFace* iLastFace,
                                      CATBoolean iStopOnFreeEdges,
                                      int iSuppIndex,
		                                  ListPOfCATEdge & oAdjEdges,
		                                  ListPOfCATFace & oAdjFaces,
                                      CATLoopExtension * iLoopExtension = NULL);  // optional

  //------------------------------------------------------------------------------
  // Inverse la liste des cellules adjacentes a un vertex.
  //------------------------------------------------------------------------------
  void InvertAdjacentCells(int iFirst=1);

  //------------------------------------------------------------------------------
  // Ferme la liste des cellules adjacentes a un vertex.
  //------------------------------------------------------------------------------
  void CloseAdjacentCells(int iFirst, CATTopologicalOperator & iTopOp);

  //------------------------------------------------------------------------------
  // Find the adjacent Faces to an Edge
  //------------------------------------------------------------------------------
  void GetAdjacentCells(CATBody          * iBody,
                        CATEdge          * iEdge,    
                        CATFace          * iLastFace,
                        ListPOfCATEdge   & oAdjEdges,
                        ListPOfCATFace   & oAdjFaces,
                        CATLoopExtension * iLoopExtension = NULL); // optional

  //------------------------------------------------------------------------------
  // Specifie le tableau de contact init (Les tableaux deviennent propriete de this).
  // Les tableaux sont detruits en cas d erreur, les pointeurs sont alors mis a NULL.
  //------------------------------------------------------------------------------
  int SetInitContact(CATSupContact    * iInitContact[],
                     CATMathDirection * iInitTgt[] = NULL);

  //------------------------------------------------------------------------------
  // Acces aux contacts init.
  //------------------------------------------------------------------------------
  CATSupContact * GetInitContact(CATMathDirection ** oInitTgt=NULL);
  
  //------------------------------------------------------------------------------
  // Specifie un tableau de contact exit (Le tableau devient propriete de this).
  // iStatus vaut 1 si l'on est sur que le contact est une exit, 0 sinon. Arrive 
  // dans les cas de signature inconnue.
  //------------------------------------------------------------------------------
  int SetExitContact(CATSupContact iExitContact[], int iStatus=1);

  //------------------------------------------------------------------------------
  // Nombre de contacts pouvant peut etre servir comme exit a priori. 
  //------------------------------------------------------------------------------
  virtual int GetNbExitContact(); 

  //------------------------------------------------------------------------------
  // Nombre de contacts valides topologiquement mais pas mathematiquement
  //------------------------------------------------------------------------------
  int GetNbNotValidMathContact();

  //------------------------------------------------------------------------------
  // Met a jour les vertex exit 
  //------------------------------------------------------------------------------
  void UpdateExit(CATVertex * iOldVertex, 
                  CATVertex * iNewVertex,
		  int         iDimension);

  //------------------------------------------------------------------------------
  // Acces aux contacts init/exit
  //
  // iNumContact varie de 0 a GetNbExitContact. 0 pour acceder au contact init, 
  // ensuite pour acceder aux contacts devant servir d'exit.
  //
  // Si le booleen oKeepVertices est passe en argument, on indique en sortie 
  // si les vertex peuvent etre detruits ou pas 
  //------------------------------------------------------------------------------
  CATBoolean GetContacts(int               iNumContact,
                         CATTopRibSign     iDirection,
                         CATTopRibNuplet * iNextNuplet,
                         CATSupContact     oContact [],
                         CATBoolean      * oKeepVertices=NULL); 

  //------------------------------------------------------------------------------
  // Qualite d'un contact au sens validite
  // 
  //  * topo: iValidTopo 
  // 
  //  * mathematique: iValidMath
  //
  //  * init/exit: iStatus
  // 
  // Si iNumSol vaut 0, il s'agit de l'init. Sinon iNumSol est un numero d'init 
  // de bonne qualite
  //------------------------------------------------------------------------------

  void SetTopQuality (int iNumSol, CATBoolean iValidTopo);
  void SetMathQuality(int iNumSol, CATBoolean iValidMath);
  void SetSingular   (int iNumSol, CATBoolean iSingular);
  void SetStatus     (int iNumSol, CATBoolean iStatus);
  void GetQuality    (int         iNumSol   , CATBoolean &oValidTopo, 
                      CATBoolean &oValidMath, CATBoolean &oSingular,
                      CATBoolean &oStatus   );

  //------------------------------------------------------------------------------
  // Add a cell to the be removed
  //------------------------------------------------------------------------------

  //------------------------------------------------------------------------------
  // Remove a cell from the cells to remove
  //------------------------------------------------------------------------------

  //------------------------------------------------------------------------------
  // Donne le cote matiere a garder d'un support 
  //------------------------------------------------------------------------------
  CATSide GetSideToKeep(int iNumSupp);

  //------------------------------------------------------------------------------
  // Methode indiquant si on peut demander l'extrapolation des surfaces supports
  // lors de l'extension des boites UV dans ComputeNuplets (avant le calcul des
  // des traces geometriques):
  // Ceci sert dans l'intersection; par defaut on n'extrapole pas
  //------------------------------------------------------------------------------
  virtual CATBoolean QueryExtrapolSupportSurface(int iSupportIndex);

  //------------------------------------------------------------------------------
  // Rajoute iSurface et iOldLimits a leurs listes respectives si
  // 1) le MacroTool est actif pour la sauvegarde des surfaces
  // 2) iSurface n'est pas deja presente ds la liste
  // 3) Les nouvelles MaxLimits sont superieures a iOldLimits
  // La methode renvoie 1 si l'ajout a ete fait, 0 sinon.
  //------------------------------------------------------------------------------
  int AddExtrSurfAndLimits(CATSurface    *iSurface,
                           CATSurLimits  &iOldLimits);

  //------------------------------------------------------------------------------
  // Acces en lecture et ecriture aux parametres des contacts
  //------------------------------------------------------------------------------
  CATXParam* GetContactXParam(const int iNumSol, const int iNumSupp) ;
  CATXParam* GetContactXParam(const int iNumSol) ; // Renvoie le tableau

  //------------------------------------------------------------------------------
  // Indique si la cellule fournie en entree est un candidat admissible comme
  // LinkCell.
  //------------------------------------------------------------------------------
  CATBoolean IsGoodLinkCell(CATCell *iCell);
  
  //------------------------------------------------------------------------------
  // Get/Set du CurrentRibDepthLevel
  //------------------------------------------------------------------------------
  int GetCurrentRibDepthLevel();  
  void SetCurrentRibDepthLevel(int iCurrentRibDepthLevel);

  void SetInitContactIsOut(int iSupp, CATBoolean iIsOutInit);
  CATBoolean GetInitContactIsOut(int iSupp);
  void SetNeedUVSwitch(int iSupp, CATBoolean iNeedUVSwitch);
  CATBoolean GetNeedUVSwitch(int iSupp);

  
  protected:
  //------------------------------------------------------------------------------
  // Remplit si possible les contacts a partir d'un nuplet dont on cherche
  // les traces et d'un nuplet precedent. Renvoie true si ok, false sinon
  //------------------------------------------------------------------------------
  virtual CATBoolean BuildContacts(CATTopRibNuplet * iPrevNuplet,
                                   CATTopRibNuplet * iNextNuplet,
		                   CATTopRibSign     iDirection,			
                                   CATSupContact     oContact []);

  //------------------------------------------------------------------------------
  // Met a jour la qualite d'un type 
  //------------------------------------------------------------------------------
  void UpdateQuality(int iNumContact, int iQualityType);
  int  GetQuality(int iNumSol);


  //------------------------------------------------------------------------------
  // Update creation body
  //------------------------------------------------------------------------------
  public:
  virtual void UpdateWithNewBody(CATBody *iOldBody, CATBody *iNewBody);

  //------------------------------------------------------------------------------
  // Find out if the touch flags of the supports shoould be modified
  //------------------------------------------------------------------------------
  public:
  CATBoolean QueryDoTouch();

  //------------------------------------------------------------------------------
  // Set the need for updating the touch flags on the shells
  //------------------------------------------------------------------------------
  public:
  void SetNeedForUpdateTouchOnShells(CATBoolean iUpdateTouchOnShellsIsNeeded);

  //------------------------------------------------------------------------------
  // Is it necessary to update the touchg flags on the shells?
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsUpdateTouchOnShellsNeeded();

  CATBoolean IsSelfRlmRibSingularCase();
  void SetSelfRlmRibSingularCase( CATBoolean sing = FALSE );
  //------------------------------------------------------------------------------
  // Data 
  //------------------------------------------------------------------------------  
  public : // A remplacer par protected: ..! 

  CATBody                *       _CreationBody;  // Body de creation 
  const ListPOfCATBody   &       _SupportBodies; // Body de chacun des appuis 
  const ListPOfCATDomain         _SupportDomains;// Domain de chacune des cellules d'init 

  protected:
  CATTopRibMacroTool     *       _MacroTool;     // Macro tool de relimitation   

  private:
  CATSupContact          *       _InitContact;   // Contacts servant pour l'init
  CATMathDirection       *       _InitTgt;       // Tangentes servant pour l'init
  ListPOfCATSupContact   *       _ExitContacts;  // Liste de contacts servant pour l'exit 
  CATListOfInt           *       _StatusOfExits; // Statut des exits
  int                            _NbExitContact; // Nb de contacts pouvant servir pour l'exit
 // ListPOfCATCell                 _CellsToRemove; // Cells that have been created without updating
  CATTopRibNuplet        *       _PrevNuplet;    // Nuplet "precedent" celui que l'on calcule
  CATBody                *      _AdjBody;
  CATVertex              *      _AdjVertex;
  CATEdge                *      _AdjFirstEdge;           
  CATFace                *      _AdjLastFace;
  CATVertexIterator      *      _AdjVertexIterator;
  CATBoolean                    _StopOnFreeEdges;
  ListPOfCATEdge                _AdjEdges;
  ListPOfCATFace                _AdjFaces;
  CATXParam              *      _ContactParams;       // Tableau de XParam contenant les parametres des contacts
  int                           _ContactParamsSize;   // Taille allouee
  CATListOfInt                  _InitContactIsOut;

  CATBoolean					_SelfRlmRibSingularCase; // Requried to indicate that the creation should use generic march

  ListPOfCATCell _LeftCells;  // Celulles de gauche dont on connait les edges communes 
  ListPOfCATCell _RightCells; // Celulles de droite dont on connait les edges communes 
  CATListPV      _ListOfLPCC; // liste de cellules communes pour chacun des couples asscies aux liste ci-dessus
};

//------------------------------------------------------------------------------
// INLINE methods
//------------------------------------------------------------------------------
// Safe MacroTool, CreationBody, SupportDomain Access
//------------------------------------------------------------------------------
INLINE CATTopRibMacroTool* CATTopRibTool::GetMacroTool   () const  // Safe
//------------------------------------------------------------------------------
{
  if ( NULL==_MacroTool ) CATThrowForNullPointerReturnValue(NULL);
  return     _MacroTool  ;   
}
//------------------------------------------------------------------------------
INLINE CATBody* CATTopRibTool::GetCreationBody() const // Safe
//------------------------------------------------------------------------------
{ 
  if ( NULL==_CreationBody ) CATThrowForNullPointerReturnValue(NULL);
  return     _CreationBody  ; 
} 
//------------------------------------------------------------------------------
INLINE CATDomain* CATTopRibTool::GetSupportDomain(const int iNumSupp) const // Safe
//------------------------------------------------------------------------------
{
  CATDomain* Domain = _SupportDomains[iNumSupp];
  if ( NULL==Domain ) CATThrowForNullPointerReturnValue(NULL);
  return     Domain  ; 
}
#endif
