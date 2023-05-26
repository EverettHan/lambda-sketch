// C++
// QF2
// CATGMCollection.hxx
// ---------------------------------------------




// ==============================================================
//        Class CATGMCollection
// ==============================================================

// Contructor
// --------------------------------------
template <class T>
CATGMCollection<T>::CATGMCollection()
{
  const std::deque<T*> & parent = this->get_parent();  
  _it = parent.end();
}


// Copy Contructor
// --------------------------------------
template <class T>
CATGMCollection<T>::CATGMCollection( const CATGMCollection<T> & iOther) :
std::deque<T*>(iOther)
{
  const std::deque<T*> & parent = this->get_parent();  
  _it = parent.end();
}

///* Constructor from Array */
//template <class T>
//CATGMCollection<T>::CATGMCollection ( T * const iArray[], CATLONG32 iSize, CATBoolean iAcceptNull)
//{
//  CATLONG32 numElt = 0;
//  for ( ; numElt < iSize ; numElt++)
//  {
//    T * pElement = iArray[numElt];    
//    this->Push(pElement, iAcceptNull);
//  }
//  
//  const std::deque<T*> & parent = this->get_parent();
//  _it = parent.end();
//}
//
///* Constructor from CATLISTP)  */
//template <class T>
//template <class LIST>
//CATGMCollection<T>::CATGMCollection (const LIST & iListPOf, CATBoolean iAcceptNull)
//{
//  CATLONG32 numElt = 1;
//  for ( ; numElt <= iListPOf.Size() ; numElt++)
//  {
//    T * pElement = iListPOf[numElt];
//    this->Push(pElement, iAcceptNull);
//  }
//
//  const std::deque<T*> & parent = this->get_parent();
//  _it = parent.end();
//}

// --------------------------------------
// Destructor
// --------------------------------------
template <class T>
CATGMCollection<T>::~CATGMCollection()
{
  const std::deque<T*> & parent = this->get_parent();
  _it = parent.end();
}


// -------------------------------------------
// Size()
// -------------------------------------------
template <class T>
CATLONG32 CATGMCollection<T>::Size() const 
{
  // return _Size;
  return (CATLONG32) this->get_parent().size();
}

// -------------------------------------------
// Empty()
// -------------------------------------------
template <class T>
CATBoolean CATGMCollection<T>::Empty() const
{
  return this->get_parent().empty();
}

// access the first element 
template <class T>
T * CATGMCollection<T>::Front() const
{
  if (!this->Empty())
    return this->get_parent().front();

  return NULL;
}

// access the last element 
template <class T>
T * CATGMCollection<T>::Back() const
{
  if (!this->Empty())
    return this->get_parent().back();

  return NULL;
}

// -------------------------------------------
// Pop()
// -------------------------------------------
template <class T>
T * CATGMCollection<T>::Pop ()
{
  return this->pop_front();
}


// -------------------------------------------
// Push()
// -------------------------------------------
template <class T>
int CATGMCollection<T>::Push(const CATGMCollection<T> & iConcat, CATBoolean iAcceptNullPointer)
{
  int ret = 0;
  CATLONG32 size = iConcat.Size();
  CATLONG32 numElt = 0;
  for ( ; numElt < size && !ret ; numElt ++)
  {
    T * pCurElem = iConcat[numElt];
    ret = this->Push(pCurElem, iAcceptNullPointer);
  }

  return ret;
}

// -------------------------------------------
// Push()
// -------------------------------------------
template <class T>
int CATGMCollection<T>::Push( T * const iArray[], int iSize, CATBoolean iAcceptNull)
{
  int ret = 0;

  CATLONG32 numElt = 0;
  for ( ; numElt < iSize && !ret ; numElt ++)
  {
    T * pCurElem = iArray[numElt];
    ret = this->Push(pCurElem, iAcceptNull);
  }

  return ret;
}

