#ifndef CATDistanceMinImpl_h
#define CATDistanceMinImpl_h

#include "CATExtTopOperator.h"
#include "CATHybDef.h"
#include "CATMathDef.h"
#include "AnalysisToolsLight.h"

class CATTopOpEnvironment;


///////////////////////////////////////////////////////////////
// This API has been deprecated. 
// Please use the new API instead:
//    CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
///////////////////////////////////////////////////////////////


/**
 * @deprecated V5R27-R419 CATICGMDistanceBodyBody
 * This API has been deprecated. 
 * Please use the new API instead:
 *   CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
 *
 * Base class minimum distance operator, serving as an interface for 
 * compatibility with both old and new distance operators.
 */
class ExportedByAnalysisToolsLight CATDistanceMinImpl : public CATExtTopOperator
{
  public :
    //CATDistanceMinImpl(CATGeoFactory  *iFactory,CATTopData * iData,
    //                       CATBody        *iBody1,
    //                       CATBody        *iBody2);

    virtual ~CATDistanceMinImpl();

    virtual double GetDistanceMax() = 0;
    virtual void SetDistanceMax(double iDistance) = 0;

    virtual int Run() = 0;

    virtual void ReplaceBody(CATBody *iBodyToReplace, CATBody *iNewBody) = 0;
    virtual double  GetDistance() = 0;
    virtual void GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2) = 0;
    virtual void GetSupportCells(CATCell *&oCell1, CATCell *&oCell2) = 0;

    virtual void SetPointComputationMode(CATBoolean iTrueOrFalse) = 0;
    virtual void SetMaxNumberOfTests(CATLONG32 iMaxNumberOfTests) = 0; 
    virtual CATBoolean GetPointComputationMode() = 0;
    virtual CATBoolean GetMathPoints(CATMathPoint& oP1, CATMathPoint& oP2) = 0;
    virtual CATBody* GetBody1() = 0; 
    virtual CATBody* GetBody2() = 0; 
    virtual void GetBody(CATLONG32 iNum, CATBody *& oBody) = 0;
    virtual CATBoolean Done() = 0;
    virtual void SetDone(CATBoolean idone) = 0;
    virtual CATLONG32 GetMaxNumberOfTests() = 0; 
    virtual void SetEnvironment(CATTopOpEnvironment * iEnviron) = 0;
    virtual void ErasePoint(CATPoint *&oPoint) = 0;
    virtual void GetPoints_forDebug(CATPoint *&oPoint1, CATPoint *&oPoint2) = 0;
};

#endif










