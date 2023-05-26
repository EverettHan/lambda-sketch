#ifndef CATRawCollPVIterator_H
#define CATRawCollPVIterator_H

#include "CATOmxPortability.h"
#include "CATListPV.h"

/** internal base class for CATListPtrIterator, do not use direcly */
class CATRawCollPVIterator
{
protected:
  void** m_cur;
  void** m_end;
  ExportedByCATOmxKernel CATRawCollPVIterator(const CATRawCollPV& list, bool begin);
  ExportedByCATOmxKernel void MoveNext();
};

#endif
