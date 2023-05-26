#ifndef CATIOProtocolHandler_H
#define CATIOProtocolHandler_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"

#include "CATIOFuture.h"
#include "CATIOBuffer.h"

typedef float CATLoadPriority;
typedef CATIOFuture<CATIOUri> 		CATIOFutureUri;
typedef ExportedBySGComposites CATIOFuture<CATIOBufferPtr>	CATIOFutureBuffer;

/**
 * Abstract interface definition for protocol handlers.
 */
class ExportedBySGComposites CATIOProtocolHandler : public CATSGComposite
{
public:
	/**
	 * This method will be called on your protocol handler implementation any
	 * time the CATIOManager has to save something that was provided with an
	 * indicative URI which prefix match with the prefix associated with your
	 * protocol handler.
	 * In your implementation of protocol handler you should override this method
	 * it is in that one that you will perform the actual work to persist the
	 * data that has been provided to you.
	 */
	virtual CATIOUri 			Save(CATIOBufferPtr iIOBuffer, CATIOUri iUri) = 0;

    /**
     * This method is similar to the Save method but there is one major difference:
     * The caller expects the buffer to be saved without overwriting the existing
     * data saved in the same resource.
     * Example:
     * A call to Append(buffer64bytes, "file://MyFile.txt") is expected to return
     * "file://MyFile.txt/512:64" instead of "file://MyFile.txt/0:64" if there
     * were already 512 bytes written in this file.
     */
    virtual CATIOUri            Append(CATIOBufferPtr iIOBuffer, CATIOUri iUri) = 0;

	/**
	 * This is the symetric method of Save. Will be called by the CATIOManager
	 * against which the protocol handle is registered when a load is asked
	 * with an URI which prefix match the the protocol handler supported
	 * prefix.
	 * Again in implementations you should clearly provide an implemantation
	 * of this method it is in that one that you will do the bulk of the
	 * work for the load operation.
	 */
	virtual CATIOBufferPtr 	Load(const CATIOUri iCacheUri) = 0;

	/**
	 * Protocol handlers are associated with prefix in URI. This method should
	 * be implemented by any protocol handler implementation so that they
	 * communicate on which protocol they will handle.
	 */
	virtual CATIOUri 			ProtocolPrefix() = 0;
};

// {3882BC9D-3FAC-4599-B9A4-5B64A18F021B}
const GUID GUID_CATIOProtocolHandlerTrait =
{ 0x3882bc9d, 0x3fac, 0x4599, { 0xb9, 0xa4, 0x5b, 0x64, 0xa1, 0x8f, 0x2, 0x1b } };


template<>
class CATTraitInfo<CATIOProtocolHandler>
{
public:
	static const GUID& 					GetTraitGUID()
	{
		return GUID_CATIOProtocolHandlerTrait;
	}
	static const int					GetTraitTag() { return CATTraitTag(-1); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeNOWAY;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTPtr<CATIOProtocolHandler>	CATIOProtocolHandlerPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOProtocolHandler_H
