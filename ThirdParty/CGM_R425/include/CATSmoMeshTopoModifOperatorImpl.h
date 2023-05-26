//====================================================================
// Copyright Dassault Systemes Provence 2005, All Rights Reserved 
//====================================================================
//
// CATSmoMeshTopoModifOperatorImpl.h
//
//====================================================================
//
// Usage notes: Op�rateur effectuant les modifications topologiques
//              sur le mesh (Impl�mentation)
//
//====================================================================
// June,      2010 : RAQ : Cr�ation, changement d'archi pour Phase 2
//====================================================================
#ifndef CATSmoMeshTopoModifOperatorImpl_H
#define CATSmoMeshTopoModifOperatorImpl_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoMeshTopoModifOperator.h"

//Objets Subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfVertex.h"

//Divers
#include "CATBoolean.h"

class CATSobMesh;
class CATSobFace;
class CATSobEdge;
class CATSobVertex;


class ExportedByCATSmoOperators CATSmoMeshTopoModifOperatorImpl: public CATSmoMeshTopoModifOperator
{
public:

  //Constructeur
  CATSmoMeshTopoModifOperatorImpl(CATSobMesh* iMesh);

  //Destruction par release
  virtual void Release();

  //Gestion du compteur de r�f�rence
  virtual int GetNbRef() const;
  virtual void AddRef();

  //Obtention du diag
  virtual CATSobDiag GetDiag() const;

  //Set/Get du Mesh
  virtual void SetMesh(CATSobMesh* iMesh);
  virtual CATSobMesh* GetMesh() const;

  /////////////////////////////////////////////////////////////////////////
  //----- Options de suivi des cellules pour le journal topologique -----//
  /////////////////////////////////////////////////////////////////////////
  inline CATBoolean MustFollowCells() const;

  /////////////////////////////////////////////////////////////////
  //---------- Modifications g�om�triques du base mesh ----------//
  /////////////////////////////////////////////////////////////////

  //Changement des coordonn�es d'un vertex
  virtual CATSobDiag SetVertexCoordinates(CATSobVertex* iVertex, const double* iCoords);
  virtual CATSobDiag SetVertexCoordinates(CATSobVertex* iVertex, const double iX, const double iY, const double iZ);

  //Changement du poids d'un vertex
  virtual CATSobDiag SetVertexWeight(CATSobVertex* iVertex, const double iWeight);

  //Changement du sharpness d'une edge
  virtual CATSobDiag SetSharpnessOnEdge(CATSobEdge* iEdge, const short iSharpness);
  virtual CATSobDiag SetSharpnessOnEdge(CATSobEdge* iEdge, const short iSharpness, const CATBoolean iSmoothEdge);

  //Vivicit� d'une edge: G0 (FALSE) / G1 (TRUE)
  virtual CATSobDiag SetSmoothingOnEdge(CATSobEdge* iEdge, const CATBoolean iSmoothEdge);

  //Mise � jour des cellules autour d'un vertex
  virtual CATSobDiag SetVertexModified(CATSobVertex* iVertex, const int iNbRings);

  //Mise en modification d'une face
  virtual CATSobDiag SetFaceModified(CATSobFace* iSobFace);

  //Force la reconstruction topologique de l'image d'une face subdiv sur le body associ� (purement topo)
  virtual CATSobDiag SetForceTopoReconstruction(CATSobFace* iSobFace);


  /////////////////////////////////////////////////////////////////
  //-------------------- Gestion des d�tails --------------------//
  /////////////////////////////////////////////////////////////////

  //Set de d�tails
  virtual CATSobDiag SetDetail(CATSobFace* iFace, const int iU, const int iV, const int iLevel, const double* iDetail, const int iDaughterFaceIndex = 0);
  virtual CATSobDiag SetDetail(CATSobEdge* iEdge, const int iU, const int iLevel, const double* iDetail);
  virtual CATSobDiag SetDetail(CATSobVertex* iVertex, const int iLevel, const double* iDetail);

  //Ajout de d�tails
  virtual CATSobDiag AddDetail(CATSobFace* iFace, const int iU, const int iV, const int iLevel, const double* iDetail, const int iDaughterFaceIndex = 0);
  virtual CATSobDiag AddDetail(CATSobEdge* iEdge, const int iU, const int iLevel, const double* iDetail);
  virtual CATSobDiag AddDetail(CATSobVertex* iVertex, const int iLevel, const double* iDetail);

  //Suppression de d�tails
  virtual CATSobDiag RemoveDetail(CATSobFace* iFace, const int iU, const int iV, const int iLevel, const int iDaughterFaceIndex = 0);
  virtual CATSobDiag RemoveDetail(CATSobEdge* iEdge, const int iU, const int iLevel);
  virtual CATSobDiag RemoveDetail(CATSobVertex* iVertex, const int iLevel);

  //Suppression d'un niveau de d�tails
  virtual CATSobDiag RemoveLOD(CATSobFace* iFace, const int iLevel);
  virtual CATSobDiag RemoveLOD(CATSobEdge* iEdge, const int iLevel);

  //Suppression de tous les d�tails
  virtual CATSobDiag RemoveAllDetails();

  //Conversion des d�tails en local frame
  virtual CATSobDiag ConvertDetailsToLocalFrame();
  
