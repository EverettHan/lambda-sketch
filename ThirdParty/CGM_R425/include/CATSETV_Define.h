////////////////////////////////////////////////////////////////////////////////

// COPYRIGHT DASSAULT SYSTEMES 2000

//
// FrameWork COLLECTIONS -- Dassault Systems (JAN96)
//
// Macros : 1- CATSETV_DEFINE( T )
// ======
//          2- CATSETV_DECLARE_TN( T, N )
//
//   where T stands for a type name
//     and N stands for a name appended to "CATSetVal"
//     (in the first case T and N are the same)
//
// Purpose : Generate functions for the non-template class CATSetVal"N"
// =======  (list of instances of the class "T")
//
// Usage :  // 1- To generate the functions bodies for CATSetValCATMyClass,
// =====    //    create a file CATSetValCATMyClass.C containing 3 lines :
//          #include  <CATSetValMyClass.h>
//          #include  <CATSETV_Define.h>
//          CATSETV_DEFINE( CATMyClass )
//          // 2- Consult documentation "COLLECTIONS" (chapter List of Values)
//          //    to know the available functionalities
//
// Authors :  Philippe BAUCHER
// =======
//
////////////////////////////////////////////////////////////////////////////////
//
// 1- To produce definition of the functions bodies for CATSetVal...
//    ===============================================================
//
#include  "CATAssert.h"

#ifndef  CATSETV_DEFINE
#define  CATSETV_DEFINE( T )  CATSETV_DEFINE_TN( T, T )
#endif

#ifndef  CATSETV_DEFINE_TN
#define  CATSETV_DEFINE_TN( T, N )                            		   \
/* CDTORS */                                                  		   \
/* default is now the exponential mode : */                   		   \
CATSetVal##N::CATSetVal##N () {}                               	           \
/* same way to grow from an initial alloc */                  	           \
CATSetVal##N::CATSetVal##N ( int iInitAlloc )                 		   \
  : _Sval ( iInitAlloc )  {}                             		   \
/* still maintain the additive mode : */                      		   \
CATSetVal##N::CATSetVal##N ( int iInitAlloc, int iExtensAlloc )            \
  : _Sval ( iInitAlloc )  {}                                               \
                                                                           \
CATSetVal##N::CATSetVal##N ( const CATSetVal##N& iCopy )                   \
  : _Sval ( iCopy.Size() )                                                 \
{                                                                          \
  int size = iCopy.Size();                                                 \
  for ( int  i = 1 ; i <= size ; i++ )                                     \
    _Sval.Append ( new T (iCopy[i]) );                                     \
}                                                                          \
                                                                           \
defCATSETV_CtorFromArrayVals( T, N )                                       \
defCATSETV_CtorFromArrayPtrs( T, N )                                       \
                                                                           \
CATSetVal##N::~CATSetVal##N  ()                                            \
{                                                                          \
  for ( int i = _Sval.Size(); i > 0; i-- )                                 \
  {                                                                        \
    T* pt = (T*) _Sval[i] ;                                                \
    delete pt ;                                                            \
  }                                                                        \
}                                                                          \
                                                                           \
/* "COPY" OPERATOR */                                                      \
CATSetVal##N& CATSetVal##N::operator= ( const CATSetVal##N& iCopy )        \
{                                                                          \
  if ( &iCopy == this ) return *this ;                                     \
  int i ;                                                                  \
  /* delete old contents */                                                \
  for ( i = _Sval.Size(); i > 0; i-- )                                     \
  {                                                                        \
    T* pt = (T*) _Sval[i];                                                 \
    delete pt ;                                                            \
  }                                                                        \
  _Sval.RemoveAll ( CATCollec::KeepAllocation );                           \
  /* copy new contents */                                                  \
  int size = iCopy.Size() ;                                                \
  for ( i = 1 ;  i <= size ; i++ )                                         \
    Add ( iCopy[i] );                                                      \
  return  *this ;                                                          \
}                                                                          \
                                                                           \
