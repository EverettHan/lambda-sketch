/* -*-c++-*- */
#ifndef CATPLMQueryEngineCB_H
#define CATPLMQueryEngineCB_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMQueryEngineCB"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMQueryEngineCB
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMModelBuilder.h"
#include "CATBaseUnknown.h"
#include "CATPLMOperationContext.h"
#include "CATIAdpErrorMonitor.h"
#include "CATPLMQueryEngineProgress.h"
#include "CATOmxCxxPortability.h"
#include "CATIAV5Level.h"
#include "CATPLMQEConstants.h"

template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEConstants::CATPLMQECBEvent>::manager();

/**
 * Callback definition to be used (by derivation) with CATPLMQueryEngine/CATPLMOperationContext/CATPLMFilterSession.
 */
class ExportedByCATPLMModelBuilder CATPLMQueryEngineCB : public CATBaseUnknown
{
  CATDeclareClass;
public:

  // ctor
  CATPLMQueryEngineCB();
  CATPLMQueryEngineCB(const CATPLMQueryEngineCB&) = delete;
  CATPLMQueryEngineCB(CATPLMQueryEngineCB&&) = delete;

  // dtor
  virtual ~CATPLMQueryEngineCB();

  // assignment
  CATPLMQueryEngineCB& operator=(const CATPLMQueryEngineCB&) = delete;
  CATPLMQueryEngineCB& operator=(CATPLMQueryEngineCB&&) = delete;

  // AddRef/Release
  virtual ULONG __stdcall AddRef() override final;
  virtual ULONG __stdcall Release() override final;

  /**
   * Notification method to overload.
   * this method will be called at the end of the query performed using CATPLMQueryEngine/CATPLMOperationContext/CATPLMFilterSession.
   * @param iEvent
   *    Event notified:
   *       Begin      : The query operation is started.
   *       Progress   : To notify informations on the entire process progression.
   *       Interrupted: To notify that the query has been interrupted. Not yet used.
   *       EndBlock   : A consistent set of objects has been processed (and may be visualized). Not yet used.
   *       End        : The entire query operation is over.
   * @param iError
   *    List of all errors logged during query operation.
   * @param iError
   *    List of all errors logged during query operation.
   * @param iProgress
   *    Describe informations related to the progression of query execution.
   * @return
   *    S_OK  : Notification correctly treated.
   *    E_FAIL: Otherwise.
   */
  virtual HRESULT Notify(CATPLMQEConstants::CATPLMQECBEvent iEvent, CATIAdpErrorMonitor* iError, CATPLMQueryEngineProgress* iProgress) { return E_NOTIMPL; };


  /**
  * CATPLMOperationContext specific.
  * Get the key that triggered the callback.
  * @return
  *    The key.
  */
  const CATPLMOperationKey& GetKey() const { return m_key; }
  void SetKey(const CATPLMOperationKey& iKey) { m_key = iKey; }

private:

  CATPLMOperationKey m_key{};
};
#endif
