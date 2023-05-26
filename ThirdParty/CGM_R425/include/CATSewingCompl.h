/* -*-C++-*- */

#ifndef CATSewingCompl_H
#define CATSewingCompl_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//-----------------------------------------------------------------------------
// Janv.98    Creation                                       Francois Dujardin
//            Responsable                                    Pascal Rossignol
//-----------------------------------------------------------------------------
class CATLoopExtension;

#include "RibbonLight.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "CATCGMNewArray.h"

class CATLoop;

//-----------------------------------------------------------------------------
//
// CATSewingCompl
// Classe pour ajouter des faces complementaires (ajout de matiere)
//
// contient : la liste des faces initiales
//            la liste des faces complementaires
//            la liste des loops complementaires
//            la liste de listes d'aretes coupantes sur la face complementaire
//            la liste de listes de side 
//            la liste des aretes de ruban d'extrapolation à ne pas simplifier
// Rem : Toutes ces listes sont en phase
//-----------------------------------------------------------------------------
#include "CATSafe.h"
CATSafeDefine(CATSewingCompl);

class ExportedByRibbonLight CATSewingCompl
{

  private :   
  //-------

  // donnees  
  ListPOfCATFace   _InitialFace;
  ListPOfCATFace   _ComplementaryFace;
  ListPOfCATDomain _ComplementaryLoop;
  CATListPV        _CuttingEdges;
  CATListPV        _RefSides;
  CATListPV        _AllocatedCuttingEdges;
  CATListPV        _AllocatedRefSides;
  CATListOfInt     _IniComplLink; //indicates whether a complementary face is
                                  // connected to the loop of the initial face
  CATListOfInt     _NbComplFacesInLoopExtension;
  ListPOfCATEdge   _ExtrEdgeNoSimplif;
  ListPOfCATEdge   _EdgesToRelease;

  // Assignment operator. Not implemented
  CATSewingCompl& operator=(const CATSewingCompl &x);

  // Copy constructor. Not implemented
  CATSewingCompl(CATSewingCompl &iSewingCompl);

  void AddEdgeForAddRefAndRelease(CATEdge* iEdge);
  void AddEdgeForAddRefAndRelease(ListPOfCATEdge& iListEdges);
  void RemoveEdgeForAddRefAndRelease(CATEdge* iEdge);
  void RemoveEdgeForAddRefAndRelease(ListPOfCATEdge& iListEdges);

  public :
  //------

  // Constructeur
  CATSewingCompl();
  CATCGMNewClassArrayDeclare; // Pool allocation

  // Destructeur
  ~CATSewingCompl();
  
  // Nombre de complementary faces
  int GetNbCompl();

  // Get initial face
  CATFace *GetInitialFace(int iNumCompl);

  // Get complementary face
  CATFace *GetComplementaryFace(int iNumCompl);

  // Get complementary loop
  CATLoop *GetComplementaryLoop(int iNumCompl);

  // Get cutting edges
  ListPOfCATEdge *GetCuttingEdges(int iNumCompl);

  // Get ref. sides
  CATListOfInt *GetRefSides(int iNumCompl);

  // Get a CATBoolean that indicates whether a complementary
  // face is connected to the loop of the initial face
  CATBoolean GetIniComplLink(int iNumCompl);

  // Get the number of complementary faces in
  // the current initial face's loop extension
  int GetNbComplFacesInLoopExtension(int iNumCompl);

  // Locate an initial face
  int LocateInitialFace(CATFace *iInitialFace);

  // Locate a complementary face
  int LocateComplementaryFace(CATFace *iComplementaryFace);

  // Set initial face
  void SetInitialFace(int      iNumCompl,
                      CATFace *iInitialFace);

  // Set complementary face
  void SetComplementaryFace(int      iNumCompl,
                            CATFace *iComplementaryFace);

  // Set complementary loop
  void SetComplementaryLoop(int      iNumCompl,
                            CATLoop *iComplementaryLoop);

  // Add an initial face
  void AddInitialFace(CATFace *iInitialFace);

  // Add a complementary face
  void AddComplementaryFace(CATFace *iComplementaryFace);

  // Add a complementary loop
  void AddComplementaryLoop(CATLoop *iComplementaryLoop);

  // Add a list of cutting edges
  void AddCuttingEdges(ListPOfCATEdge *iCuttingEdges);

  // Add a list of cutting edges to a given location in the list
  void AddCuttingEdges(int             iNumCompl,
                       ListPOfCATEdge *iCuttingEdges);

  // Add a list of ref. sides
  void AddRefSides(CATListOfInt *iRefSides);

  // Add a list of ref. sides to a given location in the list
  void AddRefSides(int           iNumCompl,
                   CATListOfInt *iRefSides);

  // Add a CATBoolean that indicates whether a complementary
  // face is connected to the loop of the initial face
  void AddIniComplLink(CATBoolean iIniComplLink);

  // Add the number of complementary faces in
  // the current initial face's loop extension
  void AddNbComplFacesInLoopExtension(int iNbComplFacesInLoopExtension);

  // Ajout d'un bloc complementaire dans la liste, sauf si il y est deja
  // facultatif : on peut aussi donner l'edge coupante 
  // Rend la position du bloc (nouveau ou pas)
  int AddComplFace(CATLoopExtension & LoopExt,
                   int                iComplFaceIndex,
                   CATEdge          * Edge    = NULL,
                   CATSide            iRefSide= CATSideUnknown);

  // Retire une arete coupante et meme le bloc complementaire tout entier
  // si c'est la seule (auquel cas la methode retourne TRUE
  CATBoolean RemoveEdge(CATEdge          * Edge,
                        CATLoopExtension & LoopExt,
                        int                iComplFaceIndex);

  // Appel a RemoveEdge sur les edges de iListOfEdges qui sont des cuttingedges
  // si trouvees sur une seule liste
  CATBoolean RemoveCuttingEdgesIfSharedOnce(ListPOfCATEdge *iListOfEdges);

  // Indique si l'edge entree est presente dans _CuttingEdges
  CATBoolean IsSharedByCuttingEdges(CATEdge * Edge);
  
  // Indique si au moins une des edges de la liste entree est presente dans _CuttingEdges
  CATBoolean IsSharedByCuttingEdges(ListPOfCATEdge * ListOfEdges);

  // Ajout d'une edge de ruban d'extrapolation à ne pas simplifier
  void AddExtrEdgeNoSimplif(CATEdge *iEdge);

  // Recupere liste edges de ruban d'extrapolation à ne pas simplifier
  void GetExtrEdgeNoSimplif(ListPOfCATEdge & oListNoSimplif);

};
  
#endif






