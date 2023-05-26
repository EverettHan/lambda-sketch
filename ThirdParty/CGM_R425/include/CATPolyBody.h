// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//=============================================================================
//
// CATPolyBody
//
//=============================================================================
// 2016-02-03   NDO: AddRef and Release become const methods as they should be.
// 2011-05-04   NDO: Activation AddRef/Release R21 and R212.
// 2009-04-01   NDO: Revisited
// 2007-01-02   BPG: Raise
// 2003-03-20   FDS: New
//=============================================================================
#pragma once

#include "PolyMODEL.h"
#include "CATPolyDartList.h"
#include "CATPolyCellList.h"
#include "CATPolyCellOrbit.h"  // Poly::OrbitQualifier
#include "CATPolyMicroTopologyFwd.h"
#include "CATPolyMacroTopologyFwd.h"
#include "CATErrorDef.h"
#include "CATIAV5Level.h"

#include "CATIPolyPoint.h"  // Useless include here.  Make sure there are no build errors before removing.
#include "CATIPolyCurve.h"  // Useless include here.  Make sure there are no build errors before removing.

template<size_t N> class CATPolyDart;
#ifndef _AIX_SOURCE
using CATPolyDart2 = CATPolyDart<2>;
using CATPolyDart3 = CATPolyDart<3>;
#else
typedef CATPolyDart<2> CATPolyDart2;
typedef CATPolyDart<3> CATPolyDart3;
#endif

class CATIPolyBodyAttributes;
class CATPolyBodyNativeAttributes;
class CATMathBox;
class CATMutex;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Poly 
{
  ExportedByPolyMODEL CATPolyBody* NewEditableBody (const CATPolyBody& iPolyBody);
}
#endif


/**
 * Definition of a polyhedral body.
 * 
 * A CATPolyBody represents a cellular model whose cells refer to discrete geometry, namely,
 * meshes and discrete curves (polylines.)  A polyhedral body has a unique implementation (no interface).
 * 
 * The cells of the CATPolyBody, vertices, edges and faces are defined by the classes:
 * <ul>
 *   <li> CATPolyVertex
 *   <li> CATPolyEdge
 *   <li> CATPolyFace
 * </ul>
 * They all derive from CATPolyCell.
 *
 * To scan the cells from the body, several iterators are defined:
 * <ul>
 *   <li> CATPolyBodyVertexIterator
 *   <li> CATPolyBodyEdgeIterator
 *   <li> CATPolyBodyFaceIterator
 * </ul>
 * Other iterators are defined to navigate through the neighborhoods from a cell.
 *
 * The faces may refer to various types of meshes (heterogeneous model): triangles, quads, polygonal, procedural meshes.
 */
class ExportedByPolyMODEL CATPolyBody
{

public:

/** @name Life Cycle
  @{ */

  /**
   * Creates a new instance of a CATPolyBody. 
   * Instances are ref-counted.  Use the Release () method when done with this CATPolyBody; 
   *
   * @param iWithDefaultAttributes.
   *   If set to true, default attributes (see CATPolyBodyDefaultAttributes) will be added to the CATPolyBody instance.
   *   By default, the CATPolyBody is created without attributes; you must assign it to an instance of CATIPolyBodyAttributes 
   *   to specify the characteristics of the data contained in this body (see the method AbsorbAttributes ()).
   *   The attributes are required by some operators and for streaming.
   * @return
   *   A new CATPolyBody (with or without default attributes depending on the value of the input flag).
   */
  static CATPolyBody* New (bool iWithDefaultAttributes = false);

  /**
   * Creates a native CATPolyBody.
   * A native CATPolyBody refers to polyhedral surfaces, curves and points exclusive to the PolyhedralObjects framework.
   * It cannot refer to any polyhedral objects implemented in another framework.
   * Native polyhedral objects include:
   *   * Surfaces
   *       * CATPolyMeshImpl
   *       * CATPolyCompactMesh
   *       * CATPolyCompactMeshConst
   *       * CATPolyEditableMesh (if the parent mesh is native)
   *       * CATPolySubMesh (if the parent mesh is native)
   *       * CATPolyProxyMesh (if the parent mesh is native)
   *   * Curves
   *       * CATPolyLine
   *       * CATPolyLineConst
   *       * CATPolyMeshCurve
   *       * CATPolyMeshCurveConst
   *       * CATPolySurfaceVertexLine
   *       * CATPolyCompactSurfaceVertexLine
   *       * CATPolyCompactSurfaceVertexLineConst
   *       * CATPolyEditableCurve (if the parent curve is native)
   *       * CATPolyEditableSurfaceVertexLine (if the parent curve is native)
   *   * Points
   *       * CATPolyPoint
   *       * CATPolyPointConst
   *       * CATPolyMeshPoint
   *       * CATPolyMeshPointConst
   *       * CATPolyCurveVertex
   *       * CATPolyCurveVertexConst
   *       * CATPolySurfaceVertex
   *       * CATPolySurfaceVertexConst
   *
   * A native CATPolyBody instance is associated to (and only to) a CATPolyBodyNativeAttributes instance.
   *
   * @return
   *   A native CATPolyBody.
   *   The instance must be released.
   */
  static CATPolyBody* NewNative (bool iWithVolumes = false);

  /**
   * Returns true if the CATPolyBody is native.
   */
  inline bool IsNative () const;

  /**
   * Returns true if the CATPolyBody can accept volume cells.
   */
  inline bool WithVolumes () const;

  /**
   * Absorbs a new set of attributes.
   * After a successful call, the input attributes are owned by this instance;
   * The attributes should no longer be deleted or assigned to another CATPolyBody.
   *
   * The instance of attributes cannot be changed once set.
   */
  HRESULT AbsorbAttributes (CATIPolyBodyAttributes* iAttributes);

  /**
  * Reference counting.
  * Increments the reference counter.
  */
  void AddRef () const;

  /**
  * Reference counting.
  * Decrements the reference counter.  When the counter reaches 0, the instance is deleted.
  */
  void Release () const;

/** @} */

public:

/** @name Vertex
    @{ */

  /**
   * Creates a new vertex in the CATPolyBody without any geometry.
   * @return
   *   A new vertex when succeeding and 0 on failure.
   */
  CATPolyVertex* MakeVertex ();

