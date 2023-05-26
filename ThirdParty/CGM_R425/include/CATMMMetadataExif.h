/*
*  CATMMMetadataExif.h
*
*  Copyright 2017 Dassault Systemes. All rights reserved.
*
*/

#ifndef CATMMMetadataExif_H
#define CATMMMetadataExif_H

#include "CATMMMetadata.h"
#include "CATMMediaPixelImage.h"
#include "CATMMRasterEngineDef.h"
// System
#include "CATBaseUnknown.h"
#include "CATListPV.h"

/*********************************************************************/
/* Please refer Exif Version 2.3 specifications for details.         */
/* User is required to adhere strictly with ID-Type-Count relations. */
/*********************************************************************/

/**
* Image Field Directory data types definition.
*/
// IFD type             // c++ equivalent   // EXIF standards description
// -------------------------------------------------------------------------
#define eBYTE       1   // unsigned char    // 1 byte unsigned int, 
#define eASCII      2   // char             // 1 byte containing 7 bit eASCII code, may contain multiple strings terminated by single NUL character (then count represents total number of characters and NUL terminations)
#define eSHORT      3   // unsigned short   // 2 byte unsigned int, 
#define eLONG       4   // unsigned int     // 4 byte unsigned int, 
#define eRATIONAL   5   // float            // 2 LONGs... numerator and denominator
//--> defined in TIFF 6.0
#define eSBYTE      6   // signed char      // 1 byte singed integer
#define eUNDEFINED  7   // void             // 1 byte data
#define eSSHORT     8   // short            // 2 byte signed integer 
#define eSLONG      9   // int              // 4 byte signed integer 
#define eSRATIONAL  10  // float            // 2 SLONGs... numerator and denominator
#define eFLOAT      11  // float            // 4 byte IEEE format
#define eDOUBLE     12  // double           // 8 byte IEEE format

