// COPYRIGHT Dassault Systemes 2008

#ifndef CATGraphicPropertiesTransactionManager_H
#define CATGraphicPropertiesTransactionManager_H

#include "SceneGraphManager.h"
#include "CATCallbackManager.h"
#include "CATNotification.h"
#include "CATShowAttribut.h"

class CATSO;

class ExportedBySceneGraphManager CATVisBeginShowCmdNotif : public CATNotification
{
  CATDeclareClass;
  friend class CATGraphicPropertiesTransactionManager;

public:
  CATSO* GetSO();

private:  
  CATVisBeginShowCmdNotif(CATSO* iSo);
  virtual ~CATVisBeginShowCmdNotif();
  CATVisBeginShowCmdNotif();
  CATVisBeginShowCmdNotif(const CATVisBeginShowCmdNotif&);
  CATSO* _so;
};

class ExportedBySceneGraphManager CATVisEndShowCmdNotif : public CATNotification
{
  CATDeclareClass;
  friend class CATGraphicPropertiesTransactionManager;

public:
  CATSO* GetSO();
  CATShowAttribut GetShowAttribut();

private:  
  CATVisEndShowCmdNotif(CATSO* iSo, CATShowAttribut iShowAttr);
  virtual ~CATVisEndShowCmdNotif();
  CATVisEndShowCmdNotif();
  CATVisEndShowCmdNotif(const CATVisEndShowCmdNotif&);
  CATSO* _so;
  CATShowAttribut _showAttr;
};

class ExportedBySceneGraphManager CATGraphicPropertiesTransactionManager : public CATCallbackManager
{
 CATDeclareClass;
 friend class CATCmdShow; 
 friend class CATVPApplication;

public:
  static CATGraphicPropertiesTransactionManager* Get();
  virtual ULONG   __stdcall Release();

  CATDeclareCBEvent (GRAPHICPROPERTIES_BEGIN_TRANSACTION);
  CATDeclareCBEvent (GRAPHICPROPERTIES_END_TRANSACTION);

  static void DispatchBeginTransaction();
  static void DispatchEndTransaction();
  
  CATDeclareCBEvent (SHOWCOMMAND_BEGIN);
  CATDeclareCBEvent (SHOWCOMMAND_END);

protected:
  static void DispatchBeginShowCmd(CATSO* iSO);
  static void DispatchEndShowCmd(CATSO* iSO, CATShowAttribut iShowAttr);

private:
  CATGraphicPropertiesTransactionManager();
  ~CATGraphicPropertiesTransactionManager();

  static CATGraphicPropertiesTransactionManager* _manager;
};

#endif
