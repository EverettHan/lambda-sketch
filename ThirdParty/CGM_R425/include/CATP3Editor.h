// COPYRIGHT DASSAULT SYSTEMES 2002
// 17.Oct.2002 RST : created

#ifndef CATP3Editor_H
#define CATP3Editor_H

#include "CATAfrFoundation.h"
#include "CATEventSubscriber.h"
#include "CATCommandSelector.h"

class l_CATP3Editor;
class CATFrmEditor;

class ExportedByCATAfrFoundation CATP3Editor : public CATEventSubscriber
{
  CATDeclareClass;
  
public:

  CATDeclareCBEvent(EnableP3Commands);
  CATDeclareCBEvent(DisableP3Commands);
  CATDeclareCBEvent(DestroyP3Commands);
  CATDeclareCBEvent(P3Undo);
  CATDeclareCBEvent(P3Redo);
  CATDeclareCBEvent(P3Commit);
  CATDeclareCBEvent(P3RequestTransaction);
  CATDeclareCBEvent(P3BeginTransaction);
  CATDeclareCBEvent(P3DeclineTransaction);
  CATDeclareCBEvent(P3DoTransaction);
  CATDeclareCBEvent(P3EndTransaction);
  CATDeclareCBEvent(P3Update);
  CATDeclareCBEvent(P3UpdateUI);

  CATP3Editor(CATFrmEditor * iEditor);
  virtual ~CATP3Editor();

  l_CATP3Editor * GetLetter ();
  CATCommandSelector *GetP3CommandSelector();
  CATCommandSelector *GetTOMCommandSelector();

  void Close();

  // make CommandSelector P3 active
  void  GrabFocus();

private:

  l_CATP3Editor * _letter;
  void CATCmdSelP3CommandsClosed();

};

#endif
