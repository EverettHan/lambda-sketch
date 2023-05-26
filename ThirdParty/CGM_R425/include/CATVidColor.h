// COPYRIGHT Dassault Systemes 2006
//===================================================================
// CATVidColor.h
// Header definition of CATVidColor
//===================================================================
//
//  Jul 2006  Creation: jov
//===================================================================
#ifndef CATVidColor_H
#define CATVidColor_H

#include <VisuDialog.h>
#include <CATBaseUnknown.h>
#include <CATBoolean.h>
#include <CATListOfCATUnicodeString.h>
#include <CATVidRGB.h>
#include <CATVidRGBA.h>
#include <CATVidPalette.h>
#include <UIVCoreToolsInline.h>
/**
 * @ingroup VIDCore
 * Value class to define colors in VID.
 * CATVidColor can be physical, or logical.
 * Physical colors are defined with RGBA, but logical colors are based on
 * a palette of colors. The physical color resulting from a logical color
 * will be computed on a graphic primitive widget from the palette of its
 * widget tree.
 * It is highly recommended to use logical colors in the widgets, to take
 * benefit of the palette customizations depending on the current theme and
 * the current ambiance of the frame.
 * @see CATVidPalette
 */
class ExportedByVisuDialog CATVidColor
{
public:

  /** Constructor. */
  INLINE CATVidColor()
  {
    _ratioForPaletteMix = 1.0;
    _alpha = 255;
    _role0 = CATVidPalette::WindowBackground;
    _role1 = CATVidPalette::WindowForeground;
  }

  /** Constructor. */
  INLINE CATVidColor(const CATVidRGBA& i_rgba)
    :_rgb(i_rgba.GetR(), i_rgba.GetG(), i_rgba.GetB()),_alpha(i_rgba.GetA())
  {
    _ratioForPaletteMix = 1.0;
    _role0  = CATVidPalette::NoRole;
    _role1 = CATVidPalette::NoRole;
  }
  /**
   * Constructor. 
   * Sets the color as logical, represneting a color of the palette.
   */
  INLINE CATVidColor(CATVidPalette::ColorRole i_colorRole)
  {
    _ratioForPaletteMix = 0.f;
    _alpha = 255;
    _role0 = i_colorRole;
    _role1 = CATVidPalette::NoRole;
    CHECK_TRUE(_role0!=CATVidPalette::NoRole);
  }

  /**
   * Constructor. 
   * Sets the color as logical, representing a color of the palette with an
   * alpha.
   */
  INLINE CATVidColor(CATVidPalette::ColorRole i_colorRole, const unsigned char i_a)
  {
    _ratioForPaletteMix = 0.f;
    _alpha = i_a;
    _role0 = i_colorRole;
    _role1 = CATVidPalette::NoRole;
    CHECK_TRUE(_role0!=CATVidPalette::NoRole);
  }

  /** 
   * Constructor.
   * Sets the color as logical, with a role PaletteMix, in association to a ratio that will be used
   * to compute a color between the WindowBackground and WindowForeground in the palette.
   * @see CATVidColor#Set
   * @param i_role
   */
  CATVidColor (float i_ratioForPaletteMix, unsigned char i_alpha, CATVidPalette::ColorRole i_firstColorRole=CATVidPalette::WindowBackground,  CATVidPalette::ColorRole i_secondColorRole=CATVidPalette::WindowForeground);
  /**
   * Constructor.
   */
  INLINE CATVidColor(const unsigned char i_r, const unsigned char i_g, const unsigned char i_b, const unsigned char i_a)
    :_rgb(i_r, i_g, i_b),_alpha(i_a)
  {
    _ratioForPaletteMix = 1.0;
    _role0  = CATVidPalette::NoRole;
    _role1 = CATVidPalette::NoRole;
  }
  /** Non virtual Destructor. WARNING with inheritance*/
  INLINE ~CATVidColor(){}
  /** Copy constructor. */
  INLINE CATVidColor(const CATVidColor &i_original)
  {
    _ratioForPaletteMix = i_original._ratioForPaletteMix;
    _role0  = i_original._role0;
    _role1 = i_original._role1;
    _alpha = i_original._alpha;
    i_original.GetRGB(_rgb);
  }
  /** = operator.*/
  INLINE CATVidColor& operator=(const CATVidColor& i_original)
  {
    _role0  = i_original._role0;
    _role1 = i_original._role1;
    _ratioForPaletteMix = i_original._ratioForPaletteMix;
    _alpha = i_original._alpha;
    _rgb = i_original._rgb;
    return *this;
  }
  /** == operator.*/
  INLINE unsigned char operator==(const CATVidColor& i_right) const
  {
    if (
      _role0 == i_right._role0 &&
      _role1 == i_right._role1 &&
      _ratioForPaletteMix == i_right._ratioForPaletteMix &&
      _alpha == i_right._alpha &&
      _rgb == i_right._rgb )
      return TRUE;
    else
      return FALSE;
  }
  /** != operator.*/
  INLINE unsigned char operator!=(const CATVidColor& i_right) const
  {
    return !(operator==(i_right));
  }

