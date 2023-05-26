//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2013/01/10
//===================================================================
// SWXUtDbText.cpp
// Header definition of class SWXUtDbText
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/01/10 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtDbText_H
#define SWXUtDbText_H

#include "SWXUtGeneral.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------
//
// Read or write text to a plm document
//
//-----------------------------------------------------------------------

class ExportedBySWXUtGeneral SWXUtDbText
{
public:
	static HRESULT ReadText(const CATUnicodeString &iExternalID, CATUnicodeString &oText);
	static HRESULT WriteText(const CATUnicodeString &iExternalID, const CATUnicodeString &iText);
	static HRESULT WriteFileToDB(const CATUnicodeString &iExternalID, const CATUnicodeString &iFilename);
	static HRESULT WriteFileToDisk(const CATUnicodeString &iExternalID, const CATUnicodeString &iFilename);
};

//-----------------------------------------------------------------------

#endif