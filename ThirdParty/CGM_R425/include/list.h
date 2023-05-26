#ifndef LIST_H
#define LIST_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


/**
 * Class to create a list of pointers to objects.
 * <br><b>HOW TO CREATE A LIST</b>
 * <br>list<toto> li;        empty list creation
 * <br>list<toto> li2(li);   copy-constructor
 * <br>
 * <br><b>HOW TO ADD ELEMENTS</b>
 * <br>
 * <br>toto * pg1 = new toto(), * pg2 = new toto(), * pg3 = new toto();
 * <br>li += pg1;
 * <br>li += pg2;
 * <br>li += pg3;
 * <br>
 * <br><b>HOW TO WRITE LOOPS</b>
 * <br>
 * <br> To access the elements of the list, use the [] operator.
 * This operator tests for end-of-list and returns 0 if
 * the index is beyond the end.
 * <br>
 * <br> The nicest form of loop, uses the [] operator behavior
 * as the end condition.
 * <br>
 * <br>for(int i = 0; g = li[i]; i++)
 * <br>{
 * <br> g->draw();
 * <br>}
 * <br>
 * <br>A more traditional form of loop, gets size first, not as pretty.
 * <br>
 * <br>int siz = li.length();    Fetch length of list
 * <br>
 * <br>for(int i = 0, i < siz, i++)
 * <br>{
 * <br>    li[i]->draw();
 * <br>}
 * <br>
 * <br><b>HOW TO REMOVE ELEMENTS FROM THE LIST</b>
 * <br>
 * <br>li -= pg1   Remove pg1 from the list.
 * <br>
 * <br>li.empty();   Remove all elements from the list, leave
 * list in the same state as when it was
 * first created. If you want to delete all
 * the objects in the list first (assuming
 * they were created with new) then do
 * <br>
 * <br>for(int i = 0; g = li[i]; i++)
 * <br>{
 * <br>   delete g;
 * <br>}
 * <br>
 * <br>li.empty();
 * <br>
 * <br><b>HOW TO REORDER THE LIST</b>
 * <br> The swap call swaps the position of two elements. Like
 *  this you can order the list if you want to.
 * <br>
 * <br>li.swap(2,5);   exchanges the position of the element in
 * position 2 and the element in position 5.
 * <br>
 * <br><b>NOTE - A FORM OF LOOPING THAT IS DELICATE</b>
 * <br> This form of access uses an internal cursor:
 * <br>
 * <br> operator ! sets the cursor to 0.
 * <br> operator ++ advances by 1 element and returns 0 at end.
 * <br>
 * <br><b>CORRECT USE</b> of ! and ++.
 * <br>
 * <br>for(!li; g = ++li;)
 * <br>{
 * <br> g->draw();
 * <br>}
 * <br>
 * <br><b>BAD USE</b> of ! and ++
 * <br>
 * <br>toto * g1, * g2;               BAD BAD BAD
 * <br>                               BAD BAD BAD
 * <br>for(!li; g1 = ++li;)           BAD BAD BAD
 * <br>{                              BAD BAD BAD !!!!
 * <br> for(!li; g2 = ++li;)          BAD BAD BAD
 * <br> {                             BAD BAD BAD !!!!
 * <br>  g1->draw_connection(g2);
 * <br> }
 * <br>}
 * <br>
 * <br><b>GENERAL WARNING</b>
 * <br>
 * <br><b>THIS IS A LIST FOR OBJECTS</b>. Do not use this list for storing
 * base types. Do not make any instances of list<char>, list
 * <int>, list<double>. This list is meant for OBJECTS. If you
 * must create character strings, use a "String" type object.
 */

#include "baselist.h"


template <class T> class list ;

// ---- Declaration of the friend function  operator <<
//      (needed because of a compilation problem on Windows)

