#ifndef CATSYPIterator_H
#define CATSYPIterator_H

#include <stddef.h> // for NULL

/**
 * Base template interface for const iterators on a collection.
 * @see CATSYPIteratorItf
 * @see CATSYPConstIterator
 */
template <class E>
class CATSYPConstIteratorItf {
protected:
  CATSYPConstIteratorItf() {}
  CATSYPConstIteratorItf(const CATSYPConstIteratorItf&) {}
public:
  virtual ~CATSYPConstIteratorItf() {}
  /**
   * Tests if the iteration is over.
   * Note that when IsDone is true, other methods must not
   * be called
   * @return !=0 if iteration is over, else 0.
   */
  virtual int IsDone() = 0;
  /**
   * Go to the next element during the iteration.
   * Note that you must NOT call this function is @ref #IsDone
   * is true.
   */
  virtual void Next() = 0;
  /**
   * Get the current item in the iteration.
   * Note that you must NOT call this function is @ref #IsDone
   * is true.
   * @return a pointer on the current item; NULL in case of illegal call.
   * Note that after calling @ref #Next or destroying this iterator, the
   * returned item may not be valid. It should not be used.
   * Note that this pointer must not be deleted.
   */
  virtual const E *CurrentItem() = 0;
private:
  CATSYPConstIteratorItf &operator=(const CATSYPConstIteratorItf&);
};

/**
 * Base template interface for iterators on a collection of the given type.
 * @see CATSYPIterator
 * @see CATSYPConstIteratorItf
 */
template <class E>
class CATSYPIteratorItf {
protected:
  CATSYPIteratorItf() {}
  CATSYPIteratorItf(const CATSYPIteratorItf&) {}
public:
  virtual ~CATSYPIteratorItf() {}
  /**
   * Tests if the iteration is over.
   * Note that when IsDone is true, other methods must not
   * be called
   * @return !=0 if iteration is over, else 0.
   */
  virtual int IsDone() = 0;
  /**
   * Go to the next element during the iteration.
   * Note that you must NOT call this function is @ref #IsDone
   * is true.
   */
  virtual void Next() = 0;
  /**
   * Get the current item in the iteration.
   * Note that you must NOT call this function is @ref #IsDone
   * is true.
   * Note that contrary to the method @ref CATSYPConstIteratorItf#CurrentItem
   * this one is not const and does not return a pointer on a const element.
   * @return a pointer on the current item; NULL in case of illegal call.
   * Note that after calling @ref #Next or destroying this iterator, the
   * returned item may not be valid. It should not be used.
   * Note that this pointer must not be deleted.
   */
  virtual E *CurrentItem() = 0;
private:
  CATSYPIteratorItf &operator=(const CATSYPIteratorItf&);
};


/**
 * Handler for a @ref CATSYPIteratorItf instance pointer.
 * This handler simplifies the destruction of CATSYPIteratorItf
 * since it automatically calls delete on the CATSYPIteratorItf
 * pointer when it is being destroyed.
 * Typical usage is:
 *   for (CATSYPIterator<int> iterator(collection.newIterator());
 *        !iterator.IsDone();
 *        iterator.Next()) {
 *     int *pElem = iterator.CurrentItem();
 *     CHECK_POINTER_RET(pElem);
 *     ...
 *   }
 * Note that since there is no sharing mechanism for CATSYPIteratorItf
 * objects, there is no copy constructor on this class (and no affectation
 * operator for a CATSYPIterator reference). As a consequence it is not
 * possible to write:
 *   CATSYPIterator<T> iterator = collection.newIterator();
 * since (at least on linux with GCC) this would compile using the copy
 * constructor by building a temporary object (and not using the operator=
 * implementation for CATSYPIteratorItf*).
 * Note that if this handler is built with a NULL iterator, it will behave
 * as if there was nothing to iterate on (i.e. @ref #IsDone will return
 * 1).
 * @see CATSYPIteratorItf
 */
