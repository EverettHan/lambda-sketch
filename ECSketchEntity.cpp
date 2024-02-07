
#include <stdint.h>

#include <CATGeoFactory.h>
#include <CATSoftwareConfiguration.h>
#include <CATBody.h>
#include <CATErrorMacros.h>
#include <CATSurLimits.h>
#include <CATLine.h>
#include <CATCGMJournalList.h>
#include <CATGeometry.h>
#include <CATCGMCellTracker.h>
#include <CATCGMContainerMngt.h>
#include <CATIPGMTopCompatible.h>
#include <CATMathPlane.h>
#include <CATCircle.h>
#include <CATEllipse.h>
#include <CATCrvLimits.h>

#include <SWXUtAssert.h>

#include "ECSketchEntity.h"
#include "ECCurveUtilities.h"



CATBody* ECSketchCurve::makeCurveBody(const CATGeoFactory_var &iGeoFactory, CATTopData *iTopData)
{
    CATBody* pWireBody = NULL;
    
 
    CATCurve* pCATCrv = getCATCurve(iGeoFactory);
    if (pCATCrv == NULL)
        return NULL;

    CATCrvLimits lim;
    pCATCrv->GetLimits(lim);
    
    pWireBody = ECCurveUtilities::MakeWireBody(iTopData, pCATCrv, lim);

    iGeoFactory->Remove(pCATCrv) ;

    return pWireBody;

}


CATCurve* ECSketchLineSegment::getCATCurve(const CATGeoFactory_var &iGeoFactory)
{
    SWXUtLine* pUTLine = getGeometry();
    shared_ptr<ECSketchPoint> spSKStartPt = getStartPt();
	shared_ptr<ECSketchPoint> spSKEndPt = getEndPt();

    SWX_VERIFY_RETURN(iGeoFactory != NULL && pUTLine != NULL && spSKStartPt != nullptr && spSKEndPt != nullptr, "null pointer found", NULL);
	
    SWXUtPoint* pUTStartPoint = spSKStartPt->getGeometry();
    SWXUtPoint* pUTEndPoint = spSKEndPt->getGeometry();
    SWX_VERIFY_RETURN(pUTStartPoint != NULL && pUTEndPoint != NULL, "null pointer found", NULL);
	
    CATMathPoint st = pUTStartPoint->Point();
    CATMathPoint end = pUTEndPoint->Point();

    CATLine* pLine = iGeoFactory->CreateLine(st,end);
    
	return pLine;
}

CATCurve* ECSketchCircleGeom::getCATCurve(const CATGeoFactory_var &iGeoFactory)
{
    SWXUtCircle* pUTCircle = getGeometry();
    SWX_VERIFY_RETURN(iGeoFactory != NULL && pUTCircle != NULL, "null pointer found", NULL);
	
    CATMathPoint center = pUTCircle->Center();
	double radius = pUTCircle->Radius();
    
    CATMathPlane pln(center, pUTCircle->XDir(), pUTCircle->YDir());

    CATCircle* pCircle = iGeoFactory->CreateCircle(radius, pln);
    
    return (pCircle);
}


CATCurve* ECSketchArc::getCATCurve(const CATGeoFactory_var &iGeoFactory)
{
    SWXUtCircle* pUTCircle = getGeometry();
    SWX_VERIFY_RETURN(iGeoFactory != NULL && pUTCircle != NULL, "null pointer found", NULL);
	
    CATMathPoint center = pUTCircle->Center();
    CATMathDirection x_dir = pUTCircle->XDir();
    CATMathDirection normal_dir = pUTCircle->Axis();
	double radius = pUTCircle->Radius();
    
    CATMathPlane pln(center, pUTCircle->XDir(), pUTCircle->YDir());

    shared_ptr<ECSketchPoint> spSKStartPt = getStartPt();
	shared_ptr<ECSketchPoint> spSKEndPt = getEndPt();
    SWX_VERIFY_RETURN(spSKStartPt != nullptr && spSKEndPt != nullptr, "null pointer found", NULL);
	
    SWXUtPoint* pUTStartPoint = spSKStartPt->getGeometry();
    SWXUtPoint* pUTEndPoint = spSKEndPt->getGeometry();
    SWX_VERIFY_RETURN(pUTStartPoint != NULL && pUTEndPoint != NULL, "null pointer found", NULL);

    CATMathPoint st = pUTStartPoint->Point();
    CATMathPoint end = pUTEndPoint->Point();

    CATMathVector vec1 = st - center;
    vec1.Normalize();
    CATMathVector vec2 = end - center;
    vec2.Normalize();

    CATAngle stAngle = x_dir.AngleTo(vec1, normal_dir);
    CATAngle endAngle = x_dir.AngleTo(vec2, normal_dir);;

    CATCircle* pCircle = iGeoFactory->CreateCircle(radius, pln, stAngle, endAngle);
    
    return (pCircle);
}

CATCurve* ECSketchEllipseGeom::getCATCurve(const CATGeoFactory_var &iGeoFactory)
{    
    SWXUtEllipse* pUTEllipse = getGeometry();
    SWX_VERIFY_RETURN(iGeoFactory != NULL && pUTEllipse != NULL, "null pointer found", NULL);
	
    double majorRadius = pUTEllipse->GetMajorRadius();
	double minorRadius = pUTEllipse->GetMinorRadius();
    
    CATMathPlane pln(pUTEllipse->Center(), pUTEllipse->XDir(), pUTEllipse->YDir());

    CATEllipse* pEllipse = iGeoFactory->CreateEllipse(majorRadius, minorRadius, pln);
    
    return (pEllipse);
}



