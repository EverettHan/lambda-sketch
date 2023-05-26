#ifndef CATGeomType_H
#define CATGeomType_H

// COPYRIGHT DASSAULT SYSTEMES 2015

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * The type of geometric elements.
 * @param CATBoundaryEdge
 *    A @href CAT3DEdgeGP or @href CAT3DLineGP that bounds a face
 * @param CATInternalSharpeEdge
 *    A G0 continuous @href CAT3DEdgeGP or @href CAT3DLineGP between two faces
 * @param CATInternalSmoothEdge
 *    An at least G1 continuous @href CAT3DEdgeGP or @href CAT3DLineGP between two faces
 * @param CATBoundaryPoint
 *    A @href CAT3DMarkerGP that bounds a face
 * @param CATInternalSharpePoint
 *    A G0 continuous @href CAT3DMarkerGP
 * @param CATInternalSmoothPoint
 *    An at least G1 continuous @href CAT3DMarkerGP
 * @param CATSurfacicPoint
 *    A @href CAT3DMarkerGP that lies on a face
 * @param CATFreePoint
 *    A @href CAT3DMarkerGP
 * @param CATWireEdge
 *    A @href CAT3DLineGP that represents a wire (polyline)
 * @param CATVolume
 *    A @href CAT3DVolumeGP that represents a volume (defined by a list of face)
 */
enum CATGeomType {
   CATBoundaryEdge,
   CATInternalSharpeEdge,
   CATInternalSmoothEdge,
   CATBoundaryPoint,
   CATInternalSharpePoint,
   CATInternalSmoothPoint,
   CATSurfacicPoint,
   CATFreePoint,
   CATWireEdge,
   CATInfiniteFace,
   CATVisVolume
};

#endif
