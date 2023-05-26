/* -*-c++-*- */
#ifndef CATVisPropertiesValues_H
#define CATVisPropertiesValues_H
//
// COPYRIGHT DASSAULT SYSTEMES 1999
//

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisPropertiesPrivateValues.h"
#include "CATShowAttribut.h"

#include "CATVisItf.h"
#include "CATVisPropertyType.h"
#include "CATSymbolType.h"
#include "CATPickAttribut.h"
#include "CATRenderingAttribut.h"

/**
* Class to represent a set of graphic properties.
* <b>Role</b>: This class is used in the @href CATIVisPropertiesAbstract#GetPropertiesAtt , @href CATIVisPropertiesAbstract#SetPropertiesAtt 
* and in the @href CATIVisPropertiesAbstract#ResetPropertiesAtt methods. 
* @see CATIVisProperties
*/

class CATUuid;
class ExportedByCATVisItf CATVisPropertiesValues : public CATVisPropertiesPrivateValues
{
public:

  /** 
  * Constructs a graphic property set.
  */
  CATVisPropertiesValues ();

  /**
  * Sets the color.
  * @param iRed
  * A value between 0 and 255.
  * @param iGreen
  * A value between 0 and 255.
  * @param iBlue
  * A value between 0 and 255.
  * @param iInheritance
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>0</tt>
  * <dd>No heritance 
  * <dt><tt>1</tt>
  * <dd>Heritance
  * </dl>
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */

  HRESULT SetColor   (unsigned int  iRed, unsigned int  iGreen, unsigned int  iBlue, unsigned int  iInheritance=0);

  /**
  * Retrieves the color.
  * @param oRed
  * A value between 0 and 255.
  * @param oGreen
  * A value between 0 and 255.
  * @param oBlue
  * A value between 0 and 255.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The color has been defined using the @href #SetColor method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The color has not been defined using the @href #SetColor method or the color has been 
  * reset using the @href #ResetColor method.
  * </dl> 
  */
  HRESULT GetColor   (unsigned int& oRed, unsigned int& oGreen, unsigned int& oBlue);

  /**
  * Resets the color.
  * The color becomes undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetColor ();

  /**
  * Sets the opacity value.
  * @param iOpacity
  * The opacity is defined from 255 (total opacity) to 0 (total transparency). 
  * <br>In Material visualization mode the transparency is real, so the element
  * is truly  more or less opaque. But in any other visualization mode, the transparency is a 
  * simulation, so if the opacity is between 0 and 254, the element is transparent and displayed
  * in the same way whatever the opacity value, and if the opacity is 255 the element is opaque. 
  * @param iInheritance
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>0</tt>
  * <dd>No heritance for the opacity
  * </dl>
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetOpacity   (unsigned int  iOpacity, unsigned int  iInheritance=0);

  /**
  * Retrieves the opacity value.
  * @param oOpacity
  * A value between 0 and 255.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The opacity has been defined using the @href #SetOpacity  method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The opacity has not been defined using the @href #SetOpacity method or the 
  * opacity has been reset using the @href #ResetOpacity  method.
  * </dl> 
  */
  HRESULT GetOpacity   (unsigned int& oOpacity);

  /**
  * Resets the opacity value.
  * The opacity becomes undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetOpacity ();

  /**
  * Sets the point symbol.
  * @param iSymbol
  *     The point symbol.
  *	<br><b>legal values</b>:
  *	<ul>
  *	<li> CROSS: a cross which looks like a "X".</li>
  *	<li> PLUS: a cross which looks like a "+"</li>
  *	<li> CONCENTRIC: an unfilled circle</li>
  *	<li> COINCIDENT: two unfilled concentric circles</li>
  *	<li> FULLCIRCLE: a filled circle</li>
  *	<li> FULLSQUARE: a filled square</li>
  *	<li> STAR: a star which is the union of a 2D marker CROSS, a 2D marker PLUS and a 2D marker DOT</li>
  *	<li> DOT: a dot </li>
  *	<li> SMALLDOT: a smalldot whose size is one pixel</li>
  *	<li> MISC1: a kind of arrow which points to the bottom-left
  *	<pre>
  *	     /
  *	|  /
  *	|/__
  *	</pre>
  *	</li>
  *	<li> MISC2: a kind of arrow which points to the top-rigth
  *	<pre>
  *	    ___ 	
  *	      /| 
  *	    /  |
  *	  /
  *	</pre>
  *	</li>
  *	<li> FULLCIRCLE2: a big FULLCIRCLE</li>
  *	<li> FULLSQUARE2: a big FULLSQUARE</li>
  *	</ul>
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetSymbolType    (CATSymbolType  iSymbol);

  /** @nodoc . */
  HRESULT SetSymbol    (unsigned int  iSymbol);

