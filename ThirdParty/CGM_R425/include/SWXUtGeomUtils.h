//===================================================================
// COPYRIGHT DS SolidWorks 2010/10/27
//===================================================================
// SWXUtGeomUtils.cpp
// Header definition of class SWXUtGeomUtils
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/10/27 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtGeomUtils_H
#define SWXUtGeomUtils_H

#include "SWXMathematics.h"

//-----------------------------------------------------------------------

class CATMathPlane; 
class CATMathAxis;
class CATMathVector;
class CATMathLine;
class CATMathPoint;
class CATMathDirection;
class CATMathTransformation;

class ExportedBySWXMathematics SWXUtGeomUtils
{
public:
    SWXUtGeomUtils ();
    virtual ~SWXUtGeomUtils ();

    static CATMathAxis PlaneToSys(CATMathPlane const &iPln, int iNormalIdx = 2);
    static CATMathPlane SysToPlane (CATMathAxis const &iAxis, int iNormalIdx = 2);
    static CATMathVector GetPerpendicularVector(const CATMathVector &iToThis);
	static CATMathDirection GetRotatedVector(const CATMathLine &iAxis, double iRadian, const CATMathDirection &iArrowDir);
	static CATMathPoint GetRotatedPoint(const CATMathLine &iAxis, double iRadian, const CATMathPoint &iPoint);

	static void GetTransformationOfPointsAndDirections(
		CATMathTransformation & oTransformation,
		const CATMathPoint & iPoint1,
		const CATMathDirection & iDirection1,
		const CATMathPoint & iPoint2,
		const CATMathDirection & iDirection2);

private:
    SWXUtGeomUtils (SWXUtGeomUtils &);
    SWXUtGeomUtils& operator=(SWXUtGeomUtils&);

};

//-----------------------------------------------------------------------

#endif