//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/05/06
//===================================================================
// CATSYPArray.cpp
// Header definition of template class CATSYPArray and CATSYPStaticArray
//===================================================================
//
// Usage notes: 
//
//===================================================================
//  2010/05/06 Creation: jov
//===================================================================
/**
* @quickeReview 16:09:21 Correct FMR-3898524 which happen while inserting two elements in same index and the capacity of the array is augmented. 
*/ 
#ifndef CATSYPArray_H
#define CATSYPArray_H

#include <CATSYPMacros.h>
#include <CATSYPCheck.h>
#include <string.h>
#include <stdlib.h> // For qsort
#include <UIVCoreToolsInline.h>

/** Possible actions to do when removing all elements of an array */
enum CATSYPArrayMemoryHandling
{
  /** releases the data. */
  CATSYPArrayReleaseAllocation = 0, 
  /** keeps the data allocated.*/
  CATSYPArrayKeepAllocation
};

/**
 * Class that provide a type dynamic array.
 * At the creation of this array, a default value is automatically created.
 * The default capacity of an array is 0, that is no internall array is created.
 * If customer knows how much components he will need, he should pass it in the constructor ( #CATSYPConstArray(int i_capacity=0) )
 * Or call #SetCapacity on it before o fill it.
 * Otherwise by adding an element, the dimension of the internal array is automatically changed if its length is overtaken:
 * If the previous capacity was 0, it becomes one, otherwise if it is n, it becomes (n+1)*2, avoiding to recreate the internal array for each addition.
 * The array may be used with pointers, or values, if the used type provide operator= and default constructor. Warning, the constructors and destructors 
 * of the contained values will be called only by the internal array managment, in case of redimensionning, for example.
 * To access an element, customer should use #Get method, but if knows in its scope the boundaries of the array, it may uses the UnsafeGet, that
 * internally doesn't check the position of the requested index. For example, it is good when iterating through all the elements : 
 * 
 * const CATArray<CATString>& myArray = GetArray();
 * for (int index; index< myArray.GetLength(); index++)
 * {
 *   CATString currentString = myArray.UnsafeGet(index);
 * }
 *
 * When removing all elements, or modifying capacity, customer may want to not reduce internal array dimension. For example, if he knows that the array will be filled again.
 * In this case, it is very valuable to use the argument i_memoryHandling to CATSYPArrayKeepAllocation
 */
