//=================================================================================
// Copyright Dassault Systemes Provence 2007, All Rights Reserved
//=================================================================================
//
// CATSmoBasicJoinMeshesOperator.h
//
//=================================================================================
//
// Usage notes: Assemblage de parties non connnexes au sein d'un m�me mesh
//
//=================================================================================
// 21/11/07 MMO Correction des erreurs BAD004 (headerruler)
// 01/08/07 RAQ Creation
//=================================================================================
#ifndef CATSmoBasicJoinMeshesOperator_H
#define CATSmoBasicJoinMeshesOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"
// #include "CATSobEdge.h" // MMO BAD004
// #include "CATSobVertex.h" // MMO BAD004
#include "CATSobListOfEdge.h"
#include "CATSobListOfFace.h" // MMO BAD004
#include "CATSobListOfVertex.h"

//Divers
#include "CATListOfInt.h" // MMO BAD004
#include "CATBoolean.h" // MMO BAD004

#include <math.h> // MMO BAD004


class CATSobMesh;
class CATSobVertex;
class CATSobAttributes;


class ExportedByCATSmoOperators CATSmoBasicJoinMeshesOperator
{
public:

  //Constructeur
  CATSmoBasicJoinMeshesOperator();

  //Destructeur
  virtual ~CATSmoBasicJoinMeshesOperator();

  //Set des listes en cas de suivi des cellules en cas de join
  void SetListsForTraceBack(CATLISTP(CATSobFace)& ioImportedFaces);

  //Option: ignore les erreurs de connexit� invalide
  void SetIgnoreInvalidConnexityError();

  //Option d'insertion de points entre les deux bords
  void SetInsertVerticesMode();

  //Option: merge simple en cas de symm�trie
  void SetJustMergeWhenSymmetric();

  //Option de sharpness sur les edges de jointure
  void SetSharpnessOnJonctions();

  //Resampling des vertex sur le bord
  void SetEnableVerticesResampling();

  //Set de la couture dans le cas d'un merge (interne � un mesh) - Loop ouverte
  CATSobDiag SetBoundaries(CATSobMesh* iCurrentMesh,
                           CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                           CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2);

  //Set de la couture dans le cas d'un join (entre deux mesh) - Loop ouverte
  CATSobDiag SetBoundaries(CATSobMesh* ioMeshDest, CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                           CATSobMesh* iMeshSrc, CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2);

  //Set de la couture dans le cas d'un merge (interne � un mesh) sans intersections entre les fronti�res - Loop ferm�e
  CATSobDiag SetBoundaries(CATSobMesh* iCurrentMesh,
                           CATLISTP(CATSobEdge)& iBoundarySide1, CATLISTP(CATSobEdge)& iBoundarySide2);

  //Set de la couture dans le cas d'un join (entre deux mesh) sans intersections entre les fronti�res - Loop ferm�e
  CATSobDiag SetBoundaries(CATSobMesh* ioMeshDest, CATLISTP(CATSobEdge)& iBoundarySide1,
                           CATSobMesh* iMeshSrc, CATLISTP(CATSobEdge)& iBoundarySide2);

  //Run de l'op�rateur
  CATSobDiag Run();

  //Obtention du diag
  CATSobDiag GetDiag() const;


protected:

  //Gestion du diag
  CATSobDiag SetDiag(const CATSobDiag iDiag);




private:

  //Calcul de la bounding box
  CATSobDiag ComputeBoundingBox();

  //V�rification des entr�es pour les fronti�res bien d�limit�es
  CATSobDiag RunCheckBoundariesAndFillCleanSymetric(CATBoolean& oWorkHasBeenDoneWithCleanSymetric);
  CATSobDiag CheckInputCells(CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                             CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2);
  CATSobDiag CheckInputCells(CATLISTP(CATSobEdge)& iBoundarySide1, CATLISTP(CATSobEdge)& iBoundarySide2);

  //V�rification du cha�nage
  CATSobDiag CheckChainedList(CATSobVertex* iStartVertex, CATLISTP(CATSobEdge)& iEdgesList, CATSobVertex* iEndVertex);
  CATSobDiag CheckChainedList(CATLISTP(CATSobEdge)& iEdgesList);

  //Check des orientations relatives entre deux bords ferm�s
  CATSobDiag CheckClosedBoundaryLoopsOrientation(CATLISTP(CATSobEdge)& ioBoundaryEdges1, CATLISTP(CATSobEdge)& ioBoundaryEdges2);

