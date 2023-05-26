//===================================================================
// COPYRIGHT Dassault Systemes 2011
//===================================================================
#ifndef CATVidTextStyle_H
#define CATVidTextStyle_H

#include <CATUnicodeString.h>
#include <CATVidColor.h>
#include <CATVid.h>
#include <VisuDialog.h>
#include <CATBaseUnknown.h>
#include <CATVidMargin.h>

class  ExportedByVisuDialog CATVidTextParagraphStyle
{
  FORCE_STACK_ALLOCATION();

public:
  // constructor & destructor
  CATVidTextParagraphStyle();
  virtual ~CATVidTextParagraphStyle(){};
  // operators
  CATVidTextParagraphStyle& operator=(const CATVidTextParagraphStyle& i_Right);
  int operator == (const CATVidTextParagraphStyle & i_Right) const;
  int operator != (const CATVidTextParagraphStyle & i_Right) const;
  // Get/Set
  CATVid::Alignment GetAlignment() const{return _alignment;}
  void SetAlignment(CATVid::Alignment i_alignment){_alignment=i_alignment;}

  CATVidMargin GetMargin()const{return _margin;}
  void SetMargin(CATVidMargin i_margin){_margin = i_margin;}

private:
  CATVid::Alignment _alignment;
  CATVidMargin  _margin;
};

