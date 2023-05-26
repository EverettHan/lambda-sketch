// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyServices.h
//
//===================================================================
// May  2011  Creation: NDO
// June 2014  Modification JXO: Geometric diagnosis
// March 2018 Modification JXO: SetPointType, SetWireType, SetSkinType, SetSolidType
//===================================================================
#pragma once

#include "PolyBodyTools.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATPolyStreamOptions.h"
#include "CATPolyDeprecated.h"
#include "CATMathStreamVersionDef.h"

#include "CATPolyMacroTopologyFwd.h"
#include "CATIPolyBodyAttributes.h"
#include "CATPolyBody.h"

class CATIPolyObject;
class CATIPolyPoint;
class CATIPolyCurve;
class CATIPolySurface;
class CATIPolySurfaceVertex;

class CATPolyStreamRecord;
class CATPolyUnstreamRecord;
class CATUnicodeString;
class CATMapOfPtrToInt;


/** @file 
 * Global services about CATPolyBody.
 *
 * @see CATPolyServices.h for services about CATIPolyPoint, CATIPolyCurve and CATIPolySurface.
 * @see CATPolyCGMServices.h for additional CGM services about CATIPolyPoint, CATIPolyCurve and CATIPolySurface.
 * @see CATPolyVisServices.h for additional visualization services.
 */

class CATPolyBodyDiagnosis;
class CATPolyBodyGeoDiagnosis;
class CATIPolyPrimitiveSupport;

class CATMathBox;
class CATMathTransformation;
class CATTolerance;


namespace Poly
{
  /** @name Topology Services
   *
   * CATPolyBodyServices.h
   * @{ */

  /**
   * Activation of the methods for the construction of new edge topology:
   *   * Edges with incomplete boundaries (without start or end vertices).
   *   * A closed edge:
   *     ** Referring to a close curve without any vertex.
   *     ** Referring to an open curve with a vertex joining the start and end of the curve.
   */
  ExportedByPolyBodyTools bool EnablePolyBodyWithPartialOrClosedEdgeTopo ();

  /**
   * Returns the CATPolyEdge incident to a CATPolyVertex and adjacent to a CATPolyEdge from a same CATPolyFace.
   * There can be at most one incident CATPolyEdge (unless the vertex is bounding twice the edge from the face.)
   * @return
   *   The incident CATPolyEdge or 0 if there is none.
   */
  ExportedByPolyBodyTools CATPolyEdge* GetIncidentEdge (const CATPolyVertex* iVertex, const CATPolyEdge* iEdge, const CATPolyFace* iFace);

  /**
   * Returns the CATPolyFace incident to a CATPolyEdge and adjacent to a CATPolyFace from a same CATPolyVolume.
   * There can be at most one face satisfying the conditions (unless the edge is bounding twice the face from the volume.)
   * @return
   *   The incident CATPolyFace or 0 if there is none.
   */
  ExportedByPolyBodyTools CATPolyFace* GetIncidentFace (const CATPolyEdge* iEdge, const CATPolyFace* iFace, const CATPolyVolume* iVolume);

  /**
   * Returns the adjacent face to a face across an edge.
   * Note that an edge can be incident to several faces.
   * The adjacent face may not be unique.
   * It returns null if the edge has no other incident face.
   * @return
   *   The adjacent face or null.
   */
  ExportedByPolyBodyTools CATPolyFace* GetAdjacentFace (const CATPolyEdge* E, const CATPolyFace* F);

  /**
   * Returns the adjacent volume to a volume across a face.
   * A face is incident to at most two volumes.
   * There cannot be more than one adjacent volume.
   * It returns null if the face has no other incident volume.
   * @return
   *   The adjacent face or null.
   */
  ExportedByPolyBodyTools CATPolyVolume* GetAdjacentVolume (const CATPolyFace* F, const CATPolyVolume* VLM);

  /**
   * Returns the CATPolyVertex and its CATIPolySurfaceVertex uniquely associated to a CATPolyFaceOrbit.
   */
  ExportedByPolyBodyTools CATPolyVertex* GetVertex (CATPolyFaceOrbit& orbit, CATIPolySurfaceVertex*& iSV);

  /** @} */

};


/** @name Topology Services
    @{ */

/**
 * Returns an adjacent face to the edge if any.
 * @return
 *   The adjacent CATPolyFace or 0 if there is none.
 */
