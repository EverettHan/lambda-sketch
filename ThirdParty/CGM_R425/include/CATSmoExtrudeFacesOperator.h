//======================================================================
// Copyright Dassault Systemes Provence 2006-2007, all rights reserved 
//======================================================================
//
// CATSmoExtrudeFacesOperator.h
//
//======================================================================
//
// Usage notes:
//
//======================================================================
// February,     2023 : RBD : Ajout SetAutoWeight() : iAutoWeight prend maintenant les valeurs 0 � 3 inclus.
// January,      2021 : RBD : Implementation GetTopFaceTag()
// 27.02.2017         : RAQ : Ajout set multi-param�tres pour la sym�trie
// March,        2014 : RBD : Ajout GetResultType()
// March,        2014 : RBD : Ajout de l'option extrusion pure unitaire
// January,      2014 : RBD : Ajout option fermeture du mod�le
// January,      2014 : RBD : R�-architecture, ajout SetLength(), GetLength(), ...
// September,    2009 : RBD : AutoWeight sur les sommets des faces selectionnees si SetAutoWeightOnSelectedVertices
// August,       2008 : RBD : Possibilite d'inverser le sens de l'extrusion
// 21-11-07 MMO Correction des erreurs BAD004 (headerruler)
// 01-11-06 RBD Creation
//======================================================================
#ifndef CATSmoExtrudeFacesOperator_H
#define CATSmoExtrudeFacesOperator_H

//Pour l'h�ritage
#include "CATSmoSubdivisionMeshOperator.h"

//Pour l'export
#include "CATSmoOperators.h"

//Objets subdivision
#include "CATSobDiag.h"
#include "CATSobListOfFace.h"

//Divers
#include "CATBoolean.h"
#include "CATLib.h" //Monocodage OS

//STL
#ifdef _AIX_SOURCE
#undef throw
#endif  //_AIX_SOURCE
#include <vector>

class CATSobMesh;
class CATSmoMeshTopoModifOperator;
class CATSmoExtrudeFacesParameter;



class ExportedByCATSmoOperators CATSmoExtrudeFacesOperator: public CATSmoSubdivisionMeshOperator
{
public:

  //Destructeur
  virtual ~CATSmoExtrudeFacesOperator();

  //Mono-parameter set : ipParam is addreferenced by the operator, it is also released with it.
  virtual void SetFacesToExtrude(CATSmoExtrudeFacesParameter* ipParam) = 0;

  //Multi-parameters set : parameters are all addreferenced by the operator, they're also released with it.
  virtual void SetFacesToExtrude(const std::vector<CATSmoExtrudeFacesParameter*>& iParams) = 0;

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
  //Multi-parameters set : parameters are not addreferenced by the operator, but the operator will release them.
  //This signature is useful if you just want to give the parameters to the operator and then you don't care about them anymore.
  virtual void SetFacesToExtrude(std::vector<CATSmoExtrudeFacesParameter*>&& ioParams) = 0;
#endif  //_WINDOWS_SOURCE || _LINUX_SOURCE

  // After Run(), return the tag > 0 of top face of the extrusion of input face given by his tag iInputFaceTag > 0
  // return a diag if there is no top face :
  //     return CATSobDiag_InputNullFace if the input face tag iInputFaceTag is 0
  //     return CATSobDiag_FaceNull if there is no top face associated to iInputFaceTag;
  //     return CATSobDiag_OK if there is a valid result
  virtual CATSobDiag GetTopFaceTag(const unsigned int iInputFaceTag, unsigned int &oTopFaceTag) = 0;


  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  //Extrusion d'une liste de faces
  virtual void SetFacesToExtrude(CATLISTP(CATSobFace)* iFacesToExtrude) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // Inversion du sens de l'extrusion par rapport � la normale � la surface
  // (VRAI par defaut)
  virtual void SetInvertXtrudeDir(const CATBoolean iInvertNormal = TRUE) = 0;

  // DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight)
  // Activation du poid automatique sur les vertex DES FACES SELECTIONNEES.
  // Pour activer le report automatique du poids des edges DES FACES SELECTIONNEES vers les vertex commun, 
  // mettre iAutoWeight � TRUE.
  // Il faut qu'il y ai au moins 3 edges de poids > 0 pour que le poids du vertex commun soit modifi�.
  // Pour d�sactiver le poids automatique, remettre iAutoWeight � FALSE.
  virtual void SetAutoWeightOnSelectedVertices(const CATBoolean iAutoWeight = FALSE) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // Activation du poid automatique sur les vertex DES FACES SELECTIONNEES.
  // Pour activer le report automatique du poids des edges DES FACES SELECTIONNEES vers les vertex commun, 
  // mettre iAutoWeight > 0 (valeur recommand�e : 3).
  // Il faut qu'il y ai au moins 3 edges de poids > 0 pour que le poids du vertex commun soit modifi�.
  // Pour d�sactiver le poids automatique, remettre iAutoWeight � 0.
  virtual void SetAutoWeight(const int& iAutoWeight) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // D�fini le mode d'extrusion
  // Fill/join/merge pour 2 � 5 faces connexes : iPureExtrusion = 0
  // Extrusion pure : iPureExtrusion = 1
  // Extrusion pure unitaire : iPureExtrusion = 2
  // Defaut : iPureExtrusion = 0
  virtual void SetPureExtrusion(const int iPureExtrusion = 0) = 0;
 
  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  //------ Extrusion Length  (Only available with the PureExtrusion case) :
  // Set Length
  // Set the extrusion length :
  // USER'S MODE if iLength > 0.0 (the extrusion length is defined by iLength)
  // AUTO MODE if iLength <= 0.0 (the extrusion length is defined automatically by the system)
  virtual void SetLength(const double iLength) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // Get Length  (Only available with the PureExtrusion case) : 
  // return the extrusion length AFTER running the operator (else return -1.0)
  virtual void GetLength(double &oLength) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  //------ fermeture de l'extrusion si possible  (Only available with the PureExtrusion case) :
  // Set de la fermeture (Recopie des faces initiales SI POSSIBLE)
  virtual void SetCloseXtrude(const CATBoolean iCloseXtrude = FALSE) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // Get :Retourne le statut sur la fermeture de l'extrusion
  virtual void GetCloseXtrude(CATBoolean &oCloseXtrude) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // Poids sur les edges libres des faces s�lectionn�es (utile seulement si fermeture de l'extrusion)
  // Le poids varie entre -100 et +100 (999 = edge libre, on ne fait rien).
  // Si un poids est > 0, l'edge est marqu�e smooth.
  // Si un poids est < 0, l'edge est marqu�e sharp.
  virtual void SetWeightOnFreeEdges(const int iFreeWeight = 999) = 0;

  //DEPRECATED : Use CATSmoExtrudeFacesParameter instead
  // Get du type de r�sultat produit par l'op�rateur
  // 0 = CATStoXtrudeFacesResUndef,
  // 1 = CATStoXtrudeFacesResFill,
  // 2 = CATStoXtrudeFacesResJoin, 
  // 3 = CATStoXtrudeFacesResMerge,
  // 4 = CATStoXtrudeFacesResXtrusionPure,
  // 5 = CATStoXtrudeFacesResXtrusionPureUnitaire
  virtual int GetResultType() = 0;

protected:

  //Constructeur
  CATSmoExtrudeFacesOperator(CATSobMesh* iMesh, CATSmoMeshTopoModifOperator* iTopoModifOpe);

  //Run de l'op�rateur
  virtual CATSobDiag RunOperator() = 0;

};


//M�thode de cr�ation de l'op�rateur
//Operateur general
ExportedByCATSmoOperators
CATSmoExtrudeFacesOperator* CATSmoCreateExtrudeFacesOperator(CATSobMesh* iMesh, 
                                                             CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


//M�thode de cr�ation de l'op�rateur
//Operateur d'extrusion pure
ExportedByCATSmoOperators
CATSmoExtrudeFacesOperator* CATSmoCreateExtrudeNFacesOperator(CATSobMesh* iMesh, 
                                                              CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);

//M�thode de cr�ation de l'op�rateur
//Operateur d'extrusion/fill/join/merge 2 � 5 faces
ExportedByCATSmoOperators
CATSmoExtrudeFacesOperator* CATSmoCreateExtrudeFillJoinMergeFacesOperator(CATSobMesh* iMesh, 
                                                                          CATSmoMeshTopoModifOperator* iTopoModifOpe = 0);


#endif

