#ifndef CAT2DRectangleGP_H
#define CAT2DRectangleGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"
#include "CATGraphicPrimitive.h"
#include "CATVisMacroForInterfaces.h"

class CATStreamer;

class IVisSG2DPrimitive;
class CAT2DRectangleGPIVisSG2DPrimitiveBOAImpl;

/** @nodoc */
#define NOFILL 0
/** @nodoc */
#define FILL   1

/**
* Class to create a dynamic graphic primitive of a 2D rectangle.
*/
class ExportedBySGInfra CAT2DRectangleGP : public CATGraphicPrimitive
{
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT2DRectangleGP, IVisSG2DPrimitive, CAT2DRectangleGPIVisSG2DPrimitiveBOAImpl);
  public:

/**
 * Default constructor.
 */
   CAT2DRectangleGP ();
  
/**
* Constructs a 2D rectangle dynamic graphic primitive.
* <pre>
*                          +----------------------x topRight Point
*                          |                      |
*          bottoLeft point x----------------------+
* </pre>
* @param iBottomLeft
*	the bottom-left 2D point of the 2D rectangle (XY).
* @param iTopRight
*	the top-right 2D point of the 2D rectangle (XY).
* @param iFill
*	the integer which allows to construct a 2D rectangle
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>: 
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D rectangle is filled
*				with graphic attributes.
*	<br> By default, the 2D rectangle is not filled.
*/
    CAT2DRectangleGP (const float iBottomLeft[2],
		      const float iTopRight[2],
		      const int iFill=NOFILL);
    
    
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
/**
* Draws the dynamic graphic primitive with a render.
* @param iRender
*	the render used to draw the dynamic graphic primitive.
*/
    virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;
    
    
/**
* Retrieves data about the 2D rectangle.
* @param oBottomLeft
*	the bottom-left 2D point of the 2D rectangle (XY).
* @param oTopRight
*	the top-right 2D point of the 2D rectangle (XY).
* @param oFill
*	the integer which allows to construct a 2D rectangle
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>: 
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D rectangle is filled
*				with graphic attributes.
*/   
    inline void Get (float **oBottomLeft, float **oTopRight, int *oFill) const;

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
   virtual int DetailCulling(CATRender *render);

/**
 * @nodoc
 */
   virtual void Visit(CATIGPVisitor& iVisitor) const final;
    
  protected:
    
    virtual ~CAT2DRectangleGP();
    
    
  private:
    
    int   _fill;
    float _topRight[2];
    float _bottomLeft[2];

};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline void CAT2DRectangleGP::Get (float **bottomLeft,
				   float **topRight,
				   int *fill) const
{
  *bottomLeft = (float *) _bottomLeft;
  *topRight   = (float *) _topRight;
  *fill       = _fill;
}


#endif