ExportedByPolyBodyTools CATPolyFace* CATPolyGetAdjacentFace (CATPolyEdge* iEdge);

/**
 * Returns the CATIPolyCurve that is shared by the CATPolyEdge and the CATPolyFace.
 * The returned instance should not be released.
 */
ExportedByPolyBodyTools CATIPolyCurve* CATPolyGetCurve (CATPolyEdge* iEdge, CATPolyFace* iFace);

/**
 * Returns the CATIPolyPoint that is shared by the CATPolyVertex and the CATPolyFace.
 * The returned instance should not be released.
 */
ExportedByPolyBodyTools CATIPolyPoint* CATPolyGetPoint (CATPolyVertex* iVertex, CATPolyFace* iFace);

/**
 * Returns the CATIPolyObject that is shared by the CATPolyCell and the CATPolyFace.
 * The returned instance should not be released.
 */
ExportedByPolyBodyTools CATIPolyObject* CATPolyGetPolyObject (CATPolyCell* iCell, CATPolyFace* iFace);

/**
 * Returns a CATIPolyCurve associated to a CATPolyEdge.
 * The returned instance should not be released.
 */
ExportedByPolyBodyTools CATIPolyCurve* CATPolyGetACurve (const CATPolyEdge* iEdge);

/**
* Returns a CATIPolyPoint associated to a CATPolyVertex.
* The returned instance should not be released.
*/
ExportedByPolyBodyTools CATIPolyPoint* CATPolyGetAPoint (const CATPolyVertex* iVertex);

/**
 * Given two CATPolyCell, returns the CATPolyEdge that is adjacent to both cells.
 * This CATPolyEdge may not be unique for two CATPolyVertex.
 * @return
 *   The CATPolyEdge shared by the two input cells.
 */
ExportedByPolyBodyTools const CATPolyEdge* CATPolyGetCommonEdge (const CATPolyCell* iCell0, const CATPolyCell* iCell1);

/** @} */


/** @name Diagnosis
    @{ */

/**
 * Returns the status about the validity of the CATPolyBody. 
 * @return
 *   <ul>
 *     <li> <tt>S_OK</tt> if the CATPolyBody is valid;
 *     <li> <tt>S_FALSE</tt> if the CATPolyBody is invalid;
 *     <li> <tt>E_FAIL</tt> if a serious error is detected (corrupted CATPolyBody) and the tests
 *          could not be completed.
 *   </ul>
 * See CATPolyBodyDiagnosis if the CATPolyBody is invalid for further information about 
 * the errors.
 */
ExportedByPolyBodyTools HRESULT CATPolyIsValid (const CATPolyBody& iPolyBody);

/**
 * Returns the status about the watertightness of the CATPolyBody. 
 * @return
 *   <ul>
 *     <li> <tt>S_OK</tt> if the CATPolyBody is topologically watertight;
 *     <li> <tt>S_FALSE</tt> if the CATPolyBody is open;
 *     <li> <tt>E_FAIL</tt> if a serious error is detected (corrupted CATPolyBody) and the tests
 *          could not be completed.
 *   </ul>
 */
ExportedByPolyBodyTools HRESULT CATPolyIsTopologicallyWatertight(const CATPolyBody& iPolyBody);

/**
 * Returns the status about the geometric watertightness of the CATPolyBody. 
 * @return
 *   <ul>
 *     <li> <tt>S_OK</tt> if the CATPolyBody is geometrically watertight;
 *     <li> <tt>S_FALSE</tt> if the CATPolyBody is open;
 *     <li> <tt>E_FAIL</tt> if a serious error is detected (corrupted CATPolyBody) and the tests
 *          could not be completed.
 *   </ul>
 */
ExportedByPolyBodyTools HRESULT CATPolyIsGeometricallyWatertight(const CATPolyBody& iPolyBody);

/**
 * Returns the CATPolyBodyDiagnosis from a CATPolyBody if available.
 * The object returned should not be deleted by the caller.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @return
 *   The diagnosis of the CATPolyBody.
 */
ExportedByPolyBodyTools CATPolyBodyDiagnosis* CATPolyGetDiagnosis (const CATPolyBody& iPolyBody);

/**
 * Returns the geometric diagnosis from a CATPolyBody if available.
 * The diagnosis has to be filled with a CATPolyBodyGeoChecker, or by calling CATPolyIsGeoValid.
 * The object returned should not be deleted by the caller.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @return
 *   The geometric diagnosis of the CATPolyBody.
 */
