#ifndef CAT2DBoundingBox_H
#define CAT2DBoundingBox_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"

#include "CATBoundingElement.h"
#include "CATMathPoint2Df.h"

class CAT3x3Matrix;
class CAT2DBoundingSphere;
class CATStreamer;


#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
struct CATShaderBox;
#endif


/**
 * Class to manage a box encompassing 2D elements.
 * <b>Role</b>:This classe is used to manage the space used by a 2D 
 * element. This information is used at the rendering time to know if a given
 * element is visible on the screen and needs to be drawn on not.
 * For performances issues 2DBoundingBox need to be at close to the object they are linked
 * to as possible. Idealy they represent the smallest rectangle containing the object.
 * You can add 2 2DBoundingBox using the += operator.
 */


class ExportedBySGInfra CAT2DBoundingBox : public CATBoundingElement
{
 friend class CAT2DViewport;
 friend class SGCGRStreamerFor2DBoundingBox;
 friend class SGCGRNodesFactoryA;
 CATDeclareClass_Deprec;

 public :

 /**
  * Default constructor.
  * Construct a boundingBox of width and height 1 and centered on 0,0.
  */
   CAT2DBoundingBox ();
   
 /**
  * Copy Constructor
  */
   CAT2DBoundingBox (const CAT2DBoundingBox &); 

 /**
  * Creates a BoundingBox from a 2DBoundingSphere.
  * You get the smallest Box containing the circle.
  * @param bs
  * The 2DboundingSphere tou construct the box from. 
  */
   CAT2DBoundingBox (const CAT2DBoundingSphere &bs); 

 /**
  * Construct a 2DBoundingBox.
  * @param xmin
  * The min x value
  * @param xmax
  * The max x value
  * @param ymin
  * The min y value
  * @param ymax
  * The max y value
  */
   CAT2DBoundingBox (const float xmin, const float xmax, const float ymin, const float ymax); 

  /**
   * Construct a Box of width and height 0 and 0 and centered in x,y.
   * This is used for non zoomable objects.
   * @param x 
   * The x value of the center
   * @param y
   * The y value of the center
   * @param size_mm
   * The size of the non zommable box (it is a square in this case)
   */
   CAT2DBoundingBox (const float x, const float y, const float size_mm); 

   virtual ~CAT2DBoundingBox();

  /**
   * Multiplication assignment operator.
   * @param iMatrix
   * The tranform to apply to the boundingbox.
   * @return
   * The 2DBoundingBox resulting from this transformation.
   */
   CAT2DBoundingBox & operator *= (const CAT3x3Matrix &iMatrix);

  /**
   * Addition assignment operator.
   * @param bbox
   * The boundingbox to add.
   * @return
   * The 2DBoundingBox resulting from this transformation
   */
   CAT2DBoundingBox & operator += (const CAT2DBoundingBox &bbox);

  /**
   * Assignment operator.
   * @param bbox
   * The 2DBoundingBox to assign to the current one.
   * @return 
   * The 2DBoundingBox resulting from the assignment.
   */
   CAT2DBoundingBox & operator  = (const CAT2DBoundingBox &bbox);

  /**
   * Returns the Bounding Box center.
   * @return
   * The 2DBoundingBox center.
   */
   const CATMathPoint2Df & GetCenter() const;

  /**
   * Retrieves the BoundingBox parameters.
   * @param xmin
   * The returned xmin.
   * @param xmax
   * The returned xmax
   * @param ymin
   * The returned ymin
   * @param ymax
   * The returned ymax.
   */
   inline void GetParameter ( float *xmin, float *xmax, float *ymin, float *ymax) const;

  /**
   * Returns the 2DBoundingBox size in milimmeters.
   * @return
   * The size in mm of the 2DBoundingBox.
   * A non zero value means the object this box is attached too will have that
   * size on the screen whatever the zoom value is.
   */
   inline float GetSizeMM () const;

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

   
#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /** @nodoc */
  inline CATShaderBox *GetBox(void);
#endif    


//------------------------------------------------------------------------------

  private :

   float _xmin, _xmax, _ymin, _ymax;
   float _size_mm;
};

inline void CAT2DBoundingBox::GetParameter (float *xmin, float *xmax, float *ymin, float *ymax) const
{
  *xmin = _xmin;
  *xmax = _xmax;
  *ymin = _ymin;
  *ymax = _ymax;
}

inline float CAT2DBoundingBox::GetSizeMM () const
{
  return (_size_mm);
}

#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
inline CATShaderBox *CAT2DBoundingBox::GetBox(void)
{
 return (CATShaderBox *) -1;
}
#endif

#endif
