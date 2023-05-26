//============================================================================
// Copyright Dassault Systemes Provence 2003-2018, all rights reserved 
//============================================================================
//
// CATSobDiag.h
//
//============================================================================
//
// Usage notes:
//
//============================================================================
// 28.06.2018 : MMO : Ajout CATSobDiag_InputPolyhedralBodyNotAuthorized 
//                    pour les CATBody Polyedrique non autorise en entree de certains op�rateurs (POLYCRASH)
// 28.02.2013 : RAQ : Ajout CATSobDiag_MergedCurveComputationError
// December,  2009 : RAQ : Ajout IsOK(const CATSobDiag iDiag)
// April,     2008 : RAQ : Ajout CATSobDiag_InternalNullSubdivCellSurface
// January  , 2008 : MPS : Ajout CATSobDiag_NotModifiableDimension
// September, 2007 : RNO : Ajout CATSobDiag_UnableToEval
// July    ,  2007 : PMG : Ajout CATSobDiag_InsuficientNumberOfActiveCells
// March   ,  2007 : PMG : Ajout CATSobDiag_OperatorNotInitialized 
// February,  2007 : MPS : Ajout CATSobDiag_EdgesPartiallyConfused 
// February,  2007 : RAQ : Ajout ToString
// October,   2004 : RAQ : Optimisation m�moire + nouveaux diag
// January,   2004 : RAQ : Changement d'architecture des subdivisions
// January,   2004 : RAQ : Ajout CATSobDiag_SurfacePointerNotNull
// Marsh,     2003 : JCV : Creation CATSobDiag.h
//============================================================================
#ifndef CATSobDiag_H
#define CATSobDiag_H

//Pour l'export
#include "CATSobObjects.h"

//Divers
#include "CATBoolean.h"



