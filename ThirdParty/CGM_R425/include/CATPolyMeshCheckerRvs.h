//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011
//==============================================================================================================
// CATPolyMeshCheckerRvs :
// Operator for the Mesh Cleaner command.
//==============================================================================================================
// 05-Feb-2018 : JLH : Traitement des auto-intersections.
// 20-Jul-2017 : JLH : Ajout de GetBoundaries.
// 26-May-2017 : JLH : Ajout des méthodes '[SG]etMesh' et 'Reinitialize'.
// 14-Apr-2017 : JLH : Données-membres en protected.
// 13-Apr-2017 : JLH : Mise en commentaire de IsClosed et IsOrientable.
//                     Les services appelés ne répondent pas aux besoins.
// 31-Mar-2017 : JLH : Ajout de GetNbBoundaries, IsClosed et IsOrientable.
//    Oct-2003 - DNR - Creation a partir de CATCldMeshCleanerOpr.
//==============================================================================================================

#ifndef CATPolyMeshCheckerRvs_H
#define CATPolyMeshCheckerRvs_H

#include "CATPolyCurveList.h"
#include "CATBooleanDef.h"
#include "CATCGMBucketsDcl.h"

class CATIPolyMesh ;
class CATCldMeshCleaner ;
class CATPolyMeshCleanerMesh ;

#include "ExportedByPolyhedralOperatorsRvs.h"

class ExportedByPolyhedralOperatorsRvs CATPolyMeshCheckerRvs
{
public:

  class ExportedByPolyhedralOperatorsRvs CATCGMBucketsOfInt ;
  class ExportedByPolyhedralOperatorsRvs CATCGMBucketsOfEdges ;
  class ExportedByPolyhedralOperatorsRvs CATCGMBucketsOfZones ;
  class ExportedByPolyhedralOperatorsRvs CATCGMBucketsOfConfusedPoints ;

  CATCGMBucketsDeclare (Int, int) ;

  typedef struct Edge {
    boolean _VtxDef ; // TRUE, if _Numi is vertices numbers, FALSE is triangle numbers.
    int _Num[2] ;
  } StructEdge ;
  CATCGMBucketsDeclare (Edges, StructEdge) ;

  typedef struct Zone {
    unsigned int _Direct  :  1 ;
    unsigned int _Zone    : 31 ;
    int _Arrow ;
    int _NbTriangles ;
    int _FirstTriangle ;
  } StructZone ;
  CATCGMBucketsDeclare (Zones, StructZone) ;

  typedef struct ConfPoint {
    int _Dup ;
    int _Ref ;
  } StructConfPoint ;
  CATCGMBucketsDeclare (ConfusedPoints, StructConfPoint) ;
  /**
   * Constructor / Destructor.<br>
   */
  CATPolyMeshCheckerRvs(CATIPolyMesh* iMesh);
  ~CATPolyMeshCheckerRvs();

  /**
   * Set or modify the mesh to clean.
   * @return
   * <tt>TRUE</tt> if the modification succeeded<br>
   * <tt>FALSE</tt> otherwise.
   */
  boolean SetMesh (CATIPolyMesh * iMesh) ;

  /**
   * Get the mesh to clean.
   * @return
   * <tt>TRUE</tt> if succeeded<br>
   * <tt>FALSE</tt> otherwise.
   */
  boolean GetMesh (CATIPolyMesh * &oMesh) ;

  /**
   * Sends a notification to the cleaner to reinitialize its data.
   * @return
   * <tt>TRUE</tt> if succeeded<br>
   * <tt>FALSE</tt> otherwise.
   */
  boolean Reinitialize() ;

