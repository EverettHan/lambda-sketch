//===================================================================
// COPYRIGHT DS SolidWorks 2010/08/06
//===================================================================
// SWXUtParamName.cpp
// Header definition of class SWXUtParamName
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/08/06 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtParamName_H
#define SWXUtParamName_H

#include "SWXUtBasePacket.h"

#include "CATUnicodeString.h"
#include "CATString.h"

//-----------------------------------------------------------------------

class ExportedBySWXUtBasePacket SWXUtParamName
{
public:
	SWXUtParamName ();
	//SWXUtParamName (const CATString &iCatalog, const CATString & iKey);
	explicit SWXUtParamName (const CATUnicodeString &iName);
	virtual ~SWXUtParamName ();

	const CATUnicodeString &GetName() const;

private:
	// Copy constructor and equal operator autogenerated
	CATUnicodeString mName;
};

//-----------------------------------------------------------------------

#endif
