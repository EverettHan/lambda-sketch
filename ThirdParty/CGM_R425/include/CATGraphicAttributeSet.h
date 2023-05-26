#ifndef CATGraphicAttributeSet_H
#define CATGraphicAttributeSet_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATIAV5Level.h"

// Explicit Color
#include "CATColorName.h"

#include "VisDataType.h"
#include "VisAttributeID.h"
#include "CATSysErrorDef.h"

/** @nodoc */
typedef union
{
 int basic;
 struct
 {
#ifdef _ENDIAN_LITTLE
  unsigned no_pick     : 1; 
  unsigned highlight   : 1; 
  unsigned lowlight    : 1; 
  unsigned no_show     : 1; 

  unsigned type        : 2;
  unsigned showfree    : 1;
  unsigned transparent : 1;

  unsigned priority    : 4;
  unsigned thickness   : 6;
  unsigned linetype    : 6;

  unsigned color       : 8;
#else
  unsigned color       : 8;

  unsigned linetype    : 6;
  unsigned thickness   : 6;
  unsigned priority    : 4;

  unsigned transparent : 1;
  unsigned showfree    : 1;
  unsigned type        : 2;

  unsigned no_show     : 1; 
  unsigned lowlight    : 1; 
  unsigned highlight   : 1; 
  unsigned no_pick     : 1; 
#endif
 } extend ;
} AttributStruct;

/** @nodoc */
typedef union
{
 int basic;
 struct
 {
#ifdef _ENDIAN_LITTLE
  unsigned alpha : 8;
  unsigned blue  : 8;
  unsigned green : 8;
  unsigned red   : 8;
#else
  unsigned red   : 8;
  unsigned green : 8;
  unsigned blue  : 8;
  unsigned alpha : 8;
#endif
 } extend ;
} RGBAStruct;

/** @nodoc */
#define DEFAULT_VISU_PRIORITY 4
 
/** @nodoc */
#define COLOR_MASK     0xFF000000
/** @nodoc */
#define LINETYPE_MASK  0x003F0000
/** @nodoc */
#define PRIORITY_MASK  0x0000F000
/** @nodoc */
#define THICKNESS_MASK 0x00000F00
/** @nodoc */
#define OTHER_MASK     0x000000FF

/**
 * Class to create a graphic attribute.
 * <b>Role</b>: This class permits to have a graphic attribute which define
 * the display properties of an element. Always associated to a rep or a
 * graphic primitive.
 */
class CATGraphicAttributeSet
{
 public:

   /** Construct a graphic attribute.
    * @param iAtt
    * The value coresponding to set.basic.<br>
    * The default value is:<br><ul>
    * <li>set.extend.color       : FOREGROUND  ( 253, @see CATColorName ).
    * <li>set.extend.linetype    : 1 (Solid).
    * <li>set.extend.thickness   : 0 .
    * <li>set.extend.type        : 0 (none, no participation to ZBuffer). 
    * <li>set.extend.transparent : 0 (No transparency).
    * <li>set.extend.no_show     : 0 (Shown).
    * <li>set.extend.lowlight    : 0 (Not under intensified).
    * <li>set.extend.highlight   : 0 (Not intensified).
    * <li>set.extend.no_pick     : 0 (Pickable)
    * <li>set.extend.showFree    : 0 (Show/NoShow taken into account). 
    * <li>set.extend.priority    : 4 (default selection priority).</ul>
    * @param iRGBA
    * The red, green, blue and alpha component corresponding to rvba.basic.<br>
    * The default value is 255 (black and not transparent).<br>
    * Used only if set.extend.color = TRUECOLOR ( 255, @see CATColorName ).
    */

   inline CATGraphicAttributeSet ( unsigned int iAtt = 0xFD040400, unsigned int iRGBA = 0x000000FF); 