  /**
  * Retrieves the point symbol. 
  * @param oSymbol
  *   The point symbol.
  *   <br>see the @href #SetSymbolType method to have the list of legal values. 
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The symbol has been defined using the @href #SetSymbolType method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The symbol has not been defined using the @href #SetSymbolType  method 
  * or the symbol has been reset using the @href #ResetSymbolType  method.
  * </dl> 
  */
  HRESULT GetSymbolType    (CATSymbolType& oSymbol);

  /** @nodoc . */
  HRESULT GetSymbol    (unsigned int& oSymbol);

  /**
  * Resets the point symbol.
  * The symbol becomes undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetSymbolType  ();

  /** @nodoc . */
  HRESULT ResetSymbol  ();

  /**
  * Sets the line type.
  * @param iLineType
  * The value ranges from 1 to 63. Each index is a line type customizable in
  * the Tools/Options/General/Display/Line Type property page.
  * @param iInheritance
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>0</tt>
  * <dd>No heritance 
  * <dt><tt>1</tt>
  * <dd>Heritance
  * </dl> 
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetLineType    (unsigned int  iLineType, unsigned int  iInheritance=0);

  /**
  * Retrieves the line type.
  * @param oLineType
  * The value ranges from 1 to 63. Each index is a line type customizable in
  * the page Tools/Options/General/Display/Line Type.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The line type has been defined using the @href #SetLineType method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The line type has not been defined using the @href #SetLineType method or 
  * the line type has been reset using the @href #ResetLineType  method.
  * </dl> 
  */
  HRESULT GetLineType    (unsigned int& oLineType);

  /**
  * Resets the line type.
  * The line type becomes undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetLineType  ();

   /**
  * Sets the line width.
  * @param iWidth
  * The value ranges from 1 to 63. Each index is a thickness customizable in
  * the Tools/Options/General/Display/thickness property page.
  * @param iInheritance
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>0</tt>
  * <dd>No heritance 
  * <dt><tt>1</tt>
  * <dd>Heritance
  * </dl> 
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetWidth    (unsigned int  iWidth, unsigned int  iInheritance=0);

  /**
  * Retrieves the line width.
  * @param oWidth
  * The value ranges from 1 to 63. Each index is a thickness customizable in
  * the Tools/Options/General/Display/thickness property page.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The line width has been defined using the @href #SetWidth method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The line width has not been defined using the @href #SetWidth method or 
  * the line width has been reset using the @href #ResetWidth  method.
  * </dl> 
  */
  HRESULT GetWidth    (unsigned int& oWidth);

  /**
  * Resets the line width.
  * The line width becomes undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetWidth  ();

  /**
  * Sets the inheritance flag for a given property.
  * @param iType
  * The type of property. The <b>legal values></b> are:Color,Opacity,Line Type,Line Width.  
  * @param oInheritance
  * The inheritance flag for the iType property.
  * <br><b>Legal value:</b>
  * <dl>
  * <dt><tt>0</tt>
  * <dd>No heritance 
  * <dt><tt>1</tt>
  * <dd>Heritance
  * </dl> 
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>iType is valid
  * <dt><tt>E_FAIL</tt>
  * <dd>iType is not valid.
  * </dl> 
  */
  HRESULT SetInheritance    (CATVisPropertyType iType, unsigned int  iInheritance);

  /**
  * Retrieves the inheritance flag for a given property.
  * @param iType
  * The type of property. The <b>legal values></b> are:Color,Opacity,Line Type,Line Width.  
  * @param oInheritance
  * The flag of inheritance for the iType property.
  * <br><b>Legal value:</b>
  * <dl>
  * <dt><tt>0</tt>
  * <dd>No heritance 
  * <dt><tt>1</tt>
  * <dd>Heritance
  * </dl> 
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The inheritance flag has been defined using the Setxxx method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The inheritance flag has not been defined using the the Setxxx method or 
  * the inheritance flag has been reset using the @href #ResetInheritance  method.
  * </dl> 
  */
  HRESULT GetInheritance    (CATVisPropertyType iType, unsigned int& oInheritance);

