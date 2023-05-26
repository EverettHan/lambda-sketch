//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2011
//==============================================================================================================
// CATPolyMeshCleanerRvs :
// Operator fix mesh incidents.
//==============================================================================================================
// 24-May-2019 : JLH : Ajout de MeshOptimization.
// 24-Jan-2019 : JLH : Ajout de FixNonOrientableTriangles.
// 03-Jul-2018 : JLH : Ajout de FixSelfIntersections et de ExternalEnvelop.
// 28-Apr-2017 : JLH : Ajout de la méthode 'Reinitialize' qui envoie une notification au cleaner pour réinitia-
//                     liser ses données.
// 11-Apr-2017 : JLH : Ajout de [SG]etMesh.
// 06-Apr-2017 : JLH : Données-membres en protected.
// 05-Apr-2017 : JLH : Ajout de FixUnreferencedVertices et de FixDuplicatedTriangles.
// 27-Oct-2011 - DNR - Creation.
//==============================================================================================================

#ifndef CATPolyMeshCleanerRvs_H
#define CATPolyMeshCleanerRvs_H

#include "ExportedByPolyhedralOperatorsRvs.h"
#include "CATPolyMeshCheckerRvs.h"

#include "CATBooleanDef.h"


class CATIPolyMesh ;
class CATCldMeshCleaner ;
class CATPolyMeshCleanerMesh ;
class CATTolerance ;

class ExportedByPolyhedralOperatorsRvs CATPolyMeshCleanerRvs
{
public:

  /**
   * Constructor / Destructor.<br>
   */
  CATPolyMeshCleanerRvs(CATIPolyMesh* iMesh) ;
  ~CATPolyMeshCleanerRvs() ;

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
   * Fix the confused points in iConfusedPoints of the mesh.<br>
   * @param iConfusedPoints
   * Array (with buckets mechanism) of the indexes of confused points (Confused,With).<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixConfusedPoints (CATPolyMeshCheckerRvs::CATCGMBucketsOfConfusedPoints& iConfusedPoints) ;

  /**
   * Fix all the confused points of the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixConfusedPoints (const double iTolerance = 0.) ;

  /**
   * Fix all the unreferenced points of the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixUnreferencedVertices() ;

  /**
   * Fix the corrupted triangles in iCorruptedTriangles of the mesh.<br>
   * @param iCorruptedTriangles
   * Array (with buckets mechanism) of the indexes of the corrupted triangles to be fixed.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixCorruptedTriangles (CATPolyMeshCheckerRvs::CATCGMBucketsOfInt& iCorruptedTriangles) ;

  /**
   * Fix all the corrupted triangles of the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixCorruptedTriangles() ;

  /**
   * Fix the duplicated triangles in iDuplicatedTriangles of the mesh.<br>
   * @param iCorruptedTriangles
   * Array (with buckets mechanism) of the indexes of the corrupted triangles to be fixed.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixDuplicatedTriangles (CATPolyMeshCheckerRvs::CATCGMBucketsOfInt &iDuplicatedTriangles) ;

  /**
   * Fix all the duplicated triangles of the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixDuplicatedTriangles() ;

  /**
   * Fix a non manifold edge given by iVtx1,iVtx2.<br>
   * parameter iRatio : distance value used to separate the MNF edges.
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixNonManifoldEdge (const int iVtx1, const int iVtx2,const double iRatio) ;

  /**
   * Fix all non manifold edges.<br>
   * parameter iRatio : distance value used to separate the MNF edges.
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixNonManifoldEdges (const double iRatio) ;

  /**
   * Fix all non manifold Vertices.<br>
   * parameter iRatio : distance value used to separate the MNF vertices.
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixNonManifoldVertices (const double iRatio) ;
  boolean FixNonManifoldVertices (CATPolyMeshCheckerRvs::CATCGMBucketsOfInt& iNMFVtxList,const double iRatio) ;
  boolean FixNonManifoldVertex   (const int iNum, const double iRatio) ;

  /**
   * Fix all the multi layer of the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixMultiLayers() ;

  /**
   * Fix all the non-orientable triangles of the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixNonOrientableTriangles() ;

  /**
   * Fix all the defaults found in the mesh.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean FixAllDefaults() ;

  /**
   * Repair Small Angle Triangle by collapse.<br>
   * @return
   * return value is TRUE if the mesh has been modied.
   *                      else it is FALSE.
   */
  boolean CollapseSmallAngles (CATPolyMeshCheckerRvs::CATCGMBucketsOfInt& iSmallAnglesList) ;
  boolean CollapseSmallAngles (const int iNumTriangle) ;

  boolean FixButtonHoles (const double iEpsilon) ;

  boolean FixSelfIntersections (const CATTolerance &iTolerance) ;

  boolean ExternalEnvelop (const double        iHoleMaxSize,
                           const CATTolerance &iTolerance) ;

  boolean MeshOptimization (const double iLength) ;

protected:

  CATIPolyMesh *           _PolyMesh ;
  CATCldMeshCleaner *      _Cleaner ;
  CATPolyMeshCleanerMesh * _Mesh ;

} ;

#endif
