#ifndef PLMITosOccurrences_H
#define PLMITosOccurrences_H

/**
 * internal helper for PLMITosOccurrence
 */
class PLMITosOccurrences
{
private:
  friend class PLMITosOccurrence;
  virtual PLMITosOccurrence* Wrap(const CATBaseUnknown& iOccurrence) const = 0;
  virtual CATOmxIter<PLMITosOccurrence> QueryOccurrences(const CATBaseUnknown& instance) const = 0;
  virtual CATOmxIter<PLMITosOccurrence> QueryRootOccurrences(const CATBaseUnknown& reference) const = 0;
};

#endif
