#ifndef CATVisInfiniteEnvironmentFactory_H
#define CATVisInfiniteEnvironmentFactory_H

// COPYRIGHT Dassault Systemes 2009

#include "SGInfra.h"
#include "CATListOfCATString.h"
#include "CATString.h"

#include "CATSysDevLA.h"
USE_LA_VAR(V6Signature, CATVisSignatureAmbiances);

class CATString;
class CATVisInfiniteEnvironment;
class CATVisSSAOData;
class CATViewer;
class CATFrmWindow;
class ExportedBySGInfra CATVisInfiniteEnvironmentFactory
{
  friend class VisuDebugToolbarAddin;

public:
  static CATVisInfiniteEnvironment* Create(const CATString& iEnvID);

  static const CATListOfCATString& GetPredefinedList(const CATString& iListName);

  static bool ArePrototypeAmbiancesActivated  ();
  static bool AreMoreAmbiancesActivated       (CATViewer* iViewer);
  static void GenerateMoreAmbiances           (CATViewer* iWindow);

  static bool  IsAPredefinedAmbiance(const CATString& iName, const CATString& iListName = "CATIA");
  static bool  IsCustomAmbianceDefined();
  static const CATString& GetCustomAmbianceId();

private:
  CATVisInfiniteEnvironmentFactory();
  ~CATVisInfiniteEnvironmentFactory();

  static void _Init();
  static void _UpdateSSAO(CATVisSSAOData& ioSsaoData);
  static void _UpdateForODT(CATVisInfiniteEnvironment& ioEnv);
  static void _ActivatePrototypeAmbiances();

  static int  m_Init;
  static int  m_IsCaptureReplay;
  static int  m_IsSignature;
  static bool m_PrototypeAmbiancesActivation;

  static CATListOfCATString m_CATIA;
  static CATListOfCATString m_CATIALive;
  static CATListOfCATString m_CATIAWork;
  static CATListOfCATString m_CATIAReview;
  static CATListOfCATString m_CATIAReview2;
  static CATListOfCATString m_CATIADesign;
  static CATListOfCATString m_CATIAOther;
  static CATListOfCATString m_CATIAWorkbench;
  static CATListOfCATString m_Visu;
  static CATListOfCATString m_VisuV1;
  static CATListOfCATString m_VisuV2;
  static CATListOfCATString m_VisuPrototype;
  static CATListOfCATString m_LiveRenderingNRE;
  static CATListOfCATString m_3DXMLPlayer;
  static CATListOfCATString m_Mobile;
  static CATListOfCATString m_All;
  static CATListOfCATString m_Default;
  
  static bool m_MoreAmbiancesActivation;
  static CATString m_MoreAmbiances;

  static CATString s_CustomAmbianceID;
};

//-----------------------------------------------------------------------

#endif
