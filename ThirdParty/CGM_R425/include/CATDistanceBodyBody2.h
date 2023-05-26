//------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES  2008
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
// Computation of Distance between two bodies belonging to different containers
//------------------------------------------------------------------------------------------------ 

//------------------------------------------------------------------------------------------------
// Dec 08 Creation                           MPX
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
#ifndef CATDistanceBodyBody2_h
#define CATDistanceBodyBody2_h

#include "Distance.h"
#include "CATDistanceBodyBody2Light.h"
/**
 * Creates an operator for computing general minimum distance from body1 to body2, belonging to different containers.
 * The input surfaces (or volume) must be G1 continuous.
 * @param iData
 * The pointer to the data defining the software configuration and the journal.  
 * @param iFactory1
 * The pointer to the factory of the geometry of first body.
 * @param iBody1
 * The pointer to the first body.
 * @param iBody1Transformation
 * Tranformation to be applied to iBody1 before calculating distance
 * @param iFactory2
 * The pointer to the factory of the geometry of second body.
 * @param iBody2
 * The pointer to the second body.
 * @param iBody2Transformation
 * Tranformation to be applied to iBody2 before calculating distance
 * @param iSkillValue
 * If used with <tt>BASIC</tt> skill value, then distance is directly computed at the 
 * operator creation. So that you directly access the result without <tt>Run</tt>ning the operator.
 * If used with <tt>ADVANCED</tt> skill value, then one needs to <tt>Run</tt> the operator before
 * accessing the result.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByDistance CATDistanceBodyBody2* CATCreateDistanceBodyBody2(
                                                                     CATTopData    *iTopData,
                                                                     CATGeoFactory  *iFactory1,
                                                                     CATBody       *iBody1,
                                                                     const CATMathTransformation& iBody1Transformation,
                                                                     CATGeoFactory  *iFactory2,
                                                                     CATBody       *iBody2,
                                                                     const CATMathTransformation& iBody2Transformation,
                                                                     CATSkillValue iSkillValue = BASIC);


/**
 * Creates an operator for computing general minimum distance from cell1 to cell2, belonging to different containers.
 * The input surfaces (or volume) must be G1 continuous.
 * @param iData
 * The pointer to the data defining the software configuration and the journal.  
 * @param iFactory1
 * The pointer to the factory of the geometry of first cell.
 * @param iCell1
 * The pointer to the first cell.
 * @param iCell1Transformation
 * Tranformation to be applied to iCell1 before calculating distance
 * @param iFactory2
 * The pointer to the factory of the geometry of second cell.
 * @param iCell2
 * The pointer to the second cell.
 * @param iCell2Transformation
 * Tranformation to be applied to iCell2 before calculating distance
 * @param iSkillValue
 * If used with <tt>BASIC</tt> skill value, then distance is directly computed at the 
 * operator creation. So that you directly access the result without <tt>Run</tt>ning the operator.
 * If used with <tt>ADVANCED</tt> skill value, then one needs to <tt>Run</tt> the operator before
 * accessing the result.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByDistance CATDistanceBodyBody2* CATCreateDistanceBodyBody2(
                                                                     CATTopData    *iTopData,
                                                                     CATGeoFactory  *iFactory1,
                                                                     CATCell       *iCell1,
                                                                     const CATMathTransformation& iCell1Transformation,
                                                                     CATGeoFactory  *iFactory2,
                                                                     CATCell       *iCell2,
                                                                     const CATMathTransformation& iCell2Transformation,
                                                                     CATSkillValue iSkillValue = BASIC);

/**
 * Creates an operator for computing general minimum distance from domain1 to domain2, belonging to different containers.
 * The input surfaces (or volume) must be G1 continuous.
 * @param iData
 * The pointer to the data defining the software configuration and the journal.  
 * @param iFactory1
 * The pointer to the factory of the geometry of first domain.
 * @param iDomain1
 * The pointer to the first domain.
 * @param iDomain1Transformation
 * Tranformation to be applied to iDomain1 before calculating distance
 * @param iFactory2
 * The pointer to the factory of the geometry of second domain.
 * @param iDomain2
 * The pointer to the second domain.
 * @param iDomain2Transformation
 * Tranformation to be applied to iDomain2 before calculating distance
 * @param iSkillValue
 * If used with <tt>BASIC</tt> skill value, then distance is directly computed at the 
 * operator creation. So that you directly access the result without <tt>Run</tt>ning the operator.
 * If used with <tt>ADVANCED</tt> skill value, then one needs to <tt>Run</tt> the operator before
 * accessing the result.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByDistance CATDistanceBodyBody2* CATCreateDistanceBodyBody2(
                                                                     CATTopData    *iTopData,
                                                                     CATGeoFactory  *iFactory1,
                                                                     CATDomain     *iDomain1,
                                                                     const CATMathTransformation& iDomain1Transformation,
                                                                     CATGeoFactory  *iFactory2,
                                                                     CATDomain     *iDomain2,
                                                                     const CATMathTransformation& iDomain2Transformation,
                                                                     CATSkillValue iMODE = BASIC);

// Functions not supported as of today
/** 
* @nodoc
*/	
ExportedByDistance CATDistanceBodyBody2* CATCreateDistanceBodyBody2(
                                                                     CATTopData    *iTopData,
                                                                     CATGeoFactory  *iFactory1,
                                                                     CATBody       *iBody1,
                                                                     const CATMathTransformation& iBody1Transformation,
                                                                     CATGeoFactory  *iFactory2,
                                                                     CATBody       *iBody2,
                                                                     const CATMathTransformation& iBody2Transformation,
                                                                     CATDistanceBodyBody::CATDistanceType iType,
                                                                     CATDistanceBodyBody::CATDistanceMode iMode,
                                                                     CATSkillValue iSkillValue = BASIC);

/** 
* @nodoc
*/	
ExportedByDistance CATDistanceBodyBody2* CATCreateDistanceBodyBody2(
                                                                     CATTopData    *iTopData,
                                                                     CATGeoFactory  *iFactory1,
                                                                     CATCell       *iCell1,
                                                                     const CATMathTransformation& iCell1Transformation,
                                                                     CATGeoFactory  *iFactory2,
                                                                     CATCell       *iCell2,
                                                                     const CATMathTransformation& iCell2Transformation,
                                                                     CATDistanceBodyBody::CATDistanceType iType,
                                                                     CATDistanceBodyBody::CATDistanceMode iMode,
                                                                     CATSkillValue iSkillValue = BASIC);

/** 
* @nodoc
*/	
ExportedByDistance CATDistanceBodyBody2* CATCreateDistanceBodyBody2(
                                                                     CATTopData    *iTopData,
                                                                     CATGeoFactory  *iFactory1,
                                                                     CATDomain     *iDomain1,
                                                                     const CATMathTransformation& iDomain1Transformation,
                                                                     CATGeoFactory  *iFactory2,
                                                                     CATDomain     *iDomain2,
                                                                     const CATMathTransformation& iDomain2Transformation,
                                                                     CATDistanceBodyBody::CATDistanceType iType,
                                                                     CATDistanceBodyBody::CATDistanceMode iMode,
                                                                     CATSkillValue iMODE = BASIC);

#endif