ExportedByPolyBodyTools CATPolyBodyGeoDiagnosis* CATPolyGetGeoDiagnosis (const CATPolyBody& iPolyBody);

/** @} */


/** @name Bounding Volumes
    @{ */

namespace Poly
{

  /**
   * Computes the bounding box of a CATPolyBody instance.
   * @param iPolyBody
   *   The input CATPolyBody.
   * @param ioBox
   *   The computed bounding box.
   * @param iPosMatrix
   *   An optional transformation applied to the points.
   * @return
   *   S_OK for a successful call
   *   S_FALSE if the bounding box has not been computed.
   *   E_FAIL if an error occurs during the computation.
   */
  ExportedByPolyBodyTools HRESULT ComputeBoundingBox (const CATPolyBody& iPolyBody,
    CATMathBox& ioBox,
    const CATMathTransformation* iPosMatrix = 0);

}

/** @} */


/** @name Miscellaneous Services
    @{ */

/**
 * Retrieves the CGM ID of a CATPolyBody.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oID
 *   The returned ID of the CATPolyBody.
 * @return
 *   S_OK if the ID is set,
 *   S_FALSE if the body does not have an ID, or
 *   E_FAIL or another error code if an error occurs.
 */
ExportedByPolyBodyTools HRESULT CATPolyGetID (const CATPolyBody& iPolyBody, unsigned int& oID);

/**
 * Retrieves the sag of a CATPolyBody.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oSag
 *   The returned sag of the CATPolyBody.
 * @return
 *   S_OK if the sag is set,
 *   S_FALSE if the body does not have a sag, or
 *   E_FAIL or another error code if an error occurs.
 */
ExportedByPolyBodyTools HRESULT CATPolyGetSag (const CATPolyBody& iPolyBody, double& oSag);

/**
 * Retrieves the CATTolerance of a CATPolyBody.
 * The CATTolerance provides a set of tolerance values for geometric tests.
 * For instance, the distance from a point to the surface of a CATPolyBody can be compared to a length epsilon 
 * to check whether the point is on the surface or not.
 * Some tolerances like length tolerances depend on the scale of the model.
 * The instance returned cannot be deleted by the caller.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oTolerance
 *   The returned CATTolerance associated to the CATPolyBody.
 * @return
 *   S_OK if the CATTolerance is set,
 *   S_FALSE if the body does not have a CATTolerance, or
 *   E_FAIL or another error code if an error occurs.
 */
ExportedByPolyBodyTools HRESULT CATPolyGetTolerance (const CATPolyBody& iPolyBody, const CATTolerance*& oTolerance);

/**
 * Retrieves the underlying primitive support associated to a CATPolyBody, if any.
 * @param oSupport
 *   The support.  The returned support must be released (ref-counted.)
 * <ul>
 *   <li> <tt>S_OK</tt> if a support is successfully returned.
 *   <li> <tt>S_FALSE</tt> if a support is not available.
 *   <li> <tt>E_FAIL</tt> if an error occurs.
 * </ul>
 */
ExportedByPolyBodyTools HRESULT CATPolyGetSupport (const CATPolyBody& iPolyBody, CATIPolyPrimitiveSupport*& oSupport);

/**
 * Query about a solid body.
 * A CATPolyBody is a solid body if all the cells define the boundary of a solid.
 * A solid body refers exclusively to domains of dimension 3.
 * Note: this service only reads the attributes, it does not actually check the body.
 * <ul>
 *   <li> <tt>S_OK</tt> is a solid body.
 *   <li> <tt>S_FALSE</tt> is not a solid body.
 *   <li> <tt>E_FAIL</tt> for any error.
 * </ul>
 */
ExportedByPolyBodyTools HRESULT CATPolyIsSolidBody (const CATPolyBody& iPolyBody);

/**
 * Query about a skin body.
 * A skin body refers exclusively to domains of dimension 2.
 * Note: this service only reads the attributes, it does not actually check the body.
 * <ul>
 *   <li> <tt>S_OK</tt> is a skin body.
 *   <li> <tt>S_FALSE</tt> is not a skin body.
 *   <li> <tt>E_FAIL</tt> for any error.
 * </ul>
 */
ExportedByPolyBodyTools HRESULT CATPolyIsSkinBody (const CATPolyBody& iPolyBody);

