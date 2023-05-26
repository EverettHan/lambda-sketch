#ifndef CATSYPHashMap_H
#define CATSYPHashMap_H

#include "UIVCoreTools.h"
#include "CATSYPMap.h"
#include "CATSYPHashMapBaseIterator.h"
#include "CATSYPRemoveExportWarning.h" // see documentation in this header
#include <CATSysSimpleHashTable.h>
#include <CATSYPCheck.h>


/**
 * Default comparator for the CATSYPHashMap template.
 * This comparator uses the == operator.
 * Note that it is specialized for:
 *   - double
 *   - float
 *   - const char *
 *
 * This float/double specialization is mandatory since == 
 * operator on floating point number (float/double) always 
 * returns 0 if one of its operand is NaN. The specialization
 * return 1 if both operand are NaN (even if they are not
 * the same NaN), 0 if only one of them is NaN. Note also that
 * by default 0. == -0. but they are two distinct numbers.
 * Consequently, if this specialization also make an exception
 * for 0. and -0. so that positive and negative zeros are not
 * considered equal. For other numbers the result of the == 
 * operator is returned.
 * Note that CATSYPHashMapComparator is also specialized
 * for double/float so that it returns the same value
 * for all NaN value (two different NaN will have the 
 * same hash) to ensure that the comparator and the hasher
 * are coherents.
 *
 * The "const char *" specialization uses strcmp to do
 * the comparison. It makes the assumption that the key
 * is a null terminated string of bytes.
 */
template <class Key> struct CATSYPHashMapComparator
{
  /** 
   * Compare two keys.
   * Note that if two keys are equal for this function, they must
   * have the same hash code.
   * @param i_key1 the first key
   * @param i_key2 the second key
   * @return !=0 if the key are equal, else 0.
   * @see #ComputeHash
   */
  int AreEqual(const Key &i_key1, const Key &i_key2) {
    return i_key1 == i_key2;
  }
};

ExportedByUIVCoreTools int CATSYPHashMapComparatorDouble(const double &i_key1, const double &i_key2);
ExportedByUIVCoreTools int CATSYPHashMapComparatorFloat(const float &i_key1, const float &i_key2);
ExportedByUIVCoreTools int CATSYPHashMapComparatorCString(const char * const&i_key1, const char * const&i_key2);
/**
 * Specialization of CATSYPHashMapComparator for double.
 * See CATSYPHashMapComparator documentation for details.
 */
template <> struct CATSYPHashMapComparator<double>
{
  int AreEqual(const double &i_key1, const double &i_key2) {
    return CATSYPHashMapComparatorDouble(i_key1, i_key2);
  }
};

/**
 * Specialization of CATSYPHashMapComparator for float.
 * See CATSYPHashMapComparator documentation for details.
 */
template <> struct CATSYPHashMapComparator<float>
{
  int AreEqual(const float &i_key1, const float &i_key2) {
    return CATSYPHashMapComparatorFloat(i_key1, i_key2);
  }
};

template <> struct CATSYPHashMapComparator<const char *>
{
  int AreEqual(const char * const &i_key1, const char * const &i_key2) {
    return CATSYPHashMapComparatorCString(i_key1, i_key2);
  }
};


/**
 * Default hash computation for the CATSYPHashMap template.
 * This comparator uses the member function int HashCode() of
 * the class.
 * Note that the implementation of HashCode must be coherent
 * with the implementation of operator == if the default
 * comparator is used along this default hasher.
 * Note that it is specialized for:
 *   - CATINT32
 *   - CATUINT32
 *   - CATLONG64
 *   - CATULONG64
 *   - char
 *   - unsigned char
 *   - signed char
 *   - double
 *   - float
 *   - const char *
 *   - CATUnicodeString
 *   - CATString
 * since all those types do not have a HashCode function.
 * The implementation for those specialized types is 
 * See documentation of @href CATSYPHashMapComparator
 * for details about double and float hash computation.
 *
 * For pointer, you may use the @ref CATSYPHashMapPointerHasher.
 */
