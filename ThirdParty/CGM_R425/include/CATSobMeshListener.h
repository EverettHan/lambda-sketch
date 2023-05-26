//======================================================================
// Copyright Dassault Systemes Provence 2009, All rights reserved
//======================================================================
//
// CATSobMeshListener.h
//
//======================================================================
//
// Usage notes: Mesh modification 'listener'.
//
//======================================================================
// December,    2021 : RBD : Ajout de OnChangeEdgeSmoothing () avec iNewSmoothingSwitch pour IR-898878
// December,    2009 : RAQ : Cr�ation
//======================================================================
#ifndef CATSobMeshListener_H
#define CATSobMeshListener_H

//Pour l'export
#include "CATSobObjects.h"

//Divers
#include "CATSobDiag.h"

class CATSobFace;
class CATSobEdge;
class CATSobVertex;


class ExportedByCATSobObjects CATSobMeshListener
{
public:
  
  //Destructeur
  virtual ~CATSobMeshListener();

  //Gestion r�f�rences
  int AddRef();
  void Release();
 
  //R�cup�ration du diag
  CATSobDiag GetDiag() const;

  //Callbacks de cr�ation, envoy�s APRES la cr�ation effective de la cellule
  virtual CATSobDiag CreateFaceEvent(CATSobFace* iNewCreatedFace);
  virtual CATSobDiag CreateHoleFaceEvent(CATSobFace* iNewCreatedFace);
  virtual CATSobDiag CreateEdgeEvent(CATSobEdge* iNewCreatedEdge);
  virtual CATSobDiag CreateVertexEvent(CATSobVertex* iNewCreatedVertex);

  //Callbacks de suppression, envoy�s AVANT la suppression effective de la cellule
  virtual CATSobDiag RemoveFaceEvent(CATSobFace* iFaceToRemove);
  virtual CATSobDiag RemoveHoleFaceEvent(CATSobFace* iFaceToRemove);
  virtual CATSobDiag RemoveEdgeEvent(CATSobEdge* iEdgeToRemove);
  virtual CATSobDiag RemoveVertexEvent(CATSobVertex* iVertexToRemove);
  virtual CATSobDiag OnReplaceVertex(CATSobEdge* ipEdge, CATSobVertex* ipOldVertex, CATSobVertex* ipNewVertex);

  //Callback envoy� AVANT la mise � jour du mesh
  virtual CATSobDiag PrepareToUpdateMeshEvent();

  //Callback envoy� APRES la mise � jour du mesh
  virtual CATSobDiag UpdateMeshEvent();

  //Callback de modification de la g�om�trie, envoy�s APRES la modification
  virtual CATSobDiag OnChangeVertexCoordinates(CATSobVertex* iVertex);
  virtual CATSobDiag OnChangeVertexWeight(CATSobVertex* iVertex);
  virtual CATSobDiag OnChangeEdgeSharpness(CATSobEdge* iEdges, const short iNewSharpness);
  virtual CATSobDiag OnChangeEdgeSmoothing(CATSobEdge* iEdge);
  virtual CATSobDiag OnChangeEdgeSmoothing(CATSobEdge* iEdge, const CATBoolean iNewSmoothingSwitch);

protected:

  //Constructeur
  CATSobMeshListener();

  //Set du diag
  CATSobDiag SetDiag(const CATSobDiag iDiag);


  //---------- Protected data:
  CATSobDiag _Diag;


private:


  //---------- Private data:
  int _RefCounter;

};

#endif

