// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshMeanFilterOper.h
// Header definition of CATPolyMeshMeanFilterOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2005  Creation: ktu
//===================================================================
#ifndef CATPolyMeshMeanFilterOper_H
#define CATPolyMeshMeanFilterOper_H

#include "CATPolyModOper.h"
#include "CATPolySmoothingOperators.h" 
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"


/**
*
* Mean Filter for Averaging Face Normals 
* Consider an oriented triangle mesh. Let T be a mesh
* triangle, n(T) be the unit normal of T, A(T) be the area
* of T, and C(T) be the centroid of T. Denote by N(T) the
* set of all mesh triangles that have a common edge or vertex
* with T. One iteration of the iterative mesh mean filtering
* scheme consists of the following three successive steps:
* 
* Step 1. For each mesh triangle T, compute the triangle normal
* n(T) and perform the following area-weighted averaging
* normals:
* 		m(T) = SUM_S [  A(S)*n(S)  ] / SUM_S[ A(S) ]   with S in N(T).
* 
* Step 2. For each mesh triangle T, normalize the averaged
* normals m(T):
* 		m(T)  =  m(T)/ || m(T) ||
* 
* Step 3.  For each mesh vertex P, perform the vertex updating
* procedure
* 		Pnew  = Pold + V 
* 	where  V = SUM_T[ A(T)*[( C(T)-Pold)*m(T)]*m(T) ] /  / SUM_T[ A(T) ];
* 	with  T in the  direct neighboood Triangles of  P and C the  centroid of T
*/

class ExportedByCATPolySmoothingOperators CATPolyMeshMeanFilterOper : public CATPolyModOper
{

public:

  /**
  * Default constructor.
  */
  CATPolyMeshMeanFilterOper( void ); 

  /**
  * Destructor
  */ 
  ~CATPolyMeshMeanFilterOper();

  /**
  * To set smoothing's  parameters. The  algorithm stops when  one of constraints
  * defined  by  one of following  imput parameters is satisfied.
  * @param iMaxDeviationAllowed 
  *   Maximum deviation allowed by user. 
  * @param iNbIter 
  *   Maximum  iterations.  
  * @param iMinStep 
  *   the  algorithm stops  when  at  one iteration,  Max ( distance(Pold, Pnew) ) <=  iMinStep
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT SetSmoothingParameters (const double iMaxDeviationAllowed, 
                                  const int iNbIterations, 
                                  const double iMinStep);

  /**
  * Runs the operator.
  * The mesh on which the operator is run must be set with the method SetMesh.
  * The operation is done in place.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT Run ();

  /**
  * Return  max deviation 
  */
  double GetMaxDeviation () const ;

private:

  HRESULT Init ();
  HRESULT PerfomMeanFilter ();

  HRESULT ComputeMeanNormal4Tri (const int iIdxTri, double &oNewNormal0, double &oNewNormal1, double &oNewNormal2);
  HRESULT ComputeDeplacement4Vtx (const int iIdxVtx, double &oDir0, double &oDir1, double &oDir2);
  HRESULT UpdateVtx ();
  HRESULT UpdateSolution ();

  // Member variables.

  double _MaxDeviationAllowed;
  double _MinDeplacementAllowed;
  double _MaxDeplacement;
  double _MaximumStep;
  double _MaxDeviation;

  double * _TriNormals[3];
  double * _OldVtx[3];
  double * _NewVtx[3];

  int _MaxVtxIdx;
  int _MaxTriIdx;

  int _ErrorCode;

  CATListOfInt _ListeOfIndex1;
  CATListOfInt _ListeOfIndex2;
};

#endif

