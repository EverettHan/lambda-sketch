#ifndef __CATEditingContext_h
#define __CATEditingContext_h	


// COPYRIGHT DASSAULT SYSTEMES 2000


#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATString.h"
#include "CATAfrFoundation.h"
#include "CATEventSubscriber.h"
#include "CATCommand.h"


#ifndef CNEXT_CLIENT
#include "CATTraMacro.h"
TRAINIT (EditContext, "Editing context traces");
#define EPrint(t)\
	if (Tra_EditContext.IsActive ())\
		Tra_EditContext.TraPrint t
#else
#define EPrint(t)
#endif


class l_CATEditingContext;
class CATFrmEditor;
class CATCommandHeader;


class ExportedByCATAfrFoundation CATEditingContext: public CATEventSubscriber {

	CATDeclareClass;

public:

  CATEditingContext  (CATFrmEditor *);
	virtual ~CATEditingContext ();

	const CATString & GetCurrentWorkshop () const;
	const CATString & GetCurrentWorkbench () const;

	CATCommandHeader * GetHeaderFromList (const CATString & iHeaderId, CATBoolean iForceLoad = FALSE);
	CATFrmEditor     * GetEditor         ();

	l_CATEditingContext * GetLetter ();
	
  CATDeclareCBEvent(DestroyEvent);

protected:
	
	l_CATEditingContext * _letter;
	
};

#endif//__CATEditingContext_h
