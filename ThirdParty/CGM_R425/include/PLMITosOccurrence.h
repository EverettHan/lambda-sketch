#ifndef PLMITosOccurrence_H
#define PLMITosOccurrence_H

#include "CATOmxSR.h"
#include "CATComponentId.h"
#include "CATOmxIter.h"
#include "CATOmxSharable.h"

/**
 * generalization of the occurrence concept to all TOS objects
 * objects are directly occurrences or raw components in the context of a father occurrence
 *
 * for example, this IRPC model
 * root
 *   + instA1 --\
 *   |           --> refA
 *   + instA2 --/      + instB1 --\
 *                     |           --> refB
 *                     + instB2 --/
 *                     + portA
 *
 * gives (unfiltered) occurrence model:
 *  rootOcc
 *    + instA1Occ
 *       + instB1Occ.1
 *       + instB2Occ.1
 *    + instA2Occ
 *       + instB1Occ.2
 *       + instB2Occ.2
 *
 * tos occurrence view will be:
 *  rootTosOcc
 *    + instA1TosOcc
 *        + refATosOcc.1
 *          + instB1TosOcc.1
 *            + refBTosOcc.1.1
 *          + instB2TosOcc.1
 *            + refBTosOcc.1.2
 *          + portATosOcc.1
 *    + instA2TosOcc
 *        + refATosOcc.2
 *          + instB1TosOcc.2
 *            + refBTosOcc.2.1
 *          + instB2TosOcc.2
 *            + refBTosOcc.2.2
 *          + portATosOcc.2
 */
class PLMITosOccurrence : public CATOmxSharable
{
public:
  /**
   * retrieve parent, null for root occurrences
   */
  virtual CATOmxSR<PLMITosOccurrence> GetParent() const = 0;

  /**
   * retrieve associated TOS component
   */
  virtual CATComponentId GetComponent() const = 0;

  /**
   * retrieve associated occurrence
   * nullptr on nodes which are not associated to a genuine occurrence
   * (like ports, connection or non root references)
   */
  virtual CATOmxSR<CATBaseUnknown> GetOccurrence() const = 0;

  /**
   * retrieve children (either occurrences or TOS components)
   * filtered occurrences are excluded
   * deleted TOS components are included (unless filtered)
   * RelationType objects which are not instances are excluded (as well as SRs)
   */
  virtual CATOmxIter<PLMITosOccurrence> GetChildren() const = 0;

  /**
   * wrap an occurrence (a PLMOccurrence or a CATObjectIPLMRepOccurrence)
   */
  static ExportedByCATPLMTos CATOmxSR<PLMITosOccurrence> Wrap(const CATBaseUnknown& iOccurrence);

  /**
   * query all (tos) occurrences of input instance (or relation) in all contexts
   */
  static ExportedByCATPLMTos CATOmxIter<PLMITosOccurrence> QueryOccurrences(const CATBaseUnknown& instance);
  /**
   * query all (tos) root occurrences of input reference in all contexts
   */
  static ExportedByCATPLMTos CATOmxIter<PLMITosOccurrence> QueryRootOccurrences(const CATBaseUnknown& reference);
};

#endif
