
/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//===================================================================
// COPYRIGHT Dassault Systemes 2007, all rights reserved
//===================================================================
//
// CATPolySweep TAT3
//
//      Polyhedral Sweep Operator
// 
//      input:
//          Trajectory (3 Axis, 5 Axis, 6 Axis)
//          Mesh Profile
//      output:
//          Mesh of the swept volume of the input profile along trajectory
//  
//      Trajectory definition:
//        3 Axis:
//          List of positions
//        5 Axis:
//          List of positions
//          List of axis vector
//        6 Axis:
//          List of positions
//          List of 1st axis
//          List of 2nd axis
//===================================================================
// 
//===================================================================

#ifndef CATPolySweep_H
#define CATPolySweep_H

class CATIPolyMesh;
class CATMathPoint;
class CATMathVector;
class CATPolyTrajectory;

#include "ExportedByCATPolySweep.h"

class ExportedByCATPolySweep CATPolySweep
{
  

public:

  static CATPolySweep *CreateInstanceOfElementarySweep(CATIPolyMesh *iSolidProfile , const CATMathVector * iAxis = 0 );
  static CATPolySweep *CreateInstanceOfSweep5Axis (CATIPolyMesh *iSolidProfile );
  static CATPolySweep *CreateInstanceOfSweep6Axis (CATIPolyMesh *iSolidProfile );

  //
  virtual ~CATPolySweep() {} ;
  //
  // return 0 if OK
  // iResult must be an empty, instanciated CATIPolyMesh (if not empy, the resukt wil be added (as chains can be aded) to the previous content...
  // for 3 axis
  virtual int Run (const int iNbVertexInPath,  CATMathPoint *iPath,  CATIPolyMesh *iResult, const double iTol = 5.e-4) = 0;

  // for 5 axis
  virtual int Run (const int iNbVertexInPath,  CATMathPoint *iPath,  CATMathVector * iTobOfAxis, CATIPolyMesh *iResult, const double iTol = 5.e-4) = 0;

  // for 6 axis
  virtual int Run (const int iNbVertexInPath,  CATMathPoint *iPath,  CATMathVector * iTobOfAxis, CATMathVector * iTobOfSecondAxis, CATIPolyMesh *iResult, const double iTol = 5.e-4) = 0;

  virtual int Run (CATPolyTrajectory * iTrajectory, const double iTol = 5.e-4) = 0;

  virtual void SetChordalTolerance(double iTolChordal)=0;

  virtual void SetInitialAxis ( const CATMathVector & iAxis ) = 0;

  virtual int CleanAndPerturbPath ( int & ioNbPointsInPath, CATMathPoint *ioPath, const double iTol) = 0;

};


#endif