  /** 
   * Given a CATIPolyPoint, P, creates a new vertex in the CATPolyBody.
   * @param P 
   *   The geometry of the vertex.
   * @return 
   *   A new vertex when succeeding and 0 on failure. 
   */
  inline CATPolyVertex* MakeVertex (CATIPolyPoint& P);

  /**
   * Creates a new vertex in the CATPolyBody out of a vertex-orbit.
   * This new vertex will refer typically to just one vertex-orbit.  
   * (However, it may embark other orbits if they refer to the same geometry or points.)
   * Be aware that the origin vertex to which iVertexOrbit belongs is not deleted.
   * @param iVertexOrbit
   *   The input vertex-orbit.
   * @return
   *   The new vertex constructed from this input vertex-orbit.
   */
  inline CATPolyVertex* MakeVertex (CATPolyVertexOrbit* iVertexOrbit);

  /** 
   * Removes and deletes a vertex. 
   * The vertex can no longer be incident to any edge of face to be removed.
   * See FaceRemoveVertex () to remove the incidence between a face and a vertex.
   * If the vertex is the start or end vertex of a CATPolyEdge, then the method fails.
   * The edges incident to the vertex should be deleted first.
   * @param V
   *   The vertex to be deleted.
   * @return 
   *   On success, returns S_OK and otherwise, an error.
  */
  inline HRESULT DeleteVertex (CATPolyVertex*& V);

  /**
   * Returns the number of CATPolyVertex in the CATPolyBody.
   * @return
   *   The number of vertex cells.
   */
  inline unsigned int GetNbVertices () const;

  /** 
   * Returns a CATPolyVertex.
   * @return 
   *   Returns the CATPolyVertex of index v with v ranging from 1 to GetNbVertices () included. 
   */
  inline CATPolyVertex* GetVertex (int v) const;

/** @} */


public:

/** @name Edge
    @{ */

  /**
    * Creates a new edge in the CATPolyBody without any geometry.
    * @return
    *   A new edge when succeeding and 0 on failure.
    */
  CATPolyEdge* MakeEdge ();

  /**
   * Creates a new edge in the CATPolyBody without any geometry.
   * @param VS
   *   The optional start vertex of the edge.
   * @param VE
   *   The optional end vertex of the edge.
   * @return
   *   The new edge.
   */
  inline CATPolyEdge* MakeEdge (CATPolyVertex* VS, CATPolyVertex* VE);

  /**
   * Given a CATIPolyCurve, C, creates a new edge in the CATPolyBody.
   * @param C
   *   The geometry of the edge.
   * @return
   *   A new edge when succeeding and 0 on failure.
   */
  inline CATPolyEdge* MakeEdge (CATIPolyCurve& C);

  /**
   * Given a CATIPolyCurve, C, and optionally a start and/or an end vertex,
   * creates a new edge in the CATPolyBody.
   * @param C
   *   The geometry of the edge.
   * @param VS
   *   The optional start vertex of the edge.
   * @param VE
   *   The optional end vertex of the edge.
   *
   * @return
   *   The new edge.
   */
  inline CATPolyEdge* MakeEdge (CATIPolyCurve& C, CATPolyVertex* VS, CATPolyVertex* VE);

  /**
   * Creates a new edge in the CATPolyBody out of an edge-orbit.
   * This new edge will refer to just one edge-orbit (manifold edge).
   * This method does not delete the original edge.
   * @param iEdgeOrbit
   *   The input edge-orbit.
   * @return
   *   The new edge constructed from this edge-orbit.
   */
  inline CATPolyEdge* MakeEdge (CATPolyEdgeOrbit* iEdgeOrbit);

  /**
   * Removes and deletes an edge.
   * To be removed, the edge cannot be incident to any face.
   * See FaceRemoveEdge () to remove the incidence between a face and an edge.
   * @param E
   *   The edge to be deleted.
   * @return
   *   On success, returns S_OK and otherwise, an error.
  */
  inline HRESULT DeleteEdge (CATPolyEdge*& E);

  /**
   * Returns the number of CATPolyEdge in the CATPolyBody.
   * @return
   *   The number of edge cells.
   */
  inline unsigned int GetNbEdges () const;

  /**
   * Returns a CATPolyEdge.
   * @return
   *   Returns the CATPolyEdge of index e with e ranging from 1 to GetNbEdges () included.
   */
  inline CATPolyEdge* GetEdge (int e) const;

/** @} */

public:

/** @name Face
    @{ */

  /** 
   * Given a CATIPolySurface, S, creates a new face in the CATPolyBody.
   * A CATPolyFace is associated to one and only one CATIPolySurface.
   * @param p 
   *   The surface that is associated to the vertex.
   * @return 
   *   A new face when succeeding and 0 on failure (e.g. not enough memory). 
   */
  CATPolyFace* MakeFace (CATIPolySurface& S);

  /** 
   * Removes and deletes a face.  
   *
   * The suppression of a face does not get rid of vertices and edges supported by the
   * CATIPolySurface associated to the face.  These must be detached explicitely.  For instance, 
   * assume that CATPolyFace, F, is incident to a CATPolyEdge, E.  This edge, E, references a
   * CATIPolyCurve, C, that references the CATIPolySurface, S.  Before suppression of F, the 
   * surface S is referenced by F and C.  Suppression of F removes its reference to S but not 
   * that of the curve C.  The surface S is not deleted because there remains at least one reference.
   * 
   * @param F
   *   The face to be deleted.
   * @return 
   *   On success, returns S_OK and otherwise, an error.
  */
  inline HRESULT DeleteFace (CATPolyFace*& F);

  /**
   * Returns the number of CATPolyFace in the CATPolyBody.
   * @return
   *   The number of face cells.
   */
  inline unsigned int GetNbFaces () const;

  /**
   * Returns a CATPolyFace.
   * @return
   *   Returns the CATPolyFace of index f with f ranging from 1 to GetNbFaces () included.
   */
  inline CATPolyFace* GetFace (int f) const;

