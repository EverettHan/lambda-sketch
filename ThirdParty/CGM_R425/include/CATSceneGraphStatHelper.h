//===================================================================
// COPYRIGHT Dassault Systemes 2015/11/06
//===================================================================
// CATSceneGraphStatHelper.h
//===================================================================

#ifndef CATSceneGraphStatHelper_H
#define CATSceneGraphStatHelper_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CATSysErrorDef.h"
#include "CATSysDataType.h"

class CATRep;

/**
 * Structure containing the different statistics for a SceneGraph representation.
 *
 * <b>TRIANGLES INFO</b>
 * @param _nb_triangles                   : total number of triangles.
 * @param _nb_single_triangles            : number of single triangles.
 * @param _nb_strips                      : number of strips.
 * @param _nb_fans                        : number of fans.
 * @param _nb_triangles_in_strips         : number of triangles in strips.
 * @param _nb_triangles_in_fans           : number of triangles in fans.
 * @param _min_nb_triangles_in_strip      : minimum number of triangles per strip.
 * @param _min_nb_triangles_in_fan        : minimum number of triangles per fan.
 * @param _max_nb_triangles_in_strip      : maximum number of triangles per strip.
 * @param _max_nb_triangles_in_fan        : maximum number of triangles per fan.
 * @param _average_nb_triangles_in_strip  : average number of triangles per strip.
 * @param _average_nb_triangles_in_fan    : average number of triangles per fan.
 *
 * <b>MEMORY INFO</b>
 * @param _memory_size_in_bytes           : Approximation of the total amount of memory used for this representation (expressed in bytes).
 * @param _vertices_array_size_in_bytes   : Cumulated amount of memory used for vertices storage (expressed in bytes).
 * @param _normals_array_size_in_bytes    : Cumulated amount of memory used for normal storage (expressed in bytes).
 * @param _indices_array_size_in_bytes    : Cumulated amount of memory used for indices storage (expressed in bytes).
 *
 * <b>CAT3DBAGREP INFO</b>
 * @param _nb_bagreps                           : number of @href CAT3DBagRep
 * @param _nb_bagreps_with_null_matrix_pointer  : number of @href CAT3DBagRep with a NULL matrix pointer.
 * @param _nb_bagreps_with_identity_matrix      : number of @href CAT3DBagRep with an identity matrix.
 * @param _nb_bagreps_with_non_identity_matrix  : number of @href CAT3DBagRep with a non-identity matrix.
 *
 * <b>CAT3DGEOMREP INFO</b>
 * @param _nb_geomreps                    : number of @href CAT3DGeomRep.
 * @param _nb_empty_geomreps              : number of @href CAT3DGeomRep without any geometry inside.
 * @param _nb_not_empty_geomreps          : number of @href CAT3DGeomRep with geometry inside.
 * @param _nb_faces                       : number of faces in the geometrical representations.
 * @param _nb_edges                       : total number of edges in the geometrical representations.
 * @param _nb_boundary_and_internal_edges : cumulated number of boundary and internal edges in the geometrical representations.
 * @param _nb_boundary_edges              : number of boundary edges in the geometrical representations.
 * @param _nb_internal_sharpe_edges       : number of internal sharpe edges in the geometrical representations.
 * @param _nb_internal_smooth_edges       : number of internal smooth edges in the geometrical representations.
 * @param _nb_wire_edges                  : number of wire edges in the geometrical representations.
 * @param _nb_points                      : total number of points in the geometrical representations.
 * @param _nb_boundary_points             : number of boundary points in the geometrical representations.
 * @param _nb_internal_sharpe_points      : number of internal sharpe points in the geometrical representations.
 * @param _nb_internal_smooth_points      : number of internal smooth points in the geometrical representations.
 * @param _nb_surfacic_points             : number of surfacic points in the geometrical representations.
 * @param _nb_free_points                 : number of free points in the geometrical representations.
 * @param _nb_isopars                     : number of isopars in the geometrical representations.
 *
 * see @href CATGeomType for further information about geometrical types.
 *
 * Among geometrical representations (@href CAT3DGeomRep), there are surfacic representations (@href CATSurfacicRep) and mono-wire representations (@href CATMonoWireRep).
 * Here below are the statistics for those two kinds of geometrical representations.
 *
 * <b>CATSURFACICREP INFO</b>
 * @param _nb_surfacicreps                                        : number of @href CATSurfacicRep.
 * @param _nb_empty_surfacicreps                                  : number of @href CATSurfacicRep without any geometry inside.
 * @param _nb_not_empty_surfacicreps                              : number of @href CATSurfacicRep with geometry inside.
 * @param _nb_faces_in_surfacicreps                               : number of faces in the surfacic representations.
 * @param _min_nb_faces_in_surfacicrep                            : minimum number of faces per surfacic representation. Set to -1 if no surfacic representation.
 * @param _max_nb_faces_in_surfacicrep                            : maximum number of faces per surfacic representation.
 * @param _average_nb_faces_in_surfacicrep                        : average number of faces per surfacic representation.
 * @param _nb_edges_in_surfacicreps                               : number of edges in the surfacic representations.
 * @param _min_nb_edges_in_surfacicrep                            : minimum number of edges per surfacic representation. Set to -1 if no surfacic representation.
 * @param _max_nb_edges_in_surfacicrep                            : maximum number of edges per surfacic representation.
 * @param _average_nb_edges_in_surfacicrep                        : average number of edges per surfacic representation.
 * @param _nb_boundary_and_internal_edges_in_surfacicreps         : cumulated number of boundary and internal edges in the surfacic representations.
 * @param _min_nb_boundary_and_internal_edges_in_surfacicrep      : minimum number of boundary and internal edges per surfacic representation. Set to -1 if no surfacic representation.
 * @param _max_nb_boundary_and_internal_edges_in_surfacicrep      : maximum number of boundary and internal edges per surfacic representation.
 * @param _average_nb_boundary_and_internal_edges_in_surfacicrep  : average number of boundary and internal edges per surfacic representation.
 * @param _nb_wire_edges_in_surfacicreps                          : number of wire edges in the surfacic representations.
 * @param _min_nb_wire_edges_in_surfacicrep                       : minimum number of wire edges per surfacic representation. Set to -1 if no surfacic representation.
 * @param _max_nb_wire_edges_in_surfacicrep                       : maximum number of wire edges per surfacic representation.
 * @param _average_nb_wire_edges_in_surfacicrep                   : average number of wire edges per surfacic representation.
 * @param _nb_points_in_surfacicreps                              : total number of points in the surfacic representations.
 * @param _min_nb_points_in_surfacicrep                           : minimum number of points per surfacic representation. Set to -1 if no surfacic representation.
 * @param _max_nb_points_in_surfacicrep                           : maximum number of points per surfacic representation.
 * @param _average_nb_points_in_surfacicrep                       : average number of points per surfacic representation.
 * @param _nb_LODs_in_surfacicreps                                : number of LODs (Level Of Detail) in the surfacic representations.
 * @param _min_nb_LODs_in_surfacicrep                             : minimum number of LODs per surfacic representation. Set to -1 if no surfacic representation.
 * @param _max_nb_LODs_in_surfacicrep                             : maximum number of LODs per surfacic representation.
 * @param _average_nb_LODs_in_surfacicrep                         : average number of LODs per surfacic representation.
 *
 *
 * <b>CATMONOWIREREP INFO</b>
 * @param _nb_monowirereps                      : number of @href CATMonoWireRep.
 * @param _nb_empty_monowirereps                : number of @href CATMonoWireRep without any geometry inside.
 * @param _nb_not_empty_monowirereps            : number of @href CATMonoWireRep with geometry inside.
 * @param _nb_wire_edges_in_monowirereps        : number wire edges in the mono-wire representations.
 * @param _min_nb_wire_edges_in_monowirerep     : minimum number of wire edges per mono-wire representation. Set to -1 if no mono-wire representation.
 * @param _max_nb_wire_edges_in_monowirerep     : maximum number of wire edges per mono-wire representation.
 * @param _average_nb_wire_edges_in_monowirerep : average number of wire edges per mono-wire representation.
 * @param _nb_points_in_monowirereps            : number of points in the mono-wire representations.
 * @param _min_nb_points_in_monowirerep         : minimum number of points per mono-wire representation. Set to -1 if no mono-wire representation.
 * @param _max_nb_points_in_monowirerep         : maximum number of points per mono-wire representation.
 * @param _average_nb_points_in_monowirerep     : average number of points per mono-wire representation.
 *
 *
 * <b>VISPRIMITIVEGROUPREP INFO</b>
 * @param _nb_visprimitivegroupreps                         : number of @href VisPrimitiveGroupRep.
 * @param _nb_visprimitives_in_visprimitivegroupreps        : number of @href VisPrimitive in the @href VisPrimitiveGroupRep.
 * @param _min_nb_visprimitives_in_visprimitivegrouprep     : minimum number of @href VisPrimitive per @href VisPrimitiveGroupRep. Set to -1 if no @href VisPrimitiveGroupRep.
 * @param _max_nb_visprimitives_in_visprimitivegrouprep     : maximum number of @href VisPrimitive per @href VisPrimitiveGroupRep.
 * @param _average_nb_visprimitives_in_visprimitivegrouprep : average number of @href VisPrimitive per @href VisPrimitiveGroupRep.
 *
 *
 * <b>CANONICALREP INFO</b>
 * @param _nb_canonicalreps           : number of @href CAT3DCanonicalRep.
 * @param _nb_canonicalcuboids        : number of @href CAT3DCanonicalCuboidRep.
 * @param _nb_canonicalspheres        : number of @href CAT3DCanonicalSphereRep.
 * @param _nb_canonicalpartialspheres : number of @href CAT3DCanonicalPartialSphereRep.
 * @param _nb_canonicalcylinders      : number of @href CAT3DCanonicalCylinderRep.
 * @param _nb_canonicalcones          : number of @href CAT3DCanonicalConeRep.
 * @param _nb_canonicaltorus          : number of @href CAT3DCanonicalTorusRep.
 * @param _nb_canonicalpartialtorus   : number of @href CAT3DCanonicalPartialTorusRep.
 * @param _nb_canonicalcurvedpipes    : number of @href CAT3DCanonicalCurvedPipeRep.
 */
