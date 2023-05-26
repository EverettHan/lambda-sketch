#ifndef CATHLRCONSTANT_H
#define CATHLRCONSTANT_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRConstant : special class for defining constants with a limited
// visibility for the framework hlr
//
// DESCRIPTION : there is no implementation. This is used to have constants
// by CATHLRConstant::...
//
//=============================================================================
// Abstract Class     : Yes
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

#include "CATDataType.h"
// Ids of the objects in a CATHLRComputer.
typedef CATLONG32 CATHLRId;

class CATHLRConstant
{
public:
// Type of the output of an element by the HLR
  enum TypeVisibility {Visible, Hidden, Null, Occluded, Smooth};

// OcclusionType of the output of an element by the HLR
  enum TypeOcclusion {None, Left, Right, Both, Undefined};

// Types of projection
  enum TypeProjection {Cylindrical, Conical, Unknown }; 

// Types of edges
  enum TypeEdge { NonReflect, Reflect, Border };

// Types of edges
  enum Vivicity { NonVivid, Vivid, UnknownVivicity};

// Position of a node on a sub-edge
  enum PositionOnEdge {BeginningOfEdge, EndOfEgde}; 

// Types of curves recognised by the HLR. Spline if for any curve.
  enum TypeCurve { Spline, Line, Circle, Helix, PolyLine }; 

// Types of surfaces recognied by the HLR 
//  - Generic is any surface with no specificity 
  enum TypeSurface {Generic, Plane, Sphere, Cone, Cylinder, Torus, PolyMesh, Nurbs };

// IsoParameters
  //  enum Isopar { IsoNoDir = 0, IsoParamU = 1, IsoParamV = 2, IsoBothDir = 3}; 

private:
// Disables the instanciation of the class
  inline CATHLRConstant();
  inline ~CATHLRConstant();
};

//=============================================================================
// UNUSED INLINE IMPLEMENTATION (but needed on NT)
//=============================================================================
inline CATHLRConstant::CATHLRConstant()
{
  // Nothing to do
}

inline CATHLRConstant::~CATHLRConstant()
{
  // Nothing to do
}

#endif
