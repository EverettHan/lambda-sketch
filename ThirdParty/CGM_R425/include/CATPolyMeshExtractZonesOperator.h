//==============================================================================================
// Copyright Dassault Systemes Provence 2009, All Rights Reserved
//==============================================================================================
//
// CATPolyMeshExtractZonesOperator.h
//
//==============================================================================================
//
// Usage notes: This operator extracts all the set of triangles bounded by vertex-path polymesh
//              curves or free borders.
//
//==============================================================================================
// March,   2009 : RAQ : Création
//==============================================================================================
#ifndef CATPolyMeshExtractZonesOperator_H
#define CATPolyMeshExtractZonesOperator_H

//Pour l'export
#include "CATPolyTrimOperators.h"

//Structure polyhédrique
#include "CATIPolyMesh.h"
#include "CATLISTP_CATPolyMCurve.h"
#include "CATPolyBitSet.h"
#include "CATBoolean.h"

class CATPolyAttributeDomains;


class ExportedByCATPolyTrimOperators CATPolyMeshExtractZonesOperator
{
public:

/**
 * Builds the operator.
 *
 * @param iPolyMesh
 * The PolyMesh to work on.
 **/
  CATPolyMeshExtractZonesOperator(CATIPolyMesh& iPolyMesh);

/**
 * Deletes the operator.
 **/
  ~CATPolyMeshExtractZonesOperator();

/**
 * In order to retrieve curves intersections vertices.
 **/
  void SetExtractCurvesIntersections();

/**
 * Runs the operator.
 *
 * @param iMeshCurveList
 * The regular mesh curves.
 *
 * @return
 * 0 if the operator runs successfully, FALSE otherwise.
 **/
  int Run(const CATListPtrCATPolyMCurve& iMeshCurveList);

/**
 * Returns the result.
 *
 * @return
 * A pointer to a structure containing all domains. Triangle indices are relative to the input polymesh.
 * The caller must release this object.
 **/
  CATPolyAttributeDomains* GetAllDomains();

/**
 * Retrieves curves intersections vertices.
 *
 * @param oIntersectionVertices
 * The list of vertices at curves intersections.
 *
 * @return
 * Returns 0 if successful.
 **/
  const CATListOfInt* GetCurvesIntersections() const;


private:

  //Set de l'erreur
  int SetError(const int iError);

  //Check si une edge du maillage est une edge d'une MeshCurve
  CATBoolean IsBarOnMeshCurve(const int iVertexIndex1, const int iVertexIndex2, const CATPolyBitSet& iVerticesFlag) const;

  //Calcul des points d'intersection des courbes
  int ComputeCurvesIntersections(const CATListPtrCATPolyMCurve& iMeshCurveList);

  //--------- Data:
  int _Error;
  CATIPolyMesh& _PolyMesh;
  int _NbMeshCurves;
  CATListOfInt* _AllVerticesPath;
  CATPolyAttributeDomains* _AllDomains;
  CATBoolean* _IsMeshCurveClosed;
  CATBoolean _MustExtractCurvesIntersections;
  CATListOfInt _CurvesIntersections;
};

#endif