struct CATREPSTATS
{
  // TRIANGLES INFO
  int   _nb_triangles;
  int   _nb_single_triangles;
  int   _nb_strips;
  int   _nb_fans;
  int   _nb_triangles_in_strips;
  int   _nb_triangles_in_fans;
  int   _min_nb_triangles_in_strip;
  int   _min_nb_triangles_in_fan;
  int   _max_nb_triangles_in_strip;
  int   _max_nb_triangles_in_fan;
  float _average_nb_triangles_in_strip;
  float _average_nb_triangles_in_fan;

  // MEMORY INFO
  int   _memory_size_in_bytes;
  int   _vertices_array_size_in_bytes;
  int   _normals_array_size_in_bytes;
  int   _indices_array_size_in_bytes;

  // BAGREPS INFO
  int   _nb_bagreps;
  int   _nb_bagreps_with_null_matrix_pointer;
  int   _nb_bagreps_with_identity_matrix;
  int   _nb_bagreps_with_non_identity_matrix;

  // GEOMREPS INFO
  int   _nb_geomreps;
  int   _nb_empty_geomreps;
  int   _nb_not_empty_geomreps;
  // faces
  int   _nb_faces;
  // edges
  int   _nb_edges;
  // boundary & internal edges
  int   _nb_boundary_and_internal_edges;
  int   _nb_boundary_edges;
  int   _nb_internal_sharpe_edges;
  int   _nb_internal_smooth_edges;
  // wire edges
  int   _nb_wire_edges;
  // points
  int   _nb_points;
  int   _nb_boundary_points;
  int   _nb_internal_sharpe_points;
  int   _nb_internal_smooth_points;
  int   _nb_surfacic_points;
  int   _nb_free_points;
  // isopars
  int   _nb_isopars;