typedef enum 
{ 
/////////////////////////////////////////////////////////////////////////////////////
  CATSobDiag_OK = 0                             // OK
/////////////////////////////////////////////////////////////////////////////////////
//                                ERREURS
/////////////////////////////////////////////////////////////////////////////////////
//                                       Erreurs sur les entr�es
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_InputNullPointer                   // Un pointeur donne en entr�e est nul.
, CATSobDiag_InputNullMesh                      // Le pointeur de mesh donne en entr�e est nul.
, CATSobDiag_InputNullFace                      // Le pointeur de face donne en entr�e est nul.
, CATSobDiag_InputNullEdge                      // Le pointeur d'edge donne en entr�e est nul.
, CATSobDiag_InputNullVertex                    // Le pointeur de vertex donne en entr�e est nul.
, CATSobDiag_InputNullCell                      // Le pointeur de cellule donn� en entr�e est nul.
, CATSobDiag_InputNullVertexOnEdge              // Pointeur de vertex sur edge nul.
, CATSobDiag_InputNullList                      // Le pointeur de liste donne en entr�e est nul.
, CATSobDiag_InputNullLayer                     // Pointeur de layer null en entr�e d'un l'op�rateur.
, CATSobDiag_InputNullListener                  // Pointeur de listener null en entr�e d'un l'op�rateur.
, CATSobDiag_InputInvalidIndex                  // L'index donne en entr�e est invalide (hors bornes).
, CATSobDiag_InputInvalidValue                  // La valeur donn�e en entr�e est invalide.
, CATSobDiag_InputInvalidCell                   // La cellule donn�e en entr�e est invalide.
, CATSobDiag_InputInvalidLevel                  // Le niveau de subdivision donn� en entr�e est invalide
, CATSobDiag_InputNullListElement               // Un element contenu dans la liste donn�e en entr�e est nul.
, CATSobDiag_InputInvalidSize                   // Une liste donn�e en entr�e est de taille invalide.
, CATSobDiag_InputMeshIncompatibility           // Une donn�e n'est pas compatible avec le mesh courant.
, CATSobDiag_InputCellsIncompatibility          // Certaines donn�es sont incompatibles (ex : edge hors face trait�e).
, CATSobDiag_InputPolyhedralBodyNotAuthorized   // Une entr�e en un CATBody Polyedrique, type d'entr�e non valide
, CATSobDiag_InsuficientNumberOfActiveCells     // Nombre de cellules active insuffisante
, CATSobDiag_NotModifiableDimension             // La modification de la dimension demand�e est impossible
, CATSobDiag_IncompatibleOptions                // Options incompatibles
/////////////////////////////////////////////////////////////////////////////////////
//                                       Erreurs li�es � la validite de la structure
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_FaceNull                           // Pointeur de face nul dans le mesh -> faire un Update.
, CATSobDiag_EdgeNull                           // Pointeur d'edge nul dans le mesh -> faire un Update.
, CATSobDiag_VertexNull                         // Pointeur de vertex nul dans le mesh -> faire un Update.
, CATSobDiag_OpenVertex                         // Un vertex est ouvert, ie sur un bord
, CATSobDiag_ClosedVertex                       // Un vertex est interne, ie pas sur un bord
, CATSobDiag_MeshInvalidConnexity               // Mesh non connexe.
, CATSobDiag_EdgeLenghtMin                      // Longueur minimum d'edge non respect�e.
, CATSobDiag_MeshNotQuad                        // Mesh constitue de faces non quadrangulaires.
, CATSobDiag_MeshNotTriQuad                     // Mesh constitue de faces non quadrangulaires ou triangulaires.
, CATSobDiag_MeshIncompatibility                // Une cellule n'est pas compatible avec le mesh courant.
, CATSobDiag_CellsIncompatibility               // Certaines cellules sont incompatibles (ex : edge hors face trait�e).
, CATSobDiag_EdgeSameVertex                     // Une edge ne peut pas avoir le meme vertex au debut et a la fin.
, CATSobDiag_EdgeSameSupport                    // Une edge ne peut etre jointure de deux fois la meme face.
, CATSobDiag_EdgeMoreSupport                    // Une edge ne peut pas avoir plus de deux supports.
, CATSobDiag_FaceNotConnectedEdge               // Les edges de la face ne sont pas connect�es.
, CATSobDiag_FaceBoundaryNotClose               // La premiere et la derniere edges de la face ne sont pas connect�es.
, CATSobDiag_FaceNotQuad                        // La face n'est pas quad
, CATSobDiag_FaceInvalidEdgeSize                // Une face doit etre constitu�e d'au moins 3 edges.
, CATSobDiag_InvalidValenceTwoVertex            // Un vertex interne � un maillage ne peut pas �tre de valence 2
, CATSobDiag_BigValenceError                    // Le mesh poss�de des vertex de valence trop importante
, CATSobDiag_MeshFrozen                         // Le mesh est gel�, il ne peut �tre modifi�
, CATSobDiag_EdgesPartiallyConfused             // Dans le mesh , il existe des edges partiellement confondues
, CATSobDiag_CellTagNotUnique                   // Des valeurs de tag sont dupliqu�es
, CATSobDiag_CellAlreadyModified                // Cellule ne pouvant �tre modifi�e qu'une unique fois et d�j� modifi�e
/////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_ErrorFaceAlreadyCut                // La face est d�j� coup�e, impossible de la red�couper
, CATSobDiag_LocalVertexNotModifiable           // Un vertex du base mesh local ne peut pas �tre d�plac�
/////////////////////////////////////////////////////////////////////////////////////
//                                       Erreurs internes
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_InternalError                      // Erreur interne dans l'operateur.
, CATSobDiag_InternalNullPointer                // Pointeur nul rencontr� dans l'operateur.
, CATSobDiag_InternalNullMesh                   // Pointeur de mesh nul rencontr� dans l'operateur.
, CATSobDiag_InternalNullFace                   // Pointeur de face nul rencontr� dans l'operateur.
, CATSobDiag_InternalNullEdge                   // Pointeur d'edge nul rencontr� dans l'operateur.
, CATSobDiag_InternalNullVertex                 // Pointeur de vertex nul rencontr� dans l'operateur.
, CATSobDiag_InternalNullCell                   // Pointeur de cellule nul rencontr� dans l'op�rateur.
, CATSobDiag_InternalNullVertexOnEdge           // Pointeur de vertex sur edge nul rencontr� dans l'operateur.
, CATSobDiag_InternalNullSurface                // Pointeur de surface null rencontr� dans l'op�rateur.
, CATSobDiag_InternalNullSubdivCellSurface      // Pointeur de CATSubdivCellSurface null rencontr� dans l'op�rateur.
, CATSobDiag_InternalNullLayer                  // Pointeur de layer null rencontr� dans l'op�rateur.
, CATSobDiag_InternalNullListener               // Pointeur de listener null rencontr� dans l'op�rateur.
, CATSobDiag_InternalNullList                   // Pointeur de liste nul rencontr� dans l'operateur.
, CATSobDiag_InternalInvalidSize                // Liste de taille invalide rencontr�e dans l'operateur.
, CATSobDiag_InternalInvalidValue               // Valeur incorrecte rencontr�e dans l'op�rateur
, CATSobDiag_InternalInvalidLevel               // Le niveau de subdivision est invalide
, CATSobDiag_InternalInvalidIndex               // L'index donn� est invalide (hors bornes).
/////////////////////////////////////////////////////////////////////////////////////
//                                       Pointeurs de surface non d�truit
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_SurfacePointerNotNull              // Pointeur sur la surface d'une face non nul
/////////////////////////////////////////////////////////////////////////////////////
//                                       Erreurs relatives aux d�tails
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_NullDetail                         // Detail nul
/////////////////////////////////////////////////////////////////////////////////////
//                                       Diag pour l'op�rateur de compression
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_Done                               // Le tra�tement est effectu�
, CATSobDiag_Continue                           // Le tra�tement doit se poursuivre
, CATSobDiag_BadCompressorLevel                 // Erreur de version dans l'op�rateur de compression
/////////////////////////////////////////////////////////////////////////////////////
//                                       Diag pour les op�rateurs de topologie
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_InputNullOperator                  // Un pointeur donn� en entr�e sur un op�rateur est nul
, CATSobDiag_InternalNullOperator               // Un pointeur sur un op�rateur est nul en interne
, CATSobDiag_InputNullSubdivMesh                // Le CATSubdivMesh donn� en entr�e est nul
, CATSobDiag_InternalNullSubdivMesh             // Un CATSubdivMesh est nul dans l'op�rateur
, CATSobDiag_OperatorAlreadyRun                 // L'op�rateur a d�j� �t� jou�, un seul run autoris�
, CATSobDiag_OperatorNotRun                     // Aucun Run n'a �t� fait sur l'op�rateur
, CATSobDiag_OperatorNotInitialized             // Aucun Init n'a �t� fait sur l'op�rateur
, CATSobDiag_MergedCurveComputationError        // Unable to create a merged curve during topological update
/////////////////////////////////////////////////////////////////////////////////////
//                                       Diag pour les Eval
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_UnableToEval                       //Cas non gere par l'eval 
, CATSobDiag_UnableToComputeCurvature 
/////////////////////////////////////////////////////////////////////////////////////
//                                       Solveur hybride
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_HybSolver_AreaModificationIntersection   //Zones de modification en intersection
/////////////////////////////////////////////////////////////////////////////////////
//                                       Match de Subdivision
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_Match_InvalidBoundary                    //Bord non r�gulier pour le match : pr�sence de poids, vertex non r�gulier...
, CATSobDiag_Match_InvalidRequestedContinuity         //L'op�rateur ne peut pas matcher avec la continuit� demand�e : le wire cible ne permet pas de tenir les continuit�s g�om�triques demand�es (pas de support alors que G1 ou G2 demand� par exemple),
                                                      //limitation n'autorisant que du G0 mais G1 ou G2 demand�...
, CATSobDiag_Match_IncompatibleDiscontinuities        //Le nombre de discontinuit�s G1 sur la cible n'est pas le m�me que celui du bord � matcher
, CATSobDiag_Match_IncompatibleTargetWire             //Courbe cible et bord de subdiv incompatibles : ferm�/ouvert par exemple
, CATSobDiag_Match_UndefinedSupport                   //Support non d�finit ou ambigu
, CATSobDiag_Match_AreaModificationIntersection       //Intersection de zones de modification � l'interieur de l'op�rateur de match (conflit de param�tres)
/////////////////////////////////////////////////////////////////////////////////////
//                                       Divers
/////////////////////////////////////////////////////////////////////////////////////
, CATSobDiag_ErrorNotImplemented                // M�thode non impl�ment�e
, CATSobDiag_ErrorDeprecated                    // M�thode deprecated
/////////////////////////////////////////////////////////////////////////////////////

} CATSobDiag;


/**
 * Checks diag.
 *
 * @param iDiag
 *
 * @return
 * TRUE if iDiag is CATSobDiag_OK, FALSE otherwise.
 **/
inline ExportedByCATSobObjects
CATBoolean IsOK(const CATSobDiag iDiag) { return (iDiag==CATSobDiag_OK); }


/**
 * Gets the string corresponding to a diag
 *
 * @param iDiag
 * The Diag
 *
 * @return
 * The string corresponding to the given diag
 **/
ExportedByCATSobObjects
const char* ToString(const CATSobDiag iDiag);

#endif


