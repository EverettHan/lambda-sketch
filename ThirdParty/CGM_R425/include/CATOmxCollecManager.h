/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxCollecManager_h__ 
#define __CATOmxCollecManager_h__ 1

#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATOmxCompare.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxPortability.h"

/**
 * Abstract type manager manipulated by ObjectModelerCollection framework.
 * Allows to initialize, copy, destroy and compare objects.
 * This class must never be used directly but can be implemented.
 * An implementation of this interface exist for all C types and common System/ObjectModelerCollection types.
 * For other types you should preferably inherit from CATOmxCOMCollecManager or CATOmxClassManager.
 *
 * @href http://osmwebdsy/wiki/index.php/CATOmxArray_Usage
 */
class ExportedByCATOmxKernel CATOmxCollecManager
{
public:
  /** sizeof */
  const unsigned int m_width;

  /** erroneous name, it should be 'm_unmovable' meaning type cannot be memmove'd*/
  /*const*/ int m_safeReferencing;

  /** sizeof */
  inline unsigned int SizeOf() const { return m_width; }

  /** constructor */
  inline CATOmxCollecManager(unsigned int width) : m_width(width), m_safeReferencing(0) {}

  /**
   * Initialize (default constructor semantic) a memory zone.
   * @param dst: target vector
   * @param count: number of item to initialize.
   *
   * You must never call this method.
   * You should never implement this method.
   */
  virtual void InitVect(void* dst, unsigned int count) const = 0;

  /**
   * Initialize (copy constructor semantic) a memory zone.
   * @param dst: target vector
   * @param src: source vector
   * @param count: number of items to initialize
   *
   * You must never call this method.
   * You should never implement this method.
   * There is a default (sub-optimal) implementation.
   */
  virtual void InitVect(void* dst, const void* src, unsigned int count) const;

  /**
   * Copy (copy operator semantic) a memory zone.
   * @param dst: target vector
   * @param src: source vector
   * @param count: number of items to copy
   *
   * Overlapping is managed.
   * You must never call this method.
   * You should never implement this method.
   */
  virtual void SetVect(void* dst, const void* src, unsigned int count) const = 0;

  /**
   * Unset (destructor semantic) a memory zone.
   * @param dst: target vector
   * @param count: number of items to unset.
   * You must never call this method.
   * You should never implement this method.
   */
  virtual void UnsetVect(void* dst, unsigned int count) const = 0;

  /**
   * Compute hash key of an item
   * @param ptr: address of the item to hash
   * @return: hask key of the item
   *
   * You must never call this method.
   * You can implement this method.
   *
   * hash key must be stable:
   * the hash key of an object stored in a hashed collection must be never change.
   */
  virtual CATHashKey Hash(const void* ptr) const = 0;

  /**
   * Compare two objects
   * @param ptr1: address of the first object
   * @param ptr2: address of the second object
   * @return:
   *   negative: first object is less than second object
   *   zero:     first object is equal to second object
   *   positive: first object is greater than second object
   *
   * It must be implement an 'order relation': reflexive, antisymetric and transitive.
   *
   * Beware that the ADDRESS of the objects are passed to this method.
   * So for collections of objects:   ptr1/ptr2 are Object*
   * but for collections of pointers: ptr1/ptr2 are Object**
   *
   * You must never call this method.
   * You can implement this method.
   */
  virtual int Compare(const void* ptr1, const void* ptr2) const = 0;

  /** @nodoc */
  inline int Equal(const void* ptr1, const void* ptr2) const { return 0 == Compare(ptr1, ptr2); }
};

/**
 * Implementation of CATOmxCollecManager for 'raw C types' (int, double etc...)
 * You should not use it except on POD types.
 * For c++ class/struct: use CATOmxClassManager
 * For enum: use enum_manager
 */
class ExportedByCATOmxKernel CATOmxBasicTypeManager : public  CATOmxCollecManager
{
public:
  inline CATOmxBasicTypeManager(unsigned int width) : CATOmxCollecManager(width) {}
  virtual void InitVect(void* dst, unsigned int count) const;
  virtual void InitVect(void* dst, const void* src, unsigned int count) const;
  virtual void SetVect(void* dst, const void* src, unsigned int count) const;
  virtual void UnsetVect(void* dst, unsigned int count) const;
  virtual CATHashKey Hash(const void* ptr) const;
  virtual int Compare(const void* ptr1, const void* ptr2) const;
};

/**
 * Implementation of CATOmxCollecManager for unmanaged pointers (void*)
 * Hash and Compare are naive pointer tests.
 * You can inherit this class in order to override Hash/Compare
 */
class ExportedByCATOmxKernel CATOmxPtrManager : public  CATOmxBasicTypeManager
{
public:
  inline CATOmxPtrManager() : CATOmxBasicTypeManager(sizeof(void*)) {}
  virtual CATHashKey Hash(const void* ptr) const;
  virtual int Compare(const void* ptr1, const void* ptr2) const;
};

/**
 * Implementation of CATOmxCollecManager for managed IUnknown derived pointers (IUnknown*)
 * AddRef/Release is managed.
 *
 * Warning: Hash & Compare are inherited from CATOmxPtrManager and are not 'COM compliant'
 * Use genuine_com_manager, cbu_manager if you need 'COM compliant' hashing/comparison.
 *
 * You can inherit this class in order to override Hash/Compare
 */
class ExportedByCATOmxKernel CATOmxCOMCollecManager : public CATOmxPtrManager
{
public:
  virtual void InitVect(void* dst, const void* src, unsigned int count) const;
  virtual void SetVect(void* dst, const void* src, unsigned int count) const;
  virtual void UnsetVect(void* dst, unsigned int count) const;
};

/**
* Implementation of CATOmxCollecManager for managed CATOmxSharable derived pointers (CATOmxSharable*)
* AddRef/Release is managed.
*
* Hash/Compare are overriden in order to use CATOmxSharable hashing/comparison protocol
*
* You must not inherit or use this class.
*/
class ExportedByCATOmxKernel CATOmxSharableCollecManager : public CATOmxCOMCollecManager
{
public:
  virtual CATHashKey Hash(const void* ptr) const;
  virtual int Compare(const void* ptr1, const void* ptr2) const;
};


#endif
