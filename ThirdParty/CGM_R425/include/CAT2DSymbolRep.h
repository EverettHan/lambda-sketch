#ifndef CAT2DSymbolRep_H
#define CAT2DSymbolRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"

#include "CAT2DRep.h"
#include "CATSymbolType.h"

class CAT2DSymbolGP;

/**
* Class to create a representation of a 2D Symbol.
*/
class ExportedBySGInfra CAT2DSymbolRep : public CAT2DRep
{
  CATDeclareClass;
public:

  /**
  * Constructs an empty representation of a 2D symbol.
  */
  static CAT2DSymbolRep* CreateRep();

  /**
  * Constructs a 2D symbol representation.
  * @param iPoint
  *	the position of the representation in a 2D space (in model coordinates).
  * @param iSize
  *	the size of the 2D symbol.
  * @param iSymbol
  *	the type of 2D Symbol.
  *	<br><b>legal values</b>:
  *	<ul>
  *	<li>UNFILLED_CIRCLE : an unfilled circle</li>
  *	<li>BLANKED_CIRCLE : a circle composed of an unfilled circle and a circle filled with the background color.</li>
  *	<li>FILLED_CIRCLE : a filled circle.</li>
  *	<li>CROSSED_CIRCLE : a BLANKED_CIRCLE symbol with a cross which looks like a "X".</li>
  *	<li>BLANKED_SQUARE : a square composed of an unfilled square and a square filled with the background color.</li>
  *	<li>FILLED_SQUARE : a filled square.</li>
  *	<li>BLANKED_TRIANGLE : a triangle composed of an unfilled triangle and a triangle filled with the background color.</li>
  *	<li>FILLED_TRIANGLE : a filled triangle.</li>
  *	<li>MANIPULATOR_SQUARE : a square composed of a white unfilled square and a black filled square</li>
  *	<li>MANIPULATOR_DIAMOND : a square rotated of 45 degrees  composed of a white unfilled square and a black filled square</li>
  *	<li>MANIPULATOR_CIRCLE : a circle composed of a white unfilled circle and a black filled circle</li>
  *	<li>MANIPULATOR_TRIANGLE : a triangle composed of a white unfilled triangle and a black filled triangle</li>
  *	</ul>
  * @param iZoom
  *	the type of size values.
  *	<br><b>legal values</b>:
  *	<ul><li> 0 :
  *		size is expressed in millimeters.</li>
  *	<li> 1 :
  *		size is expressed in model unit.</li>
  *	</ul>
  */
  static CAT2DSymbolRep* CreateRep(const CATMathPoint2Df& iPoint, const float iSize, CATSymbolType iSymbol, const int iZoom = 0);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DSymbolRep::CreateRep
  * Default constructor.
  */
  CAT2DSymbolRep();

  /**
  * @deprecated R422 CAT2DSymbolRep::CreateRep
  * Constructs a 2D symbol representation.
  * @param iPoint
  *	the position of the representation in a 2D space (in model coordinates).
  * @param iSize
  *	the size of the 2D symbol.
  * @param iSymbol
  *	the type of 2D Symbol.
  *	<br><b>legal values</b>:
  *	<ul>
  *	<li>UNFILLED_CIRCLE : an unfilled circle</li>
  *	<li>BLANKED_CIRCLE : a circle composed of an unfilled circle and a circle filled with the background color.</li>
  *	<li>FILLED_CIRCLE : a filled circle.</li>
  *	<li>CROSSED_CIRCLE : a BLANKED_CIRCLE symbol with a cross which looks like a "X".</li>
  *	<li>BLANKED_SQUARE : a square composed of an unfilled square and a square filled with the background color.</li>
  *	<li>FILLED_SQUARE : a filled square.</li>
  *	<li>BLANKED_TRIANGLE : a triangle composed of an unfilled triangle and a triangle filled with the background color.</li>
  *	<li>FILLED_TRIANGLE : a filled triangle.</li>
  *	<li>MANIPULATOR_SQUARE : a square composed of a white unfilled square and a black filled square</li>
  *	<li>MANIPULATOR_DIAMOND : a square rotated of 45 degrees  composed of a white unfilled square and a black filled square</li>
  *	<li>MANIPULATOR_CIRCLE : a circle composed of a white unfilled circle and a black filled circle</li>
  *	<li>MANIPULATOR_TRIANGLE : a triangle composed of a white unfilled triangle and a black filled triangle</li>
  *	</ul>
  * @param iZoom
  *	the type of size values.
  *	<br><b>legal values</b>:
  *	<ul><li> 0 :
  *		size is expressed in millimeters.</li>
  *	<li> 1 :
  *		size is expressed in model unit.</li>
  *	</ul>
  */
  CAT2DSymbolRep(const CATMathPoint2Df& iPoint, const float iSize, CATSymbolType iSymbol, const int iZoom = 0);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DSymbolRep();

  #if defined(REMOVE_USELESS_INCLUDE)
    #pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
  #endif
  /**
  * @nodoc
  */
  virtual void DrawShading(CATRender&, int) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
  /**
  * @nodoc
  */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
  /**
  * @nodoc
  */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual int GetGeomIndex(const CATGraphicPrimitive* gp);
  /**
  * Modifies the position of the 2D symbol.
  * @param iPoint
  *	the new position of the 2D symbol.
  */
  void Modify(const CATMathPoint2Df& iPoint);

protected:

  /**
  * @nodoc
  */
  void BuildSymbol(const CATMathPoint2Df& point, const float size_in_mm, CATSymbolType symbol, const int zoom);

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  /**
 * @nodoc
 */
  CAT2DSymbolGP* _geometrie;

  /**
  * @nodoc
  */
  CATSymbolType _Symbol;

  /**
  * @nodoc
  */
  float _Size;

  /**
  * @nodoc
  */
  int _Zoom;
};

#endif 









