#ifndef CATTrianglesCountRender_H
#define CATTrianglesCountRender_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1997
//******************************************************************************
//  Abstract:
//  ---------
//    Simple render made to count the number of triangles in a representation
//    tree. This render counts the triangles for original representations only,
//    not for levels of detail. All elements are considered to be visible.
//
//******************************************************************************
//  Usage:
//  ------
//   The render creation with a given support, then a call to the DrawShading of
//   a representation, and that's all: The number of triangles can be returned
//   by a call to GetSceneSize.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATTrianglesCountRender
//                  CATDrawRender
//                    CATRender
//
//******************************************************************************
//  Main Methods:
//  -------------
//    Overloaded draw methods for objects that may contain triangles. Some other
//    control methods have been overloaded too to ensure a complete tree
//    traversal.
//
//******************************************************************************

#include "SGInfra.h"

#include "CATDrawRender.h"
#include "CATVisGPUStorageManager.h"

typedef struct TrianglesInformations
{
  int Size;
  int Number;
} CATTCR_TRIANGLES_INFORMATIONS;

typedef struct LODsInformations
{
  int LODNumber;
  int NumberOfEltInLODs;
  int NumberOfSimpleTriangles;
  int NBStripInformations;
  int NBFanInformations;
  CATTCR_TRIANGLES_INFORMATIONS* LODStripInformations;
  CATTCR_TRIANGLES_INFORMATIONS* LODFanInformations;
} CATTCR_LODS_INFORMATIONS;

class ExportedBySGInfra CATTrianglesCountRender : public CATDrawRender
{
  public:

    CATTrianglesCountRender (const CATSupport &support);
    virtual ~CATTrianglesCountRender (void);

    virtual int IsDrawable (const CATGraphicAttributeSet &, const float *center, const float radius, const int SubElementId);
    virtual int IsDrawable (const CATGraphicAttributeSet &, const CAT3DBoundingSphere &, const CATRep &, CATGraphicMaterial *iMat = 0);
    virtual int IsDrawable (const CATGraphicAttributeSet &, const int SubElementId);
    virtual int IsDrawable (const CATGraphicAttributeSet &, const CATRep &,  CATGraphicMaterial *iMat = 0);
    virtual int IsDrawable (const CATGraphicAttributeSet &,CATGraphicMaterial *iMat );
    virtual int IsDrawable (const CATGraphicAttributeSet &);

    virtual int IsDrawable (const CATGraphicAttributeSet &, const CAT2DBoundingBox &, const CATRep &);
    virtual int IsDrawable (const CATGraphicAttributeSet &, const CAT2DBoundingBox &, const int);

    virtual int IsSeen  (const float*, const float*);

    int IsToSmall (const CAT3DBoundingSphere &);
    int IsToSmall (const CAT2DBoundingBox &);

    int IsInside  (const CAT3DBoundingSphere &);
    int IsInside  (const CAT2DBoundingBox &);

    float Get3DModelCulling (const CAT3DBoundingSphere &) const;
    int   Get3DLODNumber (const CAT3DBoundingSphere & iBS3D, const int iNbOfLOD, const float sagArray[] ) const;
    float Get3DModelSag (const CAT3DBoundingSphere & iBS3D) const;
    void DestroyAllVBO();

    virtual void Draw3DFace                (CAT3DFaceGP &);
    virtual void Draw3DPlanarFace          (CAT3DPlanarFaceGP &);
    virtual void Draw3DCylinder            (CAT3DCylinderGP &, const int = 0);
    virtual void Draw3DCurvedPipe          (CAT3DCurvedPipeGP &pipe);
    virtual void Draw3DEdge                (CAT3DEdgeGP &);
    virtual void DrawDynamicGP             (CATDynamicGP &);
    virtual void Draw3DBufferedFace        (CAT3DFaceGP &, int);
    virtual void Draw3DBufferedEdge        (CAT3DEdgeGP &);
    virtual void DrawVisPrimitive          (VisPrimitive &);
    virtual void DrawCATViz3DFace          (CATViz3DFace *);

