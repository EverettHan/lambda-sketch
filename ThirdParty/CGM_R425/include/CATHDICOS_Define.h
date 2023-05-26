////////////////////////////////////////////////////////////////////////////////

// COPYRIGHT DASSAULT SYSTEMES 2000

//
// FrameWork COLLECTIONS        --        Dassault Systems (FEB96)
// 
// Macros :  1- CATHDICOS_DEFINE( T, N )
// ======    
//           2- CATHDICOS_DEFINE_TN( T, N )
// 	     
//           where T stands for a type name
//             and N stands for a name appended to "CATHasHDic"
//           (in the first case T and N are the same)
// 	     
// Purpose : Generate functions for the non-template class CATHasHDic"N"
// =======   (hash-coding table of pointers to instances of the class "T")
// 
// Usage :   // 1- To generate the functions bodies for CATHashDicCATMyClass,
// =====     //    create a file CATHashDicCATMyClass.C containing those lines :
//           //
//           // include definition of collection-class
//           // (declarations of functions)
//           //
//           #include  <CATHashDicCATMyClass.h>
//           //
//           // IF REQUIRED include definition of class used for the elements
//           //                (==> might be required for some functions)
//           //
//           #include  <CATMyClass.h>
//           //
//           // define macros CATHDICOS_DEFINE :
//           //
//           #include  <CATHDICOS_Define.h>
//           //
//           // DEFINE functions for class CATHashDicCATMyClass :
//           // (generate their bodies)
//           //
//           CATHDICOS_DEFINE( CATMyClass )
//           //
//           // DEFINE functions for class CATHashDicConstMyClass :
//           // (generate their bodies)
//           //
//           CATHDICOS_DEFINE_TN( const CATMyClass, ConstMyClass )
// 
//           // 2- Consult documentation "COLLECTIONS" (chapter List of Pointers)
//           //    to know the available functionalities
// 	     
// Authors : Philippe BAUCHER
// =======
//
////////////////////////////////////////////////////////////////////////////////
//
// 1- To produce definition of the functions bodies for CATHashDicS...
//    ===============================================================
//
#ifndef CATHDICOS_DEFINE
#define CATHDICOS_DEFINE( T ) CATHDICOS_DEFINE_TN( T, T )
#endif	
	
#ifndef CATHDICOS_DEFINE_TN
#define CATHDICOS_DEFINE_TN( T, N )                                               \
/* CDTORS */                                                                      \
defCATHDICOS_Dtor( T, N )                                                         \
                                                                                  \
/* "COPY" OPERATOR */                                                             \
CATHashDicS##N& CATHashDicS##N::operator= ( const CATHashDicS##N& iCopy )         \
{                                                                                 \
  if ( &iCopy == this ) return *this ;                                            \
  _HD = iCopy._HD ;                                                               \
  return  *this ;                                                                 \
}                                                                                 \
                                                                                  \
/* APPLY */                                                                       \
defCATHDICOS_ApplyMemberFunct( T, N )                                             \
defCATHDICOS_ApplyMemberFunctConst( T, N )                                        \
defCATHDICOS_ApplyDelete( T, N )

#endif    // CATHDICOS_DEFINE_TN

//
// 2- To prepare (non-)declaration of functions or class CATHashDicS...
//    ================================================================
//
#undef  defCATHDICOS_Dtor
#undef  defCATHDICOS_ApplyMemberFunct
#undef  defCATHDICOS_ApplyMemberFunctConst
#undef  defCATHDICOS_ApplyDelete

// ==========
// 2-1 CDTORS
// ==========
#ifndef __hpux
#define defCATHDICOS_Dtor( T, N )
#else
#define defCATHDICOS_Dtor( T, N )                                    \
CATHashDicS##N::~CATHashDicS##N () { }
#endif

// =======================
// 2-2  APPLY AN OPERATION
// =======================
#ifndef CATHDICOS_ApplyMemberFunct
#define defCATHDICOS_ApplyMemberFunct( T, N )
#else
#define defCATHDICOS_ApplyMemberFunct( T, N )                                 \
int CATHashDicS##N::ApplyMemberFunct ( PtrMbrFunct      iPF    ,              \
                                       const CATString* iFrom  ,              \
                                       CATString*       iPLast ,              \
                                       int*             iPRC   ) const        \
{                                                                             \
  int RC ;                                                                    \
  if ( ! iPRC ) iPRC = &RC ;                                                  \
  *iPRC = 0 ;                                                                 \
  int oBucket = 1 ;                                                           \
  int oPosition = 0 ;                                                         \
  T*  pt ;                                                                    \
  if ( iFrom )                                                                \
  {                                                                           \
    pt = (T*)_HD.LocatePosition ( *iFrom, oBucket, oPosition );               \
    if ( pt && iPLast ) *iPLast = *iFrom ;                                    \
  }                                                                           \
  else                                                                        \
  { pt = (T*)_HD.Next ( oBucket, oPosition, iPLast ); }                       \
  int count = 0 ;                                                             \
  if ( ! pt ) return count ;                                                  \
  do                                                                          \
  {                                                                           \
    count++ ;                                                                 \
    *iPRC = (pt->*iPF)() ;                                                    \
    if ( *iPRC )                                                              \
      return count ;                                                          \
    else                                                                      \
    {                                                                         \
      pt = (T*)_HD.Next ( oBucket, oPosition, iPLast );                       \
      if ( ! pt ) return count ;                                              \
    }                                                                         \
  }                                                                           \
  while ( 1 );                                                                \
}
#include "CATString.h"
#endif

