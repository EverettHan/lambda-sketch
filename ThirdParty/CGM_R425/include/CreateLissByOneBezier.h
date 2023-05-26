//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
//====================================================================
//
// Usage notes:
//
//====================================================================
//  Avril 2003 : anr : Creation 
//====================================================================

#ifndef CREATELISSBYONEBEZIER_H 
#define CREATELISSBYONEBEZIER_H
 
#include "MathCascade.h"

#include "CATSkillValue.h"

class CATGeoFactory;
class CATLissByOneBezier;
class CATMathSetOfPointsND;

/**
 * Creates the operator that smoothes a set of points to create a curve.
 * <br>By default, the degree of the smoothed curve is 5, the continuity constraint is C2, the
 * parameterization is free.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iPoints
 * The pointer to the set of points. Its dimension can be 2 (for a planar curve) or 3
 * @param iTol
 * The maximum distance between an input point and the smoothed curve. 
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATLissByOneBezier
 */
ExportedByMathCascade CATLissByOneBezier * CreateLissByOneBezier(CATMathSetOfPointsND *iPoints,
                                                                 CATLONG32                  iFirstPoint,
                                                                 CATLONG32                  iLastPoint,
                                                                 CATLONG32                 *iConstraints,
                                                                 double               *iParameters,
                                                                 CATLONG32                  iDegree,
                                                                 double                iTol,
                                                                 CATLONG32                  iIterations,
											                                           CATSkillValue         iMode=BASIC);

/**
 * @nodoc
 */
ExportedByMathCascade void Remove( CATLissByOneBezier *&iLissByOneBezier);

#endif