    virtual int DrawRepresentation (CATRep &rep, int iInside, void* &iData);

    virtual int ViewMode (const int mode) const;

    virtual CATRender * PushMatrix (CAT4x4Matrix &);
    virtual CATRender * PushMatrix (CAT3x3Matrix &);
    virtual void PopMatrix         (CATRender *);

    virtual void PushReference (void);
    virtual void PopReference  (void);

    virtual void BeginDrawDL (CATVizElementType type);
    virtual void EndDrawDL   (CATVizElementType type);

    virtual void BeginDrawLeft  (CATViewpoint &viewpoint, const int, const float);
    virtual void BeginDrawRight (CATViewpoint &viewpoint, const int, const float);

    virtual void SaveBackBuffer     (char **);
    virtual void RestoreBackBuffer  (char **);

    // Result query:
    // -------------

    inline void GetStripTrianglesInformations(CATTCR_TRIANGLES_INFORMATIONS**, int*);
    inline void GetFanTrianglesInformations(CATTCR_TRIANGLES_INFORMATIONS**, int*);
    inline void GetLODsInformations(CATTCR_LODS_INFORMATIONS**, int*);
    inline void GetVBOInformations(unsigned int*, unsigned int*, unsigned int*, unsigned int*);
    inline void GetSceneSizeData (int *, float *);
    inline int GetSceneSizeVertices (void);
    inline void GetSceneSizeDataExtended (int* &idata, float *fdata);

    int GetSceneSize (void);

protected:
    void InternalDraw3DFace(float const* gp_vertices,
                            int          gp_vertices_arraysize,
                            float const* gp_normals,
                            int          gp_normals_arraysize,
                            int const*   gp_tri_indices,
                            int          nb_of_gp_tri,
                            int const*   gp_strip_indices,
                            int          nb_of_gp_strips,
                            int const*   gp_strip_size,
                            int const*   gp_fan_indices,
                            int          nb_of_gp_fans,
                            int const*   gp_fan_size);

protected:

    // Number of triangles of the scene:
    // ---------------------------------

    int _nb_triangles;
    int _nb_strip;
    int _nb_triangles_in_strip;
    int _nb_max_triangles_in_strip;
    int _nb_fan;
    int _nb_triangles_in_fan;
    int _nb_max_triangles_in_fan;

    int _nb_triangles_wo_vbo;
    int _nb_triangles_vbo;
    int _max_triangles_in_vbo;
    int _nb_triangles_merge_face_no_vbo;
    int _nb_triangles_not_yet_in_vbo;
    int _nb_triangles_simple_vbo;
    int _nb_triangles_in_strip_vbo;

    // Number of vertices for edges of the scene:
    // ------------------------------------------

    int _nb_vertices;

    // Number of Reps in the scene:
    //-----------------------------