/**
* Image Field Directory IDs required for EXIF
*/
// Table 4 TIFF Rev. 6.0 Attribute Information Used in Exif
// ========================================================
// Field Name                Dec<Tag ID>Hex   Type             Count   Tag Name  
// ---------------------------------------------------------------------------
// A. Tags relating to image data structure
#define eImageWidth                256    // 100  eSHORT or eLONG  1       Image width 
#define eImageLength               257    // 101  eSHORT or eLONG  1       Image height 
#define eBitsPerSample             258    // 102  eSHORT           3       Number of bits per component 
#define eCompression               259    // 103  eSHORT           1       Compression scheme 
#define ePhotometricInterpretation 262    // 106  eSHORT           1       Pixel composition 
#define eOrientation               274    // 112  eSHORT           1       Orientation of image 
#define eSamplesPerPixel           277    // 115  eSHORT           1       Number of components 
#define ePlanarConfiguration       284    // 11C  eSHORT           1       Image data arrangement 
#define eXResolution               282    // 11A  eRATIONAL        1       Image resolution in width direction 
#define eYResolution               283    // 11B  eRATIONAL        1       Image resolution in height direction 
#define eResolutionUnit            296    // 128  eSHORT           1       Unit of X and Y resolution 
// C. Tags relating to image data characteristics
#define eTransferFunction          301    // 12D  eSHORT           3*256   Transfer function 
#define eWhitePoint                318    // 13E  eRATIONAL        2       White point chromaticity 
#define ePrimaryChromaticities     319    // 13F  eRATIONAL        6       Chromaticities of primaries 
#define eReferenceBlackWhite       532    // 214  eRATIONAL        6       Pair of black and white reference values 
// D. Other tags
#define eDateTime                  306    // 132  eASCII           20      File change date and time 
#define eImageDescription          270    // 10E  eASCII           Any     Image title 
#define eMake                      271    // 10F  eASCII           Any     Image input equipment manufacturer 
#define eModel                     272    // 110  eASCII           Any     Image input equipment model 
#define eSoftware                  305    // 131  eASCII           Any     Software used 
#define eArtist                    315    // 13B  eASCII           Any     Person who created the image 
#define eCopyright                 33432  // 8298 eASCII           Any     Copyright holder 
// Table 7 Exif IFD Attribute Information (1)
// Field Name                Dec<Tag ID>Hex   Type            Count    Tag Name  
// -----------------------------------------------------------------------------
// A. Tags Relating to Version
#define eExifVersion               36864  // 9000 eUNDEFINED       4       Exif version 
#define eFlashpixVersion           40960  // A000 eUNDEFINED       4       Supported Flashpix version 
// B. Tag Relating to Image Data Characteristics
#define eColorSpace                40961  // A001 eSHORT           1       Color space information 
#define eGamma                     42240  // A500 eRATIONAL        1       Gamma
// C. Tags Relating to Image Configuration
#define eComponentsConfiguration   37121  // 9101 eUNDEFINED       4       Meaning of each component 
#define eCompressedBitsPerPixel    37122  // 9102 eRATIONAL        1       Image compression mode 
#define ePixelXDimension           40962  // A002 eSHORT or eLONG  1       Valid image width 
#define ePixelYDimension           40963  // A003 eSHORT or eLONG  1       Valid image height 
// D. Tags Relating to User Information
#define eMakerNote                 37500  // 927C eUNDEFINED       Any     Manufacturer notes 
#define eUserComment               37510  // 9286 eUNDEFINED       Any     User comments 
// F. Tags Relating to Date and Time
#define eDateTimeOriginal          36867  // 9003 eASCII           20      Date and time of original data generation 
#define eDateTimeDigitized         36868  // 9004 eASCII           20      Date and time of digital data generation 
#define eSubSecTime                37520  // 9290 eASCII           Any     DateTime subseconds 
#define eSubSecTimeOriginal        37521  // 9291 eASCII           Any     DateTimeOriginal subseconds 
#define eSubSecTimeDigitized       37522  // 9292 eASCII           Any     DateTimeDigitized subseconds 
// G. Tags Relating to Picture-Taking Conditions
#define eExposureTime              33434  // 829A eRATIONAL        1       Exposure time 
#define eFNumber                   33437  // 829D eRATIONAL        1       F number 
#define eExposureProgram           34850  // 8822 eSHORT           1       Exposure program 
#define eSpectralSensitivity       34852  // 8824 eASCII           Any     Spectral sensitivity 
#define ePhotographicSensitivity   34855  // 8827 eSHORT           Any     Photographic Sensitivity 
#define eOECF                      34856  // 8828 eUNDEFINED       Any     Optoelectric conversion factor 
#define eSensitivityType           34864  // 8830 eSHORT           1       Sensitivity Type 
#define eStandardOutputSensitivity 34865  // 8831 eLONG            1       Standard Output Sensitivity 
#define eRecommendedExposureIndex  34866  // 8832 eLONG            1       Recommended Exposure Index 
#define eISOSpeed                  34867  // 8833 eLONG            1       ISO Speed 
#define eISOSpeedLatitudeyyy       34868  // 8834 eLONG            1       ISO Speed Latitude yyy 
#define eISOSpeedLatitudezzz       34869  // 8835 eLONG            1       ISO Speed Latitude zzz 
#define eShutterSpeedValue         37377  // 9201 eSRATIONAL       1       Shutter speed 
#define eApertureValue             37378  // 9202 eRATIONAL        1       Aperture 
#define eBrightnessValue           37379  // 9203 eSRATIONAL       1       Brightness 
#define eExposureBiasValue         37380  // 9204 eSRATIONAL       1       Exposure bias 
#define eMaxApertureValue          37381  // 9205 eRATIONAL        1       Maximum lens aperture 
#define eSubjectDistance           37382  // 9206 eRATIONAL        1       Subject distance 
#define eMeteringMode              37383  // 9207 eSHORT           1       Metering mode 
#define eLightSource               37384  // 9208 eSHORT           1       Light source 
#define eFlash                     37385  // 9209 eSHORT           1       Flash 
#define eFocalLength               37386  // 920A eRATIONAL        1       Lens focal length 
#define eSubjectArea               37396  // 9214 eSHORT           2/3/4   Subject area 
#define eFlashEnergy               41483  // A20B eRATIONAL        1       Flash energy 
#define eSpatialFrequencyResponse  41484  // A20C eUNDEFINED       Any     Spatial frequency response 
#define eFocalPlaneXResolution     41486  // A20E eRATIONAL        1       Focal plane X resolution 
#define eFocalPlaneYResolution     41487  // A20F eRATIONAL        1       Focal plane Y resolution 
#define eFocalPlaneResolutionUnit  41488  // A210 eSHORT           1       Focal plane resolution unit 
#define eSubjectLocation           41492  // A214 eSHORT           2       Subject location 
#define eExposureIndex             41493  // A215 eRATIONAL        1       Exposure index 
#define eSensingMethod             41495  // A217 eSHORT           1       Sensing method 
#define eFileSource                41728  // A300 eUNDEFINED       1       File source 
#define eSceneType                 41729  // A301 eUNDEFINED       1       Scene type 
#define eCFAPattern                41730  // A302 eUNDEFINED       Any     CFA pattern 
#define eCustomRendered            41985  // A401 eSHORT           1       Custom image processing 
#define eExposureMode              41986  // A402 eSHORT           1       Exposure mode 
#define eWhiteBalance              41987  // A403 eSHORT           1       White balance 
#define eDigitalZoomRatio          41988  // A404 eRATIONAL        1       Digital zoom ratio 
#define eFocalLengthIn35mmFilm     41989  // A405 eSHORT           1       Focal length in 35 mm film 
#define eSceneCaptureType          41990  // A406 eSHORT           1       Scene capture type 
#define eGainControl               41991  // A407 eRATIONAL        1       Gain control 
#define eContrast                  41992  // A408 eSHORT           1       Contrast 
#define eSaturation                41993  // A409 eSHORT           1       Saturation 
#define eSharpness                 41994  // A40A eSHORT           1       Sharpness 
#define eDeviceSettingDescription  41995  // A40B eUNDEFINED       Any     Device settings description 
#define eSubjectDistanceRange      41996  // A40C eSHORT           1       Subject distance range 
// H. Other Tags
#define eImageUniqueID             42016  // A420 eASCII           33      Unique image ID 
#define eCameraOwnerName           42032  // A430 eASCII           Any     Camera Owner Name
#define eBodySerialNumber          42033  // A431 eASCII           Any     Body Serial Number
#define eLensSpecification         42034  // A432 eRATIONAL        4       Lens Specification 
#define eLensMake                  42035  // A433 eASCII           Any     Lens Make 
#define eLensModel                 42036  // A434 eASCII           Any     Lens Model 
#define eLensSerialNumber          42037  // A435 eASCII           Any     Lens Serial Number 
//  GPS Tags
#define  eGPSVersionID				0     // 0x0000 Byte           4       GPS tag version
#define  eGPSLatitudeRef			1	  // 0x0001 Ascii		   2       North or South Latitude
#define  eGPSLatitude				2     // 0x0002 Rational       3       Latitude
#define  eGPSLongitudeRef			3     // 0x0003 Ascii          2       East or West Longitude
#define  eGPSLongitude              4	  // 0x0004 Rational	   3       Longitude
#define  eGPSAltitudeRef			5	  // 0x0005 Byte		   1       Altitude reference
#define  eGPSAltitude				6     // 0x0006 Rational	   1       Altitude
#define  eGPSTimeStamp				7     // 0x0007 Rational       3       GPS time (atomic clock)
#define  eGPSSatellites				8	  // 0x0008 Ascii          Any	   GPS satellites used for measurement
#define  eGPSStatus					9     // 0x0009 Ascii		   2	   GPS receiver status
#define  eGPSMeasureMode			10    // 0x000A Ascii		   2	   GPS measurement mode
#define  eGPSDOP					11    // 0x000B Rational	   1	   Measurement precision
#define  eGPSSpeedRef				12    // 0x000C Ascii		   2	   Speed unit
#define  eGPSSpeed					13    // 0x000D Rational	   1	   Speed of GPS receiver
#define  eGPSTrackRef				14    // 0x000E Ascii		   2	   Reference for direction of movement
#define  eGPSTrack					15    // 0x000F Rational	   1	   Direction of movement
#define  eGPSImgDirectionRef		16    // 0x0010 Ascii		   2	   Reference for direction of image
#define  eGPSImgDirection			17    // 0x0011 Rational	   1	   Direction of image
#define  eGPSMapDatum				18    // 0x0012 Ascii		   Any	   Geodetic survey data used
#define  eGPSDestLatitudeRef		19    // 0x0013 Ascii		   2	   Reference for latitude of destination
#define  eGPSDestLatitude			20    // 0x0014 Rational	   3	   Latitude of destination
#define  eGPSDestLongitudeRef		21    // 0x0015 Ascii		   2	   Reference for longitude of destination
#define  eGPSDestLongitude			22    // 0x0016 Rational	   3	   Longitude of destination
#define  eGPSDestBearingRef			23    // 0x0017 Ascii		   2	   Reference for bearing of destination
#define  eGPSDestBearing			24    // 0x0018 Rational	   1	   Bearing of destination
#define  eGPSDestDistanceRef		25    // 0x0019 Ascii		   2	   Reference for distance to destination
#define  eGPSDestDistance			26    // 0x001A Rational	   1	   Distance to destination
#define  eGPSProcessingMethod		27    // 0x001B Undefined	   Any	   Name of GPS processing method
#define  eGPSAreaInformation		28    // 0x001C Undefined	   Any	   Name of GPS area
#define  eGPSDateStamp				29    // 0x001D Ascii		   11	   GPS date
#define  eGPSDifferential			30    // 0x001E Short		   1	   GPS differential correction
#define  eGPSHPositioningError		31    // 0x001F Rational	   1	   Horizontal positioning error



