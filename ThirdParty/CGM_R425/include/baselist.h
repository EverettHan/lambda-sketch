#ifndef BASELIST_H
#define BASELIST_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @nodoc
 * Class to create a list.
 */
#define MD(x) ((int)(x) % 10000)

template <class T> class baselist
{
  protected:

    int size;
    int startSize;
    int endSize;
public:
    int cursor;
protected:
    T * lis;

    /**
     * @nodoc
     */
    inline baselist() ;

    /**
     * @nodoc
     */
    inline baselist(const baselist<T> & b) ;

    /**
     * @nodoc
     */
    inline ~baselist() ;

    /**
     * @nodoc
     */
    inline void fixStartSize() ;

    /**
     * @nodoc
     */
    inline void fixEndSize() ;

    /**
     * @nodoc
     */
    inline void doadd(const T & t) ;

    /**
     * @nodoc
     */
    inline void add(const T & t)   ;

    /**
      * @nodoc
      */
    inline void insert(const T & t);


  public:
	 inline unsigned int getAllocatedSize();

    /**
     * @nodoc
     */
    inline int remove(const T & t) ;

    /** Indicates if the object's pointer is in the list.
     * @param iObject
     * The object's pointer tos search.
     * @return
     * The status.
     */
    inline int ismember(const T & t) const ;

    /**
     * @nodoc
     */
    inline int index(const T & t) const ;

    /** Indicates the length of the list.
     * @return
     * The length.
     */
    inline int length() const ;

    /** Empties the list. (but does not delete objects.)
     */
    inline void empty() ;

    /** Assignment operator.
     * &param iObject
     * The list of object's pointer to copy.
     */
    inline void operator = (const baselist<T> & iList) ;

} ;

template <class T> inline baselist<T>::baselist()

   : size(0),  startSize(0),endSize(0), cursor(0), lis(0)
{}

template <class T> inline baselist<T>::baselist(const baselist<T> & b)

  : size(0),  startSize(0),endSize(0), cursor(0), lis(0)
{
   *this = b;
}

template <class T> inline void baselist<T>::empty()
{
   if ( lis ) delete [] (lis - startSize);
   size = 0;
   startSize = endSize = 0;
   lis  = 0;
}

template <class T> inline baselist<T>::~baselist() { empty(); }

template <class T> inline void baselist<T>::fixEndSize()
{
    if( !endSize )
    {
       endSize = (size == 0) ? 1 : size ;
       T * newlis = new T [startSize+size+endSize];
       newlis += startSize;
       for(int i = 0; i < size; i++)
         newlis[i] = lis[i];
       if ( lis ) delete [] (lis - startSize);
       lis = newlis;
    }
}

template <class T> inline void baselist<T>::fixStartSize()
{
    if(! startSize)
    {
       startSize = (size ==0 ? 1 : size);
       T * newlis = new T [startSize + size + endSize];
       newlis += startSize ;
       for(int i = 0; i <size ; i++) newlis[i] = lis[i];
       if ( lis ) delete [] lis;
       lis = newlis;
    }
}

template <class T> inline void baselist<T>::doadd(const T & t)
{
    fixEndSize() ;
    lis[size] = t ;
    endSize--;
    size++ ;
}

template <class T> inline void baselist<T>::insert(const T & t)
{
    fixStartSize();
    lis[-1] = t;
    lis-=1;
    size++;
    startSize--;
}

template <class T> inline int baselist<T>::ismember(const T & t) const
{
   return (index(t) < 0) ? 0 : 1;
}

template <class T> inline void baselist<T>::add(const T & t)
{
    if(!ismember(t)) doadd(t);
}

// return value is index of removed item
template <class T> inline int baselist<T>::remove(const T & t)
{                        // (except in error case)
  int i = index(t);
  if(i < 0 || i >= size) return size;

  for(int j = i; j < size-1; j++) lis[j] = lis[j+1];
  endSize++;
  size --;

  return i;
}

template <class T> inline int baselist<T>::index (const T & t) const
{
    for(int i = size -1; i >= 0; i--) if(lis[i] == t) return i;
    return -1;
}

template <class T> inline int baselist<T>::length() const
{ return size; }

template <class T> inline void baselist<T>::operator = (const baselist<T> & b)
{
  if ( lis )
    delete [] (lis - startSize);

  size = b.size;
  startSize = b.startSize;
  endSize = b.endSize;
  cursor = b.cursor;
  lis = 0;

  int s =size+startSize+endSize;

  if (s)
  {
    lis = new T [s];
    lis += startSize;

    for(int i = 0; i < size; i++) lis[i] = b.lis[i];
  }
}

template <class T> inline unsigned int baselist<T>::getAllocatedSize()
{
	return (size+startSize+endSize)*sizeof(T*);
}


#endif