    int   _nb_bagreps;      //number of bagreps
    int   _nb_null_mat;     //number of bagreps with a NULL pointer as matrix
    int   _nb_mat_id;       //number of bagreps with a matrix that is the identity matrix
    int   _nb_mat;          //number of bagreps with a matrix that is not the identity matrix
    int   _nb_min_faces;    //min number of faces per rep
    int   _nb_max_faces;    //max number of faces per rep
    int   _nb_total_faces;  //total number of faces
    int   _nb_min_edges;    //min number of edges per rep
    int   _nb_max_edges;    //max number of edges per rep
    int   _nb_total_edges;  //total number of edges
    int   _nb_min_topo_surf_edges;  //min number of topo surfacic edges (border/internal)
    int   _nb_max_topo_surf_edges;  //max number of topo surfacic edges (border/internal)
    int   _nb_surf_rep_holding_surf_edges;
    int   _nb_total_topo_surf_edges;  //total number of topo surfacic edges (border/internal)
    int   _nb_min_topo_wire_edges_hold_in_surf_reps;     //min number of wire edges per rep
    int   _nb_max_topo_wire_edges_hold_in_surf_reps;     //max number of wire edges per rep
    int   _nb_min_topo_wire_edges_hold_in_monowire_reps;     //min number of wire edges per rep
    int   _nb_max_topo_wire_edges_hold_in_monowire_reps;     //max number of wire edges per rep
    int   _nb_surf_rep_holding_wire_edges;
    int   _nb_monowire_rep_holding_wire_edges;
    int   _nb_total_topo_wire_edges_hold_in_surf_reps;   //total number of wire edges
    int   _nb_total_topo_wire_edges_hold_in_monowire_reps;   //total number of wire edges
    int   _nb_min_topo_points_hold_in_surf_reps;    //min number of points per rep
    int   _nb_max_topo_points_hold_in_surf_reps;    //max number of points per rep
    int   _nb_min_topo_points_hold_in_monowire_reps;    //min number of points per rep
    int   _nb_max_topo_points_hold_in_monowire_reps;    //max number of points per rep
    int   _nb_surf_rep_holding_points;
    int   _nb_monowire_rep_holding_points;
    int   _nb_total_topo_points_hold_in_surf_reps;  //total number of points
    int   _nb_total_topo_points_hold_in_monowire_reps;  //total number of points
    int   _vertexarray_size;//size of vertex arrays
    int   _normalarray_size;//size of normals arrays
    int   _indexarray_size; //size of index arrays
    int   _nb_topo_monowire_reps;    //number of monowires rep
    int   _nb_topo_surfacic_reps;     //number of surfacic reps
    int   _nb_null_surfreps;//number of surfacicreps without geometry
    int   _nb_geom_surfreps;//number of surfacicreps with geometry
    int   _nb_min_lods;     //min number of lods per Surfacicrep
    int   _nb_max_lods;     //min number of lods per Surfacicrep
    int   _nb_total_lods;   //total number of lods
    int   _nb_curvedpipegp; //numberof curvedpipegp
    int   _nb_cylindergp;   //number of cylindergp
    int   _nb_nbsurfreps_withmergeface;   //number of surfacic with a merge faceGP
    int   _nb_faces_geoms_surfreps; //number of surfacic with a faceGP
    int   _nb_ibo_no_lod; //number of surfacic with a faceGP


    void AddInformations(CATTCR_TRIANGLES_INFORMATIONS**, int*, int);

    CATTCR_TRIANGLES_INFORMATIONS* _strip_informations;
    int _nb_strip_informations;

    CATTCR_TRIANGLES_INFORMATIONS* _fan_informations;
    int _nb_fan_informations;

    CATTCR_LODS_INFORMATIONS* _lod_informations;
    int _nb_lod_informations;
};


