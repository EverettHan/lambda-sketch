// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCompTransactionServiceAdapter.h
// Define the CATPLMCompTransactionServiceAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMCompTransactionService
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMCompTransactionServiceAdapter_H
#define CATPLMCompTransactionServiceAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

#include "CATIPLMCompTransactionService.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

class CATUnicodeString;
class CATIPLMCompSaveTransaction;
class CATIPLMCompImportTransaction;
class CATIPLMCompNewVersionTransaction;
class CATIPLMCompLockUnlockTransaction;
class CATIPLMCompCloneTransaction;
class CATIPLMCompCopyTransaction;
class CATIPLMCompDeleteRefTransaction;
class CATIPLMCompCheckEditTransaction;
class CATIPLMCompWorkspaceMngtTransaction;
class CATIPLMCompRefreshTransaction;
class CATPLMID;

class ExportedByCATPLMImplAdapterClass CATPLMCompTransactionServiceAdapter : public CATIPLMCompTransactionService
{
public:
  CATPLMCompTransactionServiceAdapter();
  virtual ~CATPLMCompTransactionServiceAdapter();

  virtual HRESULT CreateSaveTransaction(CATUnicodeString *iTransactionName, CATIPLMCompSaveTransaction** oppTransaction,
                                        CATUnicodeString* iTransactionComment=NULL, CATPLMID* iAction=NULL, CATPLMID* iWorkspace=NULL);

  virtual CATIPLMCompSaveTransaction* CreateSaveTransaction(const CATUnicodeString& iTransactionName,
    const CATUnicodeString& iTransactionComment = "", const CATPLMID& iAction = CATPLMID_Null, const CATPLMID& iWorkspace = CATPLMID_Null);

  virtual HRESULT CreateImportTransaction(CATUnicodeString *iTransactionName, CATIPLMCompImportTransaction** oppTransaction,
                                          CATUnicodeString* iTransactionComment=NULL,CATPLMID* iAction=NULL);

  virtual CATIPLMCompImportTransaction* CreateImportTransaction(const CATUnicodeString& iTransactionName,
    const CATUnicodeString& iTransactionComment = "", const CATPLMID& iAction = CATPLMID_Null);

  virtual HRESULT CreateNewVersionTransaction(CATUnicodeString *iTransactionName, CATIPLMCompNewVersionTransaction ** oTransaction,
                                              CATUnicodeString* iTransactionComment=NULL,CATPLMID* iAction=NULL, CATPLMID* iWorkspace=NULL);

  virtual HRESULT CreateLockUnlockTransaction(CATUnicodeString *iTransactionName, CATIPLMCompLockUnlockTransaction ** oTransaction);

  virtual HRESULT CreateCloneTransaction(CATUnicodeString *iTransactionName, CATIPLMCompCloneTransaction ** oTransaction,
                                         CATUnicodeString* iTransactionComment=NULL,CATPLMID* iAction=NULL, CATPLMID* iWorkspace=NULL);

  virtual HRESULT CreateCopyTransaction(  CATUnicodeString *iTransactionName           ,
                                          CATUnicodeString* iTransactionComment        ,
                                          CATIPLMCompCopyTransaction ** oTransaction   ,
                                          CATPLMID* iAction=NULL                       ,
                                          CATPLMID* iWorkspace=NULL);

  virtual HRESULT CreateDeleteRefTransaction(CATUnicodeString *iTransactionName, CATIPLMCompDeleteRefTransaction ** oTransaction,
                                             CATUnicodeString* iTransactionComment=NULL,CATPLMID* iAction=NULL, CATPLMID* iWorkspace=NULL);

  virtual HRESULT CreateCheckEditTransaction(CATUnicodeString* iTransactionName, CATIPLMCompCheckEditTransaction ** oTransaction, CATPLMEditabilityLockMode iLockMode, CATPLMID* iAction=NULL);

  virtual HRESULT CreateWorkspaceMngtTransaction(CATUnicodeString* iTransactionName, CATListOfCATUnicodeString& iParams, CATIPLMCompWorkspaceMngtTransaction ** oTransaction, CATIPLMCompTransactionService::PLMWspMngtTrnsType iTransactionType, CATPLMID* iWorkspace=NULL);

  virtual HRESULT CreateRefreshTransaction(CATUnicodeString* iTransactionName, CATIPLMCompRefreshTransaction ** oTransaction);

  virtual HRESULT CreateTransferOwnershipTransaction(CATUnicodeString *iTransactionName, CATIPLMCompTransferOwnershipTransaction **oTransaction, CATUnicodeString* iTransactionComment=NULL, CATPLMID* iAction=NULL);

  virtual HRESULT CreateIterationTransaction(CATUnicodeString *iTransactionName, CATIPLMCompIterationTransaction ** oTransaction);

  virtual HRESULT CreateWspReservationTransaction(const CATUnicodeString & iTransactionName, CATListOfCATUnicodeString& iParams, CATIPLMCompWspReservationTransaction *& opTransaction, const CATPLMID & iWorkspaceId);

  virtual HRESULT CreateForkTransaction(CATIPLMCompForkTransaction*& oTransaction);
private:
  CATPLMCompTransactionServiceAdapter (CATPLMCompTransactionServiceAdapter &);
  CATPLMCompTransactionServiceAdapter& operator=(CATPLMCompTransactionServiceAdapter&);

};

#endif
