// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicDetectOperOnCloud.h
//
//===================================================================
//
// Usage notes: Find canonics (planes, ... (cylinders, cones, fillets) )  in a Cloud
//
//===================================================================
// 
// Sep 2014 : ANR : Creation
//===================================================================

#ifndef CATPolyCanonicDetectOperOnCloud_H
#define CATPolyCanonicDetectOperOnCloud_H

#include "CATPolyCanonicOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"  
#include "CATLib.h" 
#include "CATMathPlane.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATPolyPointsOctreeOper.h"
 
class CATMapOfIntToInt ;
class CATPolyGeometricForm ;

class ExportedByCATPolyCanonicOperators CATPolyCanonicDetectOperOnCloud
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicDetectOperOnCloud(int iNbVertices,  double *iVerticesCoords, double *iNormalsCoords=NULL);


  virtual ~CATPolyCanonicDetectOperOnCloud();


  /**
  *  Set Tolerances
  */ 
  void SetToleranceOnVertices(double iTol); 


  /** 
  *  Set Options
  */ 
  void SetPlaneSurfDetection(CATBoolean iActivate);

  /**
  * Run
  */
  HRESULT Run( ); 

  int GetNbOfPlanes() ;
  //
  void GetPlane(int iNum, CATMathPlane &oPlane, CATListOfInt &oListOfIndices) ;

   
private:

  int CallToOctreeOper() ;
  int ComputeInitPlanes() ;
   
  int PropagateInitPlanes(int iF, int *iVisitedPatches) ;

  int UpdatePlanarPatch(CATListOfInt &iListVertices, double InputTol, CATMathPoint &oAjustCenter, CATMathVector &oAjustNormal, 
                         double &oCurrentMaxError, double &oCurrentMeanError) ; 

  double _InputTolOnVertices ;
  int _NbVertices ;
  double *_VerticesCoords ;
  double *_NormalsCoords ; 
  int * _Indexes ;

  CATPolyPointsOctreeOper *_OctreeOper ;
  int _NbLeaf ;
  CATListOfInt *_TabOfLeaf  ;
 
  int _NbOfCondidatePts ;
  CATMathPoint  *_CondidatePts ;
  CATMathVector *_CondiateNormals ;
  int *_CondidateVertices ;

  int *_PartitionPts ;   
  CATListOfInt *_TabOfPatchesIsOK; 
  double *_TabMaxError ;

  CATMapOfIntToInt *_MapBetweenLeafAndPlane ;

  int _NbOfPlanes ;
  CATMathPlane *_TabOfMathPlanesResult ;
  CATListOfInt *_TabOfIndicesPlanesResult;


  CATListOfInt _listOfPlanesToRemove ;
  CATMapOfIntToInt *_MapOfPatchDoNotPropagate;

};

#endif
