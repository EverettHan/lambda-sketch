#pragma once

#include "SWXUtDebugging.h"

#include "CATUnicodeString.h"

#include "SWXUtDebugVariable.h"


class ExportedBySWXUtDebugging SWXUtDebugVariableDouble : public SWXUtDebugVariable
{
public:
	typedef SWXUtDebugVariable base_class;
	typedef double value_type;
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtDebugVariableDouble (const CATUnicodeString &iName, double iValue, const CATUnicodeString &iFile, int iLine);
	virtual ~SWXUtDebugVariableDouble ();

	double GetValue() const;
	void SetValue(double iValue, bool iStore = true);

	CATUnicodeString GetValueString() const;
	void SetValueString(const CATUnicodeString &iValueStr, bool iStore = true);
	bool IsDefault() const;
	void ResetValue(bool iStore=true);

	virtual SWXUtDebugVariableDouble *ToDbgDouble();

	operator double() const;
	double operator=(double iValue);

private:
	double mValue;
	double mDefaultValue;
};



#define SWX_DEBUGVARDOUBLE_DEF(NAME, VAR, DEF) \
	SWXUtDebugVariableDouble VAR( NAME, DEF, __FILE__, __LINE__);

#define SWX_DEBUGVARDOUBLE(NAME, VAR) \
	SWXUtDebugVariableDouble VAR( NAME, 0.0, __FILE__, __LINE__);


