// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProviderCapabilityAdapter.h
// Define the CATPLMProviderCapabilityAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMProviderConnection
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMProviderConnectionAdapter_H
#define CATPLMProviderConnectionAdapter_H
#include "CATDbBinary.h"
#include "CATSysMacros.h"
#include "CATUnicodeString.h"
#include "CATInstantiateComponent.h"
#include "CATString.h"
#include "DSYSysLevelInfo.h"
#include "CATLib.h"
#include "CATLM.h"
#include "CATUuid.h"
#include "CATSysLogonDone.h"
#include "CATIUExitCrypt.h"  // Cryptage du password
#include "CATGetEntryPoint.h"// Certificates
#include "CATIAV5Level.h"
#include "CATError.h"


#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMProviderConnection.h"// CATPLMServices ProtectedInterfaces CATPLMServicesUUID.m 
#include "CATPLMResolutionKey.h"
#include "CATOmxCxxPortability.h"

class CATPLMConnectionParameters;
class CATBinary;
class CATIPLMDispConnectionToken;
class CATUnicodeString;

/**
 * gives an adapter to the interface CATIPLMProviderConnection
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMProviderConnectionAdapter : public CATIPLMProviderConnection
{
public:
  CATPLMProviderConnectionAdapter();
  virtual ~CATPLMProviderConnectionAdapter();

  /**
  * @nodoc
  */
  virtual HRESULT GetConnectionParameters(CATPLMConnectionParameters ** oConnectionParameters);

  /**
  * @nodoc
  */
  virtual HRESULT GetConnectionParameters(CATBinary ** oConnectionParameters);

  /**
  * @nodoc
  */
  virtual HRESULT IsAuthentificationRequired(CATBoolean& oIsMandatory);

  /**
  * @nodoc
  */
  virtual HRESULT IsReadyToConnect();

  /**
  * @nodoc
  */
  virtual HRESULT PrepareConnect(CATPLMConnectionParameters * ioConnectionParameters);

  /**
  * @nodoc
  */
  virtual HRESULT PrepareConnect(CATBinary * iConnectionParameters);

  /**
  * @nodoc
  */
  virtual HRESULT IsConnected();

  /**
  * @nodoc
  */
  virtual HRESULT Connect();

  /**
  * @nodoc
  */
  virtual HRESULT Disconnect();

  /**
  * @nodoc
  */
  virtual HRESULT GetConnectionToken(CATIPLMDispConnectionToken **oToken);

  /*
  * Default and final implementation of :
  * Setter of the ResolutionKey in PPrime Project
  * input:
  * @param iResolutionKey [in]
  *     Set the resolution key  associated to the CATIPLMProviderConnection Object
  * @return
  * <dt> <code>S_OK</code> <dd> if everythings is alright.
  */
  HRESULT SetResolutionKey(CATPLMResolutionKey & iResolutionKey) OMX_Cxx11_FINAL;

  /*
  * Default and final implementation of :
  * Getter of the ResolutionKey in PPrime Project
  * output:
  * @param oResolutionKey [out]
  *     Get the resolution key associated to the CATIPLMProviderConnection Object
  * @return
  * <dt> <code>S_OK</code> <dd> if everythings is alright.
  */
  HRESULT GetResolutionKey(CATPLMResolutionKey & oResolutionKey) OMX_Cxx11_FINAL;

  /**
  * Returns content of intel_a\resources\logincertificates\pvname.OLCPCertificateRequired.xml file.
  * With pvname equals to TST / PLM1 / etc...
  */
  HRESULT GetPvCertificateTokens(CATListOfCATPLMCertificateToken &oCertTokens);

  virtual HRESULT SwitchSecurityContext(const CATUnicodeString &iNewSecurityContext);

protected:
  CATPLMResolutionKey  _ResolutionKey;

private:
  CATPLMProviderConnectionAdapter(CATPLMProviderConnectionAdapter &);
  CATPLMProviderConnectionAdapter& operator=(CATPLMProviderConnectionAdapter&);

};

#endif

