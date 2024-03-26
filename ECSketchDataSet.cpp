#include "ECSketchDataSet.h"


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
#include <CATPlane.h>
#include <CATCrvLimits.h>

#include <SWXUtAssert.h>
#include <SWXFOREACH.h>
#include <SWXSvSolver.h>
#include <SWXUtPoint.h>

#include <ECSketchEntity.h>
#include <ECWireUtilities.h>
#include <ECBodyUtilities.h>
#include <ECFaceUtilities.h>
#include <ECCurveUtilities.h>

#define TRACE_ERR(...)                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }


ECSketchDataSet::ECSketchDataSet()
: m_pSolver(NULL)
{
	m_pSolverOpts = new ECSkSolverOptions();	
}
ECSketchDataSet::~ECSketchDataSet()
{
	m_vecPoints.clear();
	m_vecCurves.clear();
	m_vecConstraints.clear();

    if(m_pSolver)
		delete m_pSolver;
    if(m_pSolverOpts)
		delete m_pSolverOpts;
}


bool ECSketchDataSet::addSolverPointGeom(std::shared_ptr<ECSketchPoint> spPointIn)
{
	assert(spPointIn != nullptr);
	assert(m_pSolver != NULL);
	assert(m_sketchID.IsValid());

	SWXUtPoint* pGeom = spPointIn->getGeometry();
	SWXUtUniqueId geomID = spPointIn->getSolverEntityID();

	if (geomID.IsValid())
	{
		m_pSolver->SyncGeometryOnSolver(geomID, *pGeom);
	}
	else
	{
		geomID = m_pSolver->AddGeometry(*pGeom, m_sketchID);
		spPointIn->setSolverEntityID(geomID);
	}
	return true;
}

bool ECSketchDataSet::addSolverCurveGeom(std::shared_ptr<ECSketchLine> spLineIn)
{
	assert(spLineIn != nullptr);
	assert(m_pSolver != NULL);
	assert(m_sketchID.IsValid());

	SWXUtLine* pGeom = spLineIn->getGeometry();
	SWXUtUniqueId geomID = spLineIn->getSolverEntityID();

	if (geomID.IsValid())
	{
		m_pSolver->SyncGeometryOnSolver(geomID, *pGeom);
	}
	else
	{
		geomID = m_pSolver->AddGeometry(*pGeom, m_sketchID);
		spLineIn->setSolverEntityID(geomID);
	}
	return true;
}

bool ECSketchDataSet::addSolverCurveGeom(std::shared_ptr<ECSketchCircle> spCircleIn)
{
	assert(spCircleIn != nullptr);
	assert(m_pSolver != NULL);
	assert(m_sketchID.IsValid());

	SWXUtCircle* pGeom = spCircleIn->getGeometry();
	SWXUtUniqueId geomID = spCircleIn->getSolverEntityID();

	if (geomID.IsValid())
	{
		m_pSolver->SyncGeometryOnSolver(geomID, *pGeom);
	}
	else
	{
		geomID = m_pSolver->AddGeometry(*pGeom, m_sketchID);
		spCircleIn->setSolverEntityID(geomID);
	}
	return true;

}

bool ECSketchDataSet::addSolverCurveGeom(std::shared_ptr<ECSketchEllipse> spEllipseIn)
{
	assert(spEllipseIn != nullptr);
	assert(m_pSolver != NULL);
	assert(m_sketchID.IsValid());

	SWXUtEllipse* pGeom = spEllipseIn->getGeometry();
	SWXUtUniqueId geomID = spEllipseIn->getSolverEntityID();

	if (geomID.IsValid())
	{
		m_pSolver->SyncGeometryOnSolver(geomID, *pGeom);
	}
	else
	{
		geomID = m_pSolver->AddGeometry(*pGeom, m_sketchID);
		spEllipseIn->setSolverEntityID(geomID);
	}
	return true;

}

