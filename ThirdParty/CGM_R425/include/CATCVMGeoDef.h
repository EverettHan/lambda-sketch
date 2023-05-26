/* -*-C++-*- */

#ifndef CATCVMGeoDef_H
#define CATCVMGeoDef_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMDef
//
//===================================================================


//===================================================================
// Oct. 2006    Creation                                        AAD
// Jan. 2007    CATCVMMagnetType, CATCVMSnapType                FCX
//===================================================================
/*
enum CATCVMConstraintPossibility
{
    CATCVMConstraintActual,
    CATCVMConstraintPossible
};
*/
enum CATCVMComputationMode
{
  CATCVMComputationMode_Standard = 0,
  CATCVMComputationMode_NoIntersection = 1,
  CATCVMComputationMode_NoMerge = 2
};

enum CATCVMCanonicity
{
    CATCVMCanonicalUnknown,
    CATCVMCanonicalPoint,
    CATCVMCanonicalLine,
    CATCVMCanonicalCircle,
    CATCVMCanonicalCurve,
    CATCVMCanonicalPlane,
    CATCVMCanonicalCylinder,
    CATCVMCanonicalSurface,
    CATCVMNonCanonicalSurface,
    CATCVMRevolutionSurface,
    CATCVMNurbsSurface,
    CATCVMCanonicalCone,
    CATCVMCanonicalSphere,
    CATCVMCanonicalTorus
};

enum CATCVMMagnetType
{
    CATCVMMagnetType_Point,
    CATCVMMagnetType_Segment,
    CATCVMMagnetType_Edge,
    CATCVMMagnetType_Face,
    CATCVMMagnetType_SegmentUV,                       // new 06.2009 : UV magnets
    CATCVMMagnetType_Circle,                          // new 09.2010 : circle for fixed distance
    CATCVMMagnetType_PointList,                       // new 08.2013
    NumberOfCATCVMMagnetType                            // DO NOT USE  : define the number of magnet Type
};

enum CATCVMSnapType
{
    CATCVMSnapType_ReferenceDirection = 0,
    CATCVMSnapType_ParallelEdgeDirection,
    CATCVMSnapType_ParallelEdgeOnDemandDirection,
    CATCVMSnapType_PerpendicularEdgeDirection,
    CATCVMSnapType_AlignedVertexPoint,
    CATCVMSnapType_AlignedMiddlePoint,
    CATCVMSnapType_AlignedVertexOnDemandPoint,
    CATCVMSnapType_AlignedMiddleOnDemandPoint,
    CATCVMSnapType_ProjectedVertexPoint,              // coincident to the projection
    CATCVMSnapType_ProjectedMiddlePoint,              // coincident to the projection
    CATCVMSnapType_ReferencePlanePoint,
    CATCVMSnapType_CoincidentVertexSupport,
    CATCVMSnapType_CoincidentEdgeSupport,             // coincident with the edge
    CATCVMSnapType_CoincidentEdgeLineSupport,         // coincident with the infinite line supporting the edge
    CATCVMSnapType_CoincidentFaceSupport,             // coincident with the face
    CATCVMSnapType_CoincidentFacePlaneSupport,        // coincident with the infinite plane supporting the face
    CATCVMSnapType_CoincidentMiddleSupport,
    CATCVMSnapType_CoincidentCircleCenterSupport,     // new 06.2007 : circles & cylinder
    CATCVMSnapType_CoincidentAxisSupport,             // new 06.2007 : circles & cylinder
    CATCVMSnapType_AlignedCircleCenterPoint,          // new 06.2007 : circles & cylinder
    CATCVMSnapType_AlignedCircleCenterOnDemandPoint,  // new 06.2007 : circles & cylinder
    CATCVMSnapType_ProjectedCircleCenterPoint,        // new 06.2007 : circles & cylinder
    CATCVMSnapType_ParallelAxisDirection,             // new 06.2007 : circles & cylinder
    CATCVMSnapType_CircleTangentDirection,            // new 06.2007 : circles & cylinder
    CATCVMSnapType_CircleRadialDirection,             // new 06.2007 : circles & cylinder
    CATCVMSnapType_ExtremityForTangentArc,            // new 08.2007 : arcs
    CATCVMSnapType_LineForTangentArc,                 // new 08.2007 : arcs
    CATCVMSnapType_LineForHalfCircleArc,              // new 08.2007 : arcs
    CATCVMSnapType_SquareDirection,                   // new 10.2007 : rectangle mode
    CATCVMSnapType_CoincidentSphereCenterSupport,     // new 04.2008 : sphere, cone & torus
    CATCVMSnapType_CoincidentConeApexSupport,         // new 04.2008 : sphere, cone & torus
    CATCVMSnapType_AlignedSphereCenterPoint,          // new 04.2008 : sphere, cone & torus
    CATCVMSnapType_ProjectedSphereCenterPoint,        // new 04.2008 : sphere, cone & torus
    CATCVMSnapType_GeoMeshPoint,                      // new 06.2008 : mesh
    CATCVMSnapType_BoundingBoxPoint,                  // new 06.2008 : bounding box points
    CATCVMSnapType_ReferenceDirectionUV,              // new 06.2009 : UV magnets
    CATCVMSnapType_ParallelEdgeDirectionUV,           // new 06.2009 : UV magnets
    CATCVMSnapType_ParallelEdgeOnDemandDirectionUV,   // new 06.2009 : UV magnets
    CATCVMSnapType_PerpendicularEdgeDirectionUV,      // new 06.2009 : UV magnets
    CATCVMSnapType_AlignedVertexPointUV,              // new 06.2009 : UV magnets
    CATCVMSnapType_AlignedMiddlePointUV,              // new 06.2009 : UV magnets
    CATCVMSnapType_AlignedVertexOnDemandPointUV,      // new 06.2009 : UV magnets
    CATCVMSnapType_AlignedMiddleOnDemandPointUV,      // new 06.2009 : UV magnets
    CATCVMSnapType_AlignedOnArcTangent,               // new 09.2010 : to snap on the tangent from the extremities of an arc
    CATCVMSnapType_OnRestrictedDistance,              // new 09.2010 : to snap on other magnet at a given distance of the previous point
    CATCVMSnapType_DoubleCircleTangentDirection,      // new 03.2013 : to snap on tangent from two circles
    CATCVMSnapType_PlaneOrigin,                       // new 05.2013 : to snap on the origin of a plane
    CATCVMSnapType_BisectorBetween2Lines,             // new 05.2013 : to snap on the bisector of two lines
    CATCVMSnapType_PerpendicularInitEdgeDirection,    // new 08.2013 : to snap on the perpendical of the first edge of a polyline
    CATCVMSnapType_LinePassingThrough2Points,                // new 11.2015 : to snap on the line passing through two points
    NumberOfCATCVMSnapType                            // DO NOT USE  : define the number of Snap Type
};

enum CATCVMGeoTopoRule
{
    CATCVMGeoTopoRule_NotSet,
    CATCVMGeoTopoRule_Standard,
    CATCVMGeoTopoRule_NonManifold
};

#endif
