#ifndef SWXSvConstraintAdditionalData_H
#define SWXSvConstraintAdditionalData_H

#include "SWXSvSolverAPI.h"
#include "SWXSvEnums.h"
#include "SWXUtVector.h"
#include "SWXUtUniqueId.h"

class SWXSvSolverGeometry;

// union of additional data for all types of constraints
class ExportedBySWXSvSolverAPI SWXSvConstraintAdditionalData
{
public:
    SWXSvConstraintAdditionalData( svConstraintType const &iType );

    // svGear: data for gear constraint
    struct ExportedBySWXSvSolverAPI SWXSvGearData
    {
        SWXSvGearData();

        double mGearRatio;
        bool mObjectsRotationDirSame;
    };

    // svRackAndPinion: Rack and Pinion constraint
    struct ExportedBySWXSvSolverAPI SWXSvRackAndPinionData
    {
        SWXSvRackAndPinionData();

        double mGearRatio;
        bool mObjectsMovingInSameDir;
    };

    // svBelt: Belt constraint, for slave pulley data
    struct ExportedBySWXSvSolverAPI SWXSvSlavePulleyData
    {
        SWXSvSlavePulleyData();

        bool mRotDirSameAsFirstObj;
        double mGearRatioSlave;
    };

    // svBelt: Belt constraint
    struct ExportedBySWXSvSolverAPI SWXSvBeltData
    {
        SWXSvBeltData();

        SWXUtVector<SWXSvSlavePulleyData> mVecSlavePulleyData;
        SWXUtVector<SWXUtUniqueId> mVecGeomIdsForBelt;
        SWXUtVector<SWXSvSolverGeometry*> mVecGeomsForBelt;
    };

	// EHV-HELPPOINTS
    struct ExportedBySWXSvSolverAPI SWXSvDimensionHalfSpaceData
    {
        SWXSvDimensionHalfSpaceData();

		SWXUtUniqueId mHalfSpaceGeometryId;
		SWXSvSolverGeometry* mHalfSpaceGeometry;
		svConstraintHalfSpace mHalfSpaceOrientation;
    };

public:
    svConstraintType mConstraintType;
    
    // one of the following will have valid data
    SWXSvGearData mGearData;
    SWXSvRackAndPinionData mRackAndPinionData;
    SWXSvBeltData mBeltData;

	// EHV-HELPPOINTS
	SWXSvDimensionHalfSpaceData mHalfSpaceOrientationData;
};

#endif
