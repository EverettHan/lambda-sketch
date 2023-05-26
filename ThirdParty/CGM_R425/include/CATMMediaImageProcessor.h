//----------------------------------------------------------------------------
//	CATMMediaImageProcessor.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageProcessor_H
#define CATMMediaImageProcessor_H

#include "CATMMediaRasterProcessor_Base.h"
#include "CATErrorDef.h"
#include "CATMMediaImageDef.h"
#include "CATMMIColorRamp.h"
#include "CATBoolean.h"

class CATPixelImage;
class CATMMediaImageFilter;

#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define MIN(a,b)	((a) < (b) ? (a) : (b))

/** @nodoc */
enum ExportedByCATMMediaRasterProcessor_Base CATMMIGreyType
{ 
	MMI_GREY_Default,
	// --- from color ---
	MMI_GREY_Green,			//	L = g
	MMI_GREY_Mean,			//	L = (r+g+b)/3
	MMI_GREY_Desaturate,	//	L = (min(r,g,b) + max(r,g,b))/2
	MMI_GREY_CCIR_601,		//	L = 0.2989*r + 0.5866*g	+ 0.1145*b
	MMI_GREY_CCIR_709,		//	L = 0.2125*r + 0.7154*g	+ 0.0721*b
	MMI_GREY_ITU,			//	L = 0.222*r	+ 0.707*g + 0.071*b
	// --- from bilevel ---
	MMI_GREY_Antialiased
};

/** @nodoc */
enum ExportedByCATMMediaRasterProcessor_Base CATMMIMirrorType
{ 
	MMI_MIR_None,
	MMI_MIR_Horizontal,
	MMI_MIR_Vertical,
	MMI_MIR_Both
};


/** @nodoc */
enum ExportedByCATMMediaRasterProcessor_Base CATMMIFilterType
{ 
	// --- Smooth [L,LA,RGB,RGBA] ------
	MMI_FLTR_SmoothBoost,
	MMI_FLTR_Average = MMI_FLTR_SmoothBoost,
	MMI_FLTR_SmoothStrong,
	MMI_FLTR_SmoothMedium,
	MMI_FLTR_SmoothSoft,

	// --- Sharp [L,LA,RGB,RGBA] ------
	MMI_FLTR_SharpBoost,
	MMI_FLTR_SharpStrong,
	MMI_FLTR_SharpMedium,
	MMI_FLTR_SharpSoft,

	MMI_FLTR_Gaussian,				
	MMI_FLTR_Laplacian,

	// --- Edges detection [L] ---
	MMI_FLTR_Sobel,
	MMI_FLTR_Prewitt,
	MMI_FLTR_FreiChen,
	MMI_FLTR_Robinson,
	MMI_FLTR_Kirsch,

	MMI_FLTR_Roberts,
	MMI_FLTR_MarrHildreth,
	MMI_FLTR_CannyDeriche,			// not implemented yet
	MMI_FLTR_Shen,					// not implemented yet

	MMI_FLTR_SobelHorizontal,
	MMI_FLTR_SobelVertical,
	MMI_FLTR_PrewittHorizontal,
	MMI_FLTR_PrewittVertical,

	// --- Noice reduction [L] ---
	MMI_FLTR_Median,
	MMI_FLTR_Despeckle = MMI_FLTR_Median,

	// --- Morphology [L] ---
	MMI_FLTR_Erode,
	MMI_FLTR_Dilate,
	MMI_FLTR_Open,
	MMI_FLTR_Close,

	// --- this is not a filter ! ---
	MMI_FLTR_Max
};

/** @nodoc */
enum ExportedByCATMMediaRasterProcessor_Base CATMMIDitherType
{
	// --- Error diffusion algorithms ---
	MMI_DTHR_FloydSteinberg,
	MMI_DTHR_ShiauFan,
	MMI_DTHR_Jarvis,
	MMI_DTHR_Stucki,
	MMI_DTHR_Home,

	// --- Other algorithms ---
	MMI_DTHR_Threshold,
	MMI_DTHR_Default = MMI_DTHR_Home
};


/** @nodoc */
enum ExportedByCATMMediaRasterProcessor_Base CATMMIResampleType
{ 
	MMI_SMPL_Box,				// more speed / less accuracy
	MMI_SMPL_NearestNeightbor	= MMI_SMPL_Box,
	MMI_SMPL_Constant			= MMI_SMPL_Box,

	MMI_SMPL_Triangle,
	MMI_SMPL_Linear				= MMI_SMPL_Triangle,

	MMI_SMPL_Bell,
	MMI_SMPL_Quadratic			= MMI_SMPL_Bell,

	MMI_SMPL_BSpline,
	MMI_SMPL_Bicubic			= MMI_SMPL_BSpline,

	MMI_SMPL_CallmutRom,
	MMI_SMPL_Hermite,
	MMI_SMPL_Lanczos,
	MMI_SMPL_Mitchell,			// less speed / more accuracy
	MMI_SMPL_Default = MMI_SMPL_Mitchell
/*
	MMI_SMPL_Hamming,
	MMI_SMPL_Hanning,
	MMI_SMPL_Gaussian,
	MMI_SMPL_CatmullRom,
	MMI_SMPL_Sinc,
	MMI_SMPL_Bessel,
	MMI_SMPL_Cubic,
*/
};

enum ExportedByCATMMediaRasterProcessor_Base CATMMIMaskType
{ 
	MMI_LuminanceToAlpha = 0,
	MMI_Clip = 1
};

/**
 * @ingroup groupPixelImageTransfo
 */
 /** @nodoc */