template <class Key> struct CATSYPHashMapHasher
{
  /** 
   * Compute the hash code of a key.
   * Note that if two keys are equal, they must have the same hash code.
   * @param i_key the key
   * @return the hash
   * @see #AreEqual
   */
  int ComputeHash(const Key &i_key) {
    // by default (not specialized case) try to use a function named HashCode
    return i_key.HashCode();
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for CATINT32.
 */
template <> struct CATSYPHashMapHasher<CATINT32> 
{
public:
  int ComputeHash(const CATINT32 &i_key) {
    return i_key;
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for CATUINT32.
 */
template <> struct CATSYPHashMapHasher<CATUINT32> 
{
public:
  int ComputeHash(const CATUINT32 &i_key) {
    return (int)i_key;
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for CATLONG64.
 */
template <> struct CATSYPHashMapHasher<CATLONG64> 
{
public:
  int ComputeHash(const CATLONG64 &i_key) {
    return (int)(i_key ^ i_key >> 32);
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for CATULONG64.
 */
template <> struct CATSYPHashMapHasher<CATULONG64> 
{
public:
  int ComputeHash(const CATULONG64 &i_key) {
    return (int)(i_key ^ i_key >> 32);
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for char.
 */
template <> struct CATSYPHashMapHasher<char> 
{
public:
  int ComputeHash(const char &i_key) {
    return (int)i_key;
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for unsigned char.
 */
template <> struct CATSYPHashMapHasher<unsigned char> 
{
public:
  int ComputeHash(const unsigned char &i_key) {
    return (int)i_key;
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for signed char.
 */
template <> struct CATSYPHashMapHasher<signed char> 
{
public:
  int ComputeHash(const signed char &i_key) {
    return (int)i_key;
  }
};

ExportedByUIVCoreTools int CATSYPHashMapHasherDouble(const double &i_key);
ExportedByUIVCoreTools int CATSYPHashMapHasherFloat(const float &i_key);
ExportedByUIVCoreTools int CATSYPHashMapHasherCString(const char * const &i_key);
class CATUnicodeString;
ExportedByUIVCoreTools int CATSYPHashMapHasherCATUnicodeString(const CATUnicodeString &i_key);
class CATString;
ExportedByUIVCoreTools int CATSYPHashMapHasherCATString(const CATString &i_key);


/**
 * Specialization of CATSYPHashMapHasher template for double.
 */
template <> struct CATSYPHashMapHasher<double>
{
public:
  int ComputeHash(const double &i_key) {
    return CATSYPHashMapHasherDouble(i_key);
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for float.
 */
template <> struct CATSYPHashMapHasher<float>
{
  int ComputeHash(const float &i_key) {
    return CATSYPHashMapHasherFloat(i_key);
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for const char *.
 * See @href CATSYPHashMapComparator documentation for details.
 */
template <> struct CATSYPHashMapHasher<const char *>
{
  int ComputeHash(const char * const &i_key) {
    return CATSYPHashMapHasherCString(i_key);
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for CATUnicodeString
 * that uses CATUnicodeString#ComputeHashKey.
 */
template <> struct CATSYPHashMapHasher<CATUnicodeString>
{
  int ComputeHash(const CATUnicodeString &i_key) {
    return CATSYPHashMapHasherCATUnicodeString(i_key);
  }
};

/**
 * Specialization of CATSYPHashMapHasher template for CATString
 * that uses CATString#ComputeHashKey.
 */
template <> struct CATSYPHashMapHasher<CATString>
{
  int ComputeHash(const CATString &i_key) {
    return CATSYPHashMapHasherCATString(i_key);
  }
};


ExportedByUIVCoreTools int CATSYPHashMapPointerHasherCompute(void *i_ptr);

/**
 * Hasher for data pointers. The @c == comparaison is assumed.
 */
struct CATSYPHashMapPointerHasher
{
  int ComputeHash(void *i_ptr) {
    return CATSYPHashMapPointerHasherCompute(i_ptr);
  }
};


/**
 * Implementation of CATSYPMap based on CATSysSimpleHashTable.
 * Note that an hasher and a comparator can be specified using 
 * Hasher and Comparator template parameters.
 * By default CATSYPHashMapHasher and CATSYPHashMapComparator
 * are used. CATSYPHashMapHasher expect that the Key type has
 * a "int HashCode() const" member function, and the CATSYPHashMapComparator
 * expect that there is an overload of operator== that take 
 * const references to Key type. Note that both CATSYPHashMapHasher 
 * and CATSYPHashMapComparator has been specialized to work for
 * basic Dassault Systemes types consequently it's for example
 * possible to write CATSYPHashMap<double, int> eventhough
 * there is no "int HashCode() const" available for double.
 * The Key class must:
 *   - have a copy constructor
 * The Value class must:
 *   - have a copy constructor
 *   - implement operator=(const Value &)
 * 
 */
template <class Key, class Value, class Hasher = CATSYPHashMapHasher<Key>, class Comparator = CATSYPHashMapComparator<Key> > 
class CATSYPHashMap : public CATSYPMap<Key, Value>
{
#ifdef _SUNOS_SOURCE
/** Build error on iOS, Entry can't be accessed by Iterator's methods*/
public:
#else
private:
#endif
  /**
   * The CATSysSimpleHashTable lookup functions expect an object
   * that can be compared and hashed as a regular value.
   * Consequently we define this base struct that will be the
   * base of @href Entry struct (this way the comparison and hash
   * functions given to the CATSysSimpleHashTable can cast their
   * input pointer with this class) and stores a key.
   * Note that there is no virtual destructor. It is not needed
   * since we never delete an @href Entry using a pointer typed
   * as KeyOnlyEntry.
   */
  struct KeyOnlyEntry
  {
    KeyOnlyEntry(const Key &i_key) : key(i_key) {}
    const Key key;
  };
  /**
   * An entry stored in the CATSysSimpleHashTable.
   * See @href KeyOnlyEntry documentation to see why it must
   * inherit from KeyOnlyEntry.
   */
  struct Entry : public KeyOnlyEntry {
    Entry(const Key &i_key, const Value &i_value) : KeyOnlyEntry(i_key), value(i_value) {}
    Value value;
  };
private:
  /**
   * The comparison function to pass to CATSysSimpleHashTable 
   */
  static int Compare(void *i_elem1, void *i_elem2) {
    CHECK_POINTER_RETV(i_elem1, 0);
    CHECK_POINTER_RETV(i_elem2, 0);
    KeyOnlyEntry *elem1 = (KeyOnlyEntry*)i_elem1;
    KeyOnlyEntry *elem2 = (KeyOnlyEntry*)i_elem2;
    Comparator comparator;
    return comparator.AreEqual(elem1->key, elem2->key);
  }
  /**
   * The hashing function to pass to CATSysSimpleHashTable 
   */
  static unsigned int Hash(void *i_elem) {
    CHECK_POINTER_RETV(i_elem, 0);
    KeyOnlyEntry *elem = (KeyOnlyEntry*)i_elem;
    Hasher hasher;
    return hasher.ComputeHash(elem->key);
  }
public:
  /** Build an empty hash table */
  CATSYPHashMap()
    : _hashTable(0, Hash, Compare)
  {
  }
  ~CATSYPHashMap() {
    DoClear();
  }
  /** @copydoc CATSYPConstMap#GetSize */
  virtual int GetSize() const {
    return _hashTable.Size();
  }
  /** @copydoc CATSYPMap#Get */
  virtual Value *Get(const Key &i_key) {
    KeyOnlyEntry lookEntry(i_key);
    Entry *pEntry = (Entry*)_hashTable.Locate(&lookEntry);
    if (pEntry != NULL) {
      return &pEntry->value;
    } else
      return NULL;
  }
  /** @copydoc CATSYPConstMap#Get */
  virtual const Value *Get(const Key &i_key) const {
    KeyOnlyEntry lookEntry(i_key);
    const Entry *pEntry = (const Entry*)_hashTable.Locate(&lookEntry);
    if (pEntry != NULL) {
      return &pEntry->value;
    } else
      return NULL;
  }
  /** @copydoc CATSYPConstMap#ContainsKey */
  virtual int ContainsKey(const Key &i_key) const {
    KeyOnlyEntry lookEntry(i_key);
    const Entry *pEntry = (const Entry*)_hashTable.Locate(&lookEntry);
    return pEntry != NULL;
  }
  /** @copydoc CATSYPMap#Put */
  virtual int Put(const Key &i_key, const Value &i_value) {
    Entry *pPair = new Entry(i_key, i_value);
    Entry *pExistingPair = (Entry*)_hashTable.InsertAndReturn(pPair);
    if (pPair == pExistingPair)
    {
      return 1; // the element has been successfully inserted
    }
    else if (pExistingPair != NULL) 
    {
      delete pPair; pPair = NULL;
      pExistingPair->value = i_value;
      return 0;
    } 
    else 
    {
      delete pPair; pPair = NULL;
      FAILURE("Failed to add the element");
      return -1;
    }
  }
  /** @copydoc CATSYPMap#Remove */
  virtual int Remove(const Key &i_key) {
    KeyOnlyEntry lookEntry(i_key);
    Entry *pEntry = (Entry*)_hashTable.Remove(&lookEntry);
    if (pEntry != NULL) {
      delete pEntry; pEntry = NULL;
      return 1;
    } else
      return 0;
  }
  /** @copydoc CATSYPMap#Clear */
  virtual void Clear() {
    DoClear();
  }

  /** @copydoc CATSYPConstMap#newConstIterator */
  virtual CATSYPConstIteratorItf< CATSYPMapEntry<Key, Value> > *newConstIterator() const {
    return new ConstIterator(&_hashTable);
  }

  /** @copydoc CATSYPMap#newIterator */
  virtual CATSYPIteratorItf< CATSYPMapEntry<Key, Value> > *newIterator() {
    return new Iterator(&_hashTable);
  }

  void PrintStats()const
  {
    _hashTable.PrintStats();
  }
private:
  /**
   * Delete all pairs in @ref #_hashTable and empty it.
   */
  void DoClear() {
    for (int pairIdx = 0; pairIdx < _hashTable.Size(); ++pairIdx) {
      Entry *pPair = (Entry*)_hashTable.Get(pairIdx);
      if (pPair != NULL) {
        delete pPair; pPair = NULL;
      } else FAILURE("NULL pair?");
    }
    _hashTable.RemoveAll();
  }
private:
  /** the implementation of CATSYPConstIteratorItf for this class */
  class ConstIterator : public CATSYPConstIteratorItf< CATSYPMapEntry<Key, Value> > {
  public:
    ConstIterator(const CATSysSimpleHashTable *i_pHashTable) :
      _internalIterator(i_pHashTable), _pLastEntry(NULL) {
    }
    ~ConstIterator() {
      if (_pLastEntry != NULL) {
        delete _pLastEntry;
        _pLastEntry = NULL;
      }
    }
    /** @see CATSYPConstIteratorItf#IsDone */
    virtual int IsDone() {
      return _internalIterator.IsDone();
    }
    /** @see CATSYPConstIteratorItf#Next */
    virtual void Next() {
      if (_pLastEntry != NULL) {
        delete _pLastEntry;
        _pLastEntry = NULL;
      }
      _internalIterator.Next();
    }
    /** @see CATSYPConstIteratorItf#CurrentItem */
    virtual const CATSYPMapEntry<Key, Value> *CurrentItem() {
      if (_pLastEntry != NULL)
        return _pLastEntry;
      Entry *pEntry = (Entry*)_internalIterator.InternalCurrentItem();
      if (pEntry == NULL)
        return NULL;
      _pLastEntry = new CATSYPMapEntry<Key, Value>(pEntry->key, pEntry->value);
      return _pLastEntry;
    }
  private:
    ConstIterator(const ConstIterator&);
    ConstIterator &operator=(const ConstIterator&);
  private:
    /** the internal class in charge of the iteration */
    CATSYPHashMapBaseIterator _internalIterator;
    /** last returned entry pointer */
    CATSYPMapEntry<Key, Value> *_pLastEntry;
  };

  /** the implementation of CATSYPIteratorItf for this class */
  class Iterator : public CATSYPIteratorItf< CATSYPMapEntry<Key, Value> > {
  public:
    Iterator(const CATSysSimpleHashTable *i_pHashTable) :
      _internalIterator(i_pHashTable), _pLastEntry(NULL) {
    }
    ~Iterator() {
      if (_pLastEntry != NULL) {
        delete _pLastEntry;
        _pLastEntry = NULL;
      }
    }
    /** @see CATSYPIteratorItf#IsDone */
    virtual int IsDone() {
      return _internalIterator.IsDone();
    }
    /** @see CATSYPIteratorItf#Next */
    virtual void Next() {
      if (_pLastEntry != NULL) {
        delete _pLastEntry;
        _pLastEntry = NULL;
      }
      _internalIterator.Next();
    }
    /** @see CATSYPIteratorItf#CurrentItem */
    virtual CATSYPMapEntry<Key, Value> *CurrentItem() {
      if (_pLastEntry != NULL)
        return _pLastEntry;
      Entry *pEntry = (Entry*)_internalIterator.InternalCurrentItem();
      if (pEntry == NULL)
        return NULL;
      _pLastEntry = new CATSYPMapEntry<Key, Value>(pEntry->key, pEntry->value);
      return _pLastEntry;
    }
  private:
    Iterator(const Iterator&);
    Iterator &operator=(const Iterator&);
  private:
    /** the internal class in charge of the iteration */
    CATSYPHashMapBaseIterator _internalIterator;
    /** last returned entry pointer */
    CATSYPMapEntry<Key, Value> *_pLastEntry;
  };

private:
  CATSYPHashMap(const CATSYPHashMap&);
  CATSYPHashMap &operator=(const CATSYPHashMap&);
private:
  /** The internal hash table */
  CATSysSimpleHashTable _hashTable;
};

/**
* Creates a hash code from a previously calculated hash code @c io_seed and
* a variable @c i_keyPart. Can be called incrementally to create a hash code from
* many variables. Uses the hasher of the @c Key class.
*
* @param i_keyPart the variable to include in the final hash code
* @param io_hashCode the hash code already calculated on input, the combined hash
* code on output
*/
template <class Key>
void CombineHash(const Key &i_keyPart, int & io_hashCode) {
  CATSYPHashMapHasher<Key> hasher;
  /* static cast in "unsigned int" to avoid propagating the sign bit: */
  io_hashCode ^= hasher.ComputeHash(i_keyPart) + 0x9e3779b9 + (io_hashCode << 6) + (static_cast<unsigned int>(io_hashCode) >> 2);
}

#endif // CATSYPHashMap_H
