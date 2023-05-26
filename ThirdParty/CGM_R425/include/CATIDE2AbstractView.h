//===================================================================

//===================================================================
// CATIDE2AbstractView.cpp
// Header definition of class CATIDE2AbstractView
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013-04-23 Creation by Q62: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIDE2AbstractView_H
#define CATIDE2AbstractView_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATSYPHashMap.h"

extern ExportedByCATAfrItf  IID IID_CATIDE2AbstractView ;

class CATCommand;
class CATDialogAgent;

class ExportedByCATAfrItf CATIDE2AbstractView: public CATBaseUnknown
{
	CATDeclareInterface;

	public:

		typedef CATSYPHashMap<CATUnicodeString, CATUnicodeString>* HashMapDE2;

		/* Verify if the view the graph wants to control exist, otherwise build it from the list of file name (if provided). 
		Return a pointer to the wiev in case of existing of building successfully the view. Return NULL  otherwise.*/
		virtual HRESULT ControlView(CATUnicodeString iViewId, HashMapDE2 ipFilesListForViewInstanciation,CATBaseUnknown* ipDE2DataModel) = 0;

		/*Do the necassary to listen to the Event iEventName on the view element iSenderDeclarativePath with a DialogAgent
		Return the dialogagent built to listen if succeeded, NULL otherwise
		CAUTION: The CATDialogAgent* returned has to be Add Ref'ed!!!*/
		virtual CATBoolean ListenEventOnObject(CATUnicodeString iSenderDeclarativePath, CATUnicodeString iEventName, CATString iListenningAgentId, CATDialogAgent** ippListenningAgent) = 0;

		/*Try to get a view object instance by it name.
		Return the view object instance if found, NULL otherwise*/
		virtual CATBaseUnknown* RetrieveObjectByName(CATUnicodeString iObjectName) = 0;
};

//-----------------------------------------------------------------------

#endif
