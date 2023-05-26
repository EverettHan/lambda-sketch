#ifndef CAT2DFixedArrowGP_H
#define CAT2DFixedArrowGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */



#include "CATDynamicGP.h"
#include "CATMathPoint2Df.h"
#include "CATMathDirection2Df.h"
#include "SGInfra.h"  
#include "CATVisMacroForInterfaces.h"
#include <string.h> // strdup
 
#ifndef NOFILL
/** @nodoc */
#define NOFILL 0
/** @nodoc */
#define FILL 1
#endif

class IVisSG2DPrimitive;
class CAT2DFixedArrowGPIVisSG2DPrimitiveBOAImpl;

/**
* Class to create a dynamic graphic primitive of a 2D fixed arrow.
* <b>Role</b>: Graphic primitive to display a 2D arrow whose size remains  
* constant on the screen (i.e., does not change with zoom, etc.).
*/ 
class ExportedBySGInfra CAT2DFixedArrowGP : public CATDynamicGP
{
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT2DFixedArrowGP, IVisSG2DPrimitive, CAT2DFixedArrowGPIVisSG2DPrimitiveBOAImpl);
  public : 


/**
* Constructs an empty 2D fixed arrow dynamic graphic primitive.
*/
    CAT2DFixedArrowGP ();  

/**
* Constructs a 2D fixed arrow dynamic graphic primitive.
*<pre>
*
*                                            ->      <- Arrowhead Length
*                                              |--
*  Arrow     Direction of arrow (a vector) ->  |  --
*  Start    +----------------------------------|    + Arrow Tip Pt
*   Pt                                         |  --
*                                              |--
*           <----------  Length of Arrow  ---------->
*</pre>
* @param iStartPt
*	the start point of the 2D fixed arrow.
* @param iDirection
*	the direction of the 2D fixed arrow.<br>
*	The direction vector is assumed to be normalized.
* @param iArwLength
*	the lenght of the 2D fixed arrow (lenght from arrow start point to arrow tip point).
*	<br><b>legal values</b>: the default value is 0.
* @param iArwheadLength
*	the lenght of the head of the 2D fixed arrow.
*	<br><b>legal values</b>: the default value is 0.
* @param iAngle
*	the angle (in radians) formed by the line going from 
*	<tt>iPoint</tt> and directed by <tt>iDirection</tt>, and one of the slanted arrowhead 
*	lines.
*	It determines how wide the arrowhead is at the base. 
*	<br><b>legal values</b>: the default value is 0.
* @param iFill
*	allows to construct a 2D fixed arrow
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>: 
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D fixed arrow is filled
*				with graphic attributes.	
*/	
    CAT2DFixedArrowGP (const CATMathPoint2Df &iStartPt, 
                       const CATMathDirection2Df &iDirection,  
                       const float iArwLength = 0.f, 
                       const float iArwheadLength = 0.f,
                       const float iAngle = 0.f, 
                       const int iFill = NOFILL);
        
/**
* Retrieves data about the 2D fixed arrow.
* @param oStartPt
*	the start point of the 2D fixed arrow.
* @param oDirection
*	the direction of the 2D fixed arrow.<br>
*	The direction vector is assumed to be normalized.
* @param oArwLength
*	the lenght of the 2D fixed arrow (lenght from arrow start point to arrow tip point).
*	<br><b>legal values</b>: the default value is 0.
* @param oArwheadLength
*	the lenght of the head of the 2D fixed arrow.
*	<br><b>legal values</b>: the default value is 0.
* @param oAngle
*	the angle (in radians) formed by the line going from
*	<tt>iPoint</tt> and directed by <tt>iDirection</tt>, and one of the slanted arrowhead
*	lines.
*	It determines how wide the arrowhead is at the base.
*	<br><b>legal values</b>: the default value is 0.
* @param oFill
*	the integer which allows to construct a 2D fixed arrow
*	just with edges or filled with graphic attributes.
*	<br><b>legal values</b>:
*		<br>NOFILL : just edges are drawn.
*		<br>FILL : the 2D fixed arrow is filled
*				with graphic attributes.
* @param oText
*	the text displayed along the arrow.
*/
	inline void Get(CATMathPoint2Df &oStartPt, CATMathDirection2Df &oDirection, float &oArwLength, float &oArwheadLength, float &oAngle, int &oFill, char *&oText);

/**
* Associates some text with the 2D fixed arrow.
* This text is displayed near the 2D fixed arrow.
* @param iText
*	the string of characters which represents the text to display 
*	near the 2D fixed arrow.
*/
    void AssociateText (char *iText);
   
#ifdef CATIAR426
    /** @nodoc */
    virtual void Draw(CATRender& iRender) override final;
#endif 

/** 
* Draws a 2D fixed arrow.
* @param iRender
*	the render used to draw the 2D fixed arrow.
* @param iViewpoint
*	the viewpoint used to draw the 2D fixed arrow.
* @param iViewport
*	the viewPort used to draw the 2D fixed arrow.
*/
    virtual void ImmediateDraw (CATRender &iRender, 
                                const CATViewpoint *iViewpoint, 
                                const CATViewport *iViewPort) GP_FUNC_OVERRIDE_FINAL;  
    
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

  protected :

    virtual ~CAT2DFixedArrowGP();

  private :   

    enum { NUMPTS = 10 };

    CATMathPoint2Df       _StartPt;
    CATMathDirection2Df   _Direction;
    float                 _ArwLength; 
    float                 _ArwheadLength;
    float                 _Angle; 
    int                   _Fill;
    float                 _Points[NUMPTS];
    float                 _TextPt[2];
    char                * _Text;
};

inline void CAT2DFixedArrowGP::Get(CATMathPoint2Df &startPt, CATMathDirection2Df &direction, float &arwLength, float &arwheadLength, float &angle, int &fill, char* &text)
{
	startPt = _StartPt;
	direction = _Direction;
	arwLength = _ArwLength;
	arwheadLength = _ArwheadLength;
	angle = _Angle;
	fill = _Fill;
	text = _Text ? strdup(_Text) : NULL;
}
#endif
