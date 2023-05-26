/* -*-C++-*- */

#ifndef TopoUtilitiesForLight_H
#define TopoUtilitiesForLight_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//=============================================================================
//=============================================================================
//
// TopoUtilitiesForLight : Regroupement des utilitaires qui se retrouveront
//                         dans TopologicalOperatorsLight en R201+
//
//=============================================================================

//=============================================================================
// Dec  2006  Creation                                                    PRL
//=============================================================================
//=============================================================================

// Export
#include "TopUtilLight.h"

// Config et GeoFac
class CATSoftwareConfiguration;
class CATTopData;
class CATGeoFactory;

// Macros
#include "CATTopDefine.h"
#include "CATTopDef.h"

// Topolo
class CATVertex;
class CATEdge;
class CATFace;
class CATBody;
class CATShell;
class CATWire;

// Util NewTopo
class CATVertexIterator;

// Geo
#include "CATMathPlane.h"

// Listes
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATPointOnEdgeCurves.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"


//------------------------------------------------------------------------------
// Rend le vertex commun aux deux Edges specifiees en entree s'il existe
// et rend NULL sinon.
//
// NB: 1) iDirectionOnEdge1 permet de ne verifier que l'un des deux vertex
//        bord de iEdge1: Forward -> vertex fin
//                        Backward -> vertex debut
//     2) L'argument optionnel oSecondCommonVertex permet de recuperer - le
//        cas echeant - l'autre vertex commun entre les deux aretes (uniquement
//        possible si iDirection == UnknownDirection
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATVertex* GetSharedVertex (CATEdge         *iEdge1,
                                                   CATEdge         *iEdge2,
                                                   CATTopSign       iDirectionOnEdge1   = UnknownDirection,
                                                   CATVertex      **oSecondCommonVertex = NULL);


//------------------------------------------------------------------------------
// Rend le vertex extremite de iEdge qui n'est pas iVertex
// NB: sort en erreur si iVertex n'est pas extremite de iEdge
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATVertex* GetOtherVertex (CATEdge         *iEdge,                                             
                                                  CATVertex       *iVertex);         

//------------------------------------------------------------------------------
// Rend si elle existe l'arete adjacente a iEdge partageant le sommet iVertex
// et situe dans la meme loop que iEdge.
// Rend NULL si non trouvee.
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATEdge* GetAdjEdge (CATEdge         *iEdge,
                                            CATVertex       *iVertex,
                                            CATFace         *iFace,
                                            CATBoolean       iChkDur = TRUE);           

//---------------------------------------------------------------------------
// Retourne la face adjacente a iEdge qui appartient au Shell de iFace
// et qui n'est pas iFace
// ATTENTION: on suppose qu'on n'a pas d'arete bord libre!
//---------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATFace* GetAdjFace (CATEdge         *iEdge,
                                            CATFace         *iFace,
                                            CATBody         *iBody,
                                            CATShell        *iShell = NULL);

//---------------------------------------------------------------------------
// Cree une sorte de loop  (i.e. une liste ordonnee d'edge) pour une face 
// donnee.
// Attention : si la face possede des loops internes, on rend une seule
// liste ordonnee d'aretes et la liste parallele oNumLoop permet de savoir
// a quelle loop appartient une arete de la liste.
// Note : signature correcte sans copie de liste , remplace le service suivant
//---------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight void GetPseudoLoop(CATFace        *iFace,
										                      ListPOfCATEdge &oEdgesList,
                                          CATListOfInt   *oNumLoop = NULL,
                                          int            *oNbLoops = NULL,
                                          CATListOfInt   *oSide    = NULL);

//---------------------------------------------------------------------------
// Donne l'arete suivante d'une arete dans la liste creee par GetPseudoLoop
// et dans le sens precise (i.e. en gardant la matiere a droite ou a gauche
// pendant le parcours).
// NB: on rend tjs la suivante dans la CATLoop de l'arete donnee en entree
//     et on n'a plus la notion de premiere arete
//---------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATEdge* GetNextInPseudoLoop(CATEdge        *iEdge,
                                                    ListPOfCATEdge *iBddEdges,
                                                    CATListOfInt   *iNumLoop,
                                                    int             iNbLoops,
                                                    CATSide         iSide);

//------------------------------------------------------------------------------
// Service encapsulant la prise en compte de la config - 
//                                                      modif R17 car Header CAA
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATVertexIterator* CreateRadialIterator(CATVertex*  iVertex,
                                                               CATBody*    iBody,
                                                               CATTopData* iData);

//------------------------------------------------------------------------------
// Service encapsulant la prise en compte de la tolerance - 
//                                                      modif R17 car Header CAA
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight int XPlaneLine(const CATMathPlane&   iPlane,
                                      const CATMathLine&    iLine,
                                      double&        oParLine,
                                      double&        oParPlane1,
                                      double&        oParPlane2,
                                      CATGeoFactory* GeoFac);    // Attention, Throw si NULL a partir de la R17

