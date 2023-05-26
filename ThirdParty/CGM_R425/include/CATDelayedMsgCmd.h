/**
 * @level Protected
 * @usage U1
 */

// COPYRIGHT DASSAULT SYSTEMES  2001
//=============================================================================
//
// CATDelayedMsgCmd.h
//
//=============================================================================
// Usage Notes: This command allows to store messages. A callback on idle is put
// to show this messages in a dialog when. You can get an instance of this command
//
// 
//
//
//=============================================================================
// 2/2/01   Creation                                   T. Videcoq
//=============================================================================

#ifndef __CATDelayedMsgCmd__
#define __CATDelayedMsgCmd__

#include "CATCommand.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATUnicodeString.h"
#include "CATDataType.h"

#include "CATLifDictionary.h"

class ExportedByCATLifDictionary CATDelayedMsgCmd : public CATCommand
{
public:
	CATDelayedMsgCmd();
	~CATDelayedMsgCmd();

	static void ShowMessagesPanel(CATCommand *client, int state, void *clientData);

	void AddMessage(const CATUnicodeString &message, const CATUnicodeString &from, const CATUnicodeString &summary, const CATUnicodeString &type, int popup = 0, const CATUnicodeString &stringForFilter = "", CATINTPTR adressForFilter = 0, int msgNotShown = 0);

	static CATListOfCATUnicodeString * GetMessages();
	static CATListOfCATUnicodeString * GetFroms();
	static CATListOfCATUnicodeString * GetSummarys();
	static CATListOfCATUnicodeString * GetTypes();
	static CATListOfInt *GetInPopupsFlag();

	static void Clean();

	static void RemoveDuplicates();

	static void UseExistingPanel();

	static void SetNoMultiMsgPanelMode(int noPanel);

	 CATCallbackEvent GetNewMessageNotification() const ;

	 CATCallbackEvent GetCommandKilledNotification () const;

	 void Kill();

//	 void AppendRelationToRestore(const CATBaseUnknown_var &relation);

//	 static void RestoreRelations(CATCommand *client, int state, void *clientData);

private:
	CATDefineCBEvent(NewMessage)
	CATDefineCBEvent(CommandKilled)

	CATDeclareClass;

	static CATListOfCATUnicodeString _Messages;
	static CATListOfCATUnicodeString _Froms;
	static CATListOfCATUnicodeString _Summarys;
	static CATListOfCATUnicodeString _Types;
	static int _DialogAsked;
	static int _UseExistingPanel;
	static CATListOfCATUnicodeString _StringsForFilter;
	static CATListPV _AdressForFilter;
	static CATListOfInt _NotShownMessages;
	static CATListOfInt _InPopups;
	static int _NoMultiMsgPanel;

	static CATLISTV(CATBaseUnknown_var) _ListRelations;
	static int _RestoreAsked;
};

#endif








