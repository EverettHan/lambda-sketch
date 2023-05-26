#ifndef CATPIXELIMAGECOMPARATOR_H
#define CATPIXELIMAGECOMPARATOR_H
// COPYRIGHT DASSAULT SYSTEMES 2013

#include "CATMMediaRasterProcessor_Base.h"
#include "CATSysTSBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATPixelImage.h"
#include "CATMMCMSType.h" 

/**
 * @ingroup groupPixelImageData
 * @brief In charge of computing differences between images.
 **/
class ExportedByCATMMediaRasterProcessor_Base CATPixelImageComparator
{
public:
		
	/**	
	* Compare two images according to their filepath
	* @param iFilePath1 : the first input image
	* @param iFilePath2 : the second input image
	* @param iMaximumDistancetoStdDeviation :
	*	used to exclude the extreme outliers
	*	if a pixel has a distance to the average distance superior to maximumDistancetoStdDeviation*stadardDeviation, it is considered as an outlier
	*	put 0 to deactivate the outliers exclusion
	* @return true if teh comparison was successful
	*/
	static CATBoolean ImageCompare (CATUnicodeString iFilePath1, 
													CATUnicodeString iFilepath2, 
													CATUnicodeString iOutputImageDir, 
													double iDistanceThreshold,
													int iMaximumDistancetoStdDeviation,
													double iMaxDistance,
													double&  oLabMeanDistance, 
													int& oNbOfDifferentPixels,
													double &oPercentageOfDifferentPixels,
													double& oPixelDifferenceStandardDevation,
													double& oMaxDiffrenceValue,
													double& oMedianDifferenceValue,
													bool bHOutputHeatMap,
													bool bGenerateRelativeDifference = false);
   
	/**
	* Compare two CATPixelImage in Lab color space 
	* @param iFilePath1 : the first input image
	* @param iFilePath2 : the second input image
	* @param iMaximumDistancetoStdDeviation used to exclude the extreme ouliers:
	*	if a pixel has a distance to the average distance superior to maximumDistancetoStdDeviation*stadardDeviation, it is considered as an outlier
	*	put 0 to deactivate the outliers exclusion
	* @return true if teh comparison was successful
	*/
	static CATBoolean ImageLabCompare (CATPixelImage * pImage1, 
									  CATPixelImage * pImage2, 
									  CATUnicodeString iOutputImageDir, 
									 double iDistanceThreshold,
									 int iMaximumDistancetoStdDeviation,
									 double&  oLabMeanDistance, 
									 int& oNbOfDifferentPixels,
									double &oPercentageOfDifferentPixels,
									double& oPixelDifferenceStandardDevation,
									double& oMaxDiffrenceValue,
									double& oMedianDifferenceValue,
									double *& dPixelDistanceBuffer);


	/**
	* Compare two HDR CATPixelImage 
	* @param iFilePath1 : the first input image
	* @param iFilePath2 : the second input image
	* @param iMaximumDistancetoStdDeviation used to exclude the extreme outliers:
	*	if a pixel has a distance to the average distance superior to maximumDistancetoStdDeviation*stadardDeviation, it is considered as an outlier
	*	put 0 to deactivate the outliers exclusion
	* @return true if the comparison was successful
	*/
	static CATBoolean ImageHDRCompare (CATPixelImage * pImage1, 
												   CATPixelImage * pImage2, 
												   CATUnicodeString iOutputImageDir, 
												   double iDistanceThreshold,
												   int iMaximumDistancetoStdDeviation,
												   double&  oHDRMeanDistance, 
												   int& oNbOfDifferentPixels,
												   double &oPercentageOfDifferentPixels,
												   double& oPixelDifferenceStandardDevation,
												   double& oMaxDiffrenceValue,
												   double& oMedianDifferenceValue,
													double *& dPixelDistanceBuffer);



private:
  
  /**
	* Constructor
	*/	
	CATPixelImageComparator();
	
	
	/**
	* Destructor.
	*/
	virtual ~CATPixelImageComparator();
	
	
	/**
	 * Copy constructor
	 */
	CATPixelImageComparator(const CATPixelImageComparator&);

	
	/**
	 * Equal operator
	 */
	CATPixelImageComparator& operator=(const CATPixelImageComparator&);

  
};

#endif
