#ifndef CreateDistanceMinTopo_h
#define CreateDistanceMinTopo_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/ 

//#include "AnalysisTools.h"
#include "AnalysisToolsLight.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATBody;
class CATDomain;
class CATCell;
class CATDistanceMinBodyBody;
class CATTopData;

//#ifndef CATIACGMV5R17 
/** 
 * @nodoc 
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CreateDistanceMinTopo(
                                                 CATGeoFactory *iFactory,
                                                 CATBody       *iBody1,
                                                 CATBody       *iBody2,
                                                 CATSkillValue  iMode=BASIC);
//#endif
/**
 * @deprecated V5R27-R419 CATCGMCreateDistanceBodyBodyOp
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Creates an operator for computing the minimum distance between two CATBody.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal. The journal inside <tt>iData</tt> 
 * is not filled. 
 * @param iBody1
 * The pointer to the first body.
 * @param iBody2
 * The pointer to the second body.
 * @param iMode
 * The mode of use.
 * <br><b>Legal values</b>: 
 *<dl><dt><tt>BASIC</tt></dt><dd> for triggering the computation at the operator creation
 *<dt><tt>ADVANCED</tt></dt><dd> for delaying the computation after the operator creation. Meanwhile,
 * parameters can be set to tune the operator.</dl>
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CATCreateDistanceMinTopo(
                                                 CATGeoFactory *iFactory,
                                                 CATTopData    *iData,
                                                 CATBody       *iBody1,
                                                 CATBody       *iBody2,
                                                 CATSkillValue  iMode=BASIC);
//#ifndef CATIACGMV5R17 
/**
 * @nodoc
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Creates an operator for computing the minimum distance between two CATDomain.
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CreateDistanceMinTopo(
                                                 CATGeoFactory *iFactory,
                                                 CATDomain     *iDomain1,
                                                 CATDomain     *iDomain2,
                                                 CATSkillValue  iMode=BASIC);
//#endif

/** 
 * @deprecated V5R14
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Use the signature with CATBody. 
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CATCreateDistanceMinTopo(
                                                 CATGeoFactory *iFactory,
                                                 CATTopData * iData,
                                                 CATDomain     *iDomain1,
                                                 CATDomain     *iDomain2,
                                                 CATSkillValue  iMode=BASIC);
//#ifndef CATIACGMV5R17 
/**
 * @nodoc
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Creates an operator for computing the minimum distance between two CATCell.
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CreateDistanceMinTopo(
                                                 CATGeoFactory *iFactory,
                                                 CATCell       *iCell1,
                                                 CATCell       *iCell2,
                                                 CATSkillValue  iMode=BASIC);
//#endif

/** 
 * @deprecated V5R14
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Use the signature with CATBody. 
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CATCreateDistanceMinTopo(
                                                 CATGeoFactory *iFactory,
                                                 CATTopData * iData,
                                                 CATCell       *iCell1,
                                                 CATCell       *iCell2,
                                                 CATSkillValue  iMode=BASIC);

/**
 * @nodoc
 * Removes a CATDistanceMinBodyBody operator from memory.
 */
ExportedByAnalysisToolsLight void Remove(CATDistanceMinBodyBody *iOperatorToRemove);


#endif










