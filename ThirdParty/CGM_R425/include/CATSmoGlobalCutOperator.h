//=================================================================================
// Copyright Dassault Systemes Provence 2006, All Rights Reserved 
//=================================================================================
//
// CATSmoGlobalCutOperator.h
//
//=================================================================================
//
// Usage notes:
//
//=================================================================================
// April,    2021 : RBD : Ajout methode GetCreatedEdges for SPARK
// 06.01.2017     : RAQ : Ajout set multi-param�tres pour la sym�trie
// January,  2016 : RBD : Ajout methode GetAllCuttedEdgesByVTags
// January,  2006 : RAQ : Creation
//=================================================================================
#ifndef CATSmoGlobalCutOperator_H
#define CATSmoGlobalCutOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoSubdivisionMeshOperator.h"

//Monocodage OS
#include "CATLib.h"

//STL
#ifdef _AIX_SOURCE
#undef throw
#endif  //_AIX_SOURCE
#include <vector>

class CATSobMesh;
class CATSobEdge;
class CATSmoMeshTopoModifOperator;
class CATSmoGlobalCutParameter;


class ExportedByCATSmoOperators CATSmoGlobalCutOperator: public CATSmoSubdivisionMeshOperator
{
public:
 
  //Destructeur
  virtual ~CATSmoGlobalCutOperator();

  //Set mono-param�tre : un AddRef est fait par l'op�rateur sur ipParam
  virtual void SetEdgeToCut(CATSmoGlobalCutParameter* ipParam) = 0;

  //Set multi-param�tres : un AddRef est fait par l'op�rateur sur chacun des param�tres
  virtual void SetEdgesToCut(const std::vector<CATSmoGlobalCutParameter*>& iParams) = 0;

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
  //Multi-parameters set : parameters are not addreferenced by the operator, but the operator will release them.
  //This signature is useful if you just want to give the parameters to the operator and then you don't care about them anymore.
  virtual void SetEdgesToCut(std::vector<CATSmoGlobalCutParameter*>&& ioParams) = 0;
#endif  //_WINDOWS_SOURCE || _LINUX_SOURCE

  //DEPRECATED : use cut-parameters services instead
  //Set de l'edge � d�couper
  virtual void SetEdgeToCut(CATLISTP(CATSobEdge)* iEdgesToCut) = 0;
  virtual void SetEdgeToCut(CATSobEdge* iEdge) = 0;

  //DEPRECATED : use cut-parameters services instead
  //Set du nombre de d�coupes et des ratios
  virtual void SetNbCutsAndRatios(const int iNbCuts = 1, const double* iRatios = NULL) = 0;

  //Get des edges coup�es
  virtual CATSobDiag GetAllCuttedEdges(CATListOfInt*& oCuttedEdgesListByVTags) = 0;

  // Get des edges cr�es 
  virtual CATSobDiag GetCreatedEdges(const unsigned int iInputStartVTag, const unsigned int iInputEndVTag, CATLISTP(CATSobEdge)*& oCreatedEdgesList) = 0;

protected:
  //Constructeur
  CATSmoGlobalCutOperator(CATSobMesh*                  iMesh,
                          CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);
};


//M�thode de cr�ation globale
ExportedByCATSmoOperators
CATSmoGlobalCutOperator* CATSmoCreateGlobalCutOperator(CATSobMesh* iMeshToCut,
                                                       CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);




#endif


