#ifndef CATColorName_H
#define CATColorName_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/** 
 * Specifies a group of predefined color names.
 * <b><br>Role</b>: This set of color name can be used in 
 * the @href CATGraphicAttributeSet#SetColor method.
 * @param TRUECOLOR
 * To be used when you want to set a color to a rep by specifying its
 * red, green and blue components.<br>
 * Example to set the red color to a CATxxRep :
 * <pre>    CATxxRep *rep = new CATxxRep();
 *          rep->GetGraphicAttributeSet().SetColor(TRUECOLOR);
 *          rep->GetGraphicAttributeSet().SetColorRGBA(255,0,0);</pre>
 * But the <b>easiest way</b> to do that is:
 * <pre>    rep->SetColorRGBA(255,0,0);</pre>
 * @param BACKGROUND
 * To be used when you want to specify the BACKGROUND color.<br>
 * The red, green and blue components can be redefined with 
 * Tools/Options + General + Display + Visualization + Background
 * @param FOREGROUND
 * To be used when you want to specify the FOREGROUND color.<br>
 * This color is always visible on a BACKGROUND color.
 * @param LOWLIGHT
 * To be used when you want to specify the low-intensified element color.<br>
 * The red, green and blue components can be redefined with 
 * Tools/Options + General + Display + Visualization + Low-intensity elements.<br>
 * @param HIGHLIGHT
 * To be used when you want to specify the selected element color.<br>
 * The red, green and blue components can be redefined with 
 * Tools/Options + General + Display + Visualization + Selected elements.<br>
 * The HIGHLIGHT color is applied on an object which is under the mouse without
 * being selected (pre-highlight) or an selected object excepted for egdes i
 * (highlight).
 * @param PREHIGHLIGHT
 * To be used when you want to specify the PREHIGHLIGHT color.<br>
 * This define has not real meaning in ours frameworks.
 * @param BLACK
 * To be used when you want to specify the BLACK color. 
 * @param WHITE
 * To be used when you want to specify the WHITE color.
 * @param RED
 * To be used when you want to specify the RED color.
 * @param GREEN
 * To be used when you want to specify the GREEN color.
 * @param BLUE
 * To be used when you want to specify the BLUE color.
 * @param YELLOW
 * To be used when you want to specify the YELLOW color.
 * @param MAGENTA
 * To be used when you want to specify the MAGENTA color.
 * @param CYAN
 * To be used when you want to specify the CYAN color.
 * @param HANDLECOLOR
 * To be used when you want to specify the HANDLE color.<br>
 * The red, green and blue components can be redefined with 
 * Tools/Options + General + Display + Visualization + Handles.<br>
 * The HANDLE color is applied on a handle object.
 * @param UPDATENEEDED
 * To be used when you want to specify the UPDATENEEDED color.<br>
 * The red, green and blue components can be redefined with 
 * Tools/Options + General + Display + Visualization + Update needed.<br>
 * The UPDATENEEDED color is applied on an object which needs to be updated.
 * @param EDGEHIGHLIGHT
 * To be used when you want to specify the EDGEHIGHLIGHT color.<br>
 * The red, green and blue components can be redefined (V5R5 or higher) with 
 * Tools/Options + General + Display + Visualization + Selected edges.<br>
 * The EDGEHIGHLIGHT color is applied on an selected edge object.
 */

typedef const unsigned int CATPredefinedColorName ;

#ifdef BLACK
#undef BLACK
#endif

#ifdef WHITE
#undef WHITE
#endif

#ifdef RED
#undef RED
#endif

#ifdef GREEN
#undef GREEN
#endif

#ifdef BLUE
#undef BLUE
#endif

#ifdef YELLOW
#undef YELLOW
#endif

/** @nodoc */
#define TRUECOLOR     255

/** @nodoc */
#define BACKGROUND    254

/** @nodoc */
#define FOREGROUND    253

/** @nodoc */
#define LOWLIGHT      252

/** @nodoc */
#define HIGHLIGHT     251

/** @nodoc */
#define PREHIGHLIGHT  250

/** @nodoc */
#define BLACK         249

/** @nodoc */
#define WHITE         248

/** @nodoc */
#define RED           247

/** @nodoc */
#define GREEN         246

/** @nodoc */
#define BLUE          245

/** @nodoc */
#define YELLOW        244

/** @nodoc */
#define MAGENTA       243

/** @nodoc */
#define CYAN          242

/** @nodoc */
#define HANDLECOLOR   241

/** @nodoc */
#define UPDATENEEDED  240

/** @nodoc */
#define EDGEHIGHLIGHT 239

#endif
