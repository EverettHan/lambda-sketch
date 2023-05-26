//------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES  2004
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
// Computation of Distance with Different Type and Mode between two bodies 
//------------------------------------------------------------------------------------------------ 

//------------------------------------------------------------------------------------------------
// Jan 09 Creation                           MPX
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
#ifndef CATCreateDistanceBodyBody_h
#define CATCreateDistanceBodyBody_h

#include "Distance.h"
#include "CATDistanceBodyBody.h"

/**
 * Creates an operator for computing distance from body1 to body2. Distance type can be Deviation, Maximum, Minimum.
 * Distance mode can be Perpendicular, Directional, General 
 * The input surfaces (or volume) must be G1 continuous.
 * You should set Target Cells to calculate appropriate distance in expected portion of two bodies. You recover appropriate
 * points on two bodies.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the data defining the software configuration and the journal.  
 * @param iBody1
 * The pointer to the first body.
 * @param iBody2
 * The pointer to the second body.
 * @param iType
 * iType = 0 (Deviation Distance) 
 * iType = 1 (Maximum Distance) 
 * iType = 2 (Minimum Distance)
 * @param iMode
 * iMode = 0 (Perpendicular Mode)
 * iMode = 1 (Directional Mode)
 * iMode = 2 (General Mode)
 * @return
 * The pointer to the created operator. To <tt>delete</tt> after use with the usual C++ <tt>delete</tt> operator.
 */
ExportedByDistance CATDistanceBodyBody* CATCreateDistanceBodyBody(CATGeoFactory *iFactory,
                                                                     CATTopData    *iData,
                                                                     CATBody       *iBody1,
                                                                     CATBody       *iBody2,
                                                                     CATDistanceBodyBody::CATDistanceType iType,
                                                                     CATDistanceBodyBody::CATDistanceMode iMode,
                                                                     CATSkillValue iMODE = BASIC);

ExportedByDistance CATDistanceBodyBody* CATCreateDistanceBodyBody(CATGeoFactory *iFactory,
                                                                     CATTopData    *iData,
                                                                     CATCell       *iCell1,
                                                                     CATCell       *iCell2,
                                                                     CATDistanceBodyBody::CATDistanceType iType,
                                                                     CATDistanceBodyBody::CATDistanceMode iMode,
                                                                     CATSkillValue iMODE = BASIC);

ExportedByDistance CATDistanceBodyBody* CATCreateDistanceBodyBody(CATGeoFactory *iFactory,
                                                                     CATTopData    *iData,
                                                                     CATDomain     *iDomain1,
                                                                     CATDomain     *iDomain2,
                                                                     CATDistanceBodyBody::CATDistanceType iType,
                                                                     CATDistanceBodyBody::CATDistanceMode iMode,
                                                                     CATSkillValue iMODE = BASIC);

ExportedByDistance CATDistanceBodyBody* CATCreateDistanceBodyBody(CATGeoFactory *iFactory, 
                                                                     CATTopData    *iData,
                                                                     CATBody       *iBody1,
                                                                     CATBody       *iBody2);    

#endif


