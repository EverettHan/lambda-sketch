//===================================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveNetworkNoSupportOperator.h
//
//===================================================================================
//
// Usage notes: Calcul d'un réseau de courbes.
//
//===================================================================================
// 18.05.2020 : RAQ : Stabilisation des valeurs des curve handles dans le cgmreplay
// March,   2012 : RAQ : Création
//===================================================================================
#ifndef CATPolyMCurveNetworkNoSupportOperator_H
#define CATPolyMCurveNetworkNoSupportOperator_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe mère
#include "CATPolyRefCounted.h"

//Divers
#include "CATMathSetOfPoints.h"
#include "CATListOfInt.h"
#include "CATLISTP_CATPolyMCurve.h"
#include "CATLISTP_CATPolyMCNOPoint.h"
#include "CATLISTP_CATPolyMCNOEdge.h"
#include "CATPolyMCurveNetworkUtilities.h"


class CATPolyDebugFactoryItf;
class CATIPolyMesh;
class CATPolyMCurveNetworkNoSupportOperatorImpl;
class CATMathStream;
class CATCGMOutput;


class ExportedByCATPolyTrimOperators CATPolyMCurveNetworkNoSupportOperator: public CATPolyRefCounted
{
public:

  //Constructeur
  CATPolyMCurveNetworkNoSupportOperator(const double iConfusionTol);

  //Ajout des courbes du réseau
  int AddPolyCurves(const CATMathSetOfPoints* iSetOfPoints, const int iNbSetOfPoints, CATULONG32* oCurvesHandles);
  int AddPolyCurve(CATPolyMCurve& iPolyMCurve, CATULONG32* oCurveHandle);

  //Suppression d'une liste de courbes
  int RemovePolyCurves(const CATULONG32* iCurvesHandles, const int iNbCurves);

  //Modification de la tolérance et mise à jour forcée du réseau
  void ChangeConfusionTolerance(const double iConfusionTol, const CATBoolean iUpdateWholeNetwork = TRUE);

  //Option : la comparaison interne des edges du réseau est basée uniquement sur les vertex extrémités
  void SetCompareSameEdgesWithExtremityVertices();

  //Run de l'opérateur
  int Run();

  //Récupération de l'erreur courante
  int GetError() const;

  //Récupération des points d'intersection
  int GetNetworkVertices(CATListPOfPolyMCNOPoint& oNetworkVertices) const;
  int GetNbNetworkVertices() const;

  //Récupération des edges du réseau
  int GetNetworkEdges(CATListPOfPolyMCNOEdge& oNetworkEdges) const;
  int GetNbNetworkEdges() const;

  //Test si le run a déjà été fait
  CATBoolean GetOperatorHasRun() const;

  //Récupération des vertex et edges supprimés lors du dernier Run
  //Attention, ces pointeurs peuvent être invalides !!!
  int GetNetworkVerticesRemovedDuringLastRun(CATListPOfPolyMCNOPoint& oRemovedNetworkVertices) const;
  int GetNetworkEdgesRemovedDuringLastRun(CATListPOfPolyMCNOEdge& oRemovedNetworkEdges) const;
  int GetNetworkEdgesRemovedDuringLastRun(CATPolyMCurveNetworkUtilities::SetOfRemovedMCNOEdge_t& oRemovedNetworkEdges) const;

  
  //Utilitaires pour les CGMReplay
  int StreamPolyCurves(CATMathStream& iStr);
  static int UnstreamPolyCurves(CATMathStream& iStr, int& oNbSetOfPoints, CATMathSetOfPoints*& oAllSetOfPoints,
                                CATULONG32*& opAllCurvesHandle, const CATBoolean iUseVersionnedStream);
  void Dump(CATCGMOutput& os);

  //Ajout des courbes du réseau avec set des handles (ne pas utiliser, réservé au CGMReplay)
  int AddPolyCurvesWithHandles(const int iNbSetOfPoints, const CATMathSetOfPoints* ipSetOfPoints, const CATULONG32* ipCurvesHandles);

  //DEBUG: Activation des print
  void SetVerbose();

  //DEBUG: Factory de debug
  void SetDebugFactory(CATPolyDebugFactoryItf* iDebugFactoryItf);

  //DEBUG: Récupération des courbes de trim d'entrée
  void GetInputMCurves(const CATListPtrCATPolyMCurve*& oInputMCurves) const;


protected:

  //Destructeur
  virtual ~CATPolyMCurveNetworkNoSupportOperator();


private:

  //No default copy methods
  CATPolyMCurveNetworkNoSupportOperator(const CATPolyMCurveNetworkNoSupportOperator&);
  CATPolyMCurveNetworkNoSupportOperator& operator=(const CATPolyMCurveNetworkNoSupportOperator&);


  //------------ Data :
  CATPolyMCurveNetworkNoSupportOperatorImpl* _PolyMCurveNetworkNoSupportOperatorImpl;

};


/**
 * Operator creation.
 **/
ExportedByCATPolyTrimOperators
CATPolyMCurveNetworkNoSupportOperator* CATPolyCreateMCurveNetworkNoSupportOperator(const double iConfusionTol);


#endif  //CATPolyMCurveNetworkNoSupportOperator_H



