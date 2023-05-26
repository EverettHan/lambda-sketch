#ifndef CATSGPLMHelper_H
#define CATSGPLMHelper_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"
#include "CATIOAtomics.h"
#include "CATIOProtocolHandler.h"
#include "CATCompModelIdentification.h"
#include "CATSGManager.h"

class CATPLMID;

/**
 * This class is used as an interface with the PLM side.
 * It allows the Scene Graph to acquire important information (such as Bounding Volumes)
 * and to control important tasks (like the download of LockBytes).
 */
class ExportedBySGComposites CATSGPLMHelper : public CATSGComposite
{
public:
   /**
    * Fill the CompModelIdentification with relevant information related to this ModelIdentificator.
    * Typically, this method can be used to acquire the URL of a particular ID.
    */
   virtual HRESULT GetModelIdentification(const CATModelIdentificator& iModelIdentificator, CATCompModelIdentificationPtr& oModelIdentificationComp) const = 0;

   /**
   * Fill the CompModelIdentification with relevant information.
   * 'iUrlUsageCtx' must be of type CATOmyCioUrlUsageCtx.
   */
   virtual HRESULT GetModelIdentification(CATSGManagerPtr&                  iSGManager,
                                          CATBaseUnknown*                   iUrlUsageCtx,
                                          CATPLMID&                         iPLMID,
                                          CATCompModelIdentificationPtr&    oModelId) const = 0;

   /**
   * Fill the CompModelIdentification with relevant information.
   * 'iUrlUsageCtx' must be of type CATOmyCioUrlUsageCtx.
   */
   virtual HRESULT GetModelIdentification(CATSGManagerPtr&                  iSGManager,
                                          CATBaseUnknown*                   iUrlUsageCtx,
                                          CATPLMID&                         iPLMID,
                                          const CATMathPoint&               iBBoxMin,
                                          const CATMathPoint&               iBBoxMax,
                                          CATCompModelIdentificationPtr&    oModelId) const = 0;

   /**
   * @deprecated
   * Fill the CompModelIdentification with relevant information.
   * 'iUrlUsageCtx' must be of type CATOmyCioUrlUsageCtx.
   */
   virtual HRESULT GetModelIdentification(CATSGManagerPtr&                  iSGManager,
                                          CATBaseUnknown*                   iUrlUsageCtx,
                                          const CATUnicodeString&           iUrl,
                                          CATPLMID&                         iPLMID,
                                          CATCompModelIdentificationPtr&    oModelId) const = 0;

   /**
   * @deprecated
   * Fill the CompModelIdentification with relevant information.
   * 'iUrlUsageCtx' must be of type CATOmyCioUrlUsageCtx.
   */
   virtual HRESULT GetModelIdentification(CATSGManagerPtr&                  iSGManager,
                                          CATBaseUnknown*                   iUrlUsageCtx,
                                          const CATUnicodeString&           iUrl,
                                          CATPLMID&                         iPLMID,
                                          const CATMathPoint&               iBBoxMin,
                                          const CATMathPoint&               iBBoxMax,
                                          CATCompModelIdentificationPtr&    oModelId) const = 0;

   /**
    * @deprecated: You should use CATPLMID instead of CATUuid.
    */
   virtual HRESULT GetModelIdentification(CATSGManagerPtr&                  iSGManager,
                                          CATBaseUnknown*                   iUrlUsageCtx,
                                          const CATUnicodeString&           iUrl,
                                          const CATUuid&                    iPhysicalId,
                                          const CAT3DBoundingSphere&        iBV,
                                          CATCompModelIdentificationPtr&    oModelId) const = 0;

   /**
   * @deprecated: You should use CATPLMID instead of CATUuid.
   */
   virtual HRESULT GetModelIdentification(CATSGManagerPtr&                  iSGManager,
                                          CATBaseUnknown*                   iUrlUsageCtx,
                                          const CATUnicodeString&           iUrl,
                                          const CATUuid&                    iPhysicalId,
                                          const CATMathPoint&               iBBoxMin,
                                          const CATMathPoint&               iBBoxMax,
                                          CATCompModelIdentificationPtr&    oModelId) const = 0;

   /**
    * Extract PhysicalId of the RepRef associated with iComponent.
    * Warning: This method needs a CATPLMExtendedNavigationUnlocker instanciated in the callstack.
    */
   virtual HRESULT GetPhysicalId(CATBaseUnknown* iComponent, CATUuid& oPhysicalId) const = 0;

   virtual HRESULT GetILB2(CATBaseUnknown* iComponent, CATILockBytes2*& opILB2) const = 0;

   /**
    * Delete all context-related information (e.g. accumulated requests yet to be executed).
    */
   virtual HRESULT ClearForContext(CATSGContext* iContext) = 0;

   /**
    * Add a URL to the list of URLs to download.
    */
   virtual HRESULT StreamTo(CATCompModelIdentificationPtr& iModelIdentification, const float iPriority) = 0;
   virtual HRESULT ForceStreamTo(CATCompModelIdentificationPtr& iModelIdentification) = 0;
   virtual CATBoolean IsReadyForStreamTo() = 0;
   /**
    * Trigger the download of the requested URLs.
    */
   virtual HRESULT UpdateDownloadRequests(const bool iWaitForEndOfDownloads) = 0;

   /**
    * Check if download request was successful.
    */
   virtual HRESULT GetLoadLevel(CATCompModelIdentificationPtr& iModelIdentification) const = 0;

   /**
    * Send an asynchronous BoundingBox request to the server.
    * When the result of the request is available (on success and/or failure), the SGManager will be called to finish its treatment on the Rep.
    */
   virtual HRESULT AsyncRequestBoundingBox(CATSGManagerPtr& iSGManager, CATCompModelIdentificationPtr& iModelId, CAT3DRep* iRep, CATCGRInfo* iCGRInfo = NULL) = 0;

   /**
    * If the request for BoundingBox failed for the first time, try again with default
    */
   virtual HRESULT TryBVQueryFallback(CATSGManagerPtr& iSGManager, CATCompModelIdentificationPtr& iModelId, CAT3DRep* iRep, CATCGRInfo* iCGRInfo, bool & ioFallbackStarted) = 0;
   /**
    * Trigger the execution of the BoundingBox query.
    */
   virtual HRESULT FlushBoundingBoxQuery() = 0;

   /**
    * Returns TRUE if the variable LDH_PROGRESSIVE_DOWNLOAD has been defined
    * and is equal to '1'. Returns FALSE otherwise.
    */
   virtual CATBoolean GetVarLDH_PROGRESSIVE_DOWNLOAD() const = 0;
};

// {C6D887B1-3587-4DAE-BABB-18EC4FD9AD54}
const GUID GUID_CATSGPLMHelperTrait =
{ 0xc6d887b1, 0x3587, 0x4dae, { 0xba, 0xbb, 0x18, 0xec, 0x4f, 0xd9, 0xad, 0x54 } };



template<>
class CATTraitInfo<CATSGPLMHelper>
{
public:
	static const GUID&                      GetTraitGUID()
	{
		return GUID_CATSGPLMHelperTrait;
	}
	static const int                        GetTraitTag() { return CATTraitTag(-1); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeParticular;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTPtr<CATSGPLMHelper>	CATSGPLMHelperPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATSGPLMHelper_H