  // SURFACICREPS INFO
  int   _nb_surfacicreps;
  int   _nb_empty_surfacicreps;
  int   _nb_not_empty_surfacicreps;
  // faces
  int   _nb_faces_in_surfacicreps;
  int   _min_nb_faces_in_surfacicrep;
  int   _max_nb_faces_in_surfacicrep;
  float _average_nb_faces_in_surfacicrep;
  // edges
  int   _nb_edges_in_surfacicreps;
  int   _min_nb_edges_in_surfacicrep;
  int   _max_nb_edges_in_surfacicrep;
  float _average_nb_edges_in_surfacicrep;
  // boundary & internal edges
  int   _nb_boundary_and_internal_edges_in_surfacicreps;
  int   _min_nb_boundary_and_internal_edges_in_surfacicrep;
  int   _max_nb_boundary_and_internal_edges_in_surfacicrep;
  float _average_nb_boundary_and_internal_edges_in_surfacicrep;
  // wire edges
  int   _nb_wire_edges_in_surfacicreps;
  int   _min_nb_wire_edges_in_surfacicrep;
  int   _max_nb_wire_edges_in_surfacicrep;
  float _average_nb_wire_edges_in_surfacicrep;
  // points
  int   _nb_points_in_surfacicreps;
  int   _min_nb_points_in_surfacicrep;
  int   _max_nb_points_in_surfacicrep;
  float _average_nb_points_in_surfacicrep;
  // LODs
  int   _nb_LODs_in_surfacicreps;
  int   _min_nb_LODs_in_surfacicrep;
  int   _max_nb_LODs_in_surfacicrep;
  float _average_nb_LODs_in_surfacicrep;

