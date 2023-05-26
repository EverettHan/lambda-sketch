//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2013
//===================================================================
// SWXEUtFilterCheck.cpp
// Header definition of adaptor class for interface
//    SWXIUtFilterCheck
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef SWXEUtFilterCheck_H
#define SWXEUtFilterCheck_H

#include "SWXUtGeneral.h"
#include "SWXUtMacForOverride.h"
#include "SWXIUtFilterCheck.h"

#include "CATBaseUnknown.h"
#include "SWXUtVector.h"

class CATIPLMComponent;
class CATPathElement;
class CATUnicodeString;
class SWXUtCursorContent;
class SWXUtOperationContext;

//-----------------------------------------------------------------------

class ExportedBySWXUtGeneral SWXEUtFilterCheck: public SWXIUtFilterCheck
{
public:
	SWXEUtFilterCheck();
	virtual ~SWXEUtFilterCheck();

	virtual bool Check(const CATUnicodeString & iCheckName, CATPathElement * iPE, SWXUtOperationContext * iContext = NULL, const SWXUtVector<CATPathElement *> * iCurrentSel = NULL, const bool iAllowOutofContextPath = true) override;

	virtual bool MethodExists(const CATUnicodeString & iCheckName) override;

	virtual bool GetFilterCursor(CATPathElement * iPE, SWXUtOperationContext * iContext, int iCursorContentType, SWXUtCursorContent * iCursor) override;

	/**
	* PreProcessPath
	* @param oNewPE [out, IUnknown#Release] 
	*/
	virtual bool PreProcessPath(const CATUnicodeString & iMethodName, CATPathElement * iPE, SWXUtOperationContext * iContext, CATPathElement *& oNewPE) override;

	virtual void GetRelativePriority(SWXUtVector<CATPathElement *> & iPathElements, SWXUtVector<int> & oPriorities, SWXUtOperationContext * iContext) override;

	virtual CATBaseUnknown_var GetSOInContext(const CATUnicodeString & iMethodName, CATPathElement * iPe, CATIPLMComponent * iActiveProduct, CATPathElement * iSelectedContext, CATBaseUnknown_var ispSelection) override;

private:
	// Not implemented
	SWXEUtFilterCheck(SWXEUtFilterCheck&);
	SWXEUtFilterCheck& operator=(SWXEUtFilterCheck&);
};

//-----------------------------------------------------------------------

#endif

