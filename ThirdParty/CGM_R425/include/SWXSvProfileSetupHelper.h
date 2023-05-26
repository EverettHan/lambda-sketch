#ifndef SWXSvProfileSetupHelper_H
#define SWXSvProfileSetupHelper_H

#include "SWXSvCDSWrapper.h"
#include "SWXUtUniqueId.h"
#include "SWXUtVector.h"

class SWXSvSolver;
class SWXSvSolverConstraint;

/*
* Helper to create and setup profile information in the solver
*/
class ExportedBySWXSvCDSWrapper SWXSvProfileSetupHelper
{
public:
	SWXSvProfileSetupHelper( SWXSvSolver* iSolver, SWXUtUniqueId const &iSketchPlaneId );
	~SWXSvProfileSetupHelper();

public:
	struct ProfileData
	{
		SWXUtVector<SWXUtUniqueId> mVecProfileCurveId;	// curves forming the profile
		SWXUtVector<SWXUtUniqueId> mVecProfileVertexId; // vertices of curves in profile
		SWXUtVector<int> mVecCurveOrientation;			// curve orientations in profile
		bool mIsOffDirInsideForSingleClosedCurve;		// offset direction for single closed curve
		ProfileData() { mIsOffDirInsideForSingleClosedCurve = true; }
	};


	SWXUtUniqueId CreateProfile( ProfileData const &iProfileData );
	void		  SetTrimInfo(SWXUtUniqueId const &iProfile, CATUnicodeString &iTrimInfo);
	void		  FixProfile( SWXUtUniqueId const &iProfile, bool iFix = true );
	bool		  HasProfileMovedAfterSolve( SWXUtUniqueId const &iProfile);

private:
	SWXUtUniqueId CreateProfileForSingleClosedCurve( ProfileData const &iProfileData );
	void CreateCoincidentConstraintForRigidSetProfiles( ProfileData const &iProfileData, SWXUtVector<SWXSvSolverConstraint*> &oCoiConstr );

private:
	SWXSvSolver* mSvSolver;
	SWXUtUniqueId mSketchId;
};


#endif
