//=================================================================================
// Copyright Dassault Systemes Provence 2017, All Rights Reserved
//=================================================================================
//
// CATSmoJoinMeshesParameter.h
//
//=================================================================================
//
// Usage notes : Parameters for CATSmoJoinMeshesOperator
//
//=================================================================================
// 23.01.2023 : RBD : Appel SetEdgeWeight() : _AutoWeight prend maintenant les valeurs 0 � 3 inclus.
// 18.02.2021 : RBD : join par selection de faces
// 23.03.2017 : RAQ : Creation
//=================================================================================
#ifndef CATSmoJoinMeshesParameter_H
#define CATSmoJoinMeshesParameter_H

//Pour l'export
#include "CATSmoOperators.h"

//Monocodage OS
#include "CATLib.h"

//Subdivision
#include "CATSobAddRefRelease.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfFace.h"

//Divers
#include "CATBoolean.h"

class CATSobMesh;
class CATSobFace;
class CATSobEdge;
class CATSobVertex;


class ExportedByCATSmoOperators CATSmoJoinMeshesParameter
{
  SOB_DECLARE_ADDREF_RELEASE

public:

  //---- Constructors :
  //Default
  CATSmoJoinMeshesParameter();

  //Copy constructor (warning ref counter is not duplicated)
  CATSmoJoinMeshesParameter(const CATSmoJoinMeshesParameter& iToCopy);

  //------------------------------ Loop ouverte
  //Set de la couture dans le cas d'un merge (interne � un mesh) - Loop ouverte
  //Les deux listes doivent avoir la m�me taille
  CATSmoJoinMeshesParameter(CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                            CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2);

  //Set de la couture dans le cas d'un join (entre deux mesh) - Loop ouverte
  //Les deux listes doivent avoir la m�me taille
  //iMeshSrc n'est pas add-r�f�renc�
  CATSmoJoinMeshesParameter(CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                            CATSobMesh* iMeshSrc, CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2);

  //------------------------------ Loop ferm�e
  //Set de la couture dans le cas d'un merge (interne � un mesh) sans intersections entre les fronti�res - Loop ferm�e
  //Les deux listes doivent avoir la m�me taille
  CATSmoJoinMeshesParameter(CATLISTP(CATSobEdge)& iBoundarySide1, CATLISTP(CATSobEdge)& iBoundarySide2);

  //Set de la couture dans le cas d'un join (entre deux mesh) sans intersections entre les fronti�res - Loop ferm�e
  //Les deux listes doivent avoir la m�me taille
  //iMeshSrc n'est pas add-r�f�renc�
  CATSmoJoinMeshesParameter(CATLISTP(CATSobEdge)& iBoundarySide1,
                            CATSobMesh* iMeshSrc, CATLISTP(CATSobEdge)& iBoundarySide2);

  //------------------------------ API plus g�n�rique
  //Cas du merge (m�me mesh), gestion loop ouverte ou ferm�e
  CATSmoJoinMeshesParameter(const CATLISTP(CATSobEdge)& iBoundaryEdges1,
                            const CATLISTP(CATSobFace)& iBoundaryEdgesAfterRemoveFaces, const CATBoolean iReverseBoundaryEdgesAfterRemoveFacesOrder = FALSE);
  CATSmoJoinMeshesParameter(const CATLISTP(CATSobFace)& iBoundaryEdgesAfterRemoveFaces1,
                            const CATLISTP(CATSobFace)& iBoundaryEdgesAfterRemoveFaces2, const CATBoolean iReverseBoundaryEdgesAfterRemoveFacesOrder2 = FALSE);


  // Set de la couture dans le cas d'un merge (interne � un mesh) par s�lection de faces
  // Chaque ensemble de faces ne doit donner qu'une loop, ouverte ou ferm�e.
  CATSmoJoinMeshesParameter(CATLISTP(CATSobFace)& iFacesToJoin1, CATLISTP(CATSobFace)& iFacesToJoin2);


  // Set de la couture dans le cas d'un join (entre deux mesh) par s�lection de faces
  // Chaque ensemble de faces ne doit donner qu'une loop, ouverte ou ferm�e.
  // iMeshSrc n'est pas add-r�f�renc�
  CATSmoJoinMeshesParameter(CATLISTP(CATSobFace)& iFacesToJoin, CATSobMesh* iMeshSrc, CATLISTP(CATSobFace)& iFacesToJoinSrc);


  //---- Options :
  
  //Option d'insertion de points entre les deux bords
  virtual void SetInsertVerticesMode();

  //Option: merge simple en cas de symm�trie
  virtual void SetJustMergeWhenSymmetric(const double iRatio = 0.5);

  //Option de sharpness sur les edges de jointure
  virtual void SetSharpnessOnJunctions();

  // Poids sur les edges de jointure
  // Le poids varie entre -100 et +100.
  // Si un poids est > 0, l'edge est marqu�e smooth.
  // Si un poids est < 0, l'edge est marqu�e sharp.
  virtual void SetWeightOnBoundaries(const int iWeightOnBoundaries = 100);

  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight)
  // Activation du poids automatique sur les vertex.
  virtual void SetAutoWeight(const CATBoolean iAutoWeight = TRUE);

  // Activation du poids automatique sur les vertex.
  virtual void SetAutoWeight(const int& iAutoWeight);

  //Resampling des vertex sur le bord
  virtual void SetEnableVerticesResampling();

  //---- Services :

  // Initialisation des listes d'edges
  void InitBoundaries(CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                      CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2);


  //---- Data :
  CATSobMesh* _MeshSrc;
  double _MergeRatio;

  CATSobVertex *_InputBoundaryVertices1[2], *_InputBoundaryVertices2[2];
  CATLISTP(CATSobEdge) _InputBoundaryEdges1, _InputBoundaryEdges2;
  CATLISTP(CATSobFace) _InputFaces1, _InputFaces2;

  CATBoolean _IsJoinMode, _IsClosedBorderLoop, _IgnoreInvalidConnexityError, _JustMergeWhenSymmetric;
  CATBoolean _MustInsertVertices, _AddSharpnessOnJunctions, _EnableVerticesResampling;

  short _Sharpness;
  CATBoolean _Smooth, _AutoWeight;

protected:

  //Destructor
  virtual ~CATSmoJoinMeshesParameter();

};
 
#endif  //CATSmoJoinMeshesParameter_H
  
  


