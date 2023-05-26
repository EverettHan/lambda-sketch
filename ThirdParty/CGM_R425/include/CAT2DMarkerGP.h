#ifndef CAT2DMarkerGP_H
#define CAT2DMarkerGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CATGraphicPrimitive.h"
#include "CATSymbolType.h"
#include "CATVizMacForMetaClass.h"

class CATStreamer;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG2DPoint;
class CAT2DMarkerGPIVisSG2DPointBOAImpl;
//-- SGCAAPlan

/**
* Class to create a dynamic graphic primitive of a 2D Marker.
* <b>Role</b>: 
* A 2D Marker has a fixed zoom. Its size in pixel does not change.
* It can be composed of various representations of a same symbol placed in diferents positions.
*/
class ExportedBySGInfra CAT2DMarkerGP : public CATGraphicPrimitive
{
  CATDeclareClass;
  CATVizDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT2DMarkerGP, IVisSG2DPoint, CAT2DMarkerGPIVisSG2DPointBOAImpl);
  
public:

/**
 * Default constructor.
 */
   CAT2DMarkerGP ();

/**
* Constructs a 2D Marker Graphic primitive.
* @param iPoint
*	array which describes positions of each symbol which compose the 2D Marker (XYXYXY...).
*	Its size is <tt>iNb_point</tt>*2.
* @param iNb_point
*	total number of symbol to create.
*	<br><b>legal values</b>:
*	The default value is 1. So by default a 2D marker contains just one symbol.
* @param iSymbol
*	the type of 2D Marker.
*	All symbols which compose the 2D marker have the same type.
*	<br><b>legal values</b>:
*	<ul>
*	<li> CROSS : a cross which looks like a "X".</li>
*	<li> PLUS : a cross which looks like a "+"</li>
*	<li> CONCENTRIC : an unfilled circle</li>
*	<li> COINCIDENT : two unfilled concentric circles</li>
*	<li> FULLCIRCLE : a filled circle</li>
*	<li> FULLSQUARE : a filled square</li>
*	<li> STAR : a star which is the union of a 2D marker CROSS ,a 2D marker PLUS and a 2D marker DOT</li>
*	<li> DOT : a dot </li>
*	<li> SMALLDOT : a smalldot (one pixel)</li>
*	<li> MISC1 : a kind of arrow which points to the bottom-left
*	<pre>
*	     /
*	|  /
*	|/__
*	</pre>
*	</li>
*	<li> MISC2 : a kind of arrow which points to the top-rigth
*	<pre>
*	    ___ 	
*	      /|
*	    /  |
*	  /
*	</pre>
*	</li>
*	<li> FULLCIRCLE2 : a big FULLCIRCLE</li>
*	<li> FULLSQUARE2 : a big FULLSQUARE</li>
*	</ul>
*	<br>By default, the 2D marker represents a CROSS.
*/
   CAT2DMarkerGP (const float iPoints[],
		  const int iNb_point = 1,
		  CATSymbolType iSymbol = CROSS);
   
   
/**
* Retrieves data about the 2D Marker.
* @param oPoints
*	array which describes positions of each symbol which compose the 2D Marker (XYXYXY...).
*	Its size is <tt>iNb_point</tt>*2.
* @param oNb_point
*	total number of symbols which composed the 2D marker.
* @param oSymbol
*	the type of 2D Marker.
*	All symbols which compose the 2D marker have the same type.
*	<br><b>legal values</b>:
*	<ul>
*	<li> CROSS : a cross which looks like a "X".</li>
*	<li> PLUS : a cross which looks like a "+"</li>
*	<li> CONCENTRIC : an unfilled circle</li>
*	<li> COINCIDENT : two unfilled concentric circles</li>
*	<li> FULLCIRCLE : a filled circle</li>
*	<li> FULLSQUARE : a filled square</li>
*	<li> STAR : a star which is the union of a 2D marker CROSS ,a 2D marker PLUS and a 2D marker DOT</li>
*	<li> DOT : a dot </li>
*	<li> SMALLDOT : a smalldot (one pixel)</li>
*	<li> MISC1 : a kind of arrow which points to the bottom-left
*	<pre>
*	     /
*	|  /
*	|/__
*	</pre>
*	</li>
*	<li> MISC2 : a kind of arrow which points to the top-rigth
*	<pre>
*	    ___ 	
*	       /|
*	     /  |
*	   /
*	</pre>
*	</li>
*	<li> FULLCIRCLE2 : a big FULLCIRCLE</li>
*	<li> FULLSQUARE2 : a big FULLSQUARE</li>
*	</ul>
*/ 
   inline void Get (float **oPoints, int *oNb_point, CATSymbolType *oSymbol) const;

  /**
   * Defines the 2D Marker type.
   * @param iSymbol
   *	The type of the 2D Marker.
   */
  inline HRESULT SetSymbol(CATSymbolType iSymbol);

  /**
   * Retrieves the 2D Marker type.
   * @param oSymbol
   *	The type of the 2D Marker.
   */
  inline HRESULT GetSymbol(CATSymbolType& oSymbol);
   
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

 protected :

    virtual ~CAT2DMarkerGP();


 private :

   CATSymbolType _symbol;
   int        _nb_points;  /** @win64 fbq : 64-bit structure padding **/
   float      *_points;

};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline void CAT2DMarkerGP::Get (float **points,
				int *nb_points,
				CATSymbolType *symbol) const
{
 *symbol    = _symbol;
 *points    = _points;
 *nb_points = _nb_points;
}

inline HRESULT CAT2DMarkerGP::SetSymbol(CATSymbolType iSymbol)
{
  _symbol = iSymbol;
  return S_OK;
}

inline HRESULT CAT2DMarkerGP::GetSymbol(CATSymbolType& oSymbol)
{
  oSymbol = _symbol;
  return S_OK;
}

#endif
