#ifndef CATIOccurrenceServices3_H
#define CATIOccurrenceServices3_H

#include "CATPLMModelerOccInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxIter.h"
#include "CATOmxList.h"
#include "CATPLMID.h"

/**
 * helpers on occurrences.
 *
*  notice that:
 *   all methods only deal with "model" occurrences (genuine occurrences implemented in PLMOccurrenceBase framework)
 *   and will fail on pseudo occurrences (objects shipping their own implementation of CATIPLMNav(Rep)Occurrence, most of the time inconsistently)
 *
 *   there is no distinction between instances/occurrences and rep instances/rep occurrences
 */
class CATIOccurrenceServices3
{
public:
  static ExportedByCATPLMModelerOccInterfaces CATIOccurrenceServices3& Get();

#define OCC_MATCH_FULL_PATH            0x1
#define OCC_MATCH_TRAILING_PATH        0x2
#define OCC_MATCH_SHORT_TRAILING_PATH  0x4
  /**
   * Find occurrences (or rep occurrences) matching input path of instance in the context of another occurrence
   * @param iFatherOccurrence
   *   a father occurrence used to filter results.
   *   Can be NULL meaning no filtering (use with care)
   * @param iPath
   *   path of instance to match (must be non empty and contain only non NULL pointers to instances or rep instances)
   * @param iFlags
   *   legal values are
   *   - OCC_MATCH_FULL_PATH:
   *       full path of instance is matched,
   *       an occurrence which path is [instance1, instance2] will only match input path [instance1, instance2]
   *       it will not match input paths
   *         (a) [instance2] (too short)
   *         (b) [instance0, instance1, instance2] (too long)
   *         (c) [instance1, instance3] (last instance mismatch)
   *         (d) [instance3, instance2] (first instance mismatch)
   *         (e) [instance1, instance2, instance3] (too long and last instance mismatch)
   *   - OCC_MATCH_TRAILING_PATH
   *       only trailing path of instance is matched
   *       it will match the same path as OCC_MATCH_FULL_PATH except for case a)
   *   - OCC_MATCH_SHORT_TRAILING_PATH
   *       it will match the same path as OCC_MATCH_TRAILING_PATH except for case b)
   * @return
   *  matched occurrences if any
   *  notice that depending on inputs and data model there can be several matched occurrences and they are returned in unspecified order
   *
   * @usage:
   *
   * CATOmxIter<CATBaseUnknown> occurrences = CATIOccurrenceServices3::Get().FindOccurrencesMatchingPath(XXX,YYY,ZZZ);
   * while(CATBaseUnknown* occurrence = occurrences.Next())
   * {
   *   CATOmxQIPtr<XXX> hOccurrence(occurrence); //XXX could be CATIPLMNavOccurrence or CATIPLMNavRepOccurrence
   *   //do something with the occurrence
   * }
   *
   * notice that only iFatherOccurrence!=NULL and iFlags==OCC_MATCH_FULL_PATH guarantee that only one match can be returned
   * in other cases caller must expect several matches
   *
   * notice that the following pattern is incorrect:
   * CATBaseUnknown* occurrence = CATIOccurrenceServices3::Get().FindOccurrencesMatchingPath(XXX,YYY,ZZZ).Next();
   * because
   *   it will cause a "Free Memory Read"
   *   only the first returned occurrence is managed and there is no guarantee that it is the "good" one w(hat ever that means)
   * in place use the following snippet:
   * CATOmxIter<CATBaseUnknown> occurrences = CATIOccurrenceServices3::Get().FindOccurrencesMatchingPath(XXX,YYY,ZZZ);
   * CATOmxQIPtr<XXX> hOccurrence(occurrence);
   * if(occurrences.Next())
   * {
   *   //several matches found, error
   * }
   */
  virtual CATOmxIter<CATBaseUnknown> FindOccurrencesMatchingPath(const CATBaseUnknown* iFatherOccurrence, const CATOmxList<CATBaseUnknown>& iPath, unsigned int iFlags) const = 0;

  /**
   * Same as FindOccurrencesMatchingPath using path of instance of input occurrence
   */
  virtual CATOmxIter<CATBaseUnknown> FindOccurrencesMatchingOccurrence(const CATBaseUnknown* iFatherOccurrence, const CATBaseUnknown* iOccurrence, unsigned int iFlags) const = 0;

  /**
   * Retrieve associated root occurrence.
   * complexity: O(path of instance length)
   */
  virtual CATOmxSR<CATBaseUnknown> GetRootOccurrence(const CATBaseUnknown* iOccurrence) const = 0;

  /**
   * Retrieve associated path of instances
   * Notice it returns empty for root occurrences
   * complexity: O(path of instance length)
   */
  virtual CATOmxList<CATBaseUnknown> GetPathOfInstances(const CATBaseUnknown* iOccurrence) const = 0;

  /**
  * Retrieve associated path in the form of a CATPLMID
  * Notice it returns empty for root occurrences
  * complexity: O(path of instance length)
  */
  virtual CATPLMID GetPath(const CATBaseUnknown* iOccurrence) const = 0;

  /**
   * retrieve matching child
   * complexity: ~ O(1)
   */
  virtual CATOmxSR<CATBaseUnknown> GetChild(const CATBaseUnknown* iFatherOccurrence, const CATBaseUnknown* iInstance) const = 0;

  /**
   * retrieve matching direct or indirect child
   * complexity: ~ O(input path length)
   */
  virtual CATOmxSR<CATBaseUnknown> GetChild(const CATBaseUnknown* iFatherOccurrence, const CATOmxList<CATBaseUnknown>& iPathRelativeToFatherOccurrence) const = 0;
  virtual CATOmxSR<CATBaseUnknown> GetChild(const CATBaseUnknown* iFatherOccurrence, const CATPLMID& iPathRelativeToFatherOccurrence) const = 0;
};

#endif