  /**
   * Adds an incidence between a face and an edge using a surface-vertex line as the geometry.
   * The surface-vertex line must lie on the surface referenced by the face.
   * @return
   *   Returns S_OK on success.
   */
  HRESULT FaceAddEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL, Poly::OrbitQualifier iQualifier = Poly::NoQualifier);

  /**
   * Removes the incidence between a face and an edge.
   * The face must be incident to the edge.  The method does not delete the edge.
   * @return
   *   Returns S_OK on success.
   */
  inline HRESULT FaceRemoveEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL);

  /**
   * Adds an incidence between a face and a full vertex using a surface-vertex as geometry.
   * The point must lie on the surface referenced by the face.
   * @return
   *   Returns S_OK on success.
   */
  inline HRESULT FaceAddVertex (CATPolyFace& F, CATPolyVertex& V, CATIPolySurfaceVertex& P);

  /**
   * Removes the incidence between face and a full vertex.
   * The face must be incident to the vertex.  The method does not delete the vertex.
   * @return
   *   Returns S_OK on success.
   */
  inline HRESULT FaceRemoveVertex (CATPolyFace& F, CATPolyVertex& V, CATIPolySurfaceVertex& P);

  /**
   * Sew two faces along an edge (applicable to non-manifold edges).
   * The faces are identified by the two input surface-vertex lines.
   * The two faces should be incident to the same edge but not sewn together.
   * The method returns S_OK if sewn and S_FALSE if it cannot be done (faces already sewn for example).
   */
  HRESULT FaceSew (CATPolyEdge& E, CATIPolySurfaceVertexLine* SVL1, CATIPolySurfaceVertexLine* SVL2);

  /**
   * Unsew two faces along an edge.
   * The faces are identified by the input surface-vertex line.
   * The two faces should be incident to the same edge and sewn together.
   * The method returns S_OK if unsewn and S_FALSE if it cannot be done (faces not sewn for example).
   */
  HRESULT FaceUnsew (CATPolyEdge& E, CATIPolySurfaceVertexLine* SVL1, CATIPolySurfaceVertexLine*& SVL2);

  /** @} */

public:

/** @name Volume
    @{ */

  CATPolyVolume* MakeVolume ();

  /**
   * Deletes a volume.
   * 
   * @param VLM
   *   The face to be deleted.
   * @return
   *   On success, returns S_OK and otherwise, an error.
   */
  HRESULT DeleteVolume (CATPolyVolume*& VLM);

  /**
   * Returns the number of CATPolyVolume in the CATPolyBody.
   * @return
   *   The number of volume cells.
   */
  inline unsigned int GetNbVolumes () const;

  /**
   * Returns a CATPolyVolume.
   * @return
   *   Returns the CATPolyVolume of index v with v ranging from 1 to GetNbVolumes () included.
   */
  inline CATPolyVolume* GetVolume (int v) const;

  /**
   * @param orientation
   * Relative orientation of the face w.r.t. the volume:
   *   * +1: Face has positive orientation in the volume.
   *   *  0: Face has null orientation in volume (case of a full face).
   *   * -1: Face has negative orientation in the volume.
   */
  HRESULT VolumeAddFace (CATPolyVolume& iVolume, CATPolyFace& iFace, int orientation, Poly::OrbitQualifier iQualifier = Poly::NoQualifier);

  /**
   * Removes the incidence between a volume and a face.
   * The method does not delete the face.
   * @return
   *   Returns S_OK on success.
   */
  HRESULT VolumeRemoveFace (CATPolyVolume& iVolume, CATPolyFace& iFace);

  /**
   * Adds an incidence between a volume and a full edge.
   * @return
   *   Returns S_OK on success.
   */
  HRESULT VolumeAddEdge (CATPolyVolume& iVolume, CATPolyEdge& iEdge, CATIPolyCurve& C);

  /**
   * Removes the incidence between a volume and a full edge.
   * The method does not delete the edge.
   * @return
   *   Returns S_OK on success.
   */
  HRESULT VolumeRemoveEdge (CATPolyVolume& iVolume, CATPolyEdge& iEdge, CATIPolyCurve& C);

  /**
   * Adds an incidence between a volume and a full vertex.
   * @return
   *   Returns S_OK on success.
   */
  HRESULT VolumeAddVertex (CATPolyVolume& iVolume, CATPolyVertex& iVertex, CATIPolyPoint& P);

  /**
   * Removes the incidence between a volume and a full vertex.
   * The method does not delete the vertex.
   * @return
   *   Returns S_OK on success.
   */
  HRESULT VolumeRemoveVertex (CATPolyVolume& iVolume, CATPolyVertex& iVertex, CATIPolyPoint& P);

  /** @} */

public:

  template<class CELL>
  inline CELL* Make ();

