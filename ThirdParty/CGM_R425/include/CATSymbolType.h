#ifndef _SymbolType_H
#define _SymbolType_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/** Enumerate the different marker types and symbol types.
 * <b>Role</b>: It must be used with @href CAT2DMarkerGP, @href CAT3DMarkerGP,
 * @href CAT2DSymbolGP, @href CAT2DArrowSymbolGP, @href CAT2DSymbolRep and
 * @href CAT2DArrowSymbolRep. <br>
 * Markers 2D/3D CROSS to FULLSQUARE2. <br>
 * Symbols 2D    OPEN_ARROW to the end.<br>
 * @param NOTUSED
 * Reserved.
 * @param CROSS
 * Use this enum to have a cross marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param PLUS
 * Use this enum to have a plus marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param CONCENTRIC
 * Use this enum to have a circle marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param COINCIDENT
 * Use this enum to have a two concentric circle marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param FULLCIRCLE
 * Use this enum to have a full circle marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param FULLSQUARE
 * Use this enum to have a full square marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param STAR
 * Use this enum to have a star marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param DOT
 * Use this enum to have a dot (3x3 pixels) marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param SMALLDOT
 * Use this enum to have a small dot (1 pixel) marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param MISC1
 * Use this enum to have a 45 degrees arrow marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param MISC2 
 * Use this enum to have a 225 degrees arrow marker.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param FULLCIRCLE2
 * Use this enum to have a full circle marker bigger than FULLCIRCLE.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param FULLSQUARE2
 * Use this enum to have a full square marker bigger then FULLSQUARE.<br>
 * <b>It must be used only for 2D/3D markers.</b>
 * @param OPEN_ARROW
 * Use this enum to have an unclosed arrow symbol (>).<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param UNFILLED_ARROW
 * Use this enum to have an unfilled arrow symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param BLANKED_ARROW
 * Use this enum to have an arrow symbol. The arrow's interior is filled with 
 * background color.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FILLED_ARROW
 * Use this enum to have a filled arrow symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param UNFILLED_CIRCLE
 * Use this enum to have an unfilled circle symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param BLANKED_CIRCLE
 * Use this enum to have a circle symbol. The circle's interior is filled with 
 * background color.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FILLED_CIRCLE
 * Use this enum to have a filled circle symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param CROSSED_CIRCLE
 * Use this enum to have a circle with a cross symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param BLANKED_SQUARE
 * Use this enum to have a square symbol. The square's interior is filled with 
 * background color.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FILLED_SQUARE 
 * Use this enum to have a filled square symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param BLANKED_TRIANGLE
 * Use this enum to have a triangle symbol. The triangle's interior is filled 
 * with background color.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FILLED_TRIANGLE
 * Use this enum to have a filled triangle symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param MANIPULATOR_SQUARE
 * Use this enum to have a filled square symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param MANIPULATOR_DIAMOND
 * Use this enum to have a filled diamond symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param MANIPULATOR_CIRCLE
 * Use this enum to have a filled circle symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param MANIPULATOR_TRIANGLE
 * Use this enum to have a filled triangle symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param DOUBLE_OPEN_ARROW
 * Use this enum to have a double arrow symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param DOUBLE_FILLED_ARROW
 * Use this enum to have a double filled arrow symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param WAVE
 * Use this enum to have a wave symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FULLDOUBLEROTATEARROWBLACKBORDER
 * Use this enum to have a wave symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FULLSQUAREBLACKBORDER
 * Use this enum to have a wave symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FULLDIAMONDBLACKBORDER
 * Use this enum to have a wave symbol.<br>
 * <b>It must be used only for 2D symbols.</b>
 * @param FULLCIRCLEBLACKBORDER
 * Use this enum to have a full circle with black border marker.<br>
 * <b>It must be used only for 2D markers.</b>
 */

enum CATSymbolType 
{ 
  NOTUSED,            
  CROSS,             
  PLUS,           
  CONCENTRIC,         
  COINCIDENT,        
  FULLCIRCLE,         
  FULLSQUARE,         
  STAR,
  DOT,
  SMALLDOT,
  MISC1,
  MISC2,
  FULLCIRCLE2,         
  FULLSQUARE2,                 
  OPEN_ARROW,
  UNFILLED_ARROW,
  BLANKED_ARROW,
  FILLED_ARROW,
  UNFILLED_CIRCLE,
  BLANKED_CIRCLE,
  FILLED_CIRCLE,
  CROSSED_CIRCLE,
  BLANKED_SQUARE,
  FILLED_SQUARE,
  BLANKED_TRIANGLE,
  FILLED_TRIANGLE,
  MANIPULATOR_SQUARE,
  MANIPULATOR_DIAMOND,
  MANIPULATOR_CIRCLE,
  MANIPULATOR_TRIANGLE,
  DOUBLE_OPEN_ARROW,
  WAVE,
  DOUBLE_FILLED_ARROW,
  FULLDOUBLEROTATEARROWBLACKBORDER,
  FULLSQUAREBLACKBORDER,
  FULLDIAMONDBLACKBORDER,
  FULLCIRCLEBLACKBORDER
};

/** @nodoc */
typedef CATSymbolType SymbolType ;

#endif
