//=======================================================================================
// Copyright Dassault Systemes Provence 2006, All Rights Reserved 
//=======================================================================================
//
// CATSobMeshProtected.h
//
//=======================================================================================
//
// Usage notes: ***************** DON'T INCLUDE THIS HEADER *****************
//              Classe n'exposant en Protected que les m�thodes de CATSobMesh
//              dont les services ne sont pas ouverts aux utilisateurs mais
//              utilisables par les frameworks de subdivision
//
//=======================================================================================
// April,      2021 : RJY1: D�placement de SetTagOnVertex vers la classe CATSobMeshBase      
// January,    2008 : RAQ : D�placement des m�thodes GetMaxTagXXX de protected � public
// December,   2006 : RAQ : Ajout gestion freeze du mesh
// February,   2006 : RAQ : Cr�ation
//=======================================================================================
#ifndef CATSobMeshProtected_H
#define CATSobMeshProtected_H


//Check de la possibilit� d'inclure ce fichier
/*
#infdef XXXXX
#error Interdiction de tirer cette interface
#endif
*/


//Classe m�re
#include "CATSobMesh.h"



class CATSobMeshProtected: public CATSobMesh
{
public:

  //Destructeur
  virtual ~CATSobMeshProtected();

  //S�paration de vertex
  virtual CATSobDiag SeparateVertex(CATSobVertex* iVertexToSeparate, CATLISTP(CATSobVertex)* oNewVerticesList = 0) = 0;

  //Merge de deux vertex: iVertex1 est conserv� et iVertex2 est supprim�
  //0.0 (iVertex1) <= Ratio <= 1.0 (iVertex2), ratio lin�aire
  virtual CATSobDiag MergeVertices(CATSobVertex* iVertex1, CATSobVertex* iVertex2, const double iRatio = 0.5) = 0;

  //Merge de deux edges, Edge1 est conserv�e et Edge2 est supprim�e
  virtual CATSobDiag MergeEdges(CATSobEdge* iEdge1, CATSobEdge* iEdge2, const double iRatio = 0.5) = 0;

  //Changement d'orientation d'une sous partie connexe du mesh (pas de gestion des d�tails)
  virtual CATSobDiag ReverseOrientation(CATLISTP(CATSobFace)* iConnexZoneFaces, CATLISTP(CATSobEdge)* iConnexZoneEdges) = 0;

  //Echange de la DirectFace et de l'InvertFace d'une edge (InvertFace doit exister)
  virtual CATSobDiag SwapDirectAndInvertFaceOfEdge(CATSobEdge* iEdge) = 0;

  //Set du tag d'une face
  virtual void SetTagOnFace(CATSobFace* iFace, const unsigned int iTagForFace) = 0;

  //Freeze du mesh
  //virtual void SetFreezeMesh(const CATBoolean iMustFreeze) = 0;
 
  // DELETED : virtual CATBoolean IsMeshFrozen() = 0;

  //Compactage des listes internes de cellules (suppression des �l�ments nuls)
  virtual void CompactCellsList() = 0;


protected:

  //Constructeur
  CATSobMeshProtected();


private:

  //Copy constructor and equal operator
  CATSobMeshProtected(CATSobMeshProtected&);
  CATSobMeshProtected& operator=(CATSobMeshProtected&);


};

#endif



