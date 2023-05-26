#ifndef CATEditTranslateHeader_h
#define CATEditTranslateHeader_h
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 1998
//
// Command header for translation editing in Select command
//-----------------------------------------------------------------------------
#include "CATAfrFoundation.h"
#include "CATCommandHeader.h"
#include "CATLISTP_CATBaseUnknown.h"

class ExportedByCATAfrFoundation CATEditTranslateHeader : public CATCommandHeader

{
  CATDeclareClass;
  CATDeclareHeaderResources;
  
 public:

  CATEditTranslateHeader(const CATString & HeaderID,
			  const CATString & loadName,
			  const CATString & classname,
			  void * argument,
			  int state = CATFrmAvailable);

  
  virtual ~CATEditTranslateHeader ();
  
  virtual CATCommandHeader * Clone ();

  void SetAgentList(CATLISTP(CATBaseUnknown) * AgentList);
  CATLISTP(CATBaseUnknown) * GetAgentList();

  void SetSelectedAgentIndex(int Index);
  int GetSelectedAgentIndex();

  void SetSelectCommand(CATCommand * Command);
  CATCommand * GetSelectCommand();

  void HoldCommand();
  void QueryStopCommand();

  CATDeclareCBEvent(SelectCommandChangedEvent);
  CATDeclareCBEvent(HoldManipPanelEvent);

 protected:

  CATEditTranslateHeader (CATCommandHeader * header);
  
 private:

  void Init();

  CATLISTP(CATBaseUnknown) * _AgentList;
  int _SelectedAgentIndex;
  CATCommand * _SelectCommand;
  int _hold;
};

#endif
