//===================================================================
// COPYRIGHT Dassault Systemes 16/10/2020
//===================================================================
// CATCivilCurveDefProtected.h
//===================================================================
//
// Usage notes: Defines useful for civil curve operator input (protected)
//
//===================================================================
// Historic:
// 16/10/20 Q48  Creation
// 17/12/20 Q48  Move of ParamType for easier access
// 13/04/21 Q48  Extend CheckParamValue to have NotImpl
//===================================================================

#ifndef CATCivilCurveDefProtected_H
#define CATCivilCurveDefProtected_H

// Common types
#include "CATDataType.h"

namespace CATCivilCurveDef
{
   // --------------------------------------------------------------------------------------------------------
   // Common stream version for all civil types
   // --------------------------------------------------------------------------------------------------------

   // static const CATLONG32 VersionOfStream_Objects = 1; //             : for the existing stream methods
   // static const CATLONG32 VersionOfStream_Objects = 2; // Q48   /  /  : Migration to new stream infrastructure
   // static const CATLONG32 VersionOfStream_Objects = 3; // Q48 25/11/21: Stream init data for CircleCircle
   // static const CATLONG32 VersionOfStream_Objects = 4; // Q48 08/09/22: Remove inflection param and transition length
   // static const CATLONG32 VersionOfStream_Objects = 5; // Q48 29/09/22: Updates to CATCivilHorizParam
   static const CATLONG32 VersionOfStream_Objects = 10;   // Q48 06/12/22: Unify all civil object streaming (operators maintain their own)

   typedef enum CheckParamValue
   {
      Unset = -1,
      IsOK = 0,
      OutOfDomain,
      NotEnoughParam,
      IsAPoint,
      Inconsistent,
      Issue,
      NotImpl
   } CheckParamValue;

   /* CircleCircleTransitionType definitions for creating a civil curve in between to circles
   *  UNDEFINED       : No civil curve can be put in between the circles (considering their respective orientation).
   *  OVE             : One of the circle contains the other and they are oriented same sens.
   *                    Limit case: the 2 circles have same center and radius (and same orientation) => the civil curve is reduced to a point.
   *  REVERSE         : The two circles are exterior to each-other (non-sequent) and have inverted orientation (one clockwise, the other anti-clockwise).
   *                    The transition civil curve has thus a "S" form.
   */
   typedef enum CircleCircleTransitionType
   {
      CSC_UNDEFINED = -1,
      CSC_OVE,
      CSC_REVERSE
   }  CircleCircleTransitionType;
};

#endif //CATCivilCurveDefProtected_H
