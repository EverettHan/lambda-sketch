#ifndef CAT3DAnnotationTextGP_H
#define CAT3DAnnotationTextGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CATAnchorPoint.h"
#include "CATDynamicGP.h"
#include "CATUnicodeString.h"
#include "CATVisMacroForInterfaces.h"

class CATMathPointf;
class CATStreamer;
class CATVisTSUnicodeString;

class IVisSG3DPirmitive;
class CAT3DAnnotationTextGPIVisSG3DPrimitiveBOAImpl;

/**
* Class to create a dynamic graphic primitive of 3D annotation text.
* <b>Role</b>: 
* These Graphic primitives have a continuous zoom.
*/
class ExportedBySGInfra CAT3DAnnotationTextGP : public CATDynamicGP
{
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT3DAnnotationTextGP, IVisSG3DPirmitive, CAT3DAnnotationTextGPIVisSG3DPrimitiveBOAImpl);

 friend class CATMarshallable3DAnnotationTextGP;

 public:

// Constructors
/** @nodoc */
   CAT3DAnnotationTextGP ();
/**
* Constructs a 3D annotation text Graphic primitive.
* @param iPoint
*	the position of the Graphic Primitive in a 3D space
* @param iString
*	the string of characters which composes the text of 
*	the 3DAnnotationTextGP
* @param iPosition
*	the position of <tt>iPoint</tt> with respect to string of the 3DAnnotationTextGP
*	<br><b>legal values</b>:<pre>
*   TOP_LEFT          TOP_CENTER       TOP_RIGHT
*            +------------+-----------+
*            !                        !
*            !        BASE_CENTER     !
*  BASE_LEFT +            +           + BASE_RIGHT
*            !                        !
*            +------------+-----------+
* BOTTOM_LEFT       BOTTOM_CENTER      BOTTOM_RIGHT</pre>
* @param iHeight
*	the height of the Graphic Primitive
	<br><b>legal values</b>: the default value is NULL.
* @param iContour
*	the integer which allows or does not allow to construct a contour around 
*	the Graphic Primitive.
*	<br><b>legal values</b>:<br>
*	0 : no contour is constructed around the graphic primitive.<br>
*	1 : a contour is constructed around the graphic primitive.
*/
   CAT3DAnnotationTextGP(const CATMathPointf &iPoint, const CATUnicodeString &iString, CATAnchorPoint iPosition = BASE_LEFT,
     const float iHeight = 0.f, const int iContour = 0, const CATBoolean iIsDepthEnabled = FALSE);

  //Streaming
  /** @nodoc */
  virtual void Stream(CATStreamer& str,int savetype=0);
  /** @nodoc */
  virtual void UnStream(CATStreamer& str);

   
/**
* Retrieves data about the 3D annotation text.
* @param oPoint
*	the position of the Graphic Primitive in a 3D space.
*	It is a 3D point.
* @param oText
*	the string of characters which composes the text of 
*	the 3DAnnotationTextGP
* @param oAnchorpoint
*	the position of <tt>oPoint</tt> with respect to string of the 3DAnnotationTextGP
*	<br><b>legal values</b>:<pre>
*   TOP_LEFT          TOP_CENTER       TOP_RIGHT
*            +------------+-----------+
*            !                        !
*            !        BASE_CENTER     !
*  BASE_LEFT +            +           + BASE_RIGHT
*            !                        !
*            +------------+-----------+
* BOTTOM_LEFT       BOTTOM_CENTER      BOTTOM_RIGHT</pre>
* @param oHeight
*	the height of the Graphic Primitive
* @param oContour
*	the integer which allows or not allow to construct a contour around 
*	the graphic primitive.
*	<br><b>legal values</b>:<br>
*	0 : no contour is constructed around the graphic primitive.<br>
*	1 : a contour is constructed around the graphic primitive.
*/
   void Get (float **oPoint, char **oText, CATAnchorPoint *oAnchorpoint, float *oHeight, int *oContour) const;
   
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override ImmediateDraw function.")
#endif  
   /** @nodoc */
   virtual void ImmediateDraw (CATRender &, const CATViewpoint *, const CATViewport *) GP_FUNC_OVERRIDE_FINAL;

  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const final;

#ifdef _WINDOWS_SOURCE
/**
 * @nodoc
 */  
   inline void GetAnnotationTextFont(int & oTextFont, int & oFixedSize){oTextFont = _textFont; oFixedSize = _fixedSize;};

/**
 * @nodoc
 */  
   inline void SetAnnotationTextFont(int iTextFont, int iFixedSize = 0){_textFont = iTextFont; _fixedSize = iFixedSize;};
#endif
  
/**
* @nodoc
*/
   inline CATBoolean IsDepthTestEnabled() const { return _anchorPointDepthTest; };


#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override Draw function.")
#endif
   /** @nodoc */
   virtual void Draw(CATRender& iRender) GP_FUNC_OVERRIDE_FINAL;

//------------------------------------------------------------------------------

 protected :

   virtual ~CAT3DAnnotationTextGP();
  
//------------------------------------------------------------------------------

 private:

   float      _point[3], _height; 
   int         _contour;
   CATVisTSUnicodeString *_text;   
   CATAnchorPoint _position;      
   CATBoolean _anchorPointDepthTest;
#ifdef _WINDOWS_SOURCE
  int  _textFont;//0:MessageFont; 1:CaptionFont
  int  _fixedSize;
#endif
};

#endif