//------------------------------------------------------------------------------
// Calcule le trou d'un vertex
// iBody est optionnel : on prend tous les poecs du MacroPoint si iBody est NULL
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight void ComputeGapOnVertex(CATSoftwareConfiguration *iConfig,
                                               CATVertex                *iVertex,
                                               CATBody                  *iBody,
                                               double                   &oGap,
                                               CATShell                 *iShell = NULL,
                                               CATListOfDouble          *iPointCoord = NULL);

//------------------------------------------------------------------------------
// On lit les POECs dans le MacroPoint de iVertex
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight void GetPOECsInMacroPointOfVertex(CATVertex                     *iVertex,
                                                         CATLISTP(CATPointOnEdgeCurve) &oPOECs);

//------------------------------------------------------------------------------
// On determine les MathPoints du vetrex dans le shell (2 par POEC)
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight void ComputeMathPointsOnVertexAndShell(CATSoftwareConfiguration *iConfig,
                                                              CATVertex                *iVertex,
                                                              CATShell                 *iShell,
                                                              CATBody                  *iBody,
                                                              CATLISTV(CATMathPoint)   &oMathPoints);



//------------------------------------------------------------------------------
// Retourne les edges communes a un vertex
// iSharpness = FASLE toutes les edges
// iSharpness = TRUE  les edges Vives.
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight  void GetBorderEdgesOnVertex(CATSoftwareConfiguration *iConfig,
                                                    CATVertex                *iVertex,         // Vertex
                                                    CATBody                  *iInBody, 
                                                    ListPOfCATEdge           &oBorderEdge,     // List of border Edge
                                                    CATBoolean                iSharpness=FALSE);   

//------------------------------------------------------------------------------  
// Rend les edges internes et bord d'une liste de faces connexes
// NB - les edges de loops internes seront vues comme Border
//------------------------------------------------------------------------------  
/** @nodoc @nocgmitf */
ExportedByTopUtilLight void GetInternalAndBorderEdge(CATBody*        iBody,
                                                     ListPOfCATFace& iFaces,
                                                     ListPOfCATEdge& oInternalEdges,
                                                     ListPOfCATEdge& oBorderEdges);
  
//------------------------------------------------------------------------------  
// Rend (dans oAdjFaces) les faces adjacentes a iFaces qui ne sont pas incluses
// dans iFaces.
// Les faces iFaces sont supposees etre connexes (on ne verifie pas pr les perfos)
// Le service ne marche pas si les faces iFaces ne sont pas dans le meme shell
// iBorderEdges represente ttes les edges bord de iFaces (elles seraient bord
// libres dans un body ne contenant que iFaces)
// oFreeBorderEdges representent les aretes bord libre par rapport a iBody
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight void GetAdjFaces(CATBody*        iBody,
                                        ListPOfCATFace& iFaces,
                                        ListPOfCATEdge& iBorderEdges,
                                        ListPOfCATFace& oAdjFaces,
                                        ListPOfCATEdge& oFreeBorderEdges);

//------------------------------------------------------------------------------
//Create a modifiable wire
//------------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATBoolean CreateSingleWireFromEdges(CATGeoFactory* iGeoFactory, 
                                                            CATSoftwareConfiguration* iConfig,
                                                            const CATLISTP(CATEdge) &iEdges, 
                                                            CATBody* &ioResultBody,
                                                            CATWire* &oWire, 
                                                            CATListOfInt* iOrients = 0);

//-----------------------------------------------------------------------------
//Get the internal edges of the given single shell body
//-----------------------------------------------------------------------------
/** @nodoc @nocgmitf */
ExportedByTopUtilLight CATBoolean GetInternalEdgesOfShellBody(CATBody* iBody, 
                                                              CATLISTP(CATEdge) &oEdges,
                                                              CATShell** oShell = 0);

//----------------------------------------------------------------------------
// To get outer contour of shell. This ignores any inner loops in the shell
//----------------------------------------------------------------------------
ExportedByTopUtilLight CATBody* GetOuterBoundaryOfShell(CATTopData  &   iTopData, 
                                                        CATBody     *   ipCreationBody, 
                                                        CATShell    *   ipShell,
                                                        CATWire     *&  opWire);

//-------------------------------------------------------------------------------------------
// To get outer contour of connex set of faces. This ignores any inner loops in faces
//-------------------------------------------------------------------------------------------
ExportedByTopUtilLight CATBody* GetOuterBoundaryOfConnexFaces(CATTopData            &   iTopData,
                                                              CATBody               *   ipCreationBody,
                                                              CATLISTP(CATFace)     &   iListOfFaces,
                                                              CATWire               *&  opWire);

#endif

// Ne rien ecrire sous cette ligne
//===========================================================================================================