bool ECSketchDataSet::addSolverCurveGeom(std::shared_ptr<ECSketchLineSegment> spLineSegIn)
{	
	SWX_VERIFY_RETURN(spLineSegIn != nullptr, "null line seg", false);
	SWX_VERIFY_RETURN(m_pSolver != NULL, "null solover", false);
	SWX_VERIFY_RETURN(m_sketchID.IsValid(), "null sketch id", false);
	SWX_VERIFY_RETURN(spLineSegIn->getSolverEntityID().IsValid() == false, "sketch line seg should not have id", false);// must not have been added to solver
	
	shared_ptr<ECSketchPoint> spStartPt = spLineSegIn->getStartPt();
	SWX_VERIFY_RETURN(spStartPt != nullptr, "null start point", false); 

	shared_ptr<ECSketchPoint> spEndPt = spLineSegIn->getEndPt();
	SWX_VERIFY_RETURN(spEndPt != nullptr, "null end point", false); 

	SWXUtUniqueId startId = spStartPt->getSolverEntityID();
	SWX_VERIFY_RETURN(startId.IsValid(), "invalid start point id", false); 

	SWXUtUniqueId endId = spEndPt->getSolverEntityID();
	SWX_VERIFY_RETURN(endId.IsValid(), "invalid end point id", false); 

	SWXUtUniqueId geomId = m_pSolver->AddGeometry(m_sketchID, startId, endId );
	SWX_VERIFY_RETURN(geomId.IsValid(), "invalid geom id", false); 

	spLineSegIn->setSolverEntityID(geomId);


	m_pSolver->AddConstraint(svCoincident, geomId, startId, SWXUtUniqueId());
	m_pSolver->AddConstraint(svCoincident, geomId, endId, SWXUtUniqueId());

	return true;
}

bool ECSketchDataSet::addSolverCurveGeom(std::shared_ptr<ECSketchArc> spArcIn)
{
	SWX_VERIFY_RETURN(spArcIn != nullptr, "null arc", false);
	SWX_VERIFY_RETURN(m_pSolver != NULL, "null solver", false);
	SWX_VERIFY_RETURN(m_sketchID.IsValid(), "null sketch id", false);
	SWX_VERIFY_RETURN(spArcIn->getSolverEntityID().IsValid() == false, "arc should not have id set", false);// must not have been added to solver
	
	shared_ptr<ECSketchPoint> spStartPt = spArcIn->getStartPt();
	SWX_VERIFY_RETURN(spStartPt != nullptr, "null start point", false); 

	shared_ptr<ECSketchPoint> spEndPt = spArcIn->getEndPt();
	SWX_VERIFY_RETURN(spEndPt != nullptr, "null end point", false); 

	shared_ptr<ECSketchPoint> spCenterPt = spArcIn->getCenterPt();
	SWX_VERIFY_RETURN(spCenterPt != nullptr, "null center point", false); 
	
	double radius = spArcIn->getRadius();

	SWXUtUniqueId startId = spStartPt->getSolverEntityID();
	SWX_VERIFY_RETURN(startId.IsValid(), "invalid start point id", false); 

	SWXUtUniqueId endId = spEndPt->getSolverEntityID();
	SWX_VERIFY_RETURN(endId.IsValid(), "invalid end point id", false); 

	SWXUtUniqueId centerId = spCenterPt->getSolverEntityID();
	SWX_VERIFY_RETURN(centerId.IsValid(), "invalid center point id", false); 


	SWXUtUniqueId geomId = m_pSolver->AddGeometry(m_sketchID, startId, endId, centerId, radius);
	SWX_VERIFY_RETURN(geomId.IsValid(), "invalid geom id", false); 
	
	spArcIn->setSolverEntityID(geomId);

	m_pSolver->AddConstraint(svConcentric, geomId, centerId, SWXUtUniqueId());
	m_pSolver->AddConstraint(svCoincident, geomId, startId, SWXUtUniqueId());
	m_pSolver->AddConstraint(svCoincident, geomId, endId, SWXUtUniqueId());

	return true;
}