public:

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/** @name Other cell methods
    @{ */

  /**
   * Given a CATIPolyCurve, C, and two CATPolyVertex, V0 and V1, defining the extremities
   * creates a new edge in the CATPolyBody.
   * A CATPolyEdge is associated to at least one CATIPolyCurve.
   * @param V0
   *   The start vertex of the edge.
   * @param V1
   *   The end vertex of the edge.
   * @param C
   *   The curve that is associated to the edge.
   *
   * @return
   *   The new edge.
   */
  inline CATPolyEdge* MakeEdge (CATPolyVertex& V0, CATPolyVertex& V1, CATIPolyCurve& C);

  /**
   * Given a CATIPolyCurve, C, and two CATPolyVertex defining the end and the start, StartVertex and EndVertex,
   * creates a new edge.
   * @param StartVertex
   *   The start vertex of the edge.
   * @param PreviousEdge
   *   If different from the NULL pointer, the edge to which the new edge will be linked at StartVertex.
   * @param EndVertex
   *   The end vertex of the edge.
   * @param NextEdge
   *   If different from the NULL pointer, the edge to which the new edge will be linked at EndVertex.
   * @return
   *   A new edge when succeeding and 0 on failure (e.g. not enough memory).
   */
  inline CATPolyEdge* MakeEdge (CATPolyVertex& StartVertex, CATPolyEdge* PreviousEdge,
    CATPolyVertex& EndVertex, CATPolyEdge* NextEdge,
    CATIPolyCurve& C);

  /**
   * Add a face adjacency information around an edge.
   * Both faces must have no adjacency information yet, otherwise the operation does nothing.
   * @param face0
   *   the first face
   * @param face1
   *   the second face
   * @param edge
   *   the edge to add the adjacency
   * @return
   *   On success, returns S_OK, S_FALSE if the adjacency couldn't be performed, E_FAIL otherwise.
  */
  inline HRESULT AddFacesAdjacency (CATPolyFace& face0,
    CATPolyFace& face1,
    CATPolyEdge& edge);

  /**
   * Given a CATIPolySurfaceVertex, P, (a CATIPolyPoint referencing a vertex of a CATIPolySurface),
   * creates a new vertex.  This new vertex is incident to the CATPolyFace.
   * (To remove and delete the CATPolyVertex, use DeleteVertex ().)
   * @param F
   *   The CATPolyFace to which the new vertex is incident.
   * @param P
   *   The CATIPolySurface vertex associated to the new vertex.
   * @return
   *   A new vertex when succeeding and 0 on failure (e.g. not enough memory).
   *   The method will fail if F and P refers to different CATIPolySurface's.
   */
  inline CATPolyVertex* MakeFaceVertex (CATPolyFace& F, CATIPolySurfaceVertex& P);

  /**
   * Removes the incidence between a CATPolyFace, F, and a CATPolyVertex, V
   * and deletes the vertex.  The vertex should not be incident to any other face.
   * This method is equivalent to a FaceRemoveVertex () followed by a DeleteVertex ().
   * @return
   *   On success, returns S_OK and otherwise, an error.
   */
  HRESULT DeleteFaceVertex (CATPolyFace& F, CATPolyVertex*& V, CATIPolySurfaceVertex& P);

  /**
   * Given a CATIPolySurfaceVertexLine, SVL, and two CATPolyVertex defining the end and the start, VS and VE,
   * creates a new edge. The new edge is incident to the CATPolyFace.
   * (To remove and delete the CATPolyEdge, use DeleteEdge ().)
   * @param F
   *   The CATPolyFace to which the new edge is incident.
   * @param VS
   *   The start vertex of the edge.
   * @param VE
   *   The end vertex of the edge.
   * @param SVL
   *   The CATIPolySurface curve that is associated to the edge.
   * @return
   *   A new edge when succeeding and 0 on failure (e.g. not enough memory).
   *   The method will fail if F and C refers to different CATIPolySurface's.
   */
  inline CATPolyEdge* MakeFaceEdge (CATPolyFace& F, CATPolyVertex& VS, CATPolyVertex& VE, CATIPolySurfaceVertexLine& SVL);

  /**
   * Given a CATIPolySurfaceVertexLine, SVL, and two CATPolyVertex defining the end and the start, StartVertex and EndVertex,
   * creates a new edge. The new edge is incident to the CATPolyFace.
   * (To remove and delete the CATPolyEdge, use DeleteEdge ().)
   * @param F
   *   The CATPolyFace to which the new edge is incident.
   * @param StartVertex
   *   The start vertex of the edge.
   * @param PreviousEdge
   *   If different from the NULL pointer, the edge to which the new edge will be linked at StartVertex.
   * @param EndVertex
   *   The end vertex of the edge.
   * @param NextEdge
   *   If different from the NULL pointer, the edge to which the new edge will be linked at EndVertex.
   * @param SVL
   *   The CATIPolySurface curve that is associated to the edge.
   * @return
   *   A new edge when succeeding and 0 on failure (e.g. not enough memory).
   *   The method will fail if F and C refers to different CATIPolySurface's.
   */
  inline CATPolyEdge* MakeFaceEdge (CATPolyFace& F,
    CATPolyVertex& StartVertex, CATPolyEdge* PreviousEdge,
    CATPolyVertex& EndVertex, CATPolyEdge* NextEdge,
    CATIPolySurfaceVertexLine& SVL);

  /**
   * Removes the incidence between a CATPolyFace, F, and a CATPolyEdge, E
   * and deletes the edge.  The edge should not be incident to any other face.
   * This method is equivalent to a FaceRemoveEdge () followed by a DeleteEdge ().
   * @return
   *   On success, returns S_OK and otherwise, an error.
   */
  HRESULT DeleteFaceEdge (CATPolyFace& F, CATPolyEdge*& E, CATIPolySurfaceVertexLine& SVL);

  /**
   * Adds an incidence between a CATPolyFace, F, and a CATPolyEdge, E, using
   * the CATIPolySurfaceVertexLine, SVL, as micro-topology.  The curve, SVL, must lie on the same
   * CATIPolySurface as the surface associated to F.
   * @param F
   *   The CATPolyFace to which the edge becomes incident.
   * @param E
   *   The CATPolyEdge that becomes incident to the face.
   * @param SVL
   *   The curve added to the edge definition.  This curve is defined as a sequence of vertices on the CATIPolySurface.
   * @param iFaceSewing
   *   An optional flag, set by default to true, to specify whether to attempt the sewing of two incident faces
   *   across a manifold edge.  If the flag is set to false, faces incident to the same edge will not be sewn.
   * @return
   *   On success, returns <tt>S_OK</tt> and otherwise, an error.
   */
  HRESULT FaceAddEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL, bool iFaceSewing);

  /**
   * Adds an incidence between a CATPolyFace, F, and a CATPolyEdge, E, using
   * the CATIPolySurfaceVertexLine, SVL, as micro-topology.  The curve, SVL, must lie on the same
   * CATIPolySurface as the surface associated to F.
   *
   * This method will fail in the creation of non-manifold edges.  See method below for the creation
   * of non-manifold edges.
   *
   * @param F
   *   The CATPolyFace to which the edge becomes incident.
   * @param iPreviousEdge
   *   If different from the NULL pointer, the edge to which the edge <tt>E</tt> will be linked at its start vertex.
   *   This previous edge must be incident to the face <tt>F</tt>
   * @param E
   *   The CATPolyEdge that becomes incident to the face.
   * @param iNextEdge
   *   If different from the NULL pointer, the edge to which the edge <tt>E</tt> will be linked at its end vertex.
   *   This next edge must be incident to the face <tt>F</tt>
   * @param SVL
   *   The curve added to the edge definition.  This curve is defined as sequence of vertices on the CATIPolySurface.
   * @return
   *   On success, returns <tt>S_OK</tt> and otherwise, an error.
   */
  inline HRESULT FaceAddEdge (CATPolyFace& F,
    CATPolyEdge* iPreviousEdge, CATPolyEdge& E, CATPolyEdge* iNextEdge,
    CATIPolySurfaceVertexLine& SVL);

  /**
   * Adds an incidence between a CATPolyFace, F, and a CATPolyEdge, E, using
   * the CATIPolySurfaceVertexLine, SVL, as micro-topology.  The curve, SVL, must lie on the same
   * CATIPolySurface as the surface associated to F.
   *
   * Calling this method may result in the creation of non-manifold edges.  A manifold edge can be incident
   * to two faces at most.
   *
   * @param F
   *   The CATPolyFace to which the edge becomes incident.
   * @param iPreviousEdge
   *   If different from the NULL pointer, the edge to which the edge <tt>E</tt> will be linked at its start vertex.
   *   This previous edge must be incident to the face <tt>F</tt>
   * @param E
   *   The CATPolyEdge that becomes incident to the face.
   * @param iNextEdge
   *   If different from the NULL pointer, the edge to which the edge <tt>E</tt> will be linked at its end vertex.
   *   This next edge must be incident to the face <tt>F</tt>
   * @param SVL
   *   The curve added to the edge definition.  This curve is defined as sequence of vertices on the CATIPolySurface.
   * @param iAdjacentFace
   *   The face becoming adjacent via a manifold-edge.  Without an adjacent face specified, this method will result in
   *   the creation of a new manifold-edge bound to the input edge.
   * @return
   *   On success, returns <tt>S_OK</tt> and otherwise, an error.
   */
  inline HRESULT FaceAddEdge (CATPolyFace& F,
    CATPolyEdge* iPreviousEdge, CATPolyEdge& E, CATPolyEdge* iNextEdge,
    CATIPolySurfaceVertexLine& SVL, CATPolyFace* iAdjacentFace);

  /**
   * @param orientation
   * Relative orientation of the edge w.r.t. the face:
   *   * +1: Edge has positive orientation in the face.
   *   *  0: Edge has null orientation in face (case of a full edge).
   *   * -1: Edge has negative orientation in the face.
   */
   //inline HRESULT FaceAddEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL, int orientation, Poly::OrbitQualifier iQualifier = Poly::NoQualifier);

  // Do not call this method; the correct method is MakeFaceEdge ().
  inline CATPolyEdge* BadCallToMakeFaceEdge (CATPolyFace& F, CATPolyVertex& VS, CATPolyVertex& VE, CATIPolySurfaceVertexLine& SVL);

  // Do not call this method; the correct method is FaceAddEdge ().
  inline HRESULT BadCallToFaceAddEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL);

