#ifndef CATCREATEINTERPROXCRV_H 
#define CATCREATEINTERPROXCRV_H 

// COPYRIGHT DASSAULT SYSTEMES  2004

/**
 * @level Protected
 * @usage U1
 */ 

#include "FrFOpeCrv.h"

#include "CATSkillValue.h"
#include "CATListOfCATCurves.h"
class CATGeoFactory;
class CATMathSetOfPointsND;
class CATMathSetOfVectors;
class CATInterproxCrv;
class CATCurve;
class CATSoftwareConfiguration;
/**
 * Creates the operator that deforms curves on a set of points.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iConfig
 * The pointer to configuration defining the level of code to replay.
 * @param iListe
 * The list of pointers to the curves to deform.
 * @param iPoints
 * The pointer to the set of points on which the curves are deformed.
 * @param iVectors
 * To keep to <tt>0</tt>.
 * @param iTension
 * The tension.
 * @param iSmoothness
 * The smoothness.
 * @param iTolapp
 * Always keep to the factory resolution.
 * @param iImposition
 * The array [2] defining the type of constraints at each extremities of the deformed curve.
 * <br><b>Legal values</b>: <tt>0</tt> if a G0 continuity with the input curve is required, 
 * <tt>1</tt> for a G1 continuity, <tt>2</tt> for a G1 continuity.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATInterproxCrv
 */
ExportedByFrFOpeCrv
CATInterproxCrv * CATCreateInterproxCrv(CATGeoFactory *iFactory,
                                        CATSoftwareConfiguration * iConfig,
                                        CATLISTP(CATCurve ) &iListe,
                                        const CATMathSetOfPointsND *iPoints,
                                        const CATMathSetOfVectors *iVectors,  
                                        double & iTension , 
                                        double & iSmoothness,
                                        double & iTolapp  ,
                                        const int iImposition[2] , 
                                        CATSkillValue iMode=BASIC );


/** 
 * @nodoc
 */
ExportedByFrFOpeCrv
void Remove( CATInterproxCrv *&iInterproxCrv);

#endif
