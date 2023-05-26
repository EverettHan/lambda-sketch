#ifndef CATCGMCreateCrvDegreeModification_h_
#define CATCGMCreateCrvDegreeModification_h_

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * @CAA2Level L1
 * @CAA2Usage U3
*/

#include "CATGMOperatorsInterfaces.h"
#include "CATDataType.h"
#include "CATSkillValue.h"

class CATICGMCrvDegreeModification;
class CATCurve;
class CATGeoFactory;
class CATSoftwareConfiguration;

/**
 * Creates the geometric operator that decreases the degree of a Nurbs curve.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iNurbsCurve
 * The pointer to the curve to be converted.
 * @param iTargetDegree
 * The degree to be achieved.
 * @param iTolerance
 * The specified tolerance.
 * @param iMode
 * The mode of use.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. 
 * To be released with the <tt>Release</tt> method afer use.
 */
ExportedByCATGMOperatorsInterfaces CATICGMCrvDegreeModification *CATCGMCreateCrvDegreeModification(
  CATGeoFactory *iFactory,
  CATSoftwareConfiguration* iSoftwareConfiguration,
  CATCurve *iNurbsCurve,
  const CATLONG32 iTargetDegree,
  const double iTolerance,
  CATSkillValue iMode = BASIC);

/*
 * DEPRECATED use CATCGMCreateCrvDegreeModification with software configuration. June 2016
 */
ExportedByCATGMOperatorsInterfaces CATICGMCrvDegreeModification *CATCGMCreateCrvDegreeModification(
  CATGeoFactory *iFactory,
  CATCurve *iNurbsCurve,
  const CATLONG32 iTargetDegree,
  const double iTolerance,
  CATSkillValue iMode = BASIC);

/**
 * Creates the geometric operator increases the degree of a Nurbs curve.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iNurbsCurve
 * The pointer to the curve to be converted.
 * @param iNewDegree
 * The new degree.
 * @param iMode
 * The mode of use.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. 
 * To be released with the <tt>Release</tt> method afer use.
 */
ExportedByCATGMOperatorsInterfaces CATICGMCrvDegreeModification *CATCGMCreateCrvDegreeModification(
  CATGeoFactory *iFactory,
  CATSoftwareConfiguration* iSoftwareConfiguration,
  CATCurve *iNurbsCurve,
  const CATLONG32 &iNewDegree,
  CATSkillValue iMode = BASIC);

/*
 * DEPRECATED use CATCGMCreateCrvDegreeModification with software configuration. June 2016
 */
ExportedByCATGMOperatorsInterfaces CATICGMCrvDegreeModification *CATCGMCreateCrvDegreeModification(
  CATGeoFactory *iFactory,
  CATCurve *iNurbsCurve,
  const CATLONG32 &iNewDegree,
  CATSkillValue iMode = BASIC);

#endif /* CATCGMCreateCrvDegreeModification_h_ */