/** @} */
#endif

public:

/** @name Topological Edition
    @{ */

  /**
   * Merge two vertices (V0 absorb V1)
   * If it exist, the edge between the two vertices will be removed
   * V1 is not removed but will no longer be incident
   * to any cell and should be deleted explicitely
   * @param V0
   *   The target vertex 
   * @param V1
   *   The vertex absorbed by V0
   */
  HRESULT MergeVertices (CATPolyVertex *& V0, CATPolyVertex *& V1);

  /**
   * Collapses an edge into a vertex (start or end vertex of the edge.)
   * The edge is deleted during the collapse.  
   * The other vertex is not deleted; however it will no longer be incident 
   * to any cell and should be deleted explicitely.
   * @param V
   *   The target vertex which must be incident to the edge.
   * @param E
   *   The edge to collapse.
   */
  HRESULT CollapseEdge (CATPolyVertex* V, CATPolyEdge*& E);

  /**
   * Collapses a face onto an incident edge.
   * The face should have at most two incident edge.
   * The other edge, if it exist, is not deleted; however it will no longer be incident
   * to any cell and should be deleted explicitely.
   * If no edge to keep is provided, the face must not have any incident edge (return E_FAIL in this case).
   * 
   * The face is deleted during the collapse.
   * @param E
   *   The target edge which must be incident to the face.
   * @param F
   *   The face to collapse.
   */
  inline HRESULT CollapseFace (CATPolyEdge* E, CATPolyFace*& F);

  /**
   * Splits an edge given a curve vertex.
   * @param E
   *   The input edge which will be split.  
   *   This edge is deleted during the split.
   * @param cv
   *   The curve vertex where the edge will be split.
   * @param V
   *   The output vertex created during the split.
   * @param E1
   *   The first half of the edge created during the split.
   * @param E2
   *   The second half of the edge created during the split.
   */
  inline HRESULT SplitEdge (CATPolyEdge*& E, int cv, CATPolyVertex*& V, CATPolyEdge*& E1, CATPolyEdge*& E2);

  /**
   * Substitutes a surface-vertex line from an edge by another.
   */
  inline HRESULT Substitute (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& svlOut, CATIPolySurfaceVertexLine& svlIn);

/** @} */


public:

/** @name Attributes
    @{ */

  /**
   * Returns the attributes of the CATPolyBody.
   * The object returned is owned by the CATPolyBody and should not be deleted.
   */
  inline const CATIPolyBodyAttributes* GetAttributes () const;

  /**
   * Returns the attributes of the CATPolyBody.
   * The object returned is owned by the CATPolyBody and should not be deleted.
   */
  inline CATIPolyBodyAttributes* GetAttributes ();

  /**
   * Returns the native CATPolyBody attributes if it is native.
   * Otherwise returns 0.
   */
  const CATPolyBodyNativeAttributes* GetNativeAttributes () const;

  /**
   * Returns the native CATPolyBody attributes if it is native.
   * Otherwise returns 0.
   */
  CATPolyBodyNativeAttributes* GetNativeAttributes ();

  /**
   * Returns the number of cells in the CATPolyBody.
   */
  inline unsigned int GetNbCells () const;

  /**
   * Returns the size in bytes of the CATPolyBody.
   * The size includes the size of all polyhedral objects and cache currently in memory and 
   * on which the CATPolyBody depends.  It does not however include the size of the external (non-polyhedral) objects 
   * such as for instance a CATRep or a CATBody associated to the CATPolyBody.
   */
  unsigned int SizeOf () const;