bool ECSketchDataSet::addSolverConstraint(std::shared_ptr<ECSketchConstraint> spConstraintIn)
{
	SWX_VERIFY_RETURN(spConstraintIn != nullptr, "null constraint", false);
	SWX_VERIFY_RETURN(m_pSolver != NULL, "null solver", false);
	SWX_VERIFY_RETURN(m_sketchID.IsValid(), "invalid sketch id", false);
	SWX_VERIFY_RETURN(spConstraintIn->getSolverEntityID().IsValid() == false, "constraint id should not be set", false);// must not have been added to solver

	svConstraintType cType = spConstraintIn->getConstraintType();

	double cValue = 0.0;
	spConstraintIn->getConstraintValue(cValue);

	svConstraintChirality cChirality = spConstraintIn->getConstraintChirality();

	SWXUtUniqueId gId1, gId2, gId3, gId4;
	spConstraintIn->getEntitieIDs(gId1, gId2, gId3, gId4);

	SWXSvConstraintData* pData = NULL;


	SWXUtUniqueId constraintId = m_pSolver->AddConstraint(cType, gId1, gId2, gId3, gId4, cValue, cChirality, pData);
	SWX_VERIFY_RETURN(constraintId.IsValid(), "invalid constraint id", false); 
	
	spConstraintIn->setSolverEntityID(constraintId);

	return true;
}

void ECSketchDataSet::initSolver()
{
	SWX_VERIFY_EXIT(m_pSolverOpts != NULL, "null solver options");

	SWX_VERIFY_EXIT(m_pSolver == NULL, "null solver");
	m_pSolver = new SWXSvSolver(m_pSolverOpts->getLinearTolerance(), m_pSolverOpts->getAngularTolerance());	
	

	SWXUtCSys sys(CATMathPoint(), CATMathI, CATMathJ);
	m_sketchID = m_pSolver->AddSketch(sys);

	// add sketch points to the solver
	for (auto & spPoint : m_vecPoints) 
	{		
		addSolverPointGeom(spPoint);
	}

	// add sketch curves to the solver
	for (auto & spCurve : m_vecCurves) 
	{		
		//note: coincident constraint(s) is (are) also added for the curve end(s) if it (they) are not used in curve definition
		addSolverCurveGeom(spCurve); 
	}

	// add sketch constraints to the solver
	for (auto & aConstraint : m_vecConstraints) 
	{		
		addSolverConstraint(aConstraint);
	}	
}

bool ECSketchDataSet::updateGeomToSolveResult()
{
	SWX_VERIFY_RETURN(m_pSolver != NULL, "null solover", false);
	SWX_VERIFY_RETURN(m_sketchID.IsValid(), "invalid sketch unique id", false);

	// update sketch points to the solve result
	for (auto & spPoint : m_vecPoints) 
	{
		SWXUtUniqueId gId = spPoint->getSolverEntityID();
		SWX_VERIFY_CONTINUE(gId.IsValid(), "invalid point unique id");

    	if (!m_pSolver->IsGeomTransformed(gId))  { continue;}

		//SWXUtPoint utPoint(CATMathPoint());
		SWXUtPoint* pTemp = new SWXUtPoint(CATMathPoint());
		bool ret = m_pSolver->UpdateGeometry(*const_cast<SWXUtPoint *>(pTemp), gId);
		if (ret)
		{
			CATMathPoint mPt = pTemp->Point();
			SWXUtPoint* pUtPoint = spPoint->getGeometry();
			if (pUtPoint) pUtPoint->SetPoint(mPt);
		}
		else
		{
			SWX_VERIFY_CONTINUE(false, "UpdateGeometry failed");
		}
		delete pTemp;
	}

	// update sketch curves to the solve result
	for (auto & spCurve : m_vecCurves) 
	{
		updateCurveToSolveResult(spCurve);	
	}

	return true;
}

