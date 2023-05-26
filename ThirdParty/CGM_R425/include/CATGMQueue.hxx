//
// CATGMQueue.hxx
// ---------------------------------------------

/**
* C++ created by QF2 08/06/2022
*/
// --------------------------------------------------------

// #include "CATlsoError.h"
#include <deque> 
// ==============================================================
//        Class CATGMQueueNode
// ==============================================================
//template <class T>
//CATGMQueue<T>::CATGMQueueNode::CATGMQueueNode (T * iElem) :
//_Data(iElem),
//_Next(NULL)
//{
//}
//
//template <class T>
//CATGMQueue<T>::CATGMQueueNode::~CATGMQueueNode()
//{
//  _Data  = NULL;
//  _Next  = NULL;
//}


// ==============================================================
//        Class CATGMQueue
// ==============================================================

// Contructor
// --------------------------------------
template <class T>
CATGMQueue<T>::CATGMQueue()
{
  const std::deque<T*> & container = this->get_container();
  
  _it = container.end();
}


// Copy Contructor
// --------------------------------------
template <class T>
CATGMQueue<T>::CATGMQueue( const CATGMQueue<T> & iOther) :
std::queue<T*>(iOther)
{
  const std::deque<T*> & container = this->get_container();
  _it = container.end();
}

// --------------------------------------
// Destructor
// --------------------------------------
template <class T>
CATGMQueue<T>::~CATGMQueue()
{
  const std::deque<T*> & container = this->get_container();
  _it = container.end();
}


// access the first element 
template <class T>
T * CATGMQueue<T>::Front() const
{
  return this->get_container().front();
}


// access the last element 
template <class T>
T * CATGMQueue<T>::Back()  const
{
  return this->get_container().back();
}


// --------------------------------------
// Push : Add Element at the End
// --------------------------------------
template <class T>
int CATGMQueue<T>::Push(T * iElement, CATBoolean iAcceptNullPointer)
{
  int nbElem = 0;
  if (iAcceptNullPointer || iElement)
  {
    this->std::queue<T*>::push(iElement);
    nbElem = 1;
  }

  return nbElem;
}

// --------------------------------------
// Push : Add Elements at the End
// --------------------------------------
template <class T>
int CATGMQueue<T>::Push(const CATGMQueue<T> & iConcat, CATBoolean iAcceptNullPointer)
{
  int nbElem = 0;
  const std::deque<T*> & container = this->get_container();

  typename std::deque<T*>::const_iterator it = container.begin();

  for ( ; it != container.end() ; it++)
  {
    T * pCurElem = *it;
    nbElem += this->Push(pCurElem, iAcceptNullPointer);
  }

  return nbElem;
}

// ------------------------------------------
// Pop : Return the Top Element of the liste
// -------------------------------------------
template <class T>
T * CATGMQueue<T>::Pop ()
{  
  T * pFirst = NULL;
  if ( ! this->Empty() )
  {
    pFirst = this->std::queue<T*>::front();
    this->std::queue<T*>::pop();
  }

  return pFirst;
}


// -------------------------------------------
// Begin()
// -------------------------------------------
template <class T>
int CATGMQueue<T>::Begin () 
{
  int nbElem = this->Size();

  const std::deque<T*> & container = this->get_container();
  _it = container.begin();

  return nbElem;
}

// -------------------------------------------
// Next()
// -------------------------------------------
template <class T>
T * CATGMQueue<T>::Next ()
{
  T * pNext = NULL;
  const std::deque<T*> & container = this->get_container();

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
bool CATGMQueue<T>::Find(T * iElement) const
{
  const std::deque<T*> & container = this->get_container();
  typename std::deque<T*>::const_iterator it = container.begin();

  while (it != container.end())
  {
    if ( (*it) == iElement )
      return true;

    it++;
  }

  return false;
}
// -------------------------------------------
// Size()
// -------------------------------------------
template <class T>
int CATGMQueue<T>::Size() const 
{
  // return _Size;
  return (int) this->std::queue<T*>::size();
}

// -------------------------------------------
// Empty()
// -------------------------------------------
template <class T>
CATBoolean CATGMQueue<T>::Empty() const
{
  return this->std::queue<T*>::empty();
}


template <class T>
#if __cplusplus >= 201103L // >= C++11
int  CATGMQueue<T>::Clear( CGM::DesallocFunc<T> iDesalloc )
#else
int  CATGMQueue<T>::Clear( HRESULT (*iDesalloc)(T *iElem) )
#endif
{
  int res = 0;
 
  if (iDesalloc)
  {
    const std::deque<T*> & container = this->get_container();
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
    this->std::queue<T*>::c.clear(); // access to protected std container 

  return res;
}


// ------------------------------------------------------------------------------------
// operator ==
// ------------------------------------------------------------------------------------
template <class T>
CATBoolean CATGMQueue<T>::operator == (const CATGMQueue<T> & iOther) const
{
  CATBoolean equal = ( this->get_parent() == iOther.get_parent() ) ? TRUE : FALSE;
  return equal;
}

// ------------------------------------------------------------------------------------
// operator !=
// ------------------------------------------------------------------------------------
template <class T>
CATBoolean CATGMQueue<T>::operator != (const CATGMQueue<T> & iOther) const
{
  CATBoolean different = ( this->get_parent() != iOther.get_parent() ) ? TRUE : FALSE;
  return different;
}

/** 
* return 1 if both queues are strictly idendical (same order), 0 otherwise.
*/
template <class T>
int CATGMQueue<T>::IsEqual  (const CATGMQueue<T> & iOther) const
{
  int equal = this->operator==(iOther) ? 1 : 0;

  return equal;
}

/** return 1 if both queues contains the same elements in any order,
* 0, otherwise.
*/
template <class T>
int CATGMQueue<T>::IsEquivalent (const CATGMQueue<T> & iOther) const
{
  int equivalent = 0;
  int size     = this->Size();
  int compSize = iOther.Size();

  if (!size && !compSize)
    return 1;

  if (size == compSize)
  {
    unsigned short * positionDoneTab = new unsigned short [size] { 0 };
    equivalent = 1;
    
    int numElt = 0;
    for ( ; numElt < compSize && equivalent ; numElt++)
    {    
      T * pCurElement = iOther[numElt];
      int pos = -1;
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
T * CATGMQueue<T>::operator [](int iindex) const
{
  const std::deque<T*> & container = this->get_container();
  return container[iindex];
}


template <class T>
int CATGMQueue<T>::locate(T * iElem , int iFrom) const
{
  int pos = -1;
  if (iFrom < 0)
    return -1;
  
  const std::deque<T*> & container = this->get_container();

  int size = this->Size();
  int numElt = iFrom;
  for ( ; numElt < size && pos < 0 ; numElt ++)
  {
    T * pCurElem = container[numElt];
    if (pCurElem == iElem)
      pos = numElt;
  }

  return pos;
}


// -------------------------------------------------------------------
//  get_parent
// -------------------------------------------------------------------
template <class T>
const std::queue<T*> & CATGMQueue<T>::get_parent() const
{
  return *this;
}

// -------------------------------------------------------------------
// get_container
// -------------------------------------------------------------------
template <class T>
const std::deque<T*> & CATGMQueue<T>::get_container() const
{
  return this->std::queue<T*>::c;
}

