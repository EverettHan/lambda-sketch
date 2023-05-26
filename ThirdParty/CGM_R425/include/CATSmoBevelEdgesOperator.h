//======================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//======================================================================
//
// CATSmoBevelEdgesOperator.h
//
//======================================================================
//
// Usage notes:
//
//======================================================================
// April,   2009 : RAQ : Creation
//======================================================================
#ifndef CATSmoBevelEdgesOperator_H
#define CATSmoBevelEdgesOperator_H

//Pour l'export
#include "CATSmoOperators.h"

//Classe m�re
#include "CATSmoSubdivisionMeshOperator.h"

//Types de bevel
#include "CATSmoBevelType.h"
#include "CATSobDiag.h"
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"

class CATSobMesh;
class CATSmoMeshTopoModifOperator;
class CATLISTP(CATSobEdge);
class CATSmoBevelUserProfile;
class CATSmoBevelUserProfileParameters;
#include <vector>


class ExportedByCATSmoOperators CATSmoBevelEdgesOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoBevelEdgesOperator();

  //Set des edges
  virtual void SetEdges(const CATLISTP(CATSobEdge)& iEdgesList, const double iLength, const int iNbRoundingCuts=0) = 0;

  //Type de bevel
  virtual void SetType(const CATSmoBevelType iType) = 0;

  //Amelioration des extremites de bevel
  virtual void SetAdvancedBevel(const  CATBoolean iLocalTransitionVertices = TRUE) = 0;
  
 // les profils utilisateurs 
  virtual void SetAdvancedProfile(const std::vector <int> iVertexTags, const CATSmoBevelUserProfile& iVerticesOneProfile, const std::vector <CATSmoBevelUserProfileParameters>& iParams)=0;
  virtual void SetAdvancedProfile(const std::vector <int> iVertexTags, const std::vector<CATSmoBevelUserProfile>& iVerticesProfiles, const std::vector <CATSmoBevelUserProfileParameters>& iParams)=0;
  
  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight)
  ///permet de setter l'AutoWeight s'il y a des profils .Par defaut a TRUE dans le constructeur 
  virtual void SetAutoWeightForProfiles(const CATBoolean iAutoWeight)=0; 
  
  ///permet de setter l'AutoWeight s'il y a des profils. Par defaut a 1 dans le constructeur
  virtual void SetAutoWeightForProfiles(const int& iAutoWeight) = 0;

  //Option : pas de faces ngones pour les vertex internes (/!\ modifie les mesh lines)
  virtual void SetAvoidNGonsOnInternalBeveledVertices() = 0;

  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight)
  //Option : Sharpness sur les nouvelles edges de chaque c�t� du bevel
  virtual void SetSharpnessOnSideEdges(const short iSharpness, const CATBoolean iSmoothEdge, const CATBoolean iAutoWeight = FALSE) = 0;
 
  //Option : Sharpness sur les nouvelles edges de chaque c�t� du bevel
  virtual void SetSharpnessOnSideEdges(const short iSharpness, const CATBoolean iSmoothEdge, const int& iAutoWeight) = 0;

  //Analyse et r�cup�ration de la longueur max de bevel autoris�e, les edges doivent avoir �t� donn�es
  virtual CATSobDiag GetMaxBevelLength(double& oMaxLength) = 0;


  //-------------------------- For debug purpose --------------------------//
  //Print messages (default is no)
  virtual void SetVerbose(const CATBoolean iIsVerbose) = 0;
  
protected:

  //Constructeur
  CATSmoBevelEdgesOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

  //Run de l'op�rateur
  virtual CATSobDiag RunOperator() = 0;


};


//M�thode de cr�ation de l'op�rateur
ExportedByCATSmoOperators
CATSmoBevelEdgesOperator* CATSmoCreateBevelEdgesOperator(CATSobMesh* iMesh, 
                                                         CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);

#endif