  //Conversion des d�tails en global frame
  virtual CATSobDiag ConvertDetailsToGlobalFrame();


  /////////////////////////////////////////////////////////////////
  //---------- Modifications topologiques du base mesh ----------//
  /////////////////////////////////////////////////////////////////
  
  //Cr�ation du Current Mesh
  CATSobMesh* CreateCurrentMesh(CATSobMesh* iMesh, const CATBoolean iReportCellCreation = TRUE);

  //Cr�ation d'une face
  virtual CATSobDiag CreateFace(CATLISTP(CATSobEdge)& iEdgesOfFace, CATSobFace*& oNewFace);

  //Ajout de plusieurs faces dans un mesh (sans join !!!), possibilit� de suivi
  virtual CATSobDiag AddFaces(CATLISTP(CATSobFace)& iFacesToAdd, CATLISTP(CATSobFace)* ioCopiedFaces,
                              CATLISTP(CATSobEdge)* iInputEdges = 0, CATLISTP(CATSobEdge)* ioCopiedEdges = 0,
                              CATLISTP(CATSobVertex)* iInputVertices = 0, CATLISTP(CATSobVertex)* ioCopiedVertices = 0);

  //Destruction d'une face
  virtual CATSobDiag RemoveFace(CATSobFace* iFaceToRemove);

  //Cr�ation d'une edge
  virtual CATSobDiag CreateEdge(CATSobVertex* iStartVertex, CATSobVertex* iEndVertex, CATSobEdge*& oCreatedEdge);

  //Destruction d'une edge
  virtual CATSobDiag RemoveEdge(CATSobEdge* iEdgeToRemove, const int* iEdgeIndex = 0);

  //Cr�ation d'un vertex
  virtual CATSobDiag CreateVertex(const double* iVertexCoords, CATSobVertex*& oCreatedVertex);
  virtual CATSobDiag CreateVertex(const double iX, const double iY, const double iZ, CATSobVertex*& oCreatedVertex);

  //Destruction d'un vertex
  virtual CATSobDiag RemoveVertex(CATSobVertex* iVertexToRemove, const int* iVertexIndex = 0);

  //Merge de deux edges
  virtual CATSobDiag MergeEdges(CATSobEdge* iEdgeToKeep, CATSobEdge* iEdgeToMerge, const double iRatio = 0.5);

  //Merge de deux vertex
  virtual CATSobDiag MergeVertices(CATSobVertex* iVertexToKeep, CATSobVertex* iVertexToMerge, const double iRatio = 0.5);

  //Mise � jour du mesh courant
  virtual CATSobDiag UpdateCurrentMesh();

  //V�rification du mesh courant
  virtual CATSobDiag CheckCurrentMeshBasic(const CATBoolean iAllowNullCells = FALSE);
  virtual CATSobDiag CheckCurrentMesh(const CATBoolean iAllowNullCells = FALSE);

  //Activation/D�sactivation des checks sur le base mesh, par d�faut les checks sont actifs
  virtual void SetEnableChecks(const CATBoolean iOnOff);
  virtual CATBoolean GetEnableChecks() const;

  
  //DO NOT USE - Set des faces et vertex cr��s en externe
  virtual void SetNewSobFaces(CATLISTP(CATSobFace)& iNewSobFaces, const CATBoolean iReportCellCreation = TRUE);
  virtual void SetNewSobVertices(CATLISTP(CATSobVertex)& iNewSobVertices, const CATBoolean iReportCellCreation = TRUE);

  //DO NOT USE - Duplication
  virtual CATSobDiag Duplicate(CATSobMesh* iMeshForDuplication, CATSmoMeshTopoModifOperator** opDuplicatedOperator) const;

protected:

  //Destructeur
  virtual ~CATSmoMeshTopoModifOperatorImpl();

  //Set du diag
  CATSobDiag SetDiag(const CATSobDiag iDiag);

  //Distance au carr� entre deux points
  inline double SquareDistance(const double* iPt1, const double* iPt2);

  //Recopie des donn�es membres (sauf le mesh)
  virtual void CopyData(CATSmoMeshTopoModifOperatorImpl* iTopoModifOperatorDest) const;



  //----- Data:
  CATSobMesh* _CurrentMesh;
  CATSobDiag _Diag;
  CATBoolean _MustUpdateAfterCheck;
  CATBoolean _HasTopologyChanged;
  int _RefCount;

  CATBoolean _MustFollowCells, _MustCheckResultMesh;

};


//------------------------------
// Option de suivi de cellules
//------------------------------
inline CATBoolean CATSmoMeshTopoModifOperatorImpl::MustFollowCells() const
{
  return _MustFollowCells;
}


//-----------------------------
// Distance entre deux points
//-----------------------------
inline double CATSmoMeshTopoModifOperatorImpl::SquareDistance(const double* iPt1, const double* iPt2)
{
  if(iPt1 && iPt2)
    return (iPt1[0]-iPt2[0])*(iPt1[0]-iPt2[0])+(iPt1[1]-iPt2[1])*(iPt1[1]-iPt2[1])+(iPt1[2]-iPt2[2])*(iPt1[2]-iPt2[2]);
  else
    return -1.0;
}


#endif



