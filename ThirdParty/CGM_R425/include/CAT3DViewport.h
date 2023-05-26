#ifndef CAT3DViewport_H
#define CAT3DViewport_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines a 3D bounding object (n planes)
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by viewer at draw time to define a box where
// ------       representations are supposed to be seen. 
//              (this is used at culling time to avoid to draw representations
//               which bounding sphere is outside of this box)
//
//------------------------------------------------------------------------------
// Class :      CAT3DViewport
// -------        CATViewport
//                  
//------------------------------------------------------------------------------
#include "CATViewport.h"

#include "CAT3DBoundingSphere.h"

#include "CATMathPointf.h"
#include "CATMathPoint.h"
#include "CATMathVectorf.h"
#include "CATMathDirectionf.h"
#include "CAT4x4Matrix.h"
#include "CATMath.h"

#ifdef _IRIX_SOURCE
 //Ia64+
#include "CATDataType.h"
//Ia64-
/** @nodoc */
extern CATINTPTR DrawMenb (int);
#endif

/**
 *
 * Class that defines a 2D clipping area.
 *
 */
class ExportedBySGInfra CAT3DViewport : public CATViewport
{
 CATDeclareClass;

 public :

 /** @nodoc */
  CAT3DViewport ();
 /** @nodoc */
  CAT3DViewport(const CAT3DViewport &viewport);
 /** @nodoc */
  CAT3DViewport (const int, const float [], const float [], const float [], const float []);
 /** @nodoc */
  CAT3DViewport (const int, const CATMathPointf [], const CATMathDirectionf []);
 /** @nodoc */
  CAT3DViewport (const int, const CATMathPoint [], const CATMathDirectionf []);

 /** @nodoc */
  void Set (const int nbPlanes, const CATMathPoint point[], const CATMathDirectionf normal[]);

   /**
    *  Affectation operator.
    *  @param viewport  A reference to3D the CAT3DViewport we want to copy  into this one.
    *  @return A reference to this CATViewport
    */
  CAT3DViewport & operator = (const CAT3DViewport &viewport);

  virtual ~CAT3DViewport ();

  /**
   *  Duplicates the Viewport.
   *  @return the copy of this CATViewport
   */
  virtual CATViewport *Clone() const;
  /**
   * Duplicate a Viewport.
   * @param iViewport A pointer to the pointer on the CATViewport into wich we want to duplicate this CATViewport.
   * @return A pointer to the Duplicated CATviewport
   */
  virtual CATViewport *Clone(CATViewport **) const;

  /** 
   * Add the clipping planes of one CAT3DViewport to this one.
   * @param iFrom the CAT3DViewport of which we add the clipping planes
   */
  CAT3DViewport & operator += (const CAT3DViewport &iFrom);
  /** 
   * Remove the clipping planes of one CAT3DViewport to this one.
   * @param iFrom the CAT3DViewport of which we add the clipping planes
   * Use only if you added that CAT3DViewport clipping planes to this CAT3DViewport, and
   * did not add any other in the meantime.
   */
  CAT3DViewport & operator -= (const CAT3DViewport &iFrom);\
  /**
  * Apply the geometric transformatin defined by the CAT4x4Matrix to the clipping planes.
  *  @param iMatrix the transformation to apply.
  */
  CAT3DViewport & operator *= (const CAT4x4Matrix &iMatrix);

  /**
  * Retrieves whether viewport is a three dimensional one or not.
  * @return
  * The value is always <tt>TRUE</tt>.
  */
  virtual CATBoolean Is3D();

