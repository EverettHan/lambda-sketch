#ifndef _CATVizPtrList_ 
#define _CATVizPtrList_

#include "stdlib.h"
#include "memory.h"

template <class T> class CATVizPtrList
{
public:
	inline CATVizPtrList(int initialCapacity = 0, int increment = 10, int initMemory = 0);
	inline CATVizPtrList(const CATVizPtrList<T> & list);
	inline const CATVizPtrList<T> & operator=(const CATVizPtrList<T> & source);

	// destructor
	
	~CATVizPtrList();

	// mëthods

	inline void Empty();
	inline void IncreaseCapacity();
	inline void IncreaseCapacity(int increment);
//	inline void InitToHead() const;
//	inline T *NextElement() const;
	inline int Find(T *t) const;

	inline int Find(T *t, int startIndex) const;

	inline void SetSize(int size) {if (size > m_length) IncreaseCapacity(size - m_length);};
	inline void SetIncrement(int increment) {m_increment = increment;};
	inline int GetIncrement() {return m_increment;};
	inline void Remove(T *t);

	inline T *GetHead() const;
	inline T *GetTail() const;
	inline void AddHead(T *t);
	inline void AddTail(T *t);	
	inline int AddUnique(T *t);
	inline void InsertAt(int pos, T *t);

	inline T *RemoveAtHead();
	inline T *RemoveAt(int pos);

	inline int Length() const;

	inline T* operator[] (int pos) const;
//	inline T* & operator[] (int pos);

	inline void Sort(int ( *compare )(const void *elem1, const void *elem2 ));

	inline void Replace(T *oldValue, T*newValue);
	inline void Set(int index, T*value);
protected:
	int m_length, m_increment;
	int m_realLength;

	
	T **m_table;
//	T** m_currentElement;

};

template <class T>
inline CATVizPtrList<T>::CATVizPtrList(int length, int increment, int initMemory)
:m_length(0),
m_realLength(length),
m_increment(increment),
m_table(0)
{
	if (length)
	{
		m_table = (T**)malloc(sizeof(T*) * length);
		if (initMemory && increment == 0 && m_table) // e8c : static code analysis
		{
			m_length = m_realLength;
			memset(m_table, 0, sizeof(T*) * length);
		}
	}
}

// copy constructor