/**
 * Query about a wire body.
 * A wire body refers exclusively to domains of dimension 1.
 * Note: this service only reads the attributes, it does not actually check the body.
 * <ul>
 *   <li> <tt>S_OK</tt> is a wire body.
 *   <li> <tt>S_FALSE</tt> is not a wire body.
 *   <li> <tt>E_FAIL</tt> for any error.
 * </ul>
 */
ExportedByPolyBodyTools HRESULT CATPolyIsWireBody (const CATPolyBody& iPolyBody);

/**
* Query about a point body.
* A point body refers exclusively to domains of dimension 0.
* Note: this service only reads the attributes, it does not actually check the body.
* <ul>
*   <li> <tt>S_OK</tt> is a point body.
*   <li> <tt>S_FALSE</tt> is not a point body.
*   <li> <tt>E_FAIL</tt> for any error.
* </ul>
*/
ExportedByPolyBodyTools HRESULT CATPolyIsPointBody (const CATPolyBody& iPolyBody);

/**
 * Query about a solid body.
 * A CATPolyBody contains a solid/3d domain.
 * Note: this service only reads the attributes, it does not actually check the body.
 * @return
 * True if the body contains the domain of the dimension specified.
 */
template<unsigned int DomainDimension>
bool CATPolyContainsDomainOfDim(const CATPolyBody & iPolyBody)
{
  CATIPolyBodyAttributes * attributes = 0;
  iPolyBody.GetAttributes(attributes);  // No release or delete.
  if (attributes)
    return attributes->DoesBodyContainDomainsOfDimension(DomainDimension) == 1 ? S_OK : S_FALSE;

  return S_FALSE;
};


/** @} */


namespace Poly
{
  /** @name Size Services
   *
   * CATPolyBodyServices.h
   * @{ */

  /**
   * Returns the total number of facets in a CATPolyBody.
   * @param iPolyBody
   *   The input CATPolyBody.
   * @return
   *   The count of all facets from all CATIPolySurface.
   */
  ExportedByPolyBodyTools unsigned int GetNbFacets (const CATPolyBody& iPolyBody);

  /**
   * Returns the total number of surface-vertices in a CATPolyBody.
   * @param iPolyBody
   *   The input CATPolyBody.
   * @return
   *   The count of all surface-vertices from all CATIPolySurface.
   */
  ExportedByPolyBodyTools unsigned int GetNbSurfaceVertices (const CATPolyBody& iPolyBody);

  /**
   * Returns the total number of edge-segments in a CATPolyBody.
   * (Edge-segments or bars may be shared by several curves.)
   * @param iPolyBody
   *   The input CATPolyBody.
   * @return
   *   The count of all edge-segments from the sample curves from the edges of the CATPolyBody.
   */
  ExportedByPolyBodyTools unsigned int GetNbEdgeSegments (const CATPolyBody& iPolyBody);

  /**
   * Returns the number of curve-vertices in each curve incident to a CATPolyEdge.
   * @param iPolyBody
   *   The input CATPolyBody.
   * @return
   *   The number of curve-vertices.
   */
  ExportedByPolyBodyTools unsigned int GetNbCurveVertices (const CATPolyEdge& Edge);

  /** @} */

};


namespace Poly
{
  /** @name CATPolyBody Services
   *
   * CATPolyBodyServices.h
   * @{ */

  /**
   * Returns true if the edge is generic, that is:
   *   * Bounded zero, one or two vertices;
   *   * Without any reference to any curve;
   *   * Without incidences to a face or a volume.
   *   * With no adjacence to another edge.
   * This is a transient state of an edge before addition of incidences or its deletion.
   * A generic edge has at most one edge-orbit.
   */
  ExportedByPolyBodyTools bool IsGeneric (const CATPolyEdge& E);

  /**
   * Returns the valence of a CATPolyVertex or equivalently the number of edges.
   */
  ExportedByPolyBodyTools unsigned int GetValence(const CATPolyVertex& V);

  /**
   * Returns the valence of a CATPolyEdge or equivalently the number of faces.
   */
  ExportedByPolyBodyTools unsigned int GetValence(const CATPolyEdge& E);

  /**
   * Returns the valence of a CATPolyFace or equivalently the number of volumes.
   */
  ExportedByPolyBodyTools unsigned int GetValence(const CATPolyFace& F);

  /**
   * Returns the relative orientation for face in the context of its CATPolyBody.
   * It is equivalent to the multiplicity of the face, but limited to -1,0,+1.
   */
  ExportedByPolyBodyTools int GetRelativeOrientation(const CATPolyFace & F);

