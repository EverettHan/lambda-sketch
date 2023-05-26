#ifndef CAT2DArcEllipseGP_H
#define CAT2DArcEllipseGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"

#include "CATDynamicGP.h"
#include "CAT3DBoundingSphere.h"
#include "CATVisMacroForInterfaces.h"

class CATMathPoint2D;
class CATMathPoint2Df;
class CATStreamer;

class IVisSG2DPrimitive;
class CAT2DArcEllipseGPIVisSG2DPrimitiveBOAImpl;

#ifndef NOFILL
/** @nodoc */
#define NOFILL 0
/** @nodoc */
#define FILL 1
#endif


/**
* Class to create a dynamic graphic primitives of a 2D ellipse arc or a 2D ellipse.
*/
class ExportedBySGInfra CAT2DArcEllipseGP : public CATDynamicGP
{
  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DArcEllipseGP, IVisSG2DPrimitive, CAT2DArcEllipseGPIVisSG2DPrimitiveBOAImpl);

  public :

    /**
     * Default constructor.
     */
   
    CAT2DArcEllipseGP ();

    /**
    * Constructs a 2D ellipse arc Graphic primitive.
    * @param iCenter
    *	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
    * @param iXRadius
    *	the radius among X axis of the 2D ellipse or 2D ellipse arc.
    * @param iYRadius
    *	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
    * @param iStart_angle
    *	the start angle to construct a 2D ellipse arc.
    *	<br><b>legal values</b>: the default value is 0.
    *	By this way, it creates a 2D ellipse.
    * @param iEnd_angle
    *	the end angle to construct a 2D ellipse arc.
    *	<br><b>legal values</b>: the default value is 2*pi.
    *	By this way, it creates a 2D ellipse.
    * @param iOffset
    *	the angle between X axis and main axis of the 2D ellipse.
    *	By this way, it is possible to rotate the 2D ellipse arc 
    *	or the 2D ellipse in the 2D plan.
    * @param iFill
    *	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
    *	just with edges or filled with some graphic attributes.
    *	<br><b>legal values</b>: 
    *		<br>NOFILL : just edges are drawn.
    *		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
    *				with graphic attributes.
    * @param iStaticSagUsed
    *	used to specify wheter using a dynamic or a static sag 
    *	for the ellipse arc visualization
    *	<br><b>legal values</b>:
    *		<br>0 :  the sag value is static and taken from settings,
    *		and is constant whatever the distance between the viewpoint
    *		and the ellipse arc be
    *		<br>1 : the sage value is dynamic and calculated
    *		depending on the distance between the viewpoint and
    *		the ellipse arc.
    */
    CAT2DArcEllipseGP(  const CATMathPoint2Df &iCenter,
                        const double          iXRadius,
                        const double          iYRadius,
                        const double          iStart_angle    = 0.,
                        const double          iEnd_angle      = 6.2831853,
                        const double          iOffset         = 0.,
                        const int             iFill           = NOFILL,
                        const int             iStaticSagUsed  = 0);

    /**
    * Constructs a 2D ellipse arc Graphic primitive.
    * @param iCenter
    *	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
    * @param iXRadius
    *	the radius among X axis of the 2D ellipse or 2D ellipse arc.
    * @param iYRadius
    *	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
    * @param iStart_angle
    *	the start angle to construct a 2D ellipse arc.
    *	<br><b>legal values</b>: the default value is 0.
    *	By this way, it creates a 2D ellipse.
    * @param iEnd_angle
    *	the end angle to construct a 2D ellipse arc.
    *	<br><b>legal values</b>: the default value is 2*pi.
    *	By this way, it creates a 2D ellipse.
    * @param iOffset
    *	the angle between X axis and main axis of the 2D ellipse.
    *	By this way, it is possible to rotate the 2D ellipse arc 
    *	or the 2D ellipse in the 2D plan.
    * @param iFill
    *	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
    *	just with edges or filled with some graphic attributes.
    *	<br><b>legal values</b>: 
    *		<br>NOFILL : just edges are drawn.
    *		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
    *				with graphic attributes.
    * @param iStaticSagUsed
    *	used to specify wheter using a dynamic or a static sag 
    *	for the ellipse arc visualization
    *	<br><b>legal values</b>:
    *		<br>0 :  the sag value is static and taken from settings,
    *		and is constant whatever the distance between the viewpoint
    *		and the ellipse arc be
    *		<br>1 : the sage value is dynamic and calculated
    *		depending on the distance between the viewpoint and
    *		the ellipse arc.
    */
    CAT2DArcEllipseGP(  const CATMathPoint2D  &iCenter,
                        const double          iXRadius,
                        const double          iYRadius,
                        const double          iStart_angle    = 0.,
                        const double          iEnd_angle      = 6.2831853,
                        const double          iOffset         = 0.,
                        const int             iFill           = NOFILL,
                        const int             iStaticSagUsed  = 0);

    /**
    * Retrieves data about the 2D ellipse arc or the 2D ellipse.
    * @param oCenter
    *	the center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
    * @param oXRadius
    *	the radius among X axis of the 2D ellipse or 2D ellipse arc.
    * @param oYRadius
    *	the radius among Y axis of the 2D ellipse or 2D ellipse arc.
    * @param oBegin_angle
    *	the started angle to construct a 2D ellipse arc.
    *	<br><b>legal values</b>: the default value is 0.
    *	By this way, it creates a 2D ellipse.
    * @param oEnd_angle
    *	the end angle to construct a 2D ellipse arc.
    *	<br><b>legal values</b>: the default value is 2*pi.
    *	By this way, it creates a 2D ellipse.
    * @param oOffset
    *	the angle between X axis and main axis of the 2D ellipse.
    * @param oFill
    *	the integer which allows to construct a 2D ellipse arc or a 2D ellipse
    *	just with edges or filled with graphic attributes.
    *	<br><b>legal values</b>: 
    *		<br>NOFILL : just edges are drawn.
    *		<br>FILL : the 2D ellipse arc or the 2D ellipse is filled
    *				with graphic attributes.
    */
    inline void Get (double **oCenter, double *oXradius, double *oYradius, double *oBegin_angle, double *oEnd_angle, double *oOffset);


    /**
    * Returns whether or not the 2D ellipse is filled.
    */
    inline int IsFilled();


