////////////////////////////////////////////////////////////////////////////////

// COPYRIGHT DASSAULT SYSTEMES 2000

//
// FrameWork COLLECTIONS        --        Dassault Systems (FEB96)
// 
// Macros :  1- CATHDICOS_DECLARE( T )
// ======    
//           2- CATHDICOS_DECLARE_TN( T, N )
// 	     
//           where T stands for a type name
//             and N stands for a name appended to "CATHashDic"
//           (in the first case T and N are the same)
// 	     
// Purpose : Generate body of a non-template class CATHashDic"N"
// =======   (hash-coding dictionary of pointers to instances of the class "T")
// 
// Usage :   // 1- To generate the body of a class CATHashDicMyClass,
// =====     //    create a file CATHashDicCATMyClass.h containing those lines :
//           #ifndef        CATHashDicCATMyClass_h
//           #define        CATHashDicCATMyClass_h
//           //
//           // clean previous requests for extra functionalities :
//           //
//           #include  <CATHDICOS_Clean.h>
//           //
//           // define symbols for extra functionalities :
//           //
//           #define        CATHDICOS_ostreamOP
//           #define        CATHDICOS_...
//           //
//           // define macros CATHDICOS_DECLARE :
//           //
//           #include  <CATHDICOS_Declare.h>
//           //
//           // DECLARE functions for class CATHashDicCATMyClass :
//           // (generate body of class)
//           //
//           CATHDICOS_DECLARE( CATMyClass, XX0MODUL )
//           //
//           // DECLARE functions for class CATHashDicSConstMyClass :
//           // (generate body of class)
//           //
//           CATHDICOS_DECLARE_TN( const CATMyClass, ConstMyClass )
//           //
//           #endif        // CATHashDicSCATMyClass_h
// 
//           // 2- Consult documentation "COLLECTIONS" (chapter Hash Tables)
//           //    to know the available functionalities
//           
// Authors : Philippe BAUCHER
// =======
//

////////////////////////////////////////////////////////////////////////////////
//
// 1- To produce declaration of functions for class CATHashDicS...
//    ===========================================================
//
#ifndef CATHDICOS_DECLARE
#define CATHDICOS_DECLARE( T ) class T ; CATHDICOS_DECLARE_TN( T, T )
#endif
//
// Macro CATCOLLEC_ExportedBy is used for WindowsNT import/export DDL specifications
// 1- it should be defined to ExportedByXX0MODUL
// 2- but if not defined, it should not be kept as indesirable text :
#ifndef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy
#endif

