////////////////////////////////////////////////////////////////////////////////

// COPYRIGHT DASSAULT SYSTEMES 2000

//
// FrameWork COLLECTIONS        --        Dassault Systems (JAN96)
// 
// Macros :  1- CATRCOLL_DEFINE( T, N )
// ======    
//           2- CATRCOLL_DEFINE_TN( T, N )
// 	    
//           where T stands for a type name
//             and N stands for a name appended to "CATRawColl"
//           (in the first case T and N are the same)
// 
// Purpose : Generate functions for the non-template class CATRawColl"N"
// =======   (raw collection of instances of the type "T")
// 
// Usage :   // 1- To generate the functions bodies for CATRawCollMyClass,
// =====     //    create a file CATRawCollMyClass.C containing those lines :
//           //
//           // include definition of collection-class
//           // (declarations of functions)
//           //
//           #include  <CATRawCollMyClass.h>
//           //
////////////////////////////////////////////////////////////////////////////////
//
// FrameWork COLLECTIONS        --        Dassault Systems (JAN96)
// 
// Macros :  1- CATRCOLL_DEFINE( T, N )
// ======    
//           2- CATRCOLL_DEFINE_TN( T, N )
// 	    
//           where T stands for a type name
//             and N stands for a name appended to "CATRawColl"
//           (in the first case T and N are the same)
// 
// Purpose : Generate functions for the non-template class CATRawColl"N"
// =======   (raw collection of instances of the type "T")
// 
// Usage :   // 1- To generate the functions bodies for CATRawCollMyClass,
// =====     //    create a file CATRawCollMyClass.C containing those lines :
//           //
//           // include definition of collection-class
//           // (declarations of functions)
//           //
//           #include  <CATRawCollMyClass.h>
//           //
//           // IF REQUIRED include definition of class used for the elements
//           //                (==> might be required for some functions)
//           //
//           #include  <CATMyClass.h>
//           //
//           // define macros CATRCOLL_DEFINE :
//           //
//           #include  <CATRCOLL_Define.h>
//           //
//           // DEFINE functions for class CATRawCollCATMyClass :
//           // (generate their bodies)
//           //
//           CATRCOLL_DEFINE( CATMyClass )
//           //
//           // DEFINE functions for class CATRawCollConstMyClass :
//           // (generate their bodies)
//           //
//           CATRCOLL_DEFINE_TN( const CATMyClass, ConstMyClass )
// 
//           // 2- Consult documentation "COLLECTIONS" (chapter Raw Collections)
//           //    to know the available functionalities
// 
// Authors : Philippe BAUCHER
// =======
//
////////////////////////////////////////////////////////////////////////////////
//
//        1- To produce definition of the functions bodies for CATRawColl...
//           ===============================================================
//
#include  "CATAssert.h"

#ifndef  CATRCOLL_DEFINE
#define  CATRCOLL_DEFINE( T )  CATRCOLL_DEFINE_TN( T, T )
#endif	
	
#ifndef  CATRCOLL_DEFINE_TN
#define  CATRCOLL_DEFINE_TN( T, N )                                             \
/* CDTORS */                                                                    \
CATRawColl##N::CATRawColl##N ( int iInitAlloc )                                 \
        : _Size ( 0 ), _MaxSize ( iInitAlloc ), _Block ( NULL )                 \
{                                                                               \
  if ( _MaxSize )                                                               \
    GetStorage ( _MaxSize, _Block );                                            \
}                                                                               \
                                                                                \
CATRawColl##N::CATRawColl##N ( const CATRawColl##N& iCopy )                     \
        : _Size ( iCopy._Size ), _MaxSize ( iCopy._Size ), _Block ( NULL )      \
{                                                                               \
  if ( _MaxSize )                                                               \
    GetStorage ( _MaxSize, _Block );                                            \
  memcpy ( (void*) _Block, (const void*) iCopy._Block, sizeof(T) * _Size );     \
}                                                                               \
                                                                                \
defCATRCOLL_CtorFromArray( T, N )                                               \
                                                                                \
CATRawColl##N::~CATRawColl##N ()                                                \
{ FreeStorage ( _Block ); }                                                     \
                                                                                \
/* "COPY" OPERATOR */                                                           \
CATRawColl##N& CATRawColl##N::operator = ( const CATRawColl##N& iCopy )         \
{                                                                               \
  if ( &iCopy == this ) return *this ; /* nothing to do */                      \
                                                                                \
  _Size = iCopy._Size ;                                                         \
  /* if block is too small, reallocate it */                                    \
  if ( _Size > _MaxSize )                                                       \
  {                                                                             \
    FreeStorage ( _Block );                                                     \
    _MaxSize = _Size ;                                                          \
    GetStorage ( _MaxSize, _Block );                                            \
  }                                                                             \
  /* copy of elements */                                                        \
  memcpy ( (void*) _Block, (const void*) iCopy._Block, sizeof(T) * _Size );     \
  return  *this ;                                                               \
}                                                                               \
                                                                                \
                                                                                \
/* APPEND ELEMENT(S) */                                                         \
defCATRCOLL_Append( T, N )                                                      \
defCATRCOLL_AppendList( T, N )                                                  \
                                                                                \
/* INSERT ELEMENT */                                                            \
defCATRCOLL_InsertAt( T, N )                                                    \
                                                                                \
/* GET/SET NUMBER OF ELEMENTS */                                                \
defCATRCOLL_ReSize( T, N )                                                      \
defCATRCOLL_ReSizeFill( T, N )                                                  \
                                                                                \
/* INDEXATION OPERATORS */                                                      \
T& CATRawColl##N::operator[] ( int iPos )                                       \
{                                                                               \
  CATAssert ( iPos > 0 && iPos <= _Size );                                         \
  return  _Block[iPos-1] ;                                                      \
}                                                                               \
                                                                                \
T CATRawColl##N::operator[] ( int iPos ) const                                  \
{                                                                               \
  CATAssert ( iPos > 0 && iPos <= _Size );                                         \
  return  _Block[iPos-1] ;                                                      \
}                                                                               \
                                                                                \
/* LOCALIZE ELEMENT */                                                          \
defCATRCOLL_Locate( T, N )                                                      \
                                                                                \
/* REMOVE ELEMENT(S) */                                                         \
defCATRCOLL_RemoveValue( T, N )                                                 \
defCATRCOLL_RemoveList( T, N )                                                  \
defCATRCOLL_RemovePosition( T, N )                                              \
defCATRCOLL_RemoveAll( T, N )                                                   \
defCATRCOLL_RemoveNulls( T, N )                                                 \
defCATRCOLL_RemoveDuplicatesCount( T, N )                                       \
                                                                                \
