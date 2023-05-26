#ifndef CATAfrColor_H
#define CATAfrColor_H

// COPYRIGHT Microsoft 2011/07/08

#include "UIModelInterfaces.h"
#include "CATBoolean.h"

/**
* Value class to define colors.
*/

class ExportedByUIModelInterfaces CATAfrColor
{
  public:
    /** 
    * Constructor.
    */
    CATAfrColor();
    CATAfrColor ( float i_ratioForPaletteMix, unsigned char i_alpha );
    CATAfrColor (const unsigned char i_r, const unsigned char i_g, const unsigned char i_b, const unsigned char i_a);
    CATAfrColor (const CATAfrColor &i_original);
    CATAfrColor& operator=(const CATAfrColor& i_original);

    ~CATAfrColor();

    /** = operator.*/

    /** == operator.*/
    unsigned char operator==(const CATAfrColor& i_right) const;
    unsigned char operator!=(const CATAfrColor& i_right) const;

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
    unsigned char Set(float i_ratioForPaletteMix, unsigned char i_alpha);

    /**
    * Sets the color as physical, with RGBA parameters, from 0 to 255.
    * @param i_r red component from 0 to 255
    * @param i_g green component from 0 to 255
    * @param i_b blue component from 0 to 255
    * @param i_a alpha component from 0 to 255
    * @return 0 parameters are the same than the current values, 1 otherwise.
    */
    unsigned char Set(const unsigned char i_r, const unsigned char i_g, const unsigned char i_b, const unsigned char i_a);

    /**
    * @return 1 if ColorRole==PaletteMix.
    */
    unsigned char GetAutoColorFlag() const;

    /**
    * Sets the alpha of the color.
    * @param i_alpha unsigned char from 0 (transparent) to 255 (opaque).
    */
    void SetAlpha(unsigned char i_alpha);

    /**
    * @return the alpha from 0 (transparent) to 255 (opaque).
    */

    unsigned char GetAlpha() const;
    /**
    * Recovers the parameters of a logical color with a role PaletteMix.
    * @param o_ratioForPaletteMix the ratio to give, from -1 to 1.
    * @param o_transparencyForAutoColor the transparency to give, from 0 t0 255.
    * @return 0 if the color is physical, 1 otherwise.
    */

    int GetColor(float &o_ratioForPaletteMix, unsigned char& o_transparencyForAutoColor) const;

    /**
    * Recovers the parameters of a physiical color.
    * @param o_r the red component to give, from 0 to 255.
    * @param o_g the green component to give, from 0 to 255.
    * @param o_b the blue component to give, from 0 to 255.
    * @param o_a the alpha component to give, from 0 to 255.
    * @return 0 if the color is logical, 1 otherwise.
    */
    int GetColorRGBA(unsigned char& o_r, unsigned char& o_g, unsigned char& o_b, unsigned char& o_a) const;

    //_red, _green, _blue, _transparency and _texture are the color attributes and there values varies from 0 to 255.
    int isNull( );

  private:
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
    unsigned char _alpha;
    float         _ratioForPaletteMix;
    CATBoolean    _autoColorFlag;
    CATBoolean    _bNULL;
};

//-----------------------------------------------------------------------
#include "CATSYPDeclareBoxing.h"
CATSYP_DECLARE_BOXING( ExportedByUIModelInterfaces, CATAfrColor );

#include <CATSYPFactoryResult.h>
extern "C" ExportedByUIModelInterfaces 
  CATSYPFactoryResult CATSYPCATAfrColorFactory(const CATUnicodeString& i_string);
extern "C" ExportedByUIModelInterfaces 
  HRESULT CATSYPCATAfrColorSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif 
