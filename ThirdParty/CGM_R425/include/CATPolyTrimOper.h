//====================================================================
// Copyright Dassault Systemes Provence 2008, all rights reserved 
//====================================================================
//
//======================================================================
// 22 Juillet  2008 : Creation                                       ANR
//======================================================================
#ifndef CATPolyTrimOper_H
#define CATPolyTrimOper_H

//Pour l'export
#include "CATPolyTrimOperators.h"
#include "CATMathDirection.h"
#include "CATPolyMeshProjectionOperator.h"

//Divers
#include "CATListOfInt.h"
#include "CATMathSetOfPoints.h"
#include "CATLISTP_CATPolyMCurve.h"
#include "CATTolerance.h"

class CATIPolyMesh;
class CATPolyAttributeDomains;
class CATUnicodeString;
class CATPolyMeshExtractZonesOperator;


class ExportedByCATPolyTrimOperators CATPolyTrimOper 
{
public:

  // Attention : ioPolyMesh est modifié : On insere les points
  CATPolyTrimOper(CATIPolyMesh* ioPolyMesh, CATTolerance *iTolObject=NULL);

  ~CATPolyTrimOper();

/**
 * Adds a trim polyline.
 *
 * @param iSetOfPoints
 * The trim polyline.
 *
 * @return
 * 0 if successful.
 **/
  int AddTrimPoints(CATMathSetOfPoints& iSetOfPoints);
  int AddTrimPoints(CATMathSetOfPoints* iSetOfPoints, const int iNbSetOfPoints);

/**
 * Adds a trim CATPolyMCurve.
 *
 * @param iPolyMCurve
 * The trim polycurve.
 *
 * @return
 * 0 if successful.
 **/
  int AddTrimPolyCurve(CATPolyMCurve& iPolyMCurve);

/**
 * Asks for sub-polymeshes computation and sets whether the mesh must be sliced along the mesh curves.
 *
 * @param iSliceMesh
 * Sets whether the mesh must be sliced along the mesh curves.
 **/
  void SetExtractComponents(const CATBoolean iSliceMesh = FALSE);

/**
 * In order to retrieve curves intersections vertices.
 **/
  void SetExtractCurvesIntersections();

  //Activation du raffinement en croix (local bisection refinement)
  void SetEnableLocalBisectionRefinement(CATBoolean iOptionOnBorderTriangles = TRUE);

/**
 * Disables polymesh manifoldness check. To use at your own risk !
 **/
  void SetNoManifoldCheck();

/**
 * Disables input curves cleaning (sub loops extraction...)
 */
  void DisableInputCurvesCleaning();


  /**
   * EnableProjectionOnMesh 
   * @param iDirection = NULL -> Normal projection
   *                     else -> Along a direction
   */
  void EnableProjectionOnMesh(CATMathDirection *iDirection = NULL);

  /**
  * CheckAndCleanNearestPoints
  * @param itolerance = NULL -> Resolution * Lg of Curve
  *                     else -> (*itolerance)
  */
  void CheckAndCleanNearestPoints(const double *itolerance = NULL);

/**
 * Runs the operator
 *
 * @return
 * Returns 0 if successful.
 **/
  int Run();

/**
 * Retrieves sub-meshes as triangle list.
 *
 * @return
 * A pointer to a structure containing all domains. Triangle indices are relative to the input polymesh.
 * The caller must release this object.
 **/
  CATPolyAttributeDomains* GetAllDomains();

/**
 * Gets split components if SetExtractComponents has been called.
 *
 * @param oNbComponents
 * The number of components
 * @param oComponents
 * The sub meshes.
 **/
  void GetComponents(int& oNbComponents, CATIPolyMesh**& oComponents);

/**
 * Retrieves the trim curves, they lie on the mesh and are regular (each curve point is a vertex in the mesh).
 * The curves must be released by the user.
 *
 * @param oTrimCurves
 * The trim curves.
 **/
  void GetTrimCurves(CATListPtrCATPolyMCurve& oTrimCurves) const;

/**
 * Retrieves curves intersections vertices.
 *
 * @return
 * Returns a pointer to the list of vertices indexes.
 **/
  const CATListOfInt* GetCurvesIntersections() const;

/**
 * Reports if at least one of the input curve has been cleaned (self intersection, overlaps removall)
 *
 * @return
 * FALSE if none of the curves has been cleaned.
 **/
  CATBoolean CurvesHaveBeenCleaned() const;

  /**
  Allow to retrieve the index of the vertices lying of the trimming curve
  */
  void GetCreatedVertices(CATListOfInt & oNewIndices) const
  {
    oNewIndices = m_CreatedVertices;
  }

private:

  //DEBUG: dump des entrées
  int DebugDumpInputData(const CATUnicodeString& iFileName);

  //DEBUG: dump d'un CATMathSetOfPoints
  int DebugDumpSetOfPoints(const CATMathSetOfPoints& iSetOfPoints, const CATUnicodeString& iFileName);

  //Nettoyage des courbes données en entrée (overlapp et cie...)
  int CleanInputCurves();

  // ANR : je prends pas de risque avec AddTrimPolyCurve  car il y a GetTrimCurves et j'ai l'impresssion que c'est pas 
  // compatible avec le dev
  int OldRun();

  //Ajout ANR
  int ConvertInputs();
  int ConvertOutputs();

  void CheckConfusedPoints();
  int ProjectionOfPoints();
  int NormalProjection();
  int ProjectionInDirection(); // Merci a Nua
  int CheckOrientation(CATTolerance *TolObject=NULL); //pour alleger le Run

  //
  void debugFunction_checkInputs(); //Debug de RAQ pour alleger le Run

  //----------- Data:
  CATIPolyMesh* _PolyMesh;
  CATIPolyMesh *_SaveInputMesh;

  CATListPtrCATPolyMCurve _TrimCurves;
  CATPolyAttributeDomains* _PolyDomains;
  CATBoolean _EnableLocalBisectionRefinement, _MustExtractComponents, _MustSliceMesh, _MustExtractCurvesIntersections, _CurvesHaveBeenCleaned,
             _PerformManifoldCheck, _MustCleanInputCurves, _RefineBorderTriangles;
  CATPolyMeshExtractZonesOperator* _PolyMeshExtractZonesOperator;
  int _Error, _NbComponents;
  CATIPolyMesh** _Components;

  CATTolerance *_TolObject ;

  CATListOfInt m_CreatedVertices;


  //Dev ANR/NUA ( Pb Large/Normal Range)
  CATBoolean _OldVersion;

  double _ScalingValue; CATBoolean _ScaleData;
  CATMathSetOfPoints* _SetOfPoints;
  int _NbSetOfPoints; 
  CATMathDirection *_ProjDir;
  CATBoolean _EnableProjection;
  
  CATPolyMeshProjectionOperator *_ProjectionOperator;
   
  CATBoolean _CleanNearestPoints, _ImposedTolerance;
  double _FilteringTolerance;
  double *_LengthOfEachCurve;

  double _MeanEdge, _MaxLgEdge ;
};

#endif


