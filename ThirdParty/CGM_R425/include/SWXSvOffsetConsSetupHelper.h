#ifndef SWXSvOffsetConsSetupHelper_H
#define SWXSvOffsetConsSetupHelper_H

#include "SWXSvCDSWrapper.h"
#include "SWXUtUniqueId.h"
#include "SWXUtVector.h"
#include "SWXUtGeometry.h"

class SWXSvSolverSketch;
class SWXSvCDSOffset;
class SWXSvSolver;
class SWXSvSolverGeometry;


/*
* class to setup offset constraints in solver corresponding to SWXISkOffsetConstraint
* Usage example:
*		SWXSvOffsetConsSetupHelper offHelper( solver, sketch );
*		offHelper.CreateOffsetConstraint();
*		offHelper.AddBaseProfile( baseProfId, retOffProdId, retOffCurveIds, retOffVertIds );
*		offHelper.AddBaseProfile( baseProfId1, retOffProdId1, retOffCurveIds1, retOffVertIds1 );
*/
class ExportedBySWXSvCDSWrapper SWXSvOffsetConsSetupHelper
{
public:
	SWXSvOffsetConsSetupHelper( SWXSvSolver* iSolver, SWXUtUniqueId const &iSketchPlaneId/* SWXSvSolverSketch* iSketch*/ );
	SWXSvOffsetConsSetupHelper( SWXSvSolver* iSolver, SWXUtUniqueId const &iSketchPlaneId, SWXUtUniqueId const &iOffConstrId );
	~SWXSvOffsetConsSetupHelper();

	struct ProfileGeoms
	{
		SWXUtVector<SWXUtGeometry_Ptr> mVecProfileCurveGeom;	// curves forming the profile
		SWXUtVector<SWXUtGeometry_Ptr> mVecProfileVertexGeom;	// vertices of curves in profile
		CATUnicodeString mTrimInfo;								// Trim info for offset profile
		bool mBorderVerticesAlignment;							// Alignment of border vertices with base profile
		ProfileGeoms() { mBorderVerticesAlignment = true;}
	};
	/* create an offset swx-solver offset constraint (SWXSvCDSOffset)
	*/
	SWXUtUniqueId		CreateOffsetConstraint();

	/* Add a base profile to offset constraint. Create offset profile, curves, vertices and set up CDS offset constraint
	* @param iBaseProfileId		: Base profile  
	* @param iOffProfileInitPosn: Initial position of offset profile
	* @param oOffsetProfileId	: Solver id for Created offset profile 
	* @param oOffsetCurveIds	: Solver id for Created offset profile curves
	* @param oOffsetVertexIds	: Solver id for Created offset profile vertices
	*/
	bool				AddBaseProfile( SWXUtUniqueId const &iBaseProfileId, ProfileGeoms const &iOffProfileInitPosn,
										SWXUtUniqueId &oOffsetProfileId,
										SWXUtVector<SWXUtUniqueId> &oOffsetCurveIds,
										SWXUtVector<SWXUtUniqueId> &oOffsetVertexIds );

	bool				RemoveBaseProfile( SWXUtUniqueId const &iBaseProfileId );

	void				SetBorderVerticesAlignment(SWXUtUniqueId const &iBaseProfileId, bool iIsAligned);

	// Use this function to recreate offset after every solver clear
	bool				AddOffset( SWXUtUniqueId const &iBaseProfileId, SWXUtUniqueId &iOffsetProfileId, double iOffDist, bool iBorderVerticesAligned);

	void				InitializeOffsetProfile(SWXUtVector<SWXUtUniqueId> const &iOffsetCurvesId, SWXUtVector<SWXUtUniqueId> const &iOffsetVerticesId, 
														  SWXUtUniqueId const &iOffsetProfileId, ProfileGeoms const &iInitPosn);

private:
	void				UpdateOffsetGeomPosition(SWXUtVector<SWXSvSolverGeometry*> const &iOffsetCurves, 
												 SWXUtVector<SWXSvSolverGeometry*> const &iOffsetVertices,
												 SWXSvSolverGeometry* const &iOffsetProfile,
												 ProfileGeoms const &iInitPosn);
private:
	SWXSvCDSOffset* mOffsetConstraint;
	
	SWXSvSolver* mSvSolver;
	SWXUtUniqueId mSketchId;	
};

#endif
