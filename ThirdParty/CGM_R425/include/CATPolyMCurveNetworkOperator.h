//===================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveNetworkOperator.h
//
//===================================================================================
//
// Usage notes: Calcul d'un réseau de courbes sur maillage et calcul des domaines
//              délimités par les courbes.
//
//===================================================================================
// June,   2009 : RAQ : Création
//===================================================================================
#ifndef CATPolyMCurveNetworkOperator_H
#define CATPolyMCurveNetworkOperator_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Classe mère
#include "CATPolyRefCounted.h"

//Divers
#include "CATMathSetOfPoints.h"
#include "CATLISTP_CATPolyMCurve.h"
#include "CATListOfInt.h"
#include "CATLISTP_CATPolyMCurveNetworkIntersectionPoint.h"

class CATPolyDebugFactoryItf;
class CATIPolyMesh;
class CATPolyMCurveNetworkOperatorImpl;


class ExportedByCATPolyTrimOperators CATPolyMCurveNetworkOperator: public CATPolyRefCounted
{
public:

/**
 * Operator creation
 *
 * @param iPolyMesh
 * The support polygon.
 **/
  CATPolyMCurveNetworkOperator(CATIPolyMesh& iPolyMesh);

/**
 * Adds poly-curves.
 *
 * @param iSetOfPoints
 * An array of polylines
 * @param iNbSetOfPoints
 * The number of polylines
 *
 * @return
 * 0 if successful.
 **/
  int AddPolyCurves(CATMathSetOfPoints* iSetOfPoints, const int iNbSetOfPoints);

/**
 * Adds a poly-curve.
 *
 * @param iPolyMCurve
 * The poly-curve.
 *
 * @return
 * 0 if successful.
 **/
  int AddPolyCurve(CATPolyMCurve& iPolyMCurve);

/**
 * Disables auto-insertion of the curves made of the free borders of the polygon.
 **/
  void SetDisableAutoInsertBorderCurve();

/**
 * In order to retrieve curves intersections vertices.
 **/
  void SetExtractCurvesIntersections();

/**
 * Runs the operator.
 *
 * @return
 * 0 if OK
 **/
  int Run();

/**
 * Intersection points retrieval
 *
 * @param oNetworkIntersectionPoints
 * A list that will be filled with the intersection points.
 **/
  int GetNetworkIntersectionPoints(CATListPtrNetworkIntersectionPoint& oNetworkIntersectionPoints);

/**
 * Retrieves split components.
 *
 * @param oNbComponents
 * The number of components
 * @param oComponents
 * The sub meshes. They must be released by the caller.
 **/
  void GetComponents(int& oNbComponents, CATIPolyMesh**& oComponents);


  //DEBUG: Activation des print
  void SetVerbose();

  //DEBUG: Factory de debug
  void SetDebugFactory(CATPolyDebugFactoryItf* iDebugFactoryItf);

  //DEBUG: Forçage de l'insertion de courbes sur les bords libres
  void SetForceInsertBorderCurves();

  //DEBUG: Récupération des points d'intersection insérés dans le maillage d'input
  void GetIntersectionPoints(const CATListOfInt*& oIntersectionPoints) const;

  //DEBUG: Implémentation
  void* GetImpl();

protected:

/**
 * Destructor
 **/
  virtual ~CATPolyMCurveNetworkOperator();


private:

  //No default methods
  CATPolyMCurveNetworkOperator(const CATPolyMCurveNetworkOperator&);
  CATPolyMCurveNetworkOperator& operator=(const CATPolyMCurveNetworkOperator&);


  //---------- Data :
  CATPolyMCurveNetworkOperatorImpl* _PolyMCurveNetworkOperatorImpl;

};


/**
 * Operator creation.
 **/
ExportedByCATPolyTrimOperators
CATPolyMCurveNetworkOperator* CATPolyCreateMCurveNetworkOperator(CATIPolyMesh& iPolyMesh);

#endif