#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif  
    /**
    * Draws the dynamic graphic primitive with a render.
    * @param iRender
    *	the render used to draw the dynamic graphic primitive.
    */
    virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;


#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override ImmediateDraw function.")
#endif  
    /**
    * Draws a 2D ellipse arc or a 2D ellipse.
    * @param iRender
    *	the render used to draw the 2D ellipse arc or the 2D ellipse.
    * @param iViewpoint
    *	the viewpoint used to draw the 2D ellipse arc or the 2D ellipse.
    * @param iViewport
    *	the viewport used to draw tthe 2D ellipse arc or the 2D ellipse.
    */
    virtual void ImmediateDraw (CATRender & iRender, const CATViewpoint * iViewpoint, const CATViewport * iViewport) GP_FUNC_OVERRIDE_FINAL;   

    /**
    * Modifies the 2D ellipse arc or the 2D ellipse.
    * @param iCenter
    *	the new center of the 2D ellipse or 2D ellipse arc, it is a 2D point.
    * @param iXRadius
    *	the new radius among X axis of the 2D ellipse or 2D ellipse arc.
    * @param iYRadius
    *	the new radius among Y axis of the 2D ellipse or 2D ellipse arc.
    */
    void Modify (const float iCenter[2], const float iXRadius, const float iYRadius);

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
   virtual int DetailCulling(CATRender *);

  //--------------------------------------------------------------------------------

  protected :

    virtual ~CAT2DArcEllipseGP();
    virtual int ComputeGeometry();

    int _fill, _Sagmax;
    double _center[2], _XRadius, _YRadius, _begin_angle, _end_angle, _radius, _Offset;
    float _ToleranceScale;

    // working data
    double dcos, dsin;
};

inline void CAT2DArcEllipseGP::Get (double **center, double *Xradius, double *Yradius, double *begin_angle, double *end_angle, double *offset)
{
  *center      = _center;
  *Xradius     = _XRadius;
  *Yradius     = _YRadius;
  *begin_angle = _begin_angle;
  *end_angle   = _end_angle;
  *offset      = _Offset;
}

inline int CAT2DArcEllipseGP::IsFilled()
{
    return _fill;
}

#endif
