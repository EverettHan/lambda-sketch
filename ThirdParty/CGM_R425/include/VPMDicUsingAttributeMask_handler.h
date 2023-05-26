/**
 * @level Private
 * @usage U1
 */
#ifndef __VPMDicUsingAttributeMask_handler_h__
#define __VPMDicUsingAttributeMask_handler_h__

#include "CATOmxSR.h"
#include "ENODicBase.h"
class EnoDicMask;
class VPMIDicUsingAttributeMask;
class VPMIDicSimple;

/**
 * A smart handler that prevent retention of VPMIDicUsingAttributeMask in memory
 */
class ExportedByENODicBase VPMDicUsingAttributeMask_handler 
{
private:
  CATOmxSR<EnoDicMask> mask;
  int id;
  void Set( const VPMIDicUsingAttributeMask * iPointer);
public:
  inline VPMDicUsingAttributeMask_handler() : id(0) { }
  /** optimized binding */
  inline VPMDicUsingAttributeMask_handler(EnoDicMask *iMask, int iId) : mask(iMask), id(iId) { }

  inline VPMDicUsingAttributeMask_handler(const VPMDicUsingAttributeMask_handler & iSR) :
     mask(iSR.mask), id(iSR.id) { }
  inline VPMDicUsingAttributeMask_handler(const VPMIDicUsingAttributeMask * iPointer) : id(0) { Set(iPointer); }

  /** assignment. */
  inline VPMDicUsingAttributeMask_handler & operator = (const VPMDicUsingAttributeMask_handler & iSR) {
    mask = iSR.mask;
    id = iSR.id;
    return *this;
  }
  /** assignment. */
  inline VPMDicUsingAttributeMask_handler & operator = (const VPMIDicUsingAttributeMask * iPointer) {
    Set(iPointer); 
    return *this;
  }

  /** access function */
  CATOmxSR<VPMIDicUsingAttributeMask> Ref() const;
  CATOmxSR<VPMIDicSimple> GetTargetSimple() const;
};

#endif // __VPMDicUsingAttributeMask_handler_h__
