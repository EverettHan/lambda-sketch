#ifndef CAT3DBoundingSphere_H
#define CAT3DBoundingSphere_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"

#include "CATBoundingElement.h"
#include "CATMathPointf.h"
 
class CAT4x4Matrix;
class CAT2DBoundingBox;
class CATStreamer;



/**
 * Class to manage bounding volume of 3D elements.
 * <b>Role</b>:This class is used to manage the volume occupied by a 3D 
 * element. <br>This information is used at the rendering time to know if a given
 * element is visible on the screen and needs to be drawn or not.<br>
 * For performance issues BoundingSpheres need to be as close to the object they are linked
 * to as possible. <br>Idealy they represent the smallest sphere containing the object.
 * You can add 2 3DBoundingSpheres using the += operator<br> 
 */
class ExportedBySGInfra CAT3DBoundingSphere : public CATBoundingElement
{
 friend class CAT3DViewport;
 friend class CATMarshal3DBoundingSphere;
 friend class SGCGRStreamerFor3DBoundingSphere;
 friend class SGCGRNodesFactoryA;
 CATDeclareClass_Deprec;

 public :

   /**
   * Constructs an empty boundingSphere.
   * default center will be 0,0,0 and default radius 1
   */
   CAT3DBoundingSphere ();
   
   /**
    * Copy constructor.
    */
   CAT3DBoundingSphere (const CAT3DBoundingSphere &); 

   /**
    * Constructs a BoundingSphere from a 2D box.
	*/
   CAT3DBoundingSphere (const CAT2DBoundingBox &);
   
   /**
    * Constructs a 3DBoundingSphere with a given center, radius and radius in mm.
	* @param center
	*  The center of the boundingSphere
	* @param radius
	*  The radius of the boundingSphere in model unit.
	* @param radius_mm
	*  This is used for elements with fixed size on the screen on which
	*  zoom has no effect.<br>
	*  Default is 0.
	*/
   CAT3DBoundingSphere (const CATMathPointf &center, const float radius, const float radius_mm = 0.f);


   /**
    * Destructor.
	*/
   virtual ~CAT3DBoundingSphere();

   /**
    * @nodoc
	* Streaming
	*/
   virtual void Stream(CATStreamer& str,int savetype=0);

   /**
    * @nodoc
	* UnStreaming
	*/
   virtual void UnStream(CATStreamer& str);



   /**
    * Multiply operator. Multiply a BoundingSphere by a given Matrix.
	* @param mat
	* The matrix to apply to the Sphere
	*/
   CAT3DBoundingSphere & operator *= (const CAT4x4Matrix &mat);

   /**
    * Add operator. Add 2 boundingSpheres.
	*/
   CAT3DBoundingSphere & operator += (const CAT3DBoundingSphere &);

   /**
    * Assign a new value to the current BoundingSphere.
    */
   CAT3DBoundingSphere & operator  = (const CAT3DBoundingSphere &);
 
   /**
    * Returns the 3DBoundingSphere center.
	*/
   inline const CATMathPointf & GetCenter() const;

   /**
    * Returns the radius of the 3DBoundingSphere.
	*/
   inline float GetRadius   () const ;

   /**
    * Returns the radius for fixed element.
	*  (Element with fixed size on the screen on which
	*  zoom has no effect.)
	*/
   inline float GetRadiusMM () const ;

   /**
   * @nodoc
   */
   void GetClippedBoundingSphere(CAT3DBoundingSphere& oSphere,
     float *ipPoint, float *ipNormal, int iNbPlanes) const;

   

//------------------------------------------------------------------------------

  private :

   CATMathPointf _center;

   float _radius;
   float _radius_mm;

};

inline const CATMathPointf & CAT3DBoundingSphere::GetCenter () const
{
 return (_center);
}

inline float CAT3DBoundingSphere::GetRadius () const 
{
 return (_radius);
}

inline float CAT3DBoundingSphere::GetRadiusMM () const
{
 return (_radius_mm);
}

#endif
