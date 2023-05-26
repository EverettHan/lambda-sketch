#ifndef CATIPLMLocalSavePrivateServices_H
#define CATIPLMLocalSavePrivateServices_H
/**
* @level Private
* @usage U1
*/

#include "CATBaseUnknown.h"

#include "CATPLMServicesItf.h"
#include "CATOmxSR.h"
#include "CATIOmyTransactionsManager.h"

class CATUnicodeString;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMLocalSavePrivateServices;
#else
extern "C" const IID IID_CATIPLMLocalSavePrivateServices;
#endif


/** @nodoc */
#define AuthorizedModule 999
/** @nodoc */
#define CATPLMServicesItf AuthorizedModule
/** @nodoc */
#define CATPLMPXn AuthorizedModule
/** @nodoc */
#define CATPLMImplAdapterBase AuthorizedModule
/** @nodoc */
#define CATPLMEmptyProviderImpl AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
  #error Forbidden access to CATIPLMLocalSavePrivateServices
  @error 
#endif


#undef CATPLMServicesItf
#undef CATPLMPXn
#undef CATPLMImplAdapterBase
#undef CATPLMEmptyProviderImpl


/**
 * This interface is implemented by LocalSave providers and should not be implemented by other providers
 * It provides services dedicated to LocalSave process
 */

class ExportedByCATPLMServicesItf CATIPLMLocalSavePrivateServices : public CATBaseUnknown
{
  CATDeclareInterface;

 public:
  /**
   * Inits a new LocalSave Transaction
   * @param [in] iNameOfTransaction, the name of the new transaction
   *             the caller should ensure that this name is unique
   * @param [in] iNameOfPreviousTransaction, the name of the previous transaction to take in account
   *             Usefull for undo/redo management
   * @param [in] iTransManager, the transaction manager which implements what to do with the local save transaction
   * @return S_OK if the initialization succeeded
   *         E_FAIL if it failed.
   */
  virtual HRESULT InitLocalSaveTransaction(const CATUnicodeString &iNameOfTransaction, 
                                           const CATUnicodeString &iNameOfPreviousTransaction,
                                           const CATOmxSR<CATIOmyTransactionsManager> &iTransManager) =0;

};


#endif
