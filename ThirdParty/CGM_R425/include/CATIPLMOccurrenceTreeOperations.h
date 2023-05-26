#ifndef CATIPLMOccurrenceTreeOperations_H
#define CATIPLMOccurrenceTreeOperations_H

#include "CATOmxSharable.h"
#include "CATPLMOccurrenceWrapper.h"
#include "CATOmxSR.h"
#include "CATPLMIdentificationAccessOccWrapper.h"

class CATListValCATPLMOccurrenceWrapper;
/**
 * Untested prototype, do not use 
 *
 * This class is dedicated to apply basic operations on an occurrence tree identified by the Root Occurrence of the tree.
 * The occurrence tree must be build with an Explicite filter (as occurrence tree built by UWP).
 * Else, methods fail.
 */
class CATIPLMOccurrenceTreeOperations: public CATOmxSharable
{
public:
  static ExportedByCATPLMIdentificationAccessOccWrapper CATOmxSR<CATIPLMOccurrenceTreeOperations> Create(const CATIPLMNavOccurrence* iRootOccurrence);

  /**
  * Add an occurrence in order to be traited by ApplyXxx methods
  *  @param iOccurrence
  *      An occurrence.
  *  @return
  *      <code>S_OK</code> the occurrence was successfuly added. <br>
  */
  virtual HRESULT Append(const CATPLMOccurrenceWrapper & iOccurrence) = 0;

  /**
  * Add a list of occurrence in order to be traited by ApplyXxx methods
  *  @param iOccurrenceList
  *      A list of occurrence.
  *  @return
  *      <code>S_OK</code> the occurrences was successfuly added. <br>
  */
  virtual HRESULT Append(const CATListValCATPLMOccurrenceWrapper & iOccurrenceList) = 0;

  /**
  * Creates occurrences, if they did not already exist, is the occurrence tree.
  *  @return
  *      <code>S_OK</code> all occurrences was successfuly added, or already exit. <br>
  *      <code>E_INVALIDARG</code> the root occurrence used in constructor is not valid for operations, probably because the occurrence tree was not built with an explicite filter.
  *      <code>E_FAIL</code> at least one occurrence has not been created. <br>
  */
  virtual HRESULT ApplyAdd() = 0;

  /**
  * Removes occurrences, if they existed, from the occurrence tree.
  *  @return
  *      <code>S_OK</code> at least one occurrence was successfuly removed. <br>
  *      <code>E_INVALIDARG</code> the root occurrence used in constructor is not valid for operations, probably because the occurrence tree was not built with an explicite filter.
  *      <code>E_FAIL</code> no occurrences has been removed. <br>
  */
  virtual HRESULT ApplyRemove() = 0;

  /**
  * Apply a filtering operation on the occurrence tree from a specified occurrence of the occurrence tree.
  * Occurrences of the appended list are created if they did not already exist 
  * Existing occurrence that not belonging to the appended list are removed.
  *  @param iFilteredRootOccurrence
  *      The occurrence from which apply the filtering. 
  *  @param iKeepTrailingPath
  *      If 1, does not remove the children occurrence of occurrence of the appended list.
  *      If 0, removes the children occurrence of occurrence of the appended list
  *  @return
  *      <code>S_OK</code> all occurrences was successfuly added, or already exit. <br>
  *      <code>E_INVALIDARG</code> the root occurrence used in constructor is not valid for operations, probably because the occurrence tree was not built with an explicite filter.
  *      <code>E_FAIL</code> at least one occurrence has not been created. <br>
  */
  virtual HRESULT ApplyFilter(CATPLMOccurrenceWrapper & iFilteredRootOccurrence, int iKeepTrailingPath) = 0;
};

#endif
