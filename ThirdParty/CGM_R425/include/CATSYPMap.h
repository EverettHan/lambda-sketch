#ifndef CATSYPMap_H
#define CATSYPMap_H

#include "UIVCoreTools.h"
#include "CATSYPIterator.h"

/**
 * Base class representing a entry in the map.
 * Note that it uses references for key and value, that
 * means that a non-const reference on an object of this
 * type can be used to modify a value in the map.
 * @see CATSYPMap#newIterator
 * @see CATSYPConstMap#newIterator
 */
template <class Key, class Value> 
struct CATSYPMapEntry
{
  CATSYPMapEntry(const Key &i_key, Value &i_value) : key(i_key), value(i_value) {}
  CATSYPMapEntry(const CATSYPMapEntry &i_other) : key(i_other.key), value(i_other.value) {}
  /** the key */
  const Key &key;
  /** the value */
  Value &value;
};

/**
 * Base interface for constant maps.
 * A map is a collection that link a key to a value.
 * Keys cannot be duplicated. To each key can corresponds
 * at most one value (or none).
 * The algorithm used to compare the keys is implementation
 * dependend. See the implementations of this interface for
 * details.
 */
template <class Key, class Value> class CATSYPConstMap
{
protected:
  CATSYPConstMap() {}
  CATSYPConstMap(const CATSYPConstMap&) {}
public:
  virtual ~CATSYPConstMap() {}
  /**
   * Get the value corresponding to the given key if it
   * exists. Note that it returns a const value.
   * @param i_key the key to look for
   * @return a pointer on the value, NULL if the key
   * has no associated values in this map.
   */
  virtual const Value *Get(const Key &i_key) const = 0;
  /**
   * Check if this map contains a value for the given key.
   * @param i_key the key to look for
   * @return !=0 if this map contains a value for the key, else 0.
   */
  virtual int ContainsKey(const Key &i_key) const = 0;
  /**
   * Get the number of entries in the map.
   */
  virtual int GetSize() const = 0;
  /**
   * Build a new const iterator.
   * Note that the return iterator must not be used if:
   *   - the map is modified (a key is added, removed)
   *   - the map is destroyed
   * after its creation.
   * @return [delete] the new instance of the iterator.
   * It has to be deleted by the caller
   * @see CATSYPMap#newIterator
   */
  virtual CATSYPConstIteratorItf< CATSYPMapEntry<Key, Value> > *newConstIterator() const = 0;
private:
  CATSYPConstMap &operator=(const CATSYPConstMap&);
};

/**
 * Base interface for modifiable maps.
 * The algorithm used to replace and destroy values is
 * implementation dependent. See the implementations of
 * this interface for details.
 * @see CATSYPConstMap
 */
template <class Key, class Value> class CATSYPMap : public CATSYPConstMap<Key, Value>
{
protected:
  CATSYPMap() {}
  CATSYPMap(const CATSYPMap&) {}
public:
  virtual ~CATSYPMap() {}
  /**
   * Same as CATSYPConstMap#Get but returns a non-const value.
   * @see CATSYPConstMap#Get
   */
  virtual Value *Get(const Key &i_key) = 0;
  /**
   * Sets the value corresponding to the given key.
   * If a previous value was associated with the key, the new value is not inserted.
		 * Returns 1 if the given element has been inserted successfully.
   * Returns 0 if an element, equal to the given one, already exists in the hashmap,
		 * Returns -1 in case of failure.
   *
   * @param i_key the key
   * @param i_value the value to insert.
   */
  virtual int Put(const Key &i_key, const Value &i_value) = 0;
  /**
   * Removes the value for the given key.
   * @param i_key the key to look for
   * @return !=0 if this map contained a value for the key (this
   * value has been removed), else 0.
   */
  virtual int Remove(const Key &i_key) = 0;
  /**
   * Remove all values from the map.
   */
  virtual void Clear() = 0;
  /**
   * Build a new iterator.
   * Note that the return iterator must not be used if:
   *   - the map is modified (a key is added, removed)
   *   - the map is destroyed
   * after its creation.
   * Note that the @href CATSYPMapEntry#value can be used
   * to modify a value in the map. This kind of modification
   * does not prevent the iterator to work.
   * @return [delete] the new instance of the iterator.
   * It has to be deleted by the caller
   * @see CATSYPConstMap#newConstIterator
   */
  virtual CATSYPIteratorItf< CATSYPMapEntry<Key, Value> > *newIterator() = 0;
private:
  CATSYPMap &operator=(const CATSYPMap&);
};


#endif // CATSYPMap_H
