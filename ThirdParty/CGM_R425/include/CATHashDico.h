#ifndef CATHashDico_h
#define CATHashDico_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 2000

////////////////////////////////////////////////////////////////////////////////
//
//        FrameWork COLLECTIONS        --        Dassault Systems (FEB96)
//
//        Class :                CATHashDico 
//        =====
//
//        Purpose :        Hash Dictionary of void* pointers (identified by CATUnicodeString)
//        =======                (used as implementation for hash dictionary of typed pointers)
//                  
//        Authors :         Philippe        BAUCHER
//        =======
//
//        Abstract :        1- Implementation through a list of pointers to buckets
//        ========
//
////////////////////////////////////////////////////////////////////////////////
#include  "CATCollec.h"
#include  "CATHashCodeCollec.h"
#include  "CO0HDICO.h"

class   CATUnicodeString ;
class   CATHashDicoElem ;
#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:05:13 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class   ostream ;
#endif //_CAT_ANSI_STREAMS
class   CATHashDico ;
//

class ExportedByCO0HDICO CATHashDico : public CATHashCodeCollec
{       
  public :

    // * the dictionary is empty
    // * its dimension is provided
    CATHashDico ( int iDimension = 10 );
    CATHashDico ( const CATHashDico& iCopy );
    ~CATHashDico ();

    // ASSIGNEMENT
    CATHashDico& operator = ( const CATHashDico& iCopy );

    // INSERT        (if already exists, 0 is returned)
    int Insert ( const CATUnicodeString& iName, void* iAdd);

    // SIZE / DIMENSION
    inline int Dimension () const;
    inline int Size () const;
    // Warning, this method modifies the internal data structure of the hashdico then all 
	// relative information that has been saved should be recomputed (e.g. iterators, buckets 
	// or positions index, count of unused buckets, the dimension).
    void Rebuild(int iNewDimension); 
    
    // STATISTICS  (good dimension?        efficiency of hashing function?)
    inline int Collisions () const;
    inline int Unused () const;

    // FIND AN ITEM
    void* Locate         ( const CATUnicodeString& iLocate ) const ;
    void* LocatePosition ( const CATUnicodeString& iLocate, int& oBucket, int& oPosition ) const ;
    void* Retrieve       ( int iBucket, int iPosition, CATUnicodeString* iPName = 0 ) const ;
    void* operator[]     ( const CATHashCodeIter& iIter ) const ; 
    const CATUnicodeString* ItemName ( const CATHashCodeIter& iIter ) const ; 

    // NEXT ITEM
    void* NextItem( int& ioBucket, int& ioPosition ) const ;
    void* Next    ( int& ioBucket, int& ioPosition, CATUnicodeString* iPName = 0 ) const ;
    void* Next    ( const CATUnicodeString* iFrom, CATUnicodeString* iPName = 0 ) const ;

    // REMOVE
    // 1- remove the corresponding pointer from the dictionary
    //    ==> return it, or NULL if not found
    void* Remove  ( const CATUnicodeString& iRemove );
    // 2- remove by position
    //    ==> return it, or NULL if not exists
    void* RemovePosition ( int iBucket, int iPosition, CATUnicodeString* iPName = 0 );
    // 3- remove all the elements
    void  RemoveAll ();

    // COMPARING
    // comparisons provided compare items functions
    // NB : the size of lists is the first differentiator,
    //      then each element is compared one to one (ordered test)
    int operator == ( const CATHashDico& iHD ) const ;
    int operator != ( const CATHashDico& iHD ) const ;

    // APPLY
    typedef int (*PtrGlbFunct) (void*) ;
    int ApplyGlobalFunct( PtrGlbFunct iPF                    ,
                          const CATUnicodeString* iFrom  = 0 ,
                          CATUnicodeString*       iPLast = 0 ,
                          int*                    iPRC   = 0 ) const ;

  private :
    // DATA MEMBERS
    // list of buckets
    void** _Lbuckets ;
    // list of flags on buckets (0:one item alone / 1:list of items)
    unsigned char* _Lflags ;
    // number of buckets inside the dictionary
    int  _Dimension ;
    // items inside the dictionary
    int  _Size ;
    // unsed buckets
    int  _Unused ;
	
	int  _Insert ( const CATUnicodeString&, void* ,CATHashDicoElem *, short);
};

inline int CATHashDico::Dimension () const
{
  return _Dimension ;
}
inline int CATHashDico::Size () const
{
  return _Size ;
}
inline int CATHashDico::Collisions () const 
{
  int collisions = _Size - (_Dimension-_Unused);
  return collisions;
}
inline int CATHashDico::Unused () const
{
  return _Unused;
}

//
// Macro to help iterations on hash dicos
//
#include  "CATHashCodeIter.h"
#define CATHDICO_START_LOOP( H, ITR )                        \
{                                                            \
  CATHashCodeIter ITR = (H).CreateIterator() ;               \
  while ( ITR++ != NULL )

#define  CATHDICO_END_LOOP  }

#endif                /* CATHashDico_h */
