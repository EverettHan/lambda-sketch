#ifndef CATCREATELISS_H 
#define CATCREATELISS_H
 
// COPYRIGHT DASSAULT SYSTEMES  2004

/**
 * @level Protected
 * @usage U1
 */ 

#include "FrFFitting.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATLiss;
class CATMathSetOfPointsND;
class CATSoftwareConfiguration;

/**
 * Creates the operator that smoothes a set of points to create a curve.
 * <br>By default, the degree of the smoothed curve is 5, the continuity constraint is C2, the
 * parameterization is free.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iConfig
 * The pointer to configuration defining the level of code to replay.
 * @param iPoints
 * The pointer to the set of points. Its dimension can be 2 (for a planar curve) or 3
 * @param iTol
 * The maximum distance between an input point and the smoothed curve. 
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATLiss
 */
ExportedByFrFFitting
CATLiss * CATCreateLiss(CATGeoFactory *iFactory,
                        CATSoftwareConfiguration * iConfig,
                        CATMathSetOfPointsND *iPoints,
                        double         &iTol,
                        CATSkillValue  iMode=BASIC);

#endif
