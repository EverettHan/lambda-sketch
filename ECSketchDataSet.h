#ifndef ECSketchDataSet_H
#define ECSketchDataSet_H
#include <stdint.h>


#include "ECSketchEntity.h"
#include "ECSketchConstraint.h"

#include <vector>
#include <memory>

class SWXSvSolver;

enum ECSketchSolveStatus
{
	EC_UNKNOWN			= 0,
	EC_UNDERDEFINED		= 1,
	EC_WELLDEFINED		= 2,
	EC_OVERDEFINED		= 3,
	EC_DANGLING			= 4,
};

class ECSketchDataSet
{
public:
    ECSketchDataSet();
	~ECSketchDataSet();

	std::string getSketchName() { return m_sketchName; }
	void setSketchName(std::string& nameIn) { m_sketchName = nameIn;}
	void setSketchSolveStatus(std::string& statusStringIn);
	std::string getSketchSolveStatusString();
	void setSketchXform(double coeffs[12]) { m_S2W_xform.SetCoefficients(coeffs);}
	
	bool addPoint(std::shared_ptr<ECSketchPoint>& spPointIn);
	bool addCurve(std::shared_ptr<ECSketchCurve>& spCurveIn);
	bool addConstraint(std::shared_ptr<ECSketchConstraint>& spConstraintIn);

	bool solve();
	CATBody* extractCountours();

	std::shared_ptr<ECSketchPoint> findSketchPoint(std::string skPointNameIn);
	std::shared_ptr<ECSketchPoint> findSketchPoint(std::string skPointNameIn);

protected:
private:	
	void initSolver();
	bool updateGeomToSolveResult();
	bool updateSolveStatus();

	bool addSolverPointGeom(std::shared_ptr<ECSketchPoint>& spPointIn);
	virtual bool addSolverCurveGeom(std::shared_ptr<ECSketchCurve>& spCurveIn) {assert(0); return false;};
	virtual bool addSolverCurveGeom(std::shared_ptr<ECSketchLine>& spLineIn);
	virtual bool addSolverCurveGeom(std::shared_ptr<ECSketchLineSegment>& spLineSegIn);
	virtual bool addSolverCurveGeom(std::shared_ptr<ECSketchCircle>& spCircleIn);
	virtual bool addSolverCurveGeom(std::shared_ptr<ECSketchArc>& spArcIn);
	virtual bool addSolverCurveGeom(std::shared_ptr<ECSketchEllipse>& spEllipseIn);

	//virtual bool updateCurveToSolveResult();
	virtual bool updateCurveToSolveResult(std::shared_ptr<ECSketchCurve>& spCurveIn) {assert(0); return false;};
	virtual bool updateCurveToSolveResult(std::shared_ptr<ECSketchLine>& spLineIn);
	virtual bool updateCurveToSolveResult(std::shared_ptr<ECSketchLineSegment>& spLineSegIn);
	virtual bool updateCurveToSolveResult(std::shared_ptr<ECSketchCircle>& spCircleIn);
	virtual bool updateCurveToSolveResult(std::shared_ptr<ECSketchArc>& spArcIn);
	virtual bool updateCurveToSolveResult(std::shared_ptr<ECSketchEllipse>& spEllipseIn);

	bool addSolverConstraint(std::shared_ptr<ECSketchConstraint>& spConstraintIn);
	CATBody* CreateSheetNew(CATGeoFactory_var const &ispFactory, CATSoftwareConfiguration* ipConfig, CATTopData* ipTopData, CATBody *ipWire, CATPlane* ipPlane);


private:
    std::vector< std::shared_ptr<ECSketchPoint> > m_vecPoints;
	std::vector< std::shared_ptr<ECSketchCurve> > m_vecCurves;
	std::vector< std::shared_ptr<ECSketchConstraint> > m_vecConstraints;
	CATBody_var m_spCountourSheet;
	CATMathTransformation m_S2W_xform;
    SWXSvSolver* m_pSolver;
	ECSketchSolveStatus m_SolveStatus;
	SWXUtUniqueId m_sketchID;
	std::string m_sketchName;
};

#endif //ECSketchDataSet_H