bool ECSketchDataSet::updateCurveToSolveResult(std::shared_ptr<ECSketchLine> spLineIn)
{
	SWXUtUniqueId gId = spLineIn->getSolverEntityID();
	SWX_VERIFY_RETURN(gId.IsValid(), "Invalid unique id (ECSketchLine) in updateCurveToSolveResult", false);

	if (!m_pSolver->IsGeomTransformed(gId))
		return true;

	SWXUtLine* pTemp = new SWXUtLine(CATMathPoint(), CATMathDirection());
	bool ret = m_pSolver->UpdateGeometry(*const_cast<SWXUtLine *>(pTemp), gId);
	if (ret)
	{
		SWXUtLine* pLine = spLineIn->getGeometry();
		*pLine = *pTemp;
	}
	delete pTemp;
	return ret;
}

bool ECSketchDataSet::updateCurveToSolveResult(std::shared_ptr<ECSketchLineSegment> spLineSegIn)
{
	SWXUtUniqueId gId = spLineSegIn->getSolverEntityID();
	SWX_VERIFY_RETURN(gId.IsValid(), "Invalid unique id (ECSketchLineSegment) in updateCurveToSolveResult", false);

	if (!m_pSolver->IsGeomTransformed(gId))
		return true;

	SWXUtLine* pTemp = new SWXUtLine(CATMathPoint(), CATMathDirection());
	bool ret = m_pSolver->UpdateGeometry(*const_cast<SWXUtLine *>(pTemp), gId);
	if (ret)
	{
		SWXUtLine* pLine = spLineSegIn->getGeometry();
		*pLine = *pTemp;
	}
	
	delete pTemp;
	return ret;

}

bool ECSketchDataSet::updateCurveToSolveResult(std::shared_ptr<ECSketchCircle> spCircleIn)
{
	SWXUtUniqueId& gId = spCircleIn->getSolverEntityID();
	SWX_VERIFY_RETURN(gId.IsValid(), "Invalid unique id (ECSketchCircle) in updateCurveToSolveResult", false);

	if (!m_pSolver->IsGeomTransformed(gId))
		return true;

	SWXUtCircle utCircle;
	bool ret = m_pSolver->UpdateGeometry(utCircle, gId);
	if (ret)
	{
		SWXUtCircle* pCircle = spCircleIn->getGeometry();
		*pCircle = utCircle;
	}
	
	return ret;

}

bool ECSketchDataSet::updateCurveToSolveResult(std::shared_ptr<ECSketchArc> spArcIn)
{
	SWXUtUniqueId& gId = spArcIn->getSolverEntityID();
	SWX_VERIFY_RETURN(gId.IsValid(), "Invalid unique id (ECSketchArc) in updateCurveToSolveResult", false);

	if (!m_pSolver->IsGeomTransformed(gId))
		return true;

	SWXUtCircle utCircle;
	bool ret = m_pSolver->UpdateGeometry(utCircle, gId);
	if (ret)
	{
		SWXUtCircle* pCircle = spArcIn->getGeometry();
		*pCircle = utCircle;
	}
	
	return ret;

}

bool ECSketchDataSet::updateCurveToSolveResult(std::shared_ptr<ECSketchEllipse> spEllipseIn)
{
	SWXUtUniqueId& gId = spEllipseIn->getSolverEntityID();
	SWX_VERIFY_RETURN(gId.IsValid(), "Invalid unique id (ECSketchEllipse) in updateCurveToSolveResult", false);

	if (!m_pSolver->IsGeomTransformed(gId))
		return true;

	SWXUtEllipse utEllipse;
	bool ret = m_pSolver->UpdateGeometry(utEllipse, gId);
	if (ret)
	{
		SWXUtEllipse* pEllipse = spEllipseIn->getGeometry();
		*pEllipse = utEllipse;
	}
	
	return ret;

}