/**
* @c CATVidTextStyle is used to aggregate various character styles. These styles controle the way characters
* are displayed. They are,
* @li Bold: If set to @c 1, text will be displayed in bold style (if corresponding font is available). 
* @li Italic: If set to @c 1, text will be displayed in italic style (if corresponding font is available). 
* @li Underlined: If set to @c 1, a line will be drawn below text. 
* @li Font Height: Height of text in points. 
* @li Font Name: Font family name (ex. Times New Roman). 
* @li Color: color of text defined by @ref CATVidColor. 
* There is no default values, as by default the values are "unset".
* To check if a property has been set, customer must use the GetDefinedFlag methods associated to it.
* @see CATVidCtlTextEditor
*/
class ExportedByVisuDialog CATVidTextStyle
{
  FORCE_STACK_ALLOCATION();
public:
  /** Constructor*/
  CATVidTextStyle();
  /** Destructor*/
  ~CATVidTextStyle(){};
  /** Copy Constructor*/
  CATVidTextStyle(const CATVidTextStyle& i_toCopy);
  /** operator ==  */
  int operator == (const CATVidTextStyle & i_Right) const;
  /** operator !=  */
  int operator != (const CATVidTextStyle & i_Right) const;
  /** operator =  */
  CATVidTextStyle& operator =(const CATVidTextStyle& i_Right);
  /** Merges the current  style with the one given as a parameter.*/
  void Merge(const CATVidTextStyle& i_style);
  /** Sets the font size */
  INLINE void SetFontSize(int i_fontSize){if (i_fontSize<0)return;_fontSize=i_fontSize;_fontSizeDefinedFlag=1;}
  /** @return the font size */
  INLINE int GetFontSize() const {return _fontSize;}
  /** Sets an hyperling URL and tooltip */
  INLINE void SetHyperlink(const CATUnicodeString& i_strURL, const CATUnicodeString& i_strToolTip){_strURL=i_strURL;_strToolTip=i_strToolTip;_strURLDefinedFlag=1;_strToolTipDefinedFlag=1;}
  /** Sets an hyperling URL */
  INLINE void SetHyperlinkURL(const CATUnicodeString& i_strURL){_strURL=i_strURL;_strURLDefinedFlag=1;}
  /** @return an hyperling URL */
  INLINE const CATUnicodeString& GetHyperlinkURL()const{return _strURL;}
  /** Sets an hyperling tooltip */
  INLINE void SetHyperlinkTooltipText(const CATUnicodeString& i_strToolTip){ _strToolTip=i_strToolTip;_strToolTipDefinedFlag=1;}
  /** @return an hyperling tooltip text*/
  INLINE const CATUnicodeString& GetHyperlinkTooltipText()const{return _strToolTip;}
  /** Sets an hyperling visited flag */
  INLINE void SetHyperlinkVisitedFlag(int i_isVisited){if (i_isVisited<0)return;_isVisited=i_isVisited;_isVisitedDefinedFlag=1;}
  /** @return the hyperling visited flag */
  INLINE int GetHyperlinkVisitedFlag()const{return _isVisited;}
  /** Sets the color.*/
  INLINE void SetColor(const CATVidColor& i_color){_color=i_color;_colorDefinedFlag=1;}
  /** @return the color */
  INLINE const CATVidColor& GetColor()const{return _color;}
  /** Sets the font family name.*/
  INLINE void SetFontName(const CATUnicodeString&i_fontName){_fontName=i_fontName;_fontNameDefinedFlag=1;}
  /** @return the font family name.*/
  INLINE const CATUnicodeString& GetFontName()const{return _fontName;}
  /** Sets the underline flag*/
  INLINE void SetUnderlinedFlag(int i_underlineFlag){if (i_underlineFlag<0)return;_underlineFlag=i_underlineFlag;_underlineFlagDefinedFlag=1;}
  /** @return the underline flag*/
  INLINE int GetUnderlinedFlag()const{return _underlineFlag;}
  /** Sets the italic flag*/
  INLINE void SetItalicFlag(int i_italicFlag){if (i_italicFlag<0)return;_italicFlag=i_italicFlag;_italicFlagDefinedFlag=1;}
  /** @return the italic flag*/
  INLINE int GetItalicFlag()const{return _italicFlag;}
  /** Sets the bold flag*/
  INLINE void SetBoldFlag(int i_boldFlag){if (i_boldFlag<0)return;_boldFlag=i_boldFlag;_boldFlagDefinedFlag=1;}
  /** @return the bold flag*/
  INLINE int GetBoldFlag()const{return _boldFlag;}
  /** @return 1 if one style is overriden in the text style.*/
  INLINE int GetStyleOverriddenFlag()const
  {
    return (
       _boldFlagDefinedFlag        || 
       _italicFlagDefinedFlag      ||                            
       _underlineFlagDefinedFlag   ||                           
       _isVisitedDefinedFlag       ||                           
       _fontSizeDefinedFlag        ||                           
       _colorDefinedFlag           ||                           
       _fontNameDefinedFlag        ||                           
       _strURLDefinedFlag          ||                           
       _strToolTipDefinedFlag);
  }
  INLINE void Reset()
  {       
    _boldFlagDefinedFlag        =0; 
    _italicFlagDefinedFlag      =0;                         
    _underlineFlagDefinedFlag   =0;                          
    _isVisitedDefinedFlag       =0;                         
    _fontSizeDefinedFlag        =0;                         
    _colorDefinedFlag           =0;                         
    _fontNameDefinedFlag        =0;                         
    _strURLDefinedFlag          =0;                         
    _strToolTipDefinedFlag      =0;
  }
  INLINE void ResetHyperlink()
  {       
    _strURL="";     
    _strToolTip="";
    _strURLDefinedFlag          =0;                         
    _strToolTipDefinedFlag      =0;
  }
  INLINE int GetBoldFlagDefinedFlag()const
  {       
    return _boldFlagDefinedFlag;    
  }
  INLINE int GetItalicFlagDefinedFlag()const
  {       
    return _italicFlagDefinedFlag;                            
  }
  INLINE int GetUnderlineFlagDefinedFlag()const
  {       
    return _underlineFlagDefinedFlag;                         
  }
  INLINE int GetIsVisitedDefinedFlag()const
  {       
    return _isVisitedDefinedFlag;
  }
  INLINE int GetFontSizeDefinedFlag()const
  {       
    return _fontSizeDefinedFlag;
  }
  INLINE int GetColorDefinedFlag()const
  {       
    return _colorDefinedFlag;
  }
  INLINE int GetFontNameDefinedFlag()const
  {       
    return _fontNameDefinedFlag;
  }
  INLINE int GetURLDefinedFlag()const
  {       
    return _strURLDefinedFlag;
  }
  INLINE int GetToolTipDefinedFlag()const
  {       
    return _strToolTipDefinedFlag;
  }
  /**@deprecated */
  INLINE void SetColorDefinedFlag(int i){} 
  /**@deprecated */
  INLINE void SetStyleOverriddenFlag(int i){}
private:
  unsigned int _boldFlag                    :1;
  unsigned int _italicFlag                  :1;
  unsigned int _underlineFlag               :1;
  unsigned int _isVisited                   :1;
  unsigned int _boldFlagDefinedFlag         :1;         
  unsigned int _italicFlagDefinedFlag       :1;
  unsigned int _underlineFlagDefinedFlag    :1;
  unsigned int _isVisitedDefinedFlag        :1;
  unsigned int _fontSizeDefinedFlag         :1;
  unsigned int _colorDefinedFlag            :1;
  unsigned int _fontNameDefinedFlag         :1;
  unsigned int _strURLDefinedFlag           :1;
  unsigned int _strToolTipDefinedFlag       :1;
  unsigned int _fontSize                    :19;//and padding
  CATVidColor       _color;
  CATUnicodeString  _fontName;
  CATUnicodeString  _strURL;
  CATUnicodeString  _strToolTip;
public:
  void SetSuperScriptFlag(int i_isSuperScript){}
  int GetSuperScriptFlag()const{return 0;}
  void SetSubScriptFlag(int i_isSubScript){}
  int GetSubScriptFlag()const{return 0;}
  void SetFontHeight(int i_fontSize){SetFontSize(i_fontSize);}
  int GetFontHeight() const {return GetFontSize();}
};

#endif
