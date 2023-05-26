// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSPolynomialFunction.h
//
//===================================================================
//
// This class defines a polynomial function with one variable
// The domain is assumed to be the set of real numbers
//
//===================================================================
//
//  Oct 2011  Creation:                BF8 / CHU
//===================================================================
#ifndef CATCSPolynomialFunction_H
#define CATCSPolynomialFunction_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"   // export
#include "CATCSFunction.h"     // derived

//-----------------------------------------------------------------------


/*
 * Used this class to define polynomial function for the offset variable.
*/

class ExportedBySolverInterface CATCSPolynomialFunction : public CATCSFunction
{
public:

  /**
  * Constructor
  * Life cycle : iCoeffs[] has 1+iDegree parameters, the polynomial function is defined by 
  *  y = iCoeffs[0] + iCoeffs[1] . X +  iCoeffs[2] . X**2 + iCoeffs[3] . X**3 +  ....
  * @param iDegree Degree of the polynomial
  * @param iCoeffs Coefficients of the polynomial
  */
  CATCSPolynomialFunction(int iDegree, double * iCoeffs);

  /**
  * Destructor
  */
  virtual ~CATCSPolynomialFunction();

  /**
  * Evaluate the polynomial at given parameter's value
  * @param iT 
  * @return Return the value at given parameter's value
  */
  virtual double Eval(const double & iT) const CATCDSOverride;

  /**
  * Evaluate the first derivative of the polynomial at given parameter's value
  * @param iT 
  * @return Return the value of the first derivative at given parameter's value
  */
  virtual double EvalFirstDeriv(const double & iT) const CATCDSOverride;

    /**
  * Evaluate the second derivative of the polynomial at given parameter's value
  * @param iT 
  * @return Return the value of the second derivative at iT
  */
  virtual double EvalSecondDeriv(const double & iT) const CATCDSOverride;

  /**
  * Evaluate the third derivative of the polynomial at given parameter's value
  * @param iT 
  * @return Return the value of the third derivative at given parameter's value
  */
  virtual double EvalThirdDeriv (const double & iT) const CATCDSOverride;

  /**
  * Get function
  * @return Return the degree of the polynomial
  */
  virtual int GetDegree () const ;

  /**
  * Get function
  * @return Return the coefficients of the polynomial
  */
  virtual double* GetCoeffs () const ;

private:

  int      _Degree;
  double * _Coeffs; // owned

};

//-----------------------------------------------------------------------

#endif
