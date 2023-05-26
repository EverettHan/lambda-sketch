//======================================================================
// Copyright Dassault Systemes Provence 2017, All Rights Reserved
//======================================================================
//
// CATSmoXtrudeNEdgesParameter.h
//
//======================================================================
//
// Usage notes : Param�tres pour l'op�rateur CATSmoXtrudeNEdgesOperator
//
//======================================================================
// 23.01.2023 : RBD : Appel SetAutoWeight() : _AutoWeight prend maintenant les valeurs 0 � 3 inclus.
// 16.11.2020 : RBD : Ajout methode GetImgPoint()
// 30.06.2020 : RBD : Ajout methode SetExtrapoleAlongMeshLines() for edges extrusion along mesh lines (STANDARD mode) 
// 04.06.2018 : RAQ : Ajout SetFollowExtrudedVertices pour suivi des vertex extrud�s
// 17.11.2017 : RBD : Creation d'apr�s CATSmoExtrudeFacesParameter de RAQ
//======================================================================
#ifndef CATSmoXtrudeNEdgesParameter_H
#define CATSmoXtrudeNEdgesParameter_H

//Pour l'export
#include "CATSmoOperators.h"

//Monocodage OS
#include "CATLib.h"

//Subdivision
#include "CATSobAddRefRelease.h"
#include "CATSobListOfVertex.h"
#include "CATSobListOfEdge.h"
#include "CATSobListOfFace.h"
#include "CATSobDiag.h"

//Divers
#include "CATBoolean.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"

//STL
#ifndef _AIX_SOURCE
#include <unordered_map>
#endif  //!_AIX_SOURCE


class CATSobVertex;
class CATSobEdge;
class CATSobFace;
class CATMathPlane;

class ExportedByCATSmoOperators CATSmoXtrudeNEdgesParameter
{
  SOB_DECLARE_ADDREF_RELEASE;

public:
  //-----------------------------------------------------------------------------
  //Constructeurs
  //-----------------------------------------------------------------------------
  CATSmoXtrudeNEdgesParameter(const CATLISTP(CATSobEdge)& iEdgesToXtrude);
  CATSmoXtrudeNEdgesParameter(const CATSmoXtrudeNEdgesParameter& iToCopy);

  //-----------------------------------------------------------------------------
  // Set STANDARD or ADVANCED mode
  //-----------------------------------------------------------------------------
  // Set STANDARD mode : without fixed direction (Default) OR with fixed direction OR along meshlines 
  void SetStandardMode();

  // Set ADVANCED mode : Drafting Direction + Angle + Length
  void SetAdvancedMode();

  //------ Poids  :
  //-----------------------------------------------------------------------------
  // Set Sharpness (Poids) sur les  sur les aretes du profil selectionne (STANDARD and ADVANCED mode)
  // ----------------------------------------------------------------------------
  void SetInputEdgesWeight(const int iWeight = 0, const CATBoolean iSmooth = TRUE);
  
  //-----------------------------------------------------------------------------
  // **** DEPRECATED DO NOT USE **** : Utiliser la m�thode SetAutoWeight(const int& iAutoWeight)
  //------ Activation du poid automatique sur les vertex (STANDARD and ADVANCED mode)
  // ----------------------------------------------------------------------------
  void SetAutoWeight(const CATBoolean iAutoWeight = TRUE);

  //-----------------------------------------------------------------------------
  //------ Activation du poid automatique sur les vertex (STANDARD and ADVANCED mode)
  // Pour activer le report automatique du poids des edges vers les vertex commun, mettre iAutoWeight > 0.
  // Il faut qu'il y ai au moins 3 edges de poids > 0 pour que le poids du vertex commun soit modifi�.
  // Si iAutoWeight == 1, on prend le max du poids des ar�tes et on l'impose au vertex
  // Si iAutoWeight == n <= 3, on prend le n-i�me poids. Valeur conseill�e : 3.
  // PUIS utiliser les m�thodes SetSharpnessOnEdge ou SetSmoothingOnEdge.
  // Pour d�sactiver le poids automatique, remettre iAutoWeight � 0.
  // ----------------------------------------------------------------------------
  void SetAutoWeight(const int& iAutoWeight);