  /**
  * Resets all inheritance flags.
  * All inheritance flags become undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetInheritance  ();

  /**
  * Sets the show flag.
  * @param iShow
  * The show flag
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetShowAttr    (CATShowAttribut  iShow);
  
  /** @nodoc. */
  HRESULT SetShow    (CATShowAttribut  iShow);

  /**
  * Retrieves the show flag.
  * @param oShow
  * The show flag
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The show flag has been defined using the @href #SetShowAttr method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The show flag has not been defined using the @href #SetShowAttr method or 
  * the show flag has been reset using the @href #ResetShowAttr  method.
  * </dl> 
  */
  HRESULT GetShowAttr    (CATShowAttribut& oShow);

  /** @nodoc. */
  HRESULT GetShow    (CATShowAttribut& oShow);

  /**
  * Resets the show flag.
  * The show flag becomes undefined
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetShowAttr  ();

  /** @nodoc. */
  HRESULT ResetShow  ();

   /**
  * Sets the pick flag.
  * @param iPick
  * The pick flag
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetPickAttr    (CATPickAttribut  iPick);

  /** @nodoc. */
  HRESULT SetPick    (unsigned int  iPick);

  /**
  * Retrieves the pick flag.
  * @param oPick
  * The pick flag
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The pick flag has been defined using the @href #SetPickAttr method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The pick flag has not been defined using the @href #SetPickAttr method or 
  * the pick flag has been reset using the @href #ResetPickAttr method.
  * </dl> 
  */
  HRESULT GetPickAttr    (CATPickAttribut& oPick);

  /** @nodoc. */
  HRESULT GetPick    (unsigned int& oPick);

  /**
  * Resets the pick flag.
  * The pick flag becomes undefined
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetPickAttr  ();

  /** @nodoc. */
  HRESULT ResetPick  ();

  /** @nodoc. */
  HRESULT SetLowInt    (unsigned int iLowInt);

  /** @nodoc. */
  HRESULT GetLowInt    (unsigned int& oLowInt);

  /** @nodoc. */
  HRESULT ResetLowInt  ();

  /** @nodoc. */
  HRESULT SetRenderingStyle    (CATRenderingAttribut iRenderingStyle);

  /** @nodoc. */
  HRESULT GetRenderingStyle    (CATRenderingAttribut& oRenderingStyle);

  /** @nodoc. */
  HRESULT ResetRenderingStyle  ();

  /** @nodoc. */
  HRESULT SetEffectID          (const CATUuid& iID);

  /** @nodoc. */
  HRESULT GetEffectID          (CATUuid& oID);

   /** @nodoc. */
  HRESULT SetEffectID          (const unsigned char iEffectID[16]);

  /** @nodoc. */
  HRESULT GetEffectID          (unsigned char oEffect[16]);

  /** @nodoc. */
  HRESULT ResetEffectID        ();


   /**
  * Sets the layer number.
  * @param iLayer
  * The layer number between 0 and 999
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT SetLayer    (unsigned int  iLayer);

  /**
  * Retrieves the layer number.
  * @param oLayer
  * The layer number between 0 and 999
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>The layer value has been defined using the @href #SetLayer method.
  * <dt><tt>E_FAIL</tt>
  * <dd>The layer value has not been defined using the @href #SetLayer method or 
  * the layer value has been reset using the @href #ResetLayer method.
  * </dl> 
  */
  HRESULT GetLayer    (unsigned int& oLayer);

  /**
  * Resets the layer value.
  * The layer value becomes undefined.
  * @return 
  * <b>Legal value:</b>
  * <dl>
  * <dt><tt>S_OK</tt>
  * </dl> 
  */
  HRESULT ResetLayer  ();

  /** @nodoc */
  void operator += (CATVisPropertiesValues& otherValue);

  /** @nodoc */
  //void operator = (CATVisPropertiesValues& otherValue);

};


#endif
