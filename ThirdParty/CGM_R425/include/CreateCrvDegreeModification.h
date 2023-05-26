#ifndef CreateCrvDegreeModification_H 
#define CreateCrvDegreeModification_H 

// COPYRIGHT DASSAULT SYSTEMES  2001

/**
 * @level Protected
 * @usage U1
 */

#include "FrFOpeCrv.h"
#include "CATDataType.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATCurve;
class CATCrvDegreeModification;
class CATSoftwareConfiguration;

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
 * @return
 * The pointer to the created operator. 
 * To be deleted with the usual C++ <tt>delete</tt> operator afer use.
 */

ExportedByFrFOpeCrv
CATCrvDegreeModification       * CATCreateCrvDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATSoftwareConfiguration*  iSoftwareConfiguration,
                                                                      CATCurve                *  iNurbsCurve           ,
                                                                const CATLONG32                & iNewDegree            ,
                                                                      CATSkillValue              iMode                 = BASIC);

/*
 * DEPRECATED use CATCreateCrvDegreeModification. June 2016
 */
ExportedByFrFOpeCrv
CATCrvDegreeModification       *    CreateCrvDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATCurve                *  iNurbsCurve           ,
                                                                const CATLONG32                & iNewDegree            ,
                                                                      CATSkillValue              iMode                 = BASIC);

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
 * @return
 * The pointer to the created operator. 
 * To be deleted with the usual C++ <tt>delete</tt> operator afer use.
 */
ExportedByFrFOpeCrv
CATCrvDegreeModification       * CATCreateCrvDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATSoftwareConfiguration*  iSoftwareConfiguration,
                                                                      CATCurve                *  iNurbsCurve           ,
                                                                const CATLONG32                  iTargetDegree         ,
                                                                const double                     iTolerance            ,
                                                                      CATSkillValue              iMode                 = BASIC);
/*
 * DEPRECATED use CATCreateCrvDegreeModification. June 2016
 */
ExportedByFrFOpeCrv
CATCrvDegreeModification       *    CreateCrvDegreeModification(      CATGeoFactory           *  iFactory              ,
                                                                      CATCurve                *  iNurbsCurve           ,
                                                                const CATLONG32                  iTargetDegree         ,
                                                                const double                     iTolerance            ,
                                                                      CATSkillValue              iMode                 = BASIC);

/**
 * @nodoc
 * Removes the operator.
 * @param iCrvDegreeModification
 * The pointer to the operator to be removed.
 */
ExportedByFrFOpeCrv
void Remove( CATCrvDegreeModification *&iCrvDegreeModification );


#endif


