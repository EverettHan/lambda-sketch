//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract: Used when calling DrawMenb
//
//------------------------------------------------------------------------------
// Usage:
//------------------------------------------------------------------------------


#ifdef _SUNOS_SOURCE

#ifndef CATSUNCONST_H
#define CATSUNCONST_H

#define SUN_GRAPHICSBOARD 99
#define SUN_FFB3     1
#define SUN_EXP3D    2
#define SUN_CREA3D   3
#define SUN_XVR500   4
#define SUN_ELIT3D   5
#define SUN_XVR1200  6
#define SUN_XVR4000  7

#define SUN_OPTI_NONE  0
#define SUN_OPTI_EDGE  1
#define SUN_OPTI_FACE  2
#define SUN_OPTI_ALL   4

static const int SUN_NONE_MASK = 0; 
static const int SUN_EDGE_MASK = 5; 
static const int SUN_FACE_MASK = 6; 
static const int SUN_ALL_MASK  = 4; 

#endif

#endif