template <class T> class list : public baselist<T*>
{


  public:

    /** Create an empty list of object's pointers. */
    inline list() ;

    /**
     * @deprecated R424 - call operator+=(T*) instead, and do not use objects allocated on the stack unless you know what you are doing.
     *
     * Addition assignement operator.
     * @param iObject
     * The object to add at the end of the list and if does not exist already
     * in the list.
     */
    inline void operator += ( T & iObject ) ;

    /**
     * @deprecated R424 - call operator-=(T*) instead.
     *
     * Substraction assignement operator.
     * @param iObject
     * The object to remove of the list.
     */
    inline void operator -= ( T & iObject ) ;

    /** Addition assignement operator.
     * @param iObject
     * The object to add at the end of the list and if does not exist already
     * in the list.
     * Warning: do not use objects allocated on the stack unless you know what you are doing.
     */
    inline void operator += ( T * iObject ) ;

    /** Substraction assignement operator.
     * @param iObject
     * The object to remove of the list.
     */
    inline void operator -= ( T * iObject ) ;

    /**
     * @deprecated R424 - call fastadd(T*) instead, and do not use objects allocated on the stack unless you know what you are doing.
     *
     * Add an object at the end of the list without control.
     * @param iObject
     * The object to add at the end of the list without control.
     */
    inline void fastadd (T & iObject) ;

    /** Add an object at the end of the list without control.
     * @param iObject
     * The object to add at the end of the list without control.
     * Warning: do not use objects allocated on the stack unless you know what you are doing.
     */
    inline void fastadd (T * iObject) ;

    /** Subscripting operator.
     * @param iPosition
     * The object's position in the list.
     * @return
     * The object's pointer.
     */
    inline T * operator [] (int i) const ;

    /** Prefix increment operator.
     * @return
     * The object's pointer.
     */
    inline T * operator ++ () ;

    /** Logical-negation operator.
     * <br><b>Role</b>: Sets the cursor to the top of the list.
     */
    inline void operator ! () ;

    /** Swap two objects in the list.
     * @param iObject1
     * The first object to swap.
     * @param iObject2
     * The second object to swap.
     */
    inline void swap(int iObject1, int iObject2) ;


    /** @nodoc */
    inline void fastinsert(T * t);
    /** @nodoc */
    inline void fastinsert(T & t);
    /** @nodoc */
    inline void operator <= (T * t);
    /** @nodoc */
    inline void operator <= (T & t);

};

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline ::list<T>::list() : baselist<T*>() {}
#else
template <class T> inline list<T>::list() : baselist<T*>() {}
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator += (T & t)
#else
template <class T> inline void list<T>::operator += ( T & t )
#endif
{
 if (!this->ismember(&t))
   this->doadd(&t);
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator += (T * t)
#else
template <class T> inline void list<T>::operator += ( T * t )
#endif
{
 if (t)
 {
  if (!this->ismember(t))
    this->doadd(t);
 }
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator -= ( T & t )
#else
template <class T> inline void list<T>::operator -= ( T & t )
#endif
{
  int i = this->remove(&t);
  if(i < this->cursor) this->cursor--;
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator -= ( T * t )
#else
template <class T> inline void list<T>::operator -= ( T * t )
#endif
{
  int i = this->remove(t);
  if(i < this->cursor) this->cursor--;
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::fastadd (T & t)
#else
template <class T> inline void list<T>::fastadd (T & t)
#endif
{
  this->doadd(&t);
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::fastadd(T * t)
#else
template <class T> inline void list<T>::fastadd (T * t)
#endif
{
  this->doadd(t);
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline T * ::list<T>::operator [] (int i) const
#else
template <class T> inline T * list<T>::operator [] (int i) const
#endif
{
  return i < this->size ? this->lis[i] : 0;
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline T * ::list<T>::operator ++ ()
#else
template <class T> inline T * list<T>::operator ++ ()
#endif
{
  return this->cursor < this->size ? this->lis[this->cursor++] : 0;
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator ! () { this->cursor = 0; }
#else
template <class T> inline void list<T>::operator ! () { this->cursor = 0; }
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::swap(int i, int j)
#else
template <class T> inline void list<T>::swap(int i, int j)
#endif
{
    if(i >= this->size || j >= this->size) return;
    T * t;
    t = this->lis[i];
    this->lis[i] = this->lis[j];
    this->lis[j] = t;
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::fastinsert(T * t)
#else
template <class T> inline void list<T>::fastinsert(T * t)
#endif
{
  this->insert(t);
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::fastinsert(T & t)
#else
template <class T> inline void list<T>::fastinsert(T & t)
#endif
{
  this->insert(&t);
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator <= (T * t)
#else
template <class T> inline void list<T>::operator <= (T * t)
#endif
{
  if (t)
  {
    if (!this->ismember(t))
      this->insert(t);
  }
}

#if defined(_MSC_VER) && (_MSC_VER >= 1924)
template <class T> inline void ::list<T>::operator <= (T & t)
#else
template <class T> inline void list<T>::operator <= (T & t)
#endif
{
  if (!this->ismember(&t))
    this->insert(&t);
}

#endif