template<class T> class CATSYPConstArray
{
public:
  /**
   * Constructor of the  array. It uses internally a standard array, that is 
   * resized automatically when there is no room left.
   * @param i_capacity the initial dimension of the internal arrray
   */
  INLINE explicit CATSYPConstArray(int i_capacity=0):_defaultValue(),_length(0),_plaArray(NULL), _capacity(0) {SetCapacity(i_capacity);}
  /**
   * Contructor of the array.
   * @param i_plrArray a C array to copy to init the array. 
   * @param i_length the length of the C array to copy.
   */
  INLINE CATSYPConstArray(const T* i_plrArray, int i_length):_defaultValue(),_length(0),_plaArray(NULL), _capacity(0) {if(i_plrArray){SetCapacity(i_length);AddArray(i_plrArray, i_length);}else{CHECK_TRUE(i_length==0);}}
  /** Destructor */
  INLINE ~CATSYPConstArray(){delete [] _plaArray;_plaArray = NULL;}
  /**
   * Returns a const element at a given index, after checking that the index is inside the bounds of the array.
   */
  INLINE const T& Get(int i_index) const  { CHECK_TRUE_RETV((i_index>=0 && i_index<_length), _defaultValue);return _plaArray[i_index];}
  /**
   * @copydoc CATSYPConstArray#Get
   */
  INLINE const T& operator[](int i_index) const{return Get(i_index);};
  /**
   * Returns an const element at a given index, after checking that the index is inside the bounds of the array.
   */
  INLINE int Get(int i_index, T& o_value) const {CHECK_TRUE_RETV((i_index>=0 && i_index<_length), 0);o_value=_plaArray[i_index];return 1;}
  /**
   * Returns an element at a given index, after checking that the index is inside the bounds of the array.
   */
  INLINE T& Get(int i_index) {CHECK_TRUE_RETV((i_index>=0 && i_index<_length), _defaultValue);return _plaArray[i_index];}
  /**
   * @copydoc CATSYPConstArray#Get
   */
  INLINE T& operator[](int i_index){return Get(i_index);};
  /**
   * Sets a value at a given index after checkingit is inside the bounds of the array.
   */
  INLINE void Set(int i_index, const T& i_value){CHECK_TRUE_RET((i_index>=0 && i_index<_length));_plaArray[i_index]=i_value;}
  /**
   * @return the number of items of the array.
   */
  INLINE int GetLength() const { return _length; }
  /**
  * @return a const pointer on the inner array.
   */
  INLINE const T* ToArray() const
  {
    return _plaArray;
  };
  /**
  * @return a pointer on the inner array.
   */
  INLINE T* ToArray()
  {
    return _plaArray;
  };
  /**
   * Adds an element to the array, and change dimension of internal array if needed.
   */
  INLINE void Add(const T &i_T) {UpdateSize();_plaArray[_length++]=i_T;}
  /**
   * Adds an array of values tothe array, and change dimension of internal array if needed.
   */
  INLINE void AddArray(const T *i_T, int i_nbElements)
  {
    UpdateSize(i_nbElements);
    for (int index=0; index<i_nbElements; index++)
    {
      _plaArray[_length+index] = i_T[index];
    }
    _length+=i_nbElements;
  }
		/**
		 * Finds the first occurrence of a given element from a given index.
		 * @return 
		 * <br><b>Legal values</b>: The index of the located element, or 
		 * <tt>-1</tt> if the list does not contain it.
		 */
		INLINE int Locate(const T &i_T, int i_from = 0) const
  {
    for (int index = i_from; index < _length; index++)
    {
      if (_plaArray[index] == i_T) {
        return index;
      }
    }
    return -1;
  }
  /**
   * Removes a value of the array. Warning, if the array is not resized, no destructeur will be called!
   */
  INLINE int Remove(int i_index)
  {
    CHECK_TRUE_RETV((i_index >=0 && i_index < _length), 0); 
    return UnsafeRemove(i_index);
  };
  /**
   * Removes an object of the array. Warning, if the array is not resized, no destructeur will be called!
   * It removes only the first Element found !
   */
  INLINE int RemoveElement(const T &i_T)
  {
    int index = Locate(i_T);
    if (index >= 0)
    {
      return UnsafeRemove(index);
    }
    return 0;
  };
  /**
   * Removes all values of the array. Warning, if i_memoryHandling=CATSYPArrayReleaseAllocation, no destructeur will be called!
   */
  INLINE void RemoveAll( CATSYPArrayMemoryHandling i_memoryHandling = CATSYPArrayReleaseAllocation)
  {
    _length=0;
    if (i_memoryHandling == CATSYPArrayReleaseAllocation)
    {
      delete [] _plaArray;_plaArray = NULL;
      _capacity = 0;
    }
  };
  /**
   * Sorts the array using the quicksort algorithm.
   */
  INLINE void QuickSort(int (*iPFCompare) (const T*, const T*))
  {
    qsort(_plaArray, _length, sizeof(T), (int (*)(const void *,const void *)) iPFCompare);
  }
  /**
   * @return a value at a given index without checking that the given index is inside the bounds of the internal array.
   */
  INLINE const T& UnsafeGet(int i_index) const  {return _plaArray[i_index];}
  /** Returned a value from an index without checking it is inside the bounds of the array. */
  INLINE T& UnsafeGet(int i_index) {return _plaArray[i_index];}
  /**
   * @return a value at a given index without checking that the given index is inside the bounds of the internal array.
   */
  INLINE int UnsafeGet(int i_index, T& o_value) const {o_value=_plaArray[i_index];return 1;}
  /**
   * Sets a value in the array without checking that the given index is inside the bounds of the internal array.
   */
  INLINE void UnsafeSet(int i_index, const T& i_value){_plaArray[i_index]=i_value;}
  /**
   * Removes a value from the array without checking that the given index is inside the bounds of the internal array.
   */
  INLINE int UnsafeRemove(int i_index)
  {
    for(int i = i_index; i < _length-1; i++)
      _plaArray[i] = _plaArray[i+1];
    _length--;
    return 1;
  };
  /**
   * Swaps 2 items of the list. Asserts if one of the indexes is out of the bounds.
   */
  INLINE void Swap(int i_index1, int i_index2 )
  {
    if (i_index1 == i_index2)return;
    CHECK_TRUE_RET(i_index1>=0 && i_index1<_length);
    CHECK_TRUE_RET(i_index2>=0 && i_index2<_length);
   
    T temp = _plaArray[i_index1];
    _plaArray[i_index1]=_plaArray[i_index2];
    _plaArray[i_index2] = temp;
  }
  /**
   * Inserts the value in the array at the given index (cursor position). Asserts if the index is out of bounds.
   */
  INLINE void InsertAt(int i_index, const T& i_value)
  {
    CHECK_TRUE_RET(i_index <= _length && i_index >= 0);
    if (i_index == _length) Add(i_value);
    else
    {
			UpdateSize();
			_length++;
      for (int index = _length-1; index > i_index; index--)
      {
        _plaArray[index] = _plaArray[index-1];
      }
      _plaArray[i_index] = i_value;
    }
  }

  /** Operator=*/
  INLINE CATSYPConstArray<T>& operator=(const CATSYPConstArray<T>& i_toCopy)
  {
    if (this==&i_toCopy) return *this;
    if (_plaArray)
    {
      delete [] _plaArray;_plaArray = NULL;
    }
    _capacity = i_toCopy._capacity;
    _length = i_toCopy._length;
    if (_capacity > 0) _plaArray = new T[_capacity];
    for(int i = 0; i < _length; i++)
      _plaArray[i] = i_toCopy._plaArray[i];

    return *this;
  }
  /** Copy constructor*/
  INLINE CATSYPConstArray(const CATSYPConstArray<T>& i_toCopy) : _plaArray(NULL)
  {
    _capacity = i_toCopy._capacity;
    _length = i_toCopy._length;
    if (_capacity > 0) _plaArray = new T[_capacity];
    for(int i = 0; i < _length; i++)
      _plaArray[i] = i_toCopy._plaArray[i];
  }
  /***Sets the capacity of the array, that is the length of the inner C array*/
  INLINE void SetCapacity(int i_capacity, CATSYPArrayMemoryHandling i_memoryHandling = CATSYPArrayReleaseAllocation)
  {
    if (i_capacity==_capacity)return;
    if (i_memoryHandling == CATSYPArrayKeepAllocation && i_capacity < _capacity) return;
    CHECK_TRUE_RET(i_capacity > _length);
    _capacity = i_capacity;
    T* plNewArray = new T[i_capacity];
    // Check that the allocation succeeded.
    CHECK_POINTER_RET(plNewArray);
    if (_plaArray)
    {
      for(int i = 0; i < _length; i++) plNewArray[i] = _plaArray[i];
      delete [] _plaArray;
    }
    _plaArray = plNewArray;
  }
  /**@deprecated*/
  INLINE const T& QuickGet(int i_index) const  {return UnsafeGet(i_index);}
  /**@deprecated*/
  INLINE int QuickGet(int i_index, T& o_value) const {return UnsafeGet(i_index, o_value);}
  /**@deprecated*/
  INLINE T& QuickGet(int i_index) {return UnsafeGet(i_index);}
  /**@deprecated*/
  INLINE int QuickGetLength() const { return GetLength(); }
  /**@deprecated*/
  INLINE const T* QuickToArray() const{return ToArray();};
  /**@deprecated*/
  INLINE void QuickSet(int i_index, const T& i_value){UnsafeSet(i_index, i_value);}
  /**@deprecated*/
  INLINE void QuickAdd(const T &i_T) {Add(i_T);}
  /**@deprecated*/
  INLINE void QuickAddArray(const T *i_T, int i_nbElements){AddArray(i_T, i_nbElements);}
  /**@deprecated*/
  INLINE int QuickRemove(int i_index){return UnsafeRemove(i_index);};
  /** @deprecated */
  INLINE void QuickRemoveAll( CATSYPArrayMemoryHandling i_memoryHandling = CATSYPArrayReleaseAllocation){RemoveAll(i_memoryHandling);};
  /** @deprecated */
  INLINE T* QuickToArray(){return _plaArray;};
private:
  INLINE void UpdateSize(int i_nbNewElem=1)
  {
    if (_length + i_nbNewElem > _capacity)
    {
      int newCapacity = _length + i_nbNewElem;
      if (newCapacity > 1)
      {
        newCapacity *= 2;
      }
      SetCapacity(newCapacity);
    }
  }
private:
  T _defaultValue;
  T *_plaArray;
  int _length;
  int _capacity;
};

template<class T> class CATSYPArray : public CATSYPConstArray<T>
{
public:
  explicit CATSYPArray(int i_capacity=0): CATSYPConstArray<T>(i_capacity){}
  CATSYPArray(const T* i_plrArray, int i_length):CATSYPConstArray<T>(i_plrArray, i_length) {}
};

template<class T> class CATSYPDynArray : public CATSYPArray<T>
{
public:
  explicit CATSYPDynArray(int i_capacity=0): CATSYPArray<T>(i_capacity){}
  CATSYPDynArray(const T* i_plrArray, int i_length):CATSYPArray<T>(i_plrArray, i_length) {}
};
//-----------------------------------------------------------------------

#endif
