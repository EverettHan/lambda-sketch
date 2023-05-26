//===================================================================
// COPYRIGHT DS SolidWorks 2010/07/20
//===================================================================
// SWXUtDebugVariable.cpp
// Header definition of class SWXUtDebugVariable
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/07/20 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtDebugVariable_H
#define SWXUtDebugVariable_H

#include "SWXUtDebugging.h"

#include "CATUnicodeString.h"

class SWXUtDebugVariableBool;
class SWXUtDebugVariableInt;
class SWXUtDebugVariableDouble;
class SWXUtDebugVariableString;
class CATListPtrSWXUtDebugVariable;

typedef void (*CallBackType)();
//Debug variables beginning with this string will never be permanently set and will be reset each time you start the debug var component. 
static const CATUnicodeString s_DebugVolatile("DebugVolatile");

//-----------------------------------------------------------------------

class ExportedBySWXUtDebugging SWXUtDebugVariable
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	SWXUtDebugVariable (const CATUnicodeString &iName, const CATUnicodeString &iFile, int iLine);
	virtual ~SWXUtDebugVariable ();

	const CATUnicodeString &GetName();

	virtual SWXUtDebugVariableBool *ToDbgBool();
	virtual SWXUtDebugVariableInt  *ToDbgInt();
	virtual SWXUtDebugVariableDouble *ToDbgDouble();
	virtual SWXUtDebugVariableString *ToDbgString();

	virtual void CallCallBack();

	virtual CATUnicodeString GetValueString() const = 0;
	virtual void SetValueString(const CATUnicodeString &iValueStr, bool iStore = true) = 0;

	CATUnicodeString GetFile() const;
	int GetLine() const;
	CATUnicodeString GetLocation() const;
	
	// Does this still have its default value?
	virtual bool IsDefault() const = 0;
	// Reset to default value
	virtual void ResetValue(bool iStore=true) = 0;

	void Register();
	void Unregister();
	static SWXUtDebugVariable *GetByName(const CATUnicodeString &iName);
	static void GetAll(CATListPtrSWXUtDebugVariable &oAllVariables);

    static bool GetValue(const CATUnicodeString &iName, bool &oValue);
    static bool SetValue(const CATUnicodeString &iName, bool iValue, bool iStore = true);
    static bool GetValue(const CATUnicodeString &iName, int &oValue);
    static bool SetValue(const CATUnicodeString &iName, int iValue, bool iStore = true);
    static bool GetValue(const CATUnicodeString &iName, double &oValue);
    static bool SetValue(const CATUnicodeString &iName, double iValue, bool iStore = true);
    static bool GetValue(const CATUnicodeString &iName, CATUnicodeString &oValue);
    static bool SetValue(const CATUnicodeString &iName, const char *iValue, bool iStore = true);
    static bool SetValue(const CATUnicodeString &iName, CATUnicodeString const &iValue, bool iStore = true);
	
	//Just a void type method. 
	CallBackType GetCallBack() { return mCallBack; }
	void SetCallBack(CallBackType iCallBack, bool iExecuteOnChange = false);//If false, will be called only on DebugVar dialog closed. If true, on every change of this Debug value. 

	bool GetExecuteOnChange() { return mExecuteOnChange; }

	// For testing: we want to use real default values
	static void SetTesting();

private:
	CATUnicodeString mName;
	CATUnicodeString mFile;
	int mLine;
	CallBackType mCallBack;
	bool mExecuteOnChange;
	





	// Copy constructor and equal operator
	// -----------------------------------
	SWXUtDebugVariable (SWXUtDebugVariable &);
	SWXUtDebugVariable& operator=(SWXUtDebugVariable&);

};

#include "SWXUtDebugVariableBool.h"
#include "SWXUtDebugVariableInt.h"
#include "SWXUtDebugVariableDouble.h"
#include "SWXUtDebugVariableString.h"



//-----------------------------------------------------------------------
// Putting this here because I REALLY HATE TRYING TO FIND THE HEADERS FOR THESE
#include "CATLISTP_Clean.h"
#include "CATLISTP_AllFunct.h"
#include "CATLISTP_Declare.h"

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define	CATCOLLEC_ExportedBy ExportedBySWXUtDebugging

CATLISTP_DECLARE(SWXUtDebugVariable)

//-----------------------------------------------------------------------

#endif
