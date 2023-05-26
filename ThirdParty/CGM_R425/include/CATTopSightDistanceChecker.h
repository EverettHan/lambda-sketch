/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2019
//=============================================================================
// CATTopSightDistanceChecker :
/**
 * Creates an operator for checking the Sight Distance on a Wire
 * All the curves in the wire must be defined on same surface and it must be a PLANE.
 * To use the operator:
 * <ul><li>Create it with the <tt>CATCreateTopSightDistanceChecker</tt> global function,
 * <li>Set parameters to tune its use,
 *    <ul><li>You must:
 *        <ul><li>SetSightDistance,
 *            <li>SetHeights for Eye and Hazard heights on road 
 *        </ul>
 *    <li>Optional:
 *        <ul><li>SetAcceptTangency
 *            <li>SetRevertDirectionOfCourse
 *        </ul>
 *    </ul>
 * <li>Run the operator ,
 * <li>Retrieve the results with the <tt>GetCheckResult</tt> method,
 * <li><tt>delete</tt> it after use with the usual C++ <tt>delete</tt> operator.
 * </ul>
 */
//=============================================================================
//=============================================================================
// Nov 19 Update interfaces to fit operators implementation + CGMReplay     F4E
// Oct 19 Creation                                                          JSX
//=============================================================================


#ifndef CATTopSightDistanceChecker_h
#define CATTopSightDistanceChecker_h

// COPYRIGHT DASSAULT SYSTEMES  2019

#include "AnalysisTools.h"
#include "CATTopOperator.h"
#include "CATMathDef.h"  

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATLaw;


class ExportedByAnalysisTools CATTopSightDistanceChecker : public CATTopOperator
   {
   CATCGMVirtualDeclareClass( CATTopSightDistanceChecker );
   protected:

      CATTopSightDistanceChecker( CATGeoFactory  * iFactory,
                                  CATTopData     * iData,
                                  CATBody        * iBodyWire );

   public:

      ~CATTopSightDistanceChecker();

 //-----------------------------------------------------------------------------
 //  Settings
 //-----------------------------------------------------------------------------
      virtual void SetHeights( double iDriverEyeHeight, double iHazardHeight ) = 0;
      /**
      * Set the distance between Driver and Hazard.
      *
      * N.B.: for performance we assume that the sight distance is constant along straight lines.
      * To avoid this assumption set boolean to false (default TRUE)
      */
      virtual void SetSightDistance( CATLaw * iSightDistanceLaw, CATBoolean iIsSightDistanceConstantAlongLines = TRUE ) = 0;
      virtual void SetAcceptTangency(CATBoolean iTangencyAccepted = FALSE) = 0;
      virtual void SetRevertDirectionOfCourse(CATBoolean iRevertDirectionOfCourse) = 0;


//-------------------------------------------------------------------------
// Result Access
//-------------------------------------------------------------------------

/**
 * Returns a list of double which must be taken by pairs:
 * each pair is an interval of wire param where the sight line is broken.
 * If empty, the sight distance is respected everywhere.
 */
      virtual void GetCheckResult(CATListOfDouble *& oBreakingSightLineIntervalsOnWire) = 0;


   private:
     // this operator returns no body as a result.
     // to get the result of the check call GetCheckResult()
     virtual CATBody * GetResult() = 0;



   };

ExportedByAnalysisTools 
CATTopSightDistanceChecker * CATCreateTopSightDistanceChecker( CATGeoFactory  * iFactory,
                                                               CATTopData     * iData,
                                                               CATBody        * iBody );


#endif










