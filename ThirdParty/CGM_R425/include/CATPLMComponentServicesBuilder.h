//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/06/17
//===================================================================
// CATPLMComponentServicesBuilder.h
// Header definition of class CATPLMComponentServicesBuilder
//===================================================================
//
// Usage notes:
// class implemented as part of Project:
// Ability to import a 3DXML for review in V6 session using a specific provider called Psp.
// (Psp like Provider Session)
//
// class specification:
// ability to create the singleton CATPLMTETransaction that implements interface CATIPLMCompTransactionService
// singleton that can be instantiated by CATPLMComponentServicesBuilder class only.
//
// CATPLMTETransaction gives access to 2 kinds of transaction:
// save transaction CATIPLMCompSaveTransaction
// import transaction CATIPLMCompImportTransaction
//
// class hardcoded for transition engine
// if CATIPLMImportInputOutput object stores 3DXML (source repository) and CATPLMImportOption::ImportInSession or CATPLMImportOption::ImportInSessionAndSave,
// save transaction will realise the loading in session of all datas stored in 3DXML file thanks to PSP provider.
// if no instance of CATIPLMImportInputOutput exists or if one instance of CATIPLMImportInputOutput exists and if this instance stores 3DXML (source repository) and CATPLMImportOption::ImportInDatabase,
// save transaction will realise the save in database of all datas stored in 3DXML file.
//
//===================================================================
//  2010/06/17 Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMComponentServicesBuilder_H
#define CATPLMComponentServicesBuilder_H

#include "CATPLMIntegration.h"

#include "CATBaseUnknown_WR.h"// System PublicInterfaces JS0CORBA.m JS0GROUP.dll

class CATIPLMCompTransactionService;
class CATIAdpErrorMonitor;

/**
* @level Protected
* @usage U1
*/

class ExportedByCATPLMIntegration CATPLMComponentServicesBuilder
{
private:

  friend class CATPLMTEExchangeEngine;
  friend class TstCATPLMPspImportCoverage;
  friend class CATPLMLocalTestBase;

  CATPLMComponentServicesBuilder();
  virtual ~CATPLMComponentServicesBuilder();

  /**
   * Returns the Transaction service allowing to import datas in session or in database.
   *
   * @param oTransactionService [out, CATBaseUnknown#Release]
   *    The CATIPLMCompTransactionService interface.
   * @return
   *
   */
  HRESULT GetTransactionService(CATIPLMCompTransactionService* & opTransactionService);

  /**
  *
  * <br><b>Role</b>:
  *
  * @param oTransactionService [out, CATBaseUnknown#Release]
  *  error generated during the closure of the transaction
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CloseTransactionService(CATIAdpErrorMonitor* iopErrorMonitor = NULL);

  static CATBaseUnknown_WR _pWR;

};

#endif
