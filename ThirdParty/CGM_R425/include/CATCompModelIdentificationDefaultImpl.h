#ifndef CATCompModelIdentificationDefaultImpl_h_
#define CATCompModelIdentificationDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGContext.h"
#include "CATCompModelIdentification.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"

class ExportedBySGComposites CATCompModelIdentificationDefaultImpl : public CATSGCompositeHost1NoListeners<CATCompModelIdentification, CATSGComposite>
{
public:
	CATCompModelIdentificationDefaultImpl();
	CATCompModelIdentificationDefaultImpl(CATSGContext& iContext);
	virtual ~CATCompModelIdentificationDefaultImpl();

	virtual unsigned int            GetSizeInBytes(const int iIncludeStructuralSize = 1);

    virtual HRESULT                 SetModelIdentificator(const CATModelIdentificator& iIdentificator);
	virtual HRESULT                 SetModelIdentificator(CATBaseUnknown* iIdentificator);
	virtual CATBaseUnknown*         GetModelIdentificator();
	virtual HRESULT                 SetCtxId(const CATCompCtxId iCtxId);
	virtual CATCompCtxId            GetCtxId();
	virtual HRESULT                 SetUuid(const CATUuid& iUuid);
	virtual CATUuid&                GetUuid();
    virtual const CATUuid&          GetUuid() const;
    virtual HRESULT                 SetPLMID(CATPLMIDHolder* iPLMID);
    virtual HRESULT                 GetPLMID(CATPLMIDHolder*& oPLMID) const;
	virtual HRESULT                 SetILB2(CATILockBytes2* iILB2);
	virtual CATILockBytes2*         GetILB2();
	virtual HRESULT                 SetStorageUri(const CATUnicodeString& iUri);
	virtual const CATUnicodeString& GetStorageUri() const;
	virtual HRESULT                 SetUserData(void* iUserData);
	virtual void*                   GetUserData();

private:
	CATBaseUnknown*                 _identificator;
	void*                           _userData;
	CATUuid                         _uuid;
    CATPLMIDHolder*                 _plmId;
	CATILockBytes2*                 _ilb2;
	CATUnicodeString                _storageUri;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompModelIdentificationDefaultImpl_h_
