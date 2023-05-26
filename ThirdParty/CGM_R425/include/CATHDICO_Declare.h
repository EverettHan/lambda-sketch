
// COPYRIGHT DASSAULT SYSTEMES 1999
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/


#ifndef CATHDICO_DECLARE
/** 
 * @nodoc 
 * Macros to declare classes which implement hash tables of pointers 
 * to a user-defined type X.
 * <br><b>Role:</b> The functionalities supported by the hash table class
 * can be turned on and off depending on your needs, using #define
 * symbols (if the proper #defined symbol is present, the
 * functionality is added to the class, otherwise it is omitted).
 * There is a trade-off between code-size and functionalities:
 * the more functionalities, the larger the code size.
 * The list of available functionalities is defined in 
 * <tt>CATHDICO_AllFunct.h</tt>
 */
#define CATHDICO_DECLARE( T ) class T ; CATHDICO_DECLARE_TN( T, T )
#endif

#ifndef CATCOLLEC_ExportedBy
/** 
 * @nodoc 
 * Macro for Windows NT to trigger the export of the list class
 * defined in a DLL.
 */
#define CATCOLLEC_ExportedBy
#endif

#ifndef CATHDICO_DECLARE_TN
/** 
 * @nodoc 
 * Macro to declare hash table class with a user-defined name.
 */