  //V�rification des entr�es et merge des cellules confondues pour les fronti�res sans intersection
  CATSobDiag RunCheckBoundariesAndMergeConfusedCells();

  //Tentive de merge total dans la cas sym�trique
  CATSobDiag TryToMergeAllEdgesInSymetricCase(CATLISTP(CATSobFace)* iAllFaces, CATLISTP(CATSobEdge)* iAllEdges, CATBoolean& oMergeHasBeenDone);

  //For�age d'un merge d'edge dans le cas de fronti�res sans intersection
  CATSobDiag RunForceMergeEdge(CATLISTP(CATSobEdge)& ioBoundary1, CATLISTP(CATSobEdge)& ioBoundary2,
                               CATLISTP(CATSobFace)* iFacesForReverseOrientation, CATLISTP(CATSobEdge)* iEdgesForReverseOrientation);

  //Ajout de faces dans le mesh courant (pour le join) et gestion de suivi
  CATSobDiag RunAdvancedAddFaces(CATLISTP(CATSobFace)* iInputFaces, CATLISTP(CATSobFace)* ioImportedFaces,
                                 CATLISTP(CATSobEdge)* iInputEdges, CATLISTP(CATSobEdge)* ioImportedEdges,
                                 CATLISTP(CATSobVertex)* iInputVertices, CATLISTP(CATSobVertex)* ioImportedVertices);

  //Inversion d'orientation dans le cas d'un Join
  CATSobDiag ReverseOrientationInJoinMode(CATLISTP(CATSobFace)* iAllFaces, CATLISTP(CATSobEdge)* iAllEdges);

  //Inversion d'orientation dans le cas d'un Merge
  CATSobDiag ReverseOrientationInMergeMode(CATSobEdge* iStartEdgeOfConnexPart);

  //Merge des vertex extr�mit�
  CATSobDiag RunMergeExtremityVertices();

  //Cr�ation des liste ordonn�es des vertex et des edges de bord
  CATSobDiag ExtractBorderCells();

  //Calcul d'un scan pour approximer la zone de jonction et �largissement du trou
  CATSobDiag ComputeCommonBoundaryScanAndMoveVertices();

  //D�placement d'un vertex pour �largissement du trou
  CATSobDiag MoveVertex(CATSobVertex* iVertex);

  //Projection sur la fronti�re commune
  CATSobDiag ProjectOnCommonBoundary(const double* iPointToProject, double* ioProjectedPoint);

  //Run du remaillage pour le cas des fronti�res AVEC intersections
  CATSobDiag RunRemeshing();

  //Run du remaillage pour le cas des fronti�res SANS intersections
  CATSobDiag RunPartialRemeshing();

  //Extraction d'une loop d'edges libres
  CATSobDiag ComputeLoopOfFreeEdges(CATSobEdge* iStartingEdge, CATLISTP(CATSobEdge)& oListOfBorderEdges);

  //Split d'une edge et remaillage de sa DirectFace
  CATSobDiag SplitEdge(CATSobEdge* iOldEdge, CATSobEdge*& oNewEdge1, CATSobVertex*& oNewVertex, CATSobEdge*& oNewEdge2);

  //Sampling des vertex de bord
  CATSobDiag SampleOldBorderVertices();

  //Remaillage des trous: cas sym�trique
  CATSobDiag FillMeshHoleSymetric(CATBoolean& oSomethingHasBeenDone, const int iP2QConstraintIndex = -1);
  CATSobDiag FillMeshHoleSymetricJustMerge(CATBoolean& oSomethingHasBeenDone, const int iP2QConstraintIndex = -1);
  CATSobDiag FillMeshHoleSymetricNoIntersection(CATLISTP(CATSobEdge)& iEdgesHigh, CATLISTP(CATSobEdge)& iEdgesLow,
                                                const CATBoolean iIsClosedLoop, CATBoolean& oSomethingHasBeenDone);

  //Remaillage des trous: cas pair - impair
  CATSobDiag FillMeshHoleEvenOdd(CATBoolean& oSomethingHasBeenDone, const int iP2QConstraintIndex = -1);

  //Remaillage des trous: cas impair - pair
  CATSobDiag FillMeshHoleOddEven(CATBoolean& oSomethingHasBeenDone, const int iP2QConstraintIndex = -1);

  //Remaillage des trous: cas pair - pair
  CATSobDiag FillMeshHoleEvenEven(CATBoolean& oSomethingHasBeenDone, const int iP2QConstraintIndex = -1);

