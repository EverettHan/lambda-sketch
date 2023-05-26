
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// Creation: P.MANGIN Decembre 1999


#ifndef _CATGridPolynomialToPoles_H
#define _CATGridPolynomialToPoles_H

#include "MathCascade.h"
#include "CATMathDef.h"

class  CATGridPolynomialToPoles  
{

public:

 // Methods PUBLIC
 // 	 
 virtual CATBoolean IsDone() const =0;
 virtual int NbUPoles() const =0;
 virtual int NbVPoles() const =0;
 virtual int UDegree() const =0;
 virtual int VDegree() const =0;
 virtual int NbUKnots() const =0;
 virtual int NbVKnots() const =0; 
	 
 virtual int GetResult(double * oUKnots  , 
											 double * oVKnots  ,
											 int    * oUMult   ,
											 int    * oVMult   ,
											 double * oPoles) const =0;


};

/*
---Purpose: To one grid of polynomial Surface.
 ---Level: Advanced
 ---Warning:
 --  Continuity in each parametric direction can be at MOST the
 --  maximum degree of the polynomial functions. 
 --           
 --  <TrueUIntervals>, <TrueVIntervals> :
 --  this is the true parameterisation for the composite surface
 --  
 --  Coefficients :
 --  The Coefficients have to be formated than an "C array" 
 --          [NbVSurfaces] [NBUSurfaces] [MaxUDegree+1] [MaxVDegree+1] [3]
 raises DomainError ; -- if <NumCoeffPerSurface> is not a  
                      -- [1, NbVSurfaces*NbUSurfaces, 1,2] array.
                      -- if <Coefficients> is not a 
	                    --[1, NbVSurfaces*NBUSurfaces*(MaxUDegree+1)*(MaxVDegree+1)*3] array
*/

ExportedByMathCascade CATGridPolynomialToPoles * 
	CreateGridPolynomialToPoles( const int      iNbrPatchU,  
															 const int      iNbrPatchV,
															 const int      iMaxDegInU,
															 const int      iMaxDegInV,
															 const int    * iContUTab ,
															 const int    * iContVTab ,
															 const int    * iNbrCoeff ,
															 const double * iCoeffUV  ,
															 const double * iIntDefU  ,
															 const double * iIntDefV  ,
															 const double * iKnotsUTab,
															 const double * iKnotsVTab );

ExportedByMathCascade void Remove(CATGridPolynomialToPoles *&);

#endif