template <class E>
class CATSYPIterator {
public:
  /**
   * Initialize the handler with no iterator.
   */
  CATSYPIterator()
    : _pIteratorItf(NULL) {
  }
  /**
   * Initialize this handler with the given iterator.
   * Note that this handler takes the property of this
   * iterator and will delete it in its destructor (or
   * in its operator=).
   * @param i_pIteratorItf the iterator. May be NULL.
   */
  explicit CATSYPIterator(CATSYPIteratorItf<E> *i_pIteratorItf) 
    : _pIteratorItf(i_pIteratorItf) {
  }
  /**
   * Delete the associated iterator.
   */
  ~CATSYPIterator() {
    if (_pIteratorItf != NULL)
      delete _pIteratorItf;
    _pIteratorItf = NULL;
  }
  /**
   * Change the handled iterator.
   * Note that the previous iterator handled by this class
   * is deleted.
   */
  CATSYPIterator &operator=(CATSYPIteratorItf<E> *i_pIteratorItf) {
    if (i_pIteratorItf == _pIteratorItf)
      return *this;
    if (_pIteratorItf != NULL)
      delete _pIteratorItf;
    _pIteratorItf = i_pIteratorItf;
    return *this;
  }
  /** @see CATSYPIteratorItf#IsDone */
  virtual int IsDone() {
    if (_pIteratorItf == NULL)
      return 1;
    return _pIteratorItf->IsDone();
  }
  /** @see CATSYPIteratorItf#Next */
  virtual void Next() {
    if (_pIteratorItf != NULL)
      _pIteratorItf->Next();
  }
  /** @see CATSYPIteratorItf#CurrentItem */
  virtual E *CurrentItem() {
    if (_pIteratorItf != NULL)
      return _pIteratorItf->CurrentItem();
    else
      return NULL;
  }
private:
  CATSYPIterator(const CATSYPIterator&);
  CATSYPIterator &operator=(const CATSYPIterator&);
private:
  /** the handled iterator, may be NULL */
  CATSYPIteratorItf<E> *_pIteratorItf;
};

/**
 * Handler for a @ref CATSYPConstIteratorItf instance pointer.
 * This handler simplifies the destruction of CATSYPConstIteratorItf
 * since it automatically calls delete on the CATSYPConstIteratorItf
 * pointer when it is being destroyed.
 * Typical usage is:
 *   for (CATSYPConstIterator<int> iterator(collection.newConstIterator());
 *        !iterator.IsDone();
 *        iterator.Next()) {
 *     int *pElem = iterator.CurrentItem();
 *     CHECK_POINTER_RET(pElem);
 *     ...
 *   }
 * Note that since there is no sharing mechanism for CATSYPConstIteratorItf
 * objects, there is no copy constructor on this class (and no affectation
 * operator for a CATSYPConstIterator reference). As a consequence it is not
 * possible to write:
 *   CATSYPConstIterator<T> iterator = collection.newConstIterator();
 * since (at least on linux with GCC) this would compile using the copy
 * constructor by building a temporary object (and not using the operator=
 * implementation for CATSYPIteratorItf*).
 * @see CATSYPConstIteratorItf
 */
template <class E>
class CATSYPConstIterator {
public:
  /**
   * Initialize the handler with no iterator.
   */
  CATSYPConstIterator()
    : _pIteratorItf(NULL) {
  }
  /**
   * Initialize this handler with the given iterator.
   * Note that this handler takes the property of this
   * iterator and will delete it in its destructor (or
   * in its operator=).
   * @param i_pIteratorItf the iterator. May be NULL.
   */
  explicit CATSYPConstIterator(CATSYPConstIteratorItf<E> *i_pIteratorItf) 
    : _pIteratorItf(i_pIteratorItf) {
  }
  /**
   * Delete the associated iterator.
   */
  ~CATSYPConstIterator() {
    if (_pIteratorItf != NULL)
      delete _pIteratorItf;
    _pIteratorItf = NULL;
  }
  /**
   * Change the handled iterator.
   * Note that the previous iterator handled by this class
   * is deleted.
   */
  CATSYPConstIterator &operator=(CATSYPConstIteratorItf<E> *i_pIteratorItf) {
    if (i_pIteratorItf == _pIteratorItf)
      return *this;
    if (_pIteratorItf != NULL)
      delete _pIteratorItf;
    _pIteratorItf = i_pIteratorItf;
    return *this;
  }
  /** @see CATSYPConstIteratorItf#IsDone */
  virtual int IsDone() {
    if (_pIteratorItf == NULL)
      return 1;
    return _pIteratorItf->IsDone();
  }
  /** @see CATSYPConstIteratorItf#Next */
  virtual void Next() {
    if (_pIteratorItf != NULL)
      _pIteratorItf->Next();
  }
  /** @see CATSYPConstIteratorItf#CurrentItem */
  virtual const E *CurrentItem() {
    if (_pIteratorItf != NULL)
      return _pIteratorItf->CurrentItem();
    else
      return NULL;
  }
private:
  CATSYPConstIterator(const CATSYPConstIterator&);
  CATSYPConstIterator &operator=(const CATSYPConstIterator&);
private:
  /** the handled iterator, may be NULL */
  CATSYPConstIteratorItf<E> *_pIteratorItf;
};

#endif // CATSYPIterator_H
