//=================================================================================
// Copyright Dassault Systemes Provence 2006, All Rights Reserved 
//=================================================================================
//
// CATSmoJoinMeshesOperator.h
//
//=================================================================================
//
// Usage notes: Join de deux mesh
//              /!\: Pas de cr�ation de faces triangulaires
//              /!\: Les deux bords doivent avoir le m�me nombre d'edges
//
//=================================================================================
// August,	  2011 : RBD : Gestion des poids sur les ar�tes du joint + AutoWeight sur les sommets
// December,  2007 : RAQ : Enfin un vrai op�rateur de join :)
// February,  2006 : RAQ : Creation
//=================================================================================
#ifndef CATSmoJoinMeshesOperator_H
#define CATSmoJoinMeshesOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoSubdivisionMeshOperator.h"

//Objets Subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"
#include "CATSobListOfEdge.h"

//Monocodage OS
#include "CATLib.h"

//STL
#ifdef _AIX_SOURCE
#undef throw
#endif  //_AIX_SOURCE
#include <vector>

class CATSobMesh;
class CATSobVertex;
class CATSmoJoinMeshesParameter;


class ExportedByCATSmoOperators CATSmoJoinMeshesOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoJoinMeshesOperator();

  //Set mono-param�tre : un AddRef est fait par l'op�rateur sur ipParam
  virtual void SetParam(CATSmoJoinMeshesParameter* ipParam) = 0;

  //Set multi-param�tres : un AddRef est fait par l'op�rateur sur chacun des param�tres
  virtual void SetParams(const std::vector<CATSmoJoinMeshesParameter*>& iParams) = 0;

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
  //Multi-parameters set : parameters are not addreferenced by the operator, but the operator will release them.
  //This signature is useful if you just want to give the parameters to the operator and then you don't care about them anymore.
  virtual void SetParams(std::vector<CATSmoJoinMeshesParameter*>&& ioParams) = 0;
#endif  //_WINDOWS_SOURCE || _LINUX_SOURCE
  


  //DEPRECATED : use parameters services instead
  //Option d'insertion de points entre les deux bords
  virtual void SetInsertVerticesMode() = 0;

  //DEPRECATED : use parameters services instead
  //Option: merge simple en cas de symm�trie
  virtual void SetJustMergeWhenSymmetric(const double iRatio = 0.5) = 0;

  //DEPRECATED : use parameters services instead
  //Option de sharpness sur les edges de jointure
  virtual void SetSharpnessOnJunctions() = 0;

  //DEPRECATED : use parameters services instead
  // Poids sur les edges de jointure
  // Le poids varie entre -100 et +100.
  // Si un poids est > 0, l'edge est marqu�e smooth.
  // Si un poids est < 0, l'edge est marqu�e sharp.
  virtual void SetWeightOnBoundaries(const int iWeightOnBoundaries = 100) = 0;
 
  //DEPRECATED : use parameters services instead
  // Activation du poids automatique sur les vertex.
  virtual void SetAutoWeight(const CATBoolean iAutoWeight = 1) = 0;

  //DEPRECATED : use parameters services instead
  //Resampling des vertex sur le bord
  virtual void SetEnableVerticesResampling() = 0;

  //DEPRECATED : use parameters services instead
  //Set de la couture dans le cas d'un merge (interne � un mesh) - Loop ouverte
  //Les deux listes doivent avoir la m�me taille
  virtual CATSobDiag SetBoundaries(CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                                   CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2) = 0;

  //DEPRECATED : use parameters services instead
  //Set de la couture dans le cas d'un join (entre deux mesh) - Loop ouverte
  //Les deux listes doivent avoir la m�me taille
  virtual CATSobDiag SetBoundaries(CATSobVertex* iStartVertex1, CATLISTP(CATSobEdge)& iBoundarySide1, CATSobVertex* iEndVertex1,
                                   CATSobMesh* iMeshSrc, CATSobVertex* iStartVertex2, CATLISTP(CATSobEdge)& iBoundarySide2, CATSobVertex* iEndVertex2) = 0;

  //DEPRECATED : use parameters services instead
  //Set de la couture dans le cas d'un merge (interne � un mesh) sans intersections entre les fronti�res - Loop ferm�e
  //Les deux listes doivent avoir la m�me taille
  virtual CATSobDiag SetBoundaries(CATLISTP(CATSobEdge)& iBoundarySide1, CATLISTP(CATSobEdge)& iBoundarySide2) = 0;

  //DEPRECATED : use parameters services instead
  //Set de la couture dans le cas d'un join (entre deux mesh) sans intersections entre les fronti�res - Loop ferm�e
  //Les deux listes doivent avoir la m�me taille
  virtual CATSobDiag SetBoundaries(CATLISTP(CATSobEdge)& iBoundarySide1,
                                   CATSobMesh* iMeshSrc, CATLISTP(CATSobEdge)& iBoundarySide2) = 0;

protected:
  
  //Constructeur
  CATSmoJoinMeshesOperator(CATSobMesh* iMesh,
                           CATSmoMeshTopoModifOperator* iTopoModifOpe);

};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoJoinMeshesOperator* CATSmoCreateJoinMeshesOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif



