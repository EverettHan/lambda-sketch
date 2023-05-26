#ifndef CATIPLMUpdateSessionAfterShortTransaction_H
#define CATIPLMUpdateSessionAfterShortTransaction_H

#define AuthorizedModule 999
#define CATPLMIntegrationInterfaces  AuthorizedModule
#define CATPLMEditabilityImpl        AuthorizedModule
#define CATPLMIntegration            AuthorizedModule
#define CATItgTestLib                AuthorizedModule
#define CATPLMBaseLifeCycleCmdWidget AuthorizedModule // FUN102410, for web-in-win maturity command session refresh
#define CATPLMChangeMaturityWidget   AuthorizedModule // FUN102410, for web-in-win maturity command session refresh
#define CATPLMIntegrationAccess      AuthorizedModule // FUN126998, precommit bls integration in CATAdpProtectedDeleteServices
#define CATPLMIntegrationAccessBase  AuthorizedModule // FUN126998, precommit bls integration 

#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header is for internal use only
// Fatal error on solaris
@error
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMEditabilityImpl
#undef CATPLMIntegration
#undef CATItgTestLib
#undef CATPLMBaseLifeCycleCmdWidget
#undef CATPLMChangeMaturityWidget
#undef CATPLMIntegrationAccess
#undef CATPLMIntegrationAccessBase

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATPLMShortTransactionType.h"
#include "CATPLMIntegrationInterfaces.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxDefaultCollecManager.h"

class CATPLMTypeH;
class CATOmxKeyValueBlock;
class CATPLMCEStamp;
class CATProxySpace;
class CATIPLMSpace;
class CATIPLMRecordRead;
class CATPLMID;
template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMID>::manager();

/**
 * This interface is dedicated to session update after a server write transaction
 *
 * USAGE IS FORBIDDEN unless allowed by CATPLMIntegration team
 *
 * The protocol is complex and must be carefuly respected,
 * other usages will lead to client data corruption (even if your wonderful 'redwire' scenario with one product does not crash)
 * Use this API only if your understand cestamp mechanism and how session/server synchronization works.
 * Read carefuly the whole API documentation before using it.
 *
 * The methods appear in the same order as they must be called.
 */
class CATIPLMUpdateSessionAfterShortTransaction : public CATBaseUnknown
{
public:
  /**
   * factory
   * @param iTransactionType: the type of server transaction (must be the correct)
   */
  static ExportedByCATPLMIntegrationInterfaces HRESULT Create(CATPLMShortTransactionType iTransactionType, CATIPLMUpdateSessionAfterShortTransaction*& oObj);

  /** Set space to be refreshed. */
  virtual HRESULT SetSpace(const CATProxySpace& iSpace) = 0;
  virtual HRESULT SetSpace(const CATIPLMSpace* iSpace) = 0;

  /**
   * Register an object before sending it to server
   * @param iId: id of the object (no path)
   * @param oSessionCEStamp: session cestamp, NULL if object is not in session or does know its cestamp
   *
   * By calling this method you SWEAR that you will pass oSessionCEStamp to server transaction
   * (this means that server transaction will fail if oSessionCEStamp is not synchronized)
   */
  virtual HRESULT AddObject(const CATPLMID& iId, CATPLMCEStamp& oSessionCEStamp) = 0;

  /** Call this method before actually running server operation */
  virtual HRESULT StartShortTransaction() = 0;

  /** Call this method after running server operation and before starting calling RegisterUpdate*/
  virtual HRESULT StartSessionRefresh() = 0;

  /**
   * Register update of session with provided data.
   *
   * Notice it is possible to call RegisterUpdate several times on the same object
   * for example, calling
   *   RegisterUpdate(x,"", {a: 1, b: 2})
   * and then
   *   RegisterUpdate(x,"", {a: 3, c: 4})
   * is equivalent to
   *   RegisterUpdate(x,"", {a: 3, b: 2, c: 4})
   *
   * No side-effect on session (deferred to UpdateSession)
   *
   * Attributes values must come from server
   */
  virtual HRESULT RegisterUpdate(const CATPLMID& iId, const CATPLMTypeH& iExtension, const CATOmxKeyValueBlock& iAttributes) = 0;
  virtual HRESULT RegisterUpdate(const CATPLMID& iId, const CATPLMCEStamp& iCEStamp) = 0;
  virtual HRESULT RegisterUpdate(CATIPLMRecordRead& iRecord) = 0;
  virtual HRESULT RegisterExtensionDeletion(const CATPLMID& iId, const CATPLMTypeH& iExtension) = 0;

  /**
   * "light refresh" consists in retrieving object state from server (through a query) and updating session state accordingly.
   * only a small set of modifications are allowed (including some basic attributes and customer attributes, excluding modeler attributes, streams or relations).
   * dirty objects cannot be updated unless registered through AddObject method call
   * RegisterLightRefresh and RegisterUpdate are exclusive.
   *
   * this method must be used exclusively for server calls that do not return updated attributes.
   *
   * iForReidentification : this mode is here to work around a specific behavior on stream descriptors
   *                        which changes URL even if streams are shared.
   */
  virtual HRESULT RegisterLightRefresh(const CATPLMID& iId, bool iForReidentification = FALSE) = 0;

  /**
   * Update session based on RegisterUpdate calls
   * component not being loaded in session is fine (in such case nothing is done)
   *
   * LocalSave repository is updated
   * xPDMLog (whatever it is) is updated
   */
  virtual HRESULT UpdateSession() = 0;

  /*
  * Some PLMID could not have been refreshed, this may be an error case and caller should process this
  * accordingly. In most case, we are in a session with components not refreshed (and CEStamp not refreshed)
  * but it may be worse.
  */
  virtual CATOmxOrderedOSet<CATPLMID> GetNotRefreshed() const = 0;

};

#endif