/* COMPARISON OPERATORS */                                                      \
int CATRawColl##N::operator != ( const CATRawColl##N& iRC ) const               \
{                                                                               \
  if ( this == &iRC )        return 0 ;                                         \
  if ( _Size != iRC._Size )  return 1 ;                                         \
                                                                                \
  for ( int  i = 0; i < _Size; i++ )                                            \
    if ( _Block[i] != iRC._Block[i] ) return 1;                                 \
                                                                                \
  return 0 ;                                                                    \
}                                                                               \
                                                                                \
/* COMPARE  (STATIC FUNCTION) */                                                \
defCATRCOLL_GenericCompare( T, N )                                              \
defCATRCOLL_PtrCompare( T, N )                                                  \
defCATRCOLL_ValCompare( T, N )                                                  \
                                                                                \
/* CHANGE/MOVE ELEMENT(S) */                                                    \
defCATRCOLL_Swap( T, N )                                                        \
defCATRCOLL_PtrQuickSort( T, N )                                                \
defCATRCOLL_ValQuickSort( T, N )                                                \
                                                                                \
/* MISCELLANEOUS */                                                             \
defCATRCOLL_FillArray( T, N )                                                   \
defCATRCOLL_NbOccur( T, N )                                                     \
defCATRCOLL_Intersection( T, N )                                                \
                                                                                \
/* STORAGE */                                                                   \
void CATRawColl##N::FreeStorage ( T*& ioBlock )                                 \
{                                                                               \
  if ( ioBlock )                                                                \
  {                                                                             \
    delete [] ioBlock ;                                                         \
    ioBlock = NULL ;                                                            \
  }                                                                             \
}

#endif                // CATRCOLL_DEFINE_TN


#undef  defCATRCOLL_CtorFromArray
#undef  defCATRCOLL_Append
#undef  defCATRCOLL_AppendList
#undef  defCATRCOLL_InsertAt
#undef  defCATRCOLL_ReSize
#undef  defCATRCOLL_ReSizeFill
#undef  defCATRCOLL_Locate
#undef  defCATRCOLL_RemoveValue
#undef  defCATRCOLL_RemoveList
#undef  defCATRCOLL_RemovePosition
#undef  defCATRCOLL_RemoveAll
#undef  defCATRCOLL_RemoveNulls
#undef  defCATRCOLL_RemoveDuplicatesCount
#undef  defCATRCOLL_GenericCompare
#undef  defCATRCOLL_PtrCompare
#undef  defCATRCOLL_ValCompare
#undef  defCATRCOLL_Swap
#undef  defCATRCOLL_PtrQuickSort
#undef  defCATRCOLL_ValQuickSort
#undef  defCATRCOLL_FillArray
#undef  defCATRCOLL_NbOccur
#undef  defCATRCOLL_Intersection

//
// 2- To prepare (non-)declaration of functions or class CATRawColl...
//    ================================================================
//
// ==========
// 2-1 CDTORS
// ==========
#ifndef CATRCOLL_CtorFromArray
#define defCATRCOLL_CtorFromArray( T, N )
#else	
#define defCATRCOLL_CtorFromArray( T, N )                                       \
CATRawColl##N::CATRawColl##N ( T* iArray, int iSize )                           \
        : _Size ( iSize ), _MaxSize ( iSize ), _Block ( NULL )                  \
{                                                                               \
  if ( _MaxSize )                                                               \
    GetStorage ( _MaxSize, _Block );                                            \
  memcpy ( (void*) _Block, (const void*) iArray, sizeof(T) * _Size );           \
}
#endif

// =====================
// 2-2 APPEND ELEMENT(S)
// =====================
#ifndef CATRCOLL_Append
#define defCATRCOLL_Append( T, N )
#else	
#define defCATRCOLL_Append( T, N )                                              \
void CATRawColl##N::Append ( T iAdd )                                           \
{                                                                               \
  if ( _Size == _MaxSize )                                                      \
  {                                                                             \
    _MaxSize = ( _MaxSize ? ( _MaxSize * 2 ) : 1 );                             \
    T* initial = _Block ;                                                       \
    GetStorage ( _MaxSize, _Block );                                            \
    memcpy ( (void*) _Block, (const void*) initial, sizeof(T) * _Size );        \
    FreeStorage ( initial );                                                    \
  }                                                                             \
  _Block[_Size] = iAdd ;                                                        \
  _Size++ ;                                                                     \
}
#endif

#ifndef CATRCOLL_AppendList
#define defCATRCOLL_AppendList( T, N )
#else  
#define defCATRCOLL_AppendList( T, N )                                          \
void CATRawColl##N::Append ( const CATRawColl##N& iConcat )                     \
{                                                                               \
  int req_size = _Size + iConcat._Size;                                         \
  if ( req_size > _MaxSize )                                                    \
  {                                                                             \
    _MaxSize = req_size ;                                                       \
    T* initial = _Block ;                                                       \
    GetStorage ( _MaxSize, _Block );                                            \
    memcpy( (void*) _Block, (const void*) initial, sizeof(T) * _Size );         \
    FreeStorage ( initial );                                                    \
  }                                                                             \
  /* copy new elements at the end */                                            \
  memcpy ( (void*) &_Block[_Size], (const void*) iConcat._Block,                \
           sizeof(T) * iConcat._Size );                                         \
  _Size = req_size ;                                                            \
}
#endif

// ==================
// 2-3 INSERT ELEMENT
// ==================
#ifndef CATRCOLL_InsertAt
#define defCATRCOLL_InsertAt( T, N )
#else	
#define defCATRCOLL_InsertAt( T, N )                                            \
void CATRawColl##N::InsertAt ( int iPos, T iAdd )                               \
{                                                                               \
  CATAssert ( iPos >= 1 && iPos <= _Size+1 );                                      \
                                                                                \
  if ( _Size == _MaxSize )                                                      \
  {                                                                             \
    _MaxSize = ( _MaxSize ? ( _MaxSize * 2 ) : 1 );                             \
    T* initial = _Block ;                                                       \
    GetStorage ( _MaxSize , _Block );                                           \
                                                                                \
    /* copy first elements (if any) to reallocated block */                     \
    if ( iPos > 1 )                                                             \
      memcpy ( (void*) _Block, (const void*) initial, sizeof(T)*(iPos-1) );     \
                                                                                \
    _Block[iPos-1] = iAdd ;                                                     \
                                                                                \
    /* copy last elements (if any) to reallocated block */                      \
    int last = _Size - iPos + 1 ;                                               \
    if ( last > 0 )                                                             \
      memcpy ( (void*) &_Block[iPos], (const void*) &initial[iPos-1],           \
               sizeof(T) * last );                                              \
    FreeStorage ( initial );                                                    \
  }                                                                             \
  else                                                                          \
  {                                                                             \
    /* move last elements to create a hole */                                   \
    if ( iPos <= _Size )                                                        \
      memmove ( &_Block[iPos], &_Block[iPos-1], (_Size - iPos + 1)*sizeof(T) ); \
                                                                                \
    _Block[iPos-1] = iAdd ;                                                     \
  }                                                                             \
  _Size++ ;                                                                     \
}
#endif

