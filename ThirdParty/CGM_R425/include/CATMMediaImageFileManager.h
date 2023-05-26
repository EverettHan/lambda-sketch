//----------------------------------------------------------------------------
//	CATMMediaImageFileManager.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageFileManager_H
#define CATMMediaImageFileManager_H

#include "CATMMediaRasterFormats_SB_File.h"
#include "CATMMediaImageFileInfo.h"
#include "CATMMediaImageFileOption.h"
#include "CATBoolean.h"
//#include "CATPixelImage.h"

class CATPixelImage;
class CATUnicodeString;
struct TFormatInterface;

//============================================================================
//	class CATMMediaImageFileFormatList
//============================================================================
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileFormatList
{
public:
	/**
	 * default constructor builds an empty list for write.
	 */
	CATMMediaImageFileFormatList(const CATBoolean ibRead = FALSE);

	/**
	 * builds list with all types (Read or Write)
	 */
	void AddAllType();

	/**
	 * builds list with all types with option (Read or Write)
	 */
	void AddTypeWithOption();

	/**
	 * Adds a format with the supported type.
	 */
	CATBoolean AddType(const CATMMediaImageFileType iType);

	/**
	 * Removes a format with the supported type.
	 */
	CATBoolean DelType(const CATMMediaImageFileType iType);

	CATBoolean IsEmpty() const { return (NULL == _paFirst); }

	~CATMMediaImageFileFormatList();

	// --- formats info ---
	int GetCount() const { return _nItems; }
	int GetIndex(const CATMMediaImageFileType iType) const;

	CATMMediaImageFileType GetType(const int iIndex) const;
	CATMMediaImageFileBPP GetFilter(const int iIndex) const;
	CATBoolean HasQuality(const int iIndex) const;
	const char * GetName(const int iIndex) const;
	const char * GetDescription(const int iIndex) const;
	const char * GetExtension(const int iIndex) const;

	// --- options ---
	int GetOptionCount(const int iIndex) const;
	CATMMediaImageFileCompression GetOptionCompression(int iIndex, const int iOption) const;
	CATMMediaImageFileBPP GetOptionFilter(int iIndex, const int iOption) const;
	const char * GetOptionDescription(const int iIndex, const int iOption) const;
	CATBoolean HasOptionQuality(const int iIndex, const int iOption) const;

private:
	TFormatInterface * GetFormat(const int iIndex) const;
	CATBoolean InsertNew(const CATMMediaImageFileType iType);

	const CATBoolean	_bRead;
	int					_nItems;
	TFormatInterface	*_paFirst;	// linked list
	TFormatInterface	*_prLast;
};


//============================================================================
//	class CATMMediaImageFileManager as a namespace
//============================================================================
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileManager
{
public:
	//-------------------------------------------------------------
	//	Getting informations from filename string
	//-------------------------------------------------------------
	/*
	 * Retrieves file extension from filename
	 */
	static CATUnicodeString GetFileExtension(const CATUnicodeString& iFilename);

	/*
	 * Retrieves raster file type from file extension
	 */
	static CATMMediaImageFileType GetTypeFromExtension(const CATUnicodeString& iExtension);

	/*
	 * Retrieves raster file type from filename string
	 */
	static CATMMediaImageFileType GetTypeFromFilename(const CATUnicodeString& iFilename)
		{ const CATUnicodeString Extension = GetFileExtension(iFilename);	return GetTypeFromExtension(Extension); }

	/*
	 * Retrieves extension  supported for a file type
	 */
	static CATUnicodeString GetExtension(const CATMMediaImageFileType iType);

	//-------------------------------------------------------------
	//	Getting informations from file
	//-------------------------------------------------------------
	/*
	 * Retrieves image file informations
	 */
	static HRESULT GetInfo(const CATUnicodeString& iFilename, CATMMediaImageFileInfo& oInfo);

	/*
	 * Retrieves the number of pages stored in a raster file
	 */
	static int GetPages(const CATUnicodeString& iFilename);

	/*
	 * Retrieves if the raster file is composed with tiles
	 */
	static CATBoolean IsTiled(const CATUnicodeString& iFilename);


	//-------------------------------------------------------------
	//	Getting strings for dialogs
	//-------------------------------------------------------------
	/*
	 * Retrieves a CATUnicodeString of raster file type
	 */
	static CATUnicodeString GetTypeString(const CATMMediaImageFileType iType);
	static CATUnicodeString GetTypeString(const CATUnicodeString& iFilename)
		{ return GetTypeString( GetTypeFromFilename(iFilename) ); }

	/*
	 * Retrieves a CATUnicodeString of raster file compression
	 */
	static CATUnicodeString GetCompressionString(const CATMMediaImageFileCompression iCompression);


	//-------------------------------------------------------------
	//
	//-------------------------------------------------------------
	/*
	 * Generic write
	 */
	static HRESULT Write(
			const CATPixelImage& iPixelImage,
			const CATUnicodeString& iFilename,
			const CATMMediaImageFileType iType = MMIFT_UNKNOW,
			CATMMediaImageFileOption * const iprOption = NULL,
		    bool endFlag = false);

private:
	static void SetupSystemInfo(const char * const iprFilename, CATMMediaImageFileInfo& oInfo);

	// useless default methods intentionally not accessible (and not generated):
    CATMMediaImageFileManager();
    CATMMediaImageFileManager(const CATMMediaImageFileManager&);
    ~CATMMediaImageFileManager();
    CATMMediaImageFileManager& operator=(const CATMMediaImageFileManager&);
    CATMMediaImageFileManager * operator&();
    const CATMMediaImageFileManager * operator&() const;
};

#endif // CATMMediaImageFileManager_H
