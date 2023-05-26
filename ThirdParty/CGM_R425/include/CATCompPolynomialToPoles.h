// COPYRIGHT DASSAULT SYSTEMES PROVENCE 1999
//
// P. MANGIN Decembre 1999 : Curve Conversion operator

#ifndef _CATCompPolynomialToPoles_H
#define _CATCompPolynomialToPoles_H



#include "MathCascade.h"
#include "CATMathDef.h"

class CATCompPolynomialToPoles  {

public:

 // Methods PUBLIC
 // 
 virtual ~CATCompPolynomialToPoles();

 virtual int NbPoles() const =0; 
 virtual int Degree() const =0;
 virtual int NbKnots() const =0;
 virtual CATBoolean IsDone() const =0;
 virtual int GetResult( double * oKnots   ,
												int    * oMult    ,
												double * oPoles) const =0;
};

/*
---Purpose: 
    --   This class uses the following arguments :
    --   iNbrCurve :  the number of Polynomial Curves 
    --   iContTab  :  the requested continuity for the n-dimensional Spline 
											(ie a [iNbrCurve+1] array)
    --   iDimSpa :  the dimension of the Spline
    --   iMaxDegree  :  maximum allowed degree for each composite 
    --                polynomial segment.
    --   iNbrCoeff : the number of coefficient per segments = degree - 1
    --   iCoefficients   :  the coefficients organized in the following way
    --       [1..<myNumPolynomials>][1..myMaxDegree +1][1..myDimension] 
    --       that is : index [n,d,i] is at slot 
    --       (n-1) * (myMaxDegree + 1) * myDimension + (d-1) * myDimension + i
    --  iIntDef :  nth polynomial represents a polynomial between 
    --     iIntDef[2*n-2] and 
    --     iIntDef[2*n-1]
    --  iKnotsTab : the nth polynomial has to be mapped linearly to be
    --       defined on the following interval :
    --       myTrueIntervals[n] and myTrueIntervals[n+1]
    --       so that it represent adequatly the function with the
    --       required continuity
*/
ExportedByMathCascade CATCompPolynomialToPoles * 
	CreateCompPolynomialToPoles(const int      iDimSpa  ,
															const int      iNbrCurve,
															const int      iMaxDegree  ,
															const int    * iContTab , 
															const int    * iNbrCoeff,
															const double * iCoefficients   ,
															const double * iIntDef  ,
															const double * iKnotsTab );

ExportedByMathCascade void Remove(CATCompPolynomialToPoles *&);


#endif