typedef struct { unsigned int numerator; unsigned int denominator; } ExifRational;
typedef struct { int numerator; unsigned int denominator; } ExifSRational;
typedef unsigned short ExifFieldID;
typedef unsigned short ExifFieldType;
/*
* Class to use for image metadata.
*/

class ExportedByCATMMediaPixelImage CATMMMetadataExif : public CATMMMetadata
{
	CATDeclareClass;

public:

	/**
	* Constructs an instance of metadata class containing empty data.
	*/
	CATMMMetadataExif();
	virtual ~CATMMMetadataExif();

	virtual CATUnicodeString GetIdentifier() const { return "Exif"; };
	//virtual CATUnicodeString GetDump()       const                                                 ;

	virtual bool GetData(CATUnicodeString iParameter, CATBoolean       &oValue) const { return 0; };
	virtual bool GetData(CATUnicodeString iParameter, int              &oValue) const { return 0; };
	virtual bool GetData(CATUnicodeString iParameter, unsigned int     &oValue) const { return 0; };
	virtual bool GetData(CATUnicodeString iParameter, CATUnicodeString &oValue) const { return 0; };

	virtual bool SetData(CATUnicodeString iParameter, CATBoolean        iValue) { return 0; };
	virtual bool SetData(CATUnicodeString iParameter, int               iValue) { return 0; };
	virtual bool SetData(CATUnicodeString iParameter, unsigned int      iValue) { return 0; };
	virtual bool SetData(CATUnicodeString iParameter, CATUnicodeString  iValue) { return 0; };