  // MONOWIREREPS INFO
  int   _nb_monowirereps;
  int   _nb_empty_monowirereps;
  int   _nb_not_empty_monowirereps;
  // wire edges
  int   _nb_wire_edges_in_monowirereps;
  int   _min_nb_wire_edges_in_monowirerep;
  int   _max_nb_wire_edges_in_monowirerep;
  float _average_nb_wire_edges_in_monowirerep;
  // points
  int   _nb_points_in_monowirereps;
  int   _min_nb_points_in_monowirerep;
  int   _max_nb_points_in_monowirerep;
  float _average_nb_points_in_monowirerep;

  // VISPRIMITIVEGROUPREPS INFO
  int   _nb_visprimitivegroupreps;
  int   _nb_visprimitives_in_visprimitivegroupreps;
  int   _min_nb_visprimitives_in_visprimitivegrouprep;
  int   _max_nb_visprimitives_in_visprimitivegrouprep;
  float _average_nb_visprimitives_in_visprimitivegrouprep;

  // CANONICALREPS INFO
  int   _nb_canonicalreps;
  int   _nb_canonicalcuboids;
  int   _nb_canonicalspheres;
  int   _nb_canonicalpartialspheres;
  int   _nb_canonicalcylinders;
  int   _nb_canonicalcones;
  int   _nb_canonicaltorus;
  int   _nb_canonicalpartialtorus;
  int   _nb_canonicalcurvedpipes;

