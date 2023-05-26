#ifndef CATIPGMCavityExtractOperator_h_
#define CATIPGMCavityExtractOperator_h_

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMCavityExtractOperator;

/**
 * Interface representing an operator that uses a solid container bodies and lids
 * to find the cavity or fluid region, i.e. the volumes enclosed by the solid bodies and lids.
 *
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATPGMCreateCavityExtractOperator</tt> global function.
 * <li>Run it
 * <li>Get the resulting body with the <tt>GetResult</tt> method. If you do not want
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
 * geometric factory, after the operator deletion.
 *<li>delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */
class ExportedByCATGMOperatorsInterfaces CATIPGMCavityExtractOperator: public CATIPGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMCavityExtractOperator();

  /**
  * Simplify edges between solid containers. 
  * @param iSimplify
  * Whether to simplify.  By default, simplification is done.
  */
  virtual void SetSimplifyContainers(CATBoolean iSimplify) = 0;

  /**
  * Simplify edges between lids and containers.
  * @param iSimplify
  * Whether to simplify.  By default, simplification is not done.
  */
  virtual void SetSimplifyLids(CATBoolean iSimplify) = 0;

  /**
  * Whether to find the Exterior Wrap, i.e. The combination of the cavity
  * and all the container bodies to produce a body with one volume for each 
  * set of containers and cavities that touch.
  * @param iExteriorWrap. By default, an Exterior Wrap is not done.
  */
  virtual void SetExteriorWrap(CATBoolean iExteriorWrap) = 0;

  /**
  * Whether to keep in the result only the volumes in contact with lids and 
  * not those that are completely enclosed by the container bodies.
  * @param iKeepOnlyLidCavities. By default, this is false and we keep all volumes.
  */
  virtual void SetKeepOnlyCavitiesTouchingLids(CATBoolean iKeepOnlyLidCavities) = 0;

  /**
  * Restrict the cavity or fluid region to the box. This most useful for external flows.
  * @param iBody - A body consisting of a single closed shell.
  */
  virtual void SetFlowBox(CATBody *iBody) = 0;

  /**
  * Restrict the cavity or fluid region to one side of a list of planes.  This most useful for symmetric flows.
  * @param iBodyList    - List of bodies each containing a single planar shell.
  * @param iOriList     - List of orientations as integers.  See the definition of CATOrientation.
  *                       If the orientation = CATOrientationPositive = 1, choose the side that the shell is
  *                       oriented towards. If it is CATOrientationNegative = -1, choose the other side.
  */
  virtual void SetFlowSide(
    CATLISTP(CATBody) &iBodyList,
    CATListOfInt &iOriList) = 0;

  /**
  * For lattice operations, set the list of solid container bodies that we want in the result besides the cavity.
  * In this mode, the volumes of these bodies and/or the cavity will be kept as separate volumes even if they
  * are touching.
  * @param iBodyList - The list of solid container bodies.
  */
  virtual void SetContainerBodiesToKeep(CATLISTP(CATBody) &iBodyList) = 0;

  /**
  * Simplify edges between solid containers.
  * @param iPHAuthorized
  * tell if we request a PH Result value
  * 0 : the result will be an exact body
  * 1 : the result will be a polyhedral result.
  */
  virtual void RequestForPHResult(int iPHAuthorized) = 0;

  /**
  * Simplify edges between solid containers.
  * @param iTolerance
  * if we have leak we will try to fill them using this tolerance as maximum value.
  * default value is resolution if not requested
  */
  virtual void SetMaxDistanceForLeak(double iTolerance) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMCavityExtractOperator(); // -> delete can't be called
};

/**
 * Creates a CATIPGMCavityExtractOperator.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iSolidContainerBodyList
 * List of solid container bodies.
 * @param iLidBodyList
 * List of surfacic or volumic bodies that make up the lids. There does not have to be exactly one body per lid.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByCATGMOperatorsInterfaces CATIPGMCavityExtractOperator *CATPGMCreateCavityExtractOperator(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  CATLISTP(CATBody) &iSolidContainerBodyList,
  CATLISTP(CATBody) &iLidBodyList);

#endif /* CATIPGMCavityExtractOperator_h_ */ 