   /** Retrieves the indexed color.<br>
    * (Corresponding to set.extend.color)
    */
   inline unsigned int GetColor()       const;
   /** Retrieves the red, green,blue and alpha color components.<br>
    * (Corresponding to rvba.basic)
    */
   inline unsigned int GetColorRGBA()   const;
   /** Retrieves the red, green, blue and alpha color components.
    * @param oRed
    * The red component of the color.
    * <b>Legal values</b>: <tt>oRed</tt> ranges from 0 to 255.
    * @param oGreen
    * The green component of the color.
    * <b>Legal values</b>: <tt>oGreen</tt> ranges from 0 to 255.
    * @param oBlue
    * The blue component of the color.
    * <b>Legal values</b>: <tt>oBlue</tt> ranges from 0 to 255.
    * @param oAlpha
    * The alpha component of the color.
    * <b>Legal values</b>: <tt>oAlpha</tt> ranges from 0 to 255.
    */ 
   inline void GetColorRGBA(int* oRed, int* oGreen, int* oBlue, int* oAlpha)   const;
   /** Retrieves the line type.<br>
    * (Corresponding to set.extend.linetype)
    */
   inline unsigned int GetLineType()    const;
   /** Retrieves the advanced line type.<br>
    * (Corresponding to set.extend.thickness * 64 + set.extend.linetype)
    */
   inline unsigned int GetAdvancedLineType()    const;
   /** Retrieves the selection priority.<br>
    * (Corresponding to set.extend.priority)
    */
   inline unsigned int GetPriority()   const;
   /** Retrieves the thickness.<br>
    * (Corresponding to set.extend.thickness)
    */
   inline unsigned int GetThickness()   const;
   /** Retrieves the type.<br>
    * (Corresponding to set.extend.type)
    */
   inline unsigned int GetType()        const;
   /** Retrieves the show mode.<br>
    * (Corresponding to set.extend.no_show)
    */
   inline unsigned int IsHidden()       const;
   /** Retrieves the transparent mode.<br>
    * (Corresponding to set.extend.transparent)
    */
   inline unsigned int IsTransparent()  const;
   /** Retrieves the lowlight mode.<br>
    * (Corresponding to set.extend.lowlight)
    */
   inline unsigned int IsLowlighted()   const;
   /** Retrieves the highlight mode.<br>
    * (Corresponding to set.extend.highlight)
    */
   inline unsigned int IsHighlighted()  const;
   /** Retrieves the pick mode.<br>
    * (Corresponding to set.extend.no_pick)
    */
   inline unsigned int IsNotPickable()  const;
   /** Retrieves the showfree mode.<br>
    * (Corresponding to set.extend.showfree)
    */
   inline unsigned int IsShowFree()  const;

