/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Dec 2001
 *   Purpose : Methods to crate curve constraints Array fo
 *              BeamFE algorithms
 *=========================================================
 * HISTORY:
 * Dec 2001 : ktu definition 
 */

#ifndef _CATCreateCurveConstraintArray_H
#define _CATCreateCurveConstraintArray_H

#include "MathPlate.h"
#include "CATDataType.h"
#include "CATBoolean.h"
class CATIMathPlateCurvPPCArray;
class CATIMathPlateCurvLSCArray;

/* =================================================================================================== *
 * ==================================     Create PPC arrays        =================================== *
 * 1. Constructs a array of a given size (iLength). Only working epace dimension's is initialized
 *    Use SetPPC to initialize them
   2. create one G0 constraint 
   3. create one G1(toC1) constraint
   4. create G0 and G1 constraints(preffer  to optimize algorithm if G1)
 * Les TolG1 sont  en radian
/* =================================================================================================== */

ExportedByMathPlate CATIMathPlateCurvPPCArray* CreateCurvePPCArray(const int iLength, 
                                                         const int iDimension);

ExportedByMathPlate CATIMathPlateCurvPPCArray* CreateCurvePPCArray(const int iDimension,
                                                          const double iParameter,
                                                          const double iValues[],
                                                          const double iTolG0=0.001);

ExportedByMathPlate CATIMathPlateCurvPPCArray* CreateCurvePPCArray(const int    iDimension,
                                                          const double iParameter,
                                                          const double iTgtValues[],
                                                          const double iDirValues[],
                                                          CATBoolean iIsColinear,
                                                          const double iTolG1);// en radian

ExportedByMathPlate CATIMathPlateCurvPPCArray* CreateCurvePPCArray(const int    iDimension,
                                                          const double iParameter,
                                                          const double iPointValues[],
                                                          const double iTgtValues[],
                                                          const double iDirValues[],
                                                          CATBoolean iIsColinear,
                                                          const double iTolG1,// en radian
                                                          const double iTolG0=0.001);


/* =================================================================================================== *
 * ==================================     Create LSC arrays        =================================== *
 * 1. Constructs a array of a given size (iLength). Only working epace dimension's is initialized
 *    Use SetPPC to initialize them
   2. cree un lsc verifiant Angle(Dir, Tg+DeltaTg) <= 0.5*PI - Tol;
   3. create 
   4. create G0 and G1 constraints(preffer  to optimize algorithm if G1)
   Les TolG1 sont  en radian
/* =================================================================================================== */

 
ExportedByMathPlate CATIMathPlateCurvLSCArray* CreateCurveLScalarCArray(CATLONG32 iLength,
                                                              const int iDimension);

ExportedByMathPlate CATIMathPlateCurvLSCArray* CreateCurveLScalarCArray(const int  iDimension,
                                                             const double iParameter,
                                                             const double iTgtValues[],
                                                             const double iDirValues[],
                                                             CATBoolean iIsColinear,
                                                             const double iTolG1);// en radian


#endif

