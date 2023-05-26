#ifndef CAT_OUTLINE_BUILDER_H
#define CAT_OUTLINE_BUILDER_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    Computes the outlines of a given tesselation set. Given tesselation sets
//    are to be merged once the computation is requested, and outlines produced.
//
//******************************************************************************
//  Usage:
//  ------
//    First, tesselations have to be added. Second, visualization parameters
//    have to be properly set. When this is finished, a call to
//    ComputeOutlines can be performed in order to produce the outlines.
//    Call sequence looks like this:
//      . SetViewing parameters(...)
//      . AddTesselation(...)
//      . AddTesselation(...)
//      . AddTesselation(...)
//      . ComputeOutlines(...)
//    If this sequence is repeated, only updates are to occur in the builder,
//    so the result is computed faster.
//    If a ClearOutlines occurs, the builder is entirely reseted, and the next
//    computation will rebuild everything.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                NONE.
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************
#include "SGInfra.h"

class ExportedBySGInfra CATOutlineBuilder
{
  public:
    
    // Construction and destruction methods:
    // -------------------------------------
    CATOutlineBuilder          (void);
    virtual ~CATOutlineBuilder (void);
    
    // Tolerance definition methods:
    // -----------------------------
    //   The iToleranceScale parameter differs according to the part model size.
	//   It is set to 1.0 in classic world
	//   It is superior to 1 in large world
	//   It is inferior to 1 in small world.
    
    inline void SetToleranceScale(float iToleranceScale);

    // Activate/Deactivate management of boundary bars
    // 1) border bars (1 only adjacent triangle) will be considered as outlines (Default value).
    // 1) border bats (1 only adjacent triangle) will not be considered as outlines. 

    inline void SetBoundaryBarMode(char iMode) {_boundary_bars = (iMode == 0) ? 0 : 1;};

    // Configuration methods:
    // ----------------------
    //   The <proj_type> parameter refers to the type of visualization projec-
    //   tion applied to the scene; 1: Conic, 0: Cylindric.
    inline void SetViewingParameters (float *eye_position, float *sight, int proj_type);
    
    // Tesselation addition method:
    // ----------------------------
    //   <tesselation_id> is an identifier for the added tesselation. Each
    //   created outline belongs to one or two tesselations and is returned with
    //   the identifiers for those tesselations.
    void AddTesselation (float const* vertices,
                         int   const* triangle_index,
                         int          nb_triangle,
                         int   const* strip_index,
                         int   const* strip_size,
                         int          nb_triangle_strip,
                         int   const* fan_index,
                         int   const* fan_size,
                         int          nb_triangle_fan,
                         int        * tesselation_id);
    
    // Outlines computation methods:
    // -----------------------------
    //   - ComputeOutlines: Internally performs the generation of outlines.
    //   - GetOutlines: <segments> has the format XYZ XYZ XYZ XYZ...
    //   where two consecutive vertices are defining a line segment. <id> has
    //   the format: n m n m... Where a line segment belongs to the n and m
    //   tesselations. Parameters are shared with the object, and can be deleted
    //   using the ClearOutlines method only.
    //
    //   - ClearOutlinesTables: Deletes all information stored during the first
    //   sequence. Builder is entirely reseted.
    //   - ClearOutlines: Deletes the produced outlines only, leaving all
    //   parameters ready for a fast computation during the next sequence.
    virtual void ComputeOutlines     (void);
    inline void GetOutlines  (float **segments,int *nb_segments,int ***id);
    void ClearOutlinesTables (void);
    void ClearOutlines       (void);
    
  protected:
    
    // Visualization parameters:
    // -------------------------
    float          _eye_position[3];      // Observer position.
    float          _sight[3];             // Observer looking at direction.
    char           _proj_type;            // 1: Conic, 0: Cylindric.
    char           _boundary_bars;        // 1: Boundary bars considered as outlines, 0 Boundary bars not considered as outlines.
    
    // Internal tables for outlines generation:
    // ----------------------------------------
    char           _complete;             // 1: Internal tables are ready.
    
    int            _size_mem_triangles;   // Memory size for triangles.
    int            _nb_mem_triangles;     // Memory size for triangles.
    int            _nb_triangles;         // Number of triangles for the object.
    signed char   *_triangle;             // Triangle viewability (1,-1).
    signed char   *_trianglePlanar;       // Triangle coplanarity (0, 1).

    int            _size_mem_edges;       // Memory size for edges.
    int            _nb_mem_edges;         // Memory size for edges.
    int            _nb_edges;             // Number of edges for the objet.
    float         *_p;                    // Edge list: XYZXYZ XYZXYZ...
    int          (*_ref)[2];              // Edges triangles references.
    int        *((*_id)[2]);              // Edges tesselation identifiers.
    
    // Computation results:
    // --------------------
    float         *_lines_segments;       // Lines:       XYZXYZ XYZXYZ XYZXYZ..
    int          **_segment_id;           // Identifiers:  n  m   n  m   n  m...
    int            _nb_segments;          // Number of resulting line segments.
    
    // Internal methods:
    // -----------------
    void SightVector (float const*P,float *vector);
    void TriangleNormalDirection (float const*P,float const*Q,float const*R,float *n);
    void AddEdge (float const*P,float const*Q,int ref1,int ref2,int *id1,int *id2);
    
  private:
    //used to check if 2 vectors are colinear
    int SameDirection(float *N1, float *N2);

  protected:
    float _ToleranceScale;

};

//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************
inline void CATOutlineBuilder::SetViewingParameters (float *eye_position, float *sight, int proj_type)
{
   _eye_position[0] = eye_position[0];
   _eye_position[1] = eye_position[1];
   _eye_position[2] = eye_position[2];
   _sight[0]        = sight[0];
   _sight[1]        = sight[1];
   _sight[2]        = sight[2];
   _proj_type       = proj_type ? 1:0;
}


inline void CATOutlineBuilder::GetOutlines (float **segments, int *nb_segments, int ***id)
{
   *segments=_lines_segments;
   *nb_segments=_nb_segments;
   *id=_segment_id;
}
inline void CATOutlineBuilder::SetToleranceScale(float iToleranceScale)
{
    _ToleranceScale = iToleranceScale;
}

#endif
