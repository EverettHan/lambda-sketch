//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2011/10/24
//===================================================================
// CATFreeTypeFactory.cpp
// Header definition of class CATFreeTypeFactory
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/10/24 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATFreeTypeFactory_H
#define CATFreeTypeFactory_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATFreeType.h"
#include "CATUnicodeString.h"
#include "CATString.h"


#ifdef VISU_ENABLE_FREETYPE
typedef struct FT_LibraryRec_* FT_Library;  
#endif // VISU_ENABLE_FREETYPE

class CATFreeTypeFace;
class CATFreeTypeFontFile;
class CATFreeTypeFontCollection;
class CATFreeTypeTextFormat;
//-----------------------------------------------------------------------

class ExportedBySGInfra CATFreeTypeFactory: public CATBaseUnknown
{
	friend HRESULT CATFreeType::CreateFreeTypeFactory(CATFreeTypeFactory** oFactory);

public:
	//! Create a font face from a font file and index into the file (usually 0)
	HRESULT CreateFace(CATFreeTypeFontFile* iFile, int index, CATFreeTypeFace** oFace);
	
	//! Create a freetype font file from a font file in disk (file will be empty if filepath is NULL)
	HRESULT CreateFontFile(CATUnicodeString const& iFilePath, CATFreeTypeFontFile** oFile);

	//! Create a new collection of freetype fonts
	HRESULT CreateFontCollection(CATFreeTypeFontCollection** oFontCollection);

	//! Create a text format
	HRESULT CreateTextFormat(CATFreeTypeFace* iFace, CATFreeTypeTextFormat** oTextFormat);


private:
	HRESULT CreateLibrary();

private:
	CATFreeTypeFactory ();
	virtual ~CATFreeTypeFactory ();
	CATFreeTypeFactory (CATFreeTypeFactory &);
	CATFreeTypeFactory& operator=(CATFreeTypeFactory&);

#ifdef VISU_ENABLE_FREETYPE
private:
	FT_Library _library;  
#endif // VISU_ENABLE_FREETYPE

};

//-----------------------------------------------------------------------

#endif
