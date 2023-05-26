#ifndef CATICGMTopPolarExtremumOperator_h_
#define CATICGMTopPolarExtremumOperator_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U3
*/

#include "CATGMModelInterfaces.h"
#include "CATICGMTopOperator.h"
#include "CATMathDef.h"
#include "CatTopPolarExtremum.h"

class CATMathVector;
class CATTopData;

extern ExportedByCATGMModelInterfaces IID IID_CATICGMTopPolarExtremumOperator;

/**
 * Class defining the operator which computes the polar extremums of a wire body.
 * This operator follows the general scheme of the topological operators:
 * <ul>
 *<li> Create the operator with the global function <tt>CATCreateTopPoslarExtremumOperator</tt>, which defines
 * the wire to be computed and the expected extremums.
 *<li> Set the parameters
 *<li> Run
 *<li> Do not use the GetResult(), GetResult(Journal) methods which will here return a NULL pointer.
 *<li> Get the resulting body by the following methods :
 *<li>   - body = GetResultAngleMin(iJournal, oAngleMin)
 *<li>   - body = GetResultAngleMax(iJournal, oAngleMax)
 *<li>   - body = GetResultRadiusMax(iJournal,oRadiusMin)
 *<li>   - body = GetResultRadiusMax(iJournal,oRadiusMax)
 *<li> Release the operator with the <tt>Release</tt> method after use.
 *</ul>
 */
class ExportedByCATGMModelInterfaces CATICGMTopPolarExtremumOperator: public CATICGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATICGMTopPolarExtremumOperator();

  /**
  * Returns the point located at the minimum angle.
  * @param oAngleMin
  * The minimum angle value from polar axis.
  * @return
  * A pointer to the created vertex body.
  */
  virtual CATBody *GetResultAngleMin(
    CATCGMJournalList *ioReport,
    CATAngle &oAngleMin) = 0;

  /**
  * Returns the point located at the maximum angle.
  * @param oAngleMax
  * The maximum angle value from polar axis.
  * @return
  * A pointer to the created vertex body.
  */
  virtual CATBody *GetResultAngleMax(
    CATCGMJournalList *ioReport,
    CATAngle &oAngleMax) = 0;

  /**
  * Returns the point located at the minimum radius.
  * @param oRadiusMin
  * The minimum radius value from polar origin.
  * @return
  * A pointer to the created vertex body.
  */
  virtual CATBody *GetResultRadiusMin(
    CATCGMJournalList *ioReport,
    CATLength &oRadiusMin) = 0;

  /**
  * Returns the point located at the maximum radius.
  * @param oRadiusMax
  * The maximum radius value from polar origin.
  * @return
  * A pointer to the created vertex body.
  */
  virtual CATBody *GetResultRadiusMax(
    CATCGMJournalList *ioReport,
    CATLength &oRadiusMax) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATICGMTopPolarExtremumOperator(); // -> delete can't be called
};

/**
* Creates a topological operator which computes the polar extremums of a wire.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iWireBody
* The wire body on which polar extremums will be computed.
* @param iPlanarShellBody
* The plane which contains the wire body.
* @param iPolarOriginVertexBody
* The vertex body defining the origin of the lengths and angles.
* @param iPolarAxis
* The direction of the angle reference.
* @return [out, IUnknown#Release]
* A pointer to the created operator. To be released with the <tt>Release</tt> method.
*/
ExportedByCATGMModelInterfaces CATICGMTopPolarExtremumOperator *CATCGMCreateTopPolarExtremumOperator(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATBody *iWireBody,
  CATBody *iPlanarShellBody,
  CATBody *iPolarOriginVertexBody,
  const CATMathVector &iPolarAxis,
  const CatTopPolarExtremum iPolarExtremumExpected);

#endif /* CATICGMTopPolarExtremumOperator_h_ */
