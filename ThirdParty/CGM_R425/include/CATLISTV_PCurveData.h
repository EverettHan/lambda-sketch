//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATLISTV_PCurveData:
//    Header file for the CATLISTV_PCurveData structure.
//
//    The structure is used to store p-curve data for the class
//    CATThinLoopDetector.
//
//=============================================================================
// Usage notes:
//=============================================================================
// 20/09/22 R1Y Creation.
//=============================================================================

#ifndef CATLISTV_PCurveData_H
#define CATLISTV_PCurveData_H

// System
#include "CATLISTV_Declare.h"
#include "CATLISTV_Clean.h"

// GeometricObjects
#include "CATPCurve.h"
#include "CATCrvLimits.h"

// GeometricOperators
#include "Y30C3XGG.h"


/**
  * @collection CATLISTV(PCurveDataElement)
  * Collection class for a p-curve data structure for the class
  * CATThinLoopDetector.
  * Only the following methods of collection classes are available:-
  * <li><tt>AppendList</tt></li>
  * <li><tt>InsertAt</tt></li>
  * <li><tt>IReSize</tt></li>
  * <li><tt>NbOccur</tt></li>
  * <li><tt>RemovePosition</tt></li>
  * <li><tt>RemoveValue</tt></li>
  * <li><tt>Locate</tt></li>
  * <li><tt>Replace</tt></li>
  * <li><tt>ArrayVals</tt></li>
  * <li><tt>Swap</tt></li>
  * Refer to the articles dealing with collections in the encyclopedia.
  */

#define	CATLISTV_AppendList
#define	CATLISTV_InsertAt
#define CATLISTV_ReSize
#define CATLISTV_NbOccur
#define	CATLISTV_RemovePosition
#define	CATLISTV_RemoveValue
#define CATLISTV_Locate
#define CATLISTV_Replace
#define CATLISTV_ArrayVals
#define	CATLISTV_Swap

/**
  * Defines the structure for one element of the list of  p-curve data for the
  * class CATThinLoopDetector.
  * @param <tt>_PCurve</tt>
  * The pointer to a p-curve.
  * @param <tt>_PCurveLimits</tt>
  * The curve limits for a p-curve.
  * @param <tt>_PCurveOrien</tt>
  * Indicates whether the p-curve is in the same direction as the loop.
  * @param <tt>_EdgeIndex</tt>
  * The index (beginning at one) of the edge that contains a p-curve.
  */
struct PCurveDataElement {
                           CATPCurve    * _PCurve;
                           CATCrvLimits   _PCurveLimits;
                           CATBoolean     _PCurveOrien;
                           CATLONG32      _EdgeIndex;
};

/**
 * @nodoc
 */
INLINE int operator == (const PCurveDataElement & iElement1,
                        const PCurveDataElement & iElement2)
{
  return (   (iElement1._PCurve       == iElement2._PCurve)
          && (iElement1._PCurveLimits == iElement2._PCurveLimits)
          && (iElement1._PCurveOrien  == iElement2._PCurveOrien)
          && (iElement1._EdgeIndex    == iElement2._EdgeIndex));
}

/**
 * @nodoc
 */
INLINE int operator != (const PCurveDataElement & iElement1,
                        const PCurveDataElement & iElement2)
{
  return (   (iElement1._PCurve       != iElement2._PCurve)
          || (iElement1._PCurveLimits != iElement2._PCurveLimits)
          || (iElement1._PCurveOrien  != iElement2._PCurveOrien)
          || (iElement1._EdgeIndex    != iElement2._EdgeIndex));
}


#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByY30C3XGG


CATLISTV_DECLARE(PCurveDataElement);


typedef CATLISTV(PCurveDataElement) PCurveDataList;

#endif
