#ifndef __CATOmxKeyValueBlock_h__
#define __CATOmxKeyValueBlock_h__

#include "CATOmxPortability.h"
#include "CATOmxSet.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxKeyValueFlags.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATUnicodeString.h" //required by CATProcedureCallAsyncResultMsg.h
#include "CATOmxDeprecated.h"

struct CATOmxKeyValue;
class CATOmxKeyString;
class CATOmxAny;
class CATOmxTextStream;
ExportedByCATOmxKernel CATOmxCollecManager& CATOmxKVManager();
typedef CATOmxOrderedOSet<CATOmxKeyValue,CATOmxKVManager> CATOmxKeyValue_set;
class CATOmxKeyValueBlock;
template<> ExportedByCATOmxKernel CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxKeyValueBlock>::manager () ;
class CATOmxStructDescription;

/**
 * A Dictionary of Any.
 * @href http://osmwebdsy/wiki/index.php/CATOmxKeyValueBlock
 */
class ExportedByCATOmxKernel CATOmxKeyValueBlock
{
  CATUINTPTR m_value_set;
public:
  typedef CATOmxKeyValue ValueType;
  //typedef CATOmxKeyValue const KeyType;

  typedef CATOmxKeyValue_set::IteratorType IteratorType;
  typedef CATOmxKeyValue_set::ConstIteratorType ConstIteratorType;

  /** default constructor. */
  CATOmxKeyValueBlock();

  /** constructor with a reserved size. */
  OMX_EXPLICIT CATOmxKeyValueBlock(unsigned int iSize);

  /**
   * Assign a "struct description"
   * When using a struct description, external behavior of CATOmxKeyValueBlock should remained unchanged
   * If the description is appropriate the memory usage of internal data should be significantly disminished
   */
  HRESULT SetDescription(const CATOmxStructDescription* iDescription);

  /** Retrieve struct description*/
  const CATOmxStructDescription* GetDescription() const;

  /** copy constructor. */
  CATOmxKeyValueBlock(const CATOmxKeyValueBlock& iOther);
  /** assignment operator. */
  CATOmxKeyValueBlock& operator=(const CATOmxKeyValueBlock& iOther);

  /** destructor. */
  ~CATOmxKeyValueBlock();

  /** Adjust the preallocated size.  */
  void Reserve(unsigned int iSize);
  
  /**
   * Set a value according to iKey.
   * @param iKey the key
   * @param iValue the value to set
   * @param iMask the mask to set (OMX_KEYVALUE_NONE or bitwise OR of OMX_KEYVALUE_ISVALUATED and OMX_KEYVALUE_ISMULTIVALUATED)
   * @deprecated
   * WARNING: If value is already set, its mask is unchanged (iMask is not used).
   *          Use SetValueAndMask to avoid this issue.
   */
  HRESULT SetValue(const CATOmxKeyString &iKey,const CATOmxAny &iValue);
  HRESULT SetValue(const CATOmxKeyString &iKey,const CATOmxAny &iValue, unsigned int iMask);
  /**
   * Get a value according to iKey.
   * @param iKey the key
   * @param oValue the value to get
   * @return E_FAIL if does not exist, oValue is unchanged
   */
  HRESULT GetValue(const CATOmxKeyString &iKey,CATOmxAny &oValue) const;
  const CATOmxAny operator[](const CATOmxKeyString& iKey) const;

