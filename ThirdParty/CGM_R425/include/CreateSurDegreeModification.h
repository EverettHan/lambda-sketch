#ifndef CreateSurDegreeModification_H 
#define CreateSurDegreeModification_H 

// COPYRIGHT DASSAULT SYSTEMES  2002

/**
 * @level Protected
 * @usage U1
 */

#include "FrFOpeSur.h"

#include "CATDataType.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATNurbsSurface;
class CATSurDegreeModification;
class CATSoftwareConfiguration;

/**
 * Creates the geometric operator increases the degree of a Nurbs surface.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iNurbsCurve
 * The pointer to the surface to be converted.
 * @param iNewDegreeU
 * The new degree along U.
 * @param iNewDegreeV
 * The new degree along V.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. 
 * To be deleted with the usual C++ <tt>delete</tt> operator afer use.
 */

ExportedByFrFOpeSur
CATSurDegreeModification       * CATCreateSurDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATSoftwareConfiguration*  iSoftwareConfiguration,
                                                                      CATNurbsSurface         *  iNurbsSurface         ,
                                                                const CATLONG32                & iNewDegreeU           ,
                                                                const CATLONG32                & iNewDegreeV           ,
                                                                      CATSkillValue              iMode                 = BASIC);

// DEPRECATED: use CATCreateSurDegreeModification
ExportedByFrFOpeSur
CATSurDegreeModification       *    CreateSurDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATNurbsSurface         *  iNurbsSurface         ,
                                                                const CATLONG32                & iNewDegreeU           ,
                                                                const CATLONG32                & iNewDegreeV           ,
                                                                      CATSkillValue              iMode                 = BASIC);

/**
 * Creates the geometric operator that decreases the degree of a Nurbs curve.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iNurbsCurve
 * The pointer to the curve to be converted.
 * @param iTargetDegreeU
 * The degree along U to be achieved.
 * @param iTargetDegreeV
 * The degree along V to be achieved.
 * @param iTolerance
 * The specified tolerance.
 * @param iMode
 * The mode of use.
 * @return
 * The pointer to the created operator. 
 * To be deleted with the usual C++ <tt>delete</tt> operator afer use.
 */

ExportedByFrFOpeSur
CATSurDegreeModification       * CATCreateSurDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATSoftwareConfiguration*  iSoftwareConfiguration,
                                                                      CATNurbsSurface         *  iNurbsSurface         ,
                                                                const CATLONG32                & iTargetDegreeU        ,
                                                                const CATLONG32                & iTargetDegreeV        ,
                                                                const double                     iTolerance            ,
                                                                      CATSkillValue              iMode                 = BASIC);
// DEPRECATED: use CATCreateSurDegreeModification
ExportedByFrFOpeSur
CATSurDegreeModification       *    CreateSurDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATNurbsSurface         *  iNurbsSurface         ,
                                                                const CATLONG32                & iTargetDegreeU        ,
                                                                const CATLONG32                & iTargetDegreeV        ,
                                                                const double                     iTolerance            ,
                                                                      CATSkillValue              iMode                 = BASIC);

/**
 * @nodoc
 * Removes the operator.
 * @param ioSurDegreeModification
 * The pointer to the operator to be removed.
 */
ExportedByFrFOpeSur
void Remove( CATSurDegreeModification *&ioSurDegreeModification );



#endif