	/**
	* Set the desired metadata. There are various functions for each type
	* of field type. The function which accepts 'float' is used for both
	* RATIONAL and SRATIONAL types. User is required to adhere strictly
	* with ID-Type-Count relations.
	* @param iID
	*   IFD field ID.
	* @param ipData
	*   Pointer to data corresponding to iID.
	* @param iCount
	*   Number of items of data (NOT the number of bytes). Default value is 1.
	* @return
	* <br><b>Legal values</b>
	* <dl>
	*  <dt>MMIE_TYPE_MISMATCH</dt>
	*  <dd>Type provided is not allowed for given ID.</dd>
	*  <dt>MMIE_COUNT_MISMATCH</dt>
	*  <dd>Count provided is not allowed for given ID.</dd>
	*  <dt>E_FAIL</dt>
	*  <dd>Unknown error.</dd>
	*  <dt>S_OK</dt>
	*  <dd>Data is added successfully.</dd>
	* </dl>
	* @see ExifFieldID, ExifFieldType
	*/
	HRESULT SetData(const ExifFieldID iID, const char           *ipData, const int iCount = 1);  // for ASCII (may contain multiple strings terminated by single NUL character)
	HRESULT SetData(const ExifFieldID iID, const unsigned short *ipData, const int iCount = 1);  // for SHORT
	HRESULT SetData(const ExifFieldID iID, const unsigned int   *ipData, const int iCount = 1);  // for LONG
	HRESULT SetData(const ExifFieldID iID, const ExifRational   *ipData, const int iCount = 1);  // for RATIONAL
	HRESULT SetData(const ExifFieldID iID, const ExifSRational  *ipData, const int iCount = 1);  // for SRATIONAL
	HRESULT SetData(const ExifFieldID iID, const void           *ipData, const int iCount = 1);  // for UNDEFINED (1 byte data)
	HRESULT SetDataByte(const ExifFieldID iID, const void           *ipData, const int iCount = 1);  // for BYTE 
																								 /**
																								 * Get data size in bytes for requested tag.
																								 * @param iID
																								 *   IFD field ID.
																								 * @param oByteSz
																								 *   Size of data in bytes.
																								 * @return
																								 * <br><b>Legal values</b>
																								 * <dl>
																								 *  <dt>E_INVALIDARG</dt>
																								 *  <dd>Requested ID is not present.</dd>
																								 *  <dt>E_FAIL</dt>
																								 *  <dd>Unknown error.</dd>
																								 *  <dt>S_OK</dt>
																								 *  <dd>Success.</dd>
																								 * </dl>
																								 * @see ExifFieldID, ExifFieldType
																								 */
	HRESULT GetDataSizeInBytes(ExifFieldID iID, int &oByteSz) const;

