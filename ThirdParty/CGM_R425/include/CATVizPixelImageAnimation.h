#ifndef CATVIZPIXELIMAGEANIMATION_H
#define CATVIZPIXELIMAGEANIMATION_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
//-----------------------------------------------------------------------------
// Class  :  	CATVizPixelImageAnimation
// Date   :  	15/01/07
//-----------------------------------------------------------------------------
//  Inheritance : CATVizPixelImageAnimation
//						CATBaseUnknown
//-----------------------------------------------------------------------------
// Abstract : This class specifies an animation with pixel images.
//-----------------------------------------------------------------------------
//  Main Methods :
//
//-----------------------------------------------------------------------------

// Local Framework
#include "CATBaseUnknown.h"
#include "CATMMediaPixelImage.h"
// VisualizationBase Framework
#include "CATPixelImage.h"
#include "CATListOfCATPixelImage.h"
#include "CATUnicodeString.h"

#include "CATMMSTDSafeIncludeStart.h"
#include <vector>
#include "CATMMSTDSafeIncludeEnd.h"

class CATVizMNGInterpreter;
class CATVizGIFInterpreter;

class ExportedByCATMMediaPixelImage CATVizPixelImageAnimation : public CATBaseUnknown
{
	CATDeclareClass;

public:

	/** Contructs an empty animation.
	 * @param iWidth
	 * Width of the display.
	 * @param iHeight
	 * Height of the display.
	 */
	CATVizPixelImageAnimation(const int iWidth, const int iHeight);

    /** Create an animation from an Mng file.
	 * @param iMNGFilePath
	 * Path of the MngFile
     * @param iOnTheFlyFrameParsingMode
     * Decide whether all frame should be loaded in memory at creation or if each frame is only created on demand by parsing the file.
     * In case iOnTheFlyFrameParsingMode is TRUE, the CATVizPixelImageAnimation::AddFrame method is deactivated
	 * <b>Legal values</b>
     * <dl>
	 *  FALSE : (default value). All frame are loaded in memory at creation.
     *  TRUE : each frame is only created on demand by parsing the file.
	 * </dl>
	 */
	static CATVizPixelImageAnimation* CreateCATVizPixelImageAnimationFromMNG(CATUnicodeString& iMNGFilePath, CATBoolean iOnTheFlyFrameParsingMode=FALSE);

  /** Create an animation from an Gif file.
   * @param iGIFFilePath
   * Path of the GifFile
   * @param iOnTheFlyFrameParsingMode
   * Decide whether all frame should be loaded in memory at creation or if each frame is only created on demand by parsing the file.
   * In case iOnTheFlyFrameParsingMode is TRUE, the CATVizPixelImageAnimation::AddFrame method is deactivated
   * <b>Legal values</b>
   * <dl>
       FALSE : (default value). All frame are loaded in memory at creation.
   *  TRUE : each frame is only created on demand by parsing the file.
   * </dl>
   */
  static CATVizPixelImageAnimation* CreateCATVizPixelImageAnimationFromGIF(CATUnicodeString& iGIFFilePath, CATBoolean iOnTheFlyFrameParsingMode=FALSE);


    /** Create an animation from an Mng file.
	 * @param buffer
	 *  MngFile loaded in a memory buffer
     * @param bufferSize
	 *  size of the buffer in octects.
     * @param iOnTheFlyFrameParsingMode
     * Decide whether all frame should be loaded in memory at creation or if each frame is only created on demand by parsing the file.
	 * <b>Legal values</b>
     * <dl>
	 *  FALSE : (default value). All frame are loaded in memory at creation.
     *  TRUE : each frame is only created on demand by parsing the file.
	 * </dl>
	 */
	static CATVizPixelImageAnimation* CreateCATVizPixelImageAnimationFromMNG(const unsigned char* buffer,int bufferSize, CATBoolean iOnTheFlyFrameParsingMode=FALSE);

/** Create an animation from an Gif file.
   * @param buffer
   *  GifFile loaded in a memory buffer
   * @param bufferSize
   *  size of the buffer in octects.
   * @param iOnTheFlyFrameParsingMode
   * Decide whether all frame should be loaded in memory at creation or if each frame is only created on demand by parsing the file.
   * <b>Legal values</b>
   * <dl>
   *  FALSE : (default value). All frame are loaded in memory at creation.
   *  TRUE : each frame is only created on demand by parsing the file.
   * </dl>
   */
  static CATVizPixelImageAnimation* CreateCATVizPixelImageAnimationFromGIF(const unsigned char* buffer,int bufferSize, CATBoolean iOnTheFlyFrameParsingMode=FALSE);

