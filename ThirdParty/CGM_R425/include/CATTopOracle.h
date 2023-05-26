#ifndef CATTopOracle_H
#define CATTopOracle_H
//===================================================================
// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATAutoFilletCATAutoFilletBuildStatus.h
// 		
//===================================================================
//  Feb 2004  Creation: JHG
//===================================================================

#include "CATTopRibObject.h"
#include "CATTolerance.h"
#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "CATListPOfCATCGMDiagnoses.h"
#include "CATAutoBaseThreadContext.h"
#include "CATOracleSwitch.h"
#include "CATListOfInt.h"
#include "CATMathInline.h"

#include "CFSEngine.h"

class CATAutoBaseProgressBar;
class CATPersistentCellFactory;
class CATODTAutoBaseCheckData;
class CATCGMProgressBar;
class CATTopOpInError;

class CATAutoBaseThreadContext;

//#define RetrieveThreadContextIsForbidden_ENABLED

class ExportedByCFSEngine CATTopOracle : public CATTopRibObject
{
public:
  
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATTopOracle(CATSoftwareConfiguration &iConfig, const CATTolerance &iTolerance,
    const CATAutoBaseThreadContext &iThreadContext, CATPersistentCellFactory &iPersistentCellFactory);
  virtual ~CATTopOracle();

  void ActivateOracleSwitch(int iOracleSwitchId);

//  CATGeoFactory *GetFactory();
//  CATGeoFactory &Factory();

  CATSoftwareConfiguration *GetSoftwareConfiguration();
  CATSoftwareConfiguration &SoftwareConfiguration();

  CATPersistentCellFactory *GetPersistentCellFactory();
  CATPersistentCellFactory &PersistentCellFactory();

  const CATTolerance & Tolerance();

  // fait un throw si l'utilisateur a demande l'interruptionde l'operation
  // et met a jour la progress bar si besoin est
  void CheckForInterruption();

  virtual void OnProgress(int iProgress);
  virtual CATODTAutoBaseCheckData *ReadCheckData();

  // Stocke le warning dans l'oracle
  void SendWarning(CATCGMDiagnosis *iDiag, CATBoolean iConcatenateErrorBodyIfMultipleOccurence = FALSE);
  void RemoveWarning(CATErrorId iErrorIdToRemove);
  CATBoolean AreWarningsOn();
  CATAutoBaseProgressBar *ReadProgressBar();

  void SetCGMProgressBar(CATCGMProgressBar *iCGMProgressBar);
  CATCGMProgressBar * GetCGMProgressBar();

  // L'operateur doit appeler cette methode pour envoyer les warnings stockes
  void ReallySendWarnings();

  void ForceParanoidMode();

  CATBoolean ParanoidMode();

  INLINE CATBoolean IsSwitchActive(short iVersioningFlag);
  INLINE CATBoolean IsOracleSwitchActive(int iOracleSwitchId);

  void AttachError(CATTopOpInError * iError, CATBoolean iAppendErrors = FALSE);
  CATBoolean NoErrorAttached();
  CATTopOpInError * GetAttachedError();

#ifndef RetrieveThreadContextIsForbidden_ENABLED
  const CATAutoBaseThreadContext &RetrieveThreadContext() { return _ThreadContext; }
#else
  const CATAutoBaseThreadContext &RetrieveThreadContext();
  static CATBoolean RetrieveThreadContextIsForbidden;
#endif
private:
  CATSoftwareConfiguration &_Config;
  short _CGMLevel;
  const CATTolerance &_Tolerance; 

  CATLISTP(CATCGMDiagnosis) _WarningList;
  CATListOfInt _ConcatenateErrorBodyIfMultipleOccurence;

  CATAutoBaseProgressBar *_ProgressBar;

  CATCGMProgressBar *_CGMProgressBar;

  CATBoolean _ParanoidMode;

  const CATAutoBaseThreadContext &_ThreadContext;
  CATPersistentCellFactory &_PersistentCellFactory;

  CATBoolean _ActiveOracleSwitches[CATOracleSwitch_Dimension];

  CATTopOpInError * _AttachedError;
};

INLINE CATBoolean CATTopOracle::IsSwitchActive(short iVersioningFlag) { return (iVersioningFlag <= _CGMLevel); }

INLINE CATBoolean CATTopOracle::IsOracleSwitchActive(int iOracleSwitchId) { return _ActiveOracleSwitches[iOracleSwitchId-1]; }

#endif // !CATTopOracle_H
