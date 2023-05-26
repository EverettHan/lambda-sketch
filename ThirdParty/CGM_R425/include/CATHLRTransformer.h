#ifndef CATHLRTransformer_H
#define CATHLRTransformer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRTransformer 
//
/** class to fill a vector or a point, of s surface specifity
 * being the transformation of another one.
 *
 * <BR> DESCRIPTION : the matrix is considered as an array of 12 double, ordered
 * column after column, the last one being the translation. A transformation
 * that is a NULL pointer means that no transformation should be applied.
 */
//
//=============================================================================
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Jan. 98 JCH Creation            
// Jun. 99 HKL Added TransformTorus method
//             Added MathBox transformation
//             Added inverse transformation support
//
//=============================================================================

#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathBox.h"
#include "CATMathDirection.h"
#include "CATHLRTransformation.h"

// For Windows NT
#include "HLRGeometry.h"

class CATHLRCircleSpec;
class CATHLRConeSpec;
class CATHLRCurveSpec;
class CATHLRCylinderSpec;
class CATHLRLineSpec;
class CATHLRMemoryManager;
class CATHLRPlaneSpec;
class CATHLRSphereSpec;
class CATHLRTorusSpec;
class CATHLRSurfaceSpec;


// The same with a CATHLRTransformation
inline void Transform(const CATHLRTransformation * iTransformation,
		      CATMathPoint & iPoint);

inline void InverseTransform(const CATHLRTransformation * iTransformation,
                             CATMathPoint & iPoint);

// The transformation is directly applied to the vector
inline void Transform(const CATHLRTransformation * iTransformation,
		      CATMathVector & iVector);

inline void InverseTransform(const CATHLRTransformation * iTransformation,
                             CATMathVector & iVector);


inline void Transform(const CATHLRTransformation * iTransformation,
		      CATMathDirection & iDirection);

inline void InverseTransform(const CATHLRTransformation * iTransformation,
                             CATMathDirection & iDirection);

// Transforms the specificity of a surface or curve. The object is created in the
// memory manager given in entry
class ExportedByHLRGeometry CATHLRTransformer
{
public:
//=============================================================================
// CONSTRUCTOR AND DESTRUCTOR
//=============================================================================
/** Constructor with a memory manager in which will be put the created objects,
 * and a pointer on the transformation to apply ( that may be NULL for identity).
 */
  CATHLRTransformer(CATHLRMemoryManager        * iManager,
		    const CATHLRTransformation * iTransformation);

/** Destructor
 */
  ~CATHLRTransformer();

//=============================================================================
// Methods
//=============================================================================
/** Transforms a surface's specification.
 */
  CATHLRSurfaceSpec *  Apply(CATHLRSurfaceSpec * iSurfaceSpec);
/** Transforms a curve's specification.
 */
  CATHLRCurveSpec *  Apply(CATHLRCurveSpec * iCurveSpec);

/** Gets the transformation that is applied.
 */
  inline const CATHLRTransformation * GetTransformation();

/** Gets the memory manager for the objects.
 */
  inline CATHLRMemoryManager * GetMemoryManager() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Transformation to apply
  const CATHLRTransformation * _Transformation;

// Working datas
  CATMathPoint     _Origin, _OtherPoint;
  CATMathDirection _DirectionA, _Normal;

// Memory manager in which the objects will be put.
  CATHLRMemoryManager * _MemoryManager;

//------------------------------------------------------------
// Internal functions
//------------------------------------------------------------
  CATHLRPlaneSpec    * TransformPlane   (CATHLRPlaneSpec      * iPlaneSpec);
  CATHLRConeSpec     * TransformCone    (CATHLRConeSpec       * iConeSpec);
  CATHLRCylinderSpec * TransformCylinder(CATHLRCylinderSpec   * iCylinderSpec);
  CATHLRSphereSpec   * TransformSphere  (CATHLRSphereSpec     * iSphereSpec);
  CATHLRTorusSpec    * TransformTorus   (CATHLRTorusSpec      * iTorusSpec);

