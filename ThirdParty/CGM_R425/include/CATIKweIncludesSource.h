//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/07/24
//===================================================================
// CATIKweIncludesSource.cpp
// Header definition of class CATIKweIncludesSource
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/07/24 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIKweIncludesSource_H
#define CATIKweIncludesSource_H

#include "KnowledgeItfCPP.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

extern ExportedByKnowledgeItfCPP  IID IID_CATIKweIncludesSource;

class CATUnicodeString;
class CATIKweResourceTableProvider_var;
class CATIKweFunctionsProvider_var;
class ExportedByKnowledgeItfCPP CATIKweIncludesSource : public CATBaseUnknown
{
	CATDeclareInterface;

public:
	// Finds an included library and parses it
	// The returned object implement CATIKweFunctionsProvider
	// The name is misleading : now it's supported by KML libraries that provides concept types
	// and by Know how Apps components that provides udf types
	virtual CATBaseUnknown_var FindAndParse(const CATUnicodeString &iName, CATListOfCATUnicodeString &ioIncludesLogicalName, CATLISTV(CATBaseUnknown_var) &ioAlreadyDoneIncludes, CATBoolean iOnlyKMLTypes = FALSE) = 0;

	// used to prefix functions in language browser
	virtual CATUnicodeString FindIdOfProvider(const CATUnicodeString &iLogicalName) = 0;

	// Provides the local resource table
	virtual void SetTablesProvider(const CATIKweResourceTableProvider_var &iProvider) = 0;

	// Removes things declared in include from the dico
	virtual void CleanDico(const CATLISTV(CATBaseUnknown_var) &iIncludedLibs) = 0;

	// Next four methods are used to pass include information from main expression to sub expressions
	// for example when using Query(type, expression). The included functions can be used in expression.
	// Auto include is also used in know how libraries to support auto inclusion (a function can use another function of the library without an explicit include)
	virtual void DoAutoIncludes(CATListOfCATUnicodeString &ioIncludesLogicalName, CATLISTV(CATBaseUnknown_var) &ioIncludedLibs) = 0;
	virtual void SetAutoIncludes(const CATListOfCATUnicodeString &iNames, const CATLISTV(CATBaseUnknown_var) &iToInclude) = 0;
	virtual void GetAutoIncludes(CATListOfCATUnicodeString &oNames, CATLISTV(CATBaseUnknown_var) &oLibs) = 0;
	// returns the included libs in current context
	virtual void GetIncludedLibs(CATListOfCATUnicodeString &oNames, CATLISTV(CATBaseUnknown_var) &oLibs) = 0;

	// Finds the libraries available in current context
	// in order to show their content in language browser
	virtual void GetAllIncludableLibs(CATListOfCATUnicodeString &oIncludableLibs) = 0;


	// Finds a functions/types provider from its name
	virtual CATBaseUnknown_var FindProviderFromName(const CATUnicodeString &iName) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIKweIncludesSource, CATBaseUnknown);

#endif
