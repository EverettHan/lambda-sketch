//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/05/03
//===================================================================
// SWXUtKeyboardHook.cpp
// Header definition of class SWXUtKeyboardHook
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/05/03 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtKeyboardHook_H
#define SWXUtKeyboardHook_H

#include "SWXUtGeneral.h"

class CATUnicodeString;

//-----------------------------------------------------------------------

class ExportedBySWXUtGeneral SWXUtKeyboardHook
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtKeyboardHook ();
	virtual ~SWXUtKeyboardHook ();

	void RegisterCallback(void *iFromComp, void (*iCallback)(void *iFromComp, const CATUnicodeString &iCmd));

	static void GetClipboard(CATUnicodeString &oStr);
	static void SetClipboard(const CATUnicodeString &iStr);

	static bool GetCompositionString(CATUnicodeString &oStr);
	static bool SetCompositionString(const CATUnicodeString &iStr);
	static void ResetCompositionString();

	static int GetInputLanguage();
	static void EnableTabHook(bool iEnable);

private:
	// Copy constructor and equal operator
	// -----------------------------------
	SWXUtKeyboardHook (SWXUtKeyboardHook &);
	SWXUtKeyboardHook& operator=(SWXUtKeyboardHook&);
};

//-----------------------------------------------------------------------

#endif
