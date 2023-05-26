#ifndef CATPLMCompletionDatum_h
#define CATPLMCompletionDatum_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"

#include "CATPLMID.h"
#include "CATUnicodeString.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMID.h"
#include "CATPLMIDCollections.h"
#include "CATIPLMCacheData.h"
#include "CATIPLMQueryFilter.h"
#include "CATOmxSR.h"

class CATIPLMRecordRead;


/**
 * Class representing a component to be completed by the complete graph with all
 * relevent information that can already be known in order to acheive the completion
 */
class ExportedByCATPLMIntegrationAccess CATPLMCompletionDatum
{
  CATPLMID _plmid;
  CATUnicodeString * _discipline;
  CATUnicodeString * _description;
  CATOmxList<CATIPLMQueryFilter> _queryFilters;

  mutable CATIntToPLMIDS _ApplisMap;
public:
  CATPLMCompletionDatum();
  CATPLMCompletionDatum(const CATPLMCompletionDatum & iDatum);
  const CATPLMCompletionDatum & operator =(const CATPLMCompletionDatum & iDatum);
  CATPLMCompletionDatum(const CATPLMID & iPlmId);
  CATPLMCompletionDatum(const CATPLMID & iPlmId, const CATUnicodeString & iDiscipline);
  CATPLMCompletionDatum(const CATPLMID & iPlmId, const CATPLMCompletionDatum &iRefInfos); //transfere aussi les infos de datum sur ce plmid
  ~CATPLMCompletionDatum();
  CATPLMID GetPLMID() const;

  void SetDiscipline(const CATUnicodeString & iDiscipline);
  HRESULT GetDiscipline(CATUnicodeString & oDiscipline) const;
  void SetDescription(const CATUnicodeString & iDescription);
  HRESULT GetDescription(CATUnicodeString & oDescription) const;

  void AppendQueryFilter(CATIPLMQueryFilter *iQueryFilter);
  CATOmxList<CATIPLMQueryFilter> GetQueryFilters() const;
  /*
  * This functions manage additional connections
  */
  HRESULT SetAssociated(const CATIPLMCacheData::CATPLMAppli &iAppli, const CATPLMID &iPid, const CATPLMIDs &iPLMIDs);
  HRESULT GetAssociated(const CATIPLMCacheData::CATPLMAppli &iAppli, CATOmxIter<CATOmxPair<CATPLMID, CATPLMIDs> > &oPLMIDs) const;


};

#include "CATOmxDefaultCollecManager.h"
template <>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMCompletionDatum>::manager();

#endif