  /**
   * Customization of the face-add vertex for some import operators.
   * Before calling the CATPolyBody::FaceAddVertex, this method checks 
   * a surface-vertex does not already refer to a CATPolyVertex.
   * It does not call CATPolyBody::FaceAddVertex if there is a reference to a vertex.
   * If the reference matches the input vertex, it just returns; if it does not match it fails.
   */
  ExportedByPolyBodyTools HRESULT CustomFaceAddVertex (CATPolyBody& B, CATPolyFace& F, const int sv, CATPolyVertex& V);

  /**
  * Retursn true if the edge is a border edge
  * @param oCurve
  *   The curve on the unique face
  * @param oFace
  *   The unique border face
  */
  ExportedByPolyBodyTools bool IsBorder(CATPolyEdge * E,
                                        CATPolyFace ** oFace = 0,
                                        CATIPolyCurve ** oCurve = 0);

 /** @} */

};


namespace Poly
{
  /** @name CATPolyBody Services
   *
   * CATPolyBody services to map the cell to an increasing id. <br/>
   * It can be useful to use array instead of map for highly-called methods.
   *
   * The map becomes invalid when the CATPolyBody topology changes.
   *
   * CATPolyBodyServices.h
   * @{ */

   /**
    * Maps the vertex to their integer position in the CATPolyBodyVertexIterator (starting from 1).
    * @param iPolyBody
    *   The input CATPolyBody.
    * @param oVertexToId
    *   A map from the CATPolyBody vertices to an integer index.
    */
  ExportedByPolyBodyTools HRESULT CreateVertexToIteratorId (const CATPolyBody& iPolyBody,
                                                            CATMapOfPtrToInt& oVertexToId);

  /**
   * Maps the edge to their integer position in the CATPolyBodyEdgeIterator (starting from 1).
   * @param iPolyBody
  *   The input CATPolyBody.
  * @param oEdgeToId
  *   A map from the CATPolyBody edges to an integer index.
  */
  ExportedByPolyBodyTools HRESULT CreateEdgeToIteratorId (const CATPolyBody& iPolyBody,
                                                          CATMapOfPtrToInt& oEdgeToId);

  /**
   * Maps the face to their integer position in the CATPolyBodyFaceIterator (starting from 1).
   * @param iPolyBody
   *   The input CATPolyBody.
   * @param oFaceToId
   *   A map from the CATPolyBody faces to an integer index.
   */
  ExportedByPolyBodyTools HRESULT CreateFaceToIteratorId (const CATPolyBody& iPolyBody,
                                                          CATMapOfPtrToInt& oFaceToId);

};


namespace Poly
{
  /** @name CATPolyBody Services
   *
   * CATPolyBodyServices.h
   * @{ */

  /** 
   * Sets the point flag on the CATPolyBody (domains of dimension 0)
   * @return 
   *         S_FALSE if the attributes cannot be changed on the CATPolyBody.
   */
  ExportedByPolyBodyTools HRESULT SetPointType(CATPolyBody& iPolyBody);

  /** 
   * Sets the wire flag on the CATPolyBody (domains of dimension 1)
   * @return 
   *         S_FALSE if the attributes cannot be changed on the CATPolyBody.
   */
  ExportedByPolyBodyTools HRESULT SetWireType (CATPolyBody& iPolyBody);

  /** 
   * Sets the skin flag on the CATPolyBody (domains of dimension 2)
   * @return 
   *         S_FALSE if the attributes cannot be changed on the CATPolyBody.
   */
  ExportedByPolyBodyTools HRESULT SetSkinType (CATPolyBody& iPolyBody);

  /** 
   * Sets the solid flag on the CATPolyBody (domains of dimension 3)
   * @return 
   *         S_FALSE if the attributes cannot be changed on the CATPolyBody.
   */
  ExportedByPolyBodyTools HRESULT SetSolidType (CATPolyBody& iPolyBody);

  /**
   * Returns the highest dimension of the cells that can be traversed from the orbit.
   * The highest dimensions that can be traversed can be:
   * 
   *   * For a CATPolyVolumeOrbit
   *   ** 2 for CATPolyFace
   *   ** 1 for CATPolyEdge
   *   ** 0 for CATPolyVertex (orbit referring to just one CATPolyVertex).
   * 
   *   * For a CATPolyFaceOrbit
   *   ** 1 for CATPolyEdge
   *   ** 0 for CATPolyVertex (orbit referring to just one CATPolyVertex).
   *
   *   * For a CATPolyEdgeOrbit
   *   ** 0 for CATPolyVertex.
   */
  ExportedByPolyBodyTools unsigned int GetHighestCellDimension (const CATPolyCellOrbit& orbit);

