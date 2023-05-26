//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997
//============================================================================
//
// macro CATHTAB_ODT(T):
//	This macro expands in a program that performs a basic call to all
//	the methods contained in the recommended interface.
//	The CATHTAB(T) class should have been generated using that header :
//	#include "CATHTAB_PublicInterface.h"
//	(it has all the recommended #define)
//
//============================================================================
//	
// Usage:
//	Edit a .cpp in a .mtst module in that style :
//
//	/*
//	** headers of collection-classes
//	*/
//	#include "CATHTAB_MyClass.h"
//	#include "CATHTAB_AnotherClass.h"
//	#include "CATHTAB_OneMoreClass.h"
//	/*
//	** headers for macro used to generate code
//	*/
//	#include "CATHTAB_BodyOfODT.h"
//	/*
//	** generation of code calling services of collection-classes
//	*/
//	CATHTAB_ODT(MyClass)
//	CATHTAB_ODT(AnotherClass)
//	CATHTAB_ODT(OneMoreClass)
//	int main()
//	{ 
//	  return 0 ;
//	} 
//
//============================================================================
// Avr. 97	Initial coding				Ph.Baucher
//============================================================================

#ifndef CATHTAB_BodyOfODT_H
#define CATHTAB_BodyOfODT_H

#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATAssert.h"


#define	CATHTAB_ODT(T)								\
static										\
unsigned int	CATHTAB_ComputeKey##T( T* pt )					\
{ return ((unsigned int)pt) / 4; } 						\
static										\
int	CATHTAB_Compare##T( T* t1, T* t2 )					\
{ return ((t1==t2) ? 0 : 1 ); } 						\
static										\
int	CATHTAB_GlobalFunct##T( T* )						\
{ return 0; } 									\
static										\
int	CATHTAB_Test_##T()							\
{										\
  /* test cdtors */								\
  CATHTAB(T)	H1( CATHTAB_ComputeKey##T					\
					, CATHTAB_Compare##T );			\
  CATHTAB(T)	H2(H1);								\
  CATHTAB(T)	H3( CATHTAB_ComputeKey##T					\
					, CATHTAB_Compare##T			\
					,  100);				\
  H1 = H3 ;									\
  /* insert */									\
  H1.Insert( (T*)8 );								\
  /* size */									\
  int	Size = H1.Size();							\
  int	Dimension = H1.Dimension();						\
  int	Collisions = H1.Collisions();						\
  int	Unused = H1.Unused();							\
  /* locating */								\
  T*	Ptr = H1.Locate( (T*)8 );						\
  int	Bucket, Position ;							\
  Ptr = H1.LocatePosition( Ptr							\
			  , Bucket						\
			  , Position );						\
  Ptr = H1.Retrieve( Bucket							\
		    , Position );						\
  Ptr = H1.Next( Bucket								\
		, Position );							\
  Ptr = H1.Next( Ptr );								\
  /* removals */								\
  H1.Remove( Ptr );								\
  H1.RemovePosition( Bucket							\
		    , Position );						\
  H1.RemoveAll();								\
  /* comparisons */								\
  CATAssert( H1 == H2 );								\
  CATAssert( !(H1 != H2) );							\
  /* miscellanous */								\
  H1.PrintStats( cout );							\
  cout << H1 ;									\
  H1.PrintAddr( cout );								\
  /* apply */									\
  H1.ApplyGlobalFunct( &CATHTAB_GlobalFunct##T );				\
  H1.ApplyDelete();								\
  /* exit */									\
  return 0 ;									\
}										\
static										\
int	CATHTAB_Dummy##T = CATHTAB_Test_##T() ;



#endif
