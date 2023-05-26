/* -*-c++-*- */

/**
 * @level Protected
 * @usage U4
 */

// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIOmyTransactionsManager.h
// Define the CATIOmyTransactionsManager interface
//
//===================================================================
//
// Interface dedicated to transactions management for hidden provider
//
// Realises the transactions management for images, etc.
//
//===================================================================
//  Dec 2009  Creation: Code generated a la mano because of no integration in new RADE
//===================================================================
#ifndef CATIOmyTransactionsManager_h
#define CATIOmyTransactionsManager_h

/**
* Interface dedicated to Session Image user choice.
* <br><b>Role:</b> Realises the interactive or batch user choice for a Session Image
* <br> to be opened and/or used by the current V5 PLM Session.
*/

#include "CATBaseUnknown.h"
#include "CATOMYBaseSession.h"
#include "CATOmyBSCTypeDefs.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
class CATOmyPrivateTransactionDescriptor;
class CATListPtrCATOmyLocalSaveTransaction;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmyTransactionsManager;
#else
extern "C" const IID IID_CATIOmyTransactionsManager;
#endif



class ExportedByCATOMYBaseSession CATIOmyTransactionsManager : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
  * Returns S_FALSE if no transaction to restore
  */
  virtual HRESULT GetTransactionToRestore(CATUnicodeString & oTransactionName) = 0;
  virtual HRESULT GetNextMergeToDo(CATUnicodeString          & oTargetTransName,
                                   CATListOfCATUnicodeString & oTransToMerge) = 0;
  virtual HRESULT CommitDatabaseTransaction(const CATUnicodeString & iNewTransName,
                                            const CATUnicodeString & iPreviousTransName,
                                            const LocalSaveTransaction::Mode    iMode) = 0;
  /**
  * Returns S_FALSE in case of no path
  */
  virtual HRESULT GetTransactionsPath(CATUnicodeString &oPath) = 0;

  //Init functions
  /**
  * Initialize transactions manager with a path (for new set of transactions)
  * @return S_OK in case of directory creation
  *         S_FALSE if the directory already exists
  **/
  virtual HRESULT NewFromPath(const CATUnicodeString &iPath) = 0;
  /**
  * Load trasactions from database file. Return failure in case of reading problem, or already initialized
  **/
  virtual HRESULT LoadFromPath(const CATUnicodeString &iPath) = 0;
  /**
  * Load trasactions from database file, then initialize from function defined in transactions descriptor
  * return E_FAIL in failure, or already initialized
  **/
  virtual HRESULT LoadFromDescriptor(const CATUnicodeString& iPath) = 0;

  virtual HRESULT GetListTransactionsToRestore(CATListPtrCATOmyLocalSaveTransaction & oList) = 0;
  virtual HRESULT SetTransactionToRestore(const CATUnicodeString & iTransaction) = 0;
  virtual HRESULT GetCurrentTransactionName(CATUnicodeString & oTransName) = 0;

  virtual HRESULT GetVaultSite(CATUnicodeString & oVVS) = 0;
};

CATDeclareHandler(CATIOmyTransactionsManager, CATBaseUnknown);

#endif



