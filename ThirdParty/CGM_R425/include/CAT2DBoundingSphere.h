#ifndef CAT2DBoundingSphere_H
#define CAT2DBoundingSphere_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"

#include "CATBoundingElement.h"
#include "CATMathPoint2Df.h"

class CAT3x3Matrix;

/**
 * Class to manage bounding surface of 2D elements.
 * <b>Role</b>:This class is used to manage the space used by a 2D 
 * element. This information is used at the rendering time to know if a given
 * element is visible on the screen and needs to be drawn or not.
 * 2DBoundingSpheres are Circles.
 * For performance issues BoundingSpheres need to be as close to the object they are linked
 * to as possible. Idealy they represent the smallest circle containing the object.
 * You can add 2 2DBoundingSpheres using the += operator inherited from boundingElements.
 */

class ExportedBySGInfra CAT2DBoundingSphere : public CATBoundingElement
{
 friend class CAT2DViewport;

 public :

   /**
    * Construct an empty boundingSphere.
	* default center will be 0,0 and default radius 1
	*/
   CAT2DBoundingSphere ();
   
   /**
    * Copy constructor
	*/
   CAT2DBoundingSphere (const CAT2DBoundingSphere &);
   
   /**
    * Constructs a 2DBoundingSphere with a given center, radius and radius in mm.
	* @param center
	*  The center of the boundingSphere.
	* @param radius
	*  The radius of the boundingSphere in model unit.
	* @param radius_mm
	*  This is used for elements with fixed size on the screen on which
	*  zoom has no effect. Default is 0.
	*/
   CAT2DBoundingSphere (const CATMathPoint2Df &center, const float radius, const float radius_mm = 0.f);

   /**
    * Destructor
	*/
   virtual ~CAT2DBoundingSphere();

   /**
    * Returns the 2DBoundingSphere center.
	*/
   inline const CATMathPoint2Df & GetCenter() const;

   /**
    * Returns the radius of the 2DBoundingSphere.
	*/
   inline float GetRadius   () const;

   /** 
    * Returns the radius in millimeter of the 2DBoundingSphere.
    */
   inline float GetRadiusMM () const ;


//------------------------------------------------------------------------------

  private :

   CATMathPoint2Df _center;

   float _radius;
   float _radius_mm;

};

inline const CATMathPoint2Df & CAT2DBoundingSphere::GetCenter () const
{
 return (_center);
}

inline float CAT2DBoundingSphere::GetRadius () const 
{
 return (_radius);
}

inline float CAT2DBoundingSphere::GetRadiusMM () const
{
 return (_radius_mm);
}

#endif