/** @} */

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:

  CATPolyDartList _Darts;
  CATPolyVertexList _Vertices;
  CATPolyEdgeList _Edges;
  CATPolyFaceList _Faces;
  CATPolyVolumeList* _Volumes;

  CATIPolyBodyAttributes* _Attributes;
  void* _UnusedDart;  // Recycling.

private:

  unsigned int _NextCellTag;
  mutable unsigned int _Ref;

  static CATMutex& GetRefCountedMutex ();

  template<class DART> friend class CATPolyBodyDartIterator;
  friend class CATPolyDartHelpers;
  friend class CATPolyBodyHelpers;
  friend class CATPolyBodyTopologyStreamer;
  friend class CATPolyBodyTopologyUnstreamer;
  friend CATPolyBody* Poly::NewEditableBody (const CATPolyBody& iPolyBody);

public:

  /**
   * @nodoc
   * To create an instance of a CATPolyBody, use CATPolyBody::New ().
   */
  CATPolyBody(bool iWithVolumes=false);

  /**
   * @nodoc
   */
  HRESULT GetAttributes (CATIPolyBodyAttributes*& oAttributes) const;

private:

  ~CATPolyBody (); // DO NOT VIRTUALIZE

  inline unsigned int GetCellTag () const;  // Reserved for CATPolyBodyTopologyStreamer.
  inline void SetCellTag (unsigned int tag);  // Reserved for CATPolyBodyTopologyUnstreamer.

  template<class DART>
  void PushToRecycling (DART*& d);

  template<class DART>
  DART* PopFromRecycling ();

  template<class DART>
  DART* NewDart ();

  template<class DART>
  DART* NewDart (CATIPolyPoint& p);

  template<class DART>
  HRESULT DeleteDart (DART*& ioDart);

  template<class DART>
  HRESULT RemoveOrbitsDeleteDart (DART*& d);

  template<class DART>
  CATPolyVertex* MakeVertexP (CATIPolyPoint& P);

  template<class DART>
  CATPolyVertex* MakeVertexP (CATPolyVertexOrbit* iVertexOrbit);

  // Removes the pseudo-manifold vertex and deletes its dart.
  template<class DART>
  HRESULT DeletePseudoManifoldVertex (CATPolyVertex& V, DART*& d);

  template<class DART>
  HRESULT DeleteVertexP (CATPolyVertex*& V);

  template<class DART>
  CATPolyEdge* MakeEdgeP (CATPolyVertex* VS, CATPolyVertex* VE);

  template<class DART>
  CATPolyEdge* MakeEdgeP (CATIPolyCurve& C, CATPolyVertex* VS, CATPolyVertex* VE);

  template<class DART>
  CATPolyEdge* MakeEdgeP (CATPolyVertex& StartVertex, CATPolyEdge* PreviousEdge,
    CATPolyVertex& EndVertex, CATPolyEdge* NextEdge,
    CATIPolyCurve& C);

  template<class DART>
  CATPolyEdge* MakeEdgeP (CATPolyEdgeOrbit* iEdgeOrbit);

  // Case of a dart which is neither a start or end dart.
  template<class DART>
  CATPolyEdge* MakeEdgeP (CATIPolyCurve& C, DART& d);

  template<class DART>
  CATPolyEdge* MakeEdgeP (CATIPolyCurve& C, DART* ds, DART* de);

  // Removes the manifold edge and deletes its darts.
  template<class DART>
  HRESULT DeleteManifoldEdge (CATPolyEdge& E, DART*& d0, DART*& d1);

  template<class DART>
  HRESULT DeleteEdgeP (CATPolyEdge*& E);

  template<class DART>
  HRESULT FaceAddEdgeP (CATPolyFace& F,
                        CATPolyEdge* iPreviousEdge, CATPolyEdge& E, CATPolyEdge* iNextEdge,
                        CATIPolySurfaceVertexLine& SVL, CATPolyFace** iAdjacentFace);

  template<class DART>
  HRESULT FaceAddEdgeP (CATPolyFace& F,
                        CATPolyEdge* iPreviousEdge, CATPolyEdge& E, CATPolyEdge* iNextEdge,
                        CATPolyVertex * v0, CATPolyVertex * v1,
                        CATIPolySurfaceVertexLine& SVL, CATPolyFace** iAdjacentFace);

  template<class DART>
  HRESULT FaceRemoveEdgeP (CATPolyFace& F, CATPolyEdge& E, DART*& d);

  template<class DART>
  HRESULT DeleteFaceP (CATPolyFace*& F);

  template<class DART>
  CATPolyVertex* MakeFaceVertexP (CATPolyFace& F, CATIPolySurfaceVertex& P);

  // To get rid of.  Replaced by MakeFaceEdgeV2.
  template<class DART>
  CATPolyEdge* MakeFaceEdgeV1 (CATPolyFace& F, CATPolyVertex& VS, CATPolyVertex& VE, CATIPolySurfaceVertexLine& SVL);

  template<class DART>
  CATPolyEdge* MakeFaceEdgeV2 (CATPolyFace& F, CATPolyVertex& VS, CATPolyVertex& VE, CATIPolySurfaceVertexLine& SVL);

  template<class DART>
  CATPolyEdge* MakeFaceEdgeP (CATPolyFace& F, CATPolyVertex& VS, CATPolyEdge* EP, CATPolyVertex& VE, CATPolyEdge* EN, CATIPolySurfaceVertexLine& SVL);

  template<class DART>
  HRESULT FaceAddVertexV2 (CATPolyFace& F, CATPolyVertex& V, CATIPolySurfaceVertex& P);

  template<class DART>
  HRESULT FaceRemoveVertexP (CATPolyFace& F, CATPolyVertex& V, DART*& d);

  template<class DART>
  HRESULT FaceRemoveVertexP (CATPolyFace& F, CATPolyVertex& V, CATIPolySurfaceVertex& P);

  // To get rid of.  Replaced by FaceAddEdgeV2.
  template<class DART>
  HRESULT FaceAddEdgeV1 (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL, 
    int orientation, Poly::OrbitQualifier iQualifier, bool iFaceSewing);

  template<class DART>
  HRESULT FaceAddEdgeV2 (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL,
    int orientation, Poly::OrbitQualifier iQualifier, bool iFaceSewing);

  template<class DART>
  HRESULT FaceRemoveEdgeP (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL);

  template<class DART>
  HRESULT CollapseFaceP (CATPolyEdge* E, CATPolyFace*& F);

  template<class DART>
  HRESULT MergeGeometry (CATPolyVertex& V0, CATPolyVertex& V1);

  template<class DART>
  HRESULT AddFacesAdjacencyP (CATPolyFace& face0,
    CATPolyFace& face1,
    CATPolyEdge& edge);

  template<class DART>
  HRESULT UpdateTopology (DART* d1a1,
    CATPolyFace* F,
    CATPolyVertex* V0,
    CATPolyVertex* V1,
    CATIPolyPoint* P0,
    CATIPolyPoint* P1,
    int sv0,
    int sv1,
    void* pMapFaceToSV);

  template<class DART>
  HRESULT MergeVerticesP (CATPolyVertex *& V0, CATPolyVertex *& V1, CATPolyEdge *& E);

  template<class DART>
  HRESULT SplitEdgeP (CATPolyEdge*& E, int cv, CATPolyVertex*& V, CATPolyEdge*& E1, CATPolyEdge*& E2);

  template<class DART>
  HRESULT SubstituteP (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& svlOut, CATIPolySurfaceVertexLine& svlIn);