// ==============================
// 2-4 GET/SET NUMBER OF ELEMENTS
// ==============================
#ifndef CATRCOLL_ReSize
#define defCATRCOLL_ReSize( T, N )
#else	
#define defCATRCOLL_ReSize( T, N )                                              \
void CATRawColl##N::Size ( int iSize )                                          \
{                                                                               \
  if ( iSize > _Size )                                                          \
  {                                                                             \
    if ( iSize > _MaxSize )                                                     \
    {                                                                           \
      T* bigger ;                                                               \
      GetStorage ( iSize , bigger );                                            \
      memcpy ( (void*) bigger, (const void*) _Block, sizeof(T) * _Size );       \
      FreeStorage ( _Block );                                                   \
      _Block = bigger ;                                                         \
      _MaxSize = iSize ;                                                        \
    }                                                                           \
  }                                                                             \
  _Size = iSize ;                                                               \
}
#endif

#ifndef CATRCOLL_ReSizeFill
#define defCATRCOLL_ReSizeFill( T, N )
#else	
#define defCATRCOLL_ReSizeFill( T, N )                                          \
void CATRawColl##N::Size ( int iSize, T iFiller )                               \
{                                                                               \
  if ( iSize > _Size )                                                          \
  {                                                                             \
    if ( iSize > _MaxSize )                                                     \
    {                                                                           \
      T* bigger ;                                                               \
      GetStorage ( iSize, bigger );                                             \
                                                                                \
      memcpy ( (void*) bigger, (const void*) _Block, sizeof(T) * _Size );       \
                                                                                \
      FreeStorage ( _Block );                                                   \
                                                                                \
      _Block = bigger ;                                                         \
      _MaxSize = iSize ;                                                        \
    }                                                                           \
                                                                                \
    for ( int  i = _Size; i < iSize; i++ )                                      \
      _Block[i] = iFiller ;                                                     \
  }                                                                             \
  _Size = iSize ;                                                               \
}

#endif

// ====================
// 2-5 LOCALIZE ELEMENT
// ====================
#ifndef  CATRCOLL_Locate
#define defCATRCOLL_Locate( T, N )
#else	
#define defCATRCOLL_Locate( T, N )                                              \
int CATRawColl##N::Locate ( T iLocate, int iFrom ) const                        \
{                                                                               \
  for ( int  i = (iFrom - 1); i < _Size; i++ )                                  \
    if ( _Block[i] == iLocate )                                                 \
      return i+1 ;                                                              \
  return  0 ;        /* not found */                                            \
}
#endif

// =====================
// 2-6 REMOVE ELEMENT(S)
// =====================
#ifndef  CATRCOLL_RemoveValue
#define defCATRCOLL_RemoveValue( T, N )
#else       
#define defCATRCOLL_RemoveValue( T, N )                                        \
int CATRawColl##N::RemoveValue ( T iRemove )                                   \
{                                                                              \
  int pos = Locate ( iRemove );                                                \
  if ( pos )        /* if element found */                                     \
    RemovePosition ( pos );                                                    \
  return pos;                                                                  \
}
#endif

#ifndef  CATRCOLL_RemoveList
#define defCATRCOLL_RemoveList( T, N )
#else       
#define defCATRCOLL_RemoveList( T, N )                                         \
int CATRawColl##N::Remove ( const CATRawColl##N& iSubstract )                  \
{                                                                              \
  if ( this == &iSubstract )                                                   \
  {                                                                            \
    int size = _Size ;                                                         \
    RemoveAll() ;                                                              \
    return size ;                                                              \
  }                                                                            \
                                                                               \
  int count = 0 ;                                                              \
  for ( int  i = 0; i < iSubstract._Size; i++ )                                \
  if ( RemoveValue ( iSubstract._Block[i] ) )                                  \
    count ++;                                                                  \
  return count ;                                                               \
}
#endif

#ifndef  CATRCOLL_RemovePosition
#define defCATRCOLL_RemovePosition( T, N )
#else       
#define defCATRCOLL_RemovePosition( T, N )                                     \
void CATRawColl##N::RemovePosition ( int iPos )                                \
{                                                                              \
  CATAssert ( iPos > 0 && iPos <= _Size );                                        \
                                                                               \
  if ( iPos < _Size )                                                          \
    memmove ( &_Block[iPos -1], &_Block[iPos], (_Size - iPos)*sizeof(T) );     \
  _Size--;                                                                     \
}
#endif

#ifndef CATRCOLL_RemoveAll
#define defCATRCOLL_RemoveAll( T, N )
#else	
#define defCATRCOLL_RemoveAll( T, N )                                          \
void CATRawColl##N::RemoveAll ( CATCollec::MemoryHandling iMH )                \
{                                                                              \
  _Size = 0 ;                                                                  \
  if ( iMH == CATCollec::ReleaseAllocation )                                   \
  {                                                                            \
    FreeStorage ( _Block );                                                    \
    _MaxSize = 0 ;                                                             \
  }                                                                            \
}
#endif

#ifndef  CATRCOLL_RemoveNulls
#define defCATRCOLL_RemoveNulls( T, N )
#else       
#define defCATRCOLL_RemoveNulls( T, N )                                        \
int CATRawColl##N::RemoveNulls ()                                              \
{                                                                              \
  int count = 0 ;                                                              \
  int pos = 1 ;                                                                \
  int null_ptr = 0 ;                                                           \
  T   null_value = 0 ;                                                         \
  do                                                                           \
  {                                                                            \
    null_ptr = Locate ( null_value, pos );                                     \
    if ( null_ptr )                                                            \
    {                                                                          \
      RemovePosition ( null_ptr );                                             \
      count++ ;                                                                \
      pos = null_ptr ;                                                         \
    }                                                                          \
  }                                                                            \
  while ( null_ptr );                                                          \
  return count;                                                                \
}
#endif

