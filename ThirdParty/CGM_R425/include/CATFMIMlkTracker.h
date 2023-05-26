#ifndef __CATFMIMlkTracker_h__
#define __CATFMIMlkTracker_h__


// SpecialAPI
#include "CATDataType.h" // CATUINT32
#include "CATSysDataType.h" // ULONG
// System
struct IUnknown;
// ObjectModelerCollection
#include "CATOmxPortability.h"

/**
 * The Mlk tracker abstraction.
 */
class CATFMIMlkTracker
{
public:
  /**
   * Method to be called when an object is AddRef'd.
   * @param iObject the tracked object.
   * @param cref the iObject cref current (before alteration) value.
   */
  virtual void OnAddRef(IUnknown & iObject, ULONG cref) = 0;

  /**
   * Method to be called when an object is Released.
   * @param iObject the tracked object.
   * @param cref the iObject cref current (before alteration) value.
   */
  virtual void OnRelease(IUnknown & iObject, ULONG cref) = 0;

  /**
   * Method to be called when an object is Created.
   * @param iObject the object being created.
   */
  virtual void OnCreate(IUnknown & iObject, CATUINT32 iTag) = 0;

  /**
   * Method to be called when an object is Destroyed.
   * @param iObject the object being destroyed.
   */
  virtual void OnDestroy(IUnknown & iObject) = 0;

  /**
   * Method than can be used for DEBUGGING purposes ONLY to retrieve an MLK-Tracker object tag.
   * @param iObject the object to identify.
   * @return 0 if anything is wrong (Light Mode, deleted object...) or the tag.
   */
  virtual CATUINT32 GetTag(IUnknown const & iObject) const = 0;
};


#endif // __CATFMIMlkTracker_h__
