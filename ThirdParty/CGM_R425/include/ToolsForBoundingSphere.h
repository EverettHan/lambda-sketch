#ifndef TOOLS_FOR_BOUNDING_SPHERE_H
#define TOOLS_FOR_BOUNDING_SPHERE_H
#include "SGInfra.h"
//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1997
//******************************************************************************
//  Abstract:
//  ---------
//    Required functions to compute an optimized bounding sphere enclosing a
//    given set of vertices.
//
//******************************************************************************
//  Usage:
//  ------
//    Two functions are provided for the computation of the bounding sphere:
//      - Create a bounding sphere from a set of vertices,
//      - Update an existing bounding sphere with a new set of vertices.
//    The list of vertices is made of (XYZXYZXYZ...) coordinates, the given size
//    is the array size, not the number of vertices.
//
//  Memory behavior:
//  ----------------
//    <center> parameter is not allocated by these routines.
//
//******************************************************************************
//  Functions description:
//  ----------------------
//    - CreateBoundingSphere: Generate the bounding sphere from a vertex list,
//    - UpdateBoundingSphere: Update a bounding sphere from a new vertex list.
//
//******************************************************************************
//  Creation 08.01.97                                                      RDS
//******************************************************************************

void ExportedBySGInfra CreateBoundingSphere (float *center,float *radius,
			   float const *vertex,int vertex_array_size, float toleranceScale);

void ExportedBySGInfra CreateBoundingSphere (float *center,float *radius,
			   float const *vertex,int vertex_array_size);

void UpdateBoundingSphere (float *center,float *radius,
			   float const *vertex,int vertex_array_size);


#endif