   /**
    * Call this method to retrieve one of the attribute values.
    * @param iAttributeID
    *   The value identifier.
    * @param iType
    *   The type in which the value has to be retrieved.
    * @param oValue
    *   The retrieved value.
    * @return
    *   <dl>
    *   <dt><tt>S_OK</tt>          <dd>If the has been succeessfully retrieved
    *   <dt><tt>E_INVALIDARG</tt>  <dd>If the value doesn't exist or can't be converted into the desired form
    *   <dt>Other                  <dd>If the value can't be retrieved for any other reason.
    *   </dl>
    */
   inline HRESULT GetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) const;

   /**
    * Call this method to set one of the attribute values.
    * @param iAttributeID
    *   The value identifier.
    * @param iType
    *   The type in which the value is specified.
    * @param iValue
    *   The value to set.
    * @return
    *   <dl>
    *   <dt><tt>S_OK</tt>          <dd>If the value has been succeessfully set
    *   <dt><tt>E_INVALIDARG</tt>  <dd>If the value doesn't exist or can't be converted from the specified form
    *   <dt>Other                  <dd>If the value can't be set for any other reason.
    *   </dl>
    */
   inline HRESULT SetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue);

   /** 
    * Sets the indexed color.
    * @param iColor
    * The index of the color.
    * <b>Legal values</b>: <tt>iColor</tt> ranges from 0 to 255.
    * <br>See @href CATPredefinedColorName to have predefined color. 
    */
   inline void SetColor(const unsigned int iColor = FOREGROUND);
   /** Sets the red, green, blue and alpha components color.
    * @param iRGBA
    * The components of the color.
    */
   inline void SetColorRGBA(const unsigned int iRGBA = 255);
   /** Sets the red, green, blue and alpha components color.
    * @param iRed
    * The red component of the color.
    * <b>Legal values</b>: <tt>iRed</tt> ranges from 0 to 255.
    * @param iGreen
    * The green component of the color.
    * <b>Legal values</b>: <tt>iGreen</tt> ranges from 0 to 255.
    * @param iBlue
    * The blue component of the color.
    * <b>Legal values</b>: <tt>iBlue</tt> ranges from 0 to 255.
    * @param iAlpha
    * The alpha component of the color.
    * <b>Legal values</b>: <tt>iAlpha</tt> ranges from 0 to 255.
    */ 
   inline void SetColorRGBA(const int iRed, const int iGreen, const int iBlue, const int iAlpha= 255);
   /** Sets the line type.
    * @param iLinetype
    * The line type.
    * <b>Legal values</b>: <tt>iLinetype</tt> ranges from 0 to 63.<ul>
    * <li>0 or 1 = Solid.
    * <li>2 = Dotted.
    * <li>3 = Dashed. 
    * <li>4 = Dot-dashed.
    * <li>5 = Phantom.
    * <li>6 = Small-dotted.
    * <li>7 = JIS Axis.
    * <li>8 to 63 = Solid or application dependant.</ul>
    */
   inline void SetLineType(const unsigned int iLinetype = 1);

   /** Sets the ADVANCED line type.
    * WARNING : to be used only with dedicated linetype tables allowing 4096 types, embedding both line type AND thickness
    * This method is not compatible with Set/GetLineType and Set/GetThickness
    * @param iAdvancedLineType
    * The advanced line type.
    * <b>Legal values</b>: <tt>iAdvancedLineType</tt> ranges from 0 to 4095.<ul>
    */
   inline void SetAdvancedLineType(const unsigned int iAdvancedLineType);

    /** Sets the thickness.
     * @param iThickness
     * The thickness index.
     * <b>Legal values</b>: <tt>iThickness</tt> range from 1 to 55.
     */
   inline void SetThickness(const unsigned int iThickness = 1);

    /** Sets the thickness.
     * @param iThickness
     * The thickness index.
     * <b>Legal values</b>: <tt>iThickness</tt> range from 1 to 8.
     */
   inline void SetFixedThickness(const unsigned int iThickness = 1);

   /** Sets the graphic element type.
    * @param itype
    * The type of the graphic element.
    * <b>Legal values</b>: <tt>iType</tt> ranges from 0 to 3.<ul>
    * <li>0 = None (no participation to ZBuffer).
    * <li>1 = Edge (participation to ZBuffer).
    * <li>2 = Skin (participation to ZBuffer + two-sided lighting).
    * <li>3 = Volume (participation to ZBuffer).</ul>
    */
   inline void SetType(const unsigned int iType = 0);
   /** Sets the transparency participation.
    * @param iMode
    * The transparency participation.
    * <b>Legal values</b>: <tt>iMode</tt> ranges from 0 to 1.<ul>
    * <li>0 = No transparency.
    * <li>1 = Transparency.</ul>
    */
   inline void SetTransparentMode(const unsigned int iMode = 0);
   /** Sets the show mode.
    * @param iMode
    * The show mode.
    * <b>Legal values</b>: <tt>iMode</tt> ranges from 0 to 1.<ul>
    * <li>0 = Shown.
    * <li>1 = Not shown.</ul>
    */
   inline void SetShowMode(const unsigned int iMode = 0);
   /** Sets the lowlight mode.
    * @param iMode
    * The lowlight mode.
    * <b>Legal values</b>: <tt>iMode</tt> ranges from 0 to 1.<ul>
    * <li>0 = No lowlight (Not under intensified).
    * <li>1 = lowlight (Under intensified).</ul>
    */
   inline void SetLowlightMode(const unsigned int iMode = 0);
   /** Sets the highlight mode.
    * @param iMode
    * The highlight mode.
    * <b>Legal values</b>: <tt>iMode</tt> ranges from 0 to 1.<ul>
    * <li>0 = No highlight (Not intensified).
    * <li>1 = Highlight (Intensified).</ul>
    */
   inline void SetHighlightMode(const unsigned int iMode = 0);
   /** Sets the pick mode.
    * @param iMode
    * The pick mode.
    * <b>Legal values</b>: <tt>iMode</tt> ranges from 0 to 1.<ul>
    * <li>0 = Pickable.
    * <li>1 = Not pickable.</ul>
    */
   inline void SetPickMode(const unsigned int iMode = 0);
   /** Increase the selection priority.
    * @param iStep
    * The increasing step.
    * <b>Legal values</b>: <tt>iStep</tt> ranges from 1 to n,
    * but set.extend.priority ranges from 0 to 15.
    */
   inline void IncreasePriority(const unsigned int iStep = 1);
   /** Decrease the selection priority.
    * @param iStep
    * The decreasing step.
    * <b>Legal values</b>: <tt>iStep</tt> ranges from 1 to n,
    * but set.extend.priority ranges from 0 to 15.
    */
   inline void DecreasePriority(const unsigned int iStep = 1);
   /** Sets the showfree mode.
    * @param iMode
    * The showfree mode.
    * <b>Legal values</b>: <tt>iMode</tt> ranges from 0 to 1.<ul>
    * <li>0 = Show/Noshow is taken into account.
    * <li>1 = Show/Noshow is not taken into account.</ul>
    */
   inline void SetShowFreeMode(const unsigned int iMode = 0);

   /**
    * @nodoc
    */
   inline CATGraphicAttributeSet& operator = (const CATGraphicAttributeSet &);
   /**
    * @nodoc
    */
   inline int operator == (const CATGraphicAttributeSet &) const;
   /**
    * @nodoc
    */
   inline int operator != (const CATGraphicAttributeSet &) const;
   /**
    * @nodoc
    */
   inline void SetPriority(const unsigned int iPriority = 4);

