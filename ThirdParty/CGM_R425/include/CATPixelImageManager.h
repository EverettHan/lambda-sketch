#ifndef CATPixelImageManager_H
#define CATPixelImageManager_H

#include "SGInfra.h"
#include "CATPixelImage.h"

class CATString;
class CATVisPixelImage;

class ExportedBySGInfra CATPixelImageManager
{
public:	
	
 /** Empty Image Generator
  * @param ImageName 
  * The image name used for retrieving it 
  * @param xSize
  * @param ySize
  * @param format 
  * @return pointer to the image in manager. You need to release it.
  */
  static CATPixelImage* GenerateImage(const CATString& iImageName, 
                    unsigned int xSize = 0,
                    unsigned int ySize = 0,
                    CATPixelImageFormat format = RGB);

  /** Removes the image named iImageName
  * @param ImageName 
  * The name of the image you want to remove in the manager   
  */
	static void RemoveImage(const CATString& iImageName);

  /** Gets the image named iImageName
  * @param ImageName 
  * The name of the image you want to get
  * Do not make a release on the resulting pointer !
  */
	static CATPixelImage* GetImage(const CATString& iImageName);

  /** Gets the image named iImageName
  * @param ImageName 
  * The name of the image you want to get
  */
	static void InvalidateImage(const CATString& iImageName);

  /** Gets the image named iImageName
  * @param ImageName 
  * The name of the image you want to get
  * Do not make a release on the resulting pointer !
  *@return the CATVisPixelImage - basically the same as CATPixelImage but with some option for invalidating the image and syncing culling\drawing
  */
  static CATVisPixelImage* GetVisImage(const CATString& iImageName);

  static void Update();
};

#endif // CATPixelImageManager_H
