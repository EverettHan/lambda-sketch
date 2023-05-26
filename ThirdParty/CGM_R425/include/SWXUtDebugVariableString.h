#pragma once

#include "SWXUtDebugging.h"

#include "CATUnicodeString.h"

#include "SWXUtDebugVariable.h"


class ExportedBySWXUtDebugging SWXUtDebugVariableString : public SWXUtDebugVariable
{
public:
	typedef SWXUtDebugVariable base_class;
	typedef const CATUnicodeString value_type;
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtDebugVariableString (const CATUnicodeString &iName, const CATUnicodeString & iValue, const CATUnicodeString &iFile, int iLine);
	virtual ~SWXUtDebugVariableString ();

	const CATUnicodeString & GetValue() const;
	void SetValue(const CATUnicodeString & iValue, bool iStore = true);

	CATUnicodeString GetValueString() const;
	void SetValueString(const CATUnicodeString &iValueStr, bool iStore = true);
	bool IsDefault() const;
	void ResetValue(bool iStore=true);

	virtual SWXUtDebugVariableString *ToDbgString();

	operator const CATUnicodeString &() const;
	const CATUnicodeString & operator=(const CATUnicodeString & iValue);

private:
	CATUnicodeString mValue;
	CATUnicodeString mDefaultValue;
};





#define SWX_DEBUGVARSTRING_DEF(NAME, VAR, DEF) \
	SWXUtDebugVariableString VAR( NAME, DEF, __FILE__, __LINE__);

#define SWX_DEBUGVARSTRING(NAME, VAR) \
	SWXUtDebugVariableString VAR( NAME, CATUnicodeString(), __FILE__, __LINE__);


