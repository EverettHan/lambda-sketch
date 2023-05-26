#ifndef TopologicalUtilities2_H
#define TopologicalUtilities2_H

// COPYRIGHT DASSAULT SYSTEMES 2002

//=============================================================================
//=============================================================================
//
// TopologicalUtilities2.cpp 
//
// Suite de TopologicalUtilities.cpp 
//
//=============================================================================

//=============================================================================
// Oct  2000  Creation                               P. Rossignol
//=============================================================================
//=============================================================================


// Operateurs
class CATTopologicalOperator;

// List
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "ListPOfCATWire.h"
#include "ListPOfCATVertex.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATListOfCATPointOnEdgeCurves.h"

// Split for Light
#include "TopoUtilitiesForLight.h" 

// Autres
#include "CATTopRibDef.h"

// ExportedBy
#include "RibbonLight.h"



//===========================================================================================================
// Ordonne la liste d'edge en entree en regardant les connexions au niveau des vertex
// Sort une liste de listes, chacune des ces listes regroupant des edges "jointives"
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void SortEdges(ListPOfCATEdge &iToOrder,
                                ListPOfCATEdge &oOrdered,
                                CATListOfInt   &oNumList);

//===========================================================================================================
// Service de SortEdges
//===========================================================================================================
/** @nodoc @nocgmitf */
void SortSomeEdges(ListPOfCATEdge &ioToOrder,
                   ListPOfCATEdge  &oOrdered);

//===========================================================================================================
// Indique si iEdge est connectee a une arete de la liste iOrdered/iNumList
// NB: iEdge doit etre un element de iOrdered/iNumList
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATEdge* IsLinkedWithAnotherEdge(CATEdge        *iEdge,
                                                  CATTopRibSign   iDirection,
                                                  ListPOfCATEdge &iOrdered,
                                                  CATListOfInt   &iNumList);

//===========================================================================================================
// Service d'enrobage de TopOp.IntersectShells avec nettoyage integre
// Rend vrai s'il y aeu une intersection
// Fait tous les 
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean XShellsAndClean(CATShell               *iShell1, 
                                            CATShell               *iShell2, 
                                            CATBody                *iBody1,   
                                            CATBody                *iBody2,
                                            CATTopologicalOperator &iTopOp,
                                            CATBoolean              iRecalculateTouch = FALSE);

//===========================================================================================================
// Calcule le trou d'un vertex
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void ComputeGapOnVertex(CATSoftwareConfiguration *iConfig,
                                         CATVertex                *iVertex,
                                         CATMathPoint             &iPoint,
                                         CATBody                  *iBody,
                                         double                   &oGap,
                                         CATShell                 *iShell = NULL);

//===========================================================================================================
// Merger les vertex tres proches, decouper les wires en cas de croisements .
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void HealWireTopology (CATGeoFactory *iFactory,CATBody *iCreationBody, 
                                            ListPOfCATDomain& ioCreatedWires, 
                                            CATCGMJournalList  *iJournal, 
                                            CATSoftwareConfiguration *iSoftwareConfiguration,
                                            ListPOfCATDomain& oWiresToDelete,
                                            CATLISTP(CATVertex) & oMergedVertices,
                                            CATBoolean iOptimizedDS = FALSE);


//===========================================================================================================
// Chances of overlapped wire due to filtering of border solutions
// So a additional treatment is added than in HealWireTopology
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void HealWireTopology2 (CATGeoFactory *iFactory,CATBody *iCreationBody, 
                                              ListPOfCATDomain& ioCreatedWires, 
                                              CATCGMJournalList  *iJournal, 
                                              CATSoftwareConfiguration *iSoftwareConfiguration,
                                              ListPOfCATDomain& oWiresToDelete,
                                              CATLISTP(CATVertex) & oMergedVertices,
                                              CATBoolean iOptimizedDS = FALSE);

//===========================================================================================================
// Trouver tous les vertex references par les iWires, chaque vertex est reference par un seul wire note dans 
// oAllWires.
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void GetAllVerticesFromWires (ListPOfCATDomain&  iWires, 
                                               CATLISTP(CATVertex) & oAllVertices, 
                                               CATLISTP(CATWire) &oAllWires,
                                               CATLISTP(CATVertex) & oMergedVertices);