	/**
	* Get data for requested tag.
	* @param iID
	*   IFD field ID.
	* @param oType
	*   IFD field type.
	* @param opData
	*   Pointer to receive data corresponding to iID. User should allocate necessary memory.
	*   Size of required memory can be found using GetDataSizeInBytes.
	* @param iSzDataInBytes
	*   Size of user allocated opData.
	* @return
	* <br><b>Legal values</b>
	* <dl>
	*  <dt>E_INVALIDARG</dt>
	*  <dd>Requested ID is not present.</dd>
	*  <dt>E_OUTOFMEMORY</dt>
	*  <dd>The memory is not sufficient. Please use GetDataSizeInBytes to know size of memory needed.</dd>
	*  <dt>E_FAIL</dt>
	*  <dd>Unknown error.</dd>
	*  <dt>S_OK</dt>
	*  <dd>Success.</dd>
	* </dl>
	* @see ExifFieldID, ExifFieldType
	*/
	HRESULT GetData(ExifFieldID iID, ExifFieldType &oType, int &oCount, void *opData, int iSzDataInBytes) const;

	int GetNumberOfEntries() const;
	ExifFieldID GetID(int index) const; // 0 <= index < GetNumberOfEntries()
	CATMMMetadataExif& operator=(const CATMMMetadataExif&);

private:
	// useless default methods intentionally not accessible (and not generated)
	CATMMMetadataExif(const CATMMMetadataExif&);

	friend class CATMMRasterEngineSB;
	friend class CATMMRasterEngineOpenAPI;
	friend class CATMMRasterEngineGDIplus;
	friend class CATMMImageMetadata;

	// if opIFD is NULL, oSzIFD returns size needed
	HRESULT Generate(unsigned char *&opIFD, int &ioSzIFD, CATBoolean iForTIFF = TRUE) const;
	HRESULT Interpret(const unsigned char *ipIFD, const int iSzIFD, const unsigned char* ipTIFFHeader = NULL);

	HRESULT SetData(const ExifFieldID iID, const ExifFieldType iType, const void *ipData, const int iSzBytes, const int iCount);
	HRESULT InterpretIFD(const unsigned char *ipIFD, const int iSzIFD, const int iOffset, const CATBoolean iDoBigLittle, CATListPV &iAddToIFD);
	HRESULT CheckTypeAndSize(ExifFieldID iID, ExifFieldType iType, int iCount, int &oSzValue) const;
	void EmptyIFDList();

private:
	CATListPV _listIFDEntries;
};


#endif  // CATMMImageMetadata_H
