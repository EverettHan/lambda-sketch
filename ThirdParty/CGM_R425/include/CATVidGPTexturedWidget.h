//===================================================================
// COPYRIGHT Dassault Systemes 2012
//===================================================================
#ifndef CATVidGPTexturedWidget_H
#define CATVidGPTexturedWidget_H

#include <VisuDialog.h>
#include <CATVidGP.h>
#include <CATUnicodeString.h>
#include <list.h>
#include <CATVidColor.h>
#include <CATGraphicMaterial.h>
#include <CATVidImageBlender.h>
#include <CATGraphicMaterial.h>
#include <CATVid.h>
#include <CATVidRGBA.h>
#include <CATVidVectorImageRenderParams.h>
#include <CATVidBorder.h>

class CATSYPIntAnimation;
class CATSYPBeginStoryboard;
class CATVidGPTexture;
class CATVidImageBlender;
class CATPixelImage;
class CATVidVisitor_BufferedDraw;
class CATVidOneGPRep;
class CATMathPointf;
class CATGraphicAttributeSet;
class CATMathVectorf;
class CATVidGPTextureObject;
//-----------------------------------------------------------------------

/**
 * @ingroup VIDGP
 * Base class for textured widgets.
 */
class ExportedByVisuDialog CATVidGPTexturedWidget: public CATVidGP
{
  CATDeclareClass;
public:
  friend class CATVidVisitor_SKIA;
  /** 
   * Sets the margins used around the layout.
   * By default, these margins are null.
   */
  void SetContentsMargins(const CATVidBorder& i_contentsMargins);

  /**
   * @return the margins used around the layout.
   */
  const CATVidBorder& GetContentsMargins() const;

  /**
  * The color of the square
  */
  void SetColor(const CATVidColor& i_color);
  /**
  * @see SetColor
  */
  CATVidColor GetColor() const;
  /**
  * The name of the texturefor the square.
  * At draw, the texture manager will try to find it.
  * If it its extension is .mng, it sets the mngTextureFlag to TRUE.
  * @param i_texture
  * @see CATVidGPTextureManager
  */
  void SetTexture( const CATUnicodeString &i_texture);
  /**
  * Retrieve the name of the texture, if setted by SetTexture(CATUnicodeString&).
  */
  const CATUnicodeString &GetTexture() const;
  /**
  * @see SetPixelImage
  */
  void SetTexture(CATPixelImage* i_pImage);
  /**
  * @param i_pImage the image to set as a texture.
  */
  void SetPixelImage(CATPixelImage* i_pImage);
  /**
  * Forces an update on the texture.
  * Suitable when the pixel image pointer is the same and only the pixel buffer has changed.
  * @param i_fullRefresh 
  *        LEGAL values: 
           TRUE: recover a new gp Texture object
           FALSE: test if the pixel image and the gp texture have different dimensions. If this the case,  recover a new gp texture object
                  but if not, copy only the new pixel buffer inside the existing gp texture.
  * By default, the @c i_fullRefresh is @c TRUE.
  */
  void RefreshTexture(CATBoolean i_fullRefresh=TRUE);
  /**
  * @see SetPixelImage
  */
  CATPixelImage* GetPixelImage() const;
  /**
  * @nodoc
  */
  void SetImageBlender(const CATVidImageBlender& i_ImageBlender);
  /**
  * @nodoc
  */
  const CATVidImageBlender& GetImageBlender() const;
  /**
  * Allows to replace any color of the texture with another color.
  * This is independent of the transparency of such pixels.
  * @param i_fromR deprecated.
  * @param i_fromG deprecated.
  * @param i_fromB deprecated.
  * @param deprecated.
  */
  void ColorizeTexture(const CATVidColor& i_color, unsigned char i_fromR, unsigned char i_fromG, unsigned char i_fromB);
  /**
  * Reset the list of colorized colors of a texture
  */
  void ResetColorize();
  /**
  * The color by which you want to replace all black pixels in the texture.
  * This is independent of the transparency of the black pixels.
  * @see ColorizeTexture
  */
  void SetColorizeBlackPixelTo(const CATVidColor& i_color);
  /**
  * @see SetColorizeBlackPixelTo
  */
  const CATVidColor& GetColorizeBlackPixelTo() const;
  /**
   * The color diplayed when the GP is disabled
   */
  void SetDisableColor(const CATVidColor& i_color);
  /**
   * @see SetDisableColor
   */
  const CATVidColor& GetDisableColor() const;
  /**
  * Texture transparency.
  * @param i_textureAlpha an integer between 0 (transparent) and 255(opaque).
  */
  void SetTextureAlpha(unsigned char  i_textureAlpha);
  /**
  * @see SetTextureAlpha
  */
  unsigned char GetTextureAlpha() const;
  /**
  * Texture filter.
  * Default : FALSE.
  * @param i_textureFilterFlag
  *        Legal values :
  *        TRUE : texture/material creation use an anverage of nearest texels.
  *        FALSE : use the nearest texel.
  * @see CATTextureFilter
  */
  void SetTextureFilter(CATBoolean i_textureFilterFlag);
  CATBoolean GetTextureFilter() const;
  /**
   * Sets the filtering method used for minification.
   * Currently may not deliver requested filtering due to a bug in CATRender.
   * @param i_mininificationFilter The filter value to apply.
   */
  void SetMinificationFilter(enum CATVid::TextureFilter i_mininificationFilter);
  /**
   * Gets the filtering method used for minification.
   */
  enum CATVid::TextureFilter GetMinificationFilter() const; 
  /**
  * Start or stop the texture animation, if there is one.
  * <b>Prerequisites :</b> the texture has been set and is a <b>mng file</b>, with .mng extension.
  * mng is a public graphics file format for animated images, closely related to PNG.
  * Duration, number of loops and number of frames are retrieved from the mng texture settings.
  * @param i_animationOnFlag
  *        Legal values :
  *        TRUE : starts the animation.
  *        FALSE : resets the texture and stops the animation.
  */
  void SetAnimationOnFlag(CATBoolean i_animationOnFlag);
  /**
  * @see SetAnimationOnFlag
  */
  CATBoolean GetAnimationOnFlag() const;
  /**
  * @nodoc
  * Default : FALSE
  */
  void SetUseColorizeFlag(CATBoolean i_useColorizeFlag);
  /**
  * @nodoc
  */
  CATBoolean GetUseColorizeFlag() const;
  CATBoolean GetUseColorizeState() const;
  /**
  * The current frame of the pixel animation.
  * Prerequisite : The texture is a mng file.
  * If i_index is greater than the number of frames of the animation,
  * it is set to the index of the last frame.
  * @param i_index the new current index
  */
  void SetPixelAnimationFrame(unsigned int i_index);
  /**
  * @see SetPixelAnimationFrame
  */
  unsigned int GetPixelAnimationFrame() const;
  /**
   * Sets the current progression of the pixel animation (gif or mng).
   */
  void SetPixelAnimationProgression(float i_progression);
  /**
   * @return the current progression of the pixel animation (gif or mng).
   */
  float GetPixelAnimationProgression() const;
  /**
  * Return the number of frames of the texture animation, if there is one.
  * Prerequisite : The texture is a mng file.
  * @return the number of frames (int > 0), or 0 if the texture is not animated.
  */
  unsigned int GetPixelAnimationNbFrames() const;