/** @nodoc */
   AttributStruct set;
/** @nodoc */
   RGBAStruct     rvba;   
};

//------------------------------------------------------------------------------

inline CATGraphicAttributeSet::CATGraphicAttributeSet ( unsigned int valeur, unsigned int rgba )
{ 
 set.basic  = valeur;
 rvba.basic = rgba;
}

// Get Attributes
inline unsigned int CATGraphicAttributeSet::GetColor()      const { return (set.extend.color); }
inline unsigned int CATGraphicAttributeSet::GetColorRGBA()  const { return (rvba.basic); }
inline unsigned int CATGraphicAttributeSet::GetPriority()   const { return (set.extend.priority); }
inline unsigned int CATGraphicAttributeSet::GetThickness()  const { return (set.extend.thickness); }
inline unsigned int CATGraphicAttributeSet::GetLineType()   const { return (set.extend.linetype); }
inline unsigned int CATGraphicAttributeSet::GetAdvancedLineType()   const { return (set.extend.thickness)* 64 + (set.extend.linetype); }
inline unsigned int CATGraphicAttributeSet::GetType()       const { return (set.extend.type); }
inline unsigned int CATGraphicAttributeSet::IsHidden()      const { return (set.extend.no_show); }
inline unsigned int CATGraphicAttributeSet::IsTransparent() const { return (set.extend.transparent); }
inline unsigned int CATGraphicAttributeSet::IsLowlighted()  const { return (set.extend.lowlight); }
inline unsigned int CATGraphicAttributeSet::IsHighlighted() const { return (set.extend.highlight); }
inline unsigned int CATGraphicAttributeSet::IsNotPickable() const { return (set.extend.no_pick); }
inline unsigned int CATGraphicAttributeSet::IsShowFree() const { return (set.extend.showfree); }


