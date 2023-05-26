#ifndef CATCompModelIdentification_H
#define CATCompModelIdentification_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATModelIdentificator.h"
#include "CATUuid.h"
#include "CATILockBytes2.h"
#include "CATUnicodeString.h"

typedef int CATCompCtxId;
class CATPLMID;

/**
* The only implementation of this class should be "CATPLMIDHolderImpl" (located in the VisuPLMHelpers framework).
*/
class ExportedBySGComposites CATPLMIDHolder
{
public:
    virtual ~CATPLMIDHolder();

    virtual HRESULT GetPLMID(CATPLMID& oPLMID) const = 0;

protected:
    CATPLMIDHolder();
};

/**
 * This composite can be used in a Ring as a means of identification.
 * Various types of identification are possible (IDs, strings, objects, ...).
 */
class ExportedBySGComposites CATCompModelIdentification : public CATSGComposite
{
public:
    /** ModelIdentificator. */
    virtual HRESULT                 SetModelIdentificator(const CATModelIdentificator& iIdentificator) = 0;
    /** ModelIdentificator. Directly refer to the pointed object. */
    virtual HRESULT                 SetModelIdentificator(CATBaseUnknown* iIdentificator) = 0;
    /** ModelIdentificator. Directly returns the pointed object. */
    virtual CATBaseUnknown*         GetModelIdentificator() = 0;

    /** Deprecated. */
	virtual HRESULT                 SetCtxId(const CATCompCtxId iCtxId) = 0;
    /** Deprecated. */
	virtual CATCompCtxId            GetCtxId() = 0;

    /** CATUuid. */
	virtual HRESULT                 SetUuid(const CATUuid& iUuid) = 0;
    /** CATUuid. */
	virtual CATUuid&                GetUuid() = 0;
    /** CATUuid. */
    virtual const CATUuid&          GetUuid() const = 0;

    /** CATPLMID. The caller IS NOT responsible for the lifecycle. */
    virtual HRESULT                 SetPLMID(CATPLMIDHolder* iPLMID) = 0;
    /** CATPLMID. */
    virtual HRESULT                 GetPLMID(CATPLMIDHolder*& oPLMID) const = 0;

    /** CATILockBytes2. */
	virtual HRESULT                 SetILB2(CATILockBytes2* iILB2) = 0;
    /** CATILockBytes2. */
	virtual CATILockBytes2*         GetILB2() = 0;

    /** Storage URI. Usually points to FCS stream or CGR filepath. */
	virtual HRESULT                 SetStorageUri(const CATUnicodeString& iUri) = 0;
    /** Storage URI. Usually points to FCS stream or CGR filepath. */
	virtual const CATUnicodeString& GetStorageUri() const = 0;

    /** Custom. The caller is responsible for the lifecycle. */
	virtual HRESULT					SetUserData(void* iUserData) = 0;
    /** Custom. The caller is responsible for the lifecycle. */
	virtual void*					GetUserData() = 0;
};

// {391E8D70-B91C-439A-8533-AB6FE2263951}
static const IID GUID_CATCompModelIdentificationTrait =
{ 0x391e8d70, 0xb91c, 0x439a, { 0x85, 0x33, 0xab, 0x6f, 0xe2, 0x26, 0x39, 0x51 } };


template<>
class CATTraitInfo<CATCompModelIdentification>
{
public:
	static const GUID&                      GetTraitGUID()
	{
		return GUID_CATCompModelIdentificationTrait;
	}
	static const int                        GetTraitTag() { return CATTraitTag(-1); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTWeakPtr<CATCompModelIdentification>        CATCompModelIdentificationWeakPtr;
typedef CATCompositeTPtr<CATCompModelIdentification>            CATCompModelIdentificationPtr;
typedef CATOnStackBorrowPtr<CATCompModelIdentification>	        CATCompModelIdentificationBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompModelIdentification_H
