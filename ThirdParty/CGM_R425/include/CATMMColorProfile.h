#ifndef CATMMColorProfile_H
#define CATMMColorProfile_H
// COPYRIGHT DASSAULT SYSTEMES 2013

#include "CATMMediaPixelImage.h"
#include "CATSysTSBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATPixelImage.h"
#include "CATMMCMSType.h" 

/**
 * @ingroup groupPixelImageColor
 * class CATMMColorProfile
 * Contains an icc profile to be manipulated
 */
class ExportedByCATMMediaPixelImage CATMMColorProfile : public CATSysTSBaseUnknown
{
	friend class CATMMColorTransform;
	friend class CATMMColorProfileFactory;
public:
	/**
	* Destructor.
	*/
	virtual ~CATMMColorProfile();

	/**
	* Save the current Color Profile into a file.
	* @param iFilePath the path to the .icc file to be written. Note that if the file already exist it will be overwritten.
	*/
	HRESULT		saveProfileInFile(CATUnicodeString iFilePath);

	/**
	* Save the current Color Profile into a buffer.
	* @param oBuffer the buffer where the icc profile will be written
	* @param oLen the length of the created buffer.
	*/
	HRESULT		saveProfileToMem(unsigned char* oBuffer, size_t* oLen);

	/**
	* Check if the Color Profile exists (is not empty).
	* @return true if the profile is not empty. False otherwise.
	*/
	bool		exist() const;

	/**
	* Return the name of the Color Profile as written in the parameters. eg : sRGB.
	* @return CATUnicodeString containing the Color Profile Name.
	*/
	CATUnicodeString		getProfileName();

	/**
	* Return the name of the Manufacturer as written in the parameters. eg : Dassault Systemes.
	* @return CATUnicodeString containing the Manufacturer Name.
	*/
	CATUnicodeString		getProfileManufacturer();

	/**
	* Return the name of the Model as written in the parameters. eg : CATIA.
	* @return CATUnicodeString containing the Model Name.
	*/
	CATUnicodeString		getProfileModel();

	/**
	* Return the value of the Copyright as written in the parameters. eg : Dassault Systemes 2013 all right reserved.
	* @return CATUnicodeString containing the Copyright value.
	*/
	CATUnicodeString		getProfileCopyright();

	/**
	* Return the date of creation of the Color Profile as written in the parameters. eg : 15/08/1990 12:34:56.
	* @return CATUnicodeString containing the Date with "01/01/1970 00:00:00" format.
	*/
	CATUnicodeString		getProfileCreationDate();

	/**
	* Return the name of the device attribut as written in the parameters. eg : Reflective.
	* @return CATUnicodeString containing the device attribut name.
	*/
	CATUnicodeString		getProfileDeviceAttribut();

	/**
	* Return the default rendering intent as written in the parameters. eg : Perceptual.
	* @return CATUnicodeString containing the Rendering Intent name.
	*/
	CATUnicodeString		getProfileRenderingIntent();

	/**
	* Return the color space signature. eg : RGB or CMYK.
	* @return CATcmsColorSpaceSignature.
	*/
	CATcmsColorSpaceSignature getProfileColorSpaceSignature();

protected:
	/**
	* Constructor
	* Create an empty Color Profile.
	*/
	CATMMColorProfile();

	/**
	* Constructor
	* Create a Color Profile using an .icc file.
	* @param iFilePath the path to the .icc file.
	*/
//CATMMColorProfile(CATUnicodeString iFilePath);

	/**
	* Constructor
	* Create a Color Profile using an embedded icc profile in a buffer.
	* @param iBuffer the buffer containing the raw icc profile.
	* @param iLen the length of the buffer.
	*/
//CATMMColorProfile(unsigned char* iBuffer, size_t iLen);

	/**
	* Copy the whole Color Profile object into another Color Profile.
	*/
	CATMMColorProfile& operator=(const CATMMColorProfile&);

private:
  CATMMColorProfile(const CATMMColorProfile&);
	/**
	* Intialise the informations attributes.
	*/
	void		InitInfo();

	/**
	* Fill the informations attributes reading the Color Profile.
	*/
	void		FillInfo();

	/**
	* Retrieves the informations from the loaded profile.
	* @param iInfoType values from the enum cmsInfoType. Eg : cmsInfoDescription.
	*/
	CATUnicodeString		getInfoProfile(CATcmsInfoType iInfoType);

	/**
	* Retrieves the date informations from the loaded profile.
	*/
	CATUnicodeString		getInfoDateProfile();

	/**
	* Retrieves the device attributes informations from the loaded profile.
	*/
	CATUnicodeString		getInfoDeviceAttribut();

	/**
	* Retrieves the rendering intent informations from the loaded profile.
	*/
	CATUnicodeString		getInfoRenderingIntent();

	/**
	* Retrieves the color space signature from the loaded profile.
	*/
	CATcmsColorSpaceSignature getInfoColorSpaceSignature();

	CATcmsHPROFILE _hProfile;
	CATUnicodeString _profileInfoName;
	CATUnicodeString _profileInfoManufacturer;
	CATUnicodeString _profileInfoCopyright;
	CATUnicodeString _profileInfoCreationDate;
	CATUnicodeString _profileInfoDeviceAttribut;
	CATUnicodeString _profileInfoRenderingIntent;
	CATUnicodeString _profileInfoModel;
	CATcmsColorSpaceSignature _profileColorSpaceSignature;
};

#endif