/* ADD ELEMENT(S) */                                                       \
int CATSetVal##N::Add ( const T& iAdd )                                    \
{                                                                          \
  int max = Size() ;                                                       \
  /* check if set is empty */                                              \
  if ( max == 0 )                                                          \
  { _Sval.Append( new T (iAdd) ); return 1; }                              \
  /* dichotomic search */                                                  \
  int min = 1 ;                                                            \
  int mid ;                                                                \
  do                                                                       \
  {                                                                        \
    mid = (min + max) / 2 ;                                                \
    T* tmid = (T*) _Sval[mid];                                             \
    if ( iAdd == *tmid ) return 0 ; /* no duplicate */                     \
    if ( iAdd < *tmid )                                                    \
    {                                                                      \
      if ( mid == min )                                                    \
      { _Sval.InsertAt ( mid, new T (iAdd) ); return 1; }                  \
      max = mid - 1 ;                                                      \
    }                                                                      \
    else                                                                   \
    {                                                                      \
      if ( mid == max )                                                    \
      { _Sval.InsertAt ( mid+1, new T (iAdd) ); return 1; }                \
      min = mid + 1 ;                                                      \
    }                                                                      \
 }                                                                         \
 while ( min <= max );                                                     \
 /* should never go up to that point */                                    \
 CATAssert ( 0 );                                                             \
 return  0 ;                                                               \
}                                                                          \
                                                                           \
defCATSETV_AddSet( T, N )                                                  \
                                                                           \
/* GET NUMBER OF ELEMENTS */                                               \
int CATSetVal##N::Size () const                                            \
{ return  _Sval.Size() ;  }                                                \
                                                                           \
/* INDEXATION OPERATORS */                                                 \
T CATSetVal##N::operator[] ( int iPos )  const                             \
{ return *( (T*) _Sval[iPos] ); }                                          \
                                                                           \
/* LOCALIZE ELEMENT */                                                     \
defCATSETV_Locate( T, N )                                                  \
                                                                           \
/* REMOVE ELEMENT(S) */                                                    \
defCATSETV_RemoveValue( T, N )                                             \
defCATSETV_RemoveSet( T, N )                                               \
defCATSETV_RemovePosition( T, N )                                          \
                                                                           \
void CATSetVal##N::RemoveAll ( CATCollec::MemoryHandling iMH )             \
{                                                                          \
 for ( int  i = Size() ; i > 0 ;  i-- )                                    \
 {                                                                         \
   T* pt = (T*) _Sval[i] ;                                                 \
   delete pt ;                                                             \
 }                                                                         \
 _Sval.RemoveAll( iMH );                                                   \
}                                                                          \
                                                                           \
/* COMPARISON OPERATORS */                                                 \
int CATSetVal##N::operator == ( const CATSetVal##N& iSV ) const            \
{  return ( *this != iSV ? 0 : 1 ); }                                      \
                                                                           \
int CATSetVal##N::operator != ( const CATSetVal##N& iSV ) const            \
{                                                                          \
  if ( this == &iSV ) return 0 ;                                           \
  if ( Size() != iSV.Size() ) return 1 ;                                   \
  int size = Size() ;                                                      \
  for ( int  i = 1 ; i <= size ; i++ )                                     \
    if ( (*this)[i] != iSV[i] ) return 1 ;                                 \
  return 0 ;                                                               \
}                                                                          \
                                                                           \
defCATSETV_gtOP( T, N )                                                    \
defCATSETV_ltOP( T, N )                                                    \
defCATSETV_geOP( T, N )                                                    \
defCATSETV_leOP( T, N )                                                    \
                                                                           \
/* COMPARE  (STATIC FUNCTION) */                                           \
defCATSETV_Compare( T, N )                                                 \
                                                                           \
/* CHANGE/MOVE ELEMENT(S) */                                               \
defCATSETV_Replace( T, N )                                                 \
                                                                           \
/*  MISCELLANEOUS */                                                       \
defCATSETV_ArrayVals( T, N )                                               \
defCATSETV_ArrayPtrs( T, N )                                               \
defCATSETV_Contains( T, N )                                                \
defCATSETV_Intersection( T, N )                                            \
                                                                           \
/* APPLY */                                                                \
defCATSETV_ApplyMemberFunct( T, N )                                        \
defCATSETV_ApplyMemberFunctConst( T, N )                                   \
defCATSETV_ApplyGlobalFunct( T, N )                                        \

#endif  // CATSETV_DEFINE_TN

#undef  defCATSETV_CtorFromArrayVals
#undef  defCATSETV_CtorFromArrayPtrs
#undef  defCATSETV_AddSet
#undef  defCATSETV_Locate
#undef  defCATSETV_RemoveValue
#undef  defCATSETV_RemoveSet
#undef  defCATSETV_RemovePosition
#undef  defCATSETV_leOP
#undef  defCATSETV_geOP
#undef  defCATSETV_ltOP
#undef  defCATSETV_gtOP
#undef  defCATSETV_Compare
#undef  defCATSETV_Replace
#undef  defCATSETV_ArrayVals
#undef  defCATSETV_ArrayPtrs
#undef  defCATSETV_Contains
#undef  defCATSETV_Intersection
#undef  defCATSETV_ApplyMemberFunct
#undef  defCATSETV_ApplyMemberFunctConst
#undef  defCATSETV_ApplyGlobalFunct
#undef  defCATSETV_NewDeleteOP

