//===========================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===========================================================================
//
// CATSmoNGonMeshEditionOperator.h
//
//===========================================================================
//
// Usage notes: Op�rateur d'�dition de base mesh ngone.
//
//===========================================================================
// December,  2009 : RAQ : Creation
//===========================================================================
#ifndef CATSmoNGonMeshEditionOperator_H
#define CATSmoNGonMeshEditionOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Structure subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"

class CATSobMesh;
class CATSobEdge;
class CATSobVertex;
class CATLISTP(CATSobEdge);
class CATLISTP(CATSobVertex);
class CATSmoMeshTopoModifOperator;
class CATLISTV(CATMathPoint);


class ExportedByCATSmoOperators CATSmoNGonMeshEditionOperator
{
public:

  //Destructeur
  virtual ~CATSmoNGonMeshEditionOperator();

  //Diag de l'op�rateur
  virtual CATSobDiag GetDiag() const = 0;

  //Cr�ation de face : les vertex sont identifi�s � partir des positions ou �ventuellement cr��s.
  virtual CATSobDiag CreateFace(const CATLISTV(CATMathPoint)& iVerticesPosition, CATSobFace*& oNewFace) = 0;

  //Cr�ation de face
  virtual CATSobDiag CreateFace(const CATLISTP(CATSobVertex)& iVertices, CATSobFace*& oNewFace) = 0;
  virtual CATSobDiag CreateFace(CATLISTP(CATSobEdge)& iEdges, CATSobFace*& oNewFace) = 0;

  //Insertion d'un vertex dans une edge
  virtual CATSobDiag SplitEdge(CATSobEdge* iEdgeToSplit, const double iRatio,
                               CATSobVertex** oInsertedVertex = 0, CATSobEdge** oNewHalfEdge1 = 0, CATSobEdge** oNewHalfEdge2 = 0) = 0;

  virtual CATSobDiag SplitEdge(CATSobEdge* iEdgeToSplit, const double iRatio,
                               const CATSobFace* iContextFace, CATSobFace*& oNewFace,
                               CATSobVertex** oInsertedVertex = 0, CATSobEdge** oNewHalfEdge1 = 0, CATSobEdge** oNewHalfEdge2 = 0) = 0;

  //Merge de faces
  virtual CATSobDiag MergeFaces(CATLISTP(CATSobFace)& iFacesToMerge, CATSobFace** oNewFace = 0) = 0;

  //Merge de faces: toutes les faces autour du vertex sont merg�es.
  virtual CATSobDiag MergeFaces(CATSobVertex* iVertex, CATSobFace** oNewFace = 0) = 0;

  //Merge de faces: les deux faces adjacentes � l'edge sont merg�es.
  virtual CATSobDiag MergeFaces(CATSobEdge* iEdge, CATSobFace** oNewFace = 0) = 0;

  //Suppression de face
  virtual CATSobDiag RemoveFace(CATSobFace* iFaceToRemove) = 0;

  //D�coupage de face
  virtual CATSobDiag SplitFace(CATSobVertex* iVertex1, CATSobVertex* iVertex2, CATSobFace** oNewFace1 = 0, CATSobFace** oNewFace2 = 0) = 0;

  //Merge de vertex: iVertexToKeep doit �tre dans la liste des vertex � merger.
  virtual CATSobDiag MergeVertices(const CATLISTP(CATSobVertex)& iVerticesToMerge, CATSobVertex* iVertexToKeep) = 0;

  //Merge de vertex: si iMergeCoords est NULL le nouveau vertex est le barycentre des vertex � merger.
  virtual CATSobDiag MergeVertices(const CATLISTP(CATSobVertex)& iVerticesToMerge, const double* iMergeCoords = 0, CATSobVertex** oResultVertex = 0) = 0;

  //Merge de vertex: merge de tous les vertex d'une face, si iMergeCoords est NULL le nouveau vertex est le barycentre des vertex � merger.
  // /!\: iFaceToCollapse est d�truite.
  virtual CATSobDiag MergeVertices(CATSobFace* iFaceToCollapse, const double* iMergeCoords = 0, CATSobVertex** oResultVertex = 0) = 0;

  //Merge de vertex: merge des deux vertex d'une edge, si iMergeCoords est NULL le nouveau vertex est le barycentre des vertex � merger.
  // /!\: iEdgeToCollapse est d�truite.
  virtual CATSobDiag MergeVertices(CATSobEdge* iEdgeToCollapse, const double* iMergeCoords = 0, CATSobVertex** oResultVertex = 0) = 0;

  //Suppression d'un vertex de valence 2 interne: simplifie la topologie en mergeant les deux edges autour de ce vertex.
  virtual CATSobDiag RemoveInternalValenceTwoVertex(CATSobVertex* iVertexToRemove, CATSobEdge** oNewEdge = 0) = 0;



protected:

  //Constructeur
  CATSmoNGonMeshEditionOperator();

};


//Construction de l'op�rateur
ExportedByCATSmoOperators
CATSmoNGonMeshEditionOperator* CATSmoCreateNGonMeshEditionOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOperator = 0);


#endif