#endif

};

inline unsigned int CATPolyBody::GetCellTag () const
{
  return _NextCellTag;
}

inline void CATPolyBody::SetCellTag (unsigned int tag)
{
  _NextCellTag = tag;
}

inline bool CATPolyBody::IsNative () const
{
  return GetNativeAttributes () != 0;
}

inline bool CATPolyBody::WithVolumes () const
{
  return _Volumes != 0;
}

inline const CATIPolyBodyAttributes* CATPolyBody::GetAttributes () const
{
  return _Attributes;
}

inline CATIPolyBodyAttributes* CATPolyBody::GetAttributes ()
{
  return _Attributes;
}

inline unsigned int CATPolyBody::GetNbVertices () const
{
  return _Vertices.Size ();
}

inline unsigned int CATPolyBody::GetNbEdges () const
{
  return _Edges.Size ();
}

inline unsigned int CATPolyBody::GetNbFaces () const
{
  return _Faces.Size ();
}

inline unsigned int CATPolyBody::GetNbVolumes () const
{
  return _Volumes ? _Volumes->Size () : 0;
}

inline unsigned int CATPolyBody::GetNbCells () const
{
  return GetNbVertices () + GetNbEdges () + GetNbFaces () + GetNbVolumes ();
}

inline CATPolyVertex* CATPolyBody::GetVertex (int v) const
{
  return v <= _Vertices.Size () ? _Vertices[v] : 0;
}

inline CATPolyEdge* CATPolyBody::GetEdge (int e) const
{
  return e <= _Edges.Size () ? _Edges[e] : 0;
}

inline CATPolyFace* CATPolyBody::GetFace (int f) const
{
  return f <= _Faces.Size () ? _Faces[f] : 0;
}

inline CATPolyVolume* CATPolyBody::GetVolume (int v) const
{
  return _Volumes && v <= _Volumes->Size () ? (*_Volumes)[v] : 0;
}

inline CATPolyVertex* CATPolyBody::MakeVertex (CATIPolyPoint& P)
{
  return !WithVolumes () ? MakeVertexP<CATPolyDart2> (P) : MakeVertexP<CATPolyDart3> (P);
}

inline CATPolyVertex* CATPolyBody::MakeVertex (CATPolyVertexOrbit* iVertexOrbit)
{
  return !WithVolumes () ? MakeVertexP<CATPolyDart2> (iVertexOrbit) : MakeVertexP<CATPolyDart3> (iVertexOrbit);
}

inline HRESULT CATPolyBody::DeleteVertex (CATPolyVertex*& V)
{
  return !WithVolumes () ? DeleteVertexP<CATPolyDart2> (V) : DeleteVertexP<CATPolyDart3> (V);
}

inline CATPolyEdge* CATPolyBody::MakeEdge (CATPolyVertex* VS, CATPolyVertex* VE)
{
  return !WithVolumes () ? MakeEdgeP<CATPolyDart2> (VS, VE) : MakeEdgeP<CATPolyDart3> (VS, VE);
}

inline CATPolyEdge* CATPolyBody::MakeEdge (CATIPolyCurve& C, CATPolyVertex* VS, CATPolyVertex* VE)
{
  return !WithVolumes () ? MakeEdgeP<CATPolyDart2> (C, VS, VE) : MakeEdgeP<CATPolyDart3> (C, VS, VE);
}

inline CATPolyEdge* CATPolyBody::MakeEdge (CATPolyVertex& VS, CATPolyVertex& VE, CATIPolyCurve& C)
{
  return !WithVolumes () ? MakeEdgeP<CATPolyDart2> (C, &VS, &VE) : MakeEdgeP<CATPolyDart3> (C, &VS, &VE);
}

inline CATPolyEdge* CATPolyBody::MakeEdge (CATIPolyCurve& C)
{
  return !WithVolumes () ? MakeEdgeP<CATPolyDart2> (C, 0, 0) : MakeEdgeP<CATPolyDart3> (C, 0, 0);
}

inline CATPolyEdge* CATPolyBody::MakeEdge (CATPolyVertex& StartVertex, CATPolyEdge* PreviousEdge,
  CATPolyVertex& EndVertex, CATPolyEdge* NextEdge,
  CATIPolyCurve& C)
{
  return !WithVolumes () ? MakeEdgeP<CATPolyDart2> (StartVertex, PreviousEdge, EndVertex, NextEdge, C) : 
                           MakeEdgeP<CATPolyDart3> (StartVertex, PreviousEdge, EndVertex, NextEdge, C);
}

inline CATPolyEdge* CATPolyBody::MakeEdge (CATPolyEdgeOrbit* iEdgeOrbit)
{
  return !WithVolumes () ? MakeEdgeP<CATPolyDart2> (iEdgeOrbit) : MakeEdgeP<CATPolyDart3> (iEdgeOrbit);
}

inline HRESULT CATPolyBody::DeleteEdge (CATPolyEdge*& E)
{
  return !WithVolumes () ? DeleteEdgeP<CATPolyDart2> (E) : DeleteEdgeP<CATPolyDart3> (E);
}