bool ECSketchDataSet::updateSolveStatus()
{
	SWX_VERIFY_RETURN(m_pSolver != NULL, "null solover", false);
	SWX_VERIFY_RETURN(m_sketchID.IsValid(), "invalid sketch unique id", false);

	ECSketchSolveStatus globalSKStatus = ECSketchSolveStatus::EC_UNKNOWN;

	//update geometry solve status
	for (auto & spPoint : m_vecPoints) 
	{
		SWXUtUniqueId& gId = spPoint->getSolverEntityID();
		SWX_VERIFY_CONTINUE(gId.IsValid(), "invalid point unique id");

    	svGeometryStatus newStatus = m_pSolver->GetGeomStatus(gId);	
		svGeometryStatus oldStatus = spPoint->getGeometrySolveStatus();

		if (oldStatus != newStatus)
		{
			spPoint->setGeometrySolveStatus(newStatus);
		}

		// dangling overrides overdefined overrides underdefined which overrides well defined
		if (globalSKStatus != ECSketchSolveStatus::EC_DANGLING)
		{
			if (globalSKStatus != ECSketchSolveStatus::EC_OVERDEFINED)
			{
				if (newStatus == svGeomOverdefined)
					globalSKStatus  = ECSketchSolveStatus::EC_OVERDEFINED;
				else
				{
					if (newStatus == svGeomUnderdefined)
						globalSKStatus  = ECSketchSolveStatus::EC_UNDERDEFINED;
					else if (globalSKStatus  != ECSketchSolveStatus::EC_UNDERDEFINED && (newStatus == svGeomWellDefined || newStatus == svFixed))
						globalSKStatus  = ECSketchSolveStatus::EC_WELLDEFINED;
				}
			}
		}

	}

	for (auto & spCurve : m_vecCurves) 
	{
		SWXUtUniqueId& gId = spCurve->getSolverEntityID();
		SWX_VERIFY_CONTINUE(gId.IsValid(), "invalid curve unique id");

    	svGeometryStatus newStatus = m_pSolver->GetGeomStatus(gId);	
		svGeometryStatus oldStatus = spCurve->getGeometrySolveStatus();

		if (oldStatus != newStatus)
		{
			spCurve->setGeometrySolveStatus(newStatus);
		}

		// dangling overrides overdefined overrides underdefined which overrides well defined
		if (globalSKStatus != ECSketchSolveStatus::EC_DANGLING)
		{
			if (globalSKStatus != ECSketchSolveStatus::EC_OVERDEFINED)
			{
				if (newStatus == svGeomOverdefined)
					globalSKStatus  = ECSketchSolveStatus::EC_OVERDEFINED;
				else
				{
					if (newStatus == svGeomUnderdefined)
						globalSKStatus  = ECSketchSolveStatus::EC_UNDERDEFINED;
					else if (globalSKStatus  != ECSketchSolveStatus::EC_UNDERDEFINED && (newStatus == svGeomWellDefined || newStatus == svFixed))
						globalSKStatus  = ECSketchSolveStatus::EC_WELLDEFINED;
				}
			}
		}

	}

	//update constraint solve status	
	for (auto & spConstraint : m_vecConstraints) 
	{		
		SWXUtUniqueId& gId = spConstraint->getSolverEntityID();
		SWX_VERIFY_CONTINUE(gId.IsValid(), "invalid constraint unique id");

		svConstraintStatus newStatus = m_pSolver->GetConstraintStatus(gId);	
		svConstraintStatus oldStatus = spConstraint->getConstraintSolveStatus();

		if (newStatus == svBetweenFixed)
			newStatus = svConstraintOverdefined;

		if (oldStatus != newStatus)
		{
			spConstraint->setConstraintSolveStatus(newStatus);
		}
	}	

	return true;
}


bool ECSketchDataSet::solve()
{
	initSolver();	
	m_pSolver->Solve();
	updateGeomToSolveResult();
	updateSolveStatus();	

	return true;
}


CATBody* ECSketchDataSet::extractCountours()
{
	TRACE_ERR("\t To call CATCreateCGMContainer \n")
    CATGeoFactory *pFactory = CATCreateCGMContainer();
    if (pFactory != NULL)
        TRACE_ERR("\t Successfully getting pFactory = %p \n", (void *)pFactory)
    else
        TRACE_ERR("\t Failed getting pFactory \n")


    TRACE_ERR("\t To call CATCreateSoftwareConfiguration \n")
    CATSoftwareConfiguration *pConfig = CATCreateSoftwareConfiguration();
    if (pConfig != NULL)
        TRACE_ERR("\t Successfully getting pConfig = %p \n", (void *)pConfig)
    else
        TRACE_ERR("\t Failed getting pConfig \n")
    
    

	CATCGMJournalList journal;
	CATTopData curveTopdata(pConfig, &journal);

	CATLISTP(CATBody) tempCurveWires;
	for (auto & spCurve : m_vecCurves) 
	{
		if (!spCurve)
			continue;

		CATBody* pCurveBody = spCurve->makeCurveBody(pFactory, &curveTopdata);
		if (pCurveBody)
			tempCurveWires.Append(pCurveBody);
	}

	CATBody* pCountourWireBody = NULL; 
	CATTopData countourTopData(pConfig);
	CATCGMJournalList* pNewJournal = new CATCGMJournalList();
	if(pNewJournal)
	{
		countourTopData.SetJournal(pNewJournal);
		pCountourWireBody = ECWireUtilities::MakeWire(pFactory, &countourTopData, tempCurveWires);
		//if(populateJournal && !!spResult)
		//	EntityTracker.Update(pNewJournal);
		delete pNewJournal; 
		pNewJournal = NULL;
	}

	if (ECWireUtilities::CheckSelfIntersection(pConfig, pCountourWireBody))
		return NULL;


	CATTopData sheetTopData(pConfig);
	CATCGMJournalList* pSheetJournal = new CATCGMJournalList();
	sheetTopData.SetJournal(pSheetJournal);

	CATMathPlane localPln = CATMathOIJ;
	CATPlane* pCommonPlane = pFactory->CreatePlane(localPln);

	CATBody *sheet = CreateSheetNew(pFactory, pConfig, &sheetTopData, pCountourWireBody, pCommonPlane);


	for ( int ii = 1 ; ii <= tempCurveWires.Size() ; ii++ ) 
	{
		CATBody_var spBody = tempCurveWires[ii];
		if(!!spBody)
			pFactory->Remove(spBody) ;
	}
	tempCurveWires.RemoveAll();
	pFactory->Remove(pCountourWireBody) ;
	
    CATCloseCGMContainer(pFactory);
    pFactory = NULL;

	delete pSheetJournal;
	pSheetJournal = NULL;

	return sheet;
}


static CATBody* s_MakeDummyWire(CATGeoFactory * ipFactory, CATTopData* ipTopData, CATBody* ipWire, CATMathPlane const&iPln)
{
	CATBody* pRet = NULL;
	if(ipWire == NULL || ipFactory == NULL) return pRet;

	CATMathBox box = ipWire->GetBoundingBox();
	CATMathPoint low, high, lowProj, highProj;
	box.Inflate(10); // small amount of inflation

	box.GetLowLimit(low);
	box.GetHighLimit(high);

	iPln.Project(high, lowProj);
	CATMathPoint high2 = high + (high - low);
	iPln.Project(high2, highProj);

	CATLine* pCurve = ipFactory->CreateLine(lowProj, highProj);
	if(pCurve)
	{
		CATCrvLimits limits;
		pCurve->GetLimits(limits);
		pRet = ECCurveUtilities::MakeWireBody(ipTopData, pCurve, limits);
	}

	return pRet;
}


