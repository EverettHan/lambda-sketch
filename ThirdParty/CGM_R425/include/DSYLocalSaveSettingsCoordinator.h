

#ifndef DSYLocalSaveSettingsCoordinator_H
#define DSYLocalSaveSettingsCoordinator_H



#include "JS0SETT.h"
#include "CATBaseUnknown.h"


#define IMAGESESSION_FILENAME "is.log"
#define SETTINGS_CACHE_DIR_NAME "SETTINGS_CACHE"


#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"




class ExportedByJS0SETT DSYLocalSaveSettingsCoordinator
{
 
  public:
	DSYLocalSaveSettingsCoordinator();
	~DSYLocalSaveSettingsCoordinator();
  
  
	/*
	* Retrieve the list of available images, no validity check. 
	* Return S_OK if  images are found and S_FALSE if list is empty.
	*/
	HRESULT GetImageList(CATListOfCATUnicodeString & oImages);
	/*
	* Retrieve pah of last used image 
	* Return S_OK if  images are found and S_FALSE if list is empty.
	*/
	HRESULT GetLastImage(CATUnicodeString & oLastImage);
	
	/*
	* Set the current image for this session 
	*/
	HRESULT SelectImage(const CATUnicodeString & iSelectedImage);

	/*
	* When ioCreatedImage==""
	* Create a new image folder. Folder is empty.  
	* Create a new image if the last used image was selected. Otherwise return the last created image (not selected yet)
	* When ioCreatedImage != ""
	* Create the local save image provided as input. 
	*/
	HRESULT CreateImage(CATUnicodeString & ioCreatedImage);

	/*
	* Delete an image folder. 
	*/
	HRESULT DeleteImage(CATUnicodeString & iImageToDelete);  

	/*
	* returns current process name 
	*/
	CATUnicodeString GetProcessName();
	
	
private:
	
	
	
	HRESULT Init();
	
	static CATUnicodeString * _rootImagePath;
	
	static CATUnicodeString * _lastSelectedImage;
	
	static CATUnicodeString * _newImage;
  
};

#endif
