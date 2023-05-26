#ifndef CAT2DArrowSymbolGP_H
#define CAT2DArrowSymbolGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

#include "CAT2DSymbolGP.h"
#include "CATSymbolType.h"

class CATStreamer;

/**
* Class to create a dynamic graphic primitive of a 2D arrow symbol.
*/
class ExportedBySGInfra CAT2DArrowSymbolGP : public CAT2DSymbolGP
{
 CATDeclareClass;

 public :

/**
* Constructs a default graphic primitive of a two dimensional arrow symbol.
*/
   CAT2DArrowSymbolGP ();

/**
* Constructs a 2D arrow symbol Graphic primitive.
* @param iPoint
*	the position of the 2D arrow symbol.<br>
*	This is the point which represents the top of the 2D arrow symbol.
* @param iDirection
*	the direction vector of the 2D arrow symbol.<br>
*	The direction vector is assumed to be normalized
* @param iSize_in_mm
*	the size of the 2D arrow symbol among the axis defined by the Direction vector.
* @param iAngle
*	the angle (in radians) formed by the line going from 
*	<tt>iPoint</tt> and directed by <tt>iDirection</tt>, and one of the slanted arrowhead 
*	lines.
*	It determines how wide the arrowhead is at the base. 
* @param iSymbol
*	the type of 2D arrow symbol.
*	<br><b>legal values</b>:
*	<br>OPEN_ARROW : 
*				arrow drawn with two symetric segments 
*				with respect to the vector director
*	<br>UNFILLED_ARROW :
*				unfilled arrow drawn with three segments.
*	<br>FILLED ARROW :
*				filled arrow drawn with three segments.
*	<br>BLANKER_ARROW :
*				arrow drawn with three segments.
*				This arrow is composed of two arrows: one
*				is an UNFILLED_ARROW 2D arrow and the other one is
*				a FILLED_ARROW 2D arrow which has the color of the background.
* @param iZoom
*	the type of size values.
*	<br><b>legal values</b>: 
*	<br>0 :
*		size is expressed in millimeter.
*	<br>1 :
*		size is expressed in model unit.
*/
   CAT2DArrowSymbolGP (const float iPoint[2], const float iDirection[2], const float iSize_in_mm, const float iAngle, CATSymbolType iSymbol, const int iZoom = 0);
	      

/** 
* Draws a 2D arrow symbol.
* @param iRender
*	the render used to draw the 2D arrow symbol.
* @param iViewpoint
*	the viewpoint used to draw the 2D arrow symbol.
* @param iViewport
*	the viewport used to draw the 2D arrow symbol.
*/
   virtual void ImmediateDraw (CATRender & iRender, const CATViewpoint * iViewpoint, const CATViewport * iViewport);   

/** 
* Retrieve Data of 2D arrow symbol.
* @param oPoint
*	the position of the 2D arrow symbol.<br>
*	This is the point which represents the top of the 2D arrow symbol.
* @param oDirection
*	the direction vector of the 2D arrow symbol.<br>
*	The direction vector is assumed to be normalized
* @param oSize
*	the size of the 2D arrow symbol among the axis defined by the Direction vector.
* @param oAngle
*	the angle (in radians) formed by the line going from 
*	<tt>iPoint</tt> and directed by <tt>iDirection</tt>, and one of the slanted arrowhead 
*	lines.
*	It determines how wide the arrowhead is at the base. 
* @param oSymbol
*	the type of 2D arrow symbol.
*	<br><b>legal values</b>:
*	<br>OPEN_ARROW : 
*				arrow drawn with two symetric segments 
*				with respect to the vector director
*	<br>UNFILLED_ARROW :
*				unfilled arrow drawn with three segments.
*	<br>FILLED ARROW :
*				filled arrow drawn with three segments.
*	<br>BLANKER_ARROW :
*				arrow drawn with three segments.
*				This arrow is composed of two arrows: one
*				is an UNFILLED_ARROW 2D arrow and the other one is
*				a FILLED_ARROW 2D arrow which has the color of the background.
* @param oZoom
*	the type of size values.
*	<br><b>legal values</b>: 
*	<br>0 :
*		size is expressed in millimeter.
*	<br>1 :
*		size is expressed in model unit.
*/
   void Get(float** oPoint, float** oDirection, float* oSize, float* oAngle, CATSymbolType* oSymbol, int* oZoom) const;

/** @nodoc
 *  Streams the graphic primitive of a two dimensional symbol.
 * <br><b>Role:</b>This method streams a <tt>CAT2DArrowSymbolGP</tt> .
 *  @param   oStr
 *    The streamer used to stream the <tt>CAT2DArrowSymbolGP</tt>.
 *  @param   iSavetype
 *    <br><b>legal values</b>
 *    <ul>
 *         <li>0 the name of the GP will not be saved</li>
 *         <li>1 the name of the GP will be saved</li>
 *    </ul>
 */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
/** @nodoc
 *  Unstreams the graphic primitive of a two dimensional symbol.
 * <br><b>Role:</b>This method unstreams a <tt>CAT2DArrowSymbolGP</tt> .
 *  @param   iStr
 *    The streamer used to unstream the <tt>CAT2DArrowSymbolGP</tt>.
 */
   virtual void UnStream(CATStreamer& iStr);
   
//--------------------------------------------------------------------------------
 
 protected :

   virtual ~CAT2DArrowSymbolGP();
     
//--------------------------------------------------------------------------------

 private :

   float _direction[2], _angle;
};

#endif