  /**
   * Determine wether or not a given CAT3DBoundingSphere lies outside the CAT3DViewport.
   * @param iBox  The CAT3DBoundingSphere we want to test
   * @param iratio
   * @return the result of the test
   */
  inline int IsOutside (const CAT3DBoundingSphere &, const float iratio= 1.f) const;
  /**
   * Determine wether or not a given sphere lies outside the CAT2DViewport.
   * @param icenter  a pointer to an array of coorinates for the center of the sphere
   * @param iradius  the radius of the spheres
   * @return the result of the test
   */
  inline int IsOutside (const float *center,const float radius) const;
  /**
   * Determine wether or not a given sphere lies inside the CAT2DViewport.
   * @param icenter  a pointer to an array of coorinates for the center of the sphere
   * @param iradius  the radius of the spheres
   * @return the result of the test
   */
  int IsInside  (const float *icenter,const float iradius) const;
  /**
   * Determine wether or not a given CAT3DBoundingSphere lies inside the CAT3DViewport.
   * @param iBox  The CAT3DBoundingSphere we want to test
   * @param iratio
   * @return the result of the test
   */
  int IsInside  (const CAT3DBoundingSphere &, const float iratio= 1.f) const;
  /**
   * Determine wether or not a given point lies inside the CAT2DViewport.
   * @param icenter  a pointer to an array of coorinates for the point
   * @return the result of the test
   */
  int IsInside  (const float point[3]) const;
  /**
   * Determine whether or not a given point lies inside a triangle.
   * @param  an array of coordinates for the point
   * @return the result of the test
   */
  int IsInsideTriangle  (const float *p1, const float *p2, const float *p3) const;
  /**
   * Determine whether or not a given point lies inside the CAT2DViewport.
   * @param icenter  an array of coordinates for the point
   * @return the result of the test
   */
  int IsInsideTriangle  (const double *p1, const double *p2, const double *p3) const;

  /**
   * Get the number of planes.
   * @return the number of planes
   */
  inline int GetNbPlanes() const;

  /** 
   * @nodoc : deprecated R216
   * In favor of void GetPlanesEquation (double* oa, double* ob, double* oc, double* od, int& ioPlanesCount).
   * Get the clipping planes equations.
   * @param oa an array of float representing the a param in the plane equation
   * @param ob an array of float representing the b param in the plane equation
   * @param oc an array of float representing the c param in the plane equation
   * @param od an array of float representing the d param in the plane equation
   *  The planes equations are of the form a.x+b.y+c.z+d = 0
   */
  inline void GetPlanes (float **oa, float **ob, float **oc, float **od);
  /**
   * Get the clipping planes equations.
   * @param oa an array of double representing the a param in the plane equation
   * @param ob an array of double representing the b param in the plane equation
   * @param oc an array of double representing the c param in the plane equation
   * @param od an array of double representing the d param in the plane equation
   * @param ioPlanesCount the size of arrays allocated as input, the number of planes set as outpput
   *  The planes equations are of the form a.x+b.y+c.z+d = 0
   */
  void GetPlanesEquation (double* oa, double* ob, double* oc, double* od, int& ioPlanesCount);

  /** @nodoc */
  virtual int SizeOf();

#ifdef _IRIX_SOURCE
 /** @nodoc */
inline  int IsOutside (const float *box_center, const float *box_dim ) const;
 /** @nodoc */
inline  int IsOutside (const CATMathPointf &min_point, const CATMathPointf &max_point ) const;
 /** @nodoc */
inline int IsOutside (const float x, const float y, const float z ) const;
#endif

 private :

 /** @nodoc */
   int _nbPlanes;
 /** @nodoc */
   float a[18],b[18],c[18],d[18];
   double ad[18],bd[18],cd[18],dd[18];
};

inline int CAT3DViewport::GetNbPlanes() const
{
 return ( _nbPlanes);
}

inline void CAT3DViewport::GetPlanes(float **oa, float **ob, float **oc, float **od)
{
 *oa = &a[0];
 *ob = &b[0];
 *oc = &c[0];
 *od = &d[0];
}

inline int CAT3DViewport::IsOutside ( const CAT3DBoundingSphere &bs3D,
                                      const float ratio ) const
{
      if ( bs3D._state == EMPTY ) return (1);
 else if ( bs3D._state == INFINIT || bs3D._state == CONTAIN ) return (0);
 else
 {
   float x = bs3D._center.x;
   float y = bs3D._center.y;
   float z = bs3D._center.z;
   float rayon;
  
   if(bs3D._radius_mm>(1e-6))
    rayon=bs3D._radius+bs3D._radius_mm*ratio;
   else
    rayon=bs3D._radius; 
 
   // Dans le cas du IsOutside on ne prend que les 6 plans de base, les plans
   // additionnels comme les clipping planes ne sont pas a prendre en compte
   for ( int i = 5; i >= 0 ; i-- )
   { 
    if ( ad[i]*x + bd[i]*y + cd[i]*z + dd[i] - rayon > 0 ) return (1);
   }
 }

 return (0);
}


