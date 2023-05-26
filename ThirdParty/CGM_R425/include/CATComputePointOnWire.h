#ifndef CATComputePointOnWire_H
#define CATComputePointOnWire_H

// COPYRIGHT : DASSAULT SYSTEMES 2001
/**
 * @required Protected
 * @usage U1
 */ 

#include "YJ000GSM.h"
#include "CATTopOperator.h"
#include "CATIAV5Level.h"

class CATGeoFactory;
class CATMathPoint;
class CATBody;
class CATTopData;



/**
 * Class defining the operator that computes mathematical points on a wire.
 *<br> This operator follows the general scheme of the topological operators:
 *<ul>
 *<li> Create the operator with the global function <tt>CATCreateComputePointOnWire</tt>
 *<li> Set parameters if necessary
 *<li> Run with the <tt>Run</tt> method
 *<li> Get the result mathematical point with the <tt>GetMathPoint</tt> method.
 * Here, the <tt>GetResult</tt> method will always return <tt>NULL</tt>, and there is no associated
 * journal, because the operator does not create any body. 
 *<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */ 
class  ExportedByYJ000GSM CATComputePointOnWire : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATComputePointOnWire);
public:
  
  /** @nodoc */
  CATComputePointOnWire(CATGeoFactory* iFactory, CATTopData * iTopData );

  virtual ~CATComputePointOnWire();

  /**
   * Defines the value for the computation and it switches the type of computation to mathpointform value.
   * @param iValue
   * The value, according to the computation mode.
   */
  virtual void SetValue (double iValue)=0;

  /**
   * Defines the mathematical point and it switches the type of computation to valued from mathpoint.
   * @param iPoint
   * The CATMathPoint.
   */
  virtual void SetMathPoint(const CATMathPoint & iPoint)=0;

  /**
   * Runs <tt>this</tt> operator.
   * @return
   * Not <tt>NULL</tt> in case of error.
   */
  virtual int Run()=0;

  /**
   * Retrieves the corresponding mathematical point.
   * @param ioResultPoint
   * The result as a CATMathPoint.
   */
  virtual void GetMathPoint(CATMathPoint & ioResultPoint)=0;

  /**
   * Retrieves the corresponding value for the computation.
   * @param oResultValue
   * The value, according to the computation mode.
   */
  virtual void GetValue (double & oResultValue)=0;

};
/**
* Creates an operator that computes mathematical points on a wire.
* @param iFactory
* The factory of the geometry.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. Notice that here, the journal is
* not filled, because there is no body creation.
* @param iWire
* The pointer to the wire body on which the mathematical point is computed.
* @param iValue
* The ratio of the length of the wire on which the mathematical point is computed.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByYJ000GSM
CATComputePointOnWire * CATCreateComputePointOnWire(CATGeoFactory* iFactory, 
                                                    CATTopData * iTopData, 
                                                    CATBody* iWire, 
                                                    double iValue);
#endif
