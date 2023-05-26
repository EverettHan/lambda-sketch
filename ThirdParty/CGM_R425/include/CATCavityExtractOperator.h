#ifndef CATCavityExtractOperator_h
#define CATCavityExtractOperator_h
//==========================================================================
// ExportedByPBELight allows this to be used for ODTs.
//==========================================================================
// 10/12/2020 G5S Created as CATFluidRegionExtractOperator.
// 21/01/2021 G5S Added options of whether to simplify lids and containers.
// 08/07/2021 G5S Allow construction of lids from a list of edges on the container bodies.
// 14/09/2021 G5S Move construction of lids to a separate operator, CATFluidRegionLidOperator.
// 13/10/2021 G5S Added options for external flows and symmetric flows.
// 16/03/2022 G5S Interface to allow several flow side bodies.
// 30/03/2022 G5S Operator name changed to CATCavityExtractOperator.
// 31/03/2022 G5S For lattice operations, new interface to add some containers to the result body.
// 19/10/2022 G5S New Interface SetExteriorWrap(Boolean) to keep all containers and combine into
//                one volume for each set of touching cavities and containers.
// 28/10/2022 G5S New Interface SetKeepOnlyCavitiesTouchingLids(Boolean) to keep only
//                cavities that touch lids.
//==========================================================================

//#include "ExportedByCATTopologicalObjects.h"
#include "CATTopOperator.h"
#include "ExportedByBONEWOPE.h"
#include "ListPOfCATEdge.h"
#include "CATTopDefine.h"

/**
 * Interface representing an operator that uses a solid container bodies and lids
 * to find the cavity or fluid region, i.e. the volumes enclosed by the solid bodies and lids.
 *
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateCavityExtractOperator</tt> global function.
 * <li>Run it
 * <li>Get the resulting body with the <tt>GetResult</tt> method. If you do not want
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
 * geometric factory, after the operator deletion.
 *<li>delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */
class CATCavityExtractOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATCavityExtractOperator);
public:
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
  virtual void SetFlowBox(CATBody* iBody) = 0;

  /**
  * Restrict the cavity or fluid region to one side of a list of planes.  This most useful for symmetric flows.
  * @param iBodyList    - List of bodies each containing a single planar shell.
  * @param iOriList     - List of orientations as integers.  See the definition of CATOrientation.
  *                       If the orientation = CATOrientationPositive = 1, choose the side that the shell is
  *                       oriented towards. If it is CATOrientationNegative = -1, choose the other side.
  */
  virtual void SetFlowSide(ListPOfCATBody& iBodyList, CATListOfInt& iOriList) = 0;

  /*
  * For lattice operations, set the list of solid container bodies that we want in the result besides the cavity.
  * In this mode, the volumes of these bodies and/or the cavity will be kept as separate volumes even if they
  * are touching.
  * @param iBodyList - The list of solid container bodies.
  */
  virtual void SetContainerBodiesToKeep(ListPOfCATBody& iBodyList) = 0;

  virtual ~CATCavityExtractOperator();

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
  CATCavityExtractOperator(CATGeoFactory * iGeoFactory, CATTopData * iData, CATExtTopOperator* iExtensible);
  
};

/**
 * Creates a CATCavityExtractOperator.
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
ExportedByBONEWOPE CATCavityExtractOperator * CATCreateCavityExtractOperator(CATGeoFactory * iFactory,
  CATTopData * iTopData,
  ListPOfCATBody & iSolidContainerBodyList,
  ListPOfCATBody & iLidBodyList);

#endif