  // CONSTRUCTOR
  CATREPSTATS() :
    _nb_triangles(0),
    _nb_single_triangles(0),
    _nb_strips(0),
    _nb_fans(0),
    _nb_triangles_in_strips(0),
    _nb_triangles_in_fans(0),
    _min_nb_triangles_in_strip(-1),
    _min_nb_triangles_in_fan(-1),
    _max_nb_triangles_in_strip(0),
    _max_nb_triangles_in_fan(0),
    _average_nb_triangles_in_strip(0.),
    _average_nb_triangles_in_fan(0.),
    _memory_size_in_bytes(0),
    _vertices_array_size_in_bytes(0),
    _normals_array_size_in_bytes(0),
    _indices_array_size_in_bytes(0),
    _nb_bagreps(0),
    _nb_bagreps_with_null_matrix_pointer(0),
    _nb_bagreps_with_identity_matrix(0),
    _nb_bagreps_with_non_identity_matrix(0),
    _nb_geomreps(0),
    _nb_empty_geomreps(0),
    _nb_not_empty_geomreps(0),
    _nb_monowirereps(0),
    _nb_empty_monowirereps(0),
    _nb_not_empty_monowirereps(0),
    _nb_surfacicreps(0),
    _nb_empty_surfacicreps(0),
    _nb_not_empty_surfacicreps(0),
    _nb_faces(0),
    _nb_faces_in_surfacicreps(0),
    _min_nb_faces_in_surfacicrep(-1),
    _max_nb_faces_in_surfacicrep(0),
    _average_nb_faces_in_surfacicrep(0.),
    _nb_edges(0),
    _nb_edges_in_surfacicreps(0),
    _min_nb_edges_in_surfacicrep(-1),
    _max_nb_edges_in_surfacicrep(0),
    _average_nb_edges_in_surfacicrep(0.),
    _nb_boundary_edges(0),
    _nb_internal_sharpe_edges(0),
    _nb_internal_smooth_edges(0),
    _nb_boundary_and_internal_edges(0),
    _nb_boundary_and_internal_edges_in_surfacicreps(0),
    _min_nb_boundary_and_internal_edges_in_surfacicrep(-1),
    _max_nb_boundary_and_internal_edges_in_surfacicrep(0),
    _average_nb_boundary_and_internal_edges_in_surfacicrep(0.),
    _nb_wire_edges(0),
    _nb_wire_edges_in_surfacicreps(0),
    _nb_wire_edges_in_monowirereps(0),
    _min_nb_wire_edges_in_surfacicrep(-1),
    _min_nb_wire_edges_in_monowirerep(-1),
    _max_nb_wire_edges_in_surfacicrep(0),
    _max_nb_wire_edges_in_monowirerep(0),
    _average_nb_wire_edges_in_surfacicrep(0.),
    _average_nb_wire_edges_in_monowirerep(0.),
    _nb_points(0),
    _nb_boundary_points(0),
    _nb_internal_sharpe_points(0),
    _nb_internal_smooth_points(0),
    _nb_surfacic_points(0),
    _nb_free_points(0),
    _nb_points_in_surfacicreps(0),
    _nb_points_in_monowirereps(0),
    _min_nb_points_in_surfacicrep(-1),
    _min_nb_points_in_monowirerep(-1),
    _max_nb_points_in_surfacicrep(0),
    _max_nb_points_in_monowirerep(0),
    _average_nb_points_in_surfacicrep(0),
    _average_nb_points_in_monowirerep(0),
    _nb_isopars(0),
    _nb_LODs_in_surfacicreps(0),
    _min_nb_LODs_in_surfacicrep(-1),
    _max_nb_LODs_in_surfacicrep(0),
    _average_nb_LODs_in_surfacicrep(0.),
    _nb_visprimitivegroupreps(0),
    _nb_visprimitives_in_visprimitivegroupreps(0),
    _min_nb_visprimitives_in_visprimitivegrouprep(-1),
    _max_nb_visprimitives_in_visprimitivegrouprep(0),
    _average_nb_visprimitives_in_visprimitivegrouprep(0.),
    _nb_canonicalreps(0),
    _nb_canonicalcuboids(0),
    _nb_canonicalspheres(0),
    _nb_canonicalpartialspheres(0),
    _nb_canonicalcylinders(0),
    _nb_canonicalcones(0),
    _nb_canonicaltorus(0),
    _nb_canonicalpartialtorus(0),
    _nb_canonicalcurvedpipes(0)
  {}

};

//-----------------------------------------------------------------------

/**
 * Class to retrieve SceneGraph statistics.
 *
 * The static method HRESULT CATSceneGraphStatHelper::CATGetSceneGraphRepStats( CATRep*, CATREPSTATS& )
 * allow you to retrieve all the CATREPSTATS struct statistics of a given @href CATRep,
 * which could be either a leaf representation, with  or a internal SceneGraph node, in which case the statistics are computed on the all above child representations.
 *
 * <b>WARNING</b>
 * 1. CAT3DCustomRep are only taken into account for triangles count
 */
class ExportedBySGInfra CATSceneGraphStatHelper
{
public:

  static HRESULT CATGetSceneGraphRepStats( CATRep* iRep, CATREPSTATS& oStats );

private:

	CATSceneGraphStatHelper();
	virtual ~CATSceneGraphStatHelper();
	CATSceneGraphStatHelper(CATSceneGraphStatHelper &);
	CATSceneGraphStatHelper& operator=(CATSceneGraphStatHelper&);
};

//-----------------------------------------------------------------------

#endif
