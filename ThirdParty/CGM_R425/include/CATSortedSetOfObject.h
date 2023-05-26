#ifndef CATSortedSetOfObject_h
#define CATSortedSetOfObject_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @quickReview CDT 02:12:06
 **/
#include "SGInfra.h"
#include "CATSetOfObject.h"
#include <string.h>


/**
* A set of objects.
* <br><b>Role</b> : Enclosed objects are instances of the @href CATBaseUnknown class.
* This class makes use of the AddRef/Release mechanism when adding or removing object.
*/
class ExportedBySGInfra CATSortedSetOfObject : public CATSetOfObject
{
public:
 
 inline CATSortedSetOfObject (int iSize=0,int (*iCompare) (void* a, void* b)=NULL);
 inline void Sort();
 inline int Find (void * iObj);
 inline void operator += ( void * iObj );
 inline void operator -= ( void * iObj ) ;
 int (*_pCompare) (void* a, void* b); // comparison function
};

inline CATSortedSetOfObject::CATSortedSetOfObject(int iSize,int (*iCompare) (void* a, void* b)) : CATSetOfObject(iSize), _pCompare(iCompare)
{ 
}

inline void CATSortedSetOfObject::Sort() 
{
  // on suppose que seul le dernier element n'est pas trie
  if ( _size >= 2)
  {
    int g=0,d=_size-2,m;
    void * key;
    void* aux= _tab[_size-1];
    
    key = _tab[_size-1];
    if (_pCompare)
    {
      while (g<=d)
      {
        m = (g+d) >> 1;
        if ( _pCompare(_tab[m] , key) < 0 )
        {
          g = m+1;
        }
        else if ( _pCompare(_tab[m] , key) > 0 )
        {
          d = m-1;
        }
        else
        {
          _size--;
          return;
        }
      }
    }
    else
    {
      while (g<=d)
      {
        m = (g+d) >> 1;
        if (_tab[m] < key)
        {
          g = m+1;
        }
        else if (_tab[m] > key)
        {
          d = m-1;
        }
        else
        {
          _size--;
          return;
        }
      }
    }
    for (int ii = _size-2; ii>=g;ii--)
      _tab[ii+1] = _tab[ii];
    _tab[g] = aux;
  }
}



inline void CATSortedSetOfObject::operator += ( void * iObj )
{
 CATSetOfObject::operator += (iObj);
 Sort();
}


inline int CATSortedSetOfObject::Find(void * iObj) 
{
 int g=0,d=_size-1;
 int m;
 void * mval;
 
 if (_pCompare)
 {
   while ( g <= d )
   {
     m = (d+g) >> 1;
     mval =  _tab[m];
     if ( _pCompare(mval,iObj) == 0)
     {
       return m;
     }
     else
     {
       if ( _pCompare(iObj,mval) <0 )
       {
         d = m - 1;
       }
       else
       {
         g = m + 1;
       }
     }
   }
 }
 else
 {
   while ( g <= d )
   {
     m = (d+g) >> 1;
     mval =  _tab[m];
     if ( mval == iObj )
     {
       return m;
     }
     else
     {
       if (iObj < mval)
       {
         d = m - 1;
       }
       else
       {
         g = m + 1;
       }
     }
   }
 }
 return -1;
}


inline void CATSortedSetOfObject::operator -= ( void * iObj ) 
{
 int index = Find (iObj);
 if(index < 0 || index >= _size) return;
 _size--;
 for(int j = index; j < _size; j++) _tab[j] = _tab[j+1];
 return ;
}

#endif


