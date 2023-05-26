#ifndef CATMMICROPPING_H
#define CATMMICROPPING_H

#include "CATMMediaRasterProcessor_Base.h"

#include "CATPixelImage.h"
#include "CATMMPIPixelColor.h"

class CATMMPIImagePixelIterator;

/**
 * @ingroup groupPixelImageTransfo
 */
class ExportedByCATMMediaRasterProcessor_Base CATMMICropping
{
public:
  /** Retrieves the colors of the corners of a CATPixelImage.
   * @param iPixelImageToAnalyse, the CATPixelImage to analyse its corners colors.
   * @param ioCornersColorIndexes. Index of corners colors in opColorsTable where: [0]:bottom left corner, [1]:bottom right corner, [2]:top right corner, and [3]:top left corner.
   * @param opColorsTable. Colors are ordered from the most used color to the less used color. Returned array of colors has to be deleted.
   * @return the maximum number of corners having the same color.
   */
  static int RetrieveCornersColors(/*const*/CATPixelImage &iPixelImageToAnalyse, int ioCornersColorIndexes[4], CATMMPIPixelColor* &opColorsTable);
  
  /**
   * Retrieves CATPixelImage's trimming color regarding CATPixelImage's corners colors. CATPixelImage's background color is assigned with
   *   	@li CASE 1: the color of the 4 corners when they are equal,
   *    @li CASE 2: when 3 corners have the same color, their color is used as trim color,
	 *    @li CASE 3: when 2 corners of the same side (:top,bottom, left or right side) and colors of corners on opposite side have different, the common color the two corners on same side is used as trim color.
   *    .
   */
  static CATBoolean EvalTrimmingColorOnCornersStrategy(/*const*/CATPixelImage &iPixelImageToAnalyse, CATMMPIPixelColor &oTrimColor);

  /**
   * Retrieves CATPixelImage area which can be extract by removing perimeter background color.
   * @param iPixelImageToAnalyse pointer to CATPixelImage in which we want to extract
   * @param iPixelColor: the color to use to retrieve sides of image to be removed.
   * @param oNewXMin: if none 0, left side of image has to be removed. Its value represents the position in pixels of the begining of the new image in horizontal direction.
   * @param oNewYMin: if different with image width, bottom side of image has to be removed. Its value represents the position in pixels of the begining of the new image in vertical direction.
   * @param oNewXMax: if none 0, right side of image has to be removed. Its value represents the position in pixels of the end of the new image in horizontal direction.
   * @param oNewYMax: if different with image height, top side of image has to be removed. Its value represents the position in pixels of the begining of the new image in vertical direction.
   * @return TRUE if CATPixelImage has perimeter background color that can be removed. FALSE otherwise.
   */
  static CATBoolean ComputeCroppingAreaFromTrimmingColor(/*const*/CATPixelImage &iPixelImageToAnalyse, const CATMMPIPixelColor &iPixelColor, int &oNewXMin, int &oNewYMin, int &oNewXMax, int &oNewYMax);

  CATMMICropping(CATPixelImage &iPixelImageToAnalyse);
  virtual ~CATMMICropping();
  int         RetrieveCornersColors(int ioCornersColorIndexes[4], CATMMPIPixelColor* &opColorsTable);
  CATBoolean  EvalTrimmingColorOnCornersStrategy(CATMMPIPixelColor &oTrimColor);
  CATBoolean  ComputeCroppingAreaFromTrimmingColor(const CATMMPIPixelColor &iPixelColor, int &oNewXMin, int &oNewYMin, int &oNewXMax, int &oNewYMax);
private:
  CATMMICropping();
  CATMMICropping(const CATMMICropping&);
  CATMMICropping& operator=(const CATMMICropping&);
  /**
   * @nodoc
   */
  CATBoolean  IsValid();
  /**
   * @nodoc
   */
  CATBoolean HasPixelImageRowSameColorThan_Forward(const CATMMPIPixelColor &iPixelColor);
  /**
   * @nodoc
   */
  CATBoolean HasPixelImageRowSameColorThan_Backward(const CATMMPIPixelColor &iPixelColor);
  /**
   * @nodoc
   */
  CATBoolean HasPixelImageColumnSameColorThan_Forward(const CATMMPIPixelColor &iPixelColor);
  /**
   * @nodoc
   */
  CATBoolean HasPixelImageColumnSameColorThan_Backward(const CATMMPIPixelColor &iPixelColor);

  const CATPixelImage&  _image;
  int                   _width;
  int                   _height;
  int                   _bpp;
  const unsigned char*  _data;
  int                   _isValid;
  CATMMPIPixelColor     _pixelColorBuffer;//used for performance.
  CATMMPIImagePixelIterator *_piterator;
};

#endif

