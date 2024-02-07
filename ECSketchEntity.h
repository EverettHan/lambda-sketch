#ifndef ECSkEntity_H
#define ECSkEntity_H

#include <CATGeoFactory.h>
#include <CATCurve.h>
#include <CATMathDirection.h>

#include <SWXUtUniqueId.h>
#include <SWXUtPoint.h>
#include <SWXUtLine.h>
#include <SWXUtCircle.h>
#include <SWXUtArc.h>
#include <SWXUtEllipse.h>
#include <SWXUtCSys.h>
#include <SWXSvSolver.h>


#include <algorithm>
#include <vector>
#include <memory>

using namespace std;


class ECSketchEntity
{
public:
	ECSketchEntity() {};

    std::string getName() {return m_entityName;}
    void setName(std::string nameIn) { m_entityName = nameIn;}
    uint64_t getId() {return m_entityID;}
	SWXUtUniqueId& getSolverEntityID() {return m_solverEntityID;};
	void setSolverEntityID(const SWXUtUniqueId& svEntID) { m_solverEntityID = svEntID; }

protected:

private:
	std::string 		m_entityName;
	uint64_t 			m_entityID;
	SWXUtUniqueId 		m_solverEntityID;
};

class ECSketchGeometry : public ECSketchEntity
{
public:
	ECSketchGeometry() 
	: 	ECSketchEntity(),
		m_geometrySolveStatus(svInvalidGeomStatus) {}

	void setGeometrySolveStatus(svGeometryStatus& newStatus) { m_geometrySolveStatus = newStatus; }
	svGeometryStatus getGeometrySolveStatus() const { return m_geometrySolveStatus;}

protected:

private:
	svGeometryStatus 	m_geometrySolveStatus;
};

class ECSketchPoint : public ECSketchGeometry
{
public:
	ECSketchPoint(double x, double y, double z) 
	: 	ECSketchGeometry(),
		mGeom(CATMathPoint(x, y, z)) 
	{}
	
	double getX() const {return mGeom.Point().GetX();}
	double getY() const {return mGeom.Point().GetY();}
	double getZ() const {return mGeom.Point().GetZ();}

	SWXUtPoint* getGeometry() {return &mGeom;}

protected:

private:
	SWXUtPoint mGeom;
};

class ECSketchCurve : public ECSketchGeometry
{
public:
	ECSketchCurve()
	: 	ECSketchGeometry()
	{}

	CATBody* makeCurveBody(const CATGeoFactory_var &iGeoFactory, CATTopData *iTopData);
	
	virtual CATCurve* getCATCurve(const CATGeoFactory_var &iGeoFactory) {return NULL;}
protected:

private:

};

class ECSketchLine : public ECSketchCurve
{
public:
	ECSketchLine(double x_start, double y_start, double z_start, double x_dir, double y_dir, double z_dir)
	: 	ECSketchCurve(),
		m_line(CATMathPoint(x_start, y_start, z_start), CATMathDirection(x_dir, y_dir, z_dir))
	{
	}
	SWXUtLine* getGeometry() {return &m_line;};
protected:

private:
	SWXUtLine m_line;
};

class ECSketchLineSegment : public ECSketchLine
{
public:
	ECSketchLineSegment(shared_ptr<ECSketchPoint>& spStartPt, shared_ptr<ECSketchPoint>& spEndPt)
	:	ECSketchLine(spStartPt->getX(), spStartPt->getY(), spStartPt->getZ(),
		spEndPt->getX() - spStartPt->getX(), spEndPt->getY() - spStartPt->getY(), spEndPt->getZ() - spStartPt->getZ()),
		m_spStart(spStartPt),
		m_spEnd(spEndPt)
	{
	}

	shared_ptr<ECSketchPoint> getStartPt() { return m_spStart;}
	shared_ptr<ECSketchPoint> getEndPt() { return m_spEnd;}

	virtual CATCurve* getCATCurve(const CATGeoFactory_var &iGeoFactory);
protected:

private:
	shared_ptr<ECSketchPoint> m_spStart;
	shared_ptr<ECSketchPoint> m_spEnd;
};

