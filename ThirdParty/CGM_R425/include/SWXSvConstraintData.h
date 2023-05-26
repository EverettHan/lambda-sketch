//===================================================================
// COPYRIGHT Dassault Systemes 2015/03/17
//===================================================================
// SWXSvConstraintData.cpp
// Header definition of class SWXSvConstraintData
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/03/17 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXSvConstraintData_H
#define SWXSvConstraintData_H

#include "SWXSvSolverAPI.h"
#include "SWXUtUniqueId.h"
#include "CATMathPoint.h"
#include "SWXSvEnums.h"

class SWXSvSolverContainers;

//-----------------------------------------------------------------------

class ExportedBySWXSvSolverAPI SWXSvConstraintData
{
public:
// Standard constructors and destructors
// -------------------------------------
SWXSvConstraintData ();
virtual ~SWXSvConstraintData ();

//
// TODO: Add your methods for this class here.
//
	svConstraintType GetConstraintType() { return mConstraintType;};
	void SetConstraintType( svConstraintType iConstraintType) { mConstraintType = iConstraintType;};

	void IsConnected(bool ibIsConnected) { mbIsConnected = ibIsConnected;} ;
	bool IsConnected() { return mbIsConnected; }

	static SWXSvConstraintData* CreateEqualCurvatureConstraintData(bool ibIsConnected, CATMathPoint const &iPoint, bool ibStart[2], CATMathVector const &iNormal, SWXUtUniqueId iSideIds[2]);
	static SWXSvConstraintData* CreateConstraintData(svConstraintType iConstraintType, bool ibIsConnected);

	virtual void MapGeomPointers(SWXSvSolverContainers* iMapContainer) {};
private:

	svConstraintType mConstraintType;
	bool mbIsConnected;


// Copy constructor and equal operator
// -----------------------------------
SWXSvConstraintData (SWXSvConstraintData &);
SWXSvConstraintData& operator=(SWXSvConstraintData&);

};

//-----------------------------------------------------------------------

#endif