  //Remaillage des trous: cas impair - impair
  CATSobDiag FillMeshHoleOddOdd(CATBoolean& oSomethingHasBeenDone, const int iP2QConstraintIndex = -1);

  //Modification du remplissage en tenant compte d'une contrainte
  CATSobDiag RemeshWithConstraint(CATSobVertex* iSideVertices[2], CATLISTP(CATSobEdge)& iTransversalEdges,
                                  CATLISTP(CATSobFace)& iInnerFaces, const int iP2QConstraintIndex = -1);

  //Pr�-d�tection et correction des valences 2 internes pendant le bouchage des trous
  CATSobDiag CheckInternalValenceTwoVertex(CATSobVertex* iVertex);

  //D�tection et correction des valences 2 internes (m�thode g�n�rale)
  CATSobDiag DetectAndRepairInternalValenceTwoVertices();

  //Check du r�sultat
  CATSobDiag RunCheckResult();

  //Distance entre deux points (� supprimer apr�s d�rivation...)
  double GetDistance(const double* iPt1, const double* iPt2) const;
  double GetSquareDistance(const double* iPt1, const double* iPt2) const;
  double GetSquareDistance(const CATSobVertex* iVertex1, const CATSobVertex* iVertex2) const;

  //Normalisation d'un vecteur
  void Normalize(double* iVector, double* ioNorm = 0) const;


  //------ Data:
  CATSobDiag _Diag;
  CATSobMesh *_CurrentMesh, *_MeshSrc;
  double _NormalizationDistance, _MoveVertexRatio;

  CATSobVertex *_InputBoundaryVertices1[2], *_InputBoundaryVertices2[2];
  CATLISTP(CATSobEdge) _InputBoundaryEdges1, _InputBoundaryEdges2;

  CATSobVertex *_BoundaryVertices1[2], *_BoundaryVertices2[2];
  CATLISTP(CATSobVertex) _AllBorderVertices;
  CATLISTP(CATSobEdge) _BoundaryEdges1, _BoundaryEdges2, _AllBorderEdges;
  CATListOfInt _HighestVertices, _LowestVertices;
  
  CATBoolean _IsJoinMode, _IsClosedBorderLoop, _IgnoreInvalidConnexityError, _JustMergeWhenSymmetric;
  CATSobEdge *_BoundaryEdgeToMerge1, *_BoundaryEdgeToMerge2;

  CATBoolean _MustInsertVertices, _AddSharpnessOnJonctions, _EnableVerticesResampling;
  double* _CommonBoundaryScan;
  int _CommonBoundaryScanLength;

  //Listes pour le suivi en cas de join
  CATBoolean _MustTraceBackCells;
  CATLISTP(CATSobFace)* _ImportedFaces;
  CATSobAttributes *_AttributeForFaceHigh, *_AttributeForFaceLow;
  CATSobAttributes * _AttributeForEdgesOnBoundary;
};


//----------------------------------------------------------------
// Distance entre deux points (� supprimer apr�s d�rivation...)
//----------------------------------------------------------------
inline double CATSmoBasicJoinMeshesOperator::GetDistance(const double* iPt1, const double* iPt2) const
{
  return sqrt((iPt1[0]-iPt2[0])*(iPt1[0]-iPt2[0]) + (iPt1[1]-iPt2[1])*(iPt1[1]-iPt2[1]) + (iPt1[2]-iPt2[2])*(iPt1[2]-iPt2[2]));
}


inline double CATSmoBasicJoinMeshesOperator::GetSquareDistance(const double* iPt1, const double* iPt2) const
{
  return ((iPt1[0]-iPt2[0])*(iPt1[0]-iPt2[0]) + (iPt1[1]-iPt2[1])*(iPt1[1]-iPt2[1]) + (iPt1[2]-iPt2[2])*(iPt1[2]-iPt2[2]));
}


//-----------------------------
// Normalisation d'un vecteur
//-----------------------------
inline void CATSmoBasicJoinMeshesOperator::Normalize(double* iVector, double* ioNorm) const
{
  double Norm=sqrt(iVector[0]*iVector[0]+iVector[1]*iVector[1]+iVector[2]*iVector[2]);
  iVector[0]/=Norm;
  iVector[1]/=Norm;
  iVector[2]/=Norm;
  if(ioNorm) *ioNorm=Norm;
}


#endif