template <class T>
inline CATVizPtrList<T>::CATVizPtrList(const CATVizPtrList<T> & source)
:m_length(source.m_length),
m_increment(source.m_increment),
m_realLength(source.m_realLength)
{
	if (source.m_table && source.m_realLength)
	{
		m_table = (T**)malloc(sizeof(T*)*m_realLength);

		if (m_table) // e8c : static code analysis
			memcpy(m_table,source.m_table,m_length*sizeof(T*));
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
inline CATVizPtrList<T>::~CATVizPtrList()
{
	if (m_table) free(m_table);
   m_table  = NULL;
   m_length = 0;
   m_realLength = 0;
}


///////////////////////////////////////////////
// methods
///////////////////////////////////////////////

template <class T>
inline void CATVizPtrList<T>::AddHead(T *t)
{
	if (m_length >= m_realLength)
		IncreaseCapacity();	

	if (!m_table) return; // e8c : static code analysis

	memmove(&m_table[1],m_table,m_length*sizeof(T *));
	*m_table = t;
	m_length++;
}

template <class T>
inline void CATVizPtrList<T>::AddTail(T *t)
{
	if (m_length >= m_realLength)
		IncreaseCapacity();

	if (!m_table) return; // e8c : static code analysis

	m_table[m_length++] = t;
}

template <class T>
inline T *CATVizPtrList<T>::RemoveAtHead()
{
	if (m_length == 0)
		return NULL;
	else
		return RemoveAt(0);
}



template <class T>
inline T *CATVizPtrList<T>::RemoveAt(int pos)
{
   if (pos < 0 || pos > m_length - 1 || !m_table)
      return NULL;
	T *returnValue = m_table[pos];

	for (int i = pos ; i < m_length - 1 ; ++i)
	{
		m_table[i] = m_table[i+1];
	}
	
	m_length--;
	return returnValue;
}

template <class T>
inline void CATVizPtrList<T>::InsertAt(int pos, T *t)
{
	if (pos < m_length)
	{
		if (m_length  >= m_realLength)
			IncreaseCapacity();

		if (!m_table) return; // e8c : static code analysis

		memmove(&m_table[pos + 1],&m_table[pos],(m_length - pos)*sizeof(T *));
		m_table[pos] = t;
		m_length++;
	}
	else
		AddTail(t);
}


template <class T>
inline void CATVizPtrList<T>::Empty()
{
	m_length = 0;
}


template <class T>
inline const CATVizPtrList<T> &  CATVizPtrList<T>::operator=(const CATVizPtrList<T> & source)
{
   if(m_table)	free(m_table);
   m_table = NULL;

	m_length = source.m_length;
	m_increment = source.m_increment;
	m_realLength = source.m_realLength;

   if(m_realLength)
   {
	   m_table = (T**)malloc(sizeof(T*)*m_realLength);
		 if (m_table) // e8c : static code analysis
			 memcpy(m_table,source.m_table,m_length*sizeof(T*));
   }

	return (*this);
}


template <class T>
inline T *CATVizPtrList<T>::GetHead() const
{
	return m_table ? *m_table : NULL;
}

template <class T>
inline T *CATVizPtrList<T>::GetTail() const
{
	return m_table ? m_table[m_length - 1] : NULL;
}

template <class T>
inline int CATVizPtrList<T>::Length() const
{
	return m_length;
}

template <class T>
inline T *CATVizPtrList<T>::operator[] (int pos) const
{
	if (pos < 0 || pos > m_length - 1 || !m_table)
		return NULL;
	else
		return m_table[pos];
}

/*
template <class T>
	void CATVizPtrList<T>::InitToHead() const
	{
		((CATVizPtrList *)this)->m_currentElement = m_table;
	}
	
template <class T>
	T *CATVizPtrList<T>::NextElement() const
	{
		if (m_table && (m_currentElement < &m_table[m_length]))
			return *((((CATVizPtrList *)this)->m_currentElement)++);
		else
			return 0;
	}
*/		
template <class T>
inline void CATVizPtrList<T>::Remove(T *t)
	{
		int pos = Find(t);
		if (pos != -1)
			RemoveAt(pos);
	}

template <class T>
inline int CATVizPtrList<T>::Find(T *t) const
	{
		if (!m_table) return -1; // e8c : static code analysis

		for (int i = 0 ; i < m_length ; ++i)	
		{
			if (m_table[i] == t)
				return i;
		}

		return -1;
	}

	
template <class T>
inline int CATVizPtrList<T>::Find(T *t, int startIndex) const
	{
		if (!m_table || startIndex < 0) return -1; // e8c : static code analysis

		for (int i = startIndex ; i < m_length ; ++i)	
		{
			if (m_table[i] == t)
				return i;
		}

		return -1;
	}

template <class T>
inline void CATVizPtrList<T>::IncreaseCapacity()
	{
		IncreaseCapacity(m_increment);
	}

template <class T>
inline void CATVizPtrList<T>::IncreaseCapacity(int increment)
	{
		m_realLength += increment;
    if (m_realLength > 0) //D1A (9-Apr-2019): fix NSA-213409
    {
			if (m_table)
			{
				// e8c : static code analysis
				T** table = (T**)realloc(m_table, m_realLength * sizeof(T*));
				if (table)
					m_table = table;
			}
      else
      {
        m_table = (T **)malloc(m_realLength * sizeof(T *));
      }
    }
	}


template <class T>
inline void CATVizPtrList<T>::Sort(int ( *compare )(const void *elem1, const void *elem2 ))
{
	if (!m_table) return; // e8c : static code analysis
	qsort((void *)m_table, m_length, sizeof(T *),compare);
}


template <class T>
inline int CATVizPtrList<T>::AddUnique(T *t)
{		
	if (Find(t) == -1)
	{
		AddTail(t);
		return 1;
	}
	else
		return 0;
}

template <class T>
inline void CATVizPtrList<T>::Replace(T *oldValue, T*newValue)
{
	int pos = Find(oldValue);
	if (pos != -1)
		m_table[pos] = newValue;
}

template <class T>
inline void CATVizPtrList<T>::Set(int index, T*newValue)
{
		if (index < 0 || index > m_length - 1 || !m_table) return; // e8c : static code analysis
		m_table[index] = newValue;
}

#endif
