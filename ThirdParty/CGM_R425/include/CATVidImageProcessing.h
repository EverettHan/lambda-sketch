// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATVidImageProcessing.h
// Header definition of CATVidImageProcessing
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  nov 2009  Creation: jov
//===================================================================
#ifndef CATVidImageProcessing_H
#define CATVidImageProcessing_H

#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATVidColor.h>
#include <CATSYPDeclareEnumFactory.h>
class CATPixelImage;

//-----------------------------------------------------------------------

/*
*
* Class CATVidImageProcessing
* Service class for images blending
*/
class  ExportedByVisuDialog CATVidImageProcessing
{
public:
    enum BlendingMode {
        NoBlending=0,
        Normal,
        Multiply,
        LinearDodge,
        Screen,
        LinearBurn,
        ColorDodge,
        ColorBurn,
        Soustraction,
        Difference,
        Exclusion,
        Lighten,
        Darken,
        Overlay,
        HardLight,
        LinearLight,
        VividLight,
        PinLight,
        Luminosity,
        Saturation,
        Hue,
        Color
    };

    /**
    * Blends an image with a color mask.
    * <br> Works only for RGB and RGBA CATPixelImages
    * @param i_BlendingMode
    *   The Blending mode used to blend the two images.
    * @param i_pImage
    *   The input image or background image.
    * @param i_maskColor
    *   The color mask used for blending.
    * @return
    * <dl>
    *  <dt>A <tt>CATPixelImage</tt> pointer</dt>
    *  <dd>The resulting image is not <tt>ReadOnly</tt>.</dd>
    * </dl>
    */
    static CATPixelImage* BlendWithColor(CATVidImageProcessing::BlendingMode i_BlendingMode, CATPixelImage* i_pImage,const CATVidColor &i_maskColor);
    
    /**
    * Blends an image with a image mask.
    * <br>The result image will have the size of the input image.
    * <br> Works only for RGB and RGBA CATPixelImages
    * @param i_BlendingMode
    *   The Blending mode used to blend the two images.
    * @param i_pImage
    *   The input image or background image.
    * @param i_pMaskImage
    *   The mask image used for blending.
    * @return
    * <dl>
    *  <dt>A <tt>CATPixelImage</tt> pointer</dt>
    *  <dd>The resulting image is not <tt>ReadOnly</tt>.</dd>
    * </dl>
    */
    static CATPixelImage* BlendWithImage(CATVidImageProcessing::BlendingMode i_BlendingMode, CATPixelImage* i_pImage,CATPixelImage* i_pMaskImage);

    /**
    * Mask an image according to the image mask luminosity.
    * <br>The result image will have the size of the input image.
    * <br> Works only for RGBA CATPixelImages
    * @param i_BlendingMode
    *   The Blending mode used to blend the two images.
    * @param i_pImage
    *   The input image or background image.
    * @param i_pMaskImage
    *   The mask image used for alpha blending.
    * @return
    * <dl>
    *  <dt>A <tt>CATPixelImage</tt> pointer</dt>
    *  <dd>The resulting image is not <tt>ReadOnly</tt>.</dd>
    * </dl>
    */
    static CATPixelImage* ApplyMask(CATPixelImage* i_pImage,CATPixelImage* i_pMaskImage);
};

CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidImageProcessing__BlendingMode);

//-----------------------------------------------------------------------

#endif
