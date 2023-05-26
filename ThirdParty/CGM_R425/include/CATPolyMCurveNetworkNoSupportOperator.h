//===================================================================================
// Copyright Dassault Systemes Provence 2012, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveNetworkNoSupportOperator.h
//
//===================================================================================
//
// Usage notes: Calcul d'un r�seau de courbes.
//
//===================================================================================
// 18.05.2020 : RAQ : Stabilisation des valeurs des curve handles dans le cgmreplay
// March,   2012 : RAQ : Cr�ation
//===================================================================================
#ifndef CATPolyMCurveNetworkNoSupportOperator_H
#define CATPolyMCurveNetworkNoSupportOperator_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe m�re
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

  //Ajout des courbes du r�seau
  int AddPolyCurves(const CATMathSetOfPoints* iSetOfPoints, const int iNbSetOfPoints, CATULONG32* oCurvesHandles);
  int AddPolyCurve(CATPolyMCurve& iPolyMCurve, CATULONG32* oCurveHandle);

  //Suppression d'une liste de courbes
  int RemovePolyCurves(const CATULONG32* iCurvesHandles, const int iNbCurves);

  //Modification de la tol�rance et mise � jour forc�e du r�seau
  void ChangeConfusionTolerance(const double iConfusionTol, const CATBoolean iUpdateWholeNetwork = TRUE);

  //Option : la comparaison interne des edges du r�seau est bas�e uniquement sur les vertex extr�mit�s
  void SetCompareSameEdgesWithExtremityVertices();

  //Run de l'op�rateur
  int Run();

  //R�cup�ration de l'erreur courante
  int GetError() const;

  //R�cup�ration des points d'intersection
  int GetNetworkVertices(CATListPOfPolyMCNOPoint& oNetworkVertices) const;
  int GetNbNetworkVertices() const;

  //R�cup�ration des edges du r�seau
  int GetNetworkEdges(CATListPOfPolyMCNOEdge& oNetworkEdges) const;
  int GetNbNetworkEdges() const;

  //Test si le run a d�j� �t� fait
  CATBoolean GetOperatorHasRun() const;

  //R�cup�ration des vertex et edges supprim�s lors du dernier Run
  //Attention, ces pointeurs peuvent �tre invalides !!!
  int GetNetworkVerticesRemovedDuringLastRun(CATListPOfPolyMCNOPoint& oRemovedNetworkVertices) const;
  int GetNetworkEdgesRemovedDuringLastRun(CATListPOfPolyMCNOEdge& oRemovedNetworkEdges) const;
  int GetNetworkEdgesRemovedDuringLastRun(CATPolyMCurveNetworkUtilities::SetOfRemovedMCNOEdge_t& oRemovedNetworkEdges) const;

  
  //Utilitaires pour les CGMReplay
  int StreamPolyCurves(CATMathStream& iStr);
  static int UnstreamPolyCurves(CATMathStream& iStr, int& oNbSetOfPoints, CATMathSetOfPoints*& oAllSetOfPoints,
                                CATULONG32*& opAllCurvesHandle, const CATBoolean iUseVersionnedStream);
  void Dump(CATCGMOutput& os);

  //Ajout des courbes du r�seau avec set des handles (ne pas utiliser, r�serv� au CGMReplay)
  int AddPolyCurvesWithHandles(const int iNbSetOfPoints, const CATMathSetOfPoints* ipSetOfPoints, const CATULONG32* ipCurvesHandles);

  //DEBUG: Activation des print
  void SetVerbose();

  //DEBUG: Factory de debug
  void SetDebugFactory(CATPolyDebugFactoryItf* iDebugFactoryItf);

  //DEBUG: R�cup�ration des courbes de trim d'entr�e
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