#if !defined(CATRCOLL_RemoveDuplicatesCount) && !defined(CATRCOLL_RemoveDuplicates)
#define defCATRCOLL_RemoveDuplicatesCount( T, N )
#else
#define defCATRCOLL_RemoveDuplicatesCount( T, N )                             \
int CATRawColl##N::RemoveDuplicates ( CATRawColl##N* ioExtract )              \
{                                                                             \
  int count = 0 ;                                                             \
  int i = 0 ;                                                                 \
  while ( i < _Size )                                                         \
  {                                                                           \
    int j = i+1 ;                                                             \
    while ( j < _Size )                                                       \
    {                                                                         \
      if ( _Block[i] == _Block[j] )                                           \
      {                                                                       \
        if ( ioExtract )  ioExtract->Append ( _Block[j] );                    \
        count++ ;                                                             \
        RemovePosition ( j+1 );        /* indexing is not the same */         \
      }                                                                       \
      else                                                                    \
        j++ ;                                                                 \
    }                                                                         \
    i++ ;                                                                     \
  }                                                                           \
  return count;                                                               \
}
#endif

// ============================
// 2-7  COMPARE STATIC FUNCTION
// ============================
#ifndef CATRCOLL_GenericCompare
#define defCATRCOLL_GenericCompare( T, N )
#else	
#define defCATRCOLL_GenericCompare( T, N )                                    \
static CATCollec::PFCompare CurrentCompareFunct##N ;                          \
                                                                              \
static int GenericCompare##N ( const void* iPV1, const void* iPV2 )           \
{                                                                             \
  const void**  ppv1 = (const void**) iPV1 ;                                  \
  const void**  ppv2 = (const void**) iPV2 ;                                  \
  /**/                                                                        \
  const void* pv1 = *ppv1 ;                                                   \
  const void* pv2 = *ppv2 ;                                                   \
  /**/                                                                        \
  return (*CurrentCompareFunct##N ) ( pv1, pv2 );                             \
}
#endif

#ifndef CATRCOLL_PtrCompare
#define defCATRCOLL_PtrCompare( T, N )
#else	
#define defCATRCOLL_PtrCompare( T, N )                                        \
int CATRawColl##N::Compare ( const CATRawColl##N& iRC1,                       \
                             const CATRawColl##N& iRC2,                       \
                             int (*iPFCompare) ( const void*, const void* ) ) \
{                                                                             \
  if ( &iRC1 == &iRC2 )          return 0  ;                                  \
  if ( iRC1._Size < iRC2._Size ) return -1 ;                                  \
  else                                                                        \
  if ( iRC1._Size > iRC2._Size ) return +1 ;                                  \
                                                                              \
  /* try to find a difference between elements */                             \
  int test;                                                                   \
  CurrentCompareFunct##N = iPFCompare;                                        \
  for ( int  i = 0; i < iRC1._Size; i++ )                                     \
  {                                                                           \
    test = GenericCompare##N ( &(iRC1._Block[i]), &(iRC2._Block[i]) );        \
    if ( test != 0 ) return test;                                             \
  }                                                                           \
  return 0;                                                                   \
}
#endif

#ifndef CATRCOLL_ValCompare
#define defCATRCOLL_ValCompare( T, N )
#else	
#define defCATRCOLL_ValCompare( T, N )                                              \
int CATRawColl##N::Compare ( const CATRawColl##N& iRC1, const CATRawColl##N& iRC2 ) \
{                                                                                   \
  if ( &iRC1 == &iRC2 )          return 0  ;                                        \
  if ( iRC1._Size < iRC2._Size ) return -1 ;                                        \
  else                                                                              \
  if ( iRC1._Size > iRC2._Size ) return +1 ;                                        \
                                                                                    \
  /* try to find a difference between elements */                                   \
  int test ;                                                                        \
  for ( int  i = 0; i < iRC1._Size; i++ )                                           \
  {                                                                                 \
    test = Compare_##N ( &(iRC1._Block[i]), &(iRC2._Block[i]) );                    \
    if ( test != 0 ) return test;                                                   \
  }                                                                                 \
  return 0;                                                                         \
}
#endif

// ===========================
// 2-8  CHANGE/MOVE ELEMENT(S)
// ===========================
#ifndef CATRCOLL_Swap
#define defCATRCOLL_Swap( T, N )
#else	
#define defCATRCOLL_Swap( T, N )                                                \
void CATRawColl##N::Swap ( int iPos1, int iPos2 )                               \
{                                                                               \
  CATAssert ( iPos1 > 0 && iPos1 <= _Size && iPos2 > 0 && iPos2 <= _Size );        \
  if ( iPos1 == iPos2 ) return ;                                                \
                                                                                \
  T tempo = _Block[iPos1 -1] ;                                                  \
  _Block[iPos1 -1] = _Block[iPos2 -1] ;                                         \
  _Block[iPos2 -1] = tempo ;                                                    \
}
#endif

