#ifndef CATTopReflectLine_H
#define CATTopReflectLine_H

// COPYRIGHT DASSAULT SYSTEMES  2005

/**
* @level Protected
* @usage U1
*/ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "BODYNOPE.h"
#include "CATTopOperator.h"
class CATBody;
class CATFace;

/**
 * Class defining the operator that computes the reflect lines on a skin body.
 *<br>
 * The CATTopReflectLine operator follows the global frame of the topological operators and satisfies the smart mechanism: 
 * the input bodies are not modified. A new resulting body is created, 
 * possibly sharing data with the input bodies.
 *<ul>
 * <li>A CATTopReflectLine operator is created with the <tt>CATCreateTopReflectLine</tt> global method:
 * It must be directly <tt>delete</tt>d after use. It is not streamable. 
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometry factory.
 *</ul>
 */
class ExportedByBODYNOPE CATTopReflectLine : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopReflectLine);
  public :
 /**
 * @nodoc
 * Constructor. Do not use. Use the <tt>CATCreateTopReflectLine</tt> global function to create a
 * CATTopReflectLine operator.
 */
  CATTopReflectLine (CATGeoFactory* iContainer, CATTopData* iData);
  virtual              ~CATTopReflectLine ()          ;

  /**
  * Use this method before the Run() method in order to have a better associativity of the CATTopReflectLine result.
  */
  virtual void OptimizeDomainStructure() = 0;

  /** @nodoc */
  // @nocgmitf
  virtual void FilterBorderSolution() = 0;
 

#ifdef CATIACGMR215CAA 
  /** @nodoc */
  // @nocgmitf
  virtual void ExtractIsoCurves() = 0;
#endif

#ifdef CATIACGMR216CAA 
  /** @nodoc */
  // @nocgmitf
  virtual void SetVolumetricSweepMode(const CATMathVector &iLinearVelocity, const CATMathVector &iAngularVelocity) = 0;
#endif

};
#endif


