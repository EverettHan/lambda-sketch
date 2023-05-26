// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATPLMCompConnectionInstanceAdapter.h
// Define the CATPLMCompConnectionInstanceAdapter interface
//
//===================================================================
//
// Usage notes: adapter for CATIPLMCompConnectionInstance
//
//===================================================================
// March 2015  Creation: EPB
//===================================================================
#ifndef CATPLMCompConnectionInstanceAdapter_H
#define CATPLMCompConnectionInstanceAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMCompConnectionInstance.h"
#include "CATUuid.h"
#include "PLMLevelInfo.h"

class CATPLMConnectionParameters;
class CATBinary;
class CATIPLMDispConnectionToken;
class CATPLMRepositoryName;
class CATUnicodeString;
class CATIPLMSecurity;
class CATPLMPhysicalRepositoryID;

class ExportedByCATPLMImplAdapterClass CATPLMCompConnectionInstanceAdapter: public CATIPLMCompConnectionInstance
{
  public:

	virtual HRESULT GetType( CATPLMRepositoryName * oType );
		
	virtual HRESULT InstanceId(CATUnicodeString **oLogicalInstanceId);

	virtual HRESULT GetConnectionParameters(CATPLMConnectionParameters ** oConnectionParameters);

	virtual HRESULT GetConnectionParameters(CATBinary ** oConnectionParameters);

	virtual HRESULT IsReadyToConnect();

	virtual HRESULT PrepareConnect(CATPLMConnectionParameters * ioConnectionParameters);

	virtual HRESULT PrepareConnect(CATBinary * iConnectionParameters);

	virtual HRESULT IsConnected();

	virtual HRESULT Connect();

	virtual HRESULT Disconnect();

  virtual HRESULT GetConnectionToken(CATIPLMDispConnectionToken **oToken);

	virtual HRESULT GetSecurityPolicy(CATIPLMSecurity ** oSecurity);
  
	virtual HRESULT GetPhysicalRepositoryName (CATUnicodeString &oPhysicalRepositoryName);
  
	virtual HRESULT GetPhysicalRepositoryIdentifier (CATPLMPhysicalRepositoryID &oPhysicalRepositoryIdentifier);

	virtual HRESULT GetPLMLevelInfo (PLMLevelInfo &oLevelInfo);

  virtual HRESULT SwitchSecurityContext (const CATUnicodeString &iNewSecurityContext);
};

#endif
