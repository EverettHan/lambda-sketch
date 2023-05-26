#ifndef __CATOmyIncidentGroup_H
#define __CATOmyIncidentGroup_H

// System
#include "CATError.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
// ObjectModelerSystem
#include "CATOmyIncidentCollect.h"
#include "CATIOmyIncidentCell.h"

/**
* Manages groups of incidents into @href CATIOmyIncidentCollector stack
* 
* @href CATOmyIncidentGroup to create a new group
*       this group becomes the current one
* @href CATIOmyIncidentCollector::CreateIncidentCell to create new errors cells in this group
* @href CATOmxIter<CATIOmyIncidentCell> CATOmyIncidentGroup#Iterator to get an iterator on error group
* @href CATOmxIter#Next to iterate on group errors handled via @href CATIOmyIncidentCell#GetError
* The current group is ended at the end of the current group scope:
*       - incidents in group are concatenated to previous group (or no group)
*       - current group is terminated and no more usable
*       - last created group (or no group) becomes the current one 
* All errors created in any group are logged to traces but may be removed by user before use,
* using @href CATOmyIncidentGroup#Summarize(a new error)
*       - incidents in current group are removed from group and deleted
*       - incidents in current group are replaced by a new error that becomes the only one in the group.
*       - so, be careful: a series of Summarize on same group only keeps in group/collector the error created by the LAST Summarize.
* 
* CATOmyIncidentGroup IncidentGroup;  // declares a new group on the heap
*  ...
* CreateIncidentCell(...);
* CallAService{ ..CreateIncidentCell(...)...};
* HRESULT HR = CallAnotherService();
* ...
* CATIOmyIncidentCell* pCell = NULL;
* CATOmxIter<CATIOmyIncidentCell> Iter = IncidentGroup.Iterator();
* while (pCell = Iter.Next())
* {
*   CATOmxSR<CATError> pError = pCell->GetError();
*    ...
* }
* if (some condition/specific Errors/FAILED(HR)..etc) 
*   IncidentGroup.Summarize(ErrorKey, Catalog, Severity, eventual Parameters);
*/

class ExportedByCATOmyIncidentCollect CATOmyIncidentGroup
{
public:

  /**
	* Declares a new incident cells group to be managed by @href CATIOmyIncidentCollector stack
  * This Group becomes the current one.
  * All Incidents created by @href CATIOmyIncidentCollector.CreateIncidentCell methods in this CATOmyIncidentGroup scope belong to this group.
  * When group scope terminates, all its incidents are appended to the previous one (or no group), that becomes the current one.
  * @return 
	*      The group identifier.
  * All incidents created between ThisGroup=StartAGroup and next EndTheGroup(ThisGroup) or next AnotherGroup=StartAGroup() are appended to ThisGroup
	*/
  CATOmyIncidentGroup();
  virtual ~CATOmyIncidentGroup();

  /**
	* Summarizes this incident group into a new incident
  * All incidents in this group  are removed from collector and replaced by the new input error.
  * This new error created is appended to collector, into the previous group created (or no group)
  * @param iErrorKey
	*        the key describing this specific error in a given error messages catalog
	* @param iErrorCatalog
	*        the error messages catalog the error is described into
	* @param iSeverity
	*        the severity to be set on this Error
	* @param iContext
	*        Any text formatted information that really helps debugging error cause. 
  * @param iReqParms
	*        The table of parameters to be added to error message, in numbering order : /p1, /p2..etc
	*        The Request parameter tables if composite (Request-Diagnostic-Advice) message, the single parameter table otherwise.
  * @param iDiagParms
	*        The Diagnostic parameter table if composite (Request-Diagnostic-Advice) message, empty table otherwise.
  * @param iAdvParms
	*        The Advice parameter table if composite (Request-Diagnostic-Advice) message, empty table otherwise.
  * @return 
	*      The error created from group content and logged in all active logs (stderr, DSYSystrace, Error Statistics preference, OMB_XML_TRACE, log_abend..) 
	*/
  CATOmxSR<CATError> Summarize(const HRESULT iHR, const char *iErrorKey, const char* iErrorCatalog, CATErrorType iSeverity, const CATUnicodeString& iContext, HRESULT& oHGroup);
  CATOmxSR<CATError> Summarize(const HRESULT iHR, const char *iErrorKey, const char* iErrorCatalog, CATErrorType iSeverity, const CATUnicodeString& iContext, const CATOmxArray<CATUnicodeString>& iParms, const CATOmxArray<CATUnicodeString>& iDiagParms, const CATOmxArray<CATUnicodeString>& iAdvParms, HRESULT& oHGroup);

 /**
	* Iterates on all incidents created into this group
  * @return 
	*      each error successively created in this group
	*/
  CATOmxIter<CATIOmyIncidentCell> Iterator();

 /**
   * Empties this incident group
  * All incidents currently in this group are removed from collector
	*/
  void Empty();

 /**
  * Check for Severe errors into this incident group
  * returns TRUE if at least one fatal or critical Error in this group
  * @return 
	*      TRUE if at least one fatal or critical Error in this group
	*/
  CATBoolean SevereErrors();

private:
  unsigned int _Group;

};
#endif
