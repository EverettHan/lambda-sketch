#ifndef CATCreateConvertCrvToNurbsCrv_H
#define CATCreateConvertCrvToNurbsCrv_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

class CATCurve;
class CATGeoFactory;
class CATConvertCrvToNurbsCrv;
class CATSoftwareConfiguration;

#include "FrFOpeCrv.h"
#include "CATSkillValue.h"


/**
 * @deprecated V5R10 CreateCrvFittingToNurbsCrv
 * Creates the geometric operator that computes the Nurbs representation of a CATCurve.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iCurve
 * The pointer to the curve to convert.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. To <tt>delete</tt> with the usual C++ delete operator afer use.
 * @see CATConvertCrvToNurbsCrv
 */
ExportedByFrFOpeCrv
 CATConvertCrvToNurbsCrv*  CATCreateConvertCrvToNurbsCrv(      CATGeoFactory           *  iFactory ,
                                                         const CATCurve                 & iCurve   ,
                                                               CATSkillValue              iMode    = BASIC);
ExportedByFrFOpeCrv
 CATConvertCrvToNurbsCrv*  CATCreateConvertCrvToNurbsCrv(      CATGeoFactory           *  iFactory ,
                                                               CATSoftwareConfiguration*  iConfig,
                                                         const CATCurve                 & iCurve );

#endif