inline int CAT3DViewport::IsOutside (const float *center, 
                                     const float radius) const
{
  int i;
  
  // Dans le cas du IsOutside on ne prend que les 6 plans de base, les plans
  // additionnels comme les clipping planes ne sont pas a prendre en compte
  for(i=5;i>=0;i--)
  {
    if(ad[i]*center[0]+bd[i]*center[1]+cd[i]*center[2]+dd[i]-radius>0)
      return 1;
  }

  return 0;
}

#ifdef _IRIX_SOURCE
inline int CAT3DViewport::IsOutside (const float x, const float y, const float z ) const
{
   // Dans le cas du IsOutside on ne prend que les 6 plans de base, les plans
   // additionnels comme les clipping planes ne sont pas a prendre en compte
   for (int i = 5; i >= 0; i-- )
   {
    if ((ad[i] *x+bd[i] * y+cd[i] * z + dd[i]) > 0)
   	return 1;
   }
   return 0;
}

inline int CAT3DViewport::IsOutside (const CATMathPointf &min_point, const CATMathPointf &max_point ) const
{
// if (( min_point == NULL )||( max_point == NULL )) return (1);
// else
 {
   int   i, isect;
   double xmin, ymin, zmin, xmax, ymax, zmax, offset;

   // Dans le cas du IsOutside on ne prend que les 6 plans de base, les plans
   // additionnels comme les clipping planes ne sont pas a prendre en compte
   for ( i = 5; i >= 0; i-- )
   {
    isect  = 0;
    offset = - d[i];
    
    xmin = ad[i] * (min_point.x);
    ymin = bd[i] * (min_point.y);
    zmin = cd[i] * (min_point.z);

    if (xmin+ymin+zmin <= offset)
        isect++;
    
    xmax = ad[i] * (max_point.x);
    ymax = bd[i] * (max_point.y);
    zmax = cd[i] * (max_point.z);

    if (xmax+ymax+zmax <= offset)
        isect++;
    
    if (xmin+ymin+zmax <= offset)
        isect++;
    
    if (xmin+ymax+zmin <= offset)
        isect++;
    
    if (xmin+ymax+zmax <= offset)
        isect++;
    
    if (xmax+ymin+zmin <= offset)
        isect++;
    
    if (xmax+ymin+zmax <= offset)
        isect++;
    
    if (xmax+ymax+zmin <= offset)
        isect++;

    if (isect == 0)
        return(1);
   }
 }
 return (0);
}

inline int CAT3DViewport::IsOutside (const float *box_center, const float *box_dim ) const
{
 if (( box_center == NULL )||( box_dim == NULL )) return (1);
 else
 {
   int   i, isect;
   double xmin, ymin, zmin, xmax, ymax, zmax, offset;

   // Dans le cas du IsOutside on ne prend que les 6 plans de base, les plans
   // additionnels comme les clipping planes ne sont pas a prendre en compte
   for ( i = 5; i >= 0; i-- )
   {
    isect  = 0;
    offset = - d[i];
    
    xmin = ad[i] * (box_center[0] - box_dim[0]);
    ymin = bd[i] * (box_center[1] - box_dim[1]);
    zmin = cd[i] * (box_center[2] - box_dim[2]);

    if (xmin+ymin+zmin <= offset)
        isect++;
    
    xmax = ad[i] * (box_center[0] + box_dim[0]);
    ymax = bd[i] * (box_center[1] + box_dim[1]);
    zmax = cd[i] * (box_center[2] + box_dim[2]);

    if (xmax+ymax+zmax <= offset)
        isect++;
    
    if (xmin+ymin+zmax <= offset)
        isect++;
    
    if (xmin+ymax+zmin <= offset)
        isect++;
    
    if (xmin+ymax+zmax <= offset)
        isect++;
    
    if (xmax+ymin+zmin <= offset)
        isect++;
    
    if (xmax+ymin+zmax <= offset)
        isect++;
    
    if (xmax+ymax+zmin <= offset)
        isect++;

    if (isect == 0)
        return(1);
   }
 }
 return (0);
}
#endif
#endif
