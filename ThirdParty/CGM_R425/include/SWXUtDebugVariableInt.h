#pragma once

#include "SWXUtDebugging.h"

#include "CATUnicodeString.h"

#include "SWXUtDebugVariable.h"


class ExportedBySWXUtDebugging SWXUtDebugVariableInt : public SWXUtDebugVariable
{
public:
	typedef SWXUtDebugVariable base_class;
	typedef int value_type;
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtDebugVariableInt (const CATUnicodeString &iName, int iValue, const CATUnicodeString &iFile, int iLine);
	virtual ~SWXUtDebugVariableInt ();

	int GetValue() const;
	void SetValue(int iValue, bool iStore = true);

	CATUnicodeString GetValueString() const;
	void SetValueString(const CATUnicodeString &iValueStr, bool iStore = true);
	bool IsDefault() const;
	void ResetValue(bool iStore=true);

	virtual SWXUtDebugVariableInt *ToDbgInt();

	operator int() const;
	int operator=(int iValue);

private:
	int mValue;
	int mDefaultValue;
};


#define SWX_DEBUGVARINT_DEF(NAME, VAR, DEF) \
	SWXUtDebugVariableInt VAR( NAME, DEF, __FILE__, __LINE__);

#define SWX_DEBUGVARINT(NAME, VAR) \
	SWXUtDebugVariableInt VAR( NAME, 0, __FILE__, __LINE__);