class ECSketchCircleGeom : public ECSketchCurve
{
public:
	ECSketchCircleGeom(double x_center, double y_center, double z_center, double x_normal, double y_normal, double z_normal, double radius)
	: 	ECSketchCurve(),
		m_circle(CATMathPoint(x_center, y_center, z_center), CATMathDirection(x_normal, y_normal, z_normal), radius)
	{
	}

	SWXUtCircle* getGeometry() {return &m_circle;};
	virtual CATCurve* getCATCurve(const CATGeoFactory_var &iGeoFactory);
	double getRadius() 
	{ 
		SWXUtCircle* pCircle = getGeometry(); 
		if (pCircle) 
			return pCircle->Radius(); 
		else 
			return 0.0;
	}
protected:

private:	
	SWXUtCircle m_circle;
};

class ECSketchCircle : public ECSketchCircleGeom
{
public:
	ECSketchCircle(shared_ptr<ECSketchPoint>& spCenter, CATMathDirection& dirIn, double radius)
	: 	ECSketchCircleGeom(spCenter->getX(), spCenter->getY(), spCenter->getZ(), dirIn.GetX(), dirIn.GetY(), dirIn.GetZ(), radius),
		m_spCenter(spCenter)
	{
	}

	shared_ptr<ECSketchPoint> getCenterPt() { return m_spCenter;}

protected:

private:	
	shared_ptr<ECSketchPoint> m_spCenter;
};

class ECSketchArc : public ECSketchCircleGeom
{
public:
	ECSketchArc(shared_ptr<ECSketchPoint>& spCenter, shared_ptr<ECSketchPoint>& spStart, 
				shared_ptr<ECSketchPoint>& spEnd, CATMathDirection& dirIn, double radius)
	:	ECSketchCircle(spCenter->getX(), spCenter->getY(), spCenter->getZ(), dirIn.GetX(), dirIn.GetY(), dirIn.GetZ(), radius),
		m_spStart(spStart),
		m_spEnd(spEnd),
		m_spCenter(spCenter)
	{
	}

	shared_ptr<ECSketchPoint> getStartPt() { return m_spStart;}
	shared_ptr<ECSketchPoint> getEndPt() { return m_spEnd;}
	shared_ptr<ECSketchPoint> getCenterPt() { return m_spCenter;}
	virtual CATCurve* getCATCurve(const CATGeoFactory_var &iGeoFactory);
protected:

private:
	shared_ptr<ECSketchPoint> m_spStart;
	shared_ptr<ECSketchPoint> m_spEnd;
	shared_ptr<ECSketchPoint> m_spCenter;
};

class ECSketchEllipseGeom : public ECSketchCurve
{
public:
	ECSketchEllipseGeom(double x_center, double y_center, double z_center, 
					double x_xaxis, double y_xaxis, double z_xaxis, 
					double x_yaxis, double y_yaxis, double z_yaxis, 
					double major_radius, double minor_radius)
	:	ECSketchCurve(),
		m_ellipse(CATMathPoint(x_center, y_center, z_center), 
					 CATMathDirection(x_xaxis, y_xaxis, z_xaxis),
					 CATMathDirection(x_yaxis, y_yaxis, z_yaxis), 
					 major_radius, minor_radius)
	{
	}

	
	
	SWXUtEllipse* getGeometry() {return &m_ellipse;};
	virtual CATCurve* getCATCurve(const CATGeoFactory_var &iGeoFactory);

protected:

private:
	SWXUtEllipse m_ellipse;

};


class ECSketchEllipse : public ECSketchEllipseGeom
{
public:
	ECSketchEllipse(shared_ptr<ECSketchPoint>& spCenter, CATMathDirection& x_dirIn, CATMathDirection& y_dirIn, double majorRadiusIn, double minorRadius)
	: 	ECSketchEllipseGeom(spCenter->getX(), spCenter->getY(), spCenter->getZ(), 
							x_dirIn.GetX(), x_dirIn.GetY(), x_dirIn.GetZ(),  
							y_dirIn.GetX(), y_dirIn.GetY(), y_dirIn.GetZ(), 
							majorRadiusIn, minorRadius),
		m_spCenter(spCenter)
	{
	}

	shared_ptr<ECSketchPoint> getCenterPt() { return m_spCenter;}

protected:

private:	
	shared_ptr<ECSketchPoint> m_spCenter;
};


#endif //ECSkEntity_H