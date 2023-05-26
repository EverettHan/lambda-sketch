#ifndef CATHashDicoS_h
#define CATHashDicoS_h

// COPYRIGHT DASSAULT SYSTEMES 2000

////////////////////////////////////////////////////////////////////////////////
//
//        FrameWork COLLECTIONS        --        Dassault Systems (FEB96)
//
//        Class :                CATHashDicoS 
//        =====
//
//        Purpose :        Hash Dictionary of void* pointers (identified by CATString)
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

class   CATString ;
class   CATHashDicoSElem ;
#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:05:00 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class   ostream ;
#endif //_CAT_ANSI_STREAMS
class   CATHashDicoS ;
//

class ExportedByCO0HDICO CATHashDicoS : public CATHashCodeCollec
{       
  public :

    // * the dictionary is empty
    // * its dimension is provided
    CATHashDicoS ( int iDimension = 10 );
    CATHashDicoS ( const CATHashDicoS& iCopy );
    ~CATHashDicoS ();

    // ASSIGNEMENT
    CATHashDicoS& operator = ( const CATHashDicoS& iCopy );

    // INSERT        (if already exists, 0 is returned)
    int Insert ( const CATString& iName, void* iAdd);
	
    // SIZE / DIMENSION
	int Dimension () const { return _Dimension ; }
    int Size () const { return _Size ; }
	// Warning, this method modifies the internal data structure of the hashdico then all 
	// relative information that has been saved should be recomputed (e.g. iterators, buckets 
	// or positions index, count of unused buckets, the dimension).    
	void Rebuild(int iNewDimension); 
    
    // STATISTICS  (good dimension?        efficiency of hashing function?)
    int Collisions () const 
      {  int collisions = _Size - (_Dimension-_Unused); return collisions; }
    int Unused () const { return _Unused; }

    // FIND AN ITEM
    void* Locate         ( const CATString& iLocate ) const ;
    void* LocatePosition ( const CATString& iLocate, int& oBucket, int& oPosition ) const ;
    void* Retrieve       ( int iBucket, int iPosition, CATString* iPName = 0 ) const ;
    void* operator[]     ( const CATHashCodeIter& iIter ) const ; 
    const CATString* ItemName ( const CATHashCodeIter& iIter ) const ; 

    // NEXT ITEM
    void* NextItem( int& ioBucket, int& ioPosition ) const ;
    void* Next    ( int& ioBucket, int& ioPosition, CATString* iPName = 0 ) const ;
    void* Next    ( const CATString* iFrom, CATString* iPName = 0 ) const ;

    // REMOVE
    // 1- remove the corresponding pointer from the dictionary
    //    ==> return it, or NULL if not found
    void* Remove  ( const CATString& iRemove );
    // 2- remove by position
    //    ==> return it, or NULL if not exists
    void* RemovePosition ( int iBucket, int iPosition, CATString* iPName = 0 );
    // 3- remove all the elements
    void  RemoveAll ();

    // COMPARING
    // comparisons provided compare items functions
    // NB : the size of lists is the first differentiator,
    //      then each element is compared one to one (ordered test)
    int operator == ( const CATHashDicoS& iHD ) const ;
    int operator != ( const CATHashDicoS& iHD ) const ;

    // APPLY
    typedef int (*PtrGlbFunct) (void*) ;
    int ApplyGlobalFunct( PtrGlbFunct iPF             ,
                          const CATString* iFrom  = 0 ,
                          CATString*       iPLast = 0 ,
                          int*             iPRC   = 0 ) const ;

  private :
    // DATA MEMBERS
    // list of buckets
    void ** _Lbuckets ;
    // list of flags on buckets (0:one item alone / 1:list of items)
    unsigned char* _Lflags ;
    // number of buckets inside the dictionary
    int  _Dimension ;
    // items inside the dictionary
    int  _Size ;
    // unsed buckets
    int  _Unused ;
	
	int  _Insert ( const CATString& , void* , CATHashDicoSElem * , short );
};

//
// Macro to help iterations on hash dicos
//
#include  "CATHashCodeIter.h"
#define CATHDICOS_START_LOOP( H, ITR )                        \
{                                                            \
  CATHashCodeIter ITR = (H).CreateIterator() ;               \
  while ( ITR++ != NULL )

#define  CATHDICOS_END_LOOP  }

#endif                /* CATHashDicoS_h */
