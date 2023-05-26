#pragma once

#include "SWXUtDebugging.h"

#include "CATUnicodeString.h"

#include "SWXUtDebugVariable.h"


class ExportedBySWXUtDebugging SWXUtDebugVariableBool : public SWXUtDebugVariable
{
public:
	typedef SWXUtDebugVariable base_class;
	typedef bool value_type;

	// Standard constructors and destructors
	// -------------------------------------
	SWXUtDebugVariableBool (const CATUnicodeString &iName, bool iValue, const CATUnicodeString &iFile, int iLine);
	virtual ~SWXUtDebugVariableBool ();

	bool GetValue() const;
	void SetValue(bool iValue, bool iStore = true);

	CATUnicodeString GetValueString() const;
	void SetValueString(const CATUnicodeString &iValueStr, bool iStore = true);
	bool IsDefault() const;
	void ResetValue(bool iStore=true);

	virtual SWXUtDebugVariableBool *ToDbgBool();

	operator bool() const;
	bool operator=(bool iValue);

private:
	bool mValue;
	bool mDefaultValue;
};


#define SWX_DEBUGVARBOOL_DEF(NAME, VAR, DEF) \
	SWXUtDebugVariableBool VAR( NAME, DEF, __FILE__, __LINE__);

#define SWX_DEBUGVARBOOL(NAME, VAR) \
	SWXUtDebugVariableBool VAR( NAME, false, __FILE__, __LINE__ );


