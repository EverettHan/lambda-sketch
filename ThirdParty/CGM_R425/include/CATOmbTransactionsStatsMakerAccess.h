#ifndef CATOmbTransactionsStatsMakerAccess_H
#define CATOmbTransactionsStatsMakerAccess_H

#include "CATSysBoolean.h"
#include "IUnknown.h"
#include "CATDataType.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"
#include "CATOmxArray.h"
#include "CATObjectModelerBase.h"
#include "AD0XXBAS.h"
#include "CATUnicodeString.h"

class CATIOmbTransactionsStatsController;
class CATIOmbDebugUndoRedoObserver;
class CATDocument;
class CATOmxUTF8String;
class CATWOmbContainer;
class CATILockBytes2;
class CATStorage;
ExportedByAD0XXBAS CATOmxCollecManager& ArrayOfArrayStringMgr();

class ExportedByAD0XXBAS CATOmbTransactionsStatsMakerAccess
{
  friend class CATSession;
  friend class CATEModelUndoRedoManager;
  friend class CATOmbTransactionsStatsController;
  friend class __TA__TestTransactionStats;
public:

  /*
  ** Allow applications to register modification on their model to make statistics on it.
  ** Parameters
  **    iContainer: pointer to the container that contains the modified object.
  **
  **    iDomain : name of the domain which the object belongs.
  **
  **    iObjectAddress : pointer to the modified object. It will be only used to identify the object.
  **
  **    iObjectName : name of the modified object.
  **
  **    iObjectAttributeName : name of the modified attribute of the object.
  **  
  ** return S_OK : record well registered
  **        S_FALSE : stats not activated or record not done completely (object or attribute name not valid)
  **        E_FAIL : failure
  */
  static HRESULT RecordApplicativeModif(CATBaseUnknown* iContainer, CATOmxUTF8String& iDomain, CATBaseUnknown* iObjectAddress, CATOmxUTF8String& iObjectName,  CATOmxUTF8String& iObjectAttributeName);

  static CATBoolean AreStatsActivated();

  // DO NOT USE METHODS BELOW. For internal use only

  //deprecated
  static HRESULT RecordModif(CATWOmbContainer& iStartupCont, CATWOmbContainer& iFeatureCont, CATBaseUnknown* iFeatureImpl, CATOmxUTF8String& iFeatureName, const CATOmxUTF8String& iAttributeName);
  static HRESULT RecordModif(CATDocument* doc, CATOmxUTF8String& iContainerName, CATOmxUTF8String& iCatalogName, CATBaseUnknown* iFeatureImpl, CATOmxUTF8String& iFeatureName, const CATOmxUTF8String& iAttributeName);
  static HRESULT RecordModif(CATDocument* doc, CATOmxUTF8String& iContainerName, CATOmxUTF8String& iCatalogName, CATULONG64 iIncrementalStreamSize, CATULONG64 iNumberOfObjectStreamed, CATULONG64 iNumberOfObjectsTotal);

  static void NoticeDocModification(CATDocument* doc);
  static void RecordCommentForCurrentTransaction(const CATUnicodeString& iComment);
  static HRESULT NoticeLocalSave();
  static HRESULT NoticeLocalSaveEnd();
  static HRESULT DumpResults();
  static HRESULT DumpStorage(CATILockBytes2* iInput, CATUnicodeString iDumpDest = "");
  static HRESULT DumpStorage(CATStorage* iInput, CATUnicodeString iDumpDest = "");

  // OBSERVER 

  static void RecordCommandNamePair(const CATUnicodeString& iCompleteCommandName, const CATUnicodeString& iSimpleCommandName);
  // to be deleted
  static void RemoveUndoRequestFromCurrentCommand(const CATUnicodeString& iSimpleCommandName);
  static void RemoveUndo(const CATUnicodeString& iSimpleCommandName);
  static void RemoveRedo(const CATUnicodeString& iSimpleCommandName);
  static void UnstackRedo(const CATUnicodeString& iSimpleCommandName);
  static void ExecuteUndo(const CATUnicodeString& iSimpleCommandName);
  static void ExecuteRedo(const CATUnicodeString& iSimpleCommandName);
  static void DeleteAllUndo();
  static void DeleteAllRedo();
  static void StartUndoStepsFlush();
  static void EndUndoStepsFlush();
  static void Empty();

  // doesn't display hidden command
  static HRESULT GetCurrentCommandNames(CATOmxArray<CATOmxUTF8String>& oCommandNames);
  // manage hidden commands : only first element of secondary array is visible, following element are hidden under this one
  static HRESULT GetCurrentCommandNames(CATOmxArray< CATOmxArray<CATOmxUTF8String> , ArrayOfArrayStringMgr>&oCommandNames);

private:
  static CATOmxSR<CATIOmbTransactionsStatsController> GetController();
  static CATOmxSR<CATIOmbDebugUndoRedoObserver> GetUndoRedoDebugObserver();
};

#endif // CATOmbTransactionsStatsMakerAccess_H
