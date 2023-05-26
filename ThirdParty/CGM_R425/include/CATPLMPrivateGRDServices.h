#ifndef CATPLMPrivateGRDServices_H
#define CATPLMPrivateGRDServices_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#include "CATPLMServicesItf.h"

#include "CATPLMRepositoryName.h"
#include "CATCollec.h"
#include "CATIOmyTransactionsManager.h"

class CATIPLMCompConnectionInstance;
class CATIPLMCompSaveTransaction;
class CATString;
class CATLISTV(CATPLMID);
class CATIPLMCompRecordWrite;
class CATPLMStreamDescriptor;
class CATVVSUrl;
class CATIPLMCompGRDSession_var;

/**
 * RESTRICTED TOOLBOX for GRD provider access
 * @nodoc
 */

class ExportedByCATPLMServicesItf CATPLMPrivateGRDServices
{
public:

  /** 
  * Retrieves the connection instance of the provider used for session image (GRD).
  * @nodoc
  */
  static HRESULT GetGRDConnectionInstance (CATIPLMCompConnectionInstance **oGRDConnection, const CATUnicodeString & iRepositoryName);

  static HRESULT GetCompGRDSession(CATIPLMCompGRDSession_var       & oService, 
                             const CATUnicodeString                & iRepositoryName);

  /**
  * Method needed by CATPLMAdapterImpl to know if the repository is a GRD (hidden) repository, or not
  * @nodoc
  */
  static CATBoolean IsGRDRepository (const CATPLMRepositoryName& iName);

/**
 * Quick access to general GRD transaction context.
 * The context is valid during the refresh transaction lifecycle.
 * @nodoc
 */
//  static TransactionContext GetTransactionContext();

  static HRESULT WriteURLInMessage( CATIPLMCompRecordWrite * iMsg, CATPLMStreamDescriptor * iStreamDesc, CATVVSUrl * iURL );

  static HRESULT InitDefaultMetadata();
  
};

#endif