inline HRESULT CATPolyBody::DeleteFace (CATPolyFace*& F)
{
  return !WithVolumes () ? DeleteFaceP<CATPolyDart2> (F) : DeleteFaceP<CATPolyDart3> (F);
}

inline CATPolyVertex* CATPolyBody::MakeFaceVertex (CATPolyFace& F, CATIPolySurfaceVertex& P)
{
  return !WithVolumes () ? MakeFaceVertexP<CATPolyDart2> (F, P) : MakeFaceVertexP<CATPolyDart3> (F, P);
}

inline CATPolyEdge* CATPolyBody::MakeFaceEdge (CATPolyFace& F, CATPolyVertex& VS, CATPolyVertex& VE, CATIPolySurfaceVertexLine& SVL)
{
  return !WithVolumes () ? 
    MakeFaceEdgeV2<CATPolyDart2> (F, VS, VE, SVL) : MakeFaceEdgeV2<CATPolyDart3> (F, VS, VE, SVL);
}

inline CATPolyEdge* CATPolyBody::BadCallToMakeFaceEdge (CATPolyFace& F, CATPolyVertex& VS, CATPolyVertex& VE, CATIPolySurfaceVertexLine& SVL)
{
  return !WithVolumes () ?
    MakeFaceEdgeV1<CATPolyDart2> (F, VS, VE, SVL) :  // Version V1 is obsolete.
    0;
}

CATPolyEdge* CATPolyBody::MakeFaceEdge (CATPolyFace& F, CATPolyVertex& VS, CATPolyEdge* EP, CATPolyVertex& VE, CATPolyEdge* EN, CATIPolySurfaceVertexLine& SVL)
{
  return !WithVolumes () ?
    MakeFaceEdgeP<CATPolyDart2> (F, VS, EP, VE, EN, SVL) : 
    MakeFaceEdgeP<CATPolyDart3> (F, VS, EP, VE, EN, SVL);
}

inline HRESULT CATPolyBody::FaceAddVertex (CATPolyFace& F, CATPolyVertex& V, CATIPolySurfaceVertex& P)
{
  return !WithVolumes () ? FaceAddVertexV2<CATPolyDart2> (F, V, P) : FaceAddVertexV2<CATPolyDart3> (F, V, P);
}

inline HRESULT CATPolyBody::FaceRemoveVertex (CATPolyFace& F, CATPolyVertex& V, CATIPolySurfaceVertex& P)
{
  return !WithVolumes () ? FaceRemoveVertexP<CATPolyDart2> (F, V, P) : FaceRemoveVertexP<CATPolyDart3> (F, V, P);
}

inline HRESULT CATPolyBody::FaceAddEdge (CATPolyFace& F,
  CATPolyEdge* iPreviousEdge, CATPolyEdge& E, CATPolyEdge* iNextEdge,
  CATIPolySurfaceVertexLine& SVL)
{
  return !WithVolumes () ?
    FaceAddEdgeP<CATPolyDart2> (F, iPreviousEdge, E, iNextEdge, SVL, 0) :
    FaceAddEdgeP<CATPolyDart3> (F, iPreviousEdge, E, iNextEdge, SVL, 0);
}

inline HRESULT CATPolyBody::FaceAddEdge (CATPolyFace& F,
  CATPolyEdge* iPreviousEdge, CATPolyEdge& E, CATPolyEdge* iNextEdge,
  CATIPolySurfaceVertexLine& SVL, CATPolyFace* iAdjacentFace)
{
  return !WithVolumes () ?
    FaceAddEdgeP<CATPolyDart2> (F, iPreviousEdge, E, iNextEdge, SVL, &iAdjacentFace) :
    FaceAddEdgeP<CATPolyDart3> (F, iPreviousEdge, E, iNextEdge, SVL, &iAdjacentFace);
}

inline HRESULT CATPolyBody::BadCallToFaceAddEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL)
{
  return !WithVolumes () ?
    FaceAddEdgeV1<CATPolyDart2> (F, E, SVL, -2, Poly::NoQualifier, false) :  // Version V1 is obsolete.
    E_FAIL;
}

inline HRESULT CATPolyBody::FaceRemoveEdge (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& SVL)
{
  return !WithVolumes () ?
    FaceRemoveEdgeP<CATPolyDart2> (F, E, SVL) :
    FaceRemoveEdgeP<CATPolyDart3> (F, E, SVL);
}

inline HRESULT CATPolyBody::CollapseFace (CATPolyEdge* E, CATPolyFace*& F)
{
  return !WithVolumes () ? 
    CollapseFaceP<CATPolyDart2> (E, F) : 
    CollapseFaceP<CATPolyDart3> (E, F);
}

inline HRESULT CATPolyBody::SplitEdge (CATPolyEdge*& E, int cv, CATPolyVertex*& V, CATPolyEdge*& E1, CATPolyEdge*& E2)
{
  return !WithVolumes () ? 
    SplitEdgeP<CATPolyDart2> (E, cv, V, E1, E2) : 
    SplitEdgeP<CATPolyDart3> (E, cv, V, E1, E2);
}

inline HRESULT CATPolyBody::Substitute (CATPolyFace& F, CATPolyEdge& E, CATIPolySurfaceVertexLine& svlOut, CATIPolySurfaceVertexLine& svlIn)
{
  return !WithVolumes () ? 
    SubstituteP<CATPolyDart2> (F, E, svlOut, svlIn) : 
    SubstituteP<CATPolyDart3> (F, E, svlOut, svlIn);
}

inline HRESULT CATPolyBody::AddFacesAdjacency (CATPolyFace& face0,
  CATPolyFace& face1,
  CATPolyEdge& edge)
{
  return !WithVolumes () ? 
    AddFacesAdjacencyP<CATPolyDart2> (face0, face1, edge) : 
    AddFacesAdjacencyP<CATPolyDart3> (face0, face1, edge);
}

template<>
inline CATPolyVertex* CATPolyBody::Make<CATPolyVertex> ()
{
  return MakeVertex ();
}

template<>
inline CATPolyEdge* CATPolyBody::Make<CATPolyEdge> ()
{
  return MakeEdge ();
}

template<>
inline CATPolyVolume* CATPolyBody::Make<CATPolyVolume> ()
{
  return MakeVolume ();
}
