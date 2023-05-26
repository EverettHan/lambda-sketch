#ifndef CAT2DViewport_H
#define CAT2DViewport_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   defines a 2D bounding object (rectangle)
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by viewer at draw time to define a box where
// ------       representations are supposed to be seen. 
//              (this is used at culling time to avoid to draw representations
//               which bounding sphere is outside of this box)
//
//------------------------------------------------------------------------------
// Inheritance :      CAT2DViewport
// ------------          CATViewport
//                  
//------------------------------------------------------------------------------
#include "CATViewport.h"

class CAT2DBoundingBox;
class CAT3x3Matrix;

#include "CATMathPoint2Df.h"

/**
 * Class that defines a 2D clipping area.
 */
class ExportedBySGInfra CAT2DViewport : public CATViewport
{
 CATDeclareClass;

 public :

  CAT2DViewport ();  
 /** @nodoc */
  CAT2DViewport (const CAT2DViewport &);    
 /** @nodoc */
  CAT2DViewport (const float, const float, const float, const float);            
 /** @nodoc */
  CAT2DViewport & operator= (const CAT2DViewport & brother);

  virtual ~CAT2DViewport ();

  /**
  * Applies the geometric transformatin defined by the CAT3x3Matrix to the limits 
  * of the CAT2DViewport.
  *  @param iMatrix 
  * the transformation to apply.
  */
  CAT2DViewport & operator*= (const CAT3x3Matrix & iMatrix);

  /**
   *  Duplicate the Viewport.
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
  * Retrieves whether viewport is a three dimensional one or not. 
  * @return
  * The value is always <tt>FALSE</tt>.
  */
  virtual CATBoolean Is3D();

 /** @nodoc */
  inline int CSoutcode (const float, const float) const;
 /** @nodoc */
  inline int CSoutcode (const CATMathPoint2Df &) const;

  /**
   * Determine wether or not a given CAT2DBoundingBox lies inside the CAT2DViewport.
   * @param iBox  The CAT2DBoundingBox we want to test
   * @param iratio
   * @return the result of the test
   */
  int IsInside  (const CAT2DBoundingBox &iBox, const float iratio = 1.f) const;
  /**
   * Determine wether or not a given CAT2DBoundingBox lies outside the CAT2DViewport.
   * @param iBox  The CAT2DBoundingBox we want to test
   * @param iratio
   * @return the result of the test
   */
  int IsOutside (const CAT2DBoundingBox &iBox, const float iratio= 1.f) const;

  /** Get the extend of the CAT2DViewport.
   *  @param  oXmin  minimal vue a x coordinate concidered inside the CAT2DViewport
   *  @param  oXmax  maximal vue a x coordinate concidered inside the CAT2DViewport
   *  @param  oYmin  minimal vue a y coordinate concidered inside the CAT2DViewport
   *  @param  oYmax  maximal vue a y coordinate concidered inside the CAT2DViewport
   */
  void GetParameter ( float *oXmin, float *oXmax, float *oYmin, float *oYmax) const ;

  /** @nodoc */
  void SetParameter(float oXmin, float oXmax, float oYmin, float oYmax);
  
  /** @nodoc */
  virtual int SizeOf();

 private :

 /** @nodoc */
  float _xmin;
   /** @nodoc */
  float _xmax;  // Abcisses minimale et maximale
 /** @nodoc */
  float _ymin;
   /** @nodoc */
  float _ymax;  // Ordonnees minimale et maximale

};

inline int CAT2DViewport::CSoutcode ( const float x, const float y ) const
{
 return ( ( x < _xmin ) << 3 | ( x > _xmax ) << 2 | ( y < _ymin ) << 1 | ( y > _ymax ) );
}

inline int CAT2DViewport::CSoutcode ( const CATMathPoint2Df &point ) const
{
 return ( ( point.x < _xmin ) << 3 | ( point.x > _xmax ) << 2 | ( point.y < _ymin ) << 1 | ( point.y > _ymax ) );
}

#endif