  //-----------------------------------------------------------------------------
  //------ Get : image d'un point sur 1 ar�te par extrusion   (STANDARD mode or ADVANCED mode)
  // iEdge : Input edge before extrusion
  // iLambda : Must be between 0. and 1. (0. = start vertex, 1.0 = end vertex of iEdge)
  // oEdgePoint : The point at iLambda on the edge iEdge
  // oImgPoint : the image of a point at iLambda on iEdge by extrusion
  // oInitialXtrudeDir : The extrusion direction of the edge iEdge (STANDARD mode) or the initial extrusion direction of iEdge (ADVANCED mode with angle = 0.0)
  //-----------------------------------------------------------------------------
  CATSobDiag GetImgPoint(const CATSobEdge* iEdge, const double iLambda, CATMathPoint &oEdgePoint, CATMathPoint &oImgPoint, CATMathDirection &oInitialXtrudeDir);


  //Suivi des vertex extrud�s, remplit la map 'm_extrudedVertices'
  void SetFollowExtrudedVertices() { m_followExtrudedVertices=TRUE;  }


  //
  //======================================================================================================
  //-=-=-=-=-=-=-=- STANDARD mode -=-=-=-=-=-=-=-
  //======================================================================================================
  // STANDARD mode(s) groups 3 options :
  // 1- Extrusion directions are computed to be the best possible (DEFAULT)
  // 2- Extrusion directions are fixed to one unique direction
  // 3- Extrusion directions are computed to be along mesh lines
  //
  //------ Length  :
  //-----------------------------------------------------------------------------
  // Set Length (STANDARD mode)
  // if iEdge is NULL, iLength > 0. is the default value for ALL edges
  // ----------------------------------------------------------------------------
  CATSobDiag SetLength(const CATSobEdge* iEdge, const double iLength);
  //-----------------------------------------------------------------------------
  // Get Length (STANDARD mode)
  // ----------------------------------------------------------------------------
  void GetLength(const CATSobEdge* iEdge, double &oLength);

  //------ fixed direction :
  // ----------------------------------------------------------------------------
  // Set a fixed direction for extrusion (STANDARD Mode)
  // May be initialized by GetDefaultFixedVector()
  // ----------------------------------------------------------------------------
  CATSobDiag SetExtrapoleFixedVector(CATMathVector* iFixedVector);
  // ----------------------------------------------------------------------------
  // Get a pre-computed default fixed direction for extrusion (WARNING : The result may be the null vector) 
  // ----------------------------------------------------------------------------
  // return CATSobDiag_EdgeLenghtMin iff oDefaultDirection is the null vector (0., 0., 0.)
  // else return CATSobDiag_OK
  CATSobDiag GetDefaultFixedVector(CATMathVector& oDefaultDirection);

  // ----------------------------------------------------------------------------
  // Extrusion directions are computed along mesh lines (STANDARD Mode)
  // 0 : No extrusion along mesh lines
  // 1 : The extrusion direction is the mean between two extremal mesh lines at each vertex
  // 2 : The extrusion direction is the mesh line that is closer to a direction orthogonal at each vertex 
  // ----------------------------------------------------------------------------
  CATSobDiag SetExtrapoleAlongMeshLines(int iIsDirectionAlongMeshLines = 1);

  // ----------------------------------------------------------------------------
  // Ajout ANR : on extrapole d'une longueur donnee
  // ----------------------------------------------------------------------------
  void SetExtrapoleLength(const double iLength);
 
  // ----------------------------------------------------------------------------
  // Ajout ANR : on extrapole sur la base d'un plan moyen
  // ----------------------------------------------------------------------------
  void SetMeanPlane(CATMathPlane *iMeanPlane, CATBoolean iQuasiPlanar = FALSE);

  // ----------------------------------------------------------------------------
  // Ajout ANR : Traitement si le BaseMesh Input est une grille
  // ----------------------------------------------------------------------------
  void SetBaseMeshMxN(CATBoolean iBaseMeshMxN = FALSE);