//===========================================================================================================
// Trouver le vertex proche d'un autre wire a merger
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean ShouldMergeVertexInWire (CATSoftwareConfiguration *iSoftwareConfiguration,
                                                          CATBody * iWireBody,
                                                          ListPOfCATDomain&  iAllWires, 
                                                          CATWire *iWire, CATVertex *iVertex, double iTol,
                                                          CATWire *&OtherWire, CATVertex *&OtherVertex,
                                                          CATGeoFactory *iFactory = NULL);
//===========================================================================================================
// Creer 2 wires partition du wire avec le vertex
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean SplitWireWithVertex (CATBody * iCreationBody, CATGeoFactory *iFactory, 
                                                 CATSoftwareConfiguration * iConfig, CATWire *iWire, 
                                                 CATVertex *iVertex, ListPOfCATDomain& oNewWires);


//===========================================================================================================
// Lecture des edges adjacents au vertex iVertex au sein du wire iWire
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void GetEdgeFromWire (CATSoftwareConfiguration *iSoftwareConfiguration, CATBody * iWireBody,
                                            CATWire *iWire, CATVertex *iVertex, CATEdge *& edge1, CATEdge *& edge2,
                                            CATGeoFactory *iFactory = NULL);


//===========================================================================================================
// Méthode de simplication des FatEdges d'un shell après disconnection de celui-ci
// (il ne doit plus y avoir de coupantes sur le shell)
// Si iInteriorShell vaut TRUE, on ne simplifie que les edges internes de ce shell
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void SimplifyFatEdge(CATSoftwareConfiguration * iConfig,
                                      CATShell* iSkinToSimplify,
                                      CATBody * iBodyToSimplify,
                                      CATBoolean iInteriorEdge=FALSE,
                                      ListPOfCATEdge * iListOfEdgeNoSimplif = NULL,
                                      CATBoolean iUnsetCutting = FALSE);




//===========================================================================================================
// Entre deux liste de faces, cette méthode renvoie les edges partagées entre les deux listes 
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void GetCommonEdgesBetweenListOfFaces(CATDomain      *iDomain,
                                                       CATBody        *iBody,
                                                       const ListPOfCATFace & iListFace1,
                                                       const ListPOfCATFace & iListFace2,
                                                       ListPOfCATEdge &oListOfCommonEdge);

//===========================================================================================================
// Entre deux faces, cette méthode renvoie les edges partagées entre leurs deux loops externes
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void GetCommonEdgesBetweenExtLoops(CATFace*        iFace1,
                                                         CATFace*        iFace2,                                                       
                                                         ListPOfCATEdge& oListOfCommonEdge);

//===========================================================================================================
// renvoie TRUE si les edges internes à un ensemble de faces connexes sont smooths.
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean CommonEdgesBetweenFacesAreSmooth(const CATTopData     &iTopData, 
                                                             const ListPOfCATFace & iFaceInShell, 
                                                             CATBody        *iBody);

//===========================================================================================================
// Service pour l'operateur reflect-line permettant de savoir si deux edges correspondent a la meme solution
// (en tenant copmte de l'orientation)
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight int AreReflectLineEdgesConfused(CATSoftwareConfiguration * iConfig, CATEdge * iEdge1, CATEdge * iEdge2, double iTol);



//===========================================================================================================
// renvoie 1 si les edges internes à un ensemble de faces connexes sont smooths (service OK pour Shell & Regul)
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight short AreCommonEdgesBetweenFacesSmooth(CATTopData        * iTopData,
                                                             CATLISTP(CATFace) & iInputFaceList,
                                                             double            * iSharpAngleTol=NULL);


//===========================================================================================================
// renvoie 1 s'il existe une edge imprint parmis les edges internes a un ensemble connexes de faces
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight short AreCommonEdgesBetweenFacesImprint(CATGeoFactory *iFactory, CATLISTP(CATFace) &iInputFaceList);

//===========================================================================================================
// Checks if the merge done is to be allowed or not
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean IsWrongMerge(CATSoftwareConfiguration * iSoftwareConfiguration, CATEdge * iSameEdge, CATVertex * iOtherVertex, CATMathPoint &iRefPoint, double iTol);

#endif


//===========================================================================================================
//===========================================================================================================