  /**
   * Returns the corrupted triangles of the given mesh.<br>
   * A triangle is said corrupted when it has twice the same vertex.
   * @param oTriangles
   * Indices array (with buckets mechanism) of the corrupted triangles.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of corrupted triangles.
   */
  int GetCorruptedTriangles ( CATCGMBucketsOfInt& oTriangles,
                              const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the duplicated triangles of the given mesh.<br>
   * Two triangles are said duplicated when they share the same vertices.
   * @param oTriangles
   * Indices array (with buckets mechanism) of the duplicated triangles.<br>
   * <b>CAUTION 1:</b> If two or more triangles are in fact the same, the first found in the
   * mesh will not be in the array because it is considered as the reference.<br>
   * <b>CAUTION 2:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of corrupted triangles.
   */
  int GetDuplicatedTriangles ( CATCGMBucketsOfInt& oTriangles,
                               const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the non-manifold edges of the given mesh.<br>
   * An edge is said non-manifold if it is shared by more than two triangles.
   * @param oEdges
   * Array (with buckets mechanism) of the non-manifold edges.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and non-manifold edges will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of non-manifold edges.
   */
  int GetNonManifoldEdges ( CATCGMBucketsOfEdges& oEdges,
                            const boolean         iOnlyActive = TRUE) ;

  /**
   * Returns the non-manifold vertices of the given mesh.<br>
   * A vertex is said non-manifold if its neighbour triangles give two or more connected zones.
   * @param oVertices
   * Indices array (with buckets mechanism) of the non-manifold vertices.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and vertices will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active vertices.
   * @return
   * The number of non-manifold edges.
   */
  int GetNonManifoldVertices ( CATCGMBucketsOfInt& oVertices,
                               const boolean       iOnlyActive = TRUE) ;

  /**
  * Returns the number of boundaries.
  * @return
  * The number of boundaries.<br>
  * <tt>-1</tt> if something wrong.
  */
  int GetNbBoundaries() ;
  int GetBoundaries (CATCGMBucketsOfInt * &oNoVertices) ;

  /**
   * Returns the different connected zones of the given mesh.<br>
   * @param oZones
   * Array (with buckets mechanism) of the connected zones.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of connected zones.
   */
  int GetConnectedZones (CATCGMBucketsOfZones& oZones,
                         const boolean         iOnlyActive = TRUE) ;

  void GetConnectedZones (CATCGMBucketsOfInt&                oZones,
                          int&                               oNbZones,
                          const unsigned char  iOnlyActive = TRUE);

  int GetConnectedZones (CATCGMBucketsOfInt * &oNoTriangles,
                         const boolean         iOnlyActive = TRUE) ;

  /**
   * Returns all the triangles of a connected zone of the given mesh defined by one of its triangle.<br>
   * @param iFirstTriangle
   * The adress of one of the triangles.
   * @param oTriangles
   * Indices array (with buckets mechanism) of the connected triangles.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of connected triangles.
   */
  int GetConnectedTriangles ( const int           iFirstTriangle,
                              CATCGMBucketsOfInt& oTriangles,
                              const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns all the triangles surrounding one triangle which fit an angle criterion (between their normals and that of this triangle).<br>
   * @param iFirstTriangle
   * The adress of one of the triangles.
   * @param iLimit
   * The limit (cosinus of the angle).
   * @param oTriangles
   * Indices array (with buckets mechanism) of the connected triangles.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of connected triangles.
   */
  int GetConnectedTriangles ( const int           iFirstTriangle,
                              const double        iLimit,
                              CATCGMBucketsOfInt& oTriangles,
                              const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the long triangles of the given mesh.<br>
   * A triangle is said long if one of its edges has a length greater than the given one.
   * @param iMaxLength
   * The length criterion to define the long triangles.
   * @param oTriangles
   * Indices array (with buckets mechanism) of the long triangles.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of long triangles.
   */
  int GetLongEdgesTriangles ( const double        iMaxLength,
                              CATCGMBucketsOfInt& oTriangles,
                              const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the maximum edge length of the triangles of the given mesh.<br>
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The maximum edge length.
   */
  double GetMaxEdgeLength ( const boolean iOnlyActive = TRUE) ;

  /**
   * Returns the thin triangles of the given mesh.<br>
   * A triangle is said thin if one of its angles is less than the given minimum one.
   * @param iMinAngle
   * The angle criterion to define the thin triangles.
   * @param oTriangles
   * Indices array (with buckets mechanism) of the thin triangles.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of thin triangles.
   */
  int GetSmallAnglesTriangles ( const double        iMinAngle,
                                CATCGMBucketsOfInt& oTriangles,
                                const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the connected zones of the given mesh defined by triangles with same orientation.<br>
   * @param oZones
   * Array (with buckets mechanism) of the connected zones.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of connected zones.
   */
  int GetOrientedZones ( CATCGMBucketsOfZones& oZones,
                         const boolean         iOnlyActive = TRUE) ;


  /**
   * Returns all the triangles of a same oriented zone of the given mesh defined by one of its triangle.<br>
   * @param iFirstTriangle
   * The adress of one of the triangles.
   * @param oTriangles
   * Indices array (with buckets mechanism) of the connected triangles.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of connected triangles.
   */
  int GetOrientedTriangles ( const int           iFirstTriangle,
                             CATCGMBucketsOfInt& oTriangles,
                             const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the non-orientable triangles of the given mesh.<br>
   * The result is given by edges shared by triangles couple with inconsistent orientation.
   * @param oEdges
   * Array (with buckets mechanism) of the non-manifold edges.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and non-manifold edges will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of non-manifold edges.
   */
  int GetNonOrientableTriangles ( CATCGMBucketsOfEdges& oEdges,
                                  const boolean         iOnlyActive = TRUE) ;

  /**
   * Returns the confused points of the given cloud of points.<br>
   * The result is given by couple of indices <tt>(Confused,With)</tt>.
   * @param oConfusedPoints
   * Array (with buckets mechanism) of the confused points.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and confudef points will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active points.
   * @return
   * The number of confused points.
   */
  int GetConfusedPoints ( const double iTolerance,
                          CATCGMBucketsOfConfusedPoints& oConfusedPoints,
                          const boolean                  iOnlyActive = FALSE) ;
  /**
   * Returns the Free Edges of the given mesh.<br>
   * The result is given by edges is the edges of the triangles which does not have neighbour triangle.
   * @param oEdges
   * Array (with buckets mechanism) of the edges.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and free edges will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of free edges.
   */
  int GetFreeEdges ( CATCGMBucketsOfEdges& oEdges,
                     const boolean         iOnlyActive = TRUE) ;
  
  /**
   * Returns the Free Vertices of the given mesh.<br>
   * A vertex is said free if it is used a free edge.
   * @param oVertices
   * Array (with buckets mechanism) of the int.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and free edges will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of free edges.
   */
  int GetFreeVertices ( CATCGMBucketsOfInt& oVertices,
                        const boolean       iOnlyActive = TRUE) ;
  /**
   * Returns the Non Referenced Vertices of the given mesh.<br>
   * A Non referenced vertex is a vertex never used as triangle vertex definition.
   * @param oVertices
   * Array (with buckets mechanism) of the int.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and free edges will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of Non Referenced Vertices.
   */
  int GetNonReferencedVertices ( CATCGMBucketsOfInt& oVertices,
                                 const boolean       iOnlyActive = TRUE) ;

  /**
   * Returns the self intersection curves of the given mesh.
   * @param ioCurves
   * The self intersections curves.<br>
   * <b>CAUTION:</b> The curves must be released.
   * @param ioTriangles
   * The triangles where the mesh is self intersecting.
   * @return
   * The number of self intersection curves.
   */
  int GetSelfIntersections (CATPolyCurveList   & ioCurves,
                            CATCGMBucketsOfInt & ioTriangles) ;

  /**
   * Returns all the triangles forming multi layer on the mesh.<br>
   * @param oTriangles
   * Indices array of integer of the triangles impacted.<br>
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of triangles.
   */
   int GetMultiLayerTriangles ( CATCGMBucketsOfInt& oTriangles,
                                const boolean iOnlyActive = TRUE);

  /**
   * Returns all free edges forming a button hole.<br>
   * @param iCutDistance
   * The distance used to qualify the button hole.
   * @param oLstIdxVertices
   * Indices of the three vertices, origin of the button hole.<br>
   * @return
   * The number of button holes found.
   */

   int GetButtonHoles (const double iCutDistance, CATCGMBucketsOfInt& oLstIdxVertices );

#ifdef nodefine_for_coverage
   boolean IsClosed() ;
   boolean IsOrientable() ;
#endif

protected:

  CATIPolyMesh*           _PolyMesh ;
  CATCldMeshCleaner*      _Checker ;
  CATPolyMeshCleanerMesh* _Mesh ;

};

#endif