//
// 2 - To prepare (non-)declaration of functions or class CATSetVal...
//     ================================================================
//
//  ==========
//  2-1 CDTORS
//  ==========
//
//   CtorFromArrayVals
//   -----------------
#ifndef CATSETV_CtorFromArrayVals
#define defCATSETV_CtorFromArrayVals( T, N )
#else
#define defCATSETV_CtorFromArrayVals( T, N )             \
CATSetVal##N::CATSetVal##N ( T* iArray, int iSize )      \
 : _Sval ( iSize )                                       \
{                                                        \
  for ( int  i = 0 ; i < iSize ;  i++ )                  \
    Add (iArray[i] );                                    \
}
#endif
//
//   CtorFromArrayPtrs
//   -----------------
#ifndef CATSETV_CtorFromArrayPtrs
#define defCATSETV_CtorFromArrayPtrs( T, N )
#else
#define defCATSETV_CtorFromArrayPtrs( T, N )             \
CATSetVal##N::CATSetVal##N ( T** iArray, int iSize )     \
 : _Sval ( iSize )                                       \
{                                                        \
  for ( int  i = 0 ; i < iSize ;  i++ )                  \
  {                                                      \
    T* pt = iArray[i] ;                                  \
    if ( pt )                                            \
      Add ( *pt );                                       \
  }                                                      \
}
#endif

//  ==================
//  2-2 ADD ELEMENT(S)
//  ==================
#ifndef CATSETV_AddSet
#define defCATSETV_AddSet( T, N )
#else
#define defCATSETV_AddSet( T, N )                        \
int CATSetVal##N::Add ( const CATSetVal##N& iConcat )    \
{                                                        \
  int  count = 0 ;                                       \
  int  size = iConcat.Size() ;                           \
  for ( int  i = 1 ; i <= size ; i++ )                   \
    count += Add ( iConcat[i] );                         \
  return count ;                                         \
}
#endif

//  ====================
//  2-3 LOCALIZE ELEMENT
//  ====================
#ifndef CATSETV_Locate
#define defCATSETV_Locate( T, N )
#else
#define defCATSETV_Locate( T, N )                      \
int CATSetVal##N::Locate ( const T& iLocate ) const    \
{                                                      \
  int max = Size() ;                                   \
  /* check if set is empty */                          \
  if ( max == 0 ) return 0 ;                           \
  /* dichotomic search */                              \
  int min = 1 ;                                        \
  int mid ;                                            \
  do                                                   \
  {                                                    \
    mid = (min + max) / 2 ;                            \
    T rmid = (*this)[mid];                             \
    if ( iLocate == rmid ) return mid ;                \
    if ( iLocate < rmid )                              \
    {                                                  \
      if ( mid == min ) return 0 ;                     \
      max = mid - 1 ;                                  \
    }                                                  \
    else                                               \
    {                                                  \
      if ( mid == max ) return 0 ;                     \
      min = mid + 1 ;                                  \
    }                                                  \
 }                                                     \
 while ( min <= max );                                 \
 /* should never go up to that point */                \
 CATAssert ( 0 );                                         \
 return  0 ;                                           \
}
#endif

//  =====================
//  2-4 REMOVE ELEMENT(S)
//  =====================
//
//   RemoveValue
//   -----------
#ifndef CATSETV_RemoveValue
#define defCATSETV_RemoveValue( T, N )
#else
#define defCATSETV_RemoveValue( T, N )                \
int CATSetVal##N::RemoveValue ( const T& iRemove )    \
{                                                     \
  int pos = Locate ( iRemove );                       \
  if ( pos ) /* if element found */                   \
    RemovePosition ( pos );                           \
  return pos ;                                        \
}
#endif
//
//   RemoveSet
//   ---------
#ifndef CATSETV_RemoveSet
#define defCATSETV_RemoveSet( T, N )
#else
#define defCATSETV_RemoveSet( T, N )                           \
int CATSetVal##N::Remove ( const CATSetVal##N& iSubstract )    \
{                                                              \
  int count = 0 ;                                              \
  int size = iSubstract.Size() ;                               \
  for ( int  i = 1 ; i <= size ; i++ )                         \
    count += ( RemoveValue ( iSubstract[i] ) ) ? 1 : 0 ;       \
  return count ;                                               \
}
#endif
//
//   RemovePosition
//   --------------
#ifndef CATSETV_RemovePosition
#define defCATSETV_RemovePosition( T, N )
#else
#define defCATSETV_RemovePosition( T, N )           \
void CATSetVal##N::RemovePosition ( int iPos )      \
{                                                   \
  T* pt = (T*) _Sval[iPos];                         \
  delete pt ;                                       \
  _Sval.RemovePosition ( iPos );                    \
}
#endif