// -------------------------------------------
// Push List
// -------------------------------------------
template <class T>
template <class CATLISTP>
int CATGMCollection<T>::PushList(const CATLISTP & iListPOf, CATBoolean iAcceptNullPointer)
{
  int ret = 0;
  int size = iListPOf.Size();
  int numElt = 1;
  for ( ; numElt <= size && !ret ; numElt ++)
  {
    T * pCurElem = iListPOf[numElt];
    ret = this->Push(pCurElem, iAcceptNullPointer);
  }

  return ret;
}

// -------------------------------------------
// Begin()
// -------------------------------------------
template <class T>
CATLONG32 CATGMCollection<T>::Begin () 
{
  CATLONG32 nbElem = this->Size();

  const std::deque<T*> & container = this->get_parent();

  _it = container.begin();

  return nbElem;
}

// -------------------------------------------
// Next()
// -------------------------------------------
template <class T>
T * CATGMCollection<T>::Next ()
{
  T * pNext = NULL;
  const std::deque<T*> & container = this->get_parent();

  if (_it != container.end())
  {
    pNext = *_it;
    _it ++;
  }

  return pNext;
}

// -------------------------------------------
// Find
// -------------------------------------------
template <class T>
CATBoolean CATGMCollection<T>::Find(T * iElement) const
{
  const std::deque<T*> & container = this->get_parent();
  typename std::deque<T*>::const_iterator it = container.begin();

  while (it != container.end())
  {
    if ( (*it) == iElement )
      return true;

    it++;
  }

  return false;
}

// -------------------------------------------------------
// RemoveNulls
// -------------------------------------------------------
template <class T> 
int CATGMCollection<T>::RemoveNulls()
{
  int nbremoved = 0;
  std::deque<T*> & container = this->get_parent();
  typename std::deque<T*>::iterator it = container.begin();

  while (it != container.end())
  {
    if ( (*it) == NULL )
    {
      it =  container.erase(it);
      nbremoved++;
    }
    else
      it++;
  }

  return nbremoved;
}

template <class T>
#if __cplusplus >= 201103L
int  CATGMCollection<T>::Clear( CGM::DesallocFunc<T> iDesalloc ) noexcept
#else
int  CATGMCollection<T>::Clear( HRESULT (*iDesalloc)(T *iElem) )
#endif
{
  int res = 0;
 
  if (iDesalloc)
  {
    const std::deque<T*> & container = this->get_parent();
    typename std::deque<T*>::const_iterator it = container.begin();

    HRESULT hr = S_FALSE;
    for ( ; it != container.end() && SUCCEEDED(hr) ; it++)
    {
      T * pCurElem = *it;
      hr = iDesalloc (pCurElem);
    }

    if (FAILED(hr))
      res = 1;
  }

  if (!res)
    this->get_parent().clear(); // access to protected std container 

  return res;
}

// ----------------------------------------------------------
// ToList
// ----------------------------------------------------------
template <class T>
template <class LIST>
int CATGMCollection<T>::ToList(LIST & oList) const
{
  const std::deque<T*> & container = this->get_parent();

  int nbConverted = 0;
  int numElt = 0;
  for ( ; numElt < container.size()  ; numElt ++)
  {
    T * pElement = container[numElt];
    oList.Append(pElement);
    nbConverted ++;    
  }

  return nbConverted;
}

// ----------------------------------------------------------
// ToArray
// ----------------------------------------------------------
template <class T>
void CATGMCollection<T>::ToArray ( T * oArray[] , CATULONG32 iMaxSize) const
{
  const std::deque<T*> & container = this->get_parent();

  CATLONG32 size  = container.size();
  CATLONG32 limit = ( iMaxSize < size ) ? iMaxSize : size;

  // CATLONG32 nbConverted = 0;
  CATLONG32 numElt = 0;
  for ( ; numElt < limit  ; numElt ++)
  {
    T * pElement = container[numElt];
    oArray[numElt] = pElement;
    // nbConverted ++;    
  }
}

// ------------------------------------------------------------------------------------
// operator ==
// ------------------------------------------------------------------------------------
template <class T>
CATBoolean CATGMCollection<T>::operator == (const CATGMCollection<T> & iOther) const
{
  CATBoolean equal = ( this->get_parent() == iOther.get_parent() ) ? TRUE : FALSE;
  return equal;
}

