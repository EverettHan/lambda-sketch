//----------------------------------------------------------------------------
//	CATMMediaImageFileInfo.h
//----------------------------------------------------------------------------
//	Creation by CPG
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
#ifndef CATMMediaImageFileInfo_H
#define CATMMediaImageFileInfo_H

//#include "CATMMediaRasterFormats.h"
#include "CATMMediaRasterFormats_SB_File.h"
#include "CATMMediaImageFileDef.h"
#include "CATBoolean.h"
#include "CATTime.h"

class CATString;
class CATUnicodeString;
class CATMMediaImageFilePageInfo;

//class ExportedByCATMMediaRasterFormats CATMMediaImageFileInfo
class ExportedByCATMMediaRasterFormats_SB_File CATMMediaImageFileInfo
{
public:
    CATMMediaImageFileInfo();
	CATMMediaImageFileInfo(const CATUnicodeString& iFilename);
	virtual ~CATMMediaImageFileInfo();

	// --- System informations ---
	CATUnicodeString GetName() const						{ return _Name; }
	CATUnicodeString GetPath() const						{ return _Path; }
	CATUnicodeString GetExtension() const					{ return _Extension; }
	long GetFileSize() const								{ return _FileSize; }
	CATBoolean IsReadOnly() const							{ return _bReadOnly; }
	CATTime GetTime() const									{ return _Time; }
	CATUnicodeString GetTimeString() const					{ return _TimeString; }

	// --- Image informations ---
	CATMMediaImageFileType GetType() const					{ return _Type; }
	CATUnicodeString GetTypeString() const					{ return _TypeString; }

	CATMMediaImageFileCompression GetCompression() const	{ return _Compression; }
	CATUnicodeString GetCompressionString() const			{ return _CompressionString; }

	long GetUncompressedSize() const						{ return _UncompressedSize; }
	float GetCompressionRatio() const;

	// --- Page informations ---
	int GetPages() const									{ return _nPage; }
	const CATMMediaImageFilePageInfo * GetPage(const int iPage) const;

	int GetWidth(const int iPage) const;
	int GetHeight(const int iPage) const;
    long GetXdpi(const int iPage) const;
	long GetYdpi(const int iPage) const;
	float GetRatio(const int iPage) const;
	int HasMetric(const int iPage) const;
	float GetWidthInInch(const int iPage) const;
	float GetHeightInInch(const int iPage) const;
	float GetWidthInMm(const int iPage) const;
	float GetHeightInMm(const int iPage) const;
	int GetPageSize(const int iPage) const;
	int GetBitPerPixel(const int iPage) const;
	CATBoolean IsTiled(const int iPage) const;

private:
	// useless default methods intentionally not accessible (and not generated):
    CATMMediaImageFileInfo(const CATMMediaImageFileInfo&);
	CATMMediaImageFileInfo& operator=(const CATMMediaImageFileInfo&);
    CATMMediaImageFileInfo * operator&();
    const CATMMediaImageFileInfo * operator&() const;

	friend class CATMMediaImageFileManager;

	void Reset();

	// --- System informations ---
	void SetupFilename(const CATUnicodeString& iFilename);
	void SetFileSize(const int iSize)						{ _FileSize = iSize; }
	void SetReadOnly(const CATBoolean ibReadOnly)			{ _bReadOnly = ibReadOnly; }
	void SetTime(const CATTime& iTime)						{ _Time = iTime; }
	void SetTimeString(const CATUnicodeString& iTimeString)	{ _TimeString = iTimeString; }

	// --- Image informations ---
	void SetupType(const CATMMediaImageFileType iType);
	void SetupCompression(const CATMMediaImageFileCompression iCompression);
	void SetUncompressedSize(const long iUncompressedSize)	{ _UncompressedSize = iUncompressedSize; }

	// --- Page informations ---
	void CreatePages(const int iPages);
	void RemovePages();
	void SetWidth(const int iPage, const int iWidth);
	void SetHeight(const int iPage, const int iHeight);
	void SetXdpi(const int iPage, const long iXdpi);
	void SetYdpi(const int iPage, const long iYdpi);
	void SetBitPerPixel(const int iPage, const int iBitPerPixel);
	void SetTiled(const int iPage, const CATBoolean bTiled);


	// --- datas ---

	// --- System informations ---
	CATUnicodeString	_Name;
	CATUnicodeString	_Path;
	CATUnicodeString	_Extension;
	int					_FileSize;
	CATBoolean			_bReadOnly;
	CATUnicodeString	_TimeString;
	CATTime				_Time;

	// --- Image informations ---
	long							_UncompressedSize; // = somme des PageSizes

	CATMMediaImageFileType			_Type;
	CATUnicodeString				_TypeString;

	CATMMediaImageFileCompression	_Compression;
	CATUnicodeString				_CompressionString;

	int								_nPage;
	CATMMediaImageFilePageInfo		**_ppaPage;
};

#endif // CATMMediaImageFileInfo_H
