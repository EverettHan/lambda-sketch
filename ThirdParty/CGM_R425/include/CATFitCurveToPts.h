// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATFitCurveToPts: .
//
//==========================================================================
//
// Usage notes: 
// The number of cotrol points associated to a knot vector must never be 
// greater than the number of grid points. In case of surface fitting this 
// applies the two parameter direction separatedly.
// 
// The Knot vector should agree with the parameters, iParU, and should agree 
// with the knot vector of the curve.
// The objective is the option to change multiplicities, to change degree or 
// to surpress nodes but NOT to change the parametrization interval.
//
// Weights on the derivatives increase (or decrease) tangency compliance on 
// expence of point deviation. Recomended: 1.0. 
//
//========================================================================== 
// Nov 99     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATFitCurveToPts_H
#define CATFitCurveToPts_H

#include <iostream.h>
#include "CATFitCurveToPts.h"
#include "CATMathGridOfPoints.h"
#include "CATMathSetOfPoints.h"
#include "CATNurbsSurface.h"
#include "CATNurbsCurve.h"
#include "CATCrvParam.h"
#include "CATCrvEvalCommand.h"
#include "CATMathPoint.h"
#include "CATKnotVector.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathMxNMatrix.h"
#include "CATMathMxNFullMatrix.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATFrFUtiNurbs.h"
#include "CATMetaClass.h"
#include "CATGeometry.h"
#include "CATMathDef.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATFitCurveToPts : public CATCGMVirtual
 
{

public :
        
    virtual ~CATFitCurveToPts () {} ;
    
    virtual void Run() = 0 ;

    // *************** Fan Ockso
    virtual CATLONG32 OptimizeAtCurrentSize() = 0 ;
};

// For Curve fitting using points and derivatives:
ExportedByFrFFitting 
CATFitCurveToPts * CreateCATFitCurveToPts(const CATMathPoint     *iArrayOfPt,
                                          const CATMathVector    &iFirstEndDeriv, 
                                          const CATMathVector    &iSecondEndDeriv, 
                                          const CATLONG32         iNrParU,
                                          const double           *iParU,
                                          CATKnotVector          *iStartKnotVector,
                                          const CATLONG32         iMaxNrOfKnots,
                                          const CATLONG32         iMaxDegree,
                                          const CATLONG32         iPriorityOnFewArcs,
                                          const double            iMaxDevInMM,
                                          CATNurbsCurve          *ioNurbCrv );

#endif




