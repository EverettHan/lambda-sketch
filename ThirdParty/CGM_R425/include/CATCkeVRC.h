/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

#ifndef __CATCkeVRC_H
#define __CATCkeVRC_H

#include "CATLifDictionary.h"
#include "CATIParmManipulator.h"

struct ExportedByCATLifDictionary CATCkeVRC
{
  CATCkeVRC(HRESULT iHr=S_OK);
  /**
   * in output of CATCkeValuateParameter will be equal to:
   *  S_OK: all is fine
   *  S_FALSE: valuation succeeded but a value different to input value
   *           has been put on the parameter
   *  E_FAIL:   error detected
   */
  HRESULT hr;
  CATBoolean overFlow;
  CATBoolean underEpsilon;
  CATBoolean noChange;
  CATBoolean invalidString;
  CATIParmManipulator::TestRC trc;
};

/**
 * the following  flags can be combined and used as parameters for CATCkeValuateParameter 
 */

/**
 * use this flag in order to obtain the CATCkeVRC result of the valuation required,
 * without modifying parameter
 */
#define CKE_SIMUL                1

/**
 * bound checking will not be performed and value will not be truncated
 * when below magnitude epsilon
 */
#define CKE_FORCE_VALUE          2

/**
 * "exception" (@see CATLifErrorManager) will not be sent
 */
#define CKE_NO_THROW             4

/**
 * when activated, an input as "1+2+3" will be considered as erroneous
 */
#define CKE_NO_PARSE             8

/**
 * if a value is given as input on a dimension parameter
 * without unit specified (eg: "6" for "6mm")
 * it will be considered to be in the current unit of this
 * magnitude instead of its MKS unit.
 */
#define CKE_PREFER_CURRENT_UNIT 16

/**
 * this flag will allow truncature of input value if 
 * destination parameter is an integer
 * if not added, valuating an integer parameter with 1.5
 * will result in an error
 */
#define CKE_ALLOW_TRUNCATURE 32

/**
 * with this flag activated, nan +/-inf double values will not be accepted
 */
#define CKE_CHECK_FINITE 64

#endif
