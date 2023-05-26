#pragma once

enum svGeometryType
{
	svInvalid = -1,
	svPoint,
	svPoint2d,
	svLine,
	svLine2d,
	svCircle,
	svCircle2d,
	svEllipse,
	svEllipse2d,
	svPlane,
	svCylinder,
	svCone,
	svSphere,
	svTorus,
	svCSys,
	svArc2d, 
	svLine2dPlane,
	svLinePlane,
	svCircle2dPlane,
	svCirclePlane,
	svEllipse2dPlane,
	svEllipsePlane,
	svSpline2d,
	svSpline,
	svProfile2d,
	svCtrlSpline2d,
	svCtrlSpline,
	svNonStandardSurface,
	svLineNonStandardSurface // EHV-R417-EHV is this the right place for this?  svLinePlane is already here, but......
};

// EHV this is serialised data - you may add things to the end, but don't change the order of things already here.
enum svConstraintType
{
	svInvalidConstraintType = -1,
	svFreeze = 0,
	svCoincident, 
	svParallel, 
	svOrthogonal, 
	svDistance,
	svAngle,
	svRadius,
	svTangent,
	svConcentric,
	svArcLength,
	svMidPoint,
	svHorizontal,
	svVertical,
	svAlongX,
	svAlongY,
	svAlongZ,
	svDependence,
	svLinearPattern,
	svCircularPattern,
	svDistanceAlongH, // EHV 8-May-2014 renamed from svDistanceAlongX for clarity between 2D and 3D
	svDistanceAlongV, // EHV 8-May-2014 renamed from svDistanceAlongY for clarity between 2D and 3D
	svDistanceAlong3DZ, // EHV 8-May-2014 renamed from svDistanceAlongZ for clarity between 2D and 3D
	svSoftFreeze,
	svMerge,
	svEqual,
	svIntersection,
	svOnEdge,
	svSymmetric,
	svMirror,
	svCoRadial,
	svCollinear,
	svGear,
	svRackAndPinion,
	svPierce,
	svBelt,
	svDistanceRatio,
	svNotSupported,
	svMajorRadius,
	svMinorRadius,
	svNormal,
	// ZLE. SWIC. 3D Sketch - BEGIN
	// Tangent constraint at start/end point of sketch spline curve with B-Rep edge/face
	svTangentAlongEdge,
	svTangentToFaceCrossEdge,			// tangent to face and perpendicular to edge
	svNormalToFace,
	svTangentAlongUIsoCurve,			// v = const iso-curve, not implemented yet.
	svTangentAlongVIsoCurve,			// u = const iso-curve, not implemented yet.
	svAveragedNormalToFaces, 			// not implemented yet
	// ZLE. SWIC. 3D Sketch - END
    svSplineOnSurface,
    svCurveOnSurface,
    svProjectOnTarget, // not used - and no plans to do so
    svOffset,
    svCurveOnSurfaceId, // used to hold info allowing re-identification during re-execution
    svProjectSketches, // not used - and no plans to do so
	svHandleSymmetry,
	// ZLE. SWIC. 3D Sketch - BEGIN
	svEqualCurvatureAlongEdge,
	svEqualCurvatureCrossEdge,			// equal curvature for tangent to face and perpendicular to edge
	svEqualCurvatureAlongUIsoCurve,		// future use. v = const iso-curve, not implemented yet.
	svEqualCurvatureAlongVIsoCurve,		// future use. u = const iso-curve, not implemented yet.
	svIntersectionCurve,
	// ZLE. SWIC. 3D Sketch - END
    svProjectOnTargetId, // used to hold info allowing re-identification during re-execution
    svProjectSketchesId, // used to hold info allowing re-identification during re-execution
    svCompositeCurve,
	svHandleAsymmetry,
    svProjectionCurve,
	svEqualCurvature,
	// Begin: Mechanism Synthesis Constraints (KLB)
	svEqualDimValue,
	svTrackingPoint,
	// End:	  Mechanism Synthesis Constraints (KLB)
	svNormalPoints,
	svSoftDistance,
	svCurvature,
	svDistanceAlong3DX, // EHV 8-May-2014 split from old svDistanceAlongX for clarity between 2D and 3D
	svDistanceAlong3DY, // EHV 8-May-2014 split from old svDistanceAlongY for clarity between 2D and 3D
	svPlaneOrthogonalToCurve, // ZIZ 
	svNormalToSurface, // EHV 20-May-2014 for perpendicular to irregular surface
	svOffsetPlane,
	svEqualCurvatureLit,
	svPointViewPlane,
	svCoTangent,
	svEquidistantPoint,
	svCylinderRadius
};

