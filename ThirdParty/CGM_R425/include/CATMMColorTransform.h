#ifndef CATMMColorTransform_H
#define CATMMColorTransform_H
// COPYRIGHT DASSAULT SYSTEMES 2013
#include "CATMMediaPixelImage.h"
#include "CATSysTSBaseUnknown.h"
#include "CATPixelImage.h"
#include "CATMMCMSType.h" 

#include "CATMMColorProfile.h"

class CATMMColorProfile;
class CATMMPIPixelColorSpec;	  
class CATMMPIColorSpace;
/**
 * @ingroup groupPixelImageColor
 * class CATMMColorTransform
 * Apply gamut transformations using a source profile and a destination profile
 */
class ExportedByCATMMediaPixelImage CATMMColorTransform : public CATSysTSBaseUnknown
{
	

public:	
	/**
	* Constructor
	* Create an empty Color Transform.
	*/
	CATMMColorTransform();

	/**
	* Constructor
	* Create a Color Transform between two Color Profiles
	* @param ipProfileSrc input pointer to a source Color Profile.
	* @param iProfileDst input pointer to a destination Color Profile.
	* You are allowed to set "iProfileDst" to NULL to use "ipProfileSrc" as detination profile while using a sRGB virtual profile as source.
	* @param iIntentType the rendering intent to be used.
	*/
	CATMMColorTransform(CATMMColorProfile* ipProfileSrc, CATMMColorProfile* ipProfileDst, int iIntentType=MM_CMS_INTENT_PERCEPTUAL);

	/**
	* Constructor
	* Create a Color Transform between two Color Profiles
	* @param ipProfileSrc input pointer to a source Color Profile.
	* @param iTypeSrc input type of the source Color Profile. eg : TYPE_RGB_8
	* @param iProfileDst input pointer to a destination Color Profile.
	* You are allowed to set "iProfileDst" to NULL to use "ipProfileSrc" as detination profile while using a sRGB virtual profile as source.
	* @param iTypeDst  input type of the destination Color Profile. eg : TYPE_RGB_8
	* @param iIntentType the rendering intent to be used.
	*/
	CATMMColorTransform(CATMMColorProfile* ipProfileSrc, int iTypeSrc, CATMMColorProfile* ipProfileDst, int iTypeDst, int iIntentType=MM_CMS_INTENT_PERCEPTUAL);
	
	/**
	* Destructor.
	*/
	~CATMMColorTransform();
	
	/**
	* Create a Color Transform between two Color Profiles
	* @param ipProfileSrc input pointer to a source Color Profile.
	* @param iTypeSrc input type of the source Color Profile. eg : TYPE_RGB_8
	* @param iProfileDst input pointer to a destination Color Profile.
	* You are allowed to set "iProfileDst" to NULL to use "ipProfileSrc" as detination profile while using a sRGB virtual profile as source.
	* @param iTypeDst  input type of the destination Color Profile. eg : TYPE_RGB_8
	* @param iIntentType the rendering intent to be used.
	*/
	HRESULT CreateTransform(CATMMColorProfile* profileSrc, int typeSrc, CATMMColorProfile* profileDst=NULL, int typeDst=MM_CMS_TYPE_RGB_8, int intentType=MM_CMS_INTENT_PERCEPTUAL);

	/**
	* Create a Color Transform between two Color Profiles
	* @param ipProfileSrc input pointer to a source Color Profile.
	* @param iProfileDst input pointer to a destination Color Profile.
	* You are allowed to set "iProfileDst" to NULL to use "ipProfileSrc" as detination profile while using a sRGB virtual profile as source.
	* @param iIntentType the rendering intent to be used.
	*/
	HRESULT CreateTransform(CATMMColorProfile* profileSrc, CATMMColorProfile* profileDst=NULL, int intentType=MM_CMS_INTENT_PERCEPTUAL);

	/**
	* Create a Color Transform between a given Color Profile and the CIELab color space.
	* @param profileSrc : input pointer to the source Color Profile.
	* @param iTypeSrc : input type of the source Color Profile. eg : TYPE_RGB_8.
	* @param iIntentType : the rendering intent to be used.
	*/
	HRESULT CreateTransformToLAB(CATMMColorProfile* ipProfileSrc, int iTypeSrc, int iIntentType = MM_CMS_INTENT_PERCEPTUAL);

	/**
	* Apply the current Color Transform to an image using its path.
	* Note that the image will be loaded in a CATPixelImage.
	* @param iImagePath input image path.
	*/
	HRESULT DoTransform(CATUnicodeString iImagePath);

	/**
	* Apply the current Color Transform to a CATPixelImage.
	* @param ipImage input image path.
	*/
	HRESULT DoTransform(CATPixelImage* ipImage);

	/**
	* Apply the current Color Transform to a single color instance.
	* @param iInputColor : the input color.
	* @param oOutputColor : the output color.
	* @return : the transformation result .
	*/
	HRESULT DoTransform(BYTE* iInputColor, BYTE* oOutputColor);

	/**
	* Apply the current color Transform to a color specification
	* @param iColorSpec The color specification 	
	* @return The transformation  result 
	*/	
	HRESULT DoTransform(CATMMPIPixelColorSpec* iColorSpec);
						
	/**
	 * Apply a transform to a color specification to produce Lab color
	 * @param iColorSpace The color space specification
	 * @param iInputColor : The input color
	 * @param oResult The Lab color result( The user needs to provide the ouput buffer that will be filled with the result)
	 * @return The transformation result 
	 */	
	static HRESULT DoTransformToLab(CATMMPIColorSpace* iColorSpace, BYTE* iInputColor, double oResult[3]);

	/**
	 * Apply a transform to an input Lab color to produce outputColor according to the color specifcation
	 * @param iInputColor The Lab input color 
	 * @param iColorSpace The color space of the output color
	 * @param oOutputColor The output color ( The user needs to provide the output buffer that will be filled with the result)
	 * @return The transformation  result 
	 */	
	static HRESULT DoTransformFromLab(double iInputColor[3], CATMMPIColorSpace* iColorSpace, BYTE* oOutputColor);


	/**
	 * Computes the delta E distance between 2 Labcolors 
	 * @param iColor0 The first Lab input color
	 * @param iColor1 The second Lab input color
	 * @param iMethodUsed The Delta E comparison method choosen
	 * @param iParametersSize The number of parameters ( eDELTA_E_CMC_84 requires 2 parameters and eDELTA_E_2000 requires 3 parameters, other comparison methods requires no parameters)
	 * @param iParameters The parameters list
	 * @return The result if OK  
	 */	
	static HRESULT ComputeDeltaE(double iColor0[3], double iColor1[3], DELTA_E_METHOD iMethodUsed, double& oDeltaEValue, double iParametersSize = 0, double* iParameters = NULL);

	/**
	* Return the CATPixelImage transformed. You must use DoTransform() before.
	* @return Pointer of CATPixelImage containing the transformed image to be used in the destination Color Profile.
	*/
	CATPixelImage* getCATPixelImage();
	
	/**
	* Check if the Color Transform exists (is not empty).
	* @return true if the transform is not empty. False otherwise.
	*/
	bool		exist();



private:
	CATcmsHTRANSFORM _hTransform;
	CATMMColorProfile* _pProfileSrc;
	int _typeSrc;
	CATMMColorProfile* _pProfileDst;
	int _typeDst;
	int _intentType;
	CATPixelImage* _pImageRes;
};

#endif