#define CATHDICO_DECLARE_TN( T, N )                                            \
class CATCOLLEC_ExportedBy CATHashDic##N : public CATCollecRoot                \
{                                                                              \
  public :                                                                     \
    CATHashDic##N ( int iDimension = 10 )                                      \
        : _HD ( iDimension ) {}                                                \
                                                                               \
    CATHashDic##N  ( const CATHashDic##N& iCopy )                              \
        : _HD ( iCopy._HD ) {}                                                 \
                                                                               \
    dclCATHDICO_Dtor( T, N )                                                   \
                                                                               \
    CATHashDic##N& operator= ( const CATHashDic##N& iCopy );                   \
                                                                               \
    inline int Insert ( const CATUnicodeString& iName, T* iAdd )               \
       { return _HD.Insert ( iName, (void*)iAdd ); }                           \
                                                                               \
    dclCATHDICO_Dimension( T )                                                 \
    dclCATHDICO_Rebuild( T )                                                   \
    inline int Size () const { return  _HD.Size() ; }                          \
                                                                               \
    dclCATHDICO_Collisions( T )                                                \
    dclCATHDICO_Unused( T )                                                    \
                                                                               \
    CATHashCodeIter CreateIterator() const                                     \
        { CATHashCodeIter ITR ( _HD ); return ITR ; }                          \
                                                                               \
    inline T* operator[] ( const CATHashCodeIter& iPos ) const                 \
        { return  ( (T*) _HD[iPos] ); }                                        \
                                                                               \
    inline const CATUnicodeString* ItemName(const CATHashCodeIter& iPos) const \
        { return  _HD.ItemName( iPos ); }                                      \
                                                                               \
    dclCATHDICO_Locate( T )                                                    \
    dclCATHDICO_LocatePosition( T )                                            \
    dclCATHDICO_Retrieve( T )                                                  \
    dclCATHDICO_Next( T )                                                      \
    dclCATHDICO_NextPosition( T )                                              \
                                                                               \
    dclCATHDICO_Remove( T )                                                    \
    dclCATHDICO_RemovePosition( T )                                            \
    dclCATHDICO_RemoveAll( T )                                                 \
                                                                               \
    inline int operator == ( const CATHashDic##N& iH ) const                   \
        { return _HD == iH._HD; }                                              \
                                                                               \
    inline int operator != ( const CATHashDic##N& iH ) const                   \
        { return _HD != iH._HD; }                                              \
                                                                               \
    dclCATHDICO_ApplyMemberFunct( T )                                          \
    dclCATHDICO_ApplyMemberFunctConst( T )                                     \
    dclCATHDICO_ApplyGlobalFunct( T )                                          \
    dclCATHDICO_ApplyDelete( T )                                               \
                                                                               \
  private :                                                                    \
    CATHashDico _HD;                                                           \
};

#endif                // CATHDICO_DECLARE_TNM

#if defined(CATHDICO_ApplyMemberFunct) || defined(CATHDICO_ApplyMemberFunctConst) || defined(CATHDICO_ApplyGlobalFunct)
#ifndef CATHDICO_LocatePosition
/**
 * @nodoc
 */
#define CATHDICO_LocatePosition
#endif
#ifndef CATHDICO_NextPosition
/**
 * @nodoc
 */
#define CATHDICO_NextPosition
#endif
#endif

#ifdef CATHDICO_ApplyDelete
#ifndef CATHDICO_NextPosition
/**
 * @nodoc
 */
#define CATHDICO_NextPosition
#endif
#ifndef CATHDICO_RemoveAll
/**
 * @nodoc
 */
#define CATHDICO_RemoveAll
#endif
#endif

//
// 3- To prepare (non-)declaration of functions or class CATHashDic...
//    ================================================================
//
#undef  dclCATHDICO_Dtor
#undef  dclCATHDICO_Dimension
#undef  dclCATHDICO_Collisions
#undef  dclCATHDICO_Unused
#undef  dclCATHDICO_Locate
#undef  dclCATHDICO_LocatePosition
#undef  dclCATHDICO_Retrieve
#undef  dclCATHDICO_NextPosition
#undef  dclCATHDICO_Next
#undef  dclCATHDICO_Remove
#undef  dclCATHDICO_RemovePosition
#undef  dclCATHDICO_RemoveAll
#undef  dclCATHDICO_ApplyMemberFunct
#undef  dclCATHDICO_ApplyMemberFunctConst
#undef  dclCATHDICO_ApplyGlobalFunct
#undef  dclCATHDICO_ApplyDelete
#undef  dclCATHDICO_Rebuild

// ==========
// 3-1 CDTORS
// ==========
#ifdef __hpux
/**
 * @nodoc
 */
#define dclCATHDICO_Dtor( T, N )                                                \
virtual ~CATHashDic##N ();
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Dtor( T, N )                                                \
virtual ~CATHashDic##N () { }
#endif     

#ifndef CATHDICO_Dimension
/**
 * @nodoc
 */
#define dclCATHDICO_Dimension( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Dimension( T )                                          \
int Dimension () const  { return _HD.Dimension(); }
#endif

/**
 * @nodoc
 */
#ifndef CATHDICO_Rebuild
#define dclCATHDICO_Rebuild( T )
#else
#define dclCATHDICO_Rebuild( T )                                         \
void Rebuild (int iNewDimension) { _HD.Rebuild(iNewDimension); }
#endif

#ifndef CATHDICO_Collisions
/**
 * @nodoc
 */
#define dclCATHDICO_Collisions( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Collisions( T )                                         \
int Collisions () const { return _HD.Collisions(); }
#endif

#ifndef CATHDICO_Unused
/**
 * @nodoc
 */
#define dclCATHDICO_Unused( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Unused( T )                                             \
int Unused () const { return _HD.Unused(); }
#endif

#ifndef CATHDICO_Locate
/**
 * @nodoc
 */
#define dclCATHDICO_Locate( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Locate( T )                                                \
T* Locate ( const CATUnicodeString& iLocate ) const                            \
{ return (T*) _HD.Locate ( iLocate ); }
#endif

#ifndef CATHDICO_LocatePosition
/**
 * @nodoc
 */
#define dclCATHDICO_LocatePosition( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_LocatePosition( T )                                        \
T* LocatePosition ( const CATUnicodeString& iLocate,                           \
                    int& oBucket, int& oPosition ) const                       \
{ return (T*) _HD.LocatePosition ( iLocate, oBucket, oPosition ); }
#endif

#ifndef CATHDICO_Retrieve
/**
 * @nodoc
 */
#define dclCATHDICO_Retrieve( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Retrieve( T )                                              \
T* Retrieve ( int iBucket, int iPosition, CATUnicodeString* iPName = 0 ) const \
{ return (T*) _HD.Retrieve ( iBucket, iPosition, iPName ); }
#endif

#ifndef CATHDICO_NextPosition
/**
 * @nodoc
 */
#define dclCATHDICO_NextPosition( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_NextPosition( T )                                          \
T* Next ( int& ioBucket, int& ioPosition, CATUnicodeString* iPName = 0 ) const \
{ return (T*) _HD.Next( ioBucket, ioPosition, iPName ); }
#endif


#ifndef CATHDICO_Next
/**
 * @nodoc
 */
#define dclCATHDICO_Next( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Next( T )                                                  \
T* Next ( const CATUnicodeString* iFrom, CATUnicodeString* iPName = 0 ) const  \
{ return (T*) _HD.Next( iFrom, iPName ); }
#endif

#ifndef CATHDICO_Remove
/**
 * @nodoc
 */
#define dclCATHDICO_Remove( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_Remove( T )                                               \
T* Remove ( const CATUnicodeString& iRemove )                                 \
{ return (T*) _HD.Remove( iRemove ); }
#endif

#ifndef CATHDICO_RemovePosition
/**
 * @nodoc
 */
#define dclCATHDICO_RemovePosition( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_RemovePosition( T )                                        \
T* RemovePosition ( int iBucket, int iPosition, CATUnicodeString* iPName = 0 ) \
{ return (T*) _HD.RemovePosition ( iBucket, iPosition, iPName ); }
#endif

#ifndef CATHDICO_RemoveAll
/**
 * @nodoc
 */
#define dclCATHDICO_RemoveAll( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_RemoveAll( T )                                             \
void RemoveAll () { _HD.RemoveAll(); }
#endif

#ifndef CATHDICO_ApplyMemberFunct
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyMemberFunct( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyMemberFunct( T )                                     \
typedef int  (T::*PtrMbrFunct) () ;                                           \
int ApplyMemberFunct( PtrMbrFunct iPF                    ,                    \
                      const CATUnicodeString* iFrom  = 0 ,                    \
                      CATUnicodeString*       iPLast = 0 ,                    \
                      int*                    iPRC   = 0 )        const ;
#endif

#ifndef CATHDICO_ApplyMemberFunctConst
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyMemberFunctConst( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyMemberFunctConst( T )                                \
typedef int (T::*PtrMbrFunctConst) () const ;                                 \
int ApplyMemberFunctConst ( PtrMbrFunctConst iPF               ,              \
                            const CATUnicodeString* iFrom  = 0 ,              \
                            CATUnicodeString*       iPLast = 0 ,              \
                            int*                    iPRC   = 0 )  const ;
#endif

#ifndef CATHDICO_ApplyGlobalFunct
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyGlobalFunct( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyGlobalFunct( T )                                     \
typedef int  (*PtrGlbFunct) (T*) ;                                            \
int ApplyGlobalFunct( PtrGlbFunct iPF                    ,                    \
                      const CATUnicodeString* iFrom  = 0 ,                    \
                      CATUnicodeString*       iPLast = 0 ,                    \
                      int*                    iPRC   = 0 ) const              \
{ return _HD.ApplyGlobalFunct ( (CATHashDico::PtrGlbFunct)iPF,                \
                                 iFrom, iPLast, iPRC ); }
#endif

#ifndef CATHDICO_ApplyDelete
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyDelete( T )
#else
/**
 * @nodoc
 */
#define dclCATHDICO_ApplyDelete( T )                                       \
void ApplyDelete ();
#endif

#include "CATCollec.h"
#include "CATCollecRoot.h"
#include "CATHashDico.h"
