#ifndef CAT2DArrowSymbolRep_H
#define CAT2DArrowSymbolRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */



#include "SGInfra.h"

#include "CAT2DRep.h"
#include "CATSymbolType.h"

class CAT2DArrowSymbolGP;


/**
* Class to create a representation of a 2D arrow symbol.
*/
class ExportedBySGInfra CAT2DArrowSymbolRep : public CAT2DRep
{
  friend class CATDmuStream2DArrowSymbolRep;
  CATDeclareClass;

public:

  /**
  * Constructs a 2D arrow symbol representation.
  * @param iPoint
  *	the position of the 2D arrow symbol.<br>
  *	This is the point which represents the top of the 2D arrow symbol.
  * @param iDirection
  *	the direction vector of the 2D arrow symbol.
  *	The Direction vector is assumed to be normalized
  * @param iSize_in_mm
  *	the size of the 2D arrow symbol among the axis defined by the direction vector.
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
  static CAT2DArrowSymbolRep* CreateRep(const float iPoint[2], const float iDirection[2], const float iSize_in_mm, const float iAngle, CATSymbolType iSymbol, const int iZoom = 0);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 08042022 " __FILE__ " Use CreateRep to instantiate the class " )
#endif
  BEGIN_MIGRATE_REP_CTOR_PROTECTED
  /**
  * @deprecated R422 CAT2DArrowSymbolRep::CreateRep
  * Constructs a 2D arrow symbol representation.
  * @param iPoint
  *	the position of the 2D arrow symbol.<br>
  *	This is the point which represents the top of the 2D arrow symbol.
  * @param iDirection
  *	the direction vector of the 2D arrow symbol.
  *	The Direction vector is assumed to be normalized
  * @param iSize_in_mm
  *	the size of the 2D arrow symbol among the axis defined by the direction vector.
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
  CAT2DArrowSymbolRep(const float iPoint[2], const float iDirection[2], const float iSize_in_mm, const float iAngle, CATSymbolType iSymbol, const int iZoom = 0);
  END_MIGRATE_REP_CTOR

  virtual ~CAT2DArrowSymbolRep();

  #if defined(REMOVE_USELESS_INCLUDE)
    #pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
  #endif
  /**
  * @nodoc
  */
  virtual void DrawShading(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;

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

protected:

  /**
   * @nodoc
   * Constructs an empty 2DArrowSymbolRep -UnStreaming-
   */
  CAT2DArrowSymbolRep();

  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  /** @nodoc */
  CAT2DArrowSymbolGP* _geometrie;

};

#endif 