#ifndef CATHDICOS_ApplyMemberFunctConst
#define defCATHDICOS_ApplyMemberFunctConst( T, N )
#else
#define defCATHDICOS_ApplyMemberFunctConst( T, N )                               \
int CATHashDicS##N::ApplyMemberFunctConst ( PtrMbrFunctConst iPF   ,             \
                                            const CATString* iFrom ,             \
                                            CATString*       iPLast,             \
                                            int*             iPRC  ) const       \
{                                                                                \
  int RC ;                                                                       \
  if ( ! iPRC ) iPRC = &RC ;                                                     \
  *iPRC = 0 ;                                                                    \
  int oBucket = 1 ;                                                              \
  int oPosition = 0 ;                                                            \
  T*  pt ;                                                                       \
  if ( iFrom )                                                                   \
  {                                                                              \
    pt = (T*)_HD.LocatePosition ( *iFrom, oBucket, oPosition );                  \
    if ( pt && iPLast ) *iPLast = *iFrom ;                                       \
  }                                                                              \
  else                                                                           \
  {  pt = (T*)_HD.Next ( oBucket, oPosition, iPLast ); }                         \
  int count = 0 ;                                                                \
  if ( ! pt ) return count ;                                                     \
  do                                                                             \
  {                                                                              \
    count++ ;                                                                    \
    *iPRC = (pt->*iPF)() ;                                                       \
    if ( *iPRC )                                                                 \
    { return count ; }                                                           \
    else                                                                         \
    {                                                                            \
      pt = (T*)_HD.Next ( oBucket, oPosition, iPLast );                          \
      if ( ! pt ) return count ;                                                 \
    }                                                                            \
  }                                                                              \
  while ( 1 );                                                                   \
}
#include "CATString.h"
#endif

#ifndef CATHDICOS_ApplyDelete
#define defCATHDICOS_ApplyDelete( T, N )
#else
#define defCATHDICOS_ApplyDelete( T, N )                                       \
void CATHashDicS##N::ApplyDelete ()                                            \
{                                                                              \
  T*  pt ;                                                                     \
  int oBucket   = 1 ;                                                          \
  int oPosition = 0 ;                                                          \
  do                                                                           \
  {                                                                            \
    pt = (T*)_HD.Next ( oBucket, oPosition );                                  \
    delete pt ;                                                                \
  }                                                                            \
  while ( pt );                                                                \
  RemoveAll() ;                                                                \
}
#endif

// =========================
// 2-3  NEW/DELETE OPERATORS
// =========================
/*
#undef  defCATHDICOS_NewDeleteOP
#define defCATHDICOS_NewDeleteOP( T, N )                                                 \
CATDYNMRYPool*& CATHashDicS##N::CATDYNMRY_Pool_For_Class ()                              \
{                                                                                        \
  static CATDYNMRYPool* PoolUsedBy_CATHashDicS##N = NULL ;                               \
  static CATDYNMRYPoolHook                                                               \
   ToReleasePoolUsedBy_CATHashDicS##N ( &PoolUsedBy_CATHashDicS##N, "CATHashDicS"#N );   \
  return PoolUsedBy_CATHashDicS##N ;                                                     \
}                                                                                        \
                                                                                         \
int& CATHashDicS##N::CATDYNMRY_AllocatedCount ()                                         \
{                                                                                        \
  static int AllocatedCountFor_CATHashDicS##N = 0 ;                                      \
  return AllocatedCountFor_CATHashDicS##N ;                                              \
}                                                                                        \
                                                                                         \
int& CATHashDicS##N::CATDYNMRY_FreedCount ()                                             \
{                                                                                        \
  static int FreedCountFor_CATHashDicS##N = 0 ;                                          \
  return FreedCountFor_CATHashDicS##N ;                                                  \
}                                                                                        \
                                                                                         \
void* CATHashDicS##N::operator new ( size_t iSizeOfObject )                              \
{                                                                                        \
  static CATDYNMRYPool*&                                                                 \
    RefPoolUsedBy_CATHashDicS##N = CATHashDicS##N::CATDYNMRY_Pool_For_Class () ;         \
  static int&                                                                            \
    RefAllocatedCountFor_CATHashDicS##N = CATHashDicS##N::CATDYNMRY_AllocatedCount () ;  \
  static int&                                                                            \
    RefFreedCountFor_CATHashDicS##N = CATHashDicS##N::CATDYNMRY_FreedCount () ;          \
  return  CATDYNMRYGetMemory( iSizeOfObject, RefPoolUsedBy_CATHashDicS##N,               \
                              "CATHashDicS"#N, RefAllocatedCountFor_CATHashDicS##N,      \
                              RefFreedCountFor_CATHashDicS##N );                         \
}                                                                                        \
                                                                                         \
void CATHashDicS##N::operator delete ( void* iAddrOfObject, size_t iSizeOfObject )       \
{                                                                                        \
  static CATDYNMRYPool*&                                                                 \
    RefPoolUsedBy_CATHashDicS##N = CATHashDicS##N::CATDYNMRY_Pool_For_Class () ;         \
  static int&                                                                            \
    RefAllocatedCountFor_CATHashDicS##N = CATHashDicS##N::CATDYNMRY_AllocatedCount () ;  \
  static int&                                                                            \
    RefFreedCountFor_CATHashDicS##N = CATHashDicS##N::CATDYNMRY_FreedCount () ;          \
  CATDYNMRYGiveBackMemory( iAddrOfObject, iSizeOfObject, RefPoolUsedBy_CATHashDicS##N,   \
                           "CATHashDicS"#N, RefAllocatedCountFor_CATHashDicS##N,         \
                           RefFreedCountFor_CATHashDicS##N );                            \
}
*/