class ExportedByCATMMediaRasterProcessor_Base CATMMediaImageProcessor
{
public:
	/** @nodoc */
	static HRESULT Mirror(CATPixelImage& ioImage, 
			CATMMIMirrorType iType = MMI_MIR_None,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	//########################################################################
	//						ramping managment
	//########################################################################
	/*
	 *	Color managment [L,LA,RGB,RGBA]
	 */
	static HRESULT AdjustColor(CATPixelImage& ioImage,
			float iBrightness, float iContrast, float iGamma,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	static HRESULT Balance(CATPixelImage& ioImage, 
			float iRed,	float iGreen, float iBlue,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Changes Brightness of [L,LA,RGB,RGBA] image
	 */
	static HRESULT Brightness(CATPixelImage& ioImage, float iBrightness,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Changes Contrast of [L,LA,RGB,RGBA] image
	 */
	static HRESULT Contrast(CATPixelImage& ioImage, float iContrast,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Changes Gamma of [L,LA,RGB,RGBA] image
	 */
	static HRESULT Gamma(CATPixelImage& ioImage, float iGamma,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Negatives a [L,LA,RGB,RGBA] image
	 */
	static HRESULT Negative(CATPixelImage& ioImage,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Solarizes a [L,LA,RGB,RGBA] image
	 */
	static HRESULT Solarize(CATPixelImage& ioImage, const float iThreshold,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Posterizes degrades each planes to iLevels of intensity [L,LA,RGB,RGBA]
	 */
	static HRESULT Posterize(CATPixelImage& ioImage, const unsigned int iLevels,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Stretchs Histogram of a [L,LA,RGB,RGBA] image
	 */
	static HRESULT StretchHistogram(CATPixelImage& ioImage,
			CATMMIPlane iPlanes = MMI_PLN_All,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	
	//########################################################################
	//					filtering managment
	//########################################################################
	/*
	 *	Applies predefined filter on a image
	 */
	static HRESULT Filter(
			CATPixelImage& ioImage,
			CATMMIFilterType iType = MMI_FLTR_Average,
			int iIteration = 1,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	// TODO Filter SVG
	static HRESULT LinearConvolveMatrix(
			CATPixelImage& ioImage,
			int iKernelDim,
			const float * const iprKernel);

	/*
	 *	Creates a filtered image from safe source and predefined filter
	 *	caller is responsible to kill the return pointer with 'Release'
	 */
	static CATPixelImage * CreateFiltered(
			const CATPixelImage& iImage,
			CATMMIFilterType iType = MMI_FLTR_Average,
			int iIteration = 1,
			CATMMIProgressCB iCallback = 0);

	/*
	 *	Antialiases a [L,LA,RGB,RGBA] image
	 *	Type	:	0 Average,
	 *				1 Low Pass 1
	 *				2 Low Pass 2
	 *				3 Low Pass 3	(default)
	 *				4 Gaussian 
	 */
	static HRESULT Antialiase(
			CATPixelImage& ioImage, 
			int iType = 3,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Creates a antialiased a image from safe source
	 *	caller is responsible to kill the return pointer with 'Release'
	 *	Type	:	0 Average,
	 *				1 Low Pass 1
	 *				2 Low Pass 2
	 *				3 Low Pass 3	(default)
	 *				4 Gaussian 
	 */
	static CATPixelImage * CreateAntialiased(
			const CATPixelImage& iImage, 
			int iType = 3,
			CATMMIProgressCB iCallback = 0);

	/*
	 *  Converts a [L,LA,RGB,RGBA] image to bilevel (default) of L with 2 levels (0x00 and 0xFF) 
	 */
	static HRESULT Dither(
			CATPixelImage& ioImage,
			const CATMMIDitherType iType = MMI_DTHR_Home,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibForceBilevel = TRUE,
			CATBoolean ibProcess = TRUE);

	/*
	 *	Sets Thresholds when using MMI_DTHR_Threshold
	 */
	static void SetDitherThreshold(const int iThreshold);

	static HRESULT Grey(
			CATPixelImage& ioImage,
			const CATMMIGreyType iType,
			CATMMIProgressCB iCallback = 0,
			CATBoolean ibProcess = TRUE);

	//########################################################################
	//					resampling managment
	//########################################################################
	/*
	 *	Creates a resampled image from safe source
	 *	caller is responsible to kill the return pointer with 'Release'
	 *	Type	:	
	 */
	static CATPixelImage * CreateResampled(
			const CATPixelImage& iImage,
			const int iWidth,
			const int iHeight,
			const CATMMIResampleType iType = MMI_SMPL_Default,
			CATMMIProgressCB iCallback = 0);

	/*
	 *	Blend two CATPixelImage	according to the blend type
	 */
	static CATPixelImage * Mask(
			const CATPixelImage& iImage1,
			const CATPixelImage& iImage2,
			const CATMMIMaskType iType = MMI_LuminanceToAlpha,
			CATMMIProgressCB iCallback = 0);

protected:
	static HRESULT LinearConvolveMatrixRGBA(
		uchar * const ioprBitmap,
		int iWidth, int iHeight,
		int iKernelDim,
		const float * const iprKernel);

	static HRESULT ApplyKernelRGBA(int iX, int iY, int iWidth, int iHeight, int iKernelDim, const float * const iprKernel, uchar * const iSrc, uchar* oDest);
	static void GetPixelRGBA (int iX, int iY, int iWidth, int iHeight, uchar * const iprBitmap, float& oR, float& oG, float& oB, float& oA);
private:
	// useless default methods intentionally not accessible (and not generated)
    CATMMediaImageProcessor();
    CATMMediaImageProcessor(const CATMMediaImageProcessor&);
    ~CATMMediaImageProcessor();
    CATMMediaImageProcessor& operator=(const CATMMediaImageProcessor&);
    CATMMediaImageProcessor * operator&();
    const CATMMediaImageProcessor * operator&() const;
	};


#endif // CATMMediaImageProcessor_H
