/**
 * @fullreview CMG-ERS 02:07:11
 * @error UDOO Y pas de constructeur par copie et pas d'operateur =
 * @error UDOO Y destructeur pas virtuel
 * @error MISC Y class et include pas bons
*/
#ifndef CATFrmAbendInfo_h
#define CATFrmAbendInfo_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAbendInfo.h"

#include "CATListOfCATString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATCommand.h"

class CATCommand;
class CATString;

#include "CATAfrFoundation.h"
class ExportedByCATAfrFoundation CATFrmAbendInfo : public CATAbendInfo
{

public:
  
  CATFrmAbendInfo();
  virtual ~CATFrmAbendInfo();
  
  char * Dump();
  
  void SetDocument (const CATUnicodeString &);
  void SetWorkshop (const char * ws, const char * wb);

  void SetCommand  (const CATUnicodeString &cmdname, 
                    const CATString &cmdID, 
                    const CATString &cmdclass, 
                    const CATString &cmdmodul);
  void UpdateCommandState (CATCommand * cmdP, const CATString &CmdState);
  void UpdateCurrentCommand  (CATCommand * cmdP);

  static const CATString CATCmdFailed;
  static const CATString CATCmdOn;
  static const CATString CATCmdOff;
  static const CATString CATCmdDeact;
  static const CATString CATCmdNoState;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATFrmAbendInfo (const CATFrmAbendInfo &);
  CATFrmAbendInfo & operator= (const CATFrmAbendInfo &);

  void UpdateInfo();
  
  char                    * _Info;
  CATUnicodeString          _WsWb;
  CATUnicodeString          _Doc;
  CATLISTP(CATCommand)      _Cmd;
  CATListOfCATUnicodeString _CmdName;
  CATListOfCATString        _CmdClass;
  CATListOfCATString        _CmdModul;
  CATListOfCATString        _CmdState;
  CATListOfCATUnicodeString _CmdDoc;
  CATListOfCATUnicodeString _CmdWsWb;

};

extern ExportedByCATAfrFoundation CATFrmAbendInfo _FrmAbendInfo;

#endif