 /**
   * Constructor. 
   * Sets the color as logical, represneting a color of the palette.
   */
  INLINE unsigned char SetAsColorRole(CATVidPalette::ColorRole i_colorRole, unsigned char i_alpha)
  {
    if (
      _ratioForPaletteMix == 0.0f &&  
      _alpha == i_alpha &&
      _role0==i_colorRole &&
      _role1==CATVidPalette::NoRole
      ) return FALSE;
    _ratioForPaletteMix = 0.0f;
    _alpha = i_alpha;
    _role0 = i_colorRole;
    _role1 = CATVidPalette::NoRole;
    CHECK_TRUE(_role1!=CATVidPalette::NoRole);
    _rgb.Set(0, 0, 0);
    return TRUE;
  }


  /**
   * Sets the color as logical, with a role PaletteMix. It is associated to a ratio that will be used
   * to compute a color between the WindowBackground and WindowForeground in the palette, following this algo : 
   * if (i_ratioForPaletteMix > 0 && i_ratioForPaletteMix <= 1)
   *   result=WindowForeground*i_ratioForPaletteMix+WindowBackground*(1-i_ratioForPaletteMix);
   * else if (i_ratioForPaletteMix < 0 && i_ratioForPaletteMix >= -1)
   *   result=WindowForeground2*i_ratioForPaletteMix+WindowBackground*(1+i_ratioForPaletteMix);
   * Where WindowForeground2 = 1-WindowForeground.
   * @param i_ratioForPaletteMix the ratio used to compute the color.
   * @param i_alpha the transparency to apply to color. Will be mixed with the transparency defined in the palette.
   * @return 0 parameters are the same than the current values, 1 otherwise.
   */
  unsigned char Set(float i_ratioForPaletteMix, unsigned char i_alpha, CATVidPalette::ColorRole i_firstColorRole=CATVidPalette::WindowBackground,  CATVidPalette::ColorRole i_secondColorRole=CATVidPalette::WindowForeground);
  /**
   * Sets the color as physical, with RGBA parameters, from 0 to 255.
   * @param i_r red value from 0 to 255
   * @param i_g green value from 0 to 255
   * @param i_b blue value from 0 to 255
   * @param i_a alpha value from 0 to 255
   * @return 0 parameters are the same than the current values, 1 otherwise.
   */
  INLINE unsigned char Set(const unsigned char i_r, const unsigned char i_g, const unsigned char i_b, const unsigned char i_a)
  {
    if (
      _rgb == CATVidRGB(i_r, i_g, i_b) && 
      _alpha == i_a && 
      _role0==CATVidPalette::NoRole &&
      _role1==CATVidPalette::NoRole
      ) return FALSE;
    // Reset this value to the default one, o ensure == operator is ok.
    _ratioForPaletteMix = 1.0;
    _alpha = i_a;
    _rgb.Set(i_r, i_g, i_b);
    _role0  = CATVidPalette::NoRole;
    _role1 = CATVidPalette::NoRole;
    return TRUE;
  }
  /**
   * @return 1 if ColorRole==PaletteMix.
   */
  INLINE unsigned char GetAutoColorFlag() const
  {
    return (_role0 != CATVidPalette::NoRole || _role1 != CATVidPalette::NoRole);
  }
  /**
   * Sets the red value of the color.
   * @param i_r red value from 0 to 255
   */
  INLINE void SetR(unsigned char i_r)
  {
    _rgb.SetR(i_r);
  }