static bool s_FaceContainsEdges(CATFace *iFace, CATLISTP(CATCell) const &iEdges)
{
	if (NULL == iFace) return false;

	CATLISTP(CATCell) edges;
	iFace->GetAllCells(edges, 1);
	if (edges.Locate(iEdges[1]) != 0)
		return true;

	return false;
}

CATBody* ECSketchDataSet::CreateSheetNew(CATGeoFactory_var const &ispFactory, CATSoftwareConfiguration* ipConfig, CATTopData* ipTopData, CATBody *ipWire, CATPlane* ipPlane)
{
	bool iPopulateJournal = true;
	bool iAddDummyEdge = true;

	CATBody* pResultBody = NULL;
	CATLISTP(CATBody)	garbage;

	if(!ispFactory || ipConfig == NULL || ipTopData == NULL || ipWire == NULL || ipPlane == NULL) 
		return NULL;

	CATPlane *srf = ipPlane;

	CATBody* pInfBody = ECBodyUtilities::MakeBodyFromSurface(ipTopData, srf, NULL, true);
	if(!pInfBody) return NULL;

	CATLISTP(CATCell) baseEdges;
	pInfBody->GetAllCells(baseEdges, 1);

	garbage.Append(pInfBody);

	CATTopData TopData(ipConfig);
	CATCGMJournalList* pNewJournal = new CATCGMJournalList();
	TopData.SetJournal(pNewJournal);

	// Imprint the wire body into the infinite lamina - get seperate faces in infinite lamina
	// Journal missing information - internal edges
	CATIPGMTopCompatible *pCmptOp = NULL;
	CATTry
	{
		if(iAddDummyEdge)
		{
			CATMathPlane pln = srf->GetAxis();
			CATBody* pDummy = s_MakeDummyWire(ispFactory, &TopData, ipWire, pln);

			if(pDummy)
			{
				garbage.Append(pDummy);
				CATLISTP(CATBody) BodyList;
				BodyList.Append(ipWire);
				BodyList.Append(pDummy);
				CATBody* pCombine = ECBodyUtilities::Combine(ipConfig, BodyList);

				if(pCombine)
				{
					garbage.Append(pCombine);
					pCmptOp = CATPGMCreateCompatibleForCGM(ispFactory, ipTopData, pInfBody, pCombine);
				}
			}
		}

		if(pCmptOp == NULL)
			pCmptOp = CATPGMCreateCompatibleForCGM(ispFactory, ipTopData, pInfBody, ipWire);

		if(pCmptOp)
		{
			if(iPopulateJournal)
				pCmptOp->EnableCellTracker();
			pCmptOp->Run();
		}
	}
	CATCatch(CATError, errobj)
	{
		CATUnicodeString err = errobj->GetNLSMessage();
		if(pCmptOp) { pCmptOp->Release(); pCmptOp=NULL;}
	}
	CATEndTry

	CATCGMCellTracker* ct = NULL;
	if ( NULL != pCmptOp )
	{
		int nbRes = pCmptOp->GetNumberOfResults();
		CATLISTP(CATBody) opResults;

		if(iPopulateJournal)
			ct = pCmptOp->CreateCellTracker();

		if(nbRes > 0)
		{
			pCmptOp->BeginningResult();
			while(pCmptOp->NextResult())
			{
				CATBody *res = pCmptOp->GetResult(pNewJournal);
				if (NULL == res)
					continue;
				garbage.Append(res);
				// Remove the infinite face
				CATLISTP(CATFace) FacesOut, KeepFaces;
				res->GetAllCells((CATLISTP(CATCell)&)FacesOut,2) ;
				for(int i = 1; i <= FacesOut.Size(); i++)
				{
					CATFace_var spFace = FacesOut[i];
					if(!!spFace)
					{
						if (s_FaceContainsEdges(spFace, baseEdges))
							continue;
						KeepFaces.Append(spFace);
					}
				}

				if(KeepFaces.Size() > 0)
				{
					pResultBody = ECFaceUtilities::MakeSheetFromFaces(res, KeepFaces, true);
					if(ct != NULL && pResultBody != NULL)
					{
						CATLISTP(CATCell) EdgeList;
						pResultBody->GetAllCells(EdgeList, 1);

						// Fill in the same map
						int i;
						for(i = 1; i <= EdgeList.Size(); i++)
						{
							CATCell* pEdge = EdgeList[i];
							CATLISTP(CATGeometry) Before, After;
							CATLISTP(CATCell) parents;
							if(pEdge && SUCCEEDED(ct->GetSource(pEdge, ipWire, res, parents)))
							{
								After.Append(pEdge);
								SWX_FOREACH(CATGeometry *, g, parents)
									Before.Append(g);
								SWX_FOREACH_END;

								pNewJournal->Report(CATCGMJournal::Modification, Before, After, NULL);
							}
						}

						// For face we dont specify origin - change if its needed
						CATLISTP(CATCell) FaceList;
						pResultBody->GetAllCells(FaceList, 2);

						for(i = 1; i <= FaceList.Size(); i++)
						{
							CATLISTP(CATGeometry) Source;
							pNewJournal->ReportCreation(Source, FaceList[i], NULL);
						}
					}
				}
			}
		}
	}

	if(ct)
	{
		delete ct;
		ct = NULL;
	}

	if (pCmptOp) pCmptOp->Release();
	delete pNewJournal; pNewJournal = NULL;

	for(int i=1; i<=garbage.Size(); i++)
	{
		ispFactory->Remove(garbage[i], CATICGMContainer::RemoveDependancies);
	}
	garbage.RemoveAll();

	return pResultBody;
}




