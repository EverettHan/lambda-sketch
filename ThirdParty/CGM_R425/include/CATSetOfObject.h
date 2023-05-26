#ifndef CATSetOfObject_h
#define CATSetOfObject_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 1999

#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "SGInfra.h"
/**
* A set of objects.
* <br><b>Role</b> : Enclosed objects are instances of the @href CATBaseUnknown class.
* This class does not make use of the AddRef/Release mechanism when adding or removing object.
*/
class ExportedBySGInfra CATSetOfObject 
{
  public:

 /**
  * Default constructor.
  *
  * @param iSize
  *        It is the size of the set.
  */
  inline CATSetOfObject (int iSize=0);

  /** Copy Constructor .
   * @param iList
   * The list to copy. 
   */
  inline CATSetOfObject (const CATSetOfObject & iList) ;


  inline ~CATSetOfObject();

   /**
   * Subscripting operator.
   * <br><b>Role</b> : returns an object using the object index.
   * <br><b>Lifecycle rules deviation</b> : This method doesn't AddRef returned value.
   *
   * @param iIndex
   *        The index
   *        <br><b>Legal values</b> : <tt>iIndex</tt> values are between 0 and GetSize()-1.
   * @return
   *        The object.
   */
  inline void * operator [] (int iIndex) const ;
  
 /**
  * Adds an element to the set.
  *
  * @param iObject
  *   The element to add to the set.
  *   <br><b>Lifecycle rules deviation</b> : This method doesn't AddRef returned value.
  */
  inline void operator += ( void * iObject ) ;

   /**
   * Removes an element from the set.
   *
   * @param iObject
   *        The objectto remove.
   *        <br><b>Lifecycle rules deviation</b> : No release is done on this object.
   */
  inline void operator -= ( void * iObject ) ;

   /** Assignment operator.
   * &param iList
   * The list of object's pointer to copy. 
   */
  inline void operator = (const CATSetOfObject & iList) ;

  
  /**
   * Removes all elements from the set.
   * No releases are done on the objects.
   */
   inline void Empty ();


  /**
   * Checks if an element ready exists in the set.
   *
   * @param iElem
   *        The object to look for.
   * @return
   *        <br><b>Legal values</b> : return 0 if the element isn't in the set, otherwise return 1.
   */
   inline int IsMember (void *iElem);


  /**
   * Returns the count of elements in the set.
   *
   * @return
   *        Return the size of the set.
   */
   inline int GetSize ();

  /**
   * Gathers an other set with this one.
   *
   * @param iSo
   *            The set of elements to add.
   */
   //   void Gather(CATSetOfObject *iSo);


  

   
 protected:
  
  /** @nodoc */
  int _size, _memsize;
  /** @nodoc */
  void ** _tab;
   
  
};


inline CATSetOfObject::CATSetOfObject(int iSize) : _size(0), _memsize(iSize) 
{ if (iSize) 
  {
    _tab = (void **) malloc (iSize * sizeof( void *) );
    if (!_tab) _size = _memsize = 0;
  }
 else
 {
   _tab = NULL;
 }
  
}



inline void CATSetOfObject::Empty()
{
   if ( _tab ) free(_tab);
   _size = _memsize = 0;
   _tab  = 0;
}

inline CATSetOfObject::~CATSetOfObject() { Empty(); }

inline void CATSetOfObject::operator += ( void * t )
{ 
 if (t)
 {
  if(_memsize <= _size)
  {
   _memsize = (_memsize == 0) ? 5 : _memsize + (_memsize >> 1) ;
   void ** newtab = (void **) malloc (_memsize * sizeof( void *) );
   if ( _tab && newtab && _size )
   {
     newtab = (void **) memcpy(newtab, _tab,_size*sizeof(void *));
     free(_tab);
   }
   _tab = newtab;
  }
  if ( !_tab ) 
  {
   _size = _memsize = 0;
  }
  else
  {
   this->_tab[this->_size] = t;
   this->_size++ ; 
  }
 }
}

inline int CATSetOfObject::IsMember( void * t)
{
  for(int i = _size -1; i >= 0; i--) if(_tab[i] == t) return i;
  return -1;
}

inline void CATSetOfObject::operator -= ( void * t )
{ 
  int index = IsMember(t);
  if(index < 0 || index >= _size) 
  {
    1;
  }
  else
  {
    _size--;
    for(int j = index; j < _size; j++) _tab[j] = _tab[j+1];
  }
}



inline void CATSetOfObject::operator = (const CATSetOfObject & iList) 
{
  _memsize = iList._memsize;
  _size = iList._size;
  if (_tab) free(_tab);
  if ( _size )
  {
   _tab = (void **) malloc (_size * sizeof( void *) );
   if (_tab)
   {
    void **g;
    int ii;
    for ( ii=0, g = iList._tab ; ii<_size ;ii++, g++)
    {
     _tab[ii] = *g;
    }
   }
  }
  else
   _tab=NULL;
  
}

inline CATSetOfObject::CATSetOfObject(const CATSetOfObject & iList) 
{
  _memsize = iList._memsize;
  _size = iList._size;
  if ( _size )
  {
   _tab = (void **) malloc (_size * sizeof( void *) );
   if (_tab)
   {
    void **g;
    int ii;
    for ( ii=0, g = iList._tab ; ii<_size ;ii++, g++)
    {
     _tab[ii] = *g;
    }
   }
  }
  else
   _tab=NULL;
  
}

inline void * CATSetOfObject::operator [] (int i) const { return ( (i>=0) && (i<_size) ? _tab[i] : 0); }

inline int CATSetOfObject::GetSize() { return _size; }



#endif
