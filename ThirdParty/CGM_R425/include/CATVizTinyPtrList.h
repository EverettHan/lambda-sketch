#ifndef _CATVizTinyPtrList_ 
#define _CATVizTinyPtrList_

#include "stdlib.h"
#include "memory.h"
#include "CATVizArrayPool.h"
template <class T> class CATVizTinyPtrList
{
public:
	inline CATVizTinyPtrList(int initialCapacity = 0);
	inline CATVizTinyPtrList(const CATVizTinyPtrList<T> & list);
	inline const CATVizTinyPtrList<T> & operator=(const CATVizTinyPtrList<T> & source);

	// destructor
	
	~CATVizTinyPtrList();

	// mëthods

	inline void Empty();
	inline void IncreaseCapacity();
	inline void IncreaseCapacity(unsigned int increment);
	inline void SetSize(unsigned int size) {if (size > m_allocatedLength) IncreaseCapacity(size - m_allocatedLength);};
	inline void Remove(T *t);
	inline void Add(T *t);

  // used for read only !!
  inline T **GetTable(unsigned int & oLength);

	inline int Length() const;

	inline T*& operator[] (int pos) const;

protected:
  unsigned int m_allocatedLength : 27;
  unsigned int m_full : 1;

	
	T **m_table;
};

template <class T>
inline CATVizTinyPtrList<T>::CATVizTinyPtrList(int initialCapacity)
:m_allocatedLength(initialCapacity),
m_table(0)
{
	if (initialCapacity)
	{
    m_table = (T**)CATVizArrayPool::AllocateArray(initialCapacity*sizeof(T*));
    m_full = 0;
    *(unsigned int *)&m_table[m_allocatedLength-1] = 0; // real size
	}
  else
    m_full = 1;
}

// copy constructor

template <class T>
inline CATVizTinyPtrList<T>::CATVizTinyPtrList(const CATVizTinyPtrList<T> & source)
:m_allocatedLength(source.m_allocatedLength),
m_full(source.m_full)
{
	if (source.m_table && source.m_allocatedLength)
	{
		m_table = (T**)CATVizArrayPool::AllocateArray(m_allocatedLength*sizeof(T*));

		memcpy(m_table,source.m_table,m_allocatedLength*sizeof(T*));
	}
	else
	{
		m_table = 0;
	}
}

///////////////////////////////////////////////
// destructor
///////////////////////////////////////////////

template <class T>
inline CATVizTinyPtrList<T>::~CATVizTinyPtrList()
{
  if (m_table) CATVizArrayPool::FreeArray(m_allocatedLength*sizeof(T*),m_table);
   m_table  = NULL;
   m_allocatedLength = 0;
   m_full = 1;
}


///////////////////////////////////////////////
// methods
///////////////////////////////////////////////

template <class T>
inline void CATVizTinyPtrList<T>::Add(T *t)
{
	if (m_full)
		IncreaseCapacity();

  int realLength = *(unsigned int *)&m_table[m_allocatedLength-1];
	m_table[realLength++] = t;
  if (realLength == m_allocatedLength)
    m_full = 1;
  else
    *(unsigned int *)&m_table[m_allocatedLength-1] = realLength;
}


template <class T>
inline void CATVizTinyPtrList<T>::Empty()
{
  if (m_allocatedLength)
  {
    *(int *)&m_table[m_allocatedLength-1] = 0; // real size
    m_full = 0;
  }
}


template <class T>
inline const CATVizTinyPtrList<T> &  CATVizTinyPtrList<T>::operator=(const CATVizTinyPtrList<T> & source)
{
  if(m_table)	CATVizArrayPool::FreeArray(m_allocatedLength*sizeof(T*),m_table);
  m_table = NULL;

  m_full = source.m_full;
  m_allocatedLength = source.m_allocatedLength;

  if (source.m_table && source.m_allocatedLength)
  {
    m_table = (T**)CATVizArrayPool::AllocateArray(m_allocatedLength*sizeof(T*));

    memcpy(m_table,source.m_table,m_allocatedLength*sizeof(T*));
  }
  else
  {
    m_table = 0;
  }

  return (*this);
}


template <class T>
inline int CATVizTinyPtrList<T>::Length() const
{
  unsigned int length = 0;
  if (m_full)
    length = m_allocatedLength;
  else
    length = *(unsigned int *)&m_table[m_allocatedLength-1];
	return length;
}

template <class T>
inline T *& CATVizTinyPtrList<T>::operator[] (int pos) const
{
  return m_table[pos];	
}

template <class T>
inline void CATVizTinyPtrList<T>::Remove(T *t)
{
  int usedSize = Length();
  for (int i = 0 ; i < usedSize ; ++i)
  {
    if (m_table[i] == t)
    {
      m_table[i] = m_table[usedSize-1];
      *(unsigned int *)&m_table[m_allocatedLength-1] = usedSize-1;
      m_full = 0;
      break;
    }
  }
}

template <class T>
inline void CATVizTinyPtrList<T>::IncreaseCapacity()
{
  IncreaseCapacity(1);

}

template <class T>
inline void CATVizTinyPtrList<T>::IncreaseCapacity(unsigned int increment)
	{
    if (increment == 0)
      return;

    unsigned int usedSize = Length();
    unsigned int newSize = m_allocatedLength + increment;
		if (m_table)
    {
      T **newTab = (T **)CATVizArrayPool::AllocateArray(newSize*sizeof(T*));
      memcpy(newTab,m_table,usedSize*sizeof(T*));
      CATVizArrayPool::FreeArray(m_allocatedLength*sizeof(T*),m_table);
      m_allocatedLength = newSize;
      m_full = 0;
      m_table = newTab;
      *(unsigned int *)&m_table[m_allocatedLength-1] = usedSize;
    }
		else
		{
			m_table = (T **)CATVizArrayPool::AllocateArray(newSize*sizeof(T*));
      m_allocatedLength = newSize;
      m_full = 0;
      *(unsigned int *)&m_table[m_allocatedLength-1] = usedSize;
		}
	}

template <class T>
inline T **CATVizTinyPtrList<T>::GetTable(unsigned int & oLength)
{
  oLength = Length();
  return m_table;
}

#endif
