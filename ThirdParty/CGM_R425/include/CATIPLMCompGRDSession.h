#ifndef CATIPLMCompGRDSession_H
#define CATIPLMCompGRDSession_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#include "CATBaseUnknown.h"

#include "CATPLMServicesItf.h"
#include "CATOmxSR.h"
#include "CATIOmyTransactionsManager.h"
class CATPLMRepositoryName;
class CATPLMPrivateGRDServices;
class CATIOmyOfflineContentRepository;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompGRDSession;
#else
extern "C" const IID IID_CATIPLMCompGRDSession ;
#endif

class CATIPLMCompSaveTransaction;
class CATUnicodeString;

/**
 * RESTRICTED TOOLBOX for specific GRD access in PLMAdapter
 * @nodoc
 */
class ExportedByCATPLMServicesItf CATIPLMCompGRDSession : public CATBaseUnknown
{
  CATDeclareInterface;

  friend class CATPLMPrivateGRDServices;

public:

  /** 
  * Creates a save transaction which will be directed to the GRD provider whatever PLMID information.
  * @nodoc
  */
  virtual HRESULT CreateLocalSaveTransaction ( CATIPLMCompSaveTransaction    *&oTransaction, 
                                         const CATUnicodeString               &iTransName,
                                         const CATUnicodeString               &iPreviousTransName) = 0;

  /** 
  * Creates a collab save transaction which will be directed to the GRD provider whatever PLMID information.
  * @nodoc
  */
  virtual HRESULT CreateCollabSaveTransaction (CATIPLMCompSaveTransaction    *&oTransaction) = 0;

  /**
  * Create a Psp transaction.
  * <br><b>Role</b>: Create a Psp transcaction.
                     Psp transaction loads in an authoring TOS (CATProxySpace::CATIA3D) a list of CATIPLMRecordReadSet **oRecordReadSet.
  * @param oTransaction [out, CATBaseUnknown#Release]
  *   handler on the Psp transaction.
  * @return
  *  <code>E_INVALIDARG</code>if oTransaction!=NULL
  *  <code>S_OK</code>
  * 
  */
  virtual HRESULT CreateLoadInSessionSaveTransaction (CATIPLMCompSaveTransaction    *&oTransaction) = 0;

   /**
  * Initialize GRD transaction with a transactions manager able to resolve a transaction merge, then resolve merge
  * @nodoc
  */
  virtual HRESULT CreateOpenTransaction () = 0;

  virtual HRESULT CreateOfflineContentOpenTransaction(const CATOmxSR<CATIOmyOfflineContentRepository> &iRepo) = 0;

  virtual HRESULT CreateOfflineContentSaveTransaction(CATIPLMCompSaveTransaction *&oTransaction, const CATOmxSR<CATIOmyOfflineContentRepository> &iRepo) =0;

  virtual HRESULT SetProviderRepository(const CATPLMRepositoryName& iRepoName) = 0;

  /** 
  * Begins a GRD transaction specifying Transactions Manager which is used to hook transactions operations.
  * @nodoc
  */
  virtual HRESULT Begin(const CATOmxSR<CATIOmyTransactionsManager> &iTransManager) = 0;
  
    /** 
  * Ends the transaction, mandatory !
  * @nodoc
  */
  virtual HRESULT End() = 0;
  // or
  virtual HRESULT EndOffline() = 0;
};

CATDeclareHandler( CATIPLMCompGRDSession, CATBaseUnknown );

#endif
