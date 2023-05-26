#ifndef CAT2DAnnotationTextGP_H
#define CAT2DAnnotationTextGP_H

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

class CATGraphicAttributeSet;
class CATMathPoint2Df;
class CATVisTSUnicodeString;

class IVisSG2DPrimitive;
class CAT2DAnnotationTextGPIVisSG2DPrimitiveBOAImpl;

//enum  AnnotationTextFont {MessageFont = 0, CaptionFont};

/**
* Class to create a dynamic graphic primitive of 2D annotation text.
* <b>Role</b>: 
* These Graphic primitives have not a continuous zoom. There are various possible 
* zoom values and current zoom is the zoom which is the nearest of possible zoom values. 
* @see CAT2DGeometricTextGP
*/
class ExportedBySGInfra CAT2DAnnotationTextGP : public CATDynamicGP
{

 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT2DAnnotationTextGP, IVisSG2DPrimitive, CAT2DAnnotationTextGPIVisSG2DPrimitiveBOAImpl);

 public:

/**
 * Default Constructor.
 */
CAT2DAnnotationTextGP();

/**
* Constructs a 2D annotation text Graphic primitive.
* @param iPoint
*	the position of the Graphic Primitive in a 2D space
* @param iString
*	the string of characters which composes the text of 
*	the 2DAnnotationTextGP
* @param iPosition
*	the position of <tt>iPoint</tt> with respect to string of the 2DAnnotationTextGP
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
* @param iContour1
*	the graphic attribute which
*	defines graphic properties of top and left segments of the contour around
*	the graphic primitive.
*	<br><b>legal values</b>: the default value is NULL.
* @param iContour2
*	the graphic attribute which
*	defines graphic properties of bottom and right segments of the contour around
*	the graphic primitive.
*	<br><b>legal values</b>: the default value is NULL.
*/
CAT2DAnnotationTextGP (const CATMathPoint2Df &iPoint ,const CATUnicodeString &iString, CATAnchorPoint iPosition = BASE_LEFT, const float iHeight = 0.f, 
                          const int iContour = 0, const CATGraphicAttributeSet *iContour1 = NULL, const CATGraphicAttributeSet *iContour2 = NULL);

/**
* Retrieves data about the 2D annotation text.
* @param oPoint
*	the position of the Graphic Primitive in a 2D space.
*	It is a 2D point.
* @param oText
*	the string of characters which composes the text of 
*	the 2DAnnotationTextGP
* @param oAnchorpoint
*	the position of <tt>oPoint</tt> with respect to string of the 2DAnnotationTextGP
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
* @param oContour1
*	the graphic attribute which
*	defines graphic properties of top and left segments of the contour around
*	the graphic primitive.
* @param oContour2
*	the graphic attribute which
*	defines graphic properties of bottom and right segments of the contour around
*	the graphic primitive.
*/
void Get (float **oPoint, char **oText, CATAnchorPoint *oAnchorpoint, float *oHeight, int *oContour, CATGraphicAttributeSet **oContour1, CATGraphicAttributeSet **oContour2) const;

// PK2: IR-071630 : 27jan11 : This Get funtion gives the locale independent text properly
void Get (float **oPoint,  CATUnicodeString &oText, CATAnchorPoint *oAnchorpoint, float *oHeight, int *oContour, CATGraphicAttributeSet **oContour1, CATGraphicAttributeSet **oContour2) const;

#if defined(CATIAR426) || defined(REMOVE_USELESS_INCLUDE)
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override Draw function.")
#endif
/** @nodoc */
virtual void Draw(CATRender& iRender) GP_FUNC_OVERRIDE_FINAL;
#endif 

/** 
* Draws a 2D Annotation text.
* @param iRender
*	the render used to draw the 2D annotation text.
* @param iViewpoint
*	the viewpoint used to draw the 2D annotation text.
* @param iViewport
*	the viewport used to draw the 2D annotation text.
*/
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbidden to override ImmediateDraw function.")
#endif
virtual void ImmediateDraw (CATRender & iRender, const CATViewpoint * iViewpoint, const CATViewport * iViewport) GP_FUNC_OVERRIDE_FINAL;

/**
 * @nodoc
 */
virtual int DetailCulling(CATRender *iRender);

/**
 * @nodoc
 * Streaming
 */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
/**
 * @nodoc
 * Unstreaming
 */  
   virtual void UnStream(CATStreamer& iStr);

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

//------------------------------------------------------------------------------

 protected :

   virtual ~CAT2DAnnotationTextGP();

//------------------------------------------------------------------------------

 private:
	 
  float       _point[2], _height; 
  int         _contour;
  CATVisTSUnicodeString * _text;  
  CATAnchorPoint _position; 
  CATGraphicAttributeSet *_contour1, *_contour2;    

#ifdef _WINDOWS_SOURCE
  int _textFont;
  int _fixedSize;
#endif
};

#endif