	/** Copy constructor */
	CATVizPixelImageAnimation(const CATVizPixelImageAnimation& iAnimation);

	/** Deletes the animation. */
	virtual ~CATVizPixelImageAnimation();

	/**
	 * Retrieves the display size.
	 * @param oXSize
	 *   Display width in pixels.
	 * @param oYSize
	 *   Display height in pixels.
	 */
	virtual void GetSize(int& oXSize, int& oYSize) const { oXSize = _displayPixelWidth, oYSize = _displayPixelHeight; }

	/**
	 * Get the number of frames defining the animation.
	 * @return
	 * <dl>
	 *  <dt>the number of frames in the animation.</dt>
	 * </dl>
	 */
	unsigned int GetFramesCount(void) const;

    /**
     * Get the frame with number iFrameNum in the animation.
	 * @param iFrameNum
	 *   The frame number.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  This number is less or equal to the frame count and superior to 0.
	 * </dl>
     * @return
     * <dl>
	 *  <dt>The frame <tt>CATPixelImage</tt>.</dt>
     * </dl>
     */
	const CATPixelImage* GetFrame(unsigned int iFrameNum) const;

    /**
     * Get the frame with number iFrameNum in the animation.
	 * @param iFrameNum
	 *   The frame number.
	 * <br><b>Legal values</b>
	 * <dl>
	 *  This number is less or equal to the frame count and superior to 0.
	 * </dl>
     * @return
     * <dl>
	 *  <dt>The frame <tt>CATPixelImage</tt>.</dt>
     * </dl>
     */
	CATPixelImage* GetFrame(unsigned int iFrameNum);


	/**
	 * Add a frame to the animation.
     * In case the object was created with method CreateCATVizPixelImageAnimationFromMNG and parameter iOnTheFlyFrameParsingMode
     *   was TRUE, the AddFrame method is deactivated.
	 * @param iFrame
	 * The frame to add.
	 */
	void AddFrame(CATPixelImage* iprFrame);

	/**
	 * Get / Set the frame delay of the animation in ms.
	 */
    void SetFrameDelay(float iFrameDelay);
    void GetFrameDelay(float& oFrameDelay);

  /**
   * Get / Set the frame delay of the animation as per frame number. To be used for GIF format.
   */
    void SetFrameDelay(float iFrameDelay, int frameNumber);
    void GetFrameDelay(float& oFrameDelay, int frameNumber);


	/**
	 * Get / Set the animation iteration maximum.
	 */
    void SetIterationMax(unsigned int iIterationMax);
    void GetIterationMax(unsigned int& oIterationMax);

    /**
	 * Get / Set the delay before repeating the animation.
	 */
    void SetTermDelay(float iTermDelay);
    void GetTermDelay(float& oTermDelay);

private:

	// size of the display
	unsigned int _displayPixelWidth;
	unsigned int _displayPixelHeight;

	// frame rate
  float _frameDelay;
  std::vector<float> _frameDelays;

	// frame list
	CATLISTP(CATPixelImage)* _paFrameList;

    // frame iteration maximum
    unsigned int _iterationMax;

    // term delay
    float _termDelay;

    CATBoolean _onTheFly;
    int     _onTheFlyFrameCount;
    CATVizMNGInterpreter* _pMNGInterpreter;
    CATVizGIFInterpreter* _pGIFInterpreter;
};

#endif