  CATHLRLineSpec     * TransformLine    (CATHLRLineSpec   * iLineSpec);
  CATHLRCircleSpec   * TransformCircle  (CATHLRCircleSpec * iCircleSpec);

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

// Same with a CATHLRTransformation
inline void Transform(const CATHLRTransformation * Transform,
		      CATMathPoint & Point)
{
  if (Transform)
    {
      const double * Trs = Transform->GetMatrixValues();
      double X, Y , Z; 
      Point.GetCoord(X, Y, Z);
      Point.SetCoord(Trs[0] * X + Trs[3] * Y + Trs[6]* Z + Trs[9],
		     Trs[1] * X + Trs[4] * Y + Trs[7]* Z + Trs[10],
		     Trs[2] * X + Trs[5] * Y + Trs[8]* Z + Trs[11]);
    }
}

inline void InverseTransform(const CATHLRTransformation * Transform,
                             CATMathPoint & Point)
{
  if (Transform)
    {
      const double * Trs = Transform->GetInverseMatrixValues();
      double X, Y , Z; 
      Point.GetCoord(X, Y, Z);
      Point.SetCoord(Trs[0] * X + Trs[3] * Y + Trs[6]* Z + Trs[9],
		     Trs[1] * X + Trs[4] * Y + Trs[7]* Z + Trs[10],
		     Trs[2] * X + Trs[5] * Y + Trs[8]* Z + Trs[11]);
    }
}

//------------------------------------------------------------
// For the Directions : no translation

inline void Transform(const CATHLRTransformation * Transform,
		      CATMathVector & Vector)
{
 if (Transform)
    {
      const double * Trs = Transform->GetMatrixValues();
      double X, Y , Z;
      Vector.GetCoord(X, Y, Z);
      Vector.SetCoord(Trs[0] * X + Trs[3] * Y + Trs[6]* Z ,
		      Trs[1] * X + Trs[4] * Y + Trs[7]* Z ,
		      Trs[2] * X + Trs[5] * Y + Trs[8]* Z );
    }
}

inline void Transform(const CATHLRTransformation * Transform,
		      CATMathDirection & Direction)
{
  if (Transform)
    {
      const double * Trs = Transform->GetMatrixValues();
      double X, Y , Z;
      Direction.GetCoord(X, Y, Z);
      Direction.SetCoord(Trs[0] * X + Trs[3] * Y + Trs[6]* Z ,
			 Trs[1] * X + Trs[4] * Y + Trs[7]* Z ,
			 Trs[2] * X + Trs[5] * Y + Trs[8]* Z );
    }
}

inline void InverseTransform(const CATHLRTransformation * Transform,
                             CATMathVector & Vector)
{
 if (Transform)
    {
      const double * Trs = Transform->GetInverseMatrixValues();
      double X, Y , Z;
      Vector.GetCoord(X, Y, Z);
      Vector.SetCoord(Trs[0] * X + Trs[3] * Y + Trs[6]* Z ,
		      Trs[1] * X + Trs[4] * Y + Trs[7]* Z ,
		      Trs[2] * X + Trs[5] * Y + Trs[8]* Z );
    }
}

inline void InverseTransform(const CATHLRTransformation * Transform,
                             CATMathDirection & Direction)
{
  if (Transform)
    {
      const double * Trs = Transform->GetInverseMatrixValues();
      double X, Y , Z;
      Direction.GetCoord(X, Y, Z);
      Direction.SetCoord(Trs[0] * X + Trs[3] * Y + Trs[6]* Z ,
			 Trs[1] * X + Trs[4] * Y + Trs[7]* Z ,
			 Trs[2] * X + Trs[5] * Y + Trs[8]* Z );
    }
}

//------------------------------------------------------------
// For the Boxes: same as points

inline void Transform(const CATHLRTransformation * Transform,
		      CATMathBox & Box)
{
  if (Transform)
    {
      double xmin, xmax, ymin, ymax, zmin, zmax;
      Box.GetExtremities(xmin, xmax, ymin, ymax, zmin, zmax);
      CATMathPoint p1(xmin, ymin, zmin);
      CATMathPoint p2(xmin, ymin, zmax);
      CATMathPoint p3(xmin, ymax, zmin);
      CATMathPoint p4(xmin, ymax, zmax);
      CATMathPoint p5(xmax, ymin, zmin);
      CATMathPoint p6(xmax, ymin, zmax);
      CATMathPoint p7(xmax, ymax, zmin);
      CATMathPoint p8(xmax, ymax, zmax);
      
      ::Transform(Transform, p1);
      ::Transform(Transform, p2);
      ::Transform(Transform, p3);
      ::Transform(Transform, p4);
      ::Transform(Transform, p5);
      ::Transform(Transform, p6);
      ::Transform(Transform, p7);
      ::Transform(Transform, p8);

      Box.SetToEmpty();
      Box.AddInside(p1);
      Box.AddInside(p2);
      Box.AddInside(p3);
      Box.AddInside(p4);
      Box.AddInside(p5);
      Box.AddInside(p6);
      Box.AddInside(p7);
      Box.AddInside(p8);
    }
}

//=============================================================================
// INLINE METHODS
//=============================================================================
inline const CATHLRTransformation * CATHLRTransformer::GetTransformation()
{
  return _Transformation;
}

//-----------------------------------------------------------------------------

inline CATHLRMemoryManager * CATHLRTransformer::GetMemoryManager() const
{
  return _MemoryManager;
}

#endif