  /**
   * Get a value according to iKey.
   * @param iKey the key
   * @param oValue the value to get
   * @param oMask the associated mask
   * @return E_FAIL if does not exist, oValue and oMask is unchanged
   */
   HRESULT GetValueAndMask(const CATOmxKeyString &iKey,CATOmxAny &oValue, unsigned int &oMask) const;
   /**
   * Check mask info.
   * 
   */
  HRESULT TestValueMask(const CATOmxKeyString &iKey, unsigned int iMask) const; 
  /** 
   * Set mask according to iSetMask and iResetMask.
   * perform if iKey KeyValue exists
   *   m_value_set[iKey].m_mask = (m_value_set[iKey].m_mask & ~iResetMask) |iSetMask;
   * @param iKey the key.
   * @param iSetMask flags to set (or OMX_KEYVALUE_NONE)
   * @param iResetMask flags to reset (or OMX_KEYVALUE_NONE)
   * @return E_FAIL if does not exist.
   */
  HRESULT SetValueMask(const CATOmxKeyString &iKey, unsigned int iSetMask, unsigned int iResetMask); 
  /** 
   * Set mask according to iSetMask and iResetMask.
   * perform if iKey KeyValue exists
   *   m_value_set[iKey].m_mask = (m_value_set[iKey].m_mask & ~iResetMask) |iSetMask;
   * @param iKey the key.
   * @param iValue the value to set
   * @param iSetMask flags to set 
   * @param iResetMask flags to reset
   * @param iDefaultMask: the default mask used ONLY if value does not exist on this block
   * @return E_FAIL if does not exist.
   * WARNING: tricky usage.
   * example 1:
   *  If you want to set a value and its mask to EXACTLY OMX_KEYVALUE_ISVALUATED (ie NOT OMX_KEYVALUE_ISMULTIVALUATED)
   *  Use SetValueAndMask(key,value,OMX_KEYVALUE_ISVALUATED,OMX_KEYVALUE_ALL);
   * example 2:
   *  If you want to set a value and remove the OMX_KEYVALUE_ISVALUATED flag (leaving OMX_KEYVALUE_ISMULTIVALUATED unchanged)
   *  Use SetValueAndMask(key,value,OMX_KEYVALUE_NONE,OMX_KEYVALUE_ISVALUATED);
   */
  HRESULT SetValueAndMask(const CATOmxKeyString &iKey, const CATOmxAny &iValue, unsigned int iSetMask, unsigned int iResetMask);
  HRESULT SetValueAndMask(const CATOmxKeyString &iKey,const CATOmxAny &iValue, unsigned int iDefaultMask,unsigned int iSetMask, unsigned int iResetMask);
  /**
   * Use ConstIterator() instead, this call may lead to unwanted side effect. 
   * @deprecated
   */
  inline OMX_DEPRECATED("Use ConstIterator") IteratorType ValueIterator() {return Iterator();}
  /* Return a writable iterator, this will make a private copy of the collection if needed. */
  IteratorType Iterator();
  /* Return a const iterator. */
  ConstIteratorType ConstIterator() const;

  /** Remove all value in set.  */
  void RemoveAll();
  /** Return true if iKey exist in set. */
  CATBoolean KeyExists(const CATOmxKeyString &iKey) const;
  /** Remove iKey value if it exists. */
  HRESULT RemoveValue(const CATOmxKeyString &iKey);
  /** Return the number of items. */
  unsigned int Size() const;
  /** Return TRUE if does not contains anything. */
  CATBoolean IsEmpty() const;
  /** Merge all entry from iBlock.
   * Existing key will be replace by iBlock value.
   */
  HRESULT Merge(const CATOmxKeyValueBlock &iBlock);
  CATBoolean Equals(const CATOmxKeyValueBlock &iBlock) const;
  /** 
   * Compare two CATOmxKeyValueBlock as if they are ordered.
   * Because CATOmxKeyValueBlock is implemented as Hash, this feature allocate two vector if size are identical
   * Return <0 if *this < iBlock
   * Return >0 if *this > iBlock
   * Return =0 if *this == iBlock
   */
  int Compare(const CATOmxKeyValueBlock &iBlock) const;

  /** 
   * Comparison operators
   */
  inline int operator==(const CATOmxKeyValueBlock& iRight) const {return Equals(iRight);}
  inline int operator!=(const CATOmxKeyValueBlock& iRight) const {return !this->operator==(iRight);}  

  /** range for support */
  inline CATOmxSTLIter<const ValueType> begin() const {return CATOmxSTLIter<const ValueType>(ConstIterator());}
  inline CATOmxSTLIter<const ValueType> end() const {return CATOmxSTLIter<const ValueType>();}
};

/** Dump kv_blk in osm stream (JSON compatible format). */
ExportedByCATOmxKernel CATOmxTextStream &operator <<(CATOmxTextStream &osm,const CATOmxKeyValueBlock &kv_blk);

#endif