inline void CATTrianglesCountRender::GetSceneSizeDataExtended (int* &idata, float *fdata)
{
 if(idata)
 {
   free(idata);
   idata=NULL;
 }
 idata= (int*) malloc(45*sizeof(int));

 if(!idata) return;

 idata[0]=_nb_triangles+_nb_triangles_in_strip+_nb_triangles_in_fan+_nb_triangles_vbo;
 idata[1]=_nb_triangles+_nb_triangles_simple_vbo;
 idata[2]=_nb_strip;
 idata[3]=_nb_max_triangles_in_strip;
 idata[4]=_nb_fan;
 idata[5]=_nb_max_triangles_in_fan;

 idata[6]=_nb_bagreps;
 idata[7]=_nb_mat_id+_nb_mat;
 idata[8]=_nb_min_faces;
 idata[9]=_nb_max_faces;
 idata[10]=_nb_min_edges;
 idata[11]=_nb_max_edges;
 idata[12]=_vertexarray_size;
 idata[13]=_normalarray_size;
 idata[14]=_indexarray_size;
 idata[15]=_nb_min_lods;
 idata[16]=_nb_max_lods;
 idata[17]=_nb_topo_surfacic_reps + _nb_topo_monowire_reps;

 idata[18]=_nb_null_mat;
 idata[19]=_nb_mat_id;
 idata[20]=_nb_mat;

 idata[21]=_nb_null_surfreps;
 idata[22]=_nb_geom_surfreps;

 idata[23]=_nb_min_topo_surf_edges;
 idata[24]=_nb_max_topo_surf_edges;
 idata[25]=_nb_total_topo_surf_edges;

 idata[26]=_nb_min_topo_wire_edges_hold_in_surf_reps;
 idata[27]=_nb_max_topo_wire_edges_hold_in_surf_reps;
 idata[28]=_nb_min_topo_wire_edges_hold_in_monowire_reps;
 idata[29]=_nb_max_topo_wire_edges_hold_in_monowire_reps;
 idata[30]=_nb_total_topo_wire_edges_hold_in_surf_reps + _nb_total_topo_wire_edges_hold_in_monowire_reps;

 idata[31]=_nb_min_topo_points_hold_in_surf_reps;
 idata[32]=_nb_max_topo_points_hold_in_surf_reps;
 idata[33]=_nb_min_topo_points_hold_in_monowire_reps;
 idata[34]=_nb_max_topo_points_hold_in_monowire_reps;
 idata[35]=_nb_total_topo_points_hold_in_surf_reps + _nb_total_topo_points_hold_in_monowire_reps;

 idata[36]=_nb_topo_monowire_reps;
 idata[37]=_nb_topo_surfacic_reps;

 // Migrer CATIAApplicationFrame et RenderingEngine sur nouvelle method
 // realisant l'allocation (cf cross-ref)
 idata[38]=_nb_nbsurfreps_withmergeface;
 idata[39]=_nb_faces_geoms_surfreps;
 idata[40]=_nb_triangles_vbo;
 idata[41]=_nb_triangles_not_yet_in_vbo;
 idata[42]=_max_triangles_in_vbo;
 idata[43]=_nb_triangles_merge_face_no_vbo;
 idata[44]=_nb_ibo_no_lod;

 //idata[45]=_nb_triangles_not_yet_in_vbo;

 if (_nb_strip == 0)
  fdata[0]=0.f;
 else
  fdata[0]=((float)(_nb_triangles_in_strip + _nb_triangles_in_strip_vbo))/((float)(_nb_strip));

 if (_nb_fan == 0)
  fdata[1]=0.f;
 else
  fdata[1]=((float)(_nb_triangles_in_fan))/((float)(_nb_fan));

 if (_nb_total_faces == 0)
   fdata[2]=0.f;
 else
   fdata[2]=((float)(_nb_total_faces))/((float)(_nb_topo_surfacic_reps));

 if (_nb_total_topo_surf_edges == 0)
   fdata[3]=0.f;
 else
   fdata[3]=((float)(_nb_total_topo_surf_edges))/((float)(_nb_surf_rep_holding_surf_edges));

 if (_nb_total_lods == 0)
   fdata[4]=0.f;
 else
   fdata[4]=((float)(_nb_total_lods))/((float)(_nb_topo_surfacic_reps));

  if (_nb_total_topo_surf_edges == 0)
   fdata[5]=0.f;
 else
   fdata[5]=((float)(_nb_total_topo_surf_edges))/((float)(_nb_topo_surfacic_reps));

 if (_nb_total_topo_wire_edges_hold_in_surf_reps == 0)
   fdata[6]=0.f;
 else
   fdata[6]=((float)(_nb_total_topo_wire_edges_hold_in_surf_reps))/((float)(_nb_surf_rep_holding_wire_edges));

 if (_nb_total_topo_wire_edges_hold_in_monowire_reps == 0)
   fdata[7]=0.f;
 else
   fdata[7]=((float)(_nb_total_topo_wire_edges_hold_in_monowire_reps))/((float)(_nb_monowire_rep_holding_wire_edges));

 if (_nb_total_topo_points_hold_in_surf_reps == 0)
   fdata[8]=0.f;
 else
   fdata[8]=((float)(_nb_total_topo_points_hold_in_surf_reps))/((float)(_nb_surf_rep_holding_points));

 if (_nb_total_topo_points_hold_in_monowire_reps == 0)
   fdata[9]=0.f;
 else
   fdata[9]=((float)(_nb_total_topo_points_hold_in_monowire_reps))/((float)(_nb_monowire_rep_holding_points));
}

