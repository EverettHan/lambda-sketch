#ifndef CATOmyTransactionsManagerAdapter_h
#define CATOmyTransactionsManagerAdapter_h

/**
* @level Private
* @usage U1
*/

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmyBSCTypeDefs.h"
#include "CATIOmyTransactionsManager.h"
#include "CATUnicodeString.h"

class ExportedByCATOMYBaseSession CATOmyTransactionsManagerAdapter : public CATIOmyTransactionsManager
{

public:
  static const CATUnicodeString StatusResultOfMerge;
  static const CATUnicodeString StatusTransValid;
  static const CATUnicodeString StatusTransBroken;
  static const CATUnicodeString DBFileName;

  //From CATIOmyTransactionsManager
  HRESULT GetTransactionToRestore(CATUnicodeString & oTransactionName);
  HRESULT GetNextMergeToDo(CATUnicodeString          & oTargetTransName,
                           CATListOfCATUnicodeString & oTransToMerge);
  HRESULT CommitDatabaseTransaction(const CATUnicodeString & iNewTransName,
                                    const CATUnicodeString & iPreviousTransName,
                                    const LocalSaveTransaction::Mode    iMode);
  HRESULT GetTransactionsPath(CATUnicodeString &oPath);
  /**
   * @returns
   *  E_FAIL  if the given path doesn't point to an existing directory
   *  S_FALSE if the given path points to a new image (no db.dat)
   *  S_OK    if the given path points to an old image (there's a db.dat)
   */
  HRESULT NewFromPath(const CATUnicodeString &iPath);
  HRESULT LoadFromPath(const CATUnicodeString &iPath);
  HRESULT LoadFromDescriptor(const CATUnicodeString& iPath);
  HRESULT GetListTransactionsToRestore(CATListPtrCATOmyLocalSaveTransaction & oList);
  HRESULT SetTransactionToRestore(const CATUnicodeString & iTransaction);
  HRESULT GetCurrentTransactionName(CATUnicodeString & oTransName);
  HRESULT GetVaultSite(CATUnicodeString & oVVS);

public:
  CATOmyTransactionsManagerAdapter();

  ~CATOmyTransactionsManagerAdapter();
  CATBoolean    IsSet();

private:
  CATUnicodeString _transactionPath;
  CATUnicodeString _DBFilePath;

  CATUnicodeString _curTransactionName;
  LocalSaveTransaction::Mode _curTransMode;


protected:
  virtual HRESULT SetCurrentTransaction(const CATUnicodeString & iTransaction);
  HRESULT SetPaths(const CATUnicodeString &iPath);
  HRESULT ReadDBFile();

  // ajoute dans le fichier db.dat
  HRESULT WriteDatabaseTransaction(const CATUnicodeString & iNewTransName,
                                   const CATUnicodeString & iPreviousTransName,
                                   const CATUnicodeString & iMode);


  CATUnicodeString ComputeLastValidTransactionId();
  HRESULT GetTransactionsForMerge(const CATUnicodeString & iTransactionIdToMerge,
                                  CATListOfCATUnicodeString & oListOfTransactionForMerge);

  HRESULT DeleteDatabaseFile();
  void RemoveAllTransactions();
  HRESULT RemoveDeletableTransactions();
  inline const CATUnicodeString& TransactionPath() { return _transactionPath; }
  inline const CATUnicodeString& DBFilePath() { return _DBFilePath; }

  CATUnicodeString _TransactionToRestore;

  CATListOfCATUnicodeString _TransStatus;
  CATListOfCATUnicodeString _PrevLst;
  CATListOfCATUnicodeString _TransNotToDelete;
  CATListOfCATUnicodeString _TransLst;

};

#endif