  /**
   * @return the red value of the color.
   */
  INLINE unsigned char GetR() const
  {
    return _rgb.GetR();
  }
  /**
   * Sets the green value of the color.
   * @param i_g green value from 0 to 255
   */
  INLINE void SetG(unsigned char i_g)
  {
    _rgb.SetG(i_g);
  }
  /**
   * @return the green value of the color.
   */
  INLINE unsigned char GetG() const
  {
    return _rgb.GetG();
  }
  /**
   * Sets the blue value of the color.
   * @param i_b blue value from 0 to 255
   */
  INLINE void SetB(unsigned char i_b)
  {
    _rgb.SetB(i_b);
  }
  /**
   * @return the blue value of the color.
   */
  INLINE unsigned char GetB() const
  {
    return _rgb.GetB();
  }
  /**
   * Sets the alpha of the color.
   * @param i_alpha unsigned char from 0 (transparent) to 255 (opaque).
   */
  INLINE void SetAlpha(unsigned char i_alpha)
  {
    _alpha = i_alpha;
  }
  /**
   * @return the alpha from 0 (transparent) to 255 (opaque).
   */
  INLINE unsigned char GetAlpha() const
  {
    return _alpha;
  }

  INLINE void SetFirstColorRole(CATVidPalette::ColorRole i_colorRole)
  {
    _role0=i_colorRole;
  }
  INLINE CATVidPalette::ColorRole GetFirstColorRole() const
  {
    return _role0;
  }
  void SetSecondColorRole(CATVidPalette::ColorRole i_colorRole);
  INLINE CATVidPalette::ColorRole GetSecondColorRole() const
  {
    return _role1;
  }

  /**
   * Recovers the parameters of a logical color with a role PaletteMix.
   * @param o_ratioForPaletteMix the ratio to give, from -1 to 1.
   * @param o_transparencyForAutoColor the transparency to give, from 0 t0 255.
   * @return 0 if the color is physical, 1 otherwise.
   */
  INLINE int GetColor(float &o_ratioForPaletteMix, unsigned char& o_transparencyForAutoColor) const
  {
    if (!GetAutoColorFlag()) return 0;
    o_ratioForPaletteMix = _ratioForPaletteMix;
    o_transparencyForAutoColor = _alpha;
    return 1;
  }
  INLINE int GetColor(float &o_ratioForPaletteMix, unsigned char& o_transparencyForAutoColor, CATVidPalette::ColorRole& o_firstColorRole,CATVidPalette::ColorRole& o_secondColorRole) const
  {
    if (!GetAutoColorFlag()) return 0;
    o_ratioForPaletteMix = _ratioForPaletteMix;
    o_transparencyForAutoColor = _alpha;
    o_firstColorRole=_role0;
    o_secondColorRole=_role1;

    return 1;
  }
  /**
   * Recovers the parameters of a physiical color.
   * @param o_r the red value to give, from 0 to 255.
   * @param o_g the green value to give, from 0 to 255.
   * @param o_b the blue value to give, from 0 to 255.
   * @param o_a the alpha value to give, from 0 to 255.
   * @return 0 if the color is logical, 1 otherwise.
   */
  INLINE int GetColorRGBA(unsigned char& o_r, unsigned char& o_g, unsigned char& o_b, unsigned char& o_a) const
  {
    if (GetAutoColorFlag()) return 0;
    _rgb.Get(o_r, o_g, o_b);
    o_a =_alpha;
    return 1;
  }
  /**
   * Gets the rgb values, if the color is physical.
   * @return 0 if the color is logical, 1 otherwise.
   */
  INLINE int GetRGB(CATVidRGB& o_rgb)const
  {
    if (GetAutoColorFlag()) return 0;
    o_rgb = _rgb;
    return 1;
  }

  INLINE void SetRGBA(const CATVidRGBA& i_rgba)
  {
    _rgb.Set(i_rgba.GetR(), i_rgba.GetG(), i_rgba.GetB());
    _alpha=i_rgba.GetA();
  }
  INLINE CATVidRGBA GetRGBA() const
  {
    return CATVidRGBA(_rgb.GetR(), _rgb.GetG(), _rgb.GetB(), _alpha);
  }

  /**
   * @name Deprecated members
   */
  /*@{*/ 
  /**
   * @deprecated use #SetAlpha.
   */
  INLINE void SetTransparency(unsigned char i_alpha)
  {
    SetAlpha(i_alpha);
  }
/**
   * @deprecated use #GetAlpha
   */
  INLINE unsigned char GetTransparency() const
  {
    return GetAlpha();
  }

  /*@}*/ 

private:

  CATVidRGB     _rgb;
  unsigned char _alpha;
  float         _ratioForPaletteMix;
  CATVidPalette::ColorRole _role0;
  CATVidPalette::ColorRole _role1;
};

//-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>
extern "C" ExportedByVisuDialog 
CATSYPFactoryResult CATSYPCATVidColorFactory(const CATUnicodeString& i_string);
extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidColorSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif
