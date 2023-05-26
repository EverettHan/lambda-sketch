#ifndef CATPolyPolylineCleaningOperator_h__
#define CATPolyPolylineCleaningOperator_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2020
//===================================================================
// CATPolyPolylineCleaningOperator.h
//===================================================================
//
// Usage notes: Clean a polyline so that any point lie on a mesh edge
//===================================================================
// HISTORIQUE :
// 10/01/2020 : NUA : Creation
//===================================================================

#include "ExportedByCATPolyWatershedOperators.h"
#include "CATErrorDef.h"

#include "CATMathPoint2D.h"

class CATIPolyMesh;
class CATMathSetOfPoints;
class CATTolerance;

#include <memory>
#include <map>
#include <vector>

//////////
// - call "init" method
// - call "run" method to retrieve the mesh corresponding to the terrain part which flow to the given vertex 
//////////
class ExportedByCATPolyWatershedOperators CATPolyPolylineCleaningOperator
{
public:

	static CATPolyPolylineCleaningOperator * CreateInstance(CATIPolyMesh & iMesh, const CATMathSetOfPoints & iPolyline, const CATTolerance & iTol);

	virtual ~CATPolyPolylineCleaningOperator() {}

	// DEBUG
	virtual void EnableChecks() = 0;

	virtual HRESULT Run(CATMathSetOfPoints & iPolyline) = 0;
};

#endif // CATPolyPolylineCleaningOperator_h__