  /** 
   * Returns whether the body contains at least one cell (be vertex, edge or face)
   */
  ExportedByPolyBodyTools CATBoolean IsEmpty(CATPolyBody * iPolyBody);

  /**
   * Returns whether the body contains at least one volume (not attached to any volume)
   * return false if the body is without volume information.
   */
  ExportedByPolyBodyTools CATBoolean DoesContainVolume(CATPolyBody * iPolyBody);

  /**
   * Returns whether the body contains at least one free face (not attached to any volume)
   * If the body is not with volume information, return true if there is only one face.
   */
  ExportedByPolyBodyTools CATBoolean DoesContainSkin(CATPolyBody * iPolyBody);

  /** 
   * Returns whether the body contains at least one free edge (not attached to any face)
   */
  ExportedByPolyBodyTools CATBoolean DoesContainWire(CATPolyBody * iPolyBody);

  /** 
   * Returns whether the body contains at least one free vertex (not attached to any edge nor face)
   */
  ExportedByPolyBodyTools CATBoolean DoesContainPoint(CATPolyBody * iPolyBody);

  /** 
   * Does nothing if some edges point to the vertex.
   * Detaches the vertex from the faces then deletes it.
   * @return S_OK if the vertex was successfully removed.
   */
  // Revisit to achieve the same behavior as the Delete methods below.
  ExportedByPolyBodyTools HRESULT DeleteVertex (CATPolyBody& ioBody, CATPolyVertex*& iVertexToDelete);

  /** 
   * Detaches the edge from the incident faces then deletes it.
   * @return S_OK if the edge was successfully removed.
   */
  ExportedByPolyBodyTools HRESULT DeleteEdge (CATPolyBody& ioBody, CATPolyEdge*& iEdgeToDelete);

  /** 
   * Detaches the face from the incident volumes then deletes it.
   * @return S_OK if the face was successfully removed.
   */
  ExportedByPolyBodyTools HRESULT DeleteFace (CATPolyBody& ioBody, CATPolyFace*& iFaceToDelete);

  /**
   * Deletes the volume.
   * @return S_OK if the volume was successfully removed.
   */
  ExportedByPolyBodyTools HRESULT DeleteVolume (CATPolyBody& ioBody, CATPolyVolume*& iVolumeToDelete, bool iKeepCellsOfSmallerDimensions = false);

  /**
   * Calls any of DeleteVertex, DeleteEdge, DeleteFace, DeleteVolume.
   * @return S_OK if the cell was successfully removed.
   */
  ExportedByPolyBodyTools HRESULT DeleteCell (CATPolyBody& ioBody, CATPolyCell*& iCellToDelete);

  /**
   * Collapses a face onto an incident edge.
   * The face should have at most two incident edges.
   * The other edge, if any, is deleted as it no longer refers to any geometry.
   * The face is deleted once it is collapsed.
   * @param E
   *   The target edge incident to the face to collapse.
   * @param F
   *   The face to collapse.
   */
  ExportedByPolyBodyTools HRESULT CollapseFace (CATPolyBody& ioBody, CATPolyEdge& E, CATPolyFace*& F);

/** @} */

};


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @see Poly::Stream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyStreamPolyBody (const CATUnicodeString& iFileName,
  const CATPolyBody& iPolyBody, const CATMathTransformation* iPosMatrix,
  CATBoolean iPolyhedralObjectsMode,  // By default: FALSE.
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers |
  CATPolyStreamOptions::eEnableStreamOfBadBody,
  CATPolyStreamRecord* ioStreamRecords = 0);