// EHV this is serialised data - don't change the order.
enum svBooleanType
{
	svBooleanNone = 0,
	svBooleanAdd,
	svBooleanSubtract,
	svBooleanIntersect
};

enum svBooleanEditType
{
	svBooleanEditHide = 0,
	svBooleanEditShow
};

enum svGeometryStatus
{
	svInvalidGeomStatus = -1,
	svFixed,
	svGeomOverdefined,
	svGeomUnderdefined,
	svGeomWellDefined
};

enum svConstraintStatus
{
	svInvalidConstraintStatus = -1,
	svSatisfied,
	svNotSolved,
	svConstraintOverdefined,
	svNotConsistent,
	svBetweenFixed,				// UFR - this is just so we can do more diagnostics.
	svDangling,
	svAboutToDrop	//Added 4/20/15 for interchangeable geometry -sjr
};

enum svDraggingMode
{
	svInitialPositionDrag,
	svIncrementalDrag
};

enum svAlignment 
{
	svAlignmentNotSpecified,
	svAlignmentSpecified,
	svAlignmentAlign,
	svAlignmentAnti
};

enum svConstraintChirality
{
	svChiralityNotSpecified,
	svChiralityAligned,
	svChiralityAntiAligned
};

enum svConstraintDimMinMax //IZO - circle minmax dims (initially)
{
	svDimMinMaxNotSpecified ,
	svDimMax,
	svDimMin
};

// EHV-HELPPOINTS
enum svConstraintHalfSpace
{
	svHalfSpaceNotSpecified,
	svHalfSpacePositive,
	svHalfSpaceNegative
};

enum svInterpolConditionBitType
{
  svConditionBitTypePOINT					= 0x0001,
  svConditionBitTypeFIRSTDERIV_DIR			= 0x0002,
  svConditionBitTypeFIRSTDERIV_ANGLE		= 0x0004,
  svConditionBitTypeFIRSTDERIV_ANGLE_VAR	= 0x0008,
  svConditionBitTypeFIRSTDERIV_NORM			= 0x0010,
  svConditionBitTypeFIRSTDERIV_NORM_VAR		= 0x0020,
  svConditionBitTypeCURVATURE				= 0x0040,
  svConditionBitTypeCURVATURE_VAR			= 0x0080,
  svConditionBitTypeSECONDDERIV_DIR			= 0x0100,
  svConditionBitTypeSECONDDERIV_NORM		= 0x0200,
  svConditionBitTypeSECONDDERIV_NORM_VAR	= 0x0400,
};

enum svInterpolConditionType
{
  svConditionTypeNONE = 0,
  svConditionTypePOINT,
  svConditionTypeFIRSTDERIV_DIR,
  svConditionTypeFIRSTDERIV_ANGLE,
  svConditionTypeFIRSTDERIV_ANGLE_VAR,
  svConditionTypeFIRSTDERIV_NORM,
  svConditionTypeFIRSTDERIV_NORM_VAR,
  svConditionTypeCURVATURE,
  svConditionTypeCURVATURE_VAR,
  svConditionTypeSECONDDERIV_DIR,
  svConditionTypeSECONDDERIV_NORM,
  svConditionTypeSECONDDERIV_NORM_VAR,

  svNumberOfConditionTypes = 11
 };

enum svInterpolMovingMode
{
  svMovingModeIsConditions,           // attempt to minimize the movements of the interpolation conditions of the NURBS
  svMovingModeIsControlPoints         // attempt to minimize the movements of the control points
};

// EHV this is serialised data - don't change the order.
enum svPictureResizeType
{
	svPicLockRatio	= 0,
	svPicRigid		= 1,
	svPicFlexible	= 2
};

enum CurveType
{
	kRegularCurve= 0,
	kSplineOnSurface,
	kAutoTrimOffset,
	kConceptSketchStroke,
	kIntersectionCurves
};

enum svConstraintStatusCombineModeType
{
	svConstraintStatusCombineDefault = 0x0,
	svConstraintStatusCombineSatisfiedPrecedeOverdefined = 0x01
};

const int SWXSV_HELPPOINTS_MAX_SIZE = 4;


