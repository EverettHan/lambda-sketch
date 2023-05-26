#ifndef CAT_3DCYLINDER_OUTLINE_BUILDER_H
#define CAT_3DCYLINDER_OUTLINE_BUILDER_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//    Computes the outlines of a given 3DCylinder 
//   
//
//******************************************************************************
//  Usage:
//  ------
//    First, Cylinder parameters  have to be added. Second, visualization parameters
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
//  Inheritance:  CAT3DCylinderOutlineBuilder
//  		     CATOutlineBuilder
//                
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************
#include "SGInfra.h"
#include "CATOutlineBuilder.h"

class ExportedBySGInfra CAT3DCylinderOutlineBuilder : public CATOutlineBuilder
{
  public:
    
    // Construction and destruction methods:
    // -------------------------------------
    CAT3DCylinderOutlineBuilder          (void);
    virtual ~CAT3DCylinderOutlineBuilder (void);
    
    // Tesselation addition method:
    // ----------------------------
    //   <tesselation_id> is an identifier for the added tesselation. Each
    //   created outline belongs to one or two tesselations and is returned with
    //   the identifiers for those tesselations.
    void AddTesselation (float *bottom_vertex, int nb_vertices, float *body_normals, float *extrusion, float *direction);
    
    // Outlines computation methods:
    // -----------------------------
    //   - ComputeOutlines: Internally performs the generation of outlines.
    //
    virtual void ComputeOutlines     (void);
    
  private:

    float *_bottom_vertex;
    float *_top_vertex;
    float *_body_normals;
    float *_direction;
    int _nb_vertices;
};

#endif
