//======================================================================
// Copyright Dassault Systemes Provence 2017, All Rights Reserved
//======================================================================
//
// CATSmoExtrudeFacesParameter.h
//
//======================================================================
//
// Usage notes : Param�tres pour l'op�rateur CATSmoExtrudeFacesOperator
//
//======================================================================
// 23.01.2023 : RBD : Nouvelle m�thode SetAutoWeight() 
//                    remplace SetAutoWeightOnSelectedVertices() : 
//                    _AutoWeight prend maintenant les valeurs 0 � 3 inclus.
// 24.12.2020 : RBD : re-ecriture GetLength() pour avoir une init AVANT le Run()
//                    Ajout methode GetImgPoint()
// 13.04.2017 : RBD : GetResult() retourne un CATSobXtrudeFacesResultType
// 23.02.2017 : RAQ : Creation
//======================================================================
#ifndef CATSmoExtrudeFacesParameter_H
#define CATSmoExtrudeFacesParameter_H

//Pour l'export
#include "CATSmoOperators.h"

//Monocodage OS
#include "CATLib.h"

//Subdivision
#include "CATSobAddRefRelease.h"
#include "CATSobListOfFace.h"
#include "CATSobXtrudeFacesResultType.h" 
#include "CATSobDiag.h"

//Divers
#include "CATBoolean.h"
#include "CATMathPoint.h"

#define RBD_NEW_LENGTH // cf. CATSmoExtrudeFacesParameter.h


class CATSobEdge;
class CATSobFace;

class ExportedByCATSmoOperators CATSmoExtrudeFacesParameter
{
  SOB_DECLARE_ADDREF_RELEASE;

public:

  //Constructeurs
  CATSmoExtrudeFacesParameter(const CATLISTP(CATSobFace)& iFacesToExtrude);
  CATSmoExtrudeFacesParameter(const CATSmoExtrudeFacesParameter& iToCopy);

  ////Extrusion d'une liste de faces
  //void SetFacesToExtrude(CATLISTP(CATSobFace)* iFacesToExtrude) = 0;

  // Inversion du sens de l'extrusion par rapport � la normale � la surface
  // (VRAI par defaut, cad vers l'ext�rieur en cas de surface ferm�e)
  void SetInvertXtrudeDir(const CATBoolean iInvertNormal = TRUE);

  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight)
  // Activation du poid automatique sur les vertex DES FACES SELECTIONNEES.
  void SetAutoWeightOnSelectedVertices(const CATBoolean iAutoWeight = FALSE);

  // Activation du poid automatique sur les vertex DES FACES SELECTIONNEES.
  // Pour activer le report automatique du poids des edges DES FACES SELECTIONNEES vers les vertex commun, 
  // mettre iAutoWeight > 0.
  // Il faut qu'il y ai au moins 3 edges de poids > 0 (et < 999) pour que le poids du vertex commun soit modifi�.
  // Valeurs admises : 0 � 3.
  // Pour activer le report automatique du poids des edges vers les vertex commun, 
  // mettre iAutoWeight > 0.
  // 1 = poids maxi, valeur conseill�e = 3.
  // Pour d�sactiver le poids automatique, remettre iAutoWeight � 0.
  void SetAutoWeight(const int& iAutoWeight);


  // D�fini le mode d'extrusion
  // Fill/join/merge pour 2 � 5 faces connexes : iPureExtrusion = 0
  // Extrusion pure : iPureExtrusion = 1
  // Extrusion pure unitaire : iPureExtrusion = 2
  // Defaut : iPureExtrusion = 0
  void SetPureExtrusion(const int iPureExtrusion = 0);

  //------ Extrusion Length  (Only available with the PureExtrusion case) :
  // Set Length
  // Set the extrusion length :
  // USER'S MODE if iLength > 0.0 (the extrusion length is defined by iLength)
  // AUTO MODE if iLength <= 0.0 (the extrusion length is defined automatically by the system)
  void SetLength(const double iLength);

  // Get Length  (Only available with the PureExtrusion case) : 
  // return the extrusion length BEFORE (for initialisation) or AFTER running the operator
  void GetLength(double &oLength);

  //------ fermeture de l'extrusion si possible  (Only available with the PureExtrusion case) :
  // Set de la fermeture (Recopie des faces initiales SI POSSIBLE)
  void SetCloseXtrude(const CATBoolean iCloseXtrude = FALSE);

  // Get :Retourne le statut sur la fermeture de l'extrusion
  void GetCloseXtrude(CATBoolean &oCloseXtrude);

  // Poids sur les edges libres des faces s�lectionn�es (utile seulement si fermeture de l'extrusion)
  // Le poids varie entre -100 et +100 (999 = edge libre, on ne fait rien).
  // Si un poids est > 0, l'edge est marqu�e smooth.
  // Si un poids est < 0, l'edge est marqu�e sharp.
  void SetWeightOnFreeEdges(const int iFreeWeight = 999);

  // Get du type de r�sultat produit par l'op�rateur
  // 0 = CATStoXtrudeFacesResUndef,
  // 1 = CATStoXtrudeFacesResFill,
  // 2 = CATStoXtrudeFacesResJoin, 
  // 3 = CATStoXtrudeFacesResMerge,
  // 4 = CATStoXtrudeFacesResXtrusionPure,
  // 5 = CATStoXtrudeFacesResXtrusionPureUnitaire
  CATSobXtrudeFacesResultType GetResultType();


  //------ Get :  d'un point sur le r�sultat (image) de l'extrusion (pour positionner un manipulateur SPARK)
  // iFace : Input face before extrusion
  // oInputFacePoint : The point at the center of the face iFace
  // oImgPoint : A point on the TOP extruded face from iFace
  //-----------------------------------------------------------------------------
  CATSobDiag GetImgPoint(const CATSobFace* iFace, CATMathPoint &oInputFacePoint, CATMathPoint &oImgPoint);


  //---- Data :
  CATLISTP(CATSobFace) m_FacesToExtrude;
  CATBoolean _InvertNormal, _CloseXtrude, _IsCloseXtrude, _IsAlreadyClose, _AdvMustInitLength;
  int _AutoWeight, _FreeWeight;
  int _PureExtrusion, _ResultType;
  double _AdvLength, _OutLength;

private:

  //Destructor
  ~CATSmoExtrudeFacesParameter() {}

};


#endif  //CATSmoExtrudeFacesParameter_H