/**
 * @see Poly::Stream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyStreamPolyBody (CATMathStream& str,
  const CATPolyBody& iPolyBody, const CATMathTransformation* iPosMatrix,
  CATBoolean iPolyhedralObjectsMode,  // By default: FALSE.
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers |
  CATPolyStreamOptions::eEnableStreamOfBadBody,
  CATPolyStreamRecord* ioStreamRecords = 0);

/**
 * @see Poly::Stream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyStreamPolyBody (char*& oBuffer, size_t& oNbBytes,
  const CATPolyBody& iPolyBody, const CATMathTransformation* iPosMatrix,
  CATBoolean iPolyhedralObjectsMode,  // By default: FALSE.
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers |
  CATPolyStreamOptions::eEnableStreamOfBadBody,
  CATPolyStreamRecord* ioStreamRecords = 0);

/**
 * @see Poly::Stream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyStreamPolyBody (const CATUnicodeString& iFileName,
  const CATPolyBody& iPolyBody,
  CATBoolean iPolyhedralObjectsMode = FALSE,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers |
  CATPolyStreamOptions::eEnableStreamOfBadBody,
  CATPolyStreamRecord* ioStreamRecords = 0);

/**
 * @see Poly::Stream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyStreamPolyBody (CATMathStream& str,
  const CATPolyBody& iPolyBody,
  CATBoolean iPolyhedralObjectsMode = FALSE,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers |
  CATPolyStreamOptions::eEnableStreamOfBadBody,
  CATPolyStreamRecord* ioStreamRecords = 0);

/**
 * @see Poly::Unstream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyUnstreamPolyBody (const CATUnicodeString& iFileName,
  CATPolyBody*& oPolyBody, CATMathTransformation*& oPosMatrix,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers,
  CATPolyUnstreamRecord* ioUnstreamRecords = 0);

/**
 * @see Poly::Unstream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyUnstreamPolyBody (CATMathStream& str,
  CATPolyBody*& oPolyBody, CATMathTransformation*& oPosMatrix,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers,
  CATPolyUnstreamRecord* ioUnstreamRecords = 0);

/**
 * @see Poly::Unstream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyUnstreamPolyBody (const char* iBuffer, const size_t iNbBytes,
  CATPolyBody*& oPolyBody, CATMathTransformation*& oPosMatrix,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers,
  CATPolyUnstreamRecord* ioUnstreamRecords = 0);

/**
 * @see Poly::Unstream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyUnstreamPolyBody (const CATUnicodeString& iFileName,
  CATPolyBody*& oPolyBody,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers,
  CATPolyUnstreamRecord* ioUnstreamRecords = 0);

/**
 * @see Poly::Unstream
 * CATPolyStreamServices.h
 */
ExportedByPolyBodyTools HRESULT CATPolyUnstreamPolyBody (CATMathStream& str,
  CATPolyBody*& oPolyBody,
  const unsigned int iLayerFilter = CATPolyStreamOptions::eAllLayers,
  CATPolyUnstreamRecord* ioUnstreamRecords = 0);

/** @} */

/**
 * @nodoc
 */
POLY_DEPRECATED ("Use CATPolyEdge::HasIncidentFaces ();",
ExportedByPolyBodyTools HRESULT CATPolyIsEdgeAdjacentToAnyFace (CATPolyEdge* iEdge));

/**
 * @nodoc
 */
POLY_DEPRECATED ("Use Poly::GetIncidentEdge ()",
inline CATPolyEdge* CATPolyGetAdjacentEdge (const CATPolyVertex* iVertex, const CATPolyEdge* iEdge, const CATPolyFace* iFace))
{
  return (CATPolyEdge*)Poly::GetIncidentEdge (iVertex, iEdge, iFace);
}

/**
 * @nodoc
 */
POLY_DEPRECATED ("Use CATPolyBody::NewNative ();",
ExportedByPolyBodyTools CATPolyBody* CATPolyCreatePolyBodyForNativePolyhedralObjects ();)


inline HRESULT CATPolyGetNbFacets (const CATPolyBody& iPolyBody, int& oNbFacets)
{
  oNbFacets = Poly::GetNbFacets (iPolyBody);
  return S_OK;
}

inline HRESULT CATPolyGetNbSurfaceVertices (const CATPolyBody& iPolyBody, int& oNbSurfaceVertices)
{
  oNbSurfaceVertices = Poly::GetNbSurfaceVertices (iPolyBody);
  return S_OK;
}

inline HRESULT CATPolyGetNbEdgeSegments (const CATPolyBody& iPolyBody, int& oNbEdgeSegments)
{
  oNbEdgeSegments = Poly::GetNbEdgeSegments (iPolyBody);
  return S_OK;
}


ExportedByPolyBodyTools HRESULT CATPolyGetBoundingBox (const CATPolyBody& iPolyBody,
  CATMathBox& ioBox,
  const CATMathTransformation* iPosMatrix = 0);


#endif
