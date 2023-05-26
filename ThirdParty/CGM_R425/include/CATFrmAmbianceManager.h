#ifndef CATFrmAmbianceManager_H
#define CATFrmAmbianceManager_H

// COPYRIGHT DASSAULT SYSTEMES 2012

#include "CATAfrFoundation.h"

#include "list.h"
#include "CATString.h"

#define CATMaxAmbiance 40

class CATViewer;
class CATString;
class CATCommandHeader;
class CATDlgMenu;
class CATFrmWindowCommand;
class CATICAfrComponent;
class CATFrmWindow;
class ExportedByCATAfrFoundation CATFrmAmbianceManager 
{
  friend class VisuNewDevToolbarAddin;

public:
  static void CreateCommandHeaders();
  static void CreateContextualMenu(CATDlgMenu* iDlgParent, CATViewer& iViewer);
  static void CreateCommands      (list<CATFrmWindowCommand>& oList, CATViewer* iViewer);
  static void UpdateCommandHeaders(CATViewer& iViewer);
  static int  ExecuteCommandHeader(const CATString& iCmd, CATViewer& iViewer);

  static void CreateNewContextualMenu(CATViewer& iViewer);

  enum EType
  {
    eAmbiance,
    eStyle
  };
  static bool IsAvailable(EType iType);

private:
  CATFrmAmbianceManager();
  ~CATFrmAmbianceManager();

  static void Init();
  static void InitCommandHeader(CATCommandHeader& iHeader);
   
  static void AddStarterInComponentMenu(CATICAfrComponent* iCAfrComponent, CATString iHeader);

  static int _isReplayOrCapture;
  static CATString _ambianceCmdStr;
  static CATString _ambianceHeaderStr;
  static CATString _moreAmbiancesCmdStr;
  static CATString _moreAmbiancesHeaderStr;
  static CATString _styleCmdStr;
  static CATString _styleHeaderStr;
  static CATString _static_style_str[CATMaxAmbiance];
  static CATString _static_ambiance_str[CATMaxAmbiance];
};
#endif
