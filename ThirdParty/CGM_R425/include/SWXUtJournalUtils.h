//===================================================================
// COPYRIGHT Dassault Systemes 2014/01/24
//===================================================================
// SWXUtJournalUtils.cpp
// Header definition of class SWXUtJournalUtils
//===================================================================
//
// Usage notes:
// Created by IZO - as placeholder for common utility functions 
// Please feel free to move to a more appropriate place or mechanism
//===================================================================
//  2014/01/24 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtJournalUtils_H
#define SWXUtJournalUtils_H

#include "SWXUtJournal.h"
#include "SWXUtMacForOverride.h"

class CATListValCATUnicodeString;
class CATMathPoint;
class CATUnicodeString;
class CATMathTransformation;
//-----------------------------------------------------------------------

class ExportedBySWXUtJournal SWXUtJournalUtils
{
public:

	static void PointToString(const CATMathPoint &iPoint, CATUnicodeString &oString);
	static void StringToPoint(const CATUnicodeString &iX, const CATUnicodeString &iY, const CATUnicodeString &iZ, CATMathPoint &oPoint);
	static void StringToPoint(const CATUnicodeString &iCoordString, CATMathPoint &oPoint);
	static void TransformationToString(const CATMathTransformation &iTransformation, CATUnicodeString &oString);

	static bool WriteNum(const CATUnicodeString &iLabelStr, double iValue, CATListValCATUnicodeString &ioStrings);
	static bool WriteText(const CATUnicodeString &iLabelStr, const CATUnicodeString &iValueStr, CATListValCATUnicodeString &ioStrings);
	static bool WritePoint(const CATUnicodeString &iLabelStr, const CATMathPoint &iValue, CATListValCATUnicodeString &ioStrings);

	static CATUnicodeString CreateValidationString( const char* iKey, const CATUnicodeString& iValue, const CATUnicodeString& iSeparator );
	static bool ParseValidationString( const CATUnicodeString& iSource, const CATUnicodeString& iSeparator, CATUnicodeString& oKey, CATUnicodeString& oValue );

private:
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtJournalUtils ();
	virtual ~SWXUtJournalUtils ();

	// Copy constructor and equal operator
	// -----------------------------------
	SWXUtJournalUtils (SWXUtJournalUtils &);
	SWXUtJournalUtils& operator=(SWXUtJournalUtils&);
};

//-----------------------------------------------------------------------

#endif
