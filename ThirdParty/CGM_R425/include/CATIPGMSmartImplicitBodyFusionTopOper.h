#ifndef CATIPGMSmartImplicitBodyFusionTopOper_h_
#define CATIPGMSmartImplicitBodyFusionTopOper_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMImplicitTopOperator.h"
#include "ListPOfCATBody.h"

class CATBody;
class CATFace;
class CATGeoFactory;
class CATTopData;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMSmartImplicitBodyFusionTopOper;

/**
* Class defining an operator that creates an approximate rolling-ball offset of a polyhedral body
* <ul>
*     <li> A <tt>CATICGMPolyhedralRoughOffset</tt> operator is created with the <tt>CATCGMCreatePolyhedralRoughOffset</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByCATGMOperatorsInterfaces CATIPGMSmartImplicitBodyFusionTopOper: public CATIPGMImplicitTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMSmartImplicitBodyFusionTopOper();

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMSmartImplicitBodyFusionTopOper(); // -> delete can't be called
};

/**
 * Creates a CATIPGMSmartImplicitBodyFusionTopOper operator
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iInputBodies
 * List of CATBody* to process
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByCATGMOperatorsInterfaces CATIPGMSmartImplicitBodyFusionTopOper* CATPGMCreateSmartImplicitBodyFusionTopOper(
  CATGeoFactory* iFactory,
  CATTopData* iTopData,
  const ListPOfCATBody& iInputBodies);
#endif /* CATIPGMSmartImplicitBodyFusionTopOper_h_ */