inline void CATTrianglesCountRender::GetSceneSizeData (int *idata, float *fdata)
{
 idata[0]=_nb_triangles+_nb_triangles_in_strip+_nb_triangles_in_fan+_nb_triangles_vbo;
 idata[1]=_nb_triangles+_nb_triangles_simple_vbo;
 idata[2]=_nb_strip;
 idata[3]=_nb_max_triangles_in_strip;
 idata[4]=_nb_fan;
 idata[5]=_nb_max_triangles_in_fan;

 idata[6]=_nb_bagreps;
 idata[7]=_nb_mat_id+_nb_mat;
 idata[8]=_nb_min_faces;
 idata[9]=_nb_max_faces;
 idata[10]=_nb_min_edges;
 idata[11]=_nb_max_edges;
 idata[12]=_vertexarray_size;
 idata[13]=_normalarray_size;
 idata[14]=_indexarray_size;
 idata[15]=_nb_min_lods;
 idata[16]=_nb_max_lods;
 idata[17]=_nb_topo_surfacic_reps + _nb_topo_monowire_reps;

 idata[18]=_nb_null_mat;
 idata[19]=_nb_mat_id;
 idata[20]=_nb_mat;

 idata[21]=_nb_null_surfreps;
 idata[22]=_nb_geom_surfreps;

 idata[23]=_nb_min_topo_surf_edges;
 idata[24]=_nb_max_topo_surf_edges;
 idata[25]=_nb_total_topo_surf_edges;

 idata[26]=_nb_min_topo_wire_edges_hold_in_surf_reps;
 idata[27]=_nb_max_topo_wire_edges_hold_in_surf_reps;
 idata[28]=_nb_min_topo_wire_edges_hold_in_monowire_reps;
 idata[29]=_nb_max_topo_wire_edges_hold_in_monowire_reps;
 idata[30]=_nb_total_topo_wire_edges_hold_in_surf_reps + _nb_total_topo_wire_edges_hold_in_monowire_reps;

 idata[31]=_nb_min_topo_points_hold_in_surf_reps;
 idata[32]=_nb_max_topo_points_hold_in_surf_reps;
 idata[33]=_nb_min_topo_points_hold_in_monowire_reps;
 idata[34]=_nb_max_topo_points_hold_in_monowire_reps;
 idata[35]=_nb_total_topo_points_hold_in_surf_reps + _nb_total_topo_points_hold_in_monowire_reps;

 idata[36]=_nb_topo_monowire_reps;
 idata[37]=_nb_topo_surfacic_reps;
 /*
 // Migrer CATIAApplicationFrame et RenderingEngine sur nouvelle method
 // realisant l'allocation (cf cross-ref)
 idata[38]=_nb_nbsurfreps_withmergeface;
 idata[39]=_nb_faces_geoms_surfreps;
 idata[40]=_nb_triangles_vbo;
 idata[41]=_nb_triangles_not_yet_in_vbo;
 idata[42]=_max_triangles_in_vbo;
 idata[43]=_nb_triangles_merge_face_no_vbo;
 idata[44]=_nb_ibo_no_lod;
 */
 //idata[45]=_nb_triangles_not_yet_in_vbo;

 if (_nb_strip == 0)
  fdata[0]=0.f;
 else
  fdata[0]=((float)(_nb_triangles_in_strip + _nb_triangles_in_strip_vbo))/((float)(_nb_strip));

 if (_nb_fan == 0)
  fdata[1]=0.f;
 else
  fdata[1]=((float)(_nb_triangles_in_fan))/((float)(_nb_fan));

 if (_nb_total_faces == 0)
   fdata[2]=0.f;
 else
   fdata[2]=((float)(_nb_total_faces))/((float)(_nb_topo_surfacic_reps));

 if (_nb_total_topo_surf_edges == 0)
   fdata[3]=0.f;
 else
   fdata[3]=((float)(_nb_total_topo_surf_edges))/((float)(_nb_surf_rep_holding_surf_edges));

 if (_nb_total_lods == 0)
   fdata[4]=0.f;
 else
   fdata[4]=((float)(_nb_total_lods))/((float)(_nb_topo_surfacic_reps));

  if (_nb_total_topo_surf_edges == 0)
   fdata[5]=0.f;
 else
   fdata[5]=((float)(_nb_total_topo_surf_edges))/((float)(_nb_topo_surfacic_reps));

 if (_nb_total_topo_wire_edges_hold_in_surf_reps == 0)
   fdata[6]=0.f;
 else
   fdata[6]=((float)(_nb_total_topo_wire_edges_hold_in_surf_reps))/((float)(_nb_surf_rep_holding_wire_edges));

 if (_nb_total_topo_wire_edges_hold_in_monowire_reps == 0)
   fdata[7]=0.f;
 else
   fdata[7]=((float)(_nb_total_topo_wire_edges_hold_in_monowire_reps))/((float)(_nb_monowire_rep_holding_wire_edges));

 if (_nb_total_topo_points_hold_in_surf_reps == 0)
   fdata[8]=0.f;
 else
   fdata[8]=((float)(_nb_total_topo_points_hold_in_surf_reps))/((float)(_nb_surf_rep_holding_points));

 if (_nb_total_topo_points_hold_in_monowire_reps == 0)
   fdata[9]=0.f;
 else
   fdata[9]=((float)(_nb_total_topo_points_hold_in_monowire_reps))/((float)(_nb_monowire_rep_holding_points));
}