//  ========================
//  2-5 COMPARISON OPERATORS
//  ========================
//
//   leOP
//   ----
#ifndef CATSETV_leOP
#define defCATSETV_leOP( T, N )
#else
#define defCATSETV_leOP( T, N )                                   \
int CATSetVal##N::operator <= ( const CATSetVal##N& iSV ) const   \
{                                                                 \
  if ( this == &iSV ) return 1 ;                                  \
  /* check size */                                                \
  if ( Size() > iSV.Size() ) return 0 ;                           \
  if ( Size() < iSV.Size() ) return 1 ;                           \
  /* look for a difference */                                     \
  for ( int  i = 1 ; i <= Size() ; i++ )                          \
  {  if ( (*this)[i] > iSV[i] ) return 0 ;                        \
     if ( (*this)[i] < iSV[i] ) return 1 ;                        \
  }                                                               \
  return 1 ;                                                      \
}
#endif
//
//   geOP
//   ----
#ifndef CATSETV_geOP
#define defCATSETV_geOP( T, N )
#else
#define defCATSETV_geOP( T, N )                                   \
int CATSetVal##N::operator >= ( const CATSetVal##N& iSV ) const   \
{                                                                 \
  if ( this == &iSV ) return 1 ;                                  \
  /* check size */                                                \
  if ( Size() < iSV.Size() ) return 0 ;                           \
  if ( Size() > iSV.Size() ) return 1 ;                           \
  /* look for a difference */                                     \
  for ( int  i = 1 ; i <= Size() ; i++ )                          \
  {  if ( (*this)[i] < iSV[i] ) return 0 ;                        \
     if ( (*this)[i] > iSV[i] ) return 1 ;                        \
  }                                                               \
  return 1 ;                                                      \
}
#endif
//
//   ltOP
//   ----
#ifndef CATSETV_ltOP
#define defCATSETV_ltOP( T, N )
#else
#define defCATSETV_ltOP( T, N )                                   \
int CATSetVal##N::operator < ( const CATSetVal##N& iSV ) const    \
{ return ( *this >= iSV ? 0 : 1 ); }
#endif
//
//   gtOP
//   ----
#ifndef CATSETV_gtOP
#define defCATSETV_gtOP( T, N )
#else
#define defCATSETV_gtOP( T, N )                                   \
int CATSetVal##N::operator > ( const CATSetVal##N& iSV ) const    \
{ return ( *this <= iSV ? 0 : 1 ); }
#endif

//  ============================
//  2-6  COMPARE STATIC FUNCTION
//  ============================
#ifndef CATSETV_Compare
#define defCATSETV_Compare( T, N )
#else
#define defCATSETV_Compare( T, N )                                  \
int CATSetVal##N::Compare ( const CATSetVal##N& iS1,                \
                            const CATSetVal##N& iS2,                \
                            int   (*iPFCompare) ( T*, T* ) )        \
{ return CATListPV::Compare ( iS1._Sval, iS2._Sval,                 \
                              (CATCollec::PFCompare) iPFCompare ); }
#endif

//  ========================
//  2-7 REPLACEE ELEMENT(S)
//  ========================
#ifndef CATSETV_Replace
#define defCATSETV_Replace( T, N )
#else
#define defCATSETV_Replace( T, N )                           \
int CATSetVal##N::Replace ( int iPos, const T& iReplace )    \
{                                                            \
  int pos = Locate( iReplace );                              \
  if ( pos )                                                 \
  {                                                          \
    if ( pos != iPos )                                       \
      return 0 ;     /* avoid introducing a duplicate */     \
    else                                                     \
      return 1 ;     /* already done */                      \
  }                                                          \
  T* pt = (T*) _Sval[iPos];                                  \
  delete pt ;                                                \
  _Sval.RemovePosition( iPos );                              \
  return Add( iReplace );                                    \
}
#endif