void ECSketchDataSet::setSketchSolveStatus(std::string& statusStringIn) 
{ 
    if (statusStringIn == "EC_UNKNOWN")
        m_SolveStatus = EC_UNKNOWN;
    else if (statusStringIn == "EC_UNDERDEFINED")
        m_SolveStatus = EC_UNDERDEFINED;
    else if (statusStringIn == "EC_WELLDEFINED")
        m_SolveStatus = EC_WELLDEFINED;
    else if (statusStringIn == "EC_OVERDEFINED")
        m_SolveStatus = EC_OVERDEFINED;
    else if (statusStringIn == "EC_DANGLING")
        m_SolveStatus = EC_DANGLING;
    else
        SWX_VERIFY_EXIT(0, "Wrong status string in \n");
}

std::string ECSketchDataSet::getSketchSolveStatusString()
{
	if (m_SolveStatus == EC_UNKNOWN)
        return "EC_UNKNOWN";
	else if (m_SolveStatus == EC_UNDERDEFINED)
        return "EC_UNDERDEFINED";
	else if (m_SolveStatus == EC_WELLDEFINED)
        return "EC_WELLDEFINED";
	else if (m_SolveStatus == EC_OVERDEFINED)
        return "EC_OVERDEFINED";
	else if (m_SolveStatus == EC_DANGLING)
        return "EC_DANGLING";
	else
        return "EC_UNKNOWN";

}


bool ECSketchDataSet::addPoint(std::shared_ptr<ECSketchPoint> spPointIn)
{
	bool ret = true;

	m_vecPoints.push_back(spPointIn);

	return ret;
}

bool ECSketchDataSet::addCurve(std::shared_ptr<ECSketchCurve> spCurveIn)
{
	bool ret = true;

	m_vecCurves.push_back(spCurveIn);

	return ret;
}

bool ECSketchDataSet::addConstraint(std::shared_ptr<ECSketchConstraint> spConstraintIn)
{
	bool ret = true;

	m_vecConstraints.push_back(spConstraintIn);

	return ret;
}

std::shared_ptr<ECSketchPoint> ECSketchDataSet::findSketchPoint(std::string skPointNameIn)
{
	for (auto & spPoint : m_vecPoints) 
	{		
		std::string aName = spPoint->getName();
		if (aName == skPointNameIn)
			return spPoint;
	}

	return nullptr;
}