// ------------------------------------------------------------------------------------
// operator !=
// ------------------------------------------------------------------------------------
template <class T>
CATBoolean CATGMCollection<T>::operator != (const CATGMCollection<T> & iOther) const
{
  CATBoolean different = !( this-> get_parent() == iOther.get_parent() ) ? TRUE : FALSE;
  return different;
}

/** 
* return 1 if both queues are strictly idendical (same order), 0 otherwise.
*/
template <class T>
int CATGMCollection<T>::IsEqual  (const CATGMCollection<T> & iOther) const
{
  int equal = this->operator==(iOther) ? 1 : 0;

  return equal;
}

/** return 1 if both queues contains the same elements in any order,
* 0, otherwise.
*/
template <class T>
int CATGMCollection<T>::IsEquivalent (const CATGMCollection<T> & iOther) const
{
  int equivalent = 0;
  CATLONG32 size     = this->Size();
  CATLONG32 compSize = iOther.Size();

  if (!size && !compSize)
    return 1;

  if (size == compSize)
  {
    unsigned short * positionDoneTab = new unsigned short [size] ; // { 0 } ; // ne passe pas sous AIX...
    for (size_t idx = 0; idx < size; idx++) {
      positionDoneTab[idx] = 0;
    }
    equivalent = 1;
    
    CATLONG32 numElt = 0;
    for ( ; numElt < compSize && equivalent ; numElt++)
    {    
      T * pCurElement = iOther[numElt];
      CATLONG32 pos = -1;
      do {
        pos = this->locate(pCurElement, pos+1);
      }
      while ( pos >= 0 && positionDoneTab[pos]==1);

      if (pos < 0)      
        equivalent = 0;
      else
        positionDoneTab[pos] = 1;        
    }

    delete [] positionDoneTab;
  }

  return equivalent;
}

// ----------------------------------------------------------
// Protected Methods - [lower case name]
// ----------------------------------------------------------

template <class T>
T * CATGMCollection<T>::operator [](int iindex) const
{
  const std::deque<T*> & container = this->get_parent();
  return container[iindex];
}

template <class T>
T * CATGMCollection<T>::get(int iindex) const
{
  return this->get_parent().at(iindex);
}


template <class T>
CATLONG32 CATGMCollection<T>::locate(T * iElem , CATULONG32 iFrom) const
{
  CATLONG32 pos = -1;
  if (iFrom < 0)
    return -1;
  
  const std::deque<T*> & container = this->get_parent();

  CATLONG32 size = (CATLONG32) this->Size();
  CATLONG32 numElt = (CATLONG32) iFrom;
  for ( ; numElt < size && pos < 0 ; numElt ++)
  {
    T * pCurElem = container[numElt];
    if (pCurElem == iElem)
      pos = numElt;
  }

  return pos;
}

// -------------------------------------------------------------------
//  push_front
// -------------------------------------------------------------------
template <class T>
void CATGMCollection<T>::push_front( T * iElement )
{
  this->std::deque<T*>::push_front(iElement);
}

// -------------------------------------------------------------------
//  push_back
// -------------------------------------------------------------------
template <class T>
void CATGMCollection<T>::push_back ( T * iElement )
{
  this->std::deque<T*>::push_back(iElement);
}

// -------------------------------------------------------------------
//  get_parent
// -------------------------------------------------------------------
template <class T>
T * CATGMCollection<T>::pop_front()
{
  T * pFirstElem = this->Front();
  if (pFirstElem)
  {
    this->std::deque<T*>::pop_front();
    return pFirstElem;
  }

  return NULL;
}

// -------------------------------------------------------------------
//  get_parent
// -------------------------------------------------------------------
template <class T>
T *  CATGMCollection<T>::pop_back()
{
  T * pLastElem = this->Back();
  if (pLastElem)
  {
    this->std::deque<T*>::pop_back();
    return pLastElem;
  }

  return NULL;
}

// -------------------------------------------------------------------
//  get_parent
// -------------------------------------------------------------------
template <class T>
std::deque<T*> & CATGMCollection<T>::get_parent() const
{
  return (std::deque<T*> &) *this;
}