#ifndef CATHDICOS_DECLARE_TN
#define CATHDICOS_DECLARE_TN( T, N )                                           \
class CATCOLLEC_ExportedBy CATHashDicS##N : public CATCollecRoot               \
{                          /***********/                                       \
  public :                                                                     \
    /* CDTORS */                                                               \
    CATHashDicS##N ( int iDimension = 10 )                                     \
        : _HD ( iDimension ) {}                                                \
                                                                               \
    CATHashDicS##N  ( const CATHashDicS##N& iCopy )                            \
        : _HD ( iCopy._HD ) {}                                                 \
                                                                               \
    dclCATHDICOS_Dtor( T, N )                                                  \
                                                                               \
    /* COPY OPERATOR */                                                        \
    CATHashDicS##N& operator= ( const CATHashDicS##N& iCopy );                 \
                                                                               \
    /* INSERT ELEMENT */                                                       \
    inline int Insert ( const CATString& iName, T* iAdd )                      \
       { return _HD.Insert ( iName, (void*)iAdd ); }                           \
                                                                               \
    /* DIMENSION / NUMBER OF ELEMENTS */                                       \
    dclCATHDICOS_Dimension( T )                                                \
	dclCATHDICOS_Rebuild( T )                                                  \
    inline int Size () const { return  _HD.Size() ; }                          \
                                                                               \
    /* STATISTICS */                                                           \
    dclCATHDICOS_Collisions( T )                                               \
    dclCATHDICOS_Unused( T )                                                   \
                                                                               \
    /* INDEXATION OPERATORS */                                                 \
    inline CATHashCodeIter CreateIterator() const                              \
        { CATHashCodeIter ITR ( _HD ); return ITR ; }                          \
                                                                               \
    inline T* operator[] ( const CATHashCodeIter& iPos ) const                 \
        { return  ( (T*) _HD[iPos] ); }                                        \
                                                                               \
    inline const CATString* ItemName( const CATHashCodeIter& iPos ) const      \
        { return  _HD.ItemName( iPos ); }                                      \
                                                                               \
    /* LOCALIZE ELEMENT */                                                     \
    dclCATHDICOS_Locate( T )                                                   \
    dclCATHDICOS_LocatePosition( T )                                           \
    dclCATHDICOS_Retrieve( T )                                                 \
    dclCATHDICOS_Next( T )                                                     \
    dclCATHDICOS_NextPosition( T )                                             \
                                                                               \
    /* REMOVE ELEMENT(S) */                                                    \
    dclCATHDICOS_Remove( T )                                                   \
    dclCATHDICOS_RemovePosition( T )                                           \
    dclCATHDICOS_RemoveAll( T )                                                \
                                                                               \
    /* COMPARISON OPERATORS */                                                 \
    inline int operator == ( const CATHashDicS##N& iH ) const                  \
        { return _HD == iH._HD; }                                              \
                                                                               \
    inline int operator != ( const CATHashDicS##N& iH ) const                  \
        { return _HD != iH._HD; }                                              \
                                                                               \
    /* APPLY */                                                                \
    dclCATHDICOS_ApplyMemberFunct( T )                                         \
    dclCATHDICOS_ApplyMemberFunctConst( T )                                    \
    dclCATHDICOS_ApplyGlobalFunct( T )                                         \
    dclCATHDICOS_ApplyDelete( T )                                              \
                                                                               \
  private :                                                                    \
    CATHashDicoS _HD ;                                                         \
};

#endif                // CATHDICOS_DECLARE_TNM

//
// 2- To define required CATHDICOS_... symbols
//    =======================================
//
#if defined(CATHDICOS_ApplyMemberFunct) || defined(CATHDICOS_ApplyMemberFunctConst) || defined(CATHDICOS_ApplyGlobalFunct)
#ifndef CATHDICOS_LocatePosition
#define CATHDICOS_LocatePosition
#endif
#ifndef CATHDICOS_NextPosition
#define CATHDICOS_NextPosition
#endif
#endif

#ifdef CATHDICOS_ApplyDelete
#ifndef CATHDICOS_NextPosition
#define CATHDICOS_NextPosition
#endif
#ifndef CATHDICOS_RemoveAll
#define CATHDICOS_RemoveAll
#endif
#endif

//
// 3- To prepare (non-)declaration of functions or class CATHashDicS...
//    ================================================================
//
#undef  dclCATHDICOS_Dtor
#undef  dclCATHDICOS_Dimension
#undef  dclCATHDICOS_Collisions
#undef  dclCATHDICOS_Unused
#undef  dclCATHDICOS_Locate
#undef  dclCATHDICOS_LocatePosition
#undef  dclCATHDICOS_Retrieve
#undef  dclCATHDICOS_NextPosition
#undef  dclCATHDICOS_Next
#undef  dclCATHDICOS_Remove
#undef  dclCATHDICOS_RemovePosition
#undef  dclCATHDICOS_RemoveAll
#undef  dclCATHDICOS_ApplyMemberFunct
#undef  dclCATHDICOS_ApplyMemberFunctConst
#undef  dclCATHDICOS_ApplyGlobalFunct
#undef  dclCATHDICOS_ApplyDelete
#undef  dclCATHDICOS_Rebuild

// ==========
// 3-1 CDTORS
// ==========
#ifdef __hpux
#define dclCATHDICOS_Dtor( T, N )                                                \
virtual ~CATHashDicS##N ();
#else
#define dclCATHDICOS_Dtor( T, N )                                                \
virtual ~CATHashDicS##N () {}
#endif     

// ==================================
// 3-2 DIMENSION / NUMBER OF ELEMENTS
// ==================================
#ifndef CATHDICOS_Dimension
#define dclCATHDICOS_Dimension( T )
#else
#define dclCATHDICOS_Dimension( T )                                          \
int Dimension () const  { return _HD.Dimension(); }
#endif

// ==================
// 3-2-Bis Rebuild
// ==================
#ifndef CATHDICOS_Rebuild
#define dclCATHDICOS_Rebuild( T )
#else
#define dclCATHDICOS_Rebuild( T )                                         \
void Rebuild (int iNewDimension) { _HD.Rebuild(iNewDimension); }
#endif

// ==============
// 3-3 STATISTICS
// ==============
#ifndef CATHDICOS_Collisions
#define dclCATHDICOS_Collisions( T )
#else
#define dclCATHDICOS_Collisions( T )                                         \
int Collisions () const { return _HD.Collisions(); }
#endif

#ifndef CATHDICOS_Unused
#define dclCATHDICOS_Unused( T )
#else
#define dclCATHDICOS_Unused( T )                                             \
int Unused () const { return _HD.Unused(); }
#endif

// ====================
// 3-4 LOCALIZE ELEMENT
// ====================
#ifndef CATHDICOS_Locate
#define dclCATHDICOS_Locate( T )
#else
#define dclCATHDICOS_Locate( T )                                               \
T* Locate ( const CATString& iLocate ) const                                   \
{ return (T*) _HD.Locate ( iLocate ); }
#endif

#ifndef CATHDICOS_LocatePosition
#define dclCATHDICOS_LocatePosition( T )
#else
#define dclCATHDICOS_LocatePosition( T )                                       \
T* LocatePosition ( const CATString& iLocate,                                  \
                    int& oBucket, int& oPosition ) const                       \
{ return (T*) _HD.LocatePosition ( iLocate, oBucket, oPosition ); }
#endif

#ifndef CATHDICOS_Retrieve
#define dclCATHDICOS_Retrieve( T )
#else
#define dclCATHDICOS_Retrieve( T )                                             \
T* Retrieve ( int iBucket, int iPosition, CATString* iPName = 0 ) const        \
{ return (T*) _HD.Retrieve ( iBucket, iPosition, iPName ); }
#endif

#ifndef CATHDICOS_NextPosition
#define dclCATHDICOS_NextPosition( T )
#else
#define dclCATHDICOS_NextPosition( T )                                         \
T* Next ( int& ioBucket, int& ioPosition, CATString* iPName = 0 ) const        \
{ return (T*) _HD.Next( ioBucket, ioPosition, iPName ); }
#endif


#ifndef CATHDICOS_Next
#define dclCATHDICOS_Next( T )
#else
#define dclCATHDICOS_Next( T )                                                 \
T* Next ( const CATString* iFrom, CATString* iPName = 0 ) const                \
{ return (T*) _HD.Next( iFrom, iPName ); }
#endif

// =====================
// 3-5 REMOVE ELEMENT(S)
// =====================
#ifndef CATHDICOS_Remove
#define dclCATHDICOS_Remove( T )
#else
#define dclCATHDICOS_Remove( T )                                              \
T* Remove ( const CATString& iRemove )                                        \
{ return (T*) _HD.Remove( iRemove ); }
#endif

#ifndef CATHDICOS_RemovePosition
#define dclCATHDICOS_RemovePosition( T )
#else
#define dclCATHDICOS_RemovePosition( T )                                       \
T* RemovePosition ( int iBucket, int iPosition, CATString* iPName = 0 )        \
{ return (T*) _HD.RemovePosition ( iBucket, iPosition, iPName ); }
#endif

#ifndef CATHDICOS_RemoveAll
#define dclCATHDICOS_RemoveAll( T )
#else
#define dclCATHDICOS_RemoveAll( T )                                            \
void RemoveAll () { _HD.RemoveAll(); }
#endif

// =======================
// 3-6  APPLY AN OPERATION
// =======================
#ifndef CATHDICOS_ApplyMemberFunct
#define dclCATHDICOS_ApplyMemberFunct( T )
#else
#define dclCATHDICOS_ApplyMemberFunct( T )                                    \
typedef int  (T::*PtrMbrFunct) () ;                                           \
int ApplyMemberFunct( PtrMbrFunct iPF             ,                           \
                      const CATString* iFrom  = 0 ,                           \
                      CATString*       iPLast = 0 ,                           \
                      int*             iPRC   = 0 )        const ;
#endif

#ifndef CATHDICOS_ApplyMemberFunctConst
#define dclCATHDICOS_ApplyMemberFunctConst( T )
#else
#define dclCATHDICOS_ApplyMemberFunctConst( T )                        \
typedef int (T::*PtrMbrFunctConst) () const ;                          \
int ApplyMemberFunctConst ( PtrMbrFunctConst iPF        ,              \
                            const CATString* iFrom  = 0 ,              \
                            CATString*       iPLast = 0 ,              \
                            int*             iPRC   = 0 )  const ;
#endif

#ifndef CATHDICOS_ApplyGlobalFunct
#define dclCATHDICOS_ApplyGlobalFunct( T )
#else
#define dclCATHDICOS_ApplyGlobalFunct( T )                             \
typedef int  (*PtrGlbFunct) (T*) ;                                     \
int ApplyGlobalFunct( PtrGlbFunct iPF             ,                    \
                      const CATString* iFrom  = 0 ,                    \
                      CATString*       iPLast = 0 ,                    \
                      int*             iPRC   = 0 ) const              \
{ return _HD.ApplyGlobalFunct ( (CATHashDicoS::PtrGlbFunct)iPF,        \
                                 iFrom, iPLast, iPRC ); }
#endif

#ifndef CATHDICOS_ApplyDelete
#define dclCATHDICOS_ApplyDelete( T )
#else
#define dclCATHDICOS_ApplyDelete( T )                                       \
void ApplyDelete ();
#endif

// =========================
// 3-7  NEW-DELETE OPERATORS
// =========================
/*
#include <stddef.h>
#undef  dclCATHDICOS_NewDeleteOP
#define dclCATHDICOS_NewDeleteOP( T )                                           \
  private:                                                                      \
    static CATDYNMRYPool*& CATDYNMRY_Pool_For_Class ();                         \
    static int&            CATDYNMRY_AllocatedCount ();                         \
    static int&            CATDYNMRY_FreedCount ();                             \
  public:                                                                       \
    static void* operator new    ( size_t iSizeOfObject );                      \
    static void  operator delete ( void* iAddrOfObject, size_t iSizeOfObject );

#endif
*/
//
//        4- Required includes and forward declarations
//           ==========================================
//
#include "CATCollec.h"
#include "CATCollecRoot.h"
#include "CATHashDicoS.h"