//  ==================
//  2-8  MISCELLANEOUS
//  ==================
//
//   ArrayVals
//   ---------
#ifndef CATSETV_ArrayVals
#define defCATSETV_ArrayVals( T, N )
#else
#define defCATSETV_ArrayVals( T, N )              \
void CATSetVal##N::Array ( T* ioArray ) const     \
{                                                 \
  for ( int  i = Size() ; i > 0 ; i-- )           \
    ioArray[i-1] = (*this)[i] ;                   \
}
#endif
//
//   ArrayPtrs
//   ---------
#ifndef CATSETV_ArrayPtrs
#define defCATSETV_ArrayPtrs( T, N )
#else
#define defCATSETV_ArrayPtrs( T, N )               \
void CATSetVal##N::Array ( T** ioArray ) const     \
{                                                  \
  for ( int  i = Size() ; i > 0 ; i-- )            \
    ioArray[i-1] = (T*) _Sval[i];                  \
}
#endif
//
//   Contains
//   --------
#ifndef CATSETV_Contains
#define defCATSETV_Contains( T, N )
#else
#define defCATSETV_Contains( T, N )                          \
int CATSetVal##N::Contains ( const CATSetVal##N& iTest )     \
{                                                            \
  for ( int  i = iTest.Size() ; i > 0 ;  i-- )               \
    if ( ! Locate ( iTest[i] ) )                             \
      return 0 ;                                             \
 return 1 ;                                                  \
}
#endif
//
//   Intersection
//   ------------
#ifndef CATSETV_Intersection
#define defCATSETV_Intersection( T, N )
#else
#define defCATSETV_Intersection( T, N )                        \
void CATSetVal##N::Intersection ( const CATSetVal##N& iSV1,    \
                                  const CATSetVal##N& iSV2,    \
                                  CATSetVal##N& ioResult  )    \
{                                                              \
  for ( int  i = iSV1.Size() ; i > 0 ;  i-- )                  \
    if ( iSV2.Locate ( iSV1[i] ) )                             \
      ioResult.Add ( iSV1[i] );                                \
}
#endif

//  =======================
//  2-9  APPLY AN OPERATION
//  =======================
//
//   ApplyMemberFunct
//   ----------------
#ifndef CATSETV_ApplyMemberFunct
#define defCATSETV_ApplyMemberFunct( T, N )
#else
#define defCATSETV_ApplyMemberFunct( T, N )                        \
int CATSetVal##N::ApplyMemberFunct ( PtrMbrFunct  iPF  ,           \
                                     int iFrom, int iTo,           \
                                     T** iPLast, int* iPRC ) const \
{                                                                  \
  if ( ! iTo ) iTo = Size() ;                                      \
  T* pt ;                                                          \
  if ( ! iPLast ) iPLast = &pt ;                                   \
  *iPLast = NULL ;                                                 \
  int RC ;                                                         \
  if ( ! iPRC ) iPRC = &RC ;                                       \
  for ( int  i = iFrom ; i <= iTo ; i++ )                          \
  {                                                                \
    *iPLast = (T*)_Sval[i];                                        \
    if ( *iPRC = ((*iPLast)->*iPF)() )                             \
      return i ;                                                   \
  }                                                                \
  return 0 ;                                                       \
}
#endif
//
//   ApplyMemberFunctConst
//   ---------------------
#ifndef CATSETV_ApplyMemberFunctConst
#define defCATSETV_ApplyMemberFunctConst( T, N )
#else
#define defCATSETV_ApplyMemberFunctConst( T, N )                         \
int CATSetVal##N::ApplyMemberFunctConst ( PtrMbrFunctConst iPF  ,        \
                                          int iFrom, int iTo    ,        \
                                          T** iPLast, int* iPRC ) const  \
{                                                                        \
  if ( ! iTo ) iTo = Size() ;                                            \
  T* pt ;                                                                \
  if ( ! iPLast ) iPLast = &pt ;                                         \
  *iPLast = NULL ;                                                       \
  int RC ;                                                               \
  if ( ! iPRC ) iPRC = &RC ;                                             \
  for ( int  i = iFrom ; i <= iTo ; i++ )                                \
  {                                                                      \
    *iPLast = (T*)_Sval[i] ;                                             \
    if ( *iPRC = ((*iPLast)->*iPF)() )                                   \
      return i ;                                                         \
  }                                                                      \
  return 0 ;                                                             \
}
#endif
//
//   ApplyGlobalFunct
//   ----------------
#ifndef CATSETV_ApplyGlobalFunct
#define defCATSETV_ApplyGlobalFunct( T, N )
#else
#define defCATSETV_ApplyGlobalFunct( T, N )                          \
int CATSetVal##N::ApplyGlobalFunct ( PtrGlbFunct iPF       ,         \
                                     int iFrom , int  iTo  ,         \
                                     T** iPLast, int* iPRC ) const   \
{                                                                    \
  if ( ! iTo ) iTo = Size() ;                                        \
  T* pt ;                                                            \
  if ( ! iPLast ) iPLast = &pt ;                                     \
  *iPLast = NULL ;                                                   \
  int RC ;                                                           \
  if ( ! iPRC ) iPRC = &RC ;                                         \
  for ( int  i = iFrom ; i <= iTo ; i++ )                            \
  {                                                                  \
    *iPLast = (T*)_Sval[i];                                          \
    if ( *iPRC = (*iPF)(*(*iPLast)) )                                \
      return i ;                                                     \
  }                                                                  \
  return 0 ;                                                         \
}
#endif

