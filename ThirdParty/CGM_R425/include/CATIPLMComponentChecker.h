#ifndef CATIPLMComponentChecker_H
#define CATIPLMComponentChecker_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Private
 * @usage U3
 */
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMTransaction                 AuthorizedModule
#define CATOxiComponentRecovery           AuthorizedModule
#define CATPLMComponentChecker            AuthorizedModule
#define CATPLMIdentification              AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOmbLinkTrader                  AuthorizedModule
#define CATPLMREBriefcase                 AuthorizedModule
#define CATPLMREReplicationAccess         AuthorizedModule
#define CATPLMREDataAccessor              AuthorizedModule
#define CATPLMReplicationEngineBase       AuthorizedModule
#define CATPLMREOperationManager          AuthorizedModule
#define CATPLMReplicationEngineCommon     AuthorizedModule
#define CATPLMREPlug                      AuthorizedModule
#define CATPLMReplicationEngineXML        AuthorizedModule
#define TransferDataServices              AuthorizedModule
#define TransitionEngine                  AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMSynchronization             AuthorizedModule
#define CATPLMComponentCheckerBatchUI     AuthorizedModule
#define CATOxiComponentCheckerBatch       AuthorizedModule
#define CATOxiComponentChecker            AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule 
#else
#error Forbidden access to CATIPLMComponentChecker from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef CATPLMTransaction
#undef CATOxiComponentRecovery
#undef CATPLMComponentChecker
#undef CATPLMIdentification
#undef CATPLMIdentification_PLM
#undef CATOmbLinkTrader
#undef CATPLMREBriefcase
#undef CATPLMREReplicationAccess
#undef CATPLMREDataAccessor
#undef CATPLMReplicationEngineBase
#undef CATPLMREOperationManager
#undef CATPLMReplicationEngineCommon
#undef CATPLMREPlug
#undef CATPLMReplicationEngineXML
#undef TransferDataServices
#undef TransitionEngine
#undef CATPLMIntegration
#undef CATPLMSynchronization
#undef CATPLMComponentCheckerBatchUI
#undef CATOxiComponentCheckerBatch
#undef CATOxiComponentChecker
// ----------------------------------------------------------------------------------------------------------------------
#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATPLMComponentCheckerListener.h"
#include "CATLISTV_CATComponentId.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMComponentChecker;
#else
extern "C" const IID IID_CATIPLMComponentChecker;
#endif

class CATPLMComponentCheckerListener;
class CATPLMSessionOperationSet;
class CATPLMDownloader;
class CATPLMComponentCheckerParameters;
class CATPLMEngineErrorReporter;

/**
* PLM Integration Checker
* Checking Database consistency after remote operation
*/
class ExportedByCATPLMIdentification CATIPLMComponentChecker : public CATBaseUnknown
{
  friend class CATPLMComponentCheckerDefaultListener;

  CATDeclareInterface;

public:

  /**
  * Check component integrity in database
  *
  * @param iListToBeChecked
  *        List of components to be checked
  * @param iReporting
  *        Object managing reporting
  * @param iComponentCheckerParameters
  *        Checker parameters
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dt>E_FAIL</dt>
  *     <dd>An error occured.</dd>
  *   </dl>
  */
  virtual HRESULT CheckDatabaseIntegrity(CATOmxArray<CATPLMID> & iListPLMIDsToBeChecked, CATPLMComponentCheckerListener & iListener, CATPLMComponentCheckerParameters * iParameters = 0) const = 0;

  /**
  * Check component integrity in database (Warning global database introspection)
  *
  * @param iListTypeIdsToBeChecked
  *        List of TypeIds to be checked
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dt>E_FAIL</dt>
  *     <dd>An error occured.</dd>
  *   </dl>
  */
  virtual HRESULT CheckDatabaseIntegrity(CATPLMTypeIds & iListTypeIdsToBeChecked, CATPLMComponentCheckerListener & iListener, CATPLMComponentCheckerParameters * iParameters = 0) const = 0;

  /**
  * Check component integrity in session and database after Save
  *
  * @param iComponentsToBeChecked
  *        The components to be checked
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dt>E_FAIL</dt>
  *     <dd>An error occured.</dd>
  *   </dl>
  */
  virtual HRESULT CheckDatabaseAndSessionIntegrityAfterSave(const CATLISTV(CATComponentId) & iComponentsToBeChecked, CATPLMEngineErrorReporter * iReporter) const = 0;

  /**
  * Check component integrity in session after Open
  *
  * @param iComponentsToBeChecked
  *        The components to be checked
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dt>E_FAIL</dt>
  *     <dd>An error occured.</dd>
  *   </dl>
  */
  virtual HRESULT CheckSessionIntegrityAfterOpen(const CATLISTV(CATComponentId) & iComponentsToBeChecked, CATPLMEngineErrorReporter * iReporter) const = 0;

protected:

  /**
  * Internal usage
  */
  virtual HRESULT OnRelationalCorruptionDefaultDump(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator) const = 0;

  /**
  * Internal usage
  */
  virtual HRESULT OnRelationalCorruptionDefaultDump(const CATPLMID & iPLMID, const CATOmbRelationalCheckSum & iCheckSum) const = 0;

    /**
  * Internal usage
  */
  virtual HRESULT OnMetadatasCorruptionDefaultDump(const CATPLMID & iPLMID, const CATPLMRelationalCheckSumComparator & iComparator) const = 0;

  /**
  * Internal usage
  */
  virtual HRESULT OnMetadatasCorruptionDefaultDump(const CATPLMID & iPLMID, const CATOmbRelationalCheckSum & iCheckSum) const = 0;

  /**
  * Internal usage
  */
  virtual HRESULT OnStreamIterationCorruptionDefaultDump(const CATPLMID & iPLMID, const CATUnicodeString & iComments) const = 0;
 /**
  * Internal usage
  */
  virtual HRESULT OnStreamSizeWarningDefaultDump(const CATPLMID & iPLMID, const CATUnicodeString & iComments) const = 0;

};



#endif
