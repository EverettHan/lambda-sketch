#ifndef CATMMColorProfileFactory_H
#define CATMMColorProfileFactory_H
// COPYRIGHT DASSAULT SYSTEMES 2013

#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"
#include <vector>

class CATMMColorProfile;

//Typedef for window identifier( under WINDOWS OS  , it equals to HANDLE)
typedef void* WINDOW_HANDLE;

class ExportedByCATMMediaPixelImage CATMMColorProfileFactory
{
public:
	/**
	* Create a Color Profile using an .icc file.
	* @param iFilePath the path to the .icc file.
	*/
	static CATMMColorProfile* CreateColorProfileFromFile(CATUnicodeString iFilePath);

	/**
	* Create a default sRGB Color Profile.
	*/
	static CATMMColorProfile* CreateSRGBColorProfile();

	/**
	* Create a Color Profile using an embedded icc profile in a buffer.
	* @param iBuffer the buffer containing the raw icc profile.
	* @param iLen the length of the buffer.
	*/
	static CATMMColorProfile* CreateColorProfileFromBuffer(unsigned char* iBuffer, size_t iLen);

	/**
	* Create a Color Profile by retrieving the current .icc file used by the screen.
	*/
	static CATMMColorProfile* CreateColorProfileFromCurrentProfile();

   /**
	* Retrieves the screen ICC profile
	* WINDOW_HANDLE equals to HANDLE with windows OS
	*/	
	static CATUnicodeString GetScreenICCProfile(WINDOW_HANDLE iWindow = NULL);

	/**
	 * Retrieves the  ICC profile(s) listed as available for the user’s screen
	 */ 
	static std::vector<CATUnicodeString> GetListScreenICCProfiles();

	/**
	 * Retrieves the  availables ICC profile(s) on the computer
	 */ 
	static std::vector<CATUnicodeString> GetListComputerICCProfiles(CATBoolean iAbsolute = FALSE);

	/**
	 * Retrieves the  default availables ICC profile(s) available in 3DExperience
	 */ 
	static std::vector<CATUnicodeString> GetResourcesICCProfiles(CATBoolean iAbsolute = FALSE);

private:

	/**
	 * Retrieves the  availables ICC profile(s) from a folder
	 */ 
	static std::vector<CATUnicodeString>  GetICCProfilesfromFolder(const CATUnicodeString& iFolder, CATBoolean iAbsolute = FALSE);
};

#endif
