/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
 * --------------------------------------------------------
 *=========================================================
 *   PROJET:............BeamFE                             
 *   FRAMEWORK:.........SurfacicMathematics                  
 *   DATE:..............Jan 2002
 *   Purpose : Build some constraint to use in BeamFE algorithms
 *=========================================================
 * HISTORY:
 * Jan 2002 : ktu definition
 */


#ifndef _CATMathPlateCurvLinearScalarConstraint_H
#define _CATMathPlateCurvLinearScalarConstraint_H

#include "MathPlate.h"

class CATMathPlateCurvPinpointConstraint;
class CATMathGridOfPoints;
class CATIMathPlateCurvPPCArray;

class ExportedByMathPlate CATMathPlateCurvLinearScalarConstraint{

public:

   // default
   CATMathPlateCurvLinearScalarConstraint();

   // create 1 lsc 
   CATMathPlateCurvLinearScalarConstraint(const CATMathPlateCurvPinpointConstraint& iPPC,
                                           const double iCoeff[]);

   // create from PPCA and grid off 
   CATMathPlateCurvLinearScalarConstraint(CATIMathPlateCurvPPCArray* iPPCArray, 
														 const CATMathGridOfPoints& iCoeffs,
                                           const double iTol);
   
   //copy 
   CATMathPlateCurvLinearScalarConstraint(const CATMathPlateCurvLinearScalarConstraint & iCopy);

   ~CATMathPlateCurvLinearScalarConstraint();

   CATMathPlateCurvLinearScalarConstraint& operator= (
                              const CATMathPlateCurvLinearScalarConstraint & iLSC ) ; 

   const CATIMathPlateCurvPPCArray * GetPPCs()   const { return _PPCArray;}
   const CATMathGridOfPoints *       GetCoeffs() const { return _Grid;}

   int SetPPC(const int iIndex, const CATMathPlateCurvPinpointConstraint& iPPC) ;
   
   /*  Dimension  
    */
   int GetDimension() const { return _Dimension;}
   void SetDimension(const int iDim)  { _Dimension = iDim;}
   
   /*
    * Tolerance Method's 
    */
   double GetTolerance() const { return _Tolerance; }
   void    SetTolerance(const double & iTol) { _Tolerance = iTol; }
 

private: 

   void Copy(const CATMathPlateCurvLinearScalarConstraint& ippc);

   int                        _Dimension;
   double                     _Tolerance;
   CATIMathPlateCurvPPCArray * _PPCArray;
   CATMathGridOfPoints       * _Grid;


};


#endif
