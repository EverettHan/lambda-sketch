#ifndef SWXOffsetProfileUpdateHelper_H
#define SWXOffsetProfileUpdateHelper_H

#include "SWXSvCDSWrapper.h"
#include "SWXUtUniqueId.h"
#include "SWXUtVector.h"

class SWXSvSolver;
class SWXSvCDSProfile2d;
class SWXOffsetUpdateCallback;
class CATMathPoint;



// Class to help with updating of offset curves, vertices etc., in SWXSketchModeler level
class ExportedBySWXSvCDSWrapper SWXOffsetProfileUpdateHelper
{
public:
	SWXOffsetProfileUpdateHelper( SWXUtUniqueId const &iProfileId, SWXUtUniqueId const &iBaseProfileId, SWXSvSolver* iSolver );
	virtual ~SWXOffsetProfileUpdateHelper();

	bool Update( SWXOffsetUpdateCallback &iUpdateCallback );
	bool Update2( SWXOffsetUpdateCallback &iUpdateCallback );

private:
	SWXUtUniqueId mProfileId;
	SWXUtUniqueId mBaseProfileId;
	SWXSvSolver* mSvSolver;
	SWXSvCDSProfile2d* mProfile;
	SWXSvCDSProfile2d* mBaseProfile;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Callback class to help with updating of offset curves, vertices etc., in SWXSketchModeler level
class ExportedBySWXSvCDSWrapper SWXOffsetUpdateCallback
{
public:
			SWXOffsetUpdateCallback();
	virtual ~SWXOffsetUpdateCallback();

	virtual void	SetVisibilityForCurves( SWXUtVector<bool> &iVecCurveVisibility, bool &iIsSelfIntersecting ) = 0;
	virtual void	SetTrimmedEntitiesAsDangling( SWXUtVector<bool> &iVecCurvesTrimStatus, SWXUtVector<bool> &iVecVerticesTrimStatus ) = 0;
	virtual void	OnGeomUpdateComplete() = 0;	
	virtual void	StoreCDSVertexLoc( SWXUtVector<CATMathPoint> &iVertexLoc ) = 0;
	virtual void	StoreTrimInfo( CATUnicodeString const &iTrimInfo ) = 0;
	virtual void	StoreBaseTrimInfo( CATUnicodeString const &iTrimInfo ) {}

	// for future
	//void			CreateSegement( some params here ) = 0;

protected:
	//SWXSvSolver* mSvSolver;
};


#endif
