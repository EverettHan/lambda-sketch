/* -*-c++-*- */
#ifndef CATPLMOperationSandbox_H
#define CATPLMOperationSandbox_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMOperationSandbox"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMOperationSandbox
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATIAV5Level.h"
#include "CATPLMOperationContext.h"
#include "CATPLMOperationAccess.h"
#include "CATPLMQEDef.h"
#include "CATPLMLoadingSpec.h"

#include "CATOmxVector.h"
#include "CATOmxSharable.h"
#include "CATOmxDeprecated.h"
class CATIPLMRecordRead;
class CATPLMSandboxBag;
class CATProxySpace;

class ExportedByCATPLMModelBuilder CATPLMSBObject : public CATOmxSharable
{
public:
  // ctor
  CATPLMSBObject() = default;
  CATPLMSBObject(const CATPLMSBObject&) = delete;
  CATPLMSBObject(CATPLMSBObject&&) = delete;

  // dtor
  virtual ~CATPLMSBObject() = default;

  // assignment
  CATPLMSBObject& operator=(const CATPLMSBObject&) = delete;
  CATPLMSBObject& operator=(CATPLMSBObject&&) = delete;

  // Getter / Setter
  void SetRecord(const CATIPLMRecordRead* iRecord) { m_record = iRecord; }
  CATOmxSR<CATIPLMRecordRead> GetRecord() const { return m_record; }

  void SetState(CATPLMLoadingState iState) { m_state = iState; }
  CATPLMLoadingState GetState() const { return m_state; }

  // Deprecated getter (useless HRESULT)
  // Waiting for migration from CATPLMFstRelations/CATPLMFstRelServices.m/src/CATPLMFstNavQueries.cpp
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent GetRecord method.")
    HRESULT GetRecord(CATIPLMRecordRead*& oRecord) const
#else
  HRESULT GetRecord(CATIPLMRecordRead*& oRecord) const
#endif
  {
    if (oRecord) return E_INVALIDARG;

    CATOmxSR<CATIPLMRecordRead> srTmp(m_record);
    oRecord = srTmp.GiveBack();
    return S_OK;
  }

private:

  CATOmxSR<CATIPLMRecordRead> m_record{ nullptr };
  CATPLMLoadingState          m_state{ CATPLMLoadingState::Undefined };
};

class ExportedByCATPLMModelBuilder CATPLMSBPath : public CATOmxSharable
{
public:
  // ctor
  CATPLMSBPath() = default;
  CATPLMSBPath(const CATPLMSBPath&) = delete;
  CATPLMSBPath(CATPLMSBPath&&) = delete;

  // dtor
  virtual ~CATPLMSBPath() = default;

  // assignment
  CATPLMSBPath& operator=(const CATPLMSBPath&) = delete;
  CATPLMSBPath& operator=(CATPLMSBPath&&) = delete;

  // Getter / Setter
  const CATOmxVector<CATPLMSBObject>& GetObjects() const { return m_path; }
  void SetObjects(const CATOmxVector<CATPLMSBObject>& iObjects) { m_path = iObjects; }
  void AddObject(CATPLMSBObject* ioObject) { if (ioObject) m_path.Append(ioObject); }
  int PathSize() const { return m_path.Size(); }

private:
  CATOmxVector<CATPLMSBObject> m_path{};
};

class ExportedByCATPLMModelBuilder CATPLMSBBlock : public CATBaseUnknown
{
  CATDeclareClass;

public:
  // ctor
  CATPLMSBBlock(unsigned int iBlockId, boolean iValid = true);
  CATPLMSBBlock(const CATPLMSBBlock&) = delete;
  CATPLMSBBlock(CATPLMSBBlock&&) = delete;

  // dtor
  virtual ~CATPLMSBBlock();

  // AddRef/Release
  virtual ULONG __stdcall AddRef() override final;
  virtual ULONG __stdcall Release() override final;

  // assignment
  CATPLMSBBlock& operator=(const CATPLMSBBlock&) = delete;
  CATPLMSBBlock& operator=(CATPLMSBBlock&&) = delete;

  // Hash & compare
  static int Compare(const CATPLMSBBlock* iBlock1, const CATPLMSBBlock* iBlock2);
  CATHashKey Hash() const { return m_blockId; }

  // Getter / Setter
  const CATOmxVector<CATPLMSBPath>& GetPaths() const { return m_paths; }
  void AddPath(CATPLMSBPath* iPath) { if (iPath)  m_paths.Append(iPath); }
  void AddPaths(const CATOmxVector<CATPLMSBPath>& iPaths) { m_paths.Append(iPaths); }
  int BlockSize() const { return m_paths.Size(); }

  void SetValid(boolean iValid) { m_valid = iValid; }
  boolean IsValid() const { return m_valid; }

  void SetBlockId(unsigned int iBlockId) { m_blockId = iBlockId; }
  unsigned int GetBlockId() const { return m_blockId; }

  boolean ArePathsSupported() const { return m_pathSupport; }
  void SetPathSupport(boolean iPathSupport) { m_pathSupport = iPathSupport; }

  boolean ArePathsReversed() const { return m_reversePaths; }
  void SetPathReverse(boolean iPathReverse) { m_reversePaths = iPathReverse; }

private:

  CATOmxVector<CATPLMSBPath> m_paths{};
  unsigned int               m_blockId{ 0 };
  boolean                    m_valid{ true };
  boolean                    m_pathSupport{ true };
  boolean                    m_reversePaths{ false };
};

/**
 * An Operation Sandbox is quite the same thing than an Operation Context, except that:
 *   - It is linked to a corresponding Operation Context (inherits from it's applied filters)
 *   - It uses the same set of profiles
 *   - It does not uses the same data model builder. For exemple, when using OC_Session sandbox name, it
 *     does not produce a PC2 and PLMOccurrences session as the equivalent Operation Context would have,
 *     but a light data-mode, a nut-shell on top of server query result (CATPLMSBBlock\CATPLMSBPath\CATPLMSBObject).
 *   - Every single operation added can be validated or not, depending on applicative criterias or user selection
 *   - The global sandbox result can be commited in a regular OperationContext. In that case:
 *       * Only validated Operations are kept
 *       * queries are not executed twice (not implmented yet)
 *
 * Sample: To construct a sandbox to perform an Explore from a root product:
 *   CATPLMOperationKey operationKey = ...;
 *   CATPLMID plmid_rootPRODUCT = ...;
 *   CATPLMQueryEngineCB *myCallback1, myCallback2 = ...;
 *   CATIAdpErrorMonitor *errorMonitor1, errorMonitor2 = ...;
 *   CATPLMOperationContext *myContext = ...;
 *   CATOmxSR<CATPLMOperationSandbox> srSandbox (CATPLMOperationSandbox::Factory(operationKey, OC_Session));
 *   if (srSandbox) {
 *       CATPLMOperationKey newKey;
 *       CATPLMLoadingSpec spec = CATPLMLoadingSpec::Factory(LS_Explore);
 *       CATAssert(SUCCEEDED(srSandbox->LoadNetwork(newKey, plmid_rootPRODUCT, spec)));
 *
 *       HRESULT rc = srSandbox->Commit(newKey, myCallback1, errorMonitor1);
 *       if (rc == PLMOC_S_ASYNC_QUERY_STARTED) {
 *           ...;
 *       }
 *       else if (rc == PLMOC_S_SYNC_QUERY_STARTED) {
 *           ...;
 *       }
 *
 *       CATPLMOperationKey newContextKey;
 *       CATAssert(SUCCEEDED(myContext->LoadSandbox(newContextKey, newKey, sandbox)));
 *       rc = myContext->Commit(newContextKey, myCallback2, errorMonitor2);
 *       if (rc == PLMOC_S_ASYNC_QUERY_STARTED) {
 *           ...;
 *       }
 *       else if (rc == PLMOC_S_SYNC_QUERY_STARTED) {
 *           ...;
 *       }
 *
 *   }
 */
class ExportedByCATPLMModelBuilder CATPLMOperationSandbox : public CATPLMOperationAccess
{
  CATDeclareClass;

public:

  /**
   * Get a named operation sandbox - DO NOT USE - DEPRECATED.
   * As of today, only "Session" Operation Sandbox is supported, designed to contruct a valide Session.
   * @param iKey
   *    Key of the corresponding Operation Context.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return CATBaseUnknown#Release
   *    Operation Context to work with.
   */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent FactoryOS method.")
    static CATPLMOperationSandbox*
    Factory(const CATPLMOperationKey& iContextKey,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);
#else
  static CATPLMOperationSandbox*
    Factory(const CATPLMOperationKey& iContextKey,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);
#endif

  /**
   * Get a named operation sandbox.
   * As of today, only "Session" Operation Sandbox is supported, designed to contruct a valide Session.
   * @param iKey
   *    Key of the corresponding Operation Context.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return
   *    Operation Context to work with.
   */
  static CATOmxSR<CATPLMOperationSandbox>
    FactoryOS(const CATPLMOperationKey& iContextKey,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);

