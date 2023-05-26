#ifndef CAT2DArcCircleGP_H
#define CAT2DArcCircleGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"

#include "CAT2DArcEllipseGP.h"

class CATStreamer;

/**
* Class to create a dynamic graphic primitives of a 2D circle arc or a 2D circle.
*/
class ExportedBySGInfra CAT2DArcCircleGP : public CAT2DArcEllipseGP
{
 CATDeclareClass;

   public :

/**
 * Default constructor.
 */
   CAT2DArcCircleGP ();

/**
* Constructs a 2D circle arc Graphic primitive.
* @param iCenter
*	the center of the 2D circle or 2D circle arc, it is a 2D point.
* @param iRadius
*	the radius of the 2D circle or 2D circle arc.
* @param iStart_angle
*	the start angle to construct a 2D circle arc.
*	<br><b>legal values</b>: the default value is 0.
*	By this way, it creates a 2D circle.
* @param iEnd_angle
*	the end angle to construct a 2D circle arc.
*	<br><b>legal values</b>: the default value is 2*pi.
*	By this way, it creates a 2D circle.
* @param iFill
*	the integer which allows to construct a 2D circle arc or a 2D circle
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>: 
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D circle arc or the 2D circle is filled
*				with graphic attributes.
* @param iStaticSagUsed
*	used to specify wheter using a dynamic or a static sag 
*	for the circle arc visualization.
*	<br><b>legal values</b>:
*		<br>0 :  the sag value is static and taken from settings,
*		and is constant whatever the distance between the viewpoint
*		and the circle arc be
*		<br>1 : the sage value is dynamic and calculated
*		depending on the distance between the viewpoint and
*		the circle arc.
*/
   CAT2DArcCircleGP (const CATMathPoint2Df &iCenter,
		     const double          iRadius,
		     const double          iStart_angle = 0.,
                     const double          iEnd_angle   = 6.2831853,
                     const int             iFill = NOFILL,
                     const int             iStaticSagUsed = 0);

/**
* Constructs a 2D circle arc Graphic primitive.
* @param iCenter
*	the center of the 2D circle or 2D circle arc, it is a 2D point.
* @param iRadius
*	the radius of the 2D circle or 2D circle arc.
* @param iStart_angle
*	the start angle to construct a 2D circle arc.
*	<br><b>legal values</b>: the default value is 0.
*	By this way, it creates a 2D circle.
* @param iEnd_angle
*	the end angle to construct a 2D circle arc.
*	<br><b>legal values</b>: the default value is 2*pi.
*	By this way, it creates a 2D circle.
* @param iFill
*	the integer which allows to construct a 2D circle arc or a 2D circle
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>: 
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D circle arc or the 2D circle is filled
*				with graphic attributes.
* @param iStaticSagUsed
*	used to specify wheter using a dynamic or a static sag 
*	for the circle arc visualization.
*	<br><b>legal values</b>:
*		<br>0 :  the sag value is static and taken from settings,
*		and is constant whatever the distance between the viewpoint
*		and the circle arc be
*		<br>1 : the sage value is dynamic and calculated
*		depending on the distance between the viewpoint and
*		the circle arc.
*/
   CAT2DArcCircleGP (const CATMathPoint2D  &iCenter,
		     const double          iRadius,
		     const double          iStart_angle = 0.0,
                     const double          iEnd_angle   = 6.2831853,
                     const int             iFill = NOFILL,
                     const int             iStaticSagUsed = 0);

/**
* Retrieves data about the 2D circle arc or the 2D circle.
* @param oCenter
*	the center of the 2D circle or 2D circle arc, it is a 2D point.
* @param oRadius
*	the radius of the 2D circle or 2D circle arc.
* @param oBegin_angle
*	the begin angle to construct a 2D circle arc.
*	<br><b>legal values</b>: the default value is 0.
*	By this way, it creates a 2D circle.
* @param oEnd_angle
*	the end angle to construct a 2D circle arc.
*	<br><b>legal values</b>: the default value is 2*pi.
*	By this way, it creates a 2D circle.
* @param oFill
*	the integer which allows to construct a 2D circle arc or a 2D circle
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>: 
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D circle arc or the 2D circle is filled
*				with graphic attributes.
*/
   inline void Get (double **oCenter, double *oRadius, double *oBegin_angle, double *oEnd_angle, int *oFill);

/**
* Draws the dynamic graphic primitive with a render.
* @param iRender
*	the render used to draw the dynamic graphic primitive.
*/
   virtual void Draw (CATRender & iRender);   

/**
* Modifies the center or the radius of the 2D circle arc or the 2D circle.
* @param iCenter
*	the new center of the 2D circle arc or the 2D circle
* @param iRadius
*	the new radius of the 2D circle arc or the 2D circle
*/
   void Modify (const float iCenter[2], const float iRadius);

/**
 * @nodoc
 * Streaming
 */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   
/**
 * @nodoc
 * Streaming
 */  
   virtual void UnStream(CATStreamer& iStr);

/**
 * @nodoc
 */
   virtual void Visit(CATIGPVisitor& iVisitor) const final;

//--------------------------------------------------------------------------------
 
 protected :

   virtual ~CAT2DArcCircleGP();
     
};

inline void CAT2DArcCircleGP::Get (double **center, double *radius, double *begin_angle, double *end_angle, int *fill)
{
 *center      = _center;
 *radius      = _XRadius;
 *begin_angle = _begin_angle;
 *end_angle   = _end_angle;
 *fill        = _fill;
}

#endif