  // ----------------------------------------------------------------------------
  // Ajout ANR : Recup des faces cr�es
  // ----------------------------------------------------------------------------
  void GetNewFaces(CATLISTP(CATSobFace) &oNewFaces);


  //
  //======================================================================================================
  //-=-=-=-=-=-=-=- ADVANCED mode -=-=-=-=-=-=-=-
  //======================================================================================================
  //

  //------ Draft direction :
  //-----------------------------------------------------------------------------
  // Set Drafting Direction (ADVANCED mode only)
  //-----------------------------------------------------------------------------
  CATSobDiag SetDraftDirection(const CATMathDirection &iDraftDirection);
  //-----------------------------------------------------------------------------
  // Get Drafting Direction (ADVANCED mode only)
  //-----------------------------------------------------------------------------
  void GetDraftDirection(CATMathDirection &oDraftDirection);

  //------ Angle (en degr�s) :
  //-----------------------------------------------------------------------------
  // Set Angle (ADVANCED mode only)
  //-----------------------------------------------------------------------------
  void SetAngle(const double iAngleDeg = 0.0);
  //-----------------------------------------------------------------------------
  // Get Angle (ADVANCED mode only)
  //-----------------------------------------------------------------------------
  void GetAngle(double &oAngleDeg);

  //------ Length  :
  //-----------------------------------------------------------------------------
  // Set Length (ADVANCED mode)
  // ----------------------------------------------------------------------------
  CATSobDiag SetLength(const double iLength);
  //-----------------------------------------------------------------------------
  // Get Length (ADVANCED mode)
  // ----------------------------------------------------------------------------
  void GetLength(double &oLength);

  //-----------------------------------------------------------------------------
  //------ Nombre de secteurs de la subdivision (ADVANCED mode only)
  //-----------------------------------------------------------------------------
  void SetNbSectors(const int iNbSectors = 1);


  //-=-=-=-=-=-=-=-
  //-------- Data:
  CATLISTP(CATSobEdge)  _EdgesToXtrude;
  // RBD : A VIRER CATListOfInt          _EdgesOrientation;

  CATBoolean            _AdvancedMode;

  int        _InputEdgeWeight;
  CATBoolean _InputEdgeSmooth;
  CATBoolean _AutoWeight;

  CATLISTP(CATSobFace) _NewFaces;
  // CATBoolean _HasChangedMode;
  CATBoolean    _IsFixedDirection;
  int _IsDirectionAlongMeshLines;
  CATMathVector _FixedDirection, _DefaultDirection;

  double                _EpsEdgeLenghtMin;
  CATBoolean            _StdLengthIsInitialized;
  CATLISTP(CATSobEdge)  _EdgeswithLength; // A VIRER
  CATListOfInt          _NumEdgeswithLength; // REMPLACE liste precedente.
  CATListOfDouble       _LengthwithEdges;
  
  double _ExtrapoleLength;
  CATMathPlane* _MeanPlane;
  CATBoolean    _QuasiPlanar, _BaseMeshMxN;

  //Suivi des vertex, actif par appel � SetFollowExtrudedVertices
  CATBoolean m_followExtrudedVertices;
#ifndef _AIX_SOURCE
  std::unordered_map<CATSobVertex*, CATSobVertex*> m_extrudedVertices;  //map [old vertex] --> [ extruded vertex]
#endif  //!_AIX_SOURCE

 // CATLISTP(CATSobEdge) _ExtrudedEdges;

  //CATLISTP(CATSobVertex) _CornerVertices, _NewCornerVertices;

  //-------- Data Advanced mode :
  CATBoolean    _AdvMustInitLength;  
  double        _AdvLength;

  CATBoolean    _AdvMustInitDirection;
  CATMathVector _AdvDraftDirection;  
  int           _AdvOrientXtrudeDir;
  CATBoolean    _AdvMustInitAngle;
  double        _AdvAngleDeg, _AdvAngleRad;
  int           _AdvNbSectors;

private:
  //Destructor
  ~CATSmoXtrudeNEdgesParameter() {}


};


#endif  // CATSmoXtrudeNEdgesParameter_H