  /**
   * Get a named operation sandbox  - DO NOT USE - DEPRECATED.
   * As of today, only "Session" Operation Sandbox is supported, designed to contruct a valide Session.
   * @param iKey
   *    Key of the corresponding Operation Context.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return CATBaseUnknown#Release
   *    Operation Context to work with.
   */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent FactoryOS method.")
    static CATPLMOperationSandbox*
    Factory(const CATPLMOperationAccess* iOperationAccess,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);
#else
  static CATPLMOperationSandbox*
    Factory(const CATPLMOperationAccess* iOperationAccess,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);
#endif

  /**
   * Get a named operation sandbox.
   * As of today, only "Session" Operation Sandbox is supported, designed to contruct a valide Session.
   * @param iKey
   *    Key of the corresponding Operation Context.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return
   *    Operation Context to work with.
   */
  static CATOmxSR<CATPLMOperationSandbox>
    FactoryOS(const CATPLMOperationAccess* iOperationAccess,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);

  CATPLMOperationSandbox(const CATPLMOperationSandbox&) = delete;
  CATPLMOperationSandbox(CATPLMOperationSandbox&&) = delete;

  CATPLMOperationSandbox& operator=(const CATPLMOperationSandbox&) = delete;
  CATPLMOperationSandbox& operator=(CATPLMOperationSandbox&&) = delete;

  /**
   * Get the list of assciated (or created) CATPLMSBBlock objects
   * at the end of operations execution.
   * To be used when triggered on CATPLMQueryEngineCB::Notify.
   * @return
   *    S_OK  : Getting the list is ok.
   *    E_FAIL: Otherwise.
   */
  HRESULT GetResults(CATOmxVector<CATPLMSBBlock>& oResults) const;

  /**
   * Get the list of assciated (or created) root objects (occurrences if applicable, refrences if not)
   * at the end of operations execution.
   * To be used when triggered on CATPLMQueryEngineCB::Notify.
   * @return
   *    S_OK  : Getting the list is ok.
   *    E_FAIL: Otherwise.
   */
  virtual HRESULT GetResults(CATListValCATBaseUnknown_var& oResults) const override final;

  /**
   * Get the list of assciated (or created) root objects (occurrences if applicable, refrences if not)
   * at the end of operations execution.
   * To be used when triggered on CATPLMQueryEngineCB::Notify.
   * @return
   *    S_OK  : Getting the list is ok.
   *    E_FAIL: Otherwise.
   */
  virtual HRESULT GetResults(CATPLMCBUOrderedSet& oResults) const override final { return CATPLMOperationAccess::GetResults(oResults); }

  HRESULT AddObjectsToContext(const CATPLMIDs& objects);
  HRESULT AddObjectToContext(const CATPLMID& object);
  void SetProxySpace(const CATProxySpace& iProxySpace);

  virtual HRESULT LoadBranch(const CATPLMOperationInput& iBranch, const CATPLMLoadingSpec& iSpec, int iEndOfPath = 0, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable)  override final { return E_NOTIMPL; }
  virtual HRESULT LoadPointed(const CATPLMOperationInput& iPointing, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable)  override final { return E_NOTIMPL; }
  virtual HRESULT EnrichObjects(const CATPLMOperationInputs& iObjects, const CATOmxArray<CATOmxKeyString>& iAttributes, const CATOmxArray<CATOmxKeyString>& iExtensions)  override final { return E_NOTIMPL; }
  virtual HRESULT LoadInContext(CATPLMLoadInContextTarget iLoadInContextTarget, const CATPLMOperationInput& iInput, const CATPLMID& iContext, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable)  override final { return E_NOTIMPL; }
  virtual HRESULT LoadSandbox(CATPLMOperationSandbox* iSandbox)  override final { return E_NOTIMPL; }
  virtual HRESULT LoadSandbox(CATPLMOperationSandbox* iSandbox, const CATPLMLoadingSpec& iSpec)  override final { return E_NOTIMPL; }
  virtual HRESULT RemoveRoot(const CATPLMID& iPlmid, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge)  override final { return E_NOTIMPL; }
  virtual HRESULT RemoveBranch(const CATPLMID& iPlmid, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge)  override final { return E_NOTIMPL; }
  virtual HRESULT BreakLog()  override final { return E_NOTIMPL; }

private:

  virtual ~CATPLMOperationSandbox() = default;
  CATPLMOperationSandbox(const CATPLMOperationKey& iContextKey, CATPLMOperationContext* iContext);

  CATPLMOperationKey m_key_context;
};
#endif