inline int CATTrianglesCountRender::GetSceneSizeVertices (void)
{
  return _nb_vertices;
}

inline void CATTrianglesCountRender::GetStripTrianglesInformations(CATTCR_TRIANGLES_INFORMATIONS** TrianglesStripInfo, int* NbTrianglesStripInfo)
{
  *TrianglesStripInfo    = _strip_informations;
  *NbTrianglesStripInfo  = _nb_strip_informations;
}

inline void CATTrianglesCountRender::GetFanTrianglesInformations(CATTCR_TRIANGLES_INFORMATIONS** TrianglesFanInfo, int* NbTrianglesFanInfo)
{
  *TrianglesFanInfo    = _fan_informations;
  *NbTrianglesFanInfo  = _nb_fan_informations;
}

inline void CATTrianglesCountRender::GetLODsInformations(CATTCR_LODS_INFORMATIONS** LODsInfos, int* NbLODsInfos)
{
  *LODsInfos    = _lod_informations;
  *NbLODsInfos  = _nb_lod_informations;
}

inline void CATTrianglesCountRender::GetVBOInformations(unsigned int* NbVBO, unsigned int* NbIBO, unsigned int* _GPUMemoryVBO, unsigned int* _GPUMemoryIBO)
{
    *NbVBO         = 0;
    *NbIBO         = 0;
    *_GPUMemoryVBO = 0;
    *_GPUMemoryIBO = 0;

    if(_pGPUStorageManager)
    {
      _pGPUStorageManager->GetNbVBO(NbVBO,1);
      _pGPUStorageManager->GetNbVBO(NbIBO,0);
      _pGPUStorageManager->GetMemoryUsed(_GPUMemoryVBO,1);
      _pGPUStorageManager->GetMemoryUsed(_GPUMemoryIBO,0);
    }
}

#endif
