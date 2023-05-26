
// COPYRIGHT DASSAULT SYSTEMES 1999

/** @nodoc 
 * Macros to define classes which implement hash tables of pointers 
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
#ifndef CATHDICO_DEFINE
#define CATHDICO_DEFINE( T ) CATHDICO_DEFINE_TN( T, T )
#endif	
	
#ifndef CATHDICO_DEFINE_TN
#define CATHDICO_DEFINE_TN( T, N )                                                \
defCATHDICO_Dtor( T, N )                                                          \
                                                                                  \
CATHashDic##N& CATHashDic##N::operator= ( const CATHashDic##N& iCopy )            \
{                                                                                 \
  if ( &iCopy == this ) return *this ;                                            \
  _HD = iCopy._HD ;                                                               \
  return  *this ;                                                                 \
}                                                                                 \
                                                                                  \
defCATHDICO_ApplyMemberFunct( T, N )                                              \
defCATHDICO_ApplyMemberFunctConst( T, N )                                         \
defCATHDICO_ApplyDelete( T, N )

#endif    // CATHDICO_DEFINE_TN

#undef  defCATHDICO_Dtor
#undef  defCATHDICO_ApplyMemberFunct
#undef  defCATHDICO_ApplyMemberFunctConst
#undef  defCATHDICO_ApplyDelete

#ifdef __hpux
/**
 * @nodoc
 */
#define defCATHDICO_Dtor( T, N )                                    \
CATHashDic##N::~CATHashDic##N () { }
#else
/**
 * @nodoc
 */
#define defCATHDICO_Dtor( T, N )
#endif

#ifndef CATHDICO_ApplyMemberFunct
/**
 * @nodoc
 */
#define defCATHDICO_ApplyMemberFunct( T, N )
#else
/**
 * @nodoc
 */
#define defCATHDICO_ApplyMemberFunct( T, N )                                  \
int CATHashDic##N::ApplyMemberFunct ( PtrMbrFunct             iPF    ,        \
                                      const CATUnicodeString* iFrom  ,        \
                                      CATUnicodeString*       iPLast ,        \
                                      int*                    iPRC   ) const  \
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
    pt = (T*)_HD.Next ( oBucket, oPosition, iPLast );                         \
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
#include "CATUnicodeString.h"

#endif

#ifndef CATHDICO_ApplyMemberFunctConst
/**
 * @nodoc
 */
#define defCATHDICO_ApplyMemberFunctConst( T, N )
#else
/**
 * @nodoc
 */
#define defCATHDICO_ApplyMemberFunctConst( T, N )                                \
int CATHashDic##N::ApplyMemberFunctConst ( PtrMbrFunctConst iPF          ,       \
                                           const CATUnicodeString* iFrom ,       \
                                           CATUnicodeString*       iPLast,       \
                                           int*                    iPRC  ) const \
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
    pt = (T*)_HD.Next ( oBucket, oPosition, iPLast );                            \
  int count = 0 ;                                                                \
  if ( ! pt ) return count ;                                                     \
  do                                                                             \
  {                                                                              \
    count++ ;                                                                    \
    *iPRC = (pt->*iPF)() ;                                                       \
    if ( *iPRC )                                                                 \
      return count ;                                                             \
    else                                                                         \
    {                                                                            \
      pt = (T*)_HD.Next ( oBucket, oPosition, iPLast );                          \
      if ( ! pt ) return count ;                                                 \
    }                                                                            \
  }                                                                              \
  while ( 1 );                                                                   \
}
#include "CATUnicodeString.h"

#endif


#ifndef CATHDICO_ApplyDelete
/**
 * @nodoc
 */
#define defCATHDICO_ApplyDelete( T, N )
#else
/**
 * @nodoc
 */
#define defCATHDICO_ApplyDelete( T, N )                                        \
void CATHashDic##N::ApplyDelete ()                                             \
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