  /**
   * By default, the @c LowerBoundDimensionWithTextureFlag is @c FALSE.
   *
   * @param ibLowerBoundDimensionWithTexture @c TRUE if the minimum dimension 
   * must be lower-bounded by the resolution of the texture, @c FALSE else.
   */
  void SetLowerBoundDimensionWithTextureFlag(CATBoolean ibLowerBoundDimensionWithTexture);
  /**
   * @return the @c LowerBoundDimensionWithTextureFlag.
   *
   * @see #SetLowerBoundDimensionWithTexture
   */
  CATBoolean GetLowerBoundDimensionWithTextureFlag() const;
   /**
   * By default, the @c UpdateTextureOnResize is @c FALSE.
   *
   * @param iUpdateTextureOnResize @c TRUE if the texture is a vector image
   * that needs to be refreshed during resize, @c FALSE else.
   */
  void SetUpdateTextureOnResize(CATBoolean iUpdateTextureOnResize);
  /**
   * @return the @c UpdateTextureOnResize.
   *
   * @see #SetUpdateTextureOnResize
   */
  CATBoolean GetUpdateTextureOnResize() const;
   /**
   * Parameters needed to compute vector image.
   *
   * @param iVectorImageRenderParams the parameters used to compute the vector image
   */
  void SetVectorImageRenderParams(const CATVidVectorImageRenderParams& iParams);
  /**
   * @return the @c VectorImageRenderParams.
   *
   * @see #SetVectorImageRenderParams
   */
  const CATVidVectorImageRenderParams& GetVectorImageRenderParams() const;

  void SetColorizeWithAlphaFlag(int i_flag);
  int GetColorizeWithAlphaFlag() const;

  /**
  * Retrieve the dimension of the texture, if setted by SetTexture(CATUnicodeString&). In physical pixels (px).
  */
  void GetImageDimension(int& o_width, int& o_height);
  /**
   * @copydoc CATVidWidget#TunnelInformation
   */
  virtual void TunnelInformation(const CATVidInformation& i_information);
protected:
  /** Constructor */
  CATVidGPTexturedWidget (CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag, CreateLetterFunc i_pCreateLetterFunc);
  /** Constructor */
  CATVidGPTexturedWidget (CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag);
  /** Destructor */
  virtual ~CATVidGPTexturedWidget ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGPTexturedWidget (CATVidGPTexturedWidget &);
  CATVidGPTexturedWidget& operator=(CATVidGPTexturedWidget&);
};

//-----------------------------------------------------------------------

#endif
 
