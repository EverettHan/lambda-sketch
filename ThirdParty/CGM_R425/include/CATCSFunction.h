// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSFunction.h
//
//===================================================================
//
// This class is pure virtual, it is designed to be derived by C2 functions of one real variable 
// The domain is assumed t be the set of real numbers
// Example of use: variable offset law
//
//===================================================================
//
//  Oct 2011  Creation:                BF8 / CHU
//===================================================================
#ifndef CATCSFunction_H
#define CATCSFunction_H

#include "CATCDS.h"

//-----------------------------------------------------------------------

/*
 * Used this interface to define new class for the offset variable.
*/

class ExportedBySolverInterface CATCSFunction
{
public:

  // Life cycle (constructor is protected)
  virtual ~CATCSFunction();

  // NOTE: the following methods have identical signatures to likewise methods of CATMathFunctionX

  /**
  * Evaluate the polynomial at given parameter's value
  * @param iT 
  * @return Return the value at given parameter's value
  */
  virtual double Eval(const double & iT) const = 0;

  /**
  * Evaluate the first derivative of the polynomial at given parameter's value
  * @param iT 
  * @return Return the value of the first derivative at given parameter's value
  */
  virtual double EvalFirstDeriv(const double & iT) const = 0; // NOTE: a finite difference implementation should be provided as default 

  /**
  * Evaluate the second derivative of the polynomial at given parameter's value
  * @param iT 
  * @return Return the value of the second derivative at given parameter's value
  */
  virtual double EvalSecondDeriv(const double & iT) const = 0; // NOTE: a finite difference implementation should be provided as default 

  /**
  * Evaluate the third derivative of the polynomial at given parameter's value
  * @param iT 
  * @return Return the value of the third derivative at given parameter's value
  */
  virtual double EvalThirdDeriv (const double & iT) const = 0; // NOTE: a finite difference implementation should be provided as default 


protected:

   /**
  * Constructor
  */
  CATCSFunction();

};

//-----------------------------------------------------------------------

#endif
