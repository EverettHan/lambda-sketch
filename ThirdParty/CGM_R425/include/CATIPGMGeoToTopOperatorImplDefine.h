#include "CATIPGMTopOperatorImplDefine.h"
#include "CATGeoToTopOperatorExt.h"

// ---------- CATGeoToTopOperator

void CATCGM_ITF_IMPL_CLASS::SetTolerance(double iTol)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetTolerance(iTol);
}

double CATCGM_ITF_IMPL_CLASS::GetTolerance() const
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetTolerance();
}

void CATCGM_ITF_IMPL_CLASS::SetUseGeometriesInJournalItems(int iUseGeometriesInJournalItems)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
#ifdef CATIACGMR420CAA
  return HandledObject.SetUseGeometriesInJournalItems(iUseGeometriesInJournalItems);
#else
  //Temporary code, to be removed when delivery will be closed for R27/R419.
  CATGeoToTopOperatorExt * Extensible = (CATGeoToTopOperatorExt *)HandledObject.GetTopExtensible();
  if (Extensible)
  {
    Extensible->SetUseGeometriesInJournalItems(iUseGeometriesInJournalItems);
  }
#endif
}

void CATCGM_ITF_IMPL_CLASS::Report(
    CATCGMJournal ::Type iType,
    const CATGeometry *iBeforeObjects,
    const CATGeometry *iAfterObjects,
    CATCGMJournalInfo *iOptionalInfo)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.Report(
    iType,
    iBeforeObjects,
    iAfterObjects,
    iOptionalInfo);
}

CATCGMJournalList *CATCGM_ITF_IMPL_CLASS::GetReport()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetReport();
}