inline HRESULT CATGraphicAttributeSet::GetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) const
{
  HRESULT hr = E_INVALIDARG;

  if (0==oValue) return hr;

  switch (iAttributeID)
  {
    case VIS_INDEXED_COLOR:
      {
        int TheComponent = set.extend.color;

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR:
            ((unsigned char *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT:
            ((unsigned short *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT:
            ((unsigned int *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_SHORT:
            ((short *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_INT:
            ((int *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
        }
      }
      break;

    case VIS_LINE_TYPE:
    case VIS_LINE_THICKNESS:
    case VIS_ELEMENT_TYPE:
    case VIS_PICK_MODE:
    case VIS_PRIORITY:
    case VIS_SHOW_MODE:
    case VIS_TRANSPARENCY_MODE:
      {
        int TheComponent = 0;
        if      (VIS_LINE_TYPE==iAttributeID)          TheComponent = set.extend.linetype;
        else if (VIS_LINE_THICKNESS==iAttributeID)     TheComponent = set.extend.thickness;
        else if (VIS_ELEMENT_TYPE==iAttributeID)       TheComponent = set.extend.type;
        else if (VIS_PICK_MODE==iAttributeID)          TheComponent = set.extend.no_pick;
        else if (VIS_PRIORITY==iAttributeID)           TheComponent = set.extend.priority;
        else if (VIS_SHOW_MODE==iAttributeID)          TheComponent = set.extend.no_show;
        else if (VIS_TRANSPARENCY_MODE==iAttributeID)  TheComponent = set.extend.transparent;

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR:
            ((unsigned char *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT:
            ((unsigned short *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT:
            ((unsigned int *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_CHAR:
            ((char *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_SHORT:
            ((short *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_INT:
            ((int *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
        }
      }
      break;

      case VIS_RED_COLOR_COMPONENT:
      case VIS_GREEN_COLOR_COMPONENT:
      case VIS_BLUE_COLOR_COMPONENT:
      case VIS_ALPHA_COLOR_COMPONENT:
      {
        int TheComponent = 0;
        if      (VIS_RED_COLOR_COMPONENT==iAttributeID)    TheComponent = rvba.extend.red;
        else if (VIS_GREEN_COLOR_COMPONENT==iAttributeID)  TheComponent = rvba.extend.green;
        else if (VIS_BLUE_COLOR_COMPONENT==iAttributeID)   TheComponent = rvba.extend.blue;
        else if (VIS_ALPHA_COLOR_COMPONENT==iAttributeID)  TheComponent = rvba.extend.alpha;

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR:
            ((unsigned char *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT:
            ((unsigned short *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT:
            ((unsigned int *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_SHORT:
            ((short *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_INT:
            ((int *)oValue)[0] = TheComponent;
            hr = S_OK;
            break;    
          case VIS_FLOAT:
            ((float *)oValue)[0] = (float)TheComponent / 255.0f;
            hr = S_OK;
            break;    
          case VIS_DOUBLE:
            ((double *)oValue)[0] = (double)TheComponent / 255.0;
            hr = S_OK;
            break;    
        }
      }
      break;

    case VIS_RGBA_COLOR:
      {
        switch (iType)
        {
          case VIS_UNSIGNED_CHAR_4:
            ((unsigned char *)oValue)[0] = rvba.extend.red;
            ((unsigned char *)oValue)[1] = rvba.extend.green;
            ((unsigned char *)oValue)[2] = rvba.extend.blue;
            ((unsigned char *)oValue)[3] = rvba.extend.alpha;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT_4:
            ((unsigned short *)oValue)[0] = rvba.extend.red;
            ((unsigned short *)oValue)[1] = rvba.extend.green;
            ((unsigned short *)oValue)[2] = rvba.extend.blue;
            ((unsigned short *)oValue)[3] = rvba.extend.alpha;
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT_4:
            ((unsigned int *)oValue)[0] = rvba.extend.red;
            ((unsigned int *)oValue)[1] = rvba.extend.green;
            ((unsigned int *)oValue)[2] = rvba.extend.blue;
            ((unsigned int *)oValue)[3] = rvba.extend.alpha;
            hr = S_OK;
            break;    
          case VIS_SHORT_4:
            ((short *)oValue)[0] = rvba.extend.red;
            ((short *)oValue)[1] = rvba.extend.green;
            ((short *)oValue)[2] = rvba.extend.blue;
            ((short *)oValue)[3] = rvba.extend.alpha;
            hr = S_OK;
            break;    
          case VIS_INT_4:
            ((int *)oValue)[0] = rvba.extend.red;
            ((int *)oValue)[1] = rvba.extend.green;
            ((int *)oValue)[2] = rvba.extend.blue;
            ((int *)oValue)[3] = rvba.extend.alpha;
            hr = S_OK;
            break;    
          case VIS_FLOAT_4:
            ((float *)oValue)[0] = (float)rvba.extend.red   / 255.0f;
            ((float *)oValue)[1] = (float)rvba.extend.green / 255.0f;
            ((float *)oValue)[2] = (float)rvba.extend.blue  / 255.0f;
            ((float *)oValue)[3] = (float)rvba.extend.alpha / 255.0f;
            hr = S_OK;
            break;    
          case VIS_DOUBLE_4:
            ((double *)oValue)[0] = (double)rvba.extend.red   / 255.0;
            ((double *)oValue)[1] = (double)rvba.extend.green / 255.0;
            ((double *)oValue)[2] = (double)rvba.extend.blue  / 255.0;
            ((double *)oValue)[3] = (double)rvba.extend.alpha / 255.0;
            hr = S_OK;
            break;    
        }
      }
      break;
  }

  return hr;
}

inline HRESULT CATGraphicAttributeSet::SetValue(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue)
{
  HRESULT hr = E_INVALIDARG;

  if (0==iValue) return hr;

  switch (iAttributeID)
  {
    case VIS_INDEXED_COLOR:
      {
        int TheComponent = 0;

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR:
            TheComponent = ((unsigned char *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT:
            TheComponent = ((unsigned short *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT:
            TheComponent = ((unsigned int *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_SHORT:
            TheComponent = ((short *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_INT:
            TheComponent = ((int *)iValue)[0];
            hr = S_OK;
            break;    
        }

        if (TheComponent<0 || TheComponent>255) hr = E_FAIL;
        else set.extend.color = TheComponent;
      }
      break;

    case VIS_LINE_TYPE:
    case VIS_LINE_THICKNESS:
    case VIS_ELEMENT_TYPE:
    case VIS_PICK_MODE:
    case VIS_PRIORITY:
    case VIS_SHOW_MODE:
    case VIS_TRANSPARENCY_MODE:
      {
        int TheComponent = 0;

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR:
            TheComponent = ((unsigned char *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT:
            TheComponent = ((unsigned short *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT:
            TheComponent = ((unsigned int *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_CHAR:
            TheComponent = ((char *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_SHORT:
            TheComponent = ((short *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_INT:
            TheComponent = ((int *)iValue)[0];
            hr = S_OK;
            break;    
        }

        if (VIS_LINE_TYPE==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>63) hr = E_FAIL;
          else set.extend.linetype = TheComponent;
        }
        else if (VIS_LINE_THICKNESS==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>63) hr = E_FAIL;
          else set.extend.thickness = TheComponent;
        }
        else if (VIS_ELEMENT_TYPE==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>3) hr = E_FAIL;
          else set.extend.type = TheComponent;
        }
        else if (VIS_PICK_MODE==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>1) hr = E_FAIL;
          else set.extend.no_pick = TheComponent;
        }
        else if (VIS_PRIORITY==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>15) hr = E_FAIL;
          else set.extend.priority = TheComponent;
        }
        else if (VIS_SHOW_MODE==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>1) hr = E_FAIL;
          else set.extend.no_show = TheComponent;
        }
        else if (VIS_TRANSPARENCY_MODE==iAttributeID)
        {
          if (TheComponent<0 || TheComponent>1) hr = E_FAIL;
          else set.extend.transparent = TheComponent;
        }
      }
      break;

      case VIS_RED_COLOR_COMPONENT:
      case VIS_GREEN_COLOR_COMPONENT:
      case VIS_BLUE_COLOR_COMPONENT:
      case VIS_ALPHA_COLOR_COMPONENT:
      {
        int TheComponent = 0;

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR:
            TheComponent = ((unsigned char *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT:
            TheComponent = ((unsigned short *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT:
            TheComponent = ((unsigned int *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_SHORT:
            TheComponent = ((short *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_INT:
            TheComponent = ((int *)iValue)[0];
            hr = S_OK;
            break;    
          case VIS_FLOAT:
            TheComponent = (int)(((float *)iValue)[0] * 255.0f);
            hr = S_OK;
            break;    
          case VIS_DOUBLE:
            TheComponent = (int)(((double *)iValue)[0] * 255.0);
            hr = S_OK;
            break;    
        }

        if (TheComponent<0 || TheComponent>255) hr = E_FAIL;
        else
        {
          if      (VIS_RED_COLOR_COMPONENT==iAttributeID)    rvba.extend.red   = TheComponent;
          else if (VIS_GREEN_COLOR_COMPONENT==iAttributeID)  rvba.extend.green = TheComponent;
          else if (VIS_BLUE_COLOR_COMPONENT==iAttributeID)   rvba.extend.blue  = TheComponent;
          else if (VIS_ALPHA_COLOR_COMPONENT==iAttributeID)  rvba.extend.alpha = TheComponent;
        }
      }
      break;

    case VIS_RGBA_COLOR:
      {
        int TheComponent[4] = {0, 0, 0, 0};

        switch (iType)
        {
          case VIS_UNSIGNED_CHAR_4:
            TheComponent[0] = ((unsigned char *)iValue)[0];
            TheComponent[1] = ((unsigned char *)iValue)[1];
            TheComponent[2] = ((unsigned char *)iValue)[2];
            TheComponent[3] = ((unsigned char *)iValue)[3];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_SHORT_4:
            TheComponent[0] = ((unsigned short *)iValue)[0];
            TheComponent[1] = ((unsigned short *)iValue)[1];
            TheComponent[2] = ((unsigned short *)iValue)[2];
            TheComponent[3] = ((unsigned short *)iValue)[3];
            hr = S_OK;
            break;    
          case VIS_UNSIGNED_INT_4:
            TheComponent[0] = ((unsigned int *)iValue)[0];
            TheComponent[1] = ((unsigned int *)iValue)[1];
            TheComponent[2] = ((unsigned int *)iValue)[2];
            TheComponent[3] = ((unsigned int *)iValue)[3];
            hr = S_OK;
            break;    
          case VIS_SHORT_4:
            TheComponent[0] = ((short *)iValue)[0];
            TheComponent[1] = ((short *)iValue)[1];
            TheComponent[2] = ((short *)iValue)[2];
            TheComponent[3] = ((short *)iValue)[3];
            hr = S_OK;
            break;    
          case VIS_INT_4:
            TheComponent[0] = ((int *)iValue)[0];
            TheComponent[1] = ((int *)iValue)[1];
            TheComponent[2] = ((int *)iValue)[2];
            TheComponent[3] = ((int *)iValue)[3];
            hr = S_OK;
            break;    
          case VIS_FLOAT_4:
            TheComponent[0] = (int)(((float *)iValue)[0] * 255.0f);
            TheComponent[1] = (int)(((float *)iValue)[1] * 255.0f);
            TheComponent[2] = (int)(((float *)iValue)[2] * 255.0f);
            TheComponent[3] = (int)(((float *)iValue)[3] * 255.0f);
            hr = S_OK;
            break;    
          case VIS_DOUBLE_4:
            TheComponent[0] = (int)(((double *)iValue)[0] * 255.0);
            TheComponent[1] = (int)(((double *)iValue)[1] * 255.0);
            TheComponent[2] = (int)(((double *)iValue)[2] * 255.0);
            TheComponent[3] = (int)(((double *)iValue)[3] * 255.0);
            hr = S_OK;
            break;    
        }

        if (TheComponent[0]<0 || TheComponent[0]>255 ||
            TheComponent[1]<0 || TheComponent[1]>255 ||
            TheComponent[2]<0 || TheComponent[2]>255 ||
            TheComponent[3]<0 || TheComponent[3]>255)
        {
            hr = E_FAIL;
        }
        else
        {
            rvba.extend.red   = TheComponent[0];
            rvba.extend.green = TheComponent[1];
            rvba.extend.blue  = TheComponent[2];
            rvba.extend.alpha = TheComponent[3];
        }
      }
      break;
  }

  return hr;
}

// Set Attributes
inline void CATGraphicAttributeSet::SetColor ( const unsigned int color )
{
 if ( color > 255 ) set.extend.color = FOREGROUND;
 else               set.extend.color = color;
}

inline void CATGraphicAttributeSet::SetColorRGBA ( const unsigned int color )
{
 rvba.basic = color;
}

inline void CATGraphicAttributeSet::SetColorRGBA ( const int red, const int green, const int blue, const int alpha )
{
 if ( red   < 256 ) rvba.extend.red   = red;
 else rvba.extend.red   = 0;
 if ( green < 256 ) rvba.extend.green = green;
 else rvba.extend.green = 0;
 if ( blue  < 256 ) rvba.extend.blue  = blue;
 else rvba.extend.blue  = 0;
 if ( alpha < 256 ) rvba.extend.alpha = alpha;
 else rvba.extend.alpha = 255;
}

inline void CATGraphicAttributeSet::GetColorRGBA(int* oRed, int* oGreen, int* oBlue, int* oAlpha) const
{
  if (oRed)
    *oRed   = rvba.extend.red;
  if (oGreen)
    *oGreen = rvba.extend.green;
  if (oBlue)
    *oBlue  = rvba.extend.blue;
  if (oAlpha)
    *oAlpha = rvba.extend.alpha;
}

inline void CATGraphicAttributeSet::SetThickness ( const unsigned int thickness )
{

 if ( thickness > 55 ) set.extend.thickness = 1;
 else                  set.extend.thickness = thickness;
}

inline void CATGraphicAttributeSet::SetFixedThickness ( const unsigned int thickness )
{

 if ( thickness > 8 ) set.extend.thickness = 55;
 else                 set.extend.thickness = thickness+55;
}

inline void CATGraphicAttributeSet::SetLineType ( const unsigned int linetype )
{
 if ( linetype > 63 ) set.extend.linetype = 1;
 else                 set.extend.linetype = linetype;
}

inline void CATGraphicAttributeSet::SetAdvancedLineType(const unsigned int iAdvancedLineType)
{
  // advanced type = thickness * 64 + type
  if (iAdvancedLineType > 4095)
  {
    set.extend.thickness = 0;
    set.extend.linetype = 1;
  }
  else
  {
    set.extend.thickness = iAdvancedLineType >> 6;
    set.extend.linetype = iAdvancedLineType & 63;
  }
}

inline void CATGraphicAttributeSet::SetType ( const unsigned int type )
{
 if ( type > 3 ) set.extend.type = 0;
 else            set.extend.type = type;
}

inline void CATGraphicAttributeSet::SetTransparentMode ( const unsigned int transparent )
{
 set.extend.transparent = transparent;
 if (transparent == 1 && rvba.extend.alpha >= 255) rvba.extend.alpha = 179;
}

inline void CATGraphicAttributeSet::SetShowMode ( const unsigned int no_show )
{
 set.extend.no_show = no_show;
}

inline void CATGraphicAttributeSet::SetLowlightMode ( const unsigned int lowlight )
{
 set.extend.lowlight = lowlight;
}

inline void CATGraphicAttributeSet::SetHighlightMode( const unsigned int highlight )
{
 set.extend.highlight = highlight;
}

inline void CATGraphicAttributeSet::SetPickMode( const unsigned int no_pick )
{
 set.extend.no_pick = no_pick;
}

inline void CATGraphicAttributeSet::SetShowFreeMode( const unsigned int show_free )
{
  set.extend.showfree = show_free;
}

inline void CATGraphicAttributeSet::IncreasePriority ( const unsigned int priority )
{
 if ((set.extend.priority + priority) > 15) set.extend.priority = 15;
 else set.extend.priority += priority;
}

inline void CATGraphicAttributeSet::DecreasePriority ( const unsigned int priority )
{
 if ((set.extend.priority - priority) < 0) set.extend.priority = 0;
 else set.extend.priority -= priority;
}

inline void CATGraphicAttributeSet::SetPriority ( const unsigned int priority )
{
 if (priority > 15) set.extend.priority = 15;
 else set.extend.priority = priority;
}

// Operators
inline CATGraphicAttributeSet& CATGraphicAttributeSet::operator=(const CATGraphicAttributeSet &attribut)
{
 set.basic  = attribut.set.basic;
 rvba.basic = attribut.rvba.basic;

 return ( *this );
}

inline int CATGraphicAttributeSet::operator==(const CATGraphicAttributeSet &attribut) const
{
 return ( set.basic == attribut.set.basic && rvba.basic == attribut.rvba.basic);
}

inline int CATGraphicAttributeSet::operator!=(const CATGraphicAttributeSet &attribut) const
{
 return ( set.basic != attribut.set.basic || rvba.basic != attribut.rvba.basic);
}

#endif