#ifndef CATRCOLL_PtrQuickSort
#define defCATRCOLL_PtrQuickSort( T, N )
#else	
#define defCATRCOLL_PtrQuickSort( T, N )                                        \
void CATRawColl##N::QuickSort ( int (*iPFCompare)( const void*, const void* ) ) \
{                                                                               \
  CurrentCompareFunct##N = iPFCompare ;                                         \
  qsort ( _Block, _Size, sizeof(void*), &GenericCompare##N );                   \
}
#endif

#ifndef CATRCOLL_ValQuickSort
#define defCATRCOLL_ValQuickSort( T, N )
#else  
#define defCATRCOLL_ValQuickSort( T, N )                                        \
void CATRawColl##N::QuickSort ()                                                \
{ qsort ( _Block, _Size, sizeof(T), (CATCollec::PFCompare) &Compare_##N ); }
#endif

// ==================
// 2-9  MISCELLANEOUS
// ==================
#ifndef CATRCOLL_FillArray
#define defCATRCOLL_FillArray( T, N )
#else  
#define defCATRCOLL_FillArray( T, N )                                          \
void CATRawColl##N::FillArray ( T* ioArray, int iMaxSize ) const               \
{                                                                              \
  int  limit = (iMaxSize < _Size) ? iMaxSize : _Size ;                         \
  for ( int  i = 0; i < limit; i++ )                                           \
    ioArray[i] = _Block[i] ;                                                   \
}
#endif

#ifndef CATRCOLL_NbOccur
#define defCATRCOLL_NbOccur( T, N )
#else  
#define defCATRCOLL_NbOccur( T, N )                                            \
int CATRawColl##N::NbOccur ( T iTest )                                         \
{                                                                              \
  int nb_occ = 0 ;                                                             \
  for ( int  i = 0; i < _Size; i++ )                                           \
    if ( _Block[i] == iTest )                                                  \
      nb_occ ++ ;                                                              \
  return  nb_occ ;                                                             \
}
#endif

#ifndef CATRCOLL_Intersection
#define defCATRCOLL_Intersection( T, N )
#else  
#define defCATRCOLL_Intersection( T, N )                                       \
void CATRawColl##N::Intersection ( const CATRawColl##N& iRC1,                  \
                                   const CATRawColl##N& iRC2,                  \
                                   CATRawColl##N&       ioResult )             \
{                                                                              \
  if ( &iRC1 == &iRC2 )                                                        \
  {                                                                            \
    ioResult.Append ( iRC1 );                                                  \
    return ;                                                                   \
  }                                                                            \
  /* easy case */                                                              \
  if ( ( iRC1._Size == 0 ) || ( iRC2._Size == 0 ) ) return ;                   \
                                                                               \
  int size = iRC1._Size ;                                                      \
  for ( int  i = 0; i < size; i++ )                                            \
    if ( iRC2.Locate ( iRC1._Block[i] ) )                                      \
      ioResult.Append ( iRC1._Block[i] );                                      \
}
#endif

//
// 3- Required includes and forward declarations
//    ==========================================
//
#include  "CATAssert.h"
#include  <string.h>




//           // IF REQUIRED include definition of class used for the elements
//           //                (==> might be required for some functions)
//           //
//           #include  <CATMyClass.h>
//           //
//           // define macros CATRCOLL_DEFINE :
//           //
//           #include  <CATRCOLL_Define.h>
//           //
//           // DEFINE functions for class CATRawCollCATMyClass :
//           // (generate their bodies)
//           //
//           CATRCOLL_DEFINE( CATMyClass )
//           //
//           // DEFINE functions for class CATRawCollConstMyClass :
//           // (generate their bodies)
//           //
//           CATRCOLL_DEFINE_TN( const CATMyClass, ConstMyClass )
// 
//           // 2- Consult documentation "COLLECTIONS" (chapter Raw Collections)
//           //    to know the available functionalities
// 
// Authors : Philippe BAUCHER
// =======
//
////////////////////////////////////////////////////////////////////////////////
//
//        1- To produce definition of the functions bodies for CATRawColl...
//           ===============================================================
//
#include  "CATAssert.h"

#ifndef  CATRCOLL_DEFINE
#define  CATRCOLL_DEFINE( T )  CATRCOLL_DEFINE_TN( T, T )
#endif	
	
#ifndef  CATRCOLL_DEFINE_TN
#define  CATRCOLL_DEFINE_TN( T, N )                                             \
/* CDTORS */                                                                    \
CATRawColl##N::CATRawColl##N ( int iInitAlloc )                                 \
        : _Size ( 0 ), _MaxSize ( iInitAlloc ), _Block ( NULL )                 \
{                                                                               \
  if ( _MaxSize )                                                               \
    GetStorage ( _MaxSize, _Block );                                            \
}                                                                               \
                                                                                \
CATRawColl##N::CATRawColl##N ( const CATRawColl##N& iCopy )                     \
        : _Size ( iCopy._Size ), _MaxSize ( iCopy._Size ), _Block ( NULL )      \
{                                                                               \
  if ( _MaxSize )                                                               \
    GetStorage ( _MaxSize, _Block );                                            \
  memcpy ( (void*) _Block, (const void*) iCopy._Block, sizeof(T) * _Size );     \
}                                                                               \
                                                                                \
defCATRCOLL_CtorFromArray( T, N )                                               \
                                                                                \
CATRawColl##N::~CATRawColl##N ()                                                \
{ FreeStorage ( _Block ); }                                                     \
                                                                                \
/* "COPY" OPERATOR */                                                           \
CATRawColl##N& CATRawColl##N::operator = ( const CATRawColl##N& iCopy )         \
{                                                                               \
  if ( &iCopy == this ) return *this ; /* nothing to do */                      \
                                                                                \
  _Size = iCopy._Size ;                                                         \
  /* if block is too small, reallocate it */                                    \
  if ( _Size > _MaxSize )                                                       \
  {                                                                             \
    FreeStorage ( _Block );                                                     \
    _MaxSize = _Size ;                                                          \
    GetStorage ( _MaxSize, _Block );                                            \
  }                                                                             \
  /* copy of elements */                                                        \
  memcpy ( (void*) _Block, (const void*) iCopy._Block, sizeof(T) * _Size );     \
  return  *this ;                                                               \
}                                                                               \
                                                                                \
                                                                                \
/* APPEND ELEMENT(S) */                                                         \
defCATRCOLL_Append( T, N )                                                      \
defCATRCOLL_AppendList( T, N )                                                  \
                                                                                \
/* INSERT ELEMENT */                                                            \
defCATRCOLL_InsertAt( T, N )                                                    \
                                                                                \
/* GET/SET NUMBER OF ELEMENTS */                                                \
defCATRCOLL_ReSize( T, N )                                                      \
defCATRCOLL_ReSizeFill( T, N )                                                  \
                                                                                \
/* INDEXATION OPERATORS */                                                      \
T& CATRawColl##N::operator[] ( int iPos )                                       \
{                                                                               \
  CATAssert ( iPos > 0 && iPos <= _Size );                                         \
  return  _Block[iPos-1] ;                                                      \
}                                                                               \
                                                                                \
T CATRawColl##N::operator[] ( int iPos ) const                                  \
{                                                                               \
  CATAssert ( iPos > 0 && iPos <= _Size );                                         \
  return  _Block[iPos-1] ;                                                      \
}                                                                               \
                                                                                \
/* LOCALIZE ELEMENT */                                                          \
defCATRCOLL_Locate( T, N )                                                      \
                                                                                \
/* REMOVE ELEMENT(S) */                                                         \
defCATRCOLL_RemoveValue( T, N )                                                 \
defCATRCOLL_RemoveList( T, N )                                                  \
defCATRCOLL_RemovePosition( T, N )                                              \
defCATRCOLL_RemoveAll( T, N )                                                   \
defCATRCOLL_RemoveNulls( T, N )                                                 \
defCATRCOLL_RemoveDuplicatesCount( T, N )                                       \
                                                                                \
/* COMPARISON OPERATORS */                                                      \
int CATRawColl##N::operator != ( const CATRawColl##N& iRC ) const               \
{                                                                               \
  if ( this == &iRC )        return 0 ;                                         \
  if ( _Size != iRC._Size )  return 1 ;                                         \
                                                                                \
  for ( int  i = 0; i < _Size; i++ )                                            \
    if ( _Block[i] != iRC._Block[i] ) return 1;                                 \
                                                                                \
  return 0 ;                                                                    \
}                                                                               \
                                                                                \
/* COMPARE  (STATIC FUNCTION) */                                                \
defCATRCOLL_GenericCompare( T, N )                                              \
defCATRCOLL_PtrCompare( T, N )                                                  \
defCATRCOLL_ValCompare( T, N )                                                  \
                                                                                \
/* CHANGE/MOVE ELEMENT(S) */                                                    \
defCATRCOLL_Swap( T, N )                                                        \
defCATRCOLL_PtrQuickSort( T, N )                                                \
defCATRCOLL_ValQuickSort( T, N )                                                \
                                                                                \
/* MISCELLANEOUS */                                                             \
defCATRCOLL_FillArray( T, N )                                                   \
defCATRCOLL_NbOccur( T, N )                                                     \
defCATRCOLL_Intersection( T, N )                                                \
                                                                                \
/* STORAGE */                                                                   \
void CATRawColl##N::FreeStorage ( T*& ioBlock )                                 \
{                                                                               \
  if ( ioBlock )                                                                \
  {                                                                             \
    delete [] ioBlock ;                                                         \
    ioBlock = NULL ;                                                            \
  }                                                                             \
}

#endif                // CATRCOLL_DEFINE_TN


#undef  defCATRCOLL_CtorFromArray
#undef  defCATRCOLL_Append
#undef  defCATRCOLL_AppendList
#undef  defCATRCOLL_InsertAt
#undef  defCATRCOLL_ReSize
#undef  defCATRCOLL_ReSizeFill
#undef  defCATRCOLL_Locate
#undef  defCATRCOLL_RemoveValue
#undef  defCATRCOLL_RemoveList
#undef  defCATRCOLL_RemovePosition
#undef  defCATRCOLL_RemoveAll
#undef  defCATRCOLL_RemoveNulls
#undef  defCATRCOLL_RemoveDuplicatesCount
#undef  defCATRCOLL_GenericCompare
#undef  defCATRCOLL_PtrCompare
#undef  defCATRCOLL_ValCompare
#undef  defCATRCOLL_Swap
#undef  defCATRCOLL_PtrQuickSort
#undef  defCATRCOLL_ValQuickSort
#undef  defCATRCOLL_FillArray
#undef  defCATRCOLL_NbOccur
#undef  defCATRCOLL_Intersection

//
// 2- To prepare (non-)declaration of functions or class CATRawColl...
//    ================================================================
//
// ==========
// 2-1 CDTORS
// ==========
#ifndef CATRCOLL_CtorFromArray
#define defCATRCOLL_CtorFromArray( T, N )
#else	
#define defCATRCOLL_CtorFromArray( T, N )                                       \
CATRawColl##N::CATRawColl##N ( T* iArray, int iSize )                           \
        : _Size ( iSize ), _MaxSize ( iSize ), _Block ( NULL )                  \
{                                                                               \
  if ( _MaxSize )                                                               \
    GetStorage ( _MaxSize, _Block );                                            \
  memcpy ( (void*) _Block, (const void*) iArray, sizeof(T) * _Size );           \
}
#endif

// =====================
// 2-2 APPEND ELEMENT(S)
// =====================
#ifndef CATRCOLL_Append
#define defCATRCOLL_Append( T, N )
#else	
#define defCATRCOLL_Append( T, N )                                              \
void CATRawColl##N::Append ( T iAdd )                                           \
{                                                                               \
  if ( _Size == _MaxSize )                                                      \
  {                                                                             \
    _MaxSize = ( _MaxSize ? ( _MaxSize * 2 ) : 1 );                             \
    T* initial = _Block ;                                                       \
    GetStorage ( _MaxSize, _Block );                                            \
    memcpy ( (void*) _Block, (const void*) initial, sizeof(T) * _Size );        \
    FreeStorage ( initial );                                                    \
  }                                                                             \
  _Block[_Size] = iAdd ;                                                        \
  _Size++ ;                                                                     \
}
#endif

#ifndef CATRCOLL_AppendList
#define defCATRCOLL_AppendList( T, N )
#else  
#define defCATRCOLL_AppendList( T, N )                                          \
void CATRawColl##N::Append ( const CATRawColl##N& iConcat )                     \
{                                                                               \
  int req_size = _Size + iConcat._Size;                                         \
  if ( req_size > _MaxSize )                                                    \
  {                                                                             \
    _MaxSize = req_size ;                                                       \
    T* initial = _Block ;                                                       \
    GetStorage ( _MaxSize, _Block );                                            \
    memcpy( (void*) _Block, (const void*) initial, sizeof(T) * _Size );         \
    FreeStorage ( initial );                                                    \
  }                                                                             \
  /* copy new elements at the end */                                            \
  memcpy ( (void*) &_Block[_Size], (const void*) iConcat._Block,                \
           sizeof(T) * iConcat._Size );                                         \
  _Size = req_size ;                                                            \
}
#endif

// ==================
// 2-3 INSERT ELEMENT
// ==================
#ifndef CATRCOLL_InsertAt
#define defCATRCOLL_InsertAt( T, N )
#else	
#define defCATRCOLL_InsertAt( T, N )                                            \
void CATRawColl##N::InsertAt ( int iPos, T iAdd )                               \
{                                                                               \
  CATAssert ( iPos >= 1 && iPos <= _Size+1 );                                      \
                                                                                \
  if ( _Size == _MaxSize )                                                      \
  {                                                                             \
    _MaxSize = ( _MaxSize ? ( _MaxSize * 2 ) : 1 );                             \
    T* initial = _Block ;                                                       \
    GetStorage ( _MaxSize , _Block );                                           \
                                                                                \
    /* copy first elements (if any) to reallocated block */                     \
    if ( iPos > 1 )                                                             \
      memcpy ( (void*) _Block, (const void*) initial, sizeof(T)*(iPos-1) );     \
                                                                                \
    _Block[iPos-1] = iAdd ;                                                     \
                                                                                \
    /* copy last elements (if any) to reallocated block */                      \
    int last = _Size - iPos + 1 ;                                               \
    if ( last > 0 )                                                             \
      memcpy ( (void*) &_Block[iPos], (const void*) &initial[iPos-1],           \
               sizeof(T) * last );                                              \
    FreeStorage ( initial );                                                    \
  }                                                                             \
  else                                                                          \
  {                                                                             \
    /* move last elements to create a hole */                                   \
    if ( iPos <= _Size )                                                        \
      memmove ( &_Block[iPos], &_Block[iPos-1], (_Size - iPos + 1)*sizeof(T) ); \
                                                                                \
    _Block[iPos-1] = iAdd ;                                                     \
  }                                                                             \
  _Size++ ;                                                                     \
}
#endif

// ==============================
// 2-4 GET/SET NUMBER OF ELEMENTS
// ==============================
#ifndef CATRCOLL_ReSize
#define defCATRCOLL_ReSize( T, N )
#else	
#define defCATRCOLL_ReSize( T, N )                                              \
void CATRawColl##N::Size ( int iSize )                                          \
{                                                                               \
  if ( iSize > _Size )                                                          \
  {                                                                             \
    if ( iSize > _MaxSize )                                                     \
    {                                                                           \
      T* bigger ;                                                               \
      GetStorage ( iSize , bigger );                                            \
      memcpy ( (void*) bigger, (const void*) _Block, sizeof(T) * _Size );       \
      FreeStorage ( _Block );                                                   \
      _Block = bigger ;                                                         \
      _MaxSize = iSize ;                                                        \
    }                                                                           \
  }                                                                             \
  _Size = iSize ;                                                               \
}
#endif

#ifndef CATRCOLL_ReSizeFill
#define defCATRCOLL_ReSizeFill( T, N )
#else	
#define defCATRCOLL_ReSizeFill( T, N )                                          \
void CATRawColl##N::Size ( int iSize, T iFiller )                               \
{                                                                               \
  if ( iSize > _Size )                                                          \
  {                                                                             \
    if ( iSize > _MaxSize )                                                     \
    {                                                                           \
      T* bigger ;                                                               \
      GetStorage ( iSize, bigger );                                             \
                                                                                \
      memcpy ( (void*) bigger, (const void*) _Block, sizeof(T) * _Size );       \
                                                                                \
      FreeStorage ( _Block );                                                   \
                                                                                \
      _Block = bigger ;                                                         \
      _MaxSize = iSize ;                                                        \
    }                                                                           \
                                                                                \
    for ( int  i = _Size; i < iSize; i++ )                                      \
      _Block[i] = iFiller ;                                                     \
  }                                                                             \
  _Size = iSize ;                                                               \
}

#endif

// ====================
// 2-5 LOCALIZE ELEMENT
// ====================
#ifndef  CATRCOLL_Locate
#define defCATRCOLL_Locate( T, N )
#else	
#define defCATRCOLL_Locate( T, N )                                              \
int CATRawColl##N::Locate ( T iLocate, int iFrom ) const                        \
{                                                                               \
  for ( int  i = (iFrom - 1); i < _Size; i++ )                                  \
    if ( _Block[i] == iLocate )                                                 \
      return i+1 ;                                                              \
  return  0 ;        /* not found */                                            \
}
#endif

// =====================
// 2-6 REMOVE ELEMENT(S)
// =====================
#ifndef  CATRCOLL_RemoveValue
#define defCATRCOLL_RemoveValue( T, N )
#else       
#define defCATRCOLL_RemoveValue( T, N )                                        \
int CATRawColl##N::RemoveValue ( T iRemove )                                   \
{                                                                              \
  int pos = Locate ( iRemove );                                                \
  if ( pos )        /* if element found */                                     \
    RemovePosition ( pos );                                                    \
  return pos;                                                                  \
}
#endif

#ifndef  CATRCOLL_RemoveList
#define defCATRCOLL_RemoveList( T, N )
#else       
#define defCATRCOLL_RemoveList( T, N )                                         \
int CATRawColl##N::Remove ( const CATRawColl##N& iSubstract )                  \
{                                                                              \
  if ( this == &iSubstract )                                                   \
  {                                                                            \
    int size = _Size ;                                                         \
    RemoveAll() ;                                                              \
    return size ;                                                              \
  }                                                                            \
                                                                               \
  int count = 0 ;                                                              \
  for ( int  i = 0; i < iSubstract._Size; i++ )                                \
  if ( RemoveValue ( iSubstract._Block[i] ) )                                  \
    count ++;                                                                  \
  return count ;                                                               \
}
#endif

#ifndef  CATRCOLL_RemovePosition
#define defCATRCOLL_RemovePosition( T, N )
#else       
#define defCATRCOLL_RemovePosition( T, N )                                     \
void CATRawColl##N::RemovePosition ( int iPos )                                \
{                                                                              \
  CATAssert ( iPos > 0 && iPos <= _Size );                                        \
                                                                               \
  if ( iPos < _Size )                                                          \
    memmove ( &_Block[iPos -1], &_Block[iPos], (_Size - iPos)*sizeof(T) );     \
  _Size--;                                                                     \
}
#endif

#ifndef CATRCOLL_RemoveAll
#define defCATRCOLL_RemoveAll( T, N )
#else	
#define defCATRCOLL_RemoveAll( T, N )                                          \
void CATRawColl##N::RemoveAll ( CATCollec::MemoryHandling iMH )                \
{                                                                              \
  _Size = 0 ;                                                                  \
  if ( iMH == CATCollec::ReleaseAllocation )                                   \
  {                                                                            \
    FreeStorage ( _Block );                                                    \
    _MaxSize = 0 ;                                                             \
  }                                                                            \
}
#endif

#ifndef  CATRCOLL_RemoveNulls
#define defCATRCOLL_RemoveNulls( T, N )
#else       
#define defCATRCOLL_RemoveNulls( T, N )                                        \
int CATRawColl##N::RemoveNulls ()                                              \
{                                                                              \
  int count = 0 ;                                                              \
  int pos = 1 ;                                                                \
  int null_ptr = 0 ;                                                           \
  T   null_value = 0 ;                                                         \
  do                                                                           \
  {                                                                            \
    null_ptr = Locate ( null_value, pos );                                     \
    if ( null_ptr )                                                            \
    {                                                                          \
      RemovePosition ( null_ptr );                                             \
      count++ ;                                                                \
      pos = null_ptr ;                                                         \
    }                                                                          \
  }                                                                            \
  while ( null_ptr );                                                          \
  return count;                                                                \
}
#endif

#if !defined(CATRCOLL_RemoveDuplicatesCount) && !defined(CATRCOLL_RemoveDuplicates)
#define defCATRCOLL_RemoveDuplicatesCount( T, N )
#else
#define defCATRCOLL_RemoveDuplicatesCount( T, N )                             \
int CATRawColl##N::RemoveDuplicates ( CATRawColl##N* ioExtract )              \
{                                                                             \
  int count = 0 ;                                                             \
  int i = 0 ;                                                                 \
  while ( i < _Size )                                                         \
  {                                                                           \
    int j = i+1 ;                                                             \
    while ( j < _Size )                                                       \
    {                                                                         \
      if ( _Block[i] == _Block[j] )                                           \
      {                                                                       \
        if ( ioExtract )  ioExtract->Append ( _Block[j] );                    \
        count++ ;                                                             \
        RemovePosition ( j+1 );        /* indexing is not the same */         \
      }                                                                       \
      else                                                                    \
        j++ ;                                                                 \
    }                                                                         \
    i++ ;                                                                     \
  }                                                                           \
  return count;                                                               \
}
#endif

// ============================
// 2-7  COMPARE STATIC FUNCTION
// ============================
#ifndef CATRCOLL_GenericCompare
#define defCATRCOLL_GenericCompare( T, N )
#else	
#define defCATRCOLL_GenericCompare( T, N )                                    \
static CATCollec::PFCompare CurrentCompareFunct##N ;                          \
                                                                              \
static int GenericCompare##N ( const void* iPV1, const void* iPV2 )           \
{                                                                             \
  const void**  ppv1 = (const void**) iPV1 ;                                  \
  const void**  ppv2 = (const void**) iPV2 ;                                  \
  /**/                                                                        \
  const void* pv1 = *ppv1 ;                                                   \
  const void* pv2 = *ppv2 ;                                                   \
  /**/                                                                        \
  return (*CurrentCompareFunct##N ) ( pv1, pv2 );                             \
}
#endif

#ifndef CATRCOLL_PtrCompare
#define defCATRCOLL_PtrCompare( T, N )
#else	
#define defCATRCOLL_PtrCompare( T, N )                                        \
int CATRawColl##N::Compare ( const CATRawColl##N& iRC1,                       \
                             const CATRawColl##N& iRC2,                       \
                             int (*iPFCompare) ( const void*, const void* ) ) \
{                                                                             \
  if ( &iRC1 == &iRC2 )          return 0  ;                                  \
  if ( iRC1._Size < iRC2._Size ) return -1 ;                                  \
  else                                                                        \
  if ( iRC1._Size > iRC2._Size ) return +1 ;                                  \
                                                                              \
  /* try to find a difference between elements */                             \
  int test;                                                                   \
  CurrentCompareFunct##N = iPFCompare;                                        \
  for ( int  i = 0; i < iRC1._Size; i++ )                                     \
  {                                                                           \
    test = GenericCompare##N ( &(iRC1._Block[i]), &(iRC2._Block[i]) );        \
    if ( test != 0 ) return test;                                             \
  }                                                                           \
  return 0;                                                                   \
}
#endif

#ifndef CATRCOLL_ValCompare
#define defCATRCOLL_ValCompare( T, N )
#else	
#define defCATRCOLL_ValCompare( T, N )                                              \
int CATRawColl##N::Compare ( const CATRawColl##N& iRC1, const CATRawColl##N& iRC2 ) \
{                                                                                   \
  if ( &iRC1 == &iRC2 )          return 0  ;                                        \
  if ( iRC1._Size < iRC2._Size ) return -1 ;                                        \
  else                                                                              \
  if ( iRC1._Size > iRC2._Size ) return +1 ;                                        \
                                                                                    \
  /* try to find a difference between elements */                                   \
  int test ;                                                                        \
  for ( int  i = 0; i < iRC1._Size; i++ )                                           \
  {                                                                                 \
    test = Compare_##N ( &(iRC1._Block[i]), &(iRC2._Block[i]) );                    \
    if ( test != 0 ) return test;                                                   \
  }                                                                                 \
  return 0;                                                                         \
}
#endif

// ===========================
// 2-8  CHANGE/MOVE ELEMENT(S)
// ===========================
#ifndef CATRCOLL_Swap
#define defCATRCOLL_Swap( T, N )
#else	
#define defCATRCOLL_Swap( T, N )                                                \
void CATRawColl##N::Swap ( int iPos1, int iPos2 )                               \
{                                                                               \
  CATAssert ( iPos1 > 0 && iPos1 <= _Size && iPos2 > 0 && iPos2 <= _Size );        \
  if ( iPos1 == iPos2 ) return ;                                                \
                                                                                \
  T tempo = _Block[iPos1 -1] ;                                                  \
  _Block[iPos1 -1] = _Block[iPos2 -1] ;                                         \
  _Block[iPos2 -1] = tempo ;                                                    \
}
#endif

#ifndef CATRCOLL_PtrQuickSort
#define defCATRCOLL_PtrQuickSort( T, N )
#else	
#define defCATRCOLL_PtrQuickSort( T, N )                                        \
void CATRawColl##N::QuickSort ( int (*iPFCompare)( const void*, const void* ) ) \
{                                                                               \
  CurrentCompareFunct##N = iPFCompare ;                                         \
  qsort ( _Block, _Size, sizeof(void*), &GenericCompare##N );                   \
}
#endif

#ifndef CATRCOLL_ValQuickSort
#define defCATRCOLL_ValQuickSort( T, N )
#else  
#define defCATRCOLL_ValQuickSort( T, N )                                        \
void CATRawColl##N::QuickSort ()                                                \
{ qsort ( _Block, _Size, sizeof(T), (CATCollec::PFCompare) &Compare_##N ); }
#endif

// ==================
// 2-9  MISCELLANEOUS
// ==================
#ifndef CATRCOLL_FillArray
#define defCATRCOLL_FillArray( T, N )
#else  
#define defCATRCOLL_FillArray( T, N )                                          \
void CATRawColl##N::FillArray ( T* ioArray, int iMaxSize ) const               \
{                                                                              \
  int  limit = (iMaxSize < _Size) ? iMaxSize : _Size ;                         \
  for ( int  i = 0; i < limit; i++ )                                           \
    ioArray[i] = _Block[i] ;                                                   \
}
#endif

#ifndef CATRCOLL_NbOccur
#define defCATRCOLL_NbOccur( T, N )
#else  
#define defCATRCOLL_NbOccur( T, N )                                            \
int CATRawColl##N::NbOccur ( T iTest )                                         \
{                                                                              \
  int nb_occ = 0 ;                                                             \
  for ( int  i = 0; i < _Size; i++ )                                           \
    if ( _Block[i] == iTest )                                                  \
      nb_occ ++ ;                                                              \
  return  nb_occ ;                                                             \
}
#endif

#ifndef CATRCOLL_Intersection
#define defCATRCOLL_Intersection( T, N )
#else  
#define defCATRCOLL_Intersection( T, N )                                       \
void CATRawColl##N::Intersection ( const CATRawColl##N& iRC1,                  \
                                   const CATRawColl##N& iRC2,                  \
                                   CATRawColl##N&       ioResult )             \
{                                                                              \
  if ( &iRC1 == &iRC2 )                                                        \
  {                                                                            \
    ioResult.Append ( iRC1 );                                                  \
    return ;                                                                   \
  }                                                                            \
  /* easy case */                                                              \
  if ( ( iRC1._Size == 0 ) || ( iRC2._Size == 0 ) ) return ;                   \
                                                                               \
  int size = iRC1._Size ;                                                      \
  for ( int  i = 0; i < size; i++ )                                            \
    if ( iRC2.Locate ( iRC1._Block[i] ) )                                      \
      ioResult.Append ( iRC1._Block[i] );                                      \
}
#endif

//
// 3- Required includes and forward declarations
//    ==========================================
//
#include  "CATAssert.h"
#include  <string.h>