//  =========================
//  2-10 NEW/DELETE OPERATORS
//  =========================
/*
# define defCATSETV_NewDeleteOP( T, N )                                            \
CATDYNMRYPool*& CATSetVal##N::CATDYNMRY_Pool_For_Class ()                          \
{                                                                                  \
  static CATDYNMRYPool* PoolUsedBy_CATSetVal##N = NULL ;                           \
  static CATDYNMRYPoolHook                                                         \
    ToReleasePoolUsedBy_CATSetVal##N ( &PoolUsedBy_CATSetVal##N, "CATSetVal"#N );  \
  return PoolUsedBy_CATSetVal##N ;                                                 \
}                                                                                  \
int& CATSetVal##N::CATDYNMRY_AllocatedCount ()                                     \
{                                                                                  \
  static int AllocatedCountFor_CATSetVal##N = 0 ;                                  \
  return AllocatedCountFor_CATSetVal##N ;                                          \
}                                                                                  \
int& CATSetVal##N::CATDYNMRY_FreedCount ()                                         \
{                                                                                  \
  static int FreedCountFor_CATSetVal##N = 0 ;                                      \
  return FreedCountFor_CATSetVal##N ;                                              \
}                                                                                  \
void* CATSetVal##N::operator new ( size_t iSizeOfObject )                          \
{                                                                                  \
  static CATDYNMRYPool*&                                                           \
    RefPoolUsedBy_CATSetVal##N = CATSetVal##N::CATDYNMRY_Pool_For_Class () ;       \
  static int&                                                                      \
    RefAllocatedCountFor_CATSetVal##N = CATSetVal##N::CATDYNMRY_AllocatedCount (); \
  static int&                                                                      \
    RefFreedCountFor_CATSetVal##N = CATSetVal##N::CATDYNMRY_FreedCount () ;        \
  return  CATDYNMRYGetMemory( iSizeOfObject                     ,                  \
                              RefPoolUsedBy_CATSetVal##N        ,                  \
                              "CATSetVal"#N                     ,                  \
                              RefAllocatedCountFor_CATSetVal##N ,                  \
                              RefFreedCountFor_CATSetVal##N     );                 \
}                                                                                  \
void CATSetVal##N::operator delete (void* iAddrOfObject, size_t iSizeOfObject)     \
{                                                                                  \
  static CATDYNMRYPool*&                                                           \
    RefPoolUsedBy_CATSetVal##N = CATSetVal##N::CATDYNMRY_Pool_For_Class () ;       \
  static int&                                                                      \
    RefAllocatedCountFor_CATSetVal##N = CATSetVal##N::CATDYNMRY_AllocatedCount (); \
  static int&                                                                      \
    RefFreedCountFor_CATSetVal##N = CATSetVal##N::CATDYNMRY_FreedCount () ;        \
  CATDYNMRYGiveBackMemory( iAddrOfObject, iSizeOfObject      ,                     \
                           RefPoolUsedBy_CATSetVal##N        ,                     \
                           "CATSetVal"#N                     ,                     \
                           RefAllocatedCountFor_CATSetVal##N ,                     \
                           RefFreedCountFor_CATSetVal##N     );                    \
} */

//
// 3- Required includes
//    =================
#include  "CATAssert.h